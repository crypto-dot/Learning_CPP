//
// Created by Carlos Arbizu on 6/14/21.
//

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setprecision;
using std::setw;
using std::setfill;
using std::left;
using std::right;
int main(){
    double num {1234.5678};
    double Ruler{1234567890};
    cout <<  setprecision(10) << Ruler << Ruler << Ruler << endl; cout << setprecision(6);
    cout <<  setw(10) << num << "Hello" << endl; // setw makes it such that num ends at the 10 place in the output only applies to the next data item

    cout << setw(10) << num << setw(10) << "Hello" << setw(10) << "Hello" <<endl;
    //By default the data stream is right justified
    cout << setw(10) << left << num << "hello" << endl; //Notice how the data of num is place in a field width of 10 but shifted to the left
    //The left justification will persist
    cout << setw(10) << num << endl;

    cout << setfill('*');
    cout << setw(10) << num << "Hello" << endl;
    //Notice how setfill applies only to data items with a setwidth even after it is called!
    cout << setw(10) << "Hello" << endl;


    return 0;
}