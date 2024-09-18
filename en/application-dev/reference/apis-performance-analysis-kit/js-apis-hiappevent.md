# @ohos.hiAppEvent (HiAppEvent)

The **hiAppEvent** module provides the application event logging functions, such as writing application events to the event file and managing the event logging configuration.

> **NOTE**
>
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [`@ohos.hiviewdfx.hiAppEvent`](js-apis-hiviewdfx-hiappevent.md).
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import hiAppEvent from '@ohos.hiAppEvent';
```

## How to Use

Before using application event logging, you need to understand the requirements for related parameters.

**Event Name**

An event name is a string that contains a maximum of 48 characters, including the dollar sign ($), digits (0 to 9), letters (a to z), and underscore (_). It must start with a letter or dollar sign ($) and end with a digit or letter.

**Event Type**

An event type is an enumerated value of [EventType](#eventtype).

**Event Parameter**

An event parameter is an object in key-value pair format, where the key is the parameter name and the value is the parameter value. The requirements are as follows:

- A parameter name is a string that contains a maximum of 32 characters, including the dollar sign ($), digits (0 to 9), letters (a to z), and underscore (_). It must start with a letter or dollar sign ($) and end with a digit or letter.
- A parameter value can be of the string, number, boolean, or array type.
- If the parameter value is a string, its maximum length is 8*1024 characters. If this limit is exceeded, excess characters will be discarded.
- If the parameter value is a number, the value must be within the range of **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. Otherwise, uncertain values may be generated.
- If the parameter value is an array, the elements in the array must be of the same type, which can only be string, number, or boolean. In addition, the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.
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

| Name   | Type                     | Mandatory | Description          |
| --------- | ------------------------- | ---- | -------------- |
| eventName | string                    | Yes  | Event name.    |
| eventType | [EventType](#eventtype)   | Yes  | Event type.    |
| keyValues | object                    | Yes  | Event parameters.    |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Event callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, eventParams, (err: BusinessError) => {
  if (err) {
    // Event writing error: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
    console.error(`failed to write event, code=${err.code}`);
    return;
  }
  // Event writing success
  console.log(`success to write event`);
});
```


## hiAppEvent.write

write(eventName: string, eventType: EventType, keyValues: object): Promise&lt;void&gt;

Writes event information to the event file of the current day. This API uses a promise to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name   | Type                   | Mandatory | Description      |
| --------- | ----------------------- | ---- | ---------- |
| eventName | string                  | Yes  | Event name. |
| eventType | [EventType](#eventtype) | Yes  | Event type. |
| keyValues | object                  | Yes  | Event parameters. |

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to asynchronously process the callback in the **then()** and **catch()** methods when event writing succeeded or failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, eventParams).then(() => {
  // Event writing success
  console.log(`success to write event`);
}).catch((err: BusinessError) => {
  // Event writing error: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
  console.error(`failed to write event, code=${err.code}`);
});
```

## hiAppEvent.configure

configure(config: ConfigOption): boolean

Configures the application event logging function, such as setting the event logging switch and maximum size of the directory that stores the event logging files.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                         | Mandatory | Description                    |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | Yes  | Configuration items for application event logging. |

**Return value**

| Type   | Description                                                       |
| ------- | ----------------------------------------------------------- |
| boolean | Returns **true** if the configuration is successful; returns **false** otherwise. |

**Example**

```ts
// Set the application event logging switch.
let config1: hiAppEvent.ConfigOption = {
  disable: true,
};
hiAppEvent.configure(config1);

// Configure the maximum size of the directory that stores the event logging files.
let config2: hiAppEvent.ConfigOption = {
  maxStorage: '100M',
};
hiAppEvent.configure(config2);
```

## ConfigOption

Provides the configuration items for application event logging.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Mandatory | Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No  | Application event logging switch. The value **true** means to disable the application event logging function, and the value **false** means the opposite. |
| maxStorage | string  | No  | Maximum size of the event file storage directory. The default value is **10M**. If the specified size is exceeded, the oldest event logging files in the directory will be deleted to free up space. |


## EventType

Enumerates the event types.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Value  | Description          |
| --------- | ---- | -------------- |
| FAULT     | 1    | Fault event. |
| STATISTIC | 2    | Statistical event. |
| SECURITY  | 3    | Security event. |
| BEHAVIOR  | 4    | Behavior event. |


## Event

Provides constants that define the names of all predefined events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                     | Type  | Readable | Writable | Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| USER_LOGIN                | string | Yes  | No  | User login event.      |
| USER_LOGOUT               | string | Yes  | No  | User logout event.      |
| DISTRIBUTED_SERVICE_START | string | Yes  | No  | Distributed service startup event. |


## Param

Provides constants that define the names of all predefined event parameters.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                           | Type  | Readable | Writable | Description              |
| ------------------------------- | ------ | ---- | ---- | ------------------ |
| USER_ID                         | string | Yes  | No  | Custom user ID.    |
| DISTRIBUTED_SERVICE_NAME        | string | Yes  | No  | Distributed service name.  |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | Yes  | No  | Distributed service instance ID. |
