#include "Context.h"
#include "Image.h"
#include "ImageGPU.h"
#include "WriteImageFile.h"
#include "ReadImageFile.h"
#include "BrightnessContrast.h"
#include "Threshold.h"
#include "GrayScale.h"
#include "RGBToHSV.h"
#include "HSVToRGB.h"
#include "AdaptiveThreshold.h"
#include "MedianFilter.h"
#include "GaussianBlur.h"
#include "Sobel.h"
#include "Renderer.h"
#include "FindContours.h"
#include "Invert.h"
#include "Contour.h"
#include "Blend.h"
#include "ChannelDemux.h"

#include <iostream>

int main()
{
	Visi::Context context; 
	context.MakeCurrent(); 
	
	std::cout << "Running Test\n"; 


	Visi::Image image1; 
	Visi::Image image2; 
	Visi::Image image3; 

	Visi::ImageGPU imageGPU1;
	Visi::ImageGPU imageGPU2;
	Visi::ImageGPU imageGPU3;
	Visi::ImageGPU imageGPU4;


	//
	//Processes
	//

	Visi::ReadImageFile("img3.jpeg", &image1);
	imageGPU1.Copy(&image1);

	//Median Filter
	Visi::MedianFilter medianFilter; 
	medianFilter.SetSize(3); 
	medianFilter.Run(&imageGPU1, &imageGPU2); 
	image2.Copy(&imageGPU2);
	Visi::WriteImageFile("MarkerTestMedian.png", &image2);

	//RGBToHSV 
	Visi::RGBToHSV rgbtohsv; 
	rgbtohsv.Run(&imageGPU1, &imageGPU2); 
	image2.Copy(&imageGPU2);
	Visi::WriteImageFile("MarkerTestHSV.png", &image2);
	
	//threshold all saturation values above thresh
	Visi::Threshold saturationThreshold; 
	saturationThreshold.SetThreshold(glm::vec3(1, 0.1, 1));
	saturationThreshold.Run(&imageGPU2, &imageGPU3);
	image2.Copy(&imageGPU3);
	Visi::WriteImageFile("MarkerTestHSVHThresh.png", &image2);

	//Blur
	Visi::GaussianBlur blur; 
	blur.SetSigma(1.6); 
	blur.Run(&imageGPU3, &imageGPU4);
	image2.Copy(&imageGPU4);
	Visi::WriteImageFile("MarkerTestHSVHThreshBlur.png", &image2);

	//subtract
	Visi::Blend blend; 
	blend.SetMode(Visi::Blend::BlendMode::SUBTRACT);
	blend.Run(&imageGPU4, &imageGPU2, &imageGPU3);
	image2.Copy(&imageGPU3);
	Visi::WriteImageFile("MarkerTestHSVSubtract.png", &image2);

	//Back to rgb
	Visi::HSVToRGB hsvtorgb; 
	hsvtorgb.Run(&imageGPU3, &imageGPU4); 
	image2.Copy(&imageGPU4);
	Visi::WriteImageFile("MarkerTestrgbSubtract.png", &image2);

	//Greyscale
	Visi::GrayScale grayScale;
	grayScale.Run(&imageGPU4, &imageGPU2); 
	image2.Copy(&imageGPU2);
	Visi::WriteImageFile("MarkerTestGrey.png", &image2);

	//Adaptive Threshold
	Visi::AdaptiveThreshold adaptiveThreshold; 
	adaptiveThreshold.SetThreshold(0.03); 
	adaptiveThreshold.SetSize(200); 
	adaptiveThreshold.Run(&imageGPU2, &imageGPU3); 

	//Invert
	Visi::Invert invert;
	invert.Run(&imageGPU3, &imageGPU2); 
	image2.Copy(&imageGPU2);
	Visi::WriteImageFile("MarkerTest1.png", &image2);

	//Find Contours
	Visi::FindContours findContours; 
	std::vector<Visi::Contour> contours; 
	findContours.Run(&image2, &image3, &contours); 
	Visi::WriteImageFile("MarkerTest2.png", &image3);
	
	std::vector<Visi::Contour> contoursFiltered; 
	Visi::Contour::ContoursVertCountFilter(&contours, &contoursFiltered, 100);
	std::vector<Visi::Contour> contoursSimplified; 
	Visi::Contour::ContoursSimplify(&contoursFiltered, &contoursSimplified, 3);
	std::vector<Visi::Contour> contoursMerged; 
	Visi::Contour::ContoursMergeVerticies(&contoursSimplified, &contoursMerged, 4);
	std::vector<Visi::Contour> contoursQuads; 
	Visi::Contour::ContoursVertCountFilter(&contoursMerged, &contoursQuads, 4, 5);

	Visi::Renderer renderer; 
	renderer.Clear(); 
	renderer.AddContours(&contoursFiltered, true, 1, false, true); 
	renderer.Run(&image1, &image2); 
	Visi::WriteImageFile("MarkerTest3.png", &image2);

	renderer.Clear(); 
	renderer.AddContours(&contoursSimplified, true, 4, true, true); 
	renderer.Run(&image1, &image2); 
	Visi::WriteImageFile("MarkerTest4.png", &image2);

	renderer.Clear(); 
	renderer.AddContours(&contoursMerged, true, 4, true, true); 
	renderer.Run(&image1, &image2); 
	Visi::WriteImageFile("MarkerTest5.png", &image2);

	renderer.Clear();
	renderer.AddContours(&contoursQuads, true, 4, true, true); 
	renderer.Run(&image1, &image2); 
	Visi::WriteImageFile("MarkerTest6.png", &image2);


	Visi::Contour::ContoursToFile("MarkerTest.contours", &contoursQuads); 

	

	
	std::cout << "DONE\n";
	return 1; 
}