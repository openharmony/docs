# bundleStatusCallback    
应用状态发生变化时回调的信息，通过接口[innerBundleManager.on](js-apis-Bundle-InnerBundleManager.md)获取。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## BundleStatusCallback<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| add<sup>(deprecated)</sup> | (bundleName: string, userId: number) => void | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br><span style="font-size: 14px; letter-spacing: 0px;">获取应用安装时的信息。</span> |  
| update<sup>(deprecated)</sup> | (bundleName: string, userId: number) => void | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>获取应用更新时的信息。 |  
| remove<sup>(deprecated)</sup> | (bundleName: string, userId: number) => void | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>获取应用卸载时的信息。 |  
