# Basic UI Description

In ArkTS, you define a custom component by using decorators **@Component** and **@Entry** to decorate a data structure declared with the **struct** keyword. A custom component provides a **build** function, where you must write the basic UI description in chain call mode. For details about the UI description, see [UI Description Specifications](#ui-description-specifications).

## Basic Concepts

- struct: a data structure that can be used to implement custom components and cannot have inheritance. The **new** keyword can be omitted when initializing a struct.

- Decorator: a special type of declaration that can be applied to classes, structures, or class attributes to add new functionality to them. Multiple decorators can be applied to the same target element and defined on a single line or multiple lines. It is recommended that the decorators be defined on multiple lines.

  ```ts
  @Entry
  @Component
  struct MyComponent {
  }
  ```

- **build** function: a function that complies with the **Builder** API definition and is used to define the declarative UI description of components. A **build** function must be defined for custom components, and custom constructors are prohibited for custom components.

  ```ts
  interface Builder {
      build: () => void
  }
  ```

- **@Component**: a decorator applied to a struct to equip it with the component-based capability. The **build** method must be implemented for UI creation.

- **@Entry**: a decorator applied to a struct to make it the entry to a page, which is rendered and displayed when the page is loaded.

- **@Preview**: a decorator applied to struct to make it previewable in the DevEco Studio Previewer. The decorated component is created and displayed when the residing page is loaded.

  > **NOTE**
  >
  > In a single source file, you can use up to 10 **@Preview** decorators to decorate custom components. For details, see [Previewing ArkTS Components](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-previewing-app-service-0000001218760596#section146052489820).

- Chain call: a syntax for configuring the attribute methods, event methods, and more of UI components by using the dot notation.

## UI Description Specifications

### Structs Without Parameters

A struct without parameters is a component whose API definition has empty parentheses. No parameter needs to be passed to this type of component, for example, the **Divider** component in the following snippet:

```ts
Column() {
    Text('item 1')
    Divider()
    Text('item 2')
}
```

### Structs with Mandatory Parameters

A struct with mandatory parameters is a component whose API definition expects parameters enclosed in the parentheses. You can use constants to assign values to the parameters.

Sample code:

- Set the mandatory parameter **src** of the **\<Image>** component as follows:

  ```ts
  Image('https://xyz/test.jpg')
  ```

- Set the mandatory parameter **content** of the **\<Text>** component as follows:

  ```ts
  Text('test')
  ```

You can use variables or expressions to assign values to parameters. The result type returned by an expression must meet the parameter type requirements. For details about the variables, see [State Management with Page-level Variables](arkts-state-mgmt-page-level.md) and [State Management with Application-level Variables](arkts-state-mgmt-application-level.md). For example, set a variable or expression to construct the **\<Image>** and **\<Text>** components:

```ts
Image(this.imagePath)
Image('https://' + this.imageUrl)
Text(`count: ${this.count}`)
```

### Attribute Configuration

Component attributes are configured using an attribute method, which follows the corresponding component and is bound to the component using the "**.**" operator.

- Example of configuring the font size attribute of the **\<Text>** component:

  ```ts
  Text('test')
      .fontSize(12)
  ```

- Example of configuring multiple attributes at the same time by using the "**.**" operator to implement chain call:

  ```ts
  Image('test.jpg')
      .alt('error.jpg')    
      .width(100)    
      .height(100)
  ```

- Example of passing variables or expressions in addition to constants:

  ```ts
  Text('hello')
      .fontSize(this.size)
  Image('test.jpg')
      .width(this.count % 2 === 0 ? 100 : 200)    
      .height(this.offset + 100)
  ```

-  For attributes of built-in components, ArkUI also provides some predefined [enumeration types](../reference/arkui-ts/ts-appendix-enums.md), which you can pass as parameters to methods if they meet the parameter type requirements. For example, you can configure the font color and weight attributes of the **\<Text>** component as follows:

  ```ts
  Text('hello')
      .fontSize(20)
      .fontColor(Color.Red)
      .fontWeight(FontWeight.Bold)
  ```

### Event Configuration

Events supported by components are configured using event methods, which each follow the corresponding component and are bound to the component using the "**.**" operator.

- Example of using a lambda expression to configure the event of a component:

  ```ts
  Button('add counter')
      .onClick(() => {
          this.counter += 2
      })
  ```

- Example of using an anonymous function expression to configure the event of a component (**bind** must be used to ensure that the contained components are referenced by **this** in the function body):

  ```ts
  Button('add counter')
      .onClick(function () {
          this.counter += 2
      }.bind(this))
  ```

- Example of using a component's member function to configure the event of the component:

  ```ts
  myClickHandler(): void {
    this.counter += 2
  }
  
  ...

  Button('add counter')
    .onClick(this.myClickHandler)
  ```

### Child Component Configuration

For a component that supports child components, for example, a container component, add the UI descriptions of the child components inside parentheses. The **\<Column>**, **\<Row>**, **\<Stack>**, **\<Grid>**, and **\<List>** components are all container components.

- Simple example of the **\<Column>** component:

  ```ts
  Column() {
      Text('Hello')
          .fontSize(100)
      Divider()
      Text(this.myText)
          .fontSize(100)
          .fontColor(Color.Red)
  }
  ```

- Example of nesting multiple child components in the **\<Column>** component:

  ```ts
  Column() {
    Row() {
      Image('test1.jpg')
        .width(100)
        .height(100)
      Button('click +1')
        .onClick(() => {
          console.info('+1 clicked!')
        })
    }

    Divider()
    Row() {
      Image('test2.jpg')
        .width(100)
        .height(100)
      Button('click +2')
        .onClick(() => {
          console.info('+2 clicked!')
        })
    }

    Divider()
    Row() {
      Image('test3.jpg')
        .width(100)
        .height(100)
      Button('click +3')
        .onClick(() => {
          console.info('+3 clicked!')
        })
    }
  }
  ```
