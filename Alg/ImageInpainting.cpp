#include "pch.h"
#include "ImageInpainting.h"
#include "PMInterface.h"

using namespace alg;

bool CImageInpainting::run(const cv::Mat& vSrc, const cv::Mat& vMask, cv::Mat& voRes, EInpaintMode vMode) {
	_EARLY_RETURN(vSrc.size() != vMask.size(), "image inpainting error: src and mask is not the same size.", false);

	float Radius = 1.0f;

	switch (vMode) {
	case CV_TEALA:
		cv::inpaint(vSrc, vMask, voRes, Radius, CV_TEALA);
		break;
	case CV_NS:
		cv::inpaint(vSrc, vMask, voRes, Radius, CV_NS);
		break;
	case PM:
		voRes = PM::run(vSrc, vMask);
		break;
	default:
		break;
	}

	return true;

}
