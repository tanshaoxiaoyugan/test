#include "pch.h"
#include "MaskMap.h"

using namespace core;

core::CMaskMap::CMaskMap()
	: CMap<std::uint8_t>(0, 0, 0) {
	m_Empty = 255;
}

core::CMaskMap::CMaskMap(uint w, uint h)
	: CMap<std::uint8_t>(w, h, 0) {
	m_Empty = 255;
}

core::CMaskMap::CMaskMap(uint w, uint h, std::uint8_t v)
	: CMap<std::uint8_t>(w, h, v) {
	m_Empty = 255;
}