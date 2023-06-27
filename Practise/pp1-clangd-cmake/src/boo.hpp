#pragma once             // 预处理指令，用于防止头文件被重复包含。它告诉编译器只编译一次这个头文件，以防止重复定义错误。
#include <cstddef>
#include <string>
#include <string_view>   // 代表了一个字符串的只读视图。它不拥有字符串的内存，而是引用另一个字符串的内存
#include <vector>

class Boo{
    public:
    Boo(std::string_view name); // 公共构造函数
    Boo(size_t id);     // size_t 是一个标准库类型，代表了一个无符号整数。这个类包含了一个私有的 _id 成员变量，它用于存储对象的 ID。
                        // 这个成员变量可以通过 getID 方法进行访问。

    void show() const;

    size_t getID() const {return _id;}
    std::string_view getName() const {return _name;}

    private:
    std::string _name;
    size_t _id;
};