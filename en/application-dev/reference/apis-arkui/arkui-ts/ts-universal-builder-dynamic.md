# \@Builder Decorator: Custom Builder Function

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0cec034ed99ae61d457e0b35e60dcf4b360705ca translatedAt=2026-08-11T01:48:33.019Z pushedAt=2026-08-13T11:01:04.611Z -->

Functions decorated with **\@Builder** are also known as custom builder functions. They are used to encapsulate reusable UI building logic and can be called multiple times within a custom component, thereby reducing code duplication and improving the maintainability of UI building. It is suitable for scenarios where the same UI structure needs to be reused.

For details about the development guide, see [@Builder Decorator: Custom Builder Function](../../../ui/state-management/arkts-builder.md).

> **NOTE**
>
> - This decorator is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## @Builder

const Builder: MethodDecorator

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Example**

```ts
@Entry
@Component
struct BuilderDemo {
  // Decorate this function with @Builder to make it a custom builder function for configuring and building the Text component.
  @Builder
  showTextBuilder() {
    Text('Hello World')
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }

  @Builder
  showTextValueBuilder(param: string) {
    Text(param)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }

  build() {
    Column() {
      // No parameter.
      this.showTextBuilder()
      // With parameter.
      this.showTextValueBuilder('Hello @Builder')
    }
  }
}
```