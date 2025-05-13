#include <iostream>
#include <string>

const int MAX_STUDENTS = 40;
const int MAX_COURSES = 2; // Assuming 2 courses for simplicity

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grade;
};

// Function to calculate grade based on mark
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    // Add students
    // For simplicity, we're adding one course for all students
    Course course;
    course.course_code = "CS101";
    course.course_name = "Introduction to Computer Science";

    std::cout << "Adding students...\n";
    while (studentCount < MAX_STUDENTS) {
        Student newStudent;
        std::cout << "Enter registration number for student " << studentCount + 1 << ": ";
        std::cin >> newStudent.registration_number;
        std::cout << "Enter name for student " << studentCount + 1 << ": ";
        std::cin >> newStudent.name;
        std::cout << "Enter age for student " << studentCount + 1 << ": ";
        std::cin >> newStudent.age;

        newStudent.course = course;

        std::cout << "Enter mark for student " << studentCount + 1 << ": ";
        std::cin >> newStudent.grade.mark;
        newStudent.grade.the_grade = calculateGrade(newStudent.grade.mark);

        students[studentCount] = newStudent;
        studentCount++;

        char choice;
        std::cout << "Do you want to add another student? (Y/N): ";
        std::cin >> choice;
        if (choice != 'Y' && choice != 'y')
            break;
    }

    // Display students
    std::cout << "\nList of Students:\n";
    for (int i = 0; i < studentCount; ++i) {
        std::cout << "Student " << i + 1 << ":\n";
        std::cout << "Registration Number: " << students[i].registration_number << std::endl;
        std::cout << "Name: " << students[i].name << std::endl;
        std::cout << "Age: " << students[i].age << std::endl;
        std::cout << "Course Code: " << students[i].course.course_code << std::endl;
        std::cout << "Course Name: " << students[i].course.course_name << std::endl;
        std::cout << "Mark: " << students[i].grade.mark << std::endl;
        std::cout << "Grade: " << students[i].grade.the_grade << std::endl;
        std::cout << std::endl;
    }

    return 0;
}