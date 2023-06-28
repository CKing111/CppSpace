/**
 * @file main.cpp
 * @author Cxk (xiaokai.c.work@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include "../include/SManager.hpp"

using namespace std;


int main() {
    StudentManager manager;

    // 从文件中加载学生信息
    manager.load_from_file("students.txt");

    // 显示菜单
    cout << "Welcome to Student Management System!" << endl;
    while (true) {
        cout << "Please select an action:" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Remove a student" << endl;
        cout << "3. Modify student information" << endl;
        cout << "4. Query student information" << endl;
        cout << "5. Show all students" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {  // 添加学生
                string id, name, sex, major;
                int age;
                cout << "Please enter student information:" << endl;
                cout << "ID: ";
                getline(cin, id);
                cout << "Name: ";
                getline(cin, name);
                cout << "Age: ";
                cin >> age;
                cin.ignore();
                cout << "Sex: ";
                getline(cin, sex);
                cout << "Major: ";
                getline(cin, major);
                manager.add_student(new Student(id, name, age, sex, major));
                break;
            }
            case 2: {  // 删除学生
                string id;
                cout << "Please enter the student ID you want to remove: ";
                getline(cin, id);
                manager.remove_student(id);
                break;
            }
            case 3: {  // 修改学生信息
                string id, name, sex, major;
                int age;
                cout << "Please enter the student ID you want to modify: ";
                getline(cin, id);
                Student* student = manager.query_student(id);
                if (student) {
                    cout << "Please enter the new information for the student:" << endl;
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Age: ";
                    cin >> age;
                    cin.ignore();
                    cout << "Sex: ";
                    getline(cin, sex);
                    cout << "Major: ";
                    getline(cin, major);
                    manager.modify_student(id, name, age, sex, major);
                } else {
                    cout << "Student with ID " << id << " does not exist." << endl;
                }
                break;
            }
            case 4: {  // 查询学生信息
                string id;
                cout << "Please enter the student ID you want to query: ";
                getline(cin, id);
                Student* student = manager.query_student(id);
                if (student) {
                    cout << "Student information:" << endl;
                    cout << "ID: " << student->get_id() << endl;
                    cout << "Name: " << student->get_name() << endl;
                    cout << "Age: " << student->get_age() << endl;
                    cout << "Sex: " << student->get_sex() << endl;
                    cout << "Major: " << student->get_major() << endl;
                } else {
                    cout << "Student with ID " << id << " does not exist." << endl;
                }
                break;
            }
            case 5: {  // 显示所有学生信息
                manager.show_all_students();
                break;
            }
            case 6: {  // 退出程序
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: {  // 处理非法输入
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}