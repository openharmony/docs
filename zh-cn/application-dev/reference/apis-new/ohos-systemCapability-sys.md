# @ohos.systemCapability    
系统能力（SystemCapability，简称SysCap），指操作系统中每一个相对独立的特性。不同的设备对应不同的系统能力集，每个系统能力对应多个接口。开发者可根据系统能力来判断是否可以使用某接口。本模块提供接口可查询系统能力的集合。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemCapability from '@ohos.systemCapability'    
```  
    
## querySystemCapabilities    
获取系统能力集合的字符串，并调用回调函数。  
 **调用形式：**     
    
- querySystemCapabilities(callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Developtools.Syscap    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
try {  
    systemcapability.querySystemCapabilities((err:Error, data:string) => {  
    if (err == undefined) {  
        console.log("get system capabilities:" + data)  
    } else {  
        console.log(" get system capabilities err:" + err)  
    }});  
}catch(e){  
    console.log("get unexpected error: " + e);  
}  
    
```    
  
