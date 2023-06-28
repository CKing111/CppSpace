#include "../include/SManager.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

StudentManager::StudentManager() noexcept{}
// noexcept:用于指定函数是否可能抛出异常。
//           当函数被声明为 noexcept 时，编译器可以根据这个信息对代码进行优化，以提高性能和可靠性。如果函数没有 noexcept 说明，
//          编译器会假定函数可能会抛出异常，因此必须生成额外的代码来处理异常。这会导致性能下降，代码变得更加复杂。
StudentManager::~StudentManager() noexcept{
    for (auto student : students_) {
        delete student;
    }
    students_.clear();
}

void StudentManager::add_student(Student* student) {
    students_.push_back(student);
}

void StudentManager::remove_student(const std::string& id) {
    for (auto it = students_.begin(); it != students_.end(); ++it) {
        if ((*it)->get_id() == id) {
            delete *it;
            students_.erase(it);
            return;
        }
    }
}

Student* StudentManager::query_student(const std::string& id) {
    for (auto student : students_) {
        if (student->get_id() == id) {
            return student;
        }
    }
    return nullptr;
}

void StudentManager::modify_student(const std::string& id, const std::string& name, int age, const std::string& sex, const std::string& major) {
    Student* student = query_student(id);
    if (student != nullptr) {
        student->set_name(name);
        student->set_age(age);
        student->set_sex(sex);
        student->set_major(major);
    }
}

void StudentManager::show_all_students() {
    for (auto student : students_) {
        student->display();
    }
}

void StudentManager::save_to_file(const std::string& filename) {
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cout << "Failed to open file " << filename << "." << endl;
        return;
    }

    for (auto student : students_) {
        ofs << student->get_id() << " " << student->get_name() << " " << student->get_age() << " " << student->get_sex() << " " << student->get_major() << endl;
    }

    ofs.close();
    cout << "Successfully saved " << students_.size() << " students to file " << filename << "." << endl;
}

void StudentManager::load_from_file(const std::string& filename) {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Failed to open file " << filename << "." << endl;
        return;
    }

    for (auto student : students_) {
        delete student;
    }
    students_.clear();

    string line;
    while (getline(ifs, line)) {
        stringstream ss(line);
        string id, name, sex, major;
        int age;
        ss >> id >> name >> age >> sex >> major;
        add_student(new Student(id, name, age, sex, major));
    }

    ifs.close();
    cout << "Successfully loaded " << students_.size() << " students from file " << filename << "." << endl;
}