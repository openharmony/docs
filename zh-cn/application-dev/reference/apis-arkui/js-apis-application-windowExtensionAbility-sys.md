# @ohos.application.WindowExtensionAbility (窗口扩展能力)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @chbchb12-->
<!--SE: @stupidb-->
<!--TSE: @qinliwen0417-->

WindowExtensionAbility基于ExtensionAbility。WindowExtensionAbility中展示的内容可作为一个控件（AbilityComponent）内容展示在其他应用窗口中。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
```

## 属性

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称      | 类型 | 只读 | 可选 | 说明                      |
| --------- | -------- | ---- | ---- | ------------------------- |
| context      | [WindowExtensionContext](js-apis-inner-application-windowExtensionContext-sys.md)   | 否   | 否   | 上下文。      |

## WindowExtensionAbility.onConnect

onConnect(want: Want): void

当窗口扩展组件第一次连接ability时回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 当前ability的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
import { Want } from '@kit.AbilityKit';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onConnect(want: Want) {
    console.info(`WindowExtAbility onConnect, abilityName: ${want.abilityName}`);
  }
}
```

## WindowExtensionAbility.onDisconnect

onDisconnect(want: Want): void

当所有连接到窗口扩展组件的ability断开连接时回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 当前Ability的Want类型信息，包括ability名称、bundle名称等。 |


**示例：**

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
import { Want } from '@kit.AbilityKit';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onDisconnect(want: Want) {
    console.info(`WindowExtAbility onDisconnect, abilityName: ${want.abilityName}`);
  }
}
```

## WindowExtensionAbility.onWindowReady

onWindowReady(window: window.Window): void

当窗口被创建时回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| window | [window.Window](arkts-apis-window-Window.md) | 是 | 当前窗口实例。 |


**示例：**

```ts
import { WindowExtensionAbility, window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onWindowReady(window: window.Window) {
    window.setUIContent('WindowExtAbility/pages/index1',(err:BusinessError) => {
      let pro = window.getWindowProperties();
      console.info(`WindowExtension pro: ${JSON.stringify(pro)}`);
      window.showWindow();
    });
  }
}
```