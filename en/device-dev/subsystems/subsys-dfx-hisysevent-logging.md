# HiSysEvent Logging<a name="EN-US_TOPIC_0000001231373947"></a>

## Overview<a name="section77571101789"></a>

### Introduction<a name="section123133332175224"></a>

HiSysEvent provides event logging APIs for OpenHarmony to record important information of key processes during system running, helping you locate faults. In addition, you can upload the log data to the cloud for big data analytics.

### Constraints<a name="section123181432175224"></a>

Before logging system events, you need to configure HiSysEvent logging. For details, see [HiSysEvent Logging Configuration](subsys-dfx-hisysevent-logging-config.md).

## Development Guidelines<a name="section314416685113"></a>

### Available APIs<a name="section13480315886"></a>

The following table lists the C++ APIs provided by the HiSysEvent class.

For details about the HiSysEvent class, see the API reference.

**Table 1** C++ APIs provided by HiSysEvent

| API| Description|
| -------- | --------- |
| template&lt;typename... Types&gt; static int Write(const std::string &amp;domain, const std::string &amp;eventName, EventType type, Types... keyValues) | Logs system events. <br><br>Input arguments: <ul><li>**domain**: Indicates the domain related to the event. You can use a preconfigured domain or customize a domain as needed. The name of a custom domain can contain a maximum of 16 characters, including digits (0-9) and uppercase letters (A-Z). It must start with a letter. </li><li>**eventName**: Indicates the event name. The value contains a maximum of 32 characters, including digits (0 to 9), letters (A-Z), and underscores (&#95;). It must start with a letter and cannot end with an underscore. </li><li>**type**: Indicates the event type. For details, see EventType. </li><li>**keyValues**: Indicates the key-value pairs of event parameters. It can be in the format of the basic data type, std::string, std::vector&lt;basic data type&gt;, or std:vector&lt;std::string&gt;. The value contains a maximum of 48 characters, including digits (0 to 9), letters (A-Z), and underscores (&#95;). It must start with a letter and cannot end with an underscore. The number of parameter names cannot exceed 32. </li></ul>Return value: <ul><li>**0**: The logging is successful. </li><li>Negative value: The logging has failed.</li></ul> |

**Table 2** Description of HiSysEvent::Domain APIs

| API| Description|
| -------- | --------- |
| static const std::string AAFWK | Atomic ability subsystem|
| static const std::string APPEXECFWK | User program framework subsystem|
| static const std::string ACCOUNT | Account subsystem|
| static const std::string ARKUI | ARKUI subsystem|
| static const std::string AI | AI subsystem|
| static const std::string BARRIER_FREE | Accessibility subsystem|
| static const std::string BIOMETRICS | Biometric recognition subsystem|
| static const std::string CCRUNTIME |C/C++ operating environment subsystem|
| static const std::string COMMUNICATION | Public communication subsystem|
| static const std::string DEVELOPTOOLS | Development toolchain subsystem|
| static const std::string DISTRIBUTED_DATAMGR | Distributed data management subsystem|
| static const std::string DISTRIBUTED_SCHEDULE | Distributed Scheduler subsystem|
| static const std::string GLOBAL | Globalization subsystem|
| static const std::string GRAPHIC | Graphics subsystem|
| static const std::string HIVIEWDFX | DFX subsystem|
| static const std::string IAWARE | Scheduling and resource management subsystem|
| static const std::string INTELLI_ACCESSORIES | Smart accessory subsystem|
| static const std::string INTELLI_TV | Smart TV subsystem|
| static const std::string IVI_HARDWARE | IVI-dedicated hardware subsystem|
| static const std::string LOCATION | LBS subsystem|
| static const std::string MSDP | MSDP subsystem|
| static const std::string MULTI_MEDIA | Media subsystem|
| static const std::string MULTI_MODAL_INPUT | Multimode input subsystem|
| static const std::string NOTIFICATION | Common event and notification subsystem|
| static const std::string POWERMGR | Power management subsystem|
| static const std::string ROUTER | Router subsystem|
| static const std::string SECURITY | Security subsystem|
| static const std::string SENSORS | Pan-sensor subsystem|
| static const std::string SOURCE_CODE_TRANSFORMER | Application porting subsystem|
| static const std::string STARTUP | Startup subsystem|
| static const std::string TELEPHONY | Telephony subsystem|
| static const std::string UPDATE | Update subsystem|
| static const std::string USB | USB subsystem|
| static const std::string WEARABLE_HARDWARE | Wearable-dedicated hardware subsystem|
| static const std::string WEARABLE_HARDWARE | Wearable-dedicated service subsystem|
| static const std::string OTHERS | Others|

**Table 3** Description of HiSysEvent::EventType

| Name| Description|
| -------- | --------- |
| FAULT | Fault event|
| STATISTIC | Statistical event|
| SECURITY | Security event|
| BEHAVIOR | System behavior event|

### Development Example<a name="section112771171317"></a>

C++

1.  Develop the source code.

    Include the HiSysEvent header file in the class definition header file or class implementation source file. For example:

    ```
    #include "hisysevent.h"
    ```

    Add the event logging code. For example, if you want to log events specific to the app start time (start\_app), then add the following code to the service implementation source file:

    ```
    HiSysEvent::Write(HiSysEvent::Domain::AAFWK, "start_app", HiSysEvent::EventType::FAULT, "app_name", "com.demo");
    ```

2.  Configure compilation information. Specifically, add the subsystem SDK dependency to **BUILD.gn**.

    ```
    external_deps = [ "hisysevent_native:libhisysevent" ]
    ```
