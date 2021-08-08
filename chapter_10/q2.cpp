#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name{};
    int grade{};
};

void getStudents(std::vector<Student>& s_vector) {
    for (int i{1}; auto& s: s_vector) {
        std::cout << "Enter student #" << i << ":\n"; 
        std::getline(std::cin >> std::ws, s.name);
        std::cin >> s.grade;
        ++i;
    }
}

void printStudents(std::vector<Student>& s_vector) {
    for (auto& student: s_vector) {
        std::cout << student.name << " got a grade of " << student.grade << '\n';
    }
}

bool greater_by_grade(Student& i, Student& j) {
    return i.grade > j.grade;
}

int main() {
    std::cout << "Enter number of students: ";
    int s_num{};
    std::cin >> s_num;

    // Create a vector to store the students.
    std::vector<Student> students(s_num);
    getStudents(students);

    // Sort the students by grades highest first.
    std::sort(students.begin(), students.end(), greater_by_grade);
    
    printStudents(students);
}