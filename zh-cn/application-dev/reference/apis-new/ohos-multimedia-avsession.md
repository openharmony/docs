# @ohos.multimedia.avsession    
媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import avSession from '@ohos.multimedia.avsession'    
```  
    
## createAVSession<sup>(10+)</sup>    
创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void    
起始版本： 10    
- createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文，提供获取应用程序环境信息的能力。<br/> |  
| tag | string | true | 会话的自定义名称。<br/> |  
| type | AVSessionType | true | 会话类型，当前支持音频和视频。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。 |  
| Promise<AVSession> | Promise对象。返回所有会话描述的只读对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
let sessionId: string;  //供后续函数入参使用  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
    sessionId = currentAVSession.sessionId;  
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
let sessionId: string;  //供后续函数入参使用  
  
avSession.createAVSession(context, tag, "audio").then((data: avSession.AVSession) => {  
  currentAVSession = data;  
  sessionId = currentAVSession.sessionId;  
  console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);  
}).catch((err: BusinessError) => {  
  console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## AVSessionType<sup>(10+)</sup>    
当前会话支持的会话类型。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| audio | 音频 |  
| video | 视频 |  
    
## AVSession<sup>(10+)</sup>    
调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#avsessioncreateavsession10">avSession.createAVSession</a>后，返回会话的实例，可以获得会话ID，完成设置元数据，播放状态信息等操作。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sessionId<sup>(10+)</sup> | string | true | true | AVSession对象唯一的会话标识。<br/> |  
| sessionType<sup>(10+)</sup> | AVSessionType | true | true | AVSession会话类型。<br/> |  
    
### setAVMetadata<sup>(10+)</sup>    
设置会话元数据。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setAVMetadata(data: AVMetadata): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | AVMetadata | true | 会话元数据。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当元数据设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当元数据设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let metadata: avSession.AVMetadata = {  
  assetId: "121278",  
  title: "lose yourself",  
  artist: "Eminem",  
  author: "ST",  
  album: "Slim shady",  
  writer: "ST",  
  composer: "ST",  
  duration: 2222,  
  mediaImage: "https://www.example.com/example.jpg",  
  subtitle: "8 Mile",  
  description: "Rap",  
  lyric: "https://www.example.com/example.lrc",  
  previousAssetId: "121277",  
  nextAssetId: "121279",  
};  
currentAVSession.setAVMetadata(metadata, (err: BusinessError) => {  
  if (err) {  
    console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SetAVMetadata successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let metadata: avSession.AVMetadata = {  
  assetId: "121278",  
  title: "lose yourself",  
  artist: "Eminem",  
  author: "ST",  
  album: "Slim shady",  
  writer: "ST",  
  composer: "ST",  
  duration: 2222,  
  mediaImage: "https://www.example.com/example.jpg",  
  subtitle: "8 Mile",  
  description: "Rap",  
  lyric: "https://www.example.com/example.lrc",  
  previousAssetId: "121277",  
  nextAssetId: "121279",  
};  
currentAVSession.setAVMetadata(metadata).then(() => {  
  console.info(`SetAVMetadata successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
### setAVPlaybackState<sup>(10+)</sup>    
设置会话播放状态。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setAVPlaybackState(state: AVPlaybackState): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | AVPlaybackState | true | 会话播放状态，包括状态、倍数、循环模式等信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当播放状态设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let playbackState: avSession.AVPlaybackState = {  
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,  
  speed: 1.0,  
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},  
  bufferedTime:1000,  
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,  
  isFavorite:true,  
};  
currentAVSession.setAVPlaybackState(playbackState).then(() => {  
  console.info(`SetAVPlaybackState successfully`);  
}).catch((err: BusinessError) => {  
  console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let PlaybackState: avSession.AVPlaybackState = {  
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,  
  speed: 1.0,  
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},  
  bufferedTime:1000,  
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,  
  isFavorite:true,  
};  
currentAVSession.setAVPlaybackState(PlaybackState, (err: BusinessError) => {  
  if (err) {  
    console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SetAVPlaybackState successfully`);  
  }  
});  
    
```    
  
    
### setLaunchAbility<sup>(10+)</sup>    
设置一个WantAgent用于拉起会话的Ability。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setLaunchAbility(ability: WantAgent): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | WantAgent | true | 应用的相关属性信息，如bundleName，abilityName，deviceId等。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当Ability设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import wantAgent from '@ohos.app.ability.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//WantAgentInfo对象  
let wantAgentInfo: wantAgent.WantAgentInfo = {  
  wants: [  
    {  
      deviceId: "deviceId",  
      bundleName: "com.example.myapplication",  
      abilityName: "EntryAbility",  
      action: "action1",  
      entities: ["entity1"],  
      type: "MIMETYPE",  
      uri: "key={true,true,false}",  
      parameters:  
        {  
          mykey0: 2222,  
          mykey1: [1, 2, 3],  
          mykey2: "[1, 2, 3]",  
          mykey3: "ssssssssssssssssssssssssss",  
          mykey4: [false, true, false],  
          mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],  
          mykey6: true,  
        }  
    }  
  ],  
  operationType: wantAgent.OperationType.START_ABILITIES,  
  requestCode: 0,  
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}  
  
wantAgent.getWantAgent(wantAgentInfo).then((agent) => {  
  currentAVSession.setLaunchAbility(agent).then(() => {  
    console.info(`SetLaunchAbility successfully`);  
  }).catch((err: BusinessError) => {  
    console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import wantAgent from '@ohos.app.ability.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
//WantAgentInfo对象  
let wantAgentInfo: wantAgent.WantAgentInfo = {  
  wants: [  
    {  
      deviceId: "deviceId",  
      bundleName: "com.example.myapplication",  
      abilityName: "EntryAbility",  
      action: "action1",  
      entities: ["entity1"],  
      type: "MIMETYPE",  
      uri: "key={true,true,false}",  
      parameters:  
        {  
          mykey0: 2222,  
          mykey1: [1, 2, 3],  
          mykey2: "[1, 2, 3]",  
          mykey3: "ssssssssssssssssssssssssss",  
          mykey4: [false, true, false],  
          mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],  
          mykey6: true,  
        }  
    }  
  ],  
  operationType: wantAgent.OperationType.START_ABILITIES,  
  requestCode: 0,  
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
}  
  
wantAgent.getWantAgent(wantAgentInfo).then((agent) => {  
  currentAVSession.setLaunchAbility(agent, (err: BusinessError) => {  
    if (err) {  
      console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);  
    } else {  
      console.info(`SetLaunchAbility successfully`);  
    }  
  });  
});  
    
```    
  
    
### dispatchSessionEvent<sup>(10+)</sup>    
媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容, 结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void    
起始版本： 10    
- dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 需要设置的会话事件的名称<br/> |  
| args | {[key: string]: Object} | true | 需要传递的会话事件键值对<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当会话事件设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当事件设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
let eventName = "dynamic_lyric";  
if (currentAVSession !== undefined) {  
  (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}).then(() => {  
    console.info(`dispatchSessionEvent successfully`);  
  }).catch((err: BusinessError) => {  
    console.info(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
let eventName: string = "dynamic_lyric";  
if (currentAVSession !== undefined) {  
  (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}, (err: BusinessError) => {  
    if(err) {  
      console.error(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);  
    }  
  })  
}  
    
```    
  
    
### setAVQueueItems<sup>(10+)</sup>    
设置媒体播放列表。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| items | Array<AVQueueItem> | true | 播放列表单项的队列，用以表示播放列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例代码（promise）：  
```ts    
import image from '@ohos.multimedia.image';  
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
import avSession from '@ohos.multimedia.avsession';  
  
let value: Uint8Array | undefined = undefined;  
let imageSource: image.ImageSource | undefined = undefined;  
resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI').then((data) => {  
  value = data;  
});  
if (value !== undefined) {  
  imageSource = image.createImageSource((value as Uint8Array).buffer);  
}  
let imagePixel: image.PixelMap | undefined = undefined;  
if (imageSource !== undefined) {  
  (imageSource as image.ImageSource).createPixelMap({desiredSize:{width: 150, height: 150}}).then((data) => {  
    imagePixel = data;  
  }).catch((err: BusinessError) => {  
    console.error(`createPixelMap BusinessError: code: ${err.code}, message: ${err.message}`);  
  })  
}  
  
let queueItemDescription_1: avSession.AVMediaDescription = {  
  assetId: '001',  
  title: 'music_name',  
  subtitle: 'music_sub_name',  
  description: 'music_description',  
  mediaImage : imagePixel,  
  extras: {extras:'any'}  
};  
let queueItem_1: avSession.AVQueueItem = {  
  itemId: 1,  
  description: queueItemDescription_1  
};  
let queueItemDescription_2: avSession.AVMediaDescription = {  
  assetId: '002',  
  title: 'music_name',  
  subtitle: 'music_sub_name',  
  description: 'music_description',  
  mediaImage: imagePixel,  
  extras: {extras:'any'}  
};  
let queueItem_2: avSession.AVQueueItem = {  
  itemId: 2,  
  description: queueItemDescription_2  
};  
let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];  
currentAVSession.setAVQueueItems(queueItemsArray).then(() => {  
  console.info(`SetAVQueueItems successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import image from '@ohos.multimedia.image';  
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
import avSession from '@ohos.multimedia.avsession';  
  
let value: Uint8Array | undefined = undefined;  
let imageSource: image.ImageSource | undefined = undefined;  
resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI').then((data) => {  
  value = data;  
});  
if (value !== undefined) {  
  imageSource = image.createImageSource((value as Uint8Array).buffer);  
}  
let imagePixel: image.PixelMap | undefined = undefined;  
if (imageSource !== undefined) {  
  (imageSource as image.ImageSource).createPixelMap({desiredSize:{width: 150, height: 150}}).then((data) => {  
    imagePixel = data;  
  }).catch((err: BusinessError) => {  
    console.error(`createPixelMap BusinessError: code: ${err.code}, message: ${err.message}`);  
  })  
}  
let queueItemDescription_1: avSession.AVMediaDescription = {  
  assetId: '001',  
  title: 'music_name',  
  subtitle: 'music_sub_name',  
  description: 'music_description',  
  mediaImage : imagePixel,  
  extras: {extras:'any'}  
};  
let queueItem_1: avSession.AVQueueItem = {  
  itemId: 1,  
  description: queueItemDescription_1  
};  
let queueItemDescription_2: avSession.AVMediaDescription = {  
  assetId: '002',  
  title: 'music_name',  
  subtitle: 'music_sub_name',  
  description: 'music_description',  
  mediaImage: imagePixel,  
  extras: {extras:'any'}  
};  
let queueItem_2: avSession.AVQueueItem = {  
  itemId: 2,  
  description: queueItemDescription_2  
};  
let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];  
currentAVSession.setAVQueueItems(queueItemsArray, (err: BusinessError) => {  
  if (err) {  
    console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SetAVQueueItems successfully`);  
  }  
});  
    
```    
  
    
### setAVQueueTitle<sup>(10+)</sup>    
设置媒体播放列表名称。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setAVQueueTitle(title: string): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| title | string | true | 播放列表的名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let queueTitle = 'QUEUE_TITLE';  
currentAVSession.setAVQueueTitle(queueTitle).then(() => {  
  console.info(`SetAVQueueTitle successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let queueTitle = 'QUEUE_TITLE';  
currentAVSession.setAVQueueTitle(queueTitle, (err: BusinessError) => {  
  if (err) {  
    console.info(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.error(`SetAVQueueTitle successfully`);  
  }  
});  
    
```    
  
    
### setExtras<sup>(10+)</sup>    
媒体提供方设置键值对形式的自定义媒体数据包, 结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setExtras(extras: {[key: string]: Object}): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| extras | {[key: string]: Object} | true | 需要传递的自定义媒体数据包键值对<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当自定义媒体数据包设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当自定义媒体数据包设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}).then(() => {  
    console.info(`setExtras successfully`);  
  }).catch((err: BusinessError) => {  
    console.info(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}, (err: BusinessError) => {  
    if(err) {  
      console.error(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);  
    }  
  })  
}  
    
```    
  
    
### getController<sup>(10+)</sup>    
获取本会话对应的控制器。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getController(callback: AsyncCallback\<AVSessionController>): void    
起始版本： 10    
- getController(): Promise\<AVSessionController>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当自定义媒体数据包设置成功，err为undefined，否则返回错误对象。 |  
| Promise<AVSessionController> | Promise对象。返回会话控制器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let avsessionController: avSession.AVSessionController;  
currentAVSession.getController().then((avcontroller: avSession.AVSessionController) => {  
  avsessionController = avcontroller;  
  console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);  
}).catch((err: BusinessError) => {  
  console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let avsessionController: avSession.AVSessionController;  
currentAVSession.getController((err: BusinessError, avcontroller: avSession.AVSessionController) => {  
  if (err) {  
    console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    avsessionController = avcontroller;  
    console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);  
  }  
});  
    
```    
  
    
### getAVCastController<sup>(10+)</sup>    
设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- getAVCastController(callback: AsyncCallback\<AVCastController>): void    
起始版本： 10    
- getAVCastController(): Promise\<AVCastController>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回投播控制器实例。 |  
| Promise<AVCastController> | Promise对象。返回投播控制器实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600102 | session does not exist |  
| 6600110 | The remote connection does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let aVCastController: avSession.AVCastController;  
currentAVSession.getAVCastController().then((avcontroller: avSession.AVCastController) => {  
  aVCastController = avcontroller;  
  console.info(`getAVCastController : SUCCESS`);  
}).catch((err: BusinessError) => {  
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let aVCastController: avSession.AVCastController;  
currentAVSession.getAVCastController((err: BusinessError, avcontroller: avSession.AVCastController) => {  
  if (err) {  
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    aVCastController = avcontroller;  
    console.info(`getAVCastController : SUCCESS`);  
  }  
});  
    
```    
  
    
### getOutputDevice<sup>(10+)</sup>    
通过会话获取播放设备信息。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void    
起始版本： 10    
- getOutputDevice(): Promise\<OutputDeviceInfo>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回播放设备信息。 |  
| Promise<OutputDeviceInfo> | Promise对象。当会话激活成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.getOutputDevice().then((outputDeviceInfo: avSession.OutputDeviceInfo) => {  
  console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);  
}).catch((err: BusinessError) => {  
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);  
})  
    
```    
  
    
 **示例代码2：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.getOutputDevice((err: BusinessError, outputDeviceInfo: avSession.OutputDeviceInfo) => {  
  if (err) {  
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);  
  }  
});  
    
```    
  
    
### getOutputDeviceSync<sup>(10+)</sup>    
使用同步方法获取当前输出设备信息。  
 **调用形式：**     
- getOutputDeviceSync(): OutputDeviceInfo  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| OutputDeviceInfo | 当前输出设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let currentOutputDevice: avSession.OutputDeviceInfo = currentAVSession.getOutputDeviceSync();  
} catch (err: BusinessError) {  
  console.info(`getOutputDeviceSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### on('play')<sup>(10+)</sup>    
设置播放命令监听事件。  
 **调用形式：**     
    
- on(type: 'play', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为<code>'play'</code>当播放命令被发送到会话时，触发该事件回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
```tscurrentAVSession.on('play', () => {  console.info(`on play entry`);});    
```    
  
    
### on('pause')<sup>(10+)</sup>    
设置暂停命令监听事件。  
 **调用形式：**     
    
- on(type: 'pause', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为<code>'pause'</code>，当暂停命令被发送到会话时，触发该事件回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('pause', () => {  console.info(`on pause entry`);});    
```    
  
    
### on('stop')<sup>(10+)</sup>    
设置停止命令监听事件。  
 **调用形式：**     
    
- on(type: 'stop', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件是<code>'stop'</code>，当停止命令被发送到会话时，触发该事件回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('stop', () => {  console.info(`on stop entry`);});    
```    
  
    
### on('playNext')<sup>(10+)</sup>    
设置播放下一首资源的监听事件。  
 **调用形式：**     
    
- on(type: 'playNext', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'playNext'</code>：当播放下一首状态变化时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('playNext', () => {  console.info(`on playNext entry`);});    
```    
  
    
### on('playPrevious')<sup>(10+)</sup>    
设置播放上一首命令监听事件。  
 **调用形式：**     
    
- on(type: 'playPrevious', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件是<code>'playPrevious'</code>当播放上一首命令被发送到会话时，触发该事件回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('playPrevious', () => {  console.info(`on playPrevious entry`);});    
```    
  
    
### on('fastForward')<sup>(10+)</sup>    
设置快进命令监听事件。  
 **调用形式：**     
    
- on(type: 'fastForward', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件是<code>'fastForward'</code>，当快进命令被发送到会话时，触发该事件回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数time是时间节点，单位为秒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('fastForward', (time?: number) => {  console.info(`on fastForward entry`);});    
```    
  
    
### on('rewind')<sup>(10+)</sup>    
设置快退命令监听事件。  
 **调用形式：**     
    
- on(type: 'rewind', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件是<code>'rewind'</code>，当快退命令被发送到会话时，触发该事件回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数time是时间节点，单位为秒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('rewind', (time?: number) => {  console.info(`on rewind entry`);});    
```    
  
    
### off('play')<sup>(10+)</sup>    
取消会话播放事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'play', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'play'</code><br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('play');    
```    
  
    
### off('pause')<sup>(10+)</sup>    
取消会话暂停事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'pause', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'pause'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('pause');    
```    
  
    
### off('stop')<sup>(10+)</sup>    
取消会话停止事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'stop', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'stop'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('stop');    
```    
  
    
### off('playNext')<sup>(10+)</sup>    
取消会话播放下一首事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'playNext', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'playNext'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('playNext');    
```    
  
    
### off('playPrevious')<sup>(10+)</sup>    
取消会话播放上一首事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'playPrevious', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'playPrevious'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('playPrevious');    
```    
  
    
### off('fastForward')<sup>(10+)</sup>    
取消会话快进事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'fastForward', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'fastForward'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('fastForward');    
```    
  
    
### off('rewind')<sup>(10+)</sup>    
取消会话快退事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
    
- off(type: 'rewind', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'rewind'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('rewind');    
```    
  
    
### on('seek')<sup>(10+)</sup>    
设置跳转节点监听事件。  
 **调用形式：**     
    
- on(type: 'seek', callback: (time: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'seek'</code>：当跳转节点命令被发送到会话时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数time是时间节点，单位为毫秒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('seek', (time: number) => {  console.info(`on seek entry time : ${time}`);});    
```    
  
    
### off('seek')<sup>(10+)</sup>    
取消监听跳转节点事件。  
 **调用形式：**     
    
- off(type: 'seek', callback?: (time: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'seek'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数time是时间节点，单位为毫秒。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('seek');    
```    
  
    
### on('setSpeed')<sup>(10+)</sup>    
设置播放速率的监听事件。  
 **调用形式：**     
    
- on(type: 'setSpeed', callback: (speed: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'setSpeed'</code>：当设置播放速率的命令被发送到会话时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数speed是播放倍速。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('setSpeed', (speed: number) => {  console.info(`on setSpeed speed : ${speed}`);});    
```    
  
    
### off('setSpeed')<sup>(10+)</sup>    
取消监听播放速率变化事件。  
 **调用形式：**     
    
- off(type: 'setSpeed', callback?: (speed: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'setSpeed'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数speed是播放倍速。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('setSpeed');    
```    
  
    
### on('setLoopMode')<sup>(10+)</sup>    
设置循环模式的监听事件。  
 **调用形式：**     
    
- on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'setLoopMode'</code>：当设置循环模式的命令被发送到会话时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数mode是循环模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('setLoopMode', (mode: avSession.LoopMode) => {  console.info(`on setLoopMode mode : ${mode}`);});    
```    
  
    
### off('setLoopMode')<sup>(10+)</sup>    
取消监听循环模式变化事件。  
 **调用形式：**     
    
- off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'setLoopMode'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数mode是循环模式。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('setLoopMode');    
```    
  
    
### on('toggleFavorite')<sup>(10+)</sup>    
设置是否收藏的监听事件  
 **调用形式：**     
    
- on(type: 'toggleFavorite', callback: (assetId: string) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'toggleFavorite'</code>：当是否收藏的命令被发送到会话时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数assetId是媒体ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('toggleFavorite', (assetId: string) => {  console.info(`on toggleFavorite mode : ${assetId}`);});    
```    
  
    
### off('toggleFavorite')<sup>(10+)</sup>    
取消监听是否收藏的事件  
 **调用形式：**     
    
- off(type: 'toggleFavorite', callback?: (assetId: string) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'toggleFavorite'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数assetId是媒体ID。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('toggleFavorite');    
```    
  
    
### on('handleKeyEvent')<sup>(10+)</sup>    
设置按键事件的监听  
 **调用形式：**     
    
- on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'handleKeyEvent'</code>：当按键事件被发送到会话时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数event是按键事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
import keyEvent from '@ohos.multimodalInput.keyEvent';  
currentAVSession.on('handleKeyEvent', (event: keyEvent.KeyEvent) => {  console.info(`on handleKeyEvent event : ${event}`);});    
```    
  
    
### off('handleKeyEvent')<sup>(10+)</sup>    
取消监听按键事件。  
 **调用形式：**     
    
- off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'handleKeyEvent'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数event是按键事件。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('handleKeyEvent');    
```    
  
    
### on('outputDeviceChange')<sup>(10+)</sup>    
设置播放设备变化的监听事件。  
 **调用形式：**     
    
- on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'outputDeviceChange'</code>：当播放设备变化时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数device是设备相关信息。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {  console.info(`on outputDeviceChange state: ${state}, device : ${device}`);});    
```    
  
    
### off('outputDeviceChange')<sup>(10+)</sup>    
取消监听播放设备变化的事件。  
 **调用形式：**     
    
- off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'outputDeviceChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数device是设备相关信息。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('outputDeviceChange');    
```    
  
    
### on('commonCommand')<sup>(10+)</sup>    
设置自定义控制命令变化的监听器。  
 **调用形式：**     
    
- on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'commonCommand'</code>：当自定义控制命令变化时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，commonCommand为变化的自定义控制命令名，args为自定义控制命令的参数，参数内容与sendCommand方法设置的参数内容完全一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import avSession from '@ohos.multimedia.avsession';  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  (currentAVSession as avSession.AVSession).on('commonCommand', (commonCommand, args) => {  
    console.info(`OnCommonCommand, the command is ${commonCommand}, args: ${JSON.stringify(args)}`);  
  });  
}  
    
```    
  
    
### off('commonCommand')<sup>(10+)</sup>    
取消监听自定义控制命令的变化。  
 **调用形式：**     
    
- off(type: 'commonCommand', callback?: (command: string, args: {[key: string]: Object}) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'commonCommand'</code>。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数command是变化的自定义控制命令名，args为自定义控制命令的参数。 该参数为可选参数，若不填写该参数，则认为取消所有对command事件的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('commonCommand');    
```    
  
    
### on('skipToQueueItem')<sup>(10+)</sup>    
设置播放列表其中某项被选中的监听事件，session端可以选择对这个单项歌曲进行播放。  
 **调用形式：**     
    
- on(type: 'skipToQueueItem', callback: (itemId: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'skipToQueueItem'</code>：当播放列表选中单项的命令被发送到会话时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数itemId是选中的播放列表项的ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.on('skipToQueueItem', (itemId: number) => {  console.info(`on skipToQueueItem id : ${itemId}`);});    
```    
  
    
### off('skipToQueueItem')<sup>(10+)</sup>    
取消监听播放列表单项选中的事件  
 **调用形式：**     
    
- off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'skipToQueueItem'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数itemId是播放列表单项ID。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
```ts    
currentAVSession.off('skipToQueueItem');    
```    
  
    
### stopCasting<sup>(10+)</sup>    
结束投播。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- stopCasting(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopCasting(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当成功结束投播，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600109 | The remote connection is not established. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.stopCasting((err: BusinessError) => {  
  if (err) {  
    console.info(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`stopCasting successfully`);  
  }  
});  
    
```    
  
    
### activate<sup>(10+)</sup>    
激活会话，激活后可正常使用会话。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- activate(callback: AsyncCallback\<void>): void    
起始版本： 10    
- activate(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当会话激活成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当会话激活成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.activate().then(() => {  
  console.info(`Activate : SUCCESS `);  
}).catch((err: BusinessError) => {  
  console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.activate((err: BusinessError) => {  
  if (err) {  
    console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`Activate : SUCCESS `);  
  }  
});  
    
```    
  
    
### deactivate<sup>(10+)</sup>    
禁用当前会话的功能，可通过activate恢复。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- deactivate(callback: AsyncCallback\<void>): void    
起始版本： 10    
- deactivate(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当禁用会话成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当禁用会话成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.activate((err: BusinessError) => {  
  if (err) {  
    console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`Activate : SUCCESS `);  
  }  
});  
    
```    
  
    
### destroy<sup>(10+)</sup>    
禁用当前会话。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- destroy(callback: AsyncCallback\<void>): void    
起始版本： 10    
- destroy(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当禁用会话成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当会话销毁成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.destroy().then(() => {  
  console.info(`Destroy : SUCCESS `);  
}).catch((err: BusinessError) => {  
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
currentAVSession.destroy((err: BusinessError) => {  
  if (err) {  
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`Destroy : SUCCESS `);  
  }  
});  
    
```    
  
    
## AVCastControlCommandType<sup>(10+)</sup>    
投播控制器可传递的命令。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
    
| 取值范围 | 说明 |  
| --------| --------|  
| play | 播放 |  
| pause | 暂停 |  
| stop | 停止 |  
| playNext | 下一首 |  
| playPrevious | 上一首 |  
| fastForward | 快进 |  
| rewind | 快退 |  
| seek | 跳转某一节点 |  
| setVolume | 设置音量 |  
| setSpeed | 设置播放倍速 |  
| setLoopMode | 设置循环模式 |  
| toggleFavorite | 是否收藏 |  
    
## AVCastControlCommand<sup>(10+)</sup>    
投播控制器接受的命令的对象描述。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| command<sup>(10+)</sup> | AVCastControlCommandType | false | true | 命令<br/> |  
| parameter<sup>(10+)</sup> | media.PlaybackSpeed \| number \| string \| LoopMode | false | false | 命令对应的参数。 |  
    
## AVCastController<sup>(10+)</sup>    
在投播建立后，调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#getavcastcontroller10">avSession.getAVCastController</a>后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
### getAVPlaybackState<sup>(10+)</sup>    
获取当前的远端播放状态。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void    
起始版本： 10    
- getAVPlaybackState(): Promise\<AVPlaybackState>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回远端播放状态。 |  
| Promise<AVPlaybackState> | Promise对象。返回远端播放状态。。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
aVCastController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {  
  if (err) {  
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`getAVPlaybackState : SUCCESS`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
aVCastController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {  
  console.info(`getAVPlaybackState : SUCCESS`);  
}).catch((err: BusinessError) => {  
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
### sendControlCommand<sup>(10+)</sup>    
通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void>): void    
起始版本： 10    
- sendControlCommand(command: AVCastControlCommand): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command | AVCastControlCommand | true | 会话的相关命令和命令相关参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600105 | Invalid session command. |  
| 6600109 | The remote connection is not established. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avCommand: avSession.AVCastControlCommand = {command:'play'};  
// let avCommand = {command:'pause'};  
// let avCommand = {command:'stop'};  
// let avCommand = {command:'playNext'};  
// let avCommand = {command:'playPrevious'};  
// let avCommand = {command:'fastForward'};  
// let avCommand = {command:'rewind'};  
// let avCommand = {command:'seek', parameter:10};  
aVCastController.sendControlCommand(avCommand).then(() => {  
  console.info(`SendControlCommand successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avCommand: avSession.AVCastControlCommand = {command:'play'};  
// let avCommand = {command:'pause'};  
// let avCommand = {command:'stop'};  
// let avCommand = {command:'playNext'};  
// let avCommand = {command:'playPrevious'};  
// let avCommand = {command:'fastForward'};  
// let avCommand = {command:'rewind'};  
// let avCommand = {command:'seek', parameter:10};  
aVCastController.sendControlCommand(avCommand, (err: BusinessError) => {  
  if (err) {  
    console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SendControlCommand successfully`);  
  }  
});  
    
```    
  
    
### start<sup>(10+)</sup>    
启动播放某个媒体资源。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- start(item: AVQueueItem, callback: AsyncCallback\<void>): void    
起始版本： 10    
- start(item: AVQueueItem): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| item | AVQueueItem | true | 播放列表中单项的相关属性。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600109 | The remote connection is not established. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
let sessionId: string = "";  //供后续函数入参使用  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
    if (currentAVSession !== undefined) {  
      sessionId = currentAVSession.sessionId;  
    }  
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);  
  }  
});  
  
let myToken: avSession.SessionToken = {  
  sessionId: sessionId,  
}  
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;  
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {  
  castDevice = device;  
  console.info(`on deviceAvailable  : ${device} `);  
});  
if (castDevice !== undefined) {  
  avSession.startCasting(myToken, castDevice, (err: BusinessError) => {  
    if (err) {  
      console.error(`startCasting BusinessError: code: ${err.code}, message: ${err.message}`);  
    } else {  
      console.info(`startCasting successfully`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
let sessionId: string = "";  //供后续函数入参使用  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
    if (currentAVSession !== undefined) {  
      sessionId = currentAVSession.sessionId;  
    }  
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);  
  }  
});  
  
let myToken: avSession.SessionToken = {  
  sessionId: sessionId,  
}  
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;  
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {  
  castDevice = device;  
  console.info(`on deviceAvailable  : ${device} `);  
});  
if (castDevice !== undefined) {  
  avSession.startCasting(myToken, castDevice).then(() => {  
    console.info(`startCasting successfully`);  
  }).catch((err: BusinessError) => {  
    console.error(`startCasting BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
    
```    
  
    
### prepare<sup>(10+)</sup>    
准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void    
起始版本： 10    
- prepare(item: AVQueueItem): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| item | AVQueueItem | true | 播放列表中单项的相关属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600109 | The remote connection is not established. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
// 设置播放参数，开始播放  
let playItem: avSession.AVQueueItem = {  
  itemId: 0,  
  description: {  
    assetId: '12345',  
    mediaType: 'AUDIO',  
    mediaUri: 'http://resource1_address',  
    mediaSize: 12345,  
    startPosition: 0,  
    duration: 0,  
    artist: 'mysong',  
    albumTitle: 'song1_title',  
    albumCoverUri: "http://resource1_album_address",  
    lyricUri: "http://resource1_lyric_address",  
    appName: 'MyMusic'  
  }  
};  
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲  
aVCastController.prepare(playItem, (err: BusinessError) => {  
  if (err) {  
    console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`prepare successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
// 设置播放参数，开始播放  
let playItem: avSession.AVQueueItem = {  
  itemId: 0,  
  description: {  
    assetId: '12345',  
    mediaType: 'AUDIO',  
    mediaUri: 'http://resource1_address',  
    mediaSize: 12345,  
    startPosition: 0,  
    duration: 0,  
    artist: 'mysong',  
    albumTitle: 'song1_title',  
    albumCoverUri: "http://resource1_album_address",  
    lyricUri: "http://resource1_lyric_address",  
    appName: 'MyMusic'  
  }  
};  
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲  
aVCastController.prepare(playItem).then(() => {  
  console.info(`prepare successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
### getCurrentItem<sup>(10+)</sup>    
获取当前投播的资源信息。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- getCurrentItem(callback: AsyncCallback\<AVQueueItem>): void    
起始版本： 10    
- getCurrentItem(): Promise\<AVQueueItem>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<AVQueueItem> | Promise对象，返回当前的播放资源，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
aVCastController.getCurrentItem((err: BusinessError, value: avSession.AVQueueItem) => {  
  if (err) {  
    console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`getCurrentItem successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
aVCastController.getCurrentItem().then((value: avSession.AVQueueItem) => {  
  console.info(`getCurrentItem successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
### on('playbackStateChange')<sup>(10+)</sup>    
设置播放状态变化的监听事件。  
 **调用形式：**     
    
- on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'playbackStateChange'</code>：当播放状态变化时，触发该事件。<br/> |  
| filter | string | true | 'all' 表示关注播放状态所有字段变化；Array<keyof<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#avplaybackstate10">AVPlaybackState</a>> 表示关注Array中的字段变化。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数state是变化后的播放状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {  console.info(`on playbackStateChange state : ${playbackState.state}`);});  
let playbackFilter = ['state', 'speed', 'loopMode'];aVCastController.on('playbackStateChange', playbackFilter, (playbackState: avSession.AVPlaybackState) => {  console.info(`on playbackStateChange state : ${playbackState.state}`);});    
```    
  
    
### off('playbackStateChange')<sup>(10+)</sup>    
媒体控制器取消监听播放状态变化的事件。  
 **调用形式：**     
    
- off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'playbackStateChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数state是变化后的播放状态。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('playbackStateChange');    
```    
  
    
### on('mediaItemChange')<sup>(10+)</sup>    
设置投播当前播放媒体内容的监听事件。  
 **调用形式：**     
    
- on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'mediaItemChange'</code>：当播放的媒体内容变化时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.on('mediaItemChange', (item: avSession.AVQueueItem) => {  console.info(`on mediaItemChange state : ${item.itemId}`);});    
```    
  
    
### off('mediaItemChange')<sup>(10+)</sup>    
取消设置投播当前播放媒体内容的监听事件。  
 **调用形式：**     
- off(type: 'mediaItemChange'): void  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'mediaItemChange'</code>。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('mediaItemChange');    
```    
  
    
### on('playNext')<sup>(10+)</sup>    
设置播放下一首资源的监听事件。  
 **调用形式：**     
    
- on(type: 'playNext', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'playNext'</code>：当播放下一首状态变化时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.on('playNext', () => {  console.info(`on playNext`);});    
```    
  
    
### off('playNext')<sup>(10+)</sup>    
取消设置播放下一首资源的监听事件。  
 **调用形式：**     
- off(type: 'playNext'): void  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'playNext'</code>。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('playNext');    
```    
  
    
### on('playPrevious')<sup>(10+)</sup>    
设置播放上一首资源的监听事件。  
 **调用形式：**     
    
- on(type: 'playPrevious', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'playPrevious'</code>：当播放上一首状态变化时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.on('playPrevious', () => {  console.info(`on playPrevious`);});    
```    
  
    
### off('playPrevious')<sup>(10+)</sup>    
取消会话播放上一首事件监听，关闭后，不再进行该事件回调。  
 **调用形式：**     
- off(type: 'playPrevious'): void  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持的事件是<code>'playPrevious'</code>。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('playPrevious');    
```    
  
    
### on('seekDone')<sup>(10+)</sup>    
设置seek结束的监听事件。  
 **调用形式：**     
    
- on(type: 'seekDone', callback: Callback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'seekDone'</code>：当seek结束时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回seek后播放的位置 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.on('seekDone', (pos: number) => {  console.info(`on seekDone pos：${pos} `);});    
```    
  
    
### off('seekDone')<sup>(10+)</sup>    
取消设置seek结束的监听事件。  
 **调用形式：**     
- off(type: 'seekDone'): void  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'seekDone'</code>。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('seekDone');    
```    
  
    
### on('error')<sup>(10+)</sup>    
监听远端播放器的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 错误事件回调方法：远端播放过程中发生的错误，会提供错误码ID和错误信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | 错误事件回调方法：远端播放过程中发生的错误，会提供错误码ID和错误信息。 |  
| 5400101 | No memory. |  
| 5400102 | Operation not allowed. |  
| 5400103 | I/O error. |  
| 5400104 | Time out. |  
| 5400105 | Service died. |  
| 5400106 | Unsupport format. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
aVCastController.on('error', (error: BusinessError) => {  
  console.error('error happened,and error message is :' + error.message)  
  console.error('error happened,and error code is :' + error.code)  
})  
    
```    
  
    
### off('error')<sup>(10+)</sup>    
取消监听播放的错误事件。  
 **调用形式：**     
- off(type: 'error'): void  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 错误事件回调类型，取消注册的事件：'error'<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 5400101 | No memory. |  
| 5400102 | Operation not allowed. |  
| 5400103 | I/O error. |  
| 5400104 | Time out. |  
| 5400105 | Service died. |  
| 5400106 | Unsupport format. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('error')    
```    
  
    
## ConnectionState<sup>(10+)</sup>    
连接状态枚举。    
    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_CONNECTING | 0 | 设备连接中<br/> |  
| STATE_CONNECTED | 1 | 设备连接成功<br/> |  
| STATE_DISCONNECTED | 6 | 设备断开连接。 |  
    
## AVMetadata    
媒体元数据的相关属性。    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| assetId<sup>(10+)</sup> | string | false | true | 媒体ID。<br/> |  
| title<sup>(10+)</sup> | string | false | false | 标题。<br/> |  
| artist<sup>(10+)</sup> | string | false | false | 艺术家。<br/> |  
| author<sup>(10+)</sup> | string | false | false | 专辑作者。<br/> |  
| album<sup>(10+)</sup> | string | false | false | 专辑名称。<br/> |  
| writer<sup>(10+)</sup> | string | false | false | 词作者。<br/> |  
| composer<sup>(10+)</sup> | string | false | false | 作曲者。<br/> |  
| duration<sup>(10+)</sup> | number | false | false | 媒体时长，单位毫秒（ms）。<br/> |  
| mediaImage<sup>(10+)</sup> | image.PixelMap \| string | false | false | 图片的像素数据或者图片路径地址(本地路径或网络路径)。<br/> |  
| publishDate<sup>(10+)</sup> | Date | false | false | 发行日期。<br/> |  
| subtitle<sup>(10+)</sup> | string | false | false | 子标题。<br/> |  
| description<sup>(10+)</sup> | string | false | false | 媒体描述。<br/> |  
| lyric<sup>(10+)</sup> | string | false | false | 歌词文件路径地址(本地路径或网络路径)<br/> |  
| previousAssetId<sup>(10+)</sup> | string | false | false | 上一首媒体ID。<br/> |  
| nextAssetId<sup>(10+)</sup> | string | false | false | 下一首媒体ID。<br/> |  
    
## AVMediaDescription<sup>(10+)</sup>    
播放列表媒体元数据的相关属性。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| assetId<sup>(10+)</sup> | string | false | true | 播放列表媒体ID。<br/> |  
| title<sup>(10+)</sup> | string | false | false | 播放列表媒体标题。<br/> |  
| subtitle<sup>(10+)</sup> | string | false | false | 播放列表媒体子标题。<br/> |  
| description<sup>(10+)</sup> | string | false | false | 播放列表媒体描述的文本。<br/> |  
| mediaImage<sup>(10+)</sup> | image.PixelMap \| string | false | false | 播放列表媒体图片像素数据。<br/> |  
| extras<sup>(10+)</sup> | {[key: string]: Object} | false | false | 播放列表媒体额外字段。<br/> |  
| mediaType<sup>(10+)</sup> | string | false | false | 播放列表媒体类型。<br/> |  
| mediaSize<sup>(10+)</sup> | number | false | false | 播放列表媒体的大小。<br/> |  
| albumTitle<sup>(10+)</sup> | string | false | false | 播放列表媒体专辑标题。 |  
| albumCoverUri<sup>(10+)</sup> | string | false | false | 播放列表媒体专辑标题URI。<br/> |  
| lyricContent<sup>(10+)</sup> | string | false | false | 播放列表媒体歌词内容。<br/> |  
| lyricUri<sup>(10+)</sup> | string | false | false | 播放列表媒体歌词URI。<br/> |  
| artist<sup>(10+)</sup> | string | false | false | 播放列表媒体专辑作者。<br/> |  
| mediaUri<sup>(10+)</sup> | string | false | false | 播放列表媒体URI。<br/> |  
| fdSrc<sup>(10+)</sup> | media.AVFileDescriptor | false | false | 播放列表媒体本地文件的句柄。<br/> |  
| duration<sup>(10+)</sup> | number | false | false | 播放列表媒体播放时长。<br/> |  
| startPosition<sup>(10+)</sup> | number | false | false | 播放列表媒体起始播放位置。<br/> |  
| creditsPosition<sup>(10+)</sup> | number | false | false | 播放列表媒体的片尾播放位置。<br/> |  
| appName<sup>(10+)</sup> | string | false | false | 播放列表提供的应用的名字。 |  
    
## AVQueueItem<sup>(10+)</sup>    
播放列表中单项的相关属性。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| itemId<sup>(10+)</sup> | number | false | true | 播放列表中单项的ID。<br/> |  
| description<sup>(10+)</sup> | AVMediaDescription | false | false | 播放列表中单项的媒体元数据。 |  
    
## AVPlaybackState<sup>(10+)</sup>    
媒体播放状态的相关属性。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| state<sup>(10+)</sup> | PlaybackState | false | false | 播放状态<br/> |  
| speed<sup>(10+)</sup> | number | false | false | 播放倍速<br/> |  
| position<sup>(10+)</sup> | PlaybackPosition | false | false | 播放位置<br/> |  
| bufferedTime<sup>(10+)</sup> | number | false | false | 缓冲时间<br/> |  
| loopMode<sup>(10+)</sup> | LoopMode | false | false | 循环模式<br/> |  
| isFavorite<sup>(10+)</sup> | boolean | false | false | 是否收藏<br/> |  
| activeItemId<sup>(10+)</sup> | number | false | false | 正在播放的媒体Id<br/> |  
| volume<sup>(10+)</sup> | number | false | false | 正在播放的媒体音量<br/> |  
| extras<sup>(10+)</sup> | {[key: string]: Object} | false | false | 自定义媒体数据。 |  
    
## PlaybackPosition<sup>(10+)</sup>    
媒体播放位置的相关属性。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| elapsedTime<sup>(10+)</sup> | number | false | true | 已用时间，单位毫秒（ms）。<br/> |  
| updateTime<sup>(10+)</sup> | number | false | true | 更新时间，单位毫秒（ms）。 |  
    
## AVCastCategory<sup>(10+)</sup>    
投播的类别枚举。    
    
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CATEGORY_LOCAL | 0 | 本地播放，默认播放设备，声音从本机或者连接的蓝牙耳机设备出声。<br/> |  
| CATEGORY_REMOTE | 1 | 远端播放，远端播放设备，声音从其他设备发出声音或者画面。 |  
    
## DeviceType<sup>(10+)</sup>    
播放设备的类型枚举。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_TYPE_LOCAL | 0 | 系统能力：SystemCapability.Multimedia.AVSession.Core<br>本地播放类型。 |  
| DEVICE_TYPE_TV | 2 | 系统能力：SystemCapability.Multimedia.AVSession.AVCast<br><span style="font-size: 14px; letter-spacing: 0px;">电视</span><br/><strong>系统能力：</strong>SystemCapability.Multimedia.AVSession.AVCast |  
| DEVICE_TYPE_SMART_SPEAKER | 3 | 系统能力：SystemCapability.Multimedia.AVSession.AVCast<br>音箱设备<br/><strong>系统能力：</strong>SystemCapability.Multimedia.AVSession.AVCast<br/> |  
| DEVICE_TYPE_BLUETOOTH | 10 | 系统能力：SystemCapability.Multimedia.AVSession.Core<br>蓝牙设备<br/> |  
    
## DeviceInfo<sup>(10+)</sup>    
播放设备的相关信息。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| castCategory<sup>(10+)</sup> | AVCastCategory | false | true | 投播的类别。<br/> |  
| deviceId<sup>(10+)</sup> | string | false | true | 播放设备的ID。<br/> |  
| deviceName<sup>(10+)</sup> | string | false | true | 播放设备的名称。<br/> |  
| deviceType<sup>(10+)</sup> | DeviceType | false | true | 播放设备的类型。<br/> |  
    
## OutputDeviceInfo<sup>(10+)</sup>    
播放设备的相关信息。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| devices<sup>(10+)</sup> | Array<DeviceInfo> | false | true | 播放设备的集合。<br/> |  
    
## LoopMode<sup>(10+)</sup>    
表示媒体播放循环模式的枚举。    
    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOOP_MODE_SEQUENCE | 0 | 顺序播放<br/> |  
| LOOP_MODE_SINGLE | 1 | 单曲循环<br/> |  
| LOOP_MODE_LIST | 2 | 表单循环<br/> |  
| LOOP_MODE_SHUFFLE | 3 | 随机播放。 |  
    
## PlaybackState<sup>(10+)</sup>    
表示媒体播放状态的枚举。    
    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PLAYBACK_STATE_INITIAL | 0 | 初始状态<br/> |  
| PLAYBACK_STATE_PREPARE | 1 | 播放准备状态<br/> |  
| PLAYBACK_STATE_PLAY | 2 | 正在播放<br/> |  
| PLAYBACK_STATE_PAUSE | 3 | 暂停<br/> |  
| PLAYBACK_STATE_FAST_FORWARD | 4 | 快进<br/> |  
| PLAYBACK_STATE_REWIND | 5 | 快退<br/> |  
| PLAYBACK_STATE_STOP | 6 | 停止<br/> |  
| PLAYBACK_STATE_COMPLETED | 7 | 播放完成<br/> |  
| PLAYBACK_STATE_RELEASED | 8 | 释放<br/> |  
| PLAYBACK_STATE_ERROR | 9 | 错误。 |  
    
## AVSessionController<sup>(10+)</sup>    
调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#avsessioncreatecontroller">avSession.createController</a>后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sessionId<sup>(10+)</sup> | string | true | true | AVSessionController对象唯一的会话标识。<br/> |  
    
### getAVPlaybackState<sup>(10+)</sup>    
获取当前的远端播放状态。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void    
起始版本： 10    
- getAVPlaybackState(): Promise\<AVPlaybackState>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回远端播放状态。 |  
| Promise<AVPlaybackState> | Promise对象。返回远端播放状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
aVCastController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {  
  if (err) {  
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`getAVPlaybackState : SUCCESS`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
aVCastController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {  
  console.info(`getAVPlaybackState : SUCCESS`);  
}).catch((err: BusinessError) => {  
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
### getAVPlaybackStateSync<sup>(10+)</sup>    
使用同步方法获取当前会话的播放状态。  
 **调用形式：**     
- getAVPlaybackStateSync(): AVPlaybackState  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AVPlaybackState | 当前会话的播放状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let playbackState: avsession.AVPlaybackState = avsessionController.getAVPlaybackStateSync();  
} catch (err: BusinessError) {  
  console.info(`getAVPlaybackStateSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### getAVMetadata<sup>(10+)</sup>    
使用同步方法获取会话元数据。  
 **调用形式：**     
    
- getAVMetadata(callback: AsyncCallback\<AVMetadata>): void    
起始版本： 10    
- getAVMetadata(): Promise\<AVMetadata>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回会话元数据。 |  
| Promise<AVMetadata> | Promise对象，返回会话元数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getAVMetadata().then((metadata: avSession.AVMetadata) => {  
  console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);  
}).catch((err: BusinessError) => {  
  console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getAVMetadata((err: BusinessError, metadata: avSession.AVMetadata) => {  
  if (err) {  
    console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);  
  }  
});  
    
```    
  
    
### getAVMetadataSync<sup>(10+)</sup>    
使用同步方法获取会话元数据。  
 **调用形式：**     
- getAVMetadataSync(): AVMetadata  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AVMetadata | 会话元数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let metaData: avsession.AVMetadata = avsessionController.getAVMetadataSync();  
} catch (err: BusinessError) {  
  console.info(`getAVMetadataSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### getAVQueueTitle<sup>(10+)</sup>    
获取当前会话播放列表的名称。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getAVQueueTitle(callback: AsyncCallback\<string>): void    
起始版本： 10    
- getAVQueueTitle(): Promise\<string>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回播放列表名称。 |  
| Promise<string> | Promise对象。返回播放列表名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getAVQueueTitle().then((title: string) => {  
  console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);  
}).catch((err: BusinessError) => {  
  console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getAVQueueTitle((err: BusinessError, title: string) => {  
  if (err) {  
    console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);  
  }  
});  
    
```    
  
    
### getAVQueueTitleSync<sup>(10+)</sup>    
使用同步方法获取当前会话播放列表的名称。  
 **调用形式：**     
- getAVQueueTitleSync(): string  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前会话播放列表名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let currentQueueTitle: string = avsessionController.getAVQueueTitleSync();  
} catch (err: BusinessError) {  
  console.info(`getAVQueueTitleSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### getAVQueueItems<sup>(10+)</sup>    
获取当前会话播放列表相关信息。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void    
起始版本： 10    
- getAVQueueItems(): Promise\<Array\<AVQueueItem>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回播放列表队列。 |  
| Promise<Array<AVQueueItem>> | Promise对象。返回播放列表队列。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let currentQueueItems: Array<avsession.AVQueueItem> = avsessionController.getAVQueueItemsSync();  
} catch (err: BusinessError) {  
  console.info(`getAVQueueItemsSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### getAVQueueItemsSync<sup>(10+)</sup>    
使用同步方法获取当前会话播放列表相关信息。  
 **调用形式：**     
- getAVQueueItemsSync(): Array\<AVQueueItem>  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<AVQueueItem> | 当前会话播放列表队列。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let currentQueueItems: Array<avsession.AVQueueItem> = avsessionController.getAVQueueItemsSync();  
} catch (err: BusinessError) {  
  console.info(`getAVQueueItemsSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### skipToQueueItem<sup>(10+)</sup>    
设置指定播放列表单项的ID，发送给session端处理，session端可以选择对这个单项歌曲进行播放。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- skipToQueueItem(itemId: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| itemId | number | true | 播放列表单项的ID值，用以表示选中的播放列表单项。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当播放列表单项ID设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let queueItemId = 0;  
avsessionController.skipToQueueItem(queueItemId).then(() => {  
  console.info(`SkipToQueueItem successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let queueItemId = 0;  
avsessionController.skipToQueueItem(queueItemId, (err: BusinessError) => {  
  if (err) {  
    console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SkipToQueueItem successfully`);  
  }  
});  
    
```    
  
    
### getOutputDevice<sup>(10+)</sup>    
获取播放设备信息。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void    
起始版本： 10    
- getOutputDevice(): Promise\<OutputDeviceInfo>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回播放设备信息。 |  
| Promise<OutputDeviceInfo> | Promise对象，返回播放设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 600101 | Session service exception. |  
| 600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getOutputDevice().then((deviceInfo: avSession.OutputDeviceInfo) => {  
  console.info(`GetOutputDevice : SUCCESS`);  
}).catch((err: BusinessError) => {  
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getOutputDevice((err: BusinessError, deviceInfo: avSession.OutputDeviceInfo) => {  
  if (err) {  
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetOutputDevice : SUCCESS`);  
  }  
});  
    
```    
  
    
### getOutputDeviceSync<sup>(10+)</sup>    
使用同步方法获取当前输出设备信息。  
 **调用形式：**     
- getOutputDeviceSync(): OutputDeviceInfo  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| OutputDeviceInfo | 当前输出设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let currentOutputDevice: avSession.OutputDeviceInfo = avsessionController.getOutputDeviceSync();  
} catch (err: BusinessError) {  
  console.info(`getOutputDeviceSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### sendAVKeyEvent<sup>(10+)</sup>    
发送按键事件到控制器对应的会话。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void    
起始版本： 10    
- sendAVKeyEvent(event: KeyEvent): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | KeyEvent | true | 按键事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 600101 | Session service exception. |  
| 600102 | The session does not exist. |  
| 600103 | The session controller does not exist. |  
| 600105 | Invalid session command. |  
| 600106 | The session is not activated. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
```ts  
import keyEvent from '@ohos.multimodalInput.keyEvent';  
import { BusinessError } from '@ohos.base';  
  
let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};  
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};  
  
avsessionController.sendAVKeyEvent(event).then(() => {  
  console.info(`SendAVKeyEvent Successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback<span style="letter-spacing: 0px;">）：</span>  
```ts    
import keyEvent from '@ohos.multimodalInput.keyEvent';  
import { BusinessError } from '@ohos.base';  
  
let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};  
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};  
  
avsessionController.sendAVKeyEvent(event, (err: BusinessError) => {  
  if (err) {  
    console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SendAVKeyEvent Successfully`);  
  }  
});  
    
```    
  
    
### getLaunchAbility<sup>(10+)</sup>    
获取应用在会话中保存的WantAgent对象。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getLaunchAbility(callback: AsyncCallback\<WantAgent>): void    
起始版本： 10    
- getLaunchAbility(): Promise\<WantAgent>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回在setLaunchAbility保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |  
| Promise<WantAgent> | Promise对象，返回在setLaunchAbility保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getLaunchAbility().then((agent: object) => {  
  console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);  
}).catch((err: BusinessError) => {  
  console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getLaunchAbility((err: BusinessError, agent: object) => {  
  if (err) {  
    console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);  
  }  
});  
    
```    
  
    
### getRealPlaybackPositionSync<sup>(10+)</sup>    
获取当前播放位置。  
 **调用形式：**     
- getRealPlaybackPositionSync(): number  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 时间节点，毫秒数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
let time: number = avsessionController.getRealPlaybackPositionSync();    
```    
  
    
### isActive<sup>(10+)</sup>    
获取会话是否被激活。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- isActive(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isActive(): Promise\<boolean>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回会话是否为激活状态，true表示被激活，false表示禁用。 |  
| Promise<boolean> | Promise对象，返回会话是否为激活状态，true表示被激活，false表示禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.isActive().then((isActive: boolean) => {  
  console.info(`IsActive : SUCCESS : isactive : ${isActive}`);  
}).catch((err: BusinessError) => {  
  console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.isActive((err: BusinessError, isActive: boolean) => {  
  if (err) {  
    console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);  
  }  
});  
    
```    
  
    
### isActiveSync<sup>(10+)</sup>    
使用同步方法判断会话是否被激活。  
 **调用形式：**     
- isActiveSync(): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let isActive: boolean = avsessionController.isActiveSync();  
} catch (err: BusinessError) {  
  console.info(`isActiveSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### destroy<sup>(10+)</sup>    
销毁当前会话，使当前会话完全失效。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- destroy(callback: AsyncCallback\<void>): void    
起始版本： 10    
- destroy(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当会话销毁成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当会话销毁成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600103 | The session does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.destroy().then(() => {  
  console.info(`Destroy : SUCCESS `);  
}).catch((err: BusinessError) => {  
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.destroy((err: BusinessError) => {  
  if (err) {  
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`Destroy : SUCCESS `);  
  }  
});  
    
```    
  
    
### getValidCommands<sup>(10+)</sup>    
获取会话支持的有效命令。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void    
起始版本： 10    
- getValidCommands(): Promise\<Array\<AVControlCommandType>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回有效命令的集合。 |  
| Promise<Array<AVControlCommandType>> | Promise对象。返回有效命令的集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getValidCommands().then((validCommands: avSession.AVControlCommandType[]) => {  
  console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);  
}).catch((err: BusinessError) => {  
  console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avsessionController.getValidCommands((err: BusinessError, validCommands: avSession.AVControlCommandType[]) => {  
  if (err) {  
    console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);  
  }  
});  
    
```    
  
    
### getValidCommandsSync<sup>(10+)</sup>    
使用同步方法获取会话支持的有效命令。  
 **调用形式：**     
- getValidCommandsSync(): Array\<AVControlCommandType>  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<AVControlCommandType> | 会话支持的有效命令的集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let validCommands: Array<avSession.AVControlCommandType> = avsessionController.getValidCommandsSync();  
} catch (err: BusinessError) {  
  console.info(`getValidCommandsSync error, error code: ${err.code}, error message: ${err.message}`);  
}  
    
```    
  
    
### sendControlCommand<sup>(10+)</sup>    
通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void    
起始版本： 10    
- sendControlCommand(command: AVControlCommand): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command | AVControlCommand | true | 会话的相关命令和命令相关参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回有效命令的集合。 |  
| Promise<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
| 6600105 | Invalid session command. |  
| 6600106 | The session is not activated. |  
| 6600107 | Too many commands or events. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avCommand: avSession.AVCastControlCommand = {command:'play'};  
// let avCommand = {command:'pause'};  
// let avCommand = {command:'stop'};  
// let avCommand = {command:'playNext'};  
// let avCommand = {command:'playPrevious'};  
// let avCommand = {command:'fastForward'};  
// let avCommand = {command:'rewind'};  
// let avCommand = {command:'seek', parameter:10};  
aVCastController.sendControlCommand(avCommand).then(() => {  
  console.info(`SendControlCommand successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avCommand: avSession.AVCastControlCommand = {command:'play'};  
// let avCommand = {command:'pause'};  
// let avCommand = {command:'stop'};  
// let avCommand = {command:'playNext'};  
// let avCommand = {command:'playPrevious'};  
// let avCommand = {command:'fastForward'};  
// let avCommand = {command:'rewind'};  
// let avCommand = {command:'seek', parameter:10};  
aVCastController.sendControlCommand(avCommand, (err: BusinessError) => {  
  if (err) {  
    console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SendControlCommand successfully`);  
  }  
});  
    
```    
  
    
### sendCommonCommand<sup>(10+)</sup>    
通过会话控制器发送自定义控制命令到其对应的会话。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void    
起始版本： 10    
- sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command | string | true | 需要设置的自定义控制命令的名称<br/> |  
| args | {[key: string]: Object} | true | 需要传递的控制命令键值对<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
| 6600105 | Invalid session command. |  
| 6600106 | The session is not activated. |  
| 6600107 | Too many commands or events. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avSessionController: avSession.AVSessionController | undefined = undefined;  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
let sessionId: string = "";  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  sessionId = (currentAVSession as avSession.AVSession).sessionId;  
  avSession.createController(sessionId).then((controller: avSession.AVSessionController) => {  
    avSessionController = controller;  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
  
let commandName = "my_command";  
if (avSessionController !== undefined) {  
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}).then(() => {  
    console.info(`SendCommonCommand successfully`);  
  }).catch((err: BusinessError) => {  
    console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
let avSessionController: avSession.AVSessionController | undefined = undefined;  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {  
    avSessionController = controller;  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
  
let commandName = "my_command";  
if (avSessionController !== undefined) {  
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}, (err: BusinessError) => {  
    if(err) {  
        console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
    }  
  })  
}  
    
```    
  
    
### getExtras<sup>(10+)</sup>    
获取媒体提供方设置的自定义媒体数据包。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void    
起始版本： 10    
- getExtras(): Promise\<{[key: string]: Object}>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回媒体提供方设置的自定义媒体数据包，数据包的内容与setExtras设置的内容完全一致。 |  
| Promise<{[key: string]: Object}> | Promise对象，返回媒体提供方设置的自定义媒体数据包，数据包的内容与setExtras设置的内容完全一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600103 | The session controller does not exist. |  
| 6600105 | Invalid session command. |  
| 6600107 | Too many commands or events. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avSessionController: avSession.AVSessionController | undefined = undefined;  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {  
    avSessionController = controller;  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
  
if (avSessionController !== undefined) {  
  (avSessionController as avSession.AVSessionController).getExtras().then((extras) => {  
    console.info(`getExtras : SUCCESS : ${extras}`);  
  }).catch((err: BusinessError) => {  
    console.info(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avSessionController: avSession.AVSessionController | undefined = undefined;  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {  
    avSessionController = controller;  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
  
if (avSessionController !== undefined) {  
  (avSessionController as avSession.AVSessionController).getExtras((err, extras) => {  
    if (err) {  
      console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);  
    } else {  
      console.info(`getExtras : SUCCESS : ${extras}`);  
    }  
  });  
}  
    
```    
  
    
### on('metadataChange')<sup>(10+)</sup>    
设置元数据变化的监听事件。  
 **调用形式：**     
    
- on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'metadataChange'</code>：当元数据变化时，触发该事件。<br/> |  
| filter | string | true | 'all' 表示关注元数据所有字段变化；Array<keyof<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#avmetadata10">AVMetadata</a>> 表示关注Array中的字段变化。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数data是变化后的元数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('metadataChange', 'all', (metadata: avSession.AVMetadata) => {  console.info(`on metadataChange assetId : ${metadata.assetId}`);});  
avsessionController.on('metadataChange', ['assetId', 'title', 'description'], (metadata: avSession.AVMetadata) => {  console.info(`on metadataChange assetId : ${metadata.assetId}`);});    
```    
  
    
### off('metadataChange')<sup>(10+)</sup>    
媒体控制器取消监听元数据变化的事件。  
 **调用形式：**     
    
- off(type: 'metadataChange', callback?: (data: AVMetadata) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'metadataChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数data是变化后的元数据。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('metadataChange');    
```    
  
    
### on('playbackStateChange')<sup>(10+)</sup>    
设置播放状态变化的监听事件。  
 **调用形式：**     
    
- on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'playbackStateChange'</code>：当播放状态变化时，触发该事件。<br/> |  
| filter | string | true | 'all' 表示关注播放状态所有字段变化；Array<keyof<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#avplaybackstate10">AVPlaybackState</a>> 表示关注Array中的字段变化。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数state是变化后的播放状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {  console.info(`on playbackStateChange state : ${playbackState.state}`);});  
avsessionController.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: avSession.AVPlaybackState) => {  console.info(`on playbackStateChange state : ${playbackState.state}`);});    
```    
  
    
### off('playbackStateChange')<sup>(10+)</sup>    
媒体控制器取消监听播放状态变化的事件。  
 **调用形式：**     
    
- off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'playbackStateChange'</code>。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数state是变化后的播放状态。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('playbackStateChange');    
```    
  
    
### on('sessionDestroy')<sup>(10+)</sup>    
会话销毁的监听事件。  
 **调用形式：**     
    
- on(type: 'sessionDestroy', callback: () => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'sessionDestroy'</code>：当检测到会话销毁时，触发该事件）。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('sessionDestroy', () => {  console.info(`on sessionDestroy : SUCCESS `);});    
```    
  
    
### off('sessionDestroy')<sup>(10+)</sup>    
取消会话销毁事件监听，取消后，不再进行该事件的监听。  
 **调用形式：**     
    
- off(type: 'sessionDestroy', callback?: () => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为<code>'sessionDestroy'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('sessionDestroy');    
```    
  
    
### on('activeStateChange')<sup>(10+)</sup>    
会话的激活状态的监听事件。  
 **调用形式：**     
    
- on(type: 'activeStateChange', callback: (isActive: boolean) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'activeStateChange'</code>：当检测到会话的激活状态发生改变时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('activeStateChange', (isActive: boolean) => {  console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);});    
```    
  
    
### off('activeStateChange')<sup>(10+)</sup>    
媒体控制器取消监听会话激活状态变化的事件。  
 **调用形式：**     
    
- off(type: 'activeStateChange', callback?: (isActive: boolean) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'activeStateChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('activeStateChange');    
```    
  
    
### on('validCommandChange')<sup>(10+)</sup>    
会话支持的有效命令变化监听事件。  
 **调用形式：**     
    
- on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'validCommandChange'</code>：当检测到会话的合法命令发生改变时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数commands是有效命令的集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('validCommandChange', (validCommands: avSession.AVControlCommandType[]) => {  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);});    
```    
  
    
### off('validCommandChange')<sup>(10+)</sup>    
媒体控制器取消监听会话有效命令变化的事件。  
 **调用形式：**     
    
- off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'validCommandChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数commands是有效命令的集合。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('validCommandChange');    
```    
  
    
### on('outputDeviceChange')<sup>(10+)</sup>    
设置播放设备变化的监听事件。  
 **调用形式：**     
    
- on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件为<code>'outputDeviceChange'</code>：当播放设备变化时，触发该事件）。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数device是设备相关信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {  console.info(`on outputDeviceChange state: ${state}, device : ${device}`);});    
```    
  
    
### off('outputDeviceChange')<sup>(10+)</sup>    
取消监听播放设备变化的事件。  
 **调用形式：**     
    
- off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 关闭对应的监听事件，支持关闭事件<code>'outputDeviceChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数device是设备相关信息。 当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('outputDeviceChange');    
```    
  
    
### on('sessionEvent')<sup>(10+)</sup>    
媒体控制器设置会话自定义事件变化的监听器。  
 **调用形式：**     
    
- on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key: string]: Object}) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'sessionEvent'</code>：当会话事件变化时，触发该事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，sessionEvent为变化的会话事件名，args为事件的参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avSessionController: avSession.AVSessionController | undefined = undefined;  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {  
    avSessionController = controller;  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
  
if (avSessionController !== undefined) {  
  (avSessionController as avSession.AVSessionController).on('sessionEvent', (sessionEvent, args) => {  
    console.info(`OnSessionEvent, sessionEvent is ${sessionEvent}, args: ${JSON.stringify(args)}`);  
  });  
}  
    
```    
  
    
### off('sessionEvent')<sup>(10+)</sup>    
媒体控制器取消监听会话事件的变化通知。  
 **调用形式：**     
    
- off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key: string]: Object}) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'sessionEvent'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数sessionEvent是变化的事件名，args为事件的参数。 该参数为可选参数，若不填写该参数，则认为取消所有对sessionEvent事件的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('sessionEvent');    
```    
  
    
### on('queueItemsChange')<sup>(10+)</sup>    
媒体控制器设置会话自定义播放列表变化的监听器。  
 **调用形式：**     
    
- on(type: 'queueItemsChange', callback: (items: Array\<AVQueueItem>) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'queueItemsChange'</code>：当session修改播放列表时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，items为变化的播放列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('queueItemsChange', (items: avSession.AVQueueItem[]) => {  console.info(`OnQueueItemsChange, items length is ${items.length}`);});    
```    
  
    
### off('queueItemsChange')<sup>(10+)</sup>    
媒体控制器取消监听播放列表变化的事件。  
 **调用形式：**     
    
- off(type: 'queueItemsChange', callback?: (items: Array\<AVQueueItem>) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'queueItemsChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数items是变化的播放列表。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('queueItemsChange');    
```    
  
    
### on('queueTitleChange')<sup>(10+)</sup>    
媒体控制器设置会话自定义播放列表的名称变化的监听器。  
 **调用形式：**     
    
- on(type: 'queueTitleChange', callback: (title: string) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'queueTitleChange'</code>：当session修改播放列表名称时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，title为变化的播放列表名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.on('queueTitleChange', (title: string) => {  console.info(`queueTitleChange, title is ${title}`);});    
```    
  
    
### off('queueTitleChange')<sup>(10+)</sup>    
媒体控制器取消监听播放列表名称变化的事件。  
 **调用形式：**     
    
- off(type: 'queueTitleChange', callback?: (title: string) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'queueTitleChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参数items是变化的播放列表名称。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('queueTitleChange');    
```    
  
    
### on('extrasChange')<sup>(10+)</sup>    
媒体控制器设置自定义媒体数据包事件变化的监听器。  
 **调用形式：**     
    
- on(type: 'extrasChange', callback: (extras: {[key: string]: Object}) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'extrasChange'</code>：当媒体提供方设置自定义媒体数据包时，触发该事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，extras为媒体提供方新设置的自定义媒体数据包，该自定义媒体数据包与dispatchSessionEvent方法设置的数据包完全一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let avSessionController: avSession.AVSessionController | undefined = undefined;  
let currentAVSession: avSession.AVSession | undefined = undefined;  
let tag = "createNewSession";  
let context: Context = getContext(this);  
  
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {  
  if (err) {  
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVSession = data;  
  }  
});  
if (currentAVSession !== undefined) {  
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {  
    avSessionController = controller;  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
  
if (avSessionController !== undefined) {  
  (avSessionController as avSession.AVSessionController).on('extrasChange', (extras) => {  
    console.info(`Caught extrasChange event,the new extra is: ${JSON.stringify(extras)}`);  
  });  
}  
    
```    
  
    
### off('extrasChange')<sup>(10+)</sup>    
媒体控制器取消监听自定义媒体数据包变化事件。  
 **调用形式：**     
    
- off(type: 'extrasChange', callback?: (extras: {[key: string]: Object}) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'extrasChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 注册监听事件时的回调函数。 该参数为可选参数，若不填写该参数，则认为取消会话所有与此事件相关的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600103 | The session controller does not exist. |  
    
 **示例代码：**   
```ts    
avsessionController.off('extrasChange');    
```    
  
    
## AVControlCommandType<sup>(10+)</sup>    
获取会话支持的有效命令。结果通过Promise异步回调方式返回。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| play | 播放 |  
| pause | 暂停 |  
| stop | 停止 |  
| playNext | 下一首 |  
| playPrevious | 上一首 |  
| fastForward | 快进 |  
| rewind | 快退 |  
| seek | 跳转某一节点 |  
| setSpeed | 设置播放倍速 |  
| setLoopMode | 设置循环模式 |  
| toggleFavorite | 是否收藏 |  
    
## AVControlCommand<sup>(10+)</sup>    
会话接受的命令的对象描述。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| command<sup>(10+)</sup> | AVControlCommandType | false | true | 命令<br/> |  
| parameter<sup>(10+)</sup> | LoopMode \| string \| number | false | false | 命令对应的参数<br/> |  
    
## AVSessionErrorCode<sup>(10+)</sup>    
会话发生错误时的错误码。    
    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ERR_CODE_SERVICE_EXCEPTION | 6600101 | Session service exception.<br/> |  
| ERR_CODE_SESSION_NOT_EXIST | 6600102 | The session does not exist.<br/> |  
| ERR_CODE_CONTROLLER_NOT_EXIST | 6600103 | The session controller does not exist.<br/> |  
| ERR_CODE_REMOTE_CONNECTION_ERR | 6600104 | The remote session connection failed.<br/> |  
| ERR_CODE_COMMAND_INVALID | 6600105 | Invalid session command.<br/> |  
| ERR_CODE_SESSION_INACTIVE | 6600106 | The session is not activated.<br/> |  
| ERR_CODE_MESSAGE_OVERLOAD | 6600107 | Too many commands or events.<br/> |  
| ERR_CODE_DEVICE_CONNECTION_FAILED | 6600108 | Device connecting failed.<br/> |  
| ERR_CODE_REMOTE_CONNECTION_NOT_EXIST | 6600109 | The remote connection is not established.。 |  
