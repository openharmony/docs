# ViewData (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

自动填充的视图数据信息。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[ViewData](js-apis-inner-application-viewData.md)。

## 导入模块

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## ViewData

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 名称        | 类型                 | 只读 | 可选 | 说明                                                         |
| ----------- | ------------------- | ---- | ---- | ------------------------------------------------------------ |
| moduleName    | string            | 否   | 否   | 模块名称。                               |
| abilityName   | string            | 否   | 否   | Ability名称。    |
| isUserSelected<sup>12+</sup> | boolean | 否   | 否   | 表示填充内容是否由用户选择。true为用户选择，false为非用户选择。 |
| isOtherAccount<sup>12+</sup> | boolean | 否   | 否   | 表示是否拉起密码箱中其他账号信息供用户选择。true为拉起其他账号信息，false为不拉起其他账号信息。 |
