#include "pch.h"

TEST(ImageInpainting, GrayScaleImage) {
	const std::string InputDir = "Images/Input/";
	const std::string OutputDir = "Images/Output/";

	for (int i = 1; i <= 4; i++) {
		cv::Mat Src = cv::imread(InputDir+ std::to_string(i) +"-hole.png", cv::IMREAD_GRAYSCALE);
		cv::Mat Mask = cv::imread(InputDir+ std::to_string(i) +"-mask.png", cv::IMREAD_GRAYSCALE);
		cv::Mat GT = cv::imread(InputDir+ std::to_string(i) +"-gt.png", cv::IMREAD_GRAYSCALE);
		cv::Mat ResTeala, ResNS, ResPM;

		alg::CImageInpainting Inpainter;
		EXPECT_TRUE(Inpainter.run(Src, Mask, ResTeala, alg::CV_TEALA));
		EXPECT_TRUE(Inpainter.run(Src, Mask, ResNS, alg::CV_NS));
		EXPECT_TRUE(Inpainter.run(Src, Mask, ResPM, alg::PM));

		cv::imwrite(OutputDir + std::to_string(i) + "-telea.png", ResTeala);
		cv::imwrite(OutputDir + std::to_string(i) + "-ns.png", ResNS);
		cv::imwrite(OutputDir + std::to_string(i) + "-pm.png", ResPM);

		log("Teala: " + std::to_string(ImageUtil::calcSSIM(GT, ResTeala)));
		log("NS: " + std::to_string(ImageUtil::calcSSIM(GT, ResNS)));
		log("PM: " + std::to_string(ImageUtil::calcSSIM(GT, ResPM)));
	}
}