# SceneResources (系统接口)
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

本模块提供ArkGraphics 3D中常用的基本资源类型。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。
> - 页面仅包含本模块的系统接口，其他公开接口参见[SceneResources](js-apis-inner-scene-resources.md)。

## 导入模块

```ts
import { MaterialType, UnlitShadowAlphaMaterial } from '@kit.ArkGraphics3D';
```

## MaterialType

场景中物体材质类型枚举，定义材质的渲染方式。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| UNLIT_SHADOW_ALPHA<sup>23+</sup> | 100 | 仅对阴影进行绘制，当材质开启[Blend](js-apis-inner-scene-resources.md#blend20)属性，与背景融合模拟透明材质效果。<br>**系统接口：** 此接口为系统接口。<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## UnlitShadowAlphaMaterial<sup>23+</sup>

此材质继承自[Material](js-apis-inner-scene-resources.md#material)，仅绘制材质表面阴影。材质启用[Blend](js-apis-inner-scene-resources.md#blend20)属性时，可与背景融合模拟透明效果。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| baseColor | [MaterialProperty](js-apis-inner-scene-resources.md#materialproperty20) | 否 | 否 | 基础颜色属性，用于表示透明材质表面阴影的颜色信息。|