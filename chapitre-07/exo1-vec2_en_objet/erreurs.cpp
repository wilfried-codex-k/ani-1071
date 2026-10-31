struct Vec2 {
    double x, y;
    Vec2 operator+(Vec2 b) const { return {x + b.x, y + b.y}; }
    Vec2 operator*(double k) const { return {x * k, y * k}; }
};

int main() {
    Vec2 a = {1, 2};
    Vec2 b = {3, 4};
    a += b;
    Vec2 c = 2.0 * a;
    return 0;
}