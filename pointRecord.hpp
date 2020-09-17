#ifndef RAYTRACER_POINTRECORD_HPP
#define RAYTRACER_POINTRECORD_HPP


#include "vec3.hpp"

namespace rayTracer {
    namespace objects {
        namespace utils {
            template<typename T>
            class PointRecord {
            public:
                double dist;
                ::rayTracer::objects::components::Vec3<T> normal;
                ::rayTracer::objects::components::Vec3<T> pos;
            };
        }
    }
}
#endif //RAYTRACER_POINTRECORD_HPP
