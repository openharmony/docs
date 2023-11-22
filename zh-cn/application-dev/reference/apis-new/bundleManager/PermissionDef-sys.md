# PermissionDef    
配置文件中定义的权限详细信息，通过接口[bundleManager.getPermissionDef](js-apis-bundleManager.md)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## PermissionDef  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| permissionName | string | true | true | 用户权限名称。 |  
| grantMode | number | true | true | 权限的授予模式。 |  
| labelId | number | true | true | 权限的标签ID。 |  
| descriptionId | number | true | true | 描述权限的ID。 |  
