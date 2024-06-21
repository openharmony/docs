# @ohos.usb (USB管理)(已停止维护)

本模块主要提供管理USB设备的相关功能，包括查询USB设备列表、批量数据传输、控制命令传输、权限控制等。

>  **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 从API version 9开始，该接口不再维护，推荐使用新接口[@ohos.usbManager](js-apis-usbManager.md)。

## 导入模块

```js
import usb from "@ohos.usb";
```

## usb.getDevices

getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;

获取USB设备列表。

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                                                   | 说明      |
| ---------------------------------------------------- | ------- |
| Array&lt;Readonly&lt;[USBDevice](#usbdevice)&gt;&gt; | 设备信息列表。 |

**示例：**

```js
let devicesList = usb.getDevices();
console.log(`devicesList = ${devicesList}`);
//devicesList  返回的数据结构
//此处提供一个简单的示例，如下
/*[
  {
    name: "1-1",
    serial: "",
    manufacturerName: "",
    productName: "",
    version: "",
    vendorId: 7531,
    productId: 2,
    clazz: 9,
    subClass: 0,
    protocol: 1,
    devAddress: 1,
    busNum: 1,
    configs: [
      {
        id: 1,
        attributes: 224,
        isRemoteWakeup: true,
        isSelfPowered: true,
        maxPower: 0,
        name: "1-1",
        interfaces: [
          {
            id: 0,
            protocol: 0,
            clazz: 9,
            subClass: 0,
            alternateSetting: 0,
            name: "1-1",
            endpoints: [
              {
                address: 129,
                attributes: 3,
                interval: 12,
                maxPacketSize: 4,
                direction: 128,
                number: 1,
                type: 3,
                interfaceId: 0,
              },
            ],
          },
        ],
      },
    ],
  },
]*/
```

## usb.connectDevice

connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt;

打开USB设备。

需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及device，再调用[usb.requestRight](#usbrequestright)获取设备请求权限。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| device | [USBDevice](#usbdevice) | 是 | USB设备信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Readonly&lt;[USBDevicePipe](#usbdevicepipe)&gt; | 指定的传输通道对象。 |

**示例：**

```js
let devicepipe= usb.connectDevice(device);
console.log(`devicepipe = ${devicepipe}`);
```

## usb.hasRight

hasRight(deviceName: string): boolean

判断是否有权访问该设备。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceName | string | 是 | 设备名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | true表示有访问设备的权限，false表示没有访问设备的权限。 |

**示例：**

```js
let devicesName= "1-1";
let bool = usb.hasRight(devicesName);
console.log(`hasRight = ${bool}`);
```

## usb.requestRight

requestRight(deviceName: string): Promise&lt;boolean&gt;

请求软件包的临时权限以访问设备。使用Promise异步回调。系统应用默认拥有访问设备权限，无需调用此接口申请。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceName | string | 是 | 设备名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象，返回临时权限的申请结果。返回true表示临时权限申请成功；返回false则表示临时权限申请失败。 |

**示例：**

```js
let devicesName= "1-1";
usb.requestRight(devicesName).then((ret) => {
  console.log(`requestRight = ${ret}`);
});
```

## usb.claimInterface

claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number

注册通信接口。

需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及interfaces；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定总线号和设备地址。 |
| iface | [USBInterface](#usbinterface) | 是 | 用于确定需要获取接口的索引。 |
| force | boolean | 否 | 可选参数，是否强制获取。默认值为false&nbsp;，表示不强制获取。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 注册通信接口成功返回0；注册通信接口失败返回其他错误码。 |

**示例：**

```js
let ret = usb.claimInterface(devicepipe, interfaces);
console.log(`claimInterface = ${ret}`);
```

## usb.releaseInterface

releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number

释放注册过的通信接口。

需要调用[usb.claimInterface](#usbclaiminterface)先获取接口，才能使用此方法释放接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定总线号和设备地址。 |
| iface | [USBInterface](#usbinterface) | 是 | 用于确定需要释放接口的索引。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 释放接口成功返回0；释放接口失败返回其他错误码。 |

**示例：**

```js
let ret = usb.releaseInterface(devicepipe, interfaces);
console.log(`releaseInterface = ${ret}`);
```

## usb.setConfiguration

setConfiguration(pipe: USBDevicePipe, config: USBConfig): number

设置设备配置。

需要调用[usb.getDevices](#usbgetdevices)获取设备信息以及config；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定总线号和设备地址。 |
| config | [USBConfig](#usbconfig) | 是 | 用于确定需要设置的配置。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 设置设备配置成功返回0；设置设备配置失败返回其他错误码。 |

**示例：**

```js
let ret = usb.setConfiguration(devicepipe, config);
console.log(`setConfiguration = ${ret}`);
```

## usb.setInterface

setInterface(pipe: USBDevicePipe, iface: USBInterface): number

设置设备接口。

需要调用[usb.getDevices](#usbgetdevices)获取设备列表以及interfaces；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数；调用[usb.claimInterface](#usbclaiminterface)注册通信接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名   | 类型                              | 必填  | 说明            |
| ----- | ------------------------------- | --- | ------------- |
| pipe  | [USBDevicePipe](#usbdevicepipe) | 是   | 用于确定总线号和设备地址。 |
| iface | [USBInterface](#usbinterface)   | 是   | 用于确定需要设置的接口。  |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 设置设备接口成功返回0；设置设备接口失败返回其他错误码。 |

**示例：**

```js
let ret = usb.setInterface(devicepipe, interfaces);
console.log(`setInterface = ${ret}`);
```

## usb.getRawDescriptor

getRawDescriptor(pipe: USBDevicePipe): Uint8Array

获取原始的USB描述符。

需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定总线号和设备地址。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回获取的原始数据；失败返回undefined。 |

**示例：**

```js
let ret = usb.getRawDescriptor(devicepipe);
```

## usb.getFileDescriptor

getFileDescriptor(pipe: USBDevicePipe): number

获取文件描述符。

需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定总线号和设备地址。 |

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 返回设备对应的文件描述符；失败返回-1。 |

**示例：**

```js
let ret = usb.getFileDescriptor(devicepipe);
```

## usb.controlTransfer

controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout ?: number): Promise&lt;number&gt;

控制传输。

需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)接口得到devicepipe作为参数。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定设备。 |
| controlparam | [USBControlParams](#usbcontrolparams) | 是 | 控制传输参数。 |
| timeout | number | 否 | 超时时间（单位：ms），可选参数，默认为0不超时。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，获取传输或接收到的数据块大小。失败返回-1。 |

**示例：**

```js
let param = {
  request: 0,
  reqType: 0,
  target:0,
  value: 0,
  index: 0,
  data: null
};
usb.controlTransfer(devicepipe, param).then((ret) => {
 console.log(`controlTransfer = ${ret}`);
})
```

## usb.bulkTransfer

bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt;

批量传输。

需要调用[usb.getDevices](#usbgetdevices)获取设备信息列表以及endpoint；再调用[usb.requestRight](#usbrequestright)获取设备请求权限；然后调用[usb.connectDevice](#usbconnectdevice)接口得到返回数据devicepipe之后，再次获取接口[usb.claimInterface](#usbclaiminterface)；再调用usb.bulkTransfer接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定设备。 |
| endpoint | [USBEndpoint](#usbendpoint) | 是 | 用于确定传输的端口。 |
| buffer | Uint8Array | 是 | 用于写入或读取的缓冲区。 |
| timeout | number | 否 | 超时时间（单位：ms），可选参数，默认为0不超时。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，获取传输或接收到的数据块大小。失败返回-1。 |

**示例：**

```js
//usb.getDevices 接口返回数据集合，取其中一个设备对象，并获取权限 。
//把获取到的设备对象作为参数传入usb.connectDevice;当usb.connectDevice接口成功返回之后；
//才可以调用第三个接口usb.claimInterface.当usb.claimInterface 调用成功以后,再调用该接口。
usb.bulkTransfer(devicepipe, endpoint, buffer).then((ret) => {
 console.log(`bulkTransfer = ${ret}`);
});
```

## usb.closePipe

closePipe(pipe: USBDevicePipe): number

关闭设备消息控制通道。

需要调用[usb.getDevices](#usbgetdevices)获取设备列表；调用[usb.requestRight](#usbrequestright)获取设备请求权限；调用[usb.connectDevice](#usbconnectdevice)得到devicepipe作为参数。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | 是 | 用于确定USB设备消息控制通道。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 关闭设备消息控制通道成功返回0；关闭设备消息控制通道失败返回其他错误码。 |

**示例：**

```js
let ret = usb.closePipe(devicepipe);
console.log(`closePipe = ${ret}`);
```

## USBEndpoint

通过USB发送和接收数据的端口。通过[USBInterface](#usbinterface)获取。

**系统能力：** SystemCapability.USB.USBManager

| 名称            | 类型                                        |   必填      | 说明            |
| ------------- | ------------------------------------------- | ------------- |------------ |
| address       | number                                      | 是   |端点地址。         |
| attributes    | number                                      | 是   |端点属性。         |
| interval      | number                                      | 是   |端点间隔。         |
| maxPacketSize | number                                      | 是   |端点最大数据包大小。    |
| direction     | [USBRequestDirection](#usbrequestdirection) | 是   |端点的方向。        |
| number        | number                                      | 是   |端点号。          |
| type          | number                                      | 是   |端点类型。         |
| interfaceId   | number                                      | 是   |端点所属的接口的唯一标识。 |

## USBInterface

一个[USBConfig](#usbconfig)中可以含有多个USBInterface，每个USBInterface提供一个功能。

**系统能力：** SystemCapability.USB.USBManager

| 名称               | 类型                                     |  必填      |说明                    |
| ---------------- | ---------------------------------------- | ------------- |--------------------- |
| id               | number                                   | 是   |接口的唯一标识。              |
| protocol         | number                                   | 是   |接口的协议。                |
| clazz            | number                                   | 是   |设备类型。                 |
| subClass         | number                                   | 是   |设备子类。                 |
| alternateSetting | number                                   | 是   |在同一个接口中的多个描述符中进行切换设置。 |
| name             | string                                   | 是   |接口名称。                 |
| endpoints        | Array&lt;[USBEndpoint](#usbendpoint)&gt; | 是   |当前接口所包含的端点。           |

## USBConfig

USB配置，一个[USBDevice](#usbdevice)中可以含有多个配置。

**系统能力：** SystemCapability.USB.USBManager

| 名称             | 类型                                             | 必填   |说明              |
| -------------- | ------------------------------------------------ | --------------- |----------- |
| id             | number                                           | 是   |配置的唯一标识。        |
| attributes     | number                                           | 是   |配置的属性。          |
| maxPower       | number                                           | 是   |最大功耗，以毫安为单位。    |
| name           | string                                           | 是   |配置的名称，可以为空。     |
| isRemoteWakeup | boolean                                          | 是   |检查当前配置是否支持远程唤醒。 |
| isSelfPowered  | boolean                                          | 是   |检查当前配置是否支持独立电源。 |
| interfaces     | Array&nbsp;&lt;[USBInterface](#usbinterface)&gt; | 是   |配置支持的接口属性。      |

## USBDevice

USB设备信息。

**系统能力：** SystemCapability.USB.USBManager

| 名称               | 类型                                 | 必填   |说明         |
| ---------------- | ------------------------------------ | ---------- |---------- |
| busNum           | number                               | 是   |总线地址。      |
| devAddress       | number                               | 是   |设备地址。      |
| serial           | string                               | 是   |序列号。       |
| name             | string                               | 是   |设备名字。      |
| manufacturerName | string                               | 是   |产商信息。      |
| productName      | string                               | 是   |产品信息。      |
| version          | string                               | 是   |版本。        |
| vendorId         | number                               | 是   |厂商ID。      |
| productId        | number                               | 是   |产品ID。      |
| clazz            | number                               | 是   |设备类。       |
| subClass         | number                               | 是   |设备子类。      |
| protocol         | number                               | 是   |设备协议码。     |
| configs          | Array&lt;[USBConfig](#usbconfig)&gt; | 是   |设备配置描述符信息。 |

## USBDevicePipe

USB设备消息传输通道，用于确定设备。

**系统能力：** SystemCapability.USB.USBManager

| 名称       | 类型   | 必填  |说明    |
| ---------- | ------ | ----- |----- |
| busNum     | number | 是   |总线地址。 |
| devAddress | number | 是   |设备地址。 |

## USBControlParams

控制传输参数。

**系统能力：** SystemCapability.USB.USBManager

| 名称      | 类型                                            | 必填 |说明               |
| ------- | ----------------------------------------------- | ---------------- |---------------- |
| request | number                                          | 是   |请求类型。            |
| target  | [USBRequestTargetType](#usbrequesttargettype)   | 是   |请求目标类型。          |
| reqType | [USBControlRequestType](#usbcontrolrequesttype) | 是   |请求控制类型。          |
| value   | number                                          | 是   |请求参数。            |
| index   | number                                          | 是   |请求参数value对应的索引值。 |
| data    | Uint8Array                                      | 是   |用于写入或读取的缓冲区。     |


## USBRequestTargetType

请求目标类型。

**系统能力：** SystemCapability.USB.USBManager

| 名称                         | 值   | 说明   |
| ---------------------------- | ---- | ------ |
| USB_REQUEST_TARGET_DEVICE    | 0    | 设备。 |
| USB_REQUEST_TARGET_INTERFACE | 1    | 接口。 |
| USB_REQUEST_TARGET_ENDPOINT  | 2    | 端点。 |
| USB_REQUEST_TARGET_OTHER     | 3    | 其他。 |

## USBControlRequestType

控制请求类型。

**系统能力：** SystemCapability.USB.USBManager

| 名称                      | 值   | 说明   |
| ------------------------- | ---- | ------ |
| USB_REQUEST_TYPE_STANDARD | 0    | 标准。 |
| USB_REQUEST_TYPE_CLASS    | 1    | 类。   |
| USB_REQUEST_TYPE_VENDOR   | 2    | 厂商。 |

## USBRequestDirection

请求方向。

**系统能力：** SystemCapability.USB.USBManager

| 名称                        | 值   | 说明                     |
| --------------------------- | ---- | ------------------------ |
| USB_REQUEST_DIR_TO_DEVICE   | 0    | 写数据，主设备往从设备。 |
| USB_REQUEST_DIR_FROM_DEVICE | 0x80 | 读数据，从设备往主设备。 |

