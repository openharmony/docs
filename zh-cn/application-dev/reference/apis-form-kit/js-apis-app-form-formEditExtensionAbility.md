# @ohos.app.form.FormEditExtensionAbility  (FormEditExtensionAbility)

FormEditExtensionAbility模块提供卡片编辑功能，继承自[UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```

## 属性
**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form
  | 名称 | 类型    | 只读 | 可选  |说明|
  | ------ | ------ | ---- | ---- | ---- |
  | context |  [FormEditExtensionContext](./js-apis-inner-application-formEditExtensionContext.md) | 否   | 否 |FormEditExtensionAbility的上下文环境，默认值是继承自UIExtensionContext的对象。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|
