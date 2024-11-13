# @ohos.ai.intelligentVoice (Intelligent Voice) (System API)

The **intelligentVoice** module provides the intelligent voice enrollment and voice wakeup functions.

Its functions are implemented by:

- [IntelligentVoiceManager](#intelligentvoicemanager): intelligent voice manager class, which declares the functions provided by the module. Currently, voice enrollment and voice wakeup are supported. Before developing intelligent voice functions, call [getIntelligentVoiceManager()](#intelligentvoicegetintelligentvoicemanager) to check whether they are supported.
- [EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine): class that implements voice enrollment. You need to perform voice enrollment before using voice wakeup.
- [WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine): class that implements voice wakeup. You need to perform voice enrollment before using voice wakeup.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
>
> - The kit to which **@ohos.ai.intelligentVoice** belongs has been changed from MindSpore Lite Kit to Basic Services Kit. You need to use the new module name **@kit.BasicServicesKit** when importing the module. Otherwise, the APIs of this module cannot be used.

## Modules to Import
```ts
import { intelligentVoice } from '@kit.BasicServicesKit';
```

## intelligentVoice.getIntelligentVoiceManager

getIntelligentVoiceManager(): IntelligentVoiceManager

Obtains an instance of the intelligent voice manager.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                         | Description        |
| ----------------------------- | ------------ |
| [IntelligentVoiceManager](#intelligentvoicemanager)| Instance of the intelligent voice manager.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let intelligentVoiceManager: intelligentVoice.IntelligentVoiceManager | null = null;
try {
  intelligentVoiceManager = intelligentVoice.getIntelligentVoiceManager();
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get IntelligentVoiceManager failed. Code:${error.code}, message:${error.message}`);
}
```

## intelligentVoice.getWakeupManager<sup>12+</sup>

getWakeupManager(): WakeupManager

Obtains an instance of the **WakeupManager** class.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                         | Description        |
| ----------------------------- | ------------ |
| [WakeupManager](#wakeupmanager12) | Instance of the intelligent voice manager.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                              |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wakeupManager: intelligentVoice.WakeupManager | null = null;
try {
  wakeupManager = intelligentVoice.getWakeupManager();
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get WakeupManager failed. Code:${error.code}, message:${error.message}`);
}
```

## intelligentVoice.createEnrollIntelligentVoiceEngine

createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor, callback: AsyncCallback&lt;EnrollIntelligentVoiceEngine&gt;): void

Creates an instance of the intelligent voice enrollment engine. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [EnrollIntelligentVoiceEngineDescriptor](#enrollintelligentvoiceenginedescriptor)                              | Yes  | Descriptor of the intelligent voice enrollment engine.  |
| callback    | AsyncCallback\<[EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)\>         | Yes  | Callback used to return the result.  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let engineDescriptor: intelligentVoice.EnrollIntelligentVoiceEngineDescriptor = {
  wakeupPhrase: 'Xiaohua Xiaohua',
}
let enrollIntelligentVoiceEngine: intelligentVoice.EnrollIntelligentVoiceEngine | null = null;
intelligentVoice.createEnrollIntelligentVoiceEngine(engineDescriptor, (err: BusinessError, data: intelligentVoice.EnrollIntelligentVoiceEngine) => {
  if (err) {
    console.error(`Failed to create enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
  } else {
    console.info(`Succeeded in creating enrollIntelligentVoice engine.`);
    enrollIntelligentVoiceEngine = data;
  }
});
```

## intelligentVoice.createEnrollIntelligentVoiceEngine

createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor): Promise&lt;EnrollIntelligentVoiceEngine&gt;


Creates an instance of the intelligent voice enrollment engine. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [EnrollIntelligentVoiceEngineDescriptor](#enrollintelligentvoiceenginedescriptor)                              | Yes  | Descriptor of the intelligent voice enrollment engine.  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise\<[EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)\>           | Callback used to return the result.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let engineDescriptor: intelligentVoice.EnrollIntelligentVoiceEngineDescriptor = {
  wakeupPhrase: 'Xiaohua Xiaohua',
}
let enrollIntelligentVoiceEngine: intelligentVoice.EnrollIntelligentVoiceEngine | null = null;
intelligentVoice.createEnrollIntelligentVoiceEngine(engineDescriptor).then((data: intelligentVoice.EnrollIntelligentVoiceEngine) => {
  enrollIntelligentVoiceEngine = data;
  console.info(`Succeeded in creating enrollIntelligentVoice engine.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
});
```

## intelligentVoice.createWakeupIntelligentVoiceEngine

createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor, callback: AsyncCallback&lt;WakeupIntelligentVoiceEngine&gt;): void


Creates an instance of the intelligent voice wakeup engine. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [WakeupIntelligentVoiceEngineDescriptor](#wakeupintelligentvoiceenginedescriptor)                              | Yes  | Descriptor of the intelligent voice wakeup engine.  |
| callback    | AsyncCallback\<[WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)\>         | Yes  | Callback used to return the result.  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wakeupEngineDescriptor: intelligentVoice.WakeupIntelligentVoiceEngineDescriptor = {
  needReconfirm: true,
  wakeupPhrase: 'Xiaohua Xiaohua',
}
let wakeupIntelligentVoiceEngine: intelligentVoice.WakeupIntelligentVoiceEngine | null = null;
intelligentVoice.createWakeupIntelligentVoiceEngine(wakeupEngineDescriptor, (err: BusinessError, data: intelligentVoice.WakeupIntelligentVoiceEngine) => {
  if (err) {
    console.error(`Failed to create wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
  } else {
    console.info(`Succeeded in creating wakeupIntelligentVoice engine.`);
    wakeupIntelligentVoiceEngine = data;
  }
});
```

## intelligentVoice.createWakeupIntelligentVoiceEngine

createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor): Promise&lt;WakeupIntelligentVoiceEngine&gt;

Creates an instance of the intelligent voice wakeup engine. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [WakeupIntelligentVoiceEngineDescriptor](#wakeupintelligentvoiceenginedescriptor)                              | Yes  | Descriptor of the intelligent voice wakeup engine.  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise\<[WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)>           | Callback used to return the result.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wakeupEngineDescriptor: intelligentVoice.WakeupIntelligentVoiceEngineDescriptor = {
  needReconfirm: true,
  wakeupPhrase: 'Xiaohua Xiaohua',
}
let wakeupIntelligentVoiceEngine: intelligentVoice.WakeupIntelligentVoiceEngine | null = null;
intelligentVoice.createWakeupIntelligentVoiceEngine(wakeupEngineDescriptor).then((data: intelligentVoice.WakeupIntelligentVoiceEngine) => {
  wakeupIntelligentVoiceEngine = data;
  console.info(`Succeeded in creating wakeupIntelligentVoice engine.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
});
```

## IntelligentVoiceManager

Class that implements intelligent voice management. Before use, you need to call [getIntelligentVoiceManager()](#intelligentvoicegetintelligentvoicemanager) to obtain an **IntelligentVoiceManager** object.

### getCapabilityInfo

getCapabilityInfo(): Array&lt;IntelligentVoiceEngineType&gt;

Obtains the list of supported intelligent voice engine types.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[IntelligentVoiceEngineType](#intelligentvoiceenginetype)\>            | Array of supported intelligent voice engine types.             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
if (intelligentVoiceManager != null) {
  let info = intelligentVoiceManager.getCapabilityInfo();
}
```

### on('serviceChange')

on(type: 'serviceChange', callback: Callback&lt;ServiceChangeType&gt;): void

Subscribes to service change events. A callback is invoked when the status of the intelligent voice service changes.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. This field has a fixed value of **serviceChange**.|
| callback | Callback\<[ServiceChangeType](#servicechangetype)\> | Yes  | Callback for the service status change.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
if (intelligentVoiceManager != null) {
  intelligentVoiceManager.on('serviceChange', (serviceChangeType: intelligentVoice.ServiceChangeType) => {});
}
```

### off('serviceChange')

off(type: 'serviceChange', callback?: Callback\<ServiceChangeType\>): void

Unsubscribes from service change events.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. This field has a fixed value of **serviceChange**.|
| callback | Callback\<[ServiceChangeType](#servicechangetype)\> | No  | Callback for processing of the service status change event. If this parameter is specified, only the specified callback will be unsubscribed. Otherwise, all callbacks will be unsubscribed. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
if (intelligentVoiceManager != null) {
  intelligentVoiceManager.off('serviceChange');
}
```

## WakeupManager<sup>12+</sup>

Represents the **WakeupManager** class. Before using this class, you need to obtain an instance by calling [getWakeupManager()](#intelligentvoicegetwakeupmanager12).

### setParameter<sup>12+</sup>

setParameter(key: string, value: string): Promise\<void\>

Sets the specified wakeup parameter. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key, which corresponds to the wakeup keyword. Currently, only **wakeup_phrase** is supported.|
| value     | string                           | Yes  | Value.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupManager != null) {
  (wakeupManager as intelligentVoice.WakeupManager).setParameter('wakeup_phrase', 'xiaohuaxiaohua').then(() => {
    console.info(`Succeeded in setting parameter`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);
  });
}
```

### getParameter<sup>12+</sup>

getParameter(key: string): Promise\<string\>

Obtains specified intelligent voice parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key, which corresponds to the registration information. Currently, only **isEnrolled** is supported.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string\>            | Promise used to return the result. The value **true** indicates registered, and the value **false** indicates the opposite.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupManager != null) {
  (wakeupManager as intelligentVoice.WakeupManager).getParameter('isEnrolled').then((data: string) => {
    let param: string = data;
    console.info(`Succeeded in getting parameter, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);
  });
}
```

### getUploadFiles<sup>12+</sup>

getUploadFiles(maxCount: number): Promise&lt;Array&lt;UploadFile&gt;&gt;

Obtain the saved wakeup keyword files. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| maxCount     | number                           | Yes  | Number of obtained files.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;[UploadFile](#uploadfile12)&gt;&gt;   | Promise used to return the obtained files.     |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                        |
| 22700102 | Invalid parameter.                            |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupManager != null) {
  (wakeupManager as intelligentVoice.WakeupManager).getUploadFiles(2).then((data: Array<intelligentVoice.UploadFile>) => {
    let param: Array<intelligentVoice.UploadFile> = data;
    console.info(`Succeeded in getting upload files, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get upload files, Code:${err.code}, message:${err.message}`);
  });
}
```


### getWakeupSourceFiles<sup>12+</sup>

getWakeupSourceFiles(): Promise&lt;Array&lt;WakeupSourceFile&gt;&gt;

Obtains wakeup resource files, such as registration corpus and path. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;[WakeupSourceFile](#wakeupsourcefile12)&gt;&gt;            | Promise used to return the wakeup resource file.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                        |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupManager != null) {
  (wakeupManager as intelligentVoice.WakeupManager).getWakeupSourceFiles().then(
    (data: Array<intelligentVoice.WakeupSourceFile>) => {
    let param: Array<intelligentVoice.WakeupSourceFile> = data;
    console.info(`Succeeded in getting wakeup source files, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get wakeup source files, Code:${err.code}, message:${err.message}`);
  });
}
```

### enrollWithWakeupFilesForResult<sup>12+</sup>

enrollWithWakeupFilesForResult(wakeupFiles: Array\<WakeupSourceFile\>, wakeupInfo: string): Promise\<EnrollResult\>

Registers with wakeup resource files to obtain wakeup word evaluation results. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| wakeupFiles     | Array\<[WakeupSourceFile](#wakeupsourcefile12)\>                           | Yes  | Wakeup resource files.|
| wakeupInfo     | string                           | Yes  | Wakeup information, including the type and version of the source and target devices.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollResult](#enrollresult)&gt;    | Promise used to return the result.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                        |
| 22700102 | Invalid parameter.                        |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filesInfo: Array<intelligentVoice.WakeupSourceFile> = [];
filesInfo[0] = {filePath: "", fileContent: new ArrayBuffer(100)};
let wakeupInfo: string = "version: 123"

if (wakeupManager != null) {
  (wakeupManager as intelligentVoice.WakeupManager).enrollWithWakeupFilesForResult(
    filesInfo, wakeupInfo).then(
    (data: intelligentVoice.EnrollResult) => {
      let param: intelligentVoice.EnrollResult = data;
      console.info(`Succeeded in enrolling with wakeup files for result, param:${param}`);
    }).catch((err: BusinessError) => {
    console.error(`Failed to enroll with wakeup files for result, Code:${err.code}, message:${err.message}`);
  });
}
```

### clearUserData<sup>12+</sup>

clearUserData(): Promise&lt;void&gt;

Clears user data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                 |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupManager != null) {
  (wakeupManager as intelligentVoice.WakeupManager).clearUserData().then(() => {
    console.info(`Succeeded in clearing user data.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to clear user data, Code:${err.code}, message:${err.message}`);
  });
}
```

## UploadFileType<sup>12+</sup>

Enumerates upload file types.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| ENROLL_FILE      | 0    | Registration file.  |
| WAKEUP_FILE      | 1    | Wakeup file.  |

## UploadFile<sup>12+</sup>

Defines an upload file, including the file type, file description, and content.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| type | [UploadFileType](#uploadfiletype12) |        Yes      | File type.|
| filesDescription | string |        Yes      | File description.|
| filesContent | Array\<ArrayBuffer\> |        Yes      | File content.|

## WakeupSourceFile<sup>12+</sup>

Defines a wakeup resource file.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| filePath | string |        Yes      | File path.|
| fileContent | ArrayBuffer |        Yes      | File content.|

## EvaluationResultCode<sup>12+</sup>

Enumerates result codes for custom wakeup keywords.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| UNKNOWN      | 0    | Unknown error.  |
| PASS      | 1    | Passed.  |
| WORD_EMPTY      | 2    | Empty word.  |
| CHINESE_ONLY      | 3    | Chinese only.  |
| INVALID_LENGTH      | 4    | Invalid length.  |
| UNUSUAL_WORD      | 5    | Unusual word. |
| CONSECUTIVE_SAME_WORD      | 6    | Consecutive same words.  |
| TOO_FEW_PHONEMES      | 7    | Too few phonemes.  |
| TOO_MANY_PHONEMES      | 8    | Too many phonemes.  |
| COMMON_INSTRUCTION      | 9    | Common instructions included.  |
| COMMON_SPOKEN_LANGUAGE      | 10    | Common spoken language included. |
| SENSITIVE_WORD      | 11    | Sensitive words included.  |
| NO_INITIAL_CONSONANT      | 12    | Two consecutive words without initial consonants.  |
| REPEATED_PHONEME      | 13    | Duplicate phonemes included.  |

## EvaluationResult<sup>12+</sup>

Defines the wakeup word evaluation result.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| score | number |        Yes      | Evaluation score of a custom wakeup keyword. The value ranges from 0 to 5.|
| resultCode | [EvaluationResultCode](#evaluationresultcode12) |        Yes      | Evaluation result code.|

## ServiceChangeType

Enumerates service status change types.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| SERVICE_UNAVAILABLE      | 0    | The service is unavailable.  |

## IntelligentVoiceEngineType

Enumerates intelligent voice engine types.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| ENROLL_ENGINE_TYPE      | 0    | Voice enrollment engine.  |
| WAKEUP_ENGINE_TYPE      | 1    | Voice wakeup engine.  |
| UPDATE_ENGINE_TYPE      | 2    | Silent update engine.  |

## EnrollIntelligentVoiceEngineDescriptor

Defines the descriptor of an intelligent voice enrollment engine.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| wakeupPhrase | string |        Yes      | Wakeup phrase.|

## WakeupIntelligentVoiceEngineDescriptor

Defines the descriptor of an intelligent voice wakeup engine.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| needReconfirm | boolean |        Yes      | Whether re-confirmation of the wakeup result is needed. The value **true** indicates that re-confirmation is needed, and the value **false** indicates the opposite.|
| wakeupPhrase | string |        Yes      | Wakeup phrase.|

## EnrollEngineConfig

Defines the enrollment engine configuration.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| language | string |        Yes      | Language supported by the enrollment engine. Only Chinese is supported currently, and the value is **zh**.|
| region | string |        Yes      | Country/region supported by the enrollment engine. Only China is supported currently, and the value is **CN**.|

## SensibilityType

Enumerates wakeup sensibility types.
A sensibility type maps to a wakeup threshold. A higher sensibility indicates a lower threshold and a higher wakeup probability.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| LOW_SENSIBILITY      | 1    | Low sensibility.  |
| MIDDLE_SENSIBILITY      | 2    | Medium sensibility.  |
| HIGH_SENSIBILITY      | 3    | High sensibility.  |

## WakeupHapInfo

Defines the HAP information for an wakeup application.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| bundleName | string |        Yes      | Bundle name of the wakeup application.|
| abilityName | string |        Yes      | Ability name of the wakeup application.|

## WakeupIntelligentVoiceEventType

Enumerates types of intelligent voice wakeup events.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_EVENT_WAKEUP_NONE      | 0    | No wakeup.  |
| INTELLIGENT_VOICE_EVENT_RECOGNIZE_COMPLETE      | 1    | Wakeup recognition completed.  |
| INTELLIGENT_VOICE_EVENT_HEADSET_RECOGNIZE_COMPLETE      | 2    | Headset wakeup recognition completed.  |

## IntelligentVoiceErrorCode

Enumerates error codes of intelligent voice wakeup.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_NO_MEMORY      | 22700101    | Insufficient memory.  |
| INTELLIGENT_VOICE_INVALID_PARAM      | 22700102    | Invalid parameter. |
| INTELLIGENT_VOICE_INIT_FAILED      | 22700103    | Enrollment failed.  |
| INTELLIGENT_VOICE_COMMIT_ENROLL_FAILED      | 22700104    | Enrollment commit failed.  |
| INTELLIGENT_VOICE_START_CAPTURER_FAILED<sup>12+</sup>      | 22700105    | Failed to start reading streams. |
| INTELLIGENT_VOICE_READ_FAILED<sup>12+</sup>      | 22700106    | Failed to read streams.  |
| INTELLIGENT_VOICE_SYSTEM_ERROR<sup>12+</sup>      | 22700107    | System error.  |

## CapturerChannel<sup>12+</sup>

Enumerates capturer channels.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CAPTURER_CHANNEL_1      | 0x1 << 0    | Audio channel 1.  |
| CAPTURER_CHANNEL_2      | 0x1 << 1    | Audio channel 2.  |
| CAPTURER_CHANNEL_3     | 0x1 << 2    | Audio channel 3.  |
| CAPTURER_CHANNEL_4      | 0x1 << 3    | Audio channel 4.  |

## EnrollResult

Enumerates enrollment results.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| SUCCESS      | 0    | Enrollment succeeded.  |
| VPR_TRAIN_FAILED      | -1    | Voiceprint training failed. |
| WAKEUP_PHRASE_NOT_MATCH      | -2    | Wakeup phrase mismatched.  |
| TOO_NOISY      | -3    | Environment too noisy.  |
| TOO_LOUD      | -4    | Voice too loud.  |
| INTERVAL_LARGE      | -5    | Interval between wakeup phrases too long.  |
| DIFFERENT_PERSON      | -6    | Wakeup phrases enrolled by different persons.  |
| UNKNOWN_ERROR      | -100    | Unknown error.  |

## EnrollCallbackInfo

Defines the enrollment callback information.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| result | [EnrollResult](#enrollresult) |        Yes      | Enrollment result.|
| context | string |        Yes      | Context of the enrollment event.|

## WakeupIntelligentVoiceEngineCallbackInfo

Defines the callback information for the intelligent voice wakeup engine.

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| eventId | [WakeupIntelligentVoiceEventType](#wakeupintelligentvoiceeventtype) |        Yes      | Event type of the intelligent voice wakeup engine.|
| isSuccess | boolean |        Yes      | Wakeup result. The value **true** indicates that the wakeup is successful, and the value **false** indicates the opposite.|
| context | string |        Yes      | Context of the wakeup event.|

## EnrollIntelligentVoiceEngine

Class that implements the intelligent voice enrollment engine. Before use, you need to call [createEnrollIntelligentVoiceEngine()](#intelligentvoicecreateenrollintelligentvoiceengine) to obtain an instance of the intelligent voice enrollment engine.

### getSupportedRegions

getSupportedRegions(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the list of supported countries/regions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;Array&lt;string&gt;&gt;         | Yes  | Callback used to return the result, which is an array of supported countries/regions. Only China is supported currently, and the value is **CN**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let regions: Array<string> | null = null;
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getSupportedRegions((err: BusinessError, data: Array<string>) => {
    if (err) {
      console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);
    } else {
      regions = data;
      console.info(`Succeeded in getting supported regions, regions:${regions}.`);
    }
  });
}
```

### getSupportedRegions

getSupportedRegions(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of supported countries/regions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;string&gt;&gt;            | Promise used to return the result, which is an array of supported countries/regions. Only China is supported currently, and the value is **CN**.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let regions: Array<string> | null = null;
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getSupportedRegions().then((data: Array<string>) => {
    regions = data;
    console.info('Succeeded in getting supported regions, regions:${regions}.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);
  });
}
```

### init

init(config: EnrollEngineConfig, callback: AsyncCallback&lt;void&gt;): void

Initializes the intelligent voice enrollment engine. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| config     | [EnrollEngineConfig](#enrollengineconfig)                           | Yes  | Configuration of the intelligent voice enrollment engine.|
| callback     |AsyncCallback&lt;void&gt;                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700103 | Init failed.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let config: intelligentVoice.EnrollEngineConfig = {
  language: 'zh',
  region: 'CN',
}
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).init(config, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to initialize enrollIntelligentVoice engine. Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in initialzing enrollIntelligentVoice engine.`);
    }
  });
}
```

### init

init(config: EnrollEngineConfig): Promise&lt;void&gt;

Initializes the intelligent voice enrollment engine. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| config     | [EnrollEngineConfig](#enrollengineconfig)                           | Yes  | Configuration of the intelligent voice enrollment engine.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;           | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700103 | Init failed.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let config: intelligentVoice.EnrollEngineConfig = {
  language: 'zh',
  region: 'CN',
}
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).init(config).then(() => {
    console.info(`Succeeded in initializing enrollIntelligentVoice engine.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to initialize enrollIntelligentVoice engine. Code:${err.code}, message:${err.message}`);
  });
}

```

### enrollForResult

enrollForResult(isLast: boolean, callback: AsyncCallback&lt;EnrollCallbackInfo&gt;): void

Obtains the enrollment result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| isLast     | boolean                           | Yes  | Whether this is the last enrollment. The value **true** indicates the last enrollment, and the value **false** indicates the opposite.|
| callback     | AsyncCallback&lt;[EnrollCallbackInfo](#enrollcallbackinfo)&gt;                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callbackInfo: intelligentVoice.EnrollCallbackInfo | null = null;
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).enrollForResult(true, (err: BusinessError, data: intelligentVoice.EnrollCallbackInfo) => {
    if (err) {
      console.error(`Failed to enroll for result, Code:${err.code}, message:${err.message}`);
    } else {
      callbackInfo = data;
      console.info(`Succeeded in enrolling for result, info:${callbackInfo}.`);
    }
  });
}
```

### enrollForResult

enrollForResult(isLast: boolean): Promise&lt;EnrollCallbackInfo&gt;

Obtains the enrollment result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| isLast     | boolean                           | Yes  | Whether this is the last enrollment. The value **true** indicates the last enrollment, and the value **false** indicates the opposite.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollCallbackInfo](#enrollcallbackinfo)&gt;            | Promise used to return the result.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callbackInfo: intelligentVoice.EnrollCallbackInfo | null = null;
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).enrollForResult(true).then((data: intelligentVoice.EnrollCallbackInfo) => {
    callbackInfo = data;
    console.info(`Succeeded in enrolling for result, info:${callbackInfo}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to enroll for result, Code:${err.code}, message:${err.message}`);
  });
}
```

### stop

stop(callback: AsyncCallback&lt;void&gt;): void

Stops the enrollment. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     |  AsyncCallback&lt;void&gt;                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in stopping enrollIntelligentVoice engine.`);
    }
  });
}
```

### stop

stop(): Promise&lt;void&gt;

Stops the enrollment. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).stop().then(() => {
    console.info(`Succeeded in stopping enrollIntelligentVoice engine.`);
  }).catch((err:BusinessError) => {
    console.error(`Failed to stop enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
  });
}
```

### commit

commit(callback: AsyncCallback&lt;void&gt;): void

Commits the enrollment. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;void&gt;                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700104 | Failed to commit the enrollment.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).commit((err: BusinessError) => {
    if (err) {
      console.error(`Failed to commit enroll, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in committing enroll.`);
    }
  });
}
```

### commit

commit(): Promise&lt;void&gt;

Commits the enrollment. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;           | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700104 | Failed to commit the enrollment.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).commit().then(() => {
    console.info(`Succeeded in committing enroll.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to commit enroll, Code:${err.code}, message:${err.message}`);
  });
}
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void

Sets the HAP information for the wakeup application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | Yes  | HAP information for the wakeup application.|
| callback     | AsyncCallback\<void\>                          | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let info: intelligentVoice.WakeupHapInfo = {
  bundleName: 'com.wakeup',
  abilityName: 'WakeUpExtAbility',
}
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setWakeupHapInfo(info, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in setting wakeup hap info.`);
    }
  });
}
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo): Promise\<void\>

Sets the HAP information for the wakeup application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let info: intelligentVoice.WakeupHapInfo = {
  bundleName: 'com.wakeup',
  abilityName: 'WakeUpExtAbility',
}
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setWakeupHapInfo(info).then(() => {
    console.info(`Succeeded in setting wakeup hap info.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);
  });
}
```

### setSensibility

setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void\>): void

Sets the wakeup sensibility. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | Yes  | Sensibility type.|
| callback     | AsyncCallback\<void\>                         | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in setting sensibility.`);
    }
  });
}
```

### setSensibility

setSensibility(sensibility: SensibilityType): Promise\<void\>

Sets the wakeup sensibility. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | Yes  | Sensibility type.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY).then(() => {
    console.info(`Succeeded in setting sensibility.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);
  });
}
```

### setParameter

setParameter(key: string, value: string, callback: AsyncCallback\<void\>): void

Sets specified intelligent voice parameters. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|
| value     | string                           | Yes  | Value.|
| callback     | AsyncCallback\<void\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setParameter('scene', '0', (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in setting parameter`);
    }
  });
}
```

### setParameter

setParameter(key: string, value: string): Promise\<void\>

Sets specified intelligent voice parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|
| value     | string                           | Yes  | Value.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setParameter('scene', '0').then(() => {
    console.info(`Succeeded in setting parameter`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);
  });
}
```

### getParameter

getParameter(key: string, callback: AsyncCallback\<string\>): void

Obtains specified intelligent voice parameters. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|
| callback     | AsyncCallback\<string\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getParameter('key', (err: BusinessError, data: string) => {
    if (err) {
      console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);
    } else {
      let param: string = data;
      console.info(`Succeeded in getting parameter, param:${param}`);
    }
  });
}
```

### getParameter

getParameter(key: string): Promise\<string\>

Obtains specified intelligent voice parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string\>            | Promise used to return the result.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getParameter('key').then((data: string) => {
    let param: string = data;
    console.info(`Succeeded in getting parameter, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);
  });
}
```

### evaluateForResult<sup>12+</sup>

evaluateForResult(word: string): Promise\<EvaluationResult\>

Evaluates whether a custom wakeup keyword is effective. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| word     | string                           | Yes  | Custom wakeup keyword.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EvaluationResult](#evaluationresult12)&gt;     | Promise used to return the result.     |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700107 | System error.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).evaluateForResult('word').then(
    (data: intelligentVoice.EvaluationResult) => {
    let param: intelligentVoice.EvaluationResult = data;
    console.info(`Succeeded in evaluating, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to evaluate, Code:${err.code}, message:${err.message}`);
  });
}
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

Releases the intelligent voice enrollment engine. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback\<void\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in releasing enrollIntelligentVoice engine.`);
    }
  });
}
```

### release

release(): Promise&lt;void&gt;

Releases the intelligent voice enrollment engine. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).release().then(() => {
    console.info(`Succeeded in releasing enrollIntelligentVoice engine.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to release enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
  });
}
```

## WakeupIntelligentVoiceEngine

Class that implements the intelligent voice wakeup engine. Before use, you need to call [createWakeupIntelligentVoiceEngine()](#intelligentvoicecreatewakeupintelligentvoiceengine) to obtain an instance of the intelligent voice wakeup engine.

### getSupportedRegions

getSupportedRegions(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the list of supported countries/regions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;Array&lt;string&gt;&gt;                           | Yes  | Callback used to return the result, which is an array of supported countries/regions. Only China is supported currently, and the value is **CN**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getSupportedRegions((err: BusinessError, data: Array<string>) => {
    if (err) {
      console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);
    } else {
      let regions: Array<string> = data;
      console.info(`Succeeded in getting supported regions, regions:${regions}.`);
    }
  });
}
```

### getSupportedRegions

getSupportedRegions(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of supported countries/regions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;string&gt;&gt;            | Promise used to return the result, which is an array of supported countries/regions. Only China is supported currently, and the value is **CN**.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getSupportedRegions().then((data: Array<string>) => {
    let regions: Array<string> = data;
    console.info(`Succeeded in getting supported regions, regions:${regions}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);
  });
}
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void\>): void

Sets the HAP information for the wakeup application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | Yes  | HAP information for the wakeup application.|
| callback     | AsyncCallback\<void\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hapInfo: intelligentVoice.WakeupHapInfo = {
  bundleName: 'com.wakeup',
  abilityName: 'WakeUpExtAbility',
}

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setWakeupHapInfo(hapInfo, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in setting wakeup hap info.`);
    }
  });
}
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo): Promise\<void\>

Sets the HAP information for the wakeup application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | Yes  | HAP information for the wakeup application.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let hapInfo: intelligentVoice.WakeupHapInfo = {
  bundleName: 'com.wakeup',
  abilityName: 'WakeUpExtAbility',
}
if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setWakeupHapInfo(hapInfo).then(() => {
    console.info(`Succeeded in setting wakeup hap info.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);
  });
}
```

### setSensibility

setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void\>): void

Sets the wakeup sensibility. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | Yes  | Sensibility type.|
| callback     | AsyncCallback\<void\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in setting sensibility.`);
    }
  });
}
```

### setSensibility

setSensibility(sensibility: SensibilityType): Promise\<void\>

Sets the wakeup sensibility. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | Yes  | Sensibility type.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY).then(() => {
    console.info(`Succeeded in setting sensibility.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);
  });
}
```

### setParameter

setParameter(key: string, value: string, callback: AsyncCallback\<void\>): void

Sets specified intelligent voice parameters. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|
| value     | string                           | Yes  | Value.|
| callback     | AsyncCallback\<void\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setParameter('scene', '0', (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in setting parameter`);
    }
  });
}
```

### setParameter

setParameter(key: string, value: string): Promise\<void\>

Sets specified intelligent voice parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|
| value     | string                           | Yes  | Value.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setParameter('scene', '0').then(() => {
    console.info(`Succeeded in setting parameter`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);
  });
}
```

### getParameter

getParameter(key: string, callback: AsyncCallback\<string\>): void

Obtains specified intelligent voice parameters. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|
| callback     | AsyncCallback\<string\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getParameter('key', (err: BusinessError, data: string) => {
    if (err) {
      console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);
    } else {
      let param: string = data;
      console.info(`Succeeded in getting parameter, param:${param}`);
    }
  });
}
```

### getParameter

getParameter(key: string): Promise\<string\>

Obtains specified intelligent voice parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | Yes  | Key.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string\>            | Promise used to return the result.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getParameter('key').then((data: string) => {
    let param: string = data;
    console.info(`Succeeded in getting parameter, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);
  });
}
```

### getPcm<sup>12+</sup>

getPcm(): Promise\<ArrayBuffer\>

Obtains the Pulse Code Modulation (PCM) of audio signals. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<ArrayBuffer\>            | Promise used to return the result.                  |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                          |
| 22700107 | System error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getPcm().then((data: ArrayBuffer) => {
    let param: ArrayBuffer = data;
    console.info(`Succeeded in getting pcm, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get pcm, Code:${err.code}, message:${err.message}`);
  });
}
```

### startCapturer<sup>12+</sup>

startCapturer(channels: number): Promise\<void\>

Starts the capturer. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| channels     | number                           | Yes  | Number of audio channels.|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<void\>            | Promise that returns no value.                 |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                         |
| 22700105 | Start capturer failed.                          |
| 22700107 | System error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).startCapturer(1).then(() => {
    console.info(`Succeeded in starting capturer`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to start capturer, Code:${err.code}, message:${err.message}`);
  });
}
```

### read<sup>12+</sup>

read(): Promise\<ArrayBuffer\>

Reads audio data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<ArrayBuffer\>            | Promise used to return the result.                 |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                          |
| 22700106 | Read failed.                        |
| 22700107 | System error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).read().then((data: ArrayBuffer) => {
    let param: ArrayBuffer = data;
    console.info(`Succeeded in reading data, param:${param}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read data, Code:${err.code}, message:${err.message}`);
  });
}
```

### stopCapturer<sup>12+</sup>

stopCapturer(): Promise\<void\>

Stops the capturer. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<void\>            | Promise that returns no value.                    |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Intelligent Voice Error Codes](errorcode-intelligentVoice.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700107 | System error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).stopCapturer().then(() => {
    console.info(`Succeeded in stopping capturer`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop capturer, Code:${err.code}, message:${err.message}`);
  });
}
```

### release

release(callback: AsyncCallback\<void\>): void

Releases the intelligent voice wakeup engine. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback\<void\>                           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
    } else {
      console.info(`Succeeded in releasing wakeupIntelligentVoice engine.`);
    }
  });
}
```

### release

release(): Promise\<void\>

Releases the intelligent voice wakeup engine. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise that returns no value.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).release().then(() => {
    console.info(`Succeeded in releasing wakeupIntelligentVoice engine.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to release wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);
  });
}
```

### on

on(type: 'wakeupIntelligentVoiceEvent', callback: Callback\<WakeupIntelligentVoiceEngineCallbackInfo\>): void

Subscribes to wakeup events.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string          | Yes  | Event type. This field has a fixed value of **wakeupIntelligentVoiceEvent**.|
| callback     | Callback\<[WakeupIntelligentVoiceEngineCallbackInfo](#wakeupintelligentvoiceenginecallbackinfo)\>                           | Yes  | Callback for processing of the wakeup event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).on('wakeupIntelligentVoiceEvent',
    (info: intelligentVoice.WakeupIntelligentVoiceEngineCallbackInfo) => {
    let callbackInfo: intelligentVoice.WakeupIntelligentVoiceEngineCallbackInfo = info;
    console.info(`wakeup intelligentvoice event, info:${callbackInfo}`);
  });
}
```

### off

off(type: 'wakeupIntelligentVoiceEvent', callback?: Callback\<WakeupIntelligentVoiceEngineCallbackInfo\>): void;

Unsubscribes from wakeup events.

**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE

**System capability**: SystemCapability.AI.IntelligentVoice.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     |string           | Yes  | Event type. This field has a fixed value of **wakeupIntelligentVoiceEvent**.|
| callback     | Callback\<[WakeupIntelligentVoiceEngineCallbackInfo](#wakeupintelligentvoiceenginecallbackinfo)\>                           | No  | Callback for processing of the wakeup event. If this parameter is specified, only the specified callback will be unsubscribed. Otherwise, all callbacks will be unsubscribed. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**Example**

```ts
if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).off('wakeupIntelligentVoiceEvent');
}
```
