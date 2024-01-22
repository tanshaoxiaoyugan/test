#pragma once

namespace io {

class CPlyLoader {
public:
	CPlyLoader() = default;
	~CPlyLoader() = default;

	int loadDataFromFile(const std::string& vFileName, PC_t& voPointCloud);

private:

};

}
