# @ohos.FusionConnectivity.partnerAgent（设备状态通知模块）(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

本模块基于蓝牙通信技术，为应用提供设备发现与设备下线的通知功能，主要功能特性包括：

- 动态监听并发现应用预先注册的蓝牙设备。
- 采用进程拉起机制，当目标设备出现时自动拉起应用的[PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md)进程。
- 采用进程销毁机制，当所有设备下线时自动销毁应用的[PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md)进程。
- 通过[PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md)的接口通知应用发现已注册设备。

> **说明：**
> - 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { partnerAgent } from '@kit.ConnectivityKit';
```

## partnerAgent.enableDeviceControl

enableDeviceControl(deviceAddress: PartnerDeviceAddress): Promise&lt;void&gt;

开启外设互通功能，使用Promise异步回调。

- 该接口仅对应用调用[BindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice)注册过的设备生效，调用后给应用提供设备互通能力[partnerAgent](js-apis-fusionConnectivity-partnerAgent.md)。
- 可以通过[isDeviceControlEnabled](js-apis-fusionConnectivity-partnerAgent.md#partneragentisdevicecontrolenabled)判断设备的外设互通是否已开启，若已开启，重复调用不生效。
- 可以通过[disableDeviceControl](#partneragentdisabledevicecontrol)关闭外设互通功能。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**参数**：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceAddress | [PartnerDeviceAddress](js-apis-fusionConnectivity-partnerAgent.md#partnerdeviceaddress) | 是    | 应用注册的设备地址信息。<br>应用需配置PartnerDeviceAddress类型的bluetoothAddress选项。 |

**返回值**：

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参考[通用错误码说明文档](../errorcode-universal.md)和[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs.                 |
|801 | Capability not supported.          |
|34900001 | The device is not bound.                         |
|34900099 | Internal error. |

**示例**：

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let btAddr: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
  };
  let deviceAddress: partnerAgent.PartnerDeviceAddress = {
    "bluetoothAddress": btAddr,
  };
  partnerAgent.enableDeviceControl(deviceAddress)
    .then(() => {
      console.info(`enable device control success: ${btAddr.address}`);
    })
    .catch((err: BusinessError) => {
      console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    });
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## partnerAgent.disableDeviceControl

disableDeviceControl(deviceAddress: PartnerDeviceAddress): Promise&lt;void&gt;

关闭外设互通功能，使用Promise异步回调。

- 该接口仅对应用[BindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice)注册过的设备生效，调用后关闭给应用提供的设备互通能力[partnerAgent](js-apis-fusionConnectivity-partnerAgent.md)。
- 可以通过[isDeviceControlEnabled](js-apis-fusionConnectivity-partnerAgent.md#partneragentisdevicecontrolenabled)判断设备的外设互通是否已开启，若已关闭，重复调用不生效。
- 关闭后，其他应用调用[BindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice)注册过设备的被发现时不会拉起应用注册的[PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md)进程，可通过调用[enableDeviceControl](#partneragentenabledevicecontrol)重新开启的外设互通功能。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**参数**：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceAddress | [PartnerDeviceAddress](js-apis-fusionConnectivity-partnerAgent.md#partnerdeviceaddress) | 是 | 应用注册的设备地址信息。<br>应用需配置PartnerDeviceAddress类型的bluetoothAddress选项。 |

**返回值**：

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参考[通用错误码说明文档](../errorcode-universal.md)和[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs.                 |
|801 | Capability not supported.          |
|34900001 | The device is not bound.                         |
|34900099 | Internal error. |

**示例**：

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let btAddr: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
  };
  let deviceAddress: partnerAgent.PartnerDeviceAddress = {
    "bluetoothAddress": btAddr,
  };
  partnerAgent.disableDeviceControl(deviceAddress)
    .then(() => {
      console.info(`disable device control success: ${btAddr.address}`);
    })
    .catch((err: BusinessError) => {
      console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    });
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```