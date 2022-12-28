# HiAppEvent

This module provides the application event logging functions, such as writing application events to the event file and managing the event logging configuration.

> **NOTE**
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [`@ohos.hiviewdfx.hiAppEvent`](js-apis-hiviewdfx-hiappevent.md) instead.
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import hiAppEvent from '@ohos.hiAppEvent';
```

## How to Use

Before using application event logging, you need to understand the requirements for related parameters.

**Event Name**

An event name is a string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a lowercase letter and cannot end with an underscore (_).

**Event Type**

An event type is an enumerated value of [EventType](#eventtype).

**Event Parameter**

An event parameter is an object in key-value pair format, where the key is the parameter name and the value is the parameter value. The requirements are as follows:

- A parameter name is a string that contains a maximum of 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a lowercase letter and cannot end with an underscore (\_).
- The parameter value is a string, number, boolean, or array.
- When the parameter value is a string, its maximum length is 8*1024 characters. If this limit is exceeded, excess characters will be truncated.
- When the parameter value is an array, the elements in the array must be of the same type, which can only be string, number, or boolean. In addition, the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.
- The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.

**Event Callback**

Event callback can be a callback or promise that carries the return value obtained by invoking the event logging API. You can add the processing of the return value in the event callback as follows:

- If the return value is **0**, the event verification is successful, and the event will be directly written to the event file. 
- If the return value is greater than **0**, invalid parameters are present in the event, and the event will be written to the event file after the invalid parameters are ignored.
- If the return value is smaller than **0**, the event parameter verification fails, and the event will not be written to the event file.

## hiAppEvent.write

write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback&lt;void&gt;): void

Writes event information to the event file of the current day. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name   | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| eventName | string                    | Yes  | Event name.    |
| eventType | [EventType](#eventtype)   | Yes  | Event type.    |
| keyValues | object                    | Yes  | Event parameters.    |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Event callback.|

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


## hiAppEvent.write

write(eventName: string, eventType: EventType, keyValues: object): Promise&lt;void&gt;

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

| Name      | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No  | Application event logging switch. The value **true** means to disable the application event logging function, and the value **false** means the opposite.|
| maxStorage | string  | No  | Maximum size of the event file storage directory. The default value is <strong>10M</strong>. If the specified size is exceeded, the oldest event logging files in the directory will be deleted to free up space.|


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
