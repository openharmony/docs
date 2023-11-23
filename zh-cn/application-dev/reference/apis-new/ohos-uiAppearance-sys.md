# @ohos.uiAppearance    
用户界面外观提供管理系统外观的一些基础能力，目前仅包括深浅色模式配置。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import uiAppearance from '@ohos.uiAppearance'    
```  
    
## DarkMode    
深色模式枚举。    
    
 **系统能力:**  SystemCapability.ArkUI.UiAppearance    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ALWAYS_DARK | 0 | 系统始终为深色。 |  
| ALWAYS_LIGHT | 1 | 系统始终为浅色。 |  
    
## setDarkMode    
设置系统深色模式。  
 **调用形式：**     
    
- setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setDarkMode(mode: DarkMode): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.UiAppearance  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | DarkMode | true | 指定系统的深色模式配置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 配置深色模式的异步回调 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 500001 | Internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import uiAppearance from '@ohos.uiAppearance'  
import { BusinessError } from '@ohos.base';  
try {  
    uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK, (error) => {  
      if (error) {  
        console.error('Set dark-mode failed, ' + error.message);  
      } else {  
        console.info('Set dark-mode successfully.');  
      }  
    })  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('Set dark-mode failed, ' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import uiAppearance from '@ohos.uiAppearance'  
import { BusinessError } from '@ohos.base';  
try {  
    uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK).then(() => {  
      console.info('Set dark-mode successfully.');  
    }).catch((error:Error) => {  
      console.error('Set dark-mode failed, ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('Set dark-mode failed, ' + message);  
}  
    
```    
  
    
## getDarkMode    
获取当前的深色模式配置。  
 **调用形式：**     
- getDarkMode(): DarkMode  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.UiAppearance  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DarkMode | 系统当前的深色模式配置 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 500001 | Internal error. |  
    
 **示例代码：**   
```ts    
import uiAppearance from '@ohos.uiAppearance'  
import { BusinessError } from '@ohos.base';  
try {  
    let darkMode = uiAppearance.getDarkMode();  
    console.info('Get dark-mode ' + darkMode);  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('Get dark-mode failed, ' + message);  
}  
    
```    
  
