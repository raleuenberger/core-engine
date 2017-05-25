#include "Color.h"

Color::Color()
{
}

Color::Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(a)
{
}

Color::Color(float r, float g, float b) : R(r), G(g), B(b), A(1.0f)
{
}

Color::~Color()
{
}
