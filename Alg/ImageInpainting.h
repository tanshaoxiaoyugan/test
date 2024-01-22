#pragma once

namespace alg {

enum EInpaintMode {
	CV_TEALA,
	CV_NS,
	PM,
};

class CImageInpainting {
public:
	CImageInpainting() = default;
	~CImageInpainting() = default;

	bool run(const cv::Mat& vSrc, const cv::Mat& vMask, cv::Mat& voRes, EInpaintMode vMode);

private:


};

}
