# HiSysEvent查询


## 概述

HiSysEvent提供了查询接口，支持开发者设置条件查询HiSysEvent事件，例如功耗部件可以通过该接口获取所需的系统事件进行业务分析。


## 开发指导

### 接口说明

#### C++接口说明

C++ HiSysEvent查询开发能力如下：HiSysEventManager类，具体API详见接口目录（/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent_manager/include/）。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> HiSysEventQueryCallback查询回调对象OnQuery方法中的形参类型HiSysEventRecord请参考[HiSysEvent订阅](subsys-dfx-hisysevent-listening.md)中的“表4 HiSysEventRecord系统事件对象”说明。

  **表1** HiSysEvent查询接口

| 接口名称 | 描述 |
| -------- | -------- |
| int32_t Query(struct&nbsp;QueryArg&amp;&nbsp;arg,<br/>std::vector&lt;QueryRule&gt;&amp;&nbsp;rules,<br/>std::shared_ptr&lt;HiSysEventQueryCallback&gt;&nbsp;callback) | 接口功能：支持根据时间段、事件领域、事件名称等条件，查询满足条件的HiSysEvent事件。<br/>输入参数：<br/>-&nbsp;arg：查询参数。<br/>-&nbsp;rules：事件过滤规则。<br/>-&nbsp;callback：查询接口回调对象。<br/>返回值：<br/>-&nbsp;0：查询成功。<br/>-&nbsp;负值：查询失败。 |

  **表2** QueryArg查询参数对象

| 属性名称 | 属性类型 | 描述 |
| -------- | -------- | -------- |
| beginTime | long long | 用于指定查询事件的开始时间，格式为Unix毫秒级时间戳。 |
| endTime | long long | 用于指定查询事件的结束时间，格式为Unix毫秒级时间戳。 |
| maxEvents | int | 用于指定查询返回事件的最多条数。 |

  **表3** EventType事件类型枚举

| 事件类型 | 值 | 描述 |
| ------------ | ---- | ------------------ |
| FAULT        | 1    | 故障类型。     |
| STATISTIC    | 2    | 统计类型。     |
| SECURITY     | 3    | 安全类型。     |
| BEHAVIOR     | 4    | 用户行为类型。 |

  **表4** RuleType匹配规则类型枚举

| 查询规则类型 | 值 | 描述 |
| ------------ | ---- | ------------------ |
| WHOLE_WORD   | 1    | 全词匹配类型。     |
| PREFIX       | 2    | 前缀匹配类型。     |
| REGULAR      | 3    | 正则匹配类型。     |

  **表5** QueryRule查询规则对象

| 接口名称 | 描述 |
| -------- | -------- |
| QueryRule(const&nbsp;std::string&amp;&nbsp;domain,<br/>const&nbsp;std::vector&lt;std::string&gt;&amp;&nbsp;eventList,<br/>RuleType&nbsp;ruleType,<br/>uint32_t&nbsp;eventType,<br/>const&nbsp;std::string&&nbsp;cond) | 接口功能：查询规则构造函数，创建查询规则对象。<br/>输入参数：<br/>-&nbsp;domain：string类型，用来标识查询规则对象的事件所属领域，如果传入的是空字符串，则默认事件领域字段匹配成功。<br/>-&nbsp;eventList：std::vector&lt;std::string&gt;类型，事件名称的列表，如果传入的是空字符串，则默认事件名称字段匹配成功。<br/>-&nbsp;ruleType：RuleType类型，请参考表4。<br/>-&nbsp;eventType：uint32_t类型，查询的系统事件类型，系统事件类型请参考表3，当eventType取值为0时，表示查询所有事件类型。<br/>-&nbsp;cond：string类型，设置的系统事件查询条件。 |

对于condition参数需要按照指定的JSON字符串格式传入，使用实例如下：

    ```json
    {
        "version":"V1",
        "condition":{
            "and":[
                {"param":"type_","op":">","value":0},
                {"param":"uid_","op":"=","value":1201}
            ]
        }
    }
    ```
- version字段是必选字段，表示传入条件的支持版本，当前只支持V1版本。
- condition字段是必选字段，表示传入条件的具体内容。
  - and字段是可选字段，表示条件之间是与的关系。
    - param字段是必选字段，表示条件匹配的参数名称，必须为字符串类型。
    - op字段是必选字段，表示条件匹配的参数比较符，必须为字符串类型，支持的比较符包括=、>、<、>=、<=。
    - value字段是必选字段，表示条件匹配的参数值，必须为字符串类型或整型。





**表6** HiSysEventQueryCallback查询回调对象

| 接口名称 | 描述 |
| -------- | -------- |
| void&nbsp;HiSysEventQueryCallback::OnQuery(std::shared_ptr&lt;std::vector&lt;HiSysEventRecord&gt;&gt;&nbsp;sysEvents) | 接口功能：事件查询的回调。<br/>输入参数：<br/>-&nbsp;sysEvents：返回的事件集合。 |
| void&nbsp;HiSysEventQueryCallback::OnComplete(int32_t&nbsp;reason,&nbsp;int32_t&nbsp;total) | 接口功能：事件查询完成的回调。<br/>输入参数：<br/>-&nbsp;reason：查询结束的返回原因，0表示查询正常结束，其他值表示查询异常结束。<br/>-&nbsp;total：本次查询返回的事件的总数量。 |

#### C接口说明

C HiSysEvent查询开发能力如下：具体API详见接口目录（/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent_manager/include/）。

  **表7** HiSysEvent查询接口

| 接口名称                                                     | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int OH_HiSysEvent_Query(const HiSysEventQueryArg& arg, HiSysEventQueryRule rules[], size_t ruleSize, HiSysEventQueryCallback& callback); | 接口功能：支持根据时间段、事件领域、事件名称、事件参数等条件，查询满足条件的HiSysEvent事件。<br/>输入参数：<br/>-&nbsp;arg：查询参数。<br/>-&nbsp;rules：事件过滤规则。<br/>- ruleSize：事件过滤规则数量。<br/>-&nbsp;callback：查询接口回调。<br/>返回值：<br/>-&nbsp;0：查询成功。<br/>-&nbsp;负值：查询失败。 |

  **表8** HiSysEventQueryArg查询参数结构体

| 属性名称  | 属性类型 | 描述                                                 |
| --------- | -------- | ---------------------------------------------------- |
| beginTime | int64_t  | 用于指定查询事件的开始时间，格式为Unix毫秒级时间戳。 |
| endTime   | int64_t  | 用于指定查询事件的结束时间，格式为Unix毫秒级时间戳。 |
| maxEvents | int32_t  | 用于指定查询返回事件的最多条数。                     |

  **表9** HiSysEventQueryRule查询规则结构体

| 属性名称      | 属性类型  | 描述                               |
| ------------- | --------- | ---------------------------------- |
| domain        | char[]    | 用来指定查询的事件领域。           |
| eventList     | char\[][] | 用于指定查询的事件名称列表。       |
| eventListSize | size_t    | 用于指定查询的事件名称列表大小。   |
| condition     | char*     | 用于指定查询的自定义事件参数条件。 |

  **表10** HiSysEventQueryCallback查询回调结构体

| 属性名称   | 属性类型                                           | 描述                                                         |
| ---------- | -------------------------------------------------- | ------------------------------------------------------------ |
| OnQuery    | void (*)(HiSysEventRecord records[], size_t size); | 接口功能：事件查询的回调。<br/>输入参数：<br/>-&nbsp;records：返回的事件集合。<br/>- size：返回的事件集合大小。 |
| OnComplete | void (*)(int32_t reason, int32_t total);           | 接口功能：事件查询完成的回调。<br/>输入参数：<br/>-&nbsp;reason：查询结束的返回原因，0表示查询正常结束，其他值表示查询异常结束。<br/>-&nbsp;total：本次查询返回的事件的总数量。 |

  **表11** HiSysEventRecord事件结构体

| 属性名称  | 属性类型            | 描述                       |
| --------- | ------------------- | -------------------------- |
| domain    | char[]              | 事件的领域名称。           |
| eventName | char\[]             | 事件的名称。               |
| type      | HiSysEventEventType | 事件的类型。               |
| time      | uint64_t            | 事件的时间戳。             |
| tz        | char\[]             | 事件的时区。               |
| pid       | int64_t             | 事件的进程ID。             |
| tid       | int64_t             | 事件的线程ID。             |
| uid       | int64_t             | 事件的用户ID。             |
| traceId   | uint64_t            | 事件的分布式跟踪链ID。     |
| spandId   | uint64_t            | 事件的分布式跟踪分支ID。   |
| pspanId   | uint64_t            | 事件的分布式跟踪父分支ID。 |
| traceFlag | int                 | 事件的分布式跟踪标志位。   |
| level     | char*               | 事件的级别。               |
| tag       | char*               | 事件的标签。               |
| jsonStr   | char*               | 事件的内容。               |

  **表12** HiSysEventRecord解析接口

| 接口名称                                                     |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| void OH_HiSysEvent_GetParamNames(const HiSysEventRecord& record, char*** params, size_t& len); | 接口功能：获取该事件的所有的参数名。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;params：参数名数组。<br/>- len：数组大小。 |
| int OH_HiSysEvent_GetParamInt64Value(const HiSysEventRecord& record, const char* name, int64_t& value); | 接口功能：将该事件中参数名为name的参数值，解析为int64_t类型并赋值到value。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：int64_t类型的参数值。 |
| int OH_HiSysEvent_GetParamUint64Value(const HiSysEventRecord& record, const char* name, uint64_t& value); | 接口功能：将该事件中参数名为name的参数值，解析为uint64_t类型并赋值到value。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：uint64_t类型的参数值。 |
| int OH_HiSysEvent_GetParamDoubleValue(const HiSysEventRecord& record, const char* name, double& value); | 接口功能：将该事件中参数名为name的参数值，解析为double类型并赋值到value。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：double类型的参数值。 |
| int OH_HiSysEvent_GetParamStringValue(const HiSysEventRecord& record, const char* name, char** value); | 接口功能：将该事件中参数名为name的参数值，解析为char数组类型并赋值到value，value在使用完成后需要手动释放内存。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：char\*类型引用。 |
| int OH_HiSysEvent_GetParamInt64Values(const HiSysEventRecord& record, const char* name, int64_t** value, size_t& len); | 接口功能：将该事件中参数名为name的参数值，解析为int64_t数组类型并赋值到value，value在使用完成后需要手动释放内存。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：int64_t\*类型引用。<br/>-&nbsp;len：数组大小。 |
| int OH_HiSysEvent_GetParamUint64Values(const HiSysEventRecord& record, const char* name, uint64_t** value, size_t& len); | 接口功能：将该事件中参数名为name的参数值，解析为uint64_t数组类型并赋值到value，value在使用完成后需要手动释放内存。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：uint64_t\*类型引用。<br/>-&nbsp;len：数组大小。 |
| int OH_HiSysEvent_GetParamDoubleValues(const HiSysEventRecord& record, const char* name, double** value, size_t& len); | 接口功能：将该事件中参数名为name的参数值，解析为double数组类型并赋值到value，value在使用完成后需要手动释放内存。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：double\*类型引用。<br/>-&nbsp;len：数组大小。 |
| int OH_HiSysEvent_GetParamStringValues(const HiSysEventRecord& record, const char* name, char*** value, size_t& len); | 接口功能：将该事件中参数名为name的参数值，解析为char*数组类型并赋值到value，value在使用完成后需要手动释放内存。<br/>输入参数：<br/>- record：事件结构体。<br/>-&nbsp;name：参数名。<br/>-&nbsp;value：char\*\*类型引用。<br/>-&nbsp;len：数组大小。 |

HiSysEventRecord解析接口的返回值说明如下：

- 0，表示解析成功；
- -1，表示该事件初始化失败；
- -2，表示参数名不存在；
- -3，表示要解析的参数值类型与传入的参数值类型不匹配。

### 开发步骤

#### C++ HiSysEvent查询开发步骤

1. 引入对应的头文件。

    ```c++
    #include "hisysevent_manager.h"
    ```     

2. 业务领域实现对应的查询回调接口。

    ```c++
    class TestQueryCallback : public HiSysEventQueryCallback {
    public:
        void OnQuery(std::shared_ptr<std::vector<HiSysEventRecord>> sysEvents) override
        {
            if (sysEvents == nullptr) {
                return;
            }
            for_each((*sysEvents).cbegin(), (*sysEvents).cend(), [](const HiSysEventRecord& event) {
                std::cout << event.AsJson() << std::endl;
            });
        }

        void OnComplete(int32_t reason, int32_t total) override
        {
            std::cout << "Query completed" << std::endl;
            return;
        }
    };
    ```

3. 在查询的地方调用查询接口，并传入相应的查询参数、查询规则、查询回调参数。

    ```c++
    // 创建查询参数对象
    long long startTime = 0;
    long long endTime = 1668245644000; //2022-11-12 09:34:04
    int queryCount = 10;
    QueryArg arg(startTime, endTime, queryCount);

    // 创建查询规则对象
    QueryRule rule("HIVIEWDFX", { "PLUGIN_LOAD" });
    std::vector<QueryRule> queryRules = { rule };

    // 创建查询回调对象
    auto queryCallback = std::make_shared<TestQueryCallback>();

    // 调用查询接口
    HiSysEventManager::Query(arg, queryRules, queryCallback);
    ```

#### C HiSysEvent查询开发步骤

1. 引入对应的头文件。

    ```c++
    #include "hisysevent_manager_c.h"
    ```

2. 业务领域实现对应的查询回调接口。

    ```c++
    void OnQueryTest(HiSysEventRecord records[], size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            printf("OnQuery: event=%s", records[i].jsonStr);
        }
    }

    void OnCompleteTest(int32_t reason, int32_t total)
    {
        printf("OnCompleted, res=%d, total=%d\n", reason, total);
    }
    ```

3. 在查询的地方调用查询接口，并传入相应的查询参数、查询规则、查询回调参数。

    ```c++
    // 创建查询参数对象
    HiSysEventQueryArg arg;
    arg.beginTime = 0;
    arg.endTime = 1668245644000; //2022-11-12 09:34:04
    arg.maxEvents = 10;

    // 创建查询规则对象
    constexpr char TEST_DOMAIN[] = "HIVIEWDFX";
    constexpr char TEST_NAME[] = "PLUGIN_LOAD";
    HiSysEventQueryRule rule;
    (void)strcpy_s(rule.domain, strlen(TEST_DOMAIN) + 1, TEST_DOMAIN);
    (void)strcpy_s(rule.eventList[0], strlen(TEST_NAME) + 1, TEST_NAME);
    rule.eventListSize = 1;
    rule.condition = nullptr;
    HiSysEventQueryRule rules[] = { rule };

    // 创建查询回调对象
    HiSysEventQueryCallback callback;
    callback.OnQuery = OnQueryTest;
    callback.OnComplete = OnCompleteTest;

    // 调用查询接口
    OH_HiSysEvent_Query(arg, rules, sizeof(rules) / sizeof(HiSysEventQueryRule), callback);
    ```

### 开发实例

#### C++ HiSysEvent查询开发实例

假设业务模块需要查询截止至当前时间、事件领域为HIVIEWDFX、事件名称为PLUGIN_LOAD的所有事件，其完整使用示例如下所示：

1. 在业务模块的在BUILD.gn里增加hisysevent部件的libhisysevent及libhisyseventmanager依赖。

    ```c++
    external_deps = [
      "hisysevent:libhisysevent",
      "hisysevent:libhisyseventmanager",
    ]
    ```

2. 在业务模块的TestQuery()函数中，调用查询接口去查询事件。

    ```c++
    #include "hisysevent_manager.h"
    #include <iostream>
    #include <unistd.h>

    using namespace OHOS::HiviewDFX;

    class TestQueryCallback : public HiSysEventQueryCallback {
    public:
        void OnQuery(std::shared_ptr<std::vector<HiSysEventRecord>> sysEvents) override
        {
            if (sysEvents == nullptr) {
                return;
            }
            for_each((*sysEvents).cbegin(), (*sysEvents).cend(), [](const HiSysEventRecord& event) {
                std::cout << event.AsJson() << std::endl;
            });
        }

        void OnComplete(int32_t reason, int32_t total) override
        {
            std::cout << "Query completed" << std::endl;
            return;
        }
    };

    int64_t GetMilliseconds()
    {
        auto now = std::chrono::system_clock::now();
        auto millisecs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
        return millisecs.count();
    }

    void TestQuery()
    {
        long long startTime = 0;
        long long endTime = GetMilliseconds();
        int maxEvents = 100;
        QueryArg arg(startTime, endTime, maxEvents);
        QueryRule rule("HIVIEWDFX", { "PLUGIN_LOAD" });
        std::vector<QueryRule> queryRules = { rule };
        auto queryCallback = std::make_shared<TestQueryCallback>();
        int ret = HiSysEventManager::Query(arg, queryRules, queryCallback);
    }
    ```

#### C HiSysEvent查询开发实例

假设业务模块需要查询截止至当前时间、事件领域为HIVIEWDFX、事件名称为PLUGIN_LOAD的所有事件，其完整使用示例如下所示：

1. 在业务模块的在BUILD.gn里增加hisysevent部件的libhisyseventmanager依赖。

```c++
    external_deps = [ "hisysevent:libhisyseventmanager" ]

    // for strcpy_s
    deps = [ "//third_party/bounds_checking_function:libsec_shared" ]
```

2. 在业务模块的TestQuery()函数中，调用查询接口去查询事件。

    ```c++
    #include "hisysevent_manager_c.h"
    #include <securec.h>
    #include <time.h>
     
    void OnQueryTest(HiSysEventRecord records[], size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            printf("OnQuery: event=%s", records[i].jsonStr);
        }
    }

    void OnCompleteTest(int32_t reason, int32_t total)
    {
        printf("OnCompleted, res=%d, total=%d\n", reason, total);
    }

    int64_t GetMilliseconds()
    {
        return time(NULL);
    }

    void TestQuery()
    {
        HiSysEventQueryArg arg;
        arg.beginTime = 0;
        arg.endTime = GetMilliseconds();
        arg.maxEvents = 100;
        constexpr char TEST_DOMAIN[] = "HIVIEWDFX";
        constexpr char TEST_NAME[] = "PLUGIN_LOAD";
        HiSysEventQueryRule rule;
        (void)strcpy_s(rule.domain, strlen(TEST_DOMAIN) + 1, TEST_DOMAIN);
        (void)strcpy_s(rule.eventList[0], strlen(TEST_NAME) + 1, TEST_NAME);
        rule.eventListSize = 1;
        rule.condition = nullptr;
        HiSysEventQueryRule rules[] = { rule };
        HiSysEventQueryCallback callback;
        callback.OnQuery = OnQueryTest;
        callback.OnComplete = OnCompleteTest;
        int ret = OH_HiSysEvent_Query(arg, rules, sizeof(rules) / sizeof(HiSysEventQueryRule), callback);
    }
    ```
