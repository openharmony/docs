# @ohos.multimedia.systemSoundManager    
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemSoundManager from '@ohos.multimedia.systemSoundManager'    
```  
    
## RingtoneType    
枚举，铃声类型。    
    
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RINGTONE_TYPE_DEFAULT | 0 | 枚举，铃声类型。 |  
| RINGTONE_TYPE_MULTISIM | 1 | 多SIM卡铃声类型。 |  
    
## getSystemSoundManager    
获取系统声音管理器。  
 **调用形式：**     
- getSystemSoundManager(): SystemSoundManager  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SystemSoundManager | 系统声音管理类。 |  
    
 **示例代码：**   
```ts    
let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();    
```    
  
    
## SystemSoundManager    
获取系统声音管理器。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
### setSystemRingtoneUri    
设置系统铃声uri，使用callback方式异步返回结果。  
 **调用形式：**     
    
- setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 当前应用的上下文。 |  
| uri | string | true | 被设置的系统铃声的uri，资源支持可参考[media.AVPlayer](js-apis-media.md#avplayer9)。 |  
| type | RingtoneType | true | 被设置的系统铃声的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回设置成功或失败。 |  
| Promise<void> | Promise回调返回设置成功或失败。 |  
    
 **示例代码1：**   
示例代码（callback）：  
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
  
    
 **示例代码2：**   
示例代码（promise）：  
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
获取系统铃声uri，使用callback方式异步返回结果。  
 **调用形式：**     
    
- getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getSystemRingtoneUri(context: Context, type: RingtoneType): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 当前应用的上下文。 |  
| type | RingtoneType | true | 待获取的系统铃声的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> | Promise回调返回设置成功或失败。 |  
    
 **示例代码1：**   
示例代码（callback）：  
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
  
    
 **示例代码2：**   
示例代码（promise）：  
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
获取系统铃声播放器，使用callback方式异步返回结果。  
 **调用形式：**     
    
- getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback\<RingtonePlayer>): void    
起始版本： 10    
- getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise\<RingtonePlayer>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.SystemSound.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 当前应用的上下文。 |  
| type | RingtoneType | true | 待获取播放器的系统铃声的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回获取的系统铃声播放器。 |  
| Promise<RingtonePlayer> |  |  
    
 **示例代码1：**   
示例代码（callback）：  
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
  
    
 **示例代码2：**   
示例代码（promise）：  
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
  
