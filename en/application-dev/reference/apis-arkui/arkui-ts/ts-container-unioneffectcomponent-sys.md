# UnionEffectContainer (System API)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

**UnionEffectContainer** collects shapes of all descendant components [using the ancestor union effect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect) within the container, and applies the shapes to the container as its drawing shape.

>  **NOTE**
>
> - This component is supported since API version 23. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
> 
> - You can add animations to the shape union process.

## Child Components

Child components are supported.

## APIs

### UnionEffectContainer

UnionEffectContainer(options?: UnionEffectContainerOptions)

Creates a **UnionEffectContainer** component.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name           | Type       | Mandatory  | Description                                    |
| -------------- | ---------------------------------------- | ---- |  ---------------------------------------- |
| options      | [UnionEffectContainerOptions](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)| No   |  Construction options of **UnionEffectContainer**, which is used to determine the union degree of the collected descendant component shapes.<br>Default value: **{spacing:0}**              |

## UnionEffectContainerOptions

Sets the construction options of **UnionEffectContainer**.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                                   | Read-Only| Optional| Description                                                    |
| ----------- | --------------------------------------- | ---- | ---------- | ---------------------------------------------- |
| spacing | number | No| Yes | Degree of union deformation of the descendant component. This parameter does not represent the actual spacing. Union occurs only when the descendant components use the union effect of the ancestor component **UnionEffectContainer** and they come close to a certain extent.<br>**NOTE**<br>If **spacing** is greater than 0 and the descendant components that use the union effect of the ancestor component **UnionEffectContainer** come close to a certain extent, the descendant components start to deform due to union. The closer the descendant components are, the stronger the deformation effect. A larger value indicates that the union of descendant components starts earlier and is more likely to occur when the descendant components come close to each other.<br>Default value: **0**. In this case, union of the child component shapes occurs, but no deformation effect is generated.<br>Value range: [0, +∞). If the value is less than 0, **0** is used.|

## Events

Universal events are supported.

## Attributes

Universal attributes are supported. The width and height can be set.

> **NOTE**
>
> - During the union, the container exhibit a sticky non-linear deformation effect, and its border will show a sticky effect after union. Therefore, border-related capabilities will be affected. Currently, the following border-related attributes support the union deformation effect: [border](ts-universal-attributes-border.md#border), [outline](ts-universal-attributes-outline.md#outline), [shadow](ts-universal-attributes-image-effect.md#shadow), [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), and [pointLight](#pointlight). The above effects are drawn on the shape after union, which is the drawing part of **UnionEffectContainer**.
>
> - If the attributes related to the border and supporting the union deformation effect are set on the component, the drawing is displayed on the component. If the same attribute is set on the descendant component, the two attributes are set independently. The drawing is performed twice, once in the drawing of the **UnionEffectContainer** component and once in the drawing of the descendant component. Generally, you do not need to set the same attribute that supports the union deformation effect on the descendant component that uses the union effect of the ancestor component **UnionEffectContainer**. This prevents the deterioration of the union effect.

### pointLight

pointLight(value: PointLightStyle)

Sets the point light style.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description        |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | Yes  | Point light style.|

### unionMode

unionMode(mode: UnionMode)

Sets the union mode.

**Since**: 26.0.0

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description        |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| mode  | [UnionMode](#unionmode)| Yes  | Union mode.|

## UnionMode

Enumerates the union modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API.

| Name          | Value | Description                        |
| -------------- | --- |---------------------------- |
| SMOOTH_UNION       | 0   | Smooth union mode.           |
| GRAVITY_UNION      | 1   | Gravity union mode.<br>**NOTE**<br>This mode takes effect only when [useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect-1) is used and **gravityCenter** of [GravityCenterOptions](ts-universal-attributes-use-union-effect-sys.md#gravitycenteroptions) is set to **true**.           |

## Example

### Example 1 (Setting the Union Effect)

This example demonstrates how to use the [UnionEffectContainer](#unioneffectcontainer) component to generate a union deformation effect by changing the **spacing** value or the spacing between descendant components.

```ts
//UnionEffectContainerPage.ets
@Entry
@Component
struct UnionEffectContainerPage {
  @State spacing: number = 0;
  @State translateY: number = 0;

  build() {
    Column() {
      Column() {
        UnionEffectContainer({ spacing: 10 }) {
          Column({ space: 50 }) {
            Column()
              .width(100)
              .height(100)
              .margin({ top: 10 })
              .borderRadius(50)
              .useUnionEffect(true)// Set the useUnionEffect attribute to use the union effect.
              .translate({ y: this.translateY })

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('80%')
        .backgroundColor("#2787d9") // Set the attributes supported by the union effect, such as the background color.

        Row({ space: 30 }) {
          Text("translate:")
          Button('+10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY += 10; // Change the spacing between the descendant components.
              });
            })
          Button('-10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY -= 10; // Change the spacing between the descendant components.
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('40%')
      .borderWidth(1)
      .margin({ top: 10 })

      Column() {
        UnionEffectContainer({ spacing: this.spacing }) {
          Column({ space: 50 }) {
            Column()
              .width(100)
              .height(100)
              .margin({ top: 10 })
              .borderRadius(50)
              .useUnionEffect(true) // Set the useUnionEffect attribute to use the union effect.

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('80%')
        .backgroundColor("#2787d9") // Set the attributes supported by the union effect, such as the background color.

        Row({ space: 30 }) {
          Text("spacing:")
          Button('+20')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.spacing += 20; // Change the spacing of the descendant components.
              });
            })
          Button('-20')
            .onClick(() => {
              if (this.spacing <= 0 && this.spacing - 20 < 0) {
                return;
              }
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.spacing -= 20; // Change the spacing of the descendant components.
                if (this.spacing < 0) {
                  this.spacing = 0;
                }
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('40%')
      .borderWidth(1)
      .margin({ top: 10 })
    }.width('100%')
    .height('100%')
  }
}
```

### Example 2 (Setting Different Union Modes)

This example demonstrates how to use the [unionMode](#unionmode) API to set different union modes to generate different union deformation effects.

The **unionMode** API is supported since API version 26.0.0.

```ts
// UnionEffectContainerPage.ets
@Entry
@Component
struct UnionEffectContainerPage {
  @State translateY1: number = 0;
  @State translateY2: number = 0;

  build() {
    Column() {
      Column() {
        Text("UnionMode.SMOOTH_UNION")
        UnionEffectContainer({ spacing: 10 }) {
          Column({ space: 50 }) {
            Column()
              .width(100)
              .height(100)
              .margin({ top: 10 })
              .borderRadius(50)
              .useUnionEffect(true)// Set the useUnionEffect attribute to use the union effect.
              .translate({ y: this.translateY1 })

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('75%')
        .backgroundColor("#2787d9") // Set the attributes supported by the union effect, such as the background color.
        .unionMode(UnionMode.SMOOTH_UNION)

        Row({ space: 30 }) {
          Text("translate:")
          Button('+10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY1 += 10; // Change the distance between adjacent components.
              });
            })
          Button('-10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY1 -= 10; // Change the distance between adjacent components.
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('45%')
      .borderWidth(1)
      .margin({ top: 10 })

      Column() {
        Text("UnionMode.GRAVITY_UNION")
        UnionEffectContainer({ spacing: 1000 }) {
          Column({ space: 50 }) {
            Column()
              .width(40)
              .height(40)
              .margin({ top: 10 })
              .borderRadius(20)
              .useUnionEffect(true, {gravityCenter: true, gravityIntensity: 60})// Set the useUnionEffect attribute to use the union effect.
              .translate({ y: this.translateY2 })

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('75%')
        .backgroundColor("#2787d9") // Set the attributes supported by the union effect, such as the background color.
        .unionMode(UnionMode.GRAVITY_UNION)

        Row({ space: 30 }) {
          Text("translate:")
          Button('+10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY2 += 10; // Change the distance between adjacent components.
              });
            })
          Button('-10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY2 -= 10; // Change the distance between adjacent components.
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('45%')
      .borderWidth(1)
      .margin({ top: 10 })
    }.width('100%')
    .height('100%')
  }
}
```
