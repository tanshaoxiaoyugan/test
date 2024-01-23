#pragma once

namespace core {

class CMapWrapper {
public:

	template <typename T>
	static cv::Mat castMap2CVMat(const std::shared_ptr<CMap<T>> vMap);

	template <>
	static cv::Mat castMap2CVMat<float>(const std::shared_ptr<CMap<float>> vMap);

	template <>
	static cv::Mat castMap2CVMat<vec2f>(const std::shared_ptr<CMap<vec2f>> vMap);

	template <>
	static cv::Mat castMap2CVMat<std::uint8_t>(const std::shared_ptr<CMap<std::uint8_t>> vMap);

private:

};

template <typename T>
inline cv::Mat CMapWrapper::castMap2CVMat(const std::shared_ptr<CMap<T>> vMap) {
	return cv::Mat();
}

template <>
inline cv::Mat CMapWrapper::castMap2CVMat<float>(const std::shared_ptr<CMap<float>> vMap) {
	_EARLY_RETURN(vMap->isValid() == false, "map wrapper error: map is invalid.", cv::Mat());

	cv::Mat Image(vMap->getWidth(), vMap->getHeight(), CV_32FC1);
	for (int i = 0; i < vMap->getWidth(); i++) {
		for (int k = 0; k < vMap->getHeight(); k++) {
			Image.at<float>(i, k) = vMap->getValue(i, k);
		}
	}

	return Image;
}

template <>
inline cv::Mat CMapWrapper::castMap2CVMat<vec2f>(const std::shared_ptr<CMap<vec2f>> vMap) {
	_EARLY_RETURN(vMap->isValid() == false, "map wrapper error: map is invalid.", cv::Mat());

	cv::Mat Image(vMap->getWidth(), vMap->getHeight(), CV_32FC2);
	for (int i = 0; i < vMap->getWidth(); i++) {
		for (int k = 0; k < vMap->getHeight(); k++) {
			vec2f Value = vMap->getValue(i, k);
			Image.at<cv::Vec2f>(i, k) = cv::Vec2f { Value.x, Value.y };
		}
	}

	return Image;
}

template <>
inline cv::Mat CMapWrapper::castMap2CVMat<std::uint8_t>(const std::shared_ptr<CMap<std::uint8_t>> vMap) {
	_EARLY_RETURN(vMap->isValid() == false, "map wrapper error: map is invalid.", cv::Mat());

	cv::Mat Image(vMap->getWidth(), vMap->getHeight(), CV_8UC1);
	for (int i = 0; i < vMap->getWidth(); i++) {
		for (int k = 0; k < vMap->getHeight(); k++) {
			Image.at<std::uint8_t>(i, k) = vMap->getValue(i, k);
		}
	}

	return Image;
}


}


