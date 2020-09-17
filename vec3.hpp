#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include <iostream>
#include <type_traits>

namespace rayTracer {
    namespace objects {
        namespace components {
            template<typename T>
            class Vec3 {
            public:
                T x, y, z;

                constexpr Vec3<T>() : x(0), y(0), z(0) {};
                constexpr Vec3<T>(const T &v) : x(v), y(v), z(v) {};
                constexpr Vec3<T>(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {};

                /*
                 * TODO: dont be a lazy ass and learn concepts
                 * */
                template<typename T2,
                        typename = std::enable_if_t<std::is_convertible_v<T2, T>>>
                constexpr Vec3<T>(const Vec3<T2> &other) : x(other.x), y(other.y), z(other.z) {};

                template<typename T2,
                        typename = std::enable_if_t<std::is_convertible_v<T2, T>>>
                constexpr Vec3<T>(Vec3<T2> &&other)
                        : x(static_cast<T>(std::move(other.x))),
                          y(static_cast<T>(std::move(other.y))),
                          z(static_cast<T>(std::move(other.z))) {};

                ~Vec3() = default;

                template<typename T2>
                constexpr Vec3<T> &operator=(const Vec3<T2> &other) {
                    x = other.x;
                    y = other.y;
                    z = other.z;
                    return *this;
                }

                template<typename T2>
                constexpr Vec3<T> &operator=(Vec3<T2> &&other) {
                    x = static_cast<T>(std::move(other.x));
                    y = static_cast<T>(std::move(other.y));
                    z = static_cast<T>(std::move(other.z));
                    return *this;
                }

                constexpr Vec3<T> operator-() const {
                    return Vec3<T>(-x, -y, -z);
                }

                template<typename T2>
                constexpr Vec3<decltype(T{} + T2{})> operator+(const Vec3<T2> &other) const {
                    return Vec3<decltype(T{} + T2{})>(x + other.x, y + other.y, z + other.z);
                }

                template<typename T2>
                constexpr Vec3<decltype(T{} - T2{})> operator-(const Vec3<T2> &other) const {
                    return Vec3<decltype(T{} - T2{})>(x - other.x, y - other.y, z - other.z);
                }

                template<typename T2>
                constexpr decltype(T{} * T2{}) operator*(const Vec3<T2> &other) const {
                    return static_cast<decltype(T{} * T2{})>(x * other.x + y * other.y + z * other.z);
                }

                constexpr Vec3<T> operator/(T s) const {
                    return Vec3<T>(x / s, y / s, z / s);
                }

                constexpr Vec3<T> operator*(T s) const {
                    return Vec3<T>(x * s, y * s, z * s);
                }


                decltype(T{}) length() const {
                    decltype(T{}) w = *this * *this;
                    return std::sqrt(w);
                }

                decltype(T{}) lengthSquared() const {
                    return *this * *this;
                }

                static Vec3<T> unitVector(Vec3<T> v) {
                    return v / v.length();
                }
            };
        }
    }
}
#endif //RAYTRACER_VEC3_H
