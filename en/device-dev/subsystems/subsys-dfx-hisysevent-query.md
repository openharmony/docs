# HiSysEvent Query<a name="EN-US_TOPIC_0000001231455461"></a>

## Overview<a name="section279684125212"></a>

HiSysEvent provides an API for you to query system events. You can query concerned events by specifying search criteria. For example, for a power consumption module, you can query required system events for analysis.

## Available APIs<a name="section03869128521"></a>

**Table  1**  HiSysEvent query API

<a name="table1844019587496"></a>
<table><thead align="left"><tr id="row1440058184916"><th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.2.3.1.1"><p id="p19441135844915"><a name="p19441135844915"></a><a name="p19441135844915"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="51.88%" id="mcps1.2.3.1.2"><p id="p13441195815491"><a name="p13441195815491"></a><a name="p13441195815491"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p114411558204915"><a name="p114411558204915"></a><a name="p114411558204915"></a>bool HiSysEventManager::QueryHiSysEvent(struct QueryArg&amp; queryArg, std::vector&lt;struct QueryRule&gt;&amp; queryRules, std::shared_ptr&lt;HiSysEventQueryCallBackBase&gt; queryCallBack)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>Queries system events by specifying search criteria such as the time segment, event domain, and event name.</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>Input arguments:</p>
<a name="ul6717142214919"></a><a name="ul6717142214919"></a><ul id="ul6717142214919"><li><strong id="b13783124325410"><a name="b13783124325410"></a><a name="b13783124325410"></a>queryArg</strong>: event query parameter.</li><li><strong id="b179229305560"><a name="b179229305560"></a><a name="b179229305560"></a>queryRules</strong>: event filtering rules.</li><li><strong id="b1244153910574"><a name="b1244153910574"></a><a name="b1244153910574"></a>queryCallBack</strong>: callback object for query results.</li></ul>
<p id="p83591223153818"><a name="p83591223153818"></a><a name="p83591223153818"></a>Return values</p>
<a name="ul12105842111913"></a><a name="ul12105842111913"></a><ul id="ul12105842111913"><li><strong id="b16711328155919"><a name="b16711328155919"></a><a name="b16711328155919"></a>true</strong>: Operation successful.</li><li><strong id="b1421823714591"><a name="b1421823714591"></a><a name="b1421823714591"></a>false</strong>: Operation failed.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2**  HiSysEvent query parameters

<a name="table13783145132014"></a>
<table><thead align="left"><tr id="row11784451112013"><th class="cellrowborder" valign="top" width="47.85%" id="mcps1.2.3.1.1"><p id="p187841351152012"><a name="p187841351152012"></a><a name="p187841351152012"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="52.15%" id="mcps1.2.3.1.2"><p id="p4784105182019"><a name="p4784105182019"></a><a name="p4784105182019"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3784451122012"><td class="cellrowborder" valign="top" width="47.85%" headers="mcps1.2.3.1.1 "><p id="p2078414512209"><a name="p2078414512209"></a><a name="p2078414512209"></a>long long beginTime</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.2.3.1.2 "><p id="p37844517207"><a name="p37844517207"></a><a name="p37844517207"></a>Start time.</p>
</td>
</tr>
<tr id="row1564913158230"><td class="cellrowborder" valign="top" width="47.85%" headers="mcps1.2.3.1.1 "><p id="p11649191511239"><a name="p11649191511239"></a><a name="p11649191511239"></a>long long endTime</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.2.3.1.2 "><p id="p126491715182314"><a name="p126491715182314"></a><a name="p126491715182314"></a>End time.</p>
</td>
</tr>
<tr id="row461821212236"><td class="cellrowborder" valign="top" width="47.85%" headers="mcps1.2.3.1.1 "><p id="p461841262313"><a name="p461841262313"></a><a name="p461841262313"></a>int maxEvents</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.2.3.1.2 "><p id="p1161901214232"><a name="p1161901214232"></a><a name="p1161901214232"></a>Maximum number of query records.</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  HiSysEvent query rules

<a name="table1144011610564"></a>
<table><thead align="left"><tr id="row124411716175611"><th class="cellrowborder" valign="top" width="48.03%" id="mcps1.2.3.1.1"><p id="p19441151675610"><a name="p19441151675610"></a><a name="p19441151675610"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="51.970000000000006%" id="mcps1.2.3.1.2"><p id="p16441171616563"><a name="p16441171616563"></a><a name="p16441171616563"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row174411216105615"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p496413536613"><a name="p496413536613"></a><a name="p496413536613"></a><span>uint32_t</span> ruleType</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><p id="p94416160565"><a name="p94416160565"></a><a name="p94416160565"></a>Rule type. The default value is <strong id="b196007205817"><a name="b196007205817"></a><a name="b196007205817"></a>0</strong>.</p>
</td>
</tr>
<tr id="row64411816125614"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p1258135313712"><a name="p1258135313712"></a><a name="p1258135313712"></a>std::string domain;</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><a name="ul14905926102311"></a><a name="ul14905926102311"></a><ul id="ul14905926102311"><li><strong id="b9813231789"><a name="b9813231789"></a><a name="b9813231789"></a>domain</strong>: domain to which the event belongs. By default, an empty string indicates that the domain is successfully matched.</li></ul>
</td>
</tr>
<tr id="row244161615619"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p227913101887"><a name="p227913101887"></a><a name="p227913101887"></a>std::vector&lt;std::string&gt; eventList</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><a name="ul248063132319"></a><a name="ul248063132319"></a><ul id="ul248063132319"><li><strong id="b172129351784"><a name="b172129351784"></a><a name="b172129351784"></a>eventList</strong>: event name list. By default, an empty string indicates that the event names on the list are successfully matched.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  4**  HiSysEvent query callback objects

<a name="table1451320549112"></a>
<table><thead align="left"><tr id="row951420547116"><th class="cellrowborder" valign="top" width="48.03%" id="mcps1.2.3.1.1"><p id="p15141546117"><a name="p15141546117"></a><a name="p15141546117"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="51.970000000000006%" id="mcps1.2.3.1.2"><p id="p165141654151113"><a name="p165141654151113"></a><a name="p165141654151113"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row35141554151115"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p4714143785410"><a name="p4714143785410"></a><a name="p4714143785410"></a>void HiSysEventQueryCallBackBase::OnQuery(const ::std::vector&lt;std::string&gt;&amp; sysEvent, const ::std::vector&lt;int64_t&gt;&amp; seq)</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><p id="p1772213111011"><a name="p1772213111011"></a><a name="p1772213111011"></a>Callback object for event query.</p>
<p id="p182081719151016"><a name="p182081719151016"></a><a name="p182081719151016"></a>Input arguments:</p>
<a name="ul02091819131015"></a><a name="ul02091819131015"></a><ul id="ul02091819131015"><li><strong id="b132316517135"><a name="b132316517135"></a><a name="b132316517135"></a>sysEvent</strong>: event set.</li><li><strong id="b185101961310"><a name="b185101961310"></a><a name="b185101961310"></a>seq</strong>: event sequence set.</li></ul>
<p id="p18209419201010"><a name="p18209419201010"></a><a name="p18209419201010"></a>Return value: none</p>
</td>
</tr>
<tr id="row15141154161111"><td class="cellrowborder" valign="top" width="48.03%" headers="mcps1.2.3.1.1 "><p id="p561110151119"><a name="p561110151119"></a><a name="p561110151119"></a>void HiSysEventQueryCallBackBase::OnComplete(int32_t reason, int32_t total)</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.2.3.1.2 "><p id="p126315352130"><a name="p126315352130"></a><a name="p126315352130"></a>Callback object for completion of event query.</p>
<p id="p6631235191316"><a name="p6631235191316"></a><a name="p6631235191316"></a>Input arguments:</p>
<a name="ul106383518130"></a><a name="ul106383518130"></a><ul id="ul106383518130"><li><strong id="b855743017177"><a name="b855743017177"></a><a name="b855743017177"></a>reason</strong>: reason for completion of event query. The default value is <strong id="b5175337111718"><a name="b5175337111718"></a><a name="b5175337111718"></a>0</strong>.</li><li><strong id="b1196583151911"><a name="b1196583151911"></a><a name="b1196583151911"></a>total</strong>: total number of events returned in this query.</li></ul>
<p id="p176313516133"><a name="p176313516133"></a><a name="p176313516133"></a>Return value: none</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section14286111855212"></a>

### **C++**<a name="section162045551743"></a>

In this example, you'll be instructed to query all system events.

1.  Develop the source code.

    -   Import the corresponding header file:

        hisysevent\_manager.h

    -   Implement the callback API.

        void HiSysEventQueryCallBackBase::OnQuery\(const ::std::vector<std::string\>& sysEvent, const ::std::vector<int64\_t\>& seq\)

        void HiSysEventQueryCallBackBase::OnComplete\(int32\_t reason, int32\_t total\)

    -   Invoke the query API in the corresponding service logic.

        HiSysEventManager::QueryHiSysEvent\(struct QueryArg& queryArg, std::vector<struct QueryRule\>& queryRules, std::shared\_ptr<HiSysEventQueryCallBackBase\> queryCallBack\)


    ```
    // In this example, you'll query all system events.
    #include "hisysevent_manager.h"
    #include <iostream>
    
    namespace OHOS {
    namespace HiviewDFX {
    // Implement the query callback API.
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
    
    // Invoke the query callback API to obtain system events.
    auto queryCallBack = std::make_shared<HiSysEventToolQuery>();
    struct QueryArg args(clientCmdArg.beginTime, clientCmdArg.endTime, clientCmdArg.maxEvents);
    std::vector<struct QueryRule> mRules;
    HiSysEventManager::QueryHiSysEvent(args, mRules, queryCallBack);
    ```

2.  Modify the  **BUILD.gn**  file.

    In the  **BUILD.gn**  file, add the  **libhisyseventmanager**  library that depends on the** hisysevent\_native**  component.

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager",  ]
    ```


