#pragma once

#include "Viso_export.h"

#include "../Core/VectorMath.h"

#include <vector>
#include <algorithm>

namespace Viso
{
namespace Process
{


class VISO_EXPORT FixedRadiusNN
{
    private:
        class Internal;
        Internal* internal;
        
    public:
        FixedRadiusNN();
        ~FixedRadiusNN(); 
        void Build(std::vector<Vec2>* vecs, float radius);
        void Test(Vec2 point, std::vector<int>* nns);
        void SortByDistance(Vec2 point, std::vector<Vec2>* vecs, std::vector<int>* nns);
        void RadialOutlierRemoval(std::vector<Vec2>* vecs, float minRadius, float maxRadius, int minNsWithinBounds); 
};


}

}