//
// Created by Carlos Arbizu on 7/21/21.
//
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::setprecision;
using std::fixed;
using std::setfill;
#include <fstream>
using std::ifstream;
using std::string;
using std::getline;
#include <vector>
using std::vector;
#include <utility>
using std::pair;

size_t processScore(const string &answerKey,const string &Answer);
void printHeader();
void printBody(const vector<pair<string,size_t>> &StudentListWithGradesIncluded);
void printFooter(double average);
double calculateAverage(const vector<pair<string,size_t>> &StudentListWithGradesIncluded,size_t counter);

int main(){
    ifstream in_file {"Grades+AnswerKey.txt"};

    if(!in_file){
        cerr << "Problem opening file" << endl;
        return 1;
    }
    string answer;
    string student;
    vector<pair<string,size_t>> studentsWithGrades;
    string answerKey;
    size_t counter {1};
    double average;
    in_file >> answerKey;
    //Eof() in while not considered good practice read here:https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-i-e-while-stream-eof-cons
    while(!in_file.eof()){
        if(counter%2 == 0) {
                in_file >> answer;
                studentsWithGrades.emplace_back(std::make_pair(student, processScore(answerKey,answer)));
        }
        else {
            in_file >> student;
        }
        counter++;
    }

    printHeader();
    printBody(studentsWithGrades);
    average = calculateAverage(studentsWithGrades,counter);
    printFooter(average);
    in_file.close();
    return 0;
}

void printHeader(){
    cout <<  setw(18) << left << "Student" <<"Score" << endl;
    cout << setw(23) << setfill('-') << endl;
    cout << setfill(' ');
}

size_t processScore(const string &answerKey,const string &answer){
    size_t score {0};
    for (size_t i{0}; i < answerKey.length(); i++) {
        if (answerKey.at(i) == answer.at(i)) {
            score++;
        }
    }
    return score;
}
void printBody(const vector<pair<string,size_t>> &StudentListWithGradesIncluded){
    for(const std::pair<string,size_t> &studentWithGrade : StudentListWithGradesIncluded)
    {
        cout << setw(20) << studentWithGrade.first << studentWithGrade.second << endl;
    }
}

void printFooter(double average){
    cout << std::setw(23) << setfill('-')  << endl;
    cout << setfill(' ');
    cout << setw(23) << fixed << setprecision(2) << right << average << endl;
}
double calculateAverage(const vector<pair<string,size_t>> &StudentListWithGradesIncluded, size_t counter){
    //Counter counts the number of lines not the number of students however with a bit of math we can easily get the number of students
    //Assuming some basic facts
    double average {0};
    counter--;
    counter/= 2;
    for(const pair<string,size_t> &StudentWithGrade : StudentListWithGradesIncluded){
        average += StudentWithGrade.second;
    }
    if(counter != 0)
        average /= counter;
    else
        average = -1;
    return average;
}
