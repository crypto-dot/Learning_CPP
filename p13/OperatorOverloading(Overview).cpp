//
// Created by Carlos Arbizu on 1/30/21.
//

/* *Operator overloading is using traditional operators (+,*,=,etc.) with user defined types
** *It allows user defined types to behave similar to built-in types
** *Makes code more readable and writable
** *Not done automatically (except for the assignment operator). They must be explicitly defined !
** *Operator overloading only makes sense for certain types of classes (adding classes of type Player may not
** *make much sense, but adding classes of type Number would and it would make code much more readable if operator
** *overloading is used instead of class member methods or functions)
** *THE OPERATORS THAT CANNOT BE OVERLOADED ARE ::, :?, .*, ., sizeof
******************************************************************
** OPERATOR OVERLOADING BASIC RULES
** *Precedence and Associativity cannot be changed
** *'arity' cannot be changed (can't make division operator unary)
** *Cannot overload operators for primitive types (int,size_t,double,etc.)
** *Can't create new operators
** *[],(),->, and the assignment operator (=) must be declared as member methods
** *Other operators can be declared as member methods or global functions
** Declaring operators as global functions allow you to perform operations on non member objects on the left side
** unlike member functions. A good example I found on stackoverflow by James Kanze:
** class Complex
{
public:
    Complex(double r, double i = 0.0);
    bool operator==( Complex const& other ) const;
};

Complex a;
//  ...
if ( a == 1.0 ) // OK
//  ...
if ( 1.0 == a ) // error
** Versus:
** class Complex
{
public:
    Complex(double r, double i = 0.0);
    friend bool operator==( Complex const& lhs, Complex const& rhs ) const;
};

Complex a;
//  ...
if ( a == 1.0 ) // OK
//  ...
if ( 1.0 == a ) // OK


 (NOTE: the function is declared as a friend of the class, this is not necessary but it is common practice
 to do so.Additionally, the class must support some kind of implicit conversion.)
**An important thing to note is that in C++ there is no such thing as const global functions, since the const
  keyword tells an object that the member method will not change the internal state of an obj
  (const reference essentially accomplishes this for global functions or non-member functions)
___________________________________________________________________________________________________________
INSERTION AND EXTRACTION OPERATORS. (<</>>)
-It's best practice to not implement these two operators as member methods since they left side object will
 have to be a user defined class
 MyString larry;
 larry << cout;  (Will still work but is very strange)

 Mystring hero;
 hero >> cin; (another example)

q
*/