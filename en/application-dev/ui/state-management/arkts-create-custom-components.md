# Creating a Custom Component
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926; @huyisuo-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

In ArkUI, components refer to the elements displayed on the UI. They fall into two categories: built-in components (provided by the ArkUI framework out of the box) and custom components (defined by developers). While it is technically possible to build an entire UI using only built-in components, this approach often results in a monolithic structure, leading to low code maintainability and suboptimal performance. A well-designed UI requires careful planning, balancing factors such as code reusability, the separation of service logic from UI layers, and adaptability to version evolution. Creating custom components, which encapsulate UI elements and service logic, serves as a critical step in achieving this goal.

Custom components offer the following features:

- Combinability: You can combine built-in components and other components, as well as their attributes and methods.

- Reusability: Custom components can be reused across different components, serving as distinct instances in various parent components or containers.

- Data-driven update: Custom components can hold internal state variables. When these state variables change, UI re-rendering is triggered.

## Basic Usage of Custom Components

The following example shows the basic usage of a custom component.

```ts
@Component
struct HelloComponent {
  @State message: string = 'Hello, World!';

  build() {
    // The HelloComponent custom component combines the Row and Text built-in components.
    Row() {
      Text(this.message)
        .onClick(() => {
          // The change of the state variable message drives the UI to be re-rendered. As a result, the text changes from "Hello, World!" to "Hello, ArkUI!".
          this.message = 'Hello, ArkUI!';
        })
    }
  }
}
```
> **NOTE**
>
> To reference a custom component in another file, use the keyword **export** to export the component and then use **import** to import it to the target file.

Multiple **HelloComponent** instances can be created in **build()** of other custom components. In this way, **HelloComponent** is reused across those components.

```ts
@Entry
@Component
struct ParentComponent {
  build() {
    Column() {
      Text('ArkUI message')
      HelloComponent({ message: 'Hello World!' });
      Divider()
      HelloComponent({message: 'Hello, World!'});
    }
  }
}
```

To fully understand the preceding example, a knowledge of the following concepts is essential:

- [Basic Structure of a Custom Component](#basic-structure-of-a-custom-component)

- [Member Functions/Variables](#member-functionsvariables)

- [Rules for Custom Component Parameters](#rules-for-custom-component-parameters)

- [build()](#build)

- [Universal Style of a Custom Component](#universal-style-of-a-custom-component)


## Basic Structure of a Custom Component

### struct

The definition of a custom component must start with the \@Component struct followed by the component name, and then component body enclosed by curly brackets. No inheritance is allowed. You can omit the **new** operator when instantiating a struct.

  > **NOTE**
  >
  > The name assigned to a class, function, or custom component must be different from the name of any built-in component.
  
### \@Component

The \@Component decorator can decorate only the structs declared by the **struct** keyword. When being decorated by \@Component, a struct has the componentization capability. You must implement the **build** function for it to describe the UI. Each struct can be decorated by only one \@Component. \@Component can accept an optional parameter of the Boolean type.

  > **NOTE**
  >
  > This decorator can be used in ArkTS widgets since API version 9.
  > 
  > For the \@Component decorator, an optional parameter of the Boolean type is supported since API version 11.
  >
  > This decorator can be used in atomic services since API version 11.

  ```ts
  @Component
  struct MyComponent {
  }
  ```

 **freezeWhenInactive<sup>11+</sup>**
  Describes the [custom component freezing](arkts-custom-components-freeze.md) option.

  | Name  | Type  | Mandatory| Description                                                        |
  | ------ | ------ | ---- | ------------------------------------------------------------ |
  | freezeWhenInactive | boolean | No| Whether to enable component freezing. The default value is **false**. **true** means to enable component freezing, and **false** means the opposite.|

  ```ts
  @Component({ freezeWhenInactive: true })
  struct MyComponent {
  }
  ```

### build()

The **build()** function is used to define the declarative UI description of a custom component. Every custom component must define a **build()** function.

  ```ts
  @Component
  struct MyComponent {
    build() {
    }
  }
  ```

### \@Entry

The @Entry decorator marks a custom component as the entry point of a page. A single page can only have one @Entry decorated custom component serving as its entry. The \@Entry decorator accepts an optional parameter of type [LocalStorage](arkts-localstorage.md).

  > **NOTE**
  >
  > This decorator can be used in ArkTS widgets since API version 9.
  >
  > Since API version 10, the \@Entry decorator accepts an optional parameter of type [LocalStorage](arkts-localstorage.md) or type **EntryOptions**<sup>10+</sup>.
  >
  > This decorator can be used in atomic services since API version 11.

  ```ts
  @Entry
  @Component
  struct MyComponent {
  }
  ```

**EntryOptions<sup>10+</sup>**

  Describes the named route options.

  | Name  | Type  | Mandatory| Description                                                        |
  | ------ | ------ | ---- | ------------------------------------------------------------ |
  | routeName | string | No| Name of the target named route.|
  | storage | [LocalStorage](arkts-localstorage.md) | No| Storage of the page-level UI state. If no value is passed, the framework creates a new LocalStorage instance as the default value.|
  | useSharedStorage<sup>12+</sup> | boolean | No| Whether to use the LocalStorage instance passed by [LocalContent](../../reference/apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9). The default value is **false**. **true**: Use the shared [LocalStorage](arkts-localstorage.md) instance. **false**: Do not use the shared [LocalStorage](arkts-localstorage.md) instance.|

  > **NOTE**
  >
  > When **useSharedStorage** is set to **true** and **storage** is assigned a value, the value of **useSharedStorage** has a higher priority.

  ```ts
  @Entry({ routeName : 'myPage' })
  @Component
  struct MyComponent {
  }
  ```

### \@Reusable

The \@Reusable decorator enables a custom component to be reusable. For details, see [\@Reusable Decorator: Reusing Components](./arkts-reusable.md#use-scenarios).

  > **NOTE**
  >
  > This decorator can be used in ArkTS widgets since API version 10.

  ```ts
  @Reusable
  @Component
  struct MyComponent {
  }
  ```

## Member Functions/Variables

In addition to the mandatory **build()**, a custom component may implement other member functions with the following restrictions:

- Member functions of a custom component can only be accessed from within the component. Avoid declaring them as static functions.

A custom component can also implement member variables with the following restrictions:

- Member variables of a custom component can only be accessed from within the component. Avoid declaring them as static variables.

- Local initialization is optional for some member variables and mandatory for others. For details about whether local initialization or initialization from the parent component is required, see [State Management](arkts-state-management-overview.md).


## Rules for Custom Component Parameters

As can be seen from preceding examples, a custom component can be created using a **build** method. During the creation process, the custom component's parameters are initialized based on the decorator rules.

```ts
@Component
struct MyComponent {
  private countDownFrom: number = 0;
  private color: Color = Color.Blue;

  build() {
  }
}

@Entry
@Component
struct ParentComponent {
  private someColor: Color = Color.Pink;

  build() {
    Column() {
      // Create an instance of MyComponent and initialize its countDownFrom variable with the value 10 and its color variable with the value this.someColor.
      MyComponent({ countDownFrom: 10, color: this.someColor })
    }
  }
}
```

In the following example, a function in the parent component is passed to the child component and called therein.

```ts
@Entry
@Component
struct Parent {
  @State cnt: number = 0
  submit: () => void = () => {
    this.cnt++;
  }

  build() {
    Column() {
      Text(`${this.cnt}`)
      Son({ submitArrow: this.submit })
    }
  }
}

@Component
struct Son {
  submitArrow?: () => void

  build() {
    Row() {
      Button('add')
        .width(80)
        .onClick(() => {
          if (this.submitArrow) {
            this.submitArrow()
          }
        })
    }
    .height(56)
  }
}
```

## build()

Whatever declared in **build()** are called UI descriptions. UI descriptions must comply with the following rules:

- For an \@Entry decorated custom component, exactly one root component is required under **build()**. This root component must be a container component. **ForEach** is not allowed at the top level.
  For an \@Component decorated custom component, exactly one root component is required under **build()**. This root component is not necessarily a container component. **ForEach** is not allowed at the top level.

  ```ts
  @Entry
  @Component
  struct MyComponent {
    build() {
      // Exactly one root component is required, and it must be a container component.
      Row() {
        ChildComponent() 
      }
    }
  }
  
  @Component
  struct ChildComponent {
    build() {
      // Exactly one root component is required, and it is not necessarily a container component.
      Image('test.jpg')
    }
  }
  ```

- Local variable declaration is not allowed. The following example should be avoided:

  ```ts
  build() {
    // Avoid: declaring a local variable.
    let num: number = 1;
  }
  ```

- **console.info** can be used in the UI description only when it is in a method or function. The following example should be avoided:

  ```ts
  build() {
    // Avoid: using console.info directly in UI description.
    console.info('print debug log');
  }
  ```

- Creation of a local scope is not allowed. The following example should be avoided:

  ```ts
  build() {
    // Avoid: creating a local scope.
    {
      // ...
    }
  }
  ```

- Only methods decorated by \@Builder can be called. The parameters of built-in components can be the return values of TS methods.

  ```ts
  @Component
  struct ParentComponent {
    doSomeCalculations() {
    }

    calcTextValue(): string {
      return 'Hello World';
    }

    @Builder doSomeRender() {
      Text(`Hello World`)
    }

    build() {
      Column() {
        // Avoid: calling a method not decorated by @Builder.
        this.doSomeCalculations();
        // Prefer: Call an @Builder decorated method.
        this.doSomeRender();
        // Prefer: Pass the return value of a TS method as the parameter.
        Text(this.calcTextValue())
      }
    }
  }
  ```

- The **switch** syntax is not allowed. If conditional judgment is required, use the [if](./arkts-rendering-control-ifelse.md) statement. Refer to the code snippet below.

  ```ts
  build() {
    Column() {
      // Avoid: using the switch syntax.
      switch (expression) {
        case 1:
          Text('...')
          break;
        case 2:
          Image('...')
          break;
        default:
          Text('...')
          break;
      }
      // Correct usage: Use if.
      if(expression == 1) {
        Text('...')
      } else if(expression == 2) {
        Image('...')
      } else {
        Text('...')
      }
    }
  }
  ```

- Expressions are not allowed except for the **if** component. Refer to the code snippet below.

  ```ts
  build() {
    Column() {
      // Avoid: expressions.
      (this.aVar > 10) ? Text('...') : Image('...')

      // Positive example: Use if for judgment.
      if(this.aVar > 10) {
        Text('...')
      } else {
        Image('...')
      }
    }
  }
  ```

- Directly changing a state variable is not allowed. The following example should be avoided. For details, see [Changing State Variables in build() Is Forbidden](./arkts-state.md#changing-state-variables-in-build-is-forbidden).

  ```ts
  @Component
  struct MyComponent {
    @State textColor: Color = Color.Yellow;
    @State columnColor: Color = Color.Green;
    @State count: number = 1;
    build() {
      Column() {
        // Avoid directly changing the value of count in the Text component.
        Text(`${this.count++}`)
          .width(50)
          .height(50)
          .fontColor(this.textColor)
          .onClick(() => {
            this.columnColor = Color.Red;
          })
        Button("change textColor").onClick(() =>{
          this.textColor = Color.Pink;
        })
      }
      .backgroundColor(this.columnColor)
    }
  }
  ```

  In ArkUI state management, UI re-render is driven by state.

  ![en-us_image_0000001651365257](figures/en-us_image_0000001651365257.png)

  Therefore, do not change any state variable in the **build()** or \@Builder decorated method of a custom component. Otherwise, loop rendering may result. Depending on the update mode (full update or minimum update), **Text('${this.count++}')** imposes different effects:

  - Full update (API version 8 or before): ArkUI may fall into an infinite re-rendering loop because each rendering of the **Text** component changes the application state and causes a new round of re-renders. When **this.columnColor** is changed, the entire **build** function is executed. As a result, the text bound to **Text(${this.count++})** is also changed. Each time **Text(${this.count++})** is re-rendered, the **this.count** state variable is updated, and a new round of **build** execution follows, resulting in an infinite loop.
  - Minimized update (API version 9 or later): Changing **this.columnColor** updates the **Column** component, but not the **Text** component. The entire **Text** component is updated only when **this.textColor** changes. During the update, all of the component's attribute functions are executed. As a result, the value of **Text(${this.count++})** is incremented. Currently, the UI is updated by component. If an attribute of a component changes, the entire component is updated. Therefore, the overall update link is as follows: **this.textColor** = **Color.Pink** -> **Text** re-render -> **this.count++** -> **Text** re-render. It should be noted that this way of writing causes the **Text** component to be rendered twice during the initial render, which affects the performance.

  The behavior of changing the application state in the **build** function may be more covert than that in the preceding example. The following are some examples:

  - Changing the state variable within the \@Builder, \@Extend, or \@Styles decorated method

  - Changing the application state variable in the function called during parameter calculation, for example, **Text('${this.calcLabel()}')**

  - Modifying the current array: In the following code snippet, **sort()** changes the array **this.arr**, and the subsequent **filter** method returns a new array.

    ```ts
    // Incorrect usage:
    @State arr : Array<...> = [ ... ];
    ForEach(this.arr.sort().filter(...), 
      item => { 
      // ...
    })
    // Prefer: Call filter before sort() to return a new array. In this way, sort() does not change this.arr.
    ForEach(this.arr.filter(...).sort(), 
      item => { 
      // ...
    })
    ```

## Universal Style of a Custom Component

The universal style of a custom component is configured by the chain call.

```ts
@Component
struct ChildComponent {
  build() {
    Button(`Hello World`)
  }
}

@Entry
@Component
struct MyComponent {
  build() {
    Row() {
      ChildComponent()
        .width(200)
        .height(300)
        .backgroundColor(Color.Red)
    }
  }
}
```

> **NOTE**
>
> When applying styles to a custom component (**ChildComponent** in this example), the ArkUI framework implicitly wraps **ChildComponent** with an invisible container component. These styles are actually applied to this container component instead of the **Button** component inside **ChildComponent**. This behavior can be observed in rendering results: The red background color is not applied directly to the **Button** component; instead, it is rendered on the invisible container component that wraps the **Button** component.
<!--no_check-->
