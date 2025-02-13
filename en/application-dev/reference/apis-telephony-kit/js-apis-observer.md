# @ohos.telephony.observer (Observer)

The **observer** module provides event subscription management functions. You can register or unregister an observer that listens for the following events: network status change, signal status change, call status change, cellular data connection status, uplink and downlink data flow status of cellular data services, and SIM status change.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { observer } from '@kit.TelephonyKit';
```

## NetworkState

type NetworkState = radio.NetworkState

Defines the network status.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [radio.NetworkState](js-apis-radio.md#networkstate) | Network status.|

## SignalInformation

type SignalInformation = radio.SignalInformation

Defines the signal strength.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [radio.SignalInformation](js-apis-radio.md#signalinformation) | Signal strength.|


## CellInformation

type CellInformation = radio.CellInformation

Defines the cell information.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [radio.CellInformation](js-apis-radio.md#cellinformation8) | Cell information.|


## DataConnectState

type DataConnectState = data.DataConnectState

Describes the connection status of a cellular data link.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [data.DataConnectState](js-apis-telephony-data.md#dataconnectstate) | Connection status of a cellular data link.|


## RatType

type RatType = radio.RadioTechnology

Enumerates the radio access technologies.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [radio.RadioTechnology](js-apis-radio.md#radiotechnology) | Radio access technology.|


## DataFlowType

type DataFlowType = data.DataFlowType

Defines the cellular data flow type.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [data.DataFlowType](js-apis-telephony-data.md#dataflowtype) | Cellular data flow type.|


## CallState

type CallState = call.CallState

Enumerates call states.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [call.CallState](js-apis-call.md#callstate) | Call state.|


## CardType

type CardType = sim.CardType

Enumerates SIM card types.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [sim.CardType](js-apis-sim.md#cardtype7) | SIM card type.|


## SimState

type SimState = sim.SimState

SIM card state.

**System capability**: SystemCapability.Telephony.StateRegistry

|       Type      |            Description            |
| ---------------- | --------------------------- |
| [sim.SimState](js-apis-sim.md#simstate) | SIM card state.|


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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
observer.on('networkStateChange', (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')

on\(type: \'networkStateChange\', options: ObserverOptions, callback: Callback\<NetworkState\>\): void

Registers an observer for network status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

|  Name |                              Type                        | Mandatory|                            Description                                  |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | Yes  | Network status change event. This field has a fixed value of **networkStateChange**.                |
| options  | [ObserverOptions](#observeroptions11)                     | Yes  | Event subscription parameters.                                       |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | Yes  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('networkStateChange', options, (data: observer.NetworkState) => {
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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { radio } from '@kit.TelephonyKit';

observer.on('signalInfoChange', (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', options: ObserverOptions, callback: Callback\<Array\<SignalInformation\>\>): void

Registers an observer for signal status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Signal status change event. This field has a fixed value of **signalInfoChange**.             |
| options  | [ObserverOptions](#observeroptions11)                        | Yes  | Event subscription parameters.                                  |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | Yes  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
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
observer.on('signalInfoChange', options, (data: Array<radio.SignalInformation>) => {
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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { radio } from '@kit.TelephonyKit';

let callback: (data: Array<radio.SignalInformation>) => void = (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
```


## observer.on('callStateChange')

on(type: 'callStateChange', callback: Callback\<CallStateInfo\>): void

Registers an observer for call status change events. This API uses an asynchronous callback to return the execution result.

>**NOTE**
>
>Before using this API, you must declare the **ohos.permission.READ_CALL_LOG** permission (a system permission).

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                       |
| -------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | string                                        | Yes  | Call status change event. This field has a fixed value of **callStateChange**.               |
| callback | Callback\<[CallStateInfo](#callstateinfo11)\> | Yes  | Callback used to return the result. For details, see [CallState](js-apis-call.md#callstate).<br>**number**: phone number.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
observer.on('callStateChange', (data: observer.CallStateInfo) => {
    console.log("on callStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('callStateChange')

on(type: 'callStateChange', options: ObserverOptions, callback: Callback\<CallStateInfo\>): void

Registers an observer for call status change events. This API uses an asynchronous callback to return the execution result.

>**NOTE**
>
>Before using this API, you must declare the **ohos.permission.READ_CALL_LOG** permission (a system permission).

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Call status change event. This field has a fixed value of **callStateChange**.              |
| options  | [ObserverOptions](#observeroptions11)                        | Yes  | Event subscription parameters.                                 |
| callback | Callback\<[CallStateInfo](#callstateinfo11)\>                | Yes  | Callback used to return the result. For details, see [CallState](js-apis-call.md#callstate).<br>**number**: phone number.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('callStateChange', options, (data: observer.CallStateInfo) => {
    console.log("on callStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('callStateChange')

off(type: 'callStateChange', callback?: Callback\<CallStateInfo\>): void

Unregisters the observer for call status change events. This API uses an asynchronous callback to return the execution result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | Yes  | Call status change event. This field has a fixed value of **callStateChange**.              |
| callback | Callback\<[CallStateInfo](#callstateinfo11)\>                | No  | Callback used to return the result. For details, see [CallState](js-apis-call.md#callstate).<br>**number**: phone number.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let callback: (data: observer.CallStateInfo) => void = (data: observer.CallStateInfo) => {
    console.log("on callStateChange, data:" + JSON.stringify(data));
}
observer.on('callStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('callStateChange', callback);
observer.off('callStateChange');
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', callback: Callback\<DataConnectionStateInfo\>\): void

Registers an observer for connection status change events of the cellular data link. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                              | Mandatory| Description                                                                |
| -------- | --------------------------------- | ---- | -------------------------------------------------------------------- |
| type     | string                            | Yes  | Cellular data connection status event. This field has a fixed value of **cellularDataConnectionStateChange**.|
| callback | Callback\<[DataConnectionStateInfo](#dataconnectionstateinfo11)\>  | Yes  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
observer.on('cellularDataConnectionStateChange', (data: observer.DataConnectionStateInfo) => {
    console.log("on cellularDataConnectionStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', options: ObserverOptions, callback: Callback\<DataConnectionStateInfo\>\): void

Registers an observer for connection status change events of the cellular data link over the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Cellular data connection status event. This field has a fixed value of **cellularDataConnectionStateChange**.|
| options  | [ObserverOptions](#observeroptions11)                        | Yes  | Event subscription parameters.            |
| callback | Callback\<[DataConnectionStateInfo](#dataconnectionstateinfo11)\> | Yes  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('cellularDataConnectionStateChange', options, (data: observer.DataConnectionStateInfo) => {
    console.log("on cellularDataConnectionStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataConnectionStateChange')<sup>7+</sup>

off\(type: 'cellularDataConnectionStateChange',  callback?: Callback\<DataConnectionStateInfo\>\): void

Unregisters the observer for connection status change events of the cellular data link. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Cellular data connection status event. This field has a fixed value of **cellularDataConnectionStateChange**.|
| callback | Callback\<[DataConnectionStateInfo](#dataconnectionstateinfo11)\> | No  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let callback: (data: observer.DataConnectionStateInfo) => void = (data: observer.DataConnectionStateInfo) => {
    console.log("on cellularDataConnectionStateChange, data:" + JSON.stringify(data));
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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

observer.on('cellularDataFlowChange', (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', options: ObserverOptions,  callback: Callback\<DataFlowType\>\): void

Registers an observer for the uplink and downlink data flow status change events of the cellular data service on the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Cellular data flow change event. This field has a fixed value of **cellularDataFlowChange**.        |
| options   | [ObserverOptions](#observeroptions11)                     | Yes  | Event subscription parameters.                                                  |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | Yes  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('cellularDataFlowChange', options, (data: data.DataFlowType) => {
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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
observer.on('simStateChange', (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', options: ObserverOptions, callback: Callback\<SimStateData\>\): void

Registers an observer for status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | SIM status change event. This field has a fixed value of **simStateChange**.                |
| options   | [ObserverOptions](#observeroptions11)                       | Yes  | Event subscription parameters.                                 |
| callback | Callback\<[SimStateData](#simstatedata7)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('simStateChange', options, (data: observer.SimStateData) => {
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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

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


## CallStateInfo<sup>11+</sup>

Defines information about the call status.

**System capability**: SystemCapability.Telephony.StateRegistry

|     Name           |                 Type                   | Mandatory| Description    |
| ------------------- | -------------------------------------- | ---- | -------- |
| state               | [CallState](js-apis-call.md#callstate) | Yes  | Call type.|
| number              | string                                 | Yes  | Phone number.|


## DataConnectionStateInfo<sup>11+</sup>

Defines information about the data connection status.

**System capability**: SystemCapability.Telephony.StateRegistry

|     Name           |                 Type                                           | Mandatory| Description        |
| ------------------- | ---------------------------------------------------------------| ---- | ------------ |
| state               | [DataConnectState](js-apis-telephony-data.md#dataconnectstate) | Yes  | Data connection status.|
| network             | [RatType](js-apis-radio.md#radiotechnology)                    | Yes  | Network type.    |


## ObserverOptions<sup>11+</sup>

Defines event subscription parameters.

**System capability**: SystemCapability.Telephony.StateRegistry

|     Name           |         Type     | Mandatory | Description                                   |
| ------------------- | ------------------| ---- | --------------------------------------- |
| slotId              | number            | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2   |
