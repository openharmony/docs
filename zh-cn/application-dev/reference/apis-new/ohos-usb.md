# @ohos.usb    
本模块主要提供管理USB设备的相关功能，包括查询USB设备列表、批量数据传输、控制命令传输、权限控制等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import usb from '@ohos.usb'    
```  
    
## getDevices<sup>(deprecated)</sup>    
获取USB设备列表。  
 **调用形式：**     
- getDevices(): Array\<Readonly\<USBDevice>>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<Readonly<USBDevice>> | 设备信息列表。 |  
    
 **示例代码：**   
```js    
let devicesList = usb.getDevices();console.log(`devicesList = ${devicesList}`);//devicesList  返回的数据结构//此处提供一个简单的示例，如下[  {    name: "1-1",    serial: "",    manufacturerName: "",    productName: "",    version: "",    vendorId: 7531,    productId: 2,    clazz: 9,    subClass: 0,    protocol: 1,    devAddress: 1,    busNum: 1,    configs: [      {        id: 1,        attributes: 224,        isRemoteWakeup: true,        isSelfPowered: true,        maxPower: 0,        name: "1-1",        interfaces: [          {            id: 0,            protocol: 0,            clazz: 9,            subClass: 0,            alternateSetting: 0,            name: "1-1",            endpoints: [              {                address: 129,                attributes: 3,                interval: 12,                maxPacketSize: 4,                direction: 128,                number: 1,                type: 3,                interfaceId: 0,              },            ],          },        ],      },    ],  },]    
```    
  
    
## connectDevice<sup>(deprecated)</sup>    
打开USB设备。  
 **调用形式：**     
- connectDevice(device: USBDevice): Readonly\<USBDevicePipe>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | USBDevice | true | USB设备信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Readonly<USBDevicePipe> | 指定的传输通道对象。 |  
    
 **示例代码：**   
```js    
let devicepipe= usb.connectDevice(device);console.log(`devicepipe = ${devicepipe}`);    
```    
  
    
## hasRight<sup>(deprecated)</sup>    
判断是否有权访问该设备。  
 **调用形式：**     
- hasRight(deviceName: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceName<sup>(deprecated)</sup> | string | true | 设备名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true表示有访问设备的权限，false表示没有访问设备的权限。 |  
    
 **示例代码：**   
```js    
let devicesName= "1-1";let bool = usb.hasRight(devicesName);console.log(bool);    
```    
  
    
## requestRight<sup>(deprecated)</sup>    
请求软件包的临时权限以访问设备。使用Promise异步回调。系统应用默认拥有访问设备权限，无需调用此接口申请。  
 **调用形式：**     
- requestRight(deviceName: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceName<sup>(deprecated)</sup> | string | true | 设备名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象，返回临时权限的申请结果。返回true表示临时权限申请成功；返回false则表示临时权限申请失败。 |  
    
 **示例代码：**   
```js    
let devicesName= "1-1";usb.requestRight(devicesName).then((ret) => {  console.log(`requestRight = ${ret}`);});    
```    
  
    
## claimInterface<sup>(deprecated)</sup>    
注册通信接口。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及interfaces；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| iface<sup>(deprecated)</sup> | USBInterface | true | 用于确定需要获取接口的索引。 |  
| force<sup>(deprecated)</sup> | boolean | false | 可选参数，是否强制获取。默认值为false，表示不强制获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 注册通信接口成功返回0；注册通信接口失败返回其他错误码。 |  
    
 **示例代码：**   
```js    
let ret = usb.claimInterface(devicepipe, interfaces);console.log(`claimInterface = ${ret}`);    
```    
  
    
## releaseInterface<sup>(deprecated)</sup>    
释放注册过的通信接口。  
 **调用形式：**     
- releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| iface<sup>(deprecated)</sup> | USBInterface | true | 用于确定需要释放接口的索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 释放接口成功返回0；释放接口失败返回其他错误码。 |  
    
 **示例代码：**   
```js    
let ret = usb.releaseInterface(devicepipe, interfaces);console.log(`releaseInterface = ${ret}`);    
```    
  
    
## setConfiguration<sup>(deprecated)</sup>    
设置设备配置。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及config；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数。  
 **调用形式：**     
- setConfiguration(pipe: USBDevicePipe, config: USBConfig): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| config<sup>(deprecated)</sup> | USBConfig | true | 用于确定需要设置的配置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 设置设备配置成功返回0；设置设备配置失败返回其他错误码。 |  
    
 **示例代码：**   
```js    
let ret = usb.setConfiguration(devicepipe, config);console.log(`setConfiguration = ${ret}`);    
```    
  
    
## setInterface<sup>(deprecated)</sup>    
设置设备接口。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表以及interfaces；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数；调用[usb.claimInterface](#usbclaiminterface)注册通信接口。  
 **调用形式：**     
- setInterface(pipe: USBDevicePipe, iface: USBInterface): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
| iface<sup>(deprecated)</sup> | USBInterface | true | 用于确定需要设置的接口。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 设置设备接口成功返回0；设置设备接口失败返回其他错误码。 |  
    
 **示例代码：**   
```js    
let ret = usb.setInterface(devicepipe, interfaces);console.log(`setInterface = ${ret}`);    
```    
  
    
## getRawDescriptor<sup>(deprecated)</sup>    
获取原始的USB描述符。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- getRawDescriptor(pipe: USBDevicePipe): Uint8Array  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回获取的原始数据；失败返回undefined。 |  
    
 **示例代码：**   
```js    
let ret = usb.getRawDescriptor(devicepipe);    
```    
  
    
## getFileDescriptor<sup>(deprecated)</sup>    
获取文件描述符。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- getFileDescriptor(pipe: USBDevicePipe): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定总线号和设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回设备对应的文件描述符；失败返回-1。 |  
    
 **示例代码：**   
```js    
let ret = usb.getFileDescriptor(devicepipe);    
```    
  
    
## controlTransfer<sup>(deprecated)</sup>    
控制传输。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。  
 **调用形式：**     
- controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定设备。 |  
| controlparam<sup>(deprecated)</sup> | USBControlParams | true | 控制传输参数。 |  
| timeout<sup>(deprecated)</sup> | number | false | 超时时间（单位：ms），可选参数，默认为0不超时。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，获取传输或接收到的数据块大小。失败返回-1。 |  
    
 **示例代码：**   
```js    
let param = {  request: 0,  reqType: 0,  target:0,  value: 0,  index: 0,  data: null};usb.controlTransfer(devicepipe, param).then((ret) => { console.log(`controlTransfer = ${ret}`);})    
```    
  
    
## bulkTransfer<sup>(deprecated)</sup>    
批量传输。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备信息列表以及endpoint；再调用[usb.requestRight](#usbrequestright)获取设备请求权限；然后调用[usb.connectDevice](#usbconnectdevice)接口得到返回数据devicepipe之后，再次获取接口[usb.claimInterface](#usbclaiminterface)；再调用usb.bulkTransfer接口。  
 **调用形式：**     
- bulkTransfer(    pipe: USBDevicePipe,    endpoint: USBEndpoint,    buffer: Uint8Array,    timeout?: number  ): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true |  用于确定设备。 |  
| endpoint<sup>(deprecated)</sup> | USBEndpoint | true | 用于确定传输的端口。 |  
| buffer<sup>(deprecated)</sup> | Uint8Array | true | 用于写入或读取的缓冲区。 |  
| timeout<sup>(deprecated)</sup> | number | false |  超时时间（单位：ms），可选参数，默认为0不超时。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，获取传输或接收到的数据块大小。失败返回-1。 |  
    
 **示例代码：**   
```js    
//usb.getDevices 接口返回数据集合，取其中一个设备对象，并获取权限 。//把获取到的设备对象作为参数传入usb.connectDevice;当usb.connectDevice接口成功返回之后；//才可以调用第三个接口usb.claimInterface.当usb.claimInterface 调用成功以后,再调用该接口。usb.bulkTransfer(devicepipe, endpoint, buffer).then((ret) => { console.log(`bulkTransfer = ${ret}`);});    
```    
  
    
## closePipe<sup>(deprecated)</sup>    
关闭设备消息控制通道。  
  
需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数。  
 **调用形式：**     
- closePipe(pipe: USBDevicePipe): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pipe<sup>(deprecated)</sup> | USBDevicePipe | true | 用于确定USB设备消息控制通道。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 关闭设备消息控制通道成功返回0；关闭设备消息控制通道失败返回其他错误码。 |  
    
 **示例代码：**   
```js    
let ret = usb.closePipe(devicepipe);console.log(`closePipe = ${ret}`);    
```    
  
    
## USBEndpoint<sup>(deprecated)</sup>    
通过USB发送和接收数据的端口。通过[USBInterface](#usbinterface)获取。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| address<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点地址。 |  
| attributes<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点属性。  |  
| interval<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点间隔。 |  
| maxPacketSize<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点最大数据包大小。 |  
| direction<sup>(deprecated)</sup> | USBRequestDirection | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点的方向。 |  
| number<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点号。 |  
| type<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点类型。 |  
| interfaceId<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点所属的接口的唯一标识。 |  
    
## USBInterface<sup>(deprecated)</sup>    
一个[USBConfig](#usbconfig)中可以含有多个USBInterface，每个USBInterface提供一个功能。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>接口的唯一标识。 |  
| protocol<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>接口的协议。  |  
| clazz<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备类型。  |  
| subClass<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备子类。 |  
| alternateSetting<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>在同一个接口中的多个描述符中进行切换设置。 |  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>接口名称。   |  
| endpoints<sup>(deprecated)</sup> | Array<USBEndpoint> | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>当前接口所包含的端点。 |  
    
## USBConfig<sup>(deprecated)</sup>    
USB配置，一个[USBDevice](#usbdevice)中可以含有多个配置。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>配置的唯一标识。  |  
| attributes<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>配置的属性。  |  
| maxPower<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>最大功耗，以毫安为单位。 |  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>配置的名称，可以为空。  |  
| isRemoteWakeup<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>检查当前配置是否支持远程唤醒。 |  
| isSelfPowered<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>检查当前配置是否支持独立电源。 |  
| interfaces<sup>(deprecated)</sup> | Array<USBInterface> | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>配置支持的接口属性。 |  
    
## USBDevice<sup>(deprecated)</sup>    
USB设备信息。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| busNum<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>总线地址。 |  
| devAddress<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备地址。 |  
| serial<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>序列号。 |  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备名字。 |  
| manufacturerName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>产商信息。 |  
| productName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>产品信息。 |  
| version<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>版本。 |  
| vendorId<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>厂商ID。 |  
| productId<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>产品ID。 |  
| clazz<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备类。 |  
| subClass<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备子类。  |  
| protocol<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备协议码。 |  
| configs<sup>(deprecated)</sup> | Array<USBConfig> | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备配置描述符信息。 |  
    
## USBDevicePipe<sup>(deprecated)</sup>    
USB设备消息传输通道，用于确定设备。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| busNum<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>总线地址。 |  
| devAddress<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备地址。 |  
    
## USBControlParams<sup>(deprecated)</sup>    
控制传输参数。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.USB.USBManager    
### 属性    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>请求类型。   |  
| target<sup>(deprecated)</sup> | USBRequestTargetType | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br> <span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">请求目标类型。</span><br/> |  
| reqType<sup>(deprecated)</sup> | USBControlRequestType | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>请求控制类型。 |  
| value<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>请求参数。 |  
| index<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>请求参数value对应的索引值。 |  
| data<sup>(deprecated)</sup> | Uint8Array | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>用于写入或读取的缓冲区。 |  
    
## USBRequestTargetType<sup>(deprecated)</sup>    
请求目标类型。    
从API version 8 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB_REQUEST_TARGET_DEVICE<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备。 |  
| USB_REQUEST_TARGET_INTERFACE<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br> 接口。 |  
| USB_REQUEST_TARGET_ENDPOINT<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。<br>端点。 |  
| USB_REQUEST_TARGET_OTHER<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。<br>其他。 |  
    
## USBControlRequestType<sup>(deprecated)</sup>    
控制请求类型。    
从API version 8 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB_REQUEST_TYPE_STANDARD<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>标准。 |  
| USB_REQUEST_TYPE_CLASS<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>类 |  
| USB_REQUEST_TYPE_VENDOR<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。<br>厂商。 |  
    
## USBRequestDirection<sup>(deprecated)</sup>    
请求方向。    
从API version 8 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.USB.USBManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB_REQUEST_DIR_TO_DEVICE<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>写数据，主设备往从设备。 |  
| USB_REQUEST_DIR_FROM_DEVICE<sup>(deprecated)</sup> | 0x80 | 从API version 8 开始支持，从API version 9 开始废弃。<br>读数据，从设备往主设备。 |  
