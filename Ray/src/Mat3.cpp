#include "Vec3.h"
#include "Mat3.h"

Mat4x4 Mat4x4::Rotation(float ux, float uy, float uz, float fi)
{
	float sin = sinf(fi);
	float cos = cosf(fi);
	float oneMinusCos = 1.0f - cos;

	return Mat4x4(
		cos + ux*ux*oneMinusCos,
		ux*uy*oneMinusCos,
		ux*uz*oneMinusCos+uy*sin,
		0,
		uy*ux*oneMinusCos+uz*sin,
		cos+uy*uy*oneMinusCos,
		uy*uz*oneMinusCos-ux*sin,
		0,
		uz*ux*oneMinusCos-uy*sin,
		uz*uy*oneMinusCos+ux*sin,
		cos+uz*uz*oneMinusCos,
		0,

		0, 0, 0, 1);
}
