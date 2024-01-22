#include "pch.h"
#include "GradientMap.h"

using namespace core;

core::CGradientMap::CGradientMap()
	: CMap<vec2f>(0, 0, vec2f { -FLT_MAX, -FLT_MAX }) {
	m_Empty = vec2f { -FLT_MAX, -FLT_MAX };
}

core::CGradientMap::CGradientMap(uint w, uint h)
	: CMap<vec2f>(w, h, vec2f { -FLT_MAX, -FLT_MAX }) {
	m_Empty = vec2f { -FLT_MAX, -FLT_MAX };
}

core::CGradientMap::CGradientMap(uint w, uint h, vec2f v)
	: CMap<vec2f>(w, h, v) {
	m_Empty = vec2f { -FLT_MAX, -FLT_MAX };
}