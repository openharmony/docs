# Event Configuration

You can use event methods to configure events supported by components. Since API version 9, you can obtain the context associated with the current component from the callback. For details, see [Obtaining the Context on an eTS Page](../ability/context-userguide.md).


- Example of using a lambda expression to configure the event of a component:
  ```ts
  // Counter is a private data variable defined in the component.
  Button('add counter')
      .onClick(() => {
          this.counter += 2
      })
  ```


- When using an anonymous function expression to configure the event of a component, **bind** must be used to ensure that the contained components are referenced by **this** in the function body.
  ```ts
  // Counter is a private data variable defined in the component.
  Button('add counter')
      .onClick(function () {
          this.counter += 2
      }.bind(this))
  ```


- Example of using a component's member function to configure the event of the component:
  ```ts
  myClickHandler(): void {
      // do something
  }

  ...

  Button('add counter')
    .onClick(this.myClickHandler)
  ```
