#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <string>

class Polynomial {
    private:
        std::vector<int> coeffs_;
        int modulus_;

    public:
        Polynomial(std::vector<int> coeffs, int modulus);

        Polynomial(const Polynomial &that);

        ~Polynomial();

        std::vector<int> GetCoeffs() const;

        int GetModulus() const;

        int GetDegree() const;

        Polynomial &operator=(const Polynomial &that);

        Polynomial &operator+=(const Polynomial &that);

        friend Polynomial operator+(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator*=(const Polynomial &that);

        friend Polynomial operator*(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator/=(const Polynomial &that);

        friend Polynomial operator/(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator%=(const Polynomial &that);

        friend Polynomial operator%(Polynomial lhs, const Polynomial &rhs);

        int operator[](int i);

        std::string ToString();
};

#endif // POLYNOMIAL_H_
