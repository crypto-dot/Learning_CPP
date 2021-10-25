//
// Created by Carlos Arbizu on 9/19/21.
//
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <algorithm>
#include <forward_list>
using std::forward_list;
using std::find;
using std::for_each;
using std::advance;
#include <iostream>
using std::cout;
using std::string;
using std::cin;
using std::ostream;
template<typename T>
void display(const list<T> &list){
    for_each(list.begin(),list.end(),[&list](const T& val){
        if(&val == &(list.back())) {
            cout << "[" << val << "]";
        }
        else {
            cout << "[" << val << "]-";
        }
    });
}
template<typename T>
void display(const vector<T> &vector){
    cout << "[ ";
    for(const auto &element : vector){
        if(&element == &(vector.back())){
            cout << element << " ";
        }
        else {
            cout << element << ",";
        }
    }
    cout << "]";
}
class Person{
public:
    Person(std::string name,int64_t val) : name {std::move(name)},age{val} {
    }
    Person() : name{"'Unknown'"}, age{-1}{}
    friend ostream &operator<<(ostream &ostream1,const Person &person){
        ostream1 << "Name: " << person.name << " Age: " << person.age;
        return ostream1;
    }
    friend bool operator==(const Person &lhs, const Person &rhs){
       return lhs.age == rhs.age && lhs.name == rhs.name;
    }
    friend bool operator<(const Person &lhs,const Person &rhs){
        return lhs.age < rhs.age;
    }

private:
    std::string name;
    int64_t age;

};

void test1(){
    //Below is a classic example of iterator invalidation (https://stackoverflow.com/questions/6438086/iterator-invalidation-rules-for-c-containers)
    vector<uint64_t> vector1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it { find(vector1.begin(), vector1.end(), 5) };
    cout << "Vector (Before insertion): \n";
    display(vector1);
    cout << "Vector capacity: " << vector1.capacity();
    cout << "\n";
    vector1.insert(it, 20);
    cout << "Vector (After insertion): \n";
    display(vector1);
    cout << "Vector size: " << vector1.size();
    cout << "\n";
    //Notice how the new size is greater than the previous capacity
    //This invalidates all iterators (even the ones before the point of insertion)
    //Normally Just the ones after the insertion would be affected if the new container size
    //was not greater than the previous capacity but this is not the case above

    display(vector1);
    cout << "\n";
    cout << "Vector (Before deletion): ";
    display(vector1);
    cout << "\n";
    it = find(vector1.begin(), vector1.end(), 5) ;
    advance(it,-5);
    cout << *it;
    cout << "\n";
    /*vector1.erase(it);*/
    //The above line would not make any sense since we invalidated the iterator
    cout << "Vector (After deletion): ";
    display(vector1);
    cout << "\n";

    list<uint64_t> list1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it2 = find(list1.begin(), list1.end(), 5);
    cout << "List (doubly) (Before insertion): ";
    display(list1);
    cout << "\n";
    list1.insert(it2, 20);
    cout << "List (doubly) (After insertion): ";
    display(list1);
    cout << "\n";
    cout << "List (doubly) (Before deletion): ";
    display(list1);
    cout << "\n";
    list1.erase(it2);
    cout << "List (doubly) (After deletion): ";
    display(list1);
    cout << "\n";

}

void test2(){
    list<int64_t> list1 {-1,0,1,2,3};
    list<int64_t> list2 (10,1);
    display(list1);
    cout << "\n";
    cout << "List1 (doubly) FRONT: " << list1.front() << "\n";
    cout << "List1 (doubly) BACK: " << list1.back() << "\n";
    display(list2);
}
void test3(){
    list<int64_t> list1 {1,2,3,4,5,6,7,8,9,10};
    display(list1);
    cout << "\n";
    cout << "List1 (doubly) size: " << list1.size() << "\n";
    cout << "List1 (doubly) resized to 5: \n";
    list1.resize(5);
    display(list1);
    cout << "\n";
    cout << "List1 (doubly) resized back to 10: \n";
    list1.resize(10);
    display(list1);
    cout << "\n";
    list1.clear();
    cout << "List1 (doubly) cleared size: " << list1.size() << "\n";
    display(list1);
    list<Person> list2{};
    cout << "List2 (doubly Person objects) resized to 5: \n";
    list2.resize(5); // call the default constructor for the person object 5 times
    //If we overload the constructor and don't provide a default constructor the above
    //would error out
    display(list2);
}
void test4(){
    list<int64_t> list1 {1,2,3,4,5,6,7,8,9,10};
    cout << "List1 before insertion: \n";
    display(list1);
    cout << "\n";
    auto it {find(list1.begin(),list1.end(),5)};
    if(it != list1.end()){
        list1.insert(it,1100);
    }
    cout << "List1 after insertion: \n";
    display(list1);
    cout << "\n";
    //If it is not at the end (meaning it found the value in the list) insert 1100
    list<int64_t> list2 {1100,1200,1300,1400,1500,1600,1700};
    list1.insert(it,list2.begin(),list2.end());
    //Notice how the iterator is not invalidated unlike vectors which would invalidate the iterator
    //at the point of insertion and beyond it
    cout << "List1 after inserting an entire list: \n";
    display(list1);
    cout << "\n";
    advance(it,-4); //Point it to 1400
    //Advance allows you to move the iterator back or forward if the iterator supports
    //bidirectional movement
}
void test5(){
    list<Person> stooges {
            {"Larry",15},{"Curly",25},{"Moe",30}
    };
    cout << "Original Stooges: \n";
    display(stooges);
    cout << "\n";
    string name;
    int64_t age;
    cout << "Insert a name for the new stooge: "; cin >> name; cout << "\n";
    cout << "Insert an age for the new stooge: "; cin >> age; cout << "\n";
    cout << "New and Improved stooges: \n";
    stooges.emplace_back(name,age);
    display(stooges);
    cout << "\n";

    auto it { find(stooges.begin(),stooges.end(),Person("Moe",30)) };
    if(it != stooges.end()){
        stooges.emplace(it,"Dan",50);
    }
    //Inserts Dan before Moe
}
void test6(){
    list<Person> stooges {
            {"Larry",30},{"Curly",25},{"Moe",15}
    };
    cout << "Stooges before sorting: \n";
    display(stooges);
    cout << "\n";
    cout << "Stooges after sorting: \n";
    stooges.sort();
    display(stooges);
    cout << "\n";
    //Operator < must be overloaded
}
int main(){

/*     test1();*/
/*    test2();*/
/*    test3();*/
/*    test4();*/
/*test5();*/
test6();
    return 0;
}