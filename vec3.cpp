#include "vec3.hpp"

template<typename T>
Vec3<T> Vec3<T>::operator-() const
{
    return Vec3<T>(-x, -y, -z);
}

template<typename T>
template<typename T2>
Vec3<decltype(T{}+T2{})> Vec3<T>::operator+(const Vec3<T2>& other) const
{
    return Vec3<decltype(T{}+T2{})>(x + other.x, y + other.y, z + other.z);
}

template<typename T>
template<typename T2>
Vec3<decltype(T{}+T2{})> Vec3<T>::operator-(const Vec3<T2>& other) const
{
    return Vec3<decltype(T{}-T2{})>(x - other.x, y - other.y, z - other.z);
}


template<typename T>
template<typename T2>
decltype(T{}*T2{}) Vec3<T>::operator*(const Vec3<T2>& other) const
{
    return static_cast<decltype(T{}*T2{})>(x*other.x + y*other.y + z*other.z);
}

template<typename T> Vec3<T> Vec3<T>::operator/(T s) const
{
    return Vec3<T>(x/s, y/s, z/s);
}

template<typename T> Vec3<T> Vec3<T>::operator*(T s) const
{
    return Vec3<T>(x*s, y*s, z*s);
}


template<typename T>
static Vec3<T> unit_vector(Vec3<T> v)
{
    return v / v.length();
}