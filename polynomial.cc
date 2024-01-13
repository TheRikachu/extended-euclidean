#include "polynomial.hh"
#include <vector>

Polynomial::Polynomial(std::vector<int> coeffs, int modulus)
    : coeffs_(coeffs), modulus_(modulus) {}

Polynomial::Polynomial(const Polynomial &that) = default;

Polynomial::~Polynomial() = default;

std::vector<int> Polynomial::GetCoeffs() const { return this->coeffs_; }

int Polynomial::GetModulus() const { return this->modulus_; }

int Polynomial::GetDegree() const
{
    int degree = 0;
    for (int i = this->coeffs_.size() - 1; i >= 0; i--)
    {
        if (coeffs_[i] > 0)
        {
            degree = i;
            break;
        }
    }
    return degree;
}

Polynomial &Polynomial::operator=(const Polynomial &that)
{
    if (this == &that)
    {
        return *this;
    }

    this->coeffs_ = that.GetCoeffs();
    this->modulus_ = that.GetModulus();

    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &that)
{
    if (this->modulus_ != that.GetModulus())
    {
        throw ("Cannot add polynomials with different modulus");
    }

    for (int i = 0; i <= (std::max(this->GetDegree(), that.GetDegree())); i++)
    {
        this->coeffs_[i] = (this->coeffs_[i] + that.GetCoeffs()[i]) % this->modulus_;
    }

    return *this;
}

Polynomial operator+(Polynomial lhs, const Polynomial &rhs)
{
    lhs += rhs;
    return lhs;
}

Polynomial &Polynomial::operator*=(const Polynomial &that)
{
    if (this->modulus_ != that.GetModulus())
    {
        throw ("Cannot multiply polynomials with different modulus");
    }

    int modulus = this->modulus_;

    std::vector<int> a = this->GetCoeffs();
    std::vector<int> b = that.GetCoeffs();
    std::vector<int> prod;

    for (int i = 0; i <= this->GetDegree() + that.GetDegree(); i++)
    {
        int help = 0;
        for (int j = 0; j <= i; j++)
        {
            help = (help + (a[j] * b[i - j] % modulus)) % modulus;
        }
        prod[i] = help;
    }
    this->coeffs_ = prod;
    return *this;
}

Polynomial operator*(Polynomial lhs, const Polynomial &rhs)
{
    lhs *= rhs;
    return lhs;
}

Polynomial &Polynomial::operator/=(const Polynomial &that)
{

}
