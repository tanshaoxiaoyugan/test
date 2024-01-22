#include "pch.h"

TEST(HeightMap, Basic_Function) {
	std::shared_ptr<core::CHeightMap> pHeightMap(new core::CHeightMap(10, 10, 1));
	EXPECT_EQ(pHeightMap->getWidth(), 10);
	EXPECT_EQ(pHeightMap->getHeight(), 10);
	EXPECT_EQ(pHeightMap->getArea(), 100);
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			EXPECT_EQ(pHeightMap->getValue(i, k), 1);
			pHeightMap->setValue(i, k, i + k);
		}
	}

	EXPECT_TRUE(MathUtil::isEqual(pHeightMap->getMax(), 18.0f));
	EXPECT_TRUE(MathUtil::isEqual(pHeightMap->getMin(), 0.0f));
	EXPECT_TRUE(MathUtil::isEqual(pHeightMap->getMaxId(), std::pair((std::uint32_t)9, (std::uint32_t)9)));
	EXPECT_TRUE(MathUtil::isEqual(pHeightMap->getMinId(), std::pair((std::uint32_t)0, (std::uint32_t)0)));
	EXPECT_TRUE(pHeightMap->isNoEmpty());
	EXPECT_TRUE(pHeightMap->isValid());
	
	for (int i = 0; i < pHeightMap->getWidth(); i++) {
		for (int k = 0; k < pHeightMap->getHeight(); k++) {
			auto r1 = pHeightMap->calcGradient(i, k, 0);
			auto r2 = pHeightMap->calcGradient(i, k, 1);
			EXPECT_TRUE(r1.has_value() && r2.has_value());
			EXPECT_EQ(r1.value(), 1);
			EXPECT_EQ(r2.value(), 1);
		}
	}

	pHeightMap->setEmpty(5, 5);
	EXPECT_TRUE(pHeightMap->isEmpty(5, 5));
	EXPECT_EQ(pHeightMap->getEmptyCount(), 1);
}

TEST(GradientMap, Basic_Function) {
	std::shared_ptr<core::CGradientMap> pGradientMap(new core::CGradientMap(10, 10, vec2f {1, 1}));
	EXPECT_EQ(pGradientMap->getWidth(), 10);
	EXPECT_EQ(pGradientMap->getHeight(), 10);
	EXPECT_EQ(pGradientMap->getArea(), 100);
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			EXPECT_TRUE(MathUtil::isEqual(pGradientMap->getValue(i, k), vec2f {1, 1}));
			pGradientMap->setValue(i, k, vec2f { (float)(i + k), (float)(i + k) });
		}
	}

	EXPECT_TRUE(pGradientMap->isNoEmpty());
	EXPECT_TRUE(pGradientMap->isValid());

	pGradientMap->setEmpty(5, 5);
	EXPECT_TRUE(pGradientMap->isEmpty(5, 5));
	EXPECT_EQ(pGradientMap->getEmptyCount(), 1);
}

TEST(MaskMap, Basic_Function) {
	std::shared_ptr<core::CMaskMap> pMaskMap(new core::CMaskMap(10, 10, 255));
	EXPECT_EQ(pMaskMap->getWidth(), 10);
	EXPECT_EQ(pMaskMap->getHeight(), 10);
	EXPECT_EQ(pMaskMap->getArea(), 100);
	EXPECT_EQ(pMaskMap->getEmptyCount(), 100);
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			EXPECT_TRUE(MathUtil::isEqual(pMaskMap->getValue(i, k), (std::uint8_t)255));
			pMaskMap->setValue(i, k, 0);
		}
	}

	EXPECT_TRUE(pMaskMap->isNoEmpty());
	EXPECT_TRUE(pMaskMap->isValid());

	pMaskMap->setEmpty(5, 5);
	EXPECT_TRUE(pMaskMap->isEmpty(5, 5));
	EXPECT_EQ(pMaskMap->getEmptyCount(), 1);
}

TEST(MapUtil, Basic_Function) {
	std::shared_ptr<core::CHeightMap> pHeightMap(new core::CHeightMap(10, 10, 1));
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			pHeightMap->setValue(i, k, i + k * 2 + 1);
		}
	}

	pHeightMap->setEmpty(5, 5);
	pHeightMap->setEmpty(4, 6);

	auto pGradient = core::MapUtil::geneGradient(pHeightMap);
	auto pGog = core::MapUtil::geneGradient(pGradient);
	auto pMask1 = core::MapUtil::geneMask<float>(pHeightMap);
	auto pMask2 = core::MapUtil::geneMask<vec2f>(pGradient);
	auto pMask3 = core::MapUtil::geneMask<vec2f>(pGog);

	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if ((i == 5 && k == 5) || (i == 4 && k == 6)) {
				EXPECT_TRUE(pMask1->isEmpty(i, k));
				EXPECT_TRUE(pMask2->isEmpty(i, k));
				EXPECT_TRUE(pMask3->isEmpty(i, k));
			}
			else {
				EXPECT_FALSE(pMask1->isEmpty(i, k));
				EXPECT_FALSE(pMask2->isEmpty(i, k));
				EXPECT_FALSE(pMask3->isEmpty(i, k));
				EXPECT_TRUE(MathUtil::isEqual(pGradient->getValue(i, k), vec2f { 1, 2 }));
				EXPECT_TRUE(MathUtil::isEqual(pGog->getValue(i, k), vec2f { 0, 0 }));
			}
		}
	}
}
