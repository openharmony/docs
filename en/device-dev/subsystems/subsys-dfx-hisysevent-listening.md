# HiSysEvent Listening<a name="EN-US_TOPIC_0000001185655868"></a>

## Overview<a name="section315316685112"></a>

### Introduction<a name="section123181433335224"></a>

HiSysEvent supports listening for events across processes. You can register a listener to listen for concerned events on a real-time basis. For example, you can enable the battery module to listen for power consumption events for power usage analysis.

### Constraints<a name="section123181433375224"></a>

Before subscribing to system events, you need to configure HiSysEvent logging. For details, see [HiSysEvent Logging Configuration](subsys-dfx-hisysevent-logging-config.md).

## Development Guidelines<a name="section315316685113"></a>

### Available APIs<a name="section0342191810519"></a>

**Table 1** Description of EventListener APIs

| Name| Description |
| -------- | --------- |
|int32_t HiSysEventManager::AddEventListener(std::shared_ptr&lt;HiSysEventSubscribeCallBack&gt; listener, std::vector&lt;ListenerRule&gt;&amp; rules)|Registers a listener for system events. You can listen for certain events by specifying rules.<br><br>Input arguments: <ul><li>**listener**: callback object for system events. </li><li>**rules**: rules for event listening. </li></ul>Return value:<ul><li>**0**: registration is successful. </li><li>Other values: Registration has failed.</li></ul>|
|int32_t HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventSubscribeCallBack&gt; listener)|Removes the listener for system events.<br><br>Input arguments: <ul><li>**listener**: callback object for system events. </ul>Return value:<ul><li>**0**: Cancel registration is successful. </li><li>Other values: Cancel registration has failed.</li></ul>|

**Table 2** Description of ListenerRule

| API| Description |
| -------- | --------- |
|ListenerRule(const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD)|Constructor used to create a **ListenerRule** object based on the event tag.<br><br>Input arguments:<ul><li>**tag**: indicates the event tag for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, lowercase letters, and digits. </li><li>**ruleType**: indicates the type of the **ListenerRule** object. The value is an enum defined by **RuleType**.</li></ul>|
|ListenerRule(const std::string&amp; domain, const std::string&amp; eventName, RuleType ruleType = RuleType::WHOLE_WORD)|Constructor used to create a **ListenerRule** object based on the event domain and event name.<br><br>Input arguments: <ul><li>**domain**: indicates the event domain for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, digits, and underscores (&#95;). </li><li>**eventName**: indicates the event name for the **ListenerRule** object. The value is a string of 1 to 32 characters, including uppercase letters, digits, and underscores (&#95;). </li><li>**ruleType**: indicates the type of the **ListenerRule** object. The value is an enum defined by **RuleType**.</li></ul>|
|ListenerRule(const std::string&amp; domain, const std::string& eventName, const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD)|Constructor used to create a **ListenerRule** object based on the event domain, event name, and event tag.<br><br>Input arguments:<ul><li>**tag**: indicates the event tag for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, lowercase letters, and digits. </li><li>**domain**: indicates the event domain for the **ListenerRule** object. The value is a string of 1 to 16 characters, including uppercase letters, digits, and underscores (&#95;). </li><li>**eventName**: indicates the event name for the **ListenerRule** object. The value is a string of 1 to 32 characters, including uppercase letters, digits, and underscores (&#95;). </li><li>**ruleType**: indicates the type of the **ListenerRule** object. The value is an enum defined by **RuleType**.</li></ul>|

**Table 3** Description of RuleType

| Value      | Description         |
| ------------ | ------------- |
| WHOLE_WORD   | Whole word matching |
| PREFIX       | Prefix matching |
| REGULAR      | Regular expression matching |

**Table 4** Description of HiSysEventSubscribeCallBack

| API| Description |
| -------- | --------- |
|void HiSysEventSubscribeCallBack::OnHandle(const std::string&amp; domain, const std::string&amp; eventName, const int eventType, const std::string&amp; eventDetail)|Provides the callback of system events.<br><br>Input arguments: <ul><li>**domain**: indicates the domain to which the event belongs. </li><li>**eventName**: indicates the event name. </li><li>**eventType**: indicates the event type. </li><li>**eventDetail**: indicates the event information, in JSON format. </li></ul>Return value:<br>None.|

### Development Example<a name="section123181432175110"></a>

C++

1.  Develop the source code.

    Import the **DemoListener.h** header file, which contains the **DemoListener** class for implementing the custom event callback.

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

    Create the **DemoListener.cpp** file, and add the implementation logic of the custom event callback API in the **DemoListener** class.

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

    Call the **AddEventListener** API of the **HiSysEventManager** class to add a listener for system events.

    ```
    std::shared_ptr<DemoListener> demoListener = nullptr;
    try {
        demoListener = std::make_shared<DemoListener>();
    } catch(...) {
        // Catch exception thrown by make_shared
    }
    if (demoListener != nullptr) {
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
    }
    ```

2.  Configure the **BUILD.gn** file.

    In the **BUILD.gn** file, add the **libhisyseventmanager** library that depends on the **hisysevent\_native** component.

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager", ]
    ```
