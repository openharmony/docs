# @Computed: Declaring Computed Properties

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:00:20.054Z pushedAt=2026-08-14T01:44:33.668Z -->

**@Computed** is a method decorator used in [State Management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to decorate a **getter** method, turning it into a computed property. Its return value is cached and recalculated only when the dependent source data changes, reducing the overhead of repeated computation.

For details, see [@Computed Decorator: Declaring Computed Properties](../../../ui/state-management/arkts-new-computed.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Computed

const Computed: MethodDecorator

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
@Entry
@ComponentV2
struct Index {
  @Local firstName: string = 'Hua';
  @Local lastName: string = 'Li';

  // Declare the computed getter function to avoid repeated calculation.
  @Computed
  get fullName() {
    return this.firstName + ' ' + this.lastName;
  }

  build() {
    Column() {
      Text(`${this.fullName}`)
    }
  }
}
```