# AccessibilityExtensionContext (辅助功能扩展上下文)(系统接口)

AccessibilityExtensionContext是AccessibilityExtensionAbility上下文环境，继承自ExtensionContext。

辅助功能扩展上下文模块提供辅助功能扩展的上下文环境的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口请参[AccessibilityExtensionContext (辅助功能扩展上下文)](js-apis-inner-application-accessibilityExtensionContext.md)。

## 使用说明

在使用AccessibilityExtensionContext的功能前，需要通过AccessibilityExtensionAbility子类实例获取AccessibilityExtensionContex的实例。

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

### enableScreenCurtain<sup>12+</sup>

enableScreenCurtain(isEnable: boolean): void;

提供开启/关闭幕帘屏的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| isEnable | boolean | 是    | true表示打开幕帘屏功能，false表示关闭幕帘屏功能。|

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  | Input parameter error. Incorrect parameter types. |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
  await rootElement.enableScreenCurtain(true);
  console.log(`Succeeded in enableScreenCurtain}`);
}).catch((err: BusinessError) => {
  console.error(`failed to enableScreenCurtain, Code is ${err.code}, message is ${err.message}`);
});
```