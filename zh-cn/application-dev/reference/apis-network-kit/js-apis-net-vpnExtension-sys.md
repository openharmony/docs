# @ohos.net.vpnExtension (VPN 增强管理)（系统接口）

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

三方VPN管理模块，支持三方VPN的启动和停止功能。
三方VPN是指由第三方提供的VPN服务，它们通常提供更多的功能和更广泛的网络连接选项，包括更多的安全和隐私功能，以及更全面的定制选项。

> **说明：**
> 本模块首批接口从 API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.net.vpnExtension (VPN 增强管理)](js-apis-net-vpnExtension.md)。

## 导入模块

```js
import { vpnExtension } from '@kit.NetworkKit';
```


## vpnExtension.setAlwaysOnVpnEnabled

setAlwaysOnVpnEnabled(enable: boolean, bundleName: string): Promise\<void>

设置设备的启用/禁用always on VPN模式。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型    | 必填 | 说明                                                    |
| ---------- | ------- | ---- | ------------------------------------------------------- |
| enable     | boolean | 是   | always on启用或禁用。true：always on启用；false：always on禁用。                                   |
| bundleName | string  | 是   | 设置了always on vpn的包名，通常指三方应用的bundleName。 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**
Stage 模型示例：

```ts
import { vpnExtension } from '@kit.NetworkKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  deviceId: "",
  bundleName: 'com.example.myvpndemo',
  abilityName: 'MyVpnExtAbility',
};

vpnExtension.setAlwaysOnVpnEnabled(true, want.bundleName).then(() => {
  console.info('setAlwaysOnVpnEnabled success.');
}).catch((err : BusinessError) => {
  console.error('setAlwaysOnVpnEnabled fail, err-> ${JSON.stringify(err)}');
});
```

## vpnExtension.isAlwaysOnVpnEnabled

isAlwaysOnVpnEnabled(bundleName: string): Promise\<boolean>

获取always on VPN开关状态。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                    |
| ---------- | ------ | ---- | ------------------------------------------------------- |
| bundleName | string | 是   | 设置了always on vpn的包名，通常指三方应用的bundleName。 |

**返回值：**

| 类型              | 说明                           |
| ----------------- | ------------------------------ |
| Promise\<boolean> | 返回应用alway on vpn开关状态。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**
Stage 模型示例：

```ts
import { vpnExtension } from '@kit.NetworkKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  deviceId: "",
  bundleName: 'com.example.myvpndemo',
  abilityName: 'MyVpnExtAbility',
};

vpnExtension.isAlwaysOnVpnEnabled(want.bundleName).then((data : boolean) => {
  console.info('isAlwaysOnVpnEnabled success.');
}).catch((err : BusinessError) => {
  console.error('setAlwaysOnVpnEnabled fail, err-> ${JSON.stringify(err)}');
});
```

## vpnExtension.updateVpnAuthorizedState

updateVpnAuthorizedState(bundleName: string): boolean

更新VPN对话框授权信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ---------- | ------ | ---- | ------------------------------------------------ |
| bundleName | string | 是   | 应用弹框授权的包名，通常指三方应用的bundleName。 |

**返回值：**

| 类型    | 说明                                        |
| ------- | ------------------------------------------- |
| boolean | 返回值用来判断是否成功更新vpn弹框授权状态。true：成功更新vpn弹框授权状态；false：没有成功更新vpn弹框授权状态。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**
Stage 模型示例：

```ts
import { vpnExtension } from '@kit.NetworkKit';
import { Want } from '@kit.AbilityKit';

let want: Want = {
  deviceId: "",
  bundleName: 'com.example.myvpndemo',
  abilityName: 'MyVpnExtAbility',
};

let result: boolean = vpnExtension.updateVpnAuthorizedState(want.bundleName);
console.info("Result: "+ result);
```

