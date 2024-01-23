#include "pch.h"
#include "PointCloudUtil.h"
#include "AABB.h"

using namespace core;

SAABB PointCloudUtil::calcAABB(const PC_t::Ptr vCloud) {
	SAABB Box { FLT_MAX, FLT_MAX , FLT_MAX , -FLT_MAX, -FLT_MAX , -FLT_MAX };
	_EARLY_RETURN(isPointCloudValid(vCloud) == false, "point cloud util error: input cloud is invalid.", Box);
	
	for (const auto& p : *vCloud) {
		Box.minx = std::fminf(Box.minx, p.x);
		Box.miny = std::fminf(Box.miny, p.y);
		Box.minz = std::fminf(Box.minz, p.z);
		Box.maxx = std::fmaxf(Box.maxx, p.x);
		Box.maxy = std::fmaxf(Box.maxy, p.y);
		Box.maxz = std::fmaxf(Box.maxz, p.z);
	}

	_EARLY_RETURN(Box.isValid() == false, "point cloud util error: aabb calculate bug.", Box);

	return Box;
}
