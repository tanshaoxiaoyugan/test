#pragma once
#include "PointCloudType.h"
#include "GlobalValue.h"

static bool isPointCloudValid(const PC_t::Ptr& vCloud, int vLevel = 0) {
	if (vCloud == nullptr) return false;
	if (vCloud->empty()) return false;

	switch (vLevel) {
	default:
	case 0:
		break;
	case 1:
		for (auto& p : *vCloud) {
			if (std::isnan(p.x) || std::isnan(p.y) || std::isnan(p.z)) {
				return false;
			}
		}
	}

	return true;
}

static bool isPointEqual(const Point_t& p1, const Point_t& p2) {
	if ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z) < EPSILON) {
		return true;
	}

	return false;
}

