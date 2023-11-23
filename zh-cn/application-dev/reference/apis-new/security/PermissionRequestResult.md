# PermissionRequestResult    
权限请求结果对象，在调用[requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)申请权限时返回此对象表明此次权限申请的结果。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## PermissionRequestResult  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| permissions | Array<string> | false | true | 用户传入的权限。 |  
| authResults | Array<number> | false | true | 相应请求权限的结果：<br>- -1：未授权，表示权限已设置，无需弹窗，需要用户在"设置"中修改。<br>- 0：已授权。<br>- 2：未授权，表示请求无效，可能原因有：<br>  -未在设置文件中声明目标权限。<br>  -权限名非法。<br>  -部分权限存在特殊申请条件，在申请对应权限时未满足其指定的条件，见[ohos.permission.LOCATION](../../security/permission-list.md#ohospermissionlocation)与[ohos.permission.APPROXIMATELY_LOCATION](../../security/permission-list.md#ohospermissionapproximately_location)。 |  
