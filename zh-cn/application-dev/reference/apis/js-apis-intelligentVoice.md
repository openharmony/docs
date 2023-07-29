# @ohos.ai.intelligentVoice (智能语音)

智能语音组件包括智能语音服务框架和智能语音驱动，主要提供了语音注册及语音唤醒相关功能。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块
```js
import intelligentVoice from '@ohos.ai.intelligentVoice';
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

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700101 | No memory.                              |

**示例：** 

```js
var intelligentvoiceManager = intelligentVoice.getIntelligentVoiceManager();
if (intelligentvoiceManager == null) {
    console.error("Get IntelligentVoiceManager failed.");
} else {
    console.info("Get IntelligentVoiceManager success.");
    return;
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
| descriptor    | [EnrollIntelligentVoiceEngineDescriptor](#enrollintelligentvoiceenginedescriptor)                              | 是   | 表示智能语音注册引擎描述符。   |
| callback    | AsyncCallback\<[EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)\>         | 是   | 智能语音注册引擎结果回调。   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700101 | No memory.                           |
| 22700102 | if input parameter value error.                            |

**示例：** 

```js
let engineDescriptor = {
    wakeupPhrase: '',
}
intelligentVoice.createEnrollIntelligentVoiceEngine(engineDescriptor,(err, data) => {
  if (err) {
    console.error(`EnrollIntelligentVoice Created: Error: ${err}`);
  } else {
    console.info('EnrollIntelligentVoice Created: Success: SUCCESS');
    let engine = data;
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
| descriptor    | [EnrollIntelligentVoiceEngineDescriptor](#enrollintelligentvoiceenginedescriptor)                              | 是   | 表示智能语音注册引擎描述符。   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Promise\<[EnrollIntelligentVoiceEngine](#enrollintelligentvoiceengine)\>           | 智能语音注册引擎。                   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700101 | No memory.                           |
| 22700102 | if input parameter value error.                            |

**示例：** 

```js
var engine = null;
let engineDescriptor = {
    wakeupPhrase: '',
}
intelligentVoice.createEnrollIntelligentVoiceEngine(engineDescriptor).then((data) => {
    engine = data;
    console.info('Create EnrollIntelligentVoice Engine finish');
}).catch((err) => {
    console.error('Create EnrollIntelligentVoice Engine failed, err: ' + err.message);
});
if (engine == null) {
    console.error('Create EnrollIntelligentVoice Engine failed');
    return;
}
```

## intelligentVoice.createWakeupIntelligentVoiceEngine

createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor, callback: AsyncCallback&lt;WakeupIntelligentVoiceEngine&gt;): void


创建智能语音唤醒引擎实例，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| descriptor    | [WakeupIntelligentVoiceEngineDescriptor](#wakeupintelligentvoiceenginedescriptor)                              | 是   | 表示智能语音唤醒引擎描述符。   |
| callback    | AsyncCallback\<[WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)\>         | 是   | 智能语音唤醒引擎结果回调。   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700101 | No memory.                           |
| 22700102 | if input parameter value error.                            |

**示例：** 

```js
let engineDescriptor = {
    needApAlgEngine: true,
    wakeupPhrase: '',
}
intelligentVoice.createWakeupIntelligentVoiceEngine(engineDescriptor,(err, data) => {
  if (err) {
    console.error(`WakeupIntelligentVoice Created: Error: ${err}`);
  } else {
    console.info('WakeupIntelligentVoice Created: Success: SUCCESS');
    let engine = data;
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
| descriptor    | [WakeupIntelligentVoiceEngineDescriptor](#wakeupintelligentvoiceenginedescriptor)                              | 是   | 表示智能语音唤醒引擎描述符。   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Promise\<[WakeupIntelligentVoiceEngine](#wakeupintelligentvoiceengine)>           | 智能语音唤醒引擎。                   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700101 | No memory.                           |
| 22700102 | if input parameter value error.                            |

**示例：** 

```js
var engine = null;
let engineDescriptor = {
    needApAlgEngine: true,
    wakeupPhrase: '',
}
intelligentVoice.createWakeupIntelligentVoiceEngine(engineDescriptor).then((data) => {
    engine = data;
    console.info('Create WakeupIntelligentVoice Engine finish');
}).catch((err) => {
    console.error('Create WakeupIntelligentVoice Engine failed, err: ' + err.message);
});
if (engine == null) {
    console.error('Create WakeupIntelligentVoice Engine failed');
    return;
}
```

## IntelligentVoiceManager

智能语音管理器类，使用前需要通过getIntelligentVoiceManager获取智能语音管理实例。

### getCapabilityInfo

getCapabilityInfo(): Array&lt;IntelligentVoiceEngineType&gt;

获取能力信息。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[IntelligentVoiceEngineType](#intelligentvoiceenginetype)\>            | 支持的智能语音引擎类型数组。              |

**示例：**

```js
let info = intelligentvoiceManager.getCapabilityInfo();
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
| callback | Callback\<[ServiceChangeType](#servicechangetype)\> | 是   | 事件触发时调用回调。|

**示例：**

```js
intelligentvoiceManager.on('serviceChange', (serviceChangeType) => {});
```

### off('serviceChange')

off(type: 'serviceChange'): void

取消订阅服务变更事件。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 系统服务变更事件，固定取值为'serviceChange'。 |

**示例：**

```js
intelligentvoiceManager.off('serviceChange');
```

## ServiceChangeType

枚举,服务变更类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| SERVICE_UNAVAILABLE      | 0    | 服务不可用。   |

## IntelligentVoiceEngineType

枚举,智能语音引擎类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| ENROLL_ENGINE_TYPE      | 0    | 注册引擎。   |
| WAKEUP_ENGINE_TYPE      | 1    | 唤醒引擎。   |
| UPDATE_ENGINE_TYPE      | 2    | 更新引擎。   |

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
| needApAlgEngine | boolean |        是       | 需要ap算法引擎。 |
| wakeupPhrase | string |        是       | 唤醒词。 |

## EnrollEngineConfig

描述注册引擎配置。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| language | string |        是       | 注册引擎支持的语言。 |
| region | string |        是       | 注册引擎支持的区域。 |

## SensibilityType

枚举，敏感类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| LOW_SENSIBILITY      | 1    | 低灵敏度   |
| MIDDLE_SENSIBILITY      | 2    | 中灵敏度   |
| HIGH_SENSIBILITY      | 3    | 高灵敏度   |

## WakeupHapInfo

描述唤醒hap信息。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| bundleName | string |        是       | 唤醒应用bundlename。 |
| abilityName | string |        是       | 唤醒应用ailityname。 |

## EnrollIntelligentVoiceEventType

枚举，注册智能语音事件类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_EVENT_ENROLL_NONE      | 0    | 无注册。   |
| INTELLIGENT_VOICE_EVENT_ENROLL_INIT_DONE      | 1    | 初始化完成。   |
| INTELLIGENT_VOICE_EVENT_ENROLL_COMPLETE      | 2    | 注册完成。   |
| INTELLIGENT_VOICE_EVENT_COMMIT_ENROLL_COMPLETE      | 3    | 提交注册完成。   |

## WakeupIntelligentVoiceEventType

枚举，唤醒智能语音事件类型。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_EVENT_WAKEUP_NONE      | 0    | 无唤醒。   |
| INTELLIGENT_VOICE_EVENT_RECOGNIZE_COMPLETE      | 1    | 识别完成。   |

## IntelligentVoiceErrorCode

枚举，智能语音错误码。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| INTELLIGENT_VOICE_SUCCESS      | 0    | 成功。   |
| INTELLIGENT_VOICE_NO_MEMORY      | 22700101    | 内存不足。   |
| INTELLIGENT_VOICE_INVALID_PARAM      | 22700102    | 参数无效。  |
| INTELLIGENT_VOICE_INIT_FAILED      | 22700103    | 初始化失败。   |
| INTELLIGENT_VOICE_ENROLL_FAILED      | 22700104    | 注册失败。   |
| INTELLIGENT_VOICE_COMMIT_ENROLL_FAILED      | 22700105    | 提交注册失败。   |
| INTELLIGENT_VOICE_RECOGNIZE_FAILED      | 22700106    | 识别失败。   |

## EnrollIntelligentVoiceEngineCallbackInfo

介绍注册智能语音引擎回调信息。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| eventId | [EnrollIntelligentVoiceEventType](#enrollintelligentvoiceeventtype) |        是       | 注册事件ID。 |
| errCode | [IntelligentVoiceErrorCode](#intelligentvoiceerrorcode) |        是       | 错误码。 |
| context | string |        是       | 描述注册事件上下文。 |

## WakeupIntelligentVoiceEngineCallbackInfo

描述唤醒智能语音引擎回调信息。

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| eventId | [WakeupIntelligentVoiceEventType](#wakeupintelligentvoiceeventtype) |        是       | 唤醒事件ID。 |
| errCode | [IntelligentVoiceErrorCode](#intelligentvoiceerrorcode) |        是       | 错误码。 |
| context | string |        是       | 描述注册事件上下文。 |

## EnrollIntelligentVoiceEngine

实现注册智能语音引擎。

### getSupportedRegions

getSupportedRegions(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取支持的区域，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;Array&lt;string&gt;&gt;         | 是   | 支持区域的回调结果。 |

**示例：**

```js
enrollIntelligentVoiceEngine.getSupportedRegions((err, data) => {
  if (err) {
    console.error(`Failed to getSupportedRegions, ${err}`);
  } else {
    console.info('getSupportedRegions success.');
    let regions = data;
  }
});
```

### getSupportedRegions

getSupportedRegions(): Promise&lt;Array&lt;string&gt;&gt;

获取支持的区域，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;Array&lt;string&gt;&gt;            | 返回支持区域。                   |

**示例：**

```js
let regions;
enrollIntelligentVoiceEngine.getSupportedRegions().then((data) => {
  regions = data;
  console.info('getSupportedRegions success');
}).catch((err) => {
  console.error(`Failed to getSupportedRegion: ERROR : ${err}`);
});
```

### init

init(config: EnrollEngineConfig, callback: AsyncCallback&lt;EnrollIntelligentVoiceEngineCallbackInfo&gt;): void

初始化引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| config     | [EnrollEngineConfig](#enrollengineconfig)                           | 是   | config表示注册引擎配置。 |
| callback     |AsyncCallback\<[EnrollIntelligentVoiceEngineCallbackInfo](#enrollintelligentvoiceenginecallbackinfo)\>                           | 是   | 初始化返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let config = {
    language: "zh",
    area: "CN",
}
enrollIntelligentVoiceEngine.init(config,(err, data) => {
  if (err) {
    console.error(`Init EnrollIntelligentVoice Engine finish, Error: ${err}`);
  } else {
    console.info('Init EnrollIntelligentVoice Engine SUCCESS');
    let callbackInfo = data;
  }
});
```

### init

init(config: EnrollEngineConfig): Promise&lt;EnrollIntelligentVoiceEngineCallbackInfo&gt;

初始化引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| config     | [EnrollEngineConfig](#enrollengineconfig)                           | 是   | config表示注册引擎配置。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollIntelligentVoiceEngineCallbackInfo](#enrollintelligentvoiceenginecallbackinfo)&gt;            | 初始化回调信息。                   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let config = {
    language: "zh",
    area: "CN",
}
let callbackInfo;
enrollIntelligentVoiceEngine.init(config).then((data) => {
    callbackInfo = data;
    console.info('Init EnrollIntelligentVoice Engine finish');
}).catch((err) => {
    console.info('Init EnrollIntelligentVoice Engine failed, err: '+ err.message);
});
```

### start

start(isLast: boolean, callback: AsyncCallback&lt;EnrollIntelligentVoiceEngineCallbackInfo&gt;): void

启动引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| isLast     | boolean                           | 是   | isLast表示是否为最后一次启动。 |
| callback     | AsyncCallback&lt;[EnrollIntelligentVoiceEngineCallbackInfo](#enrollintelligentvoiceenginecallbackinfo)&gt;                           | 是   | 启动结果返回。 |

**示例：**

```js
let isLast = true;
enrollIntelligentVoiceEngine.start(isLast,(err, data) => {
  if (err) {
    console.error(`Start enrollment failed, error: ${err}`);
  } else {
    console.info('Start enrollment finish');
    let callbackInfo = data;
  }
});
```

### start

start(isLast: boolean): Promise&lt;EnrollIntelligentVoiceEngineCallbackInfo&gt;

启动引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| isLast     | boolean                           | 是   | isLast表示是否为最后一次启动。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollIntelligentVoiceEngineCallbackInfo](#enrollintelligentvoiceenginecallbackinfo)&gt;            | 启动结果回调信息。                   |

**示例：**

```js
let isLast = true;
let callbackInfo;
enrollIntelligentVoiceEngine.start(isLast).then((data) => {
    callbackInfo = data;
    console.info('Start enrollment finish');
}).catch((err) => {
    console.info('Start enrollment failed, err: '+ err.message);
});
```

### stop

stop(callback: AsyncCallback&lt;void&gt;): void

停止引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     |  AsyncCallback&lt;void&gt;                           | 是   | 停止结果返回。 |

**示例：**

```js
enrollIntelligentVoiceEngine.stop((err) => {
  if (err) {
    console.error(`enrollIntelligentVoiceEngine stop: Error: ${err}`);
  } else {
    console.info('enrollIntelligentVoiceEngine stop Success');
  }
});
```

### stop

stop(): Promise&lt;void&gt;

停止引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**示例：**

```js
enrollIntelligentVoiceEngine.stop().then(() => {
  console.info('enrollIntelligentVoiceEngine stop');
});
```

### commit

commit(callback: AsyncCallback&lt;EnrollIntelligentVoiceEngineCallbackInfo&gt;): void

提交注册，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback&lt;[EnrollIntelligentVoiceEngineCallbackInfo](#enrollintelligentvoiceenginecallbackinfo)&gt;                           | 是   | 提交注册结果返回。 |

**示例：**

```js
enrollIntelligentVoiceEngine.commit((err, data) => {
  if (err) {
    console.error(`Commit enroll result failed, err: ${err}`);
  } else {
    console.info('Commit enroll result finish');
    let callbackInfo = data;
  }
});
```

### commit

commit(): Promise&lt;EnrollIntelligentVoiceEngineCallbackInfo&gt;

提交注册，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise&lt;[EnrollIntelligentVoiceEngineCallbackInfo](#enrollintelligentvoiceenginecallbackinfo)&gt;           | 提交注册回调信息。                   |

**示例：**

```js
let callbackInfo;
enrollIntelligentVoiceEngine.commit().then((data) => {
    callbackInfo = data;
    console.info('Commit enroll result finish');
}).catch((err) => {
    console.info('Commit enroll result failed, err: '+ err.message);
});
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void

设置唤醒hap信息，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |
| callback     | AsyncCallback\<void>                          | 是   | 返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let info = {
    bundleName: "demo",
    abilityName: "demo",
}
enrollIntelligentVoiceEngine.setWakeupHapInfo(info,(err) => {
  if (err) {
    console.error(`Set wakeup hap info failed, err: ${err}`);
  } else {
    console.info('Set wakeup hap info finish');
  }
});
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>

设置唤醒hap信息，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let info = {
    bundleName: "demo",
    abilityName: "demo",
}
enrollIntelligentVoiceEngine.setWakeupHapInfo(info).then(() => {
    console.info('Set wakeup hap info finish');
}).catch((err) => {
    console.info('Set wakeup hap info failed, err: '+ err.message);
});
```

### setSensibility

setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void

设置灵敏度，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |
| callback     | AsyncCallback\<void>                         | 是   | 返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
enrollIntelligentVoiceEngine.setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY,(err) => {
  if (err) {
    console.error(`setSensibility: Error: ${err}`);
  } else {
    console.info('setSensibility: Success: SUCCESS');
  }
});
```

### setSensibility

setSensibility(sensibility: SensibilityType): Promise\<void>

设置灵敏度，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
enrollIntelligentVoiceEngine.setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY).then(() => {
  console.info('setSensibility Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`setSensibility : ERROR : ${err}`);
});
```

### setParameter

setParameter(key: string, value: string, callback: AsyncCallback\<void>): void

设置参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |
| callback     | AsyncCallback\<void>                           | 是   | 返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
enrollIntelligentVoiceEngine.setParameter('scene', '0' ,(err) => {
  if (err) {
    console.error(`setParameter: Error: ${err}`);
  } else {
    console.info('setParameter: Success: SUCCESS');
  }
});
```

### setParameter

setParameter(key: string, value: string): Promise\<void>

设置参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
enrollIntelligentVoiceEngine.setSensibility('scene', '0').then(() => {
  console.info('setParameter Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`setParameter : ERROR : ${err}`);
});
```

### getParameter

getParameter(key: string, callback: AsyncCallback\<string>): void

获取参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| callback     | AsyncCallback\<string>                           | 是   | 返回的值。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
enrollIntelligentVoiceEngine.getParameter('key' ,(err,data) => {
  if (err) {
    console.error(`getParameter: Error: ${err}`);
  } else {
    console.info('getParameter: Success: SUCCESS');
    let param = data;
  }
});
```

### getParameter

getParameter(key: string): Promise\<string>

获取参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string>            | 返回的信息。                   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let param;
enrollIntelligentVoiceEngine.getParameter('key').then((data) => {
  param = data;
  console.info('getParameter: Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`getParameter: ERROR : ${err}`);
});
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

释放引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback\<void>                           | 是   | 返回的结果。 |

**示例：**

```js
enrollIntelligentVoiceEngine.release((err) => {
  if (err) {
    console.error(`Release EnrollIntelligentVoice engine failed, err: ${err}`);
  } else {
    console.info('Release EnrollIntelligentVoice engine success.');
  }
});
```

### release

release(): Promise&lt;void&gt;

通过Promise释放引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**示例：**

```js
enrollIntelligentVoiceEngine.release().then(() => {
    console.info('Release EnrollIntelligentVoice engine success.');
}).catch((err) => {
    console.info('Release EnrollIntelligentVoice engine failed, err: '+ err.message);
});
```

## WakeupIntelligentVoiceEngine

实现唤醒智能语音引擎。

### getSupportedRegions

getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void

获取支持的区域，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| callback     | AsyncCallback\<void>                           | 是   | 返回的结果。 |

**示例：**

```js
wkeupIntelligentVoiceEngine.getSupportedRegions((err, data) => {
  if (err) {
    console.error(`Failed to getSupportedRegions, ${err}`);
  } else {
    console.info('getSupportedRegions success.');
    let regions = data;
  }
});
```

### getSupportedRegions

getSupportedRegions(): Promise\<Array\<string>>

获取支持的区域，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Array\<string>            | 返回受支持区域。                   |

**示例：**

```js
let regions;
wkeupIntelligentVoiceEngine.getSupportedRegions().then((data) => {
  regions = data;
  console.info('getSupportedRegions success');
}).catch((err) => {
  console.error(`Failed to getSupportedRegion: ERROR : ${err}`);
});
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void

设置唤醒hap信息，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |
| callback     | AsyncCallback\<void>                           | 是   | 返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let info = {
    bundleName: "demo",
    abilityName: "demo",
}
wkeupIntelligentVoiceEngine.setWakeupHapInfo(info,(err) => {
  if (err) {
    console.error(`Set wakeup hap info failed, err: ${err}`);
  } else {
    console.info('Set wakeup hap info finish');
  }
});
```

### setWakeupHapInfo

setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>

设置唤醒hap信息，使用promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| info     | [WakeupHapInfo](#wakeuphapinfo)                           | 是   | 唤醒hap信息。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let info = {
    bundleName: "demo",
    abilityName: "demo",
}
wkeupIntelligentVoiceEngine.setWakeupHapInfo(info).then(() => {
    console.info('Set wakeup hap info finish');
}).catch((err) => {
    console.info('Set wakeup hap info failed, err: '+ err.message);
});
```

### setSensibility

setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void

设置灵敏度，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |
| callback     | AsyncCallback\<void>                           | 是   | 返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
wkeupIntelligentVoiceEngine.setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY,(err) => {
  if (err) {
    console.error(`setSensibility: Error: ${err}`);
  } else {
    console.info('setSensibility: Success: SUCCESS');
  }
});
```


### setSensibility

setSensibility(sensibility: SensibilityType): Promise\<void>

设置灵敏度，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| sensibility     | [SensibilityType](#sensibilitytype)                           | 是   | 灵敏度类型。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
wkeupIntelligentVoiceEngine.setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY).then(() => {
  console.info('setSensibility Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`setSensibility : ERROR : ${err}`);
});
```

### setParameter

setParameter(key: string, value: string, callback: AsyncCallback\<void>): void

设置参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |
| callback     | AsyncCallback\<void>                           | 是   | 返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
wkeupIntelligentVoiceEngine.setParameter('scene', '0' ,(err) => {
  if (err) {
    console.error(`setParameter: Error: ${err}`);
  } else {
    console.info('setParameter: Success: SUCCESS');
  }
});
```

### setParameter

setParameter(key: string, value: string): Promise\<void>

设置参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| value     | string                           | 是   | 值。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
wkeupIntelligentVoiceEngine.setSensibility('scene', '0').then(() => {
  console.info('setParameter Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`setParameter : ERROR : ${err}`);
});
```

### getParameter

getParameter(key: string, callback: AsyncCallback\<string>): void

获取参数，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |
| callback     | AsyncCallback\<string>                           | 是   | 返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
wkeupIntelligentVoiceEngine.getParameter('key' ,(err,data) => {
  if (err) {
    console.error(`getParameter: Error: ${err}`);
  } else {
    console.info('getParameter: Success: SUCCESS');
    let param = data;
  }
});
```

### getParameter

getParameter(key: string): Promise\<string>

获取参数，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| key     | string                           | 是   | 键。 |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Promise\<string>            | 返回的信息。                   |

**错误码：**

以下错误码的详细介绍请参见[智能语音错误码](../errorcodes/errorcode-intelligentVoice.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 22700102 | if input parameter value error.                            |

**示例：**

```js
let param;
wkeupIntelligentVoiceEngine.getParameter('key').then((data) => {
  param = data;
  console.info('getParameter: Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`getParameter: ERROR : ${err}`);
});
```

### release

release(callback: AsyncCallback\<void>): void

释放引擎，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**示例：**

```js
wkeupIntelligentVoiceEngine.release((err) => {
  if (err) {
    console.error(`Release EnrollIntelligentVoice engine failed, err: ${err}`);
  } else {
    console.info('Release EnrollIntelligentVoice engine success.');
  }
});
```

### release

release(): Promise\<void>

释放引擎，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**示例：**

```js
wkeupIntelligentVoiceEngine.release().then(() => {
    console.info('Release EnrollIntelligentVoice engine success.');
}).catch((err) => {
    console.info('Release EnrollIntelligentVoice engine failed, err: '+ err.message);
});
```

### on

on(type: 'wakeupIntelligentVoiceEvent', callback: Callback\<WakeupIntelligentVoiceEngineCallbackInfo\>): void

订阅唤醒智能语音事件。当唤醒智能语音事件到达时，调用回调。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 唤醒智能语音事件，固定取为'wakeupIntelligentVoiceEvent'，表示智能语音唤醒事件。 |
| callback     | Callback\<[WakeupIntelligentVoiceEngineCallbackInfo](#wakeupintelligentvoiceenginecallbackinfo)\>                           | 是   | 唤醒智能语音引擎回调信息。 |

**示例：**

```js
wkeupIntelligentVoiceEngine.on('wakeupIntelligentVoiceEvent', (callback) => {
    console.info(`${tag}: wakeup intelligentvoice event`);
    for (let prop in callback) {
        console.info(`${tag}: intelligentvoice prop: ${prop}`);
    }
});
```

### off

off(type: 'wakeupIntelligentVoiceEvent')

取消订阅唤醒智能语音事件。

**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE

**系统能力：** SystemCapability.AI.IntelligentVoice.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     |string                           | 是   | 唤醒智能语音事件，固定取为'wakeupIntelligentVoiceEvent'。 |

**示例：**

```js
wkeupIntelligentVoiceEngine.off('wakeupIntelligentVoiceEvent');
```
