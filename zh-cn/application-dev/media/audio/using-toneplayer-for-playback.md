# 使用TonePlayer开发音频播放功能(仅对系统应用开放)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--SE: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--TSE: @Filger-->

TonePlayer<sup>9+</sup>提供播放和管理DTMF（Dual Tone Multi Frequency，双音多频）音调的方法，包括各种系统监听音调、专有音调，如拨号音、通话回铃音等。主要工作是将需要生成音调的[ToneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#tonetype9)类型，通过自带算法生成多个不同频率的正弦波叠加形成声音数据，通过[AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md)进行播放，同时对播放任务进行管理。包含加载DTMF音调配置、启动DTMF音调播放、停止当前正在播放的音调、释放与此TonePlayer对象关联的资源等流程。详细API说明请参考[TonePlayer API文档](../../reference/apis-audio-kit/js-apis-audio-sys.md#toneplayer9)。

## 支持的播放音调类型

播放音调类型[ToneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#tonetype9)信息（如下表所示），可通过"audio.ToneType.指定类型" 作为参数调用load()方法加载指定类型的音调资源。

| 播放音调类型 | 值 | 说明 | 
| -------- | -------- | -------- |
| TONE_TYPE_DIAL_0 | 0 | 键0的DTMF音。 | 
| TONE_TYPE_DIAL_1 | 1 | 键1的DTMF音。 | 
| TONE_TYPE_DIAL_2 | 2 | 键2的DTMF音。 | 
| TONE_TYPE_DIAL_3 | 3 | 键3的DTMF音。 | 
| TONE_TYPE_DIAL_4 | 4 | 键4的DTMF音。 | 
| TONE_TYPE_DIAL_5 | 5 | 键5的DTMF音。 | 
| TONE_TYPE_DIAL_6 | 6 | 键6的DTMF音。 | 
| TONE_TYPE_DIAL_7 | 7 | 键7的DTMF音。 | 
| TONE_TYPE_DIAL_8 | 8 | 键8的DTMF音。 | 
| TONE_TYPE_DIAL_9 | 9 | 键9的DTMF音。 | 
| TONE_TYPE_DIAL_S | 10 | 键\*的DTMF音。 | 
| TONE_TYPE_DIAL_P | 11 | 键\#的DTMF音。 | 
| TONE_TYPE_DIAL_A | 12 | 键A的DTMF音。 | 
| TONE_TYPE_DIAL_B | 13 | 键B的DTMF音。 | 
| TONE_TYPE_DIAL_C | 14 | 键C的DTMF音。 | 
| TONE_TYPE_DIAL_D | 15 | 键D的DTMF音。 | 
| TONE_TYPE_COMMON_SUPERVISORY_DIAL | 100 | 呼叫监管音调，拨号音。 | 
| TONE_TYPE_COMMON_SUPERVISORY_BUSY | 101 | 呼叫监管音调，忙。 | 
| TONE_TYPE_COMMON_SUPERVISORY_CONGESTION | 102 | 呼叫监管音调，拥塞。 | 
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK | 103 | 呼叫监管音调，无线电&nbsp;ACK。 | 
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE | 104 | 呼叫监管音调，无线电不可用。 | 
| TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING | 106 | 呼叫监管音调，呼叫等待。 | 
| TONE_TYPE_COMMON_SUPERVISORY_RINGTONE | 107 | 呼叫监管音调，铃声。 | 
| TONE_TYPE_COMMON_SUPERVISORY_CALL_HOLDING<sup>18+</sup> | 108 | 呼叫保持音调。 |
| TONE_TYPE_COMMON_PROPRIETARY_BEEP | 200 | 专有声调，一般蜂鸣声。 | 
| TONE_TYPE_COMMON_PROPRIETARY_ACK | 201 | 专有声调，ACK。 | 
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT | 203 | 专有声调，PROMPT。 | 
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP | 204 | 专有声调，双重蜂鸣声。 | 

## 开发步骤及注意事项

以下步骤描述了TonePlayer接口实现播放功能流程：

1. 创建DTMF播放器 ，获取tonePlayer实例。
     
```ts
import { audio } from '@kit.AudioKit';

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_DTMF, // 音频流使用类型：拨号音。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

async function createTonePlayer() {
  let tonePlayerPromise = await audio.createTonePlayer(audioRendererInfo);
}
```

2. 加载指定类型DTMF音调配置。
     
```ts
async function load() {
  await tonePlayerPromise.load(audio.ToneType.TONE_TYPE_DIAL_0);
}
```

3. 启动DTMF音调播放。
     
```ts
async function start() {
  await tonePlayerPromise.start();
}
```

4. 停止当前正在播放的音调。
     
```ts
async function stop() {
  await tonePlayerPromise.stop();
}
```

5. 释放与此TonePlayer对象关联的资源。
     
```ts
async function release() {
  await tonePlayerPromise.release();
}
```

在接口未按此正常调用时序调用时，接口会返回错误码6800301 NAPI_ERR_SYSTEM。

## 完整示例

参考以下示例，点击键盘拨号按键，并启动对应的DTMF音调播放。

为保证UI线程不被阻塞，大部分TonePlayer调用都是异步的。对于每个API均提供了callback函数和Promise函数，以下示例均采用Promise函数，更多方式可参考API文档[TonePlayer](../../reference/apis-audio-kit/js-apis-audio-sys.md#toneplayer9)。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let timerPro : number;
// promise调用方式
async function testTonePlayerPromise(type: audio.ToneType) {
  console.info('testTonePlayerPromise start');
  if (timerPro) clearTimeout(timerPro);
  let tonePlayerPromise: audio.TonePlayer;
  let audioRendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_DTMF, // 音频流使用类型：拨号音。根据业务场景配置，参考StreamUsage。
    rendererFlags: 0 // 音频渲染器标志。
  };
  timerPro = setTimeout(async () => {
    try {
      console.info('testTonePlayerPromise: createTonePlayer');
      // 创建DTMF播放器。   
      tonePlayerPromise = await audio.createTonePlayer(audioRendererInfo);
      console.info('testTonePlayerPromise: createTonePlayer-success');
      console.info(`testTonePlayerPromise: load type: ${type}`);
      // 加载type类型音调。
      await tonePlayerPromise.load(type);
      console.info('testTonePlayerPromise: load-success');
      console.info(`testTonePlayerPromise: start type: ${type}`);
      // 启动DTMF音调播放。
      await tonePlayerPromise.start();
      console.info('testTonePlayerPromise: start-success');
      console.info(`testTonePlayerPromise: stop type: ${type}`);
      setTimeout(async()=>{
        // 停止当前正在播放的音调。
        await tonePlayerPromise.stop();
        console.info('testTonePlayerPromise: stop-success');
        console.info(`testTonePlayerPromise: release type: ${type}`);
        // 释放与此TonePlayer对象关联的资源。
        await tonePlayerPromise.release();
        console.info('testTonePlayerPromise: release-success');
      }, 30)
    } catch(err) {
      let error = err as BusinessError;
      console.error(`testTonePlayerPromise err : ${error}`);
    }
  }, 200)
};

async function testTonePlayer() {
   testTonePlayerPromise(audio.ToneType.TONE_TYPE_DIAL_0);
}
```
