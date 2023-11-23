# @ohos.usbManager    
本模块主要提供管理USB设备的相关功能，包括主设备上查询USB设备列表、批量数据传输、控制命令传输、权限控制等；从设备上端口管理、功能切换及查询等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import usbManager from '@ohos.usbManager'    
```  
    
## getDevices    
获取接入主设备的USB设备列表。如果没有设备接入，那么将会返回一个空的列表。  
 **调用形式：**     
- getDevices(): Array\<Readonly\<USBDevice>>  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<Readonly<USBDevice>> | 设备信息列表。 |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();console.log(`devicesList = ${devicesList}`);/*devicesList 返回的数据结构,此处提供一个简单的示例，如下[  {    name: "1-1",    serial: "",    manufacturerName: "",    productName: "",    version: "",    vendorId: 7531,    productId: 2,    clazz: 9,    subClass: 0,    protocol: 1,    devAddress: 1,    busNum: 1,    configs: [      {        id: 1,        attributes: 224,        isRemoteWakeup: true,        isSelfPowered: true,        maxPower: 0,        name: "1-1",        interfaces: [          {            id: 0,            protocol: 0,            clazz: 9,            subClass: 0,            alternateSetting: 0,            name: "1-1",            endpoints: [              {                address: 129,                attributes: 3,                interval: 12,                maxPacketSize: 4,                direction: 128,                number: 1,                type: 3,                interfaceId: 0,              },            ],          },        ],      },    ],  },]*/    
```    
  
    
## connectDevice    
根据getDevices()返回的设备信息打开USB设备。需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及device，再调用[usb.requestRight](#usbrequestright)请求使用该设备的权限。  
 **调用形式：**     
- connectDevice(device: USBDevice): Readonly\<USBDevicePipe>  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device | USBDevice | true | USB设备信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Readonly<USBDevicePipe> | 指定的传输通道对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14400001 | Permission denied. Need call requestRight to get permission. |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
let device: usb.USBDevice = devicesList[0];usb.requestRight(device.name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(device);console.log(`devicepipe = ${devicepipe}`);    
```    
  
    
## hasRight    
判断是否有权访问该设备。如果“使用者”（如各种App或系统）有权访问设备则返回true；无权访问设备则返回false。  
 **调用形式：**     
- hasRight(deviceName: string): boolean  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceName | string | true | 设备名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true表示有访问设备的权限，false表示没有访问设备的权限。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesName: string = "1-1";let right: boolean = usb.hasRight(devicesName);console.log(`${right}`);    
```    
  
    
## requestRight    
请求软件包的临时权限以访问设备。使用Promise异步回调。系统应用默认拥有访问设备权限，无需调用此接口申请。  
 **调用形式：**     
    
- requestRight(deviceName: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceName | string | true | 设备名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | Promise对象，返回临时权限的申请结果。返回true表示临时权限申请成功；返回false则表示临时权限申请失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesName: string = "1-1";usb.requestRight(devicesName).then(ret => {  console.log(`requestRight = ${ret}`);});    
```    
  
    
## removeRight    
移除软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。  
 **调用形式：**     
- removeRight(deviceName: string): boolean  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceName | string | true | 设备名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回权限移除结果。返回true表示权限移除成功；返回false则表示权限移除失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesName: string = "1-1";if (usb.removeRight(devicesName)) {  console.log(`Succeed in removing right`);}    
```    
  
    
## claimInterface    
注册通信接口。需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及interfaces；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| iface | USBInterface | true | 用于确定需要获取接口的索引。 |  
| force | boolean | false | 可选参数，是否强制获取。默认值为false，表示不强制获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 注册通信接口成功返回0；注册通信接口失败返回其他错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
let device: usb.USBDevice = devicesList[0];usb.requestRight(device.name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(device);let interfaces: usb.USBInterface = device.configs[0].interfaces[0];let ret: number= usb.claimInterface(devicepipe, interfaces);console.log(`claimInterface = ${ret}`);    
```    
  
    
## releaseInterface    
释放注册过的通信接口。需要调用[usb.claimInterface](#usbclaiminterface)先获取接口，才能使用此方法释放接口。  
 **调用形式：**     
- releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| iface | USBInterface | true | 用于确定需要释放接口的索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 释放接口成功返回0；释放接口失败返回其他错误码。 |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
let device: usb.USBDevice = devicesList[0];usb.requestRight(device.name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(device);let interfaces: usb.USBInterface = device.configs[0].interfaces[0];let ret: number = usb.claimInterface(devicepipe, interfaces);ret = usb.releaseInterface(devicepipe, interfaces);console.log(`releaseInterface = ${ret}`);    
```    
  
    
## setConfiguration    
设置设备配置。需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及config；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数。  
 **调用形式：**     
- setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| config | USBConfiguration | true | 用于确定需要设置的配置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 设置设备配置成功返回0；设置设备配置失败返回其他错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
let device: usb.USBDevice = devicesList[0];usb.requestRight(device.name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(device);let config: usb.USBConfiguration = device.configs[0];let ret: number= usb.setConfiguration(devicepipe, config);console.log(`setConfiguration = ${ret}`);    
```    
  
    
## setInterface    
设置设备接口。需要调用[usb.getDevices](#usbgetdevices)获取设备列表以及interfaces；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数；调用[usb.claimInterface](#usbclaiminterface)注册通信接口。  
 **调用形式：**     
- setInterface(pipe: USBDevicePipe, iface: USBInterface): number  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| iface | USBInterface | true | 用于确定需要设置的接口。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 设置设备接口成功返回0；设置设备接口失败返回其他错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
let device: usb.USBDevice = devicesList[0];usb.requestRight(device.name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(device);let interfaces: usb.USBInterface = device.configs[0].interfaces[0];let ret: number = usb.claimInterface(devicepipe, interfaces);ret = usb.setInterface(devicepipe, interfaces);console.log(`setInterface = ${ret}`);    
```    
  
    
## getRawDescriptor    
获取原始的USB描述符。  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- getRawDescriptor(pipe: USBDevicePipe): Uint8Array  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回获取的原始数据；失败返回undefined。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
usb.requestRight(devicesList[0].name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(devicesList[0]);let ret: Uint8Array = usb.getRawDescriptor(devicepipe);    
```    
  
    
## getFileDescriptor    
获取文件描述符。需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- getFileDescriptor(pipe: USBDevicePipe): number  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回设备对应的文件描述符；失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
usb.requestRight(devicesList[0].name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(devicesList[0]);let ret: number = usb.getFileDescriptor(devicepipe);    
```    
  
    
## controlTransfer    
控制传输。  需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
    
- controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定设备。 |  
| controlparam | USBControlParams | true | 控制传输参数。 |  
| timeout | number | false | 超时时间（单位：ms），可选参数，默认为0不超时。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> | Promise对象，获取传输或接收到的数据块大小。失败返回 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class PARA {  
  request: number = 0  
  reqType: usb.USBControlRequestType = 0  
  target: usb.USBRequestTargetType = 0  
  value: number = 0  
  index: number = 0  
  data: Uint8Array = new Uint8Array()  
}  
  
let param: PARA = {  
  request: 0,  
  reqType: 0,  
  target:0,  
  value: 0,  
  index: 0,  
  data: new Uint8Array()  
};  
  
let devicesList: Array<usb.USBDevice> = usb.getDevices();  
if (devicesList.length == 0) {  
  console.log(`device list is empty`);  
}  
  
usb.requestRight(devicesList[0].name);  
let devicepipe: usb.USBDevicePipe = usb.connectDevice(devicesList[0]);  
usb.controlTransfer(devicepipe, param).then((ret: number) => {  
 console.log(`controlTransfer = ${ret}`);  
})  
    
```    
  
    
## bulkTransfer    
批量传输。  需要调用[usb.getDevices](#usbgetdevices)获取设备信息列表以及endpoint；再调用[usb.requestRight](#usbrequestright)获取设备请求权限；然后调用[usb.connectDevice](#usbconnectdevice)接口得到返回数据devicepipe之后，再次获取接口[usb.claimInterface](#usbclaiminterface)；再调用usb.bulkTransfer接口。  
 **调用形式：**     
    
- bulkTransfer(    pipe: USBDevicePipe,    endpoint: USBEndpoint,    buffer: Uint8Array,    timeout?: number  ): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定设备。 |  
| endpoint | USBEndpoint | true | 用于确定传输的端口。 |  
| buffer | Uint8Array | true | 用于写入或读取数据的缓冲区。 |  
| timeout | number | false | 超时时间（单位：ms），可选参数，默认为0不超时。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> | Promise对象，获取传输或接收到的数据块大小。失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
//usb.getDevices 接口返回数据集合，取其中一个设备对象，并获取权限 。//把获取到的设备对象作为参数传入usb.connectDevice;当usb.connectDevice接口成功返回之后；//才可以调用第三个接口usb.claimInterface.当usb.claimInterface 调用成功以后,再调用该接口。let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
let device: usb.USBDevice = devicesList[0];usb.requestRight(device.name);  
let devicepipe: usb.USBDevicePipe = usb.connectDevice(device);let interfaces: usb.USBInterface = device.configs[0].interfaces[0];let endpoint: usb.USBEndpoint = device.configs[0].interfaces[0].endpoints[0];let ret: number = usb.claimInterface(devicepipe, interfaces);let buffer =  new Uint8Array(128);usb.bulkTransfer(devicepipe, endpoint, buffer).then((ret: number) => {  console.log(`bulkTransfer = ${ret}`);});    
```    
  
    
## closePipe    
<span style="letter-spacing: 0px;">关闭设备消息控制通道。</span>  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数。  
 **调用形式：**     
- closePipe(pipe: USBDevicePipe): number  
  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe | USBDevicePipe | true | 用于确定USB设备消息控制通道。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 关闭设备消息控制通道成功返回0；关闭设备消息控制通道失败返回其他错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let devicesList: Array<usb.USBDevice> = usb.getDevices();if (devicesList.length == 0) {  console.log(`device list is empty`);}  
usb.requestRight(devicesList[0].name);let devicepipe: usb.USBDevicePipe = usb.connectDevice(devicesList[0]);let ret: number = usb.closePipe(devicepipe);console.log(`closePipe = ${ret}`);    
```    
  
    
## USBEndpoint    
通过USB发送和接收数据的端口。通过[USBInterface](#usbinterface)获取。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| address | number | false | true | 端点地址。 |  
| attributes | number | false | true | 端点属性。 |  
| interval | number | false | true | 端点间隔。 |  
| maxPacketSize | number | false | true | 端点最大数据包大小。 |  
| direction | USBRequestDirection | false | true | 端点的方向。 |  
| number | number | false | true | 端点号。 |  
| type | number | false | true | 端点类型。 |  
| interfaceId | number | false | true | 端点所属的接口的唯一标识。 |  
    
## USBInterface    
一个[USBConfiguration](#usbconfiguration)中可以含有多个USBInterface，每个USBInterface提供一个功能。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | true | 接口的唯一标识。 |  
| protocol | number | false | true | 接口的协议。 |  
| clazz | number | false | true | 设备类型。 |  
| subClass | number | false | true | 设备子类。 |  
| alternateSetting | number | false | true | 在同一个接口中的多个描述符中进行切换设置。 |  
| name | string | false | true | 接口名称。 |  
| endpoints | Array<USBEndpoint> | false | true | 当前接口所包含的端点。 |  
    
## USBConfiguration    
USB配置，一个[USBDevice](#usbdevice)中可以含有多个配置。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | true | 配置的唯一标识。 |  
| attributes | number | false | true | 配置的属性。 |  
| maxPower | number | false | true | 最大功耗，以毫安为单位。 |  
| name | string | false | true | 配置的名称，可以为空。 |  
| isRemoteWakeup | boolean | false | true | 检查当前配置是否支持远程唤醒。 |  
| isSelfPowered | boolean | false | true | 检查当前配置是否支持独立电源。 |  
| interfaces | Array<USBInterface> | false | true | 配置支持的接口属性。 |  
    
## USBDevice    
USB设备信息。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| busNum | number | false | true | 总线地址。 |  
| devAddress | number | false | true | 设备地址。 |  
| serial | string | false | true | 序列号。 |  
| name | string | false | true | 设备名字。 |  
| manufacturerName | string | false | true | 产商信息。 |  
| productName | string | false | true | 产品信息。 |  
| version | string | false | true | 版本。 |  
| vendorId | number | false | true | 厂商ID。 |  
| productId | number | false | true | 产品ID。 |  
| clazz | number | false | true | 设备类。 |  
| subClass | number | false | true | 设备子类。 |  
| protocol | number | false | true | 设备协议码。 |  
| configs | Array<USBConfiguration> | false | true | 设备配置描述符信息。 |  
    
## USBDevicePipe    
USB设备消息传输通道，用于确定设备。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| busNum | number | false | true | 总线地址。 |  
| devAddress | number | false | true | 设备地址。 |  
    
## USBControlParams    
控制传输参数。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| request | number | false | true | 请求类型。 |  
| target | USBRequestTargetType | false | true | 请求目标类型。 |  
| reqType | USBControlRequestType | false | true | 请求控制类型。 |  
| value | number | false | true | 请求参数。 |  
| index | number | false | true | 请求参数value对应的索引值。 |  
| data | Uint8Array | false | true | 用于写入或读取的缓冲区。 |  
    
## USBRequestTargetType    
请求目标类型。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB_REQUEST_TARGET_DEVICE | 0 | 设备。 |  
| USB_REQUEST_TARGET_INTERFACE | 1 | 接口。 |  
| USB_REQUEST_TARGET_ENDPOINT | 2 | 端点。 |  
| USB_REQUEST_TARGET_OTHER | 3 | 其他。 |  
    
## USBControlRequestType    
控制请求类型。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB_REQUEST_TYPE_STANDARD | 0 | 标准。 |  
| USB_REQUEST_TYPE_CLASS | 1 | 类。 |  
| USB_REQUEST_TYPE_VENDOR | 2 | 厂商。 |  
    
## USBRequestDirection    
请求方向。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB_REQUEST_DIR_TO_DEVICE | 0 | 写数据，主设备往从设备。 |  
| USB_REQUEST_DIR_FROM_DEVICE | 0x80 | 读数据，从设备往主设备。 |  
