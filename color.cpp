#include "color.hpp"


void ::rayTracer::objects::components::Color::writeColor(std::ostream &out, Color pixel_color) const
{
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.r) << ' '
        << static_cast<int>(255.999 * pixel_color.g) << ' '
        << static_cast<int>(255.999 * pixel_color.b) << '\n';
}
::rayTracer::objects::components::Color::Color(double rr, double gg, double bb) : r(rr), g(gg), b(bb){}