# SIM Management

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```js
import sim from '@ohos.telephony.sim';
```

## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number, callback: AsyncCallback<boolean\>\): void

Checks whether the SIM card in the specified slot is activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.isSimActive(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number\): Promise<boolean\>

Checks whether the SIM card in the specified slot is activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the SIM card in the specified slot is activated, and the value **false** indicates the opposite.|

**Example**

```js
let promise = sim.isSimActive(0);
promise.then(data => {
    console.log(`isSimActive success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`isSimActive fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void

Obtains the default slot ID of the SIM card that provides voice services. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description      |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.|

**Example**

```js
sim.getDefaultVoiceSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(\): Promise<number\>

Obtains the default slot ID of the SIM card that provides voice services. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<number\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getDefaultVoiceSlotId();
promise.then(data => {
    console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getDefaultVoiceSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean\>): void

Checks whether the application (caller) has been granted the operator permission. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                    |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| slotId   | number                   | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                              |

**Example**

```js
sim.hasOperatorPrivileges(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number): Promise<boolean\>

Checks whether the application (caller) has been granted the operator permission. This API uses a promise to return the result. 

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                       |
| :----------------- | :---------------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the application (caller) has been granted the operator permission, and the value **false** indicates the opposite.|

**Example**

```js
let promise = sim.hasOperatorPrivileges(0);
promise.then(data => {
    console.log(`hasOperatorPrivileges success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`hasOperatorPrivileges fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the ISO country code of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                    |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2  |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result, which is a country code, for example, **CN** (China).|

**Example**

```js
sim.getISOCountryCodeForSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number\): Promise<string\>

Obtains the ISO country code of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the result, which is a country code, for example, **CN** (China).|

**Example**

```js
let promise = sim.getISOCountryCodeForSim(0);
promise.then(data => {
    console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getISOCountryCodeForSim fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the public land mobile network (PLMN) ID of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getSimOperatorNumeric(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number\): Promise<string\>

Obtains the PLMN ID of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                            |
| ----------------- | ------------------------------------------------ |
| Promise\<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimOperatorNumeric(0);
promise.then(data => {
    console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimOperatorNumeric fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the service provider name (SPN) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getSimSpn(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number\): Promise<string\>

Obtains the SPN of the SIM card in the specified slot. This API uses a promise to return the result. 

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                     |
| ----------------- | ----------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimSpn(0);
promise.then(data => {
    console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimSpn fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimState

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

Obtains the status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                                  | Mandatory| Description                                  |
| -------- | -------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                 | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[SimState](#simstate)\> | Yes  | Callback used to return the result. For details, see [SimState](#simstate). |

**Example**

```js
sim.getSimState(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimState

getSimState\(slotId: number\): Promise<SimState\>

Obtains the status of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                            | Description                                      |
| -------------------------------- | ------------------------------------------ |
| Promise\<[SimState](#simstate)\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimState(0);
promise.then(data => {
    console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimState fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number, callback: AsyncCallback<CardType\>\): void

Obtains the type of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[CardType](#cardtype7)\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getCardType(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number\): Promise<CardType\>

Obtains the type of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<[CardType](#cardtype7)\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getCardType(0);
promise.then(data => {
    console.log(`getCardType success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getCardType fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number, callback: AsyncCallback<boolean\>\): void

Checks whether the SIM card in the specified slot is installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.hasSimCard(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number\): Promise<boolean\>

Checks whether the SIM card in the specified slot is installed. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. The options are as follows:<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the SIM card in the specified slot is installed, and the value **false** indicates the opposite.|

**Example**

```js
let promise = sim.hasSimCard(0);
promise.then(data => {
    console.log(`hasSimCard success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`hasSimCard fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getMaxSimCount<sup>7+</sup>

getMaxSimCount\(\): number

Obtains the number of card slots.

**System capability**: SystemCapability.Communication.CoreService

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| number | Number of card slots.|

**Example**

```js
console.log("Result: "+ sim.getMaxSimCount())
```


## SimState

Enumerates SIM card states.

**System capability**: SystemCapability.Telephony.CoreService

| Name                 | Value  | Description                                                      |
| --------------------- | ---- | ---------------------------------------------------------- |
| SIM_STATE_UNKNOWN     | 0    | The SIM card is in **unknown** state; that is, the SIM card status cannot be obtained.                     |
| SIM_STATE_NOT_PRESENT | 1    | The SIM card is in **not present** state; that is, no SIM card is inserted into the slot.     |
| SIM_STATE_LOCKED      | 2    | The SIM card is in **locked** state; that is, the SIM card is locked by the personal identification number (PIN), PIN unblocking key (PUK), or network.  |
| SIM_STATE_NOT_READY   | 3    | The SIM card is in **not ready** state; that is, the SIM card is present but cannot work properly.   |
| SIM_STATE_READY       | 4    | The SIM card is in **ready** state; that is, the SIM card is present and is working properly.           |
| SIM_STATE_LOADED      | 5    | The SIM card is in **loaded** state; that is, the SIM card is present and all its files have been loaded.|

## CardType<sup>7+</sup>

Enumerates card types.

**System capability**: SystemCapability.Telephony.CoreService

| Name| Value| Description|
| ----- | ----- | ----- |
|UNKNOWN_CARD | -1 | Unknown|
|SINGLE_MODE_SIM_CARD | 10 | Single-card (SIM)|
|SINGLE_MODE_USIM_CARD | 20 | Single-card (USIM)|
|SINGLE_MODE_RUIM_CARD | 30 | Single-card (RUIM)|
|DUAL_MODE_CG_CARD | 40 | Dual-card (CDMA+GSM)|
|CT_NATIONAL_ROAMING_CARD | 41 | China Telecom internal roaming card|
|CU_DUAL_MODE_CARD | 42 | China Unicom dual-mode card|
|DUAL_MODE_TELECOM_LTE_CARD | 43 | China Telecom dual-mode LTE card|
|DUAL_MODE_UG_CARD | 50 | Dual-mode card (UMTS+GSM)|
|SINGLE_MODE_ISIM_CARD<sup>8+</sup> | 60 | Single-card (ISIM)|
