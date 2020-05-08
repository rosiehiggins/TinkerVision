#pragma once

#include "Viso_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace Viso
{
namespace CompositeProcess
{
	
class VISO_EXPORT CornerDetector
{
    private: 
        class Internal;
        Internal* internal;

	public:
		CornerDetector(); 
        ~CornerDetector(); 
        
		void Run(ImageGPU* input, ImageGPU* output); 
        void Run(Image* input, Image* output); 
};
	
}
}