# @ohos.net.vpnExtension (VPN 增强管理)（系统接口）

三方VPN管理模块，支持三方VPN的启动和停止功能。

> **说明：**
> 本模块首批接口从 API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.net.vpnExtension (VPN 增强管理)](js-apis-net-vpnExtension.md)

## 导入模块

```js
import vpnExt from "@ohos.net.vpnExtension";
```


## vpnExt.setAlwaysOnVpnEnabled

setAlwaysOnVpnEnabled(enable: boolean, bundleName: string): Promise\<void>

设置设备的启用/禁用always on VPN模式。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型    | 必填 | 说明                                                    |
| ---------- | ------- | ---- | ------------------------------------------------------- |
| enable     | boolean | 是   | always on启用或禁用。                                   |
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
import vpnExt from '@ohos.net.vpnExtension';
import Want from '@ohos.app.ability.Want';  

build() {
    Column() {
      this.TipTextStyle(this.content, 20)
      Text($r('app.string.title')).ControlText()
      Text($r('app.string.warning')).fontSize(16).margin({ top: 0, bottom: 8, left: 24, right: 24 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Text($r('app.string.notAllowButton'))
          .ControlBtn(this.notAllowFontColor)
          .onClick(() => {
            this.destruction();
          })
        Text('|')
          .fontSize(20)
        Text($r('app.string.allowButton'))
          .ControlBtn(this.allowFontColor)
          .onClick(() => {
            let bundleName = globalThis.bundleName;
            let abilityName = globalThis.abilityName;
            vpnExt.setAlwaysOnVpnEnabled(true,bundleName);
            let want: Want = {
              deviceId: "",
              bundleName: bundleName,
              abilityName: abilityName,
            };
            vpnExt.startVpnExtensionAbility(want);
            this.destruction()
          })

      }.margin({ bottom: 16, left: 24, right: 24})
    }
  }
```

## vpnExt.isAlwaysOnVpnEnabled

isAlwaysOnVpnEnabled(bundleName: string): Promise\<boolean>

获取always on VPN开关状态。

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
import vpnExt from '@ohos.net.vpnExtension';
import Want from '@ohos.app.ability.Want';  

build() {
    Column() {
      this.TipTextStyle(this.content, 20)
      Text($r('app.string.title')).ControlText()
      Text($r('app.string.warning')).fontSize(16).margin({ top: 0, bottom: 8, left: 24, right: 24 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Text($r('app.string.notAllowButton'))
          .ControlBtn(this.notAllowFontColor)
          .onClick(() => {
            this.destruction()
          })
        Text('|')
          .fontSize(20)
        Text($r('app.string.allowButton'))
          .ControlBtn(this.allowFontColor)
          .onClick(() => {
            let bundleName = globalThis.bundleName;
            let abilityName = globalThis.abilityName;
            vpnExt.isAlwaysOnVpnEnabled(bundleName);
            let want: Want = {
              deviceId: "",
              bundleName: bundleName,
              abilityName: abilityName,
            };
            vpnExt.startVpnExtensionAbility(want);
            this.destruction();
          })

      }.margin({ bottom: 16, left: 24, right: 24})
    }
  }
```

## vpnExt.updateVpnAuthorizedState

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
| boolean | 返回值用来判断是否成功更新vpn弹框授权状态。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**
Stage 模型示例：

```ts
import vpnExt from '@ohos.net.vpnExtension';
import Want from '@ohos.app.ability.Want';  

build() {
    Column() {
      this.TipTextStyle(this.content, 20)
      Text($r('app.string.title')).ControlText()
      Text($r('app.string.warning')).fontSize(16).margin({ top: 0, bottom: 8, left: 24, right: 24 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Text($r('app.string.notAllowButton'))
          .ControlBtn(this.notAllowFontColor)
          .onClick(() => {
            this.destruction();
          })
        Text('|')
          .fontSize(20)
        Text($r('app.string.allowButton'))
          .ControlBtn(this.allowFontColor)
          .onClick(() => {
            let bundleName = globalThis.bundleName;
            let abilityName = globalThis.abilityName;
            vpnExt.updateVpnAuthorizedState(bundleName);
            let want: Want = {
              deviceId: "",
              bundleName: bundleName,
              abilityName: abilityName,
            };
            vpnExt.startVpnExtensionAbility(want);
            this.destruction();
          })

      }.margin({ bottom: 16, left: 24, right: 24})
    }
  }
```

