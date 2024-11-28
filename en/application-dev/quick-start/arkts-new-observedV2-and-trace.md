# \@ObservedV2 and \@Trace Decorators: Observing Class Property Changes

To allow the state management framework to observe properties in class objects, you can use the \@ObservedV2 decorator and \@Trace decorator to decorate classes and properties in classes.

>**NOTE**
>
>The \@ObservedV2 and \@Trace decorators are supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.

## Overview

The \@ObservedV2 and \@Trace decorators are used to decorate classes and properties in classes so that changes to the classes and properties can be observed.

- \@ObservedV2 and \@Trace must come in pairs. Using either of them alone does not work.
- If a property decorated by \@Trace changes, only the component bound to the property is instructed to re-render.
- In a nested class, changes to its property trigger UI re-renders only when the property is decorated by \@Trace and the class is decorated by \@ObservedV2.
- In an inherited class, changes to a property of the parent or child class trigger UI re-renders only when the property is decorated by \@Trace and the owning class is decorated by \@ObservedV2.
- Attributes that are not decorated by \@Trace cannot detect changes nor trigger UI re-renders.
- Instances of \@ObservedV2 decorated classes cannot be serialized using **JSON.stringify**.

## Limitations of State Management V1 on Observability of Properties in Nested Class Objects

With state management V1, properties of nested class objects are not directly observable.

```ts
@Observed
class Father {
  son: Son;

  constructor(name: string, age: number) {
    this.son = new Son(name, age);
  }
}
@Observed
class Son {
  name: string;
  age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
@Entry
@Component
struct Index {
  @State father: Father = new Father("John", 8);

  build() {
    Row() {
      Column() {
        Text(`name: ${this.father.son.name} age: ${this.father.son.age}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            this.father.son.age++;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

In the preceding example, clicking the **Text** component increases the value of **age**, but does not trigger UI re-renders. The reason is that, the **age** property is in a nested class and not observable to the current state management framework. To resolve this issue, state management V1 uses [\@ObjectLink](arkts-observed-and-objectlink.md) with custom components.

```ts
@Observed
class Father {
  son: Son;

  constructor(name: string, age: number) {
    this.son = new Son(name, age);
  }
}
@Observed
class Son {
  name: string;
  age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
@Component
struct Child {
  @ObjectLink son: Son;

  build() {
    Row() {
      Column() {
        Text(`name: ${this.son.name} age: ${this.son.age}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            this.son.age++;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
@Entry
@Component
struct Index {
  @State father: Father = new Father("John", 8);

  build() {
    Column() {
      Child({son: this.father.son})
    }
  }
}
```

Yet, this approach has its drawbacks: If the nesting level is deep, the code becomes unnecessarily complicated and the usability poor. This is where the class decorator \@ObservedV2 and member property decorator \@Trace come into the picture.

## Decorator Description

| \@ObservedV2 Decorator| Description                                                 |
| ------------------ | ----------------------------------------------------- |
| Decorator parameters        | None.                                                   |
| Class decorator          | Decorates a class. You must use **new** to create a class object before defining the class.||

| \@Trace member property decorator| Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Decorator parameters           | None.                                                          |
| Allowed variable types         | Member properties in classes in any of the following types: number, string, boolean, class, Array, Date, Map, Set|

## Observed Changes

In classes decorated by \@ObservedV2, properties decorated by \@Trace are observable. This means that, any of the following changes can be observed and will trigger UI re-renders of bound components:

- Changes to properties decorated by \@Trace in nested classes decorated by \@ObservedV2

```ts
@ObservedV2
class Son {
  @Trace age: number = 100;
}
class Father {
  son: Son = new Son();
}
@Entry
@ComponentV2
struct Index {
  father: Father = new Father();

  build() {
    Column() {
      // If age is changed, the Text component is re-rendered.
      Text(`${this.father.son.age}`)
        .onClick(() => {
          this.father.son.age++;
        })
    }
  }
}

```

- Changes to properties decorated by \@Trace in inherited classes decorated by \@ObservedV2

```ts
@ObservedV2
class Father {
  @Trace name: string = "Tom";
}
class Son extends Father {
}
@Entry
@ComponentV2
struct Index {
  son: Son = new Son();

  build() {
    Column() {
      // If name is changed, the Text component is re-rendered.
      Text(`${this.son.name}`)
        .onClick(() => {
          this.son.name = "Jack";
        })
    }
  }
}
```

- Changes to static properties decorated by \@Trace in classes decorated by \@ObservedV2

```ts
@ObservedV2
class Manager {
  @Trace static count: number = 1;
}
@Entry
@ComponentV2
struct Index {
  build() {
    Column() {
      // If count is changed, the Text component is re-rendered.
      Text(`${Manager.count}`)
        .onClick(() => {
          Manager.count++;
        })
    }
  }
}
```

- Changes caused by the APIs listed below to properties of built-in types decorated by \@Trace

  | Type | APIs that can observe changes                                             |
  | ----- | ------------------------------------------------------------ |
  | Array | push, pop, shift, unshift, splice, copyWithin, fill, reverse, sort|
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## Constraints

Note the following constraints when using the \@ObservedV2 and \@Trace decorators:

- The member property that is not decorated by \@Trace cannot trigger UI re-renders.

```ts
@ObservedV2
class Person {
  id: number = 0;
  @Trace age: number = 8;
}
@Entry
@ComponentV2
struct Index {
  person: Person = new Person();

  build() {
    Column() {
      // age is decorated by @Trace and can trigger re-renders when used in the UI.
      Text(`${this.person.age}`)
      // id is not decorated by @Trace and cannot trigger re-renders when used in the UI.
      Text(`${this.person.id}`) // UI is not re-rendered when id changes.
    }
  }
}
```

- \@Trace cannot be used in classes that are not decorated by \@ObservedV2.

```ts
class User {
  id: number = 0;
  @Trace name: string = "Tom"; // Incorrect usage. An error is reported at compile time.
}
```

- \@Trace is a decorator for properties in classes and cannot be used in a struct.

```ts
@ComponentV2
struct Comp {
  @Trace message: string = "Hello World"; // Incorrect usage. An error is reported at compile time.

  build() {
  }
}
```

- \@ObservedV2 and \@Trace cannot be used together with [\@Observed](arkts-observed-and-objectlink.md) and [\@Track](arkts-track.md).

```ts
@Observed
class User {
  @Trace name: string = "Tom"; // Incorrect usage. An error is reported at compile time.
}

@ObservedV2
class Person {
  @Track name: string = "Jack"; // Incorrect usage. An error is reported at compile time.
}
```

- Classes decorated by @ObservedV2 and @Trace cannot be used together with [\@State](arkts-state.md) or other decorators of V1. Otherwise, an error is reported at compile time.

```ts
// @State is used as an example.
@ObservedV2
class Job {
  @Trace jobName: string = "Teacher";
}
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace age: number = 25;
  job: Job = new Job();
}
@Entry
@Component
struct Index {
  @State info: Info = new Info(); // As @State is not allowed here, an error is reported at compile time.

  build() {
    Column() {
      Text(`name: ${this.info.name}`)
      Text(`age: ${this.info.age}`)
      Text(`jobName: ${this.info.job.jobName}`)
      Button("change age")
        .onClick(() => {
          this.info.age++;
        })
      Button("Change job")
        .onClick(() => {
          this.info.job.jobName = "Doctor";
        })
    }
  }
}
```

- Classes extended from \@ObservedV2 cannot be used together with [\@State](arkts-state.md) or other decorators of V1. Otherwise, an error is reported during running.

```ts
// @State is used as an example.
@ObservedV2
class Job {
  @Trace jobName: string = "Teacher";
}
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace age: number = 25;
  job: Job = new Job();
}
class Message extends Info {
    constructor() {
        super();
    }
}
@Entry
@Component
struct Index {
  @State message: Message = new Message(); // As @State is not allowed here, an error is reported during running.

  build() {
    Column() {
      Text(`name: ${this.message.name}`)
      Text(`age: ${this.message.age}`)
      Text(`jobName: ${this.message.job.jobName}`)
      Button("change age")
        .onClick(() => {
          this.message.age++;
        })
      Button("Change job")
        .onClick(() => {
          this.message.job.jobName = "Doctor";
        })
    }
  }
}
```

- Instances of \@ObservedV2 decorated classes cannot be serialized using **JSON.stringify**.

## Use Scenarios

### Nested Class

In the following example, **Pencil** is the innermost class in the **Son** class. As **Pencil** is decorated by \@ObservedV2 and its **length** property is decorated by \@Trace, changes to **length** can be observed.

The example demonstrates how \@Trace is stacked up against [\@Track](arkts-track.md) and [\@State](arkts-state.md) under the existing state management framework: The @Track decorator offers property-level update capability for classes, but not deep observability; \@State can only observe the changes of the object itself and changes at the first layer; in multi-layer nesting scenarios, you must encapsulate custom components and use [\@Observed](arkts-observed-and-objectlink.md) and [\@ObjectLink](arkts-observed-and-objectlink.md) to observe the changes.

* Click **Button("change length")**, in which **length** is a property decorated by \@Trace. The change of **length** can trigger the re-render of the associated UI component, that is, **UINode (1)**, and output the log "isRender id: 1".
* Because **son** on the custom component **page** is a regular variable, no change is observed for clicks on **Button("assign Son")**.
* Clicks on **Button("assign Son")** and **Button("change length")** do not trigger UI re-renders. The reason is that, the change to **son** is not updated to the bound component.

```ts
@ObservedV2
class Pencil {
  @Trace length: number = 21; // If length changes, the bound component is re-rendered.
}
class Bag {
  width: number = 50;
  height: number = 60;
  pencil: Pencil = new Pencil();
}
class Son {
  age: number = 5;
  school: string = "some";
  bag: Bag = new Bag();
}

@Entry
@ComponentV2
struct Page {
  son: Son = new Son();
  renderTimes: number = 0;
  isRender(id: number): number {
    console.info(`id: ${id} renderTimes: ${this.renderTimes}`);
    this.renderTimes++;
    return 40;
  }

  build() {
    Column() {
      Text('pencil length'+ this.son.bag.pencil.length)
        .fontSize(this.isRender(1))   // UINode (1)
      Button("change length")
        .onClick(() => {
          // The value of length is changed upon a click, which triggers a re-render of UINode (1).
          this.son.bag.pencil.length += 100;
        })
      Button("assign Son")
        .onClick(() => {
          // Changes to the regular variable son do not trigger UI re-renders of UINode (1).
          this.son = new Son();
        })
    }
  }
}
```


### Inheritance

Properties in base or derived classes are observable only when decorated by \@Trace.
In the following example, classes **GrandFather**, **Father**, **Uncle**, **Son**, and **Cousin** are declared. The following figure shows the inheritance relationship.

![arkts-old-state-management](figures/arkts-new-observed-and-track-extend-sample.png)


Create instances of the **Son** and **Cousin** classes. Clicks on **Button('change Son age')** and **Button('change Cousin age')** can trigger UI re-renders.

```ts
@ObservedV2
class GrandFather {
  @Trace age: number = 0;

  constructor(age: number) {
    this.age = age;
  }
}
class Father extends GrandFather{
  constructor(father: number) {
    super(father);
  }
}
class Uncle extends GrandFather {
  constructor(uncle: number) {
    super(uncle);
  }
}
class Son extends Father {
  constructor(son: number) {
    super(son);
  }
}
class Cousin extends Uncle {
  constructor(cousin: number) {
    super(cousin);
  }
}
@Entry
@ComponentV2
struct Index {
  son: Son = new Son(0);
  cousin: Cousin = new Cousin(0);
  renderTimes: number = 0;

  isRender(id: number): number {
    console.info(`id: ${id} renderTimes: ${this.renderTimes}`);
    this.renderTimes++;
    return 40;
  }

  build() {
    Row() {
      Column() {
        Text(`Son ${this.son.age}`)
          .fontSize(this.isRender(1))
          .fontWeight(FontWeight.Bold)
        Text(`Cousin ${this.cousin.age}`)
          .fontSize(this.isRender(2))
          .fontWeight(FontWeight.Bold)
        Button('change Son age')
          .onClick(() => {
            this.son.age++;
          })
        Button('change Cousin age')
          .onClick(() => {
            this.cousin.age++;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Decorating an Array of a Built-in Type with \@Trace

With an array of a built-in type decorated by \@Trace, changes caused by supported APIs can be observed. For details about the supported APIs, see [Observed Changes](#observed-changes).
In the following example, the **numberArr** property in the \@ObservedV2 decorated **Arr** class is an \@Trace decorated array. If an array API is used to operate **numberArr**, the change caused can be observed. Perform length checks on arrays to prevent out-of-bounds access.

```ts
let nextId: number = 0;

@ObservedV2
class Arr {
  id: number = 0;
  @Trace numberArr: number[] = [];

  constructor() {
    this.id = nextId++;
    this.numberArr = [0, 1, 2];
  }
}

@Entry
@ComponentV2
struct Index {
  arr: Arr = new Arr();

  build() {
    Column() {
      Text(`length: ${this.arr.numberArr.length}`)
        .fontSize(40)
      Divider()
      if (this.arr.numberArr.length >= 3) {
        Text(`${this.arr.numberArr[0]}`)
          .fontSize(40)
          .onClick(() => {
            this.arr.numberArr[0]++;
          })
        Text(`${this.arr.numberArr[1]}`)
          .fontSize(40)
          .onClick(() => {
            this.arr.numberArr[1]++;
          })
        Text(`${this.arr.numberArr[2]}`)
          .fontSize(40)
          .onClick(() => {
            this.arr.numberArr[2]++;
          })
      }

      Divider()

      ForEach(this.arr.numberArr, (item: number, index: number) => {
        Text(`${index} ${item}`)
          .fontSize(40)
      })

      Button('push')
        .onClick(() => {
          this.arr.numberArr.push(50);
        })

      Button('pop')
        .onClick(() => {
          this.arr.numberArr.pop();
        })

      Button('shift')
        .onClick(() => {
          this.arr.numberArr.shift();
        })

      Button('splice')
        .onClick(() => {
          this.arr.numberArr.splice(1, 0, 60);
        })


      Button('unshift')
        .onClick(() => {
          this.arr.numberArr.unshift(100);
        })

      Button('copywithin')
        .onClick(() => {
          this.arr.numberArr.copyWithin(0, 1, 2);
        })

      Button('fill')
        .onClick(() => {
          this.arr.numberArr.fill(0, 2, 4);
        })

      Button('reverse')
        .onClick(() => {
          this.arr.numberArr.reverse();
        })

      Button('sort')
        .onClick(() => {
          this.arr.numberArr.sort();
        })
    }
  }
}
```

### Decorating an Object Array with \@Trace

* In the following example, the **personList** object array and the **age** property in the **Person** class are decorated by \@Trace. As such, changes to **personList** and **age** can be observed.
* Clicking the **Text** component changes the value of **age** and thereby triggers a UI re-render of the **Text** component

```ts
let nextId: number = 0;

@ObservedV2
class Person {
  @Trace age: number = 0;

  constructor(age: number) {
    this.age = age;
  }
}

@ObservedV2
class Info {
  id: number = 0;
  @Trace personList: Person[] = [];

  constructor() {
    this.id = nextId++;
    this.personList = [new Person(0), new Person(1), new Person(2)];
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  build() {
    Column() {
      Text(`length: ${this.info.personList.length}`)
        .fontSize(40)
      Divider()
      if (this.info.personList.length >= 3) {
        Text(`${this.info.personList[0].age}`)
          .fontSize(40)
          .onClick(() => {
            this.info.personList[0].age++;
          })

        Text(`${this.info.personList[1].age}`)
          .fontSize(40)
          .onClick(() => {
            this.info.personList[1].age++;
          })

        Text(`${this.info.personList[2].age}`)
          .fontSize(40)
          .onClick(() => {
            this.info.personList[2].age++;
          })
      }

      Divider()

      ForEach(this.info.personList, (item: Person, index: number) => {
        Text(`${index} ${item.age}`)
          .fontSize(40)
      })
    }
  }
}

```

### Decorating a Property of the Map Type with \@Trace

* With a property of the Map type decorated by \@Trace, changes caused by supported APIs, such as **set**, **clear**, and **delete**, can be observed.
* In the following example, the **Info** class is decorated by \@ObservedV2 and its **memberMap** property is decorated by \@Trace; as such, changes to the **memberMap** property caused by clicking **Button('init map')** can be observed.

```ts
@ObservedV2
class Info {
  @Trace memberMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]);
}

@Entry
@ComponentV2
struct MapSample {
  info: Info = new Info();

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.info.memberMap.entries()), (item: [number, string]) => {
          Text(`${item[0]}`)
            .fontSize(30)
          Text(`${item[1]}`)
            .fontSize(30)
          Divider()
        })
        Button('init map')
          .onClick(() => {
            this.info.memberMap = new Map([[0, "a"], [1, "b"], [3, "c"]]);
          })
        Button('set new one')
          .onClick(() => {
            this.info.memberMap.set(4, "d");
          })
        Button('clear')
          .onClick(() => {
            this.info.memberMap.clear();
          })
        Button('set the key: 0')
          .onClick(() => {
            this.info.memberMap.set(0, "aa");
          })
        Button('delete the first one')
          .onClick(() => {
            this.info.memberMap.delete(0);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Decorating a Property of the Set Type with \@Trace

* With a property of the Set type decorated by \@Trace, changes caused by supported APIs, such as **add**, **clear**, and **delete**, can be observed.
* In the following example, the **Info** class is decorated by \@ObservedV2 and its **memberSet** property is decorated by \@Trace; as such, changes to the **memberSet** property caused by clicking **Button('init set')** can be observed.

```ts
@ObservedV2
class Info {
  @Trace memberSet: Set<number> = new Set([0, 1, 2, 3, 4]);
}

@Entry
@ComponentV2
struct SetSample {
  info: Info = new Info();

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.info.memberSet.entries()), (item: [number, string]) => {
          Text(`${item[0]}`)
            .fontSize(30)
          Divider()
        })
        Button('init set')
          .onClick(() => {
            this.info.memberSet = new Set([0, 1, 2, 3, 4]);
          })
        Button('set new one')
          .onClick(() => {
            this.info.memberSet.add(5);
          })
        Button('clear')
          .onClick(() => {
            this.info.memberSet.clear();
          })
        Button('delete the first one')
          .onClick(() => {
            this.info.memberSet.delete(0);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


### Decorating a Property of the Date Type with \@Trace

* With a property of the Date type decorated by \@Trace, changes caused by the following APIs can be observed: setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds.
* In the following example, the **Info** class is decorated by \@ObservedV2 and its **selectedDate** property is decorated by \@Trace; as such, changes to the **selectedDate** property caused by clicking **Button('set selectedDate to 2023-07-08')** can be observed.

```ts
@ObservedV2
class Info {
  @Trace selectedDate: Date = new Date('2021-08-08')
}

@Entry
@ComponentV2
struct DateSample {
  info: Info = new Info()

  build() {
    Column() {
      Button('set selectedDate to 2023-07-08')
        .margin(10)
        .onClick(() => {
          this.info.selectedDate = new Date('2023-07-08');
        })
      Button('increase the year by 1')
        .margin(10)
        .onClick(() => {
          this.info.selectedDate.setFullYear(this.info.selectedDate.getFullYear() + 1);
        })
      Button('increase the month by 1')
        .margin(10)
        .onClick(() => {
          this.info.selectedDate.setMonth(this.info.selectedDate.getMonth() + 1);
        })
      Button('increase the day by 1')
        .margin(10)
        .onClick(() => {
          this.info.selectedDate.setDate(this.info.selectedDate.getDate() + 1);
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.info.selectedDate
      })
    }.width('100%')
  }
}
```
