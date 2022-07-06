# HiSysEvent打点

## 概述

### 功能简介

HiSysEvent打点提供了事件埋点功能，开发者可以通过在关键路径埋点来记录系统在运行过程中的重要信息。

### 运作机制

在进行HiSysEvent事件埋点之前，需要先完成HiSysEvent打点配置，具体配置方法请参考[《HiSysEvent打点配置指导》](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-dfx-hisysevent-logging-config.md)。

## 开发指导

### 场景介绍

事件埋点的主要工作是将打点数据进行落盘。

### 接口说明

#### c++接口说明

c++事件埋点开发能力如下：HiSysEvent类，具体的API详见接口文档 。

**表1** c++事件埋点API接口功能介绍

| 接口名                                                       | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| template&lt;typename...&nbsp;Types&gt;&nbsp;<br>static&nbsp;int&nbsp;Write(const&nbsp;std::string&nbsp;&amp;domain,&nbsp;const&nbsp;std::string&nbsp;&amp;eventName,&nbsp;EventType&nbsp;type,&nbsp;Types...&nbsp;keyValues) | 将打点事件数据进行落盘 |

 **表2** c++事件类型API接口介绍

| 接口名    | 描述         |
| --------- | ------------ |
| FAULT     | 故障类型事件 |
| STATISTIC | 统计类型事件 |
| SECURITY  | 安全类型事件 |
| BEHAVIOR  | 行为类型事件 |

#### kernel接口说明

kernel事件埋点开发能力如下：

**表3** kernel事件埋点API接口功能介绍

| 接口名                                                       | 描述                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| struct hiview_hisysevent *hisysevent_create(const char *domain, const char *name, enum hisysevent_type type); | 创建一个事件对象                     |
| void hisysevent_destroy(struct hiview_hisysevent *event);    | 销毁一个事件对象                     |
| int hisysevent_put_integer(struct hiview_hisysevent *event, const char *key, long long value); | 将整数类型的事件参数添加到事件对象   |
| int hisysevent_put_string(struct hiview_hisysevent *event, const char *key, const char *value); | 将字符串类型的事件参数添加到事件对象 |
| int hisysevent_write(struct hiview_hisysevent *event);       | 将事件对象数据进行落盘               |

**表4** kernel事件类型API接口介绍

| 接口名    | 描述         |
| --------- | ------------ |
| FAULT     | 故障类型事件 |
| STATISTIC | 统计类型事件 |
| SECURITY  | 安全类型事件 |
| BEHAVIOR  | 行为类型事件 |

### 开发步骤

#### c++埋点开发步骤

1. 在需要埋点的地方直接调用埋点接口，并传入相应事件参数即可：

   ```c++
   HiSysEvent::Write(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
   ```

#### kernel埋点开发步骤

1. 根据事件领域、事件名称、事件类型参数，创建一个基础的事件对象：

   ```c
   struct hiview_hisysevent *event = hisysevent_create("KERNEL", "BOOT", BEHAVIOR);
   ```

2. 将自定义的事件参数，传入到事件对象里：

   ```c
   // 添加整数类型参数
   hisysevent_put_integer(event, "BOOT_TIME", 100);

   // 添加字符串类型参数
   hisysevent_put_string(event, "MSG", "This is a test message");
   ```

3. 在事件对象构建完成后，将事件进行上报：

   ```c
   hisysevent_write(event);
   ```

4. 事件上报完成后，需要手动将对象销毁：

   ```c
   hisysevent_destroy(&event);
   ```

### 开发实例

#### c++埋点开发实例

假设业务模块需要在应用启动时进行埋点来记录应用启动事件，且需要记录应用的包名信息，完整使用示例如下所示：

1. 首先，需要在业务模块的在BUILD.gn里增加HiSysEvent部件依赖：

   ```c++
   external_deps = [ "hisysevent_native:libhisysevent" ]
   ```

2. 在业务模块的应用启动函数StartAbility()中，调用埋点接口并传入对应事件参数：


   ```c++
   #include "hisysevent.h"

   int StartAbility()
   {
       ... // 其他业务逻辑
       int ret = HiSysEvent::Write(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
       ... // 其他业务逻辑
   }
   ```

#### kernel埋点开发实例

假设内核业务模块需要在设备启动时进行埋点来记录设备启动事件，完整使用示例如下所示：

1. 在设备启动函数device_boot()中，构建一个启动事件对象，然后将事件进行上报，最后销毁事件对象。

```c
#include <dfx/hiview_hisysevent.h>

#include <linux/errno.h>
#include <linux/printk.h>

int device_boot()
{
    ... // 其他业务逻辑
    struct hiview_hisysevent *event = NULL;
    int ret = 0;

    event = hisysevent_create("KERNEL", "BOOT", BEHAVIOR);
    if (!event) {
        pr_err("failed to create event");
        return -EINVAL;
    }
    ret = hisysevent_put_string(event, "MSG", "This is a test message");
    if (ret != 0) {
        pr_err("failed to put sting to event, ret=%d", ret);
        goto hisysevent_end;
    }
    ret = hisysevent_write(event);

hisysevent_end:
    hisysevent_destroy(&event);
    ... // 其他业务逻辑
}
```

# 参考

HiSysEvent模块会将埋点数据写入到节点文件中，而埋点数据的解析处理会在Hiview模块中统一进行，详细处理过程可参考[Hiview开发指导](subsys-dfx-hiview.md)。
