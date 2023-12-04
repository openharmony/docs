# @ohos.telephony.observer (Observer)

The **observer** module provides event subscription management functions. You can register or unregister an observer that listens for the following events: network status change, signal status change, call status change, cellular data connection status, uplink and downlink data flow status of cellular data services, and SIM status change.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import observer from '@ohos.telephony.observer';
```

## observer.on('networkStateChange')

on\(type: \'networkStateChange\', callback: Callback\<NetworkState\>\): void

Registers an observer for network status change events. This API uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                             |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | Yes  | Network status change event. This field has a fixed value of **networkStateChange**.                |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | Yes  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
observer.on('networkStateChange', (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')

on\(type: \'networkStateChange\', options: { slotId: number }, callback: Callback\<NetworkState\>\): void

Registers an observer for network status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

|  Name |                              Type                        | Mandatory|                            Description                                  |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | Yes  | Network status change event. This field has a fixed value of **networkStateChange**.                |
| slotId   | number                                                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                            |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | Yes  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('networkStateChange', id, (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('networkStateChange')

off\(type: \'networkStateChange\', callback?: Callback\<NetworkState\>\): void

Unregisters the observer for network status change events. This API uses an asynchronous callback to return the execution result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Network status change event. This field has a fixed value of **networkStateChange**.                |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | No  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
let callback: (data: observer.NetworkState) => void = (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
}
observer.on('networkStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('networkStateChange', callback);
observer.off('networkStateChange');
```

## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', callback: Callback\<Array\<SignalInformation\>\>): void

Registers an observer for signal status change events. This API uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Signal status change event. This field has a fixed value of **signalInfoChange**.             |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | Yes  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import radio from '@ohos.telephony.radio';

observer.on('signalInfoChange', (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', options: { slotId: number }, callback: Callback\<Array\<SignalInformation\>\>): void

Registers an observer for signal status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Signal status change event. This field has a fixed value of **signalInfoChange**.             |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | Yes  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import radio from '@ohos.telephony.radio';

class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('signalInfoChange', id, (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('signalInfoChange')

off\(type: \'signalInfoChange\', callback?: Callback\<Array\<SignalInformation\>\>): void

Unregisters the observer for signal status change events. This API uses an asynchronous callback to return the execution result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Signal status change event. This field has a fixed value of **signalInfoChange**.             |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | No  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import radio from '@ohos.telephony.radio';

let callback: (data: Array<radio.SignalInformation>) => void = (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import radio from '@ohos.telephony.radio';

observer.on('cellInfoChange', (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', options: { slotId: number }, callback: Callback\<Array\<CellInformation\>\>\): void

Registers an observer for signal status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the execution result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type                                              | Mandatory| Description                                     |
| ------ |--------------------------------------------------| ---- |--------------------------------------------|
| type     | string                                           | Yes  | Cell information change event. This field has a fixed value of **cellInfoChange**.|
| slotId | number                                           | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2     |
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | Yes  | Callback used to return the result.      |

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import radio from '@ohos.telephony.radio';

class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('cellInfoChange', id, (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellInfoChange')<sup>8+</sup>

off\(type: \'cellInfoChange\', callback?: Callback\<Array\<CellInformation\>\>\): void

Unregisters the observer for cell information change events. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Cell information change event. This field has a fixed value of **cellInfoChange**.                                           |
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | No  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import radio from '@ohos.telephony.radio';

let callback: (data: Array<radio.CellInformation>) => void = (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
}
observer.on('cellInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('cellInfoChange', callback);
observer.off('cellInfoChange');
```

## observer.on('callStateChange')

on(type: 'callStateChange', callback: Callback\<{ state: CallState, number: string }\>): void

Registers an observer for call status change events. This API uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Call status change event. This field has a fixed value of **callStateChange**.              |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | Yes  | Callback used to return the result. For details, see [CallState](js-apis-call.md#callstate).<br>**number**: phone number.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import call from '@ohos.telephony.call';

class Value {
    state: call.CallState = call.CallState.CALL_STATE_UNKNOWN
    number: string = ""
}
observer.on('callStateChange', (value: Value) => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.on('callStateChange')

on(type: 'callStateChange', options: { slotId: number }, callback: Callback<{ state:CallState, number: string }>): void

Registers an observer for call status change events. This API uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Call status change event. This field has a fixed value of **callStateChange**.              |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | Yes  | Callback used to return the result. For details, see [CallState](js-apis-call.md#callstate).<br>**number**: phone number.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import call from '@ohos.telephony.call';

class Value {
    state: call.CallState = call.CallState.CALL_STATE_UNKNOWN
    number: string = ""
}
class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('callStateChange', id, (value: Value) => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.off('callStateChange')

off(type: 'callStateChange', callback?: Callback<{ state: CallState, number: string }>): void

Unregisters the observer for call status change events. This API uses an asynchronous callback to return the execution result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Call status change event. This field has a fixed value of **callStateChange**.              |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | No  | Callback used to return the result. For details, see [CallState](js-apis-call.md#callstate).<br>**number**: phone number.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import call from '@ohos.telephony.call';

class Value {
    state: call.CallState = call.CallState.CALL_STATE_UNKNOWN
    number: string = ""
}
let callback: (value: Value) => void = (value: Value) => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
}
observer.on('callStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('callStateChange', callback);
observer.off('callStateChange');
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', callback: Callback\<{ state: DataConnectState, network: RatType}\>\): void

Registers an observer for connection status change events of the cellular data link. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Cellular data connection status event. This field has a fixed value of **cellularDataConnectionStateChange**.|
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | Yes  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import radio from '@ohos.telephony.radio';

class Value {
    state: data.DataConnectState = data.DataConnectState.DATA_STATE_UNKNOWN
    network: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN
}
observer.on('cellularDataConnectionStateChange', (value: Value) => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', options: { slotId: number }, callback: Callback\<{ state: DataConnectState, network: RatType }\>\): void

Registers an observer for connection status change events of the cellular data link over the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Cellular data connection status event. This field has a fixed value of **cellularDataConnectionStateChange**.|
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | Yes  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import radio from '@ohos.telephony.radio';

class Value {
    state: data.DataConnectState = data.DataConnectState.DATA_STATE_UNKNOWN
    network: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN
}
class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('cellularDataConnectionStateChange', id, (value: Value) => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.off('cellularDataConnectionStateChange')<sup>7+</sup>

off\(type: 'cellularDataConnectionStateChange',  callback?: Callback\<{ state: DataConnectState, network: RatType}\>\): void

Unregisters the observer for connection status change events of the cellular data link. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Cellular data connection status event. This field has a fixed value of **cellularDataConnectionStateChange**.|
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | No  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import radio from '@ohos.telephony.radio';

class Value {
    state: data.DataConnectState = data.DataConnectState.DATA_STATE_UNKNOWN
    network: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN
}
let callback: (value: Value) => void = (value: Value) => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
}
observer.on('cellularDataConnectionStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('cellularDataConnectionStateChange', callback);
observer.off('cellularDataConnectionStateChange');
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType\>\): void

Registers an observer for the uplink and downlink data flow status change events of the cellular data service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes | Cellular data flow change event. This field has a fixed value of **cellularDataFlowChange**.        |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | Yes  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';

observer.on('cellularDataFlowChange', (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', options: { slotId: number },  callback: Callback\<DataFlowType\>\): void

Registers an observer for the uplink and downlink data flow status change events of the cellular data service on the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Cellular data flow change event. This field has a fixed value of **cellularDataFlowChange**.        |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                                            |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | Yes  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';

class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('cellularDataFlowChange', id, (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataFlowChange')<sup>7+</sup>

off\(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType\>\): void

Unregisters the observer for the uplink and downlink data flow status change events of the cellular data service. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                               | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                             | Yes  | Cellular data flow change event. This field has a fixed value of **cellularDataFlowChange**.  |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | No  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';

let callback: (data: data.DataFlowType) => void = (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
}
observer.on('cellularDataFlowChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('cellularDataFlowChange', callback);
observer.off('cellularDataFlowChange');
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', callback: Callback\<SimStateData\>\): void

Registers an observer for SIM card status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | SIM status change event. This field has a fixed value of **simStateChange**.                |
| callback | Callback\<[SimStateData](#simstatedata7)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
observer.on('simStateChange', (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData\>\): void

Registers an observer for status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | SIM status change event. This field has a fixed value of **simStateChange**.                |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<[SimStateData](#simstatedata7)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
class SlotId {
    slotId: number = 0
}
let id: SlotId = {slotId: 0}
observer.on('simStateChange', id, (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('simStateChange')<sup>7+</sup>

off\(type: 'simStateChange', callback?: Callback\<SimStateData\>\): void

Unregisters the observer for SIM card status change events. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | SIM status change event. This field has a fixed value of **simStateChange**.                |
| callback | Callback\<[SimStateData](#simstatedata7)\> | No  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
let callback: (data: observer.SimStateData) => void = (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
}
observer.on('simStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('simStateChange', callback);
observer.off('simStateChange');
```

## observer.on('iccAccountInfoChange')<sup>10+</sup>

on\(type: 'iccAccountInfoChange', callback: Callback\<void\>\): void

Registers an observer for account information change events of the SIM card. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Account information change event. This field has a fixed value of **iccAccountInfoChange**.                |
| callback | Callback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
observer.on('iccAccountInfoChange', () => {
    console.log("on iccAccountInfoChange success");
});
```


## observer.off('iccAccountInfoChange')<sup>10+</sup>

off\(type: 'iccAccountInfoChange', callback?: Callback\<void\>\): void

Unregisters the observer for account information change events of the SIM card. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Account information change event. This field has a fixed value of **iccAccountInfoChange**.                |
| callback | Callback\<void\> | No  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
let callback: () => void = () => {
    console.log("on iccAccountInfoChange success");
}
observer.on('iccAccountInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('iccAccountInfoChange', callback);
observer.off('iccAccountInfoChange');
```


## LockReason<sup>8+</sup>

Enumerates SIM card lock types.

**System capability**: SystemCapability.Telephony.StateRegistry

| Name       | Value  | Description             |
| ----------- | ---- | ----------------- |
| SIM_NONE    | 0    | No lock.           |
| SIM_PIN     | 1    | PIN lock.          |
| SIM_PUK     | 2    | PUK lock.          |
| SIM_PN_PIN  | 3    | Network PIN lock.      |
| SIM_PN_PUK  | 4    | Network PUK lock.      |
| SIM_PU_PIN  | 5    | Subnet PIN lock.      |
| SIM_PU_PUK  | 6    | Subnet PUK lock.      |
| SIM_PP_PIN  | 7    | Service provider PIN lock.|
| SIM_PP_PUK  | 8    | Service provider PUK lock.|
| SIM_PC_PIN  | 9    | Organization PIN lock.      |
| SIM_PC_PUK  | 10   | Organization PUK lock.      |
| SIM_SIM_PIN | 11   | SIM PIN lock.      |
| SIM_SIM_PUK | 12   | SIM PUK lock.      |


## SimStateData<sup>7+</sup>

Enumerates SIM card types and states.

**System capability**: SystemCapability.Telephony.StateRegistry

|     Name           |                 Type               | Mandatory| Description                                                     |
| ------------------- | ----------------------------------- | ---- | --------------------------------------------------------  |
| type                | [CardType](js-apis-sim.md#cardtype7) | Yes  | SIM card type.|
| state               | [SimState](js-apis-sim.md#simstate) | Yes  | SIM card state.|
| reason<sup>8+</sup> | [LockReason](#lockreason8)          | Yes  | SIM card lock type.                                            |
