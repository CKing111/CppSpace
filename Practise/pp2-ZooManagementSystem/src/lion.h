#include "animal.h"

// 狮子类，继承自动物基类
class Lion : public Animal {
  public:
    Lion(const std::string& name);

    // 实现狮子发出叫声的函数
    void makeSound() const override;
};