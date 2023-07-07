#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// 定义CSV文件的数据结构
struct CSVData {
  std::string column1; // name
  std::string column2; // speciality
  std::string column3; // achievement
                       // 添加更多的列，根据CSV文件的实际结构
};

int main() {
  std::vector<CSVData> data; // 实例化存储CSV数据的动态数组

  std::vector<std::string> filenames = {"公共课成绩.csv", "理科成绩.csv",
                                        "文科成绩.csv"}; // 要读取的CSV文件名

  for (const auto &filename : filenames) { // 遍历动态数组
    std::ifstream file(
        filename); // 用于从文件中读取数据。它提供了许多用于文件输入操作的方法和功能。
    if (!file) {
      std::cout << "无法打开文件：" << filename << std::endl;
      continue;
    }
    // if (file.is_open()) {
    // // 文件打开成功，可以进行读取操作
    // } else {
    //     // 文件打开失败
    //     std::cout << "无法打开文件：" << filename << std::endl;
    //     continue;
    // }

    // 逐行读取文件
    std::string line; //
    while (std::getline(
        file,
        line)) { // 从file中逐行读取数据，并将每行的内容存储在字符串变量line中，while遍历整个文件
      // 解析CSV文件中的每一行数据
      CSVData csvEntry;

      // 使用适当的分隔符解析CSV行
      // 这里假设CSV文件的列之间使用逗号分隔
      size_t pos = 0;
      std::string token;
      int columnCount = 0;
      // 在这个特定的代码行中，它的作用是在每行数据中查找逗号，并在找到逗号的位置之前进行一些处理。这通常用于解析CSV文件或以逗号分隔的数据。
      while (
          (pos = line.find(',')) !=
          std::string::
              npos) { // 这行代码使用std::string的find()函数来查找字符串line中逗号(',')的位置。
                      // find()函数会返回找到的字符或子字符串的位置，如果找不到则返回std::string::npos。
                      // while循环会不断查找逗号
        token = line.substr(
            0, pos); // 提取逗号之前的子字符串,起始索引位置和要提取的子串长度。
        // 更新line长度，方便后续搜索，+1表示删除‘，’
        line.erase(
            0,
            pos +
                1); // 用于从字符串中删除字符或子串。它接受一个或两个参数，用于指定要删除的内容的位置和长度。

        // 将解析的数据存储到CSVData结构中的相应列
        if (columnCount == 0)
          csvEntry.column1 = token; // name
        else if (columnCount == 1)
          csvEntry.column2 = token; // 专业
        else if (columnCount == 2)
          // std::cout<<"column3:"<<token<<std::endl;
          csvEntry.column3 = token; // 成绩
        // 添加更多的列解析，根据CSV文件的实际结构

        columnCount++;
      }
      // std::cout<<csvEntry<<std::endl;
      data.push_back(csvEntry); // 将CSV数据存储到动态数组中
    }

    file.close(); // 关闭文件
  }

  // 打印读取的CSV数据
  for (const auto &entry : data) { // 遍历动态数组
    std::cout << "Column 1: " << entry.column1
              << ", Column 2: " << entry.column2 
              << ", Column 3: " << entry.column3 << std::endl;
    // 打印更多的列，根据CSV文件的实际结构
  }

  return 0;
}

/*
Column 1: 学生A, Column 2: 公共课, Column 3: 80.5
Column 1: 学生B, Column 2: 公共课, Column 3: 85.3
Column 1: 学生C, Column 2: 公共课, Column 3: 75.9
Column 1: 学生D, Column 2: 公共课, Column 3: 80
Column 1: 学生E, Column 2: 公共课, Column 3: 78
Column 1: 学生F, Column 2: 公共课, Column 3: 88.9
Column 1: 学生G, Column 2: 公共课, Column 3: 93.2
Column 1: 学生H, Column 2: 公共课, Column 3: 76.5
Column 1: 学生B, Column 2: 理科, Column 3: 68.9
Column 1: 学生D, Column 2: 理科, Column 3: 83.2
Column 1: 学生F, Column 2: 理科, Column 3: 79.3
Column 1: 学生H, Column 2: 理科, Column 3: 85
Column 1: 学生A, Column 2: 文科, Column 3: 88.6
Column 1: 学生C, Column 2: 文科, Column 3: 79.3
Column 1: 学生E, Column 2: 文科, Column 3: 85
Column 1: 学生G, Column 2: 文科, Column 3: 83.9
*/
