//
// Created by Carlos Arbizu on 10/11/21.
//
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>
template<typename T,typename T2>
void display(const std::map<T,T2> &m){
    std::cout << "{";
    size_t count {0};
    size_t count2 {0};
    if constexpr(std::is_same_v<T2,std::decay_t<std::set<int>>> ){
        for (const auto &element: m) {
            if (count == m.size() - 1) {
                std::cout << element.first << ": {";
                for(const auto &element2 : element.second){
                    if(count2 == element.second.size() - 1 ){
                        std::cout << element2 << " } ";
                    }
                    else {
                        std::cout << element2 << ", ";
                    }
                    count2++;
                }
            } else {
                std::cout << element.first << ": {";
                for(const auto &element2 : element.second){
                    if(count2 == element.second.size() - 1 ){
                        std::cout << element2 << " } \n";
                    }
                    else {
                        std::cout << element2 << ", ";
                    }
                    count2++;
                }
            }
            count2 = 0;
            count++;
        }
    }
    else {
        for (const auto &element: m) {
            if (count == m.size() - 1) {
                std::cout << element.first << ": " << element.second;
            } else {
                std::cout << element.first << ": " << element.second << '\n';
            }
            count++;
        }
    }
    std::cout << "}";
    std::cout << '\n';
    std::cout << '\n';
}
void test1(){
    std::cout << std::setw(30) << std::setfill('=') << "" << "Test" << std::setw(30) << "" << '\n';
    std::map<std::string,int> m {
            {"Larry",1},
            {"Moe",3},
            {"Curly",4}
    };
    display(m);
    m.insert(std::pair<std::string,int> {"Carlos",2});

    display(m);

    m.insert(std::make_pair("Mike",30));

    display(m);

    m["New Key"] = 3;

    display(m);

    m["New Key"] += 5;

    display(m);

    m.erase("New Key");

    std::cout << "Count for Carlos: " << m.count("Carlos") << '\n';
    std::cout << "Count for New Key: " << m.count("New Key") << '\n';

    auto it = m.find("Carlos");

    if(it!= m.end()){
        std::cout << it->first << ": "  << it->second << '\n';
    }
    m.clear();

    display(m);

}
void test2(){
    std::map<std::string,std::set<int>> grades {
            {"Larry",{90,85,30}},
            {"Moe",{56,90}},
            {"Curly",{85,90}}
    };
    grades["Larry"].insert( 99);

    display(grades);

    auto it = grades.find("Moe");

    if(it != grades.end()){
        it->second.insert(100);
    }
    display(grades);
    grades.find("Moe")->second.insert(22);
    display(grades);
}
int main(){
/*    test1();*/
    test2();



    return 0;
}