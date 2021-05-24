//
// Created by Carlos Arbizu on 3/26/21.
//
class Base{
public:
    int a {0};
protected:
    int b {0};
private:
    int c {0};

};
class Derived1:public Base {
    //Friends of this class will only have access to whatever this class has access to

    //a will be public
    //b will be protected
    //c will be inaccessible (is inherited but no access is granted)
public:
    void public_Inheritance_Acess(){
        a = 200; //ok
        b = 300; // ok
        /// c = 200 NOT OK
    }
};
class Derived2: protected Base {
    //Friends of this class will be able to access all the protected members except c since it is private
    //a will be protected
    //b will be protected
    //c will be inaccessible (is inherited but no access is granted)
public:
    void public_Inheritance_Acess(){
        a = 200; //ok
        b = 300; // ok
        /// c = 200 NOT OK
    }
};
int main (){
    Base base;
    base.a = 100; //OK!
/// base.b = 100; //NOT OK
/// base.c = 100 //NOT OK

    Derived1 derived1;
    derived1.a = 300;
    ///   derived1.b = 300; NOT OK
    /// derived1.c = 300; NOT OK

    Derived2 derived2;
    ///   derived2.a = 300; NOT OK
    ///   derived2.b = 300; NOT OK
    ///  derived2.c = 300; NOT OK

    return 0;
}