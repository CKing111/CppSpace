/**
 * @file main.cpp
 * @author Cxk (xiaokai.c.work@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "src/elephant.h"
#include "src/lion.h"

#include <memory>
#include <vector>

int main() {
    // 使用智能指针管理动物对象,这行代码是一个用于动态存储和管理Animal对象的容器。
    std::vector<std::unique_ptr<Animal>> animals;
    // std::vector是一个动态数组容器，它可以在运行时动态增加或减少其大小，并且可以存储相同类型的元素。
    // std::unique_ptr是一个智能指针，它拥有指向动态分配内存的所有权，并在其生命周期结束时自动释放该内存。
    // std::vector<std::unique_ptr<Animal>>
    // animals;:语句创建了一个名为animals的std::vector对象，
    //                              该对象存储指向Animal对象的std::unique_ptr指针。
    //                              这意味着animals可以存储Animal的派生类对象的指针，因为它们都可以转换为Animal类型的指针。
    //                              此外，由于使用了std::unique_ptr，animals会在其生命周期结束时自动释放存储的指针指向的内存。
    // 添加动物到动物园

    animals.emplace_back(new Lion("Simba"));
    animals.emplace_back(new Elephant("Dumbo"));
    // emplace_back()是std::vector容器的一个成员函数，用于在容器的末尾添加一个新元素。
    // 与push_back()不同，emplace_back()使用构造函数直接在容器中构造新元素，而不是在内存中构造对象然后再将对象复制到容器中。
    // 使用emplace_back()可以避免不必要的对象复制和移动，提高程序的性能。
    // 第二种写法
    // std::vector<std::unique_ptr<Animal>> animals{
    //   std::make_unique<Lion>("Simba"),
    //   std::make_unique<Elephant>("Dumbo")
    // };

    // 让动物发出叫声
    for (const auto& animal : animals) {
        animal->makeSound();
        // 编译器会自动将其转换为(*animal).makeSound()的形式，即先解引用指针得到Animal对象，然后调用该对象的makeSound()函数。
    }

    return 0;
}