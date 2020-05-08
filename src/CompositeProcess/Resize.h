#pragma once

#include "Viso_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

#include "../Process/Upsample.h"
#include "../Process/Downsample.h"

namespace Viso
{
namespace CompositeProcess
{
	
class VISO_EXPORT Resize
{
    private: 
        class Internal;
        Internal* internal;

	public:
		Resize(); 
        ~Resize(); 
		void Run(ImageGPU* input, ImageGPU* output); 
        void Run(Image* input, Image* output); 
        void SetUpsampleMode(Process::Upsample::Mode m);
        void SetDownsampleMode(Process::Downsample::Mode m); 
};
	
}
}