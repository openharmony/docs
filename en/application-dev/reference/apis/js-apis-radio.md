# Radio

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import radio from '@ohos.telephony.radio'
```

## radio.getRadioTech

getRadioTech\(slotId: number, callback: AsyncCallback<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>\): void

Obtains the radio access technology (RAT) used by the CS and PS domains. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<{psRadioTech: [RadioTechnology](#radiotechnology), csRadioTech:[RadioTechnology](#radiotechnology)}\> | Yes  | Callback used to return the result.                            |

**Example**

```js
let slotId = 0;
radio.getRadioTech(slotId, (err, data) =>{ 
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getRadioTech

getRadioTech\(slotId: number\): Promise<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>

Obtains the RAT used by the CS and PS domains. This API uses a promise to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                        | Description                                           |
| ------------------------------------------------------------ | ----------------------------------------------- |
| Promise<{psRadioTech: [RadioTechnology](#radiotechnology), csRadioTech: [RadioTechnology](#radiotechnology)}> | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let promise = radio.getRadioTech(slotId);
promise.then(data => {
    console.log(`getRadioTech success, data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getRadioTech fail, err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkState

getNetworkState\(callback: AsyncCallback<NetworkState\>\): void

Obtains the network status. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                          | Mandatory| Description      |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetworkState](#networkstate)\> | Yes  | Callback used to return the result.|

**Example**

```js
radio.getNetworkState((err, data) =>{
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState

getNetworkState\(slotId: number, callback: AsyncCallback<NetworkState\>\): void

Obtains the network status. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                          | Mandatory| Description                                  |
| -------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                         | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NetworkState](#networkstate)\> | Yes  | Callback used to return the result.                            |

**Example**

```js
let slotId = 0;
radio.getNetworkState(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState

getNetworkState\(slotId?: number\): Promise<NetworkState\>

Obtains the network status of the SIM card in the specified slot. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                    | Description                       |
| ---------------------------------------- | --------------------------- |
| Promise\<[NetworkState](#networkstate)\> | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let promise = radio.getNetworkState(slotId);
promise.then(data => {
    console.log(`getNetworkState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getNetworkState fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkSelectionMode

getNetworkSelectionMode\(slotId: number, callback: AsyncCallback<NetworkSelectionMode\>\): void

Obtains the network selection mode of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NetworkSelectionMode](#networkselectionmode)\> | Yes  | Callback used to return the result.                            |

**Example**

```js
let slotId = 0;
radio.getNetworkSelectionMode(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkSelectionMode

getNetworkSelectionMode\(slotId: number\): Promise<NetworkSelectionMode\>

Obtains the network selection mode of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                    | Description                           |
| -------------------------------------------------------- | ------------------------------- |
| Promise\<[NetworkSelectionMode](#networkselectionmode)\> | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let promise = radio.getNetworkSelectionMode(slotId);
promise.then(data => {
    console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getNetworkSelectionMode fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup>

getISOCountryCodeForNetwork\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                    |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2  |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result. which is a country code, for example, **CN** (China).|

**Example**

```js
let slotId = 0;
radio.getISOCountryCodeForNetwork(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup>

getISOCountryCodeForNetwork\(slotId: number\): Promise<string\>

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the result, which is an ISO country code, for example, **CN** (China).|

**Example**

```js
let slotId = 0;
let promise = radio.getISOCountryCodeForNetwork(slotId);
promise.then(data => {
    console.log(`getISOCountryCodeForNetwork success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getISOCountryCodeForNetwork fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getPrimarySlotId<sup>7+</sup>

getPrimarySlotId\(callback: AsyncCallback\<number\>\): void

Obtains the ID of the slot in which the primary card is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Example**

```js
radio.getPrimarySlotId((err, data) => {
   console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getPrimarySlotId<sup>7+</sup>

getPrimarySlotId\(\): Promise\<number\>

Obtains the ID of the slot in which the primary card is located. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Example**

```js
let promise = radio.getPrimarySlotId();
promise.then(data => {
    console.log(`getPrimarySlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getPrimarySlotId fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getSignalInformation<sup>7+</sup>

getSignalInformation\(slotId: number, callback: AsyncCallback<Array<SignalInformation\>\>\): void

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | AsyncCallback\<Array\<[SignalInformation](#signalinformation)\>\> | Yes  | Callback used to return the result, which is a list of [SignalInformation](#signalinformation) objects.|

**Example**

```js
let slotId = 0;
radio.getSignalInformation(slotId, (err, data) => {
   console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getSignalInformation<sup>7+</sup>

getSignalInformation\(slotId: number\): Promise<Array<SignalInformation\>\>

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This API uses a promise to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[SignalInformation](#signalinformation)\>\> | Promise used to return the result, which is a list of [SignalInformation](#signalinformation) objects.|

**Example**

```js
let slotId = 0;
let promise = radio.getSignalInformation(slotId);
promise.then(data => {
    console.log(`getSignalInformation success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSignalInformation fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.isNrSupported<sup>8+</sup>

isNrSupported\(slotId: number\): boolean

Checks whether the current device supports 5G \(NR\).

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| boolean | - **true**: The current device supports 5G \(NR\).<br>- **false**: The current device does not support 5G \(NR\).|

**Example**

```js
let slotId = 0;
let result = radio.isNrSupported(slotId);
console.log("result is "+ result);
```


## radio.isRadioOn<sup>7+</sup>

isRadioOn\(callback: AsyncCallback<boolean\>\): void

Checks whether the radio service is enabled on the primary SIM card. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>- **true**: The radio service is enabled.<br>- **false**: The radio service is disabled.|

**Example**

```js
radio.isRadioOn((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup>

isRadioOn\(slotId: number, callback: AsyncCallback<boolean\>\): void

Checks whether the radio service is enabled on the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| slotId   | number                   | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                 |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>- **true**: The radio service is enabled.<br>- **false**: The radio service is disabled.|

**Example**

```js
let slotId = 0;
radio.isRadioOn(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup>

isRadioOn\(slotId?: number\): Promise<boolean\>

Checks whether the radio service is enabled. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2<br>If the slot ID is not specified, this API is defaulted to check whether the radio service is enabled on the primary SIM card.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>- **true**: The radio service is enabled.<br>- **false**: The radio service is disabled.|

**Example**

```js
let slotId = 0;
let promise = radio.isRadioOn(slotId);
promise.then(data => {
    console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isRadioOn fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getOperatorName<sup>7+</sup>

getOperatorName\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the carrier name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2    |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result, which is the carrier name, for example, China Mobile.|

**Example**

```js
let slotId = 0;
radio.getOperatorName(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getOperatorName<sup>7+</sup>

getOperatorName\(slotId: number\): Promise<string\>

Obtains the carrier name. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used t return the result, which is the carrier name, for example, China Mobile.               |

**Example**

```js
let slotId = 0;
let promise = radio.getOperatorName(slotId);
promise.then(data => {
    console.log(`getOperatorName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOperatorName fail, promise: err->${JSON.stringify(err)}`);
});
```


## RadioTechnology

Enumerates the RATs.

**System capability**: SystemCapability.Telephony.CoreService

| Name                     | Value  | Description                                                        |
| ------------------------- | ---- | ------------------------------------------------------------ |
| RADIO_TECHNOLOGY_UNKNOWN  | 0    | Unknown RAT                                   |
| RADIO_TECHNOLOGY_GSM      | 1    | Global System for Mobile Communication (GSM) |
| RADIO_TECHNOLOGY_1XRTT    | 2    | Single-Carrier Radio Transmission Technology (1XRTT)|
| RADIO_TECHNOLOGY_WCDMA    | 3    | Wideband Code Division Multiple Access (WCDMA)|
| RADIO_TECHNOLOGY_HSPA     | 4    | High Speed Packet Access (HSPA)              |
| RADIO_TECHNOLOGY_HSPAP    | 5    | Evolved High Speed Packet Access (HSPA+)    |
| RADIO_TECHNOLOGY_TD_SCDMA | 6    | Time Division Synchronous Code Division Multiple Access (TD-SCDMA)|
| RADIO_TECHNOLOGY_EVDO     | 7    | Evolution-Data Optimized (EVDO)                  |
| RADIO_TECHNOLOGY_EHRPD    | 8    | Evolved High Rate Package Data (EHRPD)       |
| RADIO_TECHNOLOGY_LTE      | 9    | Long Term Evolution (LTE)                    |
| RADIO_TECHNOLOGY_LTE_CA   | 10   | Long Term Evolution_Carrier Aggregation (LTE_CA)|
| RADIO_TECHNOLOGY_IWLAN    | 11   | Industrial Wireless LAN (IWLAN)              |
| RADIO_TECHNOLOGY_NR       | 12   | New Radio (NR)                               |


## SignalInformation

Defines the signal strength.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type                       | Description              |
| ----------- | --------------------------- | ------------------ |
| signalType  | [NetworkType](#networktype) | Signal strength type.|
| signalLevel | number                      | Signal strength level.|


## NetworkType

Defines the network type.

**System capability**: SystemCapability.Telephony.CoreService

| Name                | Value  | Description                                                        |
| -------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_TYPE_UNKNOWN | 0    | Unknown network.                                              |
| NETWORK_TYPE_GSM     | 1    | GSM network.   |
| NETWORK_TYPE_CDMA    | 2    | CDMA network.           |
| NETWORK_TYPE_WCDMA   | 3    | WCDMA network. |
| NETWORK_TYPE_TDSCDMA | 4    | TD-SCDMA network.|
| NETWORK_TYPE_LTE     | 5    | LTE network.                      |
| NETWORK_TYPE_NR      | 6    | 5G NR network.                              |

## NetworkState

Defines the network registration status.

**System capability**: SystemCapability.Telephony.CoreService

| Name           | Type                 | Description                                                        |
| ----------------- | --------------------- | ------------------------------------------------------------ |
| longOperatorName  | string                | Long carrier name of the registered network.|
| shortOperatorName | string                | Short carrier name of the registered network.|
| plmnNumeric       | string                | PLMN code of the registered network.|
| isRoaming         | boolean               | Whether the user is roaming.|
| regState          | [RegState](#regstate) | Network registration status of the device.|
| cfgTech<sup>8+</sup> | [RadioTechnology](#radiotechnology) | RAT of the device.|
| nsaState          | [NsaState](#nsastate) | NSA network registration status of the device.|
| isCaActive        | boolean               | CA status.|
| isEmergency       | boolean               | Whether only emergency calls are allowed.|


## RegState

Defines the network registration status.

**System capability**: SystemCapability.Telephony.CoreService

| Name                         | Value  | Description                      |
| ----------------------------- | ---- | -------------------------- |
| REG_STATE_NO_SERVICE          | 0    | The device cannot use any service.    |
| REG_STATE_IN_SERVICE          | 1    | The device can use services normally.     |
| REG_STATE_EMERGENCY_CALL_ONLY | 2    | The device can use only the emergency call service.|
| REG_STATE_POWER_OFF           | 3    | The cellular radio service is disabled.        |


## NsaState

Enumerates NSA network states.

**System capability**: SystemCapability.Telephony.CoreService

| Name                      | Value  | Description                                                      |
| -------------------------- | ---- | ---------------------------------------------------------- |
| NSA_STATE_NOT_SUPPORT      | 1    | The device is in idle or connected state in an LTE cell that does not support NSA.        |
| NSA_STATE_NO_DETECT        | 2    | The device is in the idle state in an LTE cell that supports NSA but not NR coverage detection.|
| NSA_STATE_CONNECTED_DETECT | 3    | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection.         |
| NSA_STATE_IDLE_DETECT      | 4    | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection.          |
| NSA_STATE_DUAL_CONNECTED   | 5    | The device is connected to the LTE/NR network in an LTE cell that supports NSA.              |
| NSA_STATE_SA_ATTACHED      | 6    | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core.     |


## NetworkSelectionMode

Enumerates network selection modes.

**System capability**: SystemCapability.Telephony.CoreService

| Name                       | Value  | Description          |
| --------------------------- | ---- | -------------- |
| NETWORK_SELECTION_UNKNOWN   | 0    | Unknown network selection mode.|
| NETWORK_SELECTION_AUTOMATIC | 1    | Automatic network selection mode.|
| NETWORK_SELECTION_MANUAL    | 2    | Manual network selection mode.|
