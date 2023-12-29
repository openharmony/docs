# @ohos.multimedia.systemSoundManager (系统声音管理)

系统声音管理提供管理系统声音的一些基础能力，包括对系统铃声的资源设置与读取、获取系统铃声播放器等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```ts
import systemSoundManager from '@ohos.multimedia.systemSoundManager';
```

## RingtoneType

枚举，铃声类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称                            |  值     | 说明                                         |
| ------------------------------- | ------ | -------------------------------------------- |
| RINGTONE_TYPE_DEFAULT           | 0      | 默认铃声类型。                                 |
| RINGTONE_TYPE_MULTISIM          | 1      | 多SIM卡铃声类型。                              |

## systemSoundManager.getSystemSoundManager

getSystemSoundManager(): SystemSoundManager

获取系统声音管理器。

**系统接口：** 该接口为系统接口

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

### setSystemRingtoneUri

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback&lt;void&gt;): void

设置系统铃声uri，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | 是   | 当前应用的上下文。           |
| uri      | string                                   | 是   | 被设置的系统铃声的uri，资源支持可参考[media.AVPlayer](js-apis-media.md#avplayer9)。 |
| type     | [RingtoneType](#ringtonetype)            | 是   | 被设置的系统铃声的类型。     |
| callback | AsyncCallback&lt;void&gt;                | 是   | 回调返回设置成功或失败。     |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.setSystemRingtoneUri(context, uri, type, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set system ringtone uri. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful setting of the system ringtone uri.`);
});
```

### setSystemRingtoneUri

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise&lt;void&gt;

设置系统铃声uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | 是   | 当前应用的上下文。         |
| uri      | string                                   | 是   | 被设置的系统铃声的uri，资源支持可参考[media.AVPlayer](js-apis-media.md#avplayer9)。 |
| type     | [RingtoneType](#ringtonetype)            | 是   | 被设置的系统铃声的类型。   |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // 需更改为目标铃声文件的uri
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.setSystemRingtoneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system ringtone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system ringtone uri ${err}`);
});
```

### getSystemRingtoneUri

getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback&lt;string&gt;): void

获取系统铃声uri，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | 是   | 当前应用的上下文。         |
| type     | [RingtoneType](#ringtonetype)            | 是   | 待获取的系统铃声的类型。    |
| callback | AsyncCallback&lt;string&gt;              | 是   | 回调返回获取的系统铃声uri。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.getSystemRingtoneUri(context, type, (err: BusinessError, value: string) => {
  if (err) {
    console.error(`Failed to get system ringtone uri. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone uri is obtained ${value}.`);
});
```

### getSystemRingtoneUri

getSystemRingtoneUri(context: Context, type: RingtoneType): Promise&lt;string&gt;

获取系统铃声uri，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | 是   | 当前应用的上下文。         |
| type     | [RingtoneType](#ringtonetype)            | 是   | 被设置的系统铃声的类型。   |

**返回值：**

| 类型                | 说明                                |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise回调返回获取的系统铃声uri。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.getSystemRingtoneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system ringtone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone uri ${err}`);
});
```

### getSystemRingtonePlayer

getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback&lt;RingtonePlayer&gt;): void

获取系统铃声播放器，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                         |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | Context                                  | 是   | 当前应用的上下文。            |
| type     | [RingtoneType](#ringtonetype)            | 是   | 待获取播放器的系统铃声的类型。 |
| callback | AsyncCallback&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | 是 | 回调返回获取的系统铃声播放器。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

systemSoundManagerInstance.getSystemRingtonePlayer(context, type, (err: BusinessError, value: systemSoundManager.RingtonePlayer) => {
  if (err) {
    console.error(`Failed to get system ringtone player. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
});
```

### getSystemRingtonePlayer

getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise&lt;RingtonePlayer&gt;

获取系统铃声播放器，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                         |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | Context                                  | 是   | 当前应用的上下文。            |
| type     | [RingtoneType](#ringtonetype)            | 是   | 待获取播放器的系统铃声的类型。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | Promise回调返回获取的系统铃声播放器。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

systemSoundManagerInstance.getSystemRingtonePlayer(context, type).then((value: systemSoundManager.RingtonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone player ${err}`);
});
```
