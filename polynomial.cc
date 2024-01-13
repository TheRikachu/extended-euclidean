#include "polynomial.hh"
#include <vector>

Polynomial::Polynomial(int size, int modulus)
    : coeffs_(std::vector<int>(size, 0)), modulus_(modulus) {}

Polynomial::Polynomial(std::vector<int> coeffs, int modulus)
    : coeffs_(coeffs), modulus_(modulus) {}

Polynomial::Polynomial(const Polynomial &that) = default;

Polynomial::~Polynomial() = default;

int &Polynomial::operator[](std::size_t idx) { return this-> coeffs_[idx]; };
const int &Polynomial::operator[](std::size_t idx) const { return this->coeffs_[idx]; };

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

/*
** FIXME: Assumes modulus 2
 */
Polynomial &Polynomial::operator/=(const Polynomial &that)
{
    if (this->modulus_ != that.GetModulus())
    {
        throw ("Cannot divide polynomial with different modulus");
    }
    int modulus = this->modulus_;
    if (modulus != 2)
    {
        throw ("WIP Cannot divide polynomials with module other than 2");
    }

    auto q = Polynomial(this->GetDegree(), modulus);
    auto r = *this;
    auto b = that;
    int bDegree = b.GetDegree(); /* Remain constant */

    while (r.GetDegree() >= bDegree)
    {
       q[r.GetDegree() - bDegree] = q[r.GetDegree() - bDegree] + (/*(r.LC() * that.LC())*/ 1);
    }
}

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

int Polynomial::LC() const { return (*this)[this->GetDegree()]; }

std::string Polynomial::ToString() const {
    if (this->GetDegree() == 0)
    {
        return std::to_string((*this)[0]);
    }

    auto deg = this->GetDegree();

    std::string str = "";
    str.append(std::to_string((*this)[deg]) + "x^" + std::to_string(deg));
    for(int i = this->GetDegree() - 1; i >= 0; --i)
    {
        if (i == 0 && (*this)[0])
        {
            str.append(" + " + std::to_string((*this)[0]));
        }
        else if (i == 1 && (*this)[1])
        {
            str.append(" + " + std::to_string((*this)[1]) + "x");
        }
        else if ((*this)[i]) {
            str.append(" + " + std::to_string((*this)[i]) + "x^" + std::to_string(i));
        }
    }
    return str;
 };
