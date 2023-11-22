# @ohos.usbManager    
本模块主要提供管理USB设备的相关功能，包括主设备上查询USB设备列表、批量数据传输、控制命令传输、权限控制等；从设备上端口管理、功能切换及查询等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import usbManager from '@ohos.usbManager'    
```  
    
## addRight    
添加软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。  
 **调用形式：**     
- addRight(bundleName: string, deviceName: string): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 软件包名称。 |  
| deviceName | string | true | 设备名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回权限添加结果。返回true表示权限添加成功；返回false则表示权限添加失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesName: string = "1-1";let bundleName: string = "com.example.hello";if (usb.addRight(bundleName, devicesName)) {  console.log(`Succeed in adding right`);}    
```    
  
    
## usbFunctionsFromString    
在设备模式下，将字符串形式的USB功能列表转化为数字掩码。  
 **调用形式：**     
- usbFunctionsFromString(funcs: string): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| funcs | string | true | 字符串形式的功能列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 转化后的数字掩码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let funcs: string = "acm";let ret: number = usb.usbFunctionsFromString(funcs);    
```    
  
    
## usbFunctionsToString    
在设备模式下，将数字掩码形式的USB功能列表转化为字符串。  
 **调用形式：**     
- usbFunctionsToString(funcs: FunctionType): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| funcs | FunctionType | true | USB功能数字掩码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 转化后的字符串形式的功能列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let funcs: number = usb.FunctionType.ACM | usb.FunctionType.ECM;let ret: string = usb.usbFunctionsToString(funcs);    
```    
  
    
## setCurrentFunctions    
在设备模式下，设置当前的USB功能列表。  
 **调用形式：**     
    
- setCurrentFunctions(funcs: FunctionType): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| funcs | FunctionType | true | USB功能数字掩码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14400002 | Permission denied.The HDC is disabled by the system. |  
    
 **示例代码：**   
```ts    
import {BusinessError} from '@ohos.base';  
let funcs: number = usb.FunctionType.HDC;  
usb.setCurrentFunctions(funcs).then(() => {  
    console.info('usb setCurrentFunctions successfully.');  
}).catch((err: BusinessError) => {  
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);  
});  
    
```    
  
    
## getCurrentFunctions    
在设备模式下，获取当前的USB功能列表的数字组合掩码。  
 **调用形式：**     
- getCurrentFunctions(): FunctionType  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FunctionType | 当前的USB功能列表的数字组合掩码。 |  
    
 **示例代码：**   
```ts    
let ret: number = usb.getCurrentFunctions();    
```    
  
    
## getPorts  
 **调用形式：**     
- getPorts(): Array\<USBPort>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<USBPort> | USB端口描述信息列表。 |  
    
 **示例代码：**   
```ts    
let ret: Array<usb.USBPort> = usb.getPorts();    
```    
  
    
## getSupportedModes    
获取指定的端口支持的模式列表的组合掩码。  
 **调用形式：**     
- getSupportedModes(portId: number): PortModeType  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| portId | number | true | 端口号。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PortModeType | 支持的模式列表的组合掩码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let ret: number = usb.getSupportedModes(0);    
```    
  
    
## setPortRoles    
设置指定的端口支持的角色模式，包含充电角色、数据传输角色。  
 **调用形式：**     
    
- setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| portId | number | true | 端口号。 |  
| powerRole | PowerRoleType | true | 充电的角色。 |  
| dataRole | DataRoleType | true | 数据传输的角色。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import {BusinessError} from '@ohos.base';  
let portId: number = 1;  
usb.setPortRoles(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {  
    console.info('usb setPortRoles successfully.');  
}).catch((err: BusinessError) => {  
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);  
});  
    
```    
  
    
## PowerRoleType    
电源角色类型。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 无。 |  
| SOURCE | 1 | 外部供电。 |  
| SINK | 2 | 内部供电。 |  
    
## DataRoleType    
数据角色类型。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 无。 |  
| HOST | 1 | 主设备角色。 |  
| DEVICE | 2 | 从设备角色。 |  
    
## PortModeType    
USB端口模式类型。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 无。 |  
| UFP | 1 | 数据上行，需要外部供电。 |  
| DFP | 2 | 数据下行，对外提供电源。 |  
| DRP | 3 | 既可以做DFP(Host)，也可以做UFP(Device)，当前不支持。 |  
| NUM_MODES | 4 | 当前不支持。 |  
    
## USBPortStatus    
USB设备端口角色信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| currentMode | number | false | true | 当前的USB模式。 |  
| currentPowerRole | number | false | true | 当前设备充电模式。 |  
| currentDataRole | number | false | true | 当前设备数据传输模式。 |  
    
## USBPort    
USB设备端口。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | true | USB端口唯一标识。 |  
| supportedModes | PortModeType | false | true | USB端口所支持的模式的数字组合掩码。 |  
| status | USBPortStatus | false | true | USB端口角色。 |  
    
## FunctionType    
USB设备侧功能。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 没有功能。 |  
| ACM | 1 | acm功能。 |  
| ECM | 2 | ecm功能。 |  
| HDC | 4 | hdc功能。 |  
| MTP | 8 | 暂不支持。 |  
| PTP | 16 | 暂不支持。 |  
| RNDIS | 32 | 暂不支持。 |  
| MIDI | 64 | 暂不支持。 |  
| AUDIO_SOURCE | 128 | 暂不支持。 |  
| NCM | 256 | 暂不支持。 |  
