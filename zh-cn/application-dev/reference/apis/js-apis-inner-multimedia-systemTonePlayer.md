# systemTonePlayer (系统提示音播放器)

系统提示音播放器提供了短信提示音、通知提示音的播放、配置、获取信息等功能。

systemTonePlayer需要和[@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager.md)配合使用，才能完成管理系统提示音的功能。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```ts
import systemSoundManager from '@ohos.multimedia.systemSoundManager';
```

## SystemToneOptions

提示音参数选项。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称      | 类型            | 必填 | 说明                        |
| --------- | -------------- |---|---------------------------|
| muteAudio | boolean | 否 | 是否静音，true表示静音，false表示正常发声。 |
| muteHaptics | boolean | 否 | 是否震动，true表示无振动，false表示正常振动。 |

## SystemTonePlayer

系统提示音播放器提供了短信提示音、通知提示音的播放、配置、获取信息等功能。在调用SystemTonePlayer的接口前，需要先通过[getSystemTonePlayer](js-apis-systemSoundManager.md#getsystemtoneplayer11)创建实例。

### getTitle

getTitle(): Promise&lt;string&gt;

获取提示音标题，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                  | 说明                              |
| --------------------- | -------------------------------- |
| Promise&lt;string&gt; | Promise回调返回获取的系统提示音标题。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

systemTonePlayer.getTitle().then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system tone player title is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone player title ${err}`);
});
```

### prepare

prepare(): Promise&lt;void&gt;

准备播放提示音，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise回调返回准备成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 5400102 | Operation not allowed. |
| 5400103 | I/O error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

systemTonePlayer.prepare().then(() => {
  console.info(`Promise returned to indicate a successful prepareing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to prepareing system tone player. ${err}`);
});
```

### start

start(toneOptions?: SystemToneOptions): Promise&lt;number&gt;

开始播放提示音，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**需要权限：** ohos.permission.VIBRATE

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- |-----------------------------------------|--| ------------------------- |
| toneOptions  | [SystemToneOptions](#systemtoneoptions) | 否 | 系统提示音选项。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise回调返回streamID。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 5400102 | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

class SystemToneOptions {
  muteAudio: boolean = false;
  muteHaptics: boolean = false;
}
let systemToneOptions: SystemToneOptions = {muteAudio: true, muteHaptics: false};

systemTonePlayer.start(systemToneOptions).then((value: number) => {
  console.info(`Promise returned to indicate that the value of the system tone player streamID is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start system tone player. ${err}`);
});
```

### stop

stop(id: number): Promise&lt;void&gt;

停止播放提示音，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- |-----------------------------------------|--| ------------------------- |
| id  | number | 是 | start方法返回的streamID。 |

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise回调返回停止播放成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息              |
| ------- | --------------------- |
| 5400102 | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let streamID: number = 0; //streamID为start方法返回的streamID,此处只做初始化。
systemTonePlayer.stop(streamID).then(() => {
  console.info(`Promise returned to indicate a successful stopping of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop system tone player. ${err}`);
});
```

### release

release(): Promise&lt;void&gt;

释放提示音播放器，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回释放成功或失败。   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

systemTonePlayer.release().then(() => {
  console.info(`Promise returned to indicate a successful releasing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release system tone player. ${err}`);
});
```