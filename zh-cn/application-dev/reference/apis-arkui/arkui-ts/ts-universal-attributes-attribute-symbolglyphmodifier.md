# 动态SymbolGlyphModifier属性设置

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

开发者可使用SymbolGlyphModifier构建组件并配置属性，通过此SymbolGlyphModifier可调用所封装组件的属性和样式接口。

>  **说明：**
>
>  从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## SymbolGlyphModifier

定义SymbolGlyphModifier。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(src?: Resource)

SymbolGlyphModifier的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| src | [Resource](../../apis-localization-kit/js-apis-resource.md#resource) | 否   | 资源信息。 |

### applyNormalAttribute

applyNormalAttribute?(instance: SymbolGlyphAttribute): void

组件普通状态时的样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| instance | [SymbolGlyphAttribute](ts-basic-components-symbolGlyph.md) | 是   | 动态设置SymbolGlyph组件的属性。 |