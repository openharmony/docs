# Observer

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import observer from '@ohos.telephony.observer'
```

## observer.on('networkStateChange')<a name=observer.on.networkStateChange-callback></a>

on\(type: \'networkStateChange\', callback: Callback<NetworkState\>\): void;

Registers an observer for network status change events. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------------------------- | ---- | --------------------------------- |
| type     | string                                    | Yes| Network status change event.|
| callback | Callback\<[NetworkState](js-apis-radio.md#NetworkState)\> | Yes| Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#NetworkState).|

**Example**

```
observer.on('networkStateChange', data =>{ 
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')<a name=observer.on.networkStateChange.options-callback></a>

on\(type: \'networkStateChange\', options: { slotId: number }, callback: Callback<NetworkState\>\): void;

Registers an observer for network status change events of the SIM card in the specified slot. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| type     | string                                    | Yes| Network status change event.|
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | Callback\<[NetworkState](js-apis-radio.md#NetworkState)\> | Yes| Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#NetworkState).|

**Example**

```
observer.on('networkStateChange', {slotId: 0}, data =>{ 
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('networkStateChange')<a name=observer.off.networkStateChange-callback></a>

off\(type: \'networkStateChange\', callback?: Callback<NetworkState\>\): void;

Unregisters the observer for network status change events. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------ | ---- | --------------------------------- |
| type     | string                   | Yes| Network status change event.|
| callback | Callback\<[NetworkState](js-apis-radio.md#NetworkState)\> | No| Callback used to return the result. For details, see [NetworkState](js-apis-radio.md#NetworkState).|

**Example**

```
let callback = data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
}
observer.on('networkStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('networkStateChange', callback);
observer.off('networkStateChange');
```

## observer.on('signalInfoChange')<a name=observer.on.signalInfoChange-callback></a>

on\(type: \'signalInfoChange\', callback: Callback<Array<SignalInformation\>\>): void;

Registers an observer for signal status change events. This function uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes| Signal status change event.|
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#SignalInformation)\>\> | Yes| Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#SignalInformation).|

**Example**

```
observer.on('signalInfoChange', data =>{ 
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')<a name=observer.on.signalInfoChange.options-callback></a>

on\(type: \'signalInfoChange\', options: { slotId: number }, callback: Callback<Array<SignalInformation\>\>): void;

Registers an observer for signal status change events of the SIM card in the specified slot. This function uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| type     | string                                    | Yes| Signal status change event.|
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#SignalInformation)\>\> | Yes| Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#SignalInformation).|

**Example**

```
observer.on('signalInfoChange', {slotId: 0}, data =>{ 
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('signalInfoChange')<a name=observer.off.signalInfoChange-callback></a>

off\(type: \'signalInfoChange\', callback?: Callback<Array<SignalInformation\>\>): void;

Unregisters the observer for signal status change events. This function uses an asynchronous callback to return the execution result.

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes| Signal status change event.|
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#SignalInformation)\>\> | No| Callback used to return the result. For details, see [SignalInformation](js-apis-radio.md#SignalInformation).|

**Example**

```
let callback = data => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
```


## observer.on('callStateChange')<a name=observer.on.callStateChange-callback></a>

on(type: 'callStateChange', callback: Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\>): void;

Registers an observer for call status change events. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.READ_CALL_LOG

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes| Call status change event.|
| callback | Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\> | Yes| Callback used to return the result. For details, see [CallState](js-apis-call.md#CallState)<br />**number**: phone number.|

**Example**

```
observer.on('callStateChange', value =>{ 
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.on('callStateChange')<a name=observer.on.callStateChange.options-callback></a>

on(type: 'callStateChange', options: { slotId: number }, callback: Callback<{ state: [CallState](js-apis-call.md#CallState), number: string }>): void;

Registers an observer for call status change events. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.READ_CALL_LOG

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes| Call status change event.|
| slotId   | number                                                       | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
| callback | Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\> | Yes| Callback used to return the result. For details, see [CallState](js-apis-call.md#CallState)<br />**number**: phone number.|

**Example**

```
observer.on('callStateChange', {slotId: 0}, value =>{ 
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.off('callStateChange')<a name=observer.off.callStateChange-callback></a>

off(type: 'callStateChange', callback?: Callback<{ state: [CallState](js-apis-call.md#CallState), number: string }>): void;

Unregisters the observer for call status change events. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.READ_CALL_LOG

>**NOTE**
>
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Telephony.StateRegistry

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes| Call status change event.|
| callback | Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\> | No| Callback used to return the result. For details, see [CallState](js-apis-call.md#CallState)<br />**number**: phone number.|

**Example**

```
let callback = value => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
}
observer.on('callStateChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
observer.off('callStateChange', callback);
observer.off('callStateChange');
```
