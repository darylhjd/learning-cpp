#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct StudentGrade {
    std::string name{};
    char grade{};
};

class GradeMap {
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](const std::string& name);
};

char& GradeMap::operator[](const std::string& name) {
    // Check if the student exists.
    auto res{
        std::find_if(m_map.begin(), m_map.end(), 
        [&](const auto& stud) {
            return stud.name == name;
        })
    };

    // If found, return the grade.
    if (res != m_map.end()) {
        return res->grade;
    }
    // Else, create new StudentGrade for this student.
    m_map.push_back({ name });
    return m_map.back().grade;
}

int main() {
	GradeMap grades{};
 
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
 
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
 
	return 0;
}