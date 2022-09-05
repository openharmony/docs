# HiSysEvent查询


## 概述

HiSysEvent提供了查询接口，支持开发者设置条件查询HiSysEvent事件，例如功耗部件可以通过该接口获取所需的系统事件进行业务分析。


## 开发指导


### 接口说明

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> HiSysEventQueryCallback查询回调对象OnQuery方法中的形参类型HiSysEventRecord请参考[HiSysEvent订阅](subsys-dfx-hisysevent-listening.md)中的**表5**HiSysEventRecord系统事件对象说明

  **表1** HiSysEvent查询接口

| 接口名 | 描述 |
| -------- | -------- |
| int32_t&nbsp;HiSysEventManager::Query(struct&nbsp;QueryArg&amp;&nbsp;arg,<br/>&nbsp;std::vector&lt;QueryRule&gt;&amp;&nbsp;rules,<br/>&nbsp;std::shared_ptr&lt;HiSysEventQueryCallback&gt;&nbsp;callback) | 接口功能：支持设置时间段，事件领域，事件名称等，查询满足条件的HiSysEvent事件。<br/>输入参数：<br/>-&nbsp;arg：查询参数。<br/>-&nbsp;rules：事件过滤规则。<br/>-&nbsp;callback：查询接口回调对象。<br/>返回值：<br/>-&nbsp;0：查询成功。<br/>-&nbsp;负值：查询失败。 |

  **表2** QueryArg查询参数对象

| 属性名称 | 描述 |
| -------- | -------- |
| beginTime | long&nbsp;long&nbsp;int类型，用于指定查询事件的开始时间。 |
| endTime | long&nbsp;long&nbsp;int类型，用于指定查询事件的结束时间。 |
| maxEvents | int类型，用于指定查询返回事件查询的最多条数。 |

  **表3** QueryRule查询规则对象

| 接口名称 | 描述 |
| -------- | -------- |
| QueryRule(const&nbsp;std::string&amp;&nbsp;domain,<br/>&nbsp;const&nbsp;std::vector&lt;std::string&gt;&amp;&nbsp;eventList) | 接口功能：查询规则构造函数，创建查询规则对象。<br/>输入参数：<br/>-&nbsp;domain：string类型，用来标识查询规则对象的事件所属领域，如果传入的是空字符串，则默认事件领域字段匹配成功。<br/>-&nbsp;eventList：std::vector&lt;std::string&gt;类型，事件名称的列表，如果传入的是空字符串，则默认事件名称字段匹配成功。 |

  **表4** HiSysEventQueryCallback查询回调对象

| 接口名称 | 描述 |
| -------- | -------- |
| void&nbsp;HiSysEventQueryCallBack::OnQuery(std::shared_ptr&lt;std::vector&lt;HiSysEventRecord&gt;&gt;&nbsp;sysEvents) | 接口功能：事件查询的回调。<br/>输入参数：<br/>-&nbsp;sysEvents：返回的事件集合。<br/>返回值：<br/>无。 |
| void&nbsp;HiSysEventQueryCallBack::OnComplete(int32_t&nbsp;reason,&nbsp;int32_t&nbsp;total) | 接口功能：事件查询完成的回调。<br/>输入参数：<br/>-&nbsp;reason：查询结束返回原因，目前默认是0。<br/>-&nbsp;total：本次查询总共返回的事件总数量。<br/>返回值：<br/>无。 |

### 开发实例

C++接口实例。

1. 源代码开发：
     引入对应的头文件：

   ```
   #include "hisysevent_manager.h"
   ```

     实现对应的查询回调接口：

   ```
   void HiSysEventQueryCallBack::OnQuery(std::shared_ptr<std::vector<HiSysEventRecord>> sysEvents)
   void HiSysEventQueryCallBack::OnComplete(int32_t reason, int32_t total)
   ```

     在相应的业务逻辑里面调用查询接口：

   ```
   HiSysEventManager::Query(struct QueryArg& queryArg, 
       std::vector<QueryRule>& queryRules, std::shared_ptr<HiSysEventQueryCallBack> queryCallBack)
   ```

     以下是查询所有系统事件的应用例子：

   ```
   #include "hisysevent_manager.h"
   #include <iostream>

   namespace OHOS {
   namespace HiviewDFX {
   // 实现查询回调的接口
   void HiSysEventToolQuery::OnQuery(std::shared_ptr<std::vector<HiSysEventRecord>> sysEvents)
   {
       if (sysEvents == nullptr) {
           return;
       }
       for_each((*sysEvent).cbegin(), (*sysEvent).cend(), [](const HiSysEventRecord& event) {
           std::cout << event.AsJson() << std::endl;
       });
   }

   void HiSysEventToolQuery::OnComplete(int32_t reason, int32_t total)
   {
       return;
   }
   } // namespace HiviewDFX
   } // namespace OHOS
   
   // 调用查询接口获取HiSysEvent事件
   auto queryCallBack = std::make_shared<HiSysEventToolQuery>();
   struct QueryArg args(clientCmdArg.beginTime, clientCmdArg.endTime, clientCmdArg.maxEvents);
   std::vector<QueryRule> rules;
   HiSysEventManager::QueryHiSysEvent(args, rules, queryCallBack);
   ```

2. 编译设置：
     在BUILD.gn编译文件中，需要添加依赖hisysevent_native部件的libhisysevent及libhisyseventmanager库。
     
   ```
   external_deps = [
     "hisysevent_native:libhisysevent",
     "hisysevent_native:libhisyseventmanager",
   ]
   ```

