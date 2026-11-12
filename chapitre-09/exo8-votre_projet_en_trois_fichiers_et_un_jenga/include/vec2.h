#pragma once

namespace ani
{
    struct Vec2
    {
        double x;
        double y;
    };

    Vec2 add(Vec2 a, Vec2 b);
    double dot(Vec2 a, Vec2 b);
    double length(Vec2 v);
}
