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
public:
		CircularInt(int min, int max, int num);
		CircularInt(int min, int max);
		CircularInt();
		CircularInt& operator--();
		CircularInt& operator--(int);
		CircularInt& operator++();
		CircularInt& operator++(int);
		CircularInt& operator-=(int);
		CircularInt& operator*=(int);	
		CircularInt& operator+=(int);
		const CircularInt operator-() const;
		CircularInt& operator=(const CircularInt& another);
		friend inline bool operator< (const CircularInt& lhs, const CircularInt& rhs);
		friend inline bool operator<= (const CircularInt& lhs, const CircularInt& rhs);
		friend inline bool operator> (const CircularInt& lhs, const CircularInt& rhs);
		friend inline bool operator>= (const CircularInt& lhs, const CircularInt& rhs);
		friend ostream& operator<< (ostream& os, const CircularInt& c);
		friend const CircularInt operator+ (const CircularInt& lhs, const CircularInt& rhs);
		friend const CircularInt operator+ (const int lhs, const CircularInt& rhs);
		friend const CircularInt operator+ (const CircularInt& lhs, const int rhs);
		friend const CircularInt operator* (const CircularInt& lhs, const CircularInt& rhs);
		friend const CircularInt operator* (const CircularInt& lhs, const int rhs);
		friend const CircularInt operator* (const int lhs, const CircularInt& rhs);
		friend const CircularInt operator- (const CircularInt& lhs, const int rhs);
		friend const CircularInt operator- (const int lhs, const CircularInt& rhs);
		friend bool operator==(const CircularInt& lhs, const CircularInt& rhs);
		friend bool operator!=(const CircularInt& lhs, const CircularInt& rhs);
		friend CircularInt operator/ (const CircularInt& lhs, const int rhs);
		int gcd(int a, int b);
};