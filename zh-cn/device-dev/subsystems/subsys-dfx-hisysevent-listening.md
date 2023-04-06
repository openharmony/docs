# HiSysEvent订阅


## 概述


### 功能简介

HiSysEvent提供了跨进程订阅机制，开发者可以通过注册订阅接口实时获取关注的事件，例如电池模块侦听功耗相关的事件，用于分析耗电情况。


### 约束与限制

在订阅HiSysEvent事件之前，需要先完成HiSysEvent打点配置，具体配置方法请参考[《HiSysEvent打点配置指导》](../subsystems/subsys-dfx-hisysevent-logging-config.md)。


## 开发指导


### 接口说明

  **表1** HiSysEvent订阅接口

| 接口名称 | 描述 |
| -------- | -------- |
| int32_t&nbsp;HiSysEventManager::AddListener(std::shared_ptr&lt;HiSysEventListener&gt;&nbsp;listener,<br/>&nbsp;std::vector&lt;ListenerRule&gt;&amp;&nbsp;rules) | 接口功能：注册订阅HiSysEvent系统事件侦听对象，可设置规则订阅某些事件。<br/>输入参数：<br/>-&nbsp;listener：订阅回调对象。<br/>-&nbsp;rules：事件订阅规则。<br/>返回值：<br/>-&nbsp;0：订阅成功。<br/>-&nbsp;负值：订阅失败。 |
| int32_t&nbsp;HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventListener&gt;&nbsp;listener) | 接口功能：移除订阅hisysevent系统事件侦听对象。<br/>输入参数：<br/>-&nbsp;listener：订阅回调对象。<br/>返回值：<br/>-&nbsp;0：取消订阅成功。<br/>-&nbsp;负值：取消订阅失败。  |

  **表2** ListenerRule订阅规则对象

| 接口名称 | 描述 |
| -------- | -------- |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;tag,<br/>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | 接口功能：订阅规则构造函数，创建事件标签订阅规则对象。<br/>输入参数：<br/>-&nbsp;tag：订阅规则的HisysEvent事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。<br/>-&nbsp;ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。 |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;domain,<br/>&nbsp;const&nbsp;std::string&amp;&nbsp;eventName,<br/>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | 接口功能：订阅规则构造函数，创建事件领域与事件名称订阅规则对象。<br/>输入参数：<br/>-&nbsp;domain：订阅规则的HisysEvent事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;eventName：订阅规则的HisysEvent事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。 |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;domain,<br/>&nbsp;const&nbsp;std::string&amp;&nbsp;eventName,<br/>&nbsp;const&nbsp;std::string&amp;&nbsp;tag,<br/>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | 接口功能：订阅规则构造函数，创建事件领域、事件名称，事件标签订阅规则对象。<br/>输入参数：<br/>-&nbsp;tag：订阅规则的HisysEvent事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。<br/>-&nbsp;domain：订阅规则的HisysEvent事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;eventName：订阅规则的HisysEvent事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。<br/>-&nbsp;ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。 |

  **表3** RuleType类型

| 枚举值 | 描述 |
| -------- | -------- |
| WHOLE_WORD | 全词匹配类型 |
| PREFIX | 前缀匹配类型 |
| REGULAR | 正则匹配类型 |

  **表4** HiSysEventListener订阅对象

| 接口名称 | 描述 |
| -------- | -------- |
| void&nbsp;HiSysEventListener::OnEvent(std::shared_ptr&lt;HiSysEventRecord&gt;&nbsp;sysEvent) | 接口功能：订阅事件的回调接口。<br/>输入参数：<br/>-&nbsp;sysEvent：监听到的实时HiSysEvent事件。<br/>返回值：<br/>无。 |
| void&nbsp;HiSysEventListener::OnServiceDied() | 接口功能：服务异常回调。<br/>输入参数：<br/>无。<br/>返回值：<br/>无。 |

**表5** HiSysEventRecord系统事件对象
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
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;double&gt;&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为double类型的数组。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：ouble类型数组引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成double类型的数组。|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;std::string&gt;&amp;&nbsp;value)|接口功能：将该系统事件键名为param的值解析为string类型的数组。<br/>输入参数：<br/>-&nbsp;param：键名。<br/>-&nbsp;value：std::string类型数组引用。<br/>返回值：<br/>-&nbsp;0：解析成功。<br/>-&nbsp;-1：该系统事件初始化失败，无法解析。<br/>-&nbsp;-2：不存在的键名。<br/>-&nbsp;-3：类型不匹配，无法转换成std::string类型的数组。|


## 开发实例


### C++接口实例

订阅HiSysEvent事件C++接口实例。

1. 源代码开发
   自定义订阅回调实现类头文件DemoListener.h：

   ```
   #ifndef DEMO_LISTENER_H
   #define DEMO_LISTENER_H

   #include "hisysevent_listener.h"

   #include <string>

   class DemoListener : public OHOS::HiviewDFX::HiSysEventListener {
   public:
       explicit DemoListener() : HiSysEventListener() {}
     virtual ~DemoListener() {}

   public:
       void OnEvent(std::shared_ptr<HiSysEventRecord> sysEvent);
       void OnServiceDied();
   };
   
   #endif // DEMO_LISTENER_H
   ```

   增加DemoListener.cpp文件，在DemoListener类中根据实际需求自定义订阅回调接口的实现逻辑：

   ```
   #include "demo_listener.h"

   #include <iostream>

   void DemoListener::OnEvent(std::shared_ptr<HiSysEventRecord> sysEvent)
   {
       if (sysEvent == nullptr) {
           return;
       }
       std::cout << sysEvent.AsJson() << std::endl;
   }

   void DemoListener::OnServiceDied()
   {
       std::cout << std::string("service disconnect, exit") << std::endl;
       exit(0);
   }
   ```

   通过HiSysEventManager类提供的AddEventListener接口注册回调对象，完成对HiSysEvent的订阅：

   ```
   auto demoListener = std::make_shared<DemoListener>();
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
   ```

2. 编译配置
   在BUILD.gn编译文件中，需要添加依赖hisysevent_native组件的libhisysevent及libhisyseventmanager库：

   ```
   external_deps = [
     "hisysevent_native:libhisysevent",
     "hisysevent_native:libhisyseventmanager",
   ]
   ```
