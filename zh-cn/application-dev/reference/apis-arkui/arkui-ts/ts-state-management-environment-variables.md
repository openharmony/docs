# 内置环境变量说明

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

内置环境变量用于反映系统环境状态的值，开发者可通过[Environment](./ts-state-management.md#environment)查询内置环境变量（如深浅色模式、布局方向等）。

## ColorMode

系统当前深浅色模式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 值   | 说明       |
| ----- | ---- | ---------- |
| LIGHT | 0    | 浅色模式。 |
| DARK  | 1    | 深色模式。 |


## LayoutDirection

系统的布局方向类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值   | 说明                 |
| ---- | ---- | -------------------- |
| LTR  | 0    | 从左向右布局。       |
| RTL  | 1    | 从右向左布局。       |
| Auto<sup>8+</sup> | 2    | 自动布局，跟随系统。 |
