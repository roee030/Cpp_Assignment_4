#ifndef CircularInt_H
#define CircularInt_H
#include<iostream>
#include "iostream"
#include <string>
#include <stdexcept>


using namespace std;

class CircularInt
{
private:
		int min;
		int max;
		int range;
		int num;

		int check(int value);

public:
		CircularInt(int min, int max, int num);
		CircularInt(int min, int max);
		CircularInt();
		CircularInt & operator= (const CircularInt& other);
		CircularInt& operator--();
		CircularInt& operator--(int);
		CircularInt& operator++();
		CircularInt& operator++(int);
		CircularInt& operator-=(const int);
		CircularInt& operator-=(const CircularInt&);
		friend CircularInt operator -(const CircularInt&,const CircularInt&);
		friend CircularInt operator -(int,const CircularInt&);
		friend CircularInt operator -(const CircularInt&,int);
		friend CircularInt operator -(const CircularInt&);
		friend CircularInt operator+(CircularInt& first, CircularInt& sec);
		friend CircularInt operator +(const CircularInt&,int);
		friend CircularInt operator +(int,const CircularInt&);
		CircularInt& operator+=(int);
		CircularInt& operator+=(const CircularInt&);

		friend CircularInt operator *(int,const CircularInt&);
		friend CircularInt operator *(const CircularInt&,int);
		friend CircularInt operator*(CircularInt& first, CircularInt& sec);
		CircularInt& operator*=(int);
		CircularInt& operator*=(const CircularInt&);

		friend CircularInt operator/(const CircularInt&, int);
		friend CircularInt operator/(int,const CircularInt&);
		CircularInt& operator/=(int);
		CircularInt& operator*=(const int);	
		CircularInt& operator*=(const CircularInt&);
		CircularInt& operator+=(const int);
		CircularInt& operator+=(const CircularInt& other);
		CircularInt& operator/=(const int other);
		const CircularInt operator-() const;
		CircularInt& operator=(const int another);
		friend bool operator< (const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator<= (const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator> (const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator>= (const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator< (const int lhs, const CircularInt& rhs);
		friend bool operator<= (const int lhs, const CircularInt& rhs);
		friend bool operator> (const int lhs, const CircularInt& rhs);
		friend bool operator>= (const int lhs, const CircularInt& rhs);
		friend bool operator< (const CircularInt& lhs, const int rhs);
		friend bool operator<= (const CircularInt& lhs, const int rhs);
		friend bool operator> (const CircularInt& lhs, const int rhs);
		friend bool operator>= (const CircularInt& lhs, const int rhs);
		friend ostream& operator<< (ostream& os, const CircularInt& c);
		friend istream& operator>>(istream& in, CircularInt& c);
		friend const CircularInt operator+ (const CircularInt& lhs, const CircularInt& rhs);
		friend const CircularInt operator+ (const int lhs, const CircularInt& rhs);
		friend const CircularInt operator+ (const CircularInt& lhs, const int rhs);
		friend const CircularInt operator* (const CircularInt& lhs, const CircularInt& rhs);
		friend const CircularInt operator* (const CircularInt& lhs, const int rhs);
		friend const CircularInt operator* (const int lhs, const CircularInt& rhs);
		friend const CircularInt operator- (const CircularInt& lhs, const int rhs);
		friend const CircularInt operator- (const int lhs, const CircularInt& rhs);
		friend const CircularInt operator- (const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator==(const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator==(const CircularInt& lhs, const int rhs);
		friend bool operator==(const int lhs, const CircularInt& rhs);
		friend bool operator!=(const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator!=(const CircularInt& lhs, const int rhs);
		friend bool operator!=(const int lhs, const CircularInt& rhs);
		friend CircularInt operator/ (const CircularInt& lhs, const int rhs);
		friend CircularInt operator/ (const int lhs, const CircularInt& rhs);
		static int gcd(int a, int b);
};
#endif //CircularInt