# HiSysEvent Query


## Overview

HiSysEvent allows you to query system events by specifying search criteria. For example, for a power consumption module, you can query required system events for analysis.


## Development Guidelines


### Available APIs

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> For details about the **HiSysEventRecord** argument in the **OnQuery()** method of **HiSysEventQueryCallback**, see Table 5 in [HiSysEvent Listening](subsys-dfx-hisysevent-listening.md).

  **Table 1** Description of the HiSysEvent query API

| API| Description|
| -------- | -------- |
| int32_t HiSysEventManager::Query(struct QueryArg&amp; arg, std::vector&lt;QueryRule&gt;&amp; rules, std::shared_ptr&lt;HiSysEventQueryCallback&gt; callback) | Queries system events by specifying search criteria such as the time segment, event domain, and event name.<br>Input arguments:<br>- **arg**: event query parameter.<br>- **rules**: rules for event filtering.<br>- **callback**: callback object for event query.<br>Return value:<br>- **0**: Query is successful.<br>- A negative value: Query has failed.|

  **Table 2** Description of QueryArg

| Attribute| Description|
| -------- | -------- |
| beginTime | Start time, in the **long long int** format.|
| endTime | End time, in the **long long int** format.|
| maxEvents | Maximum number of returned events, in the **int** format.|

  **Table 3** Description of QueryRule

| API| Description|
| -------- | -------- |
| QueryRule(const std::string&amp; domain, const std::vector&lt;std::string&gt;&amp; eventList) | Constructor used to create a **QueryRule** object.<br>Input arguments:<br>- **domain**: domain to which the event of the **QueryRule** object belongs, in the string format. By default, an empty string indicates that the domain is successfully matched.<br>- **eventList**: event name list, in the **std::vector&lt;std::string&gt;** format. By default, an empty string indicates that the event names on the list are successfully matched.|

  **Table 4** Description of HiSysEventQueryCallback

| API| Description|
| -------- | -------- |
| void HiSysEventQueryCallback::OnQuery(std::shared_ptr&lt;std::vector&lt;HiSysEventRecord&gt;&gt; sysEvents) | Callback object for event query.<br>Input arguments:<br>- **sysEvents**: event list.<br>Return value:<br>None.|
| void HiSysEventQueryCallback::OnComplete(int32_t reason, int32_t total) | Callback object for completion of event query.<br>Input arguments:<br>- **reason**: reason for completion of event query. The default value is **0**.<br>- **total**: total number of events returned in this query.<br>Return value:<br>None.|

### How to Develop

**C++**

1. Develop the source code.
     Import the corresponding header file:

   ```
   #include "hisysevent_manager.h"
   ```

     Implement the callback API.

   ```
   void HiSysEventQueryCallback::OnQuery(std::shared_ptr<std::vector<HiSysEventRecord>> sysEvents)
   void HiSysEventQueryCallback::OnComplete(int32_t reason, int32_t total)
   ```

     Invoke the query API in the corresponding service logic.

   ```
   HiSysEventManager::Query(struct QueryArg& queryArg, 
       std::vector<QueryRule>& queryRules, std::shared_ptr<HiSysEventQueryCallback> queryCallBack)
   ```

     In this example, you'll query all system events.

   ```
   #include "hisysevent_manager.h"
   #include <iostream>

   namespace OHOS {
   namespace HiviewDFX {
   // Implement the query callback API.
   void HiSysEventToolQuery::OnQuery(std::shared_ptr<std::vector<HiSysEventRecord>> sysEvents)
   {
       if (sysEvents == nullptr) {
           return;
       }
       for_each((*sysEvents).cbegin(), (*sysEvents).cend(), [](const HiSysEventRecord& event) {
           std::cout << event.AsJson() << std::endl;
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
   std::vector<QueryRule> rules;
   HiSysEventManager::QueryHiSysEvent(args, rules, queryCallBack);
   ```

2. Modify the **BUILD.gn** file.
     In the **BUILD.gn** file, add the **libhisysevent** and **libhisyseventmanager** libraries that depend on the **hisysevent_native** component.
     
   ```
   external_deps = [
     "hisysevent_native:libhisysevent",
     "hisysevent_native:libhisyseventmanager",
   ]
   ```
