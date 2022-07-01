# HiSysEvent查询指导<a name="ZH-CN_TOPIC_0000001231455461"></a>


## 概述<a name="section279684125212"></a>

HiSysEvent提供了查询接口，支持开发者设置条件查询HiSysEvent事件，例如功耗部件可以通过该接口获取所需的系统事件进行业务分析。

## 开发指导<a name="section315316761113"></a>

### 接口说明<a name="section03869128521"></a>

**表 1**  HiSysEvent查询接口

| 接口名称 | 描述  |
| -------- | --------- |
| bool HiSysEventManager::QueryHiSysEvent(struct QueryArg&amp; queryArg, std::vector&lt;QueryRule&gt;&amp; queryRules, std::shared_ptr&lt;HiSysEventQueryCallBack&gt; queryCallBack) | 接口功能：<br>&emsp;&emsp;支持设置查询时间段，事件领域，事件名称等，查询满足条件的HiSysEvent事件。<br><br>输入参数：<ul><li>queryArg：查询参数。</li><li>queryRules：事件过滤规则。</li><li>queryCallBack：查询接口回调对象。</li></ul>返回值：<ul><li>true：查询成功。</li><li>false：查询失败。</li></ul> |


**表 2**  QueryArg查询参数对象

| 属性名称 | 描述  |
| -------- | --------- |
| beginTime | long long int类型，用于指定查询事件的开始时间。 |
| endTime | long long int类型，用于指定查询事件的结束时间。 |
| maxEvents | int类型，用于指定查询返回事件查询的最多条数。 |

**表 3**  QueryRule查询规则对象

| 接口名称 | 描述  |
| -------- | --------- |
| QueryRule(const std::string& domain, const std::vector&lt;std::string&gt;& eventList) | 接口功能：查询规则构造函数，创建查询规则对象。<br><br>输入参数：<ul><li>domain：string类型，用来标识查询规则对象的事件所属领域，如果传入的是空字符串，则默认事件领域字段匹配成功。</li><li>eventList：std::vector&lt;std::string&gt;类型，事件名称的列表，如果传入的是空字符串，则默认事件名称字段匹配成功。</li></ul> |

**表 4**  HiSysEventQueryCallBack查询回调对象

| 接口名称 | 描述  |
| -------- | --------- |
| void HiSysEventQueryCallBack::OnQuery(const ::std::vector&lt;std::string&gt;&amp; sysEvent, const ::std::vector&lt;int64_t&gt;&amp; seq) | 接口功能：订阅事件查询中的回调。<br><br>输入参数：<ul><li>sysEvent：返回事件集合。</li><li>seq：事件序列集合。</li></ul>返回值：<br>&emsp;&emsp;无。 |
| void HiSysEventQueryCallBack::OnComplete(int32_t reason, int32_t total) | 接口功能：订阅事件查询完成的回调。<br><br>输入参数：<ul><li>reason：查询结束返回原因，目前默认是0。</li><li>total：本次查询总共返回的事件总数量。</li></ul>返回值：<br>&emsp;&emsp;无。 |

### 开发实例<a name="section14286111855212"></a>

C++接口实例。

1.  源代码开发：

    -   引入对应的头文件：

        hisysevent\_manager.h

    -   实现对应的查询回调接口：

        void HiSysEventQueryCallBack::OnQuery\(const ::std::vector&lt;std::string&gt;& sysEvent, const ::std::vector<int64\_t\>& seq\)

        void HiSysEventQueryCallBack::OnComplete\(int32\_t reason, int32\_t total\)

    -   在相应的业务逻辑里面调用查询接口：

        HiSysEventManager::QueryHiSysEvent\(struct QueryArg& queryArg, std::vector<QueryRule\>& queryRules, std::shared\_ptr<HiSysEventQueryCallBack\> queryCallBack\)


    ```
    // 以下是查询所有系统事件的应用例子
    #include "hisysevent_manager.h"
    #include <iostream>
    
    namespace OHOS {
    namespace HiviewDFX {
    // 实现查询回调的接口
    void HiSysEventToolQuery::OnQuery(const ::std::vector<std::string>& sysEvent,
        const ::std::vector<int64_t>& seq)
    {
        for_each(sysEvent.cbegin(), sysEvent.cend(), [](const std::string &tmp) {
            std::cout << tmp << std::endl;
        });
    }
    
    void HiSysEventToolQuery::OnComplete(int32_t reason, int32_t total)
    {
        return;
    }
    } // namespace HiviewDFX
    } // namespace OHOS
    
    // 调用查询接口获取HiSysEvent事件
    std::shared_ptr<HiSysEventToolQuery> queryCallBack = nullptr;
    try {
        queryCallBack = std::make_shared<HiSysEventToolQuery>();
    } catch (...) {
        // 智能指针获取失败处理
    }
    if (queryCallBack != nullptr) {
        struct QueryArg args(clientCmdArg.beginTime, clientCmdArg.endTime, clientCmdArg.maxEvents);
        std::vector<QueryRule> rules;
        HiSysEventManager::QueryHiSysEvent(args, rules, queryCallBack);
    }
    ```

2.  编译设置：

    在BUILD.gn编译文件中，需要添加依赖hisysevent\_native部件的libhisyseventmanager库。

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager",  ]
    ```


