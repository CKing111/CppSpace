#include "../include/Logger.hpp"
#include <iostream>

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

Logger::Logger()
{
    m_logFile.open("log.txt");
    if (!m_logFile.is_open())
    {
        std::cerr << "无法打开日志文件！" << std::endl;
        std::exit(1);
    }
}

Logger::~Logger()
{
    if (m_logFile.is_open())
    {
        m_logFile.close();
    }
}

void Logger::log(const std::string &message)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_logFile << message << std::endl;
}