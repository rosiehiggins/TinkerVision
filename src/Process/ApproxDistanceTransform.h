#pragma once

#include "Viso_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace Viso
{
namespace Process
{
	
class VISO_EXPORT ApproxDistanceTransform
{
    private: 
        class Internal;
        Internal* internal;

	public:
		ApproxDistanceTransform(); 
        ~ApproxDistanceTransform(); 
        void Run(Image* input, Image* output); 
};
	
}
}