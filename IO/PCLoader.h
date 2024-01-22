#pragma once

namespace io
{
class CPCLoader
{
public:
	CPCLoader() = default;

	PC_t::Ptr loadDataFromFile(const std::string& vFileName);


};
}