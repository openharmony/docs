# SIM Management

The SIM management module provides basic SIM card management functions. You can obtain the name, number, ISO country code, home PLMN number, service provider name, SIM card status, type, installation status, activation status, and lock status of the SIM card in the specified slot. Besides, you can set the name, number, and lock status of the SIM card, activate or deactivate the SIM card, and change the PIN or unlock the PIN or PUK of the SIM card.

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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

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
    console.log(`isSimActive failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void

Obtains the default slot ID of the SIM card that provides voice services. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

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

**System capability**: SystemCapability.Telephony.CoreService

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
    console.log(`getDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean\>): void

Checks whether the application (caller) has been granted the operator permission. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                    |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| slotId   | number                   | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                              |

**Example**

```js
sim.hasOperatorPrivileges(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number): Promise<boolean\>

Checks whether the application (caller) has been granted the carrier permission. This API uses a promise to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                       |
| :----------------- | :---------------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the application (caller) has been granted the carrier permission, and the value **false** indicates the opposite.|

**Example**

```js
let promise = sim.hasOperatorPrivileges(0);
promise.then(data => {
    console.log(`hasOperatorPrivileges success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`hasOperatorPrivileges failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the ISO country code of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                    |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2  |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result. which is an ISO country code, for example, **CN** (China).|

**Example**

```js
sim.getISOCountryCodeForSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number\): Promise<string\>

Obtains the ISO country code of the SIM card in the specified slot. This API uses a promise to return the result.

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
let promise = sim.getISOCountryCodeForSim(0);
promise.then(data => {
    console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getISOCountryCodeForSim failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the public land mobile network (PLMN) ID of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

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
    console.log(`getSimOperatorNumeric failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the service provider name (SPN) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

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
    console.log(`getSimSpn failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimState

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

Obtains the status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                  | Mandatory| Description                                  |
| -------- | -------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

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
    console.log(`getSimState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number, callback: AsyncCallback<CardType\>\): void

Obtains the type of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

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
    console.log(`getCardType failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number, callback: AsyncCallback<boolean\>\): void

Checks whether the SIM card in the specified slot is installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
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

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

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
    console.log(`hasSimCard failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimAccountInfo<sup>7+</sup>

getSimAccountInfo(slotId: number, callback: AsyncCallback<IccAccountInfo\>): void

Obtains account information of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                               | Mandatory| Description                                  |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                              | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[IccAccountInfo](#iccaccountinfo7)\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getSimAccountInfo(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimAccountInfo<sup>7+</sup>

getSimAccountInfo(slotId: number): Promise<IccAccountInfo\>

Obtains account information of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                        | Description                                      |
| -------------------------------------------- | ------------------------------------------ |
| Promise<[IccAccountInfo](#iccaccountinfo7)\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimAccountInfo(0);
promise.then(data => {
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getActiveSimAccountInfoList<sup>8+</sup>

getActiveSimAccountInfoList(callback: AsyncCallback<Array<IccAccountInfo\>>): void

Obtains the account information list of the active SIM card. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description      |
| -------- | ----------------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array<[IccAccountInfo](#iccaccountinfo7)\>\> | Yes  | Callback used to return the result.|

**Example**

```js
sim.getActiveSimAccountInfoList((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getActiveSimAccountInfoList<sup>8+</sup>

getActiveSimAccountInfoList(): Promise<Array<IccAccountInfo\>>;

Obtains the account information list of the active SIM card. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type                                                | Description                                          |
| ---------------------------------------------------- | ---------------------------------------------- |
| Promise<Array<[IccAccountInfo](#iccaccountinfo7)\>\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getActiveSimAccountInfoList();
promise.then(data => {
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getActiveSimAccountInfoList failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback<void\>): void

Sets the default slot ID of the SIM card that provides voice services. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: Clears the default configuration.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
sim.setDefaultVoiceSlotId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId(slotId: number): Promise\<void\>

Sets the default slot ID of the SIM card that provides voice services. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: Clears the default configuration.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = sim.setDefaultVoiceSlotId(0);
promise.then(data => {
    console.log(`setDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**setShowName**<sup>8+</sup>

setShowName\(slotId: number, name: string, callback: AsyncCallback<void\>\): void

Sets a display name for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| name     | string                    | Yes  | SIM card name.                             |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
let name = "ShowName";
sim.setShowName(0, name, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.**setShowName**<sup>8+</sup>

setShowName\(slotId: number, name: string\): Promise\<void\>

Sets a display name for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| name   | string | Yes  | SIM card name.                             |

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let name = "ShowName";
let promise = sim.setShowName(0, name);
promise.then(data => {
    console.log(`setShowName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**getShowName**<sup>8+</sup>

getShowName(slotId: number, callback: AsyncCallback<string\>): void

Obtains the name of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getShowName(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**getShowName**<sup>8+</sup>

getShowName(slotId: number): Promise<string\>

Obtains the name of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                                  |
| --------------------- | -------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```js
let promise = sim.getShowName(0);
promise.then(data => {
    console.log(`getShowName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**setShowNumber**<sup>8+</sup>

setShowNumber\(slotId: number, number: string, callback: AsyncCallback<void\>\): void

Sets a display number for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| number   | string                    | Yes  | SIM card number.                             |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
let number = '+861xxxxxxxxxx';
sim.setShowNumber(0, number, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**setShowNumber**<sup>8+</sup>

setShowNumber\(slotId: number, number: string\): Promise\<void\>

Sets a display number for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| number | string | Yes  | SIM card number.                             |

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```js
let number = '+861xxxxxxxxxx';
let promise = sim.setShowNumber(0, number);
promise.then(data => {
    console.log(`setShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**getShowNumber**<sup>8+</sup>

getShowNumber(slotId: number, callback: AsyncCallback<string\>): void

Obtains the display number of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getShowNumber(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**getShowNumber**<sup>8+</sup>

getShowNumber(slotId: number): Promise<string\>

Obtains the display number of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```js
let promise = sim.getShowNumber(0);
promise.then(data => {
    console.log(`getShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**activateSim**<sup>8+</sup>

activateSim(slotId: number, callback: AsyncCallback<void\>): void

Activates the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.activateSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**activateSim**<sup>8+</sup>

activateSim(slotId: number): Promise\<void\>

Activates the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = sim.activateSim(0);
promise.then(data => {
    console.log(`activateSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`activateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**deactivateSim**<sup>8+</sup>

deactivateSim(slotId: number, callback: AsyncCallback<void\>): void

Deactivates the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.deactivateSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**deactivateSim**<sup>8+</sup>

deactivateSim(slotId: number): Promise\<void\>

Deactivates the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = sim.deactivateSim(0);
promise.then(data => {
    console.log(`deactivateSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`deactivateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setLockState<sup>7+</sup>

setLockState(slotId: number, options: LockInfo, callback: AsyncCallback<LockStatusResponse\>): void

Sets the lock status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                                                  |
| options  | [LockInfo](#lockinfo8)                                      | Yes  | Lock information.<br>- **lockType**: [LockType](#locktype8)<br>- **password**: string<br>- **state**: [LockState](#lockstate8) |

**Example**

```js
let lockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
sim.setLockState(0, lockInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setLockState<sup>7+</sup>

setLockState(slotId: number, options: LockInfo): Promise<LockStatusResponse\>

Sets the lock status of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                  | Mandatory| Description                                                        |
| ------- | ---------------------- | ---- | ------------------------------------------------------------ |
| slotId  | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| options | [LockInfo](#lockinfo8) | Yes  | Lock information.<br>- **lockType**: [LockType](#locktype8)<br>- **password**: string<br>- **state**: [LockState](#lockstate8) |

**Return value**

| Type                                                | Description                                        |
| ---------------------------------------------------- | -------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let lockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
let promise = sim.setLockState(0, lockInfo);
promise.then(data => {
    console.log(`setLockState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getLockState<sup>8+</sup>

getLockState(slotId: number, lockType: LockType, callback: AsyncCallback<LockState\>): void

Obtains the lock status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                     | Mandatory| Description                                   |
| -------- | ----------------------------------------- | ---- | --------------------------------------- |
| slotId   | number                                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2 |
| callback | AsyncCallback\<[LockState](#lockstate8)\> | Yes  | Callback used to return the result.                             |
| options  | [LockType](#locktype8)                    | Yes  | Lock type.<br>- **1**: PIN lock<br>- **2**: PIN 2 lock|

**Example**

```js
sim.getLockState(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getLockState<sup>8+</sup>

getLockState(slotId: number, lockType: LockType): Promise<LockState\>

Obtains the lock status of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                  | Mandatory| Description                                   |
| ------- | ---------------------- | ---- | --------------------------------------- |
| slotId  | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2 |
| options | [LockType](#locktype8) | Yes  | Lock type.<br>- **1**: PIN lock<br>- **2**: PIN 2 lock|

**Return value**

| Type                              | Description                                        |
| ---------------------------------- | -------------------------------------------- |
| Promise<[LockState](#lockstate8)\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getLockState(0, 1);
promise.then(data => {
    console.log(`getLockState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin<sup>7+</sup>

alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback<LockStatusResponse\>): void

Changes the PIN of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                  |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                            |
| newPin   | string                                                      | Yes  | New PIN.                              |
| oldPin   | string                                                      | Yes  | Old PIN.                              |

**Example**

```js
sim.alterPin(0, "1234", "0000", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin<sup>7+</sup>

alterPin(slotId: number, newPin: string, oldPin: string): Promise<LockStatusResponse\>;

Changes the PIN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin | string | Yes  | New PIN.                              |
| oldPin | string | Yes  | Old PIN.                              |

**Return value**

| Type                                                | Description                                         |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let promise = sim.alterPin(0, "1234", "0000");
promise.then(data => {
    console.log(`alterPin success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`alterPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin2<sup>8+</sup>

alterPin2(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback<LockStatusResponse\>): void

Changes PIN 2 of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                  |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                            |
| newPin2  | string                                                      | Yes  | New PIN.                              |
| oldPin2  | string                                                      | Yes  | Old PIN.                              |

**Example**

```js
sim.alterPin2(0, "1234", "0000", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin2<sup>8+</sup>

alterPin2(slotId: number, newPin2: string, oldPin2: string): Promise<LockStatusResponse\>

Changes PIN 2 of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type  | Mandatory| Description                                  |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin2 | string | Yes  | New PIN.                              |
| oldPin2 | string | Yes  | Old PIN.                              |

**Return value**

| Type                                                | Description                                         |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let promise = sim.alterPin2(0, "1234", "0000");
promise.then(data => {
    console.log(`alterPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`alterPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPin**<sup>7+</sup>

unlockPin(slotId: number, pin: string, callback: AsyncCallback<LockStatusResponse\>): void

Unlocks PIN of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin      | string                                                       | Yes  | PIN of the SIM card.                           |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)> | Yes  | Callback used to return the result.                            |

**Example**

```js
let pin = '1234';
sim.unlockPin(0, pin, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPin**<sup>7+</sup>

unlockPin(slotId: number, pin: string): Promise&lt;LockStatusResponse\>

Unlocks the PIN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin    | string | Yes  | PIN of the SIM card.                           |

**Return value**

| Type                                                | Description                                              |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let pin = '1234';
let promise = sim.unlockPin(0, pin);
promise.then(data => {
    console.log(`unlockPin success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPuk**<sup>7+</sup>

unlockPuk(slotId: number, newPin: string, puk: string ,callback: AsyncCallback<LockStatusResponse\>): void

Unlocks the PUK of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin   | string                                                       | Yes  | New PIN.                       |
| puk      | string                                                       | Yes  | PUK of the SIM card.                   |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
let puk = '1xxxxxxx';
let newPin = '1235';
sim.unlockPuk(0, newPin, puk, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPuk**<sup>7+</sup>

unlockPuk(slotId: number, newPin: string, puk: string): Promise&lt;LockStatusResponse\>

Unlocks the PUK of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin | string | Yes  | New PIN.                       |
| puk    | string | Yes  | PUK of the SIM card.                   |

**Return value**

| Type                                                | Description                                              |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let puk = '1xxxxxxx';
let newPin = '1235';
let promise = sim.unlockPuk(0, newPin, puk);
promise.then(data => {
    console.log(`unlockPuk success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPuk failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPin**2<sup>8+</sup>

unlockPin2(slotId: number, pin2: string, callback: AsyncCallback<LockStatusResponse\>): void

Unlocks PIN 2 of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin2     | string                                                       | Yes  | PIN 2 of the SIM card.                           |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
let pin2 = '1234';
sim.unlockPin2(0, pin2, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPin**2<sup>8+</sup>

unlockPin2(slotId: number, pin2: string): Promise&lt;LockStatusResponse\>

Unlocks PIN 2 of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin2   | string | Yes  | PIN 2 of the SIM card.                           |

**Return value**

| Type                                                 | Description                                              |
| ----------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let pin2='1234';
let promise = sim.unlockPin2(0, pin2);
promise.then(data => {
    console.log(`unlockPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPuk**2<sup>8+</sup>

unlockPuk2(slotId: number, newPin2: string, puk2: string, callback: AsyncCallback<LockStatusResponse\>): void

Unlocks PUK 2 of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin2  | string                                                       | Yes  | New PIN 2.                       |
| puk2     | string                                                       | Yes  | PUK 2 of the SIM card.                   |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
let puk2 = '1xxxxxxx';
let newPin2 = '1235';
sim.unlockPuk2(0, newPin2, puk2, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPuk2**<sup>8+</sup>

unlockPuk2(slotId: number, newPin2: string, puk2: string): Promise&lt;LockStatusResponse\>

Unlocks PUK 2 of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type  | Mandatory| Description                                  |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin2 | string | Yes  | New PIN 2.                       |
| puk2    | string | Yes  | PUK 2 of the SIM card.                   |

**Return value**

| Type                                                | Description                                              |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let puk2 = '1xxxxxxx';
let newPin2 = '1235';
let promise = sim.unlockPuk2(0, newPin2, puk2);
promise.then(data => {
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPuk2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getMaxSimCount<sup>7+</sup>

getMaxSimCount\(\): number

Obtains the number of card slots.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| number | Number of card slots.|

**Example**

```js
console.log("Result: "+ sim.getMaxSimCount())
```

## sim.getSimIccId<sup>7+</sup>

getSimIccId(slotId: number, callback: AsyncCallback<string\>): void

Obtains the IC card identity (ICCID) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getSimIccId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimIccId<sup>7+</sup>

getSimIccId(slotId: number): Promise<string\>

Obtains the ICCID of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                       |
| ---------------- | ------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimIccId(0);
promise.then(data => {
    console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimIccId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier(slotId: number, callback: AsyncCallback<string\>): void

Obtains the voice mailbox alpha identifier of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getVoiceMailIdentifier(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier(slotId: number): Promise<string\>

Obtains the voice mailbox alpha identifier of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getVoiceMailIdentifier(0);
promise.then(data => {
    console.log(`getVoiceMailIdentifier success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getVoiceMailIdentifier failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber(slotId: number, callback: AsyncCallback<string\>): void

Obtains the voice mailbox number of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getVoiceMailNumber(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber(slotId: number): Promise<string\>

Obtains the voice mailbox number of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                            |
| ---------------- | ------------------------------------------------ |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getVoiceMailNumber(0);
promise.then(data => {
    console.log(`getVoiceMailNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getVoiceMailNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string, callback: AsyncCallback<void\>): void

Sets voice mailbox information for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name    | Type                | Mandatory| Description                                  |
| ---------- | -------------------- | ---- | -------------------------------------- |
| slotId     | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| mailName   | string               | Yes  | Voice mailbox name.                              |
| mailNumber | string               | Yes  | Voice mailbox number.                              |
| callback   | AsyncCallback<void\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string): Promise<void\>

Sets voice mailbox information for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name    | Type  | Mandatory| Description                                  |
| ---------- | ------ | ---- | -------------------------------------- |
| slotId     | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| mailName   | string | Yes  | Voice mailbox name.                              |
| mailNumber | string | Yes  | Voice mailbox number.                              |

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```js
let promise = sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com");
promise.then(data => {
    console.log(`setVoiceMailInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setVoiceMailInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber(slotId: number, callback: AsyncCallback<string\>): void

Obtains the mobile subscriber ISDN number (MSISDN) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getSimTelephoneNumber(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber(slotId: number): Promise<string\>

Obtains the MSISDN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                        |
| ---------------- | -------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimTelephoneNumber(0);
promise.then(data => {
    console.log(`getSimTelephoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimTelephoneNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimGid1<sup>7+</sup>

getSimGid1(slotId: number, callback: AsyncCallback<string\>): void

Obtains the group identifier level 1 (GID1) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getSimGid1(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimGid1<sup>7+</sup>

getSimGid1(slotId: number): Promise<string\>

Obtains the GID1 of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getSimGid1(0);
promise.then(data => {
    console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimGid1 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getIMSI

getIMSI(slotId: number, callback: AsyncCallback<string\>): void

Obtains the international mobile subscriber identity (IMSI) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getIMSI(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getIMSI

getIMSI(slotId: number): Promise<string\>

Obtains the IMSI of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                       |
| ---------------- | ------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getIMSI(0);
promise.then(data => {
    console.log(`getIMSI success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getIMSI failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs(slotId: number, callback: AsyncCallback<Array<OperatorConfig\>>): void

Obtains the carrier configuration of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                  |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<Array<[OperatorConfig](#operatorconfig8)\>> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.getOperatorConfigs(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs(slotId: number): Promise<Array<OperatorConfig\>>

Obtains the carrier configuration of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                               | Description                         |
| --------------------------------------------------- | ----------------------------- |
| Promise<Array<[OperatorConfig](#operatorconfig8)\>> | Promise used to return the result.|

**Example**

```js
let promise = sim.getOperatorConfigs(0);
promise.then(data => {
    console.log(`getOperatorConfigs success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOperatorConfigs failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers(slotId: number, type: ContactType, callback: AsyncCallback<Array<DiallingNumbersInfo\>>): void

Queries contact numbers of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.READ_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                      |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type     | [ContactType](#contacttype8)                                                  | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| callback | AsyncCallback<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | Yes  | Callback used to return the result.                                                |

**Example**

```js
sim.queryIccDiallingNumbers(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers(slotId: number, type: ContactType): Promise<Array<DiallingNumbersInfo\>>

Queries contact numbers of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.READ_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type       | Mandatory| Description                                                      |
| ------ | ----------- | ---- | ---------------------------------------------------------- |
| slotId | number      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type   | [ContactType](#contacttype8)  | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |

**Return value**

| Type                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| Promise<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> |  Promise used to return the result.|

**Example**

```js
let promise = sim.queryIccDiallingNumbers(0, 1);
promise.then(data => {
    console.log(`queryIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`queryIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback<void\>): void

Adds contact numbers for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |
| callback        | AsyncCallback<void\>                         | Yes  | Callback used to return the result.                                                  |

**Example**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    pin2: "1234"
};
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise<void\>

Adds contact numbers for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> |  Promise used to return the result.|

**Example**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
let promise = sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof);
promise.then(data => {
    console.log(`addIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`addIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback<void\>): void

Deletes contact numbers from the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |
| callback        | AsyncCallback<void\>                         | Yes  | Callback used to return the result.                                                  |

**Example**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise<void\>

Deletes contact numbers from the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> |  Promise used to return the result.|

**Example**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
let promise = sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof);
promise.then(data => {
    console.log(`delIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`delIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback<void\>): void

Updates contact numbers for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |
| callback        | AsyncCallback<void\>                         | Yes  | Callback used to return the result.                                                  |

**Example**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise<void\>

Updates contact numbers for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
let promise = sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof);
promise.then(data => {
    console.log(`updateIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`updateIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd(slotId: number, cmd: string, callback: AsyncCallback<void\>): void

Sends an envelope command to the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                | Mandatory| Description                                  |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd      | string               | Yes  | Envelope command.                                  |
| callback | AsyncCallback<void\> | Yes  | Yes                                    |

**Example**

```js
sim.sendEnvelopeCmd(0, "ls", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd(slotId: number, cmd: string): Promise<void\>

Sends an envelope command to the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd    | string | Yes  | Envelope command.                                  |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```js
let promise = sim.sendEnvelopeCmd(0, "ls");
promise.then(data => {
    console.log(`sendEnvelopeCmd success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`sendEnvelopeCmd failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd(slotId: number, cmd: string, callback: AsyncCallback<void\>): void

Sends a terminal response command to the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                | Mandatory| Description                                  |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd      | string               | Yes  | Command                                  |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                            |

**Example**

```js
sim.sendTerminalResponseCmd(0, "ls", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd(slotId: number, cmd: string): Promise<void\>

Sends a terminal response command to the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd    | string | Yes  | Command                                  |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```js
let promise = sim.sendTerminalResponseCmd(0, "ls");
promise.then(data => {
    console.log(`sendTerminalResponseCmd success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`sendTerminalResponseCmd failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockSimLock<sup>8+</sup>

unlockSimLock(slotId: number, lockInfo: PersoLockInfo, callback: AsyncCallback<LockStatusResponse\>): void

Unlocks the SIM card in the specified slot. This API uses an asynchronous callback to return the result. 

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                  |
| -------- | ---------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                     | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| lockInfo | [PersoLockInfo](#persolockinfo8)                           | Yes  | Personalized lock information.                        |
| callback | AsyncCallback<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                              |

**Example**

```js
let persoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
sim.unlockSimLock(0, persoLockInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockSimLock<sup>8+</sup>

unlockSimLock(slotId: number, lockInfo: PersoLockInfo): Promise<LockStatusResponse\>

Unlocks the SIM card in the specified slot. This API uses a promise to return the result. 

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                            | Mandatory| Description                                  |
| -------- | -------------------------------- | ---- | -------------------------------------- |
| slotId   | number                           | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| lockInfo | [PersoLockInfo](#persolockinfo8) | Yes  | Personalized lock information.                        |

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Example**

```js
let persoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
let promise = sim.unlockSimLock(0, persoLockInfo);
promise.then(data => {
    console.log(`unlockSimLock success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockSimLock failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpKey<sup>9+</sup>

getOpKey(slotId: number, callback: AsyncCallback<string\>): void

Obtains the opkey of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                              |

**Example**

```js
sim.getOpKey(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOpKey<sup>9+</sup>

getOpKey(slotId: number): Promise<string\>

Obtains the opkey of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getOpKey(0);
promise.then(data => {
    console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOpKey failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpName<sup>9+</sup>

getOpName(slotId: number, callback: AsyncCallback<string\>): void

Obtains the OpName of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                              |

**Example**

```js
sim.getOpName(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOpName<sup>9+</sup>

getOpName(slotId: number): Promise<string\>

Obtains the OpName of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                      |
| ---------------- | ------------------------------------------ |
| Promise<string\> | Promise used to return the result.|

**Example**

```js
let promise = sim.getOpName(0);
promise.then(data => {
    console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOpName failed, promise: err->${JSON.stringify(err)}`);
});
```

## SimState

Enumerates SIM card states.

**System capability**: SystemCapability.Telephony.CoreService

| Name                 | Value  | Description                                                      |
| --------------------- | ---- | ---------------------------------------------------------- |
| SIM_STATE_UNKNOWN     | 0    | The SIM card is in **unknown** state; that is, the SIM card status cannot be obtained.                     |
| SIM_STATE_NOT_PRESENT | 1    | The SIM card is in **not present** state; that is, no SIM card is inserted into the card slot.     |
| SIM_STATE_LOCKED      | 2    | The SIM card is in **locked** state; that is, the SIM card is locked by the personal identification number (PIN), PIN unblocking key (PUK), or network.  |
| SIM_STATE_NOT_READY   | 3    | The SIM card is in **not ready** state; that is, the SIM card has been installed but cannot work properly.   |
| SIM_STATE_READY       | 4    | The SIM card is in **ready** state; that is, the SIM card has been installed and is working properly.           |
| SIM_STATE_LOADED      | 5    | The SIM card is in **loaded** state; that is, the SIM card is present and all its files have been loaded.|

## CardType<sup>7+</sup>

Enumerates SIM card types.

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

## LockType<sup>8+</sup>

Enumerates lock types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name    | Value  | Description       |
| -------- | ---- | ----------- |
| PIN_LOCK | 1    | SIM card password lock.|
| FDN_LOCK | 2    | Fixed dialing lock. |

## LockState<sup>8+</sup>

Enumerates lock states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name    | Value  | Description      |
| -------- | ---- | ---------- |
| LOCK_OFF | 0    | The lock is off.|
| LOCK_ON  | 1    | The lock is on.|

## PersoLockType<sup>8+</sup>

Enumerates personalized lock types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name        | Value  | Description                                           |
| ------------ | ---- | ----------------------------------------------- |
| PN_PIN_LOCK  | 0    | Personalized network PIN lock. For details, see *3GPP TS 22.022 [33]*.      |
| PN_PUK_LOCK  | 1    | Personalized network PUK lock.                                  |
| PU_PIN_LOCK  | 2    | Personalized network subset PIN lock. For details, see *3GPP TS 22.022 [33]*.  |
| PU_PUK_LOCK  | 3    | Personalized network subset PUK lock.                              |
| PP_PIN_LOCK  | 4    | Personalized service provider PIN lock. For details, see *3GPP TS 22.022 [33]*.|
| PP_PUK_LOCK  | 5    | Personalized service provider PUK lock.                             |
| PC_PIN_LOCK  | 6    | Personalized corporate PIN lock. For details, see *3GPP TS 22.022 [33]*.      |
| PC_PUK_LOCK  | 7    | Personalized corporate PUK lock.                                   |
| SIM_PIN_LOCK | 8    | Personalized SIM card PIN lock. For details, see *3GPP TS 22.022 [33]*.     |
| SIM_PUK_LOCK | 9    | Personalized SIM card PUK lock.                                  |

## LockStatusResponse<sup>7+</sup>

Defines the lock status response.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| result          | number | Yes | Operation result.    |
| remain?: number | number | Yes | Remaining attempts (can be null).|

## LockInfo<sup>8+</sup>

Defines the lock information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| lockType | [LockType](#locktype8)   | Yes | Lock type.|
| password | string                   | Yes | Password.  |
| state    | [LockState](#lockstate8) | Yes | Lock state.|

## PersoLockInfo<sup>8+</sup>

Defines the personalized lock information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| lockType | [PersoLockType](#persolocktype8) | Yes | Personalized lock type.|
| password | string                           | Yes | Password.        |

## IccAccountInfo<sup>7+</sup>

Defines the ICC account information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| simId      | number  | Yes | SIM card ID.         |
| slotIndex  | number  | Yes | Card slot ID.          |
| isEsim     | boolean | Yes | Whether the SIM card is an eSim card.|
| isActive   | boolean | Yes | Whether the card is activated.    |
| iccId      | string  | Yes | ICCID number.       |
| showName   | string  | Yes | SIM card display name.   |
| showNumber | string  | Yes | SIM card display number.   |

## OperatorConfig<sup>8+</sup>

Defines the carrier configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| field | string | Yes | Field. |
| value | string | Yes | Value. |

## DiallingNumbersInfo<sup>8+</sup>

Defines the contact number information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type    | Mandatory | Description |
| -------- | ------- | --------- | ----------- |
| alphaTag     | string | Yes | Alpha tag.    |
| number       | string | Yes | Contact number.    |
| recordNumber | number | Yes | Record number.|
| pin2         | string | Yes | PIN 2.|

## ContactType<sup>8+</sup>

Enumerates contact types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name           | Value  | Description      |
| :-------------- | ---- | ---------- |
| GENERAL_CONTACT | 1    | Common contact number.|
| FIXED_DIALING   | 2    | Fixed dialing number.  |
