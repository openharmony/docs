# @ohos.app.ability.ActionExtensionAbility (自定义服务扩展能力)

ActionExtensionAbility是为开发者提供的自定义操作业务模板，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 场景介绍

以翻译文本为例。首先需要创建请求发起方，再创建出ActionExtension，请求发起方需要将翻译的文本发送给ActionExtension，ActionExtension接收到文本后，需要将接收的文本进行翻译，翻译后的文本再发送给请求发起方。

## 导入模块

```ts
import { ActionExtensionAbility } from '@kit.AbilityKit';
```

## ActionExtensionAbility

ActionExtensionAbility是为开发者提供的自定义操作业务模板，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。

ActionExtensionAbility主要用于实现宿主应用的内容查看及交互处理功能。例如，添加一个书签、将选中的文本翻译成其他语言、在当前页面编辑图像等。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore
