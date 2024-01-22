#include "pch.h"
#include "PlyLoader.h"

using namespace io;

int CPlyLoader::loadDataFromFile(const std::string& vFileName, PC_t& voPointCloud) {
	return pcl::io::loadPLYFile<PC_t::PointType>(vFileName, voPointCloud);
}
