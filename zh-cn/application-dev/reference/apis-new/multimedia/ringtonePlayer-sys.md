# ringtonePlayer    
铃声播放器提供了系统铃声的播放、配置、获取信息等功能。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## RingtoneOptions    
铃声参数选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| volume | number | false | true | 指定的相对音量大小，取值范围为[0.00, 1.00]，1表示最大音量，即100%。 |  
| loop | boolean | false | true | 是否开启循环播放，true表示开启循环播放，false表示不开启循环播放。 |  
    
## RingtonePlayer    
系统铃声播放器，提供系统铃声的参数设置、参数获取、播放、停止等功能。在调用RingtonePlayer的接口前，需要先通过[getSystemRingtonePlayer](js-apis-systemSoundManager.md#getsystemringtoneplayer)创建实例。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| state | media.AVPlayerState | true | true | 音频渲染器的状态。 |  
    
### getTitle    
获取铃声标题。  
 **调用形式：**     
    
- getTitle(callback: AsyncCallback\<string>): void    
起始版本： 10    
- getTitle(): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回获取的铃声标题。 |  
| Promise<string> | Promise回调返回获取的系统铃声标题。 |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.getTitle((err: BusinessError, value: string) => {  
  if (err) {  
    console.error(`Failed to get system ringtone title. ${err}`);  
    return;  
  }  
  console.info(`Callback invoked to indicate the value of the system ringtone title is obtained ${value}.`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.getTitle().then((value: string) => {  
  console.info(`Promise returned to indicate that the value of the system ringtone title is obtained ${value}.`);  
}).catch ((err: BusinessError) => {  
  console.error(`Failed to get the system ringtone title ${err}`);  
});  
    
```    
  
    
### getAudioRendererInfo    
获取铃声使用的AudioRendererInfo。  
 **调用形式：**     
    
- getAudioRendererInfo(callback: AsyncCallback\<audio.AudioRendererInfo>): void    
起始版本： 10    
- getAudioRendererInfo(): Promise\<audio.AudioRendererInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回获取的AudioRendererInfo。 |  
| Promise<audio.AudioRendererInfo> | Promise回调返回获取的AudioRendererInfo。 |  
    
 **示例代码：**   
  
示例(callback):  
```ts    
import audio from '@ohos.multimedia.audio';  
import { BusinessError } from '@ohos.base';  
  
let audioRendererInfo: audio.AudioRendererInfo | undefined = undefined;  
  
systemRingtonePlayer.getAudioRendererInfo((err: BusinessError, value: audio.AudioRendererInfo) => {  
  if (err) {  
    console.error(`Failed to get ringtone AudioRendererInfo. ${err}`);  
    return;  
  }  
  console.info(`Callback invoked to indicate the value of the ringtone AudioRendererInfo is obtained.`);  
  audioRendererInfo = value;  
});  
    
```    
  
    
### configure    
配置铃声播放参数。  
 **调用形式：**     
    
- configure(options: RingtoneOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- configure(options: RingtoneOptions): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | RingtoneOptions | true | 指定铃声参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回配置参数成功或失败。 |  
| Promise<void> | Promise回调返回配置参数成功或失败。 |  
    
 **示例代码：**   
示例(Promise):  
```ts    
import audio from '@ohos.multimedia.audio';  
import { BusinessError } from '@ohos.base';  
  
let audioRendererInfo: audio.AudioRendererInfo | undefined = undefined;  
  
systemRingtonePlayer.getAudioRendererInfo().then((value: audio.AudioRendererInfo) => {  
  console.info(`Promise returned to indicate that the value of the ringtone AudioRendererInfo is obtained ${value}.`);  
  audioRendererInfo = value;  
}).catch ((err: BusinessError) => {  
  console.error(`Failed to get the ringtone AudioRendererInfo ${err}`);  
});  
    
```    
  
    
### start    
开始播放铃声。  
 **调用形式：**     
    
- start(callback: AsyncCallback\<void>): void    
起始版本： 10    
- start(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回开始播放成功或失败。 |  
| Promise<void> | Promise回调返回开始播放成功或失败。 |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.start((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to start playing ringtone. ${err}`);  
    return;  
  }  
  console.info(`Callback invoked to indicate a successful starting of ringtone.`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.start().then(() => {  
  console.info(`Promise returned to indicate a successful starting of ringtone.`);  
}).catch ((err: BusinessError) => {  
  console.error(`Failed to start playing ringtone. ${err}`);  
});  
    
```    
  
    
### stop    
停止播放铃声。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stop(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回停止播放成功或失败。 |  
| Promise<void> | Promise回调返回停止播放成功或失败。 |  
    
 **示例代码1：**   
  
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.stop((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to stop playing ringtone. ${err}`);  
    return;  
  }  
  console.info(`Callback invoked to indicate a successful stopping of ringtone.`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.stop().then(() => {  
  console.info(`Promise returned to indicate a successful stopping of ringtone.`);  
}).catch ((err: BusinessError) => {  
  console.error(`Failed to stop playing ringtone. ${err}`);  
});  
    
```    
  
    
### release    
释放铃声播放器。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 10    
- release(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回释放成功或失败。 |  
| Promise<void> | Promise回调返回释放成功或失败。 |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.release((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to release ringtone player. ${err}`);  
    return;  
  }  
  console.info(`Callback invoked to indicate a successful releasing of ringtone player.`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
systemRingtonePlayer.release().then(() => {  
  console.info(`Promise returned to indicate a successful releasing of ringtone player.`);  
}).catch ((err: BusinessError) => {  
  console.error(`Failed to release ringtone player. ${err}`);  
});  
    
```    
  
    
### on('audioInterrupt')    
监听音频中断事件。使用callback获取中断事件。  
 **调用形式：**     
    
- on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为：'audioInterrupt'（中断事件被触发，音频渲染被中断）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 被监听的中断事件的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if input parameter type or number mismatch |  
| 6800101 | if input parameter value error |  
    
 **示例代码：**   
```ts    
import audio from '@ohos.multimedia.audio';  
let isPlaying: boolean; // 标识符，表示是否正在渲染let isDucked: boolean; // 标识符，表示是否被降低音量  
systemRingtonePlayer.on('audioInterrupt', async(interruptEvent: audio.InterruptEvent) => {  if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {    // 由系统进行操作，强制打断音频渲染，应用需更新自身状态及显示内容等    switch (interruptEvent.hintType) {      case audio.InterruptHint.INTERRUPT_HINT_PAUSE:        // 音频流已被暂停，临时失去焦点，待可重获焦点时会收到resume对应的interruptEvent        console.info('Force paused. Update playing status and stop writing');        isPlaying = false; // 简化处理，代表应用切换至暂停状态的若干操作        break;      case audio.InterruptHint.INTERRUPT_HINT_STOP:        // 音频流已被停止，永久失去焦点，若想恢复渲染，需用户主动触发        console.info('Force stopped. Update playing status and stop writing');        isPlaying = false; // 简化处理，代表应用切换至暂停状态的若干操作        break;      case audio.InterruptHint.INTERRUPT_HINT_DUCK:        // 音频流已被降低音量渲染        console.info('Force ducked. Update volume status');        isDucked = true; // 简化处理，代表应用更新音量状态的若干操作        break;      case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:        // 音频流已被恢复正常音量渲染        console.info('Force ducked. Update volume status');        isDucked = false; // 简化处理，代表应用更新音量状态的若干操作        break;      default:        break;    }  } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {    // 由应用进行操作，应用可以自主选择响应操作或忽略该事件    switch (interruptEvent.hintType) {      case audio.InterruptHint.INTERRUPT_HINT_RESUME:        // 建议应用继续渲染（说明音频流此前被强制暂停，临时失去焦点，现在可以恢复渲染）        console.info('Resume force paused renderer or ignore');        // 若选择继续渲染，需在此处主动执行开始渲染的若干操作        break;      default:        break;    }  }});    
```    
  
    
### off('audioInterrupt')    
取消订阅音频中断事件。  
 **调用形式：**     
- off(type: 'audioInterrupt'): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要取消订阅事件的类型。支持的事件为：'audioInterrupt'。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if input parameter type or number mismatch |  
| 6800101 | if input parameter value error |  
    
 **示例代码：**   
```ts    
systemRingtonePlayer.off('audioInterrupt');    
```    
  
