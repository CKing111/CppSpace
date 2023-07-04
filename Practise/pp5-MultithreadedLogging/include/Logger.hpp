#pragma once

#include <string>
#include <fstream>
#include <mutex>

class Logger
{
public:
    // 获取单例实例
    static Logger &getInstance();

    // 删除拷贝构造函数和赋值操作符
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    // 记录日志
    void log(const std::string &message);

private:
    // 私有默认构造函数
    Logger();

    // 私有析构函数
    ~Logger();

    std::ofstream m_logFile;
    std::mutex m_mutex;
};