# @ohos.telephony.observer (Observer) (System API)

The **observer** module provides event subscription management functions. With the APIs provided by this module, you can register or unregister an observer that listens cell information events (for the SIM card in the specified slot).

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.observer (Observer)](js-apis-observer.md).

## Modules to Import

```ts
import { observer } from '@kit.TelephonyKit';
```


## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', callback: Callback\<Array\<CellInformation\>\>\): void

Registers an observer for cell information change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                     |
| -------- | --------------------------------------------------------- | ---- |------------------------------------------|
| type     | string                                                    | Yes  | Cell information change event. This field has a fixed value of **cellInfoChange**.|
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | Yes  | Callback used to return the result.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { radio } from '@kit.TelephonyKit';

observer.on('cellInfoChange', (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', options: ObserverOptions, callback: Callback\<Array\<CellInformation\>\>\): void

Registers an observer for signal status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the execution result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type                                              | Mandatory| Description                                     |
| ------ |--------------------------------------------------| ---- |--------------------------------------------|
| type     | string                                           | Yes  | Cell information change event. This field has a fixed value of **cellInfoChange**.|
| options  | [ObserverOptions](js-apis-observer.md#observeroptions11)            | Yes  | Event subscription parameters.               |
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | Yes  | Callback used to return the result.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { radio } from '@kit.TelephonyKit';

let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('cellInfoChange', options, (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellInfoChange')<sup>8+</sup>

off\(type: \'cellInfoChange\', callback?: Callback\<Array\<CellInformation\>\>\): void

Unregisters the observer for cell information change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Cell information change event. This field has a fixed value of **cellInfoChange**.                                           |
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | No  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { radio } from '@kit.TelephonyKit';

let callback: (data: Array<radio.CellInformation>) => void = (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
}
observer.on('cellInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('cellInfoChange', callback);
observer.off('cellInfoChange');
```
