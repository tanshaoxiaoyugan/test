#pragma once

#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

#define _EARLY_RETURN(condition, prompt, return_value) if (condition) {std::cout << prompt << std::endl; return return_value;}

static bool isFilePathValid(const std::string& vPath) {
	if (!boost::filesystem::exists(vPath)) {
		return false;
	}
	else {
		return true;
	}
}

static std::string getFileName(const std::string& vPath) {
	boost::filesystem::path FilePath(vPath);
	std::string FileName = FilePath.filename().string();
	return FileName;
}

static std::string getFileNameExtension(const std::string& vPath) {
	std::string FileName = getFileName(vPath);
	size_t Dot = FileName.find_last_of(".");
	std::string Extension = FileName.substr(Dot, FileName.size() - Dot);
	return Extension;
}

static void log(const std::string& vLog) {
	std::cout << vLog << std::endl;
}
