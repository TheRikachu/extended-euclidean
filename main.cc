#include <iostream>
#include <tuple>
#include <vector>

std::tuple<int, int, int ,int> GCD(int f, int g)
{
    int rLast = f;
    int sLast = 1;
    int tLast = 0;

    int r = g;
    int s = 0;
    int t = 1;

    std::cout << "i: 0, r: " << rLast << ", s: " << sLast << ", t: " << tLast << std::endl;

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

std::string PolyString(std::vector<int> poly)
{
    std::string str = "";
    if (poly[poly.size() - 1]) {
       str.append("x^" + std::to_string(poly.size() - 1));
    }
    for(int i = poly.size() - 2; i >= 0; --i)
    {
        if (i == 0 && poly[0])
        {
            str.append(" + 1");
        }
        else if (i == 1 && poly[1])
        {
            str.append(" + x");
        }
        else if (poly[i]) {
            str.append(" + x^" + std::to_string(i));
        }
    }
    return str;
}

std::tuple<int, int, int, int> GCD(std::vector<int> f, std::vector<int> g, int mod)
{
    std::vector<int> rLast = f;
    std::vector<int> sLast = {1};
    std::vector<int> tLast = {0};

    std::vector<int> r = g;
    std::vector<int> s = {0};
    std::vector<int> t = {1};

    std::cout << "i: 0, r: " << PolyString(rLast) << ", s: " << PolyString(sLast) << ", t: " << PolyString(tLast) << std::endl;

    int i = 1;
    while (r != 0)
    {
        auto rHelp = r;
        auto sHelp = s;
        auto tHelp = t;

        auto q = rLast / r;
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

    return std::make_tuple(0, 0, 0, 0);
}

auto main(int argc, char *argv[]) -> int {
    std::cout << "::Integer GCD::" << std::endl;

    int f = {1234567};
    int g = {123};

    std::cout << "f = " << f << std::endl;
    std::cout << "g = " << g << std::endl << std::endl;

    std::tuple<int, int, int, int> res = GCD(f, g);

    std::cout << std::endl;
    std::cout << "--GCD result (mod 2)--" << std::endl;
    std::cout << "l = " << std::get<0>(res) << std::endl;
    std::cout << "r = " << std::get<1>(res) << std::endl;
    std::cout << "s = " << std::get<2>(res) << std::endl;
    std::cout << "t = " << std::get<3>(res) << std::endl;
    std::cout << std::endl;

    std::cout << "::Poly GCD::" << std::endl;

    std::vector<int> fPoly = {1, 1, 0, 1, 1};
    std::vector<int> gPoly = {1, 0, 0, 0, 1};

    std::cout << "fPoly = " << PolyString(fPoly) << std::endl;
    std::cout << "gPoly = " << PolyString(gPoly) << std::endl;

    return 0;
}
