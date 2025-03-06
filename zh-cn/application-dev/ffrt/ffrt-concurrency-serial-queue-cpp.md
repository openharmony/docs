# Function Flow Runtime串行队列(C++)

## 概述

FFRT串行队列基于协程调度模型实现，提供高效的消息队列功能，支持异步通信、流量削峰、无锁化状态和资源管理以及架构解耦等多种业务场景。FFRT串行队列支持以下功能：

- **​队列创建销毁**​，支持创建和销毁队列，创建时可指定队列名称和优先级。每个队列功能上相当于一个单独的线程，队列中的任务相对于用户线程异步执行。
- **任务延迟**​，支持在任务提交时设置延迟时间（`delay`），单位为微秒（`us`）。延迟任务将在`uptime`（提交时刻+延迟时间）后调度执行。
- **​串行调度**​，同一队列中的任务按照`uptime`升序排列，严格串行执行。确保队列中上一个任务完成后，下一个任务才会开始执行。
- **​任务取消**​，支持根据任务句柄取消未出队的任务。若任务已开始执行或执行完成，则无法取消。
- **​任务等待**​，支持根据任务句柄等待任务完成。指定任务完成时，队列中所有`uptime`早于该任务的任务均已执行完成。
- **任务优先级**​，支持在任务提交时设置单个任务的优先级。优先级仅在任务出队后相对于系统其他负载生效，不影响同一队列内任务的串行顺序。若未设置任务优先级，则默认继承队列的优先级。

## 示例：异步日志系统

举例实现一个异步日志系统，主线程将日志任务提交到队列，后台线程从队列中取出任务并写入文件。这种方式既能保证日志的顺序性，又能避免文件写入操作阻塞主线程。

借助FFRT并行化框架API，开发者只需专注于业务逻辑的实现，无需关注异步线程管理、线程安全及调度效率等问题。

用例简化了异常处理和线程安全相关的一些逻辑，实现代码如下所示：

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "ffrt.h"

class Logger {
public:
    Logger(const std::string& filename)
    {
        // 创建队列
        queue_ = std::make_unique<ffrt::queue>("loggerQueue");

        // 以追加模式打开文件
        logFile_.open(filename, std::ios::app);
        if (!logFile_.is_open()) {
            throw std::runtime_error("Failed to open log file: " + filename);
        }
        std::cout << "Log file opened: " << filename << std::endl;
    }

    ~Logger() {
        // 销毁队列
        queue_ = nullptr;

        if (logFile_.is_open()) {
            logFile_.close();
            std::cout << "Log file closed." << std::endl;
        }
    }

    // 添加日志任务
    void log(const std::string& message) {
        queue_->submit([this, message] {
            logFile_ << message << std::endl;
        });
    }

private:
    std::ofstream logFile_;
    std::unique_ptr<ffrt::queue> queue_;
};

int main()
{
    Logger logger("log.txt");

    // 主线程添加日志任务
    logger.log("Log message 1");
    logger.log("Log message 2");
    logger.log("Log message 3");

    // 模拟主线程继续执行其他任务
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}
```

## 接口说明

上述样例中涉及到主要的FFRT的接口包括：

| 名称                                                                                                                  | 描述           |
| --------------------------------------------------------------------------------------------------------------------- | -------------- |
| class [queue](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#queue)   | 队列类。       |
| [sleep_for](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#sleep_for) | 延迟一定时间。 |

> **说明：**
>
> 如何使用FFRT C++ API详见：[C++接口使用指导](ffrt-development-guideline.md#using-ffrt-c-api-1)

## 约束限制

- **避免提交超长任务** FFRT内置进程级队列任务超时检测机制。当串行任务执行时间超过预设阈值（默认30秒）时，系统将打印和上报异常日志，并触发预设的进程超时回调函数（如已配置）。
- **同步原语使用规范** 在提交给FFRT的任务闭包中，避免使用`std::mutex`、`std::condition_variable`和`std::recursive_mutex`，标准库同步原语会长时间占用FFRT Worker线程。请替换为FFRT提供的同步原语：`ffrt::mutex`、`ffrt::condition_variable`或`ffrt::recursive_mutex`，其用法与标准库相同。
- **全局变量中的队列管理** 若在全局变量中管理串行队列，随业务进程销毁，测试程序中需注意生命周期解耦问题。在测试用例结束时，需显式释放串行队列，其他资源可随全局变量释放。原因是全局变量在主函数结束后析构，而串行队列的释放依赖于FFRT框架中的其他资源，此时这些资源可能已被销毁。
