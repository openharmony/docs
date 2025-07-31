# Function Flow Runtime并发队列(C)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## 概述

FFRT并发队列提供了设置任务优先级（Priority）和队列并发度的能力，使得队列中的任务能同时在多个线程上执行，获得更高的并行效果。

- **队列并发度**：通过队列最大并发度设置，可以控制同一时刻同时执行的任务数量。这有助于避免任务并发过多对系统资源造成冲击，从而保证系统的稳定性和性能。
- **任务优先级**：用户可以为每个任务设置优先级，不同的任务将严格按照优先级进行调度和执行。相同优先级的任务按照排队顺序执行，高优先级的任务将优先于低优先级的任务执行，确保关键任务能够及时处理。

## 示例：银行服务系统

举例实现一个银行服务系统，每个客户向系统提交一个服务请求，可以区分普通用户和VIP用户，VIP用户的服务请求可以优先得到执行。
银行系统中有2个窗口，可以并行取出用户提交的服务请求办理。可以利用FFRT的并行队列范式做如下建模：

- **排队逻辑**：并行队列。
- **服务窗口**：并行队列的并发度，同时也对应FFRT Worker数量。
- **用户等级**：并行队列任务优先级。

实现代码如下所示：

```c
#include <stdio.h>
#include <unistd.h>
#include "ffrt/ffrt.h" // 来自 OpenHarmony 第三方库 "@ppd/ffrt"

ffrt_queue_t create_bank_system(const char *name, int concurrency)
{
    ffrt_queue_attr_t queue_attr;
    (void)ffrt_queue_attr_init(&queue_attr);
    ffrt_queue_attr_set_max_concurrency(&queue_attr, concurrency);

    // 创建一个并发队列
    ffrt_queue_t queue = ffrt_queue_create(ffrt_queue_concurrent, name, &queue_attr);

    // 队列创建完后需要销毁队列属性
    ffrt_queue_attr_destroy(&queue_attr);
    if (!queue) {
        printf("create queue failed\n");
        return NULL;
    }

    printf("create bank system successfully\n");
    return queue;
}

void destroy_bank_system(ffrt_queue_t queue_handle)
{
    ffrt_queue_destroy(queue_handle);
    printf("destroy bank system successfully\n");
}

void bank_business(void *arg)
{
    usleep(100 * 1000);
    const char *data = (const char *)arg;
    printf("saving or withdraw for %s\n", data);
}

// 封装提交队列任务函数
ffrt_task_handle_t commit_request(ffrt_queue_t bank, void (*func)(void *), const char *name,
    ffrt_queue_priority_t level, int delay)
{
    ffrt_task_attr_t task_attr;
    (void)ffrt_task_attr_init(&task_attr);
    ffrt_task_attr_set_name(&task_attr, name);
    ffrt_task_attr_set_queue_priority(&task_attr, level);
    ffrt_task_attr_set_delay(&task_attr, delay);

    return ffrt_queue_submit_h_f(bank, func, name, &task_attr);
}

// 封装取消队列任务函数
int cancel_request(ffrt_task_handle_t request)
{
    return ffrt_queue_cancel(request);
}

// 封装等待队列任务函数
void wait_for_request(ffrt_task_handle_t task)
{
    ffrt_queue_wait(task);
}

int main()
{
    ffrt_queue_t bank = create_bank_system("Bank", 2);
    if (!bank) {
        printf("create bank system failed\n");
        return -1;
    }

    ffrt_task_handle_t task1 = commit_request(bank, bank_business, "customer1", ffrt_queue_priority_low, 0);
    ffrt_task_handle_t task2 = commit_request(bank, bank_business, "customer2", ffrt_queue_priority_low, 0);
    // VIP享受更优先的服务
    ffrt_task_handle_t task3 = commit_request(bank, bank_business, "customer3 VIP", ffrt_queue_priority_high, 0);
    ffrt_task_handle_t task4 = commit_request(bank, bank_business, "customer4", ffrt_queue_priority_low, 0);
    ffrt_task_handle_t task5 = commit_request(bank, bank_business, "customer5", ffrt_queue_priority_low, 0);

    // 取消客户4的服务
    cancel_request(task4);

    // 等待所有的客户服务完成
    wait_for_request(task5);
    destroy_bank_system(bank);

    ffrt_task_handle_destroy(task1);
    ffrt_task_handle_destroy(task2);
    ffrt_task_handle_destroy(task3);
    ffrt_task_handle_destroy(task4);
    ffrt_task_handle_destroy(task5);
    return 0;
}
```

## 接口说明

上述样例中涉及到主要的FFRT的接口包括：

| 名称                                                                                               | 描述                   |
| -------------------------------------------------------------------------------------------------- | ---------------------- |
| [ffrt_queue_create](ffrt-api-guideline-c.md#ffrt_queue_t)                                     | 创建队列。             |
| [ffrt_queue_destroy](ffrt-api-guideline-c.md#ffrt_queue_t)                                   | 销毁队列。             |
| [ffrt_task_attr_set_queue_priority](ffrt-api-guideline-c.md#ffrt_task_attr_t)     | 设置队列任务优先级。   |
| [ffrt_queue_attr_set_max_concurrency](ffrt-api-guideline-c.md#ffrt_queue_attr_t) | 设置并发队列的并发度。 |
| [ffrt_queue_submit_h_f](ffrt-api-guideline-c.md#ffrt_queue_t)                             | 向队列提交一个任务。   |

> **说明：**
>
> - 如何使用FFRT C++ API详见：[FFRT C++接口三方库使用指导](ffrt-development-guideline.md#using-ffrt-c-api-1)。
> - 使用FFRT C接口或C++接口时，都可以通过FFRT C++接口三方库简化头文件包含，即使用`#include "ffrt/ffrt.h"`头文件包含语句。

## 约束限制

1. `ffrt_queue_attr_t`必须先调用`ffrt_queue_attr_init`初始化后再设置/获取属性，不再使用后需要显式调用`ffrt_queue_attr_destroy`释放资源。
2. `ffrt_queue_t`必须在进程退出前显式调用`ffrt_queue_destroy`释放资源。
3. 并发队列最大并发度建议控制在合理范围内，配置过大超过Worker线程数没有意义，配置过小可能导致系统资源利用率不足。
