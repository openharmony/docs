# FAQs About Immersive Light Sense

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @H-xinwei-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=0ecc390317140dcc7c4726f5897f445275bf3259 translatedAt=2026-08-01T00:27:40.538Z pushedAt=2026-08-01T04:55:46.667Z -->

This document provides common issues and solutions encountered during the development of immersive light sense. For a complete introduction and development guide to immersive light sense, see [Immersive Light Sense](arkts-immersive-light-sense.md).

## No Material Effect Is Visible After Setting Immersive System Material for a Component

**Symptom**

After calling the [systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial) API to set immersive system material for a component, the component's visual appearance does not change and still displays a solid-color background or no material effect at all.

**Possible Causes**

The visual layer of the immersive system material is positioned below the component's [backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor), [backgroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundblurstyle9), and other attributes. If an opaque background color or background blur style is set simultaneously, these properties will overlay the material layer, blocking the material effect from being visible.

**Solution**

1. Set the component's background color to transparent (`Color.Transparent`) or remove the background color setting.

2. Remove background blur styles such as [backgroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundblurstyle9) to prevent the blur effect from covering the material layer.

**Code Example**

```ts
// Incorrect approach: an opaque background color overlays the material layer, making the material effect invisible
Column() {
  Text('Immersive light sense')
}
.width(328)
.height(56)
.borderRadius(28)
.systemMaterial(new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
}))
.backgroundColor(Color.White)

// Recommended approach: set the background color to transparent to ensure the material effect is visible
Column() {
  Text('Immersive light sense')
}
.width(328)
.height(56)
.borderRadius(28)
.backgroundColor(Color.Transparent)
.systemMaterial(new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
}))
```

## Component Border Displays Colors from the Surrounding Background After Setting Immersive System Material

**Symptom**

After setting immersive system material for a component, the component's border area displays colors from the surrounding background image or background color, rather than the expected border effect.

**Possible Causes**

This is a normal optical behavior of immersive system materials. The immersive light sense visual effect has refractive properties that cause surrounding content to refract through the material layer into the component's border area. This refraction effect is an important part of the material's transparency and layering, and is particularly noticeable with thinner material styles such as ULTRA_THIN and THIN.

**Solution**

- Use thicker material styles (such as REGULAR, THICK, or ULTRA_THICK) to reduce material transparency and thereby minimize the refraction effect.

- Add a [materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) overlay to the material layer to reduce the visibility of refraction by blending in a semi‑transparent color.

## Fully Transparent materialColor Removes Material Effect

**Symptom**

After passing a color to the [materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) parameter of an immersive system material, the material effect completely disappears and only a solid‑color background is displayed.

**Possible Causes**

The [materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) parameter is used to blend an additional solid color layer on top of the material filter [materialFilter](../reference/apis-arkui/arkui-ts/ts-universal-attributes-filter-effect.md#materialfilter23). This color needs to have a certain level of transparency. If a fully opaque color (such as `Color.Red` or `'#FFFF0000'`) is passed, it will obscure the material filter effect.

**Solution**

Pass a color value with transparency to [materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions).

> **NOTE**
>
> The [materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) parameter takes effect on devices of all computing power tiers. On high‑ and medium‑tier devices, it blends an additional solid color layer over the material filter; on low‑tier devices, it serves as the [backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor) attribute.

**Code Example**

```ts
// Incorrect usage: a solid opaque color blocks the material effect
new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
  materialColor: Color.Red, // Opaque, the material filter effect is completely blocked
})

// Recommended usage: use a color with transparency
new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
  materialColor: '#80FF0000', // Red with 50% transparency
})
```

## Immersive Light Sense Effect Differs Significantly on Low‑Tier Devices Compared to High‑Tier Devices

**Symptom**

When running the application on low‑tier devices, the visual effect of immersive system materials differs significantly from high‑tier devices, and some material parameter settings do not take effect.

**Possible Causes**

The effect of immersive system material is automatically adapted based on the device's computing power tier. On high and medium computing power devices, it affects the [materialFilter](../reference/apis-arkui/arkui-ts/ts-universal-attributes-filter-effect.md#materialfilter23) effect and shadow effect; on low computing power devices, it affects only the background color, border color, border width, and shadow effect. In addition, the material [style](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) and automatic color inversion [colorInvert](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) parameters take effect only on high and medium computing power devices. Setting these two parameters on low computing power devices does not produce any visual difference.

**Solution**

This is a system-level adaptive behavior. You do not need to write differentiated code for devices of different tiers; immersive light sense automatically ensures smooth operation on devices of all tiers.

## Text Color Does Not Change After Enabling Automatic Color Inversion

**Symptom**

After enabling the [colorInvert](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) automatic color inversion feature for immersive system materials, the color of the text inside the component does not automatically adapt to the background color.

**Possible Causes**

For automatic color inversion to take effect, the following conditions must be met simultaneously:

- The material style must be THIN or ULTRA_THIN. It does not take effect under REGULAR, THICK, or ULTRA_THICK styles.

- The system's immersive light sense intensity configuration affects the inversion trigger threshold. The thinner the material and the stronger the system's immersive light sense setting, the more likely automatic inversion is triggered.

- Automatic color inversion takes effect only for color values set through resource interfaces, including the [fontColor](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#fontcolor) attribute of the [Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md) component, the [fontColor](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md#fontcolor) attribute of the [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md) component, the [fontColor](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md#fontcolor) attribute of the [SymbolGlyph](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md) component, the [fillColor](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#fillcolor) attribute of the [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md) component, and the color attributes of components such as TextInput, TextArea, Chip, ChipGroup, SegmentButton, and Swiper. For the complete list of attributes that take effect, see the [colorInvert](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) parameter description. Hardcoded color values in the code (such as `Color.White` and `'#FFFFFFFF'`) do not trigger automatic color inversion.

**Solution**

1. Ensure that the material style is THIN or ULTRA_THIN.

2. Ensure that the text color is set via resource interfaces (such as `$r('app.color.xxx')`), rather than hard‑coded color values.

3. Increase the system's immersive light sense configuration and observe the effect.

## Shadow Effect Does Not Behave as Expected When Both shadow Attribute and Immersive System Material Are Set

**Symptom**

After setting both the [shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow) universal attribute and immersive system material for a component, the shadow effect displays the material's built‑in shadow style, and the custom shadow parameters do not take effect.

**Possible Causes**

When the [applyShadow](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) parameter of the immersive system material is **true** (default value), the shadow effect in the material takes effect fixedly and takes precedence over the [shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow) universal attribute. In this case, the custom shadow settings do not take effect. When this parameter is **false**, the [shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow) universal attribute takes effect, and the material's shadow effect does not take effect.

**Solution**

- If you need to use the shadow effect that comes with the material, you do not need to set the **shadow** attribute additionally.

- If you need to use a custom **shadow** universal attribute, set [applyShadow](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions) to **false**.

**Code Example**

```ts
// Disable the material shadow and use a custom shadow.
new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.REGULAR,
  applyShadow: false,
})
```

## Component Style Appears Abnormal After Setting Material via the systemMaterial Universal Attribute

**Symptom**

After setting the immersive system material through the universal attribute [systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial), the component's background color, border, and other styles do not display as expected.

**Possible Causes**

When setting materials through the universal attribute, if [systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial) is placed before other style attributes, the material effect priority may not match expectations.

**Solution**

Set [systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial) after other style attributes (such as background color, border, shadow, etc.). When setting the material through component options parameters (such as **Toast**'s [ShowToastOptions](../reference/apis-arkui/js-apis-promptAction.md#showtoastoptions), **Popup**'s [PopupOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupoptions), etc.), the order does not need to be considered.

**Code Example**

```ts
// Recommended: Set other attributes first, then set systemMaterial.
Column() {
  Text('Recommend')
}
.width(328)
.height(56)
.borderRadius(28)
.justifyContent(FlexAlign.Center)
.systemMaterial(new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.REGULAR,
}))
```

## Dialog or Toast Components Do Not Display Material Effects by Default

**Symptom**

In [DEFAULT](../reference/apis-arkui/arkts-apis-uimaterial.md#materialstate) mode, components such as [Dialog](arkts-base-dialog-overview.md) and [Toast](arkts-create-toast.md) do not display the visual effect of immersive system material.

**Possible Causes**

[DEFAULT](../reference/apis-arkui/arkts-apis-uimaterial.md#materialstate) is the default enabling mode for immersive system materials. In this mode, components such as [Dialog](arkts-base-dialog-overview.md), [Toast](arkts-create-toast.md), and [AlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md) will only enable immersive system materials by default when no background color, blur parameters, or shadow parameters are set. If you set attributes such as [backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor), [backgroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundblurstyle9), or [shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow) for these components, immersive system material will not be enabled by default.

**Solution**

- Remove conflicting property settings (such as **backgroundColor**, **backgroundBlurStyle**, and **shadow**) to allow the material effect to be enabled by default.

- In ENABLE mode, immersive system material styles have higher priority than the component's own background color, blur, shadow, and border styles, and more components enable materials by default.

- To use materials while retaining existing properties, actively set them via the [systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial) attribute.