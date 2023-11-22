# @ohos.multimodalInput.shortKey    
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import shortKey from '@ohos.multimodalInput.shortKey'    
```  
    
## setKeyDownDuration    
设置快捷键拉起Ability的延迟时间，使用Callback异步回调。  
 **调用形式：**     
    
- setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setKeyDownDuration(businessKey: string, delay: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.ShortKey    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| businessKey | string | true | 业务在多模侧注册的唯一标识，与ability_launch_config.json中的businessId对应。<br/> |  
| delay | number | true | 按下快捷键多长时间后拉起Ability，单位是毫秒（ms），仅支持快捷键按下触发。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，设置成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
import shortKey from '@ohos.multimodalInput.shortKey';  
try {  
  shortKey.setKeyDownDuration("screenshot", 500, (error) => {  
    if (error) {  
      console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Set key down duration success`);  
  });  
} catch (error) {  
  console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
import shortKey from '@ohos.multimodalInput.shortKey';  
try {  
  shortKey.setKeyDownDuration("screenshot", 500).then(() => {  
    console.log(`Set key down duration success`);  
  });  
} catch (error) {  
  console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
