# @ohos.distributedHardware.deviceManager    
本模块能力已更新至新模块。建议使用新模块的接口进行开发，参见[@ohos.distributedDeviceManager](js-apis-distributedDeviceManager.md)。  
本模块提供分布式设备管理能力。  
系统应用可调用接口实现如下功能：。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceManager from '@ohos.distributedHardware.deviceManager'    
```  
    
## DeviceManager    
设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
