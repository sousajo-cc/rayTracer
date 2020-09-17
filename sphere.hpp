#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "vec3.hpp"
#include "ray.hpp"
#include "visibleObject.hpp"

namespace rayTracer {
    namespace objects {
        template<typename T>
        class Sphere : public ::rayTracer::objects::VisibleObject<T> {
            ::rayTracer::objects::components::Vec3<T> center;
            T radius;
        public:
            constexpr Sphere(const ::rayTracer::objects::components::Vec3<T>& center, T radius) :
                                                center(center), radius(radius){};

            constexpr T hit(const ::rayTracer::objects::components::Ray<T>& r) {
                ::rayTracer::objects::components::Vec3<T> oc = r.getOrigin() - center;
                auto a = r.getDirection().lengthSquared();
                auto halfB = oc * r.getDirection();
                auto c = oc.lengthSquared() - radius * radius;
                auto discriminant = halfB * halfB - a * c;
                return discriminant < 0 ? -1 : (-halfB - std::sqrt(discriminant) ) / (a);
            }
        };
    }
}

#endif //RAYTRACER_SPHERE_HPP
