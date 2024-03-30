# HiSysEvent Listening


## Overview


### Function Introduction

HiSysEvent supports listening for events across processes. You can register a listener to listen for concerned events on a real-time basis. For example, you can enable the battery module to subscribe to power consumption events for power usage analysis.


### Constraints

Before listening for system events, you need to configure HiSysEvent logging. For details, see [HiSysEvent Logging Configuration](../subsystems/subsys-dfx-hisysevent-logging-config.md).


## How to Develop

### Available APIs

#### C++ APIs

HiSysEvent is implemented using the APIs provided by the **HiSysEventManager** class. For details, see the [API Header Files](/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent_manager/include/).

> **NOTE**
>
> For details about the **RuleType** argument in the constructor of **ListenerRule**, see Table 4 in [HiSysEvent Query](subsys-dfx-hisysevent-query.md).

  **Table 1** Description of C++ HiSysEventManager APIs

| Name| Description|
| -------- | -------- |
| int32_t&nbsp;HiSysEventManager::AddListener(std::shared_ptr&lt;HiSysEventListener&gt;&nbsp;listener,<br>&nbsp;std::vector&lt;ListenerRule&gt;&amp;&nbsp;rules) | Adds a listener to listen for system events based on the specified rules.<br>Input arguments:<br>- **listener**: listener for system events.<br>- **rules**: event listening rules.<br>Return value:<br>- **0**: The listener is added successfully.<br>- A negative value: The listener fails to be added.|
| int32_t&nbsp;HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventListener&gt;&nbsp;listener) | Removes the listener for system events.<br>Input arguments:<br>- **listener**: listener for system events.<br>Return value:<br>- **0**: The listener is removed successfully.<br>- A negative value: The listener fails to be removed. |

  **Table 2** Description of ListenerRule

| Name| Description|
| -------- | -------- |
| ListenerRule(const&nbsp;std::string&amp;&nbsp;tag,<br>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | Constructor used to create a **ListenerRule** object based on the event tag.<br>Input arguments:<br>- **tag**: event tag for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, lowercase letters, and digits.<br>- **ruleType**: type of the **ListenerRule** object. The value is an enum defined by **RuleType**.|
| ListenerRule(const&nbsp;std::string&amp;&nbsp;domain,<br>&nbsp;const&nbsp;std::string&amp;&nbsp;eventName,<br>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | Constructor used to create a **ListenerRule** object based on the event domain and event name.<br>Input arguments:<br>- **domain**: event domain for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, digits, and underscores.<br>- **eventName**: event name for the **ListenerRule** object. The value is a string of 1 to 32 characters, including uppercase letters, digits, and underscores.<br>- **ruleType**: type of the **ListenerRule** object. The value is an enum defined by **RuleType**.|
| ListenerRule(const&nbsp;std::string&amp;&nbsp;domain,<br>&nbsp;const&nbsp;std::string&amp;&nbsp;eventName,<br>&nbsp;const&nbsp;std::string&amp;&nbsp;tag,<br>&nbsp;RuleType&nbsp;ruleType&nbsp;=&nbsp;RuleType::WHOLE_WORD) | Constructor used to create a **ListenerRule** object based on the event domain, event name, and event tag.<br>Input arguments:<br>- **domain**: event domain for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, digits, and underscores.<br>- **eventName**: event name for the **ListenerRule** object. The value is a string of 1 to 32 characters, including uppercase letters, digits, and underscores.<br>- **tag**: event tag for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, lowercase letters, and digits.<br>- **ruleType**: type of the **ListenerRule** object. The value is an enum defined by **RuleType**.|

  **Table 3** Description of HiSysEventListener

| Name| Description|
| -------- | -------- |
| void&nbsp;HiSysEventListener::OnEvent(std::shared_ptr&lt;HiSysEventRecord&gt;&nbsp;sysEvent) | Callback object for system events.<br>Input arguments:<br>- **sysEvent**: real-time system event.<br>Return value:<br>None.|
| void&nbsp;HiSysEventListener::OnServiceDied() | Callback object for service exceptions.<br>Input arguments:<br>None.<br>Return value:<br>None.|

  **Table 4** Description of HiSysEventRecord
| Name| Description|
| -------- | -------- |
|std::string&nbsp;HiSysEventRecord::AsJson()|Obtains the content of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Content of the system event.|
|std::string&nbsp;HiSysEventRecord::GetDomain()|Obtains the domain name of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Domain name of the system event.|
|std::string&nbsp;HiSysEventRecord::GetEventName()|Obtains the name of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Name of the system event.|
|HiSysEvent::EventType&nbsp;HiSysEventRecord::GetEventType()|Obtains the type of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Type of the system event.|
|std::string&nbsp;HiSysEventRecord::GetLevel()|Obtains the level of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Level of the system event.|
|std::string&nbsp;HiSysEventRecord::GetTag()|Obtains the tag of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Tag of the system event.|
|std::string&nbsp;HiSysEventRecord::GetTimeZone()|Obtains the time zone of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Time zone, in the format of **+0800**.|
|int&nbsp;HiSysEventRecord::GetTraceFlag()|Obtains the distributed call chain tracing flag of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Distributed call chain tracing flag.|
|int64_t&nbsp;HiSysEventRecord::GetPid()|Obtains the ID of the process that flushes a system event to the disk.<br>Input arguments:<br>None.<br>Return value:<br>Process ID.|
|int64_t&nbsp;HiSysEventRecord::GetTid()|Obtains the thread ID of the process that flushes a system event to the disk.<br>Input arguments:<br>None.<br>Return value:<br>Thread ID.|
|int64_t&nbsp;HiSysEventRecord::GetUid()|Obtains the user ID of the process that flushes a system event to the disk.<br>Input arguments:<br>None.<br>Return value:<br>User ID.|
|uint64_t&nbsp;HiSysEventRecord::GetPspanId()|Obtains the parent span ID of the distributed call chain tracing task.<br>Input arguments:<br>None.<br>Return value:<br>Parent span ID of the distributed call chain tracing task.|
|uint64_t&nbsp;HiSysEventRecord::GetSpandId()|Obtains the span ID of the distributed call chain tracing task.<br>Input arguments:<br>None.<br>Return value:<br>Span ID of the distributed call chain tracing task.|
|uint64_t&nbsp;HiSysEventRecord::GetTime()|Obtains the timestamp of a system event.<br>Input arguments:<br>None.<br>Return value:<br>Timestamp.|
|uint64_t&nbsp;HiSysEventRecord::GetTraceId()|Obtains the ID of the distributed call chain tracing task.<br>Input arguments:<br>None.<br>Return value:<br>ID of the distributed call chain tracing task.|
|void&nbsp;HiSysEventRecord::GetParamNames(std::vector&lt;std::string&gt;&amp;&nbsp;params)|Obtains all key names of a system event.<br>Input arguments:<br>- **params**: key name array reference.<br>Return value:<br>None.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;int64_t&amp;&nbsp;value)|Parses the value of the **param** key in a system event into an int64\_t value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: int64\_t reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;uint64_t&amp;&nbsp;value)|Parses the value of the **param** key in a system event into a uint64\_t value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: uint64\_t reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;double&amp;&nbsp;value)|Parses the value of the **param** key in a system event into a double value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: double reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::string&amp; value)|Parses the value of the **param** key in a system event into a string value.<br>Input arguments:<br>- **param**: key name.<br>- **value**: std::string reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;int64_t&gt;&amp;&nbsp;value)|Parses the value of the **param** key in a system event into an int64\_t array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: int64\_t array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;uint64_t&gt;&amp;&nbsp;value)|Parses the value of the **param** key in a system event into a uint64\_t array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: uint64\_t array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;double&gt;&amp;&nbsp;value)|Parses the value of the **param** key in a system event into a double array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: double array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|
|int&nbsp;HiSysEventRecord::GetParamValue(const std::string&amp;&nbsp;param,&nbsp;std::vector&lt;std::string&gt;&amp;&nbsp;value)|Parses the value of the **param** key in a system event into a string array.<br>Input arguments:<br>- **param**: key name.<br>- **value**: std::string array reference.<br>Return value:<br>- **0**: Parsing is successful.<br>- **-1**: Parsing failed due to initialization error.<br>- **-2**: Parsing failed due to nonexistent key name.<br>- **-3**: Parsing failed due to type mismatch.|

#### C APIs

HiSysEvent listening is implemented using the API provided in the following table. For details, see the [API Header Files](/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent_manager/include/).

> **NOTE**
>
> For details about the **HiSysEventRecord** argument in the **OnEvent** callback of **HiSysEventWatcher**, see Table 11 and Table 12 in [HiSysEvent Query](subsys-dfx-hisysevent-query.md).

  **Table 5** Description of C HiSysEventManager APIs

| Name                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int OH_HiSysEvent_Add_Watcher(HiSysEventWatcher* watcher,<br>HiSysEventWatchRule rules[],<br>size_t ruleSize); | Adds a listener to listen for system events based on the specified rules.<br>Input arguments:<br>- **watcher**: watcher for system events.<br>- **rules**: array of event listening rules.<br>- **ruleSize**: length of the array of event listening rules.<br>Return value:<br>- **0**: The listener is added successfully.<br>- A negative value: The listener fails to be added.|
| int OH_HiSysEvent_Remove_Watcher(HiSysEventWatcher* watcher); | Remove the watcher for system events.<br>Input arguments:<br>- **watcher**: watcher for system events.<br>Return value:<br>- **0**: The watcher is removed successfully.<br>- A negative value: The watcher fails to be removed. |


  **Table 6** Description of the HiSysEventWatcher structure
| Field     | Type                                  | Description                                                        |
| ------------- | -------------------------------------------------- | ------------------------------------------------------------ |
| OnEvent       | void (*)(HiSysEventRecord record);        | Callback object for system events.<br>Input arguments:<br>- **record**: real-time system event.<br>Return value:<br>None.|
| OnServiceDied | void (*)();                                | Callback object for service exceptions.<br>Input arguments:<br>None.<br>Return value:<br>None. |

  **Table 7** Description of the HiSysEventWatchRule structure
| Field     | Type | Description                              |
| ------------- | --------- | ---------------------------------- |
| domain        | char[]    | Event domain.          |
| name          | char[]    | Event name.          |
| tag           | char[]    | Event tag.          |
| ruleType      | int       | Event matching rule. For details about the values, see Table 4 in [HiSysEvent Query](subsys-dfx-hisysevent-query.md).      |
| eventType     | int       | Event type. For details about the values, see Table 3 in [HiSysEvent Query](subsys-dfx-hisysevent-query.md). The value **0** indicates all event types.      |

### How to Develop

#### C++ HiSysEvent Listening

1. Import the corresponding header file.

    ```c++
    #include "hisysevent_manager.h"
    ```

2. Implement the callback API for the service domain.

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

3. Call the listening API while passing in parameters such as **listener** and **rules**. When the service ends, disable event listening.

    ```c++
    auto testListener = std::make_shared<TestListener>();
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
    // Start event listening.
    auto ret = HiSysEventManager::AddListener(testListener, sysRules);
    // Remove the listener when the service ends.
    if (ret == 0) {
       HiSysEventManager::RemoveListener(testListener);
    }
    ```

#### C HiSysEvent Listening

1. Import the corresponding header file.

    ```c++
    #include "hisysevent_manager_c.h"
    ```

2. Implement the callback API for the service domain.

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

3. Call the listening API while passing in parameters such as **watcher** and **rules**. When the service ends, disable event listening.

    ```c++
    HiSysEventWatcher watcher;
    watcher.OnEvent = OnEventTest;
    watcher.OnServiceDied = OnServiceDiedTest;
    // Add a HiSysEventWatchRule object based on the event tag, with RuleType left unspecified (in this case, ruleType is defaulted to WHOLE_WORD).
    constexpr char DFX_TAG[] = "dfx";
    HiSysEventWatchRule tagRule;
    (void)strcpy_s(tagRule.tag, strlen(DFX_TAG) + 1, DFX_TAG);
    tagRule.ruleType = 1;
    tagRule.eventType = 0;
    // Add a HiSysEventWatchRule object based on the event tag, with RuleType set as REGULAR.
    constexpr char DFX_PATTERN_TAG[] = "dfx.*";
    HiSysEventWatchRule regRule;
    (void)strcpy_s(regRule.tag, strlen(DFX_PATTERN_TAG) + 1, DFX_PATTERN_TAG);
    regRule.ruleType = 3;
    regRule.eventType = 0;
    // Add a HiSysEventWatchRule object based on the event domain and event name, with RuleType set as PREFIX.
    constexpr char DOMAIN[] = "HIVIEWDFX";
    constexpr char NAME[] = "APP_USAGE";
    HiSysEventWatchRule domainNameRule;
    (void)strcpy_s(domainNameRule.domain, strlen(DOMAIN) + 1, DOMAIN);
    (void)strcpy_s(domainNameRule.name, strlen(NAME) + 1, NAME);
    domainNameRule.ruleType = 2;
    domainNameRule.eventType = 0;
    // Start event listening.
    HiSysEventWatchRule rules[] = {tagRule, regRule, domainNameRule};
    int ret = OH_HiSysEvent_Add_Watcher(&watcher, rules, sizeof(rules) / sizeof(HiSysEventWatchRule));
    // Remove the watcher when the service ends.
    if (ret == 0) {
        ret = OH_HiSysEvent_Remove_Watcher(&watcher);
    }
    ```

### Development Examples

#### C++ HiSysEvent Listening

Suppose you want to enable listening for all events whose domain is **HIVIEWDFX** and name is **PLUGIN_LOAD**. The sample code is as follows:

1. Add the **libhisysevent** and **libhisyseventmanager** dependencies of the **hisysevent** component to the **BUILD.gn** file of the service module.

    ```c++
    external_deps = [
      "hisysevent:libhisysevent",
      "hisysevent:libhisyseventmanager",
    ]
    ```

2. Call the listening API in the **TestEventListening()** function. When the service ends, disable event listening.

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

#### C HiSysEvent Listening

Suppose you want to enable listening for all events whose domain is **HIVIEWDFX** and name is **PLUGIN_LOAD**. The sample code is as follows:

1. Add the **libhisysevent** and **libhisyseventmanager** dependencies of the **hisysevent** component to the **BUILD.gn** file of the service module.

    ```c++
    external_deps = [ "hisysevent:libhisyseventmanager" ]

    // for strcpy_s
    deps = [ "//third_party/bounds_checking_function:libsec_shared" ]
    ```

2. Call the listening API in the **TestEventListening()** function. When the service ends, disable event listening.

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
