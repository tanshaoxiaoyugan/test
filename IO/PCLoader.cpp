#include "pch.h"
#include "PCLoader.h"
#include "PlyLoader.h"

using namespace io;

PC_t::Ptr CPCLoader::loadDataFromFile(const std::string& vFileName) {
	_ASSERTE(!vFileName.empty());
	
	_EARLY_RETURN(isFilePathValid(vFileName) == 0, "load point cloud error: file path is invalid.", nullptr);

	PC_t::Ptr pPointCloud(new PC_t);
	int r = 0;
	try {
		std::string Extension = getFileNameExtension(vFileName);
		if (Extension == EXT_PLY) {
			CPlyLoader Loader;
			r = Loader.loadDataFromFile(vFileName, *pPointCloud);
		}

		if (r == 0) {
			std::cout << "point cloud load successfully: " << vFileName << std::endl;
			return pPointCloud;
		}
		else {
			pPointCloud.reset();
			std::cout << "point cloud load fail: " << vFileName << std::endl;
			return nullptr;
		}
	} catch (...) {
		pPointCloud.reset();
		std::cout << "point cloud load error: " << vFileName << std::endl;
		return nullptr;
	}
}
