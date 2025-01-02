# HiSysEvent订阅


## 概述


### 功能简介

HiSysEvent提供了跨进程订阅机制，开发者可以通过注册订阅接口实时获取关注的事件，例如电池模块订阅功耗相关的事件，用于分析耗电情况。


### 约束与限制

在订阅HiSysEvent事件之前，需要先完成HiSysEvent打点配置，具体配置方法请参考[《HiSysEvent打点配置指导》](../subsystems/subsys-dfx-hisysevent-logging-config.md)。


## 开发指导

### 接口说明

#### C++接口说明

C++ HiSysEvent订阅开发能力如下：HiSysEventManager类，具体API详见接口目录（/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent_manager/include/）。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> ListenerRule订阅规则对象构造函数形参类型RuleType请参考[HiSysEvent查询](subsys-dfx-hisysevent-query.md)中的“表4 RuleType匹配规则类型枚举”说明。

  **表1** HiSysEvent订阅接口

| 接口名称 | 描述 |
| -------- | -------- |
| int32_t&nbsp;HiSysEventManager::AddListener(std::shared_ptr&lt;HiSysEventListener&gt;&nbsp;listener,<br/>&nbsp;std::vector&lt;ListenerRule&gt;&amp;&nbsp;rules) | 接口功能：添加对系统事件的订阅，通过设置规则订阅某些特定的事件。<br/>输入参数：<br/>-&nbsp;listener：订阅回调对象。<br/>-&nbsp;rules：事件订阅规则。<br/>返回值：<br/>-&nbsp;0：订阅添加成功。<br/>-&nbsp;负值：订阅添加失败。 |
| int32_t&nbsp;HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventListener&gt;&nbsp;listener) | 接口功能：移除对系统事件的订阅。<br/>输入参数：<br/>-&nbsp;listener：订阅回调对象。<br/>返回值：<br/>-&nbsp;0：订阅移除成功。<br/>-&nbsp;负值：订阅移除失败。  |

  **表2** ListenerRule订阅规则对象

| 接口名称 | 描述 |
| -------- | -------- |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;tag,<br/>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | 接口功能：订阅规则构造函数，创建事件标签订阅规则对象。<br/>输入参数：<br/>-&nbsp;tag：订阅规则中指定的系统事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。<br/>-&nbsp;ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。 |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;domain,<br/>&nbsp;const&nbsp;std::string&amp;&nbsp;eventName,<br/>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | 接口功能：订阅规则构造函数，创建事件领域与事件名称订阅规则对象。<br/>输入参数：<br/>-&nbsp;domain：订阅规则中指定的系统事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;eventName：订阅规则中指定的系统事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。 |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;domain,<br/>&nbsp;const&nbsp;std::string&amp;&nbsp;eventName,<br/>&nbsp;const&nbsp;std::string&amp;&nbsp;tag,<br/>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | 接口功能：订阅规则构造函数，创建事件领域、事件名称，事件标签订阅规则对象。<br/>输入参数：<br/>-&nbsp;domain：订阅规则中指定的系统事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;eventName：订阅规则中指定的系统事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;tag：订阅规则中指定的系统事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。<br/>-&nbsp;ruleType：订阅规则的规则类型，RuleType枚举类型。 |

  **表3** HiSysEventListener订阅对象

| 接口名称 | 描述 |
| -------- | -------- |
| void&nbsp;HiSysEventListener::OnEvent(std::shared_ptr&lt;HiSysEventRecord&gt;&nbsp;sysEvent) | 接口功能：订阅事件的回调接口。<br/>输入参数：<br/>-&nbsp;sysEvent：订阅到的实时系统事件。<br/>返回值：<br/>无。 |
| void&nbsp;HiSysEventListener::OnServiceDied() | 接口功能：服务异常回调。<br/>输入参数：<br/>无。<br/>返回值：<br/>无。 |

  **表4** HiSysEventRecord系统事件对象
| 接口名称 | 描述 |
| -------- | -------- |
|std::string&nbsp;HiSysEventRecord::AsJson()|接口功能：获取该系统事件的内容。<br/>输入参数：<br/>无。<br/>返回值：<br/>该系统事件的内容。|
|std::string&nbsp;HiSysEventRecord::GetDomain()|接口功能：获取该系统事件的域名。<br/>输入参数：<br/>无。<br/>返回值：<br/>该系统事件的域名。|
|std::string&nbsp;HiSysEventRecord::GetEventName()|接口功能：获取该系统事件的名称。<br/>输入参数：<br/>无。<br/>返回值：<br/>该系统事件的名称。|
|HiSysEvent::EventType&nbsp;HiSysEventRecord::GetEventType()|接口功能：获取该系统事件的类型。<br/>输入参数：<br/>无。<br/>返回值：<br/>该系统事件的类型。|
|std::string&nbsp;HiSysEventRecord::GetLevel()|接口功能：获取该系统事件的级别。<br/>输入参数：<br/>无。<br/>返回值：<br/>该系统事件的级别。|
|std::string&nbsp;HiSysEventRecord::GetTag()|接口功能：获取该系统事件的标签。<br/>输入参数：<br/>无。<br/>返回值：<br/>该系统事件的标签。|
|std::string&nbsp;HiSysEventRecord::GetTimeZone()|接口功能：获取该系统事件的时区。<br/>输入参数：<br/>无。<br/>返回值：<br/>时区内容，格式为“+0800”。|
|int&nbsp;HiSysEventRecord::GetTraceFlag()|接口功能：获取该系统事件的分布式跟踪标志位。<br/>输入参数：<br/>无。<br/>返回值：<br/>分布式跟踪标志位。|
|int64_t&nbsp;HiSysEventRecord::GetPid()|接口功能：获取落盘该系统事件的进程ID。<br/>输入参数：<br/>无。<br/>返回值：<br/>进程ID。|
|int64_t&nbsp;HiSysEventRecord::GetTid()|接口功能：获取落盘该系统事件的线程ID。<br/>输入参数：<br/>无。<br/>返回值：<br/>线程ID。|
|int64_t&nbsp;HiSysEventRecord::GetUid()|接口功能：获取落盘该系统事件的用户ID。<br/>输入参数：<br/>无。<br/>返回值：<br/>用户ID。|
|uint64_t&nbsp;HiSysEventRecord::GetPspanId()|接口功能：获取该系统事件的分布式跟踪父分支ID。<br/>输入参数：<br/>无。<br/>返回值：<br/>分布式跟踪父分支ID。|
|uint64_t&nbsp;HiSysEventRecord::GetSpandId()|接口功能：获取该系统事件的分布式跟踪分支ID。<br/>输入参数：<br/>无。<br/>返回值：<br/>分布式跟踪分支ID。|
|uint64_t&nbsp;HiSysEventRecord::GetTime()|接口功能：获取该系统事件的时间戳。<br/>输入参数：<br/>无。<br/>返回值：<br/>时间戳。|
|uint64_t&nbsp;HiSysEventRecord::GetTraceId()|接口功能：获取该系统事件的分布式跟踪链ID。<br/>输入参数：<br/>无。<br/>返回值：<br/>分布式跟踪链ID。|
|void&nbsp;HiSysEventRecord::GetParamNames(std::vector&lt;std::string&gt;&amp;&nbsp;params)|接口功能：获取该系统事件的所有键名。<br/>输入参数：<br/>-&nbsp;params：键名数组引用。<br/>返回值：<br/>无。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;int64_t&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为int64_t类型的值。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：int64_t类型引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成int64_t类型的值。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;uint64_t&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为uint64_t类型的值。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：uint64_t类型引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成uint64_t类型的值。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;double&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为double类型的值。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：double类型引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成double类型的值。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::string&amp; value)|接口功能：将该系统事件键名为param的值解析为string类型的值。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：std::string类型引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成std::string类型的值。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;int64_t&gt;&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为int64_t类型的数组。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：int64_t类型数组引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成int64_t类型的数组。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;uint64_t&gt;&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为uint64_t类型的数组。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：uint64_t类型数组引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成uint64_t类型的数组。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;double&gt;&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为double类型的数组。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：double类型数组引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成double类型的数组。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;std::string&gt;&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为string类型的数组。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：std::string类型数组引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成std::string类型的数组。|

#### C接口说明

C HiSysEvent订阅开发能力如下：具体API详见接口目录（/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent_manager/include/）。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> HiSysEventWatcher订阅回调结构体OnEvent回调方法形参类型HiSysEventRecord请参考[HiSysEvent查询](subsys-dfx-hisysevent-query.md)中的“表11 HiSysEventRecord事件结构体”及“表12 HiSysEventRecord解析接口”说明。

  **表5** HiSysEvent订阅接口

| 接口名称                                                     | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int OH_HiSysEvent_Add_Watcher(HiSysEventWatcher* watcher,<br/>HiSysEventWatchRule rules[],<br/>size_t ruleSize); | 接口功能：添加对系统事件的订阅，通过设置规则订阅某些特定的事件。<br/>输入参数：<br/>-&nbsp;watcher：订阅回调对象。<br/>-&nbsp;rules：事件订阅规则数组。<br/>-&nbsp;ruleSize：事件订阅规则数组长度。<br/>返回值：<br/>-&nbsp;0：订阅添加成功。<br/>-&nbsp;负值：订阅添加失败。 |
| int OH_HiSysEvent_Remove_Watcher(HiSysEventWatcher* watcher); | 接口功能：移除对系统事件的订阅。<br/>输入参数：<br/>-&nbsp;watcher：订阅回调对象。<br/>返回值：<br/>-&nbsp;0：订阅移除成功。<br/>-&nbsp;负值：订阅移除失败。  |


  **表6** HiSysEventWatcher订阅回调结构体
| 属性名称      | 属性类型                                   | 描述                                                         |
| ------------- | -------------------------------------------------- | ------------------------------------------------------------ |
| OnEvent       | void (*)(HiSysEventRecord record);        | 接口功能：订阅事件的回调接口。<br/>输入参数：<br/>-&nbsp;record：订阅到的实时系统事件。<br/>返回值：<br/>无。 |
| OnServiceDied | void (*)();                                | 接口功能：服务异常回调。<br/>输入参数：<br/>无。<br/>返回值：<br/>无。  |

  **表7** HiSysEventWatchRule订阅规则结构体
| 属性名称      | 属性类型  | 描述                               |
| ------------- | --------- | ---------------------------------- |
| domain        | char[]    | 用来指定订阅的系统事件领域。           |
| name          | char[]    | 用来指定订阅的系统事件名称。           |
| tag           | char[]    | 用来指定订阅的系统事件标签。           |
| ruleType      | int       | 用于指定订阅事件的匹配规则，取值请参考[HiSysEvent查询](subsys-dfx-hisysevent-query.md)中的“表4 RuleType匹配规则类型枚举”。       |
| eventType     | int       | 用于指定订阅事件的事件类型，取值请参考[HiSysEvent查询](subsys-dfx-hisysevent-query.md)中的“表3 EventType事件类型枚举”，当取值0，表示订阅所有的事件类型。       |

### 开发步骤

#### C++ HiSysEvent订阅开发步骤

1. 引入对应的头文件。

    ```c++
    #include "hisysevent_manager.h"
    ```

2. 业务领域实现对应的订阅回调接口。

    ```c++
    class TestListener : public OHOS::HiviewDFX::HiSysEventListener {
    public:
        void OnEvent(std::shared_ptr<HiSysEventRecord> record)
        {
            if (record == nullptr) {
                return;
            }
            std::cout << record->AsJson() << std::endl;
        }

        void OnServiceDied()
        {
            std::cout << std::string("service disconnect, exit") << std::endl;
            exit(0);
        }
    };
    ```

3. 在订阅事件的地方调用订阅接口，并传入相应的订阅回调参数、订阅规则列表，在业务结束，注销此次订阅。

    ```c++
    auto testListener = std::make_shared<TestListener>();
    // 事件标签规则订阅，规则类型为默认的全词匹配类型
    ListenerRule tagRule("dfx");
    // 事件标签规则订阅，规则类型为正则匹配类型
    ListenerRule regRule("dfx.*", RuleType::REGULAR);
    // 事件领域及事件名称规则订阅，规则类型为前缀匹配类型
    ListenerRule domainNameRule("HIVIEWDFX", "APP_USAGE", RuleType::PREFIX);
    std::vector<ListenerRule> sysRules;
    sysRules.push_back(tagRule);
    sysRules.push_back(regRule);
    sysRules.push_back(domainNameRule);
    // 开始系统事件订阅
    auto ret = HiSysEventManager::AddListener(testListener, sysRules);
    // 订阅结束，移除订阅回调参数。
    if (ret == 0) {
       HiSysEventManager::RemoveListener(testListener);
    }
    ```

#### C HiSysEvent订阅开发步骤

1. 引入对应的头文件。

    ```c++
    #include "hisysevent_manager_c.h"
    ```

2. 业务领域实现对应的订阅回调接口。

    ```c++
    void OnEventTest(HiSysEventRecord record)
    {
        printf("OnEventTest: event=%s", record.jsonStr);
    }

    void OnServiceDiedTest()
    {
        printf("OnServiceDied");
    }
    ```

3. 在订阅事件的地方调用订阅接口，并传入相应的订阅回调参数、订阅规则列表，在业务结束，注销此次订阅。

    ```c++
    HiSysEventWatcher watcher;
    watcher.OnEvent = OnEventTest;
    watcher.OnServiceDied = OnServiceDiedTest;
    // 事件标签规则订阅，规则类型为默认的全词匹配类型
    constexpr char DFX_TAG[] = "dfx";
    HiSysEventWatchRule tagRule;
    (void)strcpy_s(tagRule.tag, strlen(DFX_TAG) + 1, DFX_TAG);
    tagRule.ruleType = 1;
    tagRule.eventType = 0;
    // 事件标签规则订阅，规则类型为正则匹配类型
    constexpr char DFX_PATTERN_TAG[] = "dfx.*";
    HiSysEventWatchRule regRule;
    (void)strcpy_s(regRule.tag, strlen(DFX_PATTERN_TAG) + 1, DFX_PATTERN_TAG);
    regRule.ruleType = 3;
    regRule.eventType = 0;
    // 事件领域及事件名称规则订阅，规则类型为前缀匹配类型
    constexpr char DOMAIN[] = "HIVIEWDFX";
    constexpr char NAME[] = "APP_USAGE";
    HiSysEventWatchRule domainNameRule;
    (void)strcpy_s(domainNameRule.domain, strlen(DOMAIN) + 1, DOMAIN);
    (void)strcpy_s(domainNameRule.name, strlen(NAME) + 1, NAME);
    domainNameRule.ruleType = 2;
    domainNameRule.eventType = 0;
    // 开始系统事件订阅
    HiSysEventWatchRule rules[] = {tagRule, regRule, domainNameRule};
    int ret = OH_HiSysEvent_Add_Watcher(&watcher, rules, sizeof(rules) / sizeof(HiSysEventWatchRule));
    // 订阅结束，移除订阅回调参数。
    if (ret == 0) {
        ret = OH_HiSysEvent_Remove_Watcher(&watcher);
    }
    ```

### 开发实例

#### C++ HiSysEvent订阅开发实例

假设业务模块需要订阅事件领域为HIVIEWDFX、事件名称为PLUGIN_LOAD的所有事件，其完整使用示例如下所示：

1. 在业务模块的在BUILD.gn里增加hisysevent部件的libhisysevent及libhisyseventmanager依赖。

    ```c++
    external_deps = [
      "hisysevent:libhisysevent",
      "hisysevent:libhisyseventmanager",
    ]
    ```

2. 在业务模块的TestEventListening()函数中，调用订阅接口去订阅事件，业务结束时移除事件订阅。

    ```c++
    #include <iostream>

    #include "hisysevent_manager.h"

    using namespace OHOS::HiviewDFX;

    class TestListener : public HiSysEventQueryCallback {
    public:
        void OnEvent(std::shared_ptr<HiSysEventRecord> record)
        {
            if (record == nullptr) {
                return;
            }
            std::cout << record->AsJson() << std::endl;
        }

        void OnServiceDied()
        {
            std::cout << std::string("service disconnect, exit") << std::endl;
            exit(0);
        }
    };

    void TestEventListening()
    {
        auto testListener = std::make_shared<TestListener>();
        ListenerRule domainNameRule("HIVIEWDFX", "PLUGIN_LOAD", RuleType::WHOLE_WORD);
        std::vector<ListenerRule> sysRules;
        sysRules.push_back(domainNameRule);
        auto ret = HiSysEventManager::AddListener(testListener, sysRules);
        if (ret == 0) {
            HiSysEventManager::RemoveListener(testListener);
        }
    }
    ```

#### C HiSysEvent订阅开发实例

假设业务模块需要订阅事件领域为HIVIEWDFX、事件名称为PLUGIN_LOAD的所有事件，其完整使用示例如下所示：

1. 在业务模块的在BUILD.gn里增加hisysevent部件的libhisysevent及libhisyseventmanager依赖。

    ```c++
    external_deps = [ "hisysevent:libhisyseventmanager" ]

    // for strcpy_s
    deps = [ "//third_party/bounds_checking_function:libsec_shared" ]
    ```

2. 在业务模块的TestEventListening()函数中，调用订阅接口去订阅事件，业务结束时移除事件订阅。

    ```c++
    #include <securec.h>

    #include "hisysevent_manager_c.h"

    void OnEventTest(HiSysEventRecord record)
    {
        printf("OnEventTest: event=%s", record.jsonStr);
    }

    void OnServiceDiedTest()
    {
        printf("OnServiceDied");
    }

    void TestEventListening()
    {
        HiSysEventWatcher watcher;
        watcher.OnEvent = OnEventTest;
        watcher.OnServiceDied = OnServiceDiedTest;
        constexpr char DOMAIN[] = "HIVIEWDFX";
        constexpr char NAME[] = "PLUGIN_LOAD";
        HiSysEventWatchRule domainNameRule;
        (void)strcpy_s(domainNameRule.domain, strlen(DOMAIN) + 1, DOMAIN);
        (void)strcpy_s(domainNameRule.name, strlen(NAME) + 1, NAME);
        domainNameRule.ruleType = 1;
        domainNameRule.eventType = 0;
        HiSysEventWatchRule rules[] = {domainNameRule};
        int ret = OH_HiSysEvent_Add_Watcher(&watcher, rules, sizeof(rules) / sizeof(HiSysEventWatchRule));
        if (ret == 0) {
           ret = OH_HiSysEvent_Remove_Watcher(&watcher);
       }
    }
    ```
