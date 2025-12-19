// 


// ...existing code...
#include "bigint.hpp"
#include <iostream>

static void section(const char* title) {
    std::cout << "\n================ " << title << " ================\n";
}

int main() {
    section("Construcción");
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);
    std::cout << "a = " << a << "\n"
              << "b = " << b << "\n"
              << "c = " << c << "\n"
              << "d = " << d << "\n"
              << "e = " << e << "\n";

    section("Suma");
    std::cout << "a + b = " << (a + b) << "   [42 + 21]\n";
    std::cout << "a + c = " << (a + c) << "   [42 + 0]\n";

    section("Suma acumulada (+=)");
    std::cout << "c antes: " << c << "\n";
    std::cout << "(c += a) = " << (c += a) << "   -> c ahora: " << c << "\n";

    section("Incrementos");
    std::cout << "b antes: " << b << "\n";
    std::cout << "++b = " << ++b << "   -> b ahora: " << b << "\n";
    std::cout << "b++ = " << b++ << "   -> b ahora: " << b << "\n";

    section("Digitshift");
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << "\n";
    std::cout << "(d <<= 4) = " << (d <<= 4) << "   -> d: " << d << "\n";
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << "   -> d: " << d << "\n";

    section("Comparaciones");
    std::cout << "(d <  a) = " << (d <  a) << "\n";
    std::cout << "(d <= a) = " << (d <= a) << "\n";
    std::cout << "(d >  a) = " << (d >  a) << "\n";
    std::cout << "(d >= a) = " << (d >= a) << "\n";
    std::cout << "(d == d) = " << (d == d) << "\n";
    std::cout << "(d != a) = " << (d != a) << "\n";

    section("Extra");
    bigint x(12345678), y(5);
    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "(x << y) = " << (x << y) << "   | x: " << x << ", y: " << y << "\n";
    std::cout << "(x >>= y) = " << (x >>= y) << "   | x: " << x << ", y: " << y << "\n";
    std::cout << "(x >= y) = " << (x >= y) << "   | x: " << x << ", y: " << y << "\n";

    std::cout << "\n================ Fin ================\n";
    return 0;
}
// ...existing code...