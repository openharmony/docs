# Radio

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import radio from '@ohos.telephony.radio'
```

## radio.getRadioTech<a name=radio.getRadioTech-callback></a>

getRadioTech\(slotId: number, callback: AsyncCallback<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>\): void

Obtains the radio access technology (RAT) used by the CS and PS domains. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | AsyncCallback\<{psRadioTech: [RadioTechnology](#RadioTechnology), csRadioTech:[RadioTechnology](#RadioTechnology)}\> | Yes| Callback used to return the result.|

**Example**

```
let slotId = 0;
radio.getRadioTech(slotId, (err, data) =>{ 
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getRadioTech<a name=radio.getRadioTech-promise></a>

getRadioTech\(slotId: number\): Promise<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>

Obtains the RAT used by the CS and PS domains. This function uses a promise to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Return value**

| Type| Description|
| ------------------------------------------------------------ | ----------------------------------------------- |
| Promise<{psRadioTech: [RadioTechnology](#RadioTechnology), csRadioTech: [RadioTechnology](#RadioTechnology)}> | Promise used to return the result.|

**Example**

```
let slotId = 0;
let promise = radio.getRadioTech(slotId);
promise.then(data => {
    console.log(`getRadioTech success, data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getRadioTech fail, err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkState<a name=radio.getNetworkState-callback1></a>

getNetworkState\(callback: AsyncCallback<NetworkState\>\): void

Obtains the network status. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetworkState](#NetworkState)\> | Yes| Callback used to return the result.|

**Example**

```
radio.getNetworkState((err, data) =>{
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState<a name=radio.getNetworkState-callback2></a>

getNetworkState\(slotId: number, callback: AsyncCallback<NetworkState\>\): void

Obtains the network status of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                         | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | AsyncCallback\<[NetworkState](#NetworkState)\> | Yes| Callback used to return the result.|

**Example**

```
let slotId = 0;
radio.getNetworkState(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState<a name=radio.getNetworkState-promise></a>

getNetworkState\(slotId?: number\): Promise<NetworkState\>

Obtains the network status of the SIM card in the specified slot. This function uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Return value**

| Type| Description|
| ---------------------------------------- | --------------------------- |
| Promise\<[NetworkState](#NetworkState)\> | Promise used to return the result.|

**Example**

```
let slotId = 0;
let promise = radio.getNetworkState(slotId);
promise.then(data => {
    console.log(`getNetworkState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getNetworkState fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkSelectionMode<a name=radio.getNetworkSelectionMode-callback></a>

getNetworkSelectionMode\(slotId: number, callback: AsyncCallback<NetworkSelectionMode\>\): void

Obtains the network selection mode of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | AsyncCallback\<[NetworkSelectionMode](#NetworkSelectionMode)\> | Yes| Callback used to return the result.|

**Example**

```
let slotId = 0;
radio.getNetworkSelectionMode(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkSelectionMode<a name=radio.getNetworkSelectionMode-promise></a>

getNetworkSelectionMode\(slotId: number\): Promise<NetworkSelectionMode\>

Obtains the network selection mode of the SIM card in the specified slot. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Return value**

| Type| Description|
| -------------------------------------------------------- | ------------------------------- |
| Promise\<[NetworkSelectionMode](#NetworkSelectionMode)\> | Promise used to return the result.|

**Example**

```
let slotId = 0;
let promise = radio.getNetworkSelectionMode(slotId);
promise.then(data => {
    console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getNetworkSelectionMode fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name=radio.getISOCountryCodeForNetwork-callback></a>

getISOCountryCodeForNetwork\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | AsyncCallback\<string\> | Yes| Callback used to return the result. which is a country code, for example, **CN** (China).|

**Example**

```
let slotId = 0;
radio.getISOCountryCodeForNetwork(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name=radio.getISOCountryCodeForNetwork-promise></a>

getISOCountryCodeForNetwork\(slotId: number\): Promise<string\>

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Return value**

| Type| Description|
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the result, which is an ISO country code, for example, **CN** (China).|

**Example**

```
let slotId = 0;
let promise = radio.getISOCountryCodeForNetwork(slotId);
promise.then(data => {
    console.log(`getISOCountryCodeForNetwork success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getISOCountryCodeForNetwork fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getSignalInformation<a name=radio.getSignalInformation-callback></a>

getSignalInformation\(slotId: number, callback: AsyncCallback<Array<SignalInformation\>\>\): void

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This function uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                                                       | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
| callback | AsyncCallback\<Array\<[SignalInformation](#SignalInformation)\>\> | Yes| Callback used to return the result, which is a list of [SignalInformation](#SignalInformation) objects.|

**Example**

```
let slotId = 0;
radio.getSignalInformation(slotId, (err, data) => {
   console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getSignalInformation<a name=radio.getSignalInformation-promise></a>

getSignalInformation\(slotId: number\): Promise<Array<SignalInformation\>\>

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This function uses a promise to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Return value**

| Type| Description|
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[SignalInformation](#SignalInformation)\>\> | Promise used to return the result, which is a list of [SignalInformation](#SignalInformation) objects.|

**Example**

```
let slotId = 0;
let promise = radio.getSignalInformation(slotId);
promise.then(data => {
    console.log(`getSignalInformation success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSignalInformation fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.isRadioOn<sup>7+</sup><a name=radio.isRadioOn-callback></a>

isRadioOn\(callback: AsyncCallback<boolean\>\): void

Checks whether the radio service is enabled on the primary SIM card. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes| Callback used to return the result. <br/> - **true**: The radio service is enabled.<br/> - **false**: The radio service is disabled.|

**Example**

```
radio.isRadioOn((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup><a name=radio.isRadioOn.slot-callback></a>

isRadioOn\(slotId: number, callback: AsyncCallback<boolean\>\): void

Checks whether the radio service is enabled on the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| slotId   | number                   | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
| callback | AsyncCallback\<boolean\> | Yes| Callback used to return the result. <br/> - **true**: The radio service is enabled.<br/> - **false**: The radio service is disabled.|

**Example**

```
let slotId = 0;
radio.isRadioOn(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup><a name=radio.isRadioOn.slot-promise></a>

isRadioOn\(slotId?: number\): Promise<boolean\>

Checks whether the radio service is enabled. This function uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No| Card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2<br/>If the slot ID is not specified, this function is defaulted to check whether the radio service is enabled on the primary SIM card.|

**Return value**

| Type| Description|
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. <br/> - **true**: The radio service is enabled.<br/> - **false**: The radio service is disabled.|

**Example**

```
let slotId = 0;
let promise = radio.isRadioOn(slotId);
promise.then(data => {
    console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isRadioOn fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getOperatorName<sup>7+</sup><a name=radio.getOperatorName-callback></a>

getOperatorName\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the carrier name. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------- | ---- | ------------------------------------------ |
| slotId   | number                  | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| callback | AsyncCallback\<string\> | Yes| Callback used to return the result, which is the carrier name, for example, China Mobile.|

**Example**

```
let slotId = 0;
radio.getOperatorName(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getOperatorName<sup>7+</sup><a name=radio.getOperatorName-promise></a>

getOperatorName\(slotId: number\): Promise<string\>

Obtains the carrier name. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Return value**

| Type| Description|
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used t return the result, which is the carrier name, for example, China Mobile.|

**Example**

```
let slotId = 0;
let promise = radio.getOperatorName(slotId);
promise.then(data => {
    console.log(`getOperatorName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOperatorName fail, promise: err->${JSON.stringify(err)}`);
});
```


## RadioTechnology<a name=RadioTechnology></a>

Enumerates the RATs.

| Variable| Value| Description|
| ------------------------- | ---- | ------------------------------------------------------------ |
| RADIO_TECHNOLOGY_UNKNOWN  | 0    | Unknown RAT <br>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_GSM      | 1    | Global System for Mobile Communication (GSM) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_1XRTT    | 2    | Single-Carrier Radio Transmission Technology (1XRTT) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_WCDMA    | 3    | Wideband Code Division Multiple Access (WCDMA) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_HSPA     | 4    | High Speed Packet Access (HSPA) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_HSPAP    | 5    | Evolved High Speed Packet Access (HSPA+) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_TD_SCDMA | 6    | Time Division Synchronous Code Division Multiple Access (TD-SCDMA) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_EVDO     | 7    | Evolution-Data Optimized (EVDO) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_EHRPD    | 8    | Evolved High Rate Package Data (EHRPD) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_LTE      | 9    | Long Term Evolution (LTE) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_LTE_CA   | 10   | Long Term Evolution_Carrier Aggregation (LTE_CA) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_IWLAN    | 11   | Industrial Wireless LAN (IWLAN) <br/>**System capability**: SystemCapability.Telephony.CoreService|
| RADIO_TECHNOLOGY_NR       | 12   | New Radio (NR) <br/>**System capability**: SystemCapability.Telephony.CoreService|


## SignalInformation<a name=SignalInformation></a>

Defines the signal strength.

| Attribute| Type| Description|
| ----------- | --------------------------- | ------------------------------------------------------------ |
| signalType  | [NetworkType](#NetworkType) | Signal strength type. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| signalLevel | number                      | Signal strength level. <br/>**System capability**: SystemCapability.Telephony.CoreService|


## NetworkType<a name=NetworkType></a>

Defines the network type.

| Variable| Value| Description|
| -------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_TYPE_UNKNOWN | 0    | Unknown network <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_TYPE_GSM     | 1    | GSM network <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_TYPE_CDMA    | 2    | CDMA network <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_TYPE_WCDMA   | 3    | WCDMA network <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_TYPE_TDSCDMA | 4    | TD-SCDMA network <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_TYPE_LTE     | 5    | LTE network <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_TYPE_NR      | 6    | 5G NR network <br/>**System capability**: SystemCapability.Telephony.CoreService|

## NetworkState<a name=NetworkState></a>

Defines the network registration status.

| Variable| Type| Description|
| ----------------- | --------------------- | ------------------------------------------------------------ |
| longOperatorName  | string                | Long carrier name of the registered network. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| shortOperatorName | string                | Short carrier name of the registered network. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| plmnNumeric       | string                | PLMN code of the registered network. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| isRoaming         | boolean               | Whether the user is roaming. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| regState          | [RegState](#RegState) | Network registration status of the device. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| cfgTech<sup>8+</sup> | [RadioTechnology](#RadioTechnology) | RAT of the device. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| nsaState          | [NsaState](#NsaState) | NSA network registration status of the device. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| isCaActive        | boolean               | CA status. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| isEmergency       | boolean               | Whether only emergency calls are allowed. <br/>**System capability**: SystemCapability.Telephony.CoreService|


## RegState<a name=RegState></a>

Defines the network registration status.

| Variable| Value| Description|
| ----------------------------- | ---- | ------------------------------------------------------------ |
| REG_STATE_NO_SERVICE          | 0    | The device cannot use any service. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| REG_STATE_IN_SERVICE          | 1    | The device can use services normally. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| REG_STATE_EMERGENCY_CALL_ONLY | 2    | The device can use only the emergency call service. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| REG_STATE_POWER_OFF           | 3    | The cellular radio service is disabled. <br/>**System capability**: SystemCapability.Telephony.CoreService|


## NsaState<a name=NsaState></a>

Enumerates NSA network states.

| Variable| Value| Description|
| -------------------------- | ---- | ------------------------------------------------------------ |
| NSA_STATE_NOT_SUPPORT      | 1    | The device is in idle or connected state in an LTE cell that does not support NSA. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NSA_STATE_NO_DETECT        | 2    | The device is in the idle state in an LTE cell that supports NSA but does not support NR coverage detection. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NSA_STATE_CONNECTED_DETECT | 3    | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NSA_STATE_IDLE_DETECT      | 4    | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NSA_STATE_DUAL_CONNECTED   | 5    | The device is connected to the LTE/NR network in an LTE cell that supports NSA. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NSA_STATE_SA_ATTACHED      | 6    | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core. <br/>**System capability**: SystemCapability.Telephony.CoreService|


## NetworkSelectionMode<a name=NetworkSelectionMode></a>

Enumerates network selection modes.

| Variable| Value| Description|
| --------------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_SELECTION_UNKNOWN   | 0    | Unknown network selection mode. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_SELECTION_AUTOMATIC | 1    | Automatic network selection mode. <br/>**System capability**: SystemCapability.Telephony.CoreService|
| NETWORK_SELECTION_MANUAL    | 2    | Manual network selection mode. <br/>**System capability**: SystemCapability.Telephony.CoreService|
