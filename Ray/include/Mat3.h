#pragma once
#include <cmath>

class Vec3;

class Mat4x4
{
public:

	// ------------ Constructors & Destructors ------------
	Mat4x4() = delete;

	Mat4x4(float f11, float f12, float f13, float f14,
		float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34,
		float f41, float f42, float f43, float f44)
	{
		this->f11 = f11;
		this->f12 = f12;
		this->f13 = f13;
		this->f14 = f14;
		this->f21 = f21;
		this->f22 = f22;
		this->f23 = f23;
		this->f24 = f24;
		this->f31 = f31;
		this->f32 = f32;
		this->f33 = f33;	
		this->f34 = f34;
		this->f41 = f41;
		this->f42 = f42;
		this->f43 = f43;
		this->f44 = f44;
	}

	~Mat4x4() {};

	// ------------ Getters & Setters ------------
	// ------------ Helper Methods ------------
	static Mat4x4 Unit()
	{
		return Mat4x4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
	}

	static Mat4x4 Translation(float x, float y, float z)
	{
		return Mat4x4(
			0, 0, 0, x,
			0, 0, 0, y,
			0, 0, 0, z,
			0, 0, 0, 1);
	}

	static Mat4x4 Scale(float x, float y, float z)
	{
		return Mat4x4(
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1);
	}

	static Mat4x4 Rotation(float ux, float uy, float rz, float fi);

	// ------------ Operators ------------
	void operator=(const Mat4x4& m)
	{
		f11 = m.f11;
		f12 = m.f12;
		f13 = m.f13;
		f14 = m.f14;

		f21 = m.f21;
		f22 = m.f22;
		f23 = m.f23;
		f24 = m.f24;

		f31 = m.f31;
		f32 = m.f32;
		f33 = m.f33;
		f34 = m.f34;

		f41 = m.f41;
		f42 = m.f42;
		f43 = m.f43;
		f44 = m.f44;
	}

	Mat4x4 operator*(const Mat4x4& m)
	{
		return Mat4x4(
			f11*m.f11 + f12*m.f21 + f13*m.f31 + f14*m.f41,
			f11*m.f12 + f12*m.f22 + f13*m.f32 + f14*m.f42,
			f11*m.f13 + f12*m.f23 + f13*m.f33 + f14*m.f43,
			f11*m.f14 + f12*m.f24 + f13*m.f34 + f14*m.f44,

			f21*m.f11 + f22*m.f21 + f23*m.f31 + f24*m.f41,
			f21*m.f12 + f22*m.f22 + f23*m.f32 + f24*m.f42,
			f21*m.f13 + f22*m.f23 + f23*m.f33 + f24*m.f43,
			f21*m.f14 + f22*m.f24 + f23*m.f34 + f24*m.f44,

			f31*m.f11 + f32*m.f21 + f33*m.f31 + f34*m.f41,
			f31*m.f12 + f32*m.f22 + f33*m.f32 + f34*m.f42,
			f31*m.f13 + f32*m.f23 + f33*m.f33 + f34*m.f43,
			f31*m.f14 + f32*m.f24 + f33*m.f34 + f34*m.f44,

			f41*m.f11 + f42*m.f21 + f43*m.f31 + f44*m.f41,
			f41*m.f12 + f42*m.f22 + f43*m.f32 + f44*m.f42,
			f41*m.f13 + f42*m.f23 + f43*m.f33 + f44*m.f43,
			f41*m.f14 + f42*m.f24 + f43*m.f34 + f44*m.f44
		);
	}


public:
	// ------------ Members ------------

	float f11, f12, f13, f14,
		  f21, f22, f23, f24,
		  f31, f32, f33, f34,
		  f41, f42, f43, f44;
};

