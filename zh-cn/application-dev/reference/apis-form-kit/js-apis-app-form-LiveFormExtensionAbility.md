# @ohos.app.form.LiveFormExtensionAbility  (LiveFormExtensionAbility)

LiveFormExtensionAbility模块提供互动卡片功能，包括创建、销毁互动卡片等，继承自[ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md)。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```
## LiveFormExtensionAbility
互动卡片扩展类。包含互动卡片提供方接收创建和销毁互动卡片的通知接口。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form
| 名称 | 类型    | 只读 | 可选  |说明|
| ------ | ------ | ---- | ---- | ---- |
| context |  [LiveFormExtensionContext](./js-apis-application-LiveFormExtensionContext.md) | 否   | 否 |LiveFormExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。|

### onLiveFormCreate

onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void

LiveFormExtensionAbility界面内容对象创建后调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | 是 | 互动卡片信息，包括卡片id等信息。|
| session      | [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md) | 是 | LiveFormExtensionAbility界面内容相关信息。 |

**示例：**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag] LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    console.info(TAG, `onLiveFormCreate, liveFormInfo: ${JSON.stringify(liveFormInfo)}`);
  }
}
```

### onLiveFormDestroy

onLiveFormDestroy(liveFormInfo: LiveFormInfo): void

LiveFormExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | 是 | 互动卡片信息，包括卡片id等信息。|

**示例：**

```ts
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag] LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
    console.info(TAG, `onLiveFormDestroy, liveFormInfo: ${JSON.stringify(liveFormInfo)}`);
  }
}
```
### LiveFormInfo

互动卡片信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | -------- |
| formId | string | 否 | 否 | 卡片id。 |
| rect | [formInfo.Rect](js-apis-app-form-formInfo.md#rect20) | 否 | 否 | 卡片位置和大小信息。 |
| borderRadius | number | 否 | 否 | 卡片圆角半径信息。取值大于0，单位vp。 |