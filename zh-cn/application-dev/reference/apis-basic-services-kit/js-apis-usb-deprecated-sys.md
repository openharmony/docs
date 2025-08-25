# @ohos.usb (USB管理)(系统接口)

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

本模块主要提供管理USB设备的相关功能，包括查询USB设备列表、批量数据传输、控制命令传输、权限控制等。

>  **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 从API version 9开始，该接口不再维护，推荐使用新接口[`@ohos.usbManager`](js-apis-usbManager.md)。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.usb (USB管理)(已停止维护)](js-apis-usb-deprecated.md)。

## 导入模块

```js
import usb from "@ohos.usb";
import { BusinessError } from '@ohos.base';
```

## usb.usbFunctionsFromString<sup>9+</sup>

usbFunctionsFromString(funcs: string): number

在设备模式下，将字符串形式的USB功能列表转化为数字掩码。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | 是   | 字符串形式的功能列表。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 转化后的数字掩码。 |

**示例：**

```js
let funcs = "acm";
let ret = usb.usbFunctionsFromString(funcs);
```

## usb.usbFunctionsToString<sup>9+</sup>

usbFunctionsToString(funcs: FunctionType): string

在设备模式下，将数字掩码形式的USB功能列表转化为字符串。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                           | 必填 | 说明              |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype9) | 是   | USB功能数字掩码。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转化后的字符串形式的功能列表。 |

**示例：**

```js
let funcs = usb.FunctionType.ACM | usb.FunctionType.ECM;
let ret = usb.usbFunctionsToString(funcs);
```

## usb.setCurrentFunctions<sup>9+</sup>

setCurrentFunctions(funcs: FunctionType): Promise\<boolean\>

在设备模式下，设置当前的USB功能列表。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                           | 必填 | 说明              |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype9) | 是   | USB功能数字掩码。 |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise对象，返回设置成功与否的结果。true表示设置成功，false表示设置失败。 |

**示例：**

```js
let funcs : number = usb.FunctionType.HDC;
usb.setCurrentFunctions(funcs).then(() => {
    console.info('usb setCurrentFunctions successfully.');
}).catch((err : BusinessError) => {
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## usb.getCurrentFunctions<sup>9+</sup>

getCurrentFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                           | 说明                              |
| ------------------------------ | --------------------------------- |
| [FunctionType](#functiontype9) | 当前的USB功能列表的数字组合掩码。 |

**示例：**

```js
let ret = usb.getCurrentFunctions();
```

## usb.getPorts<sup>9+</sup>

getPorts(): Array\<USBPort\>

获取所有物理USB端口描述信息。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                          | 说明                  |
| ----------------------------- | --------------------- |
| [Array\<USBPort\>](#usbport9) | USB端口描述信息列表。 |

**示例：**

```js
let ret = usb.getPorts();
```

## usb.getSupportedModes<sup>9+</sup>

getSupportedModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | 端口号。 |

**返回值：**

| 类型                           | 说明                       |
| ------------------------------ | -------------------------- |
| [PortModeType](#portmodetype9) | 支持的模式列表的组合掩码。 |

**示例：**

```js
let ret = usb.getSupportedModes(0);
```

## usb.setPortRoles<sup>9+</sup>

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean\>

设置指定的端口支持的角色模式，包含充电角色、数据传输角色。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型                             | 必填 | 说明             |
| --------- | -------------------------------- | ---- | ---------------- |
| portId    | number                           | 是   | 端口号。         |
| powerRole | [PowerRoleType](#powerroletype9) | 是   | 充电的角色。     |
| dataRole  | [DataRoleType](#dataroletype9)   | 是   | 数据传输的角色。 |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise对象，返回设置成功与否的结果。true表示设置成功，false表示设置失败。 |

**示例：**

```js
let portId = 1;
usb.setPortRoles(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err : BusinessError) => {
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);
});
```

## USBPort<sup>9+</sup>

USB设备端口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称           | 类型                         | 必填 |说明                                |
| -------------- | -------------------------------- | -------------- |----------------------------------- |
| id             | number                           | 是   |USB端口唯一标识。                   |
| supportedModes | [PortModeType](#portmodetype9)   | 是   |USB端口所支持的模式的数字组合掩码。 |
| status         | [USBPortStatus](#usbportstatus9) | 是   |USB端口角色。                       |

## USBPortStatus<sup>9+</sup>

USB设备端口角色信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称             | 类型 | 必填 |说明                   |
| ---------------- | -------- | ----------- |---------------------- |
| currentMode      | number   | 是   |当前的USB模式。        |
| currentPowerRole | number   | 是   |当前设备充电模式。     |
| currentDataRole  | number   | 是   |当前设备数据传输模式。 |

## FunctionType<sup>9+</sup>

USB设备侧功能。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称         | 值   | 说明       |
| ------------ | ---- | ---------- |
| NONE         | 0    | 没有功能。 |
| ACM          | 1    | acm功能。  |
| ECM          | 2    | ecm功能。  |
| HDC          | 4    | hdc功能。  |
| MTP          | 8    | 媒体传输。 |
| PTP          | 16   | 图片传输。 |
| RNDIS        | 32   | 网络共享。 |
| MIDI         | 64   | midi功能。 |
| AUDIO_SOURCE | 128  | 音频功能。 |
| NCM          | 256  | ncm传输。  |

## PortModeType<sup>9+</sup>

USB端口模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称      | 值   | 说明                                                 |
| --------- | ---- | ---------------------------------------------------- |
| NONE      | 0    | 无。                                                 |
| UFP       | 1    | 数据上行，需要外部供电。                             |
| DFP       | 2    | 数据下行，对外提供电源。                             |
| DRP       | 3    | 既可以做DFP(Host)，也可以做UFP(Device)，当前不支持。 |
| NUM_MODES | 4    | 当前不支持。                                         |

## PowerRoleType<sup>9+</sup>

电源角色类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| NONE   | 0    | 无。       |
| SOURCE | 1    | 外部供电。 |
| SINK   | 2    | 内部供电。 |

## DataRoleType<sup>9+</sup>

数据角色类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称   | 值   | 说明         |
| ------ | ---- | ------------ |
| NONE   | 0    | 无。         |
| HOST   | 1    | 主设备角色。 |
| DEVICE | 2    | 从设备角色。 |

