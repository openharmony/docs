# @ohos.arkui.performanceMonitor    
用户操作场景提供性能相关指标监测能力，目前仅包含响应时延、完成时延、丢帧。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import performanceMonitor from '@ohos.arkui.performanceMonitor'    
```  
    
## ActionType    
用户场景触发模式枚举。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LAST_DOWN | 0 | 用户按压事件触发。 |  
| LAST_UP | 1 | 用户离手事件触发。 |  
| FIRST_MOVE | 2 | 用户首次滑动事件触发。 |  
    
## begin    
用户场景开始。  
 **调用形式：**     
- begin(scene: string, startInputType: ActionType, note?: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scene | string | true | 用户场景id。 |  
| startInputType | ActionType | true | 用户场景触发模式。 |  
| note | string | false | 用户场景重要信息。 |  
    
 **示例代码：**   
```ts    
performanceMonitor.begin("LAUNCHER_APP_LAUNCH_FROM_ICON", performanceMonitor.ActionType.LAST_UP, "APP_START_BEGIN");    
```    
  
    
## end    
用户场景结束。<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");</span>。<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");</span>。  
 **调用形式：**     
- end(scene: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scene | string | true | 用户场景id，与begin配对。 |  
    
 **示例代码：**   
```ts    
performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");    
```    
  
    
 **示例代码：**   
```ts    
import performanceMonitor from '@ohos.arkui.performanceMonitor';    
```    
  
