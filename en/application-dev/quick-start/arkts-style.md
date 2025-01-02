# \@Styles Decorator: Definition of Reusable Styles


If the style of each component needs to be set separately, this will result in a large amount of repeated code during development. Though copying and pasting are available, writing code is still inefficient and error-prone. To maximize code efficiency and maintainability, the \@Styles decorator is introduced.


\@Styles helps avoid repeated style setting, by extracting multiple style settings into one method. When declaring a component, you can invoke this method and use the \@Styles decorator to quickly define and reuse the custom styles of a component.

> **NOTE**
>
> This decorator can be used in ArkTS widgets since API version 9.
>
> This decorator can be used in atomic services since API version 11.

## Rules of Use

- \@Styles supports only [universal attributes](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md) and [universal events](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md).

- \@Styles can be defined inside or outside a component declaration. When it is defined outside a component declaration, the method name must be preceded by the keyword **function**.

> **NOTE**
>
> This decorator can be used only in the current file and cannot be exported.
>
> To the export the decorator, you are advised to use [AttributeModifier](../ui/arkts-user-defined-extension-attributeModifier.md).

  ```ts
  // Global (outside a component declaration)
  @Styles function functionName() { ... }

  // Inside a component declaration
  @Component
  struct FancyUse {
    @Styles fancy() {
      .height(100)
    }
  }
  ```

To allow for cross-file operations, use the [attribute modifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md).

  ```ts
  // index.ets
  import { MyButtonModifier } from './setAttribute'

  @Entry
  @Component
  struct attributeDemo {
    @State modifier: MyButtonModifier = new MyButtonModifier()

    build() {
      Row() {
        Column() {
          Button("Button")
            .attributeModifier(this.modifier)
            .onClick(() => {
              this.modifier.isDark = !this.modifier.isDark
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

  ```ts
  // setAttribute.ets
  export class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
    isDark: boolean = false
    applyNormalAttribute(instance: ButtonAttribute): void {
      if (this.isDark) {
        instance.backgroundColor(Color.Black)
      } else {
        instance.backgroundColor(Color.Red)
      }
    }
  }
  ```

- \@Styles defined inside a component declaration can access constants and state variables of the component through **this**, and mutate the values of state variables through events in \@Styles. The following is an example:

  ```ts
  @Component
  struct FancyUse {
    @State heightValue: number = 100
    @Styles fancy() {
      .height(this.heightValue)
      .backgroundColor(Color.Yellow)
      .onClick(() => {
        this.heightValue = 200
      })
    }
  }
  ```

- The priority of \@Styles defined inside a component declaration is higher than that of \@Styles defined outside a component declaration.
  The framework preferentially searches for \@Styles within the current component.


## Constraints

- \@Styles decorated method cannot contain parameters. Otherwise, an error will be reported during compilation.

  ```ts
  // Incorrect format.
  @Styles function globalFancy (value: number) {
    .width(value)
  }

  // Correct format.
  @Styles function globalFancy () {
    .width(value)
  }
  ```


## Application Scenarios

The following example demonstrates the usage of \@Styles inside and outside a component declaration.

```ts
// Define a \@Styles decorated method outside a component declaration.
@Styles function globalFancy  () {
  .width(150)
  .height(100)
  .backgroundColor(Color.Pink)
}

@Entry
@Component
struct FancyUse {
  @State heightValue: number = 100
  // Define a \@Styles decorated method inside a component declaration.
  @Styles fancy() {
    .width(200)
    .height(this.heightValue)
    .backgroundColor(Color.Yellow)
    .onClick(() => {
      this.heightValue = 200
    })
  }

  build() {
    Column({ space: 10 }) {
      // Use the \@Styles decorated method defined outside a component declaration.
      Text('FancyA')
        .globalFancy()
        .fontSize(30)
      // Use the @Styles decorated method defined inside a component declaration.
      Text('FancyB')
        .fancy()
        .fontSize(30)
    }
  }
}
```
