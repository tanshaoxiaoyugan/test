#include "pch.h"
#include "HeightMapGenerator.h"
#include "HeightMap.h"
#include "PointCloudUtil.h"
#include "AABB.h"

using namespace core;

ptr<CHeightMap> CHeightMapGenerator::generate(const PC_t::Ptr vCloud, uint vResX, uint vResY) {
    ptr<CHeightMap> pHeight(new CHeightMap);
    _EARLY_RETURN(isPointCloudValid(vCloud) == false, "height map generator error: input cloud is invalid.", pHeight);
    _EARLY_RETURN(vResX * vResY == 0, "height map generator error: res == 0.", pHeight);

    SAABB Box = PointCloudUtil::calcAABB(vCloud);
    _EARLY_RETURN(Box.isValid() == false, "height map generator error: bounding box is invalid.", pHeight);
    float SpanX = Box.maxx - Box.minx;
    float SpanY = Box.maxy - Box.miny;

    std::vector<vec3f> Pts;
    for (const auto& p : *vCloud) {
        Pts.emplace_back(vec3f { (p.x - Box.minx) / SpanX, (p.y - Box.miny) / SpanY, p.z});
    }

    return __generate(Pts, vResX, vResY);
}

ptr<CHeightMap> CHeightMapGenerator::generate(const std::vector<vec3f>& vPts, uint vResX, uint vResY) {
    ptr<CHeightMap> pHeight(new CHeightMap);
    _EARLY_RETURN(vResX * vResY == 0, "height map generator error: res == 0.", pHeight);

    return __generate(vPts, vResX, vResY);
}

/* Pts: coor x ¡Ê [0, 1], coor y ¡Ê [0, 1], dist z */
ptr<CHeightMap> CHeightMapGenerator::__generate(const std::vector<vec3f>& vPts, uint vResX, uint vResY) {
    ptr<CHeightMap> pHeight(new CHeightMap(vResX, vResY));

    for (const auto& p : vPts) {
        vec2i e = __mapUV2Pixel(vec2f { p.x, p.y }, vResX, vResY);
        (*pHeight.get())[e.x][e.y] = std::fmaxf((*pHeight.get())[e.x][e.y], p.z);
    }

    return pHeight;
}

vec2i CHeightMapGenerator::__mapUV2Pixel(const vec2f& vUV, uint vResX, uint vResY) {
    _EARLY_RETURN(vUV.x < 0 || vUV.y < 0 || vUV.x > 1 || vUV.y > 1, "UV is invalid", vec2i ( 0, 0 ));

    uint CoorX = vUV.x * vResX;
    uint CoorY = vUV.y * vResY;

    CoorX = (CoorX == vResX) ? CoorX - 1 : CoorX;
    CoorY = (CoorY == vResY) ? CoorY - 1 : CoorY;

    return vec2i { (int)CoorX, (int)CoorY };
}
