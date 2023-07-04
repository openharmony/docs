# \@Styles Decorator: Definition of Resusable Styles


If the style of each component needs to be set separately, this will result in a large amount of repeated code during development. Though copy and paste is available, it is inefficient and error-prone. To maximize code efficiency and maintainability, the \@Styles decorator is introduced.


\@Styles helps avoid repeated style setting, by extracting multiple style settings into one method. When declaring a component, you can invoke this method and use the \@Styles decorator to quickly define and reuse the custom styles of a component.  


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Rules of Use

- \@Styles supports only [universal attributes](../reference/arkui-ts/ts-universal-attributes-size.md) and [universal events](../reference/arkui-ts/ts-universal-events-click.md).

- An \@Styles decorated method does not support parameters. The following example is invalid:

  ```ts
  // Invalid: @Styles does not support parameters.
  @Styles function globalFancy (value: number) {
    .width(value)
  }
  ```

- \@Styles can be defined inside or outside a component declaration. When it is defined outside a component declaration, the component name must be preceded by the keyword **function**.

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

- \@Styles defined inside a component declaration can access constants and state variables of the component through **this**, and mutate the values of state variables through events in \@Styles. The following is an example:

  ```ts
  @Component
  struct FancyUse {
    @State heightVlaue: number = 100
    @Styles fancy() {
      .height(this.heightVlaue)
      .backgroundColor(Color.Yellow)
      .onClick(() => {
        this.heightVlaue = 200
      })
    }
  }
  ```

- The priority of \@Styles defined inside a component declaration is higher than that of \@Styles defined outside a component declaration.
  The framework preferentially searches for \@Styles within the current component.


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
  @State heightVlaue: number = 100
  // Define a \@Styles decorated method inside a component declaration.
  @Styles fancy() {
    .width(200)
    .height(this.heightVlaue)
    .backgroundColor(Color.Yellow)
    .onClick(() => {
      this.heightVlaue = 200
    })
  }

  build() {
    Column({ space: 10 }) {
      // Use the \@Styles decorated method defined outside a component declaration.
      Text('FancyA')
        .globalFancy ()
        .fontSize(30)
      // Use the \@Styles decorated method defined outside a component declaration.
      Text('FancyB')
        .fancy()
        .fontSize(30)
    }
  }
}
```
