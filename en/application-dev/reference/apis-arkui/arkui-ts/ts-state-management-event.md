# @Event: Standardizing Component Output

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:00:18.903Z pushedAt=2026-08-14T01:46:15.072Z -->

**\@Event** decorates a callback function, which is used as the output of a custom component in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). **\@Event** is usually used together with [@Param](./ts-state-management-param.md). **\@Param** transfers data from a parent component to its child component. **\@Event** defines the callback for the child component to transfer messages to the parent component, which is applicable to scenarios where the parent component state change or event processing needs to be triggered in the child component.

For details, see [@Event Decorator: Standardizing Component Output](../../../ui/state-management/arkts-new-event.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Event

const Event: PropertyDecorator

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
@Entry
@ComponentV2
struct Index {
  @Local name: string = 'Tom';

  build() {
    Column() {
      Child({
        name: this.name,
        changeFactory: (type: number) => {
          // @Event decorated function, which is used to modify the state variable in the parent component during implementation.
          if (type == 1) {
            this.name = 'Tom';
          } else if (type == 2) {
            this.name = 'Jerry';
          }
        }
      })
    }
  }
}

@ComponentV2
struct Child {
  @Param name: string = '';
  // @Event decorated function, which is used to pass messages to the parent component.
  @Event changeFactory: (type: number) => void = (type: number) => {};

  build() {
    Column() {
      Text(`name: ${this.name}`)
      Button('change to Tom')
        .onClick(() => {
          this.changeFactory(1);
        })
      Button('change to Jerry')
        .onClick(() => {
          this.changeFactory(2);
        })
    }
  }
}
```