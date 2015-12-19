#ifndef TXZM_VEC3_H
#define TXZM_VEC3_H

#include <cmath>
#include <iostream>

class Vec3
{
public:
	float x,y,z;

	Vec3():x(0.0f),y(0.0f),z(0.0f)
	{
	}

	Vec3(const Vec3 &v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	Vec3(float vx,float vy,float vz):x(vx),y(vy),z(vz)
	{
	}

	Vec3 &operator=(const Vec3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	bool operator==(const Vec3 &v) const
	{
		return x==v.x&&y==v.y&&z==v.z;
	}

	bool operator!=(const Vec3 &v) const
	{
		return x!=v.x||y!=v.y||z!=v.z;
	}

	Vec3 operator-() const
	{
		return Vec3(-x,-y,-z);
	}

	Vec3 operator+(const Vec3 &v) const
	{
		return Vec3(x+v.x,y+v.y,z+v.z);
	}

	Vec3 operator-(const Vec3 &v) const
	{
		return Vec3(x-v.x,y-v.y,z-v.z);
	}

	Vec3 operator*(float a) const
	{
		return Vec3(a*x,a*y,a*z);
	}

	Vec3 operator/(float a) const
	{
		float oneOverA = 1.0f/a;
		return (*this)*oneOverA;
	}

	float operator*(const Vec3 &v)const
	{
		return x*v.x+y*v.y+z*v.z;	
	}

	Vec3 &operator+=(const Vec3 &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vec3 &operator-=(const Vec3 &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vec3 &operator*=(float a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}

	Vec3 &operator/=(float a)
	{
		float oneOverA = 1.0f/a;
		return (*this)*=oneOverA;
	}

	void zero()
	{
		x = y = z = 0.0f;
	}

	void normalize()
	{
		float magSq = x*x + y*y+z*z;
		if (magSq>0.0f)
		{
			float oneOverMag = 1.0f/sqrtf(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

};

inline float vecMag(const Vec3 &v)
{
	return sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
}

inline Vec3 crossProduct(const Vec3 &a,const Vec3 &b)
{
	float x = a.y*b.z - a.z*b.y;
	float y = a.z*b.x -a.x*b.z;
	float z = a.x*b.y - b.x*a.y;
	return Vec3(x,y,z);
}

inline Vec3 operator*(float a,const Vec3 &v)
{
	return v*a;
}

inline float distance(const Vec3 &a,const Vec3 &b)
{
	float x = b.x-a.x;
	float y = b.y - a.y;
	float z = b.z - a.z;
	return sqrtf(x*x+y*y+z*z);
}

inline void printVec(const Vec3 &v)
{
	std::cout << "[" << v.x <<", "<<v.y << ", " << v.z << "]"<<std::endl;
}

#endif