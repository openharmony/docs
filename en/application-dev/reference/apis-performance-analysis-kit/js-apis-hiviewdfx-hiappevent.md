# @ohos.hiviewdfx.hiAppEvent (Application Event Logging)

The **hiAppEvent** module provides application event-related functions, including flushing application events to a disk, querying and clearing application events, and customizing application event logging configuration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
```

## hiAppEvent.addProcessor<sup>11+</sup>

addProcessor(processor: Processor): number

Adds a data processor for migrating events to the cloud. The implementation of data processors can be preset in the device. You can set attributes of the data processor based on its constraints.

The configuration information of **Processor** must be provided by the data processor. Yet, as no data processor is preset in the device for interaction for the moment, migrating events to the cloud is unavailable.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type       | Mandatory| Description             |
| ---------  | ---------- | ---- | -------------    |
| processor  | [Processor](#processor11)  | Yes  | Data processor.|

**Return value**

| Type   | Description                  |
| ------ | ---------------------- |
| number | ID of the data processor to be added. If the operation fails, **-1** is returned. If the operation is successful, a value greater than **0** is returned.|

**Error codes**

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

## Processor<sup>11+</sup>

Defines a data processor for reporting events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name               | Type                    | Mandatory| Description                                                                                                       |
| ------------------- | ----------------------- | ---- | ---------------------------------------------------------------------------------------------------------- |
| name                | string                  | Yes  | Name of a data processor. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                          |
| debugMode           | boolean                 | No  | Whether to enable the debug mode. The default value is **false**. The value **true** means to enable the debugging mode, and the value **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                   |
| routeInfo           | string                  | No  | Server location information. It is left empty by default. The length of the input string cannot exceed 8 KB. If the length exceeds 8 KB, the default value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                  |
| appId               | string                  | No  | Application ID. It is left empty by default. The length of the input string cannot exceed 8 KB. If the length exceeds 8 KB, the default value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onStartReport       | boolean                 | No  | Whether to report an event when the data processor starts. The default value is **false**. The value **true** means to report events, and the value **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                  |
| onBackgroundReport  | boolean                 | No  | Whether to report an event when an application switches to the background. The default value is **false**. The value **true** means to report events, and the value **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                |
| periodReport        | number                  | No  | Interval for event reporting, in seconds. The input value must be greater than or equal to **0**. If the input value is less than **0**, the default value **0** is used and periodic reporting is not performed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                               |
| batchReport         | number                  | No  | Event reporting threshold. When the number of events reaches the threshold, an event is reported. The value must be greater than **0** and less than **1000**. If the value is not within the range, the default value **0** is used and no events are reported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                        |
| userIds             | string[]                | No  | Name array of user IDs that can be reported by the data processor. **name** corresponds to the **name** parameter of the [setUserId](#hiappeventsetuserid11) API.<br>**Atomic service API**: This API can be used in atomic services since API version 11.   |
| userProperties      | string[]                | No  | Name array of user properties that can be reported by the data processor. **name** corresponds to the **name** parameter of the [setUserProperty](#hiappeventsetuserproperty11) API.<br>**Atomic service API**: This API can be used in atomic services since API version 11.  |
| eventConfigs        | [AppEventReportConfig](#appeventreportconfig11)[]  | No  | Array of events that can be reported by the data processor.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                |
| configId<sup>12+</sup> | number | No| Configuration ID for data processor. The input value must be greater than or equal to **0**. If the input value is less than **0**, the default value 0 is used. If the input value is greater than 0, the value uniquely identifies a data processor with its name.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| customConfigs<sup>12+</sup> | Record\<string, string> | No| Custom extended parameters. If the input parameter name and value do not meet the specifications, extended parameters are not configured by default. The specifications are as follows:<br>- A parameter name is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.<br>- A parameter value is a string contains a maximum of 1024 characters.<br>- The number of parameters must be less than 32.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## AppEventReportConfig<sup>11+</sup>

Description of events that can be reported by the data processor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name        | Type   | Mandatory| Description                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| domain      | string  | No  | Event domain. The value is a string of up to 32 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (_).|
| name        | string  | No  | Event name. The value is string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.|
| isRealTime  | boolean | No  | Whether to report events in real time. The value **true** means to report events, and the value **false** means the opposite.|

## hiAppEvent.removeProcessor<sup>11+</sup>

removeProcessor(id: number): void

Removes a data processor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type   | Mandatory| Description                        |
| ------| ------- | ---- | --------------------------- |
| id    | number  | Yes  | ID of a data processor. The value must be greater than **0**.|

**Error codes**

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
    hiAppEvent.removeProcessor(id);
} catch (error) {
    hilog.error(0x0000, 'hiAppEvent', `failed to removeProcessor event, code=${error.code}`);
}
```

## hiAppEvent.write

write(info: AppEventInfo, callback: AsyncCallback&lt;void&gt;): void

Writes events to the event file of the current day through **AppEventInfo** objects. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name  | Type                          | Mandatory| Description          |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo) | Yes  | Application event object.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled.                            |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};
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

Writes events to the event file of the current day through **AppEventInfo** objects. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled.                            |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};
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

## AppEventInfo

Defines parameters for an **AppEventInfo** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type                   | Mandatory| Description                                                        |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| domain    | string                  | Yes  | Event domain. The value is a string of up to 32 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (_).|
| name      | string                  | Yes  | Event name. The value is string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.|
| eventType | [EventType](#eventtype) | Yes  | Event type.                                                  |
| params    | object                  | Yes  | Event parameter object. An event parameter has a parameter name and a parameter value. In system events, the fields contained in **params** are defined by system. For details about the fields, you can see the introduction to system events, for example, [Crash Event Overview](../../dfx/hiappevent-watcher-crash-events.md). For application events, you need to define the logging parameters. The specifications are as follows:<br>- A parameter name is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.<br>- The parameter value can be a string, number, boolean, or array. If the parameter value is a string, its maximum length is 8*1024 characters. If this limit is exceeded, excess characters will be discarded. If the parameter value is a number, the value must be within the range of **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. Otherwise, uncertain values may be generated. If the parameter value is an array, the elements in the array must be of the same type, which can only be string, number, or boolean. In addition, the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.<br>- The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.|

## hiAppEvent.setEventParam<sup>12+</sup>

setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt;

Sets custom event parameters. This API uses a promise to return the result. In the same lifecycle, you can associate system events with application events by event domain and event name. Only crash and freeze events are supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| params | Record&lt;string, [ParamType](#paramtype12)&gt; | Yes| Custom parameter object. The parameter name and value are defined as follows:<br>- A parameter name is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.<br>- The parameter value is of the [ParamType](#paramtype12) and contains a maximum of 1024 characters.<br>- The number of parameters must be less than 64.|
| domain | string                        | Yes| Event domain. The event domain can be associated with application events and system events (hiAppEvent.domain.OS).|
| name   | string                        | No| Event name. The default value is an empty string, which indicates all event names in the associated event domain. The event name can be associated with application events and system events. System events can be associated only with crash events (hiAppEvent.event.APP_CRASH) and freeze events (hiAppEvent.event.APP_FREEZE).|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

Sets the custom threshold triggering condition for an event. This API uses a promise to return the result. In the same lifecycle, you can customize the parameters related to the event threshold triggering condition based on the event name. Currently, only the **MAIN_THREAD_JANK** event is supported. For details about the parameter configuration, see [Main Thread Jank Event Overview](../../dfx/hiappevent-watcher-mainthreadjank-events.md).

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                          | Mandatory| Description          |
| ------ | ------------------------------ | ---- | -------------- |
| name   | string                        | Yes| Event name.|
| config | Record<string, ParamType> | Yes| Custom parameter object. The parameter name and value are defined as follows:<br>- The parameter name contains a maximum of 1024 characters, which is of the string type and cannot be empty.<br>- The parameter value is of the ParamType and contains a maximum of 1024 characters.|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |

**Example**

The following describes how to customize the **log_type** parameter for the **MAIN_THREAD_JANK** event.

Set **log_type** to **0** to collect the stack or trace:
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "0"
};

hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event config`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

Set **log_type** to **1** to collect only the call stack:
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "1",
  "sample_interval": "100",
  "ignore_startup_time": "11",
  "sample_count": "21",
  "report_times_per_app": "3",
};
hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event config`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

Set **log_type** to **2** to collect only the trace:
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "2"
};
hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event config`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

## ParamType<sup>12+</sup>

type ParamType = number | string | boolean | Array&lt;string&gt;

Type of a custom event parameter value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Type                      | Description               |
|--------------------------|-------------------|
| number                   | Number.        |
| string                   | String.       |
| boolean                  | The value is true or false.       |
| Array&lt;string&gt;      | The value is an array of strings.  |

## hiAppEvent.configure

configure(config: ConfigOption): void

Configures the application event logging function, such as setting the event logging switch and maximum size of the directory that stores the event logging files.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type                         | Mandatory| Description                    |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | Yes  | Configuration items for application event logging.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11103001 | Invalid max storage quota value. |

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

| Name      | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No  | Whether to enable the event logging function. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite.|
| maxStorage | string  | No  | Quota for the directory that stores event logging files. The default value is **10M**.<br>If the directory size exceeds the specified quota when application event logging is performed, event logging files in the directory will be cleared one by one based on the generation time to ensure that directory size does not exceed the quota.<br>The quota value must meet the following requirements:<br>- The quota value consists of only digits and a unit (which can be one of [b\|k\|kb\|m\|mb\|g\|gb\|t\|tb], which are case insensitive.)<br>- The quota value must start with a digit. You can determine whether to pass the unit. If the unit is left empty, **b** (that is, byte) is used by default.|

## hiAppEvent.setUserId<sup>11+</sup>

setUserId(name: string, value: string): void

Sets a user ID.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------  |
| name      | string                    | Yes  | Key of a user ID. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit.  |
| value     | string                    | Yes  | Value of a user ID. It can contain a maximum of 256 characters. If the value is **null** or left empty, the user ID is cleared.|

**Error codes**

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

Obtains the value set by **setUserId**.

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

Sets user properties.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| name      | string                    | Yes  | Key of a user property. The value is string that contains a maximum of 256 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must not start with a digit. |
| value     | string                    | Yes  | Value of a user property. It can contain a maximum of 1024 characters. If the value is **null** or left empty, the user property is cleared. |

**Error codes**

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

Obtains the value set by **setUserProperty**.

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

## hiAppEvent.addWatcher

addWatcher(watcher: Watcher): AppEventPackageHolder

Adds a watcher to subscribe to application events.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11102001 | Invalid watcher name.           |
| 11102002 | Invalid filtering event domain. |
| 11102003 | Invalid row value.              |
| 11102004 | Invalid size value.             |
| 11102005 | Invalid timeout value.          |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

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

// 2. If no callback parameters are passed to the watcher, you can have subscription events processed manually through the subscription data holder.
// For the crash event (hiAppEvent.event.APP_CRASH) and freeze event (hiAppEvent.event.APP_FREEZE) generated when the system exits abnormally, it takes some time for the system to capture maintenance and debugging logs. Typically, the capture is completed within 30s, in extreme cases, it takes about 2 minutes. If you want to manually process subscription events, you are advised to call takeNext() after the process starts.
let holder = hiAppEvent.addWatcher({
  name: "watcher2",
});
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

// 3. You can have the watcher processed the subscription event in the onReceive function.
hiAppEvent.addWatcher({
  name: "watcher3",
  appEventFilters: [
    {
      domain: "test_domain",
      eventTypes: [hiAppEvent.EventType.FAULT, hiAppEvent.EventType.BEHAVIOR]
    }
  ],
  onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
    hilog.info(0x0000, 'hiAppEvent', `domain=${domain}`);
    for (const eventGroup of appEventGroups) {
      hilog.info(0x0000, 'hiAppEvent', `eventName=${eventGroup.name}`);
      for (const eventInfo of eventGroup.appEventInfos) {
        hilog.info(0x0000, 'hiAppEvent', `event=${JSON.stringify(eventInfo)}`, );
      }
    }
  }
});
```

## hiAppEvent.removeWatcher

removeWatcher(watcher: Watcher): void

Removes a watcher to unsubscribe from application events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name | Type                | Mandatory| Description            |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | Yes  | Watcher for application events.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message             |
| -------- | --------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11102001 | Invalid watcher name. |

**Example**

```ts
// 1. Define a watcher for application events.
let watcher: hiAppEvent.Watcher = {
  name: "watcher1",
}

// 2. Add the watcher to subscribe to application events.
hiAppEvent.addWatcher(watcher);

// 3. Remove the watcher to unsubscribe from application events.
hiAppEvent.removeWatcher(watcher);
```

## Watcher

Defines parameters for a **Watcher** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name            | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string                                                       | Yes  | Unique name of a watcher.                            |
| triggerCondition | [TriggerCondition](#triggercondition)                        | No  | Subscription callback triggering condition. This parameter takes effect only when it is passed together with **onTrigger**.          |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                          | No  | Subscription filtering condition. This parameter is passed only when subscription events need to be filtered.              |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void | No  | Subscription callback. This parameter takes effect only when it is passed together with **triggerCondition**. The input arguments are described as follows:<br>**curRow**: total number of subscription events when the callback is triggered.<br>**curSize**: total size of subscribed events when the callback is triggered, in bytes.<br>**holder**: subscription data holder, which can be used to process subscribed events.|
| onReceive<sup>11+</sup>        | (domain: string, appEventGroups: Array<[AppEventGroup](#appeventgroup11)>) => void | No| Real-time subscription callback. Only this callback function is triggered if it is passed together with **onTrigger**. The input arguments are described as follows:<br>domain: domain name.<br>appEventGroups: event group.|

## TriggerCondition

Defines callback triggering conditions. A callback is triggered when any specified condition is met.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name   | Type  | Mandatory| Description                                  |
| ------- | ------ | ---- | -------------------------------------- |
| row     | number | No  | Total number of events that trigger callback. The value is a positive integer. The default value is 0, indicating that no callback is triggered. If this parameter is set to a negative value, the default value is used.            |
| size    | number | No  | Total size of events that trigger callback. The value is a positive integer, in bytes. The default value is 0, indicating that no callback is triggered. If this parameter is set to a negative value, the default value is used.|
| timeOut | number | No  | Timeout interval for triggering callback. The value is a positive integer, in unit of 30s. The default value is 0, indicating that no callback is triggered. If this parameter is set to a negative value, the default value is used.   |

## AppEventFilter

Defines parameters for an **AppEventFilter** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type                     | Mandatory| Description                    |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | Yes  | Event domain.    |
| eventTypes | [EventType](#eventtype)[] | No  | Event types.|
| names<sup>11+</sup>      | string[]                  | No  | Names of the events to be subscribed.|

## AppEventPackageHolder

Defines a subscription data holder for processing subscription events.

### constructor

constructor(watcherName: string)

A constructor used to create a holder object for subscription data. It is associated with a **Watcher** object based on its name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type             | Mandatory| Description                    |
| ------ | ----------------- | ---- | ------------------------ |
| watcherName | string | Yes  | Watcher name.|

**Example**

```ts
let holder1: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher1");
```

### setSize

setSize(size: number): void

Sets the threshold for the data size of the application event package obtained each time.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | Yes  | Data size, in bytes. The value is greater than or equal to 0, otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message           |
| -------- | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11104001 | Invalid size value. |

**Example**

```ts
let holder2: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher2");
holder2.setSize(1000);
```

### setRow<sup>12+</sup>

setRow(size: number): void

Sets the number of data records obtained from the application event package each time. When **setRow()** and **setSize()** are called at the same time, only **setRow()** takes effect.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | Yes  | Number of application events. The value must be greater than 0, otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Application Event Logging Error Codes](errorcode-hiappevent.md).

| ID| Error Message           |
| -------- | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11104001 | Invalid size value. |

**Example**

```ts
let holder3: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher3");
holder3.setRow(1000);
```

### takeNext

takeNext(): AppEventPackage

Extracts subscription event data based on the configured data size threshold or the number of application events. If all subscription event data has been extracted, **null** will be returned.
1. When an application only calls **setSize()** , the subscription events are obtained based on the data size.
2. When an application calls **setRow()**, the subscription events are obtained based on the **number** of **setRow()** regardless of whether **setSize()** is called.
3. If neither **setSize()** nor **setRow()** is called, one subscription event is obtained by default.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Return value**

| Type                               | Description                                                  |
| ----------------------------------- | ------------------------------------------------------ |
| [AppEventPackage](#appeventpackage) | Event package object. If all subscription event data has been retrieved, **null** is returned.|

**Example**

```ts
let holder4: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher4");
let eventPkg = holder4.takeNext();
```

## AppEventPackage

Defines parameters for an **AppEventPackage** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type    | Mandatory| Description                          |
| --------- | -------- | ---- | ------------------------------ |
| packageId | number   | Yes  | Event package ID, which is named from **0** in ascending order.<br>**Atomic service API**: This API can be used in atomic services since API version 11.   |
| row       | number   | Yes  | Number of events in the event package.<br>**Atomic service API**: This API can be used in atomic services since API version 11.            |
| size      | number   | Yes  | Event size of the event package, in bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| data      | string[] | Yes  | Event data in the event package.<br>**Atomic service API**: This API can be used in atomic services since API version 11.            |
| appEventInfos<sup>12+</sup> | Array<[AppEventInfo](#appeventinfo)> | Yes  | Event object group.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## AppEventGroup<sup>11+</sup>

Defines the event group returned by a subscription.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name         | Type                           | Mandatory | Description         |
| ------------- | ------------------------------- | ---- | ------------- |
| name          | string                          | Yes  | Event name.    |
| appEventInfos | Array<[AppEventInfo](#appeventinfo)> | Yes  | Event object group.|

## hiAppEvent.clearData

clearData(): void

Clears local application event logging data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Example**

```ts
hiAppEvent.clearData();
```


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


## hiappevent.domain<sup>11+</sup>

Defines the domain name of predefined events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name| Type  | Read Only  | Description      |
| ---  | ------ | ------ | ---------- |
| OS   | string | Yes| System domain.|


## hiappevent.event

Defines the names of predefined events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                     | Type  | Read Only  | Description                |
| ------------------------- | ------ | ------ | -------------------- |
| USER_LOGIN                | string | Yes| User login event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| USER_LOGOUT               | string | Yes| User logout event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| DISTRIBUTED_SERVICE_START | string | Yes| Distributed service startup event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| APP_CRASH<sup>11+</sup>   | string | Yes| Application crash event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| APP_FREEZE<sup>11+</sup>  | string | Yes| Application freeze event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| APP_LAUNCH<sup>12+</sup>  | string | Yes| Event indicating the application launch duration.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |
| SCROLL_JANK<sup>12+</sup> | string | Yes| Event indicating frame loss during swiping.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |
| CPU_USAGE_HIGH<sup>12+</sup> | string | Yes| Event indicating a high CPU usage.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| BATTERY_USAGE<sup>12+</sup> | string | Yes| Event indicating battery usage statistics.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| RESOURCE_OVERLIMIT<sup>12+</sup> | string | Yes| Event indicating an application resource leakage.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| ADDRESS_SANITIZER<sup>12+</sup> | string | Yes| Address sanitizer event.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MAIN_THREAD_JANK<sup>12+</sup> | string | Yes| Main thread jank event.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## hiappevent.param

Defines the names of predefined event parameters.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                           | Type  | Read Only  | Description              |
| ------------------------------- | ------ | ------ | ------------------ |
| USER_ID                         | string | Yes| Custom user ID.    |
| DISTRIBUTED_SERVICE_NAME        | string | Yes| Distributed service name.  |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | Yes| Distributed service instance ID.|
