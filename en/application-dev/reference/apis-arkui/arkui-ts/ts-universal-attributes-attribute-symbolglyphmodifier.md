# SymbolGlyphModifier

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

You can use **SymbolGlyphModifier** to construct components and configure their attributes. Through **SymbolGlyphModifier**, you can access the attributes and style APIs of the encapsulated component.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## SymbolGlyphModifier

Defines the **SymbolGlyphModifier**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(src?: Resource)

Constructs a **SymbolGlyphModifier** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| src | [Resource](../../apis-localization-kit/js-apis-resource.md#resource) | No  | Resource information.|

### applyNormalAttribute

applyNormalAttribute?(instance: SymbolGlyphAttribute): void

Applies the style of a component in the normal state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| instance | [SymbolGlyphAttribute](ts-basic-components-symbolGlyph.md) | Yes  | Dynamic attribute setting for the SymbolGlyph component.|
