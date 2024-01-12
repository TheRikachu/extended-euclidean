#include <iostream>
#include <tuple>

std::tuple<int, int, int ,int> GCD(int f, int g)
{
    int rLast = f;
    int sLast = 1;
    int tLast = 1;

    int r = g;
    int s = 0;
    int t = 1;

    int i = 1;
    while (r != 0)
    {
        int rHelp = r;
        int sHelp = s;
        int tHelp = t;

        int q = rLast / r;
        r = rLast - q * r;
        s = sLast - q * s;
        t = tLast - q * t;

        rLast = r;
        sLast = s;
        tLast = t;
        i++;
    }
    int l = i - 1;

    return std::make_tuple(l, r, s, t);
}

auto main(int argc, char *argv[]) -> int {

    int f = {1234};
    int g = {12};

    std::cout << "f: " << f << std::endl;
    std::cout << "g: " << g << std::endl;

    std::tuple<int, int, int, int> res = GCD(f, g);

    std::cout << std::endl;
    std::cout << "--GCD result--" << std::endl;
    std::cout << "l: " << std::get<0>(res) << std::endl;
    std::cout << "r: " << std::get<1>(res) << std::endl;
    std::cout << "s: " << std::get<2>(res) << std::endl;
    std::cout << "t: " << std::get<3>(res) << std::endl;

    return 0;
}
