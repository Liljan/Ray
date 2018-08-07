#include "Vec3.h"

int main()
{
	Vec3 a(1.0f, 0.0f,0.0f);
	Vec3 b = a;

	b *= 10.0f;
	b /= 10.0f;

	b *= 123.123f;
	b.Normalized();

	return 0;
}