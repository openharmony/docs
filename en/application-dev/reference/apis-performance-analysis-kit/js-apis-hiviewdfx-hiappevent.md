# @ohos.hiviewdfx.hiAppEvent (Application Event Logging)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

This module provides application logging and event subscription capabilities, including event storage, event subscription, event clearance, and logging configuration. HiAppEvent records the events triggered during application running in [AppEventInfo](#appeventinfo), and classifies the events into system events and application events.

System events are triggered in system services and are predefined in the system. The fields of the event parameter object **params** of such events are defined by each system event. For details, see overviews of user guides. For example, [Crash Event Overview](../../dfx/hiappevent-watcher-crash-events.md).

Application events are defined by application developers and can be customized using the [Write](#hiappeventwrite-1) API as required.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
```


## hiAppEvent.addWatcher

addWatcher(watcher: Watcher): AppEventPackageHolder

Adds an event watcher. You can use the callback of the event watcher to subscribe to events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | Yes  | Event watcher.|

**Return value**

| Type                                            | Description                                |
| ------------------------------------------------ | ------------------------------------ |
| [AppEventPackageHolder](#appeventpackageholder) | Subscription data holder. If the subscription fails, **null** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11102001 | Invalid watcher name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11102002 | Invalid filtering event domain. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11102003 | Invalid row value. Possible caused by the row value is less than zero. |
| 11102004 | Invalid size value. Possible caused by the size value is less than zero. |
| 11102005 | Invalid timeout value. Possible caused by the timeout value is less than zero. |

> **NOTE**
>
> The **addWatcher** API involves I/O operations. In performance-sensitive service scenarios, you need to determine whether to call this API in the main thread or a child thread based on the actual service requirements.
>
> To call **addWatcher** in a child thread, ensure that the child thread is not destroyed in the entire API usage period.
>
> For details about how to call the API in a child thread, see [Worker](../../arkts-utils/worker-introduction.md).
>
> The name passed to the **addWatcher** API should be unique. If the same name is passed, the previous subscription will be overwritten.

**Example**

Based on the type of the event watcher, the following methods are available:

Method 1: Set **triggerCondition** to implement the **onTrigger()** callback. When the callback conditions are met, the system automatically triggers the callback.
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.addWatcher({
  name: "watcher1",
  // Subscription filters. The application crash event in the system event domain is subscribed.
  appEventFilters: [
    {
      domain: hiAppEvent.domain.OS,
      names: [hiAppEvent.event.APP_CRASH]
    }
  ],
  // Set the condition for triggering the onTrigger callback. The callback is triggered when the total number of events reaches 10, the total event size reaches 1000 bytes, or the event lasts for more than 30s.
  triggerCondition: {
    row: 10,
    size: 1000,
    timeOut: 1
  },
  // Implement the onTrigger callback with triggerCondition. When the callback condition is met, the callback is triggered. After the callback notification is received, use takeNext() to query the subscribed event.
  onTrigger: (curRow: number, curSize: number, holder: hiAppEvent.AppEventPackageHolder) => {
    if (holder == null) {
      hilog.error(0x0000, 'hiAppEvent', "holder is null");
      return;
    }
    hilog.info(0x0000, 'hiAppEvent', `curRow=${curRow}, curSize=${curSize}`);
    let eventPkg: hiAppEvent.AppEventPackage | null = null;
    while ((eventPkg = holder.takeNext()) != null) {
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.packageId=${eventPkg.packageId}`);
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.row=${eventPkg.row}`);
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.size=${eventPkg.size}`);
      for (const eventInfo of eventPkg.data) {
        hilog.info(0x0000, 'hiAppEvent', `eventPkg.data=${eventInfo}`);
      }
    }
  }
});
```

Method 2: If the **triggerCondition** parameter is not set, use the **holder** object returned by the event subscription to obtain the subscribed event.

For crash events (**hiAppEvent.event.APP_CRASH**) and freeze events (**hiAppEvent.event.APP_FREEZE**) generated during abnormal exits, the system needs time to capture debug logs. Typically, capture completes within 30 seconds; in extreme cases, it may take up to about 2 minutes.

When the subscription data holder is used to manually process subscription events, the events may not be generated or the log capture is not complete. Therefore, you are advised to call **takeNext()** to obtain such events again after the process is started.

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

let holder: hiAppEvent.AppEventPackageHolder = hiAppEvent.addWatcher({
  name: "watcher2",
  // Subscription filters. The application crash event in the system event domain is subscribed.
  appEventFilters: [
    {
      domain: hiAppEvent.domain.OS,
      names: [hiAppEvent.event.APP_CRASH]
    }
  ],
});
// Obtain crash events through the subscription data holder.
if (holder != null) {
  let eventPkg: hiAppEvent.AppEventPackage | null = null;
  while ((eventPkg = holder.takeNext()) != null) {
    hilog.info(0x0000, 'hiAppEvent', `eventPkg.packageId=${eventPkg.packageId}`);
    hilog.info(0x0000, 'hiAppEvent', `eventPkg.row=${eventPkg.row}`);
    hilog.info(0x0000, 'hiAppEvent', `eventPkg.size=${eventPkg.size}`);
    for (const eventInfo of eventPkg.data) {
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.data=${eventInfo}`);
    }
  }
}
```

Method 3: Implement the **onReceive()** callback, which is triggered in real time when the subscribed event occurs.

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.addWatcher({
  name: "watcher3",
  // Subscription filters. The application crash event in the system event domain is subscribed.
  appEventFilters: [
    {
      domain: hiAppEvent.domain.OS,
      names: [hiAppEvent.event.APP_CRASH]
    }
  ],
  // Implement the onReceive callback, which is called in real time after an event is detected.
  onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
    hilog.info(0x0000, 'hiAppEvent', `domain=${domain}`);
    for (const eventGroup of appEventGroups) {
      hilog.info(0x0000, 'hiAppEvent', `eventName=${eventGroup.name}`);
      for (const eventInfo of eventGroup.appEventInfos) {
        hilog.info(0x0000, 'hiAppEvent', `event=${JSON.stringify(eventInfo)}`);
      }
    }
  }
});
```


## hiAppEvent.removeWatcher

removeWatcher(watcher: Watcher): void

Removes an event watcher.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | Yes  | Event watcher.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message             |
| -------- | --------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11102001 | Invalid watcher name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |

**Example**

```ts
// 1. Define an event watcher.
let watcher: hiAppEvent.Watcher = {
  name: "watcher1",
}

// 2. Add an event watcher to subscribe to events.
hiAppEvent.addWatcher(watcher);

// 3. Remove the event watcher to unsubscribe from events.
hiAppEvent.removeWatcher(watcher);
```


## hiAppEvent.setEventParam<sup>12+</sup>

setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt;

Sets custom event parameters. This API uses a promise to return the result. During the same lifecycle, system events and application events can be associated through event domain and event name.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| params | Record&lt;string, [ParamType](#paramtype12)&gt; | Yes| Custom parameter object. The parameter name and value are defined as follows:<br>- A parameter name is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.  <br>- The parameter value is of the [ParamType](#paramtype12) and contains a maximum of 1024 characters.<br>- The number of parameters must be less than 64.|
| domain | string                        | Yes| Event domain. The event domain can be associated with application events and system events (hiAppEvent.domain.OS).|
| name   | string                        | No| Event name. The default value is an empty string, which indicates all event names in the associated event domain. Event names can be used to associate application events and system events. System events can only be associated with the following events:<br>- [Crash event](../../dfx/hiappevent-watcher-crash-events.md) (**hiAppEvent.event.APP_CRASH**)<br>- [Application freeze event](../../dfx/hiappevent-watcher-freeze-events.md) (**hiAppEvent.event.APP_FREEZE**)<br>- [Resource leak event](../../dfx/hiappevent-watcher-resourceleak-events.md) (**hiAppEvent.event.RESOURCE_OVERLIMIT**).<br>**Note**: Since API version 20, the [resource leak event](../../dfx/hiappevent-watcher-resourceleak-events.md) is supported.|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled. Possible caused by the param disable in ConfigOption is true. |
| 11101001 | Invalid event domain. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101002 | Invalid event name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101007 | The number of parameter keys exceeds the limit. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "int_data": 100,
  "str_data": "strValue",
};

// Add custom parameters to the application event.
hiAppEvent.setEventParam(params, "test_domain", "test_event").then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event param`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```


## hiAppEvent.setEventConfig<sup>15+</sup>

setEventConfig(name: string, config: Record&lt;string, ParamType&gt;): Promise&lt;void&gt;

Sets event configuration. This method uses a promise to return the result. In the same lifecycle, you can set event configuration by event name.<br>Configuration items vary depending on events. Currently, only the following events are supported:
- **MAIN_THREAD_JANK** (For details about the parameter configuration, see [Main Thread Jank Event Overview](../../dfx/hiappevent-watcher-mainthreadjank-events.md#parameters-of-seteventconfig).)
- **APP_CRASH** (For details about the parameter configuration, see [Crash Log Configuration Parameters](../../dfx/hiappevent-watcher-crash-events.md#customizing-specifications).)
- **RESOURCE_OVERLIMIT** (For details about the parameter configuration, see [Resource Leak Event Overview](../../dfx/hiappevent-watcher-resourceleak-events.md#customizing-specifications).)

 > **NOTE**
 >
 > Since API version 26.0.0, all settings of this API are supported by [configEventPolicy](#hiappeventconfigeventpolicy22). You are advised to use [configEventPolicy](#hiappeventconfigeventpolicy22).

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| name   | string                        | Yes| Event name.|
| config | Record<string, [ParamType](#paramtype12)> | Yes| Custom parameter object. The parameter name and value are defined as follows:<br>- The parameter name contains a maximum of 1024 characters, which is of the string type and cannot be empty.<br>- The parameter value is of the ParamType and contains a maximum of 1024 characters.|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |

**Example**

The following example sets the collection stack parameters of the **MAIN_THREAD_JANK** event:

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "1",
  "sample_interval": "100",
  "ignore_startup_time": "11",
  "sample_count": "21",
  "report_times_per_app": "3"
};
hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `Successfully set sampling stack parameters.`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `Failed to set sample stack value. Code: ${err.code}, message: ${err.message}`);
});
```


## hiAppEvent.configEventPolicy<sup>22+</sup>

configEventPolicy(policy: EventPolicy): Promise&lt;void&gt;

Sets a system event configuration policy. This API uses a promise to return the result.

In the same lifecycle, you can set system event configuration by policy.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ---------------------------- | ---- | -------------- |
| policy | [EventPolicy](#eventpolicy22)  | Yes  | System event configuration policy.|

**Return value**

| Type               | Description         |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise that returns no value.<br>For details about the event configuration policy, see [EventPolicy](#eventpolicy22). If the configuration policy is incorrect, the API returns a failure message.<br>- If the parameter type is incorrect, error code 401 is returned.<br>- If the parameter specifications are incorrect, the error information is output in HiLog logs.|

**Example**

The following example shows how to configure a policy for the **MAIN_THREAD_JANK** event:

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
  mainThreadJankPolicy:{
    logType: 1,
    sampleInterval: 100,
    ignoreStartupTime: 11,
    sampleCount: 21,
    reportTimesPerApp: 3,
    autoStopSampling: true
  }
};
hiAppEvent.configEventPolicy(policy).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `Successfully set main thread jank event policy.`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `Failed to set main thread jank event policy. Code: ${err?.code}, message: ${err?.message}`);
});
```

## Watcher

Defines parameters for a **Watcher** object. This API is used to configure and manage event watchers to subscribe to and process specified events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name            | Type                                               |  Read Only | Optional| Description                                                        |
| ---------------- | ----------------------------------------------------|------ | ---- | ------------------------------------------------------------ |
| name             | string                                              |  No  | No  | Unique name of a watcher. The value contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), and underscore (_). It must start with a letter and end with a digit or letter. For example, **testName1** and **crash_Watcher**.                            |
| triggerCondition | [TriggerCondition](#triggercondition)               |  No  | Yes  | Subscription callback triggering condition. This parameter takes effect only when it is passed together with **onTrigger**. If this parameter is not set, the **onTrigger** callback is not triggered by default.          |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                 |  No  | Yes  | Subscription filtering condition. This parameter is passed only when subscription events need to be filtered. If this parameter is not set, events are not filtered by default.              |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void |  No  | Yes  | Subscription callback. This parameter takes effect only when it is passed together with **triggerCondition**. The input arguments are described as follows:<br>**curRow**: total number of subscription events when the callback is triggered.<br>**curSize**: total size of subscribed events when the callback is triggered, in bytes.<br>**holder**: subscription data holder, which can be used to process subscribed events.|
| onReceive<sup>11+</sup>        | (domain: string, appEventGroups: Array<[AppEventGroup](#appeventgroup11)>) => void |  No  | Yes| Real-time subscription callback. Only this callback function is triggered if it is passed together with **onTrigger**. The input arguments are described as follows:<br>domain: domain name.<br>appEventGroups: event group.|

> **NOTE**
>
> You are not advised to call [removeWatcher](#hiappeventremovewatcher) in the callback. Once a watcher is removed, the subscription callback of the watcher becomes invalid, and the callback may not be triggered when an event occurs.

## TriggerCondition

Defines the triggering condition parameters of the **onTrigger** callback of a [Watcher](#watcher).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name   | Type  | Read Only| Optional| Description                                  |
| ------- | ------ | ---- | ---- | -------------------------------------- |
| row     | number | No| Yes  | Total number of events that trigger callback. The value is a positive integer. The default value is 0, indicating that no callback is triggered. If this parameter is set to a negative value, the default value is used.            |
| size    | number | No| Yes  | Total size of events that trigger callback. The value is a positive integer, in bytes. The default value is 0, indicating that no callback is triggered. If this parameter is set to a negative value, the default value is used.|
| timeOut | number | No| Yes  | Timeout interval for triggering callback. The value is a positive integer, in unit of 30s. The default value is 0, indicating that no callback is triggered. If this parameter is set to a negative value, the default value is used.   |


## AppEventFilter

Defines parameters of subscription filtering conditions of a [Watcher](#watcher). This API is used to set event filtering conditions in the event watcher to ensure that only the events that meet the filtering conditions are subscribed to.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type                     | Read Only| Optional| Description                    |
| ---------- | ------------------------- | ---- | ---- | ------------------------ |
| domain     | string                    | No| No  | Event domain, which can be the system event domain (**hiAppEvent.domain.OS**) or the event domain of the custom event information ([AppEventInfo](#appeventinfo)) passed through the [Write](#hiappeventwrite-1) API.    |
| eventTypes | [EventType](#eventtype)[] | No| Yes  | Event types. If this parameter is not set, events are not filtered by default.|
| names<sup>11+</sup>      | string[]                  | No| Yes  | Names of the events to be subscribed. If this parameter is not set, events are not filtered by default.|

> **NOTE**
>
> The subscription specifications of system events vary according to application types. For details, see [HiAppEvent Constraints](../../dfx/hiappevent-intro.md#constraints).


## AppEventPackageHolder

Defines a subscription data holder for processing event information.

### constructor

constructor(watcherName: string)

Constructs an **AppEventPackageHolder** instance. You can call [addWatcher](#hiappeventaddwatcher) to add an event watcher, and then associate the **AppEventPackageHolder** instance with the watcher added in the application based on the watcher name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type             | Mandatory| Description                    |
| ------ | ----------------- | ---- | ------------------------ |
| watcherName | string | Yes  | Name of the event watcher added through [addWatcher](#hiappeventaddwatcher). If no watcher is added, no data is displayed by default.|

**Example**

```ts
// Add the Watcher1 to subscribe to system events.
hiAppEvent.addWatcher({
  name: "Watcher1",
  appEventFilters: [
    {
      domain: hiAppEvent.domain.OS,
    }
  ],
});

// Create an AppEventPackageHolder instance. holder1 holds the event data subscribed by Watcher1 added through addWatcher.
let holder1: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("Watcher1");
```

### setSize

setSize(size: number): void

Sets the threshold for the data size of the event package obtained each time.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | Yes  | Data size threshold, in bytes. The value range is [0, 2^31-1]. If the value is out of the range, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message           |
| -------- | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11104001 | Invalid size value. Possible caused by the size value is less than or equal to zero. |

**Example**

```ts
// Create an AppEventPackageHolder instance. holder2 holds the event data subscribed by Watcher1 added through addWatcher.
let holder2: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("Watcher1");
// Set the data size threshold for obtaining the event package each time to 1000 bytes.
holder2.setSize(1000);
```

### setRow<sup>12+</sup>

setRow(size: number): void

Sets the number of data records of the event package obtained each time. When **setRow()** and **setSize()** are called at the same time, only **setRow()** takes effect.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | Yes  | Number of events. The value range is (0, 2^31-1]. If the value is out of the range, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message           |
| -------- | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11104001 | Invalid size value. Possible caused by the size value is less than or equal to zero. |

**Example**

```ts
// Create an AppEventPackageHolder instance. holder3 holds the event data subscribed by Watcher1 added through addWatcher.
let holder3: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("Watcher1");
// Set the number of data records for obtaining the event package each time to 1000.
holder3.setRow(1000);
```

### takeNext

takeNext(): AppEventPackage

Obtains the subscription event.

The system obtains the subscription event data based on the data size threshold specified by **setSize** or the number of data records specified by **setRow**. By default, one subscription event data record is obtained. When all subscription event data is obtained, **null** is returned.

When **setRow** and **setSize** are called at the same time, only **setRow** takes effect.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Return value**

| Type                               | Description                                                  |
| ----------------------------------- | ------------------------------------------------------ |
| [AppEventPackage](#appeventpackage) | Event package object. If all subscription event data has been retrieved, **null** is returned.|

**Example**

```ts
// Create an AppEventPackageHolder instance. holder4 holds the event data subscribed by Watcher1 added through addWatcher.
let holder4: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("Watcher1");
// Obtain the subscribed event.
let eventPkg: hiAppEvent.AppEventPackage | null = holder4.takeNext();
```


## AppEventInfo

Defines parameters of the event information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type                   | Read Only| Optional| Description                                                        |
| --------- | ----------------------- | ---- | ---- | ------------------------------------------------------------ |
| domain    | string                  | No| No  | Event domain. The value is a string of up to 32 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (\_).|
| name      | string                  | No| No  | Event name. The value is string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.|
| eventType | [EventType](#eventtype) | No| No  | Event type.                                                  |
| params    | object                  | No| No  | Event parameter object, which consists of a parameter name and a parameter value. In system events, the fields contained in **params** are defined by system. For details about the fields, you can see the overviews of system events, for example, [Crash Event Overview](../../dfx/hiappevent-watcher-crash-events.md). For application events, you need to define the parameters of the [Write](#hiappeventwrite-1) API. The specifications are as follows:<br>- A parameter name is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter. For example, **testName** and **\$123_name**.<br>- The parameter value can be a string, number, boolean, or array. The string type parameter can contain a maximum of 8 × 1024 characters. If the length exceeds the limit, the parameter and its name will be discarded. The value of the number type parameter must be within the range of **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. If the value exceeds the range, an uncertain value may be generated. The element type in the array type parameter can only be string, number, or boolean. The number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.<br>- The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.|


## AppEventPackage

Defines parameters of an **AppEventPackage** object. This API is used to obtain detail information about an event package, which is obtained using the [takeNext](#takenext) API.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type    | Read Only| Optional| Description                          |
| --------- | -------- | ---- | ---- | ------------------------------ |
| packageId | number   | No| No  | Event package ID, which is named from **0** in ascending order.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.   |
| row       | number   | No| No  | Number of events in the event package.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.            |
| size      | number   | No| No  | Event size of the event package, in bytes.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.|
| data      | string[] | No| No  | Event data in the event package.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.            |
| appEventInfos<sup>12+</sup> | Array<[AppEventInfo](#appeventinfo)> | No| No  | Event object group.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|


## AppEventGroup<sup>11+</sup>

Defines parameters of the event group returned by the subscription. This API can be used to obtain detail information about an event group, which is often used in the **onReceive** callback of [Watcher](#watcher).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name         | Type                           | Read Only| Optional | Description         |
| ------------- | ------------------------------- | ---- | ---- | ------------- |
| name          | string                          | No| No  | Event name.    |
| appEventInfos | Array<[AppEventInfo](#appeventinfo)> | No| No  | Event object group.|


## hiAppEvent.write

write(info: AppEventInfo, callback: AsyncCallback&lt;void&gt;): void

Writes events of the **AppEventInfo** type. This API uses an asynchronous callback to return the result. The event object written by calling this API is a custom object. To avoid conflicts with system events, you are not advised to write it to system events (system event name constants defined in [Event](#hiappeventevent)). The events written by this API can be subscribed to through ([addWatcher](#hiappeventaddwatcher)).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name  | Type                          | Mandatory| Description          |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo) | Yes  | Application event object. You are advised to avoid the conflict between the custom event name and the system event name constant defined in [Event](#hiappeventevent).|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled. Possible caused by the param disable in ConfigOption is true. |
| 11101001 | Invalid event domain. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101002 | Invalid event name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101003 | Invalid number of event parameters. Possible caused by the number of parameters is over 32. |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101006 | Invalid array length of the event parameter. |

> **NOTE**
>
> The **write** API involves I/O operations, and the execution time is usually at the millisecond level. Therefore, you need to determine whether to call this API in the main thread or a child thread based on the actual service requirements.
>
> For details about how to call an API in a child thread, see [Overview of Multithreaded Concurrency](../../arkts-utils/multi-thread-concurrency-overview.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};

// Application event logging. This API uses an asynchronous callback to return the result.
hiAppEvent.write({
  domain: "test_domain",
  name: "test_event",
  eventType: hiAppEvent.EventType.FAULT,
  params: eventParams,
}, (err: BusinessError) => {
  if (err) {
    hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
    return;
  }
  hilog.info(0x0000, 'hiAppEvent', `success to write event`);
});
```


## hiAppEvent.write

write(info: AppEventInfo): Promise&lt;void&gt;

Writes events of the **AppEventInfo** type. This API uses a promise to return the result. The event object written by calling this API is a custom object. To avoid conflicts with system events, you are not advised to write it to system events (system event name constants defined in [Event](#hiappeventevent)). The events written by this API can be subscribed to through ([addWatcher](#hiappeventaddwatcher)).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| info   | [AppEventInfo](#appeventinfo) | Yes  | Application event object. You are advised to avoid the conflict between the custom event name and the system event name constant defined in [Event](#hiappeventevent).|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled. Possible caused by the param disable in ConfigOption is true. |
| 11101001 | Invalid event domain. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101002 | Invalid event name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101003 | Invalid number of event parameters. Possible caused by the number of parameters is over 32. |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name. Possible causes: 1. Contain invalid characters; 2. Length is invalid. |
| 11101006 | Invalid array length of the event parameter. |

> **NOTE**
>
> The **write** API involves I/O operations, and the execution time is usually at the millisecond level. Therefore, you need to determine whether to call this API in the main thread or a child thread based on the actual service requirements.
>
> For details about how to call an API in a child thread, see [Overview of Multithreaded Concurrency](../../arkts-utils/multi-thread-concurrency-overview.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};

// Application event logging. This API uses a promise to return the result.
hiAppEvent.write({
  domain: "test_domain",
  name: "test_event",
  eventType: hiAppEvent.EventType.FAULT,
  params: eventParams,
}).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to write event`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```


## hiAppEvent.addProcessor<sup>11+</sup>

addProcessor(processor: Processor): number

Adds the configuration information of the data processor, such as the event name received by it.  

This is a synchronous API and involves time-consuming operations. To ensure performance, you are advised to use the asynchronous API [addProcessorFromConfig](#hiappeventaddprocessorfromconfig20) or use a child thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type       | Mandatory| Description             |
| ---------  | ---------- | ---- | -------------    |
| processor  | [Processor](#processor11)  | Yes  | Data processor.|

**Return value**

| Type   | Description                  |
| ------ | ---------------------- |
| number | ID of the data processor of the reported event, which uniquely identifies the data processor and can be used to remove the data processor. If the operation fails, **-1** is returned. If the operation is successful, a value greater than **0** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let processor: hiAppEvent.Processor = {
    name: 'analytics_demo'
  };
  let id: number = hiAppEvent.addProcessor(processor);
  hilog.info(0x0000, 'hiAppEvent', `addProcessor event was successful, id=${id}`);
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to addProcessor event, code=${error.code}`);
}
```


## hiAppEvent.addProcessorFromConfig<sup>20+</sup>

addProcessorFromConfig(processorName: string, configName?: string): Promise&lt;number&gt;

<!--RP1-->

Adds the configuration information of the data processor. The configuration file contains information such as the name of the event received by the data processor. This API uses a promise to return the result.
<!--RP1End-->

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type       | Mandatory| Description             |
| ---------  | ---------- | ---- | -------------    |
| processorName  |  string  | Yes  | <!--RP2-->Name of a data processor. It can contain only letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit and cannot exceed 256 characters.<!--RP2End-->|
| configName  |  string  | No  | <!--RP3-->Name of the data processor configuration. The corresponding configuration can be loaded from the configuration file. The default value is **SDK_OCG**. It can contain only letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit and cannot exceed 256 characters.<!--RP3End-->|

**Return value**

| Type   | Description                  |
| ------ | ---------------------- |
| Promise&lt;number&gt; |  Promise that returns the unique ID of the added event data processor, which can be used to remove the data processor. If the adding fails, error code **11105001** is returned.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message         |
| ------- | ----------------- |
| 11105001     | Invalid parameter value. Possible causes: 1. Incorrect parameter length; 2. Incorrect parameter format. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.addProcessorFromConfig("test_name").then((processorId) => {
  hilog.info(0x0000, 'hiAppEvent', `Succeeded in adding processor from config, processorId=${processorId}`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `Failed to add processor from config, code: ${err.code}, message: ${err.message}`);
});
```


## hiAppEvent.removeProcessor<sup>11+</sup>

removeProcessor(id: number): void

Removes the data processor of a reported event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type   | Mandatory| Description                        |
| ------| ------- | ---- | --------------------------- |
| id    | number  | Yes  | ID of a data processor. The value must be greater than **0**. The value is obtained by calling [addProcessor](#hiappeventaddprocessor11) or [addProcessorFromConfig](#hiappeventaddprocessorfromconfig20).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let processor: hiAppEvent.Processor = {
    name: 'analytics_demo'
  };
  let id: number = hiAppEvent.addProcessor(processor);
  // Remove a specified data processor based on the ID returned after the data processor is added.
  hiAppEvent.removeProcessor(id);
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to removeProcessor event, code=${error.code}`);
}
```


## hiAppEvent.setUserId<sup>11+</sup>

setUserId(name: string, value: string): void

Sets a user ID, which is used for association when a [Processor](#processor11) is configured.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------  |
| name      | string                    | Yes  | Key of a user ID. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit.  |
| value     | string                    | Yes  | Value of a user ID. It can contain a maximum of 256 characters. If the value is **null** or left empty, the user ID is cleared.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  hiAppEvent.setUserId('key', 'value');
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to setUserId event, code=${error.code}`);
}
```


## hiAppEvent.getUserId<sup>11+</sup>

getUserId(name: string): string

Obtains the value set through **setUserId**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                   | Mandatory| Description        |
| --------- | ----------------------- | ---- | ----------  |
| name      | string                  | Yes  | Key of a user ID. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit.|

**Return value**

| Type   | Description                           |
| ------ | ------------------------------- |
| string | Value of a user ID. If no user ID is found, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.setUserId('key', 'value');
try {
  let value: string = hiAppEvent.getUserId('key');
  hilog.info(0x0000, 'hiAppEvent', `getUserId event was successful, userId=${value}`);
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to getUserId event, code=${error.code}`);
}
```


## hiAppEvent.setUserProperty<sup>11+</sup>

setUserProperty(name: string, value: string): void

Sets a user property, which is used for association when a [Processor](#processor11) is configured.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| name      | string                    | Yes  | Key of a user property. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit. |
| value     | string                    | Yes  | Value of a user property. It can contain a maximum of 1024 characters. If the value is **null** or left empty, the user property is cleared. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  hiAppEvent.setUserProperty('key', 'value');
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to setUserProperty event, code=${error.code}`);
}
```


## hiAppEvent.getUserProperty<sup>11+</sup>

getUserProperty(name: string): string

Obtains the value set through **setUserProperty**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                   | Mandatory| Description         |
| --------- | ----------------------- | ---- | ----------    |
| name      | string                  | Yes  | Key of a user property. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit.|

**Return value**

| Type   | Description                            |
| ------ | -------------------------------- |
| string | Value of a user property. If no user ID is found, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.setUserProperty('key', 'value');
try {
  let value: string = hiAppEvent.getUserProperty('key');
  hilog.info(0x0000, 'hiAppEvent', `getUserProperty event was successful, userProperty=${value}`);
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to getUserProperty event, code=${error.code}`);
}
```


## hiAppEvent.clearData

clearData(): void

Clears local logging data of the application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```ts
hiAppEvent.clearData();
```


## hiAppEvent.configure

configure(config: ConfigOption): void

Configures the application event logging function, such as setting the logging switch and directory storage quota.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                         | Mandatory| Description                    |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | Yes  | Configuration items for application event logging.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11103001 | Invalid max storage quota value. Possible caused by incorrectly formatted. |

**Example**

```ts
// Disable the event logging function.
let config1: hiAppEvent.ConfigOption = {
  disable: true,
};
hiAppEvent.configure(config1);

// Set the maximum size of the file storage directory to 100 MB.
let config2: hiAppEvent.ConfigOption = {
  maxStorage: '100M',
};
hiAppEvent.configure(config2);
```


## ConfigOption

Provides configuration options for application event logging.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Read Only| Optional| Description                                                        |
| ---------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No| Yes  | Whether to enable the event logging function. The default value is **false**. If this parameter is set to **true**, the logging function is disabled. Otherwise, the logging function is enabled.|
| maxStorage | string  | No| Yes  | Quota for the directory that stores event logging files. The default value is **10M**. It is recommended that the quota be less than or equal to 10 MB. Otherwise, the API efficiency may be affected.<br>If the directory size exceeds the specified quota when application event logging is performed, event logging files in the directory will be cleared one by one based on the generation time to ensure that directory size does not exceed the quota.<br>The quota value must meet the following requirements:<br>- The quota value consists of only digits and a unit (including b\|k\|kb\|m\|mb\|g\|gb\|t\|tb, which are case-insensitive).<br>- The quota value must start with a digit. You can determine whether to pass the unit. If the unit is left empty, **b** (that is, byte) is used by default.|


## EventPolicy<sup>22+</sup>

Defines the system event configuration policy, which is set by calling [configEventPolicy](#hiappeventconfigeventpolicy22).

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Read Only| Optional| Description                                        |
| ---------- | ------- | ---- | ---- | ------------------------------------------ |
| mainThreadJankPolicy | [MainThreadJankPolicy](#mainthreadjankpolicy22) | No| Yes  | Configuration policy for the main thread jank event.<br>**Atomic service API**: This API can be used in atomic services since API version 22.|
| cpuUsageHighPolicy | [CpuUsageHighPolicy](#cpuusagehighpolicy22) | No| Yes  | Configuration policy for the high CPU usage event.<br>**Atomic service API**: This API can be used in atomic services since API version 22.|
| appCrashPolicy<sup>24+</sup> | [AppCrashPolicy](#appcrashpolicy24) | No| Yes  | Crash event configuration policy.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| appFreezePolicy<sup>24+</sup> | [AppFreezePolicy](#appfreezepolicy24) | No| Yes  | Application freeze event configuration policy.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| resourceOverlimitPolicy<sup>24+</sup> | [ResourceOverlimitPolicy](#resourceoverlimitpolicy24) | No| Yes  | Resource leak event configuration policy.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| addressSanitizerPolicy<sup>24+</sup> | [AddressSanitizerPolicy](#addresssanitizerpolicy24) | No| Yes  | Address sanitizer event configuration policy.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|


## MainThreadJankPolicy<sup>22+</sup>

Defines the configuration policy for the main thread jank event.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

<!--Table: auto; auto; 10%; 10%; auto-->
| Name      | Type   | Read Only| Optional| Description                                        |
| ---------- | ------- | ---- | ---- | ------------------------------------------ |
| logType | number | No| Yes| Type of logs to collect. Default value: **0**<br>**logType = 0**: The default values of other parameters are used. When the main thread experiences two consecutive timeouts between 150 ms and 450 ms, a call stack capture is triggered. When the timeout exceeds 450 ms, a trace capture is triggered.<br>**logType=1**: Only the call stack is captured, and the threshold for triggering the detection is customized.<br>**logType=2**: Only traces are captured.<br>**NOTE**<br> - When **logType** is set to **0**, you only need to set **autoStopSampling**. Default values are used for other parameters.<br> - When **logType** is set to **2**, other parameters do not take effect and do not need to be set.|
| ignoreStartupTime | number | No| Yes| Mainthread jank event detection time ignored during application startup, in seconds. The default value is **10**, and the minimum value is **3**.|
| sampleInterval | number | No| Yes| Interval for the main thread jank event detection and sampling, in milliseconds. The default value is **150**. The value range is [50, 500].|
| sampleCount | number | No| Yes | Number of samplings for the main thread jank event. The default value is **10**. The minimum value is 1.<br>The maximum value is calculated using the following formula: **sampleCount** ≤ (2500/**sampleInterval** - 4).<br>**NOTE**<br> - The value **2500** (ms) indicates the maximum time allowed for a main thread jank event to be reported after being detected. Therefore, the value of **sampleCount** cannot be greater than the maximum value calculated based on the formula.<br> - The value **4** indicates the number of check intervals, that is, the first check interval, the twice second check intervals, and the interval for collecting and reporting stack information.<br> - You need to set the parameters as required.|
| reportTimesPerApp | number | No| Yes| Number of sampling reporting times for the main thread jank event of the processes with the same PID of an application. This parameter can be set only once for the processes with the same PID.<br>The default value is **1**.<br>The number of times that the sampling is reported per minute ranges from 1 to 3.|
| autoStopSampling | boolean | No| Yes| Whether to automatically stop sampling the main thread stack when the main thread jank event ends.<br>The value **true** means to stop sampling when the main thread jank event ends or the number of samplings reaches the specified value.<br>The value **false** means to stop sampling when the number of samplings reaches the specified value.<br>The default value is **false**.|

## CpuUsageHighPolicy<sup>22+</sup>
 
Defines the configuration policy for the high CPU usage event.
 
> **NOTE**
> 
> After this API is called, the setting is persisted. If this API is called again and the corresponding parameter is not set, the value used by the system last time is used.
 
**Atomic service API**: This API can be used in atomic services since API version 22.
 
**System capability**: SystemCapability.HiviewDFX.HiAppEvent
 
| Name      | Type   | Read Only| Optional| Description    |
| ---------- | ------- | ---- | ---- | ------------- |
| foregroundLoadThreshold    | number | No| Yes  | High CPU usage threshold of the application foreground, in percentage. The value range is **[1, 100]**. The default value is **30**. If the value is not within the threshold range, the default value **30** is used.<br>**Note**: It is recommended that the value be less than **30**.|
| backgroundLoadThreshold | number  | No| Yes  | High CPU usage threshold of the application background, in percentage. The value range is **[1, 100]**. The default value is **10**. If the value is not within the threshold range, the default value **10** is used.<br>**Note**: It is recommended that the value be less than **10**.|
| threadLoadThreshold | number  | No| Yes  | High CPU usage threshold of the application thread, in percentage. The value range is **[15, 100]**. The default value is **70**. If the value is not within the threshold range, the default value **70** is used.|
| perfLogCaptureCount | number  | No| Yes  | Number of log collection times per day. Once the system detects that the number of log collection times exceeds the set value, the system still reports the event normally, but the **external_log** field in the exception event is not attached with the log file path information.<br> For debug-type applications, the threshold range is **[-1, 100]**.<br> For release-type applications, the threshold range is **[0, 20]**.<br> Unit: times. Default value: **1**.<br> If the value is not within the threshold range, the default value **1** is used.<br>**NOTE**<br> 1. The value **-1** indicates that log collection times are not limited.<br> 2. The value **0** indicates that logs are not collected.<br> 3. A value greater than **0** indicates the maximum number of daily collection times.|
| threadLoadInterval | number  | No| Yes  | Interval for detecting high CPU usage of application threads, in seconds. The value range is **[5, 3600]**. The default value is **60**.<br>If the value is not within the threshold range, the default value **60** is used.|

## AppCrashPolicy<sup>24+</sup>

Defines the crash event configuration policy.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Read Only| Optional| Description    |
| ---------- | ------- | ---- | ---- | ------------- |
| pageSwitchLogEnable    | boolean | No| Yes  | Whether to enable the page switching log for crash events.<br>**true**: yes.<br>**false**: no.<br>The default value is **false**.<br>Note: The enabling behavior of an application takes effect only in its current lifecycle. In the same lifecycle, the enabling status of the last successful call is used. After the application restarts, you need to set the enabling status again.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| extendPcLrPrinting    | boolean | No| Yes  | Whether to print the memory values before and after the PC and LR registers in crash logs.<br>The value **true** means to print the memory values of 248 bytes before and 256 bytes after the PC and LR on 64-bit system, or 124 bytes before and 128 bytes after on 32-bit systems.<br>The value **false** means to print the memory values of 16 bytes before and 232 bytes after the PC and LR on 64-bit system, or 8 bytes before and 116 bytes after on 32-bit systems.<br>The default value is **false**.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|
| logFileCutoffSzBytes    | number | No| Yes  | Truncation size for crash logs. The value ranges from 0 to 5242880, in bytes. The default value is 0, indicating that crash logs are not truncated.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|
| simplifyVmaPrinting    | boolean | No| Yes  | Whether to print the mapping information of all virtual memory areas (VMAs) in the crash log, that is, the **Maps** field in the crash log.<br>The value **true** means to print only the VMA mapping information of the addresses in the crash log to reduce the log size.<br>The value **false** means to print all VMA mapping information.<br>The default value is **false**.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|

## AppFreezePolicy<sup>24+</sup>

Defines the application freeze event configuration policy.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Read Only| Optional| Description    |
| ---------- | ------- | ---- | ---- | ------------- |
| pageSwitchLogEnable    | boolean | No| Yes  | Whether to enable the page switching log for application freeze events.<br>**true**: yes.<br>**false**: no.<br>The default value is **false**.<br>Note: The enabling behavior of an application takes effect only in its current lifecycle. In the same lifecycle, the enabling status of the last successful call is used. After the application restarts, you need to set the enabling status again.|

## ResourceOverlimitPolicy<sup>24+</sup>

Defines the resource leak event configuration policy.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Read Only| Optional| Description    |
| ---------- | ------- | ---- | ---- | ------------- |
| pageSwitchLogEnable    | boolean | No| Yes  | Whether to enable the page switching log for resource leak events.<br>**true**: yes.<br>**false**: no.<br>The default value is **false**.<br>Note: The enabling behavior of an application takes effect only in its current lifecycle. In the same lifecycle, the enabling status of the last successful call is used. After the application restarts, you need to set the enabling status again.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| jsHeapLogtype    | string | No| Yes  | Heap snapshot transfer specifications.<br>**event**: No heap snapshot is transferred when an OOM error occurs.<br>**event_rawheap**: The system generates and transfers a heap snapshot when an OOM error occurs.<br>**NOTE**<br>- Only the preceding two values are supported. If other values are passed in, the method fails to be called and takes no effect.<br>- If the parameter value is **event_rawheap**, the heap snapshot file may fail to be generated. This is because the application may exit in advance due to a freeze event triggered by a performance problem.<br>-The enabling behavior of an application takes effect only in its current lifecycle. In the same lifecycle, the enabling status of the last successful call is used. After the application restarts, you need to set the enabling status again.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|

## AddressSanitizerPolicy<sup>24+</sup>

Defines the address sanitizer event configuration policy.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Read Only| Optional| Description    |
| ---------- | ------- | ---- | ---- | ------------- |
| pageSwitchLogEnable    | boolean | No| Yes  | Whether to enable the page switching log for address sanitizer events.<br>**true**: yes.<br>**false**: no.<br>The default value is **false**.<br>Note: The enabling behavior of an application takes effect only in its current lifecycle. In the same lifecycle, the enabling status of the last successful call is used. After the application restarts, you need to set the enabling status again.|

## Processor<sup>11+</sup>

Defines a data processor for reporting and managing events. You can customize processor configurations as required.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name               | Type                    | Read Only| Optional| Description                                                                                                       |
| ------------------- | ----------------------- | ---- | ---- | ---------------------------------------------------------------------------------------------------------- |
| name                | string                  | No| No  | Name of a data processor. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                                                                          |
| debugMode           | boolean                 | No| Yes  | Whether to enable the debug mode. The default value is **false**. The value **true** means to enable the debugging mode, and the value **false** means the opposite.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                   |
| routeInfo           | string                  | No| Yes  | Server location information. It is left empty by default. The length of the input string cannot exceed 8 KB. If the length exceeds 8 KB, the default value is used.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                                                                  |
| appId               | string                  | No| Yes  | Application ID. It is left empty by default. The length of the input string cannot exceed 8 KB. If the length exceeds 8 KB, the default value is used.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.|
| onStartReport       | boolean                 | No| Yes  | Whether to report an event when the data processor starts. The default value is **false**. The value **true** means to report events, and the value **false** means the opposite.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                  |
| onBackgroundReport  | boolean                 | No| Yes  | Whether to report an event when an application switches to the background. The default value is **false**. The value **true** means to report events, and the value **false** means the opposite.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                |
| periodReport        | number                  | No| Yes  | Interval for event reporting, in seconds. The input value must be greater than or equal to **0**. If the input value is less than **0**, the default value **0** is used and periodic reporting is not performed.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                               |
| batchReport         | number                  | No| Yes  | Event reporting threshold. When the number of events reaches the threshold, an event is reported. The value must be greater than **0** and less than **1000**. If the value is not within the range, the default value **0** is used and no events are reported.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                        |
| userIds             | string[]                | No| Yes  | Name array of user IDs that can be reported by the data processor. **name** corresponds to the **name** parameter of the [setUserId](#hiappeventsetuserid11) API. The default value is an empty array.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.   |
| userProperties      | string[]                | No| Yes  | Name array of user properties that can be reported by the data processor. **name** corresponds to the **name** parameter of the [setUserProperty](#hiappeventsetuserproperty11) API. The default value is an empty array.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.  |
| eventConfigs        | [AppEventReportConfig](#appeventreportconfig11)[]  | No| Yes  | Event description configuration array that can be reported by the data processor. The default value is an empty array.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.                                                                                |
| configId<sup>12+</sup> | number | No| Yes| Configuration ID for data processor. The input value must be greater than or equal to **0**. If the input value is less than **0**, the default value 0 is used. If the input value is greater than 0, the value uniquely identifies a data processor with its name.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| customConfigs<sup>12+</sup> | Record\<string, string> | No| Yes| Custom extended parameters. If the input parameter name and value do not meet the specifications, extended parameters are not configured by default. The specifications are as follows:<br>- A parameter name is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.<br>- A parameter value is a string contains a maximum of 1024 characters.<br>- The number of parameters must be less than 32.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| configName<sup>20+</sup>    | string                  | No| Yes  | <!--RP4-->Name of the data processor configuration, which can be loaded from the configuration file. By default, this parameter is left empty. It can contain only letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit and cannot exceed 256 characters.<br>**Atomic service API**: This parameter can be used in atomic services since API version 20.<!--RP4End-->|


## AppEventReportConfig<sup>11+</sup>

Defines the event configuration for the data processor to report.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name        | Type   | Read Only| Optional| Description                                                         |
| ----------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| domain      | string  | No| Yes  | Event domain. The value is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), and underscore (\_). It must start with a letter and cannot end with an underscore (\_). The default value is an empty string.|
| name        | string  | No| Yes  | Event name. The value is string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter. The default value is an empty string.|
| isRealTime  | boolean | No| Yes  | Whether to report events in real time. The value **true** indicates that events are reported in real time, and the value **false** indicates the opposite. The default value is **false**.|


## ParamType<sup>12+</sup>

type ParamType = number | string | boolean | Array&lt;string&gt;

Enumerates the types of custom event parameter values.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Type                      | Description               |
|--------------------------|-------------------|
| number                   | Number.        |
| string                   | String.       |
| boolean                  | The value is true or false.       |
| Array&lt;string&gt;      | The value is an array of strings.  |


## EventType

Enumerates event types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Value  | Description          |
| --------- | ---- | -------------- |
| FAULT     | 1    | Fault event.|
| STATISTIC | 2    | Statistical event.|
| SECURITY  | 3    | Security event.|
| BEHAVIOR  | 4    | Behavior event.|


## hiAppEvent.domain<sup>11+</sup>

### Constants

Provides domain name constants.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name| Type  | Read Only  | Description      |
| ---  | ------ | ------ | ---------- |
| OS   | string | Yes| System domain.|


## hiAppEvent.event

### Constants

Provides event name constants, including system event name constants and application event name constants. The application event name constants are optional custom event names reserved when you call [Write](#hiappeventwrite-1) for application event logging.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                     | Type  | Read Only  | Description                |
| ------------------------- | ------ | ------ | -------------------- |
| USER_LOGIN                | string | Yes| User login event. This is a reserved application event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.      |
| USER_LOGOUT               | string | Yes| User logout event. This is a reserved application event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.      |
| DISTRIBUTED_SERVICE_START | string | Yes| Distributed service startup event. This is a reserved application event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.|
| APP_CRASH<sup>11+</sup>   | string | Yes| Application crash event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.      |
| APP_FREEZE<sup>11+</sup>  | string | Yes| Application freeze event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 11.      |
| APP_LAUNCH<sup>12+</sup>  | string | Yes| Event indicating the application launch duration. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.  |
| SCROLL_JANK<sup>12+</sup> | string | Yes| Event indicating frame loss during swiping. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.  |
| CPU_USAGE_HIGH<sup>12+</sup> | string | Yes| Event indicating a high CPU usage. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| BATTERY_USAGE<sup>12+</sup> | string | Yes| Event indicating battery usage statistics. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| RESOURCE_OVERLIMIT<sup>12+</sup> | string | Yes| Application resource leak event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| ADDRESS_SANITIZER<sup>12+</sup> | string | Yes| Application address sanitizer event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| MAIN_THREAD_JANK<sup>12+</sup> | string | Yes| Main thread jank event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 12.|
| APP_KILLED<sup>20+</sup> | string | Yes| Application killed event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 20.|
| APP_HICOLLIE<sup>21+</sup> | string | Yes| Task execution timeout event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 21.|
| AUDIO_JANK_FRAME<sup>21+</sup> | string | Yes| Audio jank event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 21.|
| SCROLL_ARKWEB_FLING_JANK<sup>23+</sup> | string | Yes| ArkWeb fling jank event. This is a system event name constant.<br>**Atomic service API**: This parameter can be used in atomic services since API version 23.|
| appFreezeWarning | string | Yes| Application freeze warning event. This is a system event name constant.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|

## hiAppEvent.param

### Constants

Provides parameter name constants.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                           | Type  | Read Only  | Description              |
| ------------------------------- | ------ | ------ | ------------------ |
| USER_ID                         | string | Yes| Custom user ID.    |
| DISTRIBUTED_SERVICE_NAME        | string | Yes| Distributed service name.  |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | Yes| Distributed service instance ID.|
