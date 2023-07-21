# \@Prop Decorator: One-Way Synchronization from Parent to Child Components


An \@Prop decorated variable can create one-way synchronization with a variable of its parent component. \@Prop decorated variables are mutable, but changes are not synchronized to the parent component.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Overview

For an \@Prop decorated variable, the value synchronization is uni-directional from the parent component to the owning component.

- An @Prop variable is allowed to be modified locally, but the change does not propagate back to its parent component.

- Whenever that data source changes, the @Prop decorated variable gets updated, and any locally made changes are overwritten. In other words, the value synchronization is from the parent component to the (owning) child component, but not from the other way around.


## Rules of Use

| \@Prop Decorator| Description                                      |
| ----------- | ---------------------------------------- |
| Decorator parameters      | None.                                       |
| Synchronization type       | One-way: from the data source provided by the parent component to the @Prop decorated variable. For details about the scenarios of nested types, see [Observed Changes](#observed-changes).|
| Allowed variable types  | Object, class, string, number, Boolean, enum, and array of these types.<br>**any** is not supported. A combination of simple and complex types is not supported. The **undefined** and **null** values are not allowed.<br>Date type.<br>For details about the scenarios of supported types, see [Observed Changes](#observed-changes).<br>The type must be specified.<br>**NOTE**<br>The Length, ResourceStr, and ResourceColor types are a combination of simple and complex types and therefore not supported.<br>Negative examples:<br>CompA ({ aProp: undefined })<br>CompA ({ aProp: null })<br>The type must be the same as that of the [data source](arkts-state-management-overview.md#basic-concepts). There are three cases:<br>- Synchronizing the \@Prop decorated variable from an \@State or other decorated variable. Example: [Simple Type @Prop Synced from @State in Parent Component](#simple-type-prop-synced-from-state-in-parent-component).<br>- Synchronizing the \@Prop decorated variable from the item of an \@State or other decorated array. Example: [Simple Type @Prop Synced from @State Array Item in Parent Component](#simple-type-prop-synced-from-state-array-item-in-parent-component).<br>- Synchronizing the \@Prop decorated variable from a state attribute of the Object or class type in the parent component. Example: [Class Object Type @Prop Synced from @State Class Object Attribute in Parent Component](#class-object-type-prop-synced-from-state-class-object-attribute-in-parent-component).|
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

- When the decorated variable is of the Object, class, string, number, Boolean, or enum type, its value change can be observed.

  ```ts
  // Simple type
  @Prop count: number;
  // The value assignment can be observed.
  this.count = 1;
  // Complex type
  @Prop count: Model;
  // The value assignment can be observed.
  this.title = new Model('Hi');
  ```

When the decorated variable is of the Object or class type, the value changes of attributes at the first layer can be observed, that is, the attributes that **Object.keys(observedObject)** returns.

```
class ClassA {
  public value: string;
  constructor(value: string) {
    this.value = value;
  }
}
class Model {
  public value: string;
  public a: ClassA;
  constructor(value: string, a: ClassA) {
    this.value = value;
    this.a = a;
  }
}

@Prop title: Model;
// The value changes at the first layer can be observed.
this.title.value = 'Hi'
// The value changes at the second layer cannot be observed.
this.title.a.value = 'ArkUi' 
```

In the scenarios of nested objects, if a class is decorated by \@Observed, the value changes of the class attribute can be observed.

```
@Observed
class ClassA {
  public value: string;
  constructor(value: string) {
    this.value = value;
  }
}
class Model {
  public value: string;
  public a: ClassA;
  constructor(value: string, a: ClassA) {
    this.value = value;
    this.a = a;
  }
}
@Prop title: Model;
// The value changes at the first layer can be observed.
this.title.value = 'Hi'
// The value change of the ClassA attribute can be observed because ClassA is decorated by @Observed. this.title.a.value = 'ArkUi'.
```

When the decorated variable is of the array type, the value assignment, addition, deletion, and updates of array items can be observed.

```
// When the object decorated by @State is an array
@Prop title: string[]
// The value assignment of the array itself can be observed.
this.title = ['1']
// The value assignment of array items can be observed.
this.title[0] = '2'
// The deletion of array items can be observed.
this.title.pop()
// The addition of array items can be observed.
this.title.push('3')
```

For synchronization between \@State and \@Prop decorated variables:

- The value of an \@State decorated variable in the parent component initializes an \@Prop decorated variable in the child component. The \@State decorated variable also updates the @Prop decorated variable whenever the value of the former changes.
- Changes to the @Prop decorated variable do not affect the value of its source @State decorated variable.
- In addition to \@State, the source can also be decorated with \@Link or \@Prop, where the mechanisms for syncing the \@Prop would be the same.
- The source and \@Prop decorated variable must be of the same type. The \@Prop decorated variable can be of simple and class types.

- When the decorated variable is of the Date type, the overall value assignment of the Date object can be observed, and the following APIs can be called to update Date attributes: **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, and **setUTCMilliseconds**.

```ts
@Component
struct DateComponent {
  @Prop selectedDate: Date;

  build() {
    Column() {
      Button('child update the new date')
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-09-09')
        })
      Button(`child increase the year by 1`).onClick(() => {
        this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1)
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
struct ParentComponent {
  @State parentSelectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('parent update the new date')
        .margin(10)
        .onClick(() => {
          this.parentSelectedDate = new Date('2023-07-07')
        })
      Button('parent increase the day by 1')
        .margin(10)
        .onClick(() => {
          this.parentSelectedDate.setDate(this.parentSelectedDate.getDate() + 1)
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.parentSelectedDate
      })

      DateComponent({selectedDate:this.parentSelectedDate})
    }

  }
}
```

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

In this example, the \@Observed decorator can be applied to the **book** class, but it is not mandatory. It is only needed for nested structures. This will be further explained in [Class Type @Prop Synced from @State Array Item in Parent Component](#class-type-prop-synced-from-state-array-item-in-parent-component).


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
  @Prop book: Book;

  build() {
    Row() {
      Text(this.book.title)
      Text(`...has${this.book.pages} pages!`)
      Text(`...${this.book.readIt ? "I have read" : 'I have not read it'}`)
        .onClick(() => this.book.readIt = true)
    }
  }
}

@Entry
@Component
struct Library {
  @State book: Book = new Book('100 secrets of C++', 765);

  build() {
    Column() {
      ReaderComp({ book: this.book })
      ReaderComp({ book: this.book })
    }
  }
}
```

### Class Type @Prop Synced from @State Array Item in Parent Component

In the following example, an attribute of the **Book** object in the \@State decorated **allBooks** array is changed, but the system does not respond when **Mark read for everyone** is clicked. This is because the attribute is a nested attribute of the second layer, and the \@State decorator can observe only the attribute of the first layer. Therefore, the framework does not update **ReaderComp**.

```
let nextId: number = 1;

// @Observed
class Book {
  public id: number;
  public title: string;
  public pages: number;
  public readIt: boolean = false;

  constructor(title: string, pages: number) {
    this.id = nextId++;
    this.title = title;
    this.pages = pages;
  }
}

@Component
struct ReaderComp {
  @Prop book: Book;

  build() {
    Row() {
      Text(this.book.title)
      Text(`...has${this.book.pages} pages!`)
      Text(`...${this.book.readIt ? "I have read" : 'I have not read it'}`)
        .onClick(() => this.book.readIt = true)
    }
  }
}

@Entry
@Component
struct Library {
  @State allBooks: Book[] = [new Book("100 secrets of C++", 765), new Book("Effective C++", 651), new Book("The C++ programming language", 1765)];

  build() {
    Column() {
      Text('library`s all time favorite')
      ReaderComp({ book: this.allBooks[2] })
      Divider()
      Text('Books on loaan to a reader')
      ForEach(this.allBooks, book => {
        ReaderComp({ book: book })
      },
        book => book.id)
      Button('Add new')
        .onClick(() => {
          this.allBooks.push(new Book("The C++ Standard Library", 512));
        })
      Button('Remove first book')
        .onClick(() => {
          this.allBooks.shift();
        })
      Button("Mark read for everyone")
        .onClick(() => {
          this.allBooks.forEach((book) => book.readIt = true)
        })
    }
  }
}
```

 To observe the attribute of the **Book** object, you must use \@Observed to decorate the **Book** class. Note that the \@Prop decorated state variable in the child component is one-way synchronized from the data source of the parent component. This means that, the changes of the \@Prop decorated **book** in **ReaderComp** is not synchronized to the parent **library** component. The parent component triggers UI re-rendering only when the value is updated (compared with the last state).

```
@Observed
class Book {
  public id: number;
  public title: string;
  public pages: number;
  public readIt: boolean = false;

  constructor(title: string, pages: number) {
    this.id = nextId++;
    this.title = title;
    this.pages = pages;
  }
}
```

All instances of the \@Observed decorated class are wrapped with an opaque proxy object. This proxy can detect all attribute changes inside the wrapped object. If any attribute change happens, the proxy notifies the \@Prop, and the \@Prop value will be updated.

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
