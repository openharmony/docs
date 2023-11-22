# @ohos.usb    
本模块主要提供管理USB设备的相关功能，包括查询USB设备列表、批量数据传输、控制命令传输、权限控制等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import usb from '@ohos.usb'    
```  
    
## usbFunctionsFromString<sup>(deprecated)</sup>    
在设备模式下，将字符串形式的USB功能列表转化为数字掩码。  
 **调用形式：**     
- usbFunctionsFromString(funcs: string): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| funcs<sup>(deprecated)</sup> | string | true | 字符串形式的功能列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 转化后的数字掩码。 |  
    
 **示例代码：**   
```js    
let funcs = "acm";let ret = usb.usbFunctionsFromString(funcs);    
```    
  
    
## usbFunctionsToString<sup>(deprecated)</sup>    
在设备模式下，将数字掩码形式的USB功能列表转化为字符串。  
 **调用形式：**     
- usbFunctionsToString(funcs: FunctionType): string  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| funcs<sup>(deprecated)</sup> | FunctionType | true | USB功能数字掩码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 转化后的字符串形式的功能列表。 |  
    
 **示例代码：**   
```js    
let funcs = usb.FunctionType.ACM | usb.FunctionType.ECM;let ret = usb.usbFunctionsToString(funcs);    
```    
  
    
## setCurrentFunctions<sup>(deprecated)</sup>    
在设备模式下，设置当前的USB功能列表。  
 **调用形式：**     
- setCurrentFunctions(funcs: FunctionType): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| funcs<sup>(deprecated)</sup> | FunctionType | true | USB功能数字掩码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象，返回设置成功与否的结果。true表示设置成功，false表示设置失败。 |  
    
 **示例代码：**   
```js    
let funcs = usb.FunctionType.HDC;usb.setCurrentFunctions(funcs).then(() => {    console.info('usb setCurrentFunctions successfully.');}).catch(err => {    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);});    
```    
  
    
## getCurrentFunctions<sup>(deprecated)</sup>    
在设备模式下，获取当前的USB功能列表的数字组合掩码。  
 **调用形式：**     
- getCurrentFunctions(): FunctionType  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FunctionType | 当前的USB功能列表的数字组合掩码。 |  
    
 **示例代码：**   
```js    
let ret = usb.getCurrentFunctions();    
```    
  
    
## getPorts<sup>(deprecated)</sup>    
获取所有物理USB端口描述信息。  
 **调用形式：**     
- getPorts(): Array\<USBPort>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<USBPort> | USB端口描述信息列表。 |  
    
 **示例代码：**   
```js    
let ret = usb.getPorts();    
```    
  
    
## getSupportedModes<sup>(deprecated)</sup>    
获取指定的端口支持的模式列表的组合掩码。  
 **调用形式：**     
- getSupportedModes(portId: number): PortModeType  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| portId<sup>(deprecated)</sup> | number | true | 端口号。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PortModeType | 支持的模式列表的组合掩码。 |  
    
 **示例代码：**   
```js    
let ret = usb.getSupportedModes(0);    
```    
  
    
## setPortRoles<sup>(deprecated)</sup>    
设置指定的端口支持的角色模式，包含充电角色、数据传输角色。  
 **调用形式：**     
- setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| portId<sup>(deprecated)</sup> | number | true | 端口号。 |  
| powerRole<sup>(deprecated)</sup> | PowerRoleType | true | 充电的角色 |  
| dataRole<sup>(deprecated)</sup> | DataRoleType | true | 数据传输的角色。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象，返回设置成功与否的结果。true表示设置成功，false表示设置失败。 |  
    
 **示例代码：**   
```js    
let portId = 1;usb.setPortRoles(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {    console.info('usb setPortRoles successfully.');}).catch(err => {    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);});    
```    
  
    
## PowerRoleType<sup>(deprecated)</sup>    
电源角色类型。    
从API version 9 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 9 开始废弃。<br>无。 |  
| SOURCE<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 9 开始废弃。<br>外部供电。 |  
| SINK<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 9 开始废弃。<br>内部供电。 |  
    
## DataRoleType<sup>(deprecated)</sup>    
数据角色类型。    
从API version 9 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 9 开始废弃。<br> 无。 |  
| HOST<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 9 开始废弃。<br>主设备角色。 |  
| DEVICE<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 9 开始废弃。<br>从设备角色。 |  
    
## PortModeType<sup>(deprecated)</sup>    
USB端口模式类型。    
从API version 9 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 9 开始废弃。<br> 无。    |  
| UFP<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 9 开始废弃。<br>数据上行，需要外部供电。  |  
| DFP<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 9 开始废弃。<br>数据下行，对外提供电源。  |  
| DRP<sup>(deprecated)</sup> | 3 | 从API version 9 开始支持，从API version 9 开始废弃。<br>既可以做DFP(Host)，也可以做UFP(Device)，当前不支持。 |  
| NUM_MODES<sup>(deprecated)</sup> | 4 | 从API version 9 开始支持，从API version 9 开始废弃。<br>当前不支持。   |  
    
## USBPortStatus<sup>(deprecated)</sup>    
USB设备端口角色信息。    
从API version 9 开始支持，从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| currentMode<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 9 开始废弃。<br>当前的USB模式。 |  
| currentPowerRole<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 9 开始废弃。<br>当前设备充电模式。 |  
| currentDataRole<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 9 开始废弃。<br>当前设备数据传输模式。 |  
    
## USBPort<sup>(deprecated)</sup>    
USB设备端口。    
从API version 9 开始支持，从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 9 开始废弃。<br>USB端口唯一标识。 |  
| supportedModes<sup>(deprecated)</sup> | PortModeType | false | true | 从API version 9 开始支持，从API version 9 开始废弃。<br>USB端口所支持的模式的数字组合掩码。 |  
| status<sup>(deprecated)</sup> | USBPortStatus | false | true | 从API version 9 开始支持，从API version 9 开始废弃。<br>USB端口角色。 |  
    
## FunctionType<sup>(deprecated)</sup>    
USB设备侧功能。    
从API version 9 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 9 开始废弃。<br>没有功能。 |  
| ACM<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 9 开始废弃。<br>acm功能。 |  
| ECM<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 9 开始废弃。<br>ecm功能。 |  
| HDC<sup>(deprecated)</sup> | 4 | 从API version 9 开始支持，从API version 9 开始废弃。<br>hdc功能。 |  
| MTP<sup>(deprecated)</sup> | 8 | 从API version 9 开始支持，从API version 9 开始废弃。<br>暂不支持。 |  
| PTP<sup>(deprecated)</sup> | 16 | 从API version 9 开始支持，从API version 9 开始废弃。<br>暂不支持。 |  
| RNDIS<sup>(deprecated)</sup> | 32 | 从API version 9 开始支持，从API version 9 开始废弃。<br>暂不支持。 |  
| MIDI<sup>(deprecated)</sup> | 64 | 从API version 9 开始支持，从API version 9 开始废弃。<br>暂不支持。 |  
| AUDIO_SOURCE<sup>(deprecated)</sup> | 128 | 从API version 9 开始支持，从API version 9 开始废弃。<br>暂不支持。 |  
| NCM<sup>(deprecated)</sup> | 256 | 从API version 9 开始支持，从API version 9 开始废弃。<br>暂不支持。 |  
