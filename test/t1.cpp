#include <iostream>

using namespace std;

// 静态变量的自增效果
// void foo() {
//   static int x = 0;
//   x++;
//   std::cout << "x = " << x << std::endl;
// }

// int main() {
//   foo();
//   foo();
//   foo();
//   return 0;
// }



class MyClass {
public:
    static int count;
};

// int MyClass::count = 0;

int main() {
    std::cout << "MyClass::count = " << MyClass::count << std::endl;
    MyClass::count++;
    std::cout << "MyClass::count = " << MyClass::count << std::endl;
    MyClass::count++;
    std::cout << "MyClass::count = " << MyClass::count << std::endl;
    return 0;
}