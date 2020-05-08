#pragma once

#include "Viso_export.h"

#include "../Core/ImageType.h"
#include "../Core/Image.h"
#include "../Core/ImageGPU.h"

namespace Viso
{
namespace Process
{
	
class VISO_EXPORT CameraDistortion
{
    private: 
        class Internal;
        Internal* internal;

	public:
		CameraDistortion(); 
        ~CameraDistortion(); 
        void SetRadialCoefs(float k0, float k1, float k2);
        void SetTangentialCoefs(float p0, float p1);
        void SetFocalLength(float fl);
		void Run(ImageGPU* input, ImageGPU* output); 
        void Run(Image* input, Image* output); 
};
	
}
}