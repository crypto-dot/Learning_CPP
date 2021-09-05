//
// Created by Carlos on 8/26/2021.
//

#include <iomanip>
using std::setw;
using std::left;
using std::setprecision;
using std::showpoint;
using std::right;
#include <cstring>
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;

struct City{
    string name;
    long population;
    double cost;
};
struct Country{
    std::string name;
    std::vector<City> cities;
};
struct Tours{
    std::string title;
    std::vector<Country> countries;
};

int main(){
    Tours tours{
        "Tour Ticket Prices From Miami",
        {
                {
                        "Colombia", {
                        {"Bogota", 8778000, 400.98,},
                        {"Cali", 2401000, 424.12},
                        {"Medellin", 2464000, 350.98},
                        {"Cartagena", 972000, 345.34}
                        }
                },
                {
                    "Brazil", {
                        {"Rio De Janiero",13500000,567.45},
                        {"Sao Paulo",11310000,975.45},
                        {"Salvador",18234000,855.99}
                    }
                },
                {
                    "Chile",{
                        {"Valdivia",260000,569.12},
                        {"Santiago",7040000,520.00}
                    }
                },
                {
                    "Argentina",{
                        {"Buenos Aires",3010000,728.77}
                    }
                }
        }

    };

    int full_length_of_table {49};
    int cost_data_stream_length {8};
    int SpaceBufferCountry {12};
    int PopulationBuffer {14};
    int CityBuffer {15};

    cout << setw(10) << "" << tours.title << "\n";
    cout <<  setw(SpaceBufferCountry)  <<  left << "Country" << setw(CityBuffer) << "City" <<  setw(PopulationBuffer) << "Population"
    << setw(cost_data_stream_length) << right << "Cost\n" << left;
    cout << std::setfill('-') << std::setw(full_length_of_table) <<  "-" << "\n" << std::setfill(' ');
    for(auto const &country : tours.countries){
        cout << setw(SpaceBufferCountry) << left << country.name;
        for(auto const &city : country.cities) {
            if (city.name == country.cities.at(0).name) {
                cout << setw(CityBuffer) << city.name << setw(PopulationBuffer) << city.population
                     << setw(cost_data_stream_length) << showpoint << std::setprecision(5) << right << city.cost
                     << "\n";
            }
            else {
                cout << setw(SpaceBufferCountry) << "";
                cout << setw(CityBuffer) << left << city.name << setw(PopulationBuffer) << city.population
                     << setw(cost_data_stream_length) << showpoint << std::setprecision(5) << right << city.cost
                     << "\n";
                if(country.cities.at(country.cities.size() - 1).name == city.name){
                    cout << "\n";
                }
            }
        }
    }
    cout << std::setfill('-') << std::setw(full_length_of_table) <<  "-" << "\n" << std::setfill(' ');
    return 0;
}
