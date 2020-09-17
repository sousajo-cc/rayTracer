#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include <iostream>
namespace rayTracer {
    namespace objects {
        namespace components {
            class Color {
            public:
                Color(double rr = 0, double gg = 0, double bb = 0);
                double r, g, b;
                void writeColor(std::ostream &out, Color pixel_color) const;
                Color operator*(double s) const { return Color(r * s, g * s, b * s); };
                Color operator+(const Color &o) const { return Color(r + o.r, g + o.g, b + o.b); };
            };
        }
    }
}
#endif //RAYTRACER_COLOR_HPP
