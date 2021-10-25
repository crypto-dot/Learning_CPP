//
// Created by Carlos Arbizu on 10/9/21.
//
#include <iostream>
#include <cstdint>
#include <set>
#include <iomanip>
class Person{
public:
    Person() : name{"N/A"},age{0} {}
    Person(std::string name,uint64_t age) : name{std::move(name)},age{age} {}
    friend bool operator==(const Person &lhs,const Person &rhs) {
        return lhs.name == rhs.name;
    }
    friend bool operator<(const Person &lhs, const Person &rhs){
        return lhs.age < rhs.age;
    }
    friend std::ostream &operator<<(std::ostream &ostream1, const Person &person){
        ostream1 << person.name << ": " << person.age << '\n';
        return ostream1;
    }

private:
    std::string name;
    uint64_t age;

};
template<typename T>
void display(const std::set<T> &group){
    for(const auto &element : group){
        std::cout << element;
    }
    std::cout << '\n';
}
void test1(){
    std::cout << std::setfill('=') << std::setw(30) << "" << "Test1" << std::setw(30) << "" << '\n';
    std::set<int> s {5,4,1,3,2}; //elements will automatically be ordered (having a defined operator< is very important here as with all STL containers)
    display(s);

    s.insert(5); //Nothing happens
    s.insert(0); //Entered and ordered
    display(s);
    const auto &it = s.find(3);

    if(it != s.end()){
        std::cout << "The element 3 was found in the S container \n";
    }
    else {
        std::cout << "The element 3 was not found in the S container \n";
    }
}
void test2(){
    std::cout << std::setfill('=') << std::setw(30) << "" << "Test2" << std::setw(30) << "" << '\n';
    std::set<Person> stooges {
            {"Larry",1},
            {"Moe",3},
            {"Curly",2}
    };
    display(stooges);
    stooges.emplace("Carlos",4);
    display(stooges);
    stooges.emplace("Value",4); //WILL not be put in the set since the age is being used for comparison
    //If the name and the age was used then it would've been placed in the set
    display(stooges);
    //NOTE std::remove cannot be used in STL set since set is naturally ordered and std::remove
    //changes the order to place elements needed to be remove towards the end of the set
    /*stooges.erase(stooges.find(Person("Carlos",4)));*/
    //Both ways are equivalent!
    stooges.erase(Person("xxxx",4)); //uses operator<
    display(stooges);
}
void test3(){
    std::cout << std::setfill('=') << std::setw(30) << "" << "Test2" << std::setw(30) << "" << '\n';

    std::set<char> s {'A','B','C'};
    std::pair<std::set<char>::iterator,bool> result = s.insert('D');
    std::cout << std::boolalpha << *result.first << '\n' << result.second << '\n';

    auto result2 = s.insert('A');

    std::cout << *result2.first << '\n' << result2.second << '\n';
}
int main (){
    /*test1();*/
/*    test2();*/
test3();

    return 0;
}