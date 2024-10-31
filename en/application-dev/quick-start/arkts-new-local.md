# \@Local Decorator: Representing the Internal State of Components

You can use \@Local, a variable decorator in state management V2, to observe the variable changes in custom components decorated by \@ComponentV2.

>**NOTE**
>
>The \@Local decorator is supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.

## Overview

\@Local indicates the internal state of a component, which enables the variables in the custom component to observe changes:

- Variables decorated by \@Local cannot be initialized externally. They must be initialized inside the component.

- When a variable decorated by \@Local changes, the component that uses the variable is re-rendered.

- \@Local can observe basic types such as number, boolean, string, object, and class and built-in types such as Array, Set, Map, and Date.

- \@Local can observe only the variable it decorates. If the decorated variable is of the simple type, it can observe value changes to the variable; if the decorated variable is of the object type, it can observe value changes to the entire object; if the decorated variable is of the array type, it can observe changes of the entire array and its items; if the decorated variable is of the built-in types, such as Array, Set, Map, and Date, it can observe changes caused by calling the APIs. For details, see [Observed Changes](#observed-changes).

- \@Local supports null, undefined, and union types.

## Limitations of the \@State decorator in State Management V1

State management V1 uses the [\@State](arkts-state.md) decorator to define state variables in a class. However, because the \@State decorator allows variables to be initialized externally, it cannot accurately express the semantics that the internal state of the component cannot be modified externally.

```ts
class ComponentInfo {
  name: string;
  count: number;
  message: string;
  constructor(name: string, count: number, message: string) {
    this.name = name;
    this.count = count;
    this.message = message;
  }
}
@Component
struct Child {
  @State componentInfo: ComponentInfo = new ComponentInfo("Child", 1, "Hello World");

  build() {
    Column() {
      Text(`componentInfo.message is ${this.componentInfo.message}`)
    }
  }
}
@Entry
@Component
struct Index {
  build() {
    Column() {
      Child({componentInfo: new ComponentInfo("Unknown", 0, "Error")})
    }
  }
}
```

In the preceding code, the initialization of the **Child** component can pass in a new value to overwrite the local value of **componentInfo** that the component wants to use as an internal state variable. However, the **Child** component cannot detect that **componentInfo** has been initialized externally, which is inconvenient for managing the internal state of the component. This is where \@Local, a decorator that represents the internal state of components, comes into the picture.

## Decorator Description

| \@Local Variable Decorator| Description|
| ------------------- | ------------------------------------------------------------ |
| Decorator parameters| None.|
| Allowed variable types| Basic types, such as object, class, string, number, boolean, and enum, and built-in types such as Array, Date, Map, and Set. null, undefined, and union types.|
| Initial value for the decorated variable| Local initialization is required. External initialization is not allowed.|

## Variable Passing

| Passing Rules      | Description                                                     |
| -------------- | --------------------------------------------------------- |
| Initialization from the parent component| Variables decorated by \@Local can only be initialized locally.|
| Child component initialization  | Variables decorated by \@Local can initialize variables decorated by \@Param in the child components.   |

## Observed Changes

Variables decorated by \@Local are observable. When a decorated variable changes, the UI component bound to the variable will be re-rendered.

- When the decorated variable is of boolean, string, or number type, value changes to the variable can be observed.

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local count: number = 0;
    @Local message: string = "Hello";
    @Local flag: boolean = false;
    build() {
      Column() {
        Text(`${this.count}`)
        Text(`${this.message}`)
        Text(`${this.flag}`)
        Button("change Local")
          .onClick(()=>{
            // When @Local decorates a simple type, it can observe value changes to the variable.
            this.count++;
            this.message += " World";
            this.flag = !this.flag;
        })
      }
    }
  }
  ```

- When the decorated variable is of a class object type, only the overall value changes to the class object can be observed. To observe value changes to the member properties in the class object, you'll need the \@ObservedV2 and \@Trace decorators. Note that \@Local cannot be used together with the instance objects of the \@Observed decorated class.

    ```ts
    class RawObject {
      name: string;
      constructor(name: string) {
        this.name = name;
      }
    }
    @ObservedV2
    class ObservedObject {
      @Trace name: string;
      constructor(name: string) {
        this.name = name;
      }
    }
    @Entry
    @ComponentV2
    struct Index {
      @Local rawObject: RawObject = new RawObject("rawObject");
      @Local observedObject: ObservedObject = new ObservedObject("observedObject");
      build() {
        Column() {
          Text(`${this.rawObject.name}`)
          Text(`${this.observedObject.name}`)
          Button("change object")
            .onClick(() => {
              // Value changes to the class object can be observed.
              this.rawObject = new RawObject("new rawObject");
              this.observedObject = new ObservedObject("new observedObject");
          })
          Button("change name")
            .onClick(() => {
              // @Local does not have the capability of observing class object property. Therefore, value changes of rawObject.name cannot be observed.
              this.rawObject.name = "new rawObject name";
              // The name property of ObservedObject is decorated by @Trace. Therefore, value changes of observedObject.name can be observed.
              this.observedObject.name = "new observedObject name";
          })
        }
      }
    }
    ```

- When the decorated variable is of a simple array type, changes of the entire array or its items can be observed.

    ```ts
    @Entry
    @ComponentV2
    struct Index {
      @Local numArr: number[] = [1,2,3,4,5];
      @Local dimensionTwo: number[][] = [[1,2,3],[4,5,6]];
    
      build() {
        Column() {
          Text(`${this.numArr[0]}`)
          Text(`${this.numArr[1]}`)
          Text(`${this.numArr[2]}`)
          Text(`${this.dimensionTwo[0][0]}`)
          Text(`${this.dimensionTwo[1][1]}`)
          Button("change array item")
            .onClick(() => {
              this.numArr[0]++;
              this.numArr[1] += 2;
              this.dimensionTwo[0][0] = 0;
              this.dimensionTwo[1][1] = 0;
            })
          Button("change whole array")
            .onClick(() => {
              this.numArr = [5,4,3,2,1];
              this.dimensionTwo = [[7,8,9],[0,1,2]];
            })
        }
      }
    }
    ```
    
- When the decorated variable is of a nested type or an object array, changes of lower-level object properties cannot be observed. Observation of these lower-level object properties requires use of \@ObservedV2 and \@Trace decorators.

  ```ts
  @ObservedV2
  class Region {
    @Trace x: number;
    @Trace y: number;
    constructor(x: number, y: number) {
      this.x = x;
      this.y = y;
    }
  }
  @ObservedV2
  class Info {
    @Trace region: Region;
    @Trace name: string;
    constructor(name: string, x: number, y: number) {
      this.name = name;
      this.region = new Region(x, y);
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local infoArr: Info[] = [new Info("Ocean", 28, 120), new Info("Mountain", 26, 20)];
    @Local originInfo: Info = new Info("Origin", 0, 0);
    build() {
      Column() {
        ForEach(this.infoArr, (info: Info) => {
          Row() {
            Text(`name: ${info.name}`)
            Text(`region: ${info.region.x}-${info.region.y}`)
          }
        })
        Row() {
            Text(`Origin name: ${this.originInfo.name}`)
            Text(`Origin region: ${this.originInfo.region.x}-${this.originInfo.region.y}`)
        }
        Button("change infoArr item")
          .onClick(() => {
            // Because the name property is decorated by @Trace, it can be observed.
            this.infoArr[0].name = "Win";
          })
        Button("change originInfo")
          .onClick(() => {
            // Because the originInfo variable is decorated by @Local, it can be observed.
            this.originInfo = new Info("Origin", 100, 100);
          })
        Button("change originInfo region")
          .onClick(() => {
            // Because the x and y properties are decorated by @Trace, it can be observed.
            this.originInfo.region.x = 25;
            this.originInfo.region.y = 25;
          })
      }
    }
  }
  ```

- When the decorated variable is of a built-in type, you can observe the overall value changes of the variable and the changes caused by calling the APIs listed below. 

  | Type | Observable APIs                                             |
  | ----- | ------------------------------------------------------------ |
  | Array | push, pop, shift, unshift, splice, copyWithin, fill, reverse, sort|
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## Constraints

The \@Local decorator has the following constraints:

- The \@Local decorator can be used only in custom components decorated by \@ComponentV2.

  ```ts
  @ComponentV2
  struct CompA {
    @Local message: string = "Hello World"; // Correct usage.
    build() {
    }
  }
  @Component
  struct CompB {
    @Local message: string = "Hello World"; // Incorrect usage.
    build() {
    }
  }
  ```

- The variable decorated by \@Local indicates the internal state of the component and cannot be initialized externally.

  ```ts
  @ComponentV2
  struct CompA {
    @Local message: string = "Hello World";
    build() {
    }
  }
  @ComponentV2
  struct CompB {
    build() {
      CompA({ message: "Hello" }) // Incorrect usage.
    }
  }
  ```

## Comparison Between \@Local and \@State

The following table compares the usage and functions of \@Local and \@State.

|                    | \@State                      | \@Local                         |
| ------------------ | ---------------------------- | --------------------------------- |
| Parameter              | None.                         | None.                      |
| Initialization from the parent component        | Optional.                 | External initialization is not allowed.          |
| Observation capability| Variables and top-level member properties can be observed, but lower-level member properties cannot.| The variable itself can be observed. Lower-level observation requires use of \@Trace decorator.|
| Data Transfer| It can be used as a data source to synchronize with the state variables in a child component.| It can be used as a data source to synchronize with the state variables in a child component.|

## Use Scenarios

### Observing Overall Changes of Objects

When a class object and its properties are decorated by \@ObservedV2 and \@Trace, properties in the class object can be observed. However, value changes of the class object itself cannot be observed and do not initiate UI re-renders. In this case, you can use \@Local to decorate the object to observe the changes.

```ts
@ObservedV2
class Info {
  @Trace name: string;
  @Trace age: number;
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
@Entry
@ComponentV2
struct Index {
  info1: Info = new Info("Tom", 25);
  @Local info2: Info = new Info("Tom", 25);
  build() {
    Column() {
      Text(`info1: ${this.info1.name}-${this.info1.age}`) // Text1
      Text(`info2: ${this.info2.name}-${this.info2.age}`) // Text2
      Button("change info1&info2")
        .onClick(() => {
          this.info1 = new Info("Lucy", 18); // Text1 is not updated.
          this.info2 = new Info("Lucy", 18); // Text2 is updated.
      })
    }
  }
}
```

### Decorating Variables of the Date Type

When the decorated object is of the**Date** type, the overall value changes of **Date** can be observed. In addition, you can call the following APIs to update **Date** properties: **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, and **setUTCMilliseconds**.

```ts
@Entry
@ComponentV2
struct DatePickerExample {
  @Local selectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('set selectedDate to 2023-07-08')
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-07-08');
        })
      Button('increase the year by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
        })
      Button('increase the month by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
        })
      Button('increase the day by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setDate(this.selectedDate.getDate() + 1);
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

### Decorating Variables of the Map Type

When the decorated object is of the **Map** type, the overall value changes of **Map** can be observed. In addition, you can call the set, clear, and delete interfaces to update the data in **Map**.

```ts
@Entry
@ComponentV2
struct MapSample {
  @Local message: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
          Text(`${item[0]}`).fontSize(30)
          Text(`${item[1]}`).fontSize(30)
          Divider()
        })
        Button('init map').onClick(() => {
          this.message = new Map([[0, "a"], [1, "b"], [3, "c"]]);
        })
        Button('set new one').onClick(() => {
          this.message.set(4, "d");
        })
        Button('clear').onClick(() => {
          this.message.clear();
        })
        Button('replace the first one').onClick(() => {
          this.message.set(0, "aa");
        })
        Button('delete the first one').onClick(() => {
          this.message.delete(0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Decorating Variables of the Set Type

When the decorated object is **Set**, the overall value changes of **Set** can be observed. In addition, you can call the add, clear, and delete interfaces to update the data in **Set**.

```ts
@Entry
@ComponentV2
struct SetSample {
  @Local message: Set<number> = new Set([0, 1, 2, 3, 4]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
          Text(`${item[0]}`).fontSize(30)
          Divider()
        })
        Button('init set').onClick(() => {
          this.message = new Set([0, 1, 2, 3, 4]);
        })
        Button('set new one').onClick(() => {
          this.message.add(5);
        })
        Button('clear').onClick(() => {
          this.message.clear();
        })
        Button('delete the first one').onClick(() => {
          this.message.delete(0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Union Type

\@Local supports null, undefined, and union types. In the following example, the **count** type is **number | undefined**. If you click to change the **count** type, the UI will be re-rendered accordingly.

```ts
@Entry
@ComponentV2
struct Index {
  @Local count: number | undefined = 10;

  build() {
    Column() {
      Text(`count(${this.count})`)
      Button("change to undefined")
        .onClick(() => {
          this.count = undefined;
        })
      Button("change to number")
        .onClick(() => {
          this.count = 10;
      })
    }
  }
}
```

## FAQs

### Repeated Value Changes to State Variables by Complex Constants Trigger Re-rendering

```ts
@Entry
@ComponentV2
struct Index {
  list: string[][] = [['a'], ['b'], ['c']];
  @Local dataObjFromList: string[] = this.list[0];

  @Monitor("dataObjFromList")
  onStrChange(monitor: IMonitor) {
    console.log("dataObjFromList has changed");
  }

  build() {
    Column() {
      Button('change to self').onClick(() => {
        // The new value is the same as the locally initialized value.
        this.dataObjFromList = this.list[0];
      })
    }
  }
}
```

In the preceding example, each time you click Button('change to self'), the same constant of the **Array** type is assigned to a state variable of the same type, triggering re-rendering. This is because in state management V2, a proxy is added to Date, Map, Set, and Array that use state variable decorators such as @Trace and @Local to observe changes invoked by APIs. 
**dataObjFromList** is of a **Proxy** type but **list[0]** is of an **Array** type. As a result, when **list[0]** is assigned to **dataObjFromList**, the value changes trigger re-rendering. 
To avoid unnecessary value changes and re-renders, use [UIUtils.getTarget()](./arkts-new-getTarget.md) to obtain the original value and determine whether the original and new values are the same. If they are the same, do not perform value changes.

Example of Using **UIUtils.getTarget()**

```ts
import { UIUtils } from '@ohos.arkui.StateManagement';

@Entry
@ComponentV2
struct Index {
  list: string[][] = [['a'], ['b'], ['c']];
  @Local dataObjFromList: string[] = this.list[0];

  @Monitor("dataObjFromList")
  onStrChange(monitor: IMonitor) {
    console.log("dataObjFromList has changed");
  }

  build() {
    Column() {
      Button('change to self').onClick(() => {
        // Obtain the original value and compare it with the new value.
        if (UIUtils.getTarget(this.dataObjFromList) !== this.list[0]) {
          this.dataObjFromList = this.list[0];
        }
      })
    }
  }
}
```
