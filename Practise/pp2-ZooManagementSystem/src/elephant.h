#include "animal.h"

// 大象类，继承自动物基类
class Elephant : public Animal {
  public:
    Elephant(const std::string& name);

    // 实现大象发出叫声的函数
    void makeSound() const override;
};