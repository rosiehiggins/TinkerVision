#pragma once

#include "TinkerVision_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

#include <vector>

namespace TnkrVis
{
namespace Process
{

class TINKERVISION_EXPORT Mipmaps
{
    private: 
        class Internal;
        Internal* internal;

	public:
		Mipmaps(); 
        ~Mipmaps(); 
		void Run(ImageGPU* input, std::vector<ImageGPU>* output); 
        void Run(Image* input, std::vector<Image>* output); 
};
	
}
}