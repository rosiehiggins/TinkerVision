#pragma once

#include "Visi_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace Visi
{

class VISI_EXPORT DownSample
{
    private: 
        class Internal;
        Internal* internal;

	public:
        enum Mode {NEAREST, BOX, BILINEAR};

		DownSample(); 
        ~DownSample(); 
		void Run(ImageGPU* input, ImageGPU* output); 
        void Run(Image* input, Image* output); 
        void SetMode(Mode m); 
};
	
}