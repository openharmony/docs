# Radio

>**Note:**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import radio from '@ohos.telephony.radio'
```

## radio.getRadioTech<a name=radio.getRadioTech-callback></a>

getRadioTech\(slotId: number, callback: AsyncCallback<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>\): void

Obtains the radio access technologies (RATs) used by the CS and PS domains. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
  | slotId   | number                                                       | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
  | callback | AsyncCallback\<{psRadioTech: [RadioTechnology](#RadioTechnology), csRadioTech:[RadioTechnology](#RadioTechnology)}\> | Yes| Callback used to return the result.|

-   Example

    ```
    let slotId = 0;
    radio.getRadioTech(slotId, (err, data) =>{ 
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getRadioTech<a name=radio.getRadioTech-promise></a>

getRadioTech\(slotId: number\): Promise<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>

Obtains the RAT used by the CS and PS domains. This function uses a promise to return the result. 

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | ------------------------------------------------------------ | ----------------------------------------------- |
  | Promise<{psRadioTech: [RadioTechnology](#RadioTechnology), csRadioTech: [RadioTechnology](#RadioTechnology)}> | Promise used to return the result.|

-   Example

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

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ---------------------------------------------- | ---- | ---------- |
  | callback | AsyncCallback\<[NetworkState](#NetworkState)\> | Yes| Callback used to return the result.|

-   Example

    ```
    radio.getNetworkState((err, data) =>{
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getNetworkState<a name=radio.getNetworkState-callback2></a>

getNetworkState\(slotId: number, callback: AsyncCallback<NetworkState\>\): void

Obtains the network status of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ---------------------------------------------- | ---- | -------------------------------------- |
  | slotId   | number                                         | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
  | callback | AsyncCallback\<[NetworkState](#NetworkState)\> | Yes| Callback used to return the result.|

-   Example

    ```
    let slotId = 0;
    radio.getNetworkState(slotId, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getNetworkState<a name=radio.getNetworkState-promise></a>

getNetworkState\(slotId?: number\): Promise<NetworkState\>

Obtains the network status of the SIM card in the specified slot. This function uses a promise to return the result.

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | No| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | ---------------------------------------- | --------------------------- |
  | Promise\<[NetworkState](#NetworkState)\> | Promise used to return the result.|

-   Example

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

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
  | slotId   | number                                                       | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
  | callback | AsyncCallback\<[NetworkSelectionMode](#NetworkSelectionMode)\> | Yes| Callback used to return the result.|

-   Example

    ```
    let slotId = 0;
    radio.getNetworkSelectionMode(slotId, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getNetworkSelectionMode<a name=radio.getNetworkSelectionMode-promise></a>

getNetworkSelectionMode\(slotId: number\): Promise<NetworkSelectionMode\>

Obtains the network selection mode of the SIM card in the specified slot. This function uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | -------------------------------------------------------- | ------------------------------- |
  | Promise\<[NetworkSelectionMode](#NetworkSelectionMode)\> | Promise used to return the result.|

-   Example

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

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | slotId   | number                  | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
  | callback | AsyncCallback\<string\> | Yes| Callback used to return the result, which is a country code, for example, **CN** (China).|

-   Example

    ```
    let slotId = 0;
    radio.getISOCountryCodeForNetwork(slotId, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name=radio.getISOCountryCodeForNetwork-promise></a>

getISOCountryCodeForNetwork\(slotId: number\): Promise<string\>

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This function uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | ----------------- | ------------------------------------------------------------ |
  | Promise\<string\> | Promise used to return the result, which is an ISO country code, for example, **CN** (China).|

-   Example

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

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
  | slotId   | number                                                       | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|
  | callback | AsyncCallback\<Array\<[SignalInformation](#SignalInformation)\>\> | Yes| Callback used to return the result, which is a list of [SignalInformation](#SignalInformation) objects.|

-   Example

    ```
    let slotId = 0;
    radio.getSignalInformation(slotId, (err, data) => {
       console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getSignalInformation<a name=radio.getSignalInformation-promise></a>

getSignalInformation\(slotId: number\): Promise<Array<SignalInformation\>\>

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This function uses a promise to return the result. 

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | Yes| SIM card slot ID. The options are as follows: <br/> - **0**: slot 1<br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | ----------------------------------------------------------- | ------------------------------------------------------------ |
  | Promise\<Array\<[SignalInformation](#SignalInformation)\>\> | Promise used to return the result, which is a list of [SignalInformation](#SignalInformation) objects.|

-   Example

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

Checks whether radio is turned on. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------ | ---- | ------------------------------------------------------- |
  | callback | AsyncCallback\<boolean\> | Yes| Callback used to return the result. <br/> - **true**: Radio is turned on.<br/> - **false**: Radio is turned off.|

-   Example

    ```
    radio.isRadioOn((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.isRadioOn<sup>7+</sup><a name=radio.isRadioOn-promise></a>

isRadioOn\(\): Promise<boolean\>

Checks whether radio is turned on. This function uses a promise to return the result.

Before using this API, you must declare the **ohos.permission.GET\_NETWORK\_INFO** permission.

- Return values

  | Type| Description|
  | ------------------ | ------------------------------------------------------------ |
  | Promise\<boolean\> | Promise used to return the result. <br/> - **true**: Radio is turned on.<br/> - **false**: Radio is turned off.|

-   Example

    ```
    let promise = radio.isRadioOn();
    promise.then(data => {
        console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`isRadioOn fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## RadioTechnology<a name=RadioTechnology></a>

Enumerates the RATs.

| Variable| Value| Description|
| ------------------------- | ---- | ------------------------------------------------------------ |
| RADIO_TECHNOLOGY_UNKNOWN  | 0    | Unknown|
| RADIO_TECHNOLOGY_GSM      | 1    | Global System for Mobile Communication (GSM)|
| RADIO_TECHNOLOGY_1XRTT    | 2    | Single-Carrier Radio Transmission Technology (1XRTT)|
| RADIO_TECHNOLOGY_WCDMA    | 3    | Wideband Code Division Multiple Access (WCDMA)|
| RADIO_TECHNOLOGY_HSPA     | 4    | High Speed Packet Access (HSPA)|
| RADIO_TECHNOLOGY_HSPAP    | 5    | Evolved High Speed Packet Access (HSPA+)|
| RADIO_TECHNOLOGY_TD_SCDMA | 6    | Time Division Synchronous Code Division Multiple Access (TD-SCDMA)|
| RADIO_TECHNOLOGY_EVDO     | 7    | Evolution-Data Optimized (EVDO)|
| RADIO_TECHNOLOGY_EHRPD    | 8    | Evolved High Rate Package Data (EHRPD)|
| RADIO_TECHNOLOGY_LTE      | 9    | Long Term Evolution (LTE)|
| RADIO_TECHNOLOGY_LTE_CA   | 10   | Long Term Evolution_Carrier Aggregation (LTE_CA)|
| RADIO_TECHNOLOGY_IWLAN    | 11   | Industrial Wireless LAN (IWLAN)|
| RADIO_TECHNOLOGY_NR       | 12   | New Radio (NR)|


## SignalInformation<a name=SignalInformation></a>

Defines the signal strength.

| Attribute| Type| Description|
| ----------- | --------------------------- | ------------------ |
| signalType  | [NetworkType](#NetworkType) | Signal strength type.|
| signalLevel | number                      | Signal strength level.|


## NetworkType<a name=NetworkType></a>

Enumerates network types.

| Variable| Value| Description|
| -------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_TYPE_UNKNOWN | 0    | Unknown|
| NETWORK_TYPE_GSM     | 1    | GSM network|
| NETWORK_TYPE_CDMA    | 2    | CDMA network|
| NETWORK_TYPE_WCDMA   | 3    | WCDMA network|
| NETWORK_TYPE_TDSCDMA | 4    | TD-SCDMA network|
| NETWORK_TYPE_LTE     | 5    | LTE network|
| NETWORK_TYPE_NR      | 6    | 5G NR network|

## NetworkState<a name=NetworkState></a>

Defines the network registration status.

| Variable| Type| Description|
| ----------------- | --------------------- | ------------------------------ |
| longOperatorName  | string                | Long carrier name of the registered network.|
| shortOperatorName | string                | Short carrier name of the registered network.|
| plmnNumeric       | string                | PLMN code of the registered network.|
| isRoaming         | boolean               | Whether the user is roaming.|
| regState          | [RegState](#RegState) | Network registration status of the device.|
| nsaState          | [NsaState](#NsaState) | NSA network registration status of the device.|
| isCaActive        | boolean               | Whether carrier aggregation (CA) is supported.|
| isEmergency       | boolean               | Whether only emergency calls are allowed.|


## RegState<a name=RegState></a>

Enumerates network registration states.

| Variable| Value| Description|
| ----------------------------- | ---- | -------------------------- |
| REG_STATE_NO_SERVICE          | 0    | The device cannot use any service.|
| REG_STATE_IN_SERVICE          | 1    | The device can use services normally. |
| REG_STATE_EMERGENCY_CALL_ONLY | 2    | The device can use only the emergency call service.|
| REG_STATE_POWER_OFF           | 3    | The cellular radio service is disabled.|


## NsaState<a name=NsaState></a>

Enumerates NSA network states.

| Variable| Value| Description|
| -------------------------- | ---- | ---------------------------------------------------------- |
| NSA_STATE_NOT_SUPPORT      | 1    | The device is in idle or connected state in an LTE cell that does not support NSA.|
| NSA_STATE_NO_DETECT        | 2    | The device is in the idle state in an LTE cell that supports NSA but does not support NR coverage detection.|
| NSA_STATE_CONNECTED_DETECT | 3    | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection.|
| NSA_STATE_IDLE_DETECT      | 4    | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection.|
| NSA_STATE_DUAL_CONNECTED   | 5    | The device is connected to the LTE/NR network in an LTE cell that supports NSA.|
| NSA_STATE_SA_ATTACHED      | 6    | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core.|


## NetworkSelectionMode<a name=NetworkSelectionMode></a>

Enumerates network selection modes.

| Variable| Value| Description|
| --------------------------- | ---- | -------------- |
| NETWORK_SELECTION_UNKNOWN   | 0    | Unknown network selection mode.|
| NETWORK_SELECTION_AUTOMATIC | 1    | Automatic network selection mode.|
| NETWORK_SELECTION_MANUAL    | 2    | Manual network selection mode.|
