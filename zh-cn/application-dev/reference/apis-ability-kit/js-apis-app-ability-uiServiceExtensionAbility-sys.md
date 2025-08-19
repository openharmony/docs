# @ohos.app.ability.UIServiceExtensionAbility (UIServiceExtensionAbility)(系统接口)

UIServiceExtensionAbility提供浮窗组件相关扩展能力，继承自[ExtensionAbility](js-apis-app-ability-extensionAbility.md)。主要用于向三方应用提供带界面的服务。


> **说明：**
>
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。
>
> 本模块为系统接口。

## 导入模块

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
```

## UIServiceExtensionAbility

### 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIServiceExtensionContext](js-apis-inner-application-uiserviceExtensionContext-sys.md) | 否 | 否 | [UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。 |


### onCreate

onCreate(want: Want): void

[UIServiceExtensionContext](js-apis-inner-application-uiserviceExtensionContext-sys.md) 生命周期创建接口，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |  -------- |
| want |  [Want](js-apis-app-ability-want.md) | 是  | 否| 当前[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)相关的 [Want](js-apis-app-ability-want.md) 类型信息，包括Ability名称、Bundle名称等。 |

**示例：**

```ts
import { UIServiceExtensionAbility, Want } from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  // 创建UIServiceExtensionAbility
  onCreate(want: Want) {
    console.info(`onCreate, want: ${want.abilityName}`);
  }
}
```


### onRequest

onRequest(want: Want, startId: number): void

请求拉起[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)服务处理。如果是[startAbility](js-apis-inner-application-uiAbilityContext.md#startability)或者[startUIServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#startuiserviceextensionability14)拉起的服务，会在[onCreate](#oncreate)之后回调。每次拉起服务都会回调，startId会递增。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | 是 |  当前[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)相关的 [Want](js-apis-app-ability-want.md) 类型信息，包括Ability名称、Bundle名称等。 |
| startId | number | 是 | 返回浮窗拉起次数。首次拉起初始值返回1，多次之后自动递增。 |

**示例：**

```ts
import { UIServiceExtensionAbility, Want} from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest, want:' + want.abilityName + ', startId:' + startId);
  }
}
```


### onConnect

onConnect(want: Want, proxy: UIServiceHostProxy): void

[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)生命周期回调。如果是[connectUIServiceExtensionAbility()](js-apis-inner-application-uiExtensionContext.md#connectuiserviceextensionability14)拉起的服务，会在[onCreate()](#oncreate)之后回调。接收一个[UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md)对象，用于客户端和服务端进行通信。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| 是 | 否| 当前[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)相关的[Want](js-apis-app-ability-want.md)类型信息，包括Ability名称、Bundle名称等。 |
| proxy | [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) | 是 | 否 | 一个[UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md)对象，用于客户端和服务端进行通信。 |


**示例：**

```ts
import { UIServiceExtensionAbility, Want, common} from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  onConnect(want: Want, proxy: common.UIServiceHostProxy){
    console.info('onConnect, want:' + want.abilityName + '');
  }
}
```


### onDisconnect

onDisconnect(want: Want, proxy: UIServiceHostProxy): void

断开与[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)的连接。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| 是 | 否 | 当前[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)相关的[Want](js-apis-app-ability-want.md)类型信息，包括Ability名称、Bundle名称等。 |
| proxy |[UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md)| 是 | 否 | 往发起方发送数据的Proxy。 |

**示例：**

```ts
import { UIServiceExtensionAbility, Want, common } from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  onDisconnect(want: Want, proxy: common.UIServiceHostProxy) {
    console.info('onDisconnect, want: ${want.abilityName}');
  }
}
```


### onWindowWillCreate

onWindowWillCreate(config: window.ExtensionWindowConfig): void

[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)窗体创建前的回调。前台应用把要创建windows的参数通过window.ExtensionWindowConfig传回给[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)服务。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| config |[window.ExtensionWindowConfig](../apis-arkui/js-apis-window-sys.md#extensionwindowconfig14)| 是 | 否 | [UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)窗体配置信息。 |

**示例：**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class UIServiceExt extends UIServiceExtensionAbility {
  onWindowWillCreate(config : window.ExtensionWindowConfig){
    console.info('onWindowWillCreate');
  }
}
```

### onWindowDidCreate

onWindowDidCreate(window: window.Window): void

[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)创建后回调。[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)服务创建窗口成功后，通过[onWindowDidCreate](#onwindowdidcreate)接口把创建的窗口对象传递给前台应用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |  -------- |
| window | [window.Window](../apis-arkui/js-apis-window-sys.md#window) | 是 | 否 | 表示已创建的Window。 |

**示例：**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class ServiceExt extends UIServiceExtensionAbility {
  onWindowDidCreate(window : window.Window){
    console.info('onWindowDidCreate');
  }
}
```

### onData

onData(proxy: UIServiceHostProxy, data: Record&lt;string, Object&gt;): void

接收到数据的回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |  -------- |
| proxy | [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) | 是 | 否 | 往客户端发送数据的Proxy。 |
| data | Record&lt;string, Object&gt; | 是 | 否 | 表示接收到的数据。 |

**示例：**

```ts
import { UIServiceExtensionAbility, common} from '@kit.AbilityKit';

class ServiceExt extends UIServiceExtensionAbility {
  onData(proxy : common.UIServiceHostProxy, data : Record<string, Object> ){
    console.info('onData');
  }
}
```

### onDestroy

onDestroy(): void

[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**示例：**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';

class ServiceExt extends UIServiceExtensionAbility {
  onDestroy() {
    console.info('onDestroy');
  }
}
```

