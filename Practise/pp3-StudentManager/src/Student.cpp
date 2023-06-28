#include "../include/Student.hpp"

#include <iostream>

Student::Student(const std::string& id,
                 const std::string& name,
                 int age,
                 const std::string& sex,
                 const std::string& major)
    : id_(id),
      name_(name),
      age_(age),
      sex_(sex),
      major_(major) {}

std::string Student::get_id() const { return id_; }

std::string Student::get_name() const { return name_; }

int Student::get_age() const { return age_; }

std::string Student::get_sex() const { return sex_; }

std::string Student::get_major() const { return major_; }

void Student::set_name(const std::string& name) { name_ = name; }

void Student::set_age(int age) { age_ = age; }

void Student::set_sex(const std::string& sex) { sex_ = sex; }

void Student::set_major(const std::string& major) { major_ = major; }

void Student::display() {
    std::cout << "学生序号：" << id_ << ", 学生姓名：" << name_ << ",\n"
              <<"学生年龄： "<<age_<<", 学生性别： "<<sex_<<", 学生特长： "<<major_<< std::endl;
}