# @ohos.distributedBundle    
本模块提供分布式包的管理。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedBundle from '@ohos.distributedBundle'    
```  
    
## getRemoteAbilityInfo<sup>(deprecated)</sup>    
以异步方法根据给定的ElementName获取有关远程设备AbilityInfo信息，使用callback形式返回结果。  
  
 **调用形式：**     
- getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.distributedBundleManager#getRemoteAbilityInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName<sup>(deprecated)</sup> | ElementName | true | 获得的ElementName信息。       |  
| callback<sup>(deprecated)</sup> | AsyncCallback<RemoteAbilityInfo> | true | 程序启动作为入参的回调函数，返回远程基本能力信息。 。 |  
    
## getRemoteAbilityInfo<sup>(deprecated)</sup>    
以异步方法根据给定的ElementName获取有关远程设备AbilityInfo信息，使用Promise形式返回结果。  
 **调用形式：**     
- getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.distributedBundleManager#getRemoteAbilityInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName<sup>(deprecated)</sup> | ElementName | true | 获得的ElementName信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<RemoteAbilityInfo> | Promise形式返回远程基本能力信息。 |  
    
## getRemoteAbilityInfos<sup>(deprecated)</sup>    
以异步方法根据给定的ElementName获取有关远程设备AbilityInfo信息，使用callback形式返回结果。  
 **调用形式：**     
- getRemoteAbilityInfos(elementNames: Array\<ElementName>,     callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.distributedBundleManager#getRemoteAbilityInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementNames<sup>(deprecated)</sup> | Array<ElementName> | true | 获得的ElementName信息。      。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<RemoteAbilityInfo>> | true | 以异步方法根据给定的ElementName获取有关远程设备AbilityInfo信息，使用callback形式返回结果。 |  
    
## getRemoteAbilityInfos<sup>(deprecated)</sup>    
以异步方法根据给定的ElementName获取有关远程设备AbilityInfos信息，使用Promise形式返回结果。  
 **调用形式：**     
- getRemoteAbilityInfos(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.distributedBundleManager#getRemoteAbilityInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementNames<sup>(deprecated)</sup> | Array<ElementName> | true | ElementName信息，最大数组长度为10。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<RemoteAbilityInfo>> | Promise形式返回远程基本能力信息。 |  
