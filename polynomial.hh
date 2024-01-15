#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <string>

class Polynomial {
    private:
        std::vector<int> coeffs_;
        int modulus_;

    public:
        Polynomial(int size, int modulus);

        Polynomial(std::vector<int> coeffs, int modulus);

        Polynomial(const Polynomial &that);

        ~Polynomial();

        int &operator[](std::size_t idx);
        const int &operator[](std::size_t idx) const;

        Polynomial &operator=(const Polynomial &that);

        Polynomial &operator+=(const Polynomial &that);

        friend Polynomial operator+(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator-=(const Polynomial &that);

        friend Polynomial operator-(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator*=(const Polynomial &that);

        friend Polynomial operator*(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator/=(const Polynomial &that);

        friend Polynomial operator/(Polynomial lhs, const Polynomial &rhs);

        Polynomial &operator%=(const Polynomial &that);

        friend Polynomial operator%(Polynomial lhs, const Polynomial &rhs);

        std::vector<int> GetCoeffs() const;

        int GetModulus() const;

        int GetDegree() const;

        /* Leading Coefficient */
        int LC() const;

        std::string ToString() const;
};

#endif // POLYNOMIAL_H_
