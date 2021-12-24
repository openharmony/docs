# SIM Management

>**Note:**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import sim from '@ohos.telephony.sim';
```

## sim.getSimIccId<a name=sim.getSimIccId-callback></a>

getSimIccId\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the integrated circuit card identity  (ICCID) of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission.

-   Parameters

    | Name| Type| Mandatory| Description|
    | -------- | --------------------------- | ---- | -------------------------------------- |
    | slotId   | number                      | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
    | callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|


-   Example

    ```
    sim.getSimIccId(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimIccId<a name=sim.getSimIccId-promise></a>

getSimIccId\(slotId: number\): Promise<string\>

Obtains the ICCID of the SIM card in the specified slot. This function uses a promise to return the result.

Before using this API, you must declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission.

- Parameters

    | Name| Type| Mandatory| Description|
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

- Return values

    | Type| Description|
    | --------------------- | ---------------------------------- |
    | Promise&lt;string&gt; | Promise used to return the result.|

-   Example

    ```
    let promise = sim.getSimIccId(0);
    promise.then(data => {
        console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimIccId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getDefaultVoiceSlotId<sup>7+</sup><a name= sim.getDefaultVoiceSlotId-callback></a>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void

Obtains the default slot ID of the SIM card that provides voice services. This function uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | --------------------------- | ---- | ---------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result.|

-   Example

    ```
    sim.getDefaultVoiceSlotId((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getDefaultVoiceSlotId<sup>7+</sup><a name=sim.getDefaultVoiceSlotId-promise></a>

getDefaultVoiceSlotId\(\): Promise<number\>

Obtains the default slot ID of the SIM card that provides voice services. This function uses a promise to return the result.

- Return values

  | Type| Description|
  | ----------------- | --------------------------------------- |
  | Promise\<number\> | Promise used to return the result.|

-   Example

    ```
    let promise = sim.getDefaultVoiceSlotId();
    promise.then(data => {
        console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getDefaultVoiceSlotId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getISOCountryCodeForSim<a name=sim.getISOCountryCodeForSim-callback></a>

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the ISO country code of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | slotId   | number                  | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
  | callback | AsyncCallback\<string\> | Yes| Callback used to return the result, which is a country code, for example, **CN** (China).|

-   Example

    ```
    sim.getISOCountryCodeForSim(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getISOCountryCodeForSim<a name=sim.getISOCountryCodeForSim-promise></a>

getISOCountryCodeForSim\(slotId: number\): Promise<string\>

Obtains the ISO country code of the SIM card in the specified slot. This function uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | ----------------- | ------------------------------------------------------------ |
  | Promise\<string\> | Promise used to return the result, which is a country code, for example, **CN** (China).|

-   Example

    ```
    let promise = sim.getISOCountryCodeForSim(0);
    promise.then(data => {
        console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getISOCountryCodeForSim fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimOperatorNumeric<a name=sim.getSimOperatorNumeric-callback></a>

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the public land mobile network (PLMN) ID of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ----------------------- | ---- | -------------------------------------- |
  | slotId   | number                  | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
  | callback | AsyncCallback\<string\> | Yes| Callback used to return the result.|

-   Example

    ```
    sim.getSimOperatorNumeric(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimOperatorNumeric<a name=sim.getSimOperatorNumeric-promise></a>

getSimOperatorNumeric\(slotId: number\): Promise<string\>

Obtains the PLMN ID of the SIM card in the specified slot. This function uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

- Return values

  | Type| Description|
  | ----------------- | ------------------------------------------------ |
  | Promise\<string\> | Promise used to return the result.|

-   Example

    ```
    let promise = sim.getSimOperatorNumeric(0);
    promise.then(data => {
        console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimOperatorNumeric fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimSpn<a name=sim.getSimSpn-callback></a>

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the service provider name (SPN) of the SIM card in the specified slot. This function uses an asynchronous callback to return the result. 

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ----------------------- | ---- | -------------------------------------- |
  | slotId   | number                  | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
  | callback | AsyncCallback\<string\> | Yes| Callback used to return the result.|

-   Example

    ```
    sim.getSimSpn(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimSpn<a name=sim.getSimSpn-promise></a>

getSimSpn\(slotId: number\): Promise<string\>

Obtains the SPN of the SIM card in the specified slot. This function uses a promise to return the result. 

- Parameters

    | Name| Type| Mandatory| Description|
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

- Return values

    | Type| Description|
    | ----------------- | ----------------------------------------- |
    | Promise\<string\> | Promise used to return the result.|

-   Example

    ```
    let promise = sim.getSimSpn(0);
    promise.then(data => {
        console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimSpn fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimState<a name=sim.getSimState-callback></a>

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

Obtains the status of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | -------------------------------------- | ---- | ----------------------------------------- |
  | slotId   | number                                 | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
  | callback | AsyncCallback\<[SimState](#SimState)\> | Yes| Callback used to return the result. For details, see [SimState](#SimState).|

-   Example

    ```
    sim.getSimState(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimState<a name=sim.getSimState-promise></a>

getSimState\(slotId: number\): Promise<SimState\>

Obtains the status of the SIM card in the specified slot. This function uses a promise to return the result.

- Parameters

    | Name| Type| Mandatory| Description|
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

- Return values

    | Type| Description|
    | -------------------------------- | ------------------------------------------ |
    | Promise\<[SimState](#SimState)\> | Promise used to return the result.|

-   Example

    ```
    let promise = sim.getSimState(0);
    promise.then(data => {
        console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimState fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getSimGid1<a name=sim.getSimGid1-callback></a>

getSimGid1\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the group identifier level 1 (GID1) of the SIM card in the specified slot. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ----------------------- | ---- | -------------------------------------- |
  | slotId   | number                  | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
  | callback | AsyncCallback\<string\> | Yes| Callback used to return the result.|

-   Example

    ```
    sim.getSimGid1(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimGid1<a name=sim.getSimGid1-promise></a>

getSimGid1\(slotId: number\): Promise<string\>

Obtains the GID1 of the SIM card in the specified slot. This function uses a promise to return the result.

Before using this API, you must declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission.

- Parameters

    | Name| Type| Mandatory| Description|
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | Yes| Card slot ID. The options are as follows: <br/> - **0**: slot 1 <br/> - **1**: slot 2|

- Return values

    | Type| Description|
    | ----------------- | ------------------------------------------------------------ |
    | Promise\<string\> | Promise used to return the result.|

-   Example

    ```
    let promise = sim.getSimGid1(0);
    promise.then(data => {
        console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimGid1 fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## SimState<a name=SimState></a>

Enumerates SIM card states.

| Variable| Description|
| --------------------- | ---------------------------------------------------------- |
| SIM_STATE_UNKNOWN     | The SIM card is in **unknown** state; that is, the SIM card status cannot be obtained.|
| SIM_STATE_NOT_PRESENT | The SIM card is in **not present** state; that is, no SIM card is inserted into the slot.|
| SIM_STATE_LOCKED      | The SIM card is in **locked** state; that is, the SIM card is locked by the personal identification number (PIN), PIN unblocking key (PUK), or network.|
| SIM_STATE_NOT_READY   | The SIM card is in **not ready** state; that is, the SIM card is present but cannot work properly.|
| SIM_STATE_READY       | The SIM card is in **ready** state; that is, the SIM card is present and is working properly.|
| SIM_STATE_LOADED      | The SIM card is in **loaded** state; that is, the SIM card is present and all its files have been loaded.|
