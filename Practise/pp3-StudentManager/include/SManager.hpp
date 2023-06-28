
#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <vector>
#include "Student.hpp"

class StudentManager {
public:
    StudentManager() noexcept;
    ~StudentManager() noexcept;
    void add_student(Student* student);
    void remove_student(const std::string& id);
    Student* query_student(const std::string& id);
    void modify_student(const std::string& id, const std::string& name, int age, const std::string& sex, const std::string& major);
    void show_all_students();
    void load_from_file(const std::string& filename);
    void save_to_file(const std::string& filename);

private:
    std::vector<Student*> students_;
};

#endif