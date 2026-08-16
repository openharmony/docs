# @LocalBuilder Decorator: Maintaining Component Relationships

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=eaa1050c193614ed00ddfb68fb34bd4b5be86d8f translatedAt=2026-08-11T01:48:44.301Z pushedAt=2026-08-13T11:19:19.410Z -->

**@LocalBuilder** provides the same functionality as the local [@Builder](./ts-universal-builder-dynamic.md), and can better determine the parent-child relationships of components and state management than the local `@Builder`. For the development guide, see [@LocalBuilder Decorator: Maintaining Component Relationships](../../../ui/state-management/arkts-localBuilder.md).

> **NOTE**
>
> - The initial APIs of this decorator are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @LocalBuilder

const LocalBuilder: MethodDecorator

**Model restriction:** This API can be used only in the stage model.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
class ReferenceType {
  paramString: string = '';
}

@Entry
@Component
struct Parent {
  @State variableValue: string = 'Hello World';

  // Use the @LocalBuilder decorator to define a builder function, maintaining the parent-child relationship of components and state management.
  // Pass reference type parameters to listen for changes to state variables.
  @LocalBuilder
  citeLocalBuilder(params: ReferenceType) {
    Row() {
      Text(`UseStateVarByReference: ${params.paramString}`)
    }
  }

  build() {
    Column() {
      // Call the builder function defined by @LocalBuilder, and pass in reference type parameters that contain state variables.
      this.citeLocalBuilder({ paramString: this.variableValue })
      Button('Click me')
        .onClick(() => {
          // After clicking, the state variable is modified and the UI automatically refreshes.
          this.variableValue = 'Hi World';
        })
    }
  }
} 
```