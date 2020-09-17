#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "camera.hpp"
#include "sphere.hpp"

#include <iostream>

using ::rayTracer::objects::components::Color;
using ::rayTracer::objects::Sphere;
using ::rayTracer::objects::components::Ray;
using ::rayTracer::scene::Camera;
using ::rayTracer::objects::components::Vec3;

namespace {
    template<typename T>
    Color rayColor(const Ray<T> &r) {
        Sphere<double> sphere =
                Sphere<double>(Vec3<double>(0,0,-1), 0.5);
        auto t = sphere.hit(r);
        if (t > 0.0) {
            Vec3<T> N = Vec3<T>::unitVector(r.at(t) - Vec3(0, 0, -1));
            return Color(N.x+1, N.y+1, N.z+1) * 0.5;
        }
        Vec3<T> unitDirection = Vec3<T>::unitVector(r.getDirection());
        t = (unitDirection.y + 1.0) * 0.5;
        return Color(1.0, 1.0, 1.0) * (1.0 - t)
                    + Color(0.5, 0.7, 1.0) * t;
    }
}

int main() {
    // Image
    constexpr auto aspectRatio = Camera<double>::getAspectRatio();
    constexpr int imageWidth = 400;
    constexpr auto imageHeight = static_cast<int>(imageWidth / aspectRatio);

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            double u = static_cast<double>(i) / (imageWidth - 1);
            double v = static_cast<double>(j) / (imageHeight - 1);
            Ray<double> r = Camera<double>::getRay(u,v);
            Color pixelColor = ::rayColor(r);
            pixelColor.writeColor(std::cout, pixelColor);
        }
    }
    std::cerr << "\nDone.\n";
}
