#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
public:
    Student(const std::string& id, const std::string& name, int age, const std::string& sex, const std::string& major);
    std::string get_id() const;
    std::string get_name() const;
    int get_age() const;
    std::string get_sex() const;
    std::string get_major() const;
    void set_name(const std::string& name);
    void set_age(int age);
    void set_sex(const std::string& sex);
    void set_major(const std::string& major);
    void display();
private:
    std::string id_;
    std::string name_;
    int age_;
    std::string sex_;
    std::string major_;
};

#endif
// private:
//     string id;    // 学号
//     string name;  // 姓名
//     int age;      // 年龄
//     string sex;   // 性别
//     string major; // 专业
// };