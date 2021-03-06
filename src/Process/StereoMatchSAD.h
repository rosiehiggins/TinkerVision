#pragma once

#include "TinkerVision_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace TnkrVis
{
namespace Process
{
	
class TINKERVISION_EXPORT StereoMatchSAD
{
    private: 
        class Internal;
        Internal* internal;

	public:
		StereoMatchSAD(); 
        ~StereoMatchSAD(); 
		void Run(ImageGPU* inputL, ImageGPU* inputR, ImageGPU* output); 
        void Run(Image* inputL, Image* inputR, Image* output); 
        void SetBlockSize(int W, int H);
        void SetMaxK(int mk);
        void SetSADThreshold(float st); 
};
	
}
}