#include <iostream>
#include <string>
#include <vector>

class Course {
private:
    std::string course_code;
    std::string course_name;

public:
    // Constructor
    Course(std::string code, std::string name) : course_code(code), course_name(name) {}

    // Getter methods
    std::string getCourseCode() const {
        return course_code;
    }

    std::string getCourseName() const {
        return course_name;
    }
};

class Grade {
private:
    int mark;
    char the_grade;

public:
    // Constructor
    Grade(int m) : mark(m) {
        if (mark > 69)
            the_grade = 'A';
        else if (mark > 59)
            the_grade = 'B';
        else if (mark > 49)
            the_grade = 'C';
        else if (mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }

    // Getter methods
    int getMark() const {
        return mark;
    }

    char getGrade() const {
        return the_grade;
    }
};

class Student {
private:
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grade;

public:
    // Constructor
    Student(std::string reg_num, std::string student_name, int student_age, Course student_course, int mark)
        : registration_number(reg_num), name(student_name), age(student_age), course(student_course), grade(mark) {}

    // Getter methods
    std::string getRegistrationNumber() const {
        return registration_number;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    Course getCourse() const {
        return course;
    }

    Grade getGrade() const {
        return grade;
    }

    // Method to update grade
    void updateGrade(int new_mark) {
        grade = Grade(new_mark);
    }
};

int main() {
    // Create a vector to store students
    std::vector<Student> students;

    // Add students
    Course course("CS101", "Introduction to Computer Science");

    students.push_back(Student("2023001", "John Doe", 20, course, 85));
    students.push_back(Student("2023002", "Jane Smith", 21, course, 75));

    // Display student details
    for (const auto& student : students) {
        std::cout << "Registration Number: " << student.getRegistrationNumber() << std::endl;
        std::cout << "Name: " << student.getName() << std::endl;
        std::cout << "Age: " << student.getAge() << std::endl;
        std::cout << "Course Code: " << student.getCourse().getCourseCode() << std::endl;
        std::cout << "Course Name: " << student.getCourse().getCourseName() << std::endl;
        std::cout << "Grade: " << student.getGrade().getGrade() << std::endl;
        std::cout << std::endl;
    }

    // Edit a student's grade
    students[0].updateGrade(90);

    std::cout << "Updated Grade for " << students[0].getName() << ": " << students[0].getGrade().getGrade() << std::endl;

    return 0;
}