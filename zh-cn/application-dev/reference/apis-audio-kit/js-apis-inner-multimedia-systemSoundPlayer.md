# SystemSoundPlayer (音效播放器)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

本模块提供系统音效播放能力，包括系统声音的加载、卸载和播放等，支持拍照、录制视频等系统音效的播放。当需要在应用中集成标准的系统提示音以提升用户体验一致性时，使用本模块接口完成相关操作。

SystemSoundPlayer需要和[@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager.md)配合使用，才能完成管理系统音效的功能。

> **说明：**
>
> 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { systemSoundManager } from '@kit.AudioKit';
```

## SystemSoundPlayer

系统音效播放器提供了拍照和录制视频音效的播放功能。在调用SystemSoundPlayer的接口前，需要先通过[createSystemSoundPlayer](js-apis-systemSoundManager.md#systemsoundmanagercreatesystemsoundplayer)创建系统音效播放器对象。

### load

load(soundType: systemSoundManager.SystemSoundType): Promise&lt;void&gt;

加载系统音效。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| soundType | [systemSoundManager.SystemSoundType](js-apis-systemSoundManager.md#systemsoundtype) | 是   | 要加载的系统音效类型。 |

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 5400103 | I/O error. |
| 5400105 | Crash or blocking occurs in system process. |
| 5400108 | Parameter check failed. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemSoundPlayer?.load(systemSoundManager.SystemSoundType.PHOTO_SHUTTER).then(() => {
  console.info('Succeeded in loading the system sound.');
}).catch((err: BusinessError) => {
  console.error(`Failed to load the system sound. Code: ${err.code}, message: ${err.message}`);
});
```

### play

play(soundType: systemSoundManager.SystemSoundType): Promise&lt;void&gt;

播放系统音效。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| soundType | [systemSoundManager.SystemSoundType](js-apis-systemSoundManager.md#systemsoundtype) | 是   | 要播放的系统音效类型。 |

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 5400103 | I/O error. |
| 5400105 | Crash or blocking occurs in system process. |
| 5400108 | Parameter check failed. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemSoundPlayer?.play(systemSoundManager.SystemSoundType.PHOTO_SHUTTER).then(() => {
  console.info('Succeeded in playing the system sound.');
}).catch((err: BusinessError) => {
  console.error(`Failed to play the system sound. Code: ${err.code}, message: ${err.message}`);
});
```

### unload

unload(soundType: systemSoundManager.SystemSoundType): Promise&lt;void&gt;

卸载之前已加载的系统音效。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| soundType | [systemSoundManager.SystemSoundType](js-apis-systemSoundManager.md#systemsoundtype) | 是   | 要卸载的系统音效类型。 |

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 5400105 | Crash or blocking occurs in system process. |
| 5400108 | Parameter check failed. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemSoundPlayer?.unload(systemSoundManager.SystemSoundType.PHOTO_SHUTTER).then(() => {
  console.info('Succeeded in unloading the system sound.');
}).catch((err: BusinessError) => {
  console.error(`Failed to unload the system sound. Code: ${err.code}, message: ${err.message}`);
});
```

### release

release(): Promise&lt;void&gt;

释放系统音效播放器。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 5400105 | Crash or blocking occurs in system process. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemSoundPlayer?.release().then(() => {
  console.info('Succeeded in releasing the system sound player.');
}).catch((err: BusinessError) => {
  console.error(`Failed to release the system sound player. Code: ${err.code}, message: ${err.message}`);
});
```