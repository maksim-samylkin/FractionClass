#include <iostream>
#include <Windows.h>
#include <memory>
#include <initializer_list>
#include <span>
#include <utility>  
#include <algorithm> 

class Fraction
{
public:
    int NumOne;
    int NumTwo;

    Fraction()
    {
        this->NumOne = 0;
        this->NumTwo = 1;
    }

    Fraction(int OneRes, int TwoRes)
    {
        this->NumOne = OneRes;
        this->NumTwo = TwoRes;
    }

    Fraction(int num)
    {
        this->NumOne = num;
        this->NumTwo = 1;
    }

    // конструктор копирования
    Fraction(const Fraction& copy)
    {
        this->NumOne = copy.NumOne;
        this->NumTwo = copy.NumTwo;
    }

    // оператор присваивания
    Fraction& operator=(const Fraction& copy)
    {
        if (this != &copy)
        {
            this->NumOne = copy.NumOne;
            this->NumTwo = copy.NumTwo;
        }
        return *this;
    }

    Fraction Addition(const Fraction& ResSum) const
    {
        int NewNumOne = NumOne * ResSum.NumTwo + ResSum.NumOne * NumTwo;
        int NewNumTwo = NumTwo * ResSum.NumTwo;
        return Fraction(NewNumOne, NewNumTwo);
    }

    Fraction Subtraction(const Fraction& ResSum) const
    {
        int NewNumOne = NumOne * ResSum.NumTwo - ResSum.NumOne * NumTwo;
        int NewNumTwo = NumTwo * ResSum.NumTwo;
        return Fraction(NewNumOne, NewNumTwo);
    }

    Fraction Multiplication(const Fraction& ResSum) const
    {
        int NewNumOne = NumOne * ResSum.NumOne;
        int NewNumTwo = NumTwo * ResSum.NumTwo;
        return Fraction(NewNumOne, NewNumTwo);
    }

    Fraction Division(const Fraction& ResSum) const
    {
        if (ResSum.NumOne == 0)
        {
            return Fraction(0, 1);
        }
        int NewNumOne = NumOne * ResSum.NumTwo;
        int NewNumTwo = NumTwo * ResSum.NumOne;
        return Fraction(NewNumOne, NewNumTwo);
    }
    
    Fraction operator+(const Fraction& copy) const
    {
        return Addition(copy);
    }
    Fraction operator-(const Fraction& copy) const
    { 
        return Subtraction(copy);
    }
    Fraction operator*(const Fraction& copy) const
    {
        return Multiplication(copy);
    }
    Fraction operator/(const Fraction& copy) const
    {
        return Division(copy);
    }

    bool operator==(const Fraction& copy) const
    {
        return NumOne * copy.NumTwo == copy.NumOne * NumTwo;
    }

    bool operator!=(const Fraction& copy) const
    {
        return !(*this == copy);
    }
    bool operator<(const Fraction& copy) const
    {
        return NumOne * copy.NumTwo < copy.NumOne * NumTwo;
    }
    bool operator<=(const Fraction& copy) const
    { 
        return !(copy < *this);
    }
    bool operator>(const Fraction& copy) const
    { 
        return copy < *this;
    }
    bool operator>=(const Fraction& copy) const
    { 
        return !(*this < copy);
    }

  
    explicit operator double() const
    {
        return static_cast<double>(NumOne) / NumTwo;
    }
};


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Fraction a(3, 4);
    Fraction b(1, 2);

    Fraction num = a + b;
    Fraction numUm = a * 2;
    Fraction numDel = a / b;
    std::cout << "Результат: " << a.NumOne << "/" << a.NumTwo << "\n";
    std::cout << "Результат: " << b.NumOne << "/" << b.NumTwo << "\n";
    std::cout << "Результат: " << num.NumOne << "/" << num.NumTwo << "\n";
    std::cout << "Результат: " << numUm.NumOne << "/" << numUm.NumTwo << "\n";
    std::cout << "Результат: " << numDel.NumOne << "/" << numDel.NumTwo << "\n";
    
    return 0;
}