# Application Event Logging

This module provides application event-related functions, including flushing application events to a disk, querying and clearing application events, and customizing application event logging configuration.

> **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
```

## hiAppEvent.write

write(info: [AppEventInfo](#appeventinfo), callback: AsyncCallback&lt;void&gt;): void

Writes events to the event file of the current day through [AppEventInfo](#appeventinfo) objects. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name  | Type                          | Mandatory| Description          |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo) | Yes  | Application event object.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](../errorcodes/errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 11100001 | Function is disabled.                         |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**Example**

```js
hiAppEvent.write({
    domain: "test_domain",
    name: "test_event",
    eventType: hiAppEvent.EventType.FAULT,
    params: {
        int_data: 100,
        str_data: "strValue"
    }
}, (err) => {
    if (err) {
        console.error(`code: ${err.code}, message: ${err.message}`);
        return;
    }
    console.log(`success to write event`);
});
```

## hiAppEvent.write

write(info: [AppEventInfo](#appeventinfo)): Promise&lt;void&gt;

Writes events to the event file of the current day through [AppEventInfo](#appeventinfo) objects. This API uses a promise to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| info   | [AppEventInfo](#appeventinfo) | Yes  | Application event object.|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](../errorcodes/errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 11100001 | Function is disabled.                         |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**Example**

```js
hiAppEvent.write({
    domain: "test_domain",
    name: "test_event",
    eventType: hiAppEvent.EventType.FAULT,
    params: {
        int_data: 100,
        str_data: "strValue"
    }
}).then(() => {
    console.log(`success to write event`);
}).catch((err) => {
    console.error(`code: ${err.code}, message: ${err.message}`);
});
```

## AppEventInfo

Defines parameters for an **AppEventInfo** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type                   | Mandatory| Description      |
| --------- | ----------------------- | ---- | ---------- |
| domain    | string                  | Yes  | Event domain.|
| name      | string                  | Yes  | Event name.|
| eventType | [EventType](#eventtype) | Yes  | Event type.|
| params    | object                  | Yes  | Event parameters.|

## hiAppEvent.configure

configure(config: [ConfigOption](configoption)): void

Configures the application event logging function, such as setting the event logging switch and maximum size of the directory that stores the event logging files.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                         | Mandatory| Description                    |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | Yes  | Configuration items for application event logging.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](../errorcodes/errorcode-hiappevent.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 11103001 | Invalid max storage quota value. |

**Example**

```js
// Disable the event logging function.
hiAppEvent.configure({
    disable: true
});

// Set the maximum size of the file storage directory to 100 MB.
hiAppEvent.configure({
    maxStorage: '100M'
});
```

## ConfigOption

Configures options for application event logging.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No  | Whether to enable the event logging function. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite.|
| maxStorage | string  | No  | Maximum size of the directory that stores event logging files. The default value is **10M**.<br>If the directory size exceeds the specified quota when application event logging is performed, event logging files in the directory will be cleared one by one based on the generation time to ensure that directory size does not exceed the quota.|

## hiAppEvent.addWatcher

addWatcher(watcher: [Watcher](#watcher)): [AppEventPackageHolder](#appeventpackageholder)

Adds a watcher to subscribe to application events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | Yes  | Watcher for application events.|

**Return value**

| Type                                            | Description                                |
| ------------------------------------------------ | ------------------------------------ |
| [AppEventPackageHolder](#appeventpackageholder) | Subscription data holder. If the subscription fails, **null** will be returned.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](../errorcodes/errorcode-hiappevent.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 11102001 | Invalid watcher name.           |
| 11102002 | Invalid filtering event domain. |
| 11102003 | Invalid row value.              |
| 11102004 | Invalid size value.             |
| 11102005 | Invalid timeout value.          |

**Example**

```js
// 1. If callback parameters are passed to the watcher, you can have subscription events processed in the callback that is automatically triggered.
hiAppEvent.addWatcher({
    name: "watcher1",
    appEventFilters: [
        {
            domain: "test_domain",
            eventTypes: [hiAppEvent.EventType.FAULT, hiAppEvent.EventType.BEHAVIOR]
        }
    ],
    triggerCondition: {
        row: 10,
        size: 1000,
        timeOut: 1
    },
    onTrigger: function (curRow, curSize, holder) {
        if (holder == null) {
            console.error("holder is null");
            return;
        }
        let eventPkg = null;
        while ((eventPkg = holder.takeNext()) != null) {
            console.info(`eventPkg.packageId=${eventPkg.packageId}`);
            console.info(`eventPkg.row=${eventPkg.row}`);
            console.info(`eventPkg.size=${eventPkg.size}`);
            for (const eventInfo of eventPkg.data) {
                console.info(`eventPkg.data=${eventInfo}`);
            }
        }
    }
});

// 2. If no callback parameters are passed to the watcher, you can have subscription events processed manually through the subscription data holder.
let holder = hiAppEvent.addWatcher({
    name: "watcher2",
});
if (holder != null) {
    let eventPkg = null;
    while ((eventPkg = holder.takeNext()) != null) {
        console.info(`eventPkg.packageId=${eventPkg.packageId}`);
        console.info(`eventPkg.row=${eventPkg.row}`);
        console.info(`eventPkg.size=${eventPkg.size}`);
        for (const eventInfo of eventPkg.data) {
            console.info(`eventPkg.data=${eventInfo}`);
        }
    }
}
```

## hiAppEvent.removeWatcher

removeWatcher(watcher: [Watcher](#watcher)): void

Removes a watcher to unsubscribe from application events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | Yes  | Watcher for application events.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](../errorcodes/errorcode-hiappevent.md).

| ID| Error Message             |
| -------- | --------------------- |
| 11102001 | Invalid watcher name. |

**Example**

```js
// 1. Define a watcher for application events.
let watcher = {
    name: "watcher1",
}

// 2. Add the watcher to subscribe to application events.
hiAppEvent.addWatcher(watcher);

// 3. Remove the watcher to unsubscribe from application events.
hiAppEvent.removeWatcher(watcher);
```

## Watcher

Defines parameters for a **Watcher** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name            | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string                                                       | Yes  | Unique name of the watcher.                            |
| triggerCondition | [TriggerCondition](#triggercondition)                        | No  | Subscription callback triggering condition. This parameter takes effect only when it is passed together with the callback.          |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                          | No  | Subscription filtering condition. This parameter is passed only when subscription events need to be filtered.              |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void | No  | Subscription callback, which takes effect only when it is passed together with the callback triggering condition. The input arguments are described as follows:<br>**curRow**: total number of subscription events when the callback is triggered.<br>**curSize**: total size of subscribed events when the callback is triggered, in bytes.<br>**holder**: subscription data holder, which can be used to process subscribed events.|

## TriggerCondition

Defines callback triggering conditions. Subscription callback is triggered when any condition is met.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name   | Type  | Mandatory| Description                                  |
| ------- | ------ | ---- | -------------------------------------- |
| row     | number | No  | Number of events.            |
| size    | number | No  | Event data size, in bytes.|
| timeOut | number | No  | Timeout interval, in unit of 30s.   |

## AppEventFilter

Defines parameters for an **AppEventFilter** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type                     | Mandatory| Description                    |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | Yes  | Event domain.    |
| eventTypes | [EventType](#eventtype)[] | No  | Event types.|

## AppEventPackageHolder

Defines a subscription data holder for processing subscription events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

### constructor

constructor(watcherName: string)

Constructor of the **Watcher** class. When a watcher is added, the system automatically calls this API to create a subscription data holder object for the watcher and returns the holder object to the application.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type             | Mandatory| Description                    |
| ------ | ----------------- | ---- | ------------------------ |
| watcherName | string | Yes  | Watcher name.|

**Example**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
```

### setSize

setSize(size: number): void

Sets the threshold for the data size of the application event package obtained each time.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | Yes  | Data size threshold, in bytes. The default value is **512*1024**.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](../errorcodes/errorcode-hiappevent.md).

| ID| Error Message           |
| -------- | ------------------- |
| 11104001 | Invalid size value. |

**Example**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
holder.setSize(1000);
```

### takeNext

takeNext(): [AppEventPackage](#appeventpackage)

Extracts subscription event data based on the configured data size threshold. If all subscription event data has been extracted, **null** will be returned.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
let eventPkg = holder.takeNext();
```

## AppEventPackage

Defines parameters for an **AppEventPackage** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type    | Mandatory| Description                          |
| --------- | -------- | ---- | ------------------------------ |
| packageId | number   | Yes  | Event package ID, which is named from **0** in ascending order.   |
| row       | number   | Yes  | Number of events in the event package.            |
| size      | number   | Yes  | Event size of the event package, in bytes.|
| data      | string[] | Yes  | Event data in the event package.            |

## hiAppEvent.clearData

clearData(): void

Clears local application event logging data.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```js
hiAppEvent.clearData();
```


## EventType

Enumerates event types.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Value  | Description          |
| --------- | ---- | -------------- |
| FAULT     | 1    | Fault event.|
| STATISTIC | 2    | Statistical event.|
| SECURITY  | 3    | Security event.|
| BEHAVIOR  | 4    | Behavior event.|


## Event

Provides constants that define the names of all predefined events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                     | Type  | Readable| Writable| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| USER_LOGIN                | string | Yes  | No  | User login event.      |
| USER_LOGOUT               | string | Yes  | No  | User logout event.      |
| DISTRIBUTED_SERVICE_START | string | Yes  | No  | Distributed service startup event.|


## Param

Provides constants that define the names of all predefined event parameters.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                           | Type  | Readable| Writable| Description              |
| ------------------------------- | ------ | ---- | ---- | ------------------ |
| USER_ID                         | string | Yes  | No  | Custom user ID.    |
| DISTRIBUTED_SERVICE_NAME        | string | Yes  | No  | Distributed service name.  |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | Yes  | No  | Distributed service instance ID.|
