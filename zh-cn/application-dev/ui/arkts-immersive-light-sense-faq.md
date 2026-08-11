# 沉浸光感常见问题
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @H-xinwei-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

本文提供沉浸光感开发过程中的常见问题及解决措施。沉浸光感的完整能力介绍及开发指导，请参见[沉浸光感](arkts-immersive-light-sense.md)。

## 为组件设置了沉浸式系统材质但看不到材质效果

**问题现象**

为组件调用了[systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial)接口设置沉浸式系统材质后，组件的视觉效果没有发生变化，仍然呈现纯色背景或无任何材质表现。

**可能原因**

沉浸式系统材质的视觉层级位于组件的[backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)、[backgroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundblurstyle9)等属性之下。如果同时设置了不透明的背景色或背景模糊样式，这些属性会覆盖在材质层之上，导致材质效果被遮挡不可见。

**解决措施**

1. 将组件的背景色设置为透明（`Color.Transparent`）或移除背景色设置。
2. 移除[backgroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundblurstyle9)等背景模糊样式，避免模糊效果覆盖材质层。

**代码示例**

```ts
// 错误写法：不透明背景色会覆盖在材质层之上，导致材质效果不可见
Column() {
  Text('沉浸光感')
}
.width(328)
.height(56)
.borderRadius(28)
.systemMaterial(new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
}))
.backgroundColor(Color.White)

// 推荐写法：将背景色设为透明，确保材质效果可见
Column() {
  Text('沉浸光感')
}
.width(328)
.height(56)
.borderRadius(28)
.backgroundColor(Color.Transparent)
.systemMaterial(new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
}))
```

## 设置沉浸式系统材质后组件边框呈现出周围背景的颜色

**问题现象**

为组件设置沉浸式系统材质后，组件的边框区域呈现出周围背景图片或背景色的颜色，而非预期的边框效果。

**可能原因**

这是沉浸式系统材质的正常光学表现。沉浸光感视效具有折射特性，能够将组件周围的内容透过材质层折射到组件的边框区域。这种折射效果是材质通透感和层次感的重要组成部分，尤其在ULTRA_THIN和THIN等薄材质样式下表现更为明显。

**解决措施**

- 使用较厚的材质样式（如REGULAR、THICK或ULTRA_THICK），降低材质透明度以减少折射效果。
- 为材质层添加[materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)赋色，通过叠加一层半透明颜色降低折射的可见程度。

## materialColor使用透明度为0的纯色后材质效果消失

**问题现象**

为沉浸式系统材质的[materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)参数传入颜色后，组件的材质效果完全消失，仅显示纯色背景。

**可能原因**

[materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)参数的作用是为材质滤镜[materialFilter](../reference/apis-arkui/arkui-ts/ts-universal-attributes-filter-effect.md#materialfilter23)再混合一层纯色效果。该颜色需要带有一定的透明度值，如果传入纯不透明颜色（如`Color.Red`或`'#FFFF0000'`），会遮挡材质滤镜效果。

**解决措施**

为[materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)传入带有透明度的颜色值。

> **说明：**
>
> [materialColor](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)参数对所有档位的算力设备均生效。在高算力和中算力设备上，该参数为材质滤镜再混合一层纯色效果；在低算力设备上，该参数作为背景色[backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)属性值。

**代码示例**

```ts
// 错误写法：纯不透明颜色遮挡了材质效果
new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
  materialColor: Color.Red, // 不透明，材质滤镜效果被完全遮挡
})

// 推荐写法：使用带透明度的颜色
new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.THIN,
  materialColor: '#80FF0000', // 带有50%透明度的红色
})
```

## 低算力设备上沉浸光感效果与高算力设备差异较大

**问题现象**

在低算力设备上运行应用时，沉浸式系统材质的视觉效果与高算力设备相比差异较大，部分材质参数设置后没有生效。

**可能原因**

沉浸式系统材质的效果会根据设备算力档位自动适配。在高算力和中算力设备上，影响材质滤镜[materialFilter](../reference/apis-arkui/arkui-ts/ts-universal-attributes-filter-effect.md#materialfilter23)效果和阴影效果；在低算力设备上，仅影响背景色、边框颜色、边框宽度和阴影效果。此外，材质样式[style](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)和自动反色[colorInvert](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)参数仅在高算力和中算力设备上生效，在低算力设备上设置这两个参数不会产生视觉效果差异。

**解决措施**

这是系统级的自适应行为，开发者无需为不同档位设备编写差异化代码，沉浸光感会自动确保在各档位设备上的流畅运行。

## 开启自动反色后文字颜色没有变化

**问题现象**

为沉浸式系统材质开启了[colorInvert](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)自动反色功能，但组件内文字的颜色并未随背景色自动适配。

**可能原因**

自动反色功能的生效需要同时满足以下条件。

- 材质样式需要为THIN或ULTRA_THIN，在REGULAR、THICK、ULTRA_THICK样式下不生效。
- 系统沉浸光感的强弱配置影响反色触发阈值，材质越薄、系统沉浸光感设置越强，越容易触发自动反色。
- 自动反色仅对通过资源接口设置的颜色值生效，包括[Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md)组件的[fontColor](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#fontcolor)、[Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md)组件的[fontColor](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md#fontcolor)、[SymbolGlyph](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md)组件的[fontColor](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md#fontcolor)、[Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md)组件的[fillColor](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#fillcolor)、TextInput、TextArea、Chip、ChipGroup、SegmentButton、Swiper等组件的颜色属性，完整生效属性清单请参见[colorInvert](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)参数说明。使用代码中硬编码的颜色值（如`Color.White`、`'#FFFFFFFF'`）不会触发自动反色。

**解决措施**

1. 确认材质样式为THIN或ULTRA_THIN。
2. 确认文字颜色通过资源接口（如`$r('app.color.xxx')`）设置，而非硬编码颜色值。
3. 将系统沉浸光感配置调高后再观察效果。

## 同时设置shadow属性和沉浸式系统材质后阴影效果不符合预期

**问题现象**

为组件同时设置了通用属性[shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)和沉浸式系统材质后，阴影效果呈现为材质自带的阴影样式，开发者自定义的shadow参数不生效。

**可能原因**

当沉浸式系统材质的[applyShadow](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)参数为true（默认值）时，材质中的阴影效果固定生效，优先于[shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)通用属性，此时自定义的shadow设置不会生效；当该参数为false时，[shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)通用属性生效，材质的阴影效果不生效。

**解决措施**

- 如需使用材质自带的阴影效果，无需额外设置shadow属性。
- 如需使用自定义的shadow通用属性，将[applyShadow](../reference/apis-arkui/arkts-apis-uimaterial.md#immersiveoptions)设置为false。

**代码示例**

```ts
// 关闭材质阴影，使用自定义shadow
new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.REGULAR,
  applyShadow: false,
})
```

## 通过通用属性systemMaterial设置材质后组件样式显示异常

**问题现象**

通过通用属性[systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial)设置沉浸式系统材质后，组件的背景色、边框等样式显示不符合预期。

**可能原因**

通过通用属性设置材质时，如果[systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial)放在其他样式属性之前，可能导致材质效果优先级与预期不符。

**解决措施**

将[systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial)放在其他样式属性（如背景色、边框、阴影等）之后设置。通过组件options参数（如Toast的[ShowToastOptions](../reference/apis-arkui/js-apis-promptAction.md#showtoastoptions)、Popup的[PopupOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupoptions类型说明)等）设置材质时则无需关注设置顺序。

**代码示例**

```ts
// 推荐写法：先设置其他属性，再设置systemMaterial
Column() {
  Text('推荐')
}
.width(328)
.height(56)
.borderRadius(28)
.justifyContent(FlexAlign.Center)
.systemMaterial(new uiMaterial.ImmersiveMaterial({
  style: uiMaterial.ImmersiveStyle.REGULAR,
}))
```

## Dialog或Toast组件默认没有材质效果

**问题现象**

在[DEFAULT](../reference/apis-arkui/arkts-apis-uimaterial.md#materialstate)模式下，[Dialog](arkts-base-dialog-overview.md)、[Toast](arkts-create-toast.md)等组件未呈现沉浸式系统材质的视觉效果。

**可能原因**

[DEFAULT](../reference/apis-arkui/arkts-apis-uimaterial.md#materialstate)是沉浸式系统材质的默认开启模式，在该模式下，[Dialog](arkts-base-dialog-overview.md)、[Toast](arkts-create-toast.md)、[AlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md)等组件仅在未设置背景色、模糊参数和阴影参数时才会默认开启沉浸式系统材质。如果开发者主动为这些组件设置了[backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)、[backgroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundblurstyle9)或[shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)等属性，沉浸式系统材质不会默认开启。

**解决措施**

- 移除与材质冲突的属性设置（如backgroundColor、backgroundBlurStyle、shadow），让材质效果默认开启。
- 在ENABLE模式下，沉浸式系统材质样式的优先级高于组件本身设置的背景色、模糊、阴影和边框样式，且更多组件会默认开启材质。
- 如需在保留现有属性的同时使用材质，通过[systemMaterial](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#systemmaterial)属性主动设置。


## 材质渲染区域与组件可视区域不一致

**问题现象**

给组件设置沉浸式系统材质后，材质渲染区域与组件可视区域不一致。

- Checkbox可视区域为40\*40的圆形，材质渲染区域为40\*40的矩形。

  ![materialDrawingInstructions](figures/material-drawing-instruction-1.jpg)

- Text组件可视区域为文本内容，材质渲染区域为100\*40的矩形。

  ![materialDrawingInstructions](figures/material-drawing-instruction-2.jpg)

**可能原因**

材质渲染区域由组件布局区域决定，而组件可视区域为实际呈现内容，可能不等于布局区域，导致两者不一致。

**解决措施**

通过[width](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#width)、[height](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#height)、[borderRadius](../reference/apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderradius)接口控制组件可视区域与材质渲染区域一致。

> **说明：**
>
> Text组件无法给文本内容设置沉浸式系统材质。

**代码示例**

```ts
// 材质渲染区域与组件可视区域不一致示例
Row() {
  Text('Checkbox组件：')
    .fontColor(Color.Black)
  Checkbox()
    .width(40)
    .height(40)
    .borderWidth(1)
    .borderColor(Color.Blue)
    .systemMaterial(new uiMaterial.ImmersiveMaterial({
      style: uiMaterial.ImmersiveStyle.ULTRA_THIN,
      interactive: true
    }))
}
Row() {
  Text('Text组件：')
    .fontColor(Color.Black)
  Text("hello")
    .width(100)
    .height(40)
    .systemMaterial(new uiMaterial.ImmersiveMaterial({
      style: uiMaterial.ImmersiveStyle.ULTRA_THIN,
      interactive: true
    }))
}
```

## 材质效果的显示层级问题

**问题现象**

同时给组件设置沉浸式系统材质和背景色，材质效果被遮盖。例如TextArea组件设置背景色后，会遮盖材质效果。

![materialDrawingInstructions](figures/material-drawing-instruction-3.jpg)

**可能原因**

自绘制组件的背景色作用于内容层，材质效果作用于背板层，而内容层位于背板层之上，因此材质效果被内容层遮盖。

**解决措施**

不建议同时使用沉浸式系统材质和背景色[backgroundColor](../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)接口。

> **说明：**
>
> 沉浸式系统材质无法绘制在内容层。

**代码示例**

```ts
// 材质效果的显示层级问题示例
Row() {
  Text('TextArea组件：')
    .fontColor(Color.Black)
  TextArea()
    .width(100)
    .height(40)
    .backgroundColor('#cc999999') // 不建议同时使用沉浸式系统材质和背景色接口
    .systemMaterial(new uiMaterial.ImmersiveMaterial({
      style: uiMaterial.ImmersiveStyle.ULTRA_THIN,
      interactive: true
    }))
}
```