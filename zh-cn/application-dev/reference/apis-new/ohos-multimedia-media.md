# @ohos.multimedia.media    
媒体子系统为开发者提供一套简单且易于理解的接口，使得开发者能够方便接入系统并使用系统的媒体资源。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import media from '@ohos.multimedia.media'    
```  
    
## createAVPlayer<sup>(9+)</sup>    
异步方式创建音视频播放实例，通过注册回调函数获取返回值。  
 **调用形式：**     
    
- createAVPlayer(callback: AsyncCallback\<AVPlayer>): void    
起始版本： 9    
- createAVPlayer(): Promise\<AVPlayer>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。异步返回AVPlayer实例，失败时返回null。可用于音视频播放。 |  
| Promise<AVPlayer> | Promise对象。异步返回AVPlayer实例，失败时返回null。可用于音视频播放。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400101 | No memory. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let avPlayer: media.AVPlayer;  
media.createAVPlayer((error: BusinessError, video: media.AVPlayer) => {  
  if (video != null) {  
    avPlayer = video;  
    console.info('createAVPlayer success');  
  } else {  
    console.error(`createAVPlayer fail, error message:${error.message}`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let avPlayer: media.AVPlayer;  
media.createAVPlayer().then((video: media.AVPlayer) => {  
  if (video != null) {  
    avPlayer = video;  
    console.info('createAVPlayer success');  
  } else {  
    console.error('createAVPlayer fail');  
  }  
}).catch((error: BusinessError) => {  
  console.error(`AVPlayer catchCallback, error message:${error.message}`);  
});  
    
```    
  
    
## createAVRecorder<sup>(9+)</sup>    
异步方式创建音视频录制实例。通过Promise获取返回值。  
 **调用形式：**     
    
- createAVRecorder(callback: AsyncCallback\<AVRecorder>): void    
起始版本： 9    
- createAVRecorder(): Promise\<AVRecorder>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。异步返回AVRecorder实例，失败时返回null。可用于录制音视频媒体。 |  
| Promise<AVRecorder> | Promise对象。异步返回AVRecorder实例，失败时返回null。可用于录制音视频媒体。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400101 | No memory. Return by promise. |  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
let avRecorder: media.AVRecorder;  
  
media.createAVRecorder().then((recorder: media.AVRecorder) => {  
  if (recorder != null) {  
    avRecorder = recorder;  
    console.info('createAVRecorder success');  
  } else {  
    console.error('createAVRecorder fail');  
  }  
}).catch((error: Error) => {  
  console.error(`createAVRecorder catchCallback, error message:${error.message}`);  
});  
    
```    
  
    
## createAudioPlayer<sup>(deprecated)</sup>    
同步方式创建音频播放实例。  
 **调用形式：**     
- createAudioPlayer(): AudioPlayer  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media#createAVPlayer。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AudioPlayer | 返回AudioPlayer类实例，失败时返回null。可用于音频播放、暂停、停止等操作。 |  
    
 **示例代码：**   
```ts    
let audioPlayer: media.AudioPlayer = media.createAudioPlayer();    
```    
  
    
## createAudioRecorder<sup>(deprecated)</sup>    
创建音频录制的实例来控制音频的录制。 一台设备只允许创建一个录制实例。  
 **调用形式：**     
- createAudioRecorder(): AudioRecorder  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media#createAVRecorder。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AudioRecorder | 返回AudioRecorder类实例，失败时返回null。可用于录制音频媒体。 |  
    
 **示例代码：**   
```ts    
let audioRecorder: media.AudioRecorder = media.createAudioRecorder();    
```    
  
    
## createVideoPlayer<sup>(deprecated)</sup>    
异步方式创建视频播放实例，通过注册回调函数获取返回值。  
 **调用形式：**     
- createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media#createAVPlayer。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<VideoPlayer> | true | 回调函数。异步返回VideoPlayer实例，失败时返回null。可用于管理和播放视频媒体。 |  
    
## createVideoPlayer<sup>(deprecated)</sup>    
异步方式创建视频播放实例，通过Promise获取返回值。  
 **调用形式：**     
- createVideoPlayer(): Promise\<VideoPlayer>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media#createAVPlayer。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<VideoPlayer> | Promise对象。异步返回VideoPlayer实例，失败时返回null。可用于管理和播放视频媒体。 |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let videoPlayer: media.VideoPlayer;  
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {  
  if (video != null) {  
    videoPlayer = video;  
    console.info('video createVideoPlayer success');  
  } else {  
    console.error(`video createVideoPlayer fail, error:${error}`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let videoPlayer: media.VideoPlayer;  
media.createVideoPlayer().then((video: media.VideoPlayer) => {  
  if (video != null) {  
    videoPlayer = video;  
    console.info('video createVideoPlayer success');  
  } else {  
    console.error('video createVideoPlayer fail');  
  }  
}).catch((error: BusinessError) => {  
  console.error(`video catchCallback, error:${error}`);  
});  
    
```    
  
    
## createSoundPool<sup>(10+)</sup>    
创建音频池实例，使用Promise方式异步获取返回值。  
 **调用形式：**     
    
- createSoundPool(     maxStreams: number,     audioRenderInfo: audio.AudioRendererInfo,     callback: AsyncCallback\<SoundPool>   ): void    
起始版本： 10    
- createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo): Promise\<SoundPool>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Media.SoundPool    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| maxStreams | number | true | soundPool实例的最大播放的流数 |  
| audioRenderInfo | audio.AudioRendererInfo | true | 音频播放参数信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。异步返回SoundPool实例，失败时返回null。用于音频池实例的加载播放功能。 |  
| Promise<SoundPool> | Promise对象。异步返回SoundPool实例，失败时返回null。用于音频池实例的加载播放功能。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400101 | No memory. Return by promise. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import audio from '@ohos.multimedia.audio'  
  
let soundPool: media.SoundPool;  
let audioRendererInfo: audio.AudioRendererInfo = {  
  usage : audio.StreamUsage.STREAM_USAGE_MEDIA,  
  rendererFlags : 1  
}  
  
media.createSoundPool(5, audioRendererInfo, (error, soundPool_: media.SoundPool) => {  
  if (error) {  
    console.info(`createSoundPool failed`)  
    return;  
  } else {  
    soundPool = soundPool_;  
    console.info(`createSoundPool success`)  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import audio from '@ohos.multimedia.audio'  
  
let soundPool: media.SoundPool;  
let audioRendererInfo: audio.AudioRendererInfo = {  
  usage : audio.StreamUsage.STREAM_USAGE_MEDIA,  
  rendererFlags : 1  
}  
  
media.createSoundPool(5, audioRendererInfo).then((soundpool_: media.SoundPool) => {  
  if (soundpool_ != null) {  
    soundPool = soundpool_;  
    console.info('create SoundPool success');  
  } else {  
    console.error('create SoundPool fail');  
  }  
}, (error: BusinessError) => {  
  console.error(`soundpool catchCallback, error message:${error.message}`);  
});  
    
```    
  
    
## StateChangeReason<sup>(9+)</sup>    
表示播放或录制实例状态机切换原因的枚举，伴随state一起上报。    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USER | 1 | 表示用户行为造成的状态切换，由用户或客户端主动调用接口产生。 |  
| BACKGROUND | 2 | 表示系统行为造成的状态切换，比如应用未注册播控中心权限，退到后台时被系统强制暂停或停止。 |  
    
## AVErrorCode<sup>(9+)</sup>    
[媒体错误码](../errorcodes/errorcode-media.md)类型枚举    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AVERR_OK | 0 | 表示操作成功。 |  
| AVERR_NO_PERMISSION | 201 | 表示无权限执行此操作。 |  
| AVERR_INVALID_PARAMETER | 401 | 表示传入入参无效。 |  
| AVERR_UNSUPPORT_CAPABILITY | 801 | 表示当前版本不支持该API能力。 |  
| AVERR_NO_MEMORY | 5400101 | 表示系统内存不足或服务数量达到上限。 |  
| AVERR_OPERATE_NOT_PERMIT | 5400102 | 表示当前状态不允许或无权执行此操作。 |  
| AVERR_IO | 5400103 | 表示数据流异常信息。 |  
| AVERR_TIMEOUT | 5400104 | 表示系统或网络响应超时。 |  
| AVERR_SERVICE_DIED | 5400105 | 表示服务进程死亡。 |  
| AVERR_UNSUPPORT_FORMAT | 5400106 | 表示不支持当前媒体资源的格式。 |  
    
## AVPlayerState<sup>(9+)</sup>    
[AVPlayer](#avplayer9)的状态机，可通过state属性主动获取当前状态，也可通过监听[stateChange](#onstatechange9)事件上报当前状态，状态机之间的切换规则，可参考[音频播放开发指导](../../media/using-avplayer-for-playback.md)。  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
    
| 取值范围 | 说明 |  
| --------| --------|  
| idle | 闲置状态，AVPlayer刚被创建[createAVPlayer()](#mediacreateavplayer9)或者调用了reset()方法之后，进入Idle状态。<br/>首次创建createAVPlayer()，所有属性都为默认值。<br/>调用reset()方法，url<sup>9+</sup> 或 fdSrc<sup>9+</sup>或dataSrc<sup>10+</sup>属性及loop属性会被重置，其他用户设置的属性将被保留。 |  
| initialized | 资源初始化，在Idle 状态设置 url<sup>9+</sup> 或 fdSrc<sup>9+</sup>属性，AVPlayer会进入initialized状态，此时可以配置窗口、音频等静态属性。 |  
| prepared | 已准备状态，在initialized状态调用prepare()方法，AVPlayer会进入prepared状态，此时播放引擎的资源已准备就绪。 |  
| playing | 正在播放状态，在prepared/paused/completed状态调用play()方法，AVPlayer会进入playing状态。 |  
| paused | 暂停状态，在playing状态调用pause方法，AVPlayer会进入paused状态 |  
| completed | 播放至结尾状态，当媒体资源播放至结尾时，如果用户未设置循环播放（loop = 1），AVPlayer会进入completed状态，此时调用play()会进入playing状态和重播，调用stop()会进入stopped状态。 |  
| stopped | 停止状态，在prepared/playing/paused/completed状态调用stop()方法，AVPlayer会进入stopped状态，此时播放引擎只会保留属性，但会释放内存资源，可以调用prepare()重新准备，也可以调用reset()重置，或者调用release()彻底销毁。 |  
| released | 销毁状态，销毁与当前AVPlayer关联的播放引擎，无法再进行状态转换，调用release()方法后，会进入released状态，结束流程。 |  
| error | 错误状态，当**播放引擎**发生**不可逆的错误**（详见[媒体错误码](../errorcodes/errorcode-media.md)），则会转换至当前状态，可以调用reset()重置，也可以调用release()销毁重建。<br/>**注意：** 区分error状态和 [on('error')](#onerror9) ：<br/>1、进入error状态时，会触发on('error')监听事件，可以通过on('error')事件获取详细错误信息；<br/>2、处于error状态时，播放服务进入不可播控的状态，要求客户端设计容错机制，使用reset()重置或者release()销毁重建；<br/>3、如果客户端收到on('error')，但未进入error状态：<br/>原因1：客户端未按状态机调用API或传入参数错误，被AVPlayer拦截提醒，需要客户端调整代码逻辑；<br/>原因2：播放过程发现码流问题，导致容器、解码短暂异常，不影响连续播放和播控操作的，不需要客户端设计容错机制。 |  
    
## AVPlayer<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| url<sup>(9+)</sup> | string | false | false | 媒体URL，只允许在**idle**状态下设置，静态属性。<br/>支持的视频格式(mp4、mpeg-ts、webm、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac)。<br/>**支持路径示例**：<br>1. fd类型播放：fd://xx。<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http://xx。<br/>3. https网络播放: https://xx。<br/>4. hls网络播放路径：http://xx或者https://xx。 |  
| fdSrc<sup>(9+)</sup> | AVFileDescriptor | false | false | 媒体文件描述，只允许在**idle**状态下设置，静态属性。<br/>使用场景：应用中的媒体资源被连续存储在同一个文件中。<br/>支持的视频格式(mp4、mpeg-ts、webm、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac)。<br/>**使用示例**：<br/>假设一个连续存储的媒体文件: <br/>视频1(地址偏移:0，字节长度:100)；<br/>视频2(地址偏移:101，字节长度:50)；<br/>视频3(地址偏移:151，字节长度:150)；<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }。<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }。<br/>假设是一个独立的媒体文件: 请使用src=fd://xx。<br/> |  
| dataSrc<sup>(10+)</sup> | AVDataSrcDescriptor | false | false | 流式媒体资源描述，只允许在**idle**状态下设置，静态属性。<br/>使用场景：应用播放从远端下载到本地的文件，在应用未下载完整音视频资源时，提前播放已获取的资源文件。<br/>支持的视频格式(mp4、mpeg-ts、webm、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac)。<br/>**使用示例**：<br/>假设用户正在从远端服务器获取音视频媒体文件，希望下载到本地的同时播放已经下载好的部分: <br/>1.用户需要获取媒体文件的总大小size（单位为字节），获取不到时设置为-1。<br/>2.用户需要实现回调函数func用于填写数据，如果size = -1，则func形式为：func(buffer: ArrayBuffer, length: number)，此时播放器只会按照顺序获取数据；否则func形式为：func(buffer: ArrayBuffer, length: number, pos: number)，播放器会按需跳转并获取数据。<br/>3.用户设置AVDataSrcDescriptor {fileSize = size, callback = func}。<br/>**注意事项**：<br/>如果播放的是mp4/m4a格式用户需要保证moov字段（媒体信息字段）在mdat字段（媒体数据字段）之前，或者moov之前的字段小于10M，否则会导致解析失败无法播放。<br/> |  
| loop<sup>(9+)</sup> | boolean | false | true | 视频循环播放属性，默认'false'，设置为'true'表示循环播放，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>直播场景不支持loop设置。 |  
| audioInterruptMode<sup>(9+)</sup> | audio.InterruptMode | false | false | 音频焦点模型，默认SHARE_MODE，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 |  
| audioRendererInfo<sup>(10+)</sup> | audio.AudioRendererInfo | false | false | 设置音频渲染信息，默认值content为CONTENT_TYPE_MUSIC，usage为STREAM_USAGE_MEDIA，rendererFlags为0。<br/>只允许在**initialized**状态下设置 |  
| audioEffectMode<sup>(10+)</sup> | audio.AudioEffectMode | false | false | 设置音频音效模式，默认值为EFFECT_DEFAULT，动态属性。audioRendererInfo的content和usage变动时会恢复为默认值，只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 |  
| currentTime<sup>(9+)</sup> | number | true | true | 视频的当前播放位置，单位为毫秒（ms），可查询参数。<br/>返回为(-1)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回(-1)。 |  
| duration<sup>(9+)</sup> | number | true | true | 视频时长，单位为毫秒（ms），可查询参数。<br/>返回为(-1)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回(-1)。 |  
| state<sup>(9+)</sup> | AVPlayerState | true | true | 音视频播放的状态，全状态有效，可查询参数。 |  
| surfaceId<sup>(9+)</sup> | string | false | false | 视频窗口ID，默认无窗口，只允许在**initialized**状态下设置，静态属性。<br/>使用场景：视频播放的窗口渲染，纯音频播放不用设置。<br/>**使用示例**：<br/>[通过Xcomponent创建surfaceId](../arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid)。 |  
| width<sup>(9+)</sup> | number | true | true | 视频宽，单位为像素（px），可查询参数。<br/>返回为(0)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 |  
| height<sup>(9+)</sup> | number | true | true | 视频高，单位为像素（px），可查询参数。<br/>返回为(0)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 |  
| videoScaleType<sup>(9+)</sup> | VideoScaleType | false | false | 视频缩放模式，默认VIDEO_SCALE_TYPE_FIT_CROP，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 |  
    
### prepare<sup>(9+)</sup>    
通过回调方式准备播放音频/视频，需在[stateChange](#onstatechange9)事件成功触发至initialized状态后，才能调用。  
 **调用形式：**     
    
- prepare(callback: AsyncCallback\<void>): void    
起始版本： 9    
- prepare(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 准备播放的回调方法。 |  
| Promise<void> | 通过Promise方式准备播放音频/视频，需在[stateChange](#onstatechange9)事件成功触发至initialized状态后，才能调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400106 | Unsupport format. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.prepare((err: BusinessError) => {  
  if (err == null) {  
    console.info('prepare success');  
  } else {  
    console.error('prepare filed,error message is :' + err.message)  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.prepare().then(() => {  
  console.info('prepare success');  
}, (err: BusinessError) => {  
  console.error('prepare filed,error message is :' + err.message)  
})    
```    
  
    
### play<sup>(9+)</sup>    
通过回调方式开始播放音视频资源，只能在prepared/paused/completed状态调用。  
 **调用形式：**     
    
- play(callback: AsyncCallback\<void>): void    
起始版本： 9    
- play(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 开始播放的回调方法。 |  
| Promise<void> | 开始播放的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.play((err: BusinessError) => {  
  if (err == null) {  
    console.info('play success');  
  } else {  
    console.error('play filed,error message is :' + err.message)  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.play().then(() => {  
  console.info('play success');  
}, (err: BusinessError) => {  
  console.error('play filed,error message is :' + err.message)  
})    
```    
  
    
### pause<sup>(9+)</sup>    
通过回调方式暂停播放音视频资源，只能在playing状态调用。  
 **调用形式：**     
    
- pause(callback: AsyncCallback\<void>): void    
起始版本： 9    
- pause(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 暂停播放的回调方法。 |  
| Promise<void> | 暂停播放的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.pause((err: BusinessError) => {  
  if (err == null) {  
    console.info('pause success');  
  } else {  
    console.error('pause filed,error message is :' + err.message)  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.pause().then(() => {  
  console.info('pause success');  
}, (err: BusinessError) => {  
  console.error('pause filed,error message is :' + err.message)  
})    
```    
  
    
### stop<sup>(9+)</sup>    
通过回调方式停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 9    
- stop(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 停止播放的回调方法。 |  
| Promise<void> | 停止播放的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.stop((err: BusinessError) => {  
  if (err == null) {  
    console.info('stop success');  
  } else {  
    console.error('stop filed,error message is :' + err.message)  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.stop().then(() => {  
  console.info('stop success');  
}, (err: BusinessError) => {  
  console.error('stop filed,error message is :' + err.message)  
})    
```    
  
    
### reset<sup>(9+)</sup>    
通过回调方式重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。  
 **调用形式：**     
    
- reset(callback: AsyncCallback\<void>): void    
起始版本： 9    
- reset(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 重置播放的回调方法。 |  
| Promise<void> | 重置播放的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.reset((err: BusinessError) => {  
  if (err == null) {  
    console.info('reset success');  
  } else {  
    console.error('reset filed,error message is :' + err.message)  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.reset().then(() => {  
  console.info('reset success');  
}, (err: BusinessError) => {  
  console.error('reset filed,error message is :' + err.message)  
})    
```    
  
    
### release<sup>(9+)</sup>    
通过回调方式销毁播放资源，除released状态，都可以调用。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 9    
- release(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | | callback | function | 是   | 销毁播放的回调方法。 | |  
| Promise<void> | 通过Promise方式销毁播放，除released状态，都可以调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.release((err: BusinessError) => {  
  if (err == null) {  
    console.info('release success');  
  } else {  
    console.error('release filed,error message is :' + err.message)  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.release().then(() => {  
  console.info('release success');  
}, (err: BusinessError) => {  
  console.error('release filed,error message is :' + err.message)  
})    
```    
  
    
### seek<sup>(9+)</sup>    
跳转到指定播放位置，只能在prepared/playing/paused/completed状态调用，可以通过[seekDone事件](#onseekdone9)确认是否生效。注：直播场景不支持seek。  
 **调用形式：**     
- seek(timeMs: number, mode?: SeekMode): void  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeMs | number | true | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, [duration](#avplayer_duration)]。 |  
| mode | SeekMode | false | 基于视频I帧的跳转模式，默认为SEEK_PREV_SYNC模式，**仅在视频资源播放时设置**。 |  
    
 **示例代码：**   
```ts    
let seekTime: number = 1000  
avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC)    
```    
  
    
### setVolume<sup>(9+)</sup>    
设置媒体播放音量，只能在prepared/playing/paused/completed状态调用，可以通过[volumeChange事件](#onvolumechange9)确认是否生效。  
 **调用形式：**     
- setVolume(volume: number): void  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volume | number | true | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |  
    
 **示例代码：**   
```ts    
let volume: number = 1.0  
avPlayer.setVolume(volume)    
```    
  
    
### getTrackDescription<sup>(9+)</sup>    
通过回调方式获取音视频轨道信息，可以在prepared/playing/paused状态调用。  
 **调用形式：**     
    
- getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void    
起始版本： 9    
- getTrackDescription(): Promise\<Array\<MediaDescription>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 音视频轨道信息MediaDescription数组回调方法。 |  
| Promise<Array<MediaDescription>> | 通过Promise方式获取音视频轨道信息，可以在prepared/playing/paused状态调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {  
  if ((arrList) != null) {  
    console.info('getTrackDescription success');  
  } else {  
    console.log(`video getTrackDescription fail, error:${error}`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {  
  console.info('getTrackDescription success');  
}).catch((error: BusinessError) => {  
  console.info(`video catchCallback, error:${error}`);  
});    
```    
  
    
### setSpeed<sup>(9+)</sup>  
 **调用形式：**     
- setSpeed(speed: PlaybackSpeed): void  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed | PlaybackSpeed | true |  |  
    
### setBitrate<sup>(9+)</sup>  
 **调用形式：**     
- setBitrate(bitrate: number): void  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bitrate | number | true |  |  
    
### on('stateChange')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
```ts    
// 创建avPlayer实例对象  
let avPlayer = await media.createAVPlayer();  
  
avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {  
  switch (state) {  
    case 'idle':  
      console.info('state idle called');  
      break;  
    case 'initialized':  
      console.info('initialized prepared called');  
      break;  
    case 'prepared':  
      console.info('state prepared called');  
      break;  
    case 'playing':  
      console.info('state playing called');  
      break;  
    case 'paused':  
      console.info('state paused called');  
      break;  
    case 'completed':  
      console.info('state completed called');  
      break;  
    case 'stopped':  
      console.info('state stopped called');  
      break;  
    case 'released':  
      console.info('state released called');  
      break;  
    case 'error':  
      console.info('state error called');  
      break;  
    default:  
      console.info('unkown state :' + state);  
      break;  
  }  
})    
```    
  
    
### off('stateChange')  
 **调用形式：**     
- off(type: 'stateChange'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('volumeChange')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'volumeChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('volumeChange', (vol: number) => {  
  console.info('volumeChange success,and new volume is :' + vol)  
})    
```    
  
    
### off('volumeChange')  
 **调用形式：**     
- off(type: 'volumeChange'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('endOfStream')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'endOfStream', callback: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('endOfStream', () => {  
  console.info('endOfStream success')  
})    
```    
  
    
### off('endOfStream')  
 **调用形式：**     
- off(type: 'endOfStream'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('seekDone')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'seekDone', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('seekDone', (seekDoneTime:number) => {  
  console.info('seekDone success,and seek time is:' + seekDoneTime)  
})    
```    
  
    
### off('seekDone')  
 **调用形式：**     
- off(type: 'seekDone'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('speedDone')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'speedDone', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('speedDone', (speed:number) => {  
  console.info('speedDone success,and speed value is:' + speed)  
})    
```    
  
    
### off('speedDone')  
 **调用形式：**     
- off(type: 'speedDone'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('bitrateDone')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'bitrateDone', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('bitrateDone', (bitrate:number) => {  
  console.info('bitrateDone success,and bitrate value is:' + bitrate)  
})    
```    
  
    
### off('bitrateDone')  
 **调用形式：**     
- off(type: 'bitrateDone'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('timeUpdate')<sup>(9+)</sup>    
监听资源播放当前时间，单位为毫秒（ms），用于刷新进度条当前位置，默认间隔1s时间上报，因用户操作(seek)产生的时间变化会立刻上报。 注：直播场景不支持timeUpdate上报  
 **调用形式：**     
    
- on(type: 'timeUpdate', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | <table><tbody><tr><td><br/>时间更新的回调类型，支持的事件：'timeUpdate'</td></tr></tbody></table> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 当前时间 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('timeUpdate', (time:number) => {  
  console.info('timeUpdate success,and new time is :' + time)  
})    
```    
  
    
### off('timeUpdate')  
 **调用形式：**     
- off(type: 'timeUpdate'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('durationUpdate')<sup>(9+)</sup>    
监听资源播放资源的时长，单位为毫秒（ms），用于刷新进度条长度，默认只在prepared上报一次，同时允许一些特殊码流刷新多次时长。 注：直播场景不支持durationUpdate上报  
 **调用形式：**     
    
- on(type: 'durationUpdate', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 时长更新的回调类型，支持的事件：'durationUpdate'<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 资源时长 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('durationUpdate', (duration: number) => {  
  console.info('durationUpdate success,new duration is :' + duration)  
})    
```    
  
    
### off('durationUpdate')  
 **调用形式：**     
- off(type: 'durationUpdate'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('bufferingUpdate')<sup>(9+)</sup>    
订阅音视频缓存更新事件，仅网络播放支持该订阅事件  
 **调用形式：**     
    
- on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 播放缓存事件回调类型，支持的事件：'bufferingUpdate'<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 播放缓存事件回调方法。 BufferingInfoType为BUFFERING_PERCENT或CACHED_DURATION时，value值有效，否则固定为0。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {  
  console.info('bufferingUpdate success,and infoType value is:' + infoType + ', value is :' + value)  
})    
```    
  
    
### off('bufferingUpdate')  
 **调用形式：**     
- off(type: 'bufferingUpdate'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('startRenderFrame')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'startRenderFrame', callback: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 视频播放开始首帧渲染事件回调类型，支持的事件：'startRenderFrame'<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 视频播放开始首帧渲染事件回调方法 |  
    
 **示例代码：**   
订阅视频播放开始首帧渲染的更新事件，仅视频播放支持该订阅事件，该事件仅代表播放服务将第一帧画面送显示模块，实际效果依赖显示服务渲染性能  
  
```ts    
avPlayer.on('startRenderFrame', () => {  
  console.info('startRenderFrame success')  
})    
```    
  
    
### off('startRenderFrame')  
 **调用形式：**     
- off(type: 'startRenderFrame'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('videoSizeChange')<sup>(9+)</sup>    
监听视频播放宽高变化事件，仅视频播放支持该订阅事件，默认只在prepared状态上报一次，但HLS协议码流会在切换分辨率时上报  
 **调用形式：**     
    
- on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChange'<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 视频播放宽高变化事件回调方法，width表示宽，height表示高 |  
    
 **示例代码：**   
```ts    
avPlayer.on('videoSizeChange', (width: number, height: number) => {  
  console.info('videoSizeChange success,and width is:' + width + ', height is :' + height)  
})    
```    
  
    
### off('videoSizeChange')  
 **调用形式：**     
- off(type: 'videoSizeChange'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('audioInterrupt')<sup>(9+)</sup>    
监听音频焦点变化事件，多个音视频资源同时播放时，会根据音频焦点模型audio.InterruptMode触发此事件。  
 **调用形式：**     
    
- on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 音频焦点变化事件回调方法 |  
    
 **示例代码：**   
```ts    
import audio from '@ohos.multimedia.audio';  
  
avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {  
  console.info('audioInterrupt success,and InterruptEvent info is:' + info)  
})    
```    
  
    
### off('audioInterrupt')  
 **调用形式：**     
- off(type: 'audioInterrupt'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('availableBitrates')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'availableBitrates', callback: (bitrates: Array\<number>) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avPlayer.on('availableBitrates', (bitrates: Array<number>) => {  
  console.info('availableBitrates success,and availableBitrates length is:' + bitrates.length)  
})    
```    
  
    
### off('availableBitrates')  
 **调用形式：**     
- off(type: 'availableBitrates'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
### on('error')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 5400101 |  |  
| 5400102 |  |  
| 5400103 |  |  
| 5400104 |  |  
| 5400105 |  |  
| 5400106 |  |  
    
 **示例代码：**   
```ts    
avPlayer.on('error', (error: BusinessError) => {  
  console.error('error happened,and error message is :' + error.message)  
  console.error('error happened,and error code is :' + error.code)  
})    
```    
  
    
### off('error')  
 **调用形式：**     
- off(type: 'error'): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
## MediaErrorCode<sup>(8+)</sup>    
媒体服务错误类型枚举。    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MSERR_OK | 0 | 表示操作成功。 |  
| MSERR_NO_MEMORY | 1 | 表示申请内存失败，系统可能无可用内存。 |  
| MSERR_OPERATION_NOT_PERMIT | 2 | 表示无权限执行此操作。 |  
| MSERR_INVALID_VAL | 3 | 表示传入入参无效。 |  
| MSERR_IO | 4 | 表示发生IO错误。 |  
| MSERR_TIMEOUT | 5 | 表示操作超时。 |  
| MSERR_UNKNOWN | 6 | 表示未知错误。 |  
| MSERR_SERVICE_DIED | 7 | 表示服务端失效。 |  
| MSERR_INVALID_STATE | 8 | 表示在当前状态下，不允许执行此操作。 |  
| MSERR_UNSUPPORTED | 9 | 表示在当前版本下，不支持此操作。 |  
    
## BufferingInfoType<sup>(8+)</sup>    
缓存事件类型枚举。    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BUFFERING_START | 1 | 表示开始缓存。 |  
| BUFFERING_END | 2 | 表示结束缓存。 |  
| BUFFERING_PERCENT | 3 | 表示缓存百分比。 |  
| CACHED_DURATION | 4 | 表示缓存时长，单位为毫秒（ms）。 |  
    
## AVFileDescriptor<sup>(9+)</sup>    
音视频文件资源描述，一种特殊资源的播放方式，使用场景：应用中的音频资源被连续存储在同一个文件中，需要根据偏移量和长度进行播放。  
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fd<sup>(9+)</sup> | number | false | true | 资源句柄，通过[resourceManager.getRawFileDescriptor](js-apis-resource-manager.md#getrawfiledescriptordeprecated)获取。 |  
| offset<sup>(9+)</sup> | number | false | false | 资源偏移量，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |  
| length<sup>(9+)</sup> | number | false | false | 资源长度，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |  
    
## AVDataSrcDescriptor<sup>(10+)</sup>    
音视频文件资源描述，用于DataSource播放方式，使用场景：应用在未获取完整音视频资源时，允许用户创建播放实例并开始播放，达到提前播放的目的。  
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AVPlayer    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fileSize<sup>(10+)</sup> | number | false | true | 待播放文件大小（字节），-1代表大小未知。如果fileSize设置为-1, 播放模式类似于直播，不能进行seek及setSpeed操作，不能设置loop属性，因此不能重新播放。 |  
| callback<sup>(10+)</sup> | (buffer: ArrayBuffer, length: number, pos?: number) => number | false | true | 用户设置的回调函数，用于填写数据。<br>- buffer，ArrayBuffer类型，表示被填写的内存，必选。<br>- length，number类型，表示被填写内存的最大长度，必选。<br>- pos，number类型，表示填写的数据在资源文件中的位置，可选，当fileSize设置为-1时，该参数禁止被使用。 |  
    
## AudioState<sup>(deprecated)</sup>    
音频播放的状态机。可通过state属性获取当前状态。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayerState替代。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
    
| 取值范围 | 说明 |  
| --------| --------|  
| idle | 音频播放空闲，dataload/reset成功后处于此状态。 |  
| playing | 音频正在播放，play成功后处于此状态。 |  
| paused | 音频暂停播放，pause成功后处于此状态。 |  
| stopped | 音频播放停止，stop/播放结束后处于此状态。 |  
| error | 错误状态。 |  
    
## AudioPlayer<sup>(deprecated)</sup>    
音频播放管理类，用于管理和播放音频媒体。在调用AudioPlayer的方法前，需要先通过[createAudioPlayer()](#mediacreateaudioplayerdeprecated)构建一个AudioPlayer实例。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer替代。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#url替代。需要权限：ohos.permission.READ_MEDIA or ohos.permission.INTERNET<br>音频媒体URI，支持当前主流的音频格式(m4a、aac、mp3、ogg、wav)。<br>**支持路径示例**：<br>1. fd类型播放：fd://xx<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http://xx<br/>3. https网络播放: https://xx<br/>4. hls网络播放路径：http://xx或者https://xx <br/>**需要权限：** ohos.permission.READ_MEDIA 或 ohos.permission.INTERNET。 |<br/>| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | 是   | 是   | 音频媒体文件描述，使用场景：应用中的音频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>音乐1(地址偏移:0，字节长度:100)<br/>音乐2(地址偏移:101，字节长度:50)<br/>音乐3(地址偏移:151，字节长度:150)<br/>1. 播放音乐1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放音乐2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放音乐3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的音乐文件: 请使用src=fd://xx <br/><br/> |  
| fdSrc<sup>(deprecated)</sup> | AVFileDescriptor | false | true | 从API version 9 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#fdSrc替代。<br>音频媒体文件描述，使用场景：应用中的音频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>音乐1(地址偏移:0，字节长度:100)<br/>音乐2(地址偏移:101，字节长度:50)<br/>音乐3(地址偏移:151，字节长度:150)<br/>1. 播放音乐1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放音乐2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放音乐3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的音乐文件: 请使用src=fd://xx <br/><br/> |  
| loop<sup>(deprecated)</sup> | boolean | false | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#loop替代。<br>音频循环播放属性，设置为'true'表示循环播放。 |  
| audioInterruptMode<sup>(deprecated)</sup> | audio.InterruptMode | false | false | 从API version 9 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#audioInterruptMode替代。<br>音频焦点模型。 |  
| currentTime<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#currentTime替代。<br>音频的当前播放位置，单位为毫秒（ms）。 |  
| duration<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#duration替代。<br>音频时长，单位为毫秒（ms）。 |  
| state<sup>(deprecated)</sup> | AudioState | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#state替代。<br>可以查询音频播放的状态，该状态不可作为调用play/pause/stop等状态切换的触发条件。 |  
    
### play<sup>(deprecated)</sup>    
开始播放音频资源，需在'dataLoad'事件成功触发后，才能调用。  
 **调用形式：**     
- play(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#play。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **示例代码：**   
```ts    
audioPlayer.on('play', () => {    //设置'play'事件回调  
  console.log('audio play success');  
});  
audioPlayer.play();    
```    
  
    
### pause<sup>(deprecated)</sup>    
暂停播放音频资源。  
 **调用形式：**     
- pause(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#pause。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **示例代码：**   
```ts    
audioPlayer.on('pause', () => {    //设置'pause'事件回调  
  console.log('audio pause success');  
});  
audioPlayer.pause();    
```    
  
    
### stop<sup>(deprecated)</sup>    
停止播放音频资源。  
 **调用形式：**     
- stop(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#stop。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **示例代码：**   
```ts    
audioPlayer.on('stop', () => {    //设置'stop'事件回调  
  console.log('audio stop success');  
});  
audioPlayer.stop();    
```    
  
    
### reset<sup>(deprecated)</sup>    
重置播放音频资源。  
 **调用形式：**     
- reset(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#reset。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **示例代码：**   
```ts    
audioPlayer.on('reset', () => {    //设置'reset'事件回调  
  console.log('audio reset success');  
});  
audioPlayer.reset();    
```    
  
    
### seek<sup>(deprecated)</sup>    
跳转到指定播放位置。  
 **调用形式：**     
- seek(timeMs: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#seek。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeMs<sup>(deprecated)</sup> | number | true | 指定的跳转时间节点，单位毫秒（ms），取值范围[0, duration]。 |  
    
 **示例代码：**   
```ts    
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {    //设置'timeUpdate'事件回调  
  if (seekDoneTime == null) {  
    console.info('audio seek fail');  
    return;  
  }  
  console.log('audio seek success. seekDoneTime: ' + seekDoneTime);  
});  
audioPlayer.seek(30000);    //seek到30000ms的位置    
```    
  
    
### setVolume<sup>(deprecated)</sup>    
设置音量。  
 **调用形式：**     
- setVolume(vol: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#setVolume。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| vol<sup>(deprecated)</sup> | number | true | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |  
    
 **示例代码：**   
```ts    
audioPlayer.on('volumeChange', () => {    //设置'volumeChange'事件回调  
  console.log('audio volumeChange success');  
});  
audioPlayer.setVolume(1);    //设置音量到100%    
```    
  
    
### release<sup>(deprecated)</sup>    
释放音频资源。  
 **调用形式：**     
- release(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#release。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **示例代码：**   
```ts    
audioPlayer.release();  
audioPlayer = undefined;    
```    
  
    
### getTrackDescription<sup>(deprecated)</sup>    
通过回调方式获取音频轨道信息。需在'dataLoad'事件成功触发后，才能调用。  
 **调用形式：**     
- getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#getTrackDescription。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<MediaDescription>> | true | 音频轨道信息MediaDescription数组回调方法。 |  
    
 **示例代码：**   
示例代码（callback）：  
```null    
audioPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {  
  if (arrList != null) {  
    console.log('audio getTrackDescription success');  
  } else {  
    console.log(`audio getTrackDescription fail, error:${error}`);  
  }  
});  
    
```    
  
    
### getTrackDescription<sup>(deprecated)</sup>    
通过Promise方式获取音频轨道信息。需在'dataLoad'事件成功触发后，才能调用。  
 **调用形式：**     
- getTrackDescription(): Promise\<Array\<MediaDescription>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#getTrackDescription。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<MediaDescription>> | 音频轨道信息MediaDescription数组Promise返回值。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
audioPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {  
  console.log('audio getTrackDescription success');  
}).catch((error: BusinessError) => {  
  console.info(`audio catchCallback, error:${error}`);  
});    
```    
  
    
### on('bufferingUpdate')<sup>(deprecated)</sup>    
开始订阅音频缓存更新事件。仅网络播放支持该订阅事件。  
 **调用形式：**     
- on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:bufferingUpdate。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 音频缓存事件回调类型，支持的事件：'bufferingUpdate'。 |  
| callback<sup>(deprecated)</sup> | (infoType: BufferingInfoType, value: number) => void | true | 音频缓存事件回调方法。<br>[BufferingInfoType](#bufferinginfotype8)为BUFFERING_PERCENT或CACHED_DURATION时，value值有效，否则固定为0。 |  
    
 **示例代码：**   
```ts    
audioPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {  
  console.log('audio bufferingInfo type: ' + infoType);  
  console.log('audio bufferingInfo value: ' + value);  
});    
```    
  
    
### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')<sup>(deprecated)</sup>    
开始订阅音频播放事件。  
 **调用形式：**     
- on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:stateChange。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 播放事件回调类型，支持的事件包括：'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange'。<br>- 'play'：完成play()调用，音频开始播放，触发该事件。<br>- 'pause'：完成pause()调用，音频暂停播放，触发该事件。<br>- 'stop'：完成stop()调用，音频停止播放，触发该事件。<br>- 'reset'：完成reset()调用，播放器重置，触发该事件。<br>- 'dataLoad'：完成音频数据加载后触发该事件，即src属性设置完成后触发该事件。<br>- 'finish'：完成音频播放后触发该事件。<br>- 'volumeChange'：完成setVolume()调用，播放音量改变后触发该事件 |  
| callback<sup>(deprecated)</sup> | () => void | true | 播放事件回调方法。 |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let audioPlayer: media.AudioPlayer = media.createAudioPlayer();  //创建一个音频播放实例  
audioPlayer.on('dataLoad', () => {            //设置'dataLoad'事件回调，src属性设置成功后，触发此回调  
  console.info('audio set source success');  
  audioPlayer.play();                       //开始播放，并触发'play'事件回调  
});  
audioPlayer.on('play', () => {                //设置'play'事件回调  
  console.info('audio play success');  
  audioPlayer.seek(30000);                  //调用seek方法，并触发'timeUpdate'事件回调  
});  
audioPlayer.on('pause', () => {               //设置'pause'事件回调  
  console.info('audio pause success');  
  audioPlayer.stop();                       //停止播放，并触发'stop'事件回调  
});  
audioPlayer.on('reset', () => {               //设置'reset'事件回调  
  console.info('audio reset success');  
  audioPlayer.release();                    //释放播放实例资源  
  audioPlayer = undefined;  
});  
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {  //设置'timeUpdate'事件回调  
  if (seekDoneTime == null) {  
    console.info('audio seek fail');  
    return;  
  }  
  console.info('audio seek success, and seek time is ' + seekDoneTime);  
  audioPlayer.setVolume(0.5);                //设置音量为50%，并触发'volumeChange'事件回调  
});  
audioPlayer.on('volumeChange', () => {         //设置'volumeChange'事件回调  
  console.info('audio volumeChange success');  
  audioPlayer.pause();                       //暂停播放，并触发'pause'事件回调  
});  
audioPlayer.on('finish', () => {               //设置'finish'事件回调  
  console.info('audio play finish');  
  audioPlayer.stop();                        //停止播放，并触发'stop'事件回调  
});  
audioPlayer.on('error', (error: BusinessError) => {           //设置'error'事件回调  
  console.error(`audio error called, error: ${error}`);  
});  
  
// 用户选择音频设置fd(本地播放)  
let fdPath = 'fd://';  
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上  
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';  
fs.open(path).then((file) => {  
  fdPath = fdPath + '' + file.fd;  
  console.info('open fd success fd is' + fdPath);  
  audioPlayer.src = fdPath;  //设置src属性，并触发'dataLoad'事件回调  
}, (err: BusinessError) => {  
  console.info('open fd failed err is' + err);  
}).catch((err: BusinessError) => {  
  console.info('open fd failed err is' + err);  
});  
    
```    
  
    
### on('timeUpdate')<sup>(deprecated)</sup>    
监听资源播放当前时间，单位为毫秒（ms），用于刷新进度条当前位置，默认间隔1s时间上报，因用户操作(seek)产生的时间变化会立刻上报。注：直播场景不支持timeUpdate上报。  
 **调用形式：**     
- on(type: 'timeUpdate', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:timeUpdate。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 时间更新的回调类型，支持的事件：'timeUpdate'。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 当前时间。 |  
    
 **示例代码：**   
```ts    
audioPlayer.on('timeUpdate', (newTime: number) => {    //设置'timeUpdate'事件回调  
  if (newTime == null) {  
    console.info('audio timeUpadate fail');  
    return;  
  }  
  console.log('audio timeUpadate success. seekDoneTime: ' + newTime);  
});  
audioPlayer.play();    //开始播放后，自动触发时间戳更新事件    
```    
  
    
### on('audioInterrupt')<sup>(deprecated)</sup>    
监听音频焦点变化事件，多个音视频资源同时播放时，会根据音频焦点模型[audio.InterruptMode](js-apis-audio.md#interruptmode9)触发此事件。  
 **调用形式：**     
- on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:audioInterrupt。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'。 |  
| callback<sup>(deprecated)</sup> | (info: audio.InterruptEvent) => void | true | 音频焦点变化事件回调方法。 |  
    
### on('error')<sup>(deprecated)</sup>    
监听[AVPlayer](#avplayer9)的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVPlayerState](#avplayerstate9)也切至error状态，用户需要通过reset()或者release()退出播放操作。  
 **调用形式：**     
- on(type: 'error', callback: ErrorCallback): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:error。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |  
| callback<sup>(deprecated)</sup> | ErrorCallback | true | 错误事件回调方法：使用播放器的过程中发生错误，会提供错误码ID和错误信息。 |  
    
 **示例代码：**   
```ts    
audioPlayer.on('error', (error: BusinessError) => {      //设置'error'事件回调  
  console.error(`audio error called, error: ${error}`);   
});  
audioPlayer.setVolume(3);  //设置volume为无效值，触发'error'事件    
```    
  
    
## AVRecorderState<sup>(9+)</sup>    
音视频录制的状态机。可通过state属性获取当前状态。  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
    
| 取值范围 | 说明 |  
| --------| --------|  
| idle | 闲置状态。此时可以调用[AVRecorder.prepare()](#prepare9-2)方法设置录制参数，进入prepared状态。AVRecorder刚被创建，或者在任何非released状态下调用[AVRecorder.reset()](#reset9-2)方法，均进入idle状态。 |  
| prepared | 参数设置完成。此时可以调用[AVRecorder.start()](#start9)方法开始录制，进入started状态。 |  
| started | 正在录制。此时可以调用[AVRecorder.pause()](#pause9-2)方法暂停录制，进入paused状态。也可以调用[AVRecorder.stop()](#stop9-2)方法结束录制，进入stopped状态。 |  
| paused | 录制暂停。此时可以调用[AVRecorder.resume()](#resume9)方法继续录制，进入started状态。也可以调用[AVRecorder.stop()](#stop9-2)方法结束录制，进入stopped状态。 |  
| stopped | 录制停止。此时可以调用[AVRecorder.prepare()](#prepare9-2)方法设置录制参数，重新进入prepared状态。 |  
| released | 录制资源释放。此时不能再进行任何操作。在任何其他状态下，均可以通过调用[AVRecorder.release()](#release9-2)方法进入released状态。 |  
| error | 错误状态。当AVRecorder实例发生不可逆错误，会转换至当前状态。切换至error状态时会伴随[AVRecorder.on('error')事件](#onerror9-1)，该事件会上报详细错误原因。在error状态时，用户需要调用[AVRecorder.reset()](#reset9-2)方法重置AVRecorder实例，或者调用[AVRecorder.release()](#release9-2)方法释放资源。 |  
    
## AVRecorder<sup>(9+)</sup>    
音视频录制管理类，用于音视频媒体录制。在调用AVRecorder的方法前，需要先通过createAVRecorder()构建一个AVRecorder实例。  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| state<sup>(9+)</sup> | AVRecorderState | true | true |  |  
    
### prepare<sup>(9+)</sup>    
异步方式进行音视频录制的参数设置。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void    
起始版本： 9    
- prepare(config: AVRecorderConfig): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder  
 **需要权限：** ohos.permission.MICROPHONE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | AVRecorderConfig | true | 配置音视频录制的相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步音视频录制prepare方法的回调方法。 |  
| Promise<void> | 异步音视频录制prepare方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. Return by callback. |  
| 401 | Parameter error. Return by callback. |  
| 5400102 | Operate not permit. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// 配置参数以实际硬件设备支持的范围为准  
let avRecorderProfile: media.AVRecorderProfile = {  
  audioBitrate : 48000,  
  audioChannels : 2,  
  audioCodec : media.CodecMimeType.AUDIO_AAC,  
  audioSampleRate : 48000,  
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,  
  videoBitrate : 2000000,  
  videoCodec : media.CodecMimeType.VIDEO_MPEG4,  
  videoFrameWidth : 640,  
  videoFrameHeight : 480,  
  videoFrameRate : 30  
}  
let avRecorderConfig: media.AVRecorderConfig = {  
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,  
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,  
  profile : avRecorderProfile,  
  url : 'fd://', // 文件需先由调用者创建，赋予读写权限，将文件fd传给此参数，eg.fd://45  
  rotation : 0, // 合理值0、90、180、270，非合理值prepare接口将报错  
  location : { latitude : 30, longitude : 130 }  
}  
  
avRecorder.prepare(avRecorderConfig, (err: BusinessError) => {  
  if (err == null) {  
    console.info('prepare success');  
  } else {  
    console.error('prepare failed and error is ' + err.message);  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码(promise)：  
```ts    
// 配置参数以实际硬件设备支持的范围为准  
let avRecorderProfile: media.AVRecorderProfile = {  
  audioBitrate : 48000,  
  audioChannels : 2,  
  audioCodec : media.CodecMimeType.AUDIO_AAC,  
  audioSampleRate : 48000,  
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,  
  videoBitrate : 2000000,  
  videoCodec : media.CodecMimeType.VIDEO_MPEG4,  
  videoFrameWidth : 640,  
  videoFrameHeight : 480,  
  videoFrameRate : 30  
}  
let avRecorderConfig: media.AVRecorderConfig = {  
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,  
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,  
  profile : avRecorderProfile,  
  url : 'fd://',  // 文件需先由调用者创建，赋予读写权限，将文件fd传给此参数，eg.fd://45  
  rotation : 0, // 合理值0、90、180、270，非合理值prepare接口报错  
  location : { latitude : 30, longitude : 130 }  
}  
  
avRecorder.prepare(avRecorderConfig).then(() => {  
  console.info('prepare success');  
}).catch((err: Error) => {  
  console.error('prepare failed and catch error is ' + err.message);  
});    
```    
  
    
### getInputSurface<sup>(9+)</sup>    
异步方式获得录制需要的surface。此surface提供给调用者，调用者从此surface中获取surfaceBuffer，填入相应的视频数据。  
 **调用形式：**     
    
- getInputSurface(callback: AsyncCallback\<string>): void    
起始版本： 9    
- getInputSurface(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获得surface的回调方法。 |  
| Promise<string> | 异步获得surface的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operate not permit. Return by callback. |  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
let surfaceID: string; // 该surfaceID用于传递给相机接口创造videoOutput  
  
avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {  
  if (err == null) {  
    console.info('getInputSurface success');  
    surfaceID = surfaceId;  
  } else {  
    console.error('getInputSurface failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
let surfaceID: string; // 该surfaceID用于传递给相机接口创造videoOutput  
  
avRecorder.getInputSurface().then((surfaceId: string) => {  
  console.info('getInputSurface success');  
  surfaceID = surfaceId;  
}).catch((err: Error) => {  
  console.error('getInputSurface failed and catch error is ' + err.message);  
});    
```    
  
    
### start<sup>(9+)</sup>    
异步方式开始视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- start(callback: AsyncCallback\<void>): void    
起始版本： 9    
- start(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步开始视频录制的回调方法。 |  
| Promise<void> | 异步开始视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operate not permit. Return by callback. |  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avRecorder.start((err: BusinessError) => {  
  if (err == null) {  
    console.info('start AVRecorder success');  
  } else {  
    console.error('start AVRecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avRecorder.start().then(() => {  
  console.info('start AVRecorder success');  
}).catch((err: Error) => {  
  console.error('start AVRecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### pause<sup>(9+)</sup>    
异步方式暂停视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- pause(callback: AsyncCallback\<void>): void    
起始版本： 9    
- pause(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获得surface的回调方法。 |  
| Promise<void> | 异步暂停视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operate not permit. Return by callback. |  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avRecorder.pause((err: BusinessError) => {  
  if (err == null) {  
    console.info('pause AVRecorder success');  
  } else {  
    console.error('pause AVRecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avRecorder.pause().then(() => {  
  console.info('pause AVRecorder success');  
}).catch((err: Error) => {  
  console.error('pause AVRecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### resume<sup>(9+)</sup>    
异步方式恢复视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- resume(callback: AsyncCallback\<void>): void    
起始版本： 9    
- resume(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步恢复视频录制的回调方法。 |  
| Promise<void> | 异步恢复视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operate not permit. Return by callback. |  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avRecorder.resume((err: BusinessError) => {  
  if (err == null) {  
    console.info('resume AVRecorder success');  
  } else {  
    console.error('resume AVRecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avRecorder.resume().then(() => {  
  console.info('resume AVRecorder success');  
}).catch((err: Error) => {  
  console.error('resume AVRecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### stop<sup>(9+)</sup>    
异步方式停止视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 9    
- stop(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步停止视频录制的回调方法。 |  
| Promise<void> | 异步停止视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operate not permit. Return by callback. |  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avRecorder.stop((err: BusinessError) => {  
  if (err == null) {  
    console.info('stop AVRecorder success');  
  } else {  
    console.error('stop AVRecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avRecorder.stop().then(() => {  
  console.info('stop AVRecorder success');  
}).catch((err: Error) => {  
  console.error('stop AVRecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### reset<sup>(9+)</sup>    
异步方式重置音视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- reset(callback: AsyncCallback\<void>): void    
起始版本： 9    
- reset(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步重置音视频录制的回调方法。 |  
| Promise<void> | 异步重置音视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avRecorder.reset((err: BusinessError) => {  
  if (err == null) {  
    console.info('reset AVRecorder success');  
  } else {  
    console.error('reset AVRecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avRecorder.reset().then(() => {  
  console.info('reset AVRecorder success');  
}).catch((err: Error) => {  
  console.error('reset AVRecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### release<sup>(9+)</sup>    
异步方式释放音视频录制资源。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 9    
- release(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步释放音视频录制资源的回调方法。 |  
| Promise<void> | 异步释放音视频录制资源方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
avRecorder.release((err: BusinessError) => {  
  if (err == null) {  
    console.info('release AVRecorder success');  
  } else {  
    console.error('release AVRecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
avRecorder.release().then(() => {  
  console.info('release AVRecorder success');  
}).catch((err: Error) => {  
  console.error('release AVRecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### on('stateChange')<sup>(9+)</sup>    
订阅录制状态机AVRecorderState切换的事件，当 AVRecorderState状态机发生变化时，会通过订阅的回调方法通知用户。用户只能订阅一个状态机切换事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。  
 **调用形式：**     
    
- on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态机切换事件回调方法：<br>state: [AVRecorderState](#avrecorderstate9)，表示当前播放状态 ；<br>reason: [StateChangeReason](#statechangereason9)，表示当前播放状态的切换原因。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400103 | IO error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">avRecorder.on('stateChange', async (state: media.AVRecorderState, reason: media.StateChangeReason) => {</span>  
  console.info('case state has changed, new state is :' + state + ',and new reason is : ' + reason);  
});    
```    
  
    
### on('error')<sup>(9+)</sup>    
订阅AVRecorder的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVRecorderState](#avrecorderstate9)也切至error状态，用户需要通过reset()或者release()退出录制操作。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 录制错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 录制错误事件回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 5400101 | No memory. Return by callback. |  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400103 | I/O error. Return by callback. |  
| 5400104 | Time out. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
| 5400106 | Unsupport format. Return by callback. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
avRecorder.on('error', (err: BusinessError) => {  
  console.error('case avRecorder.on(error) called, errMessage is ' + err.message);  
});    
```    
  
    
### off('stateChange')<sup>(9+)</sup>    
取消订阅播放状态机。  
 **调用形式：**     
- off(type: 'stateChange'): void  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |  
    
 **示例代码：**   
```ts    
avRecorder.off('stateChange');    
```    
  
    
### off('error')<sup>(9+)</sup>    
取消订阅录制错误事件，取消后不再接收到AVRecorder的错误事件。  
 **调用形式：**     
- off(type: 'error'): void  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 录制错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |  
    
 **示例代码：**   
```ts    
avRecorder.off('error');    
```    
  
    
## AudioEncoder<sup>(deprecated)</sup>    
表示音频编码格式的枚举。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.multimedia.media/media.CodecMimeType替代。    
    
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT<sup>(deprecated)</sup> | 0 | 从API version 6 开始支持，从API version 8 开始废弃。<br>默认编码格式 |  
| AMR_NB<sup>(deprecated)</sup> | 1 | 从API version 6 开始支持，从API version 8 开始废弃。<br>AMR-NB(Adaptive Multi Rate-Narrow Band Speech Codec) 编码格式 |  
| AMR_WB<sup>(deprecated)</sup> | 2 | 从API version 6 开始支持，从API version 8 开始废弃。<br>AMR-WB(Adaptive Multi Rate-Wide Band Speech Codec) 编码格式。 |  
| AAC_LC<sup>(deprecated)</sup> | 3 | 从API version 6 开始支持，从API version 8 开始废弃。<br>AAC-LC（AdvancedAudioCodingLowComplexity）编码格式 |  
| HE_AAC<sup>(deprecated)</sup> | 4 | 从API version 6 开始支持，从API version 8 开始废弃。<br>HE_AAC（High-Efficiency AdvancedAudioCoding）编码格式 |  
    
## AudioOutputFormat<sup>(deprecated)</sup>    
表示音频封装格式的枚举。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.multimedia.media/media.ContainerFormatType替代。    
    
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT<sup>(deprecated)</sup> | 0 | 从API version 6 开始支持，从API version 8 开始废弃。<br>默认封装格式。<br/>仅做接口定义，暂不支持使用。 |  
| MPEG_4<sup>(deprecated)</sup> | 2 | 从API version 6 开始支持，从API version 8 开始废弃。<br>封装为MPEG-4格式。 |  
| AMR_NB<sup>(deprecated)</sup> | 3 | 从API version 6 开始支持，从API version 8 开始废弃。<br>封装为AMR_NB格式 |  
| AMR_WB<sup>(deprecated)</sup> | 4 | 从API version 6 开始支持，从API version 8 开始废弃。<br>封装为AMR_WB格式 |  
| AAC_ADTS<sup>(deprecated)</sup> | 6 | 从API version 6 开始支持，从API version 8 开始废弃。<br>封装为ADTS |  
    
## Location    
视频录制的地理位置。  
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | true | 地理位置的纬度。 |  
| longitude | number | false | true | 地理位置的经度。 |  
    
## AudioRecorderConfig<sup>(deprecated)</sup>    
表示音频的录音配置。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVRecorderConfig替代。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioEncoder<sup>(deprecated)</sup> | AudioEncoder | false | false | 从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.multimedia.media/media.AudioRecorderConfig.audioEncoderMime替代。<br>音频编码格式，默认设置为AAC_LC |  
| audioEncodeBitRate<sup>(deprecated)</sup> | number | false | false | 从API version 6 开始支持，从API version 9 开始废弃。<br>音频编码比特率，默认值为48000。 |  
| audioSampleRate<sup>(deprecated)</sup> | number | false | false | 从API version 6 开始支持，从API version 9 开始废弃。<br>音频采集采样率，默认值为48000。 |  
| numberOfChannels<sup>(deprecated)</sup> | number | false | false | 从API version 6 开始支持，从API version 9 开始废弃。<br>音频采集声道数，默认值为2。 |  
| format<sup>(deprecated)</sup> | AudioOutputFormat | false | false | 从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.multimedia.media/media.AudioRecorderConfig.fileFormat替代。<br>音频输出封装格式，默认设置为MPEG_4。 |  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>音频输出URI：fd |  
| location<sup>(deprecated)</sup> | Location | false | false | 从API version 6 开始支持，从API version 9 开始废弃。<br>音频采集的地理位置。 |  
| audioEncoderMime<sup>(deprecated)</sup> | CodecMimeType | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>音频编码格式。 |  
| fileFormat<sup>(deprecated)</sup> | ContainerFormatType | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>音频编码格式。 |  
    
## AudioRecorder<sup>(deprecated)</sup>    
音频录制管理类，用于录制音频媒体。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVRecorder替代。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
### prepare<sup>(deprecated)</sup>    
录音准备。  
 **调用形式：**     
- prepare(config: AudioRecorderConfig): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#prepare。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder  
 **需要权限：** ohos.permission.MICROPHONE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | AudioRecorderConfig | true | 配置录音的相关参数，包括音频输出URI、编码格式、采样率、声道数、输出格式等。 |  
    
 **示例代码：**   
```ts    
let audioRecorderConfig: media.AudioRecorderConfig = {  
  audioEncoder : media.AudioEncoder.AAC_LC,  
  audioEncodeBitRate : 22050,  
  audioSampleRate : 22050,  
  numberOfChannels : 2,  
  format : media.AudioOutputFormat.AAC_ADTS,  
  uri : 'fd://1',       // 文件需先由调用者创建，并给予适当的权限  
  location : { latitude : 30, longitude : 130},  
}  
audioRecorder.on('prepare', () => {    //设置'prepare'事件回调  
  console.log('prepare success');  
});  
audioRecorder.prepare(audioRecorderConfig);    
```    
  
    
### start<sup>(deprecated)</sup>    
开始录制，需在'prepare'事件成功触发后，才能调用start方法。  
 **调用形式：**     
- start(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#start。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **示例代码：**   
```ts    
audioRecorder.on('start', () => {    //设置'start'事件回调  
  console.log('audio recorder start success');  
});  
audioRecorder.start();    
```    
  
    
### pause<sup>(deprecated)</sup>    
暂停录制，需要在'start'事件成功触发后，才能调用pause方法。  
 **调用形式：**     
- pause(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#pause。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **示例代码：**   
```ts    
audioRecorder.on('pause', () => {    //设置'pause'事件回调  
  console.log('audio recorder pause success');  
});  
audioRecorder.pause();    
```    
  
    
### resume<sup>(deprecated)</sup>    
恢复录制，需要在'pause'事件成功触发后，才能调用resume方法。  
 **调用形式：**     
- resume(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#resume。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **示例代码：**   
```ts    
audioRecorder.on('resume', () => {    //设置'resume'事件回调  
  console.log('audio recorder resume success');  
});  
audioRecorder.resume();    
```    
  
    
### stop<sup>(deprecated)</sup>    
停止录音。  
 **调用形式：**     
- stop(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#stop。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **示例代码：**   
```ts    
audioRecorder.on('stop', () => {    //设置'stop'事件回调  
  console.log('audio recorder stop success');  
});  
audioRecorder.stop();    
```    
  
    
### release<sup>(deprecated)</sup>    
释放录音资源。  
 **调用形式：**     
- release(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#release。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **示例代码：**   
```ts    
audioRecorder.on('release', () => {    //设置'release'事件回调  
  console.log('audio recorder release success');  
});  
audioRecorder.release();  
audioRecorder = undefined;    
```    
  
    
### reset<sup>(deprecated)</sup>    
重置录音。  
 **调用形式：**     
- reset(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#reset。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **示例代码：**   
```ts    
audioRecorder.on('reset', () => {    //设置'reset'事件回调  
  console.log('audio recorder reset success');  
});  
audioRecorder.reset();    
```    
  
    
### on('prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset')<sup>(deprecated)</sup>    
重置录音。  
 **调用形式：**     
- on(type: 'prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset', callback: () => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#on。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 录制事件回调类型 |  
| callback<sup>(deprecated)</sup> | () => void | true | 录制事件回调方法。 |  
    
 **示例代码：**   
```ts    
let audioRecorder: media.AudioRecorder = media.createAudioRecorder();                                  // 创建一个音频录制实例  
let audioRecorderConfig: media.AudioRecorderConfig = {  
  audioEncoder : media.AudioEncoder.AAC_LC,  
  audioEncodeBitRate : 22050,  
  audioSampleRate : 22050,  
  numberOfChannels : 2,  
  format : media.AudioOutputFormat.AAC_ADTS,  
  uri : 'fd://xx',                                                            // 文件需先由调用者创建，并给予适当的权限  
  location : { latitude : 30, longitude : 130},  
}  
audioRecorder.on('error', (error: BusinessError) => {                                             // 设置'error'事件回调  
  console.info(`audio error called, error: ${error}`);  
});  
audioRecorder.on('prepare', () => {                                              // 设置'prepare'事件回调  
  console.log('prepare success');  
  audioRecorder.start();                                                       // 开始录制，并触发'start'事件回调  
});  
audioRecorder.on('start', () => {                                                 // 设置'start'事件回调  
  console.log('audio recorder start success');  
});  
audioRecorder.on('pause', () => {                                                 // 设置'pause'事件回调  
  console.log('audio recorder pause success');  
});  
audioRecorder.on('resume', () => {                                                 // 设置'resume'事件回调  
  console.log('audio recorder resume success');  
});  
audioRecorder.on('stop', () => {                                                 // 设置'stop'事件回调  
  console.log('audio recorder stop success');  
});  
audioRecorder.on('release', () => {                                                 // 设置'release'事件回调  
  console.log('audio recorder release success');  
});  
audioRecorder.on('reset', () => {                                                 // 设置'reset'事件回调  
  console.log('audio recorder reset success');  
});  
audioRecorder.prepare(audioRecorderConfig)                                        // 设置录制参数 ，并触发'prepare'事件回调          
```    
  
    
### on('error')<sup>(deprecated)</sup>    
开始订阅音频录制错误事件，当上报error错误事件后，用户需处理error事件，退出录制操作。  
 **调用形式：**     
- on(type: 'error', callback: ErrorCallback): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVRecorder#on。  
 **系统能力:**  SystemCapability.Multimedia.Media.AudioRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 录制错误事件回调类型'error'。 |  
| callback<sup>(deprecated)</sup> | ErrorCallback | true | 录制错误事件回调方法。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let audioRecorderConfig: media.AudioRecorderConfig = {  
  audioEncoder : media.AudioEncoder.AAC_LC,  
  audioEncodeBitRate : 22050,  
  audioSampleRate : 22050,  
  numberOfChannels : 2,  
  format : media.AudioOutputFormat.AAC_ADTS,  
  uri : 'fd://xx',                                                     // 文件需先由调用者创建，并给予适当的权限  
  location : { latitude : 30, longitude : 130},  
}  
audioRecorder.on('error', (error: Error) => {                                  // 设置'error'事件回调  
  console.error(`audio error called, error: ${error}`);  
});  
audioRecorder.prepare(audioRecorderConfig);                            // prepare不设置参数，触发'error'事件    
```    
  
    
## VideoPlayState<sup>(deprecated)</sup>    
视频录制的状态机。可通过state属性获取当前状态。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayerState替代。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
    
| 取值范围 | 说明 |  
| --------| --------|  
| idle | 视频录制空闲。 |  
| prepared | 视频录制参数设置完成。 |  
| playing | 视频正在录制。 |  
| paused | 视频暂停录制。 |  
| stopped | 视频录制停止。 |  
| error | 错误状态。 |  
    
## PlaybackSpeed<sup>(8+)</sup>    
视频播放的倍速枚举，可通过setSpeed方法作为参数传递下去。    
    
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SPEED_FORWARD_0_75_X | 0 | 表示视频播放正常播速的0.75倍。<br/> |  
| SPEED_FORWARD_1_00_X | 1 | 表示视频播放正常播速。<br/> |  
| SPEED_FORWARD_1_25_X | 2 | 表示视频播放正常播速的1.25倍。<br/> |  
| SPEED_FORWARD_1_75_X | 3 | 表示视频播放正常播速的1.75倍。<br/> |  
| SPEED_FORWARD_2_00_X | 4 | 表示视频播放正常播速的2.00倍。<br/> |  
    
## VideoPlayer<sup>(deprecated)</sup>    
视频播放管理类，用于管理和播放视频媒体。在调用VideoPlayer的方法前，需要先通过<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-media.md#mediacreatevideoplayerdeprecated">createVideoPlayer()</a>构建一个VideoPlayer实例。<h3>  
</h3>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer替代。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| url<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#url替代。<br>视频媒体URL，支持当前主流的视频格式(mp4、mpeg-ts、webm、mkv)。<br/><strong>支持路径示例</strong>：<br/>1. fd类型播放：fd://xx<br/><img src="https://gitee.com/openharmony/docs/raw/master/zh-cn/application-dev/reference/apis/figures/zh-cn_image_url.png" alt=""/><br/>2. http网络播放:<a href="https://gitee.com/link?target=http%3A%2F%2Fxx">http://xx</a><br/>3. https网络播放:<a href="https://gitee.com/link?target=https%3A%2F%2Fxx">https://xx</a><br/>4. hls网络播放路径：<a href="https://gitee.com/link?target=http%3A%2F%2Fxx%25E6%2588%2596%25E8%2580%2585https%3A%2F%2Fxx">http://xx或者https://xx</a><br/> |  
| fdSrc<sup>(deprecated)</sup> | AVFileDescriptor | false | true | 从API version 9 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#fdSrc替代。<br>视频媒体文件描述，使用场景：应用中的视频资源被连续存储在同一个文件中。<br/>使用示例：<br/>假设一个连续存储的音乐文件:<br/>视频1(地址偏移:0，字节长度:100)<br/>视频2(地址偏移:101，字节长度:50)<br/>视频3(地址偏移:151，字节长度:150)<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的视频文件: 请使用src=fd://xx<br/> |  
| loop<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#loop替代。<br>视频循环播放属性，设置为'true'表示循环播放。<br/> |  
| currentTime<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#currentTime替代。<br>视频的当前播放位置，单位为毫秒（ms）<br/> |  
| duration<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#duration替代。<br>视频时长，单位为毫秒（ms），返回-1表示直播模式<br/> |  
| state<sup>(deprecated)</sup> | VideoPlayState | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#state替代。<br>视频播放的状态<br/> |  
| width<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#width替代。<br>视频宽，单位为像素（px）<br/> |  
| height<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#height替代。<br>视频高，单位为像素（px）<br/> |  
| audioInterruptMode<sup>(deprecated)</sup> | audio.InterruptMode | false | false | 从API version 9 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#audioInterruptMode替代。<br>音频焦点模型。<br/> |  
| videoScaleType<sup>(deprecated)</sup> | VideoScaleType | false | false | 从API version 9 开始支持，从API version 9 开始废弃。建议使用ohos.multimedia.media/media.AVPlayer#videoScaleType替代。<br>视频缩放模式。 |  
    
### setDisplaySurface<sup>(deprecated)</sup>    
通过回调方式设置SurfaceId。  
  
 **调用形式：**     
- setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#surfaceId。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| surfaceId<sup>(deprecated)</sup> | string | true | SurfaceId<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设置SurfaceId的回调方法<br/> |  
    
### setDisplaySurface<sup>(deprecated)</sup>    
通过Promise方式设置SurfaceId。  
  
 **调用形式：**     
- setDisplaySurface(surfaceId: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#surfaceId。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| surfaceId<sup>(deprecated)</sup> | string | true | SurfaceId<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 设置SurfaceId的Promise返回值。 |  
    
### prepare<sup>(deprecated)</sup>    
通过回调方式准备播放视频。  
  
 **调用形式：**     
- prepare(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#prepare。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 准备播放视频的回调方法。<br/> |  
    
### prepare<sup>(deprecated)</sup>    
通过Promise方式准备播放视频。  
  
 **调用形式：**     
- prepare(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#prepare。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 准备播放视频的Promise返回值。 |  
    
### play<sup>(deprecated)</sup>    
通过回调方式开始播放视频。  
 **调用形式：**     
- play(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#play。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 开始播放视频的回调方法。<br/> |  
    
### play<sup>(deprecated)</sup>    
通过Promise方式开始播放视频。  
 **调用形式：**     
- play(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#play。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 开始播放视频的Promise返回值。 |  
    
### pause<sup>(deprecated)</sup>    
通过回调方式暂停播放视频。  
 **调用形式：**     
- pause(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#pause。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 暂停播放视频的回调方法<br/> |  
    
### pause<sup>(deprecated)</sup>    
通过Promise方式暂停播放视频。  
 **调用形式：**     
- pause(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#pause。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 暂停播放视频的Promise返回值 |  
    
### stop<sup>(deprecated)</sup>    
通过回调方式停止播放视频。  
 **调用形式：**     
- stop(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#stop。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 停止播放视频的回调方法。<br/> |  
    
### stop<sup>(deprecated)</sup>    
通过Promise方式停止播放视频。  
 **调用形式：**     
- stop(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#stop。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 停止播放视频的Promise返回值。 |  
    
### reset<sup>(deprecated)</sup>    
通过回调方式重置播放视频。  
 **调用形式：**     
- reset(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#reset。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 切换播放视频的回调方法。<br/> |  
    
### reset<sup>(deprecated)</sup>    
通过Promise方式重置播放视频。  
 **调用形式：**     
- reset(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#reset。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 切换播放视频的Promise返回值 |  
    
### seek<sup>(deprecated)</sup>    
通过回调方式跳转到指定播放位置，默认跳转到指定时间点的上一个关键帧。  
 **调用形式：**     
- seek(timeMs: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#seek。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeMs<sup>(deprecated)</sup> | number | true | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 跳转到指定播放位置的回调方法。<br/> |  
    
### seek<sup>(deprecated)</sup>    
通过回调方式跳转到指定播放位置。  
 **调用形式：**     
- seek(timeMs: number, mode: SeekMode, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#seek。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeMs<sup>(deprecated)</sup> | number | true | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]<br/> |  
| mode<sup>(deprecated)</sup> | SeekMode | true | 跳转模式。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 跳转到指定播放位置的回调方法<br/> |  
    
### seek<sup>(deprecated)</sup>    
通过Promise方式跳转到指定播放位置，如果没有设置mode则跳转到指定时间点的上一个关键帧。  
 **调用形式：**     
- seek(timeMs: number, mode?: SeekMode): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#seek。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeMs<sup>(deprecated)</sup> | number | true | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]<br/> |  
| mode<sup>(deprecated)</sup> | SeekMode | false | 基于视频I帧的跳转模式，默认为SEEK_PREV_SYNC模式。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 跳转到指定播放位置的Promise返回值，单位ms。 |  
    
### setVolume<sup>(deprecated)</sup>    
通过回调方式设置音量。  
 **调用形式：**     
- setVolume(vol: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#setVolume。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| vol<sup>(deprecated)</sup> | number | true | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 设置音量的回调方法。<br/> |  
    
### setVolume<sup>(deprecated)</sup>    
通过Promise方式设置音量。  
 **调用形式：**     
- setVolume(vol: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#setVolume。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| vol<sup>(deprecated)</sup> | number | true | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 设置音量的Promise返回值 |  
    
### release<sup>(deprecated)</sup>    
通过回调方式释放视频资源。  
 **调用形式：**     
- release(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#release。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 释放视频资源的回调方法<br/> |  
    
### release<sup>(deprecated)</sup>    
通过Promise方式释放视频资源。  
 **调用形式：**     
- release(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#release。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 释放视频资源的Promise返回值 |  
    
### getTrackDescription<sup>(deprecated)</sup>    
通过回调方式获取视频轨道信息。  
 **调用形式：**     
- getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#getTrackDescription。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<MediaDescription>> | true | 视频轨道信息MediaDescription数组回调方法<br/> |  
    
### getTrackDescription<sup>(deprecated)</sup>    
通过Promise方式获取视频轨道信息。  
 **调用形式：**     
- getTrackDescription(): Promise\<Array\<MediaDescription>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#getTrackDescription。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<MediaDescription>> | 视频轨道信息MediaDescription数组Promise返回值 |  
    
### setSpeed<sup>(deprecated)</sup>    
通过回调方式设置播放速度。  
  
 **调用形式：**     
- setSpeed(speed: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#setSpeed。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed<sup>(deprecated)</sup> | number | true | 指定播放视频速度，具体见<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-media.md#playbackspeed8">PlaybackSpeed</a><br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 设置播放速度的回调方法。<br/> |  
    
### setSpeed<sup>(deprecated)</sup>    
通过Promise方式设置播放速度。  
  
 **调用形式：**     
- setSpeed(speed: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#setSpeed。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed<sup>(deprecated)</sup> | number | true | 指定播放视频速度，具体见<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-media.md#playbackspeed8">PlaybackSpeed</a>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 播放速度Promise返回值，具体见PlaybackSpeed。 |  
    
### on('playbackCompleted')<sup>(deprecated)</sup>    
开始监听视频播放完成事件。  
  
 **调用形式：**     
- on(type: 'playbackCompleted', callback: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:stateChange。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 视频播放完成事件回调类型，支持的事件：'playbackCompleted'<br/> |  
| callback<sup>(deprecated)</sup> | Callback<void> | true | 视频播放完成事件回调方法<br/> |  
    
### on('bufferingUpdate')<sup>(deprecated)</sup>    
开始监听视频缓存更新事件。仅网络播放支持该订阅事件。  
  
 **调用形式：**     
- on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:bufferingUpdate。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 视频缓存事件回调类型，支持的事件：'bufferingUpdate'。<br/> |  
| callback<sup>(deprecated)</sup> | (infoType: BufferingInfoType, value: number) => void | true | 视频缓存事件回调方法。<br/> |  
    
### on('startRenderFrame')<sup>(deprecated)</sup>    
开始监听视频播放首帧送显上报事件  
  
 **调用形式：**     
- on(type: 'startRenderFrame', callback: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:startRenderFrame。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 视频播放首帧送显上报事件回调类型，支持的事件：'startRenderFrame'。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<void> | true | 视频播放首帧送显上报事件回调方法<br/> |  
    
### on('videoSizeChanged')<sup>(deprecated)</sup>    
开始监听视频播放宽高变化事件  
  
 **调用形式：**     
- on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:videoSizeChange。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChanged'<br/> |  
| callback<sup>(deprecated)</sup> | (width: number, height: number) => void | true | 视频播放宽高变化事件回调方法，width表示宽，height表示高<br/> |  
    
### on('audioInterrupt')<sup>(deprecated)</sup>    
监听音频焦点变化事件，多个音视频资源同时播放时，会根据音频焦点模型<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-audio.md#interruptmode9">audio.InterruptMode</a>触发此事件  
  
 **调用形式：**     
- on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:audioInterrupt。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'<br/> |  
| callback<sup>(deprecated)</sup> | (info: audio.InterruptEvent) => void | true | 音频焦点变化事件回调方法<br/> |  
    
### on('error')<sup>(deprecated)</sup>    
监听<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-media.md#avplayer9">AVPlayer</a>的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-media.md#avplayerstate9">AVPlayerState</a>也切至error状态，用户需要通过reset()或者release()退出播放操作  
  
 **调用形式：**     
- on(type: 'error', callback: ErrorCallback): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimedia.media/media.AVPlayer#event:error。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件<br/> |  
| callback<sup>(deprecated)</sup> | ErrorCallback | true | 错误事件回调方法：使用播放器的过程中发生错误，会提供错误码ID和错误信息<br/> |  
    
## VideoScaleType<sup>(9+)</sup>    
枚举，视频缩放模式。  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.VideoPlayer    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| VIDEO_SCALE_TYPE_FIT | 0 | 视频拉伸至与窗口等大。<br/> |  
| VIDEO_SCALE_TYPE_FIT_CROP | 1 | 保持视频宽高比拉伸至填满窗口，内容可能会有裁剪<br/> |  
    
## ContainerFormatType<sup>(8+)</sup>    
表示容器格式类型的枚举，缩写为CFT  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CFT_MPEG_4 | mp4 | 视频的容器格式，MP4。<br/> |  
| CFT_MPEG_4A | m4a | 音频的容器格式，M4A<br/> |  
    
## MediaType<sup>(8+)</sup>    
媒体类型枚举  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MEDIA_TYPE_AUD | 0 | 表示音频<br/> |  
| MEDIA_TYPE_VID | 1 | 表示视频<br/> |  
    
## MediaDescriptionKey<sup>(8+)</sup>    
媒体信息描述枚举。  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MD_KEY_TRACK_INDEX | track_index | 表示轨道序号，其对应键值类型为number<br/> |  
| MD_KEY_TRACK_TYPE | track_type | 表示轨道类型，其对应键值类型为number<br/> |  
| MD_KEY_CODEC_MIME | codec_mime | 表示codec_mime类型，其对应键值类型为string<br/> |  
| MD_KEY_DURATION | duration | 表示媒体时长，其对应键值类型为number，单位为毫秒（ms<br/> |  
| MD_KEY_BITRATE | bitrate | 表示比特率，其对应键值类型为number，单位为比特率（bps）<br/> |  
| MD_KEY_WIDTH | width | 表示视频宽度，其对应键值类型为number，单位为像素（px）<br/> |  
| MD_KEY_HEIGHT | height | 表示视频高度，其对应键值类型为number，单位为像素（px）<br/> |  
| MD_KEY_FRAME_RATE | frame_rate | 表示视频帧率，其对应键值类型为number，单位为100帧每秒（100fps）<br/> |  
| MD_KEY_AUD_CHANNEL_COUNT | channel_count | 表示声道数，其对应键值类型为number<br/> |  
| MD_KEY_AUD_SAMPLE_RATE | sample_rate | 表示采样率，其对应键值类型为number，单位为赫兹（Hz）<br/> |  
    
## AudioSourceType<sup>(9+)</sup>    
表示视频录制中音频源类型的枚举  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUDIO_SOURCE_TYPE_DEFAULT | 0 | 默认的音频输入源类型<br/> |  
| AUDIO_SOURCE_TYPE_MIC | 1 | 表示MIC的音频输入源<br/> |  
    
## VideoSourceType<sup>(9+)</sup>    
表示视频录制中视频源类型的枚举  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0 | 输入surface中携带的是raw data。<br/> |  
| VIDEO_SOURCE_TYPE_SURFACE_ES | 1 | 输入surface中携带的是ES data。<br/> |  
    
## AVRecorderProfile<sup>(9+)</sup>    
音视频录制的配置文件  
  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioBitrate<sup>(9+)</sup> | number | false | false | 音频编码比特率，选择音频录制时必填，支持范围[8000 - 384000]。<br/> |  
| audioChannels<sup>(9+)</sup> | number | false | false | 音频采集声道数，选择音频录制时必填，支持范围[1 - 2]。<br/> |  
| audioCodec<sup>(9+)</sup> | CodecMimeType | false | false | 音频编码格式，选择音频录制时必填。当前仅支持AUDIO_AAC。<br/> |  
| audioSampleRate<sup>(9+)</sup> | number | false | false | 音频采样率，选择音频录制时必填，支持范围[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 96000]。<br/> |  
| fileFormat<sup>(9+)</sup> | ContainerFormatType | false | true | 文件的容器格式，必要参数<br/> |  
| videoBitrate<sup>(9+)</sup> | number | false | false | 视频编码比特率，选择视频录制时必填，支持范围[1 - 3000000]<br/> |  
| videoCodec<sup>(9+)</sup> | CodecMimeType | false | false | 视频编码格式，选择视频录制时必填。当前仅支持VIDEO_MPEG4<br/> |  
| videoFrameWidth<sup>(9+)</sup> | number | false | false | 视频帧的宽，选择视频录制时必填，支持范围[2 - 1920]<br/> |  
| videoFrameHeight<sup>(9+)</sup> | number | false | false | 视频帧的高，选择视频录制时必填，支持范围[2 - 1080]。<br/> |  
| videoFrameRate<sup>(9+)</sup> | number | false | false | 视频帧率，选择视频录制时必填，支持范围[1 - 30]。 |  
    
## AVRecorderConfig<sup>(9+)</sup>    
表示音视频录制的参数设置。通过audioSourceType和videoSourceType区分纯音频录制、纯视频录制或音视频录制。纯音频录制时，仅需要设置audioSourceType；纯视频录制时，仅需要设置videoSourceType；音视频录制时，audioSourceType和videoSourceType均需要设置。  
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.AVRecorder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioSourceType<sup>(9+)</sup> | AudioSourceType | false | false | 选择录制的音频源类型。选择音频录制时必填。<br/> |  
| videoSourceType<sup>(9+)</sup> | VideoSourceType | false | false | 选择录制的视频源类型。选择视频录制时必填。<br/> |  
| profile<sup>(9+)</sup> | AVRecorderProfile | false | true | 录制的profile，必要参数。<br/> |  
| url<sup>(9+)</sup> | string | false | true | 录制输出URL：fd://xx (fd number)<br/> |  
| rotation<sup>(9+)</sup> | number | false | false | 录制的视频旋转角度，仅支持0，90，180，270，默认值为0<br/> |  
| location<sup>(9+)</sup> | Location | false | false | 录制的地理位置，默认不记录地理位置信息。 |  
    
## MediaDescription<sup>(8+)</sup>    
通过key-value方式获取媒体信息。  
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
## SeekMode<sup>(8+)</sup>    
视频播放的Seek模式枚举，可通过seek方法作为参数传递下去  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SEEK_NEXT_SYNC | 0 | 表示跳转到指定时间点的下一个关键帧，建议向后快进的时候用这个枚举值<br/> |  
| SEEK_PREV_SYNC | 1 | 表示跳转到指定时间点的上一个关键帧，建议向前快进的时候用这个枚举值。<br/> |  
    
## CodecMimeType<sup>(8+)</sup>    
Codec MIME类型枚举  
    
    
 **系统能力:**  SystemCapability.Multimedia.Media.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| VIDEO_H263 | video/h263 | 表示视频/h263类型<br/> |  
| VIDEO_AVC | video/avc | 表示视频/avc类型。<br/> |  
| VIDEO_MPEG2 | video/mpeg2 | 表示视频/mpeg2类型。<br/> |  
| VIDEO_MPEG4 | video/mp4v-es | 表示视频/mpeg4类型<br/> |  
| VIDEO_VP8 | video/x-vnd.on2.vp8 | 表示视频/vp8类型。<br/> |  
| AUDIO_AAC | audio/mp4a-latm | 表示音频/mp4a-latm类型。<br/> |  
| AUDIO_VORBIS | audio/vorbis | 表示音频/vorbis类型。<br/> |  
| AUDIO_FLAC | audio/flac | 表示音频/flac类型。 |  
