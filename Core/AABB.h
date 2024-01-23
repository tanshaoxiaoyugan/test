#pragma once

namespace core {

struct SAABB
{
	float minx;
	float miny;
	float minz;
	float maxx;
	float maxy;
	float maxz;

	bool isValid() const {
		if (minx > maxx || miny > maxy || minz > maxz) {
			return false;
		}
		else {
			return true;
		}
	}
};

}
