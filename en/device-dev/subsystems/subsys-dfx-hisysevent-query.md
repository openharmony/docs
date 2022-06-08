# HiSysEvent Query<a name="EN-US_TOPIC_0000001231455461"></a>

## Overview<a name="section279684125212"></a>

HiSysEvent provides an API for you to query system events. You can query concerned events by specifying search criteria. For example, for a power consumption module, you can query required system events for analysis.

## Development Guidelines<a name="section315316761113"></a>

### Available APIs<a name="section03869128521"></a>

**Table 1** Description of the HiSysEvent query API

| Name| Description |
| -------- | --------- |
| int32_t HiSysEventManager::QueryHiSysEvent(struct QueryArg&amp; queryArg, std::vector&lt;QueryRule&gt;&amp; queryRules, std::shared_ptr&lt;HiSysEventQueryCallBack&gt; queryCallBack) | Queries system events by specifying search criteria such as the time segment, event domain, and event name.<br><br>Input arguments:<ul><li>**queryArg**: event query parameter. </li><li>**queryRules**: event filtering rules. </li><li>**queryRules**: callback object for query results. </li></ul>Return value:<ul><li>**0**: The query is successful. </li><li>Other values: The query has failed.</li></ul> |


**Table 2** Description of QueryArg

| Attribute| Description |
| -------- | --------- |
| beginTime | Start time, in the **long long int** format.|
| endTime | End time, in the **long long int** format.|
| maxEvents | Maximum number of returned events, in the **int** format.|

**Table 3** Description of QueryRule

| API| Description |
| -------- | --------- |
| QueryRule(const std::string& domain, const std::vector&lt;std::string&gt;& eventList) | Constructor used to create a **QueryRule** object.<br><br>Input arguments:<ul><li>**domain: domain to which the event of the **QueryRule** object belongs, in the **string** format. By default, an empty string indicates that the domain is successfully matched. </li><li>**eventList**: event name list, in the **std::vector&lt;std::string&gt;** format. By default, an empty string indicates that the event names on the list are successfully matched.</li></ul> |

**Table 4** Description of HiSysEventQueryCallBack

| API| Description |
| -------- | --------- |
| void HiSysEventQueryCallBack::OnQuery(const ::std::vector&lt;std::string&gt;&amp; sysEvent, const ::std::vector&lt;int64_t&gt;&amp; seq) | Callback object for event query.<br><br>Input arguments:<ul><li>**sysEvent**: event set. </li><li>**seq**: event sequence set. </li></ul>Return value:<br>None.|
| void HiSysEventQueryCallBack::OnComplete(int32_t reason, int32_t total) | Callback object for completion of event query.<br><br>Input arguments:<ul><li>**reason**: reason for completion of event query. The default value is **0**. </li><li>**total**: total number of events returned in this query. </li></ul>Return value:<br>None.|

### Development Example<a name="section14286111855212"></a>

C++

1.  Develop the source code.

    -   Import the corresponding header file:

        hisysevent\_manager.h

    -   Implement the callback API.

        void HiSysEventQueryCallBack::OnQuery\(const ::std::vector&lt;std::string&gt;& sysEvent, const ::std::vector<int64\_t\>& seq\)

        void HiSysEventQueryCallBack::OnComplete\(int32\_t reason, int32\_t total\)

    -   Invoke the query API in the corresponding service logic.

        HiSysEventManager::QueryHiSysEvent\(struct QueryArg& queryArg, std::vector<QueryRule\>& queryRules, std::shared\_ptr<HiSysEventQueryCallBack\> queryCallBack\)


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
    std::shared_ptr<HiSysEventToolQuery> queryCallBack = nullptr;
    try {
        queryCallBack = std::make_shared<HiSysEventToolQuery>();
    } catch(...) {
        // Catch exception thrown by make_shared
    }
    if (queryCallBack != nullptr) {
        struct QueryArg args(clientCmdArg.beginTime, clientCmdArg.endTime, clientCmdArg.maxEvents);
        std::vector<QueryRule> rules;
        HiSysEventManager::QueryHiSysEvent(args, rules, queryCallBack);
    }
    ```

2.  Modify the **BUILD.gn** file.

    In the **BUILD.gn** file, add the **libhisyseventmanager** library that depends on the **hisysevent\_native** component.

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager",  ]
    ```
