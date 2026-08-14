# @ReusableV2: Component Reuse V2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=bbb682e63876992d34ec9fd16b00a36fec86c65e translatedAt=2026-08-11T01:46:23.242Z pushedAt=2026-08-13T06:34:14.051Z -->

To reduce the performance overhead caused by repeatedly creating and destroying custom components, developers can use the **\@ReusableV2** decorator on custom components decorated by [\@ComponentV2](./ts-custom-component-decorator-componentv2.md#componentv2) to achieve component reuse. This is applicable to scenarios where components need to be repeatedly created and destroyed, such as list scrolling and frequent toggling of component visibility, and supports configuring memory optimization strategies through parameters.

See the development guide: [\@ReusableV2 Decorator: Reusing V2 Components](../../../ui/state-management/arkts-new-reusableV2.md).

For the principles and applicable scenarios of component reuse, see [Component Reuse](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-component-reuse).

> **NOTE**
>
> The initial APIs of this decorator are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @ReusableV2

const ReusableV2: ClassDecorator & ((options: ReusableOptions) => ClassDecorator)

Declares a reusable custom component. This decorator must be used together with **@ComponentV2** to decorate a custom component for component reuse.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type     | Mandatory   | Description                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| options  | [ReusableOptions](./ts-custom-component-parameter.md#reusableoptions) | No    | Configuration parameters of the reusable custom component, used to configure the memory optimization policy. This parameter can be configured for optimization in scenarios where a large number of reusable components exist (for example, dozens or more reusable component instances on the same page), or when the device memory is limited and the app memory usage is high. No memory optimization policy is applied by default.<br>**Since:** 26.0.0               |

**Return value**

| Type | Description |
| ---- | ---- |
| ClassDecorator | Class decorator. You do not need to pay attention to this return value. |

**Example**

```ts
@ObservedV2
class Info {
  @Trace age: number;

  constructor(age: number) {
    this.age = age;
  }
}

@Entry
@ComponentV2
struct Index {
  // Use @Local to control the display and hiding of child components.
  @Local condition: boolean = true;

  build() {
    Column() {
      Button('Reuse')
        .onClick(() => {
          // Toggle the display state of the child component by clicking the button.
          this.condition = !this.condition;
        })
      if (this.condition) {
        ReusableV2Component()
      }
    }
  }
}

// Use the @ReusableV2 decorator to mark a reusable component, used together with @ComponentV2.
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  noDecoratorInfo: Info = new Info(30);

  @Monitor('noDecoratorInfo.age')
  onAgeChange(monitor: IMonitor) {
    console.info(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  // Callback invoked when the component is recycled.
  aboutToRecycle() {
    this.noDecoratorInfo.age = 25;
  }

  // Callback invoked when the component is reused.
  aboutToReuse() {
    this.noDecoratorInfo.age = 35;
  }

  build() {
    Column() {
      Text(`noDecoratorInfo.age: ${this.noDecoratorInfo.age}`)
        .onClick(() => {
          // Trigger a refresh but will not be reset.
          this.noDecoratorInfo.age++;
        })
    }
  }
}
```
<!--no_check-->