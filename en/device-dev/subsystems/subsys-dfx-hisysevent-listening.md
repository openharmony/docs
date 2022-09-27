# HiSysEvent Listening


## Overview


### Introduction

HiSysEvent supports listening for events across processes. You can register a listener to listen for concerned events on a real-time basis. For example, you can enable the battery module to listen for power consumption events for power usage analysis.


### Constraints

Before subscribing to system events, you need to configure HiSysEvent logging. For details, see [HiSysEvent Logging Configuration](../subsystems/subsys-dfx-hisysevent-logging-config.md).


## Development Guidelines


### Available APIs

  **Table 1** Description of HiSysEventListener APIs

| API| Description|
| -------- | -------- |
| int32_t HiSysEventManager::AddListener(std::shared_ptr&lt;HiSysEventListener&gt; listener, std::vector&lt;ListenerRule&gt;&amp; rules) | Registers a listener for system events. You can listen for certain events by specifying rules.<br>Input arguments:<br>- **listener**: callback object for system events.<br>- **rules**: rules for event listening.<br>Return value:<br>- **0**: Registration is successful.<br>- A negative value: Registration has failed.|
| int32_t HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventListener&gt; listener) | Removes the listener for system events.<br>Input arguments:<br>- **listener**: callback object for system events.<br>Return value:<br>- **0**: Canceling registration is successful.<br>- A negative value: Canceling registration has failed. |

  **Table 2** Description of ListenerRule

| API| Description|
| -------- | -------- |
| ListenerRule(const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD) | Constructor used to create a **ListenerRule** object based on the event tag.<br>Input arguments:<br>- **tag**: event tag for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, lowercase letters, and digits.<br>- **ruleType**: type of the **ListenerRule** object. The value is an enum defined by **RuleType**.|
| ListenerRule(const std::string&amp; domain, const std::string&amp; eventName, RuleType ruleType = RuleType::WHOLE_WORD) | Constructor used to create a **ListenerRule** object based on the event domain and event name.<br>Input arguments:<br>- **domain**: event domain for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, digits, and underscores.<br>- **eventName**: event name for the **ListenerRule** object. The value is a string of 1 to 32 characters, including uppercase letters, digits, and underscores.<br>- **ruleType**: type of the **ListenerRule** object. The value is an enum defined by **RuleType**.|
| ListenerRule(const std::string&amp; domain, const std::string&amp; eventName, const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD) | Constructor used to create a **ListenerRule** object based on the event domain, event name, and event tag.<br>Input arguments:<br>- **tag**: event tag for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, lowercase letters, and digits.<br>- **domain**: event domain for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, digits, and underscores.<br>- **eventName**: event name for the **ListenerRule** object. The value is a string of 1 to 32 characters, including uppercase letters, digits, and underscores.<br>- **ruleType**: type of the **ListenerRule** object. The value is an enum defined by **RuleType**.|

  **Table 3** Description of RuleType

| Value| Description|
| -------- | -------- |
| WHOLE_WORD | Whole word matching|
| PREFIX | Prefix matching|
| REGULAR | Regular expression matching|

  **Table 4** Description of HiSysEventListener

| API| Description|
| -------- | -------- |
| void HiSysEventListener::OnEvent(std::shared_ptr&lt;HiSysEventRecord&gt; sysEvent) | Callback object for system events.<br>Input arguments:<br>- **sysEvent**: real-time system events.<br>Return value:<br>None.|
| void HiSysEventListener::OnServiceDied() | Callback object for service exceptions.<br>Input arguments:<br>None.<br>Return value:<br>None.|

**Table 5** Description of HiSysEventRecord
| API| Description|
| -------- | -------- |
|std::string HiSysEventRecord::AsJson()|Obtains the content of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Content of the system event.|
|std::string HiSysEventRecord::GetDomain()|Obtains the domain name of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Domain name of the system event.|
|std::string HiSysEventRecord::GetEventName()|Obtains the name of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Name of the system event.|
|HiSysEvent::EventType HiSysEventRecord::GetEventType()|Obtains the type of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Type of the system event.|
|std::string HiSysEventRecord::GetLevel()|Obtains the level of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Level of the system event.|
|std::string HiSysEventRecord::GetTag()|Obtains the tag of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Tag of the system event.|
|std::string HiSysEventRecord::GetTimeZone()|Obtains the time zone of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Time zone, in the format of **+0800**.|
|int HiSysEventRecord::GetTraceFlag()|Obtains the distributed call chain tracing flag of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Distributed call chain tracing flag.|
|int64_t HiSysEventRecord::GetPid()|Obtains the ID of the process that flushes a system event to the disk.<br>Input arguments:<br>None.<br>Return value:<br>Process ID.|
|int64_t HiSysEventRecord::GetTid()|Obtains the thread ID of the process that flushes a system event to the disk.<br>Input arguments:<br>None.<br>Return value:<br>Thread ID.|
|int64_t HiSysEventRecord::GetUid()|Obtains the user ID of the process that flushes a system event to the disk.<br>Input arguments:<br>None.<br>Return value:<br>User ID.|
|uint64_t HiSysEventRecord::GetPspanId()|Obtains the parent span ID of the distributed call chain tracing task.<br>Input arguments:<br>None.<br>Return value:<br>Parent span ID of the distributed call chain tracing task.|
|uint64_t HiSysEventRecord::GetSpandId()|Obtains the span ID of the distributed call chain tracing task.<br>Input arguments:<br>None.<br>Return value:<br>Span ID of the distributed call chain tracing task.|
|uint64_t HiSysEventRecord::GetTime()|Obtains the timestamp of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Timestamp of the system event.|
|uint64_t HiSysEventRecord::GetTraceId()|Obtains the ID of the distributed call chain tracing task.<br>Input arguments:<br>None.<br>Return value:<br>ID of the distributed call chain tracing task.|
|void HiSysEventRecord::GetParamNames(std::vector&lt;std::string&gt;&amp; params)|Obtains all key names of a system event.<br>Input arguments:<br>- **params**: key name array reference.<br>Return value:<br>None.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, int64_t&amp; value)|Parses the value of the **param** key in a system event into an int64\_t value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: int64\_t reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, uint64_t&amp; value)|Parses the value of the **param** key in a system event into a uint64\_t value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: uint64\_t reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, double&amp; value)|Parses the value of the **param** key in a system event into a double value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: double reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, std::string&amp; value)|Parses the value of the **param** key in a system event into a string value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: std::string reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, std::vector&lt;int64_t&gt;&amp; value)|Parses the value of the **param** key in a system event into an int64\_t array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: int64\_t array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, std::vector&lt;uint64_t&gt;&amp; value)|Parses the value of the **param** key in a system event into a uint64\_t array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: uint64\_t array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, std::vector&lt;double&gt;&amp; value)|Parses the value of the **param** key in a system event into a double array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: double array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int HiSysEventRecord::GetParamValue(const std::string&amp; param, std::vector&lt;std::string&gt;&amp; value)|Parses the value of the **param** key in a system event into a string array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: std::string array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|


## How to Develop


### **C++**

The following provides an example of how to use C++ APIs of **HiSysEvent**.

1. Develop the source code.
   Import the **DemoListener.h** header file, which contains the **DemoListener** class for implementing the custom event callback.

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

   Create the **DemoListener.cpp** file, and add the implementation logic of the custom event callback API in the **DemoListener** class.

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

   Call the **AddEventListener** API of the **HiSysEventManager** class to add a listener for system events.

   ```
   auto demoListener = std::make_shared<DemoListener>();
   // Add a ListenerRule object based on the event tag, with RuleType left unspecified (in this case, ruleType is defaulted to WHOLE_WORD).
   ListenerRule tagRule("dfx");
   // Add a ListenerRule object based on the event tag, with RuleType set as REGULAR.
   ListenerRule regRule("dfx.*", RuleType::REGULAR);
   // Add a ListenerRule object based on the event domain and event name, with RuleType set as PREFIX.
   ListenerRule domainNameRule("HIVIEWDFX", "APP_USAGE", RuleType::PREFIX);
   std::vector<ListenerRule> sysRules;
   sysRules.push_back(tagRule);
   sysRules.push_back(regRule);
   sysRules.push_back(domainNameRule);
   HiSysEventManager::AddEventListener(demoListener, sysRules);
   ```

2. Configure the **BUILD.gn** file.
   In the **BUILD.gn** file, add the **libhisysevent** and **libhisyseventmanager** libraries that depend on the **hisysevent_native** component.

   ```
   external_deps = [
     "hisysevent_native:libhisysevent",
     "hisysevent_native:libhisyseventmanager",
   ]
   ```
