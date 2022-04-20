# 视频播放开发指导

## 场景介绍

视频播放的主要工作是将视频数据转码并输出到设备进行播放，同时管理播放任务。本文将对视频播放全流程、视频切换、视频循环播放等场景开发进行介绍说明。

**图1** 视频播放状态机

![zh-ch_image_video_state_machine](figures/zh-ch_image_video_state_machine.png)



**图2** 视频播放零层图

![zh-ch_image_video_player](figures/zh-ch_image_video_player.png)

*注意：视频播放需要显示、音频、编解码等硬件能力。

1. 三方应用从Xcomponent组件获取surfaceID。
2. 三方应用把surfaceID传递给VideoPlayer JS。
3. 媒体服务把帧数据flush给surface buffer。

## 兼容性说明

推荐使用视频软件主流的播放格式和主流分辨率，不建议开发者自制非常或者异常码流，以免产生无法播放、卡住、花屏等兼容性问题。若发生此类问题不会影响系统，退出码流播放即可。

主流的播放格式和主流分辨率如下：

| 视频容器规格 |                     规格描述                      |               分辨率               |
| :----------: | :-----------------------------------------------: | :--------------------------------: |
|     mp4      | 视频格式：H264/MPEG2/MPEG4/H263 音频格式：AAC/MP3 | 主流分辨率，如1080P/720P/480P/270P |
|     mkv      | 视频格式：H264/MPEG2/MPEG4/H263 音频格式：AAC/MP3 | 主流分辨率，如1080P/720P/480P/270P |
|      ts      |   视频格式：H264/MPEG2/MPEG4 音频格式：AAC/MP3    | 主流分辨率，如1080P/720P/480P/270P |
|     webm     |          视频格式：VP8 音频格式：VORBIS           | 主流分辨率，如1080P/720P/480P/270P |

## 开发步骤

详细API含义可参考：[媒体服务API文档VideoPlayer](../reference/apis/js-apis-media.md)

### 全流程场景

端到端的开发示例请参考：https://gitee.com/openharmony/app_samples/tree/master/media

包含流程：创建实例，设置url，设置SurfaceId，准备播放视频，播放视频，暂停播放，获取轨道信息，跳转播放位置，设置音量，设置倍速，结束播放，重置，释放资源等流程。

VideoPlayer支持的url媒体源输入类型可参考：[url属性说明](../reference/apis/js-apis-media.md#videoplayer_属性)

Xcomponent创建方法可参考：[Xcomponent创建方法](#xcomponent创建方法)

*注意：SetSurface需要在设置url和Prepare之间

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

let videoPlayer = undefined; // 用于保存createVideoPlayer创建的对象
let surfaceID = undefined; // 用于保存Xcomponent接口返回的surfaceID

// 调用Xcomponent的接口用于获取surfaceID，并保存在surfaceID变量中，该接口由XComponent组件默认加载，非主动调用
LoadXcomponent() {
	surfaceID = this.$element('Xcomponent').getXComponentSurfaceId();
    console.info('LoadXcomponent surfaceID is' + surfaceID);
}

// 函数调用发生错误时用于上报错误信息
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// 当函数调用发生异常时用于上报错误信息
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// 用于打印视频轨道信息
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('key is ' + item);
        console.info('value is ' + property);
    }
}

// 调用createVideoPlayer接口返回videoPlayer实例对象
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// 用户选择视频设置fd(本地播放)
let fdPath = 'fd://'
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp4';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

videoPlayer.url = fdPath;

// 设置surfaceID用于显示视频画面
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// 调用prepare完成播放前准备工作
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// 调用play接口正式开始播放
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);

// 暂停播放
await videoPlayer.pause().then(() => {
    console.info('pause success');
}, failureCallback).catch(catchCallback);

// 通过promise回调方式获取视频轨道信息
let arrayDescription;
await videoPlayer.getTrackDescription().then((arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        arrayDescription = arrlist;
    } else {
        console.log('video getTrackDescription fail');
    }
}, failureCallback).catch(catchCallback);

for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}

// 跳转播放时间到50s位置，具体入参意义请参考接口文档
let seekTime = 50000;
await videoPlayer.seek(seekTime, media.SeekMode._NEXT_SYNC).then((seekDoneTime) => {
    console.info('seek success');
}, failureCallback).catch(catchCallback);

// 音量设置接口，具体入参意义请参考接口文档
let volume = 0.5;
await videoPlayer.setVolume(volume).then(() => {
    console.info('setVolume success');
}, failureCallback).catch(catchCallback);

// 倍速设置接口，具体入参意义请参考接口文档
let speed = media.PlaybackRateMode.SPEED_FORWARD_2_00_X;
await videoPlayer.setSpeed(speed).then(() => {
    console.info('setSpeed success');
}, failureCallback).catch(catchCallback);

// 结束播放
await videoPlayer.stop().then(() => {
    console.info('stop success');
}, failureCallback).catch(catchCallback);

// 重置播放配置
await videoPlayer.reset().then(() => {
    console.info('reset success');
}, failureCallback).catch(catchCallback);

// 释放播放资源
await videoPlayer.release().then(() => {
    console.info('release success');
}, failureCallback).catch(catchCallback);

// 相关对象置undefined
videoPlayer = undefined;
surfaceID = undefined;
```

### 正常播放场景

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

let videoPlayer = undefined; // 用于保存createVideoPlayer创建的对象
let surfaceID = undefined; // 用于保存Xcomponent接口返回的surfaceID

// 调用Xcomponent的接口用于获取surfaceID，并保存在surfaceID变量中，该接口由XComponent组件默认加载，非主动调用
LoadXcomponent() {
	surfaceID = this.$element('Xcomponent').getXComponentSurfaceId();
    console.info('LoadXcomponent surfaceID is' + surfaceID);
}

// 函数调用发生错误时用于上报错误信息
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// 当函数调用发生异常时用于上报错误信息
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// 设置'playbackCompleted'事件回调，播放完成触发
function SetCallBack(videoPlayer) {
	videoPlayer.on('playbackCompleted', () => {
        console.info('video play finish');
        
        await videoPlayer.release().then(() => {
    		console.info('release success');
		}, failureCallback).catch(catchCallback);

		videoPlayer = undefined;
        surfaceID = undefined;
    });
}

// 调用createVideoPlayer接口返回videoPlayer实例对象
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// 设置事件回调
SetCallBack(videoPlayer);

// 用户选择视频设置fd(本地播放)
let fdPath = 'fd://'
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp4';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

videoPlayer.url = fdPath;

// 设置surfaceID用于显示视频画面
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// 调用prepare完成播放前准备工作
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// 调用play接口正式开始播放
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
```

### 切视频场景

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

let videoPlayer = undefined; // 用于保存createVideoPlayer创建的对象
let surfaceID = undefined; // 用于保存Xcomponent接口返回的surfaceID

// 调用Xcomponent的接口用于获取surfaceID，并保存在surfaceID变量中，该接口由XComponent组件默认加载，非主动调用
LoadXcomponent() {
	surfaceID = this.$element('Xcomponent').getXComponentSurfaceId();
    console.info('LoadXcomponent surfaceID is' + surfaceID);
}

// 函数调用发生错误时用于上报错误信息
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// 当函数调用发生异常时用于上报错误信息
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// 设置'playbackCompleted'事件回调，播放完成触发
function SetCallBack(videoPlayer) {
	videoPlayer.on('playbackCompleted', () => {
        console.info('video play finish');
        
        await videoPlayer.release().then(() => {
    		console.info('release success');
		}, failureCallback).catch(catchCallback);

		videoPlayer = undefined;
        surfaceID = undefined;
    });
}

// 调用createVideoPlayer接口返回videoPlayer实例对象
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// 设置事件回调
SetCallBack(videoPlayer);

// 用户选择视频设置fd(本地播放)
let fdPath = 'fd://'
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp4';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

videoPlayer.url = fdPath;

// 设置surfaceID用于显示视频画面
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// 调用prepare完成播放前准备工作
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// 调用play接口正式开始播放
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);

// 播放一段时间后，下发切视频指令
// 重置播放配置
await videoPlayer.reset().then(() => {
    console.info('reset success');
}, failureCallback).catch(catchCallback);

// 用户选择视频设置fd(本地播放)
let fdNextPath = 'fd://'
// path路径的码流可通过"hdc file send D:\xxx\02.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上
let nextPath = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/02.mp4';
await fileIO.open(nextPath).then(fdNumber) => {
   fdNextPath = fdNextPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdNextPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

videoPlayer.url = fdNextPath;

// 设置surfaceID用于显示视频画面
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// 调用prepare完成播放前准备工作
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// 调用play接口正式开始播放
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
```

### 单个视频循环场景

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

let videoPlayer = undefined; // 用于保存createVideoPlayer创建的对象
let surfaceID = undefined; // 用于保存Xcomponent接口返回的surfaceID

// 调用Xcomponent的接口用于获取surfaceID，并保存在surfaceID变量中，该接口由XComponent组件默认加载，非主动调用
LoadXcomponent() {
	surfaceID = this.$element('Xcomponent').getXComponentSurfaceId();
    console.info('LoadXcomponent surfaceID is' + surfaceID);
}

// 函数调用发生错误时用于上报错误信息
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// 当函数调用发生异常时用于上报错误信息
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// 设置'playbackCompleted'事件回调，播放完成触发
function SetCallBack(videoPlayer) {
	videoPlayer.on('playbackCompleted', () => {
        console.info('video play finish');
        
        await videoPlayer.release().then(() => {
    		console.info('release success');
		}, failureCallback).catch(catchCallback);

		videoPlayer = undefined;
        surfaceID = undefined;
    });
}

// 调用createVideoPlayer接口返回videoPlayer实例对象
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// 设置事件回调
SetCallBack(videoPlayer);

// 用户选择视频设置fd(本地播放)
let fdPath = 'fd://'
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp4';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

videoPlayer.url = fdPath;

// 设置surfaceID用于显示视频画面
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// 调用prepare完成播放前准备工作
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// 设置循环播放属性
videoPlayer.loop = true;

// 调用play接口正式开始播放
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
```

### Xcomponent创建方法

播放视频中获取surfaceID依赖了Xcomponent，需要创建一个和xxx.js同名的xxx.hml文件，xxx.hml里面需要添加如下代码：

```js
<xcomponent id = 'Xcomponent'
      if = "{{isFlush}}" // 刷新surfaceID，isFlush赋值false再赋值true为一次刷新，会主动再次加载LoadXcomponent获取新的surfaceID
      type = 'surface'
      onload = 'LoadXcomponent' // 默认加载接口
      style = "width:720px;height:480px;border-color:red;border-width:5px;"> // 设置窗口宽高等属性
</xcomponent>
```
