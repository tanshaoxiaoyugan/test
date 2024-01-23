#pragma once

namespace core {

template <typename T>
using ptr = std::shared_ptr<T>;
using uint = std::uint32_t;

class CHeightMap;
class CHeightMapGenerator {
public:

	ptr<CHeightMap> generate(const PC_t::Ptr vCloud, uint vResX, uint vResY);
	ptr<CHeightMap> generate(const std::vector<vec3f>& vPts, uint vResX, uint vResY);

private:
	ptr<CHeightMap> __generate(const std::vector<vec3f>& vPts, uint vResX, uint vResY);
	vec2i __mapUV2Pixel(const vec2f& vUV, uint vResX, uint vResY);
};

}
