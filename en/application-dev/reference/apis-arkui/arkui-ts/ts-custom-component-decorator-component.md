# @Component: Custom Component

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=41700c3747f4915bddd30b25e8698f31797da0fb translatedAt=2026-08-11T01:45:47.516Z pushedAt=2026-08-13T06:07:28.799Z -->

The **\@Component** decorator can decorate a struct declared with the **struct** keyword. A struct decorated by **\@Component** gains componentization capabilities, enabling UI encapsulation and reuse. It is suitable for scenarios such as building reusable custom components and splitting complex UIs. The **build** method must be implemented to describe the UI. A struct can be decorated by only one **\@Component**.

For the development guide, see [Creating a Custom Component](../../../ui/state-management/arkts-create-custom-components.md).

> **NOTE**
>
> - The initial APIs of this decorator are supported since API version 7. New APIs added in later versions are marked with superscripts to indicate their starting version.
>
> - Since API version 11, **\@Component** can accept an optional parameter of the [ComponentOptions](./ts-custom-component-parameter.md#componentoptions) type.
>
> - Since API version 26.0.0, **ComponentOptions** can accept the optional parameters `reusePool` and `poolAccepts` for configuring the global reuse pool. For the development guide, see [Global Reuse: Centralized Component Recycling and Reuse](../../../ui/state-management/arkts-global-reuse-pool.md).

## @Component

const Component: ClassDecorator &amp; ((options: ComponentOptions) =&gt; ClassDecorator)

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name                  | Type    | Mandatory  | Description                                                         |
| --------------------- | ------ | ---- | ------------------------------------------------------------ |
| options<sup>11+</sup> | [ComponentOptions](./ts-custom-component-parameter.md#componentoptions) | No | Options of the **\@Component** decorator, used to configure component freezing and global reuse. You can use **freezeWhenInactive** to control component freezing (applicable to scenarios where UI refresh is frozen when components such as page routing, **TabContent**, **LazyForEach**, and **Navigation** are inactive, to reduce unnecessary refreshes and optimize performance), and use **reusePool** and **poolAccepts** to configure the global reuse pool (applicable to scenarios where multiple parent components share reusable components of the same type and need to reuse recycled instances across parent components when switching via if or other means). For details about specific attributes, see **ComponentOptions**. When not specified, component freezing and global reuse are disabled. |

**Return value**

| Type | Description |
| --- | --- |
| ClassDecorator | Class decorator. Developers do not need to pay attention to this return value. |

**Example**

```ts
@Entry
@Component({ freezeWhenInactive: true }) // Enable component freezing.
struct MyComponent {
  build() {
    Column() {
      Text('Hello World!')
    }
  }
}
```