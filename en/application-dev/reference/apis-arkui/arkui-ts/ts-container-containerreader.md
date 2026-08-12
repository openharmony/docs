# ContainerReader

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @song-song-song-->
<!--Designer: @fenglinbailu-->
<!--Tester: @weixin_45530366-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=fd10fbb9e5b5e2e1e561a46b9ca4925a29d1a0a3 translatedAt=2026-06-30T12:26:33.742Z pushedAt=2026-07-02T09:00:10.666Z -->

**ContainerReader** is a container breakpoint component used to obtain breakpoint information based on container size in dynamic scenarios and perform responsive layout. This component returns the container's size and breakpoint in real time through [two-way binding](../../../ui/state-management/arkts-new-binding.md#two-way-binding-between-built-in-component-parameters), enabling you to create and lay out components based on container size.

> **NOTE**
>
> - To use **ContainerReader**, the parent component of **ContainerReader** should not rely on its child components to determine its own size.
> - Container breakpoints determine height and width breakpoint values based on the component's own actual size and breakpoint threshold array. The component size and breakpoint information only apply to the current component and its child components. Multiple containers on the same page can have their own independent breakpoint states.
> - The size of the **ContainerReader** component is determined by its parent container and its own layout, and is not affected by its child components. Layout specifications under different parent containers: when the parent container is [Flex](ts-container-flex.md), [Column](ts-container-column.md), or [Row](ts-container-row.md), the remaining space of **ContainerReader** is filled; when the parent container is of other types, the parent container is filled.
> - The parameters of the **ContainerReader** API must use state variables combined with the two-way binding ([!! syntax](../../../ui/state-management/arkts-new-binding.md)) so that the frontend is promptly notified to refresh the UI when the backend calculates size changes.
> - For more development guidance and complete examples on container breakpoints, see [Container Breakpoint (ContainerReader)](../../../ui/arkts-layout-development-container-reader.md).

**Since:** 26.0.0

## Child Components

Supported

## APIs

### ContainerReader

ContainerReader(value: ContainerReaderInfo)

Creates a **ContainerReader** component and configures container reader parameters.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| value | [ContainerReaderInfo](#containerreaderinfo) | Yes | Container reader configuration options, including size data and breakpoint configuration. |

## ContainerReaderInfo

Defines the configuration options for the **ContainerReader** component, used to specify parameters for reading container size and obtaining breakpoint values. The component size and breakpoint values cannot be changed through this parameter.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| size | [Size](../js-apis-arkui-graphics.md#size) | No | No | Size of the **ContainerReader** component, used for layout analysis and breakpoint calculation.<br/>Note:<br/>This parameter supports two-way binding through [!!](../../../ui/state-management/arkts-new-binding.md#two-way-binding-between-built-in-component-parameters). After binding, when the component size value changes, the bound variable of **size** automatically updates. |
| widthBreakpoint | [WidthBreakpoint](./ts-appendix-enums.md#widthbreakpoint13) | No | Yes | Width breakpoint of the container, which is the obtained width breakpoint enum value of the **ContainerReader** component.<br/>Note:<br/>This parameter supports two-way binding through [!!](../../../ui/state-management/arkts-new-binding.md#two-way-binding-between-built-in-component-parameters). After binding, when the component width breakpoint value changes, the bound variable of **widthBreakpoint** automatically updates. |
| heightBreakpoint | [HeightBreakpoint](./ts-appendix-enums.md#heightbreakpoint13) | No | Yes | Height breakpoint of the container, which is the height breakpoint enum value of the **ContainerReader** component under different aspect ratio thresholds.<br/>Note<br/>This parameter supports two-way binding through [!!](../../../ui/state-management/arkts-new-binding.md#two-way-binding-between-built-in-component-parameters). After binding, when the component height breakpoint value changes, the bound variable of **heightBreakpoint** automatically updates. |

## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported:

### breakpointConfig

breakpointConfig(value?: BreakpointOptions)

Sets the breakpoint configuration options, defining the size thresholds that trigger different layout behaviors.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| value | [BreakpointOptions](#breakpointoptions) | No | Breakpoint configuration options, containing arrays of width and height breakpoint thresholds. |

## BreakpointOptions

Defines the breakpoint configuration options, which are used to specify threshold parameters for container size analysis.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| width | Array\<number\> | No | Yes | Array of width breakpoint values. The array must be monotonically increasing.<br/>Default value: **[320, 600, 840, 1440]**, in vp, consistent with the default window width breakpoints.<br/>Note:<br/>A maximum of 5 breakpoints are supported, meaning the maximum array length is 4. |
| height | Array\<number\> | No | Yes | Array of height breakpoint values. The height breakpoint value is the ratio of the component's height to its width. No unit. The array must be monotonically increasing.<br/>Default value: **[0.8, 1.2]**, consistent with the default window height breakpoints.<br/>Note:<br/>A maximum of 3 breakpoints are supported, meaning the maximum array length is 2. |

## Events

[Universal events](ts-component-general-events.md) are supported.

## Example

### Example 1: Switching Layout Direction Based on ContainerReader Width Breakpoint)

This example demonstrates how the [ContainerReader](#containerreader-1) component obtains container size and breakpoint information through two-way binding, and switches the layout direction based on the width breakpoint.

The **ContainerReader** component is added since API version 26.0.0.

> **NOTE**
>
> To use **ContainerReader**, you need to import **ContainerReaderAttribute** at the same time, otherwise it will cause a compilation error.

```ts
// xxx.ets
import { ContainerReader, ContainerReaderAttribute, Size } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State containerSize: Size = { width: 0, height: 0 };
  @State widthBp: WidthBreakpoint = WidthBreakpoint.WIDTH_XS;
  @State heightBp: HeightBreakpoint = HeightBreakpoint.HEIGHT_SM;
  @State columnWidth: number = 180

  build() {
    Column({space: 10}) {
      Column({space: 10}) {
        ContainerReader({
          size: this.containerSize!!, // Bind to the this.containerSize variable. When the ContainerReader size changes, this.containerSize is automatically updated.
          widthBreakpoint: this.widthBp!!,
          heightBreakpoint: this.heightBp!!
        }) {
          // Switch layout direction based on the width breakpoint
          if (this.widthBp === WidthBreakpoint.WIDTH_XS) {
            Column({space: 20}) {
              Text('Vertical layout')
              Text(`Column`)
            }
            .width('100%')
            .height('100%')
            .backgroundColor('#D5D5D5')
            .justifyContent(FlexAlign.Center)
          } else {
            Row({space: 20}) {
              Text('Horizontal layout')
              Text(`Row`)
            }
            .width('100%')
            .height('100%')
            .backgroundColor('#2787D9')
            .justifyContent(FlexAlign.Center)
          }
        }
        .backgroundColor('#F0FAFF')
      }
      .height('20%')
      .width(this.columnWidth)
      Button('Change column width')
        .onClick(()=>{
          if (this.columnWidth == 180) {
            this.columnWidth = 320;
          } else {
            this.columnWidth = 180;
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

![](figures/containerReader_Demo001.gif)

### Example 2: Configuring Custom Breakpoints

This example demonstrates how to customize breakpoint thresholds via [breakpointConfig](#breakpointconfig) to define various wide and narrow layout sizes, enabling more refined layout control.

The **ContainerReader** component and the **breakpointConfig** API are added since API version 26.0.0.

> **NOTE**
>
> To use **ContainerReader**, you need to import **ContainerReaderAttribute** at the same time, otherwise a compilation error will occur.

```ts
// xxx.ets
import { ContainerReader, ContainerReaderAttribute, Size } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State containerSize: Size = { width: 0, height: 0 };
  @State widthBp: WidthBreakpoint = WidthBreakpoint.WIDTH_XS;
  @State heightBp: HeightBreakpoint = HeightBreakpoint.HEIGHT_SM;
  @State columnWidth: number = 180

  build() {
    Column({space: 10}) {
      Column({space: 10}) {
        ContainerReader({
          size: this.containerSize!!,
          widthBreakpoint: this.widthBp!!,
          heightBreakpoint: this.heightBp!!
        }) {
          if (this.widthBp === WidthBreakpoint.WIDTH_XS || this.widthBp === WidthBreakpoint.WIDTH_SM) {
            Column({space: 10}) {
              Text('Narrow screen layout')
                .fontSize(16)
              Text(`Width breakpoint: ${this.widthBp}`)
            }
            .width('100%')
            .height('100%')
            .backgroundColor('#D5D5D5')
            .justifyContent(FlexAlign.Center)
          } else {
            Row({space: 10}) {
              Text('Wide screen layout')
                .fontSize(16)
              Text(`Width breakpoint: ${this.widthBp}`)
            }
            .width('100%')
            .height('100%')
            .backgroundColor('#2787D9')
            .justifyContent(FlexAlign.Center)
          }
        }
        .height(100)
        .width('100%')
        .backgroundColor('#F0FAFF')
        .breakpointConfig({ width: [100, 200, 400, 500], height: [0.8, 1.2] })
      }
      .height('20%')
      .width(this.columnWidth)

      Button('Change column width')
        .onClick(()=>{
          if (this.columnWidth == 180) {
            this.columnWidth = 320;
          } else {
            this.columnWidth = 180;
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

Tap the button to change the width of the parent container, which returns different width breakpoint values, thereby adjusting the layout direction.

![](figures/containerReader_Demo002.gif)

### Example 3: Dynamically Adjusting the Number of Columns Using the Width Breakpoint

This example demonstrates how to dynamically adjust the number of columns based on the width breakpoint obtained from **ContainerReader**, enabling adaptive layouts across multiple devices with varying column counts for different breakpoints.

The **ContainerReader** component is added since API version 26.0.0.

> **NOTE**
>
> To use **ContainerReader**, you need to import **ContainerReaderAttribute** at the same time, otherwise a compilation error will occur.

```ts
// xxx.ets
import { ContainerReader, ContainerReaderAttribute, Size } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State containerSize: Size = { width: 0, height: 0 };
  @State widthBp: WidthBreakpoint = WidthBreakpoint.WIDTH_XS;
  @State columnWidth: number = 180

  build() {
    Column({space: 10}) {
      Column({space: 10}) {
        ContainerReader({
          size: this.containerSize!!,
          widthBreakpoint: this.widthBp!!
        }) {
          Row({ space: 2 }) {
            if (this.widthBp === WidthBreakpoint.WIDTH_XS || this.widthBp === WidthBreakpoint.WIDTH_SM) {
              Column() {
                Text(`Column 1`)
                  .fontColor(Color.White)
              }
              .width('100%')
              .height(60)
              .backgroundColor('#D5D5D5')
              .justifyContent(FlexAlign.Center)
              .borderRadius(8)
              .layoutWeight(1)
            } else {
              Column() {
                Text(`Column 1`)
                  .fontColor(Color.White)
              }
              .width('100%')
              .height(60)
              .backgroundColor('#D5D5D5')
              .justifyContent(FlexAlign.Center)
              .borderRadius(8)
              .layoutWeight(1)
              Column() {
                Text(`Column 2`)
                  .fontColor(Color.White)
              }
              .width('100%')
              .height(60)
              .backgroundColor('#707070')
              .justifyContent(FlexAlign.Center)
              .borderRadius(8)
              .layoutWeight(1)
            }
          }
          .width('100%')
          .height('100%')
        }
        .breakpointConfig({ width: [100, 200, 400, 500] })
        .backgroundColor('#F0FAFF')
      }
      .height('20%')
      .width(this.columnWidth)

      Button('Change column width')
        .onClick(()=>{
          if (this.columnWidth == 180) {
            this.columnWidth = 320;
          } else {
            this.columnWidth = 180;
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

![](figures/containerReader_Demo003.gif)
<!--no_check-->