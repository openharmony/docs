# @ohos.ai.intelligentVoice (智能语音)(系统接口)

智能语音主要提供了语音注册及语音唤醒相关功能。<!--Del-->当前功能与芯片相关，在OpenHarmony暂不支持使用。<!--DelEnd-->

该模块提供以下智能语音相关的常用功能：

- [IntelligentVoiceManager](#intelligentvoicemanager)：智能语音管理类，明确当前智能语音提供的相关功能，当前支持语音注册、语音唤醒。在进行智能语音相关开发前，需先调用[getIntelligentVoiceManager()](#intelligentvoicegetintelligentvoicemanager)确认当前支持智能语音的相关功能，再进行语音注册和语音唤醒的相关开发。
- [EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)：实现语音注册。开发者需要先进行智能语音的注册，然后才能进行唤醒。
- [WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)：实现语音唤醒。开发者需要先进行智能语音的注册，然后才能进行唤醒。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。
>
> - @ohos.ai.intelligentVoice归属的Kit已由'MindSpore Lite Kit'变更为'Basic Services Kit'，请开发者使用新模块名'@kit.BasicServicesKit'完成模块导入。如果使用'@kit.MindSporeLiteKit'导入，将无法使用本模块的接口。

## 导入模块
```ts
import { intelligentVoice } from '@kit.BasicServicesKit';
```

## intelligentVoice.getIntelligentVoiceManager

getIntelligentVoiceManager(): IntelligentVoiceManager

获取智能语音管理类。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| [IntelligentVoiceManager](#intelligentvoicemanager) | 智能语音管理类。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                              |

**示例：** 

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

获取唤醒管理类。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| [WakeupManager](#wakeupmanager12) | 智能语音管理类。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                              |
| 22700107 | System error.                            |

**示例：**

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

创建智能语音注册引擎实例，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [EnrollIntelligentVoiceEngineDescriptor](#enrollintelligentvoiceenginedescriptor)                              | 是   | 智能语音注册引擎描述符。   |
| callback    | AsyncCallback\<[EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)\>         | 是   | 返回注册智能语音引擎。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**示例：** 

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let engineDescriptor: intelligentVoice.EnrollIntelligentVoiceEngineDescriptor = {
  wakeupPhrase: '小华小华',
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


创建智能语音注册引擎实例，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [EnrollIntelligentVoiceEngineDescriptor](#enrollintelligentvoiceenginedescriptor)                              | 是   | 智能语音注册引擎描述符。   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Promise\<[EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)\>           | 返回注册智能语音引擎。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**示例：** 

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let engineDescriptor: intelligentVoice.EnrollIntelligentVoiceEngineDescriptor = {
  wakeupPhrase: '小华小华',
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


创建智能语音唤醒引擎实例，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [WakeupIntelligentVoiceEngineDescriptor](#wakeupintelligentvoiceenginedescriptor)                              | 是   | 唤醒智能语音引擎描述符。   |
| callback    | AsyncCallback\<[WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)\>         | 是   | 返回唤醒智能语音引擎。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**示例：** 

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wakeupEngineDescriptor: intelligentVoice.WakeupIntelligentVoiceEngineDescriptor = {
  needReconfirm: true,
  wakeupPhrase: '小华小华',
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

创建智能语音唤醒引擎实例，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [WakeupIntelligentVoiceEngineDescriptor](#wakeupintelligentvoiceenginedescriptor)                              | 是   | 唤醒智能语音引擎描述符。   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Promise\<[WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)>           | 返回唤醒智能语音引擎。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                           |
| 22700102 | Invalid parameter.                            |

**示例：** 

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wakeupEngineDescriptor: intelligentVoice.WakeupIntelligentVoiceEngineDescriptor = {
  needReconfirm: true,
  wakeupPhrase: '小华小华',
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

智能语音管理类，使用前需要通过[getIntelligentVoiceManager()](#intelligentvoicegetintelligentvoicemanager)获取智能语音管理实例。

### getCapabilityInfo

getCapabilityInfo(): Array&lt;IntelligentVoiceEngineType&gt;

获取支持的智能语音引擎列表信息。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[IntelligentVoiceEngineType](#intelligentvoiceenginetype)\>            | 支持的智能语音引擎类型数组。              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

```ts
if (intelligentVoiceManager != null) {
  let info = intelligentVoiceManager.getCapabilityInfo();
}
```

### on('serviceChange')

on(type: 'serviceChange', callback: Callback&lt;ServiceChangeType&gt;): void

订阅服务变更事件。当智能语音业务状态发生变化时，调用回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 系统服务变更事件，固定取值为'serviceChange'，表示服务变更事件。 |
| callback | Callback\<[ServiceChangeType](#servicechangetype)\> | 是   | 服务状态变更对应的处理。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

```ts
if (intelligentVoiceManager != null) {
  intelligentVoiceManager.on('serviceChange', (serviceChangeType: intelligentVoice.ServiceChangeType) => {});
}
```

### off('serviceChange')

off(type: 'serviceChange', callback?: Callback\<ServiceChangeType\>): void

取消订阅服务变更事件。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 系统服务变更事件，固定取值为'serviceChange'。 |
| callback | Callback\<[ServiceChangeType](#servicechangetype)\> | 否   | 服务状态变更对应的处理，无参数，则取消所有订阅，否则，取消对应的处理。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

```ts
if (intelligentVoiceManager != null) {
  intelligentVoiceManager.off('serviceChange');
}
```

## WakeupManager<sup>12+</sup>

唤醒管理类，使用前需要通过[getWakeupManager()](#intelligentvoicegetwakeupmanager12)获取唤醒管理实例。

### setParameter<sup>12+</sup>

setParameter(key: string, value: string): Promise\<void\>

设置指定的唤醒参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键，对应的是唤醒词的设置，当前仅支持'wakeup_phrase'。 |
| value     | string                           | 是   | 值。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise对象，无返回结果。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700107 | System error.                            |

**示例：**

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

获取指定的智能语音参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键，只支持注册信息查询，当前仅支持'isEnrolled'。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string\>            | Promise对象，返回是否已经注册，'true'表示注册过，'false'表示未注册过。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700107 | System error.                            |

**示例：**

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

获取保存的唤醒词文件，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| maxCount     | number                           | 是   | 获取的文件数量。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;[UploadFile](#uploadfile12)&gt;&gt;   | Promise对象，返回获取的文件。      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                        |
| 22700102 | Invalid parameter.                            |
| 22700107 | System error.                            |

**示例：**

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

获取唤醒资源文件，如注册语料、路径信息等，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;[WakeupSourceFile](#wakeupsourcefile12)&gt;&gt;            | Promise对象，返回唤醒资源文件。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                        |
| 22700107 | System error.                            |

**示例：**

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

使用唤醒文件注册以获得结果，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| wakeupFiles     | Array\<[WakeupSourceFile](#wakeupsourcefile12)\>                           | 是   | 唤醒资源文件（注册语料、路径信息等）。 |
| wakeupInfo     | string                           | 是   | 唤醒相关信息（源侧设备类型、版本，目标侧设备类型、版本等）。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollResult](#enrollresult)&gt;    | Promise对象，返回注册结果。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700101 | No memory.                        |
| 22700102 | Invalid parameter.                        |
| 22700107 | System error.                            |

**示例：**

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

清楚用户数据，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | Promise对象，无返回结果。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700107 | System error.                            |

**示例：**

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

枚举，上传文件类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| ENROLL_FILE      | 0    | 注册文件。   |
| WAKEUP_FILE      | 1    | 唤醒文件。   |

## UploadFile<sup>12+</sup>

上传文件内容，包含文件类型，文件描述和内容。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| type | [UploadFileType](#uploadfiletype12) |        是       | 文件类型。 |
| filesDescription | string |        是       | 文件描述。 |
| filesContent | Array\<ArrayBuffer\> |        是       | 文件内容。 |

## WakeupSourceFile<sup>12+</sup>

唤醒资源文件。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| filePath | string |        是       | 文件路径。 |
| fileContent | ArrayBuffer |        是       | 文件内容。 |

## EvaluationResultCode<sup>12+</sup>

枚举，自定义唤醒词返回错误码类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| UNKNOWN      | 0    | 未知错误。   |
| PASS      | 1    | 通过。   |
| WORD_EMPTY      | 2    | 字是空的。   |
| CHINESE_ONLY      | 3    | 只支持中文。   |
| INVALID_LENGTH      | 4    | 无效的长度。   |
| UNUSUAL_WORD      | 5    | 不寻常的词。  |
| CONSECUTIVE_SAME_WORD      | 6    | 连续相同的字。   |
| TOO_FEW_PHONEMES      | 7    | 音素太少。   |
| TOO_MANY_PHONEMES      | 8    | 音素太多。   |
| COMMON_INSTRUCTION      | 9    | 包含常用指令。   |
| COMMON_SPOKEN_LANGUAGE      | 10    | 包含常用口语。  |
| SENSITIVE_WORD      | 11    | 包含敏感词。   |
| NO_INITIAL_CONSONANT      | 12    | 两个连续的词，没有首辅音。   |
| REPEATED_PHONEME      | 13    | 包含重复的音素。   |

## EvaluationResult<sup>12+</sup>

唤醒词评估结果。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| score | number |        是       | 自定义唤醒词的评估得分，范围在0到5之间。 |
| resultCode | [EvaluationResultCode](#evaluationresultcode12) |        是       | 评估结果错误码。 |

## ServiceChangeType

枚举，服务状态变更类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| SERVICE_UNAVAILABLE      | 0    | 服务状态不可用。   |

## IntelligentVoiceEngineType

枚举，智能语音引擎类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| ENROLL_ENGINE_TYPE      | 0    | 语音注册引擎。   |
| WAKEUP_ENGINE_TYPE      | 1    | 语音唤醒引擎。   |
| UPDATE_ENGINE_TYPE      | 2    | 静默升级引擎。   |

## EnrollIntelligentVoiceEngineDescriptor

注册智能语音引擎描述符。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| wakeupPhrase | string |        是       | 唤醒词。 |

## WakeupIntelligentVoiceEngineDescriptor

唤醒智能语音引擎描述符。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| needReconfirm | boolean |        是       | 是否需要再次确认唤醒结果，true为需要，false为不需要。 |
| wakeupPhrase | string |        是       | 唤醒词。 |

## EnrollEngineConfig

描述注册引擎配置。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| language | string |        是       | 注册引擎支持的语言，当前仅支持中文，取值为'zh'。 |
| region | string |        是       | 注册引擎支持的区域。当前仅支持中国，取值为'CN'。 |

## SensibilityType

枚举，唤醒灵敏度类型。
灵敏度用于调整唤醒的门限，灵敏度越高，门限越低，就越容易唤醒。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| LOW_SENSIBILITY      | 1    | 低灵敏度。   |
| MIDDLE_SENSIBILITY      | 2    | 中灵敏度。   |
| HIGH_SENSIBILITY      | 3    | 高灵敏度。   |

## WakeupHapInfo

描述唤醒应用的hap信息。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| bundleName | string |        是       | 唤醒应用的bundleName。 |
| abilityName | string |        是       | 唤醒应用的ailityName。 |

## WakeupIntelligentVoiceEventType

枚举，唤醒智能语音事件类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_EVENT_WAKEUP_NONE      | 0    | 无唤醒。   |
| INTELLIGENT_VOICE_EVENT_RECOGNIZE_COMPLETE      | 1    | 唤醒识别完成。   |
| INTELLIGENT_VOICE_EVENT_HEADSET_RECOGNIZE_COMPLETE<sup>12+</sup>     | 2    | 耳机唤醒识别完成。   |

## IntelligentVoiceErrorCode

枚举，智能语音错误码。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_NO_MEMORY      | 22700101    | 内存不足。   |
| INTELLIGENT_VOICE_INVALID_PARAM      | 22700102    | 参数无效。  |
| INTELLIGENT_VOICE_INIT_FAILED      | 22700103    | 注册失败。   |
| INTELLIGENT_VOICE_COMMIT_ENROLL_FAILED      | 22700104    | 确认注册结果失败。   |
| INTELLIGENT_VOICE_START_CAPTURER_FAILED<sup>12+</sup>      | 22700105    | 启动读流失败。  |
| INTELLIGENT_VOICE_READ_FAILED<sup>12+</sup>      | 22700106    | 读流失败。   |
| INTELLIGENT_VOICE_SYSTEM_ERROR<sup>12+</sup>      | 22700107    | 系统错误。   |

## CapturerChannel<sup>12+</sup>

枚举，枚举捕获器通道。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CAPTURER_CHANNEL_1      | 0x1 << 0    | 1声道。   |
| CAPTURER_CHANNEL_2      | 0x1 << 1    | 2声道。   |
| CAPTURER_CHANNEL_3     | 0x1 << 2    | 3声道。   |
| CAPTURER_CHANNEL_4      | 0x1 << 3    | 4声道。   |

## EnrollResult

枚举，注册结果。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| SUCCESS      | 0    | 注册成功。   |
| VPR_TRAIN_FAILED      | -1    | 声纹训练失败。  |
| WAKEUP_PHRASE_NOT_MATCH      | -2    | 唤醒短语不匹配。   |
| TOO_NOISY      | -3    | 周边环境太吵。   |
| TOO_LOUD      | -4    | 声音太大。   |
| INTERVAL_LARGE      | -5    | 唤醒词时间间隔太大。   |
| DIFFERENT_PERSON      | -6    | 不同人注册唤醒词。   |
| UNKNOWN_ERROR      | -100    | 未知错误。   |

## EnrollCallbackInfo

注册回调信息。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| result | [EnrollResult](#enrollresult) |        是       | 注册结果。 |
| context | string |        是       | 描述注册事件上下文。 |

## WakeupIntelligentVoiceEngineCallbackInfo

描述唤醒智能语音引擎回调信息。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| eventId | [WakeupIntelligentVoiceEventType](#wakeupintelligentvoiceeventtype) |        是       | 唤醒智能语音事件类型。 |
| isSuccess | boolean |        是       | 是否唤醒成功，false为唤醒失败，true为唤醒成功。 |
| context | string |        是       | 描述唤醒事件上下文。 |

## EnrollIntelligentVoiceEngine

实现注册智能语音引擎，通过[createEnrollIntelligentVoiceEngine()](#intelligentvoicecreateenrollintelligentvoiceengine)获取注册智能语音引擎。

### getSupportedRegions

getSupportedRegions(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取支持的区域，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;Array&lt;string&gt;&gt;         | 是   | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

获取支持的区域，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;string&gt;&gt;            | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let regions: Array<string> | null = null;
if (enrollIntelligentVoiceEngine != null) {
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getSupportedRegions().then((data: Array<string>) => {
    regions = data;
    console.info(`Succeeded in getting supported regions, regions:${regions}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);
  });
}
```

### init

init(config: EnrollEngineConfig, callback: AsyncCallback&lt;void&gt;): void

初始化注册智能语音引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| config     | [EnrollEngineConfig](#enrollengineconfig)                           | 是   | 注册引擎配置。 |
| callback     |AsyncCallback&lt;void&gt;                           | 是   | 返回初始化结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700103 | Init failed.                           |

**示例：**

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

初始化注册智能语音引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| config     | [EnrollEngineConfig](#enrollengineconfig)                           | 是   | config表示注册引擎配置。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;           | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |
| 22700103 | Init failed.                           |

**示例：**

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

获取注册结果，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| isLast     | boolean                           | 是   | isLast表示是否为最后一次注册，false为非最后一次，true为最后一次。 |
| callback     | AsyncCallback&lt;[EnrollCallbackInfo](#enrollcallbackinfo)&gt;                           | 是   | 返回注册结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|

**示例：**

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

获取注册结果，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| isLast     | boolean                           | 是   | isLast表示是否为最后一次注册，false为非最后一次，true为最后一次。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollCallbackInfo](#enrollcallbackinfo)&gt;            | 返回注册结果。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|

**示例：**

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

停止注册，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     |  AsyncCallback&lt;void&gt;                           | 是   | 返回停止结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

停止注册，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

提交注册，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;void&gt;                           | 是   | 返回确认注册结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700104 | Failed to commit the enrollment.                           |

**示例：**

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

提交注册，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;           | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700104 | Failed to commit the enrollment.                           |

**示例：**

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

设置唤醒应用的hap信息，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |
| callback     | AsyncCallback\<void\>                          | 是   | 返回设置唤醒hap信息的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置唤醒应用的hap信息，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置唤醒灵敏度，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |
| callback     | AsyncCallback\<void\>                         | 是   | 返回设置灵敏度的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置唤醒灵敏度，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置指定的智能语音参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |
| callback     | AsyncCallback\<void\>                           | 是   | 返回设置智能语音参数的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置指定的智能语音参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

获取指定的智能语音参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| callback     | AsyncCallback\<string\>                           | 是   | 返回智能语音参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

获取指定的智能语音参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string\>            | 返回智能语音参数。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

评估自定义唤醒词是否可用，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| word     | string                           | 是   | 自定义唤醒词。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EvaluationResult](#evaluationresult12)&gt;     | Promise对象，返回评估结果。      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700107 | System error.                            |

**示例：**

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

释放注册智能语音引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback\<void\>                           | 是   | 返回释放注册引擎的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

释放注册智能语音引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

实现唤醒智能语音引擎，通过[createWakeupIntelligentVoiceEngine()](#intelligentvoicecreatewakeupintelligentvoiceengine)获取唤醒智能语音引擎。

### getSupportedRegions

getSupportedRegions(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取支持的区域，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;Array&lt;string&gt;&gt;                           | 是   | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

获取支持的区域，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;string&gt;&gt;            | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

设置唤醒应用的hap信息，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |
| callback     | AsyncCallback\<void\>                           | 是   | 返回设置唤醒hap信息的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置唤醒应用的hap信息，使用promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置唤醒灵敏度，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |
| callback     | AsyncCallback\<void\>                           | 是   | 返回设置灵敏度的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置唤醒灵敏度，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置指定的智能语音参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |
| callback     | AsyncCallback\<void\>                           | 是   | 返回设置智能语音参数的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

设置指定的智能语音参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

获取指定的智能语音参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| callback     | AsyncCallback\<string\>                           | 是   | 返回智能语音参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

获取指定的智能语音参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string\>            | 返回智能语音参数。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                            |

**示例：**

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

获取脉冲编码调制音频，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<ArrayBuffer\>            | Promise对象，返回脉冲编码调制音频。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                          |
| 22700107 | System error.                          |

**示例：**

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

启动捕获器，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| channels     | number                           | 是   | 声道数。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<void\>            | Promise对象，无返回结果。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 22700102 | Invalid parameter.                         |
| 22700105 | Start capturer failed.                          |
| 22700107 | System error.                          |

**示例：**

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

读取数据，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<ArrayBuffer\>            | Promise对象，返回音频数据结果。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700101 | No memory.                          |
| 22700106 | Read failed.                        |
| 22700107 | System error.                          |

**示例：**

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

停止捕获器，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<void\>            | Promise对象，无返回结果。                     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智能语音错误码](errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |
| 22700107 | System error.                          |

**示例：**

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

释放唤醒智能语音引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback\<void\>                           | 是   | 返回释放唤醒引擎的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

释放唤醒智能语音引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;void&gt;            | 无返回结果的Promise对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

订阅唤醒事件。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string          | 是   | 唤醒智能语音事件，固定取为'wakeupIntelligentVoiceEvent'，表示智能语音唤醒事件。 |
| callback     | Callback\<[WakeupIntelligentVoiceEngineCallbackInfo](#wakeupintelligentvoiceenginecallbackinfo)\>                           | 是   | 收到唤醒事件的对应处理。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

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

取消订阅唤醒事件。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     |string           | 是   | 唤醒智能语音事件，固定取为'wakeupIntelligentVoiceEvent'。 |
| callback     | Callback\<[WakeupIntelligentVoiceEngineCallbackInfo](#wakeupintelligentvoiceenginecallbackinfo)\>                           | 否   | 收到唤醒事件的对应处理。无参数，则取消所有的订阅，否则，取消对应的订阅 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied.                              |
| 202 | Not system application.                             |

**示例：**

```ts
if (wakeupIntelligentVoiceEngine != null) {
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).off('wakeupIntelligentVoiceEvent');
}
```
