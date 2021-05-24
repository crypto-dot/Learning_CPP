//
// Created by Carlos Arbizu on 5/15/21.
//
#include <vector>
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::cout;
using std::endl;
using std::make_shared;
using std::make_unique;
using std::cin;
class Test {
private:
    int data;
public:
     Test(int data): data{data}{}
     int getData() const {
        return data;
    }
    Test() : data{0}{}
    ~Test(){
         cout << "Destructor called" << endl;
     }
};
    unique_ptr<vector<shared_ptr<Test>>> make();
    void fill(vector<shared_ptr<Test>> &vec,int num);
    void display(const vector<shared_ptr<Test>> &vec);

int main(){
    int num;

    unique_ptr<vector<shared_ptr<Test>>> uniqueptr = make();
    cout << "How many data points do you want: "; cin >> num; cout << endl;
    fill(*uniqueptr,num);
    display(*uniqueptr);
    return 0;
}
unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>>();
}
void fill(vector<shared_ptr<Test>> &vec,int num){
    int numentry;
    for(size_t i {0}; i < num; ++i){
        cout << "Enter data point" << " [" << i + 1 << "]: "; cin >> numentry; cout << endl;
        vec.push_back(make_shared<Test>(numentry));
    }
}
void display(const vector<shared_ptr<Test>> &vec){
    for(const auto &Testptr : vec){
        cout << Testptr->getData() << endl;
    }
}
