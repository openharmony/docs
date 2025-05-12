# @ohos.usbManager (USB管理)(系统接口)

本模块主要提供管理USB设备的相关功能，包括主设备上查询USB设备列表、批量数据传输、控制命令传输、权限控制等；从设备上端口管理、功能切换及查询等。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.usbManager (USB管理)](js-apis-usbManager.md)。

## 导入模块

```ts
import { usbManager } from '@kit.BasicServicesKit';
```

## addRight <sup>(deprecated)</sup>

addRight(bundleName: string, deviceName: string): boolean

添加软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。

usbManager.requestRight (#usbrequestright)会触发弹框请求用户授权；addRight不会触发弹框，而是直接添加软件包访问设备的权限。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [addDeviceAccessRight](#adddeviceaccessright12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | ------------ |
| deviceName | string | 是   | 设备名称。   |
| bundleName | string | 是   | 软件包名称。 |

**返回值：**

| 类型    | 说明                                                                      |
| ------- | ------------------------------------------------------------------------- |
| boolean | 返回权限添加结果。返回true表示权限添加成功；返回false则表示权限添加失败。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**示例：**

```ts
let devicesName: string = "1-1";
let bundleName: string = "com.example.hello";
if (usbManager.addRight(bundleName, devicesName)) {
  console.log(`Succeed in adding right`);
}
```

## usbFunctionsFromString<sup>(deprecated)</sup>

usbFunctionsFromString(funcs: string): number

在设备模式下，将字符串形式的USB功能列表转化为数字掩码。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [getFunctionsFromString](#getfunctionsfromstring12) 替代。

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

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**示例：**

```ts
let funcs: string = "acm";
let ret: number = usbManager.usbFunctionsFromString(funcs);
```

## usbFunctionsToString<sup>(deprecated)</sup>

usbFunctionsToString(funcs: FunctionType): string

在设备模式下，将数字掩码形式的USB功能列表转化为字符串。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [getStringFromFunctions](#getstringfromfunctions12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | USB功能数字掩码。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转化后的字符串形式的功能列表。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**示例：**

```ts
let funcs: number = usbManager.FunctionType.ACM | usb.FunctionType.ECM;
let ret: string = usbManager.usbFunctionsToString(funcs);
```

## setCurrentFunctions<sup>(deprecated)</sup>

setCurrentFunctions(funcs: FunctionType): Promise\<void\>

在设备模式下，设置当前的USB功能列表。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [setDeviceFunctions](#setdevicefunctions12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | USB功能数字掩码。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400002 | Permission denied. The HDC is disabled by the system.                                                   |

**示例：**

```ts
import {BusinessError} from '@kit.BasicServicesKit';
let funcs: number = usbManager.FunctionType.HDC;
usbManager.setCurrentFunctions(funcs).then(() => {
    console.info('usb setCurrentFunctions successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## getCurrentFunctions<sup>(deprecated)</sup>

getCurrentFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。开发者模式关闭时，如果没有设备接入，接口可能返回`undefined`，注意需要对接口返回值做判空处理。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [getDeviceFunctions](#getdevicefunctions12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                          | 说明                              |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | 当前的USB功能列表的数字组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. No parameters are required.                                    |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**示例：**

```ts
let ret: number = usbManager.getCurrentFunctions();
```

## getPorts<sup>(deprecated)</sup>

getPorts(): Array\<USBPort\>

获取所有物理USB端口描述信息。开发者模式关闭时，如果没有设备接入，接口可能返回`undefined`，注意需要对接口返回值做判空处理。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [getPortList](#getportlist12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                       | 说明                  |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | USB端口描述信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. No parameters are required.                                    |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**示例：**

```ts
let ret: Array<usbManager.USBPort> = usbManager.getPorts();
```

## getSupportedModes(deprecated)

getSupportedModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [getPortSupportModes](#getportsupportmodes12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | 端口号。 |

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | 支持的模式列表的组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**示例：**

```ts
let ret: number = usbManager.getSupportedModes(0);
```

## setPortRoles<sup>(deprecated)</sup>

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

设置指定的端口支持的角色模式，包含充电角色、数据传输角色。

**说明：**

> 从 API version 9开始支持，从API version 12开始废弃。建议使用 [setPortRoleTypes](#setportroletypes12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型                            | 必填 | 说明             |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | 是   | 端口号。         |
| powerRole | [PowerRoleType](#powerroletype) | 是   | 充电的角色。     |
| dataRole  | [DataRoleType](#dataroletype)   | 是   | 数据传输的角色。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
import {BusinessError} from '@kit.BasicServicesKit';
let portId: number = 1;
usbManager.setPortRoles(portId, usbManager.PowerRoleType.SOURCE, ususbManagerb.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);
});
```

## addDeviceAccessRight<sup>12+</sup>

addDeviceAccessRight(tokenId: string, deviceName: string): boolean

添加软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。

usbManager.requestRight (#usbrequestright)会触发弹框请求用户授权；addDeviceAccessRight不会触发弹框，而是直接添加软件包访问设备的权限。

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

**返回值：**

| 类型    | 说明                                                                      |
| ------- | ------------------------------------------------------------------------- |
| boolean | 返回权限添加结果。返回true表示权限添加成功；返回false则表示权限添加失败。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let devicesName: string = "1-1";
let tokenId: string = "";

  try {
    let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
    bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
      console.info('testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(bundleInfo));
      let token = bundleInfo.appInfo.accessTokenId;
      tokenId = token.toString();
      if (usbManager.addDeviceAccessRight(tokenId, devicesName)) {
        console.log(`Succeed in adding right`);
      }
    }).catch((err : BusinessError) => {
      console.error('testTag getBundleInfoForSelf failed' );
    });
  } catch (err) {
    console.error('testTag failed');
  }
```

## getFunctionsFromString<sup>12+</sup>

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

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 转化后的数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. |
| 801      | Capability not supported.                                    |

**示例：**

```ts
let funcs: string = "acm";
let ret: number = usbManager.getFunctionsFromString(funcs);
```

## getStringFromFunctions<sup>12+</sup>

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

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转化后的字符串形式的功能列表。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |

**示例：**

```ts
let funcs: number = usbManager.FunctionType.ACM | usbManager.FunctionType.ECM;
let ret: string = usbManager.getStringFromFunctions(funcs);
```

## setDeviceFunctions<sup>12+</sup>

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

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |
| 14400002 | Permission denied. The HDC is disabled by the system.                                                   |
| 14400006 | Unsupported operation. The function is not supported.                                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let funcs: number = usbManager.FunctionType.HDC;
usbManager.setDeviceFunctions(funcs).then(() => {
    console.info('usb setDeviceFunctions successfully.');
}).catch((err : BusinessError) => {
    console.error('usb setDeviceFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## getDeviceFunctions<sup>12+</sup>

getDeviceFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。开发者模式关闭时，如果没有设备接入，接口可能返回`undefined`，注意需要对接口返回值做判空处理。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                          | 说明                              |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | 当前的USB功能列表的数字组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. No parameters are required.                                    |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. |
| 801      | Capability not supported.                                    |

**示例：**

```ts
let ret: number = usbManager.getDeviceFunctions();
```

## getPortList<sup>12+</sup>

getPortList(): Array\<USBPort\>

获取所有物理USB端口描述信息。开发者模式关闭时，如果没有设备接入，接口可能返回`undefined`，注意需要对接口返回值做判空处理。

**说明：**

> 从 API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**返回值：**

| 类型                       | 说明                  |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | USB端口描述信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported.                                    |

**示例：**

```ts
let ret: Array<usbManager.USBPort> = usbManager.getPortList();
```

## getPortSupportModes<sup>12+</sup>

getPortSupportModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | 端口号。 |

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | 支持的模式列表的组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |
| 14400003 | Unsupported operation. The current device does not support port role switching.                         |

**示例：**

```ts
let ret: number = usbManager.getPortSupportModes(0);
```

## setPortRoleTypes<sup>12+</sup>

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

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |
| 14400003 | Unsupported operation. The current device does not support port role switching.                         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let portId: number = 1;
usbManager.setPortRoleTypes(portId, usbManager.PowerRoleType.SOURCE, usbManager.DataRoleType.HOST).then(() => {
  console.info('usb setPortRoleTypes successfully.');
}).catch((err : BusinessError) => {
  console.error('usb setPortRoleTypes failed: ' + err.code + ' message: ' + err.message);
});
```

## addAccessoryRight<sup>14+<sup>

addAccessoryRight(tokenId: number, accessory: USBAccessory): void

为应用程序添加访问USB配件权限。

usbManager.requestAccessoryRight会触发弹窗请求用户授权；addAccessoryRight不会触发弹窗，而是直接添加应用程序访问设备的权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型         | 必填 | 说明                     |
| --------- | ------------ | ---- | ------------------------ |
| tokenId   | number       | 是   | 应用程序tokenId。 |
| accessory | USBAccessory | 是   | USB配件。                |

**错误码：**

以下错误码的详细介绍请参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | The permission check failed.                                 |
| 202      | Permission denied. Normal application do not have permission to use system api. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported.                                    |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |
| 14400005 | Database operation exception.                                |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { bundleManager } from '@kit.AbilityKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flags = bundleManager.BundleFlah.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY
  let bundleInfo = await bundleManager.getBundleInfoForSelf(flags)
  let tokenId: number = bundleInfo.appInfo.accessTokenId
  usbManager.addAccessoryRight(tokenId, accList[0])
  hilog.info(0, 'testTag ui', `addAccessoryRight success`)
} catch (error) {
  hilog.info(0, 'testTag ui', `addAccessoryRight error ${error.code}, message is ${error.message}`)
}
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
| MTP          | 8   | 媒体传输。 |
| PTP          | 16  | 图片传输。 |
| RNDIS        | 32  | 网络共享（暂不支持）。 |
| MIDI         | 64  | midi功能（暂不支持）。 |
| AUDIO_SOURCE | 128 | 音频功能（暂不支持）。 |
| NCM          | 256 | ncm传输（暂不支持）。  |

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
| SOURCE | 1  | 对外提供电源。 |
| SINK   | 2  | 需要外部供电。 |

## DataRoleType

数据角色类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称   | 值 | 说明         |
| ------ | -- | ------------ |
| NONE   | 0  | 无。         |
| HOST   | 1  | 主设备角色。 |
| DEVICE | 2  | 从设备角色。 |

