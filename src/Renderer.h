#pragma once

#include "Visi_export.h"

#include "ImageType.h"
#include "Image.h"
#include "ImageGPU.h"

#include <glm/glm.hpp>
#include <vector>

namespace Visi
{

class VISI_EXPORT Renderer
{
    private: 
        class Internal;
        Internal* internal;

	public:
		Renderer(); 
        ~Renderer(); 
        void Clear();
        void Run(Image* input, Image* output); 
        void AddPolyLine(std::vector<glm::vec2>* pl, glm::vec4 color=glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), float lineWidth=1); 
        void AddCircle(glm::vec2 centre, float radius, glm::vec4 color=glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), bool filled=false, float borderWidth=1); 
};
	
}