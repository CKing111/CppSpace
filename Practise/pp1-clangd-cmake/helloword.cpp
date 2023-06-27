#include "src/boo.hpp"

#include </home/cxk/project/fmt/include/fmt/core.h>
#include </home/cxk/project/fmt/include/fmt/format.h>
#include <array>
#include <cstdio>
// #include <iostream>

int main() {
    //   auto arr = std::to_array({0, 1, 2, 3, 4, 5});
    std::array<int, 6> arr = {0, 1, 2, 3, 4, 5};

    for (int val : arr) {
        std::printf("%d, ", val);
    }

    std::printf("Hello Word!!\n");
    Boo b1("Tom");
    Boo b2(-1);

    b1.show();
    b2.show();

    return 0;
}

/*
#include <array>
#include <initializer_list>

template <typename T, std::size_t N>
std::array<T, N> to_array(const std::initializer_list<T>& ilist) {
    std::array<T, N> arr{};
    std::copy(ilist.begin(), ilist.end(), arr.begin());
    return arr;
}

int main() {
    auto arr = to_array<int, 6>({0, 1, 2, 3, 4, 5});
    // 使用 arr 进行其他操作
    return 0;
}
*/

// using namespace std;

// int main() {
//   cout << "hello word!!" << endl;
//   system("pause");
//   return EXIT_SUCCESS;
// }