# @ohos.deviceInfo    
本模块提供产品信息。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceInfo from '@ohos.deviceInfo'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.Startup.SystemInfo    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| deviceType | string |  | 设备类型。 |  
| manufacture | string |  | 设备厂家名称。 |  
| brand | string |  | 设备品牌名称。 |  
| marketName | string |  | 外部产品系列。 |  
| productSeries | string |  | 产品系列。 |  
| productModel | string |  | 认证型号。 |  
| softwareModel | string |  | 内部软件子型号。 |  
| hardwareModel | string |  | 硬件版本号。 |  
| hardwareProfile<sup>(deprecated)</sup> | string |  | 从API version 6 开始支持，从API version 9 开始废弃。<br>硬件Profile。 |  
| serial | string |  | 设备序列号。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID 。 |  
| bootloaderVersion | string |  | Bootloader版本号。 |  
| abiList | string |  | 应用二进制接口（Abi）列表。 |  
| securityPatchTag | string |  | 安全补丁级别。 |  
| displayVersion | string |  | 产品版本。 |  
| incrementalVersion | string |  | 差异版本号。 |  
| osReleaseType | string |  | 系统的发布类型，取值为：<br/>-Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br/>-Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br/>-Release：面向开发者公开发布的正式版本，承诺API稳定性。 |  
| osFullName | string |  | 系统版本。 |  
| majorVersion | number |  | Major版本号，随主版本更新增加。 |  
| seniorVersion | number |  | Senior版本号，随局部架构、重大特性增加。 |  
| featureVersion | number |  | Feature版本号，标识规划的新特性版本。 |  
| buildVersion | number |  | Build版本号，标识编译构建的版本号。 |  
| sdkApiVersion | number |  | 系统软件API版本。 |  
| firstApiVersion | number |  | 首个版本系统软件API版本。 |  
| versionId | string |  | 版本ID。 |  
| buildType | string |  | 构建类型。 |  
| buildUser | string |  | 构建用户。 |  
| buildHost | string |  | 构建主机。 |  
| buildTime | string |  | 构建时间。 |  
| buildRootHash | string |  | 构建版本Hash。 |  
| udid<sup>(7+)</sup> | string |  | 设备Udid。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID。 |  
| distributionOSName<sup>(10+)</sup> | string |  | 发行版系统名称。 |  
| distributionOSVersion<sup>(10+)</sup> | string |  | 发行版系统版本号。 |  
| distributionOSApiVersion<sup>(10+)</sup> | number |  | 发行版系统api版本。 |  
| distributionOSReleaseType<sup>(10+)</sup> | string |  | 发行版系统类型。 |  
