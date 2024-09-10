# \@Monitor Decorator: Listening for Value Changes of the State Variables

You can use \@Monitor, a method decorator in state management V2, to enhance the capability of the state management framework to listen for the state variable changes

>**NOTE**
>
>The \@Monitor decorator is supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.

## Overview

To listen for value changes of the state variables in a lower level, you can use the \@Monitor decorator:

- The \@Monitor decorator can be used in custom components decorated by \@ComponentV2. But it cannot listen for the changes of the state variables that are not decorated by these decorators: [\@Local](arkts-new-local.md), [\@Param](arkts-new-param.md), [\@Provider](arkts-new-Provider-and-Consumer.md), [\@Consumer](arkts-new-Provider-and-Consumer.md), and [\@Computed](arkts-new-Computed.md).

- The \@Monitor decorator can be used in a class together with [\@ObservedV2 and \@Trace](arkts-new-observedV2-and-trace.md) decorators. But it cannot be used in a class that is not decorated by \@ObservedV2. \@Monitor cannot listen for the properties that are not decorated by \@Trace.
- When the listened property changes, the callback defined by \@Monitor will be called. Strict equality (===) is used to determine whether a property changes. If **false** is returned, the \@Monitor callback is triggered. When a property is changed for multiple times in an event, the initial value will be compared with the final value to determine whether the property is changed.
- A single \@Monitor decorator can listen for the changes of multiple properties at the same time. When these properties change together in an event, the \@Monitor callback method is triggered only once.
- The \@Monitor decorator has lower-level listening capability and can listen for changes of specified items in nested classes, multi-dimensional arrays, and object arrays. The observation requires that \@ObservedV2 decorate the nested class and \@Trace decorate the member properties in an object array.
- In the inheritance scenario, you can define \@Monitor for the same property in the parent and child components for listening. When the property changes, the \@Monitor callback defined in the parent and child components is called.
- Similar to the [\@Watch](arkts-watch.md) decorator, you should define the callback functions by yourselves. The difference is that the \@Watch decorator uses the function name as a parameter, while the \@Monitor directly decorates the callback function. For the comparison between \@Monitor and \@Watch, see [Comparing \@Monitor with \@Watch](#comparing-\@Monitor-with-\@Watch).

## Limitations of the \@Watch decorator in State Management V1

This V1 version cannot listen for the changes of an object, a single property in an array, or array items. It also cannot obtain the value before change.

```ts
@Observed
class Info {
  name: string = "Tom";
  age: number = 25;
}
@Entry
@Component
struct Index {
  @State @Watch('onInfoChange') info: Info = new Info();
  @State @Watch('onNumArrChange') numArr: number[] = [1,2,3,4,5];

  onInfoChange() {
    console.log(`info after change name: ${this.info.name}, age: ${this.info.age} `);
  }
  onNumArrChange() {
    console.log(`numArr after change ${JSON.stringify(this.numArr)}`);
  }
  build() {
    Row() {
      Column() {
        Button("change info name")
          .onClick(() => {
            this.info.name = "Jack";
          })
        Button("change info age")
          .onClick(() => {
            this.info.age = 30;
          })
        Button("change numArr[2]")
          .onClick(() => {
            this.numArr[2] = 5;
          })
        Button("change numArr[3]")
          .onClick(() => {
            this.numArr[3] = 6;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

In the preceding code, when you click **change info name** to change the **name** property in **info**, or click **change info age** to change **age**, the **info** registered \@Watch callback is triggered. When you click **change numArr[2]** to change the third element in **numArr**, or click **change numArr[3]** to change the fourth element, the **numArr** registered \@Watch callback is triggered. In these two callbacks, the value before data change cannot be obtained. This makes it inconvenient for you to listen for the variable changes because you cannot find out which property or element is changed to trigger \@Watch event in a more complex scenario. Therefore, the \@Monitor decorator comes into the picture to listen for the changes of an object, a single property in an array, or an array item and obtain the value before change.

## Decorator Description

| \@Monitor Property Decorator| Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Decorator parameter         | Object property name of the string type. This decorator can listen for multiple object properties at the same time. Each property is separated by commas (,), for example, @Monitor ("prop1", "prop2"). In addition, properties such as an element in a multi-dimensional array, a property in a nested object, and a property in an object array can be listened in a lower level. For details, see [Listened Changes](#listened-changes).|
| Decorated object           | \@Monitor decorated member method. This callback is triggered when the listened property changes. The variable of [IMonitor type](#imonitor-type) will be set as a parameter to provide related information before and after change.|

## API Description

### IMonitor Type

Variables of the IMonitor type are used as parameters for \@Monitor to decorate a method.

| Property      | Type           | Parameter         | Return Value            | Description                                                        |
| ---------- | --------------- | ------------- | ------------------ | ------------------------------------------------------------ |
| dirty      | Array\<string\> | None.           | None.                | Saves the changed property name.                                      |
| value\<T\> | function        | path?: string | IMonitorValue\<T\> | Obtains the change information of a specified property (**path**). If **path** is not specified, @Monitor will return the first changed property information in the listening sequence.|

### IMonitorValue\<T\> Type

Saves the information about property changes, including the property name, original value, and new value.

| Property  | Type  | Description                      |
| ------ | ------ | -------------------------- |
| before | T      | Listens for the value before the property change.    |
| now    | T      | Listens for the current value after the property changes.|
| path   | string | Listened property name.            |

## Listened Changes

### Using \@Monitor in Custom Components Decorated by \@ComponentV2

When the state variables listened by \@Monitor change, the callback is triggered.

- Variables listened by \@Monitor need to be decorated by \@Local, \@Param, \@Provider, \@Consumer, and \@Computed. Otherwise, they cannot be listened when they change. \@Monitor can listen for multiple state variables at the same time. Names of these variables are separated by commas (,).

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local message: string = "Hello World";
    @Local name: string = "Tom";
    @Local age: number = 24;
    @Monitor("message", "name")
    onStrChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        console.log(`${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`)
      })
    }
    build() {
      Column() {
        Button("change string")
          .onClick(() => {
            this.message += "!";
            this.name = "Jack";
        })
      }
    }
  }
  ```

- When the state variable listened by \@Monitor is a class object, only the overall object changes can be listened. To listen for the changes of a class property, this property should be decorated by \@Trace.

  ```ts
  class Info {
    name: string;
    age: number;
    constructor(name: string, age: number) {
      this.name = name;
      this.age = age;
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local info: Info = new Info("Tom", 25);
    @Monitor("info")
    infoChange(monitor: IMonitor) {
      console.log(`info change`);
    }
    @Monitor("info.name")
    infoPropertyChange(monitor: IMonitor) {
      console.log(`info name change`);
    }
    build() {
      Column() {
        Text(`name: ${this.info.name}, age: ${this.info.age}`)
        Button("change info")
          .onClick(() => {
            this.info = new Info ("Lucy", 18); // Can listen for the change.
          })
        Button("change info.name")
          .onClick(() => {
            this.info.name = "Jack"; // Cannot listen for the change.
          })
      }
    }
  }
  ```

### Using \@Monitor in Classes Decorated by \@ObservedV2

When the properties listened by \@Monitor change, the callback is triggered.

- The object property listened by \@Monitor should be decorated by \@Trace. Otherwise, the property cannot be listened. \@Monitor can listen for multiple properties at the same time. These properties are separated by commas (,).

```ts
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace region: string = "North";
  @Trace job: string = "Teacher";
  age: number = 25;
  // name is decorated by @Trace. Can listen for the change.
  @Monitor("name")
  onNameChange(monitor: IMonitor) {
    console.log(`name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  // age is not decorated by @Trace. Cannot listen for the change.
  @Monitor("age")
  onAgeChange(monitor: IMonitor) {
    console.log(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  // region and job are decorated by @Trace. Can listen for the change.
  @Monitor("region", "job")
  onChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change name")
        .onClick(() => {
          this.info.name = "Jack"; // Can trigger the onNameChange method.
        })
      Button("change age")
        .onClick(() => {
          this.info.age = 26; // Cannot trigger the onAgeChange method.
        })
      Button("change region")
        .onClick(() => {
          this.info.region = "South"; // Can trigger the onChange method.
        })
      Button("change job")
        .onClick(() => {
          this.info.job = "Driver"; // Can trigger the onChange method.
        })
    }
  }
}
```

- \@Monitor can listen for the changes of lower-level properties which should be decorated by @Trace.

```ts
@ObservedV2
class Inner {
  @Trace num: number = 0;
}
@ObservedV2
class Outer {
  inner: Inner = new Inner();
  @Monitor("inner.num")
  onChange(monitor: IMonitor) {
    console.log(`inner.num change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@Entry
@ComponentV2
struct Index {
  outer: Outer = new Outer();
  build() {
    Column() {
      Button("change name")
        .onClick(() => {
          this.outer.inner.num = 100; // Can trigger the onChange method.
        })
    }
  }
}
```

- In the inheritance class scenario, you can listen for the same property for multiple times in the inheritance chain.

```ts
@ObservedV2
class Base {
  @Trace name: string;
  // Listen for the name property of the base class.
  @Monitor("name")
  onBaseNameChange(monitor: IMonitor) {
    console.log(`Base Class name change`);
  }
  constructor(name: string) {
    this.name = name;
  }
}
@ObservedV2
class Derived extends Base {
  // Listen for the name property of the inheritance class.
  @Monitor("name")
  onDerivedNameChange(monitor: IMonitor) {
    console.log(`Derived Class name change`);
  }
  constructor(name: string) {
    super(name);
  }
}
@Entry
@ComponentV2
struct Index {
  derived: Derived = new Derived("AAA");
  build() {
    Column() {
      Button("change name")
        .onClick(() => {
          this.derived.name = "BBB"; // Can trigger the onBaseNameChange and onDerivedNameChange methods in sequence.
        })
    }
  }
}
```

### General Listening Capability

\@Monitor also has some general listening capabilities.

- \@Monitor can listen for items in arrays, including multi-dimensional arrays and object arrays. \@Monitor cannot listen for changes caused by calling APIs of built-in types (Array, Map, Date, and Set). When \@Monitor listens for the entire array, only the value changes to the entire array can be observed. But you can listen for the length change of the array to determine whether the array is inserted or deleted. Currently, only periods (.) can be used to listen for lower-level properties and array items.

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
@ObservedV2
class ArrMonitor {
  @Trace dimensionTwo: number[][] = [[1,1,1],[2,2,2],[3,3,3]];
  @Trace dimensionThree: number[][][] = [[[1],[2],[3]],[[4],[5],[6]],[[7],[8],[9]]];
  @Trace infoArr: Info[] = [new Info("Jack", 24), new Info("Lucy", 18)];
  // dimensionTwo is a two-dimensional simple array and is decorated by @Trace. Can observe the element changes.
  @Monitor("dimensionTwo.0.0", "dimensionTwo.1.1")
  onDimensionTwoChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`dimensionTwo path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
  // dimensionThree is a three-dimensional simple array and is decorated by @Trace. Can observe the element changes.
  @Monitor("dimensionThree.0.0.0", "dimensionThree.1.1.0")
  onDimensionThreeChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`dimensionThree path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
  // name and age properties of the info class are decorated by @Trace. Can listen for the changes.
  @Monitor("infoArr.0.name", "infoArr.1.age")
  onInfoArrPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`infoArr path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
  // infoArr is decorated by @Trace. Can listen for the value changes.
  @Monitor("infoArr")
  onInfoArrChange(monitor: IMonitor) {
    console.log(`infoArr whole change`);
  }
  // Can listen for the length change of the infoArr.
  @Monitor("infoArr.length")
  onInfoArrLengthChange(monitor: IMonitor) {
    console.log(`infoArr length change`);
  }
}
@Entry
@ComponentV2
struct Index {
  arrMonitor: ArrMonitor = new ArrMonitor();
  build() {
    Column() {
      Button("Change dimensionTwo")
        .onClick(() => {
          // Can trigger the onDimensionTwoChange method. 
          this.arrMonitor.dimensionTwo[0][0]++; 
          this.arrMonitor.dimensionTwo[1][1]++; 
        })
      Button("Change dimensionThree")
        .onClick(() => {
          // Can trigger the onDimensionThreeChange method.
          this.arrMonitor.dimensionThree[0][0][0]++;
          this.arrMonitor.dimensionThree[1][1][0]++; 
        })
      Button("Change info property")
        .onClick(() => {
          // Can trigger the onInfoArrPropertyChange method.
          this.arrMonitor.infoArr[0].name = "Tom"; 
          this.arrMonitor.infoArr[1].age = 19; 
        })
      Button("Change whole infoArr")
        .onClick(() => {
          // Can trigger the onInfoArrChange, onInfoArrPropertyChange, and onInfoArrLengthChange methods.
          this.arrMonitor.infoArr = [new Info("Cindy", 8)]; 
        })
      Button("Push new info to infoArr")
        .onClick(() => {
          // Can trigger the onInfoArrPropertyChange and onInfoArrLengthChange methods.
          this.arrMonitor.infoArr.push(new Info("David", 50)); 
        })
    }
  }
}
```

- When the entire object changes but the listened property remains unchanged, the \@Monitor callback is not triggered.

The following code represents the behavior in the comment when you execute the instructions in the sequence of Step 1, Step 2 and Step 3.

If you only execute the instruction of Step 2 or Step 3 to change the values of **name** or **age**, the **onNameChange** and **onAgeChange** methods are triggered.

```ts
@ObservedV2
class Info {
  @Trace person: Person;
  @Monitor("person.name")
  onNameChange(monitor: IMonitor) {
    console.log(`name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor("person.age")
  onAgeChange(monitor: IMonitor) {
    console.log(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  constructor(name: string, age: number) {
    this.person = new Person(name, age);
  }
}
@ObservedV2
class Person {
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
  info: Info = new Info("Tom", 25);
  build() {
    Column() {
      Button("Step 1, only change name")
        .onClick(() => {
          this.info.person = new Person("Jack", 25);  // Can trigger the onNameChange method, but not the onAgeChange method.
        })
      Button("Step 2, only change age")
        .onClick(() => {
          this.info.person = new Person("Jack", 18);  // Can trigger the onAgeChange method, but not the onNameChange method.
        })
      Button("Step 3, change name and age")
        .onClick(() => {
          this.info.person = new Person("Lucy", 19);  // Can trigger the onNameChange and onAgeChange methods.
        })
    }
  }
}
```

- If the property listened by \@Monitor is changed for multiple times in an event, the last change is used.

```ts
@ObservedV2
class Frequence {
  @Trace count: number = 0;
  @Monitor("count")
  onCountChange(monitor: IMonitor) {
    console.log(`count change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@Entry
@ComponentV2
struct Index {
  frequence: Frequence = new Frequence();
  build() {
    Column() {
      Button("change count to 1000")
        .onClick(() => {
          for (let i = 1; i <= 1000; i++) {
            this.frequence.count = i;
          }
        })
      Button("change count to 0 then to 1000")
        .onClick(() => {
          for (let i = 999; i >= 0; i--) {
            this.frequence.count = i;
          }
          this.frequence.count = 1000; // Cannot trigger the onCountChange method at last.
        })
    }
  }
}
```

After you click **change count to 1000**, the **onCountChange** method is triggered and the **count change from 0 to 1000** log is output. After you click **change count to 0 then to 1000**, the **onCountChange** method is not triggered because the value of **count** property remains 1000 before and after the event.

## Constraints

Pay attention to the following constraints when using \@Monitor:

- Do not listen for the same property for multiple times in a class. When a property in a class is listened for multiple times, only the last listening method takes effect.

```ts
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Monitor("name")
  onNameChange(monitor: IMonitor) {
    console.log(`onNameChange`);
  }
  @Monitor("name")
  onNameChangeDuplicate(monitor: IMonitor) {
    console.log(`onNameChangeDuplicate`);
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change name")
        .onClick(() => {
          this.info.name = "Jack"; // Only the onNameChangeDuplicate method is triggered.
        })
    }
  }
}
```

- The \@Monitor parameter must be a string that listens for the property name. Only string literals, **const** constants, and **enum** enumerated values can be used as parameters. If a variable is used as a parameter, only the property corresponding to the variable value during \@Monitor initialization is listened. When a variable is changed, \@Monitor cannot change the listened property in real time. That is, the target property listened by \@Monitor is determined during initialization and cannot be dynamically changed. Do not use variables as \@Monitor parameters for initialization.

```ts
const t2: string = "t2"; // Constant
enum ENUM {
  Enumerated Values of T3 = "t3" // Enumerated value
};
let t4: string = "t4"; // Variable
@ObservedV2
class Info {
  @Trace t1: number = 0;
  @Trace t2: number = 0;
  @Trace t3: number = 0;
  @Trace t4: number = 0;
  @Trace t5: number = 0;
  @Monitor("t1") // String literal
  onT1Change(monitor: IMonitor) {
    console.log(`t1 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor(t2)
  onT2Change(monitor: IMonitor) {
    console.log(`t2 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor(ENUM.T3)
  onT3Change(monitor: IMonitor) {
    console.log(`t3 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor(t4)
  onT4Change(monitor: IMonitor) {
    console.log(`t4 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("Change t1")
        .onClick(() => {
          this.info.t1++; // Can trigger the onT1Change method.
        })
      Button("Change t2")
        .onClick(() => {
          this.info.t2++; // Can trigger the onT2Change method.
        })
      Button("Change t3")
        .onClick(() => {
          this.info.t3++; // Can trigger the onT3Change method.
        })
      Button("Change t4")
        .onClick(() => {
          this.info.t4++; // Can trigger the onT4Change method.
        })
      Button("Change var t4 to t5")
        .onClick(() => {
          t4 = "t5"; // Change the variable value to "t5".
        })
      Button("Change t5")
        .onClick(() => {
          this.info.t5++; // The onT4Change still listens for t4. Cannot trigger the method.
        })
      Button("Change t4 again")
        .onClick(() => {
          this.info.t4++; // Can trigger the onT4Change method.
        })
    }
  }
}
```

- Changing the listened property in \@Monitor again may cause infinite loops, which is not recommended.

```ts
@ObservedV2
class Info {
  @Trace count: number = 0;
  @Monitor("count")
  onCountChange(monitor: IMonitor) {
    this.count++; // Avoid using this method because it may cause infinite loops.
  }
}
```

## Comparing \@Monitor with \@Watch

The following table compares the usage and functions of \@Monitor and \@Watch.

|                    | \@Watch                                 | \@Monitor                                                    |
| ------------------ | --------------------------------------- | ------------------------------------------------------------ |
| Parameter              | Call back the method name.                             | Listen for the state variable name and property name.                                      |
| Number of listened targets        | Only a single state variable can be listened.                   | Multiple state variables can be listened at the same time.                                      |
| Listening capability          | Listen for the top-level state variables.           | Listen for the lower-level state variables.                                |
| Obtain the value before change| No.                     | Yes.                                            |
| Listening Condition          | The listened object is a state variable.                     | The listened object is a state variable or a class member property decorated by \@Trace.               |
| Constraints          | It can be used only in custom components decorated by \@Component.| It can be used in custom components and classes decorated by \@ComponentV2.|

## Use Scenarios

### Listening for Lower-level Property Changes

\@Monitor can listen for the lower-level property changes and classify them based on the values before and after the changes.

In the following example, the change of property **value** is listened and the display style of the **Text** component is changed based on the change amplitude.

```ts
@ObservedV2
class Info {
  @Trace value: number = 50;
}
@ObservedV2
class UIStyle {
  info: Info = new Info();
  @Trace color: Color = Color.Black;
  @Trace fontSize: number = 45;
  @Monitor("info.value")
  onValueChange(monitor: IMonitor) {
    let lastValue: number = monitor.value()?.before as number;
    let curValue: number = monitor.value()?.now as number;
    if (lastValue != 0) {
      let diffPercent: number = (curValue - lastValue) / lastValue;
      if (diffPercent > 0.1) {
        this.color = Color.Red;
        this.fontSize = 50;
      } else if (diffPercent < -0.1) {
        this.color = Color.Green;
        this.fontSize = 40;
      } else {
        this.color = Color.Black;
        this.fontSize = 45;
      }
    }
  }
}
@Entry
@ComponentV2
struct Index {
  textStyle: UIStyle = new UIStyle();
  build() {
    Column() {
      Text(`Important Value: ${this.textStyle.info.value}`)
        .fontColor(this.textStyle.color)
        .fontSize(this.textStyle.fontSize)
      Button("change!")
        .onClick(() => {
          this.textStyle.info.value = Math.floor(Math.random() * 100) + 1;
        })
    }
  }
}
```
