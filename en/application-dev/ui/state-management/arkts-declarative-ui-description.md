# Declarative UI Description

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sunfei2021-->
<!--Designer: @sunfei2021-->
<!--Tester: @sally__-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:01:44.299Z pushedAt=2026-07-22T07:38:43.451Z -->

ArkTS describes an application's UI by combining and extending components in a declarative manner. It also provides basic methods for configuring attributes, events, and child components to help you implement application interaction logic.

## Creating a Component

You can create a component with or without parameters, depending on the component's constructor.

>  **NOTE**
>
>  The **new** keyword is not required for component instantiation.

### Without Parameters

If a component's API definition does not include mandatory constructor parameters, leave the parentheses empty. For example, the **Divider** component requires no parameters.

 <!-- @[segment1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) --> 

 ``` TypeScript
 Column() {
   // ...
   Divider()
   // ...
 }
 ```

### With Parameters

If a component's API definition includes constructor parameters, configure the required parameters in the parentheses.

- **Image** component with a mandatory **src** parameter:

   <!-- @[segment2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   Image('https://xyz/test.jpg')
   ```

- **Text** component with an optional **content** parameter:

  <!-- @[segment3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  // Parameter of the string type
  Text('test')
  // Reference application resources using $r, applicable to multi-language scenarios.
  Text($r('app.string.title_value'))
  // Parameter-free form
  Text()
  ```

- Variables or expressions can be used for parameter assignment, with types matching the parameter requirements.

  For example, set variables or expressions to construct parameters for **Image** and **Text** components:

  <!-- @[segment4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Image(this.imagePath)
  // Replace the URL with the correct one you need.
  Image('https://' + this.imageUrl)
  Text(`count: ${this.count}`)
  ```

## Configuring Attributes

Configure styles and other attributes using chained method calls, one per line recommended.

- Set the font size for the **Text** component:

  <!-- @[segment5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Text('test')
    .fontSize(12)
  ```

- Set multiple attributes for the **Image** component:

  <!-- @[segment6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Image('test.jpg')
    .alt('error.jpg')
    .width(100)
    .height(100)
  ```

- Attribute methods accept expressions and variables as well constant parameters.

  <!-- @[segment7](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Text('hello')
    .fontSize(this.fontSize)
  Image('test.jpg')
    .width(this.count % 2 === 0 ? 100 : 200)
    .height(this.offsetNum + 100)
  ```

- For built-in components, ArkUI also predefines some enumeration types for their attributes. Enumeration types can be passed as parameters but must meet the parameter type requirements.

  Set the font color and style for the **Text** component:

  <!-- @[segment8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Text('hello')
    .fontSize(20)
    .fontColor(Color.Red)
    .fontWeight(FontWeight.Bold)
  ```

## Configuring Events

Configure built-in component events using chained method calls, one per line recommended.

- Use the arrow function syntax for event configuration:

  <!-- @[segment9](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Button('Click me')
    .onClick(() => {
      this.myText = 'ArkUI';
    })
  ```

- Use the arrow function expression syntax for event configuration, requiring the use of "() => {...}" to ensure that the function is bound to the component and complies with ArkTS syntax specifications:

  <!-- @[segment10](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Button('add counter')
    .onClick(() => {
      this.counter += 2;
    })
  ```

- Example of using a component's member function to configure the event of the component, where **this** binding is needed: (This usage is not recommended in ArkTS.)

  <!-- @[segment11](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
    myClickHandler(): void {
      this.counter += 2;
    }
  
  // ···
     Button('add counter')	
       .onClick(this.myClickHandler.bind(this))
  ```

- Use a pre-declared arrow function for event configuration, where binding **this** is not needed:

  <!-- @[segment12](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
    fn = () => {
      hilog.info(0x0000, 'Declarative UI Description', `counter: ${this.counter}`);
      this.counter++;
    };
  
  // ···
     Button('add counter')
       .onClick(this.fn)
  ```

> **NOTE**
>
> In arrow functions, **this** inherits its value from the surrounding (lexical) scope in which they are defined. This means that, in anonymous functions, **this** may present an unclear reference and is therefore not allowed in ArkTS.

## Configuring Child Components

For a component with child components, for example, a container component, add the UI descriptions of the child components within trailing closures {...}. The **Column**, **Row**, **Stack**, **Grid**, and **List** components are all container components.

- Configure child components for the **Column** component:

  <!-- @[segment13](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
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

  <!-- @[segment14](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DeclarativeUIDescription/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  Column() {
    Row() {
      Image('test1.jpg')
        .width(100)
        .height(100)
      Button('click +1')
        .onClick(() => {
          hilog.info(0x0000, 'Declarative UI Description', '+1 clicked!');
        })
    }
  }
  ```