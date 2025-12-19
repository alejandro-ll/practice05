// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/23 14:27:41 by fatkeski          #+#    #+#             */
// /*   Updated: 2025/07/26 18:22:04 by fatkeski         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "bigint.hpp"

// int main(void)
// {
// 	const bigint a(42);
// 	bigint b(21), c, d(1337), e(d);

// 	// base test
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "d = " << d << std::endl;
// 	std::cout << "e = " << e << std::endl;

// 	std::cout << "a + b = " << a + b << std::endl;
// 	std::cout << "a + c = " << a + c << std::endl;
// 	std::cout << "(c += a) = " << (c += a) << std::endl;

// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "++b = " << ++b << std::endl;
// 	std::cout << "b++ = " << b++ << std::endl;

// 	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042
// 	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
// 	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
// 	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;

// 	std::cout << "a = " << a << std::endl; // a = 42
// 	std::cout << "d = " << d << std::endl; // d = 5348

// 	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
// 	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
// 	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
// 	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
// 	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
// 	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

// 	// extra
// 	bigint x(12345678); bigint y(5);
// 	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
// 	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
// 	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

// 	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
// 	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

// 	return (0);
// }

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