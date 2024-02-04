# 特效绘制合并

用于对背景模糊等特效进行绘制合并。

> **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 该接口为系统接口。

## useEffect

useEffect(value: boolean)

用于对背景模糊等特效进行绘制合并。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | boolean | 是 | 控制组件是否继承EffectComponent组件的特效属性参数，从而合并绘制特效。<br/>useEffect为true时子组件继承EffectComponent组件的特效属性参数。<br/>默认值：false|

## 示例

示例请参考[EffectComponent](ts-container-effectcomponent.md)
