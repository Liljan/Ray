#pragma once

#include <cmath>
#include <assert.h>

class Vec3
{
public:

	// ------------ Constructors & Destructors ------------
	Vec3() = delete;

	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	~Vec3() {};

	// ------------ Getters & Setters ------------
	// ------------ Helper Methods ------------
	const Vec3& Zero()
	{
		return Vec3(0, 0, 0);
	}

	static float Dot(const Vec3& v1, const Vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static Vec3 Cross(const Vec3& v1, const Vec3& v2)
	{
		return Vec3(v1.y*v2.z - v1.z*v2.y,
					v1.z*v2.x - v1.x*v2.z,
					v1.x*v2.y - v1.y*v2.x);
	}

	float Magnitude() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	void Normalize()
	{
		float mag = Magnitude();

		if (mag != 0.0f)
		{
			x /= mag;
			y /= mag;
			z /= mag;
		}
	}

	Vec3 Normalized()
	{
		Vec3 normalized(x, y, z);
		normalized.Normalize();
		return normalized;
	}

	static float Distance(const Vec3& v1, const Vec3& v2)
	{
		return sqrt((v1.x - v2.y) + 
					(v1.y - v2.y) +
					(v1.z - v2.z));
	}

	static float DistanceSquared(const Vec3& v1, const Vec3& v2)
	{
		return	(v1.x - v2.y) +
				(v1.y - v2.y) +
				(v1.z - v2.z);
	}

	Vec3 Ray(const Vec3& dir, float mag)
	{
		
	}

	// ------------ Operators ------------
	void operator=(const Vec3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vec3 operator+(const Vec3& v)
	{
		return Vec3(x + v.x, y + v.y, z + v.z);
	}

	void operator+=(const Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vec3 operator-(const Vec3& v)
	{
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	void operator-=(const Vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vec3 operator*(float f)
	{
		return Vec3(f*x, f*y, f*z);
	}

	void operator *=(float f)
	{
		x *= f;
		y *= f;
		z *= f;
	}

	Vec3 operator/(float f)
	{
		assert(f != 0);
		return Vec3(x / f, y / f, z / f);
	}

	void operator /=(float f)
	{
		assert(f != 0);

		x /= f;
		y /= f;
		z /= f;
	}

public:
	// ------------ Members ------------

	float x, y, z;
};

