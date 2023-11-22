# @ohos.bluetooth    
蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bluetooth from '@ohos.bluetooth'    
```  
    
## cancelPairedDevice<sup>(deprecated)</sup>    
删除配对的远程设备。  
 **调用形式：**     
- cancelPairedDevice(deviceId: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.cancelPairedDevice。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 启动取消配对，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let result : boolean = bluetooth.cancelPairedDevice("XX:XX:XX:XX:XX:XX");    
```    
  
