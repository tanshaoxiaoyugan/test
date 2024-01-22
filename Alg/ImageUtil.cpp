#include "pch.h"
#include "ImageUtil.h"

float ImageUtil::calcSSIM(const cv::Mat& a, const cv::Mat& b) {
	const float C1 = 6.5025f, C2 = 58.5225f;
	int d = CV_32F;
	cv::Mat I1, I2;
	a.convertTo(I1, d);
	b.convertTo(I2, d);
	cv::Mat I1_2 = I1.mul(I1);
	cv::Mat I2_2 = I2.mul(I2);
	cv::Mat I1_I2 = I1.mul(I2);
	cv::Mat mu1, mu2;
	cv::GaussianBlur(I1, mu1, cv::Size(11, 11), 1.5f);
	cv::GaussianBlur(I2, mu2, cv::Size(11, 11), 1.5f);
	cv::Mat mu1_2 = mu1.mul(mu1);
	cv::Mat mu2_2 = mu2.mul(mu2);
	cv::Mat mu1_mu2 = mu1.mul(mu2);
	cv::Mat sigma1_2, sigam2_2, sigam12;
	cv::GaussianBlur(I1_2, sigma1_2, cv::Size(11, 11), 1.5f);
	sigma1_2 -= mu1_2;

	cv::GaussianBlur(I2_2, sigam2_2, cv::Size(11, 11), 1.5f);
	sigam2_2 -= mu2_2;

	cv::GaussianBlur(I1_I2, sigam12, cv::Size(11, 11), 1.5f);
	sigam12 -= mu1_mu2;
	cv::Mat t1, t2, t3;
	t1 = 2 * mu1_mu2 + C1;
	t2 = 2 * sigam12 + C2;
	t3 = t1.mul(t2);

	t1 = mu1_2 + mu2_2 + C1;
	t2 = sigma1_2 + sigam2_2 + C2;
	t1 = t1.mul(t2);

	cv::Mat ssim_map;
	cv::divide(t3, t1, ssim_map);
	cv::Scalar mssim = cv::mean(ssim_map);

	float ssim = (mssim.val[0] + mssim.val[1] + mssim.val[2]) / 3;
	return ssim;
}
