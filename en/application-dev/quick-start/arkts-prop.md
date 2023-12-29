# \@Prop Decorator: One-Way Synchronization from Parent to Child Components


An \@Prop decorated variable can create one-way synchronization with a variable of its parent component. This means that, such a variable is mutable, and its changes will not be synchronized to the parent component.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Overview

For an \@Prop decorated variable, the value synchronization is uni-directional from the parent component to the owning component.

- An @Prop variable is allowed to be modified locally, but the change does not propagate back to its parent component.

- Whenever that data source changes, the @Prop decorated variable gets updated, and any locally made changes are overwritten. In other words, the value is synchronized from the parent component to the (owning) child component, but not the other way around.



## Restrictions

- When decorating variables of complex types, @Prop makes a deep copy, during which all types, except primitive types, Map, Set, Date, and Array, will be lost.

- The \@Prop decorator cannot be used in custom components decorated by \@Entry.


## Rules of Use

| \@Prop Decorator| Description                                      |
| ----------- | ---------------------------------------- |
| Decorator parameters      | None.                                       |
| Synchronization type       | One-way: from the data source provided by the parent component to the @Prop decorated variable. For details about the scenarios of nested types, see [Observed Changes](#observed-changes).|
| Allowed variable types  | Object, class, string, number, Boolean, enum, and array of these types.<br>**undefined** or **null** (**any** is not supported).<br>Date type.<br>For details about the scenarios of supported types, see [Observed Changes](#observed-changes).<br>(Applicable to API version 11 and later versions) Union type of the preceding types, for example, string \| number, string \| undefined or ClassA \| null. For details, see [Union Type @Prop](#union-type-prop).<br>**NOTE**<br>When **undefined** or **null** is used, you are advised to explicitly specify the type to pass the TypeScipt type check. For example, @Prop a: string \| undefined = undefined is recommended; **@Prop a: string = undefined** is not recommended.<br>The union types Length, ResourceStr, and ResourceColor defined by the AkrUI framework are supported.<br>The type must be specified.<br>**NOTE**<br>The type must be the same as that of the [data source](arkts-state-management-overview.md#basic-concepts). There are three cases:<br>- Synchronizing the \@Prop decorated variable from an \@State or other decorated variable. Example: [Simple Type @Prop Synced from @State in Parent Component](#simple-type-prop-synced-from-state-in-parent-component).<br>- Synchronizing the \@Prop decorated variable from the item of an \@State or other decorated array. Example: [Simple Type @Prop Synced from @State Array Item in Parent Component](#simple-type-prop-synced-from-state-array-item-in-parent-component).<br>- Synchronizing the \@Prop decorated variable from a state property of the Object or class type in the parent component. Example: [Class Object Type @Prop Synced from @State Class Object Property in Parent Component](#class-object-type-prop-synced-from-state-class-object-property-in-parent-component).|
| Number of nested layers       | In component reuse scenarios, it is recommended that @Prop be nested with no more than five layers of data. If @Prop is nested with too many layers of data, garbage collection and increased memory usage caused by deep copy will follow, resulting in performance issues. To avoid such issues, use [\@ObjectLink](arkts-observed-and-objectlink.md) instead. If you do not want to synchronize the data of a child component to the parent component, consider using **aboutToReuse** in @Reusable to pass data from the parent component to the child component. For details, see [Component Reuse](arkts-state-management-best-practices.md)|
| Initial value for the decorated variable  | Local initialization is allowed.                                |


## Variable Transfer/Access Rules

| Transfer/Access    | Description                                      |
| --------- | ---------------------------------------- |
| Initialization from the parent component  | Optional if local initialization is used and mandatory otherwise. An @Prop decorated variable can be initialized from a regular variable (whose change does not trigger UI refresh) or an @State, @Link, @Prop, @Provide, @Consume, @ObjectLink, @StorageLink, @StorageProp, @LocalStorageLink, or @LocalStorageProp decorated variable in its parent component.|
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

When the decorated variable is of the Object or class type, the value changes of properties at the first layer can be observed, that is, the properties that **Object.keys(observedObject)** returns.

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

In the scenarios of nested objects, if a class is decorated by \@Observed, the value changes of the class property can be observed. For details, see [@Prop Nesting Scenario](#prop-nesting-scenario).

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

- When the decorated variable is of the Date type, the overall value assignment of the **Date** object can be observed, and the following APIs can be called to update **Date** properties: **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, and **setUTCMilliseconds**.

```ts
@Component
struct DateComponent {
  @Prop selectedDate: Date = new Date('');

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


In this example, the \@Prop decorated **count** variable in the **CountDownComponent** child component is initialized from the \@State decorated **countDownStartValue** variable in the **ParentComponent**. When **Try again** is touched, the value of the **count** variable is modified, but the change remains within the **CountDownComponent** and does not affect the **ParentComponent**.


Updating **countDownStartValue** in the **ParentComponent** will update the value of the @Prop decorated **count**.



```ts
@Component
struct CountDownComponent {
  @Prop count: number = 0;
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

2. When the "+1" or "-1" button is touched, the @State decorated **countDownStartValue** of the **ParentComponent** changes. This will cause the **ParentComponent** to re-render. At the minimum, the **CountDownComponent** will be updated because of the change in the **count** variable value.

3. Because of the change in the **count** variable value, the **CountDownComponent** child component will re-render. At a minimum, the **if** statement's condition (**this.counter> 0**) is evaluated, and the **\<Text>** child component inside the **if** statement would be updated.

4. When **Try again** in the **CountDownComponent** child component is touched, the value of the **count** variable is modified, but the change remains within the child component and does not affect the **countDownStartValue** in the parent component.

5. Updating **countDownStartValue** will overwrite the local value changes of the @Prop decorated **count** in the **CountDownComponent** child component.


### Simple Type @Prop Synced from @State Array Item in Parent Component


The \@State decorated array an array item in the parent component can be used as data source to initialize and update a @Prop decorated variable. In the following example, the \@State decorated array **arr** in the parent component **Index** initializes the \@Prop decorated **value** variable in the child component **Child**.



```ts
@Component
struct Child {
  @Prop value: number = 0;

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
          (item: number) => {
            Child({value: item})
          }, 
          (item: string) => item.toString()
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


Click **1**, **2**, and **3** so that all local values change to **'7'**.



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


- The change of **this.arr** causes **ForEach** to update: According to the diff algorithm, the array item with the ID **3** is retained in this update, array items with IDs **1** and **2** are deleted, and array items with IDs **4** and **5** are added. The array before and after the update is **[1, 2, 3]** and **[3, 4, 5]**, respectively. This implies that the **Child** instance generated for item **3** will be moved to the first place, but not updated. In this case, the component value corresponding to **3** is **7**, and the final render result of **ForEach** is **7**, **4**, and **5**.


### Class Object Type @Prop Synced from @State Class Object Property in Parent Component

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
  @Prop book: Book = new Book("", 0);

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

In the following example, a property of the **Book** object in the \@State decorated **allBooks** array is changed, but the system does not respond when **Mark read for everyone** is clicked. This is because the property is nested at the second layer, and the \@State decorator can observe only properties at the first layer. Therefore, the framework does not update **ReaderComp**.

```ts
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
  @Prop book: Book = new Book("", 1);

  build() {
    Row() {
      Text(this.book.title).fontColor('#e6000000')
      Text(` has ${this.book.pages} pages!`).fontColor('#e6000000')
      Text(` ${this.book.readIt ? "I have read" : 'I have not read it'}`).fontColor('#e6000000')
        .onClick(() => this.book.readIt = true)
    }
  }
}

@Entry
@Component
struct Library {
  @State allBooks: Book[] = [new Book("C#", 765), new Book("JS", 652), new Book("TS", 765)];

  build() {
    Column() {
      Text('library`s all time favorite')
        .width(312)
        .height(40)
        .backgroundColor('#0d000000')
        .borderRadius(20)
        .margin(12)
        .padding({ left: 20 })
        .fontColor('#e6000000')
      ReaderComp({ book: this.allBooks[2] })
        .backgroundColor('#0d000000')
        .width(312)
        .height(40)
        .padding({ left: 20, top: 10 })
        .borderRadius(20)
        .colorBlend('#e6000000')
      Divider()
      Text('Books on loaan to a reader')
        .width(312)
        .height(40)
        .backgroundColor('#0d000000')
        .borderRadius(20)
        .margin(12)
        .padding({ left: 20 })
        .fontColor('#e6000000')
      ForEach(this.allBooks, (book: Book) => {
        ReaderComp({ book: book })
          .margin(12)
          .width(312)
          .height(40)
          .padding({ left: 20, top: 10 })
          .backgroundColor('#0d000000')
          .borderRadius(20)
      },
        (book: Book) => book.id.toString())
      Button('Add new')
        .width(312)
        .height(40)
        .margin(12)
        .fontColor('#FFFFFF 90%')
        .onClick(() => {
          this.allBooks.push(new Book("JA", 512));
        })
      Button('Remove first book')
        .width(312)
        .height(40)
        .margin(12)
        .fontColor('#FFFFFF 90%')
        .onClick(() => {
          this.allBooks.shift();
        })
      Button("Mark read for everyone")
        .width(312)
        .height(40)
        .margin(12)
        .fontColor('#FFFFFF 90%')
        .onClick(() => {
          this.allBooks.forEach((book) => book.readIt = true)
        })
    }
  }
}
```

 To observe the property of the **Book** object, you must use \@Observed to decorate the **Book** class. Note that the \@Prop decorated state variable in the child component is one-way synchronized from the data source of the parent component. This means that, the changes of the \@Prop decorated **book** in **ReaderComp** is not synchronized to the parent **library** component. The parent component triggers UI re-rendering only when the value is updated (compared with the last state).

```ts
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

All instances of the \@Observed decorated class are wrapped with an opaque proxy object. This proxy can detect all property changes inside the wrapped object. If any property change happens, the proxy notifies the \@Prop, and the \@Prop value will be updated.

![Video-prop-UsageScenario-one](figures/Video-prop-UsageScenario-one.gif)

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
        Text(`From Main: ${this.customCounter}`).fontColor('#ff6b6565').margin({ left: -110, top: 12 })
      }

      Row() {
        Button('Click to change locally !')
          .width(288)
          .height(40)
          .margin({ left: 30, top: 12 })
          .fontColor('#FFFFFF, 90%')
          .onClick(() => {
            this.customCounter2++
          })
      }

      Row() {
        Text(`Custom Local: ${this.customCounter2}`).fontColor('#ff6b6565').margin({ left: -110, top: 12 })
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
          // customCounter must be initialized from the parent component due to lack of local initialization. Here, customCounter2 does not need to be initialized.
          MyComponent({ customCounter: this.mainCounter })
          // customCounter2 of the child component can also be initialized from the parent component. The value from the parent component overwrites the locally assigned value of customCounter2 during initialization.
          MyComponent({ customCounter: this.mainCounter, customCounter2: this.mainCounter })
        }
      }

      Row() {
        Column() {
          Button('Click to change number')
            .width(288)
            .height(40)
            .margin({ left: 30, top: 12 })
            .fontColor('#FFFFFF, 90%')
            .onClick(() => {
              this.mainCounter++
            })
        }
      }
    }
  }
}
```

![Video-prop-UsageScenario-two](figures/Video-prop-UsageScenario-two.gif)

### \@Prop Nesting Scenario

In nesting scenario, each layer must be decorated with @Observed, and each layer must be received by @Prop. In this way, the nested scenario can be observed.

```ts
// The following is the data structure of a nested class object.
@Observed
class ClassA {
  public title: string;

  constructor(title: string) {
    this.title = title;
  }
}

@Observed
class ClassB {
  public name: string;
  public a: ClassA;

  constructor(name: string, a: ClassA) {
    this.name = name;
    this.a = a;
  }
}
```

The following component hierarchy presents a data structure of nested @Prop.

```ts
@Entry
@Component
struct Parent {
  @State votes: ClassB = new ClassB('Hello', new ClassA('world'))

  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center }) {
        Button('change ClassB name')
          .width(312)
          .height(40)
          .margin(12)
          .fontColor('#FFFFFF, 90%')
          .onClick(() => {
            this.votes.name = "aaaaa"
          })
        Button('change ClassA title')
          .width(312)
          .height(40)
          .margin(12)
          .fontColor('#FFFFFF, 90%')
          .onClick(() => {
            this.votes.a.title = "wwwww"
          })
        Child({ vote: this.votes })
      }

    }

  }
}

@Component
struct Child {
  @Prop vote: ClassB = new ClassB('', new ClassA(''));

  build() {
    Column() {

      Text(this.vote.name)
        .fontSize(16)
        .margin(12)
        .width(312)
        .height(40)
        .backgroundColor('#ededed')
        .borderRadius(20)
        .textAlign(TextAlign.Center)
        .fontColor('#e6000000')
        .onClick(() => {
          this.vote.name = 'Bye'
        })
      Text(this.vote.a.title)
        .fontSize(16)
        .margin(12)
        .width(312)
        .height(40)
        .backgroundColor('#ededed')
        .borderRadius(20)
        .textAlign(TextAlign.Center)
        .onClick(() => {
          this.vote.a.title = "openHarmony"
        })
      Child1({ vote1: this.vote.a })

    }
  }
}

@Component
struct Child1 {
  @Prop vote1: ClassA = new ClassA('');

  build() {
    Column() {
      Text(this.vote1.title)
        .fontSize(16)
        .margin(12)
        .width(312)
        .height(40)
        .backgroundColor('#ededed')
        .borderRadius(20)
        .textAlign(TextAlign.Center)
        .onClick(() => {
          this.vote1.title = 'Bye Bye'
        })
    }
  }
}
```

![Video-prop-UsageScenario-three](figures/Video-prop-UsageScenario-three.gif)

## Union Type @Prop 

@Prop supports **undefined**, **null**, and union types. In the following example, the type of **count** is ClassA | undefined. If the property or type of **count** is changed when the button in the parent component **Library** is clicked, the change will be synced to the child component.

```ts
class Animals {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }
}

@Component
struct Child {
  @Prop animal: Animals | undefined;

  build() {
    Column() {
      Text(`Child's animal is  ${this.animal instanceof Animals ? this.animal.name : 'undefined'}`).fontSize(30)

      Button('Child change animals into tigers')
        .onClick(() => {
          // Assign the value of an instance of Animals.
          this.animal = new Animals("Tiger")
        })

      Button('Child change animal to undefined')
        .onClick(() => {
          // Assign the value undefined.
          this.animal = undefined
        })

    }.width('100%')
  }
}

@Entry
@Component
struct Library {
  @State animal: Animals | undefined = new Animals("lion");

  build() {
    Column() {
      Text(`Parents' animals are  ${this.animal instanceof Animals ? this.animal.name : 'undefined'}`).fontSize(30)

      Child({animal: this.animal})

      Button('Parents change animals into dogs')
        .onClick(() => {
          // Determine the animal type and update the property.
          if (this.animal instanceof Animals) {
            this.animal.name = "Dog"
          } else {
            console.info('num is undefined, cannot change property')
          }
        })

      Button('Parents change animal to undefined')
        .onClick(() => {
          // Assign the value undefined.
          this.animal = undefined
        })
    }
  }
}
```


## FAQs

### \@Prop Decorated State Variable Not Initialized

The \@Prop decorated state variable must be initialized. If not initialized locally, it must be initialized from the parent component. If it has been initialized locally, initialization from the parent component is optional.

[Nonexample]

```ts
@Observed
class ClassA {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  @Prop testNum: ClassA; // The state variable is not initialized locally.

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
      .onClick(() => {
        this.testNum.c += 1;
      })
  }
}

@Entry
@Component
struct Parent {
  @State testNum: ClassA[] = [new ClassA(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
        
      // The @Prop state variable is not initialized locally, nor initialized from the parent component.
      PropChild1()
    }
  }
}
```

[Example]

```ts
@Observed
class ClassA {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild1 {
  @Prop testNum: ClassA; // The state variable is not initialized locally.

  build() {
    Text(`PropChild1 testNum ${this.testNum.c}`)
      .onClick(() => {
        this.testNum.c += 1;
      })
  }
}
@Component
struct PropChild2 {
  @Prop testNum: ClassA = new ClassA(1); // The state variable is initialized locally.

  build() {
    Text(`PropChild2 testNum ${this.testNum.c}`)
      .onClick(() => {
        this.testNum.c += 1;
      })
  }
}

@Entry
@Component
struct Parent {
  @State testNum: ClassA[] = [new ClassA(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
        
      // @PropChild1 is not initialized locally and must be initialized from the parent component.
      PropChild1({ testNum: this.testNum[0] })
      // @PropChild2 is initialized locally. In this case, initialization from the parent component is optional.
      PropChild2()
      PropChild2({ testNum: this.testNum[0] })
    }
  }
}
```

<!--no_check-->
