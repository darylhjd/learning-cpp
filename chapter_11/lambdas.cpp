#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <string_view>

struct Student {
    std::string name{};
    int points{};
};

void print_best_student() {
    std::array<Student, 8> arr {
        {
            {"Albert", 3},
            {"Ben", 5},
            {"Christine", 2},
            {"Dan", 8}, // Dan has the most points (8).
            {"Enchilada", 4},
            {"Francis", 1},
            {"Greg", 3},
            {"Hagrid", 5}
        }
    };
    Student* stud{
        std::max_element(arr.begin(), arr.end(), 
            [](Student& a, Student& b) -> bool {
                return a.points < b.points;
            })
    };
    std::cout << stud->name << " is the best student.\n";
}

struct Season {
    std::string_view name{};
    double average_temp{};
};

void sort_seasons() {
    std::array<Season, 4> seasons{
        { 
            { "Spring", 285.0 },
            { "Summer", 296.0 },
            { "Fall", 288.0 },
            { "Winter", 263.0 } 
        }
    };

    std::sort(seasons.begin(), seasons.end(), 
        [](const auto& a, const auto& b) {
            return a.average_temp < b.average_temp;
        }
    );

    for (const auto& season: seasons) {
        std::cout << season.name << '\n';
    }
}


int main() {
    print_best_student();
    sort_seasons();
    return 0;
}