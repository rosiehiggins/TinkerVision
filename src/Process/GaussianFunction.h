#pragma once

#include "Viso_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace Viso
{
namespace Process
{

class VISO_EXPORT GaussianFunction
{
    private: 
        class Internal;
        Internal* internal;

	public:
        enum GenerateMode{ FIXED, SIZE_TO_SIGMA, SIGMA_TO_SIZE };

		GaussianFunction(); 
        ~GaussianFunction(); 
        void SetSigma(float sig); 
        void SetSigma(float sigX, float sigY); 
        void SetGenerateMode(GenerateMode gm); 
		void Run(ImageGPU* dst); 
        void Run(Image* dst); 
};
	
}
}