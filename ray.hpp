#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include "vec3.hpp"
namespace rayTracer {
    namespace objects {
        namespace components {
            template<typename T>
            class Ray {
            public:
                constexpr Ray(const Vec3<T> &origin, const Vec3<T> &direction) : orig(origin), dir(direction) {}

                template<typename T2,
                        typename T3,
                        typename = std::enable_if_t<std::is_convertible_v<T2, T>>,
                        typename = std::enable_if_t<std::is_convertible_v<T3, T>>>
                constexpr explicit Ray(T2 origin, T3 direction)
                        : orig(std::move(static_cast<T>(origin))),
                          dir(std::move(static_cast<T>(direction))) {}

                Vec3<T> getOrigin() const { return orig; }

                Vec3<T> getDirection() const { return dir; }

                Vec3<T> at(T t) const {
                    return orig + (dir * t);
                }
            private:
                Vec3<T> orig;
                Vec3<T> dir;
            };

        }
    }
}
#endif //RAYTRACER_RAY_HPP
