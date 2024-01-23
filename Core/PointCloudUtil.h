#pragma once

namespace core {

struct SAABB;

class PointCloudUtil {
public:
	static SAABB calcAABB(const PC_t::Ptr vCloud);

private:

};

}
