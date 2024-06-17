# @ohos.telephony.sms (SMS) (System API)

The **sms** module provides basic SMS management functions. With the APIs provided by this module, you can create and send SMS messages, obtain the ID of the default SIM card used to send and receive SMS messages, and obtain and set the SMSC address.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.sms (SMS)](js-apis-sms.md).


## Modules to Import

```ts
import { sms } from '@kit.TelephonyKit';
```


## sms.sendMms<sup>11+</sup>

sendMms\(context: Context, mmsParams: MmsParams, callback: AsyncCallback&lt;void&gt;\): void

Sends an MMS message. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                    |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| mmsParams | [MmsParams](#mmsparams11) | Yes  | Parameters (including the callback) for sending MMS messages. For details, see [MmsParams](#mmsparams11).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

FA model:
<!--code_no_check_fa-->
```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common, featureAbility } from '@kit.AbilityKit';

// Obtain the context.
let context: common.BaseContext = featureAbility.getContext();

// Configure the path for storing PDUs of MMS messages. Such PDUs are sent from the encoding API.
const sandBoxPath: string = '/data/storage/el2/base/files/';
let filePath: string  = sandBoxPath + 'SendReq.mms';

// Options for sending MMS messages (The MMSC is for reference only.)
let mmsPars: sms.MmsParams = {
  slotId : 0,
  mmsc: 'http://mmsc.myuni.com.cn',
  data: filePath,
  mmsConfig: {
   userAgent:'ua',
   userAgentProfile: 'uaprof'
  }
};

// Call the sendMms API.
sms.sendMms(context, mmsPars, async(err: BusinessError) =>{
  if (err) {
      console.error(`sendMms fail, err : ${JSON.stringify(err)}`);
      return;
  }
  console.log(`sendMms Success`);
})
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// Configure the path for storing PDUs of MMS messages. Such PDUs are sent from the encoding API.
const sandBoxPath = '/data/storage/el2/base/files/';
let filePath  = sandBoxPath + 'SendReq.mms';

// Configure the MMS user agent and profile. The default values are ua and uaprof, respectively. The configuration is subject to the carrier's requirements. 
let mmsConf: sms.MmsConfig = {
  userAgent:'ua',
  userAgentProfile: 'uaprof'
};

// Options for sending MMS messages (The MMSC is for reference only.)
let mmsPars: sms.MmsParams = {
  slotId : 0,
  mmsc: 'http://mmsc.myuni.com.cn',
  data: filePath,
  mmsConfig: mmsConf
};

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
    sms.sendMms(this.context, mmsPars, async(err: BusinessError) =>{
        if (err) {
            console.error(`sendMms fail, err : ${JSON.stringify(err)}`);
            return;
        }
        console.log(`sendMms Success`);
        })
    }
}
```

## sms.sendMms<sup>11+</sup>

sendMms\(context: Context, mmsParams: MmsParams\): Promise&lt;void&gt;

Sends an MMS message. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                    |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| mmsParams | [MmsParams](#mmsparams11) | Yes  | Parameters (including the callback) for sending MMS messages. For details, see [MmsParams](#mmsparams11).|

**Return value**

| Type           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

FA model:
<!--code_no_check_fa-->
```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common, featureAbility } from '@kit.AbilityKit';

// Obtain the context.
let context: common.BaseContext = featureAbility.getContext();

// Configure the path for storing PDUs of MMS messages. Such PDUs are sent from the encoding API.
const sandBoxPath: string = '/data/storage/el2/base/files/';
let filePath: string = sandBoxPath + 'SendReq.mms';

// Options for sending MMS messages (The MMSC is for reference only.)
let mmsPars: sms.MmsParams = {
  slotId: 0,
  mmsc: 'http://mmsc.myuni.com.cn',
  data: filePath,
  mmsConfig: {
   userAgent:'ua',
   userAgentProfile: 'uaprof'
  }
};

// Call the sendMms API.
let promise = sms.sendMms(context, mmsPars);
promise.then(() => {
    console.log(`sendMms success`);
}).catch((err: BusinessError) => {
    console.error(`sendMms failed, promise: err->${JSON.stringify(err)}`);
});
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// Configure the path for storing PDUs of MMS messages. Such PDUs are sent from the encoding API.
const sandBoxPath = '/data/storage/el2/base/files/';
let filePath  = sandBoxPath + 'SendReq.mms';

// Configure the MMS user agent and profile. The default values are ua and uaprof, respectively. The configuration is subject to the carrier's requirements. 
let mmsConf: sms.MmsConfig = {
  userAgent:'ua',
  userAgentProfile: 'uaprof'
};

// Options for sending MMS messages (The MMSC is for reference only.)
let mmsPars: sms.MmsParams = {
  slotId : 0,
  mmsc: 'http://mmsc.myuni.com.cn',
  data: filePath,
  mmsConfig: mmsConf
};

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
    let promise = sms.sendMms(this.context, mmsPars);
    promise.then(() => {
        console.log(`sendMms success`);
    }).catch((err: BusinessError) => {
        console.error(`sendMms failed, promise: err->${JSON.stringify(err)}`);
    });
    }
}
```

## sms.downloadMms<sup>11+</sup>

downloadMms\(context: Context, mmsParams: MmsParams, callback: AsyncCallback&lt;void&gt;\): void

Downloads an MMS message. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_MMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                    |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| mmsParams | [MmsParams](#mmsparams11) | Yes  | Parameters (including the callback) for downloading MMS messages. For details, see [MmsParams](#mmsparams11).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

FA model:
<!--code_no_check_fa-->
```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common, featureAbility } from '@kit.AbilityKit';

// Obtain the context.
let context: common.BaseContext = featureAbility.getContext();

// Configure the path for storing the PDU of the MMS message.
const sandBoxPath: string = '/data/storage/el2/base/files/';
let filePath: string = sandBoxPath + 'RetrieveConf.mms';

// Parse the MMS URL from the WAP Push message.
let wapPushUrl: string = 'URL';

// Configure the parameters (including the callback) for downloading MMS messages.
let mmsPars: sms.MmsParams = {
  slotId: 0,
  mmsc: wapPushUrl,
  data: filePath,
  mmsConfig: {
   userAgent:'ua',
   userAgentProfile: 'uaprof'
  }
};

// Call the downloadMms API.
sms.downloadMms(context, mmsPars, async(err: BusinessError) =>{
  if (err) {
      console.error(`downloadMms fail, err : ${JSON.stringify(err)}`);
      return;
  }
  console.log(`downloadMms Success`);
})
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// Configure the path for storing the PDU of the MMS message.
const sandBoxPath = '/data/storage/el2/base/files/';
let filePath  = sandBoxPath + 'RetrieveConf.mms';

// Parse the MMS URL from the WAP Push message.
let wapPushUrl  = 'URL';

// Configure the MMS user agent and profile. The default values are ua and uaprof, respectively. The configuration is subject to the carrier's requirements. 
let mmsConf: sms.MmsConfig = {
  userAgent:'ua',
  userAgentProfile: 'uaprof'
};

// Configure the parameters (including the callback) for downloading MMS messages.
let mmsPars: sms.MmsParams = {
  slotId : 0,
  mmsc: wapPushUrl,
  data: filePath,
  mmsConfig: mmsConf
};

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
    sms.downloadMms(this.context, mmsPars, async(err: BusinessError) =>{
        if (err) {
            console.error(`downloadMms fail, err : ${JSON.stringify(err)}`);
            return;
        }
        console.log(`downloadMms Success`);
        });
    }
}
```

## sms.downloadMms<sup>11+</sup>

downloadMms\(context: Context, mmsParams: MmsParams\): Promise&lt;void&gt;

Sends an MMS message. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_MMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                    |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| mmsParams | [MmsParams](#mmsparams11) | Yes  | Parameters (including the callback) for sending MMS messages. For details, see [MmsParams](#mmsparams11).|

**Return value**

| Type           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

FA model:
<!--code_no_check_fa-->
```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common, featureAbility } from '@kit.AbilityKit';

// Obtain the context.
let context: common.BaseContext = featureAbility.getContext();

// Configure the path for storing the PDU of the MMS message.
const sandBoxPath: string = '/data/storage/el2/base/files/';
let filePath: string = sandBoxPath + 'RetrieveConf.mms';

// Parse the MMS URL from the WAP Push message.
let wapPushUrl: string = 'URL';

// Configure the parameters (including the callback) for downloading MMS messages.
let mmsPars: sms.MmsParams = {
  slotId: 0,
  mmsc: wapPushUrl,
  data: filePath,
  mmsConfig: {
   userAgent:'ua',
   userAgentProfile: 'uaprof'
  }
};

// Call the sendMms API.
let promise = sms.downloadMms(context, mmsPars);
promise.then(() => {
    console.log(`downloadMms success`);
}).catch((err: BusinessError) => {
    console.error(`downloadMms failed, promise: err->${JSON.stringify(err)}`);
});
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// Configure the path for storing the PDU of the MMS message.
const sandBoxPath = '/data/storage/el2/base/files/';
let filePath  = sandBoxPath + 'RetrieveConf.mms';

// Parse the MMS URL from the WAP Push message.
let wapPushUrl  = 'URL';

// Configure the MMS user agent and profile. The default values are ua and uaprof, respectively. The configuration is subject to the carrier's requirements. 
let mmsConf: sms.MmsConfig = {
  userAgent:'ua',
  userAgentProfile: 'uaprof'
};

// Configure the parameters (including the callback) for downloading MMS messages.
let mmsPars: sms.MmsParams = {
  slotId : 0,
  mmsc: wapPushUrl,
  data: filePath,
  mmsConfig: mmsConf
};

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
    let promise = sms.downloadMms(this.context, mmsPars);
    promise.then(() => {
        console.log(`downloadMms success`);
    }).catch((err: BusinessError) => {
        console.error(`downloadMms failed, promise: err->${JSON.stringify(err)}`);
    });
    }
}
```


## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number, callback: AsyncCallback&lt;void&gt;\): void

Sets the default slot ID of the SIM card used to send SMS messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: Clears the default configuration.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

sms.setDefaultSmsSlotId(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}.`);
});
```


## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number\): Promise&lt;void&gt;

Sets the default slot ID of the SIM card used to send SMS messages. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: Clears the default configuration.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

sms.setDefaultSmsSlotId(0).then(() => {
    console.log(`setDefaultSmsSlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback\<void\>\): void

Sets the short message service center (SMSC) address. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| smscAddr | string                    | Yes  | SMSC address.                       |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                               |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let smscAddr: string = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr, (err: BusinessError) => {
      console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string\): Promise\<void\>

Sets the SMSC address. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| smscAddr | string | Yes  | SMSC address.                       |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let smscAddr: string = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr).then(() => {
    console.log(`setSmscAddr success.`);
}).catch((err: BusinessError) => {
    console.error(`setSmscAddr failed, promise: err->${JSON.stringify(err)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the SMSC address. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                     |
| -------- | --------------------------- | ---- | ----------------------------------------- |
| slotId   | number                      | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                               |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
sms.getSmscAddr(slotId, (err: BusinessError, data: string) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number\): Promise\<string\>

Obtains the SMSC address. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                                         |
| --------------------- | --------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
sms.getSmscAddr(slotId).then((data: string) => {
    console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSmscAddr failed, promise: err->${JSON.stringify(err)}`);
});
```


## sms.splitMessage<sup>8+</sup>

splitMessage\(content: string, callback: AsyncCallback\<Array\<string\>\>\): void

Splits an SMS message into multiple segments. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                         | Mandatory| Description                         |
| -------- | ----------------------------- | ---- | ----------------------------- |
| content  | string                        | Yes  | SMS message content. The value cannot be null.|
| callback | AsyncCallback<Array<string\>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let content: string = "long message";
sms.splitMessage(content, (err: BusinessError, data: string[]) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.splitMessage<sup>8+</sup>

splitMessage\(content: string\): Promise\<Array\<string\>\>

Splits an SMS message into multiple segments. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| content | string | Yes  | SMS message content. The value cannot be null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Promise<Array<string\>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let content: string = "long message";
let promise = sms.splitMessage(content);
promise.then((data: string[]) => {
    console.log(`splitMessage success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`splitMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.addSimMessage<sup>7+</sup>

addSimMessage\(options: SimMessageOptions, callback: AsyncCallback\<void\>\): void

Adds a message to the SIM card. If the SIM card is full, an error is reported. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                    | Mandatory| Description           |
| -------- | ---------------------------------------- | ---- | --------------- |
| options  | [SimMessageOptions](#simmessageoptions7) | Yes  | SIM message options.|
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                           |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let simMessageOptions: sms.SimMessageOptions = {
    slotId: 0,
    smsc: "test",
    pdu: "xxxxxx",
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ
};
sms.addSimMessage(simMessageOptions, (err: BusinessError) => {
      console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sms.addSimMessage<sup>7+</sup>

addSimMessage\(options: SimMessageOptions\): Promise\<void\>

Adds a message to the SIM card. If the SIM card is full, an error is reported. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                    | Mandatory| Description           |
| ------- | ---------------------------------------- | ---- | --------------- |
| options | [SimMessageOptions](#simmessageoptions7) | Yes  | SIM message options.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let simMessageOptions: sms.SimMessageOptions = {
    slotId: 0,
    smsc: "test",
    pdu: "xxxxxx",
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ
};
sms.addSimMessage(simMessageOptions).then(() => {
    console.log(`addSimMessage success.`);
}).catch((err: BusinessError) => {
    console.error(`addSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.delSimMessage<sup>7+</sup>

delSimMessage\(slotId: number, msgIndex: number, callback: AsyncCallback\<void\>\): void

Deletes a message from the SIM card. If the specified **msgIndex** is invalid, an error is reported. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| msgIndex | number                    | Yes  | Message index.                                 |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let msgIndex: number = 1;
sms.delSimMessage(slotId, msgIndex, (err: BusinessError) => {
      console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sms.delSimMessage<sup>7+</sup>

delSimMessage\(slotId: number, msgIndex: number\): Promise\<void\>

Deletes a message from the SIM card. If the specified **msgIndex** is invalid, an error is reported. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| msgIndex | number | Yes  | Message index.                                 |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let msgIndex: number = 1;
let promise = sms.delSimMessage(slotId, msgIndex);
promise.then(() => {
    console.log(`delSimMessage success.`);
}).catch((err: BusinessError) => {
    console.error(`delSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.updateSimMessage<sup>7+</sup>

updateSimMessage\(options: UpdateSimMessageOptions, callback: AsyncCallback\<void\>\): void

Updates a SIM message. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                                | Mandatory| Description               |
| -------- | ---------------------------------------------------- | ---- | ------------------- |
| options  | [UpdateSimMessageOptions](#updatesimmessageoptions7) | Yes  | SIM message updating options.|
| callback | AsyncCallback&lt;void&gt;                            | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let updateSimMessageOptions: sms.UpdateSimMessageOptions = {
    slotId: 0,
    msgIndex: 1,
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,
    pdu: "xxxxxxx",
    smsc: "test"
};
sms.updateSimMessage(updateSimMessageOptions, (err: BusinessError) => {
      console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sms.updateSimMessage<sup>7+</sup>

updateSimMessage\(options: UpdateSimMessageOptions\): Promise\<void\>

Updates a SIM message. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                                | Mandatory| Description               |
| ------- | ---------------------------------------------------- | ---- | ------------------- |
| options | [UpdateSimMessageOptions](#updatesimmessageoptions7) | Yes  | SIM message updating options.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let updateSimMessageOptions: sms.UpdateSimMessageOptions = {
    slotId: 0,
    msgIndex: 1,
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,
    pdu: "xxxxxxx",
    smsc: "test"
};
let promise = sms.updateSimMessage(updateSimMessageOptions);
promise.then(() => {
    console.log(`updateSimMessage success.`);
}).catch((err: BusinessError) => {
    console.error(`updateSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getAllSimMessages<sup>7+</sup>

getAllSimMessages\(slotId: number, callback: AsyncCallback\<Array\<SimShortMessage\>\>\): void

Obtains all SIM card messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                     |
| -------- | ----------------------------------------------------------- | ---- | ----------------------------------------- |
| slotId   | number                                                      | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<Array<[SimShortMessage](#simshortmessage7)\>> | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                         |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
sms.getAllSimMessages(slotId, (err: BusinessError, data: sms.SimShortMessage[]) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getAllSimMessages<sup>7+</sup>

getAllSimMessages\(slotId: number\): Promise\<Array\<SimShortMessage\>\>

Obtains all SIM card messages. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                   | Description                              |
| ------------------------------------------------------- | ---------------------------------- |
| Promise<Array<[SimShortMessage](#simshortmessage7)\>&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                           |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let promise = sms.getAllSimMessages(slotId);
promise.then((data: sms.SimShortMessage[]) => {
    console.log(`getAllSimMessages success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getAllSimMessages failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setCBConfig<sup>7+</sup>

setCBConfig\(options: CBConfigOptions, callback: AsyncCallback\<void\>\): void

Sets the cell broadcast configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                | Mandatory| Description        |
| -------- | ------------------------------------ | ---- | ------------ |
| options  | [CBConfigOptions](#cbconfigoptions7) | Yes  | Cell broadcast configuration options.|
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                         |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let cbConfigOptions: sms.CBConfigOptions = {
    slotId: 0,
    enable: true,
    startMessageId: 100,
    endMessageId: 200,
    ranType: sms.RanType.TYPE_GSM
};
sms.setCBConfig(cbConfigOptions, (err: BusinessError) => {
      console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sms.setCBConfig<sup>7+</sup>

setCBConfig\(options: CBConfigOptions\): Promise\<void\>

Sets the cell broadcast configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                | Mandatory| Description        |
| ------- | ------------------------------------ | ---- | ------------ |
| options | [CBConfigOptions](#cbconfigoptions7) | Yes  | Cell broadcast configuration options.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                         |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let cbConfigOptions: sms.CBConfigOptions = {
    slotId: 0,
    enable: true,
    startMessageId: 100,
    endMessageId: 200,
    ranType: sms.RanType.TYPE_GSM
};
let promise = sms.setCBConfig(cbConfigOptions);
promise.then(() => {
    console.log(`setCBConfig success.`);
}).catch((err: BusinessError) => {
    console.error(`setCBConfig failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getSmsSegmentsInfo<sup>8+</sup>

getSmsSegmentsInfo\(slotId: number, message: string, force7bit: boolean, callback: AsyncCallback\<SmsSegmentsInfo\>\): void

Obtains SMS message segment information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                     |
| --------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| slotId    | number                                                       | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| message   | string                                                       | Yes  | SMS message.                                     |
| force7bit | boolean                                                      | Yes  | Whether to use 7-bit coding.                         |
| callback  | AsyncCallback&lt;[SmsSegmentsInfo](#smssegmentsinfo8)&gt; | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
sms.getSmsSegmentsInfo(slotId, "message", false, (err: BusinessError, data: sms.SmsSegmentsInfo) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmsSegmentsInfo<sup>8+</sup>

getSmsSegmentsInfo\(slotId: number, message: string, force7bit: boolean\): Promise\<SmsSegmentsInfo\>

Obtains SMS message segment information. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name   | Type   | Mandatory| Description                                     |
| --------- | ------- | ---- | ----------------------------------------- |
| slotId    | number  | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| message   | string  | Yes  | SMS message.                                     |
| force7bit | boolean | Yes  | Whether to use 7-bit coding.                         |

**Return value**

| Type                                                   | Description                         |
| ------------------------------------------------------- | ----------------------------- |
| Promise&lt;[SmsSegmentsInfo](#smssegmentsinfo8)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let promise = sms.getSmsSegmentsInfo(slotId, "message", false);
promise.then((data: sms.SmsSegmentsInfo) => {
    console.log(`getSmsSegmentsInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSmsSegmentsInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.isImsSmsSupported<sup>8+</sup>

isImsSmsSupported\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether SMS is supported on IMS. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| slotId   | number                       | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                          |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
sms.isImsSmsSupported(slotId, (err: BusinessError, data: boolean) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.isImsSmsSupported<sup>8+</sup>

isImsSmsSupported\(slotId: number\): Promise\<boolean\>

Checks whether SMS is supported on IMS. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory | Description                                 |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                  | Description                   |
| ---------------------- | ----------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                         |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let promise = sms.isImsSmsSupported(slotId);
promise.then((data: boolean) => {
    console.log(`isImsSmsSupported success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isImsSmsSupported failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getImsShortMessageFormat<sup>8+</sup>

getImsShortMessageFormat\(callback: AsyncCallback\<string\>\): void

Obtains the SMS format supported by the IMS, for example, **3gpp**, **3gpp2**, or **unknown**. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description      |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                           |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

sms.getImsShortMessageFormat((err: BusinessError, data: string) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getImsShortMessageFormat<sup>8+</sup>

getImsShortMessageFormat\(\): Promise\<string\>

Obtains the SMS format supported by the IMS, for example, **3gpp**, **3gpp2**, or **unknown**. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Return value**

| Type                 | Description                      |
| --------------------- | -------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

sms.getImsShortMessageFormat().then((data: string) => {
    console.log(`getImsShortMessageFormat success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getImsShortMessageFormat failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.decodeMms<sup>8+</sup>

decodeMms\(mmsFilePathName: string | Array\<number\>, callback: AsyncCallback\<MmsInformation\>\): void

Decodes MMS messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name         | Type                                                   | Mandatory| Description          |
| --------------- | ------------------------------------------------------- | ---- | -------------- |
| mmsFilePathName | string \|Array<number\>                                 | Yes  | MMS message file path.|
| callback        | AsyncCallback&lt;[MmsInformation](#mmsinformation8)&gt; | Yes  | Callback used to return the result, which is carried in {@code MmsInformation}.    |

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mmsFilePathName: string = "filename";
sms.decodeMms(mmsFilePathName, (err: BusinessError, data: sms.MmsInformation) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});

const mmsPdu: Array<number> = [0x8c, 0x80, 0x98, 0x31, 0x00, 0x8d, 0x92, 0x89, 0x09, 0x80, 0x07, 0xea, 0x31, 0x30, 0x30, 0x38, 0x36, 0x00, 0x97, 0x07, 0xea, 0x31, 0x30, 0x30,0x31, 0x30, 0x00, 0x84, 0x74, 0x79, 0x70, 0x65, 0x00, 0x00];
sms.decodeMms(mmsPdu, (err: BusinessError, data: sms.MmsInformation) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.decodeMms<sup>8+</sup>

decodeMms\(mmsFilePathName: string | Array\<number\>\): Promise\<MmsInformation\>

Decodes MMS messages. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name         | Type                   | Mandatory| Description          |
| --------------- | ----------------------- | ---- | -------------- |
| mmsFilePathName | string \|Array<number\> | Yes  | MMS message file path.|

**Return value**

| Type                                                     | Description                       |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;&lt;[MmsInformation](#mmsinformation8)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mmsFilePathName: string = "filename";
let promise = sms.decodeMms(mmsFilePathName);
promise.then((data: sms.MmsInformation) => {
    console.log(`decodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`decodeMms failed, promise: err->${JSON.stringify(err)}`);
});

const mmsPdu: Array<number> = [0x8c, 0x80, 0x98, 0x31, 0x00, 0x8d, 0x92, 0x89, 0x09, 0x80, 0x07, 0xea, 0x31, 0x30, 0x30, 0x38, 0x36, 0x00, 0x97, 0x07, 0xea, 0x31, 0x30, 0x30,0x31, 0x30, 0x00, 0x84, 0x74, 0x79, 0x70, 0x65, 0x00, 0x00];
let promiseArr = sms.decodeMms(mmsPdu);
promiseArr.then((data: sms.MmsInformation) => {
    console.log(`decodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`decodeMms failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.encodeMms<sup>8+</sup>

encodeMms\(mms: MmsInformation, callback: AsyncCallback\<Array\<number\>\>\): void

MMS message code. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                               | Mandatory| Description      |
| -------- | ----------------------------------- | ---- | ---------- |
| mms      | [MmsInformation](#mmsinformation8)  | Yes  | MMS message information.|
| callback | AsyncCallback&lt;Array<number\>&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mmsAcknowledgeInd: sms.MmsAcknowledgeInd = {
    transactionId: "100",
    version: sms.MmsVersionType.MMS_VERSION_1_0,
    reportAllowed: sms.ReportType.MMS_YES
};
let mmsInformation: sms.MmsInformation = {
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,
    mmsType: mmsAcknowledgeInd
};
sms.encodeMms(mmsInformation, (err: BusinessError, data: number[]) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.encodeMms<sup>8+</sup>

encodeMms\(mms: MmsInformation\): Promise\<Array\<number\>\>

MMS message code. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type                              | Mandatory| Description      |
| ------ | ---------------------------------- | ---- | ---------- |
| mms    | [MmsInformation](#mmsinformation8) | Yes  | MMS message information.|

**Return value**

| Type                         | Description                               |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<number\>&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { sms } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mmsAcknowledgeInd: sms.MmsAcknowledgeInd = {
    transactionId: "100",
    version: sms.MmsVersionType.MMS_VERSION_1_0,
    reportAllowed: sms.ReportType.MMS_YES
};
let mmsInformation: sms.MmsInformation = {
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,
    mmsType: mmsAcknowledgeInd
};
sms.encodeMms(mmsInformation).then((data: number[]) => {
    console.log(`encodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`encodeMms failed, promise: err->${JSON.stringify(err)}`);
});
```


## MmsParams<sup>11+</sup>

Defines the parameters for sending SMS messages.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|       Name      | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId<sup>11+</sup>           | number                                                       | Yes  | Slot ID of the SIM card used for sending SMS messages. <br>- **0**: card slot 1<br>- **1**: card slot 2     |
| mmsc<sup>11+</sup>  | string                                                       | Yes  | MMSC address.                                            |
| data<sup>11+</sup>          | string                               | Yes  | MMS PDU address.|
| mmsConfig<sup>11+</sup>    | MmsConfig                                                       | No  | MMS configuration file. For details, see [MmsParams](#mmsparams11).               |

## MmsConfig<sup>11+</sup>

MMS configuration file.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|       Name      | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| userAgent<sup>11+</sup>  | string                                                       | Yes  | User agent.                                            |
| userAgentProfile<sup>11+</sup>    | string                                                       | Yes  | User agent profile.               |



## MmsInformation<sup>8+</sup>

Defines the MMS message information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|     Name   | Type                                                        | Mandatory|    Description   |
| ----------- | ------------------------------------------------------------ | ---- | ---------- |
| messageType | [MessageType](#messagetype8)                                 | Yes  | Message type.|
| mmsType     | [MmsSendReq](#mmssendreq8) \|[MmsSendConf](#mmssendconf8) \|[MmsNotificationInd](#mmsnotificationind8) \|[MmsRespInd](#mmsrespind8) \|[MmsRetrieveConf](#mmsretrieveconf8)\|[MmsAcknowledgeInd](#mmsacknowledgeind8)\|[MmsDeliveryInd](#mmsdeliveryind8)\|[MmsReadOrigInd](#mmsreadorigind8)\|[MmsReadRecInd](#mmsreadrecind8) | Yes  | PDU header type.|
| attachment  | Array<[MmsAttachment](#mmsattachment8)\>                     | No  | Attachment.     |

## MmsSendReq<sup>8+</sup>

Defines an MMS message sending request.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|       Name      | Type                                | Mandatory| Description        |
| ---------------- | ------------------------------------ | ---- | ------------ |
| from             | [MmsAddress](#mmsaddress8)           | Yes  | MMS message source.    |
| transactionId    | string                               | Yes  | Transaction ID.      |
| contentType      | string                               | Yes  | Content type.    |
| version          | [MmsVersionType](#mmsversiontype8)   | Yes  | Version.        |
| to               | Array<[MmsAddress](#mmsaddress8)\>   | No  | Destination address.      |
| date             | number                               | No  | Date.        |
| cc               | Array<[MmsAddress](#mmsaddress8)\>   | No  | Carbon copy.        |
| bcc              | Array<[MmsAddress](#mmsaddress8)\>   | No  | Blind carbon copy.      |
| subject          | string                               | No  | Subject.        |
| messageClass     | number                               | No  | Message class.      |
| expiry           | number                               | No  | Expiration.        |
| priority         | [MmsPriorityType](#mmsprioritytype8) | No  | Priority.        |
| senderVisibility | number                               | No  | Sender visibility.|
| deliveryReport   | number                               | No  | Delivery report.    |
| readReport       | number                               | No  | Read report.    |

## MmsSendConf<sup>8+</sup>

Defines the MMS message sending configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|     Name     | Type                              | Mandatory| Description    |
| ------------- | ---------------------------------- | ---- | -------- |
| responseState | number                             | Yes  | Response status.|
| transactionId | string                             | Yes  | Transaction ID.  |
| version       | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| messageId     | string                             | No  | Message ID.  |

## MmsNotificationInd<sup>8+</sup>

Defines an MMS notification index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|      Name      | Type                              | Mandatory| Description    |
| --------------- | ---------------------------------- | ---- | -------- |
| transactionId   | string                             | Yes  | Transaction ID.  |
| messageClass    | number                             | Yes  | Message class.  |
| messageSize     | number                             | Yes  | Message size.|
| expiry          | number                             | Yes  | Expiration.    |
| contentLocation | string                             | Yes  | Content location.|
| version         | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| from            | [MmsAddress](#mmsaddress8)         | No  | Source address.    |
| subject         | string                             | No  | Subject.    |
| deliveryReport  | number                             | No  | Status report.|
| contentClass    | number                             | No  | Content class.  |

## MmsAcknowledgeInd<sup>8+</sup>

Defines an MMS confirmation index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|      Name    | Type                              | Mandatory| Description    |
| ------------- | ---------------------------------- | ---- | -------- |
| transactionId | string                             | Yes  | Transaction ID.  |
| version       | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| reportAllowed | [ReportType](#reporttype8)         | No  | Report allowed.|

## MmsRetrieveConf<sup>8+</sup>

Defines the MMS message retrieval configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|      Name     | Type                                | Mandatory| Description    |
| -------------- | ------------------------------------ | ---- | -------- |
| transactionId  | string                               | Yes  | Transaction ID.  |
| messageId      | string                               | Yes  | Message ID.  |
| date           | number                               | Yes  | Date.    |
| contentType    | string                               | Yes  | Content type.|
| to             | Array<[MmsAddress](#mmsaddress8)\>   | Yes  | Destination address.  |
| version        | [MmsVersionType](#mmsversiontype8)   | Yes  | Version.    |
| from           | [MmsAddress](#mmsaddress8)           | No  | Source address.    |
| cc             | Array<[MmsAddress](#mmsaddress8)\>   | No  | Carbon copy.    |
| subject        | string                               | No  | Subject.    |
| priority       | [MmsPriorityType](#mmsprioritytype8) | No  | Priority.  |
| deliveryReport | number                               | No  | Status report.|
| readReport     | number                               | No  | Read report.|
| retrieveStatus | number                               | No  | Retrieval status.|
| retrieveText   | string                               | No  | Retrieval text.|

## MmsReadOrigInd<sup>8+</sup>

Defines the original MMS message reading index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|    Name   | Type                              | Mandatory| Description    |
| ---------- | ---------------------------------- | ---- | -------- |
| version    | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| messageId  | string                             | Yes  | Message ID.  |
| to         | Array<[MmsAddress](#mmsaddress8)\> | Yes  | Destination address.  |
| from       | [MmsAddress](#mmsaddress8)         | Yes  | Source address.    |
| date       | number                             | Yes  | Date.    |
| readStatus | number                             | Yes  | Read status.|

## MmsReadRecInd<sup>8+</sup>

Defines the MMS message reading index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|    Name   | Type                              | Mandatory| Description    |
| ---------- | ---------------------------------- | ---- | -------- |
| version    | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| messageId  | string                             | Yes  | Message ID.  |
| to         | Array<[MmsAddress](#mmsaddress8)\> | Yes  | Destination address.  |
| from       | [MmsAddress](#mmsaddress8)         | Yes  | Source address.    |
| readStatus | number                             | Yes  | Read status.|
| date       | number                             | No  | Date.    |

## MmsAttachment<sup>8+</sup>

Defines the attachment of an MMS message.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|          Name          | Type                                | Mandatory| Description              |
| ----------------------- | ------------------------------------ | ---- | ------------------ |
| contentId               | string                               | Yes  | Content ID.            |
| contentLocation         | string                               | Yes  | Content location.          |
| contentDisposition      | [DispositionType](#dispositiontype8) | Yes  | Content disposition.          |
| contentTransferEncoding | string                               | Yes  | Encoding for content transfer.      |
| contentType             | string                               | Yes  | Content type.          |
| isSmil                  | boolean                              | Yes  | Whether the synchronized multimedia integration language is used.|
| path                    | string                               | No  | Path.              |
| inBuff                  | Array<number\>                       | No  | Whether the message is in the buffer.          |
| fileName                | string                               | No  | File name.            |
| charset                 | [MmsCharSets](#mmscharsets8)         | No  | Character set.            |

## MmsAddress<sup>8+</sup>

Defines an MMSC address.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|   Name | Type                        | Mandatory| Description  |
| ------- | ---------------------------- | ---- | ------ |
| address | string                       | Yes  | Network address.  |
| charset | [MmsCharSets](#mmscharsets8) | Yes  | Character set.|

## MessageType<sup>8+</sup>

Message type.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|          Name            | Value  | Description                |
| ------------------------- | ---- | -------------------- |
| TYPE_MMS_SEND_REQ         | 128  | MMS message sending request.    |
| TYPE_MMS_SEND_CONF        | 129  | MMS message sending configuration.    |
| TYPE_MMS_NOTIFICATION_IND | 130  | MMS notification index.    |
| TYPE_MMS_RESP_IND         | 131  | MMS message response index.    |
| TYPE_MMS_RETRIEVE_CONF    | 132  | MMS message retrieval configuration.    |
| TYPE_MMS_ACKNOWLEDGE_IND  | 133  | MMS message acknowledgement index.    |
| TYPE_MMS_DELIVERY_IND     | 134  | MMS message delivery index.    |
| TYPE_MMS_READ_REC_IND     | 135  | MMS message reading and receiving index.|
| TYPE_MMS_READ_ORIG_IND    | 136  | Original MMS message reading index.|

## MmsPriorityType<sup>8+</sup>

Enumerates MMS message priorities.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|    Name   | Value  | Description          |
| ---------- | ---- | -------------- |
| MMS_LOW    | 128  | Low priority.  |
| MMS_NORMAL | 129  | Normal priority.|
| MMS_HIGH   | 130  | High priority.  |

## MmsVersionType<sup>8+</sup>

Enumerates MMS versions.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|      Name      | Value  | Description       |
| --------------- | ---- | ----------- |
| MMS_VERSION_1_0 | 0x10 | MMS version 1_0.|
| MMS_VERSION_1_1 | 0x11 | MMS version 1_1.|
| MMS_VERSION_1_2 | 0x12 | MMS version 1_2.|
| MMS_VERSION_1_3 | 0x13 | MMS version 1_3.|

## MmsCharSets<sup>8+</sup>

Enumerates MMS character sets.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|      Name      | Value    | Description               |
| --------------- | ------ | ------------------- |
| BIG5            | 0X07EA | BIG5 format.           |
| ISO_10646_UCS_2 | 0X03E8 | ISO_10646_UCS_2 format.|
| ISO_8859_1      | 0X04   | ISO_8859_1 format.     |
| ISO_8859_2      | 0X05   | ISO_8859_2 format.     |
| ISO_8859_3      | 0X06   | ISO_8859_3 format.     |
| ISO_8859_4      | 0X07   | ISO_8859_4 format.     |
| ISO_8859_5      | 0X08   | ISO_8859_5 format.     |
| ISO_8859_6      | 0X09   | ISO_8859_6 format.     |
| ISO_8859_7      | 0X0A   | ISO_8859_7 format.     |
| ISO_8859_8      | 0X0B   | ISO_8859_8 format.     |
| ISO_8859_9      | 0X0C   | ISO_8859_9 format.     |
| SHIFT_JIS       | 0X11   | SHIFT_JIS format.      |
| US_ASCII        | 0X03   | US_ASCII format.       |
| UTF_8           | 0X6A   | UTF_8 format.          |

## DispositionType<sup>8+</sup>

Enumerates disposition types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|    Name   | Value  | Description    |
| ---------- | ---- | -------- |
| FROM_DATA  | 0    | Data source.|
| ATTACHMENT | 1    | Attachment.    |
| INLINE     | 2    | Inlining.    |

## ReportType<sup>8+</sup>

Enumerates report types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|  Name  | Value  | Description|
| ------- | ---- | ---- |
| MMS_YES | 128  | YES  |
| MMS_NO  | 129  | NO   |

## CBConfigOptions<sup>7+</sup>

Defines the cell broadcast configuration options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|      Name     | Type                | Mandatory| Description        |
| -------------- | -------------------- | ---- | ------------ |
| slotId         | number               | Yes  | Card slot ID.      |
| enable         | boolean              | Yes  | Whether to enable cell broadcast.        |
| startMessageId | number               | Yes  | Start message ID.  |
| endMessageId   | number               | Yes  | End message ID.  |
| ranType        | [RanType](#rantype7) | Yes  | RAN type.|

## SimMessageStatus<sup>7+</sup>

Defines the SIM message status.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|           Name           | Value  | Description                       |
| ------------------------- | ---- | --------------------------- |
| SIM_MESSAGE_STATUS_FREE   | 0    | Free space state of the SIM card.      |
| SIM_MESSAGE_STATUS_READ   | 1    | Read state.               |
| SIM_MESSAGE_STATUS_UNREAD | 3    | Unread state.               |
| SIM_MESSAGE_STATUS_SENT   | 5    | Storage of sent messages (applicable only to SMS).|
| SIM_MESSAGE_STATUS_UNSENT | 7    | Storage of unsent messages (applicable only to SMS).|

## RanType<sup>7+</sup>

RAN type.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|   Name   | Value  | Description|
| --------- | ---- | ---- |
| TYPE_GSM  | 1    | GSM  |
| TYPE_CDMA | 2    | CMDA |

## SmsEncodingScheme<sup>8+</sup>

Enumerates SMS encoding schemes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|         Name        | Value  | Description        |
| -------------------- | ---- | ------------ |
| SMS_ENCODING_UNKNOWN | 0    | Unknown code.|
| SMS_ENCODING_7BIT    | 1    | 7-digit code. |
| SMS_ENCODING_8BIT    | 2    | 8-digit code. |
| SMS_ENCODING_16BIT   | 3    | 16-digit code.|

## SimMessageOptions<sup>7+</sup>

Defines the SIM message options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|  Name | Type                                  | Mandatory| Description          |
| ------ | -------------------------------------- | ---- | -------------- |
| slotId | number                                 | Yes  | Card slot ID.        |
| smsc   | string                                 | Yes  | Short message service center.|
| pdu    | string                                 | Yes  | Protocol data unit.  |
| status | [SimMessageStatus](#simmessagestatus7) | Yes  | Status.          |

## UpdateSimMessageOptions<sup>7+</sup>

Defines the updating SIM message options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|   Name   | Type                                  | Mandatory| Description          |
| --------- | -------------------------------------- | ---- | -------------- |
| slotId    | number                                 | Yes  | Card slot ID.        |
| msgIndex  | number                                 | Yes  | Message index.      |
| newStatus | [SimMessageStatus](#simmessagestatus7) | Yes  | New status.        |
| pdu       | string                                 | Yes  | Protocol data unit.  |
| smsc      | string                                 | Yes  | Short message service center.|

## SimShortMessage<sup>7+</sup>

Defines a SIM message.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|       Name      | Type                                  | Mandatory| Description         |
| ---------------- | -------------------------------------- | ---- | ------------- |
| shortMessage     | [ShortMessage](js-apis-sms.md#shortmessage)          | Yes  | SMS message.       |
| simMessageStatus | [SimMessageStatus](#simmessagestatus7) | Yes  | SIM message status.|
| indexOnSim       | number                                 | Yes  | SIM card index.    |

## MmsDeliveryInd<sup>8+</sup>

Defines an MMS message delivery index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|    Name  | Type                              | Mandatory| Description  |
| --------- | ---------------------------------- | ---- | ------ |
| messageId | string                             | Yes  | Message ID.|
| date      | number                             | Yes  | Date.  |
| to        | Array<[MmsAddress](#mmsaddress8)\> | Yes  | Destination address.|
| status    | number                             | Yes  | Status.  |
| version   | [MmsVersionType](#mmsversiontype8) | Yes  | Version.  |

## MmsRespInd<sup>8+</sup>

Defines an MMS response index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|     Name     | Type                              | Mandatory| Description    |
| ------------- | ---------------------------------- | ---- | -------- |
| transactionId | string                             | Yes  | Event ID.  |
| status        | number                             | Yes  | Status.    |
| version       | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| reportAllowed | [ReportType](#reporttype8)         | No  | Report allowed.|

## SmsSegmentsInfo<sup>8+</sup>

Defines the SMS message segment information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

|        Name         | Type                                    | Mandatory| Description        |
| -------------------- | ---------------------------------------- | ---- | ------------ |
| splitCount           | number                                   | Yes  | Split count.    |
| encodeCount          | number                                   | Yes  | Encoding count.    |
| encodeCountRemaining | number                                   | Yes  | Remaining encoding count.|
| scheme               | [SmsEncodingScheme](#smsencodingscheme8) | Yes  | Encoding scheme.|
