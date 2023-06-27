#include"boo.hpp"
#include<cstddef>       // 提供了对 size_t 类型的定义。
#include</home/cxk/project/fmt/include/fmt/core.h>
#include</home/cxk/project/fmt/include/fmt/format.h>
#include<string_view>

Boo::Boo(std::string_view name){
    _name = name;
    _id = 0;
}

Boo::Boo(size_t id){
    _name = "";
    _id = id;
}

void Boo::show()const{
    fmt::print("I'm {0}, my id is {1}!/n",_name,_id);
}

