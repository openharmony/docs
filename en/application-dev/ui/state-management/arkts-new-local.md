# \@Local Decorator: Representing the Internal State of Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2fe87adc16af5a903a1eb4a9624e4d36fa962e3d translatedAt=2026-07-25T08:57:05.799Z pushedAt=2026-07-25T09:21:44.734Z -->

To observe changes to variables in custom components decorated by @ComponentV2, developers can use the [@Local](../../reference/apis-arkui/arkui-ts/ts-state-management-local.md#local) decorator to decorate variables.

Before reading this document, you are advised to read [\@ComponentV2](./arkts-create-custom-components.md#componentv2). For details about common problems, see [In-Component State Management FAQs](./arkts-state-management-faq-inner-component.md).

>**NOTE**
>
> The \@Local decorator is supported since API version 12.
>
> This decorator can be used in atomic services since API version 12.
>
> This decorator can be used in ArkTS widgets since API version 23.

## Overview

\@Local establishes the internal state of custom components with change observation capabilities.

- Variables decorated by \@Local must be initialized inside the component declaration. They cannot be initialized externally.

- When a variable decorated by \@Local changes, the component that uses the variable is re-rendered.

- @Local supports observing primitive types such as number, boolean, string, Object, and class, as well as built-in types such as [Array](#decorating-variables-of-the-array-type), [Set](#decorating-variables-of-the-set-type), [Map](#decorating-variables-of-the-map-type), and [Date](#decorating-variables-of-the-date-type).

- The observation capability of @Local is limited to the decorated variable itself. When decorating a primitive type, it can observe assignments to the variable; when decorating an object type, it can observe only overall assignments to the object; when decorating an array type, it can observe changes to the array as a whole and to array elements; when decorating built-in types such as Array, Set, Map, and Date, it can observe changes brought by API calls. For details, see [Observing Changes](#observing-changes).

- \@Local supports **null**, **undefined**, and [union types](#decorating-variables-of-the-union-type).

## Limitations of the \@State Decorator in State Management V1

In state management V1, the [\@State decorator](arkts-state.md) is used to define basic state variables within components. While these variables are typically used as internal state of components, their design presents a critical limitation: \@State decorated variables can be initialized externally, which means there is no guarantee their initial values will match the component's internal definitions. This creates potential inconsistencies in component state management.

<!-- @[Local_V1_State_Decorator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalV1StateDecorator.ets) -->

``` TypeScript
class ComponentInfo {
  public name: string;
  public count: number;
  public message: string;

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
      Child({ componentInfo: new ComponentInfo('Unknown', 0, 'Error') })
    }
  }
}
```

In the preceding code, the \@State decorated **componentInfo** variable in the **Child** component can be overridden during initialization through parameter passing by the parent component. However, the **Child** component remains unaware that its supposedly "internal" state has been modified externally—a scenario that complicates state management within components. This is where \@Local, a decorator that represents the internal state of components, comes into the picture.

## Decorator Description

| \@Local Variable Decorator| Description|
| ------------------- | ------------------------------------------------------------ |
| Decorator parameters| None.|
| Decoratable variable type | Object, class, string, number, boolean, enum, and other basic types, as well as Array, Date, Map, Set, and other built-in types. Supports null, undefined, and union types. |
| Initial value for the decorated variable| Local initialization is required. External initialization is not allowed.|

## Variable Passing

| Behavior      | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Initialization from the parent component| Variables decorated by \@Local can only be initialized locally.   |
| Child component initialization  | Variables decorated by \@Local can initialize variables decorated by [\@Param](arkts-new-param.md) in child components.|

## Observing Changes

Variables decorated by \@Local are observable. When a decorated variable changes, the UI component bound to the variable will be re-rendered.

- When the decorated variable is of boolean, string, or number type, value changes to the variable can be observed.

  <!-- @[Local_Observe_Changes_Type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalObserveChangesType.ets) -->

  ``` TypeScript
  @Entry
  @ComponentV2
  struct Index {
    // Number of clicks.
    @Local count: number = 0;
    @Local message: string = 'Hello';
    @Local flag: boolean = false;
  
    build() {
      Column() {
        Text(`${this.count}`)
        Text(`${this.message}`)
        Text(`${this.flag}`)
        Button('change Local')
          .onClick(() => {
            // For variables of primitive types, @Local can observe value changes to variables.
            this.count++;
            this.message += ' World';
            this.flag = !this.flag;
          })
      }
    }
  }
  ```

- When the decorated variable is of a class object type, only overall assignments to the class object can be observed. Changes to class member properties cannot be directly observed. Observing class member properties relies on the [@ObservedV2](arkts-new-observedV2-and-trace.md) and [@Trace](arkts-new-observedV2-and-trace.md) decorators, or you can use [makeObserved](./arkts-new-makeObserved.md) to turn the object into an observed object. Note: Before API version 19, @Local cannot be used together with class instance objects decorated by [@Observed](./arkts-observed-and-objectlink.md). Starting from API version 19, partial interoperability between state management V1 and V2 is supported, allowing @Local and @Observed to be used together. For details, see [Guidelines for Using State Management V1 and V2 Together (API Version 19 and Later)](../../ui/state-management/arkts-v1-v2-mixusage.md).

    <!-- @[Local_Observe_Changes_Decorator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalObserveChangesDecorator.ets) -->

    ``` TypeScript
    class RawObject {
      public name: string;
    
      constructor(name: string) {
        this.name = name;
      }
    }
    
    @ObservedV2
    class ObservedObject {
      @Trace public name: string;
    
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

    <!-- @[Local_Observe_Changes_Array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalObserveChangesArray.ets) -->

    ``` TypeScript
    @Entry
    @ComponentV2
    struct Index {
      @Local numArr: number[] = [1, 2, 3, 4, 5]; // @Local decorated 1D array
      @Local dimensionTwo: number[][] = [[1, 2, 3], [4, 5, 6]]; // @Local decorated 2D array
    
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
              this.numArr = [5, 4, 3, 2, 1];
              this.dimensionTwo = [[7, 8, 9], [0, 1, 2]];
            })
        }
      }
    }
    ```

- When \@Local is used to decorate a nested class or object array, changes of lower-level object properties cannot be observed. Observation of these lower-level object properties requires use of \@ObservedV2 and \@Trace decorators.

  <!-- @[Local_Observe_Changes_DeepObject](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalObserveChangesDeepObject.ets) -->

  ``` TypeScript
  @ObservedV2
  class Region {
    @Trace public x: number;
    @Trace public y: number;
  
    constructor(x: number, y: number) {
      this.x = x;
      this.y = y;
    }
  }
  
  @ObservedV2
  class Info {
    @Trace public region: Region;
    @Trace public name: string;
  
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

  | Type | APIs That Can Be Observed                                             |
  | ----- | ------------------------------------------------------------ |
  | Array | push, pop, shift, unshift, splice, copyWithin, fill, reverse, sort |
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## Constraints

The \@Local decorator has the following constraints:

- The \@Local decorator can be used only in custom components decorated with the [\@ComponentV2](./arkts-create-custom-components.md#componentv2) decorator.

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

| Usage| \@State                      | \@Local                         |
| ------------------ | ---------------------------- | --------------------------------- |
| Parameters              | None.                         | None.                      |
| Initialization from the parent component        | Optional.                 | Not allowed.          |
| Observation capability| Variables and top-level member properties can be observed, but lower-level member properties cannot.| The variable itself can be observed. Lower-level observation requires use of the \@Trace decorator.|
| Data transfer| It can be used as a data source to synchronize with the state variables in a child component.| It can be used as a data source to synchronize with the state variables in a child component.|

## Use Scenarios

### Observing Overall Changes of Objects

When a class object and its properties are decorated by \@ObservedV2 and \@Trace, properties in the class object can be observed. However, value changes of the class object itself cannot be observed and do not initiate UI re-renders. In this case, you can use \@Local to decorate the object to observe the changes.

<!-- @[Local_Use_Case_Object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalUseCaseObject.ets) -->

``` TypeScript
@ObservedV2
class Info {
  @Trace public name: string;
  @Trace public age: number;

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
    Row() {
      Column() {
        Text(`info: ${this.info.name}-${this.info.age}`) // Text1
          .margin(10)
        Text(`localInfo: ${this.localInfo.name}-${this.localInfo.age}`) // Text2
          .margin(10)
        Button('change info&localInfo')
          .onClick(() => {
            this.info = new Info('Lucy', 18); // Text1 is not updated.
            this.localInfo = new Info('Lucy', 18); // Text2 is updated.
          })
          .margin(10)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![local-object](figures/local-object.gif)

### Decorating Variables of the Array Type

When the decorated object is of the **Array** type, the following can be observed: (1) complete array reassignment; (2) array item changes caused by calling **push**, **pop**, **shift**, **unshift**, **splice**, **copyWithin**, **fill**, **reverse**, or **sort**.

<!-- @[Local_Use_Case_Array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalUseCaseArray.ets) -->

``` TypeScript
class Fruit {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }
}

@Entry
@ComponentV2
struct Index {
  @Local fruits: Fruit[] = [new Fruit('apple'), new Fruit('banana')]; // @Local decorated variables of the Array type.

  build() {
    Row() {
      Column() {
        ForEach(this.fruits, (item: Fruit) => {
          Text(`${item.name}`)
            .fontSize(20)
            .margin(10)
        })
        // Reassign the value of the array, triggering UI update.
        Button('Reset array')
          .onClick(() => {
            this.fruits = [new Fruit('strawberry'), new Fruit('blueberry')];
          })
          .width(300)
          .margin(10)
        //Add an element to the array, triggering UI update.
        Button('Push element')
          .onClick(() => {
            this.fruits.push(new Fruit('cherry'));
          })
          .width(300)
          .margin(10)
        // Reverse the array elements, triggering UI update.
        Button('Reverse array')
          .onClick(() => {
            this.fruits.reverse();
          })
          .width(300)
          .margin(10)
        //Use the same element to fill the array, triggering UI update.
        Button('Fill array')
          .onClick(() => {
            this.fruits.fill(new Fruit('apple'));
          })
          .width(300)
          .margin(10)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![local-array](figures/local-array.gif)

### Decorating Variables of the Date Type

When the decorated object is of the **Date** type, the following changes can be observed: (1) complete **Date** object reassignment; (2) property changes caused by calling **setFullYear**, **setMonth**, **setDate**, **setHours**, **setMinutes**, **setSeconds**, **setMilliseconds**, **setTime**, **setUTCFullYear**, **setUTCMonth**, **setUTCDate**, **setUTCHours**, **setUTCMinutes**, **setUTCSeconds**, or **setUTCMilliseconds**.

<!-- @[Local_Use_Case_Data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalUseCaseDate.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct DatePickerExample {
  @Local selectedDate: Date = new Date('2021-08-08'); // @Local decorated Date object

  build() {
    Row() {
      Column() {
        // Reassign a new Date object to selectedDate, triggering UI update.
        Button('set selectedDate to 2023-07-08')
          .onClick(() => {
            this.selectedDate = new Date('2023-07-08');
          })
          .margin(10)
          .width(300)
        // Call the setFullYear API of Date to change the year, triggering UI update.
        Button('increase the year by 1')
          .onClick(() => {
            this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
          })
          .margin(10)
          .width(300)
        // Call the setMonth API of Date to change the month, triggering UI update.
        Button('increase the month by 1')
          .onClick(() => {
            this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
          })
          .margin(10)
          .width(300)
        // Call the setDate API of Date to change the date, triggering UI update.
        Button('increase the day by 1')
          .onClick(() => {
            this.selectedDate.setDate(this.selectedDate.getDate() + 1);
          })
          .margin(10)
          .width(300)
        DatePicker({
          start: new Date('1970-1-1'),
          end: new Date('2100-1-1'),
          selected: this.selectedDate
        }).margin(20)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![local-date](figures/local-date.gif)

### Decorating Variables of the Map Type

When the decorated object is of the **Map** type, the following changes can be observed: (1) complete **Map** object reassignment; (2) changes caused by calling **set**, **clear**, or **delete**.

<!-- @[Local_Use_Case_Map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalUseCaseMap.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct MapSample {
  @Local fruits: Map<string, number> = new Map([['apple', 1], ['banana', 2]]); // @Local decorated variables of the Map type.

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.fruits.entries()), (item: [string, number]) => {
          Text(`key: ${item[0]}, value: ${item[1]}`)
            .fontSize(20)
            .margin(10)
        })
        // Add a key-value pair, triggering UI update.
        Button('Set entry cherry')
          .onClick(() => {
            this.fruits.set('cherry', 3);
          })
          .width(300)
          .margin(10)
        // Update a key-value pair, triggering UI update.
        Button('Update entry apple')
          .onClick(() => {
            this.fruits.set('apple', 4);
          })
          .width(300)
          .margin(10)
        // Delete a key-value pair, triggering UI update.
        Button('Delete entry apple')
          .onClick(() => {
            this.fruits.delete('apple');
          })
          .width(300)
          .margin(10)
        // Reassign values to the entire Map, triggering UI update.
        Button('Reset map')
          .onClick(() => {
            this.fruits = new Map([['strawberry', 9], ['blueberry', 8]]);
          })
          .width(300)
          .margin(10)
        // Clear the values of the entire Map, triggering UI update.
        Button('Clear map')
          .onClick(() => {
            this.fruits.clear();
          })
          .width(300)
          .margin(10)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![local-map](figures/local-map.gif)

### Decorating Variables of the Set Type

When the decorated object is of the **Set** type, the following changes can be observed: (1) complete **Set** object reassignment; (2) changes caused by calling **add**, **clear**, or **delete**.

<!-- @[Local_Use_Case_Set](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalUseCaseSet.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct SetSample {
  @Local fruits: Set<string> = new Set(['apple', 'banana']); // @Local decorated variables of the Set type.

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.fruits.entries()), (item: [string, string]) => {
          Text(`${item[0]}`)
            .fontSize(20)
            .margin(10)
        })
        // New element, triggering UI update
        Button('Add element')
          .onClick(() => {
            this.fruits.add('cherry');
          })
          .width(300)
          .margin(10)
        // Delete an element, triggering UI update.
        Button('Delete element apple')
          .onClick(() => {
            this.fruits.delete('apple');
          })
          .width(300)
          .margin(10)
        // Reassign values to the entire Set, triggering UI update.
        Button('Reset set')
          .onClick(() => {
            this.fruits = new Set(['strawberry', 'blueberry']);
          })
          .width(300)
          .margin(10)
        // Clear the values of the entire Set, triggering UI update.
        Button('Clear set')
          .onClick(() => {
            this.fruits.clear();
          })
          .width(300)
          .margin(10)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![local-set](figures/local-set.gif)

### Decorating Variables of the Union Type

\@Local supports **null**, **undefined**, and union types. In the following example, **count** is of the **number | undefined** type. Clicking the buttons to change the type of **count** will trigger UI re-rendering.

<!-- @[Local_Use_Case_Join](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalUseCaseJoin.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct Index {
  @Local count: number | undefined = 10; // @Local decorated variable of the union type

  build() {
    Row() {
      Column() {
        Text(`count: ${this.count}`)
        // Change the union variable from number to undefined, triggering the UI update.
        Button('change to undefined')
          .onClick(() => {
            this.count = undefined;
          })
          .width(300)
          .margin(10)
        // Change the union variable from undefined to number, triggering the UI update.
        Button('change to number')
          .onClick(() => {
            this.count = 10;
          })
          .width(300)
          .margin(10)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![local-union](figures/local-union.gif)

## FAQs

### Using animateTo Failed in State Management V2

In the following scenario, [animateTo](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#animateto) cannot be directly used in state management V2.

<!-- @[Local_AnimateTo_V2_Problem](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalAnimateToV2Problem.ets) -->

``` TypeScript
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

Since API version 22, you can use the [applySync API](./arkts-new-applySync-flushUpdates-flushUIUpdates.md) to achieve the expected display effect.

<!-- @[Local_ApplySync_Effect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalApplySyncEffect.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';

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
          UIUtils.applySync(() => {
            this.w = 100;
            this.h = 100;
            this.message = 'Hello World';
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

The principle is as follows: Use the **applySync** API to synchronously update the state variable changes in the closure function, and then execute the original animation to achieve the expected effect.

![arkts-new-local-animateTo-2](figures/arkts-new-local-animateTo-2.gif)