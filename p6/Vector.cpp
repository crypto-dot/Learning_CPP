//
// Created by Carlos Arbizu on 11/28/20.
//
#include <vector>
#include <iostream>
using namespace std;
int main(){

    vector<int> vector1;

    vector<int> vector2;
    vector<int> vector3 (300,1); // sets vector 3 to have 300 indices all filled with 1s
    vector1.push_back(10);
    vector1.push_back(20);
    cout << vector1.size() << " is the size of vector1 " <<  "and the two elements in it are " << vector1.at(0) << " and " << vector1.at(1) << endl;
    vector2.push_back(100);
    vector2.push_back(200);
    cout << vector2.size() << " is the size of vector2 " << "and the two elements in it are " << vector1.at(0) << " and " << vector2.at(1) << endl;
    vector<vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << vector_2d.size() << " is the size of vector_2d" << " and the elements in it are " << vector_2d.at(0).at(0) << " " <<
    vector_2d.at(0).at(1) << " " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    vector1.at(0) = 1000;
    std::cout << vector_2d.size() << " is the size of vector_2d" << " and the elements in it (after setting vector1[0] to 1000) are " << vector_2d.at(0).at(0) << " " <<
              vector_2d.at(0).at(1) << " " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << std::endl;
    std::cout << vector1.size() << " is the size of vector1 " <<  "and the two elements in it are (after setting vector1[0] to 1000) " << vector1.at(0) << " and " << vector1.at(1) << std::endl;
    return 0;

}