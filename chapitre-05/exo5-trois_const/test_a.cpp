int main() {
    int x = 1, y = 2;
    const int* a = &x;
    a = &y;
    return 0;
}