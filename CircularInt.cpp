#include "CircularInt.hpp"

CircularInt::CircularInt(int _min, int _max, int _num) : min(_min), max(_max), range(max - min + 1), num(_num)
{
}

CircularInt::CircularInt(int _min, int _max): min(_min),max(_max), range(max-min+1), num(min)
{
}
CircularInt::CircularInt(): CircularInt(0,0)
{
}

ostream& operator<< (ostream& os, const CircularInt& c)
{
	os<<c.num;
	return os;
}
istream& operator>>(istream& in, CircularInt& c)
{
	in >> c.num;
	return in;
}
CircularInt& CircularInt::operator=(const CircularInt& another)
{
	num=another.num;
	min=another.min;
	max=another.max;
	range=another.range;
	return *this;
}

CircularInt & CircularInt::operator=(const int another)
{
	int val = 0;
	if (another > max || another < min)
	{
		val = another % this->range;
		val += min;
	}
	if (val < 0)
		val = val + this->range;
	if (val > this->max)
		val -= this->range;
	this->num = val;
	return *this;
}



CircularInt& CircularInt::operator--(const int)
{
	if(num==min) num=max;
	else num--; 
	return *this;
}
CircularInt& CircularInt::operator--()
{
	if (num == min) num = max;
	else num--;
	return *this;
}

CircularInt& CircularInt::operator++(const int)
{
	if(num==max)num=min;
	else num++;
	return *this;
}
CircularInt& CircularInt::operator++()
{
	if(num==max)num=min;
	else num++;
	return *this;
}
//Recall a=b(mod m) \Rightarrow ac=bc(mod m)
CircularInt& CircularInt::operator*=(int tmp)
{
	int m = range;
	int a = num - min;
	int r = (a * tmp) % m;
	if (r < 0)
	{
		//Since this is the complement instead of doing the plus at the end
		//We should substract, in order to fix we multiply by -2
		r += (range - (((a*tmp) / range) + 2)*min);
	}
	//Make sure that r+min <= max
	this->num = (r + ((a*tmp) / range+1)*min);
	return *this;


}
CircularInt & CircularInt::operator*=(const CircularInt & other)
{
	return *this *= other.num;
}
CircularInt& CircularInt::operator+=(const int inc)
{
	int m = this->range;
	int val = this->num - this->min;
	int result = (val + inc) % m;
	this->num = result + min;
	return *this;
}
CircularInt & CircularInt::operator+=(const CircularInt & other)
{
	return *this += other.num;
}
CircularInt & CircularInt::operator/=(const int other)
{
	int r = this->num - this->min;
	int d = gcd(other, this->range);
	if (this->num % d != 0)
		throw std::string("There is no solution for this congruences");
	int result = r / d;
	this->num = result + min;
	return *this;
}
const CircularInt operator+ (const CircularInt& lhs, const int rhs)
{
	int m = lhs.range;
	int val = lhs.num - lhs.min;
	int result = (val + rhs) % m;
	int num = result + lhs.min;
	int min = lhs.min;
	int max = lhs.max;
	return CircularInt(min,max,num);
}
const CircularInt operator+ (const int lhs, const CircularInt& rhs)
{
	return rhs + lhs;
}
const CircularInt operator+ (const CircularInt& lhs, const CircularInt& rhs)
{
	int m = lhs.range;
	int val = lhs.num - lhs.min;
	int result = (val + rhs.num) % m;
	int num = result + lhs.min;
	int min = lhs.min;
	int max = lhs.max;
	return CircularInt(min, max, num);
}

const CircularInt operator* (const CircularInt& lhs, const CircularInt& rhs)
{
	int rlV = lhs.num - lhs.min;
	int rRv = rhs.num - rhs.min;
	int rResult = (rlV*rlV) % lhs.range;
	if (rResult < 0) rResult += (lhs.range - 2 * lhs.min);
	return CircularInt(lhs.min, lhs.max, rResult + ((rlV*rlV) / lhs.range + 1)*lhs.min);
}
const CircularInt operator* (const CircularInt& lhs, const int rhs)
{
	int rlV = lhs.num - lhs.min;
	int rRv = rhs;
	int rResult = (rlV*rRv) % lhs.range;
	if (rResult < 0)
	{
		//Since this is the complement instead of doing the plus at the end
		//We should substract, in order to fix we multiply by -2
		rResult += (lhs.range - (((rlV*rRv) / lhs.range) +2)*lhs.min);
	}
	return CircularInt(lhs.min, lhs.max, rResult + (((rlV*rRv) / lhs.range) + 1)*lhs.min);
}
const CircularInt operator* (const int lhs, const CircularInt& rhs)
{
	return rhs * lhs;
}
const CircularInt operator- (const CircularInt& lhs, const int rhs)
{
	int rlV = lhs.num - lhs.min;
	int rRv = rhs;
	int rResult = (rlV - rRv) % lhs.range;
	if (rResult <= 0)
	{
		rResult += (lhs.range - 2 * lhs.min);
	}
	return CircularInt(lhs.min, lhs.max, rResult + lhs.min);
}
const CircularInt operator- (const int lhs, const CircularInt& rhs)
{
	int rlv = lhs;
	int rRv = rhs.num - rhs.min;
	int rResult = (lhs - rRv) % rhs.range;
	if (rResult <= 0)
	{
		rResult += (rhs.range - 2*rhs.min);
	}
	return CircularInt(rhs.min, rhs.max, rResult + rhs.min);
}
const CircularInt operator-(const CircularInt & lhs, const CircularInt & rhs)
{
	if(lhs.range != rhs.range)
		throw std::string("Invalid");
	return lhs - rhs.num;
}
CircularInt & CircularInt::operator-=(int dec)
{

	CircularInt lhs = *this;
	int rlV = lhs.num - lhs.min;
	int rRv = dec;
	int rResult = (rlV*rlV) % lhs.range;
	if (rResult < 0)
	{
		rResult = rResult + range;
	}
	this->num = (lhs.min, lhs.max, rResult + lhs.min);
	return *this;
}

CircularInt & CircularInt::operator-=(const CircularInt & other)
{
	CircularInt lhs = *this;
	int rlV = lhs.num - lhs.min;
	int rRv = other.num;
	int rResult = (rlV*rlV) % lhs.range;
	if (rResult < 0)
	{
		rResult = rResult + range;
	}
	this->num = (lhs.min, lhs.max, rResult + lhs.min);
	return *this;
}

inline bool operator==(const CircularInt& lhs, const CircularInt& rhs)
{
	return
		lhs.min == rhs.min &&
		lhs.max == rhs.max &&
		lhs.range == rhs.range &&
		lhs.num == rhs.num;
}
bool operator==(const CircularInt & lhs, const int rhs)
{
	return lhs.num == rhs;
}
bool operator==(const int lhs, const CircularInt & rhs)
{
	return lhs == rhs.num;
}
inline bool operator!=(const CircularInt& lhs, const CircularInt& rhs)
{
	return !(lhs == rhs);
}
bool operator!=(const CircularInt & lhs, const int rhs)
{
	return lhs.num != rhs;
}
bool operator!=(const int lhs, const CircularInt & rhs)
{
	return rhs.num != lhs;
}
inline bool operator< (const CircularInt& lhs, const CircularInt& rhs)
{
	return lhs.num < rhs.num;
}
inline bool operator<= (const CircularInt& lhs, const CircularInt& rhs)
{
	return lhs.num <= rhs.num;
}
inline bool operator> (const CircularInt& lhs, const CircularInt& rhs)
{
	return lhs.num > rhs.num;
}
inline bool operator>= (const CircularInt& lhs, const CircularInt& rhs)
{
	return lhs.num >= rhs.num;
}
inline bool operator<(const int lhs, const CircularInt & rhs)
{
	return lhs < rhs.num;
}
inline bool operator<=(const int lhs, const CircularInt & rhs)
{
	return lhs <= rhs.num;
}
inline bool operator>(const int lhs, const CircularInt & rhs)
{
	return lhs > rhs.num;
}
inline bool operator>=(const int lhs, const CircularInt & rhs)
{
	return lhs >= rhs.num;
}
inline bool operator<(const CircularInt & lhs, const int rhs)
{
	return lhs.num < rhs;
}
inline bool operator<=(const CircularInt & lhs, const int rhs)
{
	return lhs.num <= rhs;
}
inline bool operator>(const CircularInt & lhs, const int rhs)
{
	return lhs.num > rhs;
}
inline bool operator>=(const CircularInt & lhs, const int rhs)
{
	return lhs.num >= rhs;
}
const CircularInt CircularInt::operator-() const
{
	return (CircularInt(this->min, this->max, this->num) * (-1));
}
int CircularInt::gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
/*
** Recall that ac=bc (mod m) if and only if a=b(mod m/gcd(c,m))
** So let call r = ac.
** Moreover Recall that there is a solution if and only if 
** (c,m)|ac
*/
CircularInt operator/(const CircularInt & lhs, const int rhs)
{
	int r = lhs.num - lhs.min;
	int d = CircularInt::gcd(rhs, lhs.range);
	if (lhs.num % d != 0)
		throw std::string("There is no solution for this congruences");
	int result = r / d;
	return CircularInt(lhs.min, lhs.max, result+lhs.min);
}

CircularInt operator/(const int lhs, const CircularInt & rhs)
{
	return rhs / lhs;
}

/*
int main() 
{
	CircularInt hour{ 1, 12 };                 // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	cout << hour + hour << endl;                // 10 (11 hours after 11)
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	cout << hour / 2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
	CircularInt hour2{ 1,12 };
	cout << (hour - hour2) << endl;
	try 
	{
		cout << hour / 3;
	}
	catch (const string& message) 
	{
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}
*/