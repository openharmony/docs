# @ohos.hiviewdfx.hiAppEvent (Application Event Logging)

The **hiAppEvent** module provides application event-related functions, including flushing application events to a disk, querying and clearing application events, and customizing application event logging configuration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
```

## hiAppEvent.addProcessor<sup>11+</sup>

addProcessor(processor: Processor): number

Adds a data processor for migrating events to the cloud. The implementation of data processors can be preset in the device. You can set attributes of the data processor based on its constraints.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type       | Mandatory| Description             |
| ---------  | ---------- | ---- | -------------    |
| processor  | [Processor](#processor11)  | Yes  | Data processor.|

**Return value**

| Type   | Description                  |
| ------ | ---------------------- |
| number | ID of the data processor to be added. If the operation fails, **-1** is returned. If the operation is successful, a value greater than 0 is returned.|

**Error codes**

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

try {
    let processor: hiAppEvent.Processor = {
      name: 'analytics_demo'
    };
    let id: number = hiAppEvent.addProcessor(processor);
    hiLog.info('hiAppEvent', `addProcessor event was successful, id=${id}`);
} catch (error) {
    hiLog.info('hiAppEvent', `failed to addProcessor event, code=${error.code}`);
} 
```

## Processor<sup>11+</sup>

Defines a data processor for reporting events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name               | Type                    | Mandatory| Description                                                                                                       |
| ------------------- | ----------------------- | ---- | ---------------------------------------------------------------------------------------------------------- |
| name                | string                  | Yes  | Name of a data processor.                                                                                          |
| debugMode           | boolean                 | No  | Whether to enable the debugging mode. The value **true** means to enable the debugging mode, and the value **false** means the opposite.                                   |
| routeInfo           | string                  | No  | Server location information, which cannot exceed 8 KB.                                                                                  |
| onStartReport       | boolean                 | No  | Whether the data processor reports events during startup. The value **true** means to report events, and the value **false** means the opposite.                                  |
| onBackgroundReport  | boolean                 | No  | Whether to report events after an application switches to the background. The value **true** means to report events, and the value **false** means the opposite.                                |
| periodReport        | number                  | No  | Time period for reporting events, in seconds. The value must be greater than or equal to **0**. If the value is **0**, no events are reported.                                               |
| batchReport         | number                  | No  | Threshold for reporting events. It is expressed by the number of events. The value must be greater than **0** and less than **1000**. If the value is not within the value range, no events are reported.                        |
| userIds             | string[]                | No  | Name array of user IDs that can be reported by the data processor. A name can contain a maximum of 256 characters, including uppercase letters, lowercase letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit.   |
| userProperties      | string[]                | No  | Name array of user properties that can be reported by the data processor. A name can contain a maximum of 256 characters, including uppercase letters, lowercase letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit.  |
| eventConfigs        | [AppEventReportConfig](#appeventreportconfig11)[]  | No  | Array of events that can be reported by the data processor.                                                                                |

## AppEventReportConfig<sup>11+</sup>

Description of events that can be reported by the data processor.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name        | Type   | Mandatory| Description                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| domain      | string  | No  | Event domain. The value is a string of up to 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a lowercase letter and cannot end with an underscore (_).|
| name        | string  | No  | Event name. It is string that contains a maximum of 48 characters, including the dollar sign ($), digits (0 to 9), letters (a to z), and underscore (_). It must start with a letter or dollar sign ($) and end with a digit or letter.|
| isRealTime  | boolean | No  | Whether to report events in real time. The value **true** means to report events, and the value **false** means the opposite.|

## hiAppEvent.removeProcessor<sup>11+</sup>

removeProcessor(id: number): void

Removes a data processor.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name| Type   | Mandatory| Description                        |
| ------| ------- | ---- | --------------------------- |
| id    | number  | Yes  | ID of a data processor. The value must be greater than **0**.|
	
**Error codes**

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

try {
    let processor: hiAppEvent.Processor = {
      name: 'analytics_demo'
    };
    let id: number = hiAppEvent.addProcessor(processor);
    hiAppEvent.removeProcessor(id);
} catch (error) {
    hiLog.info('hiAppEvent', `failed to removeProcessor event, code=${error.code}`);
} 
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

```ts
import { BusinessError } from '@ohos.base';

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

```ts
import { BusinessError } from '@ohos.base';

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
  console.log(`success to write event`);
}).catch((err: BusinessError) => {
  console.error(`code: ${err.code}, message: ${err.message}`);
});
```

## AppEventInfo

Defines parameters for an **AppEventInfo** object.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name     | Type                   | Mandatory| Description                                                        |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| domain    | string                  | Yes  | Event domain. The value is a string of up to 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a lowercase letter and cannot end with an underscore (_).|
| name      | string                  | Yes  | Event name. It is string that contains a maximum of 48 characters, including the dollar sign ($), digits (0 to 9), letters (a to z), and underscore (_). It must start with a letter or dollar sign ($) and end with a digit or letter.|
| eventType | [EventType](#eventtype) | Yes  | Event type.                                                  |
| params    | object                  | Yes  | Event parameter object, which consists of a parameter name and a parameter value. The specifications are as follows:<br>- A parameter name is a string that contains a maximum of 16 characters, including the dollar sign ($), digits (0 to 9), letters (a to z), and underscore (_). It must start with a letter or dollar sign ($) and end with a digit or letter.<br>- The parameter value can be a string, number, boolean, or array. If the parameter value is a string, its maximum length is 8*1024 characters. If this limit is exceeded, excess characters will be discarded. If the parameter value is a number, the value must be within the range of **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. Otherwise, uncertain values may be generated. If the parameter value is an array, the elements in the array must be of the same type, which can only be string, number, or boolean. In addition, the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.<br>- The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.|

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

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name      | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | No  | Whether to enable the event logging function. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite.|
| maxStorage | string  | No  | Maximum size of the directory that stores event logging files. The default value is **10M**.<br>If the directory size exceeds the specified quota when application event logging is performed, event logging files in the directory will be cleared one by one based on the generation time to ensure that directory size does not exceed the quota.|

## hiAppEvent.setUserId<sup>11+</sup>

setUserId(name: string, value: string): void

Sets a user ID.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------  |
| name      | string                    | Yes  | Key of a user ID. It is a string that contains a maximum of 256 characters, including uppercase letters, lowercase letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit.  |
| value     | string                    | Yes  | Value of a user ID. It is a string that contains a maximum of 256 characters. If the value is **null**, **undefine**, or **empty**, the user ID is cleared.|

**Error codes**

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

try {
  hiAppEvent.setUserId('key', 'value');
} catch (error) {
  hiLog.info('hiAppEvent', `failed to setUseId event, code=${error.code}`);
} 
```

## hiAppEvent.getUserId<sup>11+</sup>

getUserId(name: string): string

Obtains the value set by **setUserId**.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                   | Mandatory| Description        |
| --------- | ----------------------- | ---- | ----------  |
| name      | string                  | Yes  | Key of a user ID. It is a string that contains a maximum of 256 characters, including uppercase letters, lowercase letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit.|

**Return value**

| Type   | Description                           |
| ------ | ------------------------------- |
| string | Value of a user ID. If no user ID is found, an empty string is returned.|

**Error codes**

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

hiAppEvent.setUserId('key', 'value');
try {
  let value: string = hiAppEvent.getUserId('key');
  hiLog.info('hiAppEvent', `getUseId event was successful, userId=${value}`);/* "value" */
} catch (error) {
  hiLog.info('hiAppEvent', `failed to getUseId event, code=${error.code}`);
} 
```

## hiAppEvent.setUserProperty<sup>11+</sup>

setUserProperty(name: string, value: string): void

Sets user properties.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| name      | string                    | Yes  | Key of a user attribute. It is a string that contains a maximum of 256 characters, including uppercase letters, lowercase letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit. |
| value     | string                    | Yes  | Value of a user attribute. It is a string that contains a maximum of 1024 characters. If the value is **null**, **undefine**, or **empty**, the user ID is cleared. |

**Error codes**

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

try {
  hiAppEvent.setUserProperty('key', 'value');
} catch (error) {
  hiLog.info('hiAppEvent', `failed to setUserProperty event, code=${error.code}`);
} 
```

## hiAppEvent.getUserProperty<sup>11+</sup>

getUserProperty(name: string): string

Obtains the value set by **setUserProperty**.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Parameters**

| Name    | Type                   | Mandatory| Description         |
| --------- | ----------------------- | ---- | ----------    |
| name      | string                  | Yes  | Key of a user attribute. It is a string that contains a maximum of 256 characters, including uppercase letters, lowercase letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit.|

**Return value**

| Type   | Description                            |
| ------ | -------------------------------- |
| string | Value of a user attribute. If no user ID is found, an empty string is returned.|

**Error codes**

| ID| Error Message         |
| ------- | ----------------- |
| 401     | Parameter error. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

hiAppEvent.setUserProperty('key', 'value');
try {
  let value: string = hiAppEvent.getUserProperty('key');
  hiLog.info('hiAppEvent', `getUserProperty event was successful, userProperty=${value}`);/* "value" */
} catch (error) {
  hiLog.info('hiAppEvent', `failed to getUserProperty event, code=${error.code}`);
} 
```

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

```ts
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
      console.error("holder is null");
      return;
    }
    console.info(`curRow=${curRow}, curSize=${curSize}`);
    let eventPkg: hiAppEvent.AppEventPackage | null = null;
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
  let eventPkg: hiAppEvent.AppEventPackage | null = null;
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

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name            | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string                                                       | Yes  | Unique name of a watcher.                            |
| triggerCondition | [TriggerCondition](#triggercondition)                        | No  | Subscription callback triggering condition. This parameter takes effect only when it is passed together with the callback.          |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                          | No  | Subscription filtering condition. This parameter is passed only when subscription events need to be filtered.              |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void | No  | Subscription callback, which takes effect only when it is passed together with the callback triggering condition. The input arguments are described as follows:<br>**curRow**: total number of subscription events when the callback is triggered.<br>**curSize**: total size of subscribed events when the callback is triggered, in bytes.<br>**holder**: subscription data holder, which can be used to process subscribed events.|

## TriggerCondition

Defines callback triggering conditions. A callback is triggered when any specified condition is met.

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

### constructor

constructor(watcherName: string)

A constructor used to create a holder object for subscription data. It is associated with a **Watcher** object based on its name.

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

```ts
let holder2: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher2");
holder2.setSize(1000);
```

### takeNext

takeNext(): [AppEventPackage](#appeventpackage)

Extracts subscription event data based on the configured data size threshold. If all subscription event data has been extracted, **null** will be returned.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Return value**

| Type                               | Description                                                  |
| ----------------------------------- | ------------------------------------------------------ |
| [AppEventPackage](#appeventpackage) | Event package object. If all subscription event data has been retrieved, **null** is returned.|

**Example**

```ts
let holder3: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher3");
let eventPkg = holder3.takeNext();
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

```ts
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


## event

Provides constants that define the names of all predefined events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                     | Type  | Description                |
| ------------------------- | ------ | -------------------- |
| USER_LOGIN                | string | User login event.      |
| USER_LOGOUT               | string | User logout event.      |
| DISTRIBUTED_SERVICE_START | string | Distributed service startup event.|


## param

Provides constants that define the names of all predefined event parameters.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

| Name                           | Type  | Description              |
| ------------------------------- | ------ | ------------------ |
| USER_ID                         | string | Custom user ID.    |
| DISTRIBUTED_SERVICE_NAME        | string | Distributed service name.  |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | Distributed service instance ID.|
