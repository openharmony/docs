# @ohos.multimedia.media    
媒体子系统为开发者提供一套简单且易于理解的接口，使得开发者能够方便接入系统并使用系统的媒体资源。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import media from '@ohos.multimedia.media'    
```  
    
## createVideoRecorder<sup>(9+)</sup>    
异步方式创建视频录制实例。通过Promise获取返回值。 一台设备只允许创建一个录制实例。  
 **调用形式：**     
    
- createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void    
起始版本： 9    
- createVideoRecorder(): Promise\<VideoRecorder>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。异步返回VideoRecorder实例，失败时返回null。可用于录制视频媒体。 |  
| Promise<VideoRecorder> | Promise对象。异步返回VideoRecorder实例，失败时返回null。可用于录制视频媒体。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400101 | No memory. Return by promise. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
let videoRecorder: media.VideoRecorder;  
  
media.createVideoRecorder((error: BusinessError, video: media.VideoRecorder) => {  
  if (video != null) {  
    videoRecorder = video;  
    console.info('video createVideoRecorder success');  
  } else {  
    console.error(`video createVideoRecorder fail, error message:${error.message}`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
let videoRecorder: media.VideoRecorder;  
  
media.createVideoRecorder().then((video: media.VideoRecorder) => {  
  if (video != null) {  
    videoRecorder = video;  
    console.info('video createVideoRecorder success');  
  } else {  
    console.error('video createVideoRecorder fail');  
  }  
}).catch((error: Error) => {  
  console.error(`video catchCallback, error message:${error.message}`);  
});  
    
```    
  
    
## VideoRecordState<sup>(9+)</sup>    
视频录制的状态机。可通过state属性获取当前状态。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
    
| 取值范围 | 说明 |  
| --------| --------|  
| idle | 视频录制空闲。 |  
| prepared | 视频录制参数设置完成。 |  
| playing | 视频正在录制。 |  
| paused | 视频暂停录制。 |  
| stopped | 视频录制停止。 |  
| error | 错误状态。 |  
    
## VideoRecorder<sup>(9+)</sup>    
视频录制管理类，用于录制视频媒体  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| state<sup>(9+)</sup> | VideoRecordState | true | true | 视频录制的状态。 |  
    
### prepare<sup>(9+)</sup>    
视频录制的状态。  
 **调用形式：**     
    
- prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void    
起始版本： 9    
- prepare(config: VideoRecorderConfig): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder  
 **需要权限：** ohos.permission.MICROPHONE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | VideoRecorderConfig | true | 配置视频录制的相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步方式获得录制需要的surface。此surface提供给调用者，调用者从此surface中获取surfaceBuffer，填入相应的数据。 |  
| Promise<void> | 异步视频录制prepare方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. Return by promise. |  
| 401 | Parameter error. Return by promise. |  
| 5400102 | Operation not allowed. Return by promise |  
| 5400105 | Service died. Return by promise. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 配置参数以实际硬件设备支持的范围为准  
let videoProfile: media.VideoRecorderProfile = {  
  audioBitrate : 48000,  
  audioChannels : 2,  
  audioCodec : media.CodecMimeType.AUDIO_AAC,  
  audioSampleRate : 48000,  
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,  
  videoBitrate : 2000000,  
  videoCodec : media.CodecMimeType.VIDEO_AVC,  
  videoFrameWidth : 640,  
  videoFrameHeight : 480,  
  videoFrameRate : 30  
}  
  
let videoConfig: media.VideoRecorderConfig = {  
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,  
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,  
  profile : videoProfile,  
  url : 'fd://xx',   // 文件需先由调用者创建，并给予适当的权限  
  rotation : 0,  
  location : { latitude : 30, longitude : 130 },  
}  
  
// asyncallback  
videoRecorder.prepare(videoConfig, (err: BusinessError) => {  
  if (err == null) {  
    console.info('prepare success');  
  } else {  
    console.error('prepare failed and error is ' + err.message);  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// 配置参数以实际硬件设备支持的范围为准  
let videoProfile: media.VideoRecorderProfile = {  
  audioBitrate : 48000,  
  audioChannels : 2,  
  audioCodec : media.CodecMimeType.AUDIO_AAC,  
  audioSampleRate : 48000,  
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,  
  videoBitrate : 2000000,  
  videoCodec : media.CodecMimeType.VIDEO_AVC,  
  videoFrameWidth : 640,  
  videoFrameHeight : 480,  
  videoFrameRate : 30  
}  
  
let videoConfig: media.VideoRecorderConfig = {  
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,  
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,  
  profile : videoProfile,  
  url : 'fd://xx',   // 文件需先由调用者创建，并给予适当的权限  
  rotation : 0,  
  location : { latitude : 30, longitude : 130 },  
}  
  
// promise  
videoRecorder.prepare(videoConfig).then(() => {  
  console.info('prepare success');  
}).catch((err: Error) => {  
  console.error('prepare failed and catch error is ' + err.message);  
});    
```    
  
    
### getInputSurface<sup>(9+)</sup>  
 **调用形式：**     
    
- getInputSurface(callback: AsyncCallback\<string>): void    
起始版本： 9    
- getInputSurface(): Promise\<string>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获得surface的回调方法。 |  
| Promise<string> | 异步获得surface的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
// asyncallback  
let surfaceID: string;   // 传递给外界的surfaceID  
videoRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {  
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
// promise  
let surfaceID: string;                                               // 传递给外界的surfaceID  
videoRecorder.getInputSurface().then((surfaceId: string) => {  
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
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步开始视频录制的回调方法。 |  
| Promise<void> | 异步开始视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// asyncallback  
videoRecorder.start((err: BusinessError) => {  
  if (err == null) {  
    console.info('start videorecorder success');  
  } else {  
    console.error('start videorecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// promise  
videoRecorder.start().then(() => {  
  console.info('start videorecorder success');  
}).catch((err: Error) => {  
  console.error('start videorecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### pause<sup>(9+)</sup>    
异步方式暂停视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- pause(callback: AsyncCallback\<void>): void    
起始版本： 9    
- pause(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步暂停视频录制的回调方法。 |  
| Promise<void> | 异步暂停视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// asyncallback  
videoRecorder.pause((err: BusinessError) => {  
  if (err == null) {  
    console.info('pause videorecorder success');  
  } else {  
    console.error('pause videorecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// promise  
videoRecorder.pause().then(() => {  
  console.info('pause videorecorder success');  
}).catch((err: Error) => {  
  console.error('pause videorecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### resume<sup>(9+)</sup>    
异步方式恢复视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- resume(callback: AsyncCallback\<void>): void    
起始版本： 9    
- resume(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步恢复视频录制的回调方法。 |  
| Promise<void> | 异步恢复视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// asyncallback  
videoRecorder.resume((err: Error) => {  
  if (err == null) {  
    console.info('resume videorecorder success');  
  } else {  
    console.error('resume videorecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// promise  
videoRecorder.resume().then(() => {  
  console.info('resume videorecorder success');  
}).catch((err: Error) => {  
  console.error('resume videorecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### stop<sup>(9+)</sup>    
异步方式停止视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 9    
- stop(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步停止视频录制的回调方法。 |  
| Promise<void> | 异步停止视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400102 | Operation not allowed. Return by callback. |  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// asyncallback  
videoRecorder.stop((err: BusinessError) => {  
  if (err == null) {  
    console.info('stop videorecorder success');  
  } else {  
    console.error('stop videorecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// promise  
videoRecorder.stop().then(() => {  
  console.info('stop videorecorder success');  
}).catch((err: Error) => {  
  console.error('stop videorecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### release<sup>(9+)</sup>    
异步方式释放视频录制资源。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 9    
- release(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步释放视频录制资源的回调方法。 |  
| Promise<void> | 异步释放视频录制资源方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// asyncallback  
videoRecorder.release((err: BusinessError) => {  
  if (err == null) {  
    console.info('release videorecorder success');  
  } else {  
    console.error('release videorecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// promise  
videoRecorder.release().then(() => {  
  console.info('release videorecorder success');  
}).catch((err: Error) => {  
  console.error('release videorecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### reset<sup>(9+)</sup>    
异步方式重置视频录制。通过注册回调函数获取返回值。  
 **调用形式：**     
    
- reset(callback: AsyncCallback\<void>): void    
起始版本： 9    
- reset(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步重置视频录制的回调方法。 |  
| Promise<void> | 异步重置视频录制方法的Promise返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
// asyncallback  
videoRecorder.reset((err: BusinessError) => {  
  if (err == null) {  
    console.info('reset videorecorder success');  
  } else {  
    console.error('reset videorecorder failed and error is ' + err.message);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
// promise  
videoRecorder.reset().then(() => {  
  console.info('reset videorecorder success');  
}).catch((err: Error) => {  
  console.error('reset videorecorder failed and catch error is ' + err.message);  
});    
```    
  
    
### on('error')<sup>(9+)</sup>    
开始订阅视频录制错误事件，当上报error错误事件后，用户需处理error事件，退出录制操作。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 录制错误事件回调类型'error'。<br/>-'error'：视频录制过程中发生错误，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 录制错误事件回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 5400103 | I/O error. Return by callback. |  
| 5400105 | Service died. Return by callback. |  
    
 **示例代码：**   
```ts    
// 当获取videoRecordState接口出错时通过此订阅事件上报  
videoRecorder.on('error', (error: Error) => {   // 设置'error'事件回调  
  console.error(`audio error called, error: ${error}`);  
})    
```    
  
    
## VideoRecorderProfile<sup>(9+)</sup>    
视频录制的配置文件  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioBitrate<sup>(9+)</sup> | number | true | true | 音频编码比特率，选择音频录制时必填<br/> |  
| audioChannels<sup>(9+)</sup> | number | true | true | 音频采集声道数，选择音频录制时必填<br/> |  
| audioCodec<sup>(9+)</sup> | CodecMimeType | true | true | 音频编码格式，选择音频录制时必填<br/> |  
| audioSampleRate<sup>(9+)</sup> | number | true | true | 音频采样率，选择音频录制时必填<br/> |  
| fileFormat<sup>(9+)</sup> | ContainerFormatType | true | true | 文件的容器格式<br/> |  
| videoBitrate<sup>(9+)</sup> | number | true | true | 视频编码比特率<br/> |  
| videoCodec<sup>(9+)</sup> | CodecMimeType | true | true | 视频编码格式<br/> |  
| videoFrameWidth<sup>(9+)</sup> | number | true | true | 录制视频帧的宽<br/> |  
| videoFrameHeight<sup>(9+)</sup> | number | true | true | 录制视频帧的高<br/> |  
| videoFrameRate<sup>(9+)</sup> | number | true | true | 录制视频帧率<br/> |  
    
## VideoRecorderConfig<sup>(9+)</sup>    
表示视频录制的参数设置  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.VideoRecorder    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioSourceType<sup>(9+)</sup> | AudioSourceType | false | false | 视频录制的音频源类型，选择音频录制时必填<br/> |  
| videoSourceType<sup>(9+)</sup> | VideoSourceType | false | true | 视频录制的视频源类型<br/> |  
| profile<sup>(9+)</sup> | VideoRecorderProfile | false | true | 视频录制的profile<br/> |  
| url<sup>(9+)</sup> | string | false | true | 视频输出URL：fd://xx(fdnumber)<br/> |  
| rotation<sup>(9+)</sup> | number | false | false | 录制的视频旋转角度，仅支持0，90，180，270，默认值为0<br/> |  
| location<sup>(9+)</sup> | Location | false | false | 录制视频的地理位置，默认不记录地理位置信息<br/> |  
