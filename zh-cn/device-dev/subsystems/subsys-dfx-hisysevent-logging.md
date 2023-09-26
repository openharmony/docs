# HiSysEvent打点

## 概述

### 功能简介

HiSysEvent打点提供了事件打点功能，开发者可以通过在关键路径打点来记录系统在运行过程中的重要信息。同时，HiSysEvent打点也提供了以事件领域为单位的HiSysEvent打点屏蔽机制，方便开发者评估及调试HiSysEvent打点操作的影响。

### 运作机制

在进行HiSysEvent事件打点之前，需要先完成HiSysEvent打点配置，具体配置方法请参考[HiSysEvent打点配置指导](subsys-dfx-hisysevent-logging-config.md)。

## 开发指导

### 场景介绍

事件打点的主要工作是将打点数据进行落盘。

### 接口说明

#### C++接口说明

C++事件打点开发能力如下：HiSysEvent类，具体API详见接口目录（/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent/include/）。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 
> 从OpenHarmony-3.2-Beta3版本开始，为避免打点风暴事件引发性能问题，对HiSysEvent打点进行了管控。表1中的HiSysEvent::Write打点接口被表2中的HiSysEventWrite宏接口取代。HiSysEvent::Write接口已废弃，请使用HiSysEventWrite宏接口完成HiSysEvent事件打点。

**表1** 事件打点接口（已废弃）

| 接口名                                                       | 描述                   |
| ------------------------------------------------------------ | --------------------- |
| template&lt;typename...&nbsp;Types&gt;&nbsp;<br>static&nbsp;int&nbsp;Write(const&nbsp;std::string&nbsp;&amp;domain,&nbsp;const&nbsp;std::string&nbsp;&amp;eventName,&nbsp;EventType&nbsp;type,&nbsp;Types...&nbsp;keyValues) | 将打点事件数据进行落盘。 |

**表2** 事件打点宏接口

| 接口名                                                       | 描述                   |
| ------------------------------------------------------------ | --------------------- |
| HiSysEventWrite(domain, eventName, type, ...)                | 将打点事件数据进行落盘。 |

 **表3** EventType事件类型枚举

| 事件类型   | 描述        |
| --------- | ----------- |
| FAULT     | 故障类型事件。 |
| STATISTIC | 统计类型事件。 |
| SECURITY  | 安全类型事件。 |
| BEHAVIOR  | 行为类型事件。 |

#### C接口说明

C事件打点开发能力如下：具体API详见接口目录（/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent/include/）。

**表4** 事件打点接口

| 接口名                                                       | 描述                     |
| ------------------------------------------------------------ | ------------------------ |
| int OH_HiSysEvent_Write(const char\* domain, const char\* name, HiSysEventEventType type, HiSysEventParam params[], size_t size); | 将打点事件数据进行落盘。 |

**表5** HiSysEventEventType事件类型枚举

| 事件类型             | 描述           |
| -------------------- | -------------- |
| HISYSEVENT_FAULT     | 故障类型事件。 |
| HISYSEVENT_STATISTIC | 统计类型事件。 |
| HISYSEVENT_SECURITY  | 安全类型事件。 |
| HISYSEVENT_BEHAVIOR  | 行为类型事件。 |

**表6** HiSysEventParam事件参数结构体

| 属性名称  | 属性类型             | 描述                               |
| --------- | -------------------- | ---------------------------------- |
| name      | char name[]          | 事件参数名称。                     |
| t         | HiSysEventParamType  | 事件参数类型。                     |
| v         | HiSysEventParamValue | 事件参数值。                       |
| arraySize | size_t               | 事件参数值为数组类型时的数组长度。 |

**表7** HiSysEventParamType事件参数类型枚举

| 参数类型                | 描述                       |
| ----------------------- | -------------------------- |
| HISYSEVENT_INVALID      | 无效类型事件参数。         |
| HISYSEVENT_BOOL         | bool类型事件参数。         |
| HISYSEVENT_INT8         | int8_t类型事件参数。       |
| HISYSEVENT_UINT8        | uint8_t类型事件参数。      |
| HISYSEVENT_INT16        | int16_t类型事件参数。      |
| HISYSEVENT_UINT16       | uint16_t类型事件参数。     |
| HISYSEVENT_INT32        | int32_t类型事件参数。      |
| HISYSEVENT_UINT32       | uint32_t类型事件参数。     |
| HISYSEVENT_INT64        | int64_t类型事件参数。      |
| HISYSEVENT_UINT64       | uint64_t类型事件参数。     |
| HISYSEVENT_FLOAT        | float类型事件参数。        |
| HISYSEVENT_DOUBLE       | double类型事件参数。       |
| HISYSEVENT_STRING       | char*类型事件参数。        |
| HISYSEVENT_BOOL_ARRAY   | bool数组类型事件参数。     |
| HISYSEVENT_INT8_ARRAY   | int8_t数组类型事件参数。   |
| HISYSEVENT_UINT8_ARRAY  | uint8_t数组类型事件参数。  |
| HISYSEVENT_INT16_ARRAY  | int16_t数组类型事件参数。  |
| HISYSEVENT_UINT16_ARRAY | uint16_t数组类型事件参数。 |
| HISYSEVENT_INT32_ARRAY  | int32_t数组类型事件参数。  |
| HISYSEVENT_UINT32_ARRAY | uint32_t数组类型事件参数。 |
| HISYSEVENT_INT64_ARRAY  | int64_t数组类型事件参数。  |
| HISYSEVENT_UINT64_ARRAY | uint64_t数组类型事件参数。 |
| HISYSEVENT_FLOAT_ARRAY  | float数组类型事件参数。    |
| HISYSEVENT_DOUBLE_ARRAY | double数组类型事件参数。   |
| HISYSEVENT_STRING_ARRAY | char*数组类型事件参数。    |

**表8** HiSysEventParamValue事件参数值联合体

| 属性名称 | 属性类型 | 描述                     |
| -------- | -------- | ------------------------ |
| b        | bool     | bool类型事件参数值。     |
| i8       | int8_t   | int8_t类型事件参数值。   |
| ui8      | uint8_t  | uint8_t类型事件参数值。  |
| i16      | int16_t  | int16_t类型事件参数值。  |
| ui16     | uint16_t | uint16_t类型事件参数值。 |
| i32      | int32_t  | int32_t类型事件参数值。  |
| ui32     | uint32_t | uint32_t类型事件参数值。 |
| i64      | int64_t  | int64_t类型事件参数值。  |
| ui64     | uint64_t | uint64_t类型事件参数值。 |
| f        | float    | float类型事件参数值。    |
| d        | double   | double类型事件参数值。   |
| s        | char*    | char*类型事件参数值。    |
| array    | void*    | 数组类型事件参数值。     |

#### kernel接口说明

kernel事件打点开发能力如下：具体API详见接口文件（/kernel/linux/linux-5.10/include/dfx/hiview_hisysevent.h）。

**表9** 事件打点接口

| 接口名                                                       | 描述                                 |
| ------------------------------------------------------------ | ----------------------------------- |
| struct hiview_hisysevent *hisysevent_create(const char *domain, const char *name, enum hisysevent_type type); | 创建一个事件对象。    |
| void hisysevent_destroy(struct hiview_hisysevent *event);    | 销毁一个事件对象。                                                     |
| int hisysevent_put_integer(struct hiview_hisysevent *event, const char *key, long long value); | 将整数类型的事件参数添加到事件对象。   |
| int hisysevent_put_string(struct hiview_hisysevent *event, const char *key, const char *value); | 将字符串类型的事件参数添加到事件对象。 |
| int hisysevent_write(struct hiview_hisysevent *event);       | 将事件对象数据进行落盘。                                                |

**表10** hisysevent_type事件类型枚举

| 事件类型   | 描述        |
| --------- | ----------- |
| FAULT     | 故障类型事件。 |
| STATISTIC | 统计类型事件。 |
| SECURITY  | 安全类型事件。 |
| BEHAVIOR  | 行为类型事件。 |

### 开发步骤

#### C++打点开发步骤

在需要打点的地方直接调用打点接口，并传入相应事件参数。

   ```c++
   HiSysEventWrite(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
   ```

#### C打点开发步骤

1. 如果需要在打点时传入自定义事件参数，先要根据事件参数类型创建对应的事件参数对象，再将其放入到事件参数数组中。

   ```c
   // 创建一个int32_t类型的事件参数
   HiSysEventParam param1 = {
       .name = "KEY_INT32",
       .t = HISYSEVENT_INT32,
       .v = { .i32 = 1 },
       .arraySize = 0,
   };

   // 创建一个int32_t数组类型的事件参数
   int32_t int32Arr[] = { 1, 2, 3 };
   HiSysEventParam param2 = {
       .name = "KEY_INT32_ARR",
       .t = HISYSEVENT_INT32_ARRAY,
       .v = { .array = int32Arr },
       .arraySize = sizeof(int32Arr) / sizeof(int32Arr[0]),
   };

   // 将事件参数对象放入创建的事件参数数组中
   HiSysEventParam params[] = { param1, param2 };
   ```

2. 在需要打点的地方调用打点接口，并传入相应事件参数。

   ```c
   OH_HiSysEvent_Write("TEST_DOMAIN", "TEST_NAME", HISYSEVENT_BEHAVIOR, params, sizeof(params) / sizeof(params[0]));
   ```

#### kernel打点开发步骤

1. 根据事件领域、事件名称、事件类型参数，创建一个基础的事件对象。

   ```c
   struct hiview_hisysevent *event = hisysevent_create("KERNEL", "BOOT", BEHAVIOR);
   ```

2. 将自定义的事件参数，传入到事件对象里。

   ```c
   // 添加整数类型参数
   hisysevent_put_integer(event, "BOOT_TIME", 100);

   // 添加字符串类型参数
   hisysevent_put_string(event, "MSG", "This is a test message");
   ```

3. 在事件对象构建完成后，将事件进行上报。

   ```c
   hisysevent_write(event);
   ```

4. 事件上报完成后，需要手动将对象销毁。

   ```c
   hisysevent_destroy(&event);
   ```

#### 事件领域屏蔽的步骤

1. 在相应的文件中定义名称为“DOMAIN_MASKS”，内容形如“DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n”。共有三种屏蔽场景：

- 只屏蔽当前源码文件中的相应事件领域的HiSysEvent打点，在该cpp文件引入hisysevent.h头文件之前定义宏DOMAIN_MASKS即可。
   ```c++
   #define DOMAIN_MASKS "DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n"
   #include "hisysevent.h"
   ```

- 屏蔽整个模块相应事件领域的HiSysEvent打点，在模块的BUILD.gn文件中定义宏DOMAIN_MASKS即可。
   ```gn
   config("module_a"){
     cflags_cc += ["-DDOMAIN_MASKS=\"DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n\""]
   }
   ```

- 全局屏蔽相应事件领域的HiSysEvent打点，则在/build/config/compiler/BUILD.gn中定义宏DOMAIN_MASKS即可。
   ```gn
     cflags_cc += ["-DDOMAIN_MASKS=\"DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n\""]
   ```

2. 通过HiSysEventWrite宏完成HiSysEvent打点操作：
   ```c++
   constexpr char DOMAIN[] = "DOMAIN_NAME_1";
   const std::string eventName = "EVENT_NAME1";
   OHOS:HiviewDFX::HiSysEvent::EventType eventType = OHOS:HiviewDFX::HiSysEvent::EventType::FAULT;
   HiSysEventWrite(domain, eventName, eventType); //因为DOMAIN_NAME_1事件领域已经在DOMAIN_MASKS中定义，所以该HiSysEvent打点不会执行。
   ```

### 开发实例

#### C++打点开发实例

假设业务模块需要在应用启动时进行打点来记录应用启动事件，且需要记录应用的包名信息，完整使用示例如下所示：

1. 首先，需要在业务模块的在BUILD.gn里增加HiSysEvent部件依赖。

   ```c++
   external_deps = [ "hisysevent:libhisysevent" ]
   ```

2. 在业务模块的应用启动函数StartAbility()中，调用打点接口并传入对应事件参数。

   ```c++
   #include "hisysevent.h"

   int StartAbility()
   {
       ... // 其他业务逻辑
       int ret = HiSysEventWrite(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
       ... // 其他业务逻辑
   }
   ```

#### C打点开发实例

假设业务模块需要在应用启动时进行打点来记录应用启动事件，且需要记录应用的包名信息，完整使用示例如下所示：

1. 首先，需要在业务模块的在BUILD.gn里增加HiSysEvent部件依赖。

   ```c++
   external_deps = [ "hisysevent:libhisysevent" ]
   ```

2. 在业务模块的应用启动函数StartAbility()中，调用打点接口并传入对应事件参数。

   ```c
   #include "hisysevent_c.h"

   int StartAbility()
   {
       ... // 其他业务逻辑
       char packageName[] = "com.ohos.demo";
       HiSysEventParam param = {
           .name = "APP_NAME",
           .t = HISYSEVENT_STRING,
           .v = { .s = packageName },
           .arraySize = 0,
       };
       HiSysEventParam params[] = { param };
       int ret = OH_HiSysEvent_Write("AAFWK", "START_APP", HISYSEVENT_BEHAVIOR, params, sizeof(params) / sizeof(params[0]));
       ... // 其他业务逻辑
   }
   ```

#### kernel打点开发实例

假设内核业务模块需要在设备启动时进行打点来记录设备启动事件，完整使用示例如下所示：

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

#### 事件领域屏蔽的开发实例

- 假设业务模块中，需要在某个cpp文件中屏蔽名称分别为AAFWK和POWER的事件领域的打点，在该cpp文件引入hisysevent.h头文件之前，定义名称为DOMAIN_MASKS的宏：
    ```c++
    #define DOMAIN_MASKS "AAFWK|POWER"

    #include "hisysevent.h"
    ... // 其他业务逻辑
    HiSysEventWrite(OHOS:HiviewDFX::HiSysEvent::Domain::AAFWK, "JS_ERROR", OHOS:HiviewDFX::HiSysEvent::EventType::FAULT, "MODULE", "com.ohos.module"); // 该HiSysEvent打点操作不会执行
    ... // 其他业务逻辑
    HiSysEventWrite(OHOS:HiviewDFX::HiSysEvent::Domain::POWER, "POWER_RUNNINGLOCK", OHOS:HiviewDFX::HiSysEvent::EventType::FAULT, "NAME", "com.ohos.module"); // 该HiSysEvent打点操作不会执行
    ```

- 假设需要在整个业务模块中屏蔽名称分别为AAFWK和POWER的事件领域的打点，在模块的BUILG.gn文件中定义名称为DOMAIN_MASKS的宏：
    ```gn
    config("module_a") {
        ... // 其他配置项
        cflags_cc += ["-DDOMAIN_MASKS=\"AAFWK|POWER\""]
    }
    ```

- 假设需要在整个系统中屏蔽名称分别为AAFWK和POWER的事件领域的打点，则直接在/build/config/compiler/BUILD.gn文件中定义名称为DOMAIN_MASKS的宏：
    ```gn
    ... // 其他配置项
    cflags_cc += ["-DDOMAIN_MASKS=\"AAFWK|POWER\""]
    ```

# 参考

HiSysEvent模块会将打点数据写入到节点文件中，而打点数据的解析处理会在Hiview模块中统一进行，详细处理过程可参考[Hiview开发指导](subsys-dfx-hiview.md)。
