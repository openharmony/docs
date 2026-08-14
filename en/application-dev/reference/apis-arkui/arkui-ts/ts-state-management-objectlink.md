# @ObjectLink: Observing Property Changes in Nested Class Objects

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=55c01d4f995fe537e2aa05552d0370de0b177cb4 translatedAt=2026-08-13T07:00:46.100Z pushedAt=2026-08-14T02:19:22.371Z -->

**\@ObjectLink** is used in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to receive instances of classes decorated with [@Observed](./ts-state-management-observed.md) and establish two-way data binding with the data source in the parent component. It is applicable to scenarios where nested class properties need to be observed and UI updates need to be triggered.

For details, see [@Observed and @ObjectLink Decorators: Observing Property Changes in Nested Class Objects](../../../ui/state-management/arkts-observed-and-objectlink.md).

> **NOTE**
>
> This decorator is supported since API version 7.

## @ObjectLink

const ObjectLink: PropertyDecorator

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
@Observed
class Info {
  name: string;
  constructor(name: string) {
    this.name = name;
  }
}

@Component
struct Child {
  @ObjectLink info: Info; // @ObjectLink receives the @State decorated variable of the parent component.
  build() {
    Column() {
      Text(`name: ${this.info.name}`)
    }
  }
}

@Entry
@Component
struct Index {
  @State info: Info = new Info('Tom');
  build() {
    Column() {
      Child({info: this.info}) // The @State decorated variable is used as the initial value of @ObjectLink.
    }
  }
}
```