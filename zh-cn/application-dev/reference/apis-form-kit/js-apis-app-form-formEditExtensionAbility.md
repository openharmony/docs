# @ohos.app.form.FormEditExtensionAbility (FormEditExtensionAbility)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

FormEditExtensionAbility模块提供卡片编辑功能，支持用户在卡片提供方应用内编辑卡片内容，适用于需要动态更新卡片展示信息、实现卡片个性化配置的场景。继承自[UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```
## FormEditExtensionAbility

提供卡片编辑功能，继承此类并实现生命周期方法后，可实现卡片编辑界面，用于在用户长按卡片等场景下触发卡片编辑。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form
  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | ------ | ------ | ---- | ---- | ---- |
  | context |  [FormEditExtensionContext](./js-apis-inner-application-formEditExtensionContext.md) | 否   | 否 | FormEditExtensionAbility的上下文环境，[FormEditExtensionContext](./js-apis-inner-application-formEditExtensionContext.md)继承自[UIExtensionContext](../apis-ability-kit/js-apis-inner-application-uiExtensionContext.md#uiextensioncontext-1)。提供拉起编辑页面的能力。|