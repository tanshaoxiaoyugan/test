#pragma once

#include "Map.hpp"

namespace core {

/* 
 *	255	->	empty
 *	0	->	filled
 */

class CMaskMap: public CMap<std::uint8_t> {
public:
	CMaskMap();
	CMaskMap(uint w, uint h);
	CMaskMap(uint w, uint h, std::uint8_t v);

private:

};

}