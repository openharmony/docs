# \@Param Decorator: Inputting External Parameters to Components


You can use \@Param, a variable decorator in state management V2, to enhance the capability of child components to receive external parameter input.


\@Param can receive not only the external input of the component, but also the synchronous change of \@Local. Before reading this topic, you are advised to read [\@Local](./arkts-new-local.md).

> **NOTE**
>
> The \@Param decorator is supported since API version 12.
>

## Overview

\@Param indicates the state passed in from the external, ensuring that data can be synchronized between the parent and child components.

- Variables decorated by \@Param can be initialized locally, but cannot be changed within the component.

- \@Param decorated variables can be passed in from the external when initializing a custom component. When the data source is also a state variable, changes of the data source will be synchronized to \@Param.
- \@Param can accept data sources of any type, including common variables, state variables, constants, and function return values.
- When an \@Param decorated variable changes, the component associated with the variable will be re-rendered.
- \@Param can observe basic types such as number, boolean, string, object, and class and built-in types such as Array, Set, Map, and Date.
- For complex types such as class objects, \@Param accepts references from the data source. You can change the class object properties in the component and this change will be synchronized to the data source.
- \@Param can only observe the decorated variables. When a simple type is decorated, the overall change of variables can be observed. When an object type is decorated, only the overall change of the object can be observed. When an array type is decorated, the overall change of the entire array and its elements can be observed. When the built-in types such as Array, Set, Map, and Date are decorated, the changes brought by API invoking can be observed. For details, see [Observed Changes](#observed-changes).
- \@Param supports null, undefined, and union types.


## Limitations of State Management V1 to Accept Decorators Passed in Externally
The state management V1 has multiple decorators that can be passed in from external systems. The common-used decorators are \@State, \@Prop, \@Link, and \@ObjectLink. These decorators have their own constraints and are difficult to be distinguished. When they are used improperly, they may cause performance problems.

```ts
@Observed
class Region {
  x: number;
  y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}
@Observed
class Info {
  region: Region;
  constructor(x: number, y: number) {
    this.region = new Region(x, y);
  }
}
@Entry
@Component
struct Index {
  @State info: Info = new Info(0, 0);
  
  build() {
    Column() {
      Button("change Info")
        .onClick(() => {
          this.info = new Info(100, 100);
      })
      Child({
        region: this.info.region,
        regionProp: this.info.region,
        infoProp: this.info,
        infoLink: this.info,
        infoState: this.info
      })
    }
  }
}
@Component
struct Child {
  @ObjectLink region: Region;
  @Prop regionProp: Region;
  @Prop infoProp: Info;
  @Link infoLink: Info;
  @State infoState: Info = new Info(1, 1);
  build() {
    Column() {
      Text(`ObjectLink region: ${this.region.x}-${this.region.y}`)
      Text(`Prop regionProp: ${this.regionProp.x}-${this.regionProp.y}`)
    }
  }
}
```

In the preceding example, \@State can obtain the reference of **info** only during initialization. After **info** is changed, synchronization cannot be performed. \@Prop supports one-way synchronization, but the deep copy performance is still poor for complex types. \@Link can synchronize the input reference in a two-way manner, but it requires that the data source be also a state variable. Therefore, it cannot accept the member property **region** in **info**. \@ObjectLink can accept the class member property which must be decorated by \@Observed. Different constraints of the decorator make the rules for transferring values between parent and child components complex and difficult to use. This is where \@Param, a decorator that indicates the component state passed in from the external, comes into the picture.

## Decorator Description

| \@Param Variable Decorator | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Parameter        | None.                                                        |
| Allowed local modification      | No. To change the value, use the [\@Event](./arkts-new-event.md) decorator.                       |
| Synchronization type          | One-way synchronization from the parent to the child component.                                          |
| Allowed variable types| Basic types such as object, class, string, number, boolean, and enum and embedded types such as Array, Date, Map, and Set. Null, undefined, and union types are supported.|
| Initial value for the decorated variable| Local initialization is allowed. If local initialization is not performed, this parameter must be used together with the [\@Require](./arkts-require.md) decorator and initialization must be passed from the external.|

## Variable Passing

| Passing Rules      | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Initialization from the parent component| \@Param decorated variables can be initialized locally. If local initialization does not performed, the variables must be initialized from the external. When both the local initial value and external input value exist, the latter is preferentially used for initialization.|
| Child component initialization  | \@Param decorated variables can initialize themselves in the child components.      |
| Synchronization          | \@Param can be synchronized with the state variable data source passed in by the parent component (that is, the variable decorated by \@Local or \@Param). When the data source changes, the changes will be synchronized to \@Param of the child component.|

## Observed Changes

\@Param decorated variables enjoys observation capability. When a decorated variable changes, the UI component bound to the variable will be re-rendered.

- When the decorated variable type is boolean, string, or number, you can observe the changes synchronized from the data source.

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local count: number = 0;
    @Local message: string = "Hello";
    @Local flag: boolean = false;
    build() {
      Column() {
        Text(`Local ${this.count}`)
        Text(`Local ${this.message}`)
        Text(`Local ${this.flag}`)
        Button("change Local")
          .onClick(()=>{
            // Changes to the data source will be synchronized to the child component.
            this.count++;
            this.message += " World";
            this.flag = !this.flag;
        })
        Child({
          count: this.count,
          message: this.message,
          flag: this.flag
        })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param count: number;
    @Require @Param message: string;
    @Require @Param flag: boolean;
    build() {
      Column() {
        Text(`Param ${this.count}`)
        Text(`Param ${this.message}`)
        Text(`Param ${this.flag}`)
      }
    }
  }
  ```

- When the decorated variable is of a class object type, only the overall value changes to the class object can be observed. To observe value changes to the member properties in the class object, use the \@ObservedV2 and \@Trace decorators.

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
            // Overall changes to the class object can be observed.
            this.rawObject = new RawObject("new rawObject");
            this.observedObject = new ObservedObject("new observedObject");
        })
        Button("change name")
          .onClick(() => {
            // \@Local and \@Param cannot observe the class object properties. Therefore, the changes of rawObject.name cannot be observed.
            this.rawObject.name = "new rawObject name";
            // The name property of ObservedObject is decorated by @Trace. Therefore, the changes of observedObject.name can be observed.
            this.observedObject.name = "new observedObject name";
        })
        Child({
          rawObject: this.rawObject,
          observedObject: this.observedObject
        })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param rawObject: RawObject;
    @Require @Param observedObject: ObservedObject;
    build() {
      Column() {
        Text(`${this.rawObject.name}`)
        Text(`${this.observedObject.name}`)
      }
    }
    
  }
  ```

- When the decorated variable type is a simple array, you can observe the changes of the entire array or the array items.

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
        Child({
          numArr: this.numArr,
          dimensionTwo: this.dimensionTwo
        })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param numArr: number[];
    @Require @Param dimensionTwo: number[][];
    
    build() {
      Column() {
        Text(`${this.numArr[0]}`)
        Text(`${this.numArr[1]}`)
        Text(`${this.numArr[2]}`)
        Text(`${this.dimensionTwo[0][0]}`)
        Text(`${this.dimensionTwo[1][1]}`)
      }
    }
  }
  ```

- When the decorated variable is of a nested class or is an object array, \@Param cannot observe the change of lower-level object attributes. Observation of lower-level object attributes requires the use of \@ObservedV2 and \@Trace decorators.

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
            // Because the variable originInfo is decorated by @Local, it can be observed.
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
  @ComponentV2
  struct Child {
    @Param infoArr: Info[] = [];
    @Param originInfo: Info = new Info("O", 0, 0);
  
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
      }
    }
  }
  ```

- When the decorated variable is of a built-in type, you can observe the overall value assignment of the variable and the changes caused by API invoking.

  | Type | Observable APIs                                             |
  | ----- | ------------------------------------------------------------ |
  | Array | push, pop, shift, unshift, splice, copyWithin, fill, reverse, sort|
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## Constraints

The \@Param decorator has the following constraints:

- The \@Param decorator can be used only in custom components decorated by \@ComponentV2.

  ```ts
  @ComponentV2
  struct MyComponent {
    @Param message: string = "Hello World"; // Correct usage.
    build() {
    }
  }
  @Component
  struct TestComponent {
    @Param message: string = "Hello World"; // Incorrect usage. An error is reported during compilation.
    build() {
    }
  }
  ```

- The \@Param decorated variable indicates the external input of the component and needs to be initialized. The local initial value can be used for initialization. But if the external input value exists, it is preferentially used for initialization. It is not allowed to use neither the local initial value nor the external input value.

  ```ts
  @ComponentV2
  struct ChildComponent {
    @Param param1: string = "Initialize local";
    @Param param2: string = "Initialize local and put in";
    @Require @Param param3: string;
    @Param param4: string; // Incorrect usage. The external initialization is not performed and no initial value exists in the local host. As a result, an error is reported during compilation.
    build() {
      Column() {
        Text(`${this.param1}`) // Local initialization. "Initialize local" is displayed.
        Text(`${this.param2}`) // External initialization. "Put in" is displayed.
        Text(`${this.param3}`) // External initialization. "Put in" is displayed.
      }
    }
  }
  @Entry
  @ComponentV2
  struct MyComponent {
    @Local message: string = "Put in";
    build() {
      Column() {
        ChildComponent({
          param2: this.message,
          param3: this.message
        })
      }
    }
  }
  ```

- The \@Param decorated variables cannot be changed in the child component. However, when the decorated variable is of object type, changing the object properties in the child component is allowed.

  ```ts
  @ObservedV2
  class Info {
    @Trace name: string;
    constructor(name: string) {
      this.name = name;
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local info: Info = new Info("Tom");
    build() {
      Column() {
        Text(`Parent info.name ${this.info.name}`)
        Button("Parent change info")
          .onClick(() => {
            // If the @Local decorated variable of the parent component is changed, the @Param decorated variable is synchronized to the child component.
            this.info = new Info("Lucy");
        })
        Child({ info: this.info })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param info: Info;
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
        Button("change info")
          .onClick(() => {
            // Incorrect usage. The @Param decorated variable cannot be changed in the child component. An error is reported during compilation.
            this.info = new Info("Jack");
          })
        Button("Child change info.name")
          .onClick(() => {
            // The properties of an object can be changed in the child component and this change is synchronized to the data source of the parent component. When the properties are decorated by @Trace, the corresponding UI re-rendering is observable.
            this.info.name = "Jack";
          })
      }
    }
  }
  ```

## Use Scenarios

### Passing and Synchronizing Variables from the Parent Component to the Child Component

\@Param receives and synchronizes the data passed in by the \@Local or \@Param parent component in real time.

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
  @Trace name: string;
  @Trace age: number;
  @Trace region: Region;
  constructor(name: string, age: number, x: number, y: number) {
    this.name = name;
    this.age = age;
    this.region = new Region(x, y);
  }
}
@Entry
@ComponentV2
struct Index {
  @Local infoList: Info[] = [new Info("Alice", 8, 0, 0), new Info("Barry", 10, 1, 20), new Info("Cindy", 18, 24, 40)];
  build() {
    Column() {
      ForEach(this.infoList, (info: Info) => {
        MiddleComponent({ info: info })
      })
      Button("change")
        .onClick(() => {
          this.infoList[0] = new Info("Atom", 40, 27, 90);
          this.infoList[1].name = "Bob";
          this.infoList[2].region = new Region(7, 9);
        })
    }
  }
}
@ComponentV2
struct MiddleComponent {
  @Require @Param info: Info;
  build() {
    Column() {
      Text(`name: ${this.info.name}`)
      Text(`age: ${this.info.age}`)
      SubComponent({ region: this.info.region })
    }
  }
}
@ComponentV2
struct SubComponent {
  @Require @Param region: Region;
  build() {
    Column() {
      Text(`region: ${this.region.x}-${this.region.y}`)
    }
  }
}
```

### Decorating Variables of the Date Type

By using \@Param to decorate the variables of the Date type, you can observe the value changes to the entire **Date** and the changes brought by calling the **Date** APIs: **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, and **setUTCMilliseconds**.

```ts
@ComponentV2
struct DateComponent {
  @Param selectedDate: Date = new Date('2024-01-01');

  build() {
    Column() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate
      })
    }
  }
}

@Entry
@ComponentV2
struct ParentComponent {
  @Local parentSelectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('parent update the new date')
        .margin(10)
        .onClick(() => {
          this.parentSelectedDate = new Date('2023-07-07')
        })
      Button('increase the year by 1')
        .margin(10)
        .onClick(() => {
        this.parentSelectedDate.setFullYear(this.parentSelectedDate.getFullYear() + 1)
        })
      Button('increase the month by 1')
        .margin(10)
        .onClick(() => {
        this.parentSelectedDate.setMonth(this.parentSelectedDate.getMonth() + 1)
        })
      Button('parent increase the day by 1')
        .margin(10)
        .onClick(() => {
   this.parentSelectedDate.setDate(this.parentSelectedDate.getDate() + 1)
        })
      DateComponent({ selectedDate: this.parentSelectedDate })
    }
  }
}
```

### Decorating Variables of the Map Type

By using \@Param to decorate the variables of the **Map** type, you can observe the overall value changes to the entire **Map** and the changes brought by calling the **Map** APIs: set, clear, and delete.

```ts
@ComponentV2
struct Child {
  @Param value: Map<number, string> = new Map()

  build() {
    Column() {
      ForEach(Array.from(this.value.entries()), (item: [number, string]) => {
        Text(`${item[0]}`).fontSize(30)
        Text(`${item[1]}`).fontSize(30)
        Divider()
      })
    }
  }
}
@Entry
@ComponentV2
struct MapSample2 {
  @Local message: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]])

  build() {
    Row() {
      Column() {
        Child({ value: this.message })
        Button('init map').onClick(() => {
          this.message = new Map([[0, "a"], [1, "b"], [3, "c"]])
        })
        Button('set new one').onClick(() => {
          this.message.set(4, "d")
        })
        Button('clear').onClick(() => {
          this.message.clear()
        })
        Button('replace the first one').onClick(() => {
          this.message.set(0, "aa")
        })
        Button('delete the first one').onClick(() => {
          this.message.delete(0)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Decorating Variables of the Set Type

By using \@Param to decorate the variables of the **Set** type, you can observe the overall value changes to the entire **Set** and the changes brought by calling the **Set** APIs: add, clear, and delete.

```ts
@ComponentV2
struct Child {
  @Param message: Set<number> = new Set()

  build() {
    Column() {
      ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
        Text(`${item[0]}`).fontSize(30)
        Divider()
      })
    }
    .width('100%')
  }
}
@Entry
@ComponentV2
struct SetSample11 {
  @Local message: Set<number> = new Set([0, 1, 2, 3, 4])

  build() {
    Row() {
      Column() {
        Child({ message: this.message })
        Button('init set').onClick(() => {
          this.message = new Set([0, 1, 2, 3, 4])
        })
        Button('set new one').onClick(() => {
          this.message.add(5)
        })
        Button('clear').onClick(() => {
          this.message.clear()
        })
        Button('delete the first one').onClick(() => {
          this.message.delete(0)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Union Type

\@Param supports null, undefined, and union types. In the following example, the **count** type is of **number | undefined**. Click to change the **count** type, the UI will be re-rendered accordingly.

```ts
@Entry
@ComponentV2
struct Index {
  @Local count: number | undefined = 0;

  build() {
    Column() {
      MyComponent({ count: this.count })
      Button('change')
        .onClick(() => {
          this.count = undefined;
        })
    }
  }
}

@ComponentV2
struct MyComponent {
  @Param count: number | undefined = 0;

  build() {
    Column() {
      Text(`count(${this.count})`)
    }
  }
}
```
