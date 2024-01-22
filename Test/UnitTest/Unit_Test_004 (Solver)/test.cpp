#include "pch.h"

TEST(Solver, DT_ZeroMatrix) {
	int MatrixSize = 10;
	Eigen::MatrixXf A, B, X;

	A = Eigen::MatrixXf::Zero(MatrixSize, MatrixSize);
	B = Eigen::MatrixXf::Zero(MatrixSize, 1);

	core::CSparseLinearSolver Solver(A, B);
	for (int i = 0; i < magic_enum::enum_count<core::ESolverMode>(); i++) {
		ASSERT_DEATH(Solver.solve(static_cast<core::ESolverMode>(i)), ".*");
	}
}

TEST(Solver, NT_Identity) {
	int MatrixSize = 10;
	Eigen::MatrixXf A, B, X;

	A = Eigen::MatrixXf::Identity(MatrixSize, MatrixSize);
	B = Eigen::MatrixXf::Ones(MatrixSize, 1);

	core::CSparseLinearSolver Solver(A, B);
	for (int i = 0; i < magic_enum::enum_count<core::ESolverMode>(); i++) {
		X = Solver.solve(static_cast<core::ESolverMode>(i));
		ASSERT_EQ(X, B);
	}
}

TEST(Solver, NT_SimpleMatrix1) {
	Eigen::MatrixXf A(2, 2), X(2, 1), B(2, 1), GT(2, 1);

	A << -4, 1,
		1, -4;
	B << -3, -3;
	GT << 1, 1;

	core::CSparseLinearSolver Solver(A, B);
	for (int i = 0; i < 5; i++) {
		X = Solver.solve(static_cast<core::ESolverMode>(i));
		for (int k = 0; k < 2; k++)
			ASSERT_LT(std::fabsf(X(k, 0) - GT(k, 0)), EPSILON);
	}
}

TEST(Solver, NT_SimpleMatrix2) {
	Eigen::MatrixXf A(3, 3), X(3, 1), B(3, 1), GT(3, 1);

	A << -4, 1, 0,
		1, -4, 1,
		0, 1, -4;
	B << -3, -2, -3;
	GT << 1, 1, 1;

	core::CSparseLinearSolver Solver(A, B);
	for (int i = 0; i < 5; i++) {
		X = Solver.solve(static_cast<core::ESolverMode>(i));
		for (int k = 0; k < 3; k++)
			ASSERT_LT(std::fabsf(X(k, 0) - GT(k, 0)), EPSILON);
	}
}

TEST(Solver, NT_SimpleMatrix3) {
	Eigen::MatrixXf A(4, 4), X(4, 1), B(4, 1), GT(4, 1);

	A << -2, 1, 0, 0,
		1, -2, 0, 0,
		0, 0, -4, 1,
		1, 0, 1, -4;
	B << 0, 0, -3, -3;
	GT << 0, 0, 1, 1;

	core::CSparseLinearSolver Solver(A, B);
	for (int i = 0; i < 5; i++) {
		X = Solver.solve(static_cast<core::ESolverMode>(i));
		for (int k = 0; k < 3; k++)
			ASSERT_LT(std::fabsf(X(k, 0) - GT(k, 0)), EPSILON);
	}
}

TEST(Solver, NT_SimpleMatrix4) {
	Eigen::MatrixXf A(4, 4), X(4, 1), B(4, 1), GT(4, 1);

	A << -2, 1, 0, 0,
		1, -2, 0, 1,
		1, 0, -4, 1,
		0, 1, 0, -2;
	B << 0, 1, -3, -2;
	GT << 0, 0, 1, 1;

	core::CSparseLinearSolver Solver(A, B);
	for (int i = 0; i < 5; i++) {
		X = Solver.solve(static_cast<core::ESolverMode>(i));
		for (int k = 0; k < 3; k++)
			ASSERT_LT(std::fabsf(X(k, 0) - GT(k, 0)), EPSILON);
	}
}

