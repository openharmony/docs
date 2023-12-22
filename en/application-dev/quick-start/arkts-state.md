# \@State Decorator: State Owned by Component


An \@State decorated variable, also called a state variable, is a variable that holds the state property and is used to render the owning custom component. When it changes, the UI is re-rendered accordingly.


Among the decorators related to state variables, \@State is the most basic decorator, as it is the one that empowers variables to have the state property. It is also the data source of most state variables.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Overview

An @State decorated variable, like all other decorated variables in the declarative paradigm, are private and only accessible from within the component. Its type and its local initialization must be specified. Initialization from the parent component using the named parameter mechanism is accepted.

\@State decorated variables have the following features:

- A one-way synchronization relationship can be set up from an \@State decorated variable to an \@Prop decorated variable in a child component, and a two-way synchronization relationship to an \@Link or \@ObjectLink decorated variable.

- The lifecycle of the \@State decorated variable is the same as that of its owning custom component.


## Rules of Use

| \@State Decorator | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Decorator parameters        | None.                                                          |
| Synchronization type          | Does not synchronize with any type of variable in the parent component.                            |
| Allowed variable types| Object, class, string, number, Boolean, enum, and array of these types.<br>Date type.<br>**undefined** or **null**.<br>For details about the scenarios of supported types, see [Observed Changes](#observed-changes).<br>(Applicable to API version 11 and later versions) Union type of the preceding types, for example, string \| number, string \| undefined or ClassA \| null. For details, see [Union Type @State](#union-type-state).<br>**NOTE**<br>When **undefined** or **null** is used, you are advised to explicitly specify the type to pass the TypeScipt type check. For example, **@State a: string \| undefined = undefined** is recommended; **@State a: string = undefined** is not recommended.<br>The union types Length, ResourceStr, and ResourceColor defined by the AkrUI framework are supported.<br>The type must be specified.<br>**any** is not supported.|
| Initial value for the decorated variable| Local initialization is required.                                              |


## Variable Transfer/Access Rules

| Transfer/Access         | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Initialization from the parent component    | Optional. Initialization from the parent component or local initialization can be used. The initial value specified in the parent component will overwrite the one defined locally.<br>An @State decorated variable can be initialized from a regular variable (whose change does not trigger UI refresh) or an @State, @Link, @Prop, @Provide, @Consume, @ObjectLink, @StorageLink, @StorageProp, @LocalStorageLink, or @LocalStorageProp decorated variable in its parent component.|
| Subnode initialization  | Supported. An \@State decorated variable can be used to initialize a regular variable or \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access| Private, accessible only within the component.                                  |

  **Figure 1** Initialization rule 

![en-us_image_0000001502091796](figures/en-us_image_0000001502091796.png)


## Observed Changes and Behavior

Not all changes to state variables cause UI updates. Only changes that can be observed by the framework do. This section describes what changes can be observed and how the framework triggers UI updates after the changes are observed, that is, how the framework behaves.


### Observed Changes

- When the decorated variable is of the Boolean, string, or number type, its value change can be observed.

  ```ts
  // for simple type
  @State count: number = 0;
  // value changing can be observed
  this.count = 1;
  ```

- When the decorated variable is of the class or Object type, its value change and value changes of all its properties, that is, the properties that **Object.keys(observedObject)** returns. Below is an example.
    Declare the **ClassA** and **Model** classes.

    ```ts
      class ClassA {
        public value: string;
      
        constructor(value: string) {
          this.value = value;
        }
      }
      
      class Model {
        public value: string;
        public name: ClassA;
        constructor(value: string, a: ClassA) {
          this.value = value;
          this.name = a;
        }
      }
    ```

    Use \@State to decorate a variable of the Model class object type.

    ```ts
    // Class type
     @State title: Model = new Model('Hello', new ClassA('World'));
    ```

    Assign a value to the \@State decorated variable.

    ```ts
    // Assign a value to the class object.
    this.title = new Model('Hi', new ClassA('ArkUI'));
    ```

    Assign a value to a property of the \@State decorated variable.

    ```ts
    // Assign a value to a property of the class object.
    this.title.value = 'Hi'
    ```

    The value assignment of the nested property cannot be observed.

    ```ts
    // The value assignment of the nested property cannot be observed.
    this.title.name.value = 'ArkUI'
    ```
- When the decorated variable is of the array type, the addition, deletion, and updates of array items can be observed. Below is an example.
  Declare the **ClassA** and **Model** classes.

  ```ts
  class Model {
    public value: number;
    constructor(value: number) {
      this.value = value;
    }
  }
  ```

  Use \@State to decorate a variable of the Model class array type.

  ```ts
  @State title: Model[] = [new Model(11), new Model(1)]
  ```

  The value assignment of the array itself can be observed.

  ```ts
  this.title = [new Model(2)]
  ```

  The value assignment of array items can be observed.

  ```ts
  this.title[0] = new Model(2)
  ```

  The deletion of array items can be observed.

  ```ts
  this.title.pop()
  ```

  The addition of array items can be observed.

  ```ts
  this.title.push(new Model(12))
  ```

  The property value assignment in the array items cannot be observed.

  ```ts
  this.title[0].value = 6
  ```

- When the decorated variable is of the Date type, the overall value assignment of the **Date** object can be observed, and the following APIs can be called to update **Date** properties: **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, and **setUTCMilliseconds**.

  ```ts
  @Entry
  @Component
  struct DatePickerExample {
    @State selectedDate: Date = new Date('2021-08-08')
  
    build() {
      Column() {
        Button('set selectedDate to 2023-07-08')
          .margin(10)
          .onClick(() => {
            this.selectedDate = new Date('2023-07-08')
          })
        Button('increase the year by 1')
          .margin(10)
          .onClick(() => {
            this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1)
          })
        Button('increase the month by 1')
          .margin(10)
          .onClick(() => {
            this.selectedDate.setMonth(this.selectedDate.getMonth() + 1)
          })
        Button('increase the day by 1')
          .margin(10)
          .onClick(() => {
            this.selectedDate.setDate(this.selectedDate.getDate() + 1)
          })
        DatePicker({
          start: new Date('1970-1-1'),
          end: new Date('2100-1-1'),
          selected: this.selectedDate
        })
      }.width('100%')
    }
  }
  ```

### Framework Behavior

- When a state variable is changed, the framework searches for components that depend on this state variable.

- The framework executes an update method of the dependent components, which triggers re-rendering of the components.

- Components or UI descriptions irrelevant to the state variable are not re-rendered, thereby implementing on-demand page updates.


## Application Scenarios


### Decorating Variables of Simple Types

In this example, \@State is used to decorate the **count** variable of the simple type, turning it into a state variable. The change of **count** causes the update of the **\<Button>** component.

- When **count** changes, the framework searches for components bound to it, which include only the **\<Button>** component in this example.

- The framework executes the update method of the **\<Button>** component to implement on-demand update.


```ts
@Entry
@Component
struct MyComponent {
  @State count: number = 0;

  build() {
    Button(`click times: ${this.count}`)
      .onClick(() => {
        this.count += 1;
      })
  }
}
```


### Decorating Variables of the Class Object Type

- In this example, \@State is used to decorate the variables **count** and **title** in the custom component **MyComponent**. The type of **title** is **Model**, a custom class. If the value of **count** or **title** changes, the framework searches for all **MyComponent** instances that depend on these variables and triggers re-rendering of them.

- The **EntryComponent** has multiple **MyComponent** instances. The internal state change of the first **MyComponent** instance does not affect the second **MyComponent** instance.



```ts
class Model {
  public value: string;

  constructor(value: string) {
    this.value = value;
  }
}

@Entry
@Component
struct EntryComponent {
  build() {
    Column() {
      // The parameters specified here will overwrite the default values defined locally during initial render. Not all parameters need to be initialized from the parent component.
      MyComponent({ count: 1, increaseBy: 2 })
      MyComponent({ title: new Model('Hello, World 2'), count: 7 })
    }
  }
}

@Component
struct MyComponent {
  @State title: Model = new Model('Hello World');
  @State count: number = 0;
  private increaseBy: number = 1;

  build() {
    Column() {
      Text(`${this.title.value}`)
      Button(`Click to change title`).onClick(() => {
        // The update of the @State decorated variable triggers the update of the <Text> component.
        this.title.value = this.title.value === 'Hello ArkUI' ? 'Hello World' : 'Hello ArkUI';
      })

      Button(`Click to increase count=${this.count}`).onClick(() => {
        // The update of the @State decorated variable triggers the update of the <Button> component.
        this.count += this.increaseBy;
      })
    }
  }
}
```


From this example, we learn the initialization process of an \@State decorated variable on initial render.


1. Apply the locally defined default value.

   ```ts
   @State title: Model = new Model('Hello World');
   @State count: number = 0;
   ```

2. Apply the named parameter value, if one is provided.

   ```ts
   class C1 {
      public count:number;
      public increaseBy:number;
      constructor(count: number, increaseBy:number) {
        this.count = count;
        this.increaseBy = increaseBy;
     }
   }
   let obj = new C1(1, 2)
   MyComponent(obj)
   ```

## Union Type @State

@State supports **undefined**, **null**, and union types. In the following example, the type of **count** is number | undefined. If the property or type of **count** is changed when the button is clicked, the change will be synced to the view.

```ts
@Entry
@Component
struct EntryComponent {

  build() {
    Column() {
      MyComponent()
    }
  }
}

@Component
struct MyComponent {
  @State  count: number | undefined = 0;

  build() {
    Column() {
      Text(`count(${this.count})`)
      Button('change')
        .onClick(() => {
          this.count = undefined;
        })
    }
  }
}

```
<!--no_check-->