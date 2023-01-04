# Observer

The observer module provides event subscription management functions. You can register or unregister an observer that listens for the following events: network status change, signal status change, call status change, cellular data connection status, uplink and downlink data flow status of cellular data services, and SIM status change.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import observer from '@ohos.telephony.observer'
```

## observer.on('networkStateChange')

on\(type: \'networkStateChange\', callback: Callback<NetworkState\>\): void;

Registers an observer for network status change events. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Network status change event.                                            |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | Yes  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Example**

```js
observer.on('networkStateChange', data =>{ 
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')

on\(type: \'networkStateChange\', options: { slotId: number }, callback: Callback<NetworkState\>\): void;

Registers an observer for network status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| type     | string                                    | Yes  | Network status change event.                 |
| slotId | number | Yes  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | Yes  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Example**

```js
observer.on('networkStateChange', {slotId: 0}, data =>{ 
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('networkStateChange')

off\(type: \'networkStateChange\', callback?: Callback<NetworkState\>\): void;

Unregisters the observer for network status change events. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Network status change event.                                            |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | No  | Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#networkstate).|

**Example**

```js
let callback = data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
}
observer.on('networkStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('networkStateChange', callback);
observer.off('networkStateChange');
```

## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', callback: Callback<Array<SignalInformation\>\>): void;

Registers an observer for signal status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Signal status change event.                                            |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | Yes  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Example**

```js
observer.on('signalInfoChange', data =>{ 
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', options: { slotId: number }, callback: Callback<Array<SignalInformation\>\>): void;

Registers an observer for signal status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| type     | string                                    | Yes  | Signal status change event.               |
| slotId | number | Yes  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | Yes  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Example**

```js
observer.on('signalInfoChange', {slotId: 0}, data =>{ 
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('signalInfoChange')

off\(type: \'signalInfoChange\', callback?: Callback<Array<SignalInformation\>\>): void;

Unregisters the observer for signal status change events. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Signal status change event.                                            |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | No  | Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#signalinformation).|

**Example**

```js
let callback = data => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
```


## observer.on('callStateChange')

on(type: 'callStateChange', callback: Callback\<{ state: CallState, number: string }\>): void;

Registers an observer for call status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Call status change event.                                            |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | Yes  | Callback function. For details, see [CallState](js-apis-call.md#callstate) in call.<br>**number**: phone number.|

**Example**

```js
observer.on('callStateChange', value =>{ 
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.on('callStateChange')

on(type: 'callStateChange', options: { slotId: number }, callback: Callback<{ state:CallState, number: string }>): void;

Registers an observer for call status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Call status change event.                                            |
| slotId   | number                                                       | Yes  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | Yes  | Callback function. For details, see [CallState](js-apis-call.md#callstate) in call.<br>**number**: phone number.|

**Example**

```js
observer.on('callStateChange', {slotId: 0}, value =>{ 
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.off('callStateChange')

off(type: 'callStateChange', callback?: Callback<{ state: CallState, number: string }>): void;

Unregisters the observer for call status change events. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Call status change event.                                            |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | No  | Callback function. For details, see [CallState](js-apis-call.md#callstate) in call.<br>**number**: phone number.|

**Example**

```js
let callback = value => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
}
observer.on('callStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('callStateChange', callback);
observer.off('callStateChange');
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', callback: Callback\<{ state: DataConnectState, network: RatType}\>\): void;

Registers an observer for connection status change events of the cellular data connection.This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Connection status change event of the cellular data connection.                                    |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | Yes  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Example**

```js
observer.on('cellularDataConnectionStateChange', value =>{
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', options: { slotId: number }, callback: Callback\<{ state: DataConnectState, network: RatType }\>\): void;

Registers an observer for connection status change events of the cellular data connection over the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Connection status change event of the cellular data connection.                                   |
| slotId   | number                                                       | Yes  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | Yes  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Example**

```js
observer.on('cellularDataConnectionStateChange', {slotId: 0}, value =>{
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.off('cellularDataConnectionStateChange')<sup>7+</sup>

off\(type: 'cellularDataConnectionStateChange',  callback?: Callback\<{ state: DataConnectState, network: RatType}\>\): void;

Unregisters the observer for connection status change events of the cellular data connection.This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Connection status change event of the cellular data connection.                                   |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | No  | Callback used to return the result. For details, see [DataConnectState](js-apis-telephony-data.md#dataconnectstate) and [RadioTechnology](js-apis-radio.md#radiotechnology).|

**Example**

```js
let callback = value => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
}
observer.on('cellularDataConnectionStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('cellularDataConnectionStateChange', callback);
observer.off('cellularDataConnectionStateChange');
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType\>\): void;

Registers an observer for the uplink and downlink data flow status change events of the cellular data service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Uplink and downlink data flow status change event of the cellular data service.                      |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | Yes  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Example**

```js
observer.on('cellularDataFlowChange', data =>{
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', options: { slotId: number },  callback: Callback\<DataFlowType\>\): void;

Registers an observer for the uplink and downlink data flow status change events of the cellular data service on the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Uplink and downlink data flow status change event of the cellular data service.                          |
| slotId   | number                                                       | Yes  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | Yes  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Example**

```js
observer.on('cellularDataFlowChange', {slotId: 0}, data =>{
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataFlowChange')<sup>7+</sup>

off\(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType\>\): void;

Unregisters the observer for the uplink and downlink data flow status change events of the cellular data service. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Uplink and downlink data flow status change event of the cellular data service.                          |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | No  | Callback used to return the result. For details, see [DataFlowType](js-apis-telephony-data.md#dataflowtype).|

**Example**

```js
let callback = data => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
}
observer.on('cellularDataFlowChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('cellularDataFlowChange', callback);
observer.off('cellularDataFlowChange');
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', callback: Callback\<SimStateData\>\): void;

Registers an observer for SIM card status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | SIM card status change event.                                    |
| callback | Callback\<[SimStateData](#simstatedata7)\> | Yes  | Callback used to return the result.|

**Example**

```js
observer.on('simStateChange', data =>{
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData\>\): void;

Registers an observer for status change events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | SIM card status change event.                                    |
| slotId   | number                                                       | Yes  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | Callback\<[SimStateData](#simstatedata7)\> | Yes  | Callback used to return the result.|

**Example**

```js
observer.on('simStateChange', {slotId: 0}, data =>{
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('simStateChange')<sup>7+</sup>

off\(type: 'simStateChange', callback?: Callback\<SimStateData\>\): void;

Unregisters the observer for SIM card status change events. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | SIM card status change event.                                            |
| callback | Callback\<[SimStateData](#simstatedata7)\> | No  | Callback used to return the result.|

**Example**

```js
let callback = data => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
}
observer.on('simStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('simStateChange', callback);
observer.off('simStateChange');
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

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| type  | [CardType](js-apis-sim.md#cardtype) | Yes| SIM card type. For details, see [CardType](js-apis-sim.md#cardtype).|
| state | [SimState](js-apis-sim.md#simstate) | Yes| SIM card status. For details, see [SimState](js-apis-sim.md#simstate).|
| reason<sup>8+</sup>       | [LockReason](#lockreason8) | Yes| SIM card lock type.|
