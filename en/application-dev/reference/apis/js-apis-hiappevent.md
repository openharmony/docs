# HiAppEvent

This module provides the application event logging functions, such as writing application events to the event file and managing the event logging configuration.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import hiAppEvent from '@ohos.hiAppEvent';
```

## How to Use

Before using application event logging, you need to understand the requirements for related parameters.

**Event Domain**

An event domain is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It cannot start with an underscore (\_).

**Event Name**

An event name is a string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It cannot start with an underscore (\_).

**Event Type**

An event type is an enumerated value of [EventType](#eventtype).

**Event Parameter**

An event parameter is an object in key-value pair format, where the key is the parameter name and the value is the parameter value. The requirements are as follows:

- The parameter name is a string that contains a maximum of 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It cannot start or end with an underscore (\_).
- The parameter value is a string, number, boolean, or array.
- When the parameter value is a string, its maximum length is 8*1024 characters. If this limit is exceeded, excess characters will be truncated.
- When the parameter value is an array, the elements in the array must be of the same type, which can only be string, number, or boolean. In addition, the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.
- The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.

**Event Callback**

Event callback can be a callback or promise that carries the return value obtained by invoking the event logging API. You can add the processing of the return value in the event callback as follows:

- If the return value is **0**, the event verification is successful, and the event will be directly written to the event file. 
- If the return value is greater than **0**, invalid parameters are present in the event, and the event will be written to the event file after the invalid parameters are ignored.
- If the return value is smaller than **0**, the event parameter verification fails, and the event will not be written to the event file.

**Subscription Callback**

A subscription callback carries the subscription data obtained by invoking the watcher API. The input parameters are defined as follows:

- **curRow**: number of events.
- **curSize**: event data size, in bytes.
- **holder**: event data holder, which can be used for processing subscription events.

## hiAppEvent.write<sup>(deprecated)</sup>

write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback&lt;void&gt;): void

> **NOTE**<br>This API is discarded since API version 9. You are advised to use [hiAppEvent.write](#hiappeventwrite9) instead.

Writes event information to the event file of the current day. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name   | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| eventName | string                    | Yes  | Event name.    |
| eventType | [EventType](#eventtype)   | Yes  | Event type.    |
| keyValues | object                    | Yes  | Event parameters.    |
| callback  | AsyncCallback&lt;void&gt; | No  | Event callback.|

**Example**

```js
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"}, (err, value) => {
    if (err) {
        // Event writing error: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
        console.error(`failed to write event because ${err.code}`);
        return;
    }

    // Event writing success
    console.log(`success to write event: ${value}`);
});
```


## hiAppEvent.write<sup>(deprecated)</sup>

write(eventName: string, eventType: EventType, keyValues: object): Promise&lt;void&gt;

> **NOTE**<br>This API is discarded since API version 9. You are advised to use [hiAppEvent.write](#hiappeventwrite9-1) instead.

Writes event information to the event file of the current day. This API uses a promise to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name   | Type                   | Mandatory| Description      |
| --------- | ----------------------- | ---- | ---------- |
| eventName | string                  | Yes  | Event name.|
| eventType | [EventType](#eventtype) | Yes  | Event type.|
| keyValues | object                  | Yes  | Event parameters.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to asynchronously process the callback in the **then()** and **catch()** methods when event writing succeeded or failed.|

**Example**

```js
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"})
    .then((value) => {
        // Event writing success
        console.log(`success to write event: ${value}`);
    }).catch((err) => {
        // Event writing error: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
        console.error(`failed to write event because ${err.code}`);
    });
```

## hiAppEvent.write<sup>9+</sup>

write(info: [AppEventInfo](#appeventinfo9), callback: AsyncCallback&lt;void&gt;): void

Writes events to the event file of the current day through [AppEventInfo](#appeventinfo9) objects. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name  | Type                          | Mandatory| Description          |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo9) | Yes  | Application event object.|
| callback | AsyncCallback&lt;void&gt;      | No  | Event callback.|

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
}, (err, value) => {
    if (err) {
        // Event writing error: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
        console.error(`failed to write event because ${err.code}`);
        return;
    }

    // Event writing success
    console.log(`success to write event: ${value}`);
});
```

## hiAppEvent.write<sup>9+</sup>

write(info: [AppEventInfo](#appeventinfo9)): Promise&lt;void&gt;

Writes events to the event file of the current day through [AppEventInfo](#appeventinfo9) objects. This API uses a promise to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| info   | [AppEventInfo](#appeventinfo9) | Yes  | Application event object.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to asynchronously process the callback in the **then()** and **catch()** methods when event writing succeeded or failed.|

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
}).then((value) => {
    // Event writing success
    console.log(`success to write event: ${value}`);
}).catch((err) => {
    // Event writing error: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
    console.error(`failed to write event because ${err.code}`);
});
```

## AppEventInfo<sup>9+</sup>

Defines parameters for an **AppEventInfo** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type               | Mandatory| Description      |
| --------- | ----------------------- | ---- | ---------- |
| domain    | string                  | Yes  | Event domain.|
| name      | string                  | Yes  | Event name.|
| eventType | [EventType](#eventtype) | Yes  | Event type.|
| params    | object                  | Yes  | Event parameters.|

## hiAppEvent.configure

configure(config: ConfigOption): boolean

Configures the application event logging function, such as setting the event logging switch and maximum size of the directory that stores the event logging files.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                         | Mandatory| Description                    |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | Yes  | Configuration items for application event logging.|

**Return value**

| Type   | Description                                                       |
| ------- | ----------------------------------------------------------- |
| boolean | Returns **true** if the configuration is successful; returns **false** otherwise.|

**Example**

```js
// Set the application event logging switch.
hiAppEvent.configure({
    disable: true
});

// Configure the maximum size of the directory that stores the event logging files.
hiAppEvent.configure({
    maxStorage: '100M'
});
```

## ConfigOption

Provides the configuration items for application event logging.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name    | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No  | Application event logging switch. The value **true** means to disable the application event logging function, and the value **false** means the opposite.|
| maxStorage | string  | No  | Maximum size of the event file storage directory. The default value is <strong>10M</strong>. If the specified size is exceeded, the oldest event logging files in the directory will be deleted to free up space.|

## hiAppEvent.addWatcher<sup>9+</sup>

addWatcher(watcher: [Watcher](#watcher9)): [AppEventPackageHolder](#appeventpackageholder9)

Adds an event watcher.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher9) | Yes  | Event watcher.|

**Return value**

| Type                                            | Description                                |
| ------------------------------------------------ | ------------------------------------ |
| [AppEventPackageHolder](#appeventpackageholder9) | Subscription data holder. If the subscription fails, **null** will be returned.|

**Example**

```js
// 1. If callback parameters are passed to the watcher, you can have subscription events processed in the callback that is automatically triggered.
hiAppEvent.addWatcher({
    name: "watcher1",
    appEventFilters: [
        {
            domain: "domain_test1",
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
            console.info("eventPkg.packageId=" + eventPkg.packageId);
            console.info("eventPkg.row=" + eventPkg.row);
            console.info("eventPkg.size=" + eventPkg.size);
            for (const eventInfo of eventPkg.data) {
                console.info("eventPkg.data=" + eventInfo);
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
        console.info("eventPkg.packageId=" + eventPkg.packageId);
        console.info("eventPkg.row=" + eventPkg.row);
        console.info("eventPkg.size=" + eventPkg.size);
        for (const eventInfo of eventPkg.data) {
            console.info("eventPkg.data=" + eventInfo);
        }
    }
}
```

## hiAppEvent.removeWatcher<sup>9+</sup>

removeWatcher(watcher: [Watcher](#watcher9)): void

Removes an event watcher.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher9) | Yes  | Event watcher.|

**Example**

```js
// 1. Define a watcher.
let watcher = {
    name: "watcher1",
}

// 2. Add the watcher to subscribe to application events.
hiAppEvent.addWatcher(watcher);

// 3. Remove the watcher to unsubscribe from application events.
hiAppEvent.removeWatcher(watcher);
```

## Watcher<sup>9+</sup>

Defines parameters for a **Watcher** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name            | Type                                                    | Mandatory| Description                            |
| ---------------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| name             | string                                                       | Yes  | Unique watcher name.|
| triggerCondition | [TriggerCondition](#triggercondition9)                       | No  | Subscription callback trigger condition.              |
| appEventFilters  | [AppEventFilter](#appeventfilter9)[]                         | No  | Application event filter criteria.                  |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder9)) => void | No  | Subscription callback.                 |

## TriggerCondition<sup>9+</sup>

Defines parameters for a **TriggerCondition** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name   | Type| Mandatory| Description                                  |
| ------- | -------- | ---- | -------------------------------------- |
| row     | number   | No  | Number of events.              |
| size    | number   | No  | Event data size, in bytes.|
| timeOut | number   | No  | Timeout interval, in unit of 30s.   |

## AppEventFilter<sup>9+</sup>

Defines parameters for an **AppEventFilter** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type                 | Mandatory| Description                    |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | Yes  | Event domain.    |
| eventTypes | [EventType](#eventtype)[] | No  | Event types.|

## AppEventPackageHolder<sup>9+</sup>

Defines a subscription data holder for processing subscription events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

### constructor<sup>9+</sup>

constructor(watcherName: string);

A constructor used to create a **holder** object. It is called automatically when a **Watcher** object is added.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
```

### setSize<sup>9+</sup>

setSize(size: number): void

Sets the data size threshold for fetching an application event package. The default value is **512*1024**, in bytes.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
holder.setSize(1000);
```

### takeNext<sup>9+</sup>

takeNext(): [AppEventPackage](#appeventpackage9)

Extracts subscription event data based on the configured data size threshold. If all subscription event data has been extracted, **null** will be returned.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
let eventPkg = holder.takeNext();
```

## AppEventPackage<sup>9+</sup>

Defines parameters for an **AppEventPackage** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type| Description                          |
| --------- | -------- | ------------------------------ |
| packageId | number   | Event package ID, which is named from **0** in ascending order.   |
| row       | number   | Number of events in the event package.            |
| size      | number   | Data size of the event package, in bytes.|
| data      | string[] | Event data in the event package.            |

## hiAppEvent.clearData<sup>9+</sup>

clearData(): void

Clears local logging data.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```js
hiAppEvent.clearData();
```


## EventType

Enumerates event types.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Default Value| Description          |
| --------- | ------ | -------------- |
| FAULT     | 1      | Fault event.|
| STATISTIC | 2      | Statistical event.|
| SECURITY  | 3      | Security event.|
| BEHAVIOR  | 4      | Behavior event.|


## Event

Provides constants that define the names of all predefined events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                     | Type| Readable| Writable| Description                |
| ------------------------- | -------- | ---- | ---- | -------------------- |
| USER_LOGIN                | string   | Yes  | No  | User login event.      |
| USER_LOGOUT               | string   | Yes  | No  | User logout event.      |
| DISTRIBUTED_SERVICE_START | string   | Yes  | No  | Distributed service startup event.|


## Param

Provides constants that define the names of all predefined event parameters.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                           | Type| Readable| Writable| Description              |
| ------------------------------- | -------- | ---- | ---- | ------------------ |
| USER_ID                         | string   | Yes  | No  | Custom user ID.    |
| DISTRIBUTED_SERVICE_NAME        | string   | Yes  | No  | Distributed service name.  |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string   | Yes  | No  | Distributed service instance ID.|
