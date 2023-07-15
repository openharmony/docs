# \@State Decorator: State Owned by Component


An \@State decorated variable, also called a state variable, is a variable that holds the state property and is used to render the owning custom component. When it changes, the UI is re-rendered accordingly.


Among the decorators related to state variables, \@State is the most basic decorator, as it is the one that empowers variables to have the state property. It is also the data source of most state variables.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Overview

An @State decorated variable, like all other decorated variables in the declarative paradigm, are private and only accessible from within the component. Its type and its local initialization must be specified. Initialization from the parent component using the named parameter mechanism is accepted.

\@State decorated variables have the following features:

- A one-way and two-way data synchronization relationship can be set up from an \@State decorated variable to an \@Prop, \@Link, or \@ObjectLink decorated variable in a child component.

- The lifecycle of the \@State decorated variable is the same as that of its owning custom component.


## Rules of Use

| \@State Decorator| Description                                      |
| ------------ | ---------------------------------------- |
| Decorator parameters       | None.                                       |
| Synchronization type        | Does not synchronize with any type of variable in the parent component.                        |
| Allowed variable types   | Object, class, string, number, Boolean, enum, and array of these types. For details about the scenarios of nested types, see [Observed Changes](#observed-changes).<br>The type must be specified.<br>**any** is not supported. A combination of simple and complex types is not supported. The **undefined** and **null** values are not allowed.<br>**NOTE**<br>Avoid using this decorator to decorate the Date type, as doing so may lead to unexpected behavior of the application.<br>The Length, ResourceStr, and ResourceColor types are a combination of simple and complex types and therefore not supported.|
| Initial value for the decorated variable   | Mandatory.                                   |


## Variable Transfer/Access Rules

| Transfer/Access    | Description                                      |
| --------- | ---------------------------------------- |
| Initialization from the parent component  | Optional. Initialization from the parent component or local initialization can be used.<br>An \@State decorated variable can be initialized from a regular variable or an \@State, \@Link, \@Prop, \@Provide, \@Consume, \@ObjectLink, \@StorageLink, \@StorageProp, \@LocalStorageLink, or \@LocalStorageProp decorated variable in its parent component.|
| Subnode initialization | Supported. An \@State decorated variable can be used to initialize a regular variable or \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access| Private, accessible only within the component.                           |

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

- When the decorated variable is of the class or Object type, its value change and value changes of all its attributes, that is, the attributes that **Object.keys(observedObject)** returns. Below is an example.
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

    Assign a value to an attribute of the \@State decorated variable.

    ```ts
    // Assign a value to an attribute of the class object.
    this.title.value = 'Hi'
    ```

    The value assignment of the nested attribute cannot be observed.

    ```ts
    // The value assignment of the nested attribute cannot be observed.
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


### Framework Behavior

- When a state variable is changed, the framework searches for components that depend on this state variable.

- The framework executes an update method of the dependent components, which triggers re-rendering of the components.

- Components or UI descriptions irrelevant to the state variable are not re-rendered, thereby implementing on-demand page updates.


## Application Scenarios


### Decorating Variables of Simple Types

In this example, \@State is used to decorate the **count** variable of the simple type and turns it into a state variable. The change of **count** causes the update of the **\<Button>** component.

- When the state variable **count** changes, the framework searches for components that depend on this state variable, which include only the **\<Button>** component in this example.

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
   MyComponent({ count: 1, increaseBy: 2 })
   ```
