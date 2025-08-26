# \@Local Decorator: Representing the Internal State of Components
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

You can use \@Local, a variable decorator in state management V2, to observe the variable changes in custom components decorated by \@ComponentV2.

Before reading this topic, you are advised to read [\@ComponentV2](./arkts-new-componentV2.md).

>**NOTE**
>
> The \@Local decorator is supported since API version 12.
>
> This decorator can be used in atomic services since API version 12.

## Overview

\@Local establishes the internal state of custom components with change observation capabilities.

- Variables decorated by \@Local must be initialized inside the component declaration. They cannot be initialized externally..

- When a variable decorated by \@Local changes, the component that uses the variable is re-rendered.

- \@Local supports the following types: Primitive types: number, boolean, string<br>Object types: object, class<br>Built-in types: [Array](#decorating-variables-of-the-array-type), [Set](#decorating-variables-of-the-set-type), [Map](#decorating-variables-of-the-map-type), [Date](#decorating-variables-of-the-date-type)

- \@Local can observe only the variable it decorates. If the decorated variable is of the primitive type, it can observe value changes to the variable; if the decorated variable is of the object type, it can observe value changes to the entire object; if the decorated variable is of the array type, it can observe changes of the entire array and its items; if the decorated variable is of the built-in types, such as Array, Set, Map, and Date, it can observe changes caused by calling the APIs. For details, see [Observed Changes](#observed-changes).

- \@Local supports **null**, **undefined**, and [union types](#decorating-variables-of-the-union-type).

## Limitations of the \@State Decorator in State Management V1

In state management V1, the [\@State decorator](arkts-state.md) is used to define basic state variables within components. While these variables are typically used as internal state of components, their design presents a critical limitation: \@State decorated variables can be initialized externally, which means there is no guarantee their initial values will match the component's internal definitions. This creates potential inconsistencies in component state management.

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
  @State componentInfo: ComponentInfo = new ComponentInfo('Child', 1, 'Hello World'); // componentInfo provided by the parent component will override this initial value.

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
      Child({componentInfo: new ComponentInfo('Unknown', 0, 'Error')})
    }
  }
}
```

In the preceding code, the \@State decorated **componentInfo** variable in the **Child** component can be overridden during initialization through parameter passing by the parent component. However, the **Child** component remains unaware that its supposedly "internal" state has been modified externally�a scenario that complicates state management within components. This is where \@Local, a decorator that represents the internal state of components, comes into the picture.

## Decorator Description

| \@Local Variable Decorator| Description|
| ------------------- | ------------------------------------------------------------ |
| Decorator parameters| None.|
| Allowed variable types| Basic types, such as object, class, string, number, boolean, and enum, and built-in types such as Array, Date, Map, and Set. null, undefined, and union types.|
| Initial value for the decorated variable| Local initialization is required. External initialization is not allowed.|

## Variable Passing

| Behavior      | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Initialization from the parent component| Variables decorated by \@Local can only be initialized locally.   |
| Child component initialization  | Variables decorated by \@Local can initialize variables decorated by [\@Param](arkts-new-param.md) in child components.|

## Observed Changes

Variables decorated by \@Local are observable. When a decorated variable changes, the UI component bound to the variable will be re-rendered.

- When the decorated variable is of boolean, string, or number type, value changes to the variable can be observed.

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local count: number = 0;
    @Local message: string = 'Hello';
    @Local flag: boolean = false;
    build() {
      Column() {
        Text(`${this.count}`)
        Text(`${this.message}`)
        Text(`${this.flag}`)
        Button('change Local')
          .onClick(()=>{
            // For variables of primitive types, @Local can observe value changes to variables.
            this.count++;
            this.message += ' World';
            this.flag = !this.flag;
        })
      }
    }
  }
  ```

- When \@Local is used to decorate a variable of the class object type, only changes to the overall assignment of the class object can be observed. Direct observation of changes to class member property assignments is not supported. Observing class member properties requires the [\@ObservedV2](arkts-new-observedV2-and-trace.md) and [\@Trace](arkts-new-observedV2-and-trace.md) decorators. Note that before API version 19, \@Local cannot be used with class instance objects decorated by [\@Observed](./arkts-observed-and-objectlink.md). Since from API version 19, partial mixed usage of state management V1 and V2 is supported, allowing \@Local and \@Observed to be used together. For details, see [Mixing Use of State Management V1 and V2](../state-management/arkts-v1-v2-mixusage.md).

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
      @Local rawObject: RawObject = new RawObject('rawObject');
      @Local observedObject: ObservedObject = new ObservedObject('observedObject');
      build() {
        Column() {
          Text(`${this.rawObject.name}`)
          Text(`${this.observedObject.name}`)
          Button('change object')
            .onClick(() => {
              // Changes to the overall assignment of the class object can be observed.
              this.rawObject = new RawObject('new rawObject');
              this.observedObject = new ObservedObject('new observedObject');
          })
          Button('change name')
            .onClick(() => {
              // @Local does not support observation of changes to class member property assignments. Therefore, value changes of rawObject.name cannot be observed.
              this.rawObject.name = 'new rawObject name';
              // The name property of ObservedObject is decorated by @Trace. Therefore, value changes of observedObject.name can be observed.
              this.observedObject.name = 'new observedObject name';
          })
        }
      }
    }
    ```

- When @Local is used to decorate an array of a primitive type, changes to both the entire array and individual array items can be observed.

    ```ts
    @Entry
    @ComponentV2
    struct Index {
      @Local numArr: number[] = [1,2,3,4,5];  // @Local decorated 1D array
      @Local dimensionTwo: number[][] = [[1,2,3],[4,5,6]]; // @Local decorated 2D array
    
      build() {
        Column() {
          Text(`${this.numArr[0]}`)
          Text(`${this.numArr[1]}`)
          Text(`${this.numArr[2]}`)
          Text(`${this.dimensionTwo[0][0]}`)
          Text(`${this.dimensionTwo[1][1]}`)
          Button('change array item') // Button 1: modifies specific elements in the array.
            .onClick(() => {
              this.numArr[0]++;
              this.numArr[1] += 2;
              this.dimensionTwo[0][0] = 0;
              this.dimensionTwo[1][1] = 0;
            })
          Button('change whole array') // Button 2: replaces the entire array.
            .onClick(() => {
              this.numArr = [5,4,3,2,1];
              this.dimensionTwo = [[7,8,9],[0,1,2]];
            })
        }
      }
    }
    ```
    
- When \@Local is used to decorate a nested class or object array, changes of lower-level object properties cannot be observed. Observation of these lower-level object properties requires use of \@ObservedV2 and \@Trace decorators.

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
    @Local infoArr: Info[] = [new Info('Ocean', 28, 120), new Info('Mountain', 26, 20)];
    @Local originInfo: Info = new Info('Origin', 0, 0);
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
        Button('change infoArr item')
          .onClick(() => {
            // Because the name property is decorated by @Trace, it can be observed.
            this.infoArr[0].name = 'Win';
          })
        Button('change originInfo')
          .onClick(() => {
            // Because the originInfo variable is decorated by @Local, it can be observed.
            this.originInfo = new Info('Origin', 100, 100);
          })
        Button('change originInfo region')
          .onClick(() => {
            // Because the x and y properties are decorated by @Trace, it can be observed.
            this.originInfo.region.x = 25;
            this.originInfo.region.y = 25;
          })
      }
    }
  }
  ```

- When \@Local is used to decorate a variable of a built-in type, changes caused by both variable reassignment and API calls can be observed.

  | Type | Change-Triggering API                                             |
  | ----- | ------------------------------------------------------------ |
  | Array | push, pop, shift, unshift, splice, copyWithin, fill, reverse, sort |
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## Constraints

The \@Local decorator has the following constraints:

- \@Local can be used only in custom components decorated by [\@ComponentV2](arkts-new-componentV2.md).

  ```ts
  @ComponentV2
  struct MyComponent {
    @Local message: string = 'Hello World'; // Correct usage.
    build() {
    }
  }
  @Component
  struct TestComponent {
    @Local message: string = 'Hello World'; // Incorrect usage. An error is reported at compile time.
    build() {
    }
  }
  ```

- \@Local decorated variables represent internal state of components and cannot be initialized externally.

  ```ts
  @ComponentV2
  struct ChildComponent {
    @Local message: string = 'Hello World';
    build() {
    }
  }
  @ComponentV2
  struct MyComponent {
    build() {
      ChildComponent({ message: 'Hello' }) // Incorrect usage. An error is reported at compile time.
    }
  }
  ```

## Comparison Between \@Local and \@State

The following table compares the usage and functionality of \@Local and \@State.

|                    | \@State                      | \@Local                         |
| ------------------ | ---------------------------- | --------------------------------- |
| Feature              | None.                         | None.                      |
| Initialization from the parent component        | Optional.                 | Not allowed.          |
| Observation capability| Variables and top-level member properties can be observed, but lower-level member properties cannot.| The variable itself can be observed. Lower-level observation requires use of the \@Trace decorator.|
| Data transfer| It can be used as a data source to synchronize with the state variables in a child component.| It can be used as a data source to synchronize with the state variables in a child component.|

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
  info: Info = new Info('Tom', 25);
  @Local localInfo: Info = new Info('Tom', 25);
  build() {
    Column() {
      Text(`info: ${this.info.name}-${this.info.age}`) // Text1
      Text(`localInfo: ${this.localInfo.name}-${this.localInfo.age}`) // Text2
      Button('change info&localInfo')
        .onClick(() => {
          this.info = new Info('Lucy', 18); // Text1 is not updated.
          this.localInfo = new Info('Lucy', 18); // Text2 is updated.
      })
    }
  }
}
```

### Decorating Variables of the Array Type

When the decorated object is of the **Array** type, the following can be observed: (1) complete array reassignment; (2) array item changes caused by calling **push**, **pop**, **shift**, **unshift**, **splice**, **copyWithin**, **fill**, **reverse**, or **sort**.

```ts
@Entry
@ComponentV2
struct Index {
  @Local count: number[] = [1,2,3];

  build() {
    Row() {
      Column() {
        ForEach(this.count, (item: number) => {
          Text(`${item}`).fontSize(30)
          Divider()
        })
        Button('init array').onClick(() => {
          this.count = [9,8,7];
        })
        Button('push').onClick(() => {
          this.count.push(0);
        })
        Button('reverse').onClick(() => {
          this.count.reverse();
        })
        Button('fill').onClick(() => {
          this.count.fill(6);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```



### Decorating Variables of the Date Type

When the decorated object is of the **Date** type, the following changes can be observed: (1) complete **Date** object reassignment; (2) property changes caused by calling **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, or **setUTCMilliseconds**.

```ts
@Entry
@ComponentV2
struct DatePickerExample {
  @Local selectedDate: Date = new Date('2021-08-08'); // @Local decorated Date object

  build() {
    Column() {
      Button('set selectedDate to 2023-07-08') // Button 1: updates the date by creating an object.
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-07-08');
        })
      Button('increase the year by 1') // Button 2: increases the year by 1.
        .margin(10)
        .onClick(() => {
          this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
        })
      Button('increase the month by 1') // Button 3: increases the month by 1.
        .onClick(() => {
          this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
        })
      Button('increase the day by 1') // Button 4: increases the date by 1.
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

When the decorated object is of the **Map** type, the following changes can be observed: (1) complete **Map** object reassignment; (2) changes caused by calling **set**, **clear**, or **delete**.

```ts
@Entry
@ComponentV2
struct MapSample {
  @Local message: Map<number, string> = new Map([[0, 'a'], [1, 'b'], [3, 'c']]); // @Local decorated Map object

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string]) => { // Iterate over the key-value pairs of the Map object and render the UI.
          Text(`${item[0]}`).fontSize(30)
          Text(`${item[1]}`).fontSize(30)
          Divider()
        })
        Button('init map').onClick(() => { // Button 1: resets the Map object to its initial state.
          this.message = new Map([[0, 'a'], [1, 'b'], [3, 'c']]);
        })
        Button('set new one').onClick(() => { // Button 2: adds a key-value pair (4, "d").
          this.message.set(4, 'd');
        })
        Button('clear').onClick(() => { // Button 3: clears the Map object.
          this.message.clear();
        })
        Button('replace the first one').onClick(() => { // Button 4: updates or adds the element with key 0.
          this.message.set(0, 'aa');
        })
        Button('delete the first one').onClick(() => { // Button 5: deletes the element with key 0.
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

When the decorated object is of the **Set** type, the following changes can be observed: (1) complete **Set** object reassignment; (2) changes caused by calling **add**, **clear**, or **delete**.

```ts
@Entry
@ComponentV2
struct SetSample {
  @Local message: Set<number> = new Set([0, 1, 2, 3, 4]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string]) => { // Iterate over the key-value pairs of the Set object and render the UI.
          Text(`${item[0]}`).fontSize(30)
          Divider()
        })
        Button('init set').onClick(() => { // Button 1: updates the Set object to its initial state.
          this.message = new Set([0, 1, 2, 3, 4]);
        })
        Button('set new one').onClick(() => { // Button 2: adds element 5.
          this.message.add(5);
        })
        Button('clear').onClick(() => { // Button 3: clears the Set object.
          this.message.clear();
        })
        Button('delete the first one').onClick(() => { // Button 4: deletes element 0.
          this.message.delete(0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Decorating Variables of the Union Type

\@Local supports **null**, **undefined**, and union types. In the following example, **count** is of the **number | undefined** type. Clicking the buttons to change the type of **count** will trigger UI re-rendering.

```ts
@Entry
@ComponentV2
struct Index {
  @Local count: number | undefined = 10; // @Local decorated variable of the union type

  build() {
    Column() {
      Text(`count(${this.count})`)
      Button('change to undefined') // Button 1: sets count to undefined.
        .onClick(() => {
          this.count = undefined;
        })
      Button('change to number') // Button 2: updates count to number 10.
        .onClick(() => {
          this.count = 10;
      })
    }
  }
}
```

## FAQs

### Repeated Assignment of Complex Type Constants to State Variables Triggers Re-rendering

```ts
@Entry
@ComponentV2
struct Index {
  list: string[][] = [['a'], ['b'], ['c']];
  @Local dataObjFromList: string[] = this.list[0];

  @Monitor('dataObjFromList')
  onStrChange(monitor: IMonitor) {
    console.info('dataObjFromList has changed');
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

In the preceding example, every time the **Button('change to self')** component is clicked, assigning the same constant of type Array to a state variable of type Array triggers UI re-rendering. This is because in state management V2, a proxy is added to variables of the Date, Map, Set, and Array type decorated with state variable decorators, such as @Trace and @Local, to observe changes caused by API calls. 
When **list[0]** is reassigned, **dataObjFromList** is already of type Proxy, while **list[0]** is of type Array. Due to the type mismatch, the assignment and re-rendering are triggered.
To avoid unnecessary assignments and re-renders, use [UIUtils.getTarget()](./arkts-new-getTarget.md) to obtain the original value and compare it with the new value. If they are the same, skip the assignment.

Example of using **UIUtils.getTarget()**:

```ts
import { UIUtils } from '@ohos.arkui.StateManagement';

@Entry
@ComponentV2
struct Index {
  list: string[][] = [['a'], ['b'], ['c']];
  @Local dataObjFromList: string[] = this.list[0];

  @Monitor('dataObjFromList')
  onStrChange(monitor: IMonitor) {
    console.info('dataObjFromList has changed');
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

### Using animationTo Failed in State Management V2

In the following scenario, [animateTo](../../reference/apis-arkui/arkui-ts/ts-explicit-animation.md) cannot be directly used in state management V2.

```ts
@Entry
@ComponentV2
struct Index {
  @Local w: number = 50; // Width.
  @Local h: number = 50; // Height.
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // Values are changed additionally before the animation is executed.
          this.w = 100;
          this.h = 100;
          this.message = 'Hello World';
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            this.w = 200;
            this.h = 200;
            this.message = 'Hello ArkUI';
          })
        })
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.w)
      .height(this.h)
    }
  }
}
```

In the above code, the expected animation effect is as follows: The green rectangle transitions from 100 x 100 to 200 x 200, and the text changes from **Hello World** to **Hello ArkUI**. However, due to the current incompatibility between **animateTo** and state management V2's update mechanism, the additional modifications before the animation do not take effect. The actual animation effect is as follows: The green rectangle transitions from 50 x 50 to 200 x 200, and the text changes from **Hello** to **Hello ArkUI**.

![arkts-new-local-animateTo-1](figures/arkts-new-local-animateTo-1.gif)

Follow the method below to achieve the expected display effect temporarily.

```ts
@Entry
@ComponentV2
struct Index {
  @Local w: number = 50; // Width.
  @Local h: number = 50; // Height.
  @Local message: string = 'Hello';
  
  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // Values are changed additionally before the animation is executed.
          this.w = 100;
          this.h = 100;
          this.message = 'Hello Word';
          animateToImmediately({
            duration: 0
          }, () => {
          })
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            this.w = 200;
            this.h = 200;
            this.message = 'Hello ArkUI';
          })
        })
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.w)
      .height(this.h)
    }
  }
}
```

Use [animateToImmediately](../../reference/apis-arkui/arkui-ts/ts-explicit-animatetoimmediately.md) with **duration** of **0** to apply the additional modifications and then execute the original animation to achieve the expected effect.

![arkts-new-local-animateTo-2](figures/arkts-new-local-animateTo-2.gif)
