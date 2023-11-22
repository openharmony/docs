# @ohos.file.fileExtensionInfo    
该模块提供公共文件访问和管理模块中RootInfo与FileInfo中部分属性值的定义。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fileExtensionInfo from '@ohos.file.fileExtensionInfo'    
```  
    
## DeviceType    
组成RootInfo中的deviceType字段，表明此设备的类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_LOCAL_DISK | 1 | 本地c,d...盘。 |  
| DEVICE_SHARED_DISK | 2 | 多用户共享盘。 |  
| DEVICE_SHARED_TERMINAL | 3 | 分布式网络终端设备。 |  
| DEVICE_NETWORK_NEIGHBORHOODS | 4 | 网络邻居设备。 |  
| DEVICE_EXTERNAL_MTP | 5 | MTP设备。 |  
| DEVICE_EXTERNAL_USB | 6 | USB设备。 |  
| DEVICE_EXTERNAL_CLOUD | 7 | 云盘设备。 |  
