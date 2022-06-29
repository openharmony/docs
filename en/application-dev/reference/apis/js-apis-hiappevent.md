# HiAppEvent

This module provides the application event logging functions, such as writing application events to the event file and managing the event logging configuration.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import hiAppEvent from '@ohos.hiAppEvent';
```


## hiAppEvent.write

write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback&lt;void&gt;): void

Writes event information to the event file of the current day. This API supports JSON parameters and uses an asynchronous callback to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| eventName | string                    | Yes  | Application event name.<br>You need to customize the event name. It can contain a maximum of 48 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter.|
| eventType | [EventType](#eventtype)   | Yes  | Application event type.                                              |
| keyValues | object                    | Yes  | Parameter key-value pair. For a variable-length parameter, enter each pair of parameter name and value in sequence. For a JSON parameter, enter the parameter name as the key and parameter value as the value.<br>- A key must be a string, and a value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).<br>- The number of event parameters must be less than or equal to 32.<br>- The parameter name can contain a maximum of 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (\_).<br>- A string value can contain a maximum of 8*1024 characters.<br>- An array value can contain a maximum of 100 elements. Excess elements will be truncated.|
| callback  | AsyncCallback&lt;void&gt; | No  | Callback used to process the received return value.<br>-&nbsp; Value **0** indicates that the event verification is successful, and the event will be written to the event file asynchronously. <br>-&nbsp; A value greater than **0** indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. <br>-&nbsp; A value smaller than **0** indicates that the event verification fails, and the event will not be written to the event file.|

**Example**

```
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"}, (err, value) => {
    if (err) {
        // Event writing exception: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
        console.error(`failed to write event because ${err.code}`);
        return;
    }

    // Event writing succeeded.
    console.log(`success to write event: ${value}`);
});
```


## hiAppEvent.write

write(eventName: string, eventType: EventType, keyValues: object): Promise&lt;void&gt;

Writes event information to the event file of the current day. This API supports JSON parameters and uses a promise to return the result.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name   | Type                   | Mandatory| Description                                                        |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| eventName | string                  | Yes  | Application event name.<br>You need to customize the event name. It can contain a maximum of 48 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter.|
| eventType | [EventType](#eventtype) | Yes  | Application event type.                                              |
| keyValues | object                  | Yes  | Parameter key-value pair. For a variable-length parameter, enter each pair of parameter name and value in sequence. For a JSON parameter, enter the parameter name as the key and parameter value as the value.<br>- A key must be a string, and a value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).<br>- The number of event parameters must be less than or equal to 32.<br>- The parameter name can contain a maximum of 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (\_).<br>- A string value can contain a maximum of 8*1024 characters.<br>- An array value can contain a maximum of 100 elements. Excess elements will be truncated.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to process the callback in the then() and catch() methods when event writing succeeded or failed.|

**Example**

```
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"})
    .then((value) => {
        // Event writing succeeded.
        console.log(`success to write event: ${value}`);
    }).catch((err) => {
        // Event writing exception: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
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
```
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
| disable    | boolean | No  | Application event logging switch. The value <b>true</b> means to disable the application event logging function, and the value <b>false</b> means the opposite.|
| maxStorage | string  | No  | Maximum size of the event file storage directory. The default value is **10M**. If the specified size is exceeded, the oldest event logging files in the storage directory will be deleted to free up space.|


## EventType

Enumerates event types.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Default Value| Description          |
| --------- | ------ | -------------- |
| FAULT     | 1      | Fault event|
| STATISTIC | 2      | Statistical event|
| SECURITY  | 3      | Security event|
| BEHAVIOR  | 4      | Behavior event|


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
