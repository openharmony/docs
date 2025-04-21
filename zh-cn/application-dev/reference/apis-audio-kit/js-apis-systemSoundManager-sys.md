# @ohos.multimedia.systemSoundManager (系统声音管理)(系统接口)

系统声音管理提供管理系统声音的一些基础能力，包括对系统铃声的资源设置与读取、获取系统铃声播放器等。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import { systemSoundManager } from '@kit.AudioKit';
```

## 常量

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                                      | 值   | 说明      |
|------------------------------------------|-----|---------|
| TONE_CATEGORY_RINGTONE<sup>12+</sup>     | 1   | 铃声类别。   |
| TONE_CATEGORY_TEXT_MESSAGE<sup>12+</sup> | 2   | 短信铃声类别。 |
| TONE_CATEGORY_NOTIFICATION<sup>12+</sup> | 4   | 通知铃声类别。 |
| TONE_CATEGORY_ALARM<sup>12+</sup>        | 8   | 闹钟铃声类别。 |

## RingtoneType

枚举，铃声类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                            | 值  | 说明                                                                     |
| ------------------------------- |----|------------------------------------------------------------------------|
| RINGTONE_TYPE_DEFAULT<sup>(deprecated)</sup>           | 0  | 默认铃声类型。<br/> 从 API version 11 开始废弃。建议使用该枚举中的RINGTONE_TYPE_SIM_CARD_0替代。 |
| RINGTONE_TYPE_SIM_CARD_0<sup>11+</sup> | 0  | sim卡1的铃声。                                                              |
| RINGTONE_TYPE_MULTISIM<sup>(deprecated)</sup>          | 1  | 多SIM卡铃声类型。<br/> 从 API version 11 开始废弃。建议使用该枚举中的RINGTONE_TYPE_SIM_CARD_1替代。 |
| RINGTONE_TYPE_SIM_CARD_1<sup>11+</sup> | 1  | sim卡2的铃声。                                                              |

## SystemToneType<sup>11+</sup>

枚举，系统铃声类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                            | 值   | 说明         |
| ------------------------------- |-----|------------|
| SYSTEM_TONE_TYPE_SIM_CARD_0     | 0   | sim卡1的短信提示音。 |
| SYSTEM_TONE_TYPE_SIM_CARD_1     | 1   | sim卡2的短信提示音。 |
| SYSTEM_TONE_TYPE_NOTIFICATION   | 32  | 通知提示音。     |


## ToneCustomizedType<sup>12+</sup>

枚举，铃声自定义类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                         | 值   | 说明         |
| ----------------------------|-----|------------|
| PRE_INSTALLED<sup>12+</sup> | 0   | 预安装铃声类型。 |
| CUSTOMIZED<sup>12+</sup>    | 1   | 自定义铃声类型。 |

## ToneAttrs<sup>12+</sup>

管理铃声属性。在调用ToneAttrs<sup>12+</sup>的接口前，需要先通过[createCustomizedToneAttrs](#systemsoundmanagercreatecustomizedtoneattrs12)或[getDefaultRingtoneAttrs](#getdefaultringtoneattrs12)、[getRingtoneAttrList](#getringtoneattrlist12)等方法获取实例。

### getTitle<sup>12+</sup>

getTitle(): string

获取铃声标题。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明  |
|--------|-----|
| string | 标题。 |

**错误码：**

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**

```ts
toneAttrs.getTitle();
```

### setTitle<sup>12+</sup>

setTitle(title: string): void

设置铃声标题。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明          |
| -------| -------| ---- | ------------|
| title  | string | 是   | 铃声的标题。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
|-------| -------------------- |
| 202   | Caller is not a system application. |
| 401   | The parameters check failed. |

**示例：**

```ts
let toneAttrs = systemSoundManager.createCustomizedToneAttrs();
let title = 'text';
toneAttrs.setTitle(title);
```

### getFileName<sup>12+</sup>

getFileName(): string

获取铃声文件名。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明   |
|--------|------|
| string | 文件名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |


**示例：**

```ts
toneAttrs.getFileName();
```

### setFileName<sup>12+</sup>

setFileName(name: string): void

设置铃声文件名。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明         |
| ------| -------|-----| ------------|
| name  | string | 是   | 铃声的文件名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
|-------| -------------------- |
| 202   | Caller is not a system application. |
| 401   | The parameters check failed. |

**示例：**

```ts
let toneAttrs = systemSoundManager.createCustomizedToneAttrs();
let fileName = 'textFileName';
toneAttrs.setFileName(fileName);
```

### getUri<sup>12+</sup>

getUri(): string

获取铃声资源路径。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明                                                      |
|--------|---------------------------------------------------------|
| string | uri（如：'/data/storage/el2/base/RingTone/alarms/test.ogg'）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**

```ts
toneAttrs.getUri();
```

### getCustomizedType<sup>12+</sup>

getCustomizedType(): string

获取铃声自定义类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                                         | 说明      |
|--------------------------------------------|---------|
| [ToneCustomizedType](#tonecustomizedtype12) | 定制铃音类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**

```ts
toneAttrs.getCustomizedType();
```

### setCategory<sup>12+</sup>

setCategory(category: number): void

设置铃声类别。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名      | 类型      | 必填 | 说明       |
|----------| ---------| ---- |----------|
| category | number   | 是   | 铃声类别，取值参考[铃声类别的常量](#常量)。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
|-------| -------------------- |
| 202   | Caller is not a system application. |
| 401   | The parameters check failed. |

**示例：**

```ts
let toneAttrs = systemSoundManager.createCustomizedToneAttrs();
let categoryValue = systemSoundManager.TONE_CATEGORY_ALARM; // 需更改为实际所需类型常量。
toneAttrs.setCategory(categoryValue);
```

### getCategory<sup>12+</sup>

getCategory(): string

获取铃声类别。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明     |
|--------|--------|
| number | 铃声类别，取值参考[铃声类别的常量](#常量)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |


**示例：**

```ts
toneAttrs.getCategory();
```

## ToneAttrsArray<sup>12+</sup>

type ToneAttrsArray = Array&lt;[ToneAttrs](#toneattrs12)&gt;

铃音属性数组。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 类型                                     | 说明      |
|----------------------------------------|---------|
| Array&lt;[ToneAttrs](#toneattrs12)&gt; | 铃音属性数组。 |

## systemSoundManager.createCustomizedToneAttrs<sup>12+</sup>

createCustomizedToneAttrs(): ToneAttrs

创建自定义铃声属性。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                        | 说明         |
|---------------------------| ------------ |
| [ToneAttrs](#toneattrs12) | 铃声属性类。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**
```ts
let toneAttrs: systemSoundManager.ToneAttrs = systemSoundManager.createCustomizedToneAttrs();
```
## ToneHapticsFeature<sup>13+</sup>

枚举，系统振动风格定义。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                          | 值 | 说明                 |
| ----------------------------- | -- | -------------------- |
| STANDARD| 0  | 标准振动风格。 |
| GENTLE   | 1  | 轻柔振动风格。 |

## ToneHapticsType<sup>14+</sup>

枚举，系统铃音的振动类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                     | 值 | 说明         |
| ------------------------|----|--------|
| CALL_SIM_CARD_0         | 0  | sim卡1的来电铃声的振动。 |
| CALL_SIM_CARD_1         | 1  | sim卡2的来电铃声的振动。 |
| TEXT_MESSAGE_SIM_CARD_0 | 20 | sim卡1的短信提示音的振动。 |
| TEXT_MESSAGE_SIM_CARD_1 | 21 | sim卡2的短信提示音的振动。 |
| NOTIFICATION            | 40 | 通知提示音的振动。 |

## ToneHapticsMode<sup>14+</sup>

枚举，系统铃音场景的振动模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                          | 值 | 说明                 |
| ----------------------------- | -- | -------------------- |
| NONE        | 0  | 无振动模式。 |
| SYNC        | 1  | 与铃音同步模式。 |
| NON_SYNC    | 2  | 非同步模式。 |

## ToneHapticsSettings<sup>14+</sup>

系统铃音的振动设置。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称          | 类型 | 只读 | 可选 | 说明                 |
| ------------ | -- | -- | -- | -------------------- |
| mode | [ToneHapticsMode](#tonehapticsmode14) | 否 | 否 | 系统铃音的振动模式。 |
| hapticsUri | string                          | 否 | 是 | 系统铃音的振动路径，当振动模式不是非同步振动应该被忽略，振动的路径可通过[getToneHapticsList](#gettonehapticslist14)获取。 |

## ToneHapticsAttrs<sup>14+</sup>

系统铃音的振动属性。在调用ToneHapticsAttrs<sup>14+</sup>的接口前，需要先通过[getToneHapticsList](#gettonehapticslist14)或[getHapticsAttrsSyncedWithTone](#gethapticsattrssyncedwithtone14)方法获取实例。

### getUri<sup>14+</sup>

getUri(): string

获取振动资源路径。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明  |
|--------|-----|
| string | uri（如：'/data/storage/el2/base/haptics/synchronized/alarms/test.json'）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**

```ts
toneHapticsAttrs.getUri();
```

### getTitle<sup>14+</sup>

getTitle(): string

获取振动标题。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明  |
|--------|-----|
| string | 标题。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**

```ts
toneHapticsAttrs.getTitle();
```

### getFileName<sup>14+</sup>

getFileName(): string

获取振动文件名。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明  |
|--------|-----|
| string | 文件名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |

**示例：**

```ts
toneHapticsAttrs.getFileName();
```

## ToneHapticsAttrsArray<sup>14+</sup>

type ToneHapticsAttrsArray = Array&lt;ToneHapticsAttrs&gt;

系统铃音的振动属性数组。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 类型                                     | 说明      |
|----------------------------------------|---------|
| Array&lt;[ToneHapticsAttrs](#tonehapticsattrs14)&gt; | 系统铃音的振动属性数组。 |

## systemSoundManager.getSystemSoundManager

getSystemSoundManager(): SystemSoundManager

获取系统声音管理器。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| [SystemSoundManager](#systemsoundmanager) | 系统声音管理类。 |

**示例：**
```ts
let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
```

## SystemSoundManager

管理系统声音。在调用SystemSoundManager的接口前，需要先通过[getSystemSoundManager](#systemsoundmanagergetsystemsoundmanager)创建实例。

### setSystemRingtoneUri<sup>(deprecated)</sup>

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback&lt;void&gt;): void

设置系统铃声uri，使用callback方式异步返回结果。

> **说明：**
> 从 API version 10 开始支持，从 API version 11 开始废弃，建议使用[setRingtoneUri](#setringtoneuri11)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md)   | 是   | 当前应用的上下文。           |
| uri      | string                                   | 是   | 被设置的系统铃声的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |
| type     | [RingtoneType](#ringtonetype)            | 是   | 被设置的系统铃声的类型。     |
| callback | AsyncCallback&lt;void&gt;                | 是   | 回调返回设置成功或失败。     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.setSystemRingtoneUri(context, uri, type, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set system ringtone uri. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful setting of the system ringtone uri.`);
});
```

### setSystemRingtoneUri<sup>(deprecated)</sup>

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise&lt;void&gt;

设置系统铃声uri，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 10 开始支持，从 API version 11 开始废弃，建议使用[setRingtoneUri](#setringtoneuri11)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md)  | 是   | 当前应用的上下文。         |
| uri      | string                                   | 是   | 被设置的系统铃声的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |
| type     | [RingtoneType](#ringtonetype)            | 是   | 被设置的系统铃声的类型。   |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.setSystemRingtoneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system ringtone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system ringtone uri ${err}`);
});
```

### getSystemRingtoneUri<sup>(deprecated)</sup>

getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback&lt;string&gt;): void

获取系统铃声uri，使用callback方式异步返回结果。

> **说明：**
> 从 API version 10 开始支持，从 API version 11 开始废弃，建议使用[getRingtoneUri](#getringtoneuri11)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                                                    | 必填 | 说明                     |
| -------- |-----------------------------------------------------------------------| ---- | ------------------------ |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md)   | 是   | 当前应用的上下文。         |
| type     | [RingtoneType](#ringtonetype)                                         | 是   | 待获取的系统铃声的类型。    |
| callback | AsyncCallback&lt;string&gt;                                           | 是   | 回调返回获取的系统铃声uri。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemRingtoneUri(context, type, (err: BusinessError, value: string) => {
  if (err) {
    console.error(`Failed to get system ringtone uri. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone uri is obtained ${value}.`);
});
```

### getSystemRingtoneUri<sup>(deprecated)</sup>

getSystemRingtoneUri(context: Context, type: RingtoneType): Promise&lt;string&gt;

获取系统铃声uri，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 10 开始支持，从 API version 11 开始废弃，建议使用[getRingtoneUri](#getringtoneuri11)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------ |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md)  | 是   | 当前应用的上下文。         |
| type     | [RingtoneType](#ringtonetype)                                        | 是   | 被设置的系统铃声的类型。   |

**返回值：**

| 类型                | 说明                                |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise回调返回获取的系统铃声uri。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemRingtoneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system ringtone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone uri ${err}`);
});
```

### getSystemRingtonePlayer<sup>(deprecated)</sup>

getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback&lt;RingtonePlayer&gt;): void

获取系统铃声播放器，使用callback方式异步返回结果。

> **说明：**
> 从 API version 10 开始支持，从 API version 11 开始废弃，建议使用[getRingtonePlayer](#getringtoneplayer11)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                         |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md)  | 是   | 当前应用的上下文。            |
| type     | [RingtoneType](#ringtonetype)            | 是   | 待获取播放器的系统铃声的类型。 |
| callback | AsyncCallback&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer-sys.md#ringtoneplayer)&gt; | 是 | 回调返回获取的系统铃声播放器。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemRingtonePlayer(context, type, (err: BusinessError, value: systemSoundManager.RingtonePlayer) => {
  if (err) {
    console.error(`Failed to get system ringtone player. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
});
```

### getSystemRingtonePlayer<sup>(deprecated)</sup>

getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise&lt;RingtonePlayer&gt;

获取系统铃声播放器，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 10 开始支持，从 API version 11 开始废弃，建议使用[getRingtonePlayer](#getringtoneplayer11)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                                                  | 必填 | 说明                         |
| -------- |---------------------------------------------------------------------| ---- | --------------------------- |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。            |
| type     | [RingtoneType](#ringtonetype)                                       | 是   | 待获取播放器的系统铃声的类型。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer-sys.md#ringtoneplayer)&gt; | Promise回调返回获取的系统铃声播放器。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemRingtonePlayer(context, type).then((value: systemSoundManager.RingtonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone player ${err}`);
});
```

### setRingtoneUri<sup>11+</sup>

setRingtoneUri(context: BaseContext, uri: string, type: RingtoneType): Promise&lt;void&gt;

设置系统铃声uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- |-------------------------------| ---- | ------------------------ |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)            | 是   | 当前应用的上下文。         |
| uri      | string                        | 是   | 被设置的系统铃声的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |
| type     | [RingtoneType](#ringtonetype) | 是   | 被设置的系统铃声的类型。   |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.setRingtoneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system ringtone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system ringtone uri ${err}`);
});
```

### getRingtoneUri<sup>11+</sup>

getRingtoneUri(context: BaseContext, type: RingtoneType): Promise&lt;string&gt;

获取系统铃声uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                             | 必填 | 说明                     |
| -------- | -------------------------------| ---- | ------------------------ |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)| 是   | 当前应用的上下文。         |
| type     | [RingtoneType](#ringtonetype)  | 是   | 被设置的系统铃声的类型。   |

**返回值：**

| 类型                | 说明                                |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise回调返回获取的系统铃声uri。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400103  | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getRingtoneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system ringtone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone uri ${err}`);
});
```

### getRingtonePlayer<sup>11+</sup>

getRingtonePlayer(context: BaseContext, type: RingtoneType): Promise&lt;RingtonePlayer&gt;

获取系统铃声播放器，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                         |
| -------- | --------------------------------| ---- | --------------------------- |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。            |
| type     | [RingtoneType](#ringtonetype)   | 是   | 待获取播放器的系统铃声的类型。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer-sys.md#ringtoneplayer)&gt; | Promise回调返回获取的系统铃声播放器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getRingtonePlayer(context, type).then((value: systemSoundManager.RingtonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone player ${err}`);
});
```

### setSystemToneUri<sup>11+</sup>

setSystemToneUri(context: BaseContext, uri: string, type: SystemToneType): Promise&lt;void&gt;

设置系统提示音uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- |-------------------------------------| ---- | ------------------------ |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。         |
| uri      | string                              | 是   | 被设置的系统提示音的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |
| type     | [SystemToneType](#systemtonetype11) | 是   | 被设置的系统提示音的类型。   |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.setSystemToneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system tone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system tone uri ${err}`);
});
```

### getSystemToneUri<sup>11+</sup>

getSystemToneUri(context: BaseContext, type: SystemToneType): Promise&lt;string&gt;

获取系统提示音uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- |-------------------------------------| ---- | ------------------------ |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。         |
| type     | [SystemToneType](#systemtonetype11) | 是   | 被设置的系统提示音的类型。   |

**返回值：**

| 类型                | 说明                                |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise回调返回获取的系统提示音uri。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemToneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system tone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone uri ${err}`);
});
```

### getSystemTonePlayer<sup>11+</sup>

getSystemTonePlayer(context: BaseContext, type: SystemToneType): Promise&lt;SystemTonePlayer&gt;

获取系统提示音播放器，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                         |
| -------- |-------------------------------------| ---- | --------------------------- |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。            |
| type     | [SystemToneType](#systemtonetype11) | 是   | 待获取播放器的系统提示音的类型。 |

**返回值：**

| 类型                                                                                               | 说明                            |
|--------------------------------------------------------------------------------------------------| ------------------------------- |
| Promise&lt;[SystemTonePlayer](js-apis-inner-multimedia-systemTonePlayer-sys.md#systemtoneplayer)&gt; | Promise回调返回获取的系统提示音播放器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;
let systemTonePlayer: systemSoundManager.SystemTonePlayer | undefined = undefined;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemTonePlayer(context, type).then((value: systemSoundManager.SystemTonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system tone player is obtained.`);
    systemTonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone player ${err}`);
});
```

### getDefaultRingtoneAttrs<sup>12+</sup>

getDefaultRingtoneAttrs(context: BaseContext, type: RingtoneType): Promise&lt;ToneAttrs&gt;

获取系统铃声的属性，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                         |
| -------- |-------------------------------------| ---- | --------------------------- |
| context  |[BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。            |
| type     |[RingtoneType](#ringtonetype)        | 是   | 被设置的系统铃声的类型。  |

**返回值：**

| 类型                                       | 说明                  |
|------------------------------------------|---------------------|
| Promise&lt;[ToneAttrs](#toneattrs12)&gt; | Promise回调返回系统铃声的属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getDefaultRingtoneAttrs(context, type).then((value: systemSoundManager.ToneAttrs) => {
  console.info(`Promise returned to indicate that the value of the attributes of the default ringtone is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the default ring tone attrs ${err}`);
});
```

### getRingtoneAttrList<sup>12+</sup>

getRingtoneAttrList(context: BaseContext, type: RingtoneType): Promise&lt;ToneAttrsArray&gt;

获取系统铃声的属性列表，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                         |
| -------- |-------------------------------------| ---- | --------------------------- |
| context  |[BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。            |
| type     |[RingtoneType](#ringtonetype)        | 是   | 被设置的系统铃声的类型。  |

**返回值：**

| 类型                                                 | 说明                    |
|----------------------------------------------------|-----------------------|
| Promise&lt;[ToneAttrsArray](#toneattrsarray12)&gt; | Promise回调返回系统铃声的属性列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getRingtoneAttrList(context, type).then((value: systemSoundManager.ToneAttrsArray) => {
  console.info(`Promise returned to indicate that the value of the attribute list of ringtone is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the attribute list of ringtone ${err}`);
});
```

### getDefaultSystemToneAttrs<sup>12+</sup>

getDefaultSystemToneAttrs(context: BaseContext, type: SystemToneType): Promise&lt;ToneAttrs&gt;

获取系统提示音的属性，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                                                          | 必填 | 说明                         |
| -------- |-----------------------------------------------------------------------------| ---- | --------------------------- |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。            |
| type     | [SystemToneType](#systemtonetype11)                                         | 是   | 待获取播放器的系统提示音的类型。 |

**返回值：**

| 类型                                      | 说明                   |
|-----------------------------------------|----------------------|
| Promise&lt;[ToneAttrs](#toneattrs12)&gt; | Promise回调返回系统提示音的属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getDefaultSystemToneAttrs(context, type).then((value: systemSoundManager.ToneAttrs) => {
  console.info(`Promise returned to indicate that the value of the attributes of the system ringtone is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone attrs ${err}`);
});
```

### getSystemToneAttrList<sup>12+</sup>

getSystemToneAttrList(context: BaseContext, type: SystemToneType): Promise&lt;ToneAttrsArray&gt;

获取系统提示音的属性列表，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                                                          | 必填 | 说明                         |
| -------- |-----------------------------------------------------------------------------| ---- | --------------------------- |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。            |
| type     | [SystemToneType](#systemtonetype11)                                         | 是   | 待获取播放器的系统提示音的类型。  |

**返回值：**

| 类型                                                | 说明                     |
|---------------------------------------------------|------------------------|
| Promise&lt;[ToneAttrsArray](#toneattrsarray12)&gt; | Promise回调返回系统提示音的属性列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getSystemToneAttrList(context, type).then((value: systemSoundManager.ToneAttrsArray) => {
  console.info(`Promise returned to indicate that the value of the attribute list of system tone is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the attribute list of system tone ${err}`);
});
```

### getDefaultAlarmToneAttrs<sup>12+</sup>

getDefaultAlarmToneAttrs(context: BaseContext): Promise&lt;ToneAttrs&gt;

获取系统闹铃的属性，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型         | 必填 | 说明        |
| --------|------------| ---- |-----------|
| context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用的上下文。 |

**返回值：**

| 类型                                      | 说明                  |
|-----------------------------------------|---------------------|
| Promise&lt;[ToneAttrs](#toneattrs12)&gt; | Promise回调返回系统闹铃的属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getDefaultAlarmToneAttrs(context).then((value: systemSoundManager.ToneAttrs) => {
  console.info(`Promise returned to indicate that the value of the attributes of the default alarm tone is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the default alarm tone attrs ${err}`);
});
```

### setAlarmToneUri<sup>12+</sup>

setAlarmToneUri(context: Context, uri: string): Promise&lt;void&gt;

设置系统闹铃uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型        | 必填 | 说明   |
| -------- | --------- | ---- |--------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。                                                                           |
| uri      | string    | 是   | 被设置的系统闹铃的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |

**返回值：**

| 类型                | 说明                   |
| ------------------- |----------------------|
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.setAlarmToneUri(context, uri).then(() => {
  console.info(`Promise returned to indicate a successful setting of the alarm tone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the alarm tone uri ${err}`);
});
```

### getAlarmToneUri<sup>12+</sup>

getAlarmToneUri(context: Context): Promise&lt;string&gt;

获取系统当前闹铃uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型      | 必填 | 说明              |
| -------- | --------| ---- |-----------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。  |

**返回值：**

| 类型                    | 说明                    |
|-----------------------|-----------------------|
| Promise&lt;string&gt; | Promise回调返回系统当前闹铃uri。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getAlarmToneUri(context).then((value: string) => {
  console.info(`Promise returned to indicate that the value of alarm tone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the alarm tone uri ${err}`);
});
```

### getAlarmToneAttrList<sup>12+</sup>

getAlarmToneAttrList(context: BaseContext): Promise&lt;ToneAttrsArray&gt;

获取全部闹铃属性列表，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型            | 必填 | 说明                         |
| -------- |--------------| ---- | --------------------------- |
| context  | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)  | 是   | 当前应用的上下文。            |

**返回值：**

| 类型                                                 | 说明                   |
|----------------------------------------------------|----------------------|
| Promise&lt;[ToneAttrsArray](#toneattrsarray12)&gt; | Promise回调返回全部闹铃属性列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getAlarmToneAttrList(context).then((value: systemSoundManager.ToneAttrsArray) => {
  console.info(`Promise returned to indicate that the value of the attribute list of alarm tone is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the attribute list of alarm tone ${err}`);
});
```

### openAlarmTone<sup>12+</sup>

openAlarmTone(context: Context, uri: string): Promise&lt;number&gt;

打开闹铃文件，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                                                  |
| -------- | ---------| ---- |-------------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。                                                                           |
| uri      | string   | 是   | 被设置的系统闹铃的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |

**返回值：**

| 类型                    | 说明             |
|-----------------------|----------------|
| Promise&lt;number&gt; | Promise回调返回fd。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |
| 20700001 | Tone type mismatch, e.g. tone of uri is notification instead of alarm. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.openAlarmTone(context, uri).then((value: number) => {
  console.info(`Promise returned to indicate the value of fd.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to open alarm tone ${err}`);
});
```

### close<sup>12+</sup>

close(fd: number): Promise&lt;void&gt;

关闭闹铃文件，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                           |
|-----| --------| ---- |----------------------------------------------|
| fd  | number  | 是   | 文件描述符，通过[openAlarmTone](#openalarmtone12)获取。 |

**返回值：**

| 类型                  | 说明             |
|---------------------|----------------|
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let fd = 50; // 需更改为目标铃声的fd。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.close(fd).then(() => {
  console.info(`Promise returned to indicate that the fd has been close.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to close fd ${err}`);
});
```

### addCustomizedTone<sup>12+</sup>

addCustomizedTone(context: BaseContext, toneAttr: ToneAttrs, externalUri: string): Promise&lt;string&gt;

通过铃音uri将自定义铃音添加到铃音库，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明            |
|-----|-----------| ---- |---------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。     |
| toneAttr  | ToneAttrs | 是   | 铃音属性。         |
| externalUri  | string    | 是   | 外部存储器中的铃音uri。 |

**返回值：**

| 类型                    | 说明                      |
|-----------------------|-------------------------|
| Promise&lt;string&gt; | Promise回调返回铃音在铃音库中的uri。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 201     | Permission denied. |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400102     | Operation is not allowed, e.g. ringtone to add is not customized. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let title = 'test'; // 需更改为实际名称。
let fileName = 'displayName_test'; // 需更改为实际文件名。
let categoryValue = systemSoundManager.TONE_CATEGORY_ALARM;

let toneAttrs = systemSoundManager.createCustomizedToneAttrs();
toneAttrs.setTitle(title);
toneAttrs.setFileName(fileName);
toneAttrs.setCategory(categoryValue);

let path = 'file://data/test.ogg'; // 需更改为实际铃音uri。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.addCustomizedTone(context, toneAttrs, path).then((value: string) => {
  console.info(`Promise returned to indicate that the value of tone uri in ringtone library.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to add customized tone ${err}`);
});
```

### addCustomizedTone<sup>12+</sup>

addCustomizedTone(context: BaseContext, toneAttr: ToneAttrs, fd: number, offset?: number, length?: number): Promise&lt;string&gt;

通过文件描述符fd将自定义铃音添加到铃音库，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                     |
|-----|-----------|----|------------------------------------------------------------------------|
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是  | 当前应用的上下文。                                                              |
| toneAttr | [ToneAttrs](#toneattrs12) | 是  | 铃音属性。                                                                  |
| fd  | number    | 是  | 文件描述符，可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。 |
| offset | number    | 否  | 读取数据的偏移量（以字节为单位）。默认情况下为0。                                              |
| length | number    | 否  | 读取的数据的长度（以字节为单位）。默认情况下，长度为偏移后的剩余全部字节数。                                 |

**返回值：**

| 类型                    | 说明                      |
|-----------------------|-------------------------|
| Promise&lt;string&gt; | Promise回调返回铃音在铃音库中的uri。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 201     | Permission denied. |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400102     | Operation is not allowed, e.g. ringtone to add is not customized. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let title = 'test'; // 需更改为实际名称。
let fileName = 'displayName_test'; // 需更改为实际文件名。
let categoryValue = systemSoundManager.TONE_CATEGORY_ALARM;

let toneAttrs = systemSoundManager.createCustomizedToneAttrs();
toneAttrs.setTitle(title);
toneAttrs.setFileName(fileName);
toneAttrs.setCategory(categoryValue);

let fd = 10; // 需更改为实际铃音fd。
let offset = 0; // 需更改为实际所需偏移量。
let length = 50; // 需更改为实际所需数据长度。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.addCustomizedTone(context, toneAttrs, fd, offset, length).then((value: string) => {
  console.info(`Promise returned to indicate that the value of tone uri in ringtone library.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to add customized tone ${err}`);
});
```

### removeCustomizedTone<sup>12+</sup>

removeCustomizedTone(context: BaseContext, uri: string): Promise&lt;void&gt;

从铃音库中删除自定义铃音，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                                                      |
|-----|-----------| ---- |---------------------------------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。                                                                                               |
| uri  | string    | 是   | 铃音uri，可通过[addCustomizedTone](#addcustomizedtone12)或[getAlarmToneAttrList](#getalarmtoneattrlist12)等方法获取。 |

**返回值：**

| 类型                  | 说明                    |
|---------------------|-----------------------|
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 201     | Permission denied. |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400102     | Operation is not allowed, e.g. ringtone to add is not customized. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.removeCustomizedTone(context, uri).then(() => {
  console.info(`Promise returned to indicate that the customized tone has been deleted.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to delete customized tone ${err}`);
});
```

### getToneHapticsSettings<sup>14+</sup>

getToneHapticsSettings(context: BaseContext, type: ToneHapticsType): Promise&lt;ToneHapticsSettings&gt;

获取系统铃音的振动设置，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                          |
|-----|-----------| ---- |----------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。   |
| type  | [ToneHapticsType](#tonehapticstype14)    | 是   | 待获取系统铃音的振动类型。 |

**返回值：**

| 类型                  | 说明                    |
|---------------------|-----------------------|
| Promise&lt;[ToneHapticsSettings](#tonehapticssettings14)&gt; | Promise回调返回铃声的振动设置。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400103 | I/O error. |
| 20700003 | Unsupported operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.ToneHapticsType = systemSoundManager.ToneHapticsType.CALL_SIM_CARD_0;

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getToneHapticsSettings(context, type).then((value: systemSoundManager.ToneHapticsSettings) => {
  console.info(`Promise returned to indicate that the value of the tone haptics settings is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the tone haptics settings ${err}`);
});
```

### setToneHapticsSettings<sup>14+</sup>

setToneHapticsSettings(context: BaseContext, type: ToneHapticsType, settings: ToneHapticsSettings): Promise&lt;void&gt;

设置系统铃音的振动，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                          |
|-----|-----------| ---- |----------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。   |
| type  | [ToneHapticsType](#tonehapticstype14)    | 是   | 被设置的系统铃音的振动类型。 |
| settings  | [ToneHapticsSettings](#tonehapticssettings14)    | 是   | 被设置的系统铃音的振动设置。 |

**返回值：**

| 类型                  | 说明                    |
|---------------------|-----------------------|
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400102 | Operation is not allowed, e.g. ringtone to add is not customized. |
| 5400103 | I/O error. |
| 20700003 | Unsupported operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.ToneHapticsType = systemSoundManager.ToneHapticsType.CALL_SIM_CARD_0;
let toneHapticsSettings: systemSoundManager.ToneHapticsSettings = {
  mode: systemSoundManager.ToneHapticsMode.NON_SYNC,
  hapticsUri: '/data/storage/el2/base/haptics/synchronized/alarms/test.json', // 需更改为通过getToneHapticsList获取的Uri。
}

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.setToneHapticsSettings(context, type, toneHapticsSettings).then(() => {
  console.info(`Promise returned to indicate a successful setting of the tone haptics.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the tone haptics settings ${err}`);
});
```

### getToneHapticsList<sup>14+</sup>

getToneHapticsList(context: BaseContext, isSynced: boolean): Promise&lt;ToneHapticsAttrsArray&gt;

获取同步或者非同步的系统铃音的振动属性列表，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                          |
|-----|-----------| ---- |----------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。   |
| isSynced  | boolean    | 是   | 表示待获取的振动是否与某个铃音同步。true表示同步，false表示不同步。 |

**返回值：**

| 类型                  | 说明                    |
|---------------------|-----------------------|
| Promise&lt;[ToneHapticsAttrsArray](#tonehapticsattrsarray14)&gt; | Promise回调返回同步或者非同步的系统铃音的振动属性列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400103 | I/O error. |
| 20700003 | Unsupported operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getToneHapticsList(context, false).then((value: systemSoundManager.ToneHapticsAttrsArray) => {
  console.info(`Promise returned to indicate that the value of the attribute list of tone haptics is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the attribute list of tone haptics ${err}`);
});
```

### getHapticsAttrsSyncedWithTone<sup>14+</sup>

getHapticsAttrsSyncedWithTone(context: BaseContext, toneUri: string): Promise&lt;ToneHapticsAttrs&gt;

获取与指定铃音同步的振动属性，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                          |
|-----|-----------| ---- |----------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。   |
| toneUri  | string    | 是   | 待获取同步振动的系统铃声Uri,可通过[getRingtoneAttrList](#getringtoneattrlist12)或[getSystemToneAttrList](#getsystemtoneattrlist12)等获取。 |

**返回值：**

| 类型                  | 说明                    |
|---------------------|-----------------------|
| Promise&lt;[ToneHapticsAttrs](#tonehapticsattrs14)&gt; | Promise回调返回与指定铃音同步的振动属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息              |
|---------| -------------------- |
| 202     | Caller is not a system application. |
| 401     | The parameters check failed. |
| 5400102 | Operation is not allowed, e.g. ringtone to add is not customized. |
| 5400103 | I/O error. |
| 20700003 | Unsupported operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.BaseContext = getContext(this);
let toneUri: string = '/data/storage/el2/base/RingTone/alarms/test.ogg'; // 需更改为实际铃音uri。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.getHapticsAttrsSyncedWithTone(context, toneUri).then((value: systemSoundManager.ToneHapticsAttrs) => {
  console.info(`Promise returned to indicate that the value of the attribute of tone haptics is obtained.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the attribute of tone haptics ${err}`);
});
```

### openToneHaptics<sup>14+</sup>

openToneHaptics(context: Context, hapticsUri: string): Promise&lt;number&gt;

打开系统铃音的振动，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                                                  |
| -------- | ---------| ---- |-------------------------------------------------------------------------------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前应用的上下文。           |
| hapticsUri      | string   | 是   | 待打开系统铃音的振动的uri，资源支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)。 |

**返回值：**

| 类型                    | 说明             |
|-----------------------|----------------|
| Promise&lt;number&gt; | Promise回调返回fd。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 202 | Caller is not a system application. |
| 401 | The parameters check failed. |
| 5400102 | Operation is not allowed, e.g. ringtone to add is not customized. |
| 5400103 | I/O error. |
| 20700003 | Unsupported operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: Context = getContext(this);
let hapticsUri = '/data/storage/el2/base/haptics/synchronized/alarms/test.json'; // 需更改为目标统铃音的振动的uri。

let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
systemSoundManagerInstance.openToneHaptics(context, hapticsUri).then((value: number) => {
  console.info(`Promise returned to indicate the value of fd.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to open haptics ${err}`);
});
```

## RingtonePlayer<sup>10+</sup>

type RingtonePlayer = _RingtonePlayer;

系统铃音播放器对象。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 类型              |说明     |
|-----------------|-------|
| _RingtonePlayer | 系统铃音播放器。 |

## SystemTonePlayer<sup>11+</sup>

type SystemTonePlayer = _SystemTonePlayer;

系统提示音播放器对象。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 类型              | 说明        |
|-----------------|-----------|
| _SystemTonePlayer | 系统提示音播放器。 |

## RingtoneOptions<sup>10+</sup>

type RingtoneOptions = _RingtoneOptions;

系统铃音播放器配置项。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 类型              | 说明          |
|-----------------|-------------|
| _RingtoneOptions | 系统铃音播放器配置项。 |

## SystemToneOptions<sup>11+</sup>

type SystemToneOptions = _SystemToneOptions;

系统提示音播放器配置项。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 类型              | 说明            |
|-----------------|---------------|
| _SystemToneOptions | 系统提示音音播放器配置项。 |



