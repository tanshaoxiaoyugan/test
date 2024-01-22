#pragma once

#include "BasicMath.h"
#include "Map.hpp"

namespace core {

class CGradientMap : public CMap<vec2f> {
public:
	CGradientMap();
	CGradientMap(uint w, uint h);
	CGradientMap(uint w, uint h, vec2f v);

private:

};

}