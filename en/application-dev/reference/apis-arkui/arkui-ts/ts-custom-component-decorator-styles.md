# @Styles: Component Reuse Styles

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @VictorS67-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4b4c3fae8bb5dd3f2fd16533483d2b6e26cbc14a translatedAt=2026-08-11T01:46:17.741Z pushedAt=2026-08-13T06:38:06.243Z -->

The **\@Styles** decorator is used to extract multiple style settings into a method, which can be directly called at the component declaration site to define and reuse custom styles. It is suitable for scenarios where multiple components need to share the same styles, reducing repetitive code and improving the efficiency of maintaining style consistency.

For details about development guide, see [\@Styles Decorator: Defining Reusable Component Styles](../../../ui/state-management/arkts-style.md).

> **NOTE**
>
> - The initial APIs of this decorator are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Styles

const Styles: MethodDecorator

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
@Entry
@Component
struct FancyUse {
  @State heightValue: number = 50;

  // Use the @Styles decorator to define a reusable style method.
  @Styles
  fancy() {
    .height(this.heightValue)
    .backgroundColor(Color.Blue)
    .onClick(() => {
      this.heightValue = 100;
    })
  }

  build() {
    Column() {
      Button('change height')
        // Call the fancy style method defined by @Styles to apply the reusable style.
        .fancy()
    }
    .height('100%')
    .width('100%')
  }
}
```