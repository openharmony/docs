# DriverExtensionContext    
DriverExtensionContext模块是DriverExtensionAbility的上下文环境，继承自ExtensionContext。DriverExtensionContext模块提供DriverExtensionAbility实现中需要主动发起的操作。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DriverExtensionContext    
在使用DriverExtensionContext的功能前，需要通过DriverExtensionAbility子类实例获取。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
### updateDriverState    
驱动状态上报。预留接口，暂不提供具体功能。  
 **调用形式：**     
- updateDriverState(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **示例代码：**   
```ts    
if (context != null) {  
    context.updateDriverState();  
  }  
    
```    
  
