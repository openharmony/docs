# HiSysEvent查询指导<a name="ZH-CN_TOPIC_0000001231455461"></a>

-   [概述](#section279684125212)
-   [接口说明](#section03869128521)
-   [开发实例](#section14286111855212)
    -   [C++接口实例](#section162045551743)


## 概述<a name="section279684125212"></a>

HiSysEvent提供了查询接口，支持开发者设置条件查询HiSysEvent事件，例如功耗部件可以通过该接口获取所需的系统事件进行业务分析。

## 接口说明<a name="section03869128521"></a>

**表 1**  HiSysEvent查询接口

<a name="table1844019587496"></a>
<table><thead align="left"><tr id="row1440058184916"><th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.2.3.1.1"><p id="p19441135844915"><a name="p19441135844915"></a><a name="p19441135844915"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="51.88%" id="mcps1.2.3.1.2"><p id="p13441195815491"><a name="p13441195815491"></a><a name="p13441195815491"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p114411558204915"><a name="p114411558204915"></a><a name="p114411558204915"></a>bool HiSysEventManager::QueryHiSysEvent(struct QueryArg&amp; queryArg, std::vector&lt;struct QueryRule&gt;&amp; queryRules, std::shared_ptr&lt;HiSysEventQueryCallBackBase&gt; queryCallBack)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>接口功能：支持设置查询时间段，事件领域，事件名称等，查询满足条件的HiSysEvent事件。</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>输入参数：</p>
<a name="ul6717142214919"></a><a name="ul6717142214919"></a><ul id="ul6717142214919"><li>queryArg：查询参数。</li><li>queryRules：事件过滤规则。</li><li>queryCallBack：查询接口回调对象。</li></ul>
<p id="p83591223153818"><a name="p83591223153818"></a><a name="p83591223153818"></a>返回值：</p>
<a name="ul12105842111913"></a><a name="ul12105842111913"></a><ul id="ul12105842111913"><li>true：查询成功。</li><li>false：查询失败。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2**  QueryArg查询参数对象

<a name="table13783145132014"></a>
<table><thead align="left"><tr id="row11784451112013"><th class="cellrowborder" valign="top" width="47.85%" id="mcps1.2.3.1.1"><p id="p187841351152012"><a name="p187841351152012"></a><a name="p187841351152012"></a>属性名称</p>
</th>
<th class="cellrowborder" valign="top" width="52.15%" id="mcps1.2.3.1.2"><p id="p4784105182019"><a name="p4784105182019"></a><a name="p4784105182019"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3784451122012"><td class="cellrowborder" valign="top" width="47.85%" headers="mcps1.2.3.1.1 "><p id="p2078414512209"><a name="p2078414512209"></a><a name="p2078414512209"></a>long long beginTime</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.2.3.1.2 "><p id="p37844517207"><a name="p37844517207"></a><a name="p37844517207"></a>事件开始时间。</p>
</td>
</tr>
<tr id="row1564913158230"><td class="cellrowborder" valign="top" width="47.85%" headers="mcps1.2.3.1.1 "><p id="p11649191511239"><a name="p11649191511239"></a><a name="p11649191511239"></a>long long endTime</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.2.3.1.2 "><p id="p126491715182314"><a name="p126491715182314"></a><a name="p126491715182314"></a>事件结束事件。</p>
</td>
</tr>
<tr id="row461821212236"><td class="cellrowborder" valign="top" width="47.85%" headers="mcps1.2.3.1.1 "><p id="p461841262313"><a name="p461841262313"></a><a name="p461841262313"></a>int maxEvents</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.2.3.1.2 "><p id="p1161901214232"><a name="p1161901214232"></a><a name="p1161901214232"></a>返回最大的查询条数。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  QueryRule查询规则对象

<a name="table1144011610564"></a>
<table><thead align="left"><tr id="row124411716175611"><th class="cellrowborder" valign="top" width="48.03%" id="mcps1.2.3.1.1"><p id="p19441151675610"><a name="p19441151675610"></a><a name="p19441151675610"></a>属性名称</p>
</th>
<th class="cellrowborder" valign="top" width="51.970000000000006%" id="mcps1.2.3.1.2"><p id="p16441171616563"><a name="p16441171616563"></a><a name="p16441171616563"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row174411216105615"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p496413536613"><a name="p496413536613"></a><a name="p496413536613"></a><span>uint32_t</span> ruleType</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><p id="p94416160565"><a name="p94416160565"></a><a name="p94416160565"></a>规则类型，目前默认是0。</p>
</td>
</tr>
<tr id="row64411816125614"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p1258135313712"><a name="p1258135313712"></a><a name="p1258135313712"></a>std::string domain;</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><a name="ul14905926102311"></a><a name="ul14905926102311"></a><ul id="ul14905926102311"><li>domain：事件所属领域，如果传入的是空字符串，则默认事件领域字段匹配成功。</li></ul>
</td>
</tr>
<tr id="row244161615619"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p227913101887"><a name="p227913101887"></a><a name="p227913101887"></a>std::vector&lt;std::string&gt; eventList</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><a name="ul248063132319"></a><a name="ul248063132319"></a><ul id="ul248063132319"><li>eventList：事件名称的列表，如果传入的是空字符串，则默认事件名称字段匹配成功。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 4**  HiSysEventQueryCallBackBase查询回调对象

<a name="table1451320549112"></a>
<table><thead align="left"><tr id="row951420547116"><th class="cellrowborder" valign="top" width="48.03%" id="mcps1.2.3.1.1"><p id="p15141546117"><a name="p15141546117"></a><a name="p15141546117"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="51.970000000000006%" id="mcps1.2.3.1.2"><p id="p165141654151113"><a name="p165141654151113"></a><a name="p165141654151113"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row35141554151115"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p4714143785410"><a name="p4714143785410"></a><a name="p4714143785410"></a>void HiSysEventQueryCallBackBase::OnQuery(const ::std::vector&lt;std::string&gt;&amp; sysEvent, const ::std::vector&lt;int64_t&gt;&amp; seq)</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><p id="p1772213111011"><a name="p1772213111011"></a><a name="p1772213111011"></a>接口功能：订阅事件查询中的回调。</p>
<p id="p182081719151016"><a name="p182081719151016"></a><a name="p182081719151016"></a>输入参数：</p>
<a name="ul02091819131015"></a><a name="ul02091819131015"></a><ul id="ul02091819131015"><li>sysEvent：返回事件集合。</li><li>seq：事件序列集合。</li></ul>
<p id="p18209419201010"><a name="p18209419201010"></a><a name="p18209419201010"></a>返回值：无。</p>
</td>
</tr>
<tr id="row15141154161111"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p561110151119"><a name="p561110151119"></a><a name="p561110151119"></a>void HiSysEventQueryCallBackBase::OnComplete(int32_t reason, int32_t total)</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><p id="p126315352130"><a name="p126315352130"></a><a name="p126315352130"></a>接口功能：订阅事件查询完成的回调。</p>
<p id="p6631235191316"><a name="p6631235191316"></a><a name="p6631235191316"></a>输入参数：</p>
<a name="ul106383518130"></a><a name="ul106383518130"></a><ul id="ul106383518130"><li>reason：查询结束返回原因，目前默认是0。</li><li>total：本次查询总共返回的事件总数量。</li></ul>
<p id="p176313516133"><a name="p176313516133"></a><a name="p176313516133"></a>返回值：无。</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section14286111855212"></a>

### C++接口实例<a name="section162045551743"></a>

本实例介绍如何查询所有系统事件。

1.  源代码开发：

    -   引入对应的头文件：

        hisysevent\_manager.h

    -   实现对应的查询回调接口：

        void HiSysEventQueryCallBackBase::OnQuery\(const ::std::vector<std::string\>& sysEvent, const ::std::vector<int64\_t\>& seq\)

        void HiSysEventQueryCallBackBase::OnComplete\(int32\_t reason, int32\_t total\)

    -   在相应的业务逻辑里面调用查询接口：

        HiSysEventManager::QueryHiSysEvent\(struct QueryArg& queryArg, std::vector<struct QueryRule\>& queryRules, std::shared\_ptr<HiSysEventQueryCallBackBase\> queryCallBack\)


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
    auto queryCallBack = std::make_shared<HiSysEventToolQuery>();
    struct QueryArg args(clientCmdArg.beginTime, clientCmdArg.endTime, clientCmdArg.maxEvents);
    std::vector<struct QueryRule> mRules;
    HiSysEventManager::QueryHiSysEvent(args, mRules, queryCallBack);
    ```

2.  编译设置：

    在BUILD.gn编译文件中，需要添加依赖hisysevent\_native部件的libhisyseventmanager库。

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager",  ]
    ```


