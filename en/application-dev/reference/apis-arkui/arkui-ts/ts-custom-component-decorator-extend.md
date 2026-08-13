# @Extend: Extended Component Styles

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4b4c3fae8bb5dd3f2fd16533483d2b6e26cbc14a translatedAt=2026-08-11T01:45:46.697Z pushedAt=2026-08-13T06:19:07.407Z -->

The **\@Extend** decorator is used to extend the styles of specified components. It supports defining multiple style attributes in a unified manner within the decorated function, and enables flexible style reuse through parameter passing. This is suitable for scenarios where the same styles need to be applied to multiple components, reducing style code duplication.

See the development guide: [\@Extend Decorator: Defining Extended Component Styles](../../../ui/state-management/arkts-extend.md).

> **NOTE**
>
> - The initial APIs of this decorator are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Extend

const Extend: MethodDecorator & ((value: any) => MethodDecorator)

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | --------- | ----------- |
| value | any | Yes | Target built-in UI component type (such as **Text** and **Column**) for which the style is to be extended. Pass in the component type rather than a component instance. Custom components are not supported. The style attributes defined in the **@Extend** decorator will be bound to this component type, so that they can be called on the component in a chained manner. |

**Return value**

| Type | Description |
| --- | --- |
| MethodDecorator | Method decorator. Developers do not need to pay attention to this return value. |

**Example**

```ts
@Extend(Text)
function fancy(fontSize: number) {
  .fontColor(Color.Red)
  .fontSize(fontSize)
}

@Entry
@Component
struct FancyUse {
  build() {
    Row({ space: 10 }) {
      Text('Fancy')
        .fancy(16)
      Text('Fancy')
        .fancy(24)
    }
  }
}
```