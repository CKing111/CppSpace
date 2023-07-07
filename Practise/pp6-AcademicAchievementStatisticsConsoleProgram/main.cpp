/**
 * @file main.cpp
 * @author Cxk (xiaokai.c.work@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-07-07
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
开发一个学习成绩统计控制台程序，读取学生成绩文件：公共课成绩.csv、文科成绩.csv、理科成绩.csv（不使用第三方csv库），
并提供命令行输入命令项方式显示统计结果：
1.	每个文科学生平均成绩
2.	每个理科学生平均成绩
3.	公共课平均成绩
4.	文科学生所有科目、公共科目、文科科目的平均成绩
5.	理科学生所有科目、公共科目、理科科目平均成绩
要求使用面向对象编程，使用类、继承、派生、多态、虚函数的概念，注意合理区分类的成员变量和成员函数的访问权限。
要求个人独自编程，可查阅资料，但不可抄袭其它同事的代码。
要求使用动态申请的数组方式进行学生信息保存，即本试题不允许使用STL容器相关代码。
要求能正确运行程序，新增或删除学生成绩记录也能正确运行，并进行代码讲解。
要求程序代码尽量精简，重复代码整理成函数。

要点： OOP、类、继承、派生、多态、虚函数

这段代码实现了一个学习成绩统计控制台程序，可以读取学生成绩文件并提供命令行输入命令项方式显示统计结果。
程序使用了面向对象编程的概念，包括类、继承、派生、多态、虚函数，并注意了合理区分类的成员变量和成员函数的访问权限。

程序首先定义了一个Student基类，包括学生的姓名和公共课成绩，以及一个虚函数average_score用于计算平均成绩。
然后定义了两个派生类LiberalArtsStudent和ScienceStudent，分别代表文科学生和理科学生，它们在基类的基础上增加了文科或理科成绩，
并重载了虚函数average_score计算平均成绩。

程序还定义了一个read_csv_line函数用于读取CSV文件中的一行数据，并将其转换为字符串向量返回。然后定义了一个load_scores函数用于加载学生成绩，
它使用read_csv_line函数读取CSV文件中的每一行数据，并将公共课成绩、文科成绩和理科成绩分别存储到LiberalArtsStudent和ScienceStudent对象中。

最后，主函数main调用load_scores函数加载学生成绩，然后按照题目要求依次输出每个文科学生平均成绩、每个理科学生平均成绩、公共课平均成绩、
文科学生所有科目、公共科目、文科科目的平均成绩以及理科学生所有科目、公共科目、理科科目平均成绩。程序还释放了动态分配的内存。

*/

/*
【规则5-1】变量命名时，全局变量加前缀g_（表示global），类数据成员加前缀
m_（表示member），静态变量加前缀s_（表示static）
【规则5-2】函数、变量和参数用小写字母开头的单词或词组命名，使用词组时，除
第一个单词外，后续单词首字母大写；宏定义全用大写的字母，用下划线分隔单词；
枚举值用枚举类型（或其缩写）加枚举名的方式定义，中间以下划线分隔；名称应尽
量具备自注释性
【规则5-3】类名加前缀C（表示class），结构名加前缀S（表示struct），枚举名
加前缀E（表示enum)，联合体加前缀U（表示union ）

*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// 定义CSV文件的数据结构
struct SCsvData {
    std::string column1; // name
    float column2;       // 成绩1
    float column3;       // 成绩2
    float column4;       // 成绩3
    float column5;       // 成绩4
    float column6;       // 成绩5
};

// 学生基类Base
class CStudent {

  public:
    CStudent() { std::cout << "CStudent基类，默认构造函数调用！" << std::endl; }
    CStudent(std::string name, std::vector<SCsvData> score) {
        m_name = name;
        m_score = score;
        std::cout << "CStudent基类，有参构造函数调用！" << std::endl;
    }
    CStudent(const CStudent& student) {
        m_name = student.m_name;
        m_score = student.m_score;
        std::cout << "CStudent基类，拷贝构造函数调用！" << std::endl;
    }

    // 虚析构
    virtual ~CStudent() = 0;             // 纯虚析构函数
    virtual float getAverageScore() = 0; // 计算平均分数
    virtual void printInfo() = 0;        // 输出得分信息

  protected:
    std::string m_name;            // 学生姓名
    std::vector<SCsvData> m_score; // 实例化存储CSV数据的动态数组
};
// 实例化纯虚析构函数
CStudent::~CStudent() {
    std::cout << "CStudent基类，析构函数调用！" << std::endl;
}

// 公共课程学生类
class CCommonCourseStudent : public CStudent {
  public:
    CCommonCourseStudent() {
        std::cout << "CCommonCourseStudent子类，默认构造函数调用！"
                  << std::endl;
    }
    CCommonCourseStudent(std::string name, std::vector<SCsvData> score) {
        m_CCName = name;
        m_CCScore = score;
        std::cout << "CCommonCourseStudent子类，有参构造函数调用！"
                  << std::endl;
    }
    CCommonCourseStudent(const CCommonCourseStudent& student) {
        m_name = student.m_CCName;
        m_score = student.m_CCScore;
        std::cout << "CCommonCourseStudent子类，拷贝构造函数调用！"
                  << std::endl;
    }
    // 使用override关键字来声明这个函数是重写基类中的同名函数。这样做的好处是可以让编译器在编译时检查是否存在同名函数，从而提高代码的安全性和可读性
    virtual ~CCommonCourseStudent() override{
        std::cout << "CCommonCourseStudent子类，析构函数调用！" << std::endl;
    }; 
    virtual float getAverageScore() override{}; // 计算平均分数
    virtual void printInfo() override{};        // 输出得分信息
  protected:
    std::string m_CCName;            // 学生姓名
    std::vector<SCsvData> m_CCScore; // 实例化存储CSV数据的动态数组
};
// 文科学生类
class CliberalArtsStudent : public CStudent {};
// 理科学生类
class CScienceStudent : public CStudent {};

// 学生基类Base
class Student {
  protected:
    std::string m_name;
    double public_score; // 公共课成绩  ***

  public:
    Student(const std::string& name,
            double public_score) // 构造，姓名、公共成绩
        : m_name(name),
          public_score(public_score) {}

    // 虚析构函数
    virtual ~Student() {}

    // 纯虚函数，计算平均成绩
    virtual double average_score() const = 0;

    const std::string& get_name() const { return m_name; }
    const double& get_public_score() const { return public_score; }
};

// 文科学生类
class LiberalArtsStudent : public Student {
  private:
    double liberal_arts_score; // 文科成绩

  public:
    LiberalArtsStudent(const std::string& name,
                       double public_score,
                       double liberal_arts_score)
        : Student(name, public_score),
          liberal_arts_score(liberal_arts_score) {}

    double average_score() const override {
        return (public_score + liberal_arts_score) / 2;
    }

    double get_liberal_arts_score() const { return liberal_arts_score; }
};

// 理科学生类
class ScienceStudent : public Student {
  private:
    double science_score; // 理科成绩

  public:
    ScienceStudent(const std::string& name,
                   double public_score,
                   double science_score)
        : Student(name, public_score),
          science_score(science_score) {}

    double average_score() const override {
        return (public_score + science_score) / 2;
    }

    double get_science_score() const { return science_score; }
};

// 读取CSV文件
std::vector<std::string> read_csv_line(std::istream& file) {
    // 声明不同对象
    std::vector<std::string> result; // 输出
    std::string line;                // 行目标
    std::getline(file, line);        //
    std::istringstream line_stream(
        line); // 创建一个包含字符串的输入字符串流对象
    std::string cell;
    while (std::getline(line_stream, cell, ',')) {
        result.push_back(cell);
    }
    // 这段代码使用std::getline()函数从line_stream中按照逗号(',')作为分隔符逐个读取数据，
    // 并将每个数据单元存储到result向量中。
    return result;
}

// 加载学生成绩
void load_scores(const std::string& public_filename,
                 const std::string& liberal_arts_filename,
                 const std::string& science_filename,
                 std::vector<LiberalArtsStudent*>&
                     liberal_arts_students, // 存储数据的动态数组
                 std::vector<ScienceStudent*>& science_students) {
    std::ifstream public_file(public_filename);
    std::ifstream liberal_arts_file(liberal_arts_filename);
    std::ifstream science_file(science_filename);

    if (!public_file || !liberal_arts_file || !science_file) {
        throw std::runtime_error("无法打开成绩文件");
    }

    // 跳过CSV文件的标题行
    // 读取CSV文件
    read_csv_line(public_file);
    read_csv_line(liberal_arts_file);
    read_csv_line(science_file);

    // 声明不同类型动态变量
    std::vector<std::string> public_line;
    std::vector<std::string> liberal_arts_line;
    std::vector<std::string> science_line;

    while ((public_line = read_csv_line(public_file)).size() >
           1) { // 遍历总人数
        liberal_arts_line = read_csv_line(liberal_arts_file);
        science_line = read_csv_line(science_file);

        liberal_arts_students.push_back(
            new LiberalArtsStudent(public_line[0],
                                   std::stod(public_line[1]),
                                   std::stod(liberal_arts_line[1])));

        science_students.push_back(
            new ScienceStudent(public_line[0],
                               std::stod(public_line[1]),
                               std::stod(science_line[1])));
    }
}

int main() {
    std::vector<LiberalArtsStudent*> liberal_arts_students;
    std::vector<ScienceStudent*> science_students;

    try {
        // 加载目标对象
        load_scores("公共课成绩.csv",
                    "文科成绩.csv",
                    "理科成绩.csv",
                    liberal_arts_students,
                    science_students);
    } catch (const std::exception& e) {
        std::cerr << "错误：" << e.what() << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);
    // std::fixed:操纵符，用于将浮点数将始终以固定的小数位数输出，不会根据数字的大小进行自动调整。
    // std::setprecision(2)：操纵符，用于设置浮点数的小数精度为2位。
    std::cout << "文科学生平均成绩：\n";
    for (const auto& student : liberal_arts_students) {
        std::cout << student->get_name() << ": " << student->average_score()
                  << std::endl;
    }

    std::cout << "\n理科学生平均成绩：\n";
    for (const auto& student : science_students) {
        std::cout << student->get_name() << ": " << student->average_score()
                  << std::endl;
    }

    // 声明变量
    double public_total_score = 0;
    double liberal_arts_total_score = 0;
    double science_total_score = 0;
    int total_students = liberal_arts_students.size() + science_students.size();

    for (const auto& student : liberal_arts_students) {
        public_total_score += student->get_public_score(); //->public_score;
        liberal_arts_total_score += student->get_liberal_arts_score();
    }

    for (const auto& student : science_students) {
        public_total_score += student->get_public_score(); //->public_score;
        science_total_score += student->get_science_score();
    }

    std::cout << "\n公共课平均成绩: " << public_total_score / total_students
              << std::endl;

    std::cout << "\n文科学生所有科目、公共科目、文科科目的平均成绩: "
              << (public_total_score + liberal_arts_total_score) /
                     (2 * liberal_arts_students.size())
              << ", " << public_total_score / liberal_arts_students.size()
              << ", " << liberal_arts_total_score / liberal_arts_students.size()
              << std::endl;

    std::cout << "\n理科学生所有科目、公共科目、理科科目平均成绩: "
              << (public_total_score + science_total_score) /
                     (2 * science_students.size())
              << ", " << public_total_score / science_students.size() << ", "
              << science_total_score / science_students.size() << std::endl;

    // 释放动态分配的内存
    for (auto student : liberal_arts_students) {
        delete student;
    }

    for (auto student : science_students) {
        delete student;
    }

    return 0;
}