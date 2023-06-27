#pragma once
/*
#pragma
once是一个预处理指令，它的作用是确保头文件只被编译一次，这样可以避免由于多次包含同一头文件而导致的编译错误。
当预处理器遇到#pragma
once指令时，它会检查当前文件是否已被包含。如果是，则忽略该文件的其余部分。

使用#pragma once的好处是它可以提高编译速度，因为编译器只需要处理头文件一次。
此外，它还可以避免由于头文件包含错误而导致的编译错误，例如由于循环包含或多次包含同一头文件而导致的重复定义错误。

相比于传统的头文件保护宏，#pragma once更加简洁和方便。
使用#pragma
once可以避免使用保护宏时需要手动编写宏定义和条件编译指令的繁琐过程，也可以避免使用不同的宏定义命名方式而导致的重复定义问题。
因此，#pragma once是一种常用的头文件保护方式。
*/
#include <string>

// 动物基类
class Animal {
  public:
    Animal(const std::string& name);

    // 获取动物名称
    std::string getName() const;

    // 动物发出叫声的虚函数
    virtual void makeSound() const = 0;

  protected:
    std::string name;
};