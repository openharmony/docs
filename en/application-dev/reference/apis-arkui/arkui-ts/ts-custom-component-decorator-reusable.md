# \@Reusable: Reusing Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @keerecles-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=76658a410ba7a85f6958029575374196cc0322a7 translatedAt=2026-08-13T11:54:14.307Z pushedAt=2026-08-13T12:16:12.064Z -->

To reduce the performance overhead caused by repeatedly creating and destroying custom components, you can use **\@Reusable** to decorate custom components decorated by **\@Component**, thereby implementing component reuse. **\@Reusable** supports identifying different types of reusable components through **reuseId**, provides the **aboutToReuse** callback to receive reuse parameters, and supports configuring memory optimization policies. This decorator is applicable to scenarios that require repeatedly creating and destroying components, such as list scrolling and frequent switching of component display and hiding.

See the development guide: [\@Reusable Decorator: Reusing V1 Components](../../../ui/state-management/arkts-reusable.md).

> **NOTE**
>
> - The initial APIs of this decorator are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Reusable

const Reusable: ClassDecorator & ((options: ReusableOptions) => ClassDecorator)

Declares a reusable custom component. This decorator must be used together with **@Component** to decorate a custom component for component reuse.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type     | Mandatory   | Description                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| options  | [ReusableOptions](./ts-custom-component-parameter.md#reusableoptions) | No    | Parameters of the reusable custom component, used to configure the memory optimization policy. If this parameter is not specified, no memory optimization policy is applied. You are advised to configure this parameter in scenarios where components are frequently created and destroyed to achieve memory optimization.<br>**Since:** 26.0.0               |

**Example**

```ts
class Message {
  value: string | undefined;

  constructor(value: string) {
    this.value = value;
  }
}

@Entry
@Component
struct Index {
  // Use @State to control the display and hiding of the child component.
  @State isChildVisible: boolean = true;

  build() {
    Column() {
      Button('Hello')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          // Click the button to toggle the child component's visibility.
          this.isChildVisible = !this.isChildVisible;
        })
      if (this.isChildVisible) {
        Child({ message: new Message('Child') })
          // Set reuseId as the component reuse identifier.
          .reuseId('Child') 
      }
    }
    .height('100%')
    .width('100%')
  }
}

// Mark the reusable component with the @Reusable decorator, used together with @Component.
@Reusable
@Component
struct Child {
  @State message: Message = new Message('AboutToReuse');

  // Callback invoked when the component is reused, receiving the passed-in parameters.
  aboutToReuse(params: Record<string, ESObject>) {
    console.info('Reuse====Child==');
    this.message = params.message as Message;
  }

  build() {
    Column() {
      Text(this.message.value)
        .fontSize(30)
    }
    .borderWidth(1)
    .height(100)
  }
}
```
<!--no_check-->