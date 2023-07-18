# \@Provide and \@Consume Decorators: Two-Way Synchronization with Descendant Components


\@Provide and \@Consume are used for two-way data synchronization with descendant components in scenarios where state data needs to be transferred between multiple levels. They do not involve passing a variable from component to component multiple times.


An \@Provide decorated state variable exists in the ancestor component and is said to be "provided" to descendent components. An \@Consume decorated state variable is used in a descendent component. It is linked to ("consumes") the provided state variable in its ancestor component.


> **NOTE**
>
> Since API version 9, these two decorators are supported in ArkTS widgets.


## Overview

\@Provide/\@Consume decorated state variables have the following features:

- An \@Provide decorated state variable becomes available to all descendent components of the providing component automatically. The variable is said to be "provided" to other components. This means that you do not need to pass a variable from component to component multiple times.

- A descendent component gains access to the provided state variable by decorating a variable with \@Consume. This establishes a two-way data synchronization between the provided and the consumed variable. This synchronization works in the same manner as a combination of \@State and \@Link does. The only difference is that the former allows transfer across multiple levels of the UI parent-child hierarchy.

- \@Provide and \@Consume can be bound using the same variable name or variable alias. Whenever possible, use the same variable types to prevent implicit type conversion and consequently application behavior exceptions.


```ts
// Binding through the same variable name
@Provide a: number = 0;
@Consume a: number;

// Binding through the same variable alias
@Provide('a') b: number = 0;
@Consume('a') c: number;
```


When \@Provide and \@Consume are bound through the same variable name or variable alias, the variables decorated by \@Provide and \@Consume are in a one-to-many relationship. A custom component, including its child components, cannot contain multiple \@Provide decorated variables under the same name or alias. Otherwise, a runtime error will occur.


## Decorator Description

The rules of \@State also apply to \@Provide. The difference is that \@Provide also functions as a synchronization source for multi-layer descendants.

| \@Provide Decorator| Description                                      |
| -------------- | ---------------------------------------- |
| Decorator parameters         | Alias: constant string, optional.<br>If the alias is specified, the variable is provided under the alias name only. If the alias is not specified, the variable is provided under the variable name.|
| Synchronization type          | Two-way:<br>from the \@Provide decorated variable to all \@Consume decorated variables; and the other way around. The two-way synchronization behaviour is the same as that of the combination of \@State and \@Link.|
| Allowed variable types     | Object, class, string, number, Boolean, enum, and array of these types.<br>Date type.<br>For details about the scenarios of supported types, see [Observed Changes](#observed-changes).<br>**any** is not supported. A combination of simple and complex types is not supported. The **undefined** and **null** values are not allowed.<br>The type must be specified. The type of the provided and the consumed variables must be the same.<br>**NOTE**<br>The Length, ResourceStr, and ResourceColor types are a combination of simple and complex types and therefore not supported.|
| Initial value for the decorated variable     | Mandatory.                                   |

| \@Consume Decorator| Description                                      |
| -------------- | ---------------------------------------- |
| Decorator parameters         | Alias: constant string, optional.<br>If the alias is specified, the alias name is used for matching with the \@Provide decorated variable. Otherwise, the variable name is used.|
| Synchronization type          | from the \@Provide decorated variable to all \@Consume decorated variables; and the other way around. The two-way synchronization behaviour is the same as that of the combination of \@State and \@Link.|
| Allowed variable types     | Object, class, string, number, Boolean, enum, and array of these types.<br>Date type.<br>For details about the scenarios of supported types, see [Observed Changes](#observed-changes).<br>**any** is not supported. The **undefined** and **null** values are not allowed.<br>The type must be specified. The type of the provided and the consumed variables must be the same.<br>**NOTE**<br>An \@Consume decorated variable must have a matching \@Provide decorated variable with the corresponding attribute and alias on its parent or ancestor node.|
| Initial value for the decorated variable     | Forbidden.                              |


## Variable Transfer/Access Rules


| \@Provide Transfer/Access| Description                                      |
| -------------- | ---------------------------------------- |
| Initialization and update from the parent component    | Optional. An \@Provide decorated variable can be initialized from a regular variable or an \@State, \@Link, \@Prop, \@Provide, \@Consume, \@ObjectLink, \@StorageLink, \@StorageProp, \@LocalStorageLink, or \@LocalStorageProp decorated variable in its parent component.|
| Subnode initialization      | Supported; can be used to initialize an \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Synchronization with the parent component        | None.                                      |
| Synchronization with descendant components       | Two-way with @Consume decorated variables in descendant components.                         |
| Access     | Private, accessible only within the component.                         |


  **Figure 1** \@Provide initialization rule 


![en-us_image_0000001552614217](figures/en-us_image_0000001552614217.png)


| \@Consume Transfer/Access| Description                                      |
| -------------- | ---------------------------------------- |
| Initialization and update from the parent component    | Forbidden. Initialized from the \@Provide decorated variable with the same name or alias.     |
| Subnode initialization      | Supported; can be used to initialize an \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Synchronization with the ancestor component       | Two-way with the @Provide decorated variable in the ancestor component.                         |
| Access     | Private, accessible only within the component.                          |


  **Figure 2** \@Consume initialization rule 


![en-us_image_0000001502094666](figures/en-us_image_0000001502094666.png)


## Observed Changes and Behavior


### Observed Changes

- When the decorated variable is of the Boolean, string, or number type, its value change can be observed.

- When the decorated variable is of the class or Object type, its value change and value changes of all its attributes, that is, the attributes that **Object.keys(observedObject)** returns.

- When the decorated variable is of the array type, the addition, deletion, and updates of array items can be observed.

- When the decorated variable is of the Date type, the overall value assignment of the Date object can be observed, and the following APIs can be called to update Date attributes: **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, and **setUTCMilliseconds**.

```ts
@Component
struct CompD {

  @Consume selectedDate: Date;

  build() {
    Column() {
      Button(`child increase the day by 1`)
        .onClick(() => {
          this.selectedDate.setDate(this.selectedDate.getDate() + 1)
        })
      Button('child update the new date')
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-09-09')
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate
      })
    }
  }
}

@Entry
@Component
struct CompA {

  @Provide selectedDate: Date = new Date('2021-08-08')

  build() {
    Column() {
      Button('parent increase the day by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setDate(this.selectedDate.getDate() + 1)
        })
      Button('parent update the new date')
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-07-07')
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate
      })
      CompD()
    }
  }
}
```

### Framework Behavior

1. Initial render:
   1. The \@Provide decorated variable is passed to all child components of the owning component in map mode.
   2. If an \@Consume decorated variable is used in a child component, the system checks the map for a matching \@Provide decorated variable based on the variable name or alias. If no matching variable is found, the framework throws a JS error.
   3. The process of initializing the \@Consume decorated variable is similar to that of initializing the \@State/\@Link decorated variable. The \@Consume decorated variable saves the matching \@Provide decorated variable found in the map and registers itself with the \@Provide decorated variable.

2. When the \@Provide decorated variable is updated:
   1. The system traverses and updates all system components (**elementid**) and state variable (\@Consume) that depend on the \@Provide decorated variable, with which the \@Consume decorated variable has registered itself on initial render.  
   2. After the \@Consume decorated variable is updated in all owning child components, all system components (**elementId**) that depend on the \@Consume decorated variable are updated. In this way, changes to the \@Provide decorated variable are synchronized to the \@Consume decorated variable.

3. When the \@Consume decorated variable is updated:

   As can be learned from the initial render procedure, the \@Consume decorated variable holds an instance of \@Provide. After the \@Consume decorated variable is updated, the update method of \@Provide is called to synchronize the changes to \@Provide.


## Application Scenarios

The following example shows the two-way synchronization between \@Provide and \@Consume decorated variables. When the buttons in the **CompA** and **CompD** components are clicked, the changes to **reviewVotes** are synchronized to the **CompA** and **CompD** components.



```ts
@Component
struct CompD {
  // The @Consume decorated variable is bound to the @Provide decorated variable in its ancestor component CompA under the same attribute name.
  @Consume reviewVotes: number;

  build() {
    Column() {
      Text(`reviewVotes(${this.reviewVotes})`)
      Button(`reviewVotes(${this.reviewVotes}), give +1`)
        .onClick(() => this.reviewVotes += 1)
    }
    .width('50%')
  }
}

@Component
struct CompC {
  build() {
    Row({ space: 5 }) {
      CompD()
      CompD()
    }
  }
}

@Component
struct CompB {
  build() {
    CompC()
  }
}

@Entry
@Component
struct CompA {
  // @Provide decorated variable reviewVotes is provided by the entry component CompA.
  @Provide reviewVotes: number = 0;

  build() {
    Column() {
      Button(`reviewVotes(${this.reviewVotes}), give +1`)
        .onClick(() => this.reviewVotes += 1)
      CompB()
    }
  }
}
```
