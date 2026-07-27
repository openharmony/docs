# @ohos.usbManager (USB管理)(系统接口)

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

本模块主要提供管理USB设备的相关功能，包括主机上查询USB设备列表、批量数据传输、控制命令传输、权限控制等；设备上端口管理、功能切换及查询等。适用于需要与USB外设进行数据交互、管理USB设备权限、动态切换USB设备模式等场景。作为系统接口，本模块提供系统级权限控制机制、设备侧USB功能配置能力以及端口角色管理能力，帮助系统应用实现灵活的USB设备管理，满足不同业务场景下的USB通信需求。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.usbManager (USB管理)](js-apis-usbManager.md)。

## 导入模块

```ts
import { usbManager } from '@kit.BasicServicesKit';
```

## usbFunctionsFromString<sup>(deprecated)</sup>

usbFunctionsFromString(funcs: string): number

在设备模式下，将字符串形式的USB功能列表转换为数字掩码。适用于需要将配置文件或用户输入的字符串形式USB功能列表转换为系统内部使用的数字掩码的场景，以便后续调用setDeviceFunctions等接口设置USB功能。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [getFunctionsFromString](#getfunctionsfromstring12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | 是   | 字符串形式的功能列表，可用值包括：'none'、'acm'、'ecm'、'hdc'、'mtp'、'ptp'、'rndis'、'midi'、'audio_source'、'ncm'，可通过英文逗号分隔多个功能。传入无效字符串时抛出异常。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 转换后的功能列表对应的数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |

**示例：**

```ts
// 定义USB功能字符串
let funcs: string = 'acm';
// 将字符串转化为数字掩码
let ret: number = usbManager.usbFunctionsFromString(funcs);
```

## usbFunctionsToString<sup>(deprecated)</sup>

usbFunctionsToString(funcs: FunctionType): string

在设备模式下，将数字掩码形式的USB功能列表转换为字符串。适用于需要将当前USB功能状态以字符串形式显示或保存的场景，如在日志中记录当前功能配置、在UI界面展示当前功能等。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [getStringFromFunctions](#getstringfromfunctions12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | 功能列表对应的数字掩码，可通过位运算组合多个功能。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转换后的字符串形式的功能列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |

**示例：**

```ts
// 定义USB功能类型组合
let funcs: usbManager.FunctionType = usbManager.FunctionType.ACM | usbManager.FunctionType.ECM;
// 将数字掩码转化为字符串
let ret: string = usbManager.usbFunctionsToString(funcs);
```

## setCurrentFunctions<sup>(deprecated)</sup>

setCurrentFunctions(funcs: FunctionType): Promise\<void\>

在设备模式下，设置当前的USB功能列表。使用Promise异步回调。调用成功后，设备的USB功能将切换为指定的功能列表。适用于系统应用需要动态切换设备USB功能、配置设备工作模式的场景。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [setDeviceFunctions](#setdevicefunctions12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | 功能列表对应的数字掩码，可通过位运算组合多个功能。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。调用成功时无返回值，调用失败时抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 14400002 | Permission denied. The HDC is disabled by the system. Possible causes: The HDC (HarmonyOS Device Connector) feature is disabled in developer settings. Solution: Enable HDC in developer settings or check system configuration. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
// 设置USB功能类型为HDC
let funcs: usbManager.FunctionType = usbManager.FunctionType.HDC;
// 异步设置当前USB功能
usbManager.setCurrentFunctions(funcs).then(() => {
  console.info('usb setCurrentFunctions successfully.');
}).catch((err: BusinessError) => {
  console.error(`usb setCurrentFunctions failed. Code: ${err.code}, message: ${err.message}`);
});
```

## getCurrentFunctions<sup>(deprecated)</sup>

getCurrentFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。适用于需要检查当前USB功能状态、确认功能配置、或在功能切换前后进行状态对比的场景。开发者模式关闭时，如果没有设备接入，接口返回`undefined`，注意需要对接口返回值做判空处理。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [getDeviceFunctions](#getdevicefunctions12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**返回值：**

| 类型                          | 说明                              |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | 当前的USB功能列表的数字组合掩码。如果开发者模式关闭且没有设备接入，则返回undefined，需要对返回值做判空处理。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: No parameters are required for this interface. Solution: Remove any unnecessary parameters and call the interface without parameters. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |

**示例：**

```ts
// 获取当前USB功能的数字掩码
let ret: usbManager.FunctionType = usbManager.getCurrentFunctions();
```

## getPorts<sup>(deprecated)</sup>

getPorts(): Array\<USBPort\>

获取所有物理USB端口描述信息。适用于需要枚举USB端口、进行端口管理、设备连接诊断、或查询端口配置信息的场景。开发者模式关闭时，如果没有设备接入，接口返回`undefined`，注意需要对接口返回值做判空处理。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [getPortList](#getportlist12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**返回值：**

| 类型                       | 说明                  |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | USB端口描述信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: No parameters are required for this interface. Solution: Remove any unnecessary parameters and call the interface without parameters. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |

**示例：**

```ts
// 获取所有USB端口描述信息
let ret: Array<usbManager.USBPort> = usbManager.getPorts();
```

## getSupportedModes<sup>(deprecated)</sup>

getSupportedModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。适用于系统应用需要查询USB-C端口能力判断是否支持特定模式（如Host、Device或DRP模式）的场景。返回值为PortModeType的组合掩码，可通过位运算判断端口是否支持特定模式。PortModeType包括：NONE（0，无模式）、UFP（1，上行端口模式，dataRole为DEVICE）、DFP（2，下行端口模式，dataRole为HOST）、DRP（3，双角色模式，可在UFP和DFP间切换）、NUM_MODES（4，当前不支持）。开发者可根据返回值判断端口是否支持所需的充电角色和数据传输角色组合。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [getPortSupportModes](#getportsupportmodes12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | USB端口号，取值范围为非负整数，可通过[getPortList](#getportlist12)获取端口列表后得到。 |

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | 支持的模式列表的组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |

**示例：**

```ts
// 获取端口ID为0的端口支持的模式
let ret: usbManager.PortModeType = usbManager.getSupportedModes(0);
```

## setPortRoles<sup>(deprecated)</sup>

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

设置指定端口当前的角色模式，包含电源角色、数据传输角色。使用Promise异步回调。调用成功后端口角色将切换为指定的角色。适用于系统应用需要动态切换USB端口角色的场景。开发者模式关闭时，如果没有设备接入，操作可能会失败，调用失败时抛出异常。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用 [setPortRoleTypes](#setportroletypes12) 替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型                            | 必填 | 说明             |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | 是   | USB端口号，取值范围为非负整数，可通过[getPortList](#getportlist12)获取端口列表后得到。|
| powerRole | [PowerRoleType](#powerroletype) | 是   | 电源角色类型，可选值包括：NONE（无）、SOURCE（对外提供电源）、SINK（需要外部供电）。|
| dataRole  | [DataRoleType](#dataroletype)   | 是   | 数据传输角色类型，可选值包括：NONE（无）、HOST（主机角色）、DEVICE（设备角色）。|

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。调用成功时无返回值，调用失败时抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |

**示例：**

```ts
import {BusinessError} from '@kit.BasicServicesKit';
// 定义端口号
let portId: number = 1;
// 设置端口角色：充电角色为SOURCE，数据角色为HOST
usbManager.setPortRoles(portId, usbManager.PowerRoleType.SOURCE, usbManager.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err: BusinessError) => {
    console.error(`usb setPortRoles failed. Code: ${err.code}, message: ${err.message}`);
});
```

## addDeviceAccessRight<sup>12+</sup>

addDeviceAccessRight(tokenId: string, deviceName: string): boolean

添加应用访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。适用于系统设置应用、设备管理应用等需要为第三方应用授权访问USB设备的场景。授权立即生效并持久化存储，设备重启后仍然有效。授权范围为指定的USB设备实例，多个应用可以同时获得同一设备的访问权限。

[usbManager.requestRight](js-apis-usbManager.md#usbmanagerrequestright)会触发弹窗请求用户授权；addDeviceAccessRight不会触发弹窗，而是直接添加应用程序访问设备的权限。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名     | 类型   | 必填 | 说明            |
| ---------- | ------ | ---- | --------------- |
| tokenId    | string | 是   | 应用的唯一标识符，可通过[bundleManager.getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取。 |
| deviceName | string | 是   | 设备名称，格式为'bus-port'，例如'1-1'，可通过[getDevices](js-apis-usbManager.md#usbmanagergetdevices)接口获取设备列表后得到设备名称。|

**返回值：**

| 类型    | 说明                                                                      |
| ------- | ------------------------------------------------------------------------- |
| boolean | 返回权限添加结果。返回true表示权限添加成功；返回false则表示权限添加失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
// 设备名称示例值，实际使用时请通过usbManager.getDevices()接口获取设备列表后，从设备对象中获取deviceName字段
let deviceName: string = '1-1';
// 定义tokenId变量
let tokenId: string = '';
  // 为指定应用添加USB设备访问权限
try {
  // 获取bundle信息标志
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
  // 异步获取当前应用的bundle信息
  bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
    console.info('testTag', 'getBundleInfoForSelf successfully. Data:', JSON.stringify(bundleInfo));
    // 获取应用的accessTokenId
    let token = bundleInfo.appInfo.accessTokenId;
    tokenId = token.toString();
    // 添加设备访问权限
    if (usbManager.addDeviceAccessRight(tokenId, devicesName)) {
      console.info(`Succeed in adding right`);
    }
  }).catch((err : BusinessError) => {
    console.error(`testTag getBundleInfoForSelf failed. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err : BusinessError) {
  console.error(`testTag failed. Code: ${err.code}, message: ${err.message}`);
}
```

## getFunctionsFromString<sup>12+</sup>

getFunctionsFromString(funcs: string): number

在设备模式下，将字符串形式的USB功能列表转换为数字掩码。适用于需要将配置文件或用户输入的字符串形式USB功能列表转换为系统内部使用的数字掩码的场景，以便后续调用setDeviceFunctions等接口设置USB功能。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | 是   | 字符串形式的功能列表。可用值包括：'none'、'acm'、'ecm'、'hdc'、'mtp'、'ptp'、'rndis'、'midi'、'audio_source'、'ncm'，可通过英文逗号分隔多个功能。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 转换后的功能列表对应的数字掩码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |

**示例：**

```ts
// 定义USB功能字符串
let funcs: string = 'acm';
// 将字符串转化为数字掩码
let ret: number = usbManager.getFunctionsFromString(funcs);
```

## getStringFromFunctions<sup>12+</sup>

getStringFromFunctions(funcs: FunctionType): string

在设备模式下，将数字掩码形式的USB功能列表转换为字符串。适用于需要将当前USB功能状态以字符串形式显示或保存的场景，如在日志中记录当前功能配置、在UI界面展示当前功能等。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | 功能列表对应的数字掩码，可通过位运算组合多个功能。部分功能值当前暂不支持，具体参见[FunctionType](#functiontype)。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 转换后的字符串形式的功能列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |

**示例：**

```ts
// 定义USB功能类型组合
let funcs: usbManager.FunctionType = usbManager.FunctionType.ACM | usbManager.FunctionType.ECM;
// 将数字掩码转化为字符串
let ret: string = usbManager.getStringFromFunctions(funcs);
```

## setDeviceFunctions<sup>12+</sup>

setDeviceFunctions(funcs: FunctionType): Promise\<void\>

在设备模式下，设置当前的USB功能列表。使用Promise异步回调。调用成功后，设备的USB功能将切换为指定的功能列表。部分USB功能可能不被当前设备支持，设置前建议先查询设备支持的功能列表。开发者模式关闭时，如果没有设备接入，操作可能会失败，调用失败时抛出异常。功能切换会触发USB设备的重新枚举，已连接的主机可能需要重新识别设备。多个功能可通过位运算组合设置，但某些功能可能互斥或存在优先级，具体约束请参考设备规格。功能设置失败可能由于设备不支持、权限不足或系统限制，详见错误码说明。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型                          | 必填 | 说明              |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | 是   | 功能列表对应的数字掩码，可通过位运算组合多个功能。部分功能可能不被当前设备支持，具体参见[FunctionType](#functiontype)。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。调用成功时无返回值，调用失败时抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |
| 14400002 | Permission denied. The HDC is disabled by the system. Possible causes: The HDC (HarmonyOS Device Connector) feature is disabled in developer settings. Solution: Enable HDC in developer settings or check system configuration. |
| 14400006 | Unsupported operation. The function is not supported. Possible causes: The current device does not support this USB function. Solution: Check device capabilities and ensure the function is supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
// 设置USB功能类型为HDC
let funcs: usbManager.FunctionType = usbManager.FunctionType.HDC;
// 异步设置设备功能
usbManager.setDeviceFunctions(funcs).then(() => {
    console.info('usb setDeviceFunctions successfully.');
}).catch((err : BusinessError) => {
    console.error(`usb setDeviceFunctions failed. Code: ${err.code}, message: ${err.message}`);
});
```

## getDeviceFunctions<sup>12+</sup>

getDeviceFunctions(): FunctionType

在设备模式下，获取当前的USB功能列表的数字组合掩码。适用于需要检查当前USB功能状态、确认功能配置、或在功能切换前后进行状态对比的场景。开发者模式关闭时，如果没有设备接入，接口返回`undefined`，注意需要对接口返回值做判空处理。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**返回值：**

| 类型                          | 说明                              |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | 当前的USB功能列表的数字组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                        |
| -------- | ------------------------------------------------------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |

**示例：**

```ts
// 获取当前USB功能的数字掩码
let ret: usbManager.FunctionType = usbManager.getDeviceFunctions();
```

## getPortList<sup>12+</sup>

getPortList(): Array\<USBPort\>

获取所有物理USB端口描述信息。适用于需要枚举USB端口、进行端口管理、设备连接诊断、或查询端口配置信息的场景。开发者模式关闭时，如果没有设备接入，接口返回`undefined`，注意需要对接口返回值做判空处理。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**返回值：**

| 类型                       | 说明                  |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | USB端口描述信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |

**示例：**

```ts
// 获取USB端口列表
let ret: Array<usbManager.USBPort> = usbManager.getPortList();
```

## getPortSupportModes<sup>12+</sup>

getPortSupportModes(portId: number): PortModeType

获取指定的端口支持的模式列表的组合掩码。适用于系统应用需要查询USB-C端口能力判断是否支持特定模式（如UFP，DFP或DRP模式）的场景。开发者模式关闭时，如果没有设备接入，接口返回undefined，注意需要对接口返回值做判空处理。

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| portId | number | 是   | USB端口号，可通过[getPortList](#getportlist12)获取端口列表后得到。 |

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | 支持的模式列表的组合掩码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |

**示例：**

```ts
// 获取端口ID为0的支持模式
let ret: usbManager.PortModeType = usbManager.getPortSupportModes(0);
```

## setPortRoleTypes<sup>12+</sup>

setPortRoleTypes(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

设置指定端口当前的角色类型，包含电源角色、数据传输角色。使用Promise异步回调。调用成功后端口的电源角色和数据传输角色将切换为指定的角色。适用于系统应用需要动态切换USB端口角色的场景。开发者模式关闭时，如果没有设备接入，操作可能会失败，调用失败时抛出异常。

**使用建议：**
- 建议先调用[getPortList](#getportlist12)获取端口列表，得到有效的portId
- 建议调用[getPortSupportModes](#getportsupportmodes12)查询端口支持的模式，确保设置的角色配置在支持范围内
- 如果设置的角色不被端口支持，调用会失败并返回错误码14400003

> **说明：**
>
> 从API version 12开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型                            | 必填 | 说明             |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | 是   | 端口号，可通过[getPortList](#getportlist12)获取端口列表后得到。|
| powerRole | [PowerRoleType](#powerroletype) | 是   | 充电角色类型，可选值包括：NONE（无）、SOURCE（对外提供电源）、SINK（需要外部供电）。|
| dataRole  | [DataRoleType](#dataroletype)   | 是   | 数据传输角色类型，可选值包括：NONE（无）、HOST（主机角色）、DEVICE（设备角色）。|

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise\<void\> | Promise对象。调用成功时无返回值，调用失败时抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |
| 14400003 | Unsupported operation. The current device does not support port role switching. Possible causes: The hardware does not support USB Type-C port role switching. Solution: Check device hardware capabilities. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义端口号
let portId: number = 1;
// 设置端口角色类型：充电角色为SOURCE，数据角色为HOST
usbManager.setPortRoleTypes(portId, usbManager.PowerRoleType.SOURCE, usbManager.DataRoleType.HOST).then(() => {
  console.info('usb setPortRoleTypes successfully.');
}).catch((err : BusinessError) => {
  console.error(`usb setPortRoleTypes failed. Code: ${err.code}, message: ${err.message}`);
});
```

## addAccessoryRight<sup>14+</sup>

addAccessoryRight(tokenId: number, accessory: USBAccessory): void

为应用添加访问USB配件权限。适用于系统应用需要为第三方应用授权访问USB配件的场景。usbManager.requestAccessoryRight会触发弹窗请求用户授权；addAccessoryRight不会触发弹窗，而是直接添加应用访问USB配件的权限。授权立即生效并持久化存储，设备重启后仍然有效。授权范围为指定的USB配件实例，多个应用可以同时获得同一配件的访问权限。与requestAccessoryRight相比，addAccessoryRight不需要用户交互，适用于系统应用自动授权场景。

> **说明：**
>
> 从API version 14开始支持。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_USB_CONFIG，该权限为系统权限，仅系统应用可申请。系统应用可通过配置文件中的requestPermissions字段申请该权限，具体申请方式请参考[权限申请开发指导](../../security/AccessToken/permissions-for-all.md)。

**系统能力：** SystemCapability.USB.USBManager

**参数：**

| 参数名    | 类型         | 必填 | 说明                     |
| --------- | ------------ | ---- | ------------------------ |
| tokenId   | number       | 是   | 应用程序的唯一标识符，可通过[bundleManager.getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取。 |
| accessory | [USBAccessory](js-apis-usbManager.md#usbaccessory14) | 是   | USB配件对象，包含配件的标识和属性信息。可通过[getAccessoryList](js-apis-usbManager.md#usbmanagergetaccessorylist14)获取配件列表后获得。详细字段定义参见[USBAccessory](js-apis-usbManager.md#usbaccessory14)接口。 |

**返回值：**

| 类型      | 说明          |
| --------- | ------------- |
| void      | 调用成功后，应用程序获得USB配件访问权限；调用失败时抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. Possible causes: The application is not a system application or does not have required system permissions. Solution: Apply for the required system permissions or use public APIs. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. Solution: Check the parameter types and ensure all required parameters are provided. |
| 801      | Capability not supported. Possible causes: The current device or system does not support this USB capability. Solution: Check if the device supports this capability and ensure the system version meets the requirements. |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. Solution: Ensure the USB accessory is properly plugged into the device and try again. |
| 14400005 | Database operation exception. Possible causes: Database corruption or insufficient storage space. Solution: Check device storage space, clear cache, or restart the device. If the problem persists, contact support. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
async function addAccessoryRightExample() {
  // 为指定应用添加USB配件访问权限
  try {
    // 获取USB配件列表
    let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList();
    if (accList.length === 0) {
      console.error('No USB accessory found');
      return;
    }
    // 设置bundle信息标志
    let flags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION |
    bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;
    // 异步获取当前应用的bundle信息
    let bundleInfo = await bundleManager.getBundleInfoForSelf(flags);
    // 获取应用的tokenId
    let tokenId: number = bundleInfo.appInfo.accessTokenId;
    // 为应用添加USB配件访问权限
    usbManager.addAccessoryRight(tokenId, accList[0]);
    console.info('addAccessoryRight success');
  } catch (error: BusinessError) {
    console.error(`addAccessoryRight error ${error.code}, message is ${error.message}`);
  }
}
```

## USBPort

USB设备端口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称           | 类型                            | 只读 | 可选 | 说明                                |
| -------------- | ------------------------------- | ---- | ---- | ----------------------------------- |
| id             | number                          | 否   | 否   | USB端口唯一标识。                   |
| supportedModes | [PortModeType](#portmodetype)   | 否   | 否   | USB端口所支持的模式的数字组合掩码。status.currentMode应在此范围内。 |
| status         | [USBPortStatus](#usbportstatus) | 否   | 否   | USB端口角色信息。其currentMode应在supportedModes范围内。|

## USBPortStatus

USB设备端口角色信息。currentMode表示端口的当前USB模式，其值应在USBPort的supportedModes范围内。currentPowerRole表示当前电源角色，currentDataRole表示当前数据传输角色。这些字段之间存在对应关系：在DFP模式下，dataRole通常为HOST、powerRole通常为SOURCE；在UFP模式下，dataRole通常为DEVICE、powerRole通常为SINK。端口状态变更受硬件和系统约束，某些模式或角色组合可能不被支持。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称             | 类型   | 只读 | 可选 | 说明                   |
| ---------------- | ------ | ---- | ---- | ---------------------- |
| currentMode      | number | 否   | 否   | 当前的USB模式。        |
| currentPowerRole | number | 否   | 否   | 当前设备电源角色。     |
| currentDataRole  | number | 否   | 否   | 当前设备数据传输角色。 |

## FunctionType

USB设备侧功能。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称         | 值  | 说明       |
| ------------ | --- | ---------- |
| NONE         | 0   | 没有功能。 |
| ACM          | 1   | acm（Abstract Control Model，抽象控制模型），串口通信功能，用于模拟串口设备。|
| ECM          | 2   | ecm（Ethernet Control Model，以太网控制模型），以太网控制功能，用于网络共享。  |
| HDC          | 4   | hdc（HarmonyOS Device Connector，HarmonyOS设备连接器）。  |
| MTP          | 8   | mtp（Media Transfer Protocol，媒体传输协议）。 |
| PTP          | 16  | ptp（Picture Transfer Protocol，图片传输协议）。 |
| RNDIS        | 32  | rndis（Remote Network Driver Interface Specification，远程网络驱动接口规范），用于网络共享（暂不支持）。 |
| MIDI         | 64  | midi（Musical Instrument Digital Interface，乐器数字接口），用于MIDI设备通信（暂不支持）。 |
| AUDIO_SOURCE | 128 | 音频源功能，用于音频数据传输（暂不支持）。 |
| NCM          | 256 | ncm（Network Control Model，网络控制模型），用于高速网络共享（暂不支持）。  |

## PortModeType

USB端口模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.USB.USBManager

| 名称      | 值 | 说明                                                 |
| --------- | -- | ---------------------------------------------------- |
| NONE      | 0  | 无。                                                 |
| UFP       | 1  | 数据上行，需要外部供电。                             |
| DFP       | 2  | 数据下行，对外提供电源。                             |
| DRP       | 3  | 既可以做DFP（Host），也可以做UFP（Device），当前不支持。 |
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

