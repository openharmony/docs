# @ohos.multimedia.avsession    
媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import avSession from '@ohos.multimedia.avsession'    
```  
    
## getAllSessionDescriptors    
获取所有会话的相关描述。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void    
起始版本： 9    
- getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回所有会话描述的只读对象。 |  
| Promise<Array<Readonly<AVSessionDescriptor>>> | Promise对象。返回所有会话描述的只读对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 6600101 | Session service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.getAllSessionDescriptors((err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {  
  if (err) {  
    console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);  
    if(descriptors.length > 0 ){  
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);  
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);  
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);  
    }  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {  
  console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);  
  if(descriptors.length > 0 ){  
    console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);  
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);  
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);  
  }  
}).catch((err: BusinessError) => {  
  console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## getHistoricalSessionDescriptors<sup>(10+)</sup>    
获取所有会话的相关描述。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void    
起始版本： 10    
- getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| maxSize | number | true | 指定获取描述符数量的最大值，可选范围是0-10，不填则取默认值，默认值为3。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回所有会话描述的只读对象。 |  
| Promise<Array<Readonly<AVSessionDescriptor>>> | Promise对象。返回所有会话描述的只读对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.getHistoricalSessionDescriptors(1, (err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {  
  if (err) {  
    console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);  
    if(descriptors.length > 0 ){  
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);  
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);  
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);  
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);  
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);  
    }  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.getHistoricalSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {  
  console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);  
  if(descriptors.length > 0 ){  
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);  
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);  
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);  
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);  
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);  
  }  
}).catch((err: BusinessError) => {  
  console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## createController    
根据会话ID创建会话控制器，可以创建多个会话控制器。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void    
起始版本： 9    
- createController(sessionId: string): Promise\<AVSessionController>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId | string | true | 会话ID。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回会话控制器实例，可查看会话ID， 并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |  
| Promise<AVSessionController> | Promise对象。返回会话控制器实例，可查看会话ID， 并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
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
  
let currentAVcontroller: avSession.AVSessionController | undefined = undefined;  
avSession.createController(sessionId, (err: BusinessError, avcontroller: avSession.AVSessionController) => {  
  if (err) {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    currentAVcontroller = avcontroller;  
    console.info('CreateController : SUCCESS ');  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
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
  
let currentAVcontroller: avSession.AVSessionController | undefined = undefined;  
avSession.createController(sessionId).then((avcontroller: avSession.AVSessionController) => {  
  currentAVcontroller = avcontroller;  
  console.info('CreateController : SUCCESS ');  
}).catch((err: BusinessError) => {  
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## castAudio    
投播会话到指定设备列表。结果通过Promise异步回调方式返回。  调用此接口之前，需要导入ohos.multimedia.audio模块获取AudioDeviceDescriptor的相关描述。  
 **调用形式：**     
    
- castAudio(session: SessionToken | 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- castAudio(session: SessionToken | 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| session | string | true | 会话令牌。SessionToken表示单个token；字符串<code>'all'</code>指所有token。<br/> |  
| audioDevices | Array<audio.AudioDeviceDescriptor> | true | 媒体设备列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当投播成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当投播成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600102 | The session does not exist. |  
| 6600104 | The remote session connection failed. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import audio from '@ohos.multimedia.audio';  
import { BusinessError } from '@ohos.base';  
  
let audioManager = audio.getAudioManager();  
let audioRoutingManager = audioManager.getRoutingManager();  
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;  
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {  
  audioDevices = data;  
  console.info(`Promise returned to indicate that the device list is obtained.`);  
}).catch((err: BusinessError) => {  
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
  
if (audioDevices !== undefined) {  
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {  
    console.info(`CreateController : SUCCESS`);  
  }).catch((err: BusinessError) => {  
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import audio from '@ohos.multimedia.audio';  
import { BusinessError } from '@ohos.base';  
  
let audioManager = audio.getAudioManager();  
let audioRoutingManager = audioManager.getRoutingManager();  
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;  
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {  
  audioDevices = data;  
  console.info(`Promise returned to indicate that the device list is obtained.`);  
}).catch((err: BusinessError) => {  
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
  
if (audioDevices !== undefined) {  
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors, (err: BusinessError) => {  
    if (err) {  
      console.error(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);  
    } else {  
      console.info(`CastAudio : SUCCESS `);  
    }  
  });  
}  
    
```    
  
    
## SessionToken    
会话令牌的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager    
### 属性    
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sessionId | string | false | true | 会话ID<br/> |  
| pid | number | false | false | 会话的进程ID<br/> |  
| uid | number | false | false | 用户ID<br/> |  
    
 **示例代码：**   
```ts    
avSession.on('sessionCreate', (descriptor: avSession.AVSessionDescriptor) => {  console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);  console.info(`on sessionCreate : type : ${descriptor.type}`);  console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);});    
```    
  
    
## on('sessionCreate')    
会话的创建监听事件。  
 **调用形式：**     
    
- on(type: 'sessionCreate', callback: (session: AVSessionDescriptor) => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件是'sessionCreate'`：会话创建事件，检测到会话创建时触发。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数为会话相关描述。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.on('sessionCreate', (descriptor: avSession.AVSessionDescriptor) => {  console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);  console.info(`on sessionCreate : type : ${descriptor.type}`);  console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);});    
```    
  
    
## on('sessionDestroy')    
会话的销毁监听事件。  
 **调用形式：**     
    
- on(type: 'sessionDestroy', callback: (session: AVSessionDescriptor) => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件包括是<code>'sessionDestroy'</code>：会话销毁事件，检测到会话销毁时触发。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数为会话相关描述。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.on('sessionDestroy', (descriptor: avSession.AVSessionDescriptor) => {  console.info(`on sessionDestroy : isActive : ${descriptor.isActive}`);  console.info(`on sessionDestroy : type : ${descriptor.type}`);  console.info(`on sessionDestroy : sessionTag : ${descriptor.sessionTag}`);});    
```    
  
    
## on('topSessionChange')    
最新会话变更的监听事件。  
 **调用形式：**     
    
- on(type: 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件包括是<code>'topSessionChange'</code>：最新会话的变化事件，检测到最新的会话改变时触发。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参数为会话相关描述。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.on('topSessionChange', (descriptor: avSession.AVSessionDescriptor) => {  console.info(`on topSessionChange : isActive : ${descriptor.isActive}`);  console.info(`on topSessionChange : type : ${descriptor.type}`);  console.info(`on topSessionChange : sessionTag : ${descriptor.sessionTag}`);});    
```    
  
    
## off('sessionCreate')    
取消会话创建事件监听，取消后，不再进行该事件的监听。  
 **调用形式：**     
    
- off(type: 'sessionCreate', callback?: (session: AVSessionDescriptor) => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为：<code>'sessionCreate'</code>。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.off('sessionCreate');    
```    
  
    
## off('sessionDestroy')    
取消会话销毁事件监听，取消后，不再进行该事件的监听。  
 **调用形式：**     
    
- off(type: 'sessionDestroy', callback?: (session: AVSessionDescriptor) => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
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
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.off('sessionDestroy');    
```    
  
    
## off('topSessionChange')    
取消最新会话变更事件监听，取消后，不再进行该事件的监听。  
 **调用形式：**     
    
- off(type: 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为<code>'topSessionChange'</code>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.off('topSessionChange');    
```    
  
    
## on('sessionServiceDie')    
监听会话的服务死亡事件。  
 **调用形式：**     
    
- on(type: 'sessionServiceDie', callback: () => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'sessionServiceDie'</code>：会话服务死亡事件，检测到会话的服务死亡时触发。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.on('sessionServiceDie', () => {  console.info(`on sessionServiceDie  : session is  Died `);});    
```    
  
    
## off('sessionServiceDie')    
取消会话服务死亡监听，取消后，不再进行服务死亡监听。  
 **调用形式：**     
    
- off(type: 'sessionServiceDie', callback?: () => void): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'sessionServiceDie'</code>：会话服务死亡事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的服务死亡监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
avSession.off('sessionServiceDie');    
```    
  
    
## sendSystemAVKeyEvent    
发送按键事件给置顶会话。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void    
起始版本： 9    
- sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
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
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600105 | Invalid session command. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import keyEvent from '@ohos.multimodalInput.keyEvent';  
import { BusinessError } from '@ohos.base';  
  
let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};  
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};  
  
avSession.sendSystemAVKeyEvent(event, (err: BusinessError) => {  
  if (err) {  
    console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`SendSystemAVKeyEvent : SUCCESS `);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import keyEvent from '@ohos.multimodalInput.keyEvent';  
import { BusinessError } from '@ohos.base';  
  
let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};  
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};  
  
avSession.sendSystemAVKeyEvent(event).then(() => {  
  console.info(`SendSystemAVKeyEvent Successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## sendSystemControlCommand    
发送控制命令给置顶会话。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void    
起始版本： 9    
- sendSystemControlCommand(command: AVControlCommand): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command | AVControlCommand | true | AVSession的相关命令和命令相关参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600105 | Invalid session command. |  
| 6600107 | Too many commands or events. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import avSession from '@ohos.multimedia.avsession';  
  
let cmd : avSession.AVControlCommandType = 'play';  
// let cmd : avSession.AVControlCommandType = 'pause';  
// let cmd : avSession.AVControlCommandType = 'stop';  
// let cmd : avSession.AVControlCommandType = 'playNext';  
// let cmd : avSession.AVControlCommandType = 'playPrevious';  
// let cmd : avSession.AVControlCommandType = 'fastForward';  
// let cmd : avSession.AVControlCommandType = 'rewind';  
let avcommand: avSession.AVControlCommand = {command:cmd};  
// let cmd : avSession.AVControlCommandType = 'seek';  
// let avcommand = {command:cmd, parameter:10};  
// let cmd : avSession.AVControlCommandType = 'setSpeed';  
// let avcommand = {command:cmd, parameter:2.6};  
// let cmd : avSession.AVControlCommandType = 'setLoopMode';  
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};  
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';  
// let avcommand = {command:cmd, parameter:"false"};  
avSession.sendSystemControlCommand(avcommand, (err) => {  
  if (err) {  
    console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`sendSystemControlCommand successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import avSession from '@ohos.multimedia.avsession';  
import { BusinessError } from '@ohos.base';  
  
let cmd : avSession.AVControlCommandType = 'play';  
// let cmd : avSession.AVControlCommandType = 'pause';  
// let cmd : avSession.AVControlCommandType = 'stop';  
// let cmd : avSession.AVControlCommandType = 'playNext';  
// let cmd : avSession.AVControlCommandType = 'playPrevious';  
// let cmd : avSession.AVControlCommandType = 'fastForward';  
// let cmd : avSession.AVControlCommandType = 'rewind';  
let avcommand: avSession.AVControlCommand = {command:cmd};  
// let cmd : avSession.AVControlCommandType = 'seek';  
// let avcommand = {command:cmd, parameter:10};  
// let cmd : avSession.AVControlCommandType = 'setSpeed';  
// let avcommand = {command:cmd, parameter:2.6};  
// let cmd : avSession.AVControlCommandType = 'setLoopMode';  
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};  
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';  
// let avcommand = {command:cmd, parameter:"false"};  
avSession.sendSystemControlCommand(avcommand).then(() => {  
  console.info(`SendSystemControlCommand successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## ProtocolType<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_LOCAL | 0 |  |  
| TYPE_CAST_PLUS_MIRROR | 1 |  |  
| TYPE_CAST_PLUS_STREAM | 2 |  |  
    
## startCastDeviceDiscovery<sup>(10+)</sup>    
开始设备搜索发现。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- startCastDeviceDiscovery(callback: AsyncCallback\<void>): void    
起始版本： 10    
- startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startCastDeviceDiscovery(filter?: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | number | true | 进行设备发现的过滤条件，由ProtocolType的组合而成<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功停止搜索，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功并开始搜索，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let filter = 2;  
avSession.startCastDeviceDiscovery(filter, (err: BusinessError) => {  
  if (err) {  
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`startCastDeviceDiscovery successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let filter = 2;  
avSession.startCastDeviceDiscovery(filter).then(() => {  
  console.info(`startCastDeviceDiscovery successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## stopCastDeviceDiscovery<sup>(10+)</sup>    
结束设备搜索发现。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- stopCastDeviceDiscovery(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopCastDeviceDiscovery(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功停止搜索，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当成功停止搜索，无返回结果，否则返回错误对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.stopCastDeviceDiscovery((err: BusinessError) => {  
  if (err) {  
    console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`stopCastDeviceDiscovery successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.stopCastDeviceDiscovery().then(() => {  
  console.info(`startCastDeviceDiscovery successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## setDiscoverable<sup>(10+)</sup>    
设置设备是否可被发现，用于投播接收端。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setDiscoverable(enable: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 是否允许本设备被发现. true: 允许被发现， false：不允许被发现<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置成功，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当设置成功，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.setDiscoverable(true, (err: BusinessError) => {  
  if (err) {  
    console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`setDiscoverable successfully`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
avSession.setDiscoverable(true).then(() => {  
  console.info(`setDiscoverable successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## on('deviceAvailable')<sup>(10+)</sup>    
设备发现回调监听。  
 **调用形式：**     
    
- on(type: 'deviceAvailable', callback: (device: OutputDeviceInfo) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'deviceAvailable'</code>，有设备被发现时触发回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示取消订阅广播状态上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
    
 **示例代码：**   
```ts    
import avSession from '@ohos.multimedia.avsession';  
let castDevice: avSession.OutputDeviceInfo;avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {  castDevice = device;  console.info(`on deviceAvailable  : ${device} `);});    
```    
  
    
## off('deviceAvailable')<sup>(10+)</sup>    
取消设备发现回调的监听。  
 **调用形式：**     
    
- off(type: 'deviceAvailable', callback?: (device: OutputDeviceInfo) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持事件<code>'deviceAvailable'</code>：设备发现回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回投播控制器实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
    
 **示例代码：**   
```ts    
avSession.off('deviceAvailable');    
```    
  
    
## getAVCastController<sup>(10+)</sup>    
设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void    
起始版本： 10    
- getAVCastController(sessionId: string): Promise\<AVCastController>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId | string | true | 用于指定要获取的投播控制器的sessionId<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回投播控制器实例。 |  
| Promise<AVCastController> | Promise对象。返回投播控制器实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception |  
| 6600102 | session does not exist |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
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
  
let aVCastController: avSession.AVCastController;  
avSession.getAVCastController(sessionId , (err: BusinessError, avcontroller: avSession.AVCastController) => {  
  if (err) {  
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    aVCastController = avcontroller;  
    console.info('getAVCastController : SUCCESS ');  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
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
  
let aVCastController: avSession.AVCastController;  
avSession.getAVCastController(sessionId).then((avcontroller: avSession.AVCastController) => {  
  aVCastController = avcontroller;  
  console.info('getAVCastController : SUCCESS');  
}).catch((err: BusinessError) => {  
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## startCasting<sup>(10+)</sup>    
启动投播。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- startCasting(session: SessionToken, device: OutputDeviceInfo, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startCasting(session: SessionToken, device: OutputDeviceInfo): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast  
 **需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| session | SessionToken | true | 会话令牌。SessionToken表示单个token。 |  
| device | OutputDeviceInfo | true | 设备相关信息<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当命令发送成功并启动投播，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当命令发送成功并启动投播，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
| 6600108 | Device connecting failed. |  
    
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
  
    
## stopCasting<sup>(10+)</sup>    
结束投播。结果通过callback异步回调方式返回。  
 **调用形式：**     
    
- stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopCasting(session: SessionToken): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| session | SessionToken | true | 会话令牌。SessionToken表示单个token。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功结束投播，err为undefined，否则返回错误对象。 |  
| Promise<void> | Promise对象。当成功结束投播，无返回结果，否则返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
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
avSession.stopCasting(myToken, (err: BusinessError) => {  
  if (err) {  
    console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`stopCasting successfully`);  
  }  
});  
    
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
avSession.stopCasting(myToken).then(() => {  
  console.info(`stopCasting successfully`);  
}).catch((err: BusinessError) => {  
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## AVCastController<sup>(10+)</sup>    
在投播建立后，调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-avsession.md#getavcastcontroller10">avSession.getAVCastController</a>后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。  
  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
### setDisplaySurface<sup>(10+)</sup>    
设置播放的surfaceId，在投播sink端使用。结果通过Promise异步回调方式返回。  
 **调用形式：**     
    
- setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setDisplaySurface(surfaceId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| surfaceId | string | true | surfaceId |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前设置结果。 |  
| Promise<void> | Promise对象。返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600109 | The remote connection is not established. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
import media from '@ohos.multimedia.media';  
let surfaceID: string = '';  
media.createAVRecorder().then((avRecorder) => {  
  avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {  
    if (err == null) {  
      console.info('getInputSurface success');  
      surfaceID = surfaceId;  
    } else {  
      console.error('getInputSurface failed and error is ' + err.message);  
    }  
  });  
})  
aVCastController.setDisplaySurface(surfaceID).then(() => {  
  console.info(`setDisplaySurface : SUCCESS`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
import media from '@ohos.multimedia.media';  
let surfaceID: string = '';  
media.createAVRecorder().then((avRecorder) => {  
  avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {  
    if (err == null) {  
      console.info('getInputSurface success');  
      surfaceID = surfaceId;  
    } else {  
      console.error('getInputSurface failed and error is ' + err.message);  
    }  
  });  
})  
aVCastController.setDisplaySurface(surfaceID, (err: BusinessError) => {  
  if (err) {  
    console.info(`setDisplaySurface BusinessError: code: ${err.code}, message: ${err.message}`);  
  } else {  
    console.info(`setDisplaySurface : SUCCESS`);  
  }  
});  
    
```    
  
    
### on('videoSizeChange')<sup>(10+)</sup>    
设置video尺寸更改监听事件。  
 **调用形式：**     
    
- on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回video的宽度和高度 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.on('videoSizeChange', (width: number, height: number) => {  console.info(`width ：${width} `);  console.info(`height：${height} `);});    
```    
  
    
### off('videoSizeChange')<sup>(10+)</sup>    
取消设置video尺寸更改监听事件。  
 **调用形式：**     
- off(type: 'videoSizeChange'): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消对应的监听事件，支持事件<code>'videoSizeChange'</code>。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid parameter. |  
| 6600101 | Session service exception. |  
    
 **示例代码：**   
```ts    
aVCastController.off('videoSizeChange');    
```    
  
    
## DeviceInfo<sup>(10+)</sup>    
播放设备的相关信息。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.AVCast    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ipAddress<sup>(10+)</sup> | string | false | false | 播放设备的ip地址。<br/>此接口为系统接口。<br/><strong>系统能力：</strong>SystemCapability.Multimedia.AVSession.AVCast<br/> |  
| providerId<sup>(10+)</sup> | number | false | false | 播放设备提供商。<br/>此接口为系统接口。<br/><strong>系统能力：</strong>SystemCapability.Multimedia.AVSession.AVCast<br/> |  
    
## AVSessionDescriptor    
会话的相关描述信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.AVSession.Manager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sessionId | string | false | true | 会话ID<br/> |  
| type | AVSessionType | false | true | 会话类型<br/> |  
| sessionTag | string | false | true | 会话的自定义名称<br/> |  
| elementName | ElementName | false | true | 会话所属应用的信息（包含bundleName、abilityName等）<br/> |  
| isActive | boolean | false | true | 会话是否被激活<br/> |  
| isTopSession | boolean | false | true | 会话是否为最新的会话<br/> |  
| outputDevice | OutputDeviceInfo | false | true | 分布式设备相关信息。 |  
