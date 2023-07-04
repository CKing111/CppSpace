#include "../include/Logger.hpp"
#include <iostream>
#include <thread>

void worker(int threadId)
{
    Logger &logger = Logger::getInstance();     //获取单例实例
    logger.log("线程" + std::to_string(threadId) + "开始工作");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    logger.log("线程" + std::to_string(threadId) + "结束工作");
}

int main()
{
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);

    t1.join();
    t2.join();

    std::cout << "所有线程已结束" << std::endl;
    return 0;
}