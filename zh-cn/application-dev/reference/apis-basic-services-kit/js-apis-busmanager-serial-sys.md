# @ohos.busManager.serial (串口通信管理)(系统接口)

<!--Kit: Basic Services Kit-->
<!--Subsystem: BusManager-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @hwymlgitcode-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

本模块主要提供串口通信管理功能，包括获取串口设备列表、打开和关闭串口、读写数据、硬件流控信号管理、权限授权等。适用于需要与外部设备进行串口通信的应用场景，如嵌入式设备控制、工业数据采集等，提供稳定高效的硬件通信能力。

**起始版本：** 26.0.0

## 导入模块

```ts
import { serial } from '@kit.BasicServicesKit';
```

## serial.addPortAuthorization

addPortAuthorization(tokenId: string, deviceId: string): Promise&lt;void&gt;

添加应用访问串口的权限。此函数通过将应用的Token ID与串口设备ID关联，建立应用的串口访问权限关系。适用于系统管理类应用为第三方应用授予串口访问权限的场景，如设备管理工具为工业数据采集应用分配串口权限。仅用于会弹出串口授权弹窗的系统应用，在用户授权后，权限信息将持久化存储。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BusManager.Serial

**参数：**

| 参数名     | 类型     | 必填 | 说明                                                         |
| --------- | -------- | ---- | ------------------------------------------------------------ |
| tokenId   | string   | 是   | 被授权应用的Token ID，用于标识被授予串口访问权限的应用。设置后，指定该应用可获得对相应串口设备的访问权限。可通过[bundleManager.getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取。|
| deviceId  | string   | 是   | 串口设备ID，用于指定需要授权访问的串口设备。可通过获取串口设备列表接口获得。板载串口取值为portName；USB虚拟串口取值为VID+PID+SN的组合或设备路径（如/dev/ttyUSB0）。设置后，应用将获得对指定串口设备的访问权限。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 202      | Permission denied. Called by non-system application. |
| 35700001 | Service error.                                    |
| 35700002 | Invalid parameter.                                |
| 35700008 | Permission denied.                                |

**示例：**

```ts
import {BusinessError} from '@kit.BasicServicesKit';
// 添加串口访问权限
// Token ID 需要通过bundleManager.getBundleInfoForSelf接口获取，此处仅为示例占位符
let tokenId: string = '123456';
let deviceId: string = '/dev/ttyUSB0';
serial.addPortAuthorization(tokenId, deviceId).then(() => {
  console.info('addPortAuthorization success');
}).catch((error: BusinessError) => {
  console.error(`Failed to addPortAuthorization. Code: ${error.code}, message: ${error.message}`);
});
```
