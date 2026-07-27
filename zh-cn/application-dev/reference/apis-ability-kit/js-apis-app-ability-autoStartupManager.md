# @ohos.app.ability.autoStartupManager (开机自启管理能力)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

autoStartupManager模块提供获取自身应用的开机自启状态。

> **说明：**
>
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { autoStartupManager } from '@kit.AbilityKit';
```

## autoStartupManager.getAutoStartupStatusForSelf

getAutoStartupStatusForSelf(): Promise\<boolean\>

获取当前应用的开机自启动状态。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在Phone、PC/2in1、Tablet和Wearable设备中可正常调用，在其他设备中返回801错误码。

**返回值：**

| 类型                                          | 说明                                  |
| -------- | -------------------------------------------- |
| Promise\<boolean\> | Promise对象。返回true表示当前应用已被用户设置为开机自启动，false表示当前应用未被用户设置为开机自启动。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.|
| 16000050 | Internal error. Possible causes: 1. Connect to system service failed; 2.System service failed to communicate with dependency module.|

**示例**：

```ts
import { autoStartupManager, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    try {
      autoStartupManager.getAutoStartupStatusForSelf().then((isAutoStartup: boolean) => {
        console.info(`getAutoStartupStatusForSelf success, isAutoStartup: ${JSON.stringify(isAutoStartup)}.`);
      }).catch((err: BusinessError) => {
        console.error(`getAutoStartupStatusForSelf failed, err code: ${err.code}, err msg: ${err.message}.`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`getAutoStartupStatusForSelf failed, err code: ${code}, err msg: ${msg}.`);
    }
  }
}
```

## autoStartupManager.isAutoStartupSupported

isAutoStartupSupported(): boolean

检查当前设备是否支持开机自启动。

> **说明：**
>
>  建议在调用[autoStartupManager.getAutoStartupStatusForSelf](#autostartupmanagergetautostartupstatusforself) 之前，先调用该接口检查设备能力。如果返回false，则表明当前设备不支持开机自启动。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 26.0.0

**返回值：**

| 类型  | 说明                                  |
| -------- | -------------------------------------------- |
| boolean | 当前设备是否支持开机自启动。true表示支持开机自启动；false表示不支持开机自启动。|

**示例**：

```ts
import { autoStartupManager, UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    const isSupported: boolean = autoStartupManager.isAutoStartupSupported();
    console.info(`isAutoStartupSupported: ${isSupported}.`);
  }
}
```