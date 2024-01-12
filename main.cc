#include <iostream>
#include <tuple>

std::tuple<int, int, int ,int> GCD(int f, int g)
{
    int rLast = f;
    int sLast = 1;
    int tLast = 0;

    int r = g;
    int s = 0;
    int t = 1;

    std::cout << "i: 0" << ", r: " << rLast << ", s: " << sLast << ", t: " << tLast << std::endl;

    int i = 1;
    while (r != 0)
    {
        int rHelp = r;
        int sHelp = s;
        int tHelp = t;

        int q = rLast / r;
        std::cout << "i: " << i << ", r: " << r << ", s: " << s << ", t: " << t << ", q: " << q << std::endl;
        r = rLast - q * r;
        s = sLast - q * s;
        t = tLast - q * t;

        rLast = rHelp;
        sLast = sHelp;
        tLast = tHelp;
        i++;
    }
    std::cout << "i: " << i << ", r: " << r << ", s: " << s << ", t: " << t << std::endl;
    int l = i - 1;

    return std::make_tuple(l, r, s, t);
}

auto main(int argc, char *argv[]) -> int {

    int f = {1234567};
    int g = {123};

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
