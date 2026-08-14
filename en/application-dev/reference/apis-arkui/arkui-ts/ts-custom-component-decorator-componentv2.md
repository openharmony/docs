# @ComponentV2: Custom Component V2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=41700c3747f4915bddd30b25e8698f31797da0fb translatedAt=2026-08-11T01:45:46.059Z pushedAt=2026-08-13T06:14:58.401Z -->

**@ComponentV2** is primarily used with state management V2. Compared with [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component), **@ComponentV2** supports deep observation and deep listening of objects. The decorator is highly easy to use and extensible, and is suitable for scenarios requiring deep observation of nested object states. Unless otherwise specified, custom components decorated with **@ComponentV2** behave the same as those decorated with **@Component**.

See the development guide: [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2).

> **NOTE**
>
> - The initial APIs of this decorator are supported since API version 12. New APIs in later versions are marked with superscripts to indicate their initial versions.
>
> - Since API version 26.0.0, the [ComponentOptions](./ts-custom-component-parameter.md#componentoptions) parameter of \@ComponentV2 supports the optional attributes `reusePool` and `poolAccepts` for configuring the global reuse pool. See the development guide: [Global Reuse: Centralized Component Recycling and Reuse](../../../ui/state-management/arkts-global-reuse-pool.md).

## @ComponentV2

const ComponentV2: ClassDecorator & ((options: ComponentOptions) => ClassDecorator)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| --------------------- | ------ | ---- | ------------------------------------------------------------ |
| options | [ComponentOptions](./ts-custom-component-parameter.md#componentoptions) | No | Options of the **\@ComponentV2** decorator. Pass this parameter for custom configuration when the component freezing or global reuse feature needs to be enabled. If not specified, both the component freezing and global reuse features are disabled. |

**Return value**

| Type | Description |
| --- | --- |
| ClassDecorator | Class decorator. Developers do not need to pay attention to this return value. |

**Example**

```ts
@Entry
@ComponentV2({ freezeWhenInactive: true }) // Enable the component freezing feature.
struct MyComponent {
  build() {
    Column() {
      Text('Hello World!')
    }
  }
}
```