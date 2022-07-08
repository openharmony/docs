# HiSysEvent订阅指导<a name="ZH-CN_TOPIC_0000001185655868"></a>


## 概述<a name="section315316685112"></a>

### 功能简介<a name="section123181433335224"></a>

HiSysEvent提供了跨进程订阅机制，开发者可以通过注册订阅接口实时获取关注的事件，例如电池模块侦听功耗相关的事件，用于分析耗电情况。

### 约束与限制<a name="section123181433375224"></a>

**HiSysEvent事件订阅条件约束：**

- 在订阅HiSysEvent事件之前，需要先完成HiSysEvent打点配置，具体配置方法请参考[《HiSysEvent打点配置指导》](subsys-dfx-hisysevent-logging-config.md)。

## 开发指导<a name="section315316685113"></a>

### 接口说明<a name="section0342191810519"></a>

**表 1**  HiSysEvent订阅接口

| 接口名称 | 描述  |
| -------- | --------- |
|bool HiSysEventManager::AddEventListener(std::shared_ptr&lt;HiSysEventSubscribeCallBack&gt; listener, std::vector&lt;ListenerRule&gt;&amp; rules)|接口功能：注册订阅HiSysEvent系统事件侦听对象，可设置规则订阅某些事件。<br><br>输入参数：<ul><li>listener：订阅回调对象。</li><li>rules：事件订阅规则。</li></ul>返回值：<ul><li>0：订阅成功，重复订阅。</li><li>1：订阅成功，初次订阅。</li><li>其他值：订阅失败。</li></ul>|
|bool HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventSubscribeCallBack&gt; listener)|接口功能：移除订阅hisysevent系统事件侦听对象。<br><br>输入参数：<ul><li>listener：订阅回调对象。</ul>返回值：<br>&emsp;&emsp;无。|

**表 2**  ListenerRule订阅规则对象

| 接口名称 | 描述  |
| -------- | --------- |
|ListenerRule(const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD)|接口功能：订阅规则构造函数，创建事件标签订阅规则对象。<br><br>输入参数：<ul><li>tag：订阅规则的HisysEvent事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。</li><li>ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。</li></ul>|
|ListenerRule(const std::string&amp; domain, const std::string&amp; eventName, RuleType ruleType = RuleType::WHOLE_WORD)|接口功能：订阅规则构造函数，创建事件领域与事件名称订阅规则对象。<br><br>输入参数：<ul><li>domain：订阅规则的HisysEvent事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。</li><li>eventName：订阅规则的HisysEvent事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。</li><li>ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。</li></ul>|
|ListenerRule(const std::string&amp; domain, const std::string& eventName, const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD)|接口功能：订阅规则构造函数，创建事件领域、事件名称，事件标签订阅规则对象。<br><br>输入参数：<ul><li>tag：订阅规则的HisysEvent事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。</li><li>domain：订阅规则的HisysEvent事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。</li><li>eventName：订阅规则的HisysEvent事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。</li><li>ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。</li></ul>|

**表 3**  RuleType类型

| 枚举值       | 描述          |
| ------------ | ------------- |
| WHOLE_WORD   | 全词匹配类型  |
| PREFIX       | 前缀匹配类型  |
| REGULAR      | 正则匹配类型  |

**表 4**  HiSysEventSubscribeCallBack订阅对象

| 接口名称 | 描述  |
| -------- | --------- |
|void HiSysEventSubscribeCallBack::OnHandle(const std::string&amp; domain, const std::string&amp; eventName, const int eventType, const std::string&amp; eventDetail)|接口功能：订阅事件的回调接口。<br><br>输入参数：<ul><li>domain：事件所属领域。</li><li>eventName：事件的名称。</li><li>eventType：事件类型。</li><li>eventDetail：包含事件相关信息的字符串，以json的形式体现。</li></ul>返回值：<br>&emsp;&emsp;无。|

### 开发实例<a name="section123181432175110"></a>

订阅HiSysEvent事件C++接口实例

1.  源代码开发

    自定义订阅回调实现类头文件DemoListener.h：

    ```
    #ifndef DEMO_LISTENER_H
    #define DEMO_LISTENER_H

    #include "hisysevent_subscribe_callback.h"

    #include <string>

    class DemoListener : public OHOS::HiviewDFX::HiSysEventSubscribeCallBack {
    public:
        explicit DemoListener() : HiSysEventSubscribeCallBack() {}
        void OnHandle(const std::string& domain, const std::string& eventName, const int eventType,
            const std::string& eventDetail);
        virtual ~DemoListener() {}
        void OnServiceDied();
    };

    #endif // DEMO_LISTENER_H
    ```

    增加DemoListener.cpp文件，在DemoListener类中根据实际需求自定义订阅回调接口的实现逻辑：

    ```
    #include "demo_listener.h"

    #include <iostream>

    void DemoListener::OnHandle(const std::string& domain, const std::string& eventName,
        const int eventType, const std::string& eventDetail)
    {
        std::cout << eventDetail << std::endl;
    }

    void DemoListener::OnServiceDied()
    {
        std::cout << std::string("service disconnect, exit") << std::endl;
        exit(0);
    }
    ```

    通过HiSysEventManager类提供的AddEventListener接口注册回调对象，完成对HiSysEvent的订阅：

    ```
    std::shared_ptr<DemoListener> demoListener = nullptr;
    try {
        demoListener = std::make_shared<DemoListener>();
    } catch(...) {
        // 智能指针获取失败异常处理
    }
    if (demoListener != nullptr) {
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
        HiSysEventManager::AddEventListener(demoListener, sysRules);
    }
    ```

2.  编译配置

    在BUILD.gn编译文件中，需要添加依赖hisysevent\_native组件的libhisyseventmanager库：

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager", ]
    ```
