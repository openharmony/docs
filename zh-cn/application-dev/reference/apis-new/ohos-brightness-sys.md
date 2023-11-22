# @ohos.brightness    
该模块提供屏幕亮度的设置接口。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import brightness from '@ohos.brightness'    
```  
    
## setValue    
设置系统的屏幕亮度。  
 **调用形式：**     
- setValue(value: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 亮度的值。范围：0~255。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 4700101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    brightness.setValue(128);  
} catch(err) {  
    console.error('set brightness failed, err: ' + err);  
}  
    
```    
  
