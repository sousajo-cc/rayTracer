#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "vec3.hpp"
#include "ray.hpp"

#include <iostream>
namespace rayTracer{
    namespace scene {
        template<typename T>
        class Camera {
            static constexpr auto aspect_ratio = 16.0 / 9.0;
            static constexpr ::rayTracer::objects::components::Vec3<int> origin = ::rayTracer::objects::components::Vec3<int>();
            static constexpr auto viewport_height = 2.0;
            static constexpr auto focal_length = 1.0;
            static constexpr auto viewport_width = aspect_ratio * viewport_height;
            static constexpr ::rayTracer::objects::components::Vec3<T> vertical =
                                                ::rayTracer::objects::components::Vec3<T>(0, viewport_height, 0);
            static constexpr ::rayTracer::objects::components::Vec3<T> horizontal =
                                                ::rayTracer::objects::components::Vec3<T>(viewport_width, 0, 0);
            static constexpr ::rayTracer::objects::components::Vec3<T> lower_left_corner =
                                        origin - horizontal / 2 - vertical / 2 - ::rayTracer::objects::components::Vec3<T>(0, 0, focal_length);

        public:
            static ::rayTracer::objects::components::Ray<T> getRay(double u, double v) {
                return ::rayTracer::objects::components::Ray<T>{
                    origin, (lower_left_corner + (horizontal * u)) + (-origin + (vertical * v))
                };
            }

            static constexpr auto getAspectRatio() {
                return aspect_ratio;
            }
        };
    }
}

#endif //RAYTRACER_CAMERA_HPP
