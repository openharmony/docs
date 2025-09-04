# Declarative UI Description
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sunfei2021-->
<!--Designer: @sunfei2021-->
<!--Tester: @sally__-->
<!--Adviser: @zhang_yixin13-->

ArkTS describes an application's UI by combining and extending components in a declarative manner. It also provides basic methods for configuring attributes, events, and child components to help you implement application interaction logic.

## Creating a Component

You can create a component with or without parameters, depending on the component's constructor.

>  **NOTE**
>
>  The **new** keyword is not required for component instantiation.

### Without Parameters

If a component's API definition does not include mandatory constructor parameters, leave the parentheses empty. For example, the **Divider** component requires no parameters.

```ts
Column() {
  Text('item 1')
  Divider()
  Text('item 2')
}
```

### With Parameters

If a component's API definition includes constructor parameters, configure the required parameters in the parentheses.

- **Image** component with a mandatory **src** parameter:

  ```ts
  Image('https://xyz/test.jpg')
  ```


- **Text** component with an optional **content** parameter:

  ```ts
  // Parameter of the string type
  Text('test')
  // Reference application resources using $r, applicable to multi-language scenarios.
  Text($r('app.string.title_value'))
  // Parameter-free form
  Text()
  ```

- Variables or expressions can be used for parameter assignment, with types matching the parameter requirements.
    For example, set variables or expressions to construct parameters for **Image** and **Text** components:

    ```ts
    Image(this.imagePath)
    Image('https://' + this.imageUrl)
    Text(`count: ${this.count}`)
    ```


## Configuring Attributes

Configure styles and other attributes using chained method calls, one per line recommended.

- Set the font size for the **Text** component:

  ```ts
  Text('test')
    .fontSize(12)
  ```

- Set multiple attributes for the **Image** component:

  ```ts
  Image('test.jpg')
    .alt('error.jpg')    
    .width(100)    
    .height(100)
  ```

- Attribute methods accept expressions and variables as well constant parameters.<br>Use expressions and variables:

  ```ts
  Text('hello')
    .fontSize(this.size)
  Image('test.jpg')
    .width(this.count % 2 === 0 ? 100 : 200)    
    .height(this.offset + 100)
  ```

- For built-in components, ArkUI also predefines some enumeration types for their attributes. Enumeration types can be passed as parameters but must meet the parameter type requirements.
  Set the font color and style for the **Text** component:

  ```ts
  Text('hello')
    .fontSize(20)
    .fontColor(Color.Red)
    .fontWeight(FontWeight.Bold)
  ```


## Configuring Events

Configure built-in component events using chained method calls, one per line recommended.

- Use the arrow function syntax for event configuration:

  ```ts
  Button('Click me')
    .onClick(() => {
      this.myText = 'ArkUI';
    })
  ```

- Use the arrow function expression syntax for event configuration, requiring the use of "() => {...}" to ensure that the function is bound to the component and complies with ArkTS syntax specifications:

  ```ts
  Button('add counter')
    .onClick(() => {
      this.counter += 2;
    })
  ```

- (Not recommended in ArkTS) Use a member function for event configuration, which requires explicit **bind(this)**:

  ```ts
  myClickHandler(): void {
    this.counter += 2;
  }
  // ...
  Button('add counter')
    .onClick(this.myClickHandler.bind(this))
  ```

- Use a pre-declared arrow function for event configuration, where binding **this** is not needed:

  ```ts
  fn = () => {
    console.info(`counter: ${this.counter}`)
    this.counter++
  }
  // ...
  Button('add counter')
    .onClick(this.fn)
  ```

> **NOTE**
>
> In arrow functions, **this** inherits its value from the surrounding (lexical) scope in which they are defined. This means that, in anonymous functions, **this** may present an unclear reference and is therefore not allowed in ArkTS.

## Configuring Child Components

For a component with child components, for example, a container component, add the UI descriptions of the child components within trailing closures {...}. The **Column**, **Row**, **Stack**, **Grid**, and **List** components are all container components.

- Configure child components for the **Column** component:

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

- Configure nested child components in the **Column** component:.

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
