#include "pch.h"
#include "DGI.h"

template <typename T>
using ptr = std::shared_ptr<T>;

bool CDGI::setResolution(uint vRes) {
	_EARLY_RETURN(vRes == 0, "DGI set res error: res == 0.", false);

	m_Res = vRes;
	return true;
}

bool CDGI::run(const PC_t::Ptr vInput, const PC_t::Ptr voOutput) {
	_EARLY_RETURN(!isPointCloudValid(vInput), "DGI run error: input is not valid.", false);

	ptr<core::CHeightMap> pHeight = core::MapUtil::geneHeightMap(vInput, m_Res);


	return false;
}


