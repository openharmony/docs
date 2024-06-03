# @ohos.usbManager (USB管理)(系统接口)

本模块主要提供管理USB设备的相关功能，包括主设备上查询USB设备列表、批量数据传输、控制命令传输、权限控制等；从设备上端口管理、功能切换及查询等。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.usbManager (USB管理)](js-apis-usbManager.md)。

## 导入模块

```ts
import usb from "@ohos.usbManager";
```

## usb.addRight (deprecated)

addRight(bundleName: string, deviceName: string): boolean

添加软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。

usb.requestRight (#usbrequestright)会触发弹框请求用户授权；addRight不会触发弹框，而是直接添加软件包访问设备的权限。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 addDeviceAccessRight 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | ------------ |
| deviceName | string | 是   | 设备名称。   |
| bundleName | string | 是   | 软件包名称。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型    | 说明                                                                      |
| ------- | ------------------------------------------------------------------------- |
| boolean | 返回权限添加结果。返回true表示权限添加成功；返回false则表示权限添加失败。 |

**示例：**

```ts
let devicesName: string = "1-1";
let bundleName: string = "com.example.hello";
if (usb.addRight(bundleName, devicesName)) {
  console.log(`Succeed in adding right`);
}
```

## usb.usbFunctionsFromString(deprecated)

usbFunctionsFromString(funcs: string): number

在设备模式下，将字符串形式的USB功能列表转化为数字掩码。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 getFunctionsFromString 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | 是   | 字符串形式的功能列表。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 转化后的数字掩码。 |

**示例：**

```ts
let funcs: string = "acm";
let ret: number = usb.usbFunctionsFromString(funcs);
```

## usb.usbFunctionsToString(deprecated)

usbFunctionsToString(funcs: FunctionType): string

在设备模式下，将数字掩码形式的USB功能列表转化为字符串。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 getStringFromFunctions 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | USB功能数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转化后的字符串形式的功能列表。 |

**示例：**

```ts
let funcs: number = usb.FunctionType.ACM | usb.FunctionType.ECM;
let ret: string = usb.usbFunctionsToString(funcs);
```

## usb.setCurrentFunctions(deprecated)

setCurrentFunctions(funcs: FunctionType): Promise\<void\>

在设备模式下，设置当前的USB功能列表。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 setDeviceFunctions 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | USB功能数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 14400002 | Permission denied. The HDC is disabled by the system.         |

**返回值：**

| 类型     | 说明          |
| -------- | ------------- |
| Promise\<**void**\> | Promise对象。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
let funcs: number = usb.FunctionType.HDC;
usb.setCurrentFunctions(funcs).then(() => {
    console.info('usb setCurrentFunctions successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## usb.getCurrentFunctions(deprecated)

getCurrentFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 getDeviceFunctions 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. No parameters are required.                 |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型                          | 说明                              |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | 当前的USB功能列表的数字组合掩码。 |

**示例：**

```ts
let ret: number = usb.getCurrentFunctions();
```

## usb.getPorts(deprecated)

getPorts(): Array\<USBPort\>

获取所有物理USB端口描述信息。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 getPortList 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. No parameters are required.                 |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型                       | 说明                  |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | USB端口描述信息列表。 |

**示例：**

```ts
let ret: Array<usb.USBPort> = usb.getPorts();
```

## usb.getSupportedModes(deprecated)

getSupportedModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 getPortSupportModes 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | 端口号。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | 支持的模式列表的组合掩码。 |

**示例：**

```ts
let ret: number = usb.getSupportedModes(0);
```

## usb.setPortRoles(deprecated)

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

设置指定的端口支持的角色模式，包含充电角色、数据传输角色。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 setPortRoleTypes 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型                            | 必填 | 说明             |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | 是   | 端口号。         |
| powerRole | [PowerRoleType](#powerroletype) | 是   | 充电的角色。     |
| dataRole  | [DataRoleType](#dataroletype)   | 是   | 数据传输的角色。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |

**返回值：**

| 类型     | 说明          |
| -------- | ------------- |
| Promise\<**void**\> | Promise对象。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
let portId: number = 1;
usb.setPortRoles(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);
});
```

## usb.addDeviceAccessRight

addDeviceAccessRight(tokenId: string, deviceName: string): boolean

添加软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。

usb.requestRight (#usbrequestright)会触发弹框请求用户授权；addDeviceAccessRight不会触发弹框，而是直接添加软件包访问设备的权限。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名     | 类型   | 必填 | 说明            |
| ---------- | ------ | ---- | --------------- |
| deviceName | string | 是   | 设备名称。      |
| tokenId    | string | 是   | 软件包tokenId。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型    | 说明                                                                      |
| ------- | ------------------------------------------------------------------------- |
| boolean | 返回权限添加结果。返回true表示权限添加成功；返回false则表示权限添加失败。 |

**示例：**

```ts
 import bundleManager from '@ohos.bundle.bundleManager';
 import { BusinessError } from '@ohos.base';
 let devicesName: string = "1-1";
 let tokenId: string = "";

  try {
    let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
    bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
      console.info('testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(bundleInfo));
      let token = bundleInfo.appInfo.accessTokenId;
      tokenId = token.toString();
      if (usb.addDeviceAccessRight(tokenId, devicesName)) {
        console.log(`Succeed in adding right`);
      }
    }).catch((err : BusinessError) => {
      console.error('testTag getBundleInfoForSelf failed' );
    });
  } catch (err) {
    console.error('testTag failed');
  }
```

## usb.getFunctionsFromString

getFunctionsFromString(funcs: string): number

在设备模式下，将字符串形式的USB功能列表转化为数字掩码。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | 是   | 字符串形式的功能列表。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. No parameters are required.                 |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 转化后的数字掩码。 |

**示例：**

```ts
let funcs: string = "acm";
let ret: number = usb.getFunctionsFromString(funcs);
```

## usb.getStringFromFunctions

getStringFromFunctions(funcs: FunctionType): string

在设备模式下，将数字掩码形式的USB功能列表转化为字符串。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | USB功能数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转化后的字符串形式的功能列表。 |

**示例：**

```ts
let funcs: number = usb.FunctionType.ACM | usb.FunctionType.ECM;
let ret: string = usb.getStringFromFunctions(funcs);
```

## usb.setDeviceFunctions

setDeviceFunctions(funcs: FunctionType): Promise\<void\>

在设备模式下，设置当前的USB功能列表。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | USB功能数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型     | 说明          |
| -------- | ------------- |
| Promise\<**void**\> | Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let funcs: number = usb.FunctionType.HDC;
usb.setDeviceFunctions(funcs).then(() => {
    console.info('usb setDeviceFunctions successfully.');
}).catch(((err : BusinessError)) => {
    console.error('usb setDeviceFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## usb.getDeviceFunctions

getDeviceFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. No parameters are required.                 |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型                          | 说明                              |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | 当前的USB功能列表的数字组合掩码。 |

**示例：**

```ts
let ret: number = usb.getDeviceFunctions();
```

## usb.getPortList

getPortList(): Array\<USBPort\>

获取所有物理USB端口描述信息。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型                       | 说明                  |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | USB端口描述信息列表。 |

**示例：**

```ts
let ret: Array<usb.USBPort> = usb.getPortList();
```

## usb.getPortSupportModes

getPortSupportModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | 端口号。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | 支持的模式列表的组合掩码。 |

**示例：**

```ts
let ret: number = usb.getSupportedModes(0);
```

## usb.setPortRoleTypes

setPortRoleTypes(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

设置指定的端口支持的角色模式，包含充电角色、数据传输角色。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型                            | 必填 | 说明             |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | 是   | 端口号。         |
| powerRole | [PowerRoleType](#powerroletype) | 是   | 充电的角色。     |
| dataRole  | [DataRoleType](#dataroletype)   | 是   | 数据传输的角色。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**返回值：**

| 类型     | 说明          |
| -------- | ------------- |
| Promise\<**void**\> | Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let portId: number = 1;
usb.setPortRoleTypes(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {
  console.info('usb setPortRoleTypes successfully.');
}).catch(((err : BusinessError)) => {
  console.error('usb setPortRoleTypes failed: ' + err.code + ' message: ' + err.message);
});
```

## USBPort

USB设备端口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称           | 类型                            | 必填 | 说明                                |
| -------------- | ------------------------------- | ---- | ----------------------------------- |
| id             | number                          | 是   | USB端口唯一标识。                   |
| supportedModes | [PortModeType](#portmodetype)   | 是   | USB端口所支持的模式的数字组合掩码。 |
| status         | [USBPortStatus](#usbportstatus) | 是   | USB端口角色。                       |

## USBPortStatus

USB设备端口角色信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称             | 类型   | 必填 | 说明                   |
| ---------------- | ------ | ---- | ---------------------- |
| currentMode      | number | 是   | 当前的USB模式。        |
| currentPowerRole | number | 是   | 当前设备充电模式。     |
| currentDataRole  | number | 是   | 当前设备数据传输模式。 |

## FunctionType

USB设备侧功能。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称         | 值  | 说明       |
| ------------ | --- | ---------- |
| NONE         | 0   | 没有功能。 |
| ACM          | 1   | acm功能。  |
| ECM          | 2   | ecm功能。  |
| HDC          | 4   | hdc功能。  |
| MTP          | 8   | 暂不支持。 |
| PTP          | 16  | 暂不支持。 |
| RNDIS        | 32  | 暂不支持。 |
| MIDI         | 64  | 暂不支持。 |
| AUDIO_SOURCE | 128 | 暂不支持。 |
| NCM          | 256 | 暂不支持。 |

## PortModeType

USB端口模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称      | 值 | 说明                                                 |
| --------- | -- | ---------------------------------------------------- |
| NONE      | 0  | 无。                                                 |
| UFP       | 1  | 数据上行，需要外部供电。                             |
| DFP       | 2  | 数据下行，对外提供电源。                             |
| DRP       | 3  | 既可以做DFP(Host)，也可以做UFP(Device)，当前不支持。 |
| NUM_MODES | 4  | 当前不支持。                                         |

## PowerRoleType

电源角色类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称   | 值 | 说明       |
| ------ | -- | ---------- |
| NONE   | 0  | 无。       |
| SOURCE | 1  | 外部供电。 |
| SINK   | 2  | 内部供电。 |

## DataRoleType

数据角色类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称   | 值 | 说明         |
| ------ | -- | ------------ |
| NONE   | 0  | 无。         |
| HOST   | 1  | 主设备角色。 |
| DEVICE | 2  | 从设备角色。 |

