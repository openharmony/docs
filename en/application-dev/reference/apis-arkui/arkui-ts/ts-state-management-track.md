# @Track: Implementing Class Object Property-Level Updates

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:02:14.592Z pushedAt=2026-08-14T03:26:30.950Z -->

**\@Track** is used in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to implement property-level precise observation by decorating specified properties of a class object. When a property decorated with **\@Track** changes, the system updates only the UI components that depend on that property, thereby reducing unnecessary UI re-rendering. It is applicable to scenarios where a class object contains many properties and redundant UI refreshes need to be reduced to optimize rendering performance.

For details, see [@Track Decorator: Implementing Class Object Property-Level Updates](../../../ui/state-management/arkts-track.md).

> **NOTE**
>
> This decorator is supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Track

const Track: PropertyDecorator

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 11.

**Atomic service API:** This API can be used in atomic services since API version 12.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
class Info {
  // Add the observation capability for the property decorated with @Track.
  @Track id: number;
  age: string = '';

  constructor(id: number) {
    this.id = id;
  }
}

@Entry
@Component
struct Index {
  @State info: Info = new Info(1);

  build() {
    Column() {
      Text(`id: ${this.info.id}`)
      Button('change')
        .onClick(() => {
          // Modify the property decorated with @Track to trigger a UI update.
          this.info.id++;
        })
    }
  }
}
```