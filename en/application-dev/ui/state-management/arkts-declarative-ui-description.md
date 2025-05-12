# Declarative UI Description


ArkTS declaratively combines and extends components to describe the UI of an application. It also provides basic methods for configuring attributes, events, and child components to help you implement application interaction logic.


## Creating a Component

Depending on the builder, you can create components with or without mandatory parameters.

>  **NOTE**
>
>  The **new** operator is not required when you create a component.


### Without Mandatory Parameters

A struct without mandatory parameters is a component whose API definition has empty parentheses. No parameter needs to be passed to this type of component, for example, the **Divider** component in the following snippet:


```ts
Column() {
  Text('item 1')
  Divider()
  Text('item 2')
}
```


### With Mandatory Parameters

A struct with mandatory parameters is a component whose API definition expects parameters enclosed in parentheses.

- Set the mandatory parameter **src** of the **Image** component as follows:

  ```ts
  Image('https://xyz/test.jpg')
  ```


- Set the optional parameter **content** of the **Text** component.

  ```ts
  // Parameter of the string type
  Text('test')
  // Add application resources in $r format, which can be used in multi-language scenarios.
  Text($r('app.string.title_value'))
  // No mandatory parameters
  Text()
  ```


- You can also use variables or expressions to assign values to parameters. The result type returned by an expression must meet the parameter type requirements.
    For example, to set a variable or expression to construct the **Image** and **Text** components:

    ```ts
    Image(this.imagePath)
    Image('https://' + this.imageUrl)
    Text(`count: ${this.count}`)
    ```


## Configuring Attributes

Use chainable attribute methods to configure the style and other attributes of built-in components. It is recommended that a separate line be used for each attribute method.


- Example of configuring the **fontSize** attribute for the **Text** component:

  ```ts
  Text('test')
    .fontSize(12)
  ```

- Example of configuring multiple attributes for the **Image** component:

  ```ts
  Image('test.jpg')
    .alt('error.jpg')    
    .width(100)    
    .height(100)
  ```

- Attribute methods accept expressions and variables as well constant parameters.

  ```ts
  Text('hello')
    .fontSize(this.size)
  Image('test.jpg')
    .width(this.count % 2 === 0 ? 100 : 200)    
    .height(this.offset + 100)
  ```

- For built-in components, ArkUI also predefines some enumeration types. These enumeration types can be passed as parameters, as long as they meet the parameter type requirements.
  Example of configuring the font color and style of the **Text** component:

  ```ts
  Text('hello')
    .fontSize(20)
    .fontColor(Color.Red)
    .fontWeight(FontWeight.Bold)
  ```


## Handling Events

Use chainable event methods to configure events supported by built-in components. It is recommended that a separate line be used for each event method.


- Example of using an arrow function expression to configure the event of a component:

  ```ts
  Button('Click me')
    .onClick(() => {
      this.myText = 'ArkUI';
    })
  ```

- Example of using an arrow function expression to configure the event of a component (**() => {...}** must be used to ensure that the function is bound to the component and complies with the ArkTS syntax specifications):

  ```ts
  Button('add counter')
    .onClick(() => {
      this.counter += 2;
    })
  ```

- Example of using a component's member function to configure the event of the component, where **this** binding is needed: (This usage is not recommended in ArkTS.)

  ```ts
  myClickHandler(): void {
    this.counter += 2;
  }
  ...
  Button('add counter')
    .onClick(this.myClickHandler.bind(this))
  ```

- Example of using an arrow function expression for a declaration, where **this** binding is not needed:

  ```ts
  fn = () => {
    console.info(`counter: ${this.counter}`)
    this.counter++
  }
  ...
  Button('add counter')
    .onClick(this.fn)
  ```

> **NOTE**
>
> In arrow functions, **this** inherits its value from the surrounding (lexical) scope in which they are defined. This means that, in anonymous functions, **this** may present an unclear reference and is therefore not allowed in ArkTS.


## Configuring Child Components

For a component with child components, for example, a container component, add the UI descriptions of the child components inside parentheses. The **Column**, **Row**, **Stack**, **Grid**, and **List** components are all container components.


- Simple example of configuring child components for the **Column** component:

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

- Example of nested child components in the **Column** component:.

  ```ts
  Column() {
    Row() {
      Image('test1.jpg')
        .width(100)
        .height(100)
      Button('click +1')
        .onClick(() => {
          console.info('+1 clicked!');
        })
    }
  }
  ```
