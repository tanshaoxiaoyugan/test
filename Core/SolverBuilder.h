#pragma once

namespace core {

template <typename T>
using ptr = std::shared_ptr<T>;

class CHeightMap;
class CGradientMap;
class CMaskMap;

class CSolverBuilder {
public:

	bool run(const ptr<CHeightMap> vRaw, const ptr<CGradientMap> vGoG, const ptr<CGradientMap> vGradient);
	void dumpMatrix(Eigen::MatrixXf& voCoeff, Eigen::MatrixXf& voConst) { voCoeff = m_Coeff; voConst = m_Const; }
	void dumpUnknowns(std::vector<Eigen::Vector2f>& voUnknowns) { voUnknowns = m_Unknowns; }

private:
	void __init();
	void __setUpEachEquation(int vIndex);
	std::optional<int> __findUnknownIndex(const Eigen::Vector2f& vPos);
	float __handleNeighbor(const Eigen::Vector2f& vPos, float vConstNumber, int vIndex, float vCoeff);

private:
	ptr<CHeightMap>		m_Raw;
	ptr<CMaskMap>		m_Mask;
	ptr<CGradientMap>	m_Gradient;
	ptr<CGradientMap>	m_GoG;

	Eigen::MatrixXf		m_Coeff;
	Eigen::MatrixXf		m_Const;

	std::vector<Eigen::Vector2f> m_Unknowns;
};

}
 