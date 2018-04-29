#include "CircularInt.hpp"
#include <string>
CircularInt::CircularInt(int _min, int _max)
{
	min=_min;
	max=_max;
	range=max-min+1;
	num=min;
}
CircularInt::CircularInt()
{
	min=0;
	max=0;
	range=0;
	num=0;
}
//~~~~~~
CircularInt::~CircularInt(){}
int CircularInt::check(int value)
{
	if (value >= min && value < max)
	{
		return value;
	}
	if (value >= min)
	{
		if ((value = value % range) >= min)
		{
			return value % range;
		}
		else
		{
			return value + range;
		}
	}
	//value < min
	if (value < max)
	{
		value = value % range;
		value += ((min - value) / range) * range;
	}
	return -1;
}
CircularInt::CircularInt(): CircularInt(0,0)
{
}
void CircularInt::norm()
{
	while(num>max)num=num-range;
	while(num<min)num=num+range;
}
CircularInt& CircularInt::operator>> (const CircularInt& c)
{
	CircularInt *temp=new CircularInt (min,max);
        temp->num = (num>>c.num);
	temp->norm();
        return *temp;
}
ostream& operator<< (ostream& os, const CircularInt& c)
{
	os<<c.num;
	return os;
}

istream& operator>> (istream& is, CircularInt& c)
{
	 int x;
         is>> x;
         c.num = x;
	 c.norm();
         return is;
}
CircularInt& CircularInt::operator--(const int)
{
	puts("CircularInt& CircularInt::operator--(const int)");
	if(num==min)num=max;
	else num--;
	return *this;
}
CircularInt& CircularInt::operator++(const int)
{
	puts("CircularInt& CircularInt::operator++(const int)");
	if(num==max)num=min;
	else num++;
	return *this;
}
CircularInt& CircularInt::operator--()
{
	puts("CircularInt& CircularInt::operator--()");
	if(num==min)num=max;
	else num--;
	return *this;
}
CircularInt& CircularInt::operator++()
{
	puts("CircularInt& CircularInt::operator++()");
	if(num==max)num=min;
	else num++;
	return *this;
}

CircularInt operator -(const CircularInt & lhs, const CircularInt & rhs)
{
	puts("const CircularInt operator-(const CircularInt & lhs, const CircularInt & rhs)");
	CircularInt c{c1.min,c1.max};
	c.num=c1.num-c2.num;
	c.norm();
	return c;
}

CircularInt operator -(const int i,const CircularInt& c)
{
	puts("const CircularInt operator- (const int lhs, const CircularInt& rhs)");
	CircularInt c1{c.min,c.max};
	c1.num=i-c.num;
	c1.norm();
	return c1;
}
CircularInt operator -(const CircularInt& c,const int i)
{
	puts("const CircularInt operator- (const CircularInt& lhs, const int rhs)");
	CircularInt c1{c.min,c.max};
	c1.num=c.num-i;
	c1.norm();
	return c1;
}
CircularInt operator -(const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	c1.num=-c.num;
	c1.norm();
	return c1;
}

CircularInt& CircularInt::operator-=(int i)
{
	puts("CircularInt & CircularInt::operator-=(int dec)");
	this->num-=i;
	this->norm();
	return *this;
}
CircularInt& CircularInt::operator-=(const CircularInt& c)
{
	puts("CircularInt & CircularInt::operator-=(const CircularInt & other)");
	this->num-=c.num;
	this->norm();
	return *this;
}

CircularInt operator+(CircularInt& c1, CircularInt& c2)
{
	CircularInt c{c1.min,c1.max};
	c.num=c1.num+c2.num;
	c.norm();
	return c;
}
CircularInt operator +(const CircularInt& c,int i)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num+i;
	c1.norm();
	return c1;
}
CircularInt operator +(int i,const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num+i;
	c1.norm();
	return c1;
}
CircularInt& CircularInt::operator+=(int i)
{
	this->num+=i;
	this->norm();
	return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& c)
{
	this->num+=c.num;
	this->norm();
	return *this;
}

CircularInt operator *(int i,const CircularInt& c)
{
	puts("const CircularInt operator* (const int lhs, const CircularInt& rhs)");
	CircularInt c1{c.min,c.max};
	c1.num=c.num*i;
	c1.norm();
	return c1;
}
CircularInt operator *(const CircularInt& c,int i)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num*i;
	c1.norm();
	return c1;
}
CircularInt operator*(CircularInt& c1, CircularInt& c2)
{
	CircularInt c{c1.min,c1.max};
	c.num=c1.num*c2.num;
	c.norm();
	return c;
}
CircularInt& CircularInt::operator*=(int i)
{
	this->num*=i;
	this->norm();
	return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& c)
{
	this->num*=c.num;
	this->norm();
	return *this;
}

CircularInt operator/(const CircularInt& c, int i)
{
	CircularInt c1=c;
	if(c.num%i!=0||i==0)throw string("Error");
        c1.num=(c.num/i);
	c1.norm();
        return c1;
}
CircularInt operator/(int i,const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	if(c.num==0||i%c.num!=0)throw string("Division error");
	c1.num=i/c.num;
	c1.norm();
	return c1;
}
CircularInt& CircularInt::operator/=(int i)
{
	if(num%i!=0||i==0)throw string("error");
        num=num/i;
	this->norm();
        return *this;
}

void CircularInt::operator=(int i)
{
	this->num=i;
	this->norm();
}
void CircularInt::operator=(const CircularInt& c)
{
	this->num=c.num;
	this->norm();
}

bool CircularInt::operator ==(const CircularInt& c)
{
	return(num==c.num);
}
bool CircularInt::operator ==(int i)
{
	return(num==i);
}
bool operator==(int i, CircularInt& c)
{
	return(c.num==i);
}
bool CircularInt::operator !=(const CircularInt& c)
{
	return(num!=c.num);
}
bool operator!=(int i, CircularInt& c)
{
	return(i!=c.num);
}
bool operator!=(CircularInt& c,int i)
{
	return(i!=c.num);
}
bool CircularInt::operator >(int i)
{
	return(num>i);
}
bool operator>(int i, CircularInt& c)
{
	return(i>c.num);
}
bool CircularInt::operator >(const CircularInt& c)
{
	return(num>c.num);
}
bool CircularInt::operator >=(int i)
{
	return(num>=i);
}	
bool CircularInt::operator >=(const CircularInt& c)
{
	return(num>=c.num);
}
bool operator>=(int i, CircularInt& c)
{
	return(i>=c.num);
}
bool CircularInt::operator <(int i)
{
	return(num<i);
}
bool CircularInt::operator <(const CircularInt& c)
{
	return (num<c.num);
}
bool operator<(int i, CircularInt& c)
{
	return (i<c.num);
}
bool CircularInt::operator <=(int i)
{
	return (num<=i);
}
bool CircularInt::operator <=(const CircularInt& c)
{
	return (num<=c.num);
}
bool operator<=(int i, CircularInt& c)
{
	return (i<=c.num);
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