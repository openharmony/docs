# Function Flow Runtime任务伙伴(C++)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 概述

从API version 20开始，FFRT支持Job_Partner功能。在实际业务中，可能会遇到某一个线程（比如UI绘制线程）耗时很长，难以充分利用CPU多核能力的情况。此时，将原有线程的大任务拆分为多个小任务交给其他线程去执行是解决该问题的有效方法。但是，在实践中，会遇到两个问题：

- 问题1：小任务中的部分片段受限于某些原因，必须执行在指定的线程上（比如访问JS虚拟机中的变量）。
- 问题2：小任务会被拆分为多个小片段（可能由于问题1或者其他原因），单次执行时间可能在微秒级，而单次线程唤醒的开销在几十个微秒级，难以获得并发收益。

为解决以上问题，Job Partner并发范式应运而生。

![image](figures/ffrt_figure8.png)

Job Partner并发范式中定义原先的线程为master线程，并支持动态管理partner线程（伙伴线程）。它有两个特性：

- 特性1：针对问题1，支持partner线程在执行任务过程中暂停当前任务的执行，之后将任务发送到master线程执行，直到master线程执行完成之后在partner线程继续执行原有任务。
- 特性2：针对问题2，利用批量小任务的特征，动态将多个小任务合并为更大的FFRT任务，以均摊单个小任务的调度开销。

## 示例：某商城系统

实现一个商城系统的节点并行化创建，要求节点创建的部分代码片段必须在JS线程中运行，其他片段可以在任意线程执行。

以下是原有伪代码实现：

```cpp
namespace market_system {
    // 批量创建节点，在js线程上被调用
    void create_nodes(std::array<Node>& nodes)
    {
        for (int i = 0; i < nodes.size(); i++) {
            code1(); // 可以在任意线程上执行的代码片段
            code2(); // 必须在js线程上执行的代码片段
            code3(); // 可以在任意线程上执行的代码片段
        }
    }
};
```

使用Job Partner并行化后的伪代码如下：

```cpp
#include <array>
#include <memory>
#include "ffrt/ffrt.h" // 来自 OpenHarmony 第三方库 "@ppd/ffrt"

namespace market_system {
    // 批量创建节点，在js线程上被调用
    void create_nodes(std::array<Node>& nodes)
    {
        constexpr uint64_t stack_size = 16 * 1024;
        auto stack = std::make_unique<std::array<char, stack_size>[]>(nodes.size()); // 创建job_num个执行栈
        auto partner = ffrt::job_partner<>::get_partner_of_this_thread(); // 获得当前js线程的伙伴
        for (int i = 0; i < nodes.size(); i++) {
            partner->submit([&] { // 每个节点的创建提交给partner
                code1(); // 可以在任意线程上执行的代码片段
                ffrt::job_partner<>::submit_to_master([&] { // 遇到必须在master线程执行的任务时发给主线程并同步等待
                    code2(); // 必须在js线程上执行的代码片段
                });
                code3(); // 可以在任意线程上执行的代码片段
            }, &stack[i], stack_size);
        }
        partner->wait(); // 等待所有节点创建完成
    }
};
```

## 接口说明

上述样例中涉及的主要FFRT接口及其功能包括：

| 名称                                                                                                                      | 描述                 |
| ------------------------------------------------------------------------------------------------------------------------- | -------------------- |
| [job_partner](https://gitcode.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#job_partner) | 细粒度任务伙伴接口。 |

> **说明：**
>
> - 如何使用FFRT C++ API详见：[FFRT C++接口三方库使用指导](ffrt-development-guideline.md#using-ffrt-c-api-1)。
> - 使用FFRT C接口或C++接口时，都可以通过FFRT C++接口三方库简化头文件包含，即使用`#include "ffrt/ffrt.h"`头文件包含语句。

## 约束限制

- 适用Job Partner并发范式的场景应该是粒度较小且不会长时间阻塞线程的大批量任务。
- 如果任务粒度较大（比如数百微秒以上），推荐使用FFRT更为通用的任务提交接口。
- 如果任务不满足大批量的特征，使用Job Partner并发范式并不能显著降低调度开销。
