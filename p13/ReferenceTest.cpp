//
// Created by Carlos Arbizu on 2/3/21.
//
#include <iostream>
using std::cout;
using std::endl;
void change(int &change)
{
    change = 2;
}
int main(){
    int i=0;
    int y=1;
    int& icr=i;
    icr=y;
    icr=99;
    int x=9;
    icr=x;
    cout<<"icr: "<<i<<", y:"<<y<<endl;

    int t = 30;
    change(t);
    cout << t << endl;
    return 0;
}