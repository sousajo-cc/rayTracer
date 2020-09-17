#ifndef RAYTRACER_VISIBLEOBJECT_HPP
#define RAYTRACER_VISIBLEOBJECT_HPP

#include "ray.hpp"
#include "pointRecord.hpp"

namespace rayTracer{
    namespace objects {
        template<typename T>
        class VisibleObject {
        public:
            virtual bool hit(const ::rayTracer::objects::components::Ray<T>& r,
                    double distMin, double distMax, ::rayTracer::objects::utils::PointRecord<T>& rec) const = 0;
            virtual ~VisibleObject() = default;

        };
    }
}

#endif //RAYTRACER_VISIBLEOBJECT_HPP
