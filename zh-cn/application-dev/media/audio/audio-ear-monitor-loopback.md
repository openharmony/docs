# 实现音频低时延耳返

AudioLoopback是音频返听器，可将音频以更低时延的方式实时传输到耳机中，让用户可以实时听到自己或者其他的相关声音。

常用于K歌类应用，将录制的人声和背景音乐实时传送到耳机中，使用户通过反馈即时进行调整，获得更好的使用体验。

当启用音频返听时，系统会创建低时延渲染器与低时延采集器，实现低时延耳返功能。采集的音频直接通过内部路由返回到渲染器。对于渲染器，其音频焦点策略与[STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)相匹配。对于采集器，其音频焦点策略与[SOURCE_TYPE_MIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8)相匹配。

输入\输出设备由系统自动选择。如果当前输入\输出不支持低时延，则音频返听无法启用。在运行过程中，如果音频焦点被另一个音频流抢占，输入\输出设备切换到不支持低时延的设备，系统会自动禁用音频返听。

## 使用前提

- 当前仅支持通过有线耳机实现低时延返听功能，音频由有线耳机进行采集并播放。

- 低功耗渲染器和低时延渲染器在API version 20不能实现并发。若要启用渲染器，建议采用[STREAM_USAGE_UNKNOWN](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)；系统内决策采用[STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)创建普通渲染器。

## 开发指导

使用AudioLoopback音频返听涉及到[isAudioLoopbackSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isaudioloopbacksupported20)返听能力查询、AudioLoopback实例创建、返听音量设置、返听状态监听与返听启用禁用等。本开发指导将以一次启用返听的过程为例，向开发者讲解如何使用AudioLoopback进行音频返听，建议搭配[AudioLoopback](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md)的API说明阅读。

下图展示了AudioLoopback的状态变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应行为。

需要注意的是在确定的状态执行不合适的方法可能导致AudioLoopback发生错误，建议开发者在调用状态转换的方法前进行状态检查，避免程序运行产生预期以外的结果。

**AudioLoopback状态变化示意图**

![AudioLoopback status change](figures/audioloopback-status-change.png)

使用[on('statusChange')](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#onstatuschange20)方法可以监听AudioLoopback的状态变化，每个状态对应值与说明见[AudioLoopbackStatus](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackstatus20)。

### 开发步骤及注意事项

1. 查询返听能力并创建AudioLoopback实例，音频返听模式可以查看[AudioLoopbackMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackmode20)。

   > **说明：**
   > 返听需要申请麦克风权限ohos.permission.MICROPHONE，申请方式参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

   ```ts
    import { audio } from '@kit.AudioKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    let mode: audio.AudioLoopbackMode.HARDWARE;
    let audioLoopback: audio.AudioLoopback;
    let isSupported = audio.getAudioManager().getStreamManager().isAudioLoopbackSupported(mode);
    if (isSupported) {
      audio.createAudioLoopback(mode).then((loopback) => {
        audioLoopback = loopback;
        console.info('Invoke createAudioLoopback succeeded.');
      }).catch((err: BusinessError) => {
        console.error(`Invoke createAudioLoopback failed, code is ${err.code}, message is ${err.message}.`);
      });
    }
   ```

2. 调用[getStatus](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getstatus20)方法，查询当前返听状态。

    > **注意：**
    > 音频返听状态受音频焦点、低时延管控、采集与播放设备等因素影响。

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioLoopback.getStatus().then((status: audio.AudioLoopbackStatus) => {
      console.info(`getStatus success, status is ${status}.`);
    }).catch((err: BusinessError) => {
      console.error(`getStatus failed, code is ${err.code}, message is ${err.message}.`);
    })
   ```

3. 调用[setVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#setvolume20)方法，设置音频返听音量。

    > **注意：**
    > - 在启用返听前设置音量，音量将在启用返听成功后生效。
    > - 在启用返听后设置音量，音量将立即生效。
    > - 启用返听前未设置音量，启用返听时将采用默认音量0.5。

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioLoopback.setVolume(0.5).then(() => {
      console.info('setVolume success.');
    }).catch((err: BusinessError) => {
      console.error(`setVolume failed, code is ${err.code}, message is ${err.message}.`);
    });
   ```

4. 调用[enable](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#enable20)方法，启用或禁用音频返听功能。

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioLoopback.enable(true).then((isSuccess) => {
      if (isSuccess) {
        console.info('enable success.');
      } else {
        console.info('enable failed.');
      }
    }).catch((err: BusinessError) => {
      console.error(`enable failed, code is ${err.code}, message is ${err.message}.`);
    });

    audioLoopback.enable(false).then((isSuccess) => {
      if (isSuccess) {
        console.info('disable success.');
      } else {
        console.info('disable failed.');
      }
    }).catch((err: BusinessError) => {
      console.error(`disable failed, code is ${err.code}, message is ${err.message}.`);
    });
   ```

### 完整示例

使用AudioLoopback启用音频低时延返听示例代码如下所示。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

const TAG = 'AudioLoopbackDemo';

let mode: audio.AudioLoopbackMode.HARDWARE;
let audioLoopback: audio.AudioLoopback | undefined = undefined;

let statusChangeCallback = (status: audio.AudioLoopbackStatus) => {
  if (status == audio.AudioLoopbackStatus.UNAVAILABLE_DEVICE) {
    console.info('Audio loopback status is: UNAVAILABLE_DEVICE');
  } else if (status == audio.AudioLoopbackStatus.UNAVAILABLE_SCENE) {
    console.info('Audio loopback status is: UNAVAILABLE_SCENE');
  } else if (status == audio.AudioLoopbackStatus.AVAILABLE_IDLE) {
    console.info('Audio loopback status is: AVAILABLE_IDLE');
  } else if (status == audio.AudioLoopbackStatus.AVAILABLE_RUNNING) {
    console.info('Audio loopback status is: AVAILABLE_RUNNING');
  }
};

// 查询能力，创建实例。
function init() {
  let isSupported = audio.getAudioManager().getStreamManager().isAudioLoopbackSupported(mode);
  if (isSupported) {
    audio.createAudioLoopback(mode).then((loopback) => {
      console.info('Invoke createAudioLoopback succeeded.');
      audioLoopback = loopback;
    }).catch((err: BusinessError) => {
      console.error(`Invoke createAudioLoopback failed, code is ${err.code}, message is ${err.message}.`);
    });
  } else {
    console.error('Audio loopback is unsupported.');
  }
}

// 设置音频返听音量。
async function setVolume(volume: number) {
  if (audioLoopback !== undefined) {
    try {
      await audioLoopback.setVolume(volume);
      console.info(`Invoke setVolume ${volume} succeeded.`);
    } catch (err) {
      console.error(`Invoke setVolume failed, code is ${err.code}, message is ${err.message}.`);
    }
  } else {
    console.error('Audio loopback not created.');
  }
}

// 设置监听事件，启用音频返听。
async function enable() {
  if (audioLoopback !== undefined) {
    try {
      let status = await audioLoopback.getStatus();
      if (status == audio.AudioLoopbackStatus.AVAILABLE_IDLE) {
        // 注册监听。
        audioLoopback.on('statusChange', statusChangeCallback);
        // 启动返听。
        let success = await audioLoopback.enable(true);
        if (success) {
          console.info('Invoke enable succeeded');
        } else {
          status = await audioLoopback.getStatus();
          statusChangeCallback(status);
        }
      } else {
        statusChangeCallback(status);
      }
    } catch (err) {
      console.error(`Invoke enable failed, code is ${err.code}, message is ${err.message}.`);
    }
  } else {
    console.error('Audio loopback not created.');
  }
}

// 禁用音频返听，关闭监听事件。
async function disable() {
  if (audioLoopback !== undefined) {
    try {
      let status = await audioLoopback.getStatus();
      if (status == audio.AudioLoopbackStatus.AVAILABLE_RUNNING) {
        // 禁用返听。
        let success = await audioLoopback.enable(false);
        if (success) {
          console.info('Invoke disable succeeded');
          // 关闭监听。
          audioLoopback.off('statusChange', statusChangeCallback);
        } else {
          status = await audioLoopback.getStatus();
          statusChangeCallback(status);
        }
      } else {
        statusChangeCallback(status);
      }
    } catch (err) {
      console.error(`Invoke disable failed, code is ${err.code}, message is ${err.message}.`);
    }
  } else {
    console.error('Audio loopback not created.');
  }
}
```
