//
// Created by Carlos Arbizu on 9/16/21.
//
#include <iostream>
using std::string;
using std::cout;
using std::ostream;
#include <vector>
using std::vector;
#include <iomanip>
using std::setprecision;
using std::showpoint;
#include <algorithm>


using std::for_each;
using std::remove_if;
using std::erase_if;
using std::copy;
using std::back_inserter;
using std::copy_if;
using std::transform;
class Person{
public:
    Person(string name, uint8_t age) : name(std::move(name)),age{age}{}
    friend bool operator<(const Person &lhs,const Person &rhs){
       return lhs.age < rhs.age;
    }
    friend bool operator==(const Person &lhs,const Person &rhs){
        return ((lhs.age == rhs.age) && (lhs.name == rhs.name));
    }
    friend ostream &operator<<(ostream &ostream1, const Person &person){
        ostream1 << person.name << ": " << person.age << " years old";
        return ostream1;
    }
private:
    string name;
    uint8_t age;
};
template <typename T>
void display(const vector<T> &vector){
    cout << "[ ";
    //For lambdas to pass a reference it must be const
    //The reason for this is that it doesn't make sense to change the value of a reference to a temporary
    for_each(vector.begin(),vector.end(), [&vector] (const T &val){
        if(&val== &(vector.back())){
            cout << showpoint << setprecision(5) << val << " ";
        }
        else {
            cout << showpoint << setprecision(5) << val << ", ";
        }
    });
    cout << "] ";
}
void test1(){
    vector<int64_t> vector(10, 100);
    display(vector);
}

void test2(){
    vector<int64_t> vector{10, 9, 39, 12, 1};
    display(vector); cout << "\n";
    cout << "Vector size: " << vector.size() << "\n";
    cout << "Vector max size: " << vector.max_size() << "\n"; //max possible size allowed on system
    cout << "Vector capacity: " << vector.capacity() << "\n"; //capacity that the vector is able to hold.
    vector.push_back(3);
    cout << "Vector new size: " << vector.size() << "\n";
    cout << "Vector new max size: " << vector.max_size() << "\n";
    cout << "Vector new capacity: " << vector.capacity() << "\n"; //Notice the capacity doubles when we add 1 more element to the vector
    vector.shrink_to_fit(); //C++11
    cout << "Vector new size after shrink: " << vector.size() << "\n";
    cout << "Vector new max size after shrink: " << vector.max_size() << "\n";
    cout << "Vector new capacity after shrink: " << vector.capacity() << "\n"; //Capacity now matches size
    vector.reserve(100); //Reserve 100 spaces in contigious memory (Won't expand until it hits that 101th element then it will double in capacity
    cout << "Vector new size after reserve: " << vector.size() << "\n";
    cout << "Vector new max size after reserve: " << vector.max_size() << "\n";
    cout << "Vector new capacity after reserve: " << vector.capacity() << "\n";
}
void test3(){
    vector<int64_t> vector {1, 2, 3, 4, 5, 6};
    vector[0] = 100; //No bounds checking no exception thrown
    vector.at(1) = 101; //Bounds checking exception thrown
}
void test4(){
    vector<Person> stooges{};
    Person p1 {"Larry",20};
    cout << "Stooges size: " << stooges.size() << "\n";
    cout << "Stooges capacity: " << stooges.capacity() << "\n";
    stooges.push_back(p1);
    stooges.push_back(Person("Moe",22)); //The Clang Tidy recommends we use emplace back instead of passing temporary objects
    //Emplace back allows us to create the objects in the container rather than copying or moving them
    stooges.emplace_back("Curly",22); //Here we create the object directly in the container
    display(stooges);
}
void test5(){
    vector<Person> stooges {
            {"Moe", 22},{"Larry",15},{"Curly",22}
    };//Notice how we use the curly brackets within the stooges to create our objects alongside the vector container

    cout << "Front of the vector: " << stooges.front();
    cout << "Back of the vector: " << stooges.back();

    stooges.pop_back();
    display(stooges);
}
void test6(){
    vector<int64_t> vector {1, 2, 3, 4, 5, 6};
    display(vector);
    cout << "\n";
    vector.clear();

    display(vector);
    cout << "\n";
    vector = {77,44,23,9}; //We can set our STL container equal to a list of ints
    vector.erase(vector.begin(),vector.begin()+2); //Erases from the beginning of the vector UP to the 3rd element (not inclusive)
    display(vector);
    cout << "\n";
    vector = {1,2,3,4,5,6,7,8,9,10};
    display(vector);
    cout << "\n";
    //Below is the pre C++17 way of deleting elements from a vector
    //It is a bit bulky and hard to read
/*    vector.erase(remove_if(vector.begin(),vector.end(),[](int x)
    {
        return x%2==0;
    }),vector.end());*/
    erase_if(vector,[](int64_t x) {return x % 2 == 0;}); //C++17 way of removing certain elements given a predicate
    display(vector);
}
void test7(){

    vector<int64_t> vector1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int64_t> vector2{-1, 0, 0};

    cout << "Vector1 before copy: ";
    display(vector1);
    cout << "\n";
    cout << "Vector2 before copy: ";
    display(vector2);
    cout << "\n";
    cout << "\n";
    copy(vector1.begin(),vector1.end(), back_inserter(vector2));
    //1st arg inclusive beginning of copy
    //2nd arg exclusive ending of copy
    //3rd arg where we want the copy to go
    //In this case it takes an iterator to an STL container
    //back_inserter() allows us to easily expand vector2 and attach the copied elements
    cout << "Vector2 after copy: ";
    display(vector2);
    cout << "\n";
    cout << "Vector1 after copy: ";
    display(vector1);
    cout << "\n";

    vector2.clear();
    vector2 = {0};
    vector2.shrink_to_fit();

    copy_if(vector1.begin(),vector1.end(),back_inserter(vector2),[](int64_t x) { return (x % 2 == 0); });
    //Copy all the elements from vector 1 then insert the elemeents to the back of vector 2 if they pass the predicate statement
    display(vector2);
}

void test8(){
    vector<int64_t> vector1 {1,2,3,4,5};
    vector<int64_t> vector2 {20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int64_t> vector3{};
    transform(vector1.begin(),vector1.end(),vector2.begin(),back_inserter(vector3),[](int64_t x, int64_t y){
        return x * y;
    });
    //1st arg explanation: Range of numbers you want to transform
    //Explanation for second arg:
    // Beginning at the second container (or whatever iterator you decide to start at)
    // do something with the values in the second container and the first
    //In this case we want to multiply these values
    //NOTE: Undefined behavior if the size of the second vector is less than the first 1
    //3rd arg: where do you want to place those values
    //Since vector 3 is not defined ( has no size nor capacity)
    //We have to use back_inserter() to automatically create the size for us
    //and fill the vector
    //Notice that back_inserter() first adds 1 space to the empty container then doubles it
    //everytime we need more space in this case we get 8 spaces (1,2,4,8) even though we only
    //need 5 spaces

    cout << vector3.capacity();

    display(vector3);

}
int main(){
//    test1();
//    test2();
/*    test3();*/
/*    test4();*/
//    test5();
/*    test6();*/
/*      test7();*/
    test8();
    return 0;
}