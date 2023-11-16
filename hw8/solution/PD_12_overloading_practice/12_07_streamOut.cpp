#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// class definition of MyVector
class MyVector
{
friend ostream& operator<<(ostream& out, const MyVector& v);

private:
  static double equalityGap;
  int n; 
  double* m; 
public:
  MyVector();
  MyVector(int n, double m[]);  
  MyVector(const MyVector& v);
  const MyVector& operator=(const MyVector& v);
  ~MyVector();
  void print() const; 
  
  bool operator==(const MyVector& v) const;
  bool operator==(double d) const;
// end of class definition of MyVector
};

bool operator==(double d, const MyVector& v);






double MyVector::equalityGap = 0.00001;




// MyVector's instance functions
MyVector::MyVector(): n(0), m(NULL) 
{
}
MyVector::MyVector(int n, double m[])
{
  this->n = n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = m[i];
}
MyVector::MyVector(const MyVector& v)
{
  this->n = v.n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = v.m[i];	
}
const MyVector& MyVector::operator=(const MyVector& v)
{
  if(this != &v)
  {
    if(this->n != v.n)
    {
      delete [] this->m;
      this->n = v.n;
      this->m = new double[this->n];
    }
    for(int i = 0; i < n; i++)
      this->m[i] = v.m[i];
  }  
  return *this;
}
MyVector::~MyVector() 
{ 
  delete [] m; 
}
void MyVector::print() const 
{
  cout << "(";
  for(int i = 0; i < n - 1; i++)
    cout << m[i] << ", ";
  cout << m[n-1] << ")\n";
}
// end of MyVector's instance functions

// MyVector's overloaded operators
bool MyVector::operator==(const MyVector& v) const
{
  if(this->n != v.n)
    return false;
  else
  {
    for(int i = 0; i < n; i++)
    {
      if(this->m[i] != v.m[i])
      return false;
    }
  }	
  return true;
}
bool MyVector::operator==(double d) const
{
  for(int i = 0; i < n; i++)
  {
    if(abs(this->m[i] - d) > MyVector::equalityGap)
      return false;
  }
  return true;
}






int main()
{
  double d = 1.23;
  double m[3] = {d, d, d + 0.00000001};
  MyVector v(3, m);
  cout << v << v << endl;
  
  if(d == v)
    cout << "Equal!";
  else
    cout << "Unequal!";
  
  return 0;
}






bool operator==(double d, const MyVector& v) 
{
  return (v == d);
}

ostream& operator<<(ostream& out, const MyVector& v)
{
  out << "(";
  for(int i = 0; i < v.n - 1; i++)
    out << v.m[i] << ", ";
  out << v.m[v.n - 1] << ")";
  return out;
}
