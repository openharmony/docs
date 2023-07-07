# \@Prop Decorator: One-Way Synchronization from Parent to Child Components


An \@Prop decorated variable can create one-way synchronization with a variable of its parent component. \@Prop decorated variables are mutable, but changes are not synchronized to the parent component.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Overview

For an \@Prop decorated variable, the value synchronization is uni-directional from the parent component to the owning component.

- An @Prop variable is allowed to be modified locally, but the change does not propagate back to its parent component.

- Whenever that data source changes, the @Prop decorated variable gets updated, and any locally made changes are overwritten.


## Rules of Use

| \@Prop Decorator| Description                                      |
| ----------- | ---------------------------------------- |
| Decorator parameters      | None.                                       |
| Synchronization type       | One-way: from the data source provided by the parent component to the @Prop decorated variable.|
| Allowed variable types  | string, number, boolean, or enum type.<br>**any** is not supported. The **undefined** and **null** values are not allowed.<br>The type must be specified.<br>Negative examples:<br>CompA&nbsp;({&nbsp;aProp:&nbsp;undefined&nbsp;})<br>CompA&nbsp;({&nbsp;aProp:&nbsp;null&nbsp;})<br>The type must be the same as that of the [data source](arkts-state-management-overview.md#basic-concepts). There are three cases (\@State is used as an example of the data source):<br>- The type of the \@Prop decorated variable is the same as that of the state variable of the parent component, that is, \@Prop: S and \@State: S. For an example, see [Simple Type @Prop Synced from @State in Parent Component](#simple-type-prop-synced-from-state-in-parent-component).<br>- When the state variable of the parent component is an array, the type of the \@Prop decorated variable is the same as that of the array item of the state variable of the parent component, that is, \@Prop: S and \@State: Array\<S>. For examples, see [Simple Type @Prop Synced from @State Array Item in Parent Component](#simple-type-prop-synced-from-state-array-item-in-parent-component).<br>- When the state variable of the parent component is Object or class, the type of the \@Prop decorated variable is the same as the attribute type of the state variable of the parent component, that is, \@Prop: S and \@State: { propA: S }. For examples, see [Class Object Type @Prop Synced from @State Class Object Attribute in Parent Component](#class-object-type-prop-synced-from-state-class-object-attribute-in-parent-component). |
| Initial value for the decorated variable  | Local initialization is allowed.                                |


## Variable Transfer/Access Rules

| Transfer/Access    | Description                                      |
| --------- | ---------------------------------------- |
| Initialization from the parent component  | Optional. Initialization from the parent component or local initialization can be used. An \@Prop decorated variable can be initialized from a regular variable or an \@State, \@Link, \@Prop, \@Provide, \@Consume, \@ObjectLink, \@StorageLink, \@StorageProp, \@LocalStorageLink, or \@LocalStorageProp decorated variable in its parent component.|
| Subnode initialization | Supported; can be used to initialize a regular variable or \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access| Private, accessible only within the component.               |


  **Figure 1** Initialization rule 


![en-us_image_0000001552972029](figures/en-us_image_0000001552972029.png)


## Observed Changes and Behavior


### Observed Changes

\@Prop decorated variables can observe the following changes:

- When the decorated variable is of the string, number, Boolean, or enum type, its value change can be observed.

  ```ts
  // Simple type
  @Prop count: number;
  // The value assignment can be observed.
  this.count = 1;
  ```

For synchronization between \@State and \@Prop decorated variables:

- The value of an \@State decorated variable in the parent component initializes an \@Prop decorated variable in the child component. The \@State decorated variable also updates the @Prop decorated variable whenever the value of the former changes.

- Changes to the @Prop decorated variable do not affect the value of its source @State decorated variable.

- In addition to \@State, the source can also be decorated with \@Link or \@Prop, where the mechanisms for syncing the \@Prop would be the same.

- The type of the source and the @Prop decorated variable must be the same.


### Framework Behavior

To understand the value initialization and update mechanism of the \@Prop decorated variable, it is necessary to consider the parent component and the initial render and update process of the child component that owns the \@Prop decorated variable.

1. Initial render:
   1. The execution of the parent component's **build()** function creates a new instance of the child component, and the parent component provides a source for the @Prop decorated variable.
   2. The @Prop decorated variable is initialized.

2. Update:
   1. When the @Prop decorated variable is modified locally, the change remains local and does not propagate back to its parent component.
   2. When the data source of the parent component is updated, the \@Prop decorated variable in the child component is reset, and its local value changes are overwritten.


## Application Scenarios


### Simple Type @Prop Synced from @State in Parent Component


In this example, the \@Prop decorated **count** variable in the **CountDownComponent** child component is initialized from the \@State decorated **countDownStartValue** variable in the **ParentComponent**. When **Try again** is touched, the value of the **count** variable is modified, but the change remains within the **CountDownComponent** and does not affect the **CountDownComponent**.


Updating **countDownStartValue** in the **ParentComponent** will update the value of the @Prop decorated **count**.



```ts
@Component
struct CountDownComponent {
  @Prop count: number;
  costOfOneAttempt: number = 1;

  build() {
    Column() {
      if (this.count > 0) {
        Text(`You have ${this.count} Nuggets left`)
      } else {
        Text('Game over!')
      }
      // Changes to the @Prop decorated variables are not synchronized to the parent component.
      Button(`Try again`).onClick(() => {
        this.count -= this.costOfOneAttempt;
      })
    }
  }
}

@Entry
@Component
struct ParentComponent {
  @State countDownStartValue: number = 10;

  build() {
    Column() {
      Text(`Grant ${this.countDownStartValue} nuggets to play.`)
      // Changes to the data source provided by the parent component are synchronized to the child component.
      Button(`+1 - Nuggets in New Game`).onClick(() => {
        this.countDownStartValue += 1;
      })
      // Updating the parent component will also update the child component.
      Button(`-1  - Nuggets in New Game`).onClick(() => {
        this.countDownStartValue -= 1;
      })

      CountDownComponent({ count: this.countDownStartValue, costOfOneAttempt: 2 })
    }
  }
}
```


In the preceding example:


1. On initial render, when the **CountDownComponent** child component is created, its @Prop decorated **count** variable is initialized from the \@State decorated **countDownStartValue** variable in the **ParentComponent**.

2. When the "+1" or "-1" button is touched, the @State decorated **countDownStartValue** of the **ParentComponent** changes. This will cause the **ParentComponent** to re-render. At the minimum, the **CountDownComponent** will be updated because of the changed **count** variable value.

3. Because of the changed **count** variable value, the **CountDownComponent** child component will re-render. At a minimum, the **if** statement's conditions (**this.counter> 0**) is-evaluated and the **\<Text>** child component inside the **if** would be updated.

4. When **Try again** in the **CountDownComponent** child component is touched, the value of the **count** variable is modified, but the change remains within the child component and does not affect the **countDownStartValue** in the parent component.

5. Updating **countDownStartValue** will overwrite the local value changes of the @Prop decorated **count** in the **CountDownComponent** child component.


### Simple Type @Prop Synced from @State Array Item in Parent Component


The \@State decorated array an array item in the parent component can be used as data source to initialize and update a @Prop decorated variable. In the following example, the \@State decorated array **arr** in the parent component **Index** initializes the \@Prop decorated **value** variable in the child component **Child**.



```ts
@Component
struct Child {
  @Prop value: number;

  build() {
    Text(`${this.value}`)
      .fontSize(50)
      .onClick(()=>{this.value++})
  }
}

@Entry
@Component
struct Index {
  @State arr: number[] = [1,2,3];

  build() {
    Row() {
      Column() {
        Child({value: this.arr[0]})
        Child({value: this.arr[1]})
        Child({value: this.arr[2]})

        Divider().height(5)

        ForEach(this.arr, 
          item => {
            Child({value: item})
          }, 
          item => item.toString()
        )
        Text('replace entire arr')
        .fontSize(50)
        .onClick(()=>{
          // Both arrays contain item "3".
          this.arr = this.arr[0] == 1 ? [3,4,5] : [1,2,3];
        })
      }
    }
  }
}
```


Initial render creates six instances of the **Child** component. Each \@Prop decorated variable is initialized with a copy of an array item. The **onclick** event handler of the **Child** component changes the local variable value.


Assume that we clicked so many times that all local values be '7'.



```
7
7
7
----
7
7
7
```


After **replace entire arr** is clicked, the following information is displayed:



```
3
4
5
----
7
4
5
```


- Changes made in the **Child** component are not synchronized to the parent component **Index**. Therefore, even if the values of the six instances of the **Child** component are 7, the value of **this.arr** in the **Index** component is still **[1,2,3]**.

- After **replace entire arr** is clicked, if **this.arr[0] == 1** is true, **this.arr** is set to **[3, 4, 5]**.

- Because **this.arr[0]** has been changed, the **Child({value: this.arr[0]})** component synchronizes the update of **this.arr[0]** to the instance's \@Prop decorated variable. The same happens for **Child({value: this.arr[1]})** and **Child({value: this.arr[2]})**.


- The change of **this.arr** causes **ForEach** to update: The array item with the ID **3** is retained in this update, array items with IDs **1** and **2** are deleted, and array items with IDs **4** and **5** are added. The array before and after the update is **[1, 2, 3]** and **[3, 4, 5]**, respectively. This implies that the **Child** instance generated for item **3** will be moved to the first place, but not updated. In this case, the component value corresponding to **3** is **7**, and the final render result of **ForEach** is **7**, **4**, and **5**.


### Class Object Type @Prop Synced from @State Class Object Attribute in Parent Component

In a library with one book and two users, each user can mark the book as read, and the marking does not affect the other user reader. Technically speaking, local changes to the \@Prop decorated **book** object do not sync back to the @State decorated **book** in the **Library** component.


```ts
class Book {
  public title: string;
  public pages: number;
  public readIt: boolean = false;

  constructor(title: string, pages: number) {
    this.title = title;
    this.pages = pages;
  }
}

@Component
struct ReaderComp {
  @Prop title: string;
  @Prop readIt: boolean;

  build() {
    Row() {
      Text(this.title)
      Text(`... ${this.readIt ? 'I have read' : 'I have not read it'}`)
        .onClick(() => this.readIt = true)
    }
  }
}

@Entry
@Component
struct Library {
  @State book: Book = new Book('100 secrets of C++', 765);

  build() {
    Column() {
      ReaderComp({ title: this.book.title, readIt: this.book.readIt })
      ReaderComp({ title: this.book.title, readIt: this.book.readIt })
    }
  }
}
```


### Simple Type @Prop with Local Initialization and No Sync from Parent Component

To enable an \@Component decorated component to be reusable, \@Prop allows for optional local initialization. This makes the synchronization with a variable in the parent component a choice, rather than mandatory. Providing a data source in the parent component is optional only when local initialization is provided for the \@Prop decorated variable.

The following example includes two @Prop decorated variables in child component.

- The @Prop decorated variable **customCounter** has no local initialization, and therefore it requires a synchronization source in its parent component. When the source value changes, the @Prop decorated variable is updated.

- The @Prop decorated variable **customCounter2** has local initialization. In this case, specifying a synchronization source in the parent component is allowed but not mandatory.


```ts
@Component
struct MyComponent {
  @Prop customCounter: number;
  @Prop customCounter2: number = 5;

  build() {
    Column() {
      Row() {
        Text(`From Main: ${this.customCounter}`).width(90).height(40).fontColor('#FF0010')
      }

      Row() {
        Button('Click to change locally !').width(480).height(60).margin({ top: 10 })
          .onClick(() => {
            this.customCounter2++
          })
      }.height(100).width(480)

      Row() {
        Text(`Custom Local: ${this.customCounter2}`).width(90).height(40).fontColor('#FF0010')
      }
    }
  }
}

@Entry
@Component
struct MainProgram {
  @State mainCounter: number = 10;

  build() {
    Column() {
      Row() {
        Column() {
          Button('Click to change number').width(480).height(60).margin({ top: 10, bottom: 10 })
            .onClick(() => {
              this.mainCounter++
            })
        }
      }

      Row() {
        Column()
        // customCounter must be initialized from the parent component due to lack of local initialization. Here, customCounter2 does not need to be initialized.
        MyComponent({ customCounter: this.mainCounter })
        // customCounter2 of the child component can also be initialized from the parent component. The value from the parent component overwrites the locally assigned value of customCounter2 during initialization.
        MyComponent({ customCounter: this.mainCounter, customCounter2: this.mainCounter })
      }.width('40%')
    }
  }
}
```
<!--no_check-->
