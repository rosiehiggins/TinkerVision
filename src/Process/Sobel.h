#pragma once

#include "Visi_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace Visi
{
namespace Process
{
	
class VISI_EXPORT Sobel
{
    private: 
        class Internal;
        Internal* internal;

	public:
        enum Mode{FULL, GRAD_ONLY, MAG_ONLY};

		Sobel(); 
        ~Sobel(); 
		void Run(ImageGPU* input, ImageGPU* output); 
        void Run(Image* input, Image* output); 
        void SetMode(Mode m); 
};
	
}
}