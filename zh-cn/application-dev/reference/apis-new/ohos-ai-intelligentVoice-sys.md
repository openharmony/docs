# @ohos.ai.intelligentVoice    
智能语音主要提供了语音注册及语音唤醒相关功能。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import intelligentVoice from '@ohos.ai.intelligentVoice'    
```  
    
## getIntelligentVoiceManager    
获取智能语音管理类。  
 **调用形式：**     
- getIntelligentVoiceManager(): IntelligentVoiceManager  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IntelligentVoiceManager | 智能语音管理类。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 22700101 | No memory. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let intelligentVoiceManager: intelligentVoice.IntelligentVoiceManager | null = null;  
try {  
  intelligentVoiceManager = intelligentVoice.getIntelligentVoiceManager();  
} catch (err) {  
  let error = err as BusinessError;  
  console.error(`Get IntelligentVoiceManager failed. Code:${error.code}, message:${error.message}`);  
}  
    
```    
  
    
## IntelligentVoiceManager    
智能语音管理类，使用前需要通过[getIntelligentVoiceManager()](#intelligentvoicegetintelligentvoicemanager)获取智能语音管理实例。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### getCapabilityInfo    
获取支持的智能语音引擎列表信息。  
 **调用形式：**     
- getCapabilityInfo(): Array\<IntelligentVoiceEngineType>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<IntelligentVoiceEngineType> | 支持的智能语音引擎类型数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
```ts    
if (intelligentVoiceManager != null) {  
  let info = intelligentVoiceManager.getCapabilityInfo();  
}    
```    
  
    
### on('serviceChange')    
订阅服务变更事件。当智能语音业务状态发生变化时，调用回调。  
 **调用形式：**     
    
- on(type: 'serviceChange', callback: Callback\<ServiceChangeType>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 系统服务变更事件，固定取值为'serviceChange'，表示服务变更事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 服务状态变更对应的处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
```ts    
if (intelligentVoiceManager != null) {  
  intelligentVoiceManager.on('serviceChange', (serviceChangeType: intelligentVoice.ServiceChangeType) => {});  
}    
```    
  
    
### off('serviceChange')    
取消订阅服务变更事件。  
 **调用形式：**     
    
- off(type: 'serviceChange', callback?: Callback\<ServiceChangeType>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 系统服务变更事件，固定取值为'serviceChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 服务状态变更对应的处理，无参数，则取消所有订阅，否则，取消对应的处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
```ts    
if (intelligentVoiceManager != null) {  
  intelligentVoiceManager.off('serviceChange');  
}    
```    
  
    
## ServiceChangeType    
枚举，服务状态变更类型。    
    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SERVICE_UNAVAILABLE | 0 | 服务状态不可用。 |  
    
## IntelligentVoiceEngineType    
枚举，智能语音引擎类型。    
    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ENROLL_ENGINE_TYPE | 0 | 语音注册引擎。  |  
| WAKEUP_ENGINE_TYPE | 1 | 语音唤醒引擎。 |  
| UPDATE_ENGINE_TYPE | 2 | 静默升级引擎。 |  
    
## EnrollIntelligentVoiceEngineDescriptor    
注册智能语音引擎描述符。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### 属性    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| wakeupPhrase | string | false | true | 唤醒词。 |  
    
## WakeupIntelligentVoiceEngineDescriptor    
唤醒智能语音引擎描述符。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### 属性    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| needReconfirm | boolean | false | true | 是否需要再次确认唤醒结果，true为需要，false为不需要。 |  
| wakeupPhrase | string | false | true | 唤醒词。 |  
    
## createEnrollIntelligentVoiceEngine    
创建智能语音注册引擎实例，使用Promise异步回调。  
 **调用形式：**     
    
- createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor, callback: AsyncCallback\<EnrollIntelligentVoiceEngine>): void    
起始版本： 10    
- createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor): Promise\<EnrollIntelligentVoiceEngine>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor | EnrollIntelligentVoiceEngineDescriptor | true | 智能语音注册引擎描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<EnrollIntelligentVoiceEngine> | 返回注册智能语音引擎。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700101 | No memory. |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let engineDescriptor: intelligentVoice.EnrollIntelligentVoiceEngineDescriptor = {  
  wakeupPhrase: '小华小华',  
}  
let enrollIntelligentVoiceEngine: intelligentVoice.EnrollIntelligentVoiceEngine | null = null;  
intelligentVoice.createEnrollIntelligentVoiceEngine(engineDescriptor, (err: BusinessError, data: intelligentVoice.EnrollIntelligentVoiceEngine) => {  
  if (err) {  
    console.error(`Failed to create enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
  } else {  
    console.info(`Succeeded in creating enrollIntelligentVoice engine.`);  
    enrollIntelligentVoiceEngine = data;  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let engineDescriptor: intelligentVoice.EnrollIntelligentVoiceEngineDescriptor = {  
  wakeupPhrase: '小华小华',  
}  
let enrollIntelligentVoiceEngine: intelligentVoice.EnrollIntelligentVoiceEngine | null = null;  
intelligentVoice.createEnrollIntelligentVoiceEngine(engineDescriptor).then((data: intelligentVoice.EnrollIntelligentVoiceEngine) => {  
  enrollIntelligentVoiceEngine = data;  
  console.info(`Succeeded in creating enrollIntelligentVoice engine.`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to create enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
});  
    
```    
  
    
## createWakeupIntelligentVoiceEngine    
创建智能语音唤醒引擎实例，使用callback异步回调。  
 **调用形式：**     
    
- createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor, callback: AsyncCallback\<WakeupIntelligentVoiceEngine>): void    
起始版本： 10    
- createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor): Promise\<WakeupIntelligentVoiceEngine>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor | WakeupIntelligentVoiceEngineDescriptor | true | 唤醒智能语音引擎描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<WakeupIntelligentVoiceEngine> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700101 | No memory. |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let wakeupEngineDescriptor: intelligentVoice.WakeupIntelligentVoiceEngineDescriptor = {  
  needReconfirm: true,  
  wakeupPhrase: '小华小华',  
}  
let wakeupIntelligentVoiceEngine: intelligentVoice.WakeupIntelligentVoiceEngine | null = null;  
intelligentVoice.createWakeupIntelligentVoiceEngine(wakeupEngineDescriptor, (err: BusinessError, data: intelligentVoice.WakeupIntelligentVoiceEngine) => {  
  if (err) {  
    console.error(`Failed to create wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
  } else {  
    console.info(`Succeeded in creating wakeupIntelligentVoice engine.`);  
    wakeupIntelligentVoiceEngine = data;  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let wakeupEngineDescriptor: intelligentVoice.WakeupIntelligentVoiceEngineDescriptor = {  
  needReconfirm: true,  
  wakeupPhrase: '小华小华',  
}  
let wakeupIntelligentVoiceEngine: intelligentVoice.WakeupIntelligentVoiceEngine | null = null;  
intelligentVoice.createWakeupIntelligentVoiceEngine(wakeupEngineDescriptor).then((data: intelligentVoice.WakeupIntelligentVoiceEngine) => {  
  wakeupIntelligentVoiceEngine = data;  
  console.info(`Succeeded in creating wakeupIntelligentVoice engine.`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to create wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
});  
    
```    
  
    
## EnrollEngineConfig    
描述注册引擎配置。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### 属性    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| language | string | false | true | 注册引擎支持的语言，当前仅支持中文，取值为'zh'。  |  
| region | string | false | true | 注册引擎支持的区域。当前仅支持中国，取值为'CN'。  |  
    
## SensibilityType    
枚举，唤醒灵敏度类型。  
灵敏度用于调整唤醒的门限，灵敏度越高，门限越低，就越容易唤醒。    
    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOW_SENSIBILITY | 1 | 低灵敏度。 |  
| MIDDLE_SENSIBILITY | 2 | 中灵敏度。 |  
| HIGH_SENSIBILITY | 3 | 高灵敏度。 |  
    
## WakeupHapInfo    
描述唤醒应用的hap信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### 属性    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 唤醒应用的bundleName。 |  
| abilityName | string | false | true | 唤醒应用的ailityName。 |  
    
## WakeupIntelligentVoiceEventType    
枚举，唤醒智能语音事件类型。    
    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INTELLIGENT_VOICE_EVENT_WAKEUP_NONE | 0 | 无唤醒。 |  
| INTELLIGENT_VOICE_EVENT_RECOGNIZE_COMPLETE | 1 | 唤醒识别完成。 |  
    
## IntelligentVoiceErrorCode    
枚举，智能语音错误码。    
    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INTELLIGENT_VOICE_NO_MEMORY | 22700101 | 内存不足。 |  
| INTELLIGENT_VOICE_INVALID_PARAM | 22700102 | 参数无效。 |  
| INTELLIGENT_VOICE_INIT_FAILED | 22700103 | 注册失败。 |  
| INTELLIGENT_VOICE_COMMIT_ENROLL_FAILED | 22700104 | 确认注册结果失败。 |  
    
## EnrollResult    
枚举，注册结果。    
    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 注册成功。 |  
| VPR_TRAIN_FAILED | -1 | 声纹训练失败。 |  
| WAKEUP_PHRASE_NOT_MATCH | -2 | 唤醒短语不匹配。 |  
| TOO_NOISY | -3 | 周边环境太吵。  |  
| TOO_LOUD | -4 | 声音太大。  |  
| INTERVAL_LARGE | -5 | 唤醒词时间间隔太大。 |  
| DIFFERENT_PERSON | -6 |  不同人注册唤醒词。  |  
| UNKNOWN_ERROR | -100 | 未知错误。 |  
    
## EnrollCallbackInfo    
注册回调信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### 属性    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result | EnrollResult | false | true | 注册结果。 |  
| context | string | false | true | 描述注册事件上下文。 |  
    
## WakeupIntelligentVoiceEngineCallbackInfo    
描述唤醒智能语音引擎回调信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### 属性    
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eventId | WakeupIntelligentVoiceEventType | false | true | 唤醒智能语音事件类型。 |  
| isSuccess | boolean | false | true | 是否唤醒成功，false为唤醒失败，true为唤醒成功。 |  
| context | string | false | true | 描述唤醒事件上下文。 |  
    
## EnrollIntelligentVoiceEngine    
实现注册智能语音引擎，通过[createEnrollIntelligentVoiceEngine()](#intelligentvoicecreateenrollintelligentvoiceengine)获取注册智能语音引擎。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### getSupportedRegions    
获取支持的区域，使用callback异步回调。  
 **调用形式：**     
    
- getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getSupportedRegions(): Promise\<Array\<string>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。 |  
| Promise<Array<string>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let regions: Array<string> | null = null;  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getSupportedRegions((err: BusinessError, data: Array<string>) => {  
    if (err) {  
      console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);  
    } else {  
      regions = data;  
      console.info(`Succeeded in getting supported regions, regions:${regions}.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let regions: Array<string> | null = null;  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getSupportedRegions().then((data: Array<string>) => {  
    regions = data;  
    console.info('Succeeded in getting supported regions, regions:${regions}.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### init    
初始化注册智能语音引擎，使用callback异步回调。  
 **调用形式：**     
    
- init(config: EnrollEngineConfig, callback: AsyncCallback\<void>): void    
起始版本： 10    
- init(config: EnrollEngineConfig): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | EnrollEngineConfig | true | 注册引擎配置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回初始化结果。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
| 22700103 | Init failed. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let config: intelligentVoice.EnrollEngineConfig = {  
  language: 'zh',  
  region: 'CN',  
}  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).init(config, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to initialize enrollIntelligentVoice engine. Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in initialzing enrollIntelligentVoice engine.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let config: intelligentVoice.EnrollEngineConfig = {  
  language: 'zh',  
  region: 'CN',  
}  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).init(config).then(() => {  
    console.info(`Succeeded in initializing enrollIntelligentVoice engine.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to initialize enrollIntelligentVoice engine. Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### enrollForResult    
获取注册结果，使用callback异步回调。  
 **调用形式：**     
    
- enrollForResult(isLast: boolean, callback: AsyncCallback\<EnrollCallbackInfo>): void    
起始版本： 10    
- enrollForResult(isLast: boolean): Promise\<EnrollCallbackInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isLast | boolean | true | isLast表示是否为最后一次注册，false为非最后一次，true为最后一次。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回注册结果。 |  
| Promise<EnrollCallbackInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callbackInfo: intelligentVoice.EnrollCallbackInfo | null = null;  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).enrollForResult(true, (err: BusinessError, data: intelligentVoice.EnrollCallbackInfo) => {  
    if (err) {  
      console.error(`Failed to enroll for result, Code:${err.code}, message:${err.message}`);  
    } else {  
      callbackInfo = data;  
      console.info(`Succeeded in enrolling for result, info:${callbackInfo}.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callbackInfo: intelligentVoice.EnrollCallbackInfo | null = null;  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).enrollForResult(true).then((data: intelligentVoice.EnrollCallbackInfo) => {  
    callbackInfo = data;  
    console.info(`Succeeded in enrolling for result, info:${callbackInfo}.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to enroll for result, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### stop    
停止注册，使用callback异步回调。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stop(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).stop((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to stop enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in stopping enrollIntelligentVoice engine.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).stop().then(() => {  
    console.info(`Succeeded in stopping enrollIntelligentVoice engine.`);  
  }).catch((err:BusinessError) => {  
    console.error(`Failed to stop enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### commit    
提交注册，使用callback异步回调。  
 **调用形式：**     
    
- commit(callback: AsyncCallback\<void>): void    
起始版本： 10    
- commit(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回确认注册结果。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 22700104 | Commit enroll failed. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).commit((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to commit enroll, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in committing enroll.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).commit().then(() => {  
    console.info(`Succeeded in committing enroll.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to commit enroll, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### setWakeupHapInfo    
设置唤醒应用的hap信息，使用callback异步回调。  
 **调用形式：**     
    
- setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | WakeupHapInfo | true | 唤醒hap信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回设置唤醒hap信息的结果。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let info: intelligentVoice.WakeupHapInfo = {  
  bundleName: 'com.wakeup',  
  abilityName: 'WakeUpExtAbility',  
}  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setWakeupHapInfo(info, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in setting wakeup hap info.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let info: intelligentVoice.WakeupHapInfo = {  
  bundleName: 'com.wakeup',  
  abilityName: 'WakeUpExtAbility',  
}  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setWakeupHapInfo(info).then(() => {  
    console.info(`Succeeded in setting wakeup hap info.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### setSensibility    
设置唤醒灵敏度，使用callback异步回调。  
 **调用形式：**     
    
- setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setSensibility(sensibility: SensibilityType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sensibility | SensibilityType | true | 灵敏度类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回设置灵敏度的结果。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in setting sensibility.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY).then(() => {  
    console.info(`Succeeded in setting sensibility.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### setParameter    
设置指定的智能语音参数，使用callback异步回调。  
 **调用形式：**     
    
- setParameter(key: string, value: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setParameter(key: string, value: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true |  键 |  
| value | string | true |  值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setParameter('scene', '0', (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in setting parameter`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).setParameter('scene', '0').then(() => {  
    console.info(`Succeeded in setting parameter`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### getParameter    
获取指定的智能语音参数，使用callback异步回调。  
 **调用形式：**     
    
- getParameter(key: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getParameter(key: string): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回智能语音参数。 |  
| Promise<string> | 返回智能语音参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getParameter('key', (err: BusinessError, data: string) => {  
    if (err) {  
      console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);  
    } else {  
      let param: string = data;  
      console.info(`Succeeded in getting parameter, param:${param}`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).getParameter('key').then((data: string) => {  
    let param: string = data;  
    console.info(`Succeeded in getting parameter, param:${param}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### release    
释放注册智能语音引擎，使用callback异步回调。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 10    
- release(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回释放注册引擎的结果。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).release((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to release enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in releasing enrollIntelligentVoice engine.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (enrollIntelligentVoiceEngine != null) {  
  (enrollIntelligentVoiceEngine as intelligentVoice.EnrollIntelligentVoiceEngine).release().then(() => {  
    console.info(`Succeeded in releasing enrollIntelligentVoice engine.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to release enrollIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
## WakeupIntelligentVoiceEngine    
实现唤醒智能语音引擎，通过[createWakeupIntelligentVoiceEngine()](#intelligentvoicecreatewakeupintelligentvoiceengine)获取唤醒智能语音引擎。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core    
### getSupportedRegions    
获取支持的区域，使用callback异步回调。  
 **调用形式：**     
    
- getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getSupportedRegions(): Promise\<Array\<string>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。 |  
| Promise<Array<string>> | 返回支持区域的数组，当前只支持中国，对应取值为'CN'。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getSupportedRegions((err: BusinessError, data: Array<string>) => {  
    if (err) {  
      console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);  
    } else {  
      let regions: Array<string> = data;  
      console.info(`Succeeded in getting supported regions, regions:${regions}.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getSupportedRegions().then((data: Array<string>) => {  
    let regions: Array<string> = data;  
    console.info(`Succeeded in getting supported regions, regions:${regions}.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get supported regions, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### setWakeupHapInfo    
设置唤醒应用的hap信息，使用callback异步回调。  
 **调用形式：**     
    
- setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | WakeupHapInfo | true | 唤醒hap信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回设置唤醒hap信息的结果。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let hapInfo: intelligentVoice.WakeupHapInfo = {  
  bundleName: 'com.wakeup',  
  abilityName: 'WakeUpExtAbility',  
}  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setWakeupHapInfo(hapInfo, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in setting wakeup hap info.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let hapInfo: intelligentVoice.WakeupHapInfo = {  
  bundleName: 'com.wakeup',  
  abilityName: 'WakeUpExtAbility',  
}  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setWakeupHapInfo(hapInfo).then(() => {  
    console.info(`Succeeded in setting wakeup hap info.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set wakeup hap info, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### setSensibility    
设置唤醒灵敏度，使用callback异步回调。  
 **调用形式：**     
    
- setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setSensibility(sensibility: SensibilityType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sensibility | SensibilityType | true |  灵敏度类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回设置灵敏度的结果。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in setting sensibility.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setSensibility(intelligentVoice.SensibilityType.LOW_SENSIBILITY).then(() => {  
    console.info(`Succeeded in setting sensibility.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set sensibility, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### setParameter    
设置指定的智能语音参数，使用callback异步回调。  
 **调用形式：**     
    
- setParameter(key: string, value: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setParameter(key: string, value: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 键 |  
| value | string | true |  值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回设置智能语音参数的结果。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setParameter('scene', '0', (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in setting parameter`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).setParameter('scene', '0').then(() => {  
    console.info(`Succeeded in setting parameter`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set parameter, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### getParameter    
获取指定的智能语音参数，使用callback异步回调。  
 **调用形式：**     
    
- getParameter(key: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getParameter(key: string): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回智能语音参数。 |  
| Promise<string> | 返回智能语音参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 22700102 | Input parameter value error. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getParameter('key', (err: BusinessError, data: string) => {  
    if (err) {  
      console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);  
    } else {  
      let param: string = data;  
      console.info(`Succeeded in getting parameter, param:${param}`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).getParameter('key').then((data: string) => {  
    let param: string = data;  
    console.info(`Succeeded in getting parameter, param:${param}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get parameter, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### release    
释放唤醒智能语音引擎，使用callback异步回调。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 10    
- release(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回释放唤醒引擎的结果。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).release((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to release wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
    } else {  
      console.info(`Succeeded in releasing wakeupIntelligentVoice engine.`);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).release().then(() => {  
    console.info(`Succeeded in releasing wakeupIntelligentVoice engine.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to release wakeupIntelligentVoice engine, Code:${err.code}, message:${err.message}`);  
  });  
}  
    
```    
  
    
### on('wakeupIntelligentVoiceEvent')    
订阅唤醒事件。  
 **调用形式：**     
    
- on(type: 'wakeupIntelligentVoiceEvent', callback: Callback\<WakeupIntelligentVoiceEngineCallbackInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 唤醒智能语音事件，固定取为'wakeupIntelligentVoiceEvent'，表示智能语音唤醒事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 收到唤醒事件的对应处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）  
```ts    
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).on('wakeupIntelligentVoiceEvent',  
    (info: intelligentVoice.WakeupIntelligentVoiceEngineCallbackInfo) => {  
    let callbackInfo: intelligentVoice.WakeupIntelligentVoiceEngineCallbackInfo = info;  
    console.info(`wakeup intelligentvoice event, info:${callbackInfo}`);  
  });  
}    
```    
  
    
### off('wakeupIntelligentVoiceEvent')    
取消订阅唤醒事件。  
 **调用形式：**     
    
- off(type: 'wakeupIntelligentVoiceEvent', callback?: Callback\<WakeupIntelligentVoiceEngineCallbackInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.AI.IntelligentVoice.Core  
 **需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 唤醒智能语音事件，固定取为'wakeupIntelligentVoiceEvent'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 收到唤醒事件的对应处理。无参数，则取消所有的订阅，否则，取消对应的订阅 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
```ts    
if (wakeupIntelligentVoiceEngine != null) {  
  (wakeupIntelligentVoiceEngine as intelligentVoice.WakeupIntelligentVoiceEngine).off('wakeupIntelligentVoiceEvent');  
}    
```    
  
