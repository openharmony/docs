# \@BuilderParam Decorator: Referencing the \@Builder Function

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0cec034ed99ae61d457e0b35e60dcf4b360705ca translatedAt=2026-08-11T01:48:46.472Z pushedAt=2026-08-13T11:06:29.957Z -->

**\@BuilderParam** is used to decorate variables that point to [\@Builder](./ts-universal-builder-dynamic.md) functions, enabling a custom component to receive externally passed **\@Builder** functions for custom rendering of UI content. It is suitable for scenarios where the parent component's UI building logic needs to be passed to a child component to achieve dynamic customization of component content.

For details, see the development guide: [\@BuilderParam Decorator: Referencing the @Builder Function](../../../ui/state-management/arkts-builderparam.md).

> **NOTE**
>
> - This decorator is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## @BuilderParam

const BuilderParam: PropertyDecorator

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Example**

```ts
@Component
struct Child {
  @Builder
  customBuilder() {
  }

  // Declare a variable pointing to an @Builder function using the @BuilderParam decorator.
  // The type is a function with no parameters and no return value, and the default value is the customBuilder inside the child component.
  @BuilderParam customBuilderParam: () => void = this.customBuilder;

  build() {
    Column() {
      // Call the builder function referenced by @BuilderParam to render the UI.
      this.customBuilderParam()
    }
  }
}

@Entry
@Component
struct Parent {
  @Builder
  componentBuilder() {
    Text(`Parent builder`)
  }

  build() {
    Column() {
      // Create the child component Child, and pass the parent component's componentBuilder to customBuilderParam.
      Child({ customBuilderParam: this.componentBuilder })
    }
  }
}
```