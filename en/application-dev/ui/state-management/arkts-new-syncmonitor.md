# @SyncMonitor Decorator: Synchronous Listening for Value Changes of the State Variables

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:10:58.788Z pushedAt=2026-07-23T10:40:33.359Z -->

To enhance the state management framework's capability of listening for state variable changes, you can use the [\@SyncMonitor](../../reference/apis-arkui/arkui-ts/ts-state-management-syncmonitor.md#syncmonitor) decorator to listen for state variables.

\@SyncMonitor provides the capability of synchronously listening for state variables of V2. Before reading this document, you are advised to read [\@ComponentV2](./arkts-create-custom-components.md#componentv2), [\@ObservedV2 and \@Trace](./arkts-new-observedV2-and-trace.md), [\@Local](./arkts-new-local.md), and [\@Monitor](./arkts-new-monitor.md).

>**NOTE**
>
> The \@SyncMonitor decorator is supported since API version 23.
>
> This decorator can be used in atomic services since API version 23.

## Overview

The \@SyncMonitor decorator is used to synchronously listen to the modification of state variables so that the state variables have the deep listening capability.

- The \@SyncMonitor decorator can be used in custom components decorated by \@ComponentV2. But it cannot listen for the changes in the state variables that are not decorated by these decorators: [\@Local](arkts-new-local.md), [\@Param](arkts-new-param.md), [\@Provider](arkts-new-provider-and-consumer.md), [\@Consumer](arkts-new-provider-and-consumer.md) and [\@Computed](arkts-new-computed.md).

## Usage Rules

- The \@SyncMonitor decorator can be used in a class together with [\@ObservedV2 and \@Trace](arkts-new-observedV2-and-trace.md) decorators. But it cannot be used in a class that is not decorated by \@ObservedV2. \@SyncMonitor cannot listen for the properties that are not decorated by \@Trace. When the listened property changes, the callback defined by \@SyncMonitor will be called. Strict equality (===) is used to determine whether a property is changed. If **false** is returned, the \@SyncMonitor decorated callback is triggered. In the same event, when the observed attribute changes for multiple times, the callback function is called each time the attribute changes.

- A single \@SyncMonitor decorator can listen for the changes in multiple properties at the same time. When these properties change together in an event, the \@SyncMonitor callback method is triggered only once. When \@SyncMonitor observes an entire array, changes to individual array items are not observed. 

- In the inheritance scenario, you can define \@SyncMonitor for the same property in the parent and child classes for listening. When the property changes, the \@SyncMonitor callback defined in the parent and child components is called.

- The \@SyncMonitor decorator has deep listening capability and can listen for changes of specified items in nested classes, multi-dimensional arrays, and object arrays. The observation requires that \@ObservedV2 decorate the nested class and \@Trace decorate the member properties in an object array.

- \@SyncMonitor can observe data changes caused by the calling of APIs of the built-in types `Map`, `Set`, `Date`, and `Array`. For details, see [General Listening Capabilities](#general-listening-capability).

- Added [wildcard ('*')](#wildcards-in-the-listening-path) to the \@SyncMonitor decorator to support fuzzy listening so that the \@Watch decorator can be migrated to the \@SyncMonitor decorator.

### Comparison between \@Monitor, \@SyncMonitor, and \@Watch

Similar to the [\@Watch](arkts-watch.md) decorator, you must define the callback function. The difference is that \@Watch uses the function name as the parameter, while \@SyncMonitor directly decorates the callback function. \@SyncMonitor with a wildcard listening path has the same listening scope as \@Watch. Functions decorated by \@Watch and \@SyncMonitor are executed synchronously. The following table compares the usage and functions of \@Monitor, \@SyncMonitor, and \@Watch.

| Category                  | \@Watch                                 | \@Monitor                                                    |\@SyncMonitor                                                  |
| ------------------ | --------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Parameters             | Callback method name.                            | Listened state variable name and attribute name                                     | Listened state variable name and attribute name                                     |
| Number of Intercepted Targets       | Single state variable                  | Multiple state variables                                     | Multiple state variables    |
| Type         | Fuzzy Listening         | Fuzzy interception and precise interception are supported.                        | Fuzzy interception and precise interception are supported.                               |
| Whether to Obtain the Value Before the Change| No                    | Yes                                           | Yes                                           |
| Observation Condition         | The observed object is a state variable.                    | The observed object is a state variable or a class member attribute decorated with \@Trace.              | The observed object is a state variable or a class member attribute decorated with \@Trace.              |
| Constraints         | Only in custom components decorated by \@Component| In the custom component decorated by \@ComponentV2 and the class decorated by \@ObservedV2| In the custom component decorated by \@ComponentV2 and the class decorated by \@ObservedV2|
| Whether Wildcards Are Supported| No | Not supported by default. Supported through configuration items since API version 26.0.0.| Yes (since API version 23)|
| Callback Invoking Time| Immediately (synchronized)| After the status change function ends (asynchronous), multiple changes are triggered only once.|  Immediately (synchronized)|

[addMonitor and clearMonitor](./arkts-new-addMonitor-clearMonitor.md) APIs allows you to dynamically add and clear listeners during application execution. When **isSynchronous** is set to **true**, **addMonitor** is similar to \@SyncMonitor. When **isSynchronous** is set to **false**, **addMonitor** is similar to \@Monitor.

\@Monitor and \@SyncMonitor are member function decorators of the \@ComponentV2 and \@ObservedV2 classes, respectively. They are part of V2 state management. \@Watch is a variable decorator used in [@Component](./arkts-create-custom-components.md#component). It is a part of V1 state management.

Functions decorated by \@Monitor are executed asynchronously after the event handler is executed. After the \@SyncMonitor and \@Watch functions detect the change of the state variable, the callback function is executed immediately.

The execution of the \@Monitor function can be triggered by the value change of one or more specific tracing object attributes. The \@Watch function is executed when any observed object attribute or array item changes. It cannot listen to one or more specific attributes.

The behavior of \@SyncMonitor with wildcard characters in the path is the same as that of \@Watch. This makes it easier for applications to migrate from V1 state management to V2 state management. The following is an example:

\@Watch sample code for V1:

```typescript
@Component 
struct CompV1 {
  @State @Watch('watchFuncName') varName: ClassA = initialValue; // ClassA is of the class type.
  watchFuncName(propertyStr: string) {
    // ....
  }
}
```

Sample code for migrating to \@SyncMonitor in V2:

```typescript
@ComponentV2 
struct CompV2 {
  @Local varName: ClassA = initialValue;
  @SyncMonitor('varName.*') monitorFuncName(m: IMonitor) {
    // ....
  }
}
```

ClassA indicates the complex object type. The following example uses \@SyncMonitor and \@Monitor to track the change of the sum attribute.

The code calculates the sum of array elements. When the sum is calculated in a loop, the sum value changes to 1, 3, and 6 in sequence.

\@Monitor is called only once. The value of before is 0, and the value of now is 6.

\@SyncMonitor calls it for three times, corresponding to the changes from 0 to 1, from 1 to 3, and from 3 to 6.

 <!-- @[compare_syncmonitor_with_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/CompareSyncMonitorWithMonitor.ets) -->

 ``` TypeScript
 import { hilog } from '@kit.PerformanceAnalysisKit';
 
 @Entry
 @ComponentV2
 struct DocSampleArraySum {
   @Local sum: number = 0;
   arr: Array<number> = [1, 2, 3];
   @SyncMonitor('sum')
   syncSumMonitor(info: IMonitor) {
     let path = info.dirty[0];
     hilog.info(0xFF00, 'SyncMonitor', '%{public}s', `${path} changed from ${info.value(path)?.before} to ${info.value(path)?.now}`);
   }
   @Monitor('sum')
   asyncSumMonitor(info: IMonitor) {
     let path = info.dirty[0];
     hilog.info(0xFF00, 'Monitor', '%{public}s', `${path} changed from ${info.value(path)?.before} to ${info.value(path)?.now}`);
   }
 
   build() {
     Column() {
       Button('Calculate a sum')
         .onClick(() => {  // When the sum is modified, syncSumMonitor is called back for three times, and asyncSumMonitor is called back only once.
           this.sum = 0;
           this.arr.forEach((element) => this.sum += element);
         })
     }
   }
 }
 ```

Log output:

```typescript
SyncMonitor - sum changed from 0 to 1
SyncMonitor - sum changed from 1 to 3
SyncMonitor - sum changed from 3 to 6
Monitor - sum changed from 0 to 6
```

## Decorator Description

|\@SyncMonitor Attribute Decorator| Description                                                       |
| ------------------- | ------------------------------------------------------------ |
| Parameters        | Object attribute name of the string type. Multiple object attributes can be listened at the same time. Use commas (,) to separate attributes, for example, @SyncMonitor ('prop1','prop2'). In addition, deep attribute changes can be monitored: elements in multi-dimensional arrays, attributes in nested objects, and attributes in object arrays. The wildcard (*) can be added at the end of a path to listen to the changes of any observed attribute. For details, see [Listening for Changes](#listening-for-changes).|
| Decorated Content | Member method. When an observed property changes, this callback is triggered. The callback takes a variable of the [IMonitor](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md#imonitor) type as a parameter, from which developers can obtain information about the changes before and after the modification. |

## Wildcards in the Listening Path

When the listening path of the \@SyncMonitor decorator uses the wildcard (*):

  - This event is triggered when a value is assigned to an object or any attribute of an object changes.

  - This event is triggered when a value is assigned to an array or any item in the array changes.

  - Any attribute change or any array item change can be monitored.

  - When wildcards are used, the values returned by **before** and **now** are **undefined**.

Syntax rules for the wildcard (*) path:

* The wildcard can be used only at the end of a path.

* The wildcard cannot appear at the beginning or in the middle of a path.

The following is an example of a valid path:

* `obj.*` (observes objects containing \@Trace)

  - This event is triggered when a new value is assigned to **obj**.

  - Triggered when any attribute of obj decorated by \@Trace changes.

* `arr.*` (observation array)

  - This event is triggered when a new value is assigned to **arr**.

  - This event is triggered when any item in the array or the array length changes.

  - Call APIs of the **Array** type, such as **copyWithin**, **fill**, **sort**, and **push**. The callback function decorated with \@SyncMonitor is also executed.

* `obj.ObjA.objB.*` (observing objects in nested objects)

  - This event is triggered when a new value is assigned to **obj** and **ObjA**, and **objB** changes.

  - This event is triggered when a new value is assigned to objB.

  - This event is triggered when any of the \@Trace decorative attributes in objB changes.

* arr.1.* (multi-dimensional observation array)

  - This event is triggered when a new value is assigned to arr and the value of the first item changes.

  - Triggered when any item or length of a nested array item changes.

## Available APIs

For the API description of the IMonitor and IMonitorValue\<T\> types, see [\@Monitor: Listening for Value Changes of the State Variables](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md).

## Listening for Changes

### Using \@SyncMonitor in a Custom Component Decorated by \@ComponentV2

When the state variable monitored by \@SyncMonitor changes, the callback method of \@SyncMonitor is triggered.

- Variables listened by \@SyncMonitor must be decorated by \@Local, \@Param, \@Provider, \@Consumer, and \@Computed. Variables that are not decorated by the state variable decorator cannot be listened when they change. \@SyncMonitor can listen to multiple state variables at the same time. The variable names are separated by commas (,).

   <!-- @[monitor_multiple_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorMultipleVariables.ets) -->

   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   @Entry
   @ComponentV2
   struct Index {
     @Local message: string = 'Hello World';
     @Local name: string = 'Tom';
     @Local age: number = 24;
   
     @SyncMonitor('message', 'name')
     onStrChange(monitor: IMonitor) {
       monitor.dirty.forEach((path: string) => {
         hilog.info(0xFF00, 'testTag', '%{public}s',
           `${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
       });
     }
   
     build() {
       Column() {
         Button('change string')
           .onClick(() => {
             this.message += '!';
             this.name = 'Jack';
           })
       }
     }
   }
   ```

- When the state variable monitored by \@SyncMonitor is a class object, only the changes of the entire object can be monitored. To listen to the changes of class attributes, the class attributes must be decorated by \@Trace. The changes of non-state variables cannot be listened to.

    <!-- @[monitor_object_variable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorObjectVariable.ets) -->

    ``` TypeScript
    import { hilog } from '@kit.PerformanceAnalysisKit';
    
    class Info {
      public name: string;
      public age: number;
    
      constructor(name: string, age: number) {
        this.name = name;
        this.age = age;
      }
    }
    
    @Entry
    @ComponentV2
    struct Index {
      @Local info: Info = new Info('Tom', 25);
    
      @SyncMonitor('info')
      infoChange(monitor: IMonitor) {
        hilog.info(0xFF00, 'testTag', '%{public}s', `info change`);
      }
    
      build() {
        Column() {
          Text(`name: ${this.info.name}, age: ${this.info.age}`)
          Button('change info')
            .onClick(() => {
              this.info = new Info('Lucy', 18); // Can listen for the change.
            })
        }
      }
    }
    ```

### Use \@SyncMonitor in the class decorated by \@ObservedV2.

When the attribute monitored by \@SyncMonitor changes, the callback method of \@SyncMonitor is triggered.

- The object attributes listened by \@SyncMonitor must be decorated by \@Trace. The changes of the attributes that are not decorated by \@Trace cannot be listened. \@SyncMonitor can listen to multiple attributes at the same time. The attributes are separated by commas (,).

   <!-- @[monitor_variables_in_observedv2_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorVariablesInObservedV2Class.ets) -->

   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   @ObservedV2
   class Info {
     @Trace public name: string = 'Tom';
     @Trace public region: string = 'North';
     @Trace public job: string = 'Teacher';
     public age: number = 25;
   
     // The name variable is decorated by @Trace and can be listened to for changes.
     @SyncMonitor('name')
     onNameChange(monitor: IMonitor) {
       hilog.info(0xFF00, 'testTag', '%{public}s',
         `name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
     }
   
     // The age variable is not decorated by @Trace and cannot be listened to for changes.
     @SyncMonitor('age')
     onAgeChange(monitor: IMonitor) {
       hilog.info(0xFF00, 'testTag', '%{public}s',
         `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
     }
   
     // Both the region and job variables are decorated by @Trace and can be listened to for changes.
     @SyncMonitor('region', 'job')
     onChange(monitor: IMonitor) {
       monitor.dirty.forEach((path: string) => {
         hilog.info(0xFF00, 'testTag', '%{public}s',
           `${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
       })
     }
   }
   
   @Entry
   @ComponentV2
   struct Index {
     info: Info = new Info();
   
     build() {
       Column() {
         Button('change name')
           .onClick(() => {
             this.info.name = 'Jack'; // Can trigger the onNameChange method.
           })
         Button('change age')
           .onClick(() => {
             this.info.age = 26; // Cannot trigger the onAgeChange method.
           })
         Button('change region')
           .onClick(() => {
             this.info.region = 'South'; // Can trigger the onChange method.
           })
         Button('change job')
           .onClick(() => {
             this.info.job = 'Driver'; // Can trigger the onChange method.
           })
       }
     }
   }
   ```

- \@SyncMonitor can listen to changes of deep attributes that need to be decorated by @Trace.

  <!-- @[monitor_two_layer_variables_in_observedv2_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorTwoLayerVariablesInObservedV2Class.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Inner {
    @Trace public num: number = 0;
  }
  
  @ObservedV2
  class Outer {
    public inner: Inner = new Inner();
  
    @SyncMonitor('inner.num')
    onChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `inner.num change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    outer: Outer = new Outer();
  
    build() {
      Column() {
        Button('change num')
          .onClick(() => {
            this.outer.inner.num = 100; // Can trigger the onChange method.
          })
      }
    }
  }
  ```

- In the inheritance class scenario, you can listen to the same attribute for multiple times in the inheritance chain. The \@SyncMonitor callback defined in the parent and child classes will be called.

  <!-- @[monitor_variable_base_derived_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorVariableInBaseDerivedClass.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Base {
    @Trace public name: string;
  
    // Listen for the name property of the base class.
    @SyncMonitor('name')
    onBaseNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `Base Class name change`);
    }
  
    constructor(name: string) {
      this.name = name;
    }
  }
  
  @ObservedV2
  class Derived extends Base {
    // Listen for the name property of the inheritance class.
    @SyncMonitor('name')
    onDerivedNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `Derived Class name change`);
    }
  
    constructor(name: string) {
      super(name);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    derived: Derived = new Derived('AAA');
  
    build() {
      Column() {
        Button('change name')
          .onClick(() => {
            this.derived.name = 'BBB'; // The onDerivedNameChange method is invoked, and the onBaseNameChange method of the parent class is also invoked.
          })
      }
    }
  }
  ```

### General Listening Capability

\@SyncMonitor also provides some common listening capabilities.

- \@SyncMonitor can listen to array items, including multi-dimensional arrays and object arrays. \@SyncMonitor can use wildcards to listen to changes caused by the calling of APIs of the **Array** type, such as **copyWithin**, **fill**, **sort**, and **push**.

- \@SyncMonitor can observe the changes caused by the invoking of built-in APIs of the Map, Date, and Set types. For example, if **set**, **add**, or **delete** is called to modify a data set, the listening function is executed. When the key in the Map and Set changes, the listening function is not executed, and the framework prints error logs.

  <!-- @[monitor_variables_in_multidimensional_arrays](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorVariablesInMultidimensionalArrays.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public name: string;
    @Trace public age: number;
  
    constructor(name: string, age: number) {
      this.name = name;
      this.age = age;
    }
  }
  
  @ObservedV2
  class ArrMonitor {
    @Trace public dimensionTwo: number[][] = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    @Trace public dimensionThree: number[][][] = [[[1], [2], [3]], [[4], [5], [6]], [[7], [8], [9]]];
    @Trace public infoArr: Info[] = [new Info('Jack', 24), new Info('Lucy', 18)];
  
    // dimensionTwo is a two-dimensional simple array and is decorated by @Trace. Can observe the element changes.
    @SyncMonitor('dimensionTwo.0.0', 'dimensionTwo.1.1')
    onDimensionTwoChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `dimensionTwo path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // dimensionThree is a three-dimensional simple array and is decorated by @Trace. Can observe the element changes.
    @SyncMonitor('dimensionThree.0.0.0', 'dimensionThree.1.1.0')
    onDimensionThreeChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `dimensionThree path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // name and age properties of the info class are decorated by @Trace. Can listen for the change.
    @SyncMonitor('infoArr.0.name', 'infoArr.1.age')
    onInfoArrPropertyChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `infoArr path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // infoArr is decorated by @Trace. Can listen for the value changes.
    @SyncMonitor('infoArr')
    onInfoArrChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `infoArr whole change`);
    }
  
    // Can listen for the length change of the infoArr.
    @SyncMonitor('infoArr.length')
    onInfoArrLengthChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `infoArr length change`);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    arrMonitor: ArrMonitor = new ArrMonitor();
  
    build() {
      Column() {
        Button('Change dimensionTwo')
          .onClick(() => {
            // Can trigger the onDimensionTwoChange method.
            this.arrMonitor.dimensionTwo[0][0]++;
            this.arrMonitor.dimensionTwo[1][1]++;
          })
        Button('Change dimensionThree')
          .onClick(() => {
            // Can trigger the onDimensionThreeChange method.
            this.arrMonitor.dimensionThree[0][0][0]++;
            this.arrMonitor.dimensionThree[1][1][0]++;
          })
        Button('Change info property')
          .onClick(() => {
            // Can trigger the onInfoArrPropertyChange method.
            this.arrMonitor.infoArr[0].name = 'Tom';
            this.arrMonitor.infoArr[1].age = 19;
          })
        Button('Change whole infoArr')
          .onClick(() => {
            // Can trigger the onInfoArrChange, onInfoArrPropertyChange, and onInfoArrLengthChange methods.
            this.arrMonitor.infoArr = [new Info('Cindy', 8)];
          })
        Button('Push new info to infoArr')
          .onClick(() => {
            // Can trigger the onInfoArrPropertyChange and onInfoArrLengthChange methods.
            this.arrMonitor.infoArr.push(new Info('David', 50));
          })
      }
    }
  }
  ```

- When the entire object changes but the listened attributes remain unchanged, the \@SyncMonitor callback is not triggered.

  The following code represents the behavior in the comment when you execute the instructions in the sequence of Step 1, Step 2 and Step 3.

  If you only execute the instruction of Step 2 or Step 3 to change the values of **name** or **age**, the **onNameChange** and **onAgeChange** methods are triggered.

  <!-- @[monitor_entire_object_change_but_property_no_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorEntireObjectChangeButPropertyNoChange.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public person: Person;
  
    @SyncMonitor('person.name')
    onNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    @SyncMonitor('person.age')
    onAgeChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    constructor(name: string, age: number) {
      this.person = new Person(name, age);
    }
  }
  
  @ObservedV2
  class Person {
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
  
    build() {
      Column() {
        Button('Step1: Only change name')
          .onClick(() => {
            this.info.person = new Person('Jack', 25); // Can trigger the onNameChange method, but not the onAgeChange method.
          })
        Button('Step2: Only change age')
          .onClick(() => {
            this.info.person = new Person('Jack', 18); // Can trigger the onAgeChange method, but not the onNameChange method.
          })
        Button('Step3: Change name and age')
          .onClick(() => {
            this.info.person = new Person('Lucy', 19); // Can trigger the onNameChange and onAgeChange methods.
          })
      }
    }
  }
  ```

- If an attribute listened by \@SyncMonitor is changed multiple times in an event, \@SyncMonitor is called each time the attribute is changed.

  The behavior of \@SyncMonitor is different from that of \@Monitor. \@Monitor is called only once and the last modification takes effect.

  <!-- @[syncmonitor_behaves_differently_from_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/SyncMonitorBehavesDifferentlyFromMonitor.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Frequency {
    @Trace public count: number = 0;
  
    @SyncMonitor('count')
    onCountChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `count change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    frequency: Frequency = new Frequency();
  
    build() {
      Column() {
        Button('change count to 1000')
          .onClick(() => {
            for (let i = 1; i <= 1000; i++) {
              this.frequency.count = i;
            }
          })
        Button('change count to 0 then to 1000')
          .onClick(() => {
            for (let i = 999; i >= 0; i--) {
              this.frequency.count = i;
            }
            this.frequency.count = 1000; // The onCountChange method will be triggered.
          })
      }
    }
  }
  ```

  After you click `change count to 1000`, the `onCountChange` method is triggered 1000 times, and the logs are as follows:

  ``` text
  count change from 0 to 1
  count change from 1 to 2
  count change from 2 to 3
  ...
  count change from 999 to 1000
  ```

  After only `change count to 0 then to 1000` is clicked, `onCountChange` is triggered 1001 times, and the logs are as follows:

  ``` text
  count change from 0 to 999
  count change from 999 to 998
  ...
  count change from 1 to 0
  count change from 0 to 1000
  ```

  Difference from \@Monitor: In the preceding example, @SyncMonitor('count') is replaced with @Monitor('count'). If you press any button, the listening function decorated by @Monitor is executed only once.

- If multiple attributes observed by \@SyncMonitor change in different value assignment operations, the \@SyncMonitor callback is called immediately after each value assignment operation. This is contrary to the behavior of \@Monitor, which is called only once and uses the last changed value. Calling an API of the **Array** type may change multiple elements in the array at a time, but the callback function decorated with \@SyncMonitor is triggered only once each time.

  <!-- @[syncmonitor_array_multi_path](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/SyncMonitorArrayMultiPath.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  @Entry
  @ComponentV2
  struct DocSampleArrayMultiPath {
    @Local arr: Array<number> = [0, 1, 2, 3, 4, 5]
  
    @SyncMonitor('arr','arr.0','arr.1','arr.2','arr.3','arr.4','arr.length')
    onArrChangedSync(m: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `@SyncMonitor: arr: [${this.arr}], m.dirty: [${m.dirty}]`);
    }
  
    build() {
      Column() {
        Button('Change array by making separate assignments')
          .onClick(() => {
            hilog.info(0xFF00, 'testTag', 'arr[1] assign ...');
            this.arr[1] = 100;
            hilog.info(0xFF00, 'testTag', 'arr[2] assign ...');
            this.arr[2] = 200;
            hilog.info(0xFF00, 'testTag', '.. done');
          })
  
        Button('Change array with array functions')
          .onClick(() => {
            hilog.info(0xFF00, 'testTag', 'splice execute ...');
            // changes arr from [ 0, 1, 2, 3, 4, 5 ] to [ 0, 100, 101, 102, 5]
            this.arr.splice(1, 4, 100, 101, 102);
            hilog.info(0xFF00, 'testTag', 'shift execute ...');
            // changes arr from [ 0, 100, 101, 102, 5] to [ 100, 101, 102, 5]
            this.arr.shift();
            hilog.info(0xFF00, 'testTag', '.. done');
          })
      }
    }
  }
  ```

  Start the application. Press `Change array by making separate assignments`. The code execution process is as follows:

  1. Execute **onClick**;

  2. Print **arr[1] assign ...**.

  3. Run the onArrChangedSync command and print the log '@SyncMonitor: arr: [0,100,2,3,4,5], m.dirty [arr.1]';

  4. Print **arr[2] assign ...**.

  5. Run the **onArrChangedSync** command and print the log information '@SyncMonitor: arr: [0,100,200,3,4,5], m.dirty: [arr.2]';

  6. After **onClick** is executed, the log **.. done** is recorded.

  Start the application. Press `Change array with array functions`. The code execution process is as follows:

  1. Execute **onClick**;

  2. Print **splice execute ...**;

  3. Run the **onArrChangedSync** command to print the '@SyncMonitor: arr: [0,100,101,102,5], m.dirty: [arr.1,arr.2,arr.3,arr.4,arr.length]' log;

  4. Print the log **shift execute ...**;

  5. Run the **onArrChangedSync** command and print the '@SyncMonitor: arr: [100,101,102,5], m.dirty: [arr.0,arr.1,arr.2,arr.3,arr.4,arr.length]' log;

  6. Print the **.. done** log.

## Wildcards in the Observation Path

The wildcard (*) in the \@SyncMonitor path can be used to trigger a callback when any object attribute or array item is changed.

### When the observed attribute changes or a value is assigned to an object, the listening function is automatically executed.

<!-- @[wildcard_monitor_object_property_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/WildcardMonitorObjectPropertyChange.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class ClassA {
  @Trace public propA: number = 8;
  @Trace public propB: number = 99;

  constructor(a: number, b: number) {
    this.propA = a;
    this.propB = b;
  }
}

@Entry
@ComponentV2
struct DocSampleClass {
  @Local cls: ClassA = new ClassA(100, 100);

  @SyncMonitor('cls.*')
  onClsChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `### onClsChanged, dirty: ${m.dirty.toString()}`);
  }

  build() {
    Column() {
      Divider()
      Button(`#1 Change propA ${this.cls.propA}: +=1`)
        .onClick(() => {
          this.cls.propA += 1; // Trigger onClsChanged.
        })
      Button(`#2 Change propB ${this.cls.propB}: +=1`)
        .onClick(() => {
          this.cls.propB += 1; // Trigger onClsChanged.
        })
      Button(`#3 Assign class object`)
        .onClick(() => {
          this.cls = new ClassA(-200, -200); // Trigger onClsChanged.
        })
    }
    .border({ style: BorderStyle.Solid, width: 2, color: Color.Green })
  }
}
```

When button #1 or #2 is clicked (to update the properties of the listened object **cls**), the value of **m.dirty** is the same, including **m.dirty==['cls.*']**. The framework cannot accurately tell which attribute triggers the execution of the listening function.

For button #3 (assigning a new object to the **cls** attribute), the framework transfers **cls** to the dirty attribute array, that is, **m.dirty==['cls.*']**.

```text
Click Button #1. The following log is displayed:
### onClsChanged, dirty: cls.*

Click Button #2. The following log is displayed:
### onClsChanged, dirty: cls.*

Click Button #3. The following log is displayed:
### onClsChanged, dirty: cls.*
```

### When an array item is changed or a value is assigned to an array, the listening function is automatically executed.

Path for observing the synchronization listener: **@SyncMonitor('arrayOfPerson.*')**

<!-- @[wildcard_monitor_array_item_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/WildcardMonitorArrayItemChange.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Person {
  @Trace public firstName: string;
  @Trace public lastName: string;

  constructor(first: string = 'no first', last: string = 'no last') {
    this.firstName = first;
    this.lastName = last;
  }
}

@ObservedV2
class ArrayOfPerson extends Array<Person> {
}

@Entry
@ComponentV2
struct DocSampleArray {
  @Local arrayOfPerson: ArrayOfPerson =
    [new Person('Adrian'), new Person('Andrew'), new Person('Aaliyah'), new Person('Amir'), new Person('Angel')];

  @SyncMonitor('arrayOfPerson.*')
  arrayOfPersonMonitor(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `### SyncMonitor dirty: ${monitor.dirty.toString()}`);
  }

  build() {
    Column() {
      Button('#1 arrayOfPerson.push')
        .onClick(() => {
          // Trigger the arrayOfPersonMonitor callback.
          this.arrayOfPerson.push(new Person('Austin'));
        })
      Button('#2 arrayOfPerson.splice(0,1,P)')
        .onClick(() => {
          // Trigger the arrayOfPersonMonitor callback.
          this.arrayOfPerson.splice(0, 1, new Person('Addison'));
        })
      Button('#3 arrayOfPerson.assign new [1]')
        .onClick(() => {
          if (this.arrayOfPerson.length > 1) {
            // Trigger the arrayOfPersonMonitor callback.
            this.arrayOfPerson[1] = new Person('Andy');
          }
        })
      Button('#4 arrayOfPerson shift')
        .onClick(() => {
          if (this.arrayOfPerson.length > 2) {
            // Trigger the arrayOfPersonMonitor callback.
            this.arrayOfPerson.shift();
          }
        })
      Button('#5 arrayOfPerson length change')
        .onClick(() => {
          // Trigger the arrayOfPersonMonitor callback.
          this.arrayOfPerson.length = this.arrayOfPerson.length + 1;
        })
      Button('#6 arrayOfPerson = new Array')
        .onClick(() => {
          // Trigger the arrayOfPersonMonitor callback.
          this.arrayOfPerson = new ArrayOfPerson(new Person('Adrian'), new Person('Andrew'))
        })
      Button('#7 arrayOfPerson [1] last name')
        .onClick(() => {
          if (this.arrayOfPerson.length > 1 && this.arrayOfPerson[1] instanceof Person) {
            // The arrayOfPersonMonitor callback is not triggered.
            this.arrayOfPerson[1].lastName += '~'
          }
        })
    }
  }
}
```

When you press buttons 1 to 6, the listener function is triggered.

```text
### SyncMonitor dirty: arrayOfPerson.*
```

When you press button 7, the listener function is not called because no array item is changed.

### The Listening Function Is Executed When the Attributes of the Nested Observed Object Are Changed

<!-- @[wildcard_monitor_nested_object_property_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/WildcardMonitorNestedObjectPropertyChange.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Person {
  @Trace public firstName: string = 'first';
  @Trace public lastName: string = 'last';
}

@ObservedV2
class Class1 {
  @Trace public person: Person = new Person();
}

@ObservedV2
class Class0 {
  @Trace public class1: Class1 = new Class1();
}

@Entry
@ComponentV2
export struct DocSampleNestedClass {
  @Local class0: Class0 | number = new Class0();

  @SyncMonitor('class0.class1.person.*')
  onPersonChange(info: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', '### onPersonChange, dirty: ' + info.dirty.toString());
  }

  build() {
    Column() {
      Button('#1 Class0 = new Class')
        .onClick(() => {
          // Trigger the @SyncMonitor callback.
          this.class0 = new Class0();
        })
      Button('#2 Class0 = new Class, keep Class1')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // When class0 is of the Class0 type, the @SyncMonitor callback is not triggered.
            let newClass0 = new Class0();
            newClass0.class1.person = (this.class0 as Class0).class1.person;
            this.class0 = newClass0;
          }
        })
      Button('#3 Class0.class1 = new Class1')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // When class0 is of the Class0 type, the @SyncMonitor callback is triggered.
            (this.class0 as Class0).class1 = new Class1();
          }
        })
      Button('#4 Class0.class1.person = new Person')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // When class0 is of the Class0 type, the @SyncMonitor callback is triggered.
            (this.class0 as Class0).class1.person = new Person();
          }
        })
      Button('#5 Class0....person.last update')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // When class0 is of the Class0 type, the @SyncMonitor callback is triggered.
            (this.class0 as Class0).class1.person.lastName += '+';
          }
        })
      Button('#6 Class0 toggle number <=> new Class0')
        .onClick(() => {
          // Trigger the @SyncMonitor callback.
          this.class0 = (typeof this.class0 === 'object') ? 500 : new Class0();
        })
    }
  }
}
```

Start the application. When the **#1 Class0 = new Class** button is pressed, the listening function is triggered because the **Person** object has been changed.

```text
### onPersonChange, dirty: class0.class1.person.*
```

Start the application. When the **#2 Class0 = new Class, keep Class1** button is pressed, the listening function is not executed because the listened **Person** object remains unchanged.

Start the application. When the **#3 Class0.class1 = new Class1** button is pressed, the listening function is triggered because the **Person** object has been changed.

```text
### onPersonChange, dirty: class0.class1.person.*
```

Start the application. When the **#4 Class0.class1.person = new Person** button is pressed, the listening function is triggered because the **Person** object has been changed.

```text
### onPersonChange, dirty: class0.class1.person.*
```

Start the application. When the **#5 Class0....person.last update** button is pressed, the listening function is triggered because the attributes of the **Person** object have been changed.

```text
### onPersonChange, dirty: class0.class1.person.*
```

Start the application. When the **#6 Class0 toggle number <=> new Class0** button is pressed, the listening function is triggered because the path value is changed from the **Person** class reference to undefined.

```text
### onPersonChange, dirty: class0.class1.person.*
```

When the same button **#6 Class0 toggle number <=> new Class0** is pressed for the second time, the framework calls the listening function again and notifies it that the object has been changed from **undefined** to an instance of the **Person** class.

\@Monitor and \@SyncMonitor differ in how they handle paths that become unavailable.

\@SyncMonitor triggers execution in both cases - when the path becomes unavailable and when the path becomes available again.

\@Monitor triggers the execution of only one condition - only when the path becomes available again. When undefined is assigned to an object in the path, the callback function decorated by \@Monitor will not be triggered.

If the sample application contains **@Monitor('class0.class1.person')**, \@Monitor cannot listen to the change when the path becomes unavailable. When **this.class0 = 500** is used to change the value, the callback function decorated by \@Monitor is not triggered. When a value is assigned to **Class0** again, that is, **this.class0 = new Class0**, the callback function decorated by \@Monitor is triggered.

### Wildcard Listening for Array Item Changes

When the properties of a nested observed object are changed, the listening function is executed.

The listening function is also executed when the array and array item changes are observed.

In the following example, there are two \@SyncMonitor listening paths: **topArray.1.*** and **topArray.***.

<!-- @[wildcard_monitor_array_first_item_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/WildcardMonitorArrayFirstItemChange.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Person {
  @Trace firstName: string = 'first';
  @Trace lastName: string = 'last';

  constructor(first: string = 'no first', last: string = 'no last') {
    this.firstName = first;
    this.lastName = last;
  }
}

@ObservedV2
class ArrayOfPerson extends Array<Person> {
}

@ObservedV2
class TopArray extends Array<ArrayOfPerson> {
}

@Entry
@ComponentV2
struct DocSampleArrayOfArrays {
  @Local topArray: TopArray = this.makeNewTopArray();

  @SyncMonitor('topArray.1.*')
  topArrayMonitor1Star(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray[1]: ${monitor.dirty.toString()}`);
  }

  @SyncMonitor('topArray.*')
  topArrayMonitorStar(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray: ${monitor.dirty.toString()}`);
  }

  makeNewTopArray(): TopArray {
    return new TopArray(
      new ArrayOfPerson(new Person('Adrian'), new Person('Andrew'), new Person('Aaliyah'), new Person('Amir'),
        new Person('Angel')),
      new ArrayOfPerson(new Person('Carter'), new Person('Charlie'), new Person('Cooper'), new Person('Cole'),
        new Person('Callie')),
      new ArrayOfPerson(new Person('Daniel'), new Person('Daisy'), new Person('Dawson'), new Person('Dana'),
        new Person('Dalton'))
    );
  }

  build() {
    Column() {
      // Both the topArrayMonitor1Star and topArrayMonitorStar callbacks are triggered.
      Button('topArray = new TopArray')
        .onClick(() => {
          this.topArray = this.makeNewTopArray();
        })

      // When topArray[1][0] exists, the topArrayMonitor1Star callback is triggered, but the topArrayMonitorStar callback is not triggered.
      Button('topArray[1][0] = new Person')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0) {
            this.topArray[1][0] = new Person();
          }
        })

      // When topArray[0][1] exists, neither the topArrayMonitor1Star nor the topArrayMonitorStar callback is triggered.
      Button('topArray[0][1] = new Person')
        .onClick(() => {
          if (this.topArray.length > 0 && this.topArray[0].length > 1) {
            this.topArray[0][1] = new Person();
          }
        })

      // When topArray[1] exists, the topArrayMonitor1Star callback is triggered, but the topArrayMonitorStar callback is not triggered.
      Button('topArray[1].push')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1] instanceof ArrayOfPerson) {
            this.topArray[1].push(new Person());
          }
        })

      // When the length of topArray is greater than 2, both the topArrayMonitor1Star and topArrayMonitorStar callbacks are triggered.
      Button('topArray.shift (length>2)')
        .onClick(() => {
          if (this.topArray.length > 2) {
            this.topArray.shift();
          }
        })

      // When topArray[0] exists, the topArrayMonitor1Star callback is not triggered, but the topArrayMonitorStar callback is triggered.
      Button('topArray[0] = new ArrayOfPerson')
        .onClick(() => {
          if (this.topArray.length > 0) {
            this.topArray[0] = new ArrayOfPerson(new Person(), new Person());
          }
        })

      // When topArray[1][0] exists, neither the topArrayMonitor1Star nor the topArrayMonitorStar callback is triggered.
      Button('topArray[1][0].last update')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0 && this.topArray[1][0] instanceof Person) {
            this.topArray[1][0].lastName += '~';
          }
        })

      // The topArrayMonitor1Star callback is not triggered, but the topArrayMonitorStar callback is triggered.
      Button('topArray = new TopArray, keep [1]')
        .onClick(() => {
          let newTop = this.makeNewTopArray();
          newTop[1] = this.topArray[1]; // topArray.1 is not changed, and the last determined value before the wildcard in the path 'topArray.1.*' is not changed.
          this.topArray = newTop;
        })

      // The topArrayMonitor1Star callback is not triggered, but the topArrayMonitorStar callback is triggered.
      Button('topArray.push')
        .onClick(() => {
          this.topArray.push(new ArrayOfPerson(new Person(), new Person()));
        })
    }
  }
}
```

## Constraints

Pay attention to the following restrictions when using \@SyncMonitor:

- You are not advised to perform \@SyncMonitor listening on the same attribute for multiple times in a class. When a property in a class is listened for multiple times, only the last listening method takes effect.

  <!-- @[monitor_the_same_variable_two_times](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorTheSameVariableTwoTimes.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public name: string = 'Tom';
  
    @SyncMonitor('name')
    onNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `onNameChange`);
    }
  
    @SyncMonitor('name')
    onNameChangeDuplicate(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `onNameChangeDuplicate`);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    info: Info = new Info();
  
    build() {
      Column() {
        Button('change name')
          .onClick(() => {
            this.info.name = 'Jack'; // Only the onNameChangeDuplicate method is triggered.
          })
      }
    }
  }
  ```

- When @SyncMonitor receives multiple path parameters, the system determines whether it is a duplicate listener based on the full concatenation result of the parameters. Spaces are added between parameters during concatenation to distinguish them. For example, the full concatenation of 'ab' and 'c' is 'ab c', while 'a' and 'bc' become 'a bc'. These results are not equal. In the following example, `SyncMonitor 1`, `SyncMonitor 2`, and `SyncMonitor 3` all listen for changes to the name attribute. The full concatenation of the input parameters of `SyncMonitor 2` and `SyncMonitor 3` are the same (both are `'name position'`). Therefore, `SyncMonitor 2` does not take effect, and only `SyncMonitor 3` takes effect. When the name attribute changes, both **onNameAgeChange** and **onNamePositionChangeDuplicate** are triggered simultaneously. Note that the pattern of `SyncMonitor 2` and `SyncMonitor 3` is still considered as performing @SyncMonitor listening on the same attribute multiple times in a class, which is not recommended.

  <!-- @[monitor_duplicate_multiple_paths](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorDuplicateMultiplePaths.ets) -->

  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public name: string = 'Tom';
    @Trace public age: number = 25;
    @Trace public position: string = 'North';
  
    @SyncMonitor('name', 'age') // SyncMonitor 1
    onNameAgeChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `onNameAgeChange path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
    }
  
    @SyncMonitor('name', 'position') // SyncMonitor 2
    onNamePositionChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `onNamePositionChange path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
    }
  
    // name and position are observed repeatedly. Only the last definition takes effect
    @SyncMonitor('name', 'position') // SyncMonitor 3
    onNamePositionChangeDuplicate(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `onNamePositionChangeDuplicate path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    info: Info = new Info();
  
    build() {
      Column() {
        Button('change name')
          .onClick(() => {
            this.info.name = 'Jack'; // Triggers both onNameAgeChange and onNamePositionChangeDuplicate
          })
      }
    }
  }
  ```

- The parameter of \@SyncMonitor must be a string of the listening attribute name. Only string literals can be used. Constants, enumerated values, and variables cannot be used as parameters. If const constants, enumerated values, and variables are used as parameters, an error is reported during compilation. The following example shows the normal application scenario of @SyncMonitor.

  ```TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const propB: string = 'propB'; // const Constant
  
  enum ENUM {
    propC = 'PropC' // Enumerated value.
  };
  let propD: string = 'propD'; // Variable.
  
  @ObservedV2
  class Info {
    @Trace public propA: number = 0;
    @Trace public propB: number = 0;
    @Trace public propC: number = 0;
    @Trace public propD: number = 0;
  
    // @SyncMonitor supports only string literals.
    @SyncMonitor('propA')
    onPropAChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propA change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    // The input parameter type of @SyncMonitor is const. An error is reported during compilation, indicating `Only constant expressions are supported as parameters in '@SyncMonitor'. Variables are not allowed.`.
    @SyncMonitor(propB)
    onPropBChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propB change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
    
    // If the input parameter type of @SyncMonitor is enum, an error is reported during compilation, indicating `Only constant expressions are supported as parameters in '@SyncMonitor'. Variables are not allowed.`.
    @SyncMonitor(ENUM.propC)
    onPropCChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propC change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
    
    // The input parameter type of @SyncMonitor is variable. An error is reported during compilation, indicating `Only constant expressions are supported as parameters in '@SyncMonitor'. Variables are not allowed.`.
    @SyncMonitor(propD)
    onPropDChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propD change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    info: Info = new Info();
  
    build() {
      Column() {
        Button('Change propA')
          .onClick(() => {
            this.info.propA++; // The onPropAChange method can be triggered.
          })
      }
    }
  }
  ```

- You are advised not to change the listened attributes in \@SyncMonitor again. Otherwise, an infinite loop occurs.

  ```ts
  @ObservedV2
  class Info {
    @Trace count: number = 0;
    @SyncMonitor('count')
    onCountChange(monitor: IMonitor) {
      this.count++; // Avoid using this method because it may cause infinite loops.
    }
  }
  ```

## Use Cases

### Listening for Deep Property Changes

\@SyncMonitor can listen to the changes of deep attributes and classify the attributes based on the values before and after the changes.

In the following example, the change of property **value** is listened to and the display style of the **Text** component is changed based on the change amplitude.

<!-- @[monitor_deep_property_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorDeepPropertyChange.ets) -->

``` TypeScript
@ObservedV2
class Info {
  @Trace public value: number = 50;
}

@ObservedV2
class UIStyle {
  public info: Info = new Info();
  @Trace public color: Color = Color.Black;
  @Trace public fontSize: number = 45;

  @SyncMonitor('info.value')
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
      Button('change!')
        .onClick(() => {
          this.textStyle.info.value = Math.floor(Math.random() * 100) + 1;
        })
    }
  }
}
```

## FAQs

### Effective and Expiration Time of Variable Listening by the \@SyncMonitor in the Custom Component

When \@SyncMonitor is defined in a custom component decorated by \@ComponentV2, \@SyncMonitor takes effect after the state variable is initialized and becomes invalid when the component is destroyed.

<!-- @[effective_and_ineffective_times_of_variable_monitoring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/EffectiveAndIneffectiveTimesOfVariableMonitoring.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  @Trace public message: string = 'not initialized';

  constructor() {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'in constructor message change to initialized');
    this.message = 'initialized';
  }
}

@ComponentV2
struct Child {
  @Param info: Info = new Info();

  @SyncMonitor('info.message')
  onMessageChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `Child message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  aboutToAppear(): void {
    this.info.message = 'Child aboutToAppear';
  }

  aboutToDisappear(): void {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'Child aboutToDisappear');
    this.info.message = 'Child aboutToDisappear';
  }

  build() {
    Column() {
      Text('Child')
      Button('change message in Child')
        .onClick(() => {
          this.info.message = 'Child click to change Message';
        })
    }
    .borderColor(Color.Red)
    .borderWidth(2)

  }
}

@Entry
@ComponentV2
struct Index {
  @Local info: Info = new Info();
  @Local flag: boolean = false;

  @SyncMonitor('info.message')
  onMessageChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `Index message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column() {
      Button('show/hide Child')
        .onClick(() => {
          this.flag = !this.flag;
        })
      Button('change message in Index')
        .onClick(() => {
          this.info.message = 'Index click to change Message';
        })
      if (this.flag) {
        Child({ info: this.info })
      }
    }
  }
}
```

In the preceding example, you can create and destroy a **Child** component to observe the effective and expiration time of the \@SyncMonitor defined in the custom component. You are advised to follow the steps below:

- When the **Index** component creates an instance of the **Info** class, the log outputs the message: **in constructor message change to initialized**. At this time, the \@SyncMonitor of the **Index** component has not been initialized successfully, so \@SyncMonitor cannot listen for the message change.

- After the **Index** component is created and the page is loaded, click **change message in Index** button. \@SyncMonitor now can listen for the change and the log outputs the message "Index message change from initialized to Index click to change Message".

- Click the **show/hide Child** button to create a **Child** component. After this component initializes the \@Param decorated variables and \@SyncMonitor, call the **aboutToAppear** callback of the **Child** component to change the message. In this case, the \@SyncMonitor of the **Index** and **Child** components can listen for the change, and the logs outputs the messages "Index message change from Index click to change Message to Child aboutToAppear" and "Child message change from Index click to change Message to Child aboutToAppear."

- Click **change message in Child** button to change the message. In this case, the \@SyncMonitor of the **Index** and **Child** components can listen for the change, and the log outputs the messages "Index message change from Child aboutToAppear to Child click to change Message" and "Child message change from Child aboutToAppear to Child click to change Message."

- Click the **show/hide Child** button to destroy the **Child** component and call the **aboutToDisappear** callback to change the message. In this case, the \@SyncMonitor of the **Index** and **Child** components can listen for the change, and the log outputs the messages "Child aboutToDisappear, Index message change from Child click to change Message to Child aboutToDisappear", and "Child message change from Child click to change Message to Child aboutToDisappear."

- Click **change message in Index** button to change the message. In this case, the **Child** component is destroyed, and the \@SyncMonitor is deregistered. Only the \@SyncMonitor of the **Index** component can listen for the changes and the log outputs the message "Index message change from Child aboutToDisappear to Index click to change Message."

The preceding steps indicate that the \@SyncMonitor defined in the **Child** component takes effect when the **Child** component is created and initialized, and becomes invalid when the **Child** component is destroyed.

### Effective and Expiration Time of Variable Listening by the \@SyncMonitor in the Class

When \@SyncMonitor is defined in a class decorated with \@ObservedV2, it takes effect after the class instance is created and becomes invalid when the class instance is destroyed.

<!-- @[syncmonitor_class_effective_time](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/SyncMonitorClassEffectiveTime.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  @Trace public message: string = 'not initialized';

  constructor() {
    this.message = 'initialized';
  }

  @SyncMonitor('message')
  onMessageChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  aboutToAppear(): void {
    this.info.message = 'Index aboutToAppear';
  }

  build() {
    Column() {
      Button('change message')
        .onClick(() => {
          this.info.message = 'Index click to change message';
        })
    }
  }
}
```

In the preceding example, \@SyncMonitor takes effect after the **info** class is created, which is later than the **constructor** of the class and earlier than the **aboutToAppear** of the custom component. After the page is loaded, click the **change message** button to modify the message variable. The log outputs the messages as below:

```ts
message change from initialized to Index aboutToAppear
message change from Index aboutToAppear to Index click to change message
```

\@SyncMonitor defined in a class becomes invalid when the class is destroyed. However, since the actual destruction and release of the class depends on the garbage collection mechanism, a situation may occur where the class is not destroyed in time even though the custom component that hosts it has already been destroyed. As a result, the \@SyncMonitor defined in the class still listens for changes.

<!-- @[syncmonitor_class_gc_destruction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/SyncMonitorClassGcDestruction.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class InfoWrapper {
  public info?: Info;

  constructor(info: Info) {
    this.info = info;
  }

  @SyncMonitor('info.age')
  onInfoAgeChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}

@ObservedV2
class Info {
  @Trace public age: number;

  constructor(age: number) {
    this.age = age;
  }
}

@ComponentV2
struct Child {
  @Param @Require infoWrapper: InfoWrapper;

  aboutToDisappear(): void {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'Child aboutToDisappear');
  }

  build() {
    Column() {
      Text(`${this.infoWrapper.info?.age}`)
    }
  }
}

@Entry
@ComponentV2
struct Index {
  dataArray: Info[] = [];
  @Local showFlag: boolean = true;

  aboutToAppear(): void {
    for (let i = 0; i < 5; i++) {
      this.dataArray.push(new Info(i));
    }
  }

  build() {
    Column() {
      Button('change showFlag')
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
      Button('change number')
        .onClick(() => {
          hilog.info(0xFF00, 'testTag', '%{public}s', 'click to change age');
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          });
        })
      if (this.showFlag) {
        Column() {
          Text('Children')
          ForEach(this.dataArray, (info: Info) => {
            Child({ infoWrapper: new InfoWrapper(info) })
          })
        }
        .borderColor(Color.Red)
        .borderWidth(2)
      }
    }
  }
}
```

In the preceding example, when you click **change showFlag** to switch the condition of the **if** component, the **Child** component is destroyed. But when you click **change number** to change the value of **age**, the \@SyncMonitor callback defined in **InfoWrapper** is still triggered. This is because the custom component **Child** has executed **aboutToDisappear**, but its member variable **infoWrapper** is not destroyed immediately. When the variable changes, the **onInfoAgeChange** method defined in **infoWrapper** can still be called, therefore, the \@SyncMonitor callback is still triggered.

The result is unstable when you use the garbage collection mechanism to cancel the listening of \@SyncMonitor. You can use the following methods to manage the expiration time of the \@SyncMonitor:

Define \@SyncMonitor in a custom component. When a custom component is destroyed, the state management framework cancels the \@SyncMonitor listening. Therefore, after the custom component calls **aboutToDisappear**, the \@SyncMonitor callback will no longer be triggered, even though the custom component's data may not have been released yet. Unlike @Monitor, when the custom component is about to be destroyed, even if the object listened by \@SyncMonitor is actively set to empty, \@SyncMonitor can still listen for changes of the original target.

<!-- @[syncmonitor_component_destruction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/SyncMonitorComponentDestruction.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class InfoWrapper {
  public info?: Info;

  constructor(info: Info) {
    this.info = info;
  }
}

@ObservedV2
class Info {
  @Trace public age: number;

  constructor(age: number) {
    this.age = age;
  }
}

@ComponentV2
struct Child {
  @Param @Require infoWrapper: InfoWrapper;

  @SyncMonitor('infoWrapper.info.age')
  onInfoAgeChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  aboutToDisappear(): void {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'Child aboutToDisappear');
  }

  build() {
    Column() {
      Text(`${this.infoWrapper.info?.age}`)
    }
  }
}

@Entry
@ComponentV2
struct Index {
  dataArray: Info[] = [];
  @Local showFlag: boolean = true;

  aboutToAppear(): void {
    for (let i = 0; i < 5; i++) {
      this.dataArray.push(new Info(i));
    }
  }

  build() {
    Column() {
      Button('change showFlag')
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
      Button('change number')
        .onClick(() => {
          hilog.info(0xFF00, 'testTag', '%{public}s', 'click to change age');
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          });
        })
      if (this.showFlag) {
        Column() {
          Text('Children')
          ForEach(this.dataArray, (info: Info) => {
            Child({ infoWrapper: new InfoWrapper(info) })
          })
        }
        .borderColor(Color.Red)
        .borderWidth(2)
      }
    }
  }
}
```

### Passing Correct Input Parameters to \@SyncMonitor

\@SyncMonitor cannot verify input parameters during compilation. Currently, the following statements do not meet the listening condition, but \@SyncMonitor is still triggered. Developers must correctly pass \@SyncMonitor input parameters and avoid passing non-state variables to prevent function exceptions or unexpected behavior.

[Incorrect Usage 1]

<!-- @[monitor_non_state_variable_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorNonStateVariableNegative.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // Only state variable 'age' can be observed. Observing the non-state variable 'name' will cause a compilation warning.
  // Note: `Cannot observe non-existent variables or non-state variables, except in wildcard-based monitoring scenarios.`
  @SyncMonitor('age', 'name')
  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  build() {
    Column() {
      Button('change age&name')
        .onClick(() => {
          this.info.age = 25; // Change both state variable age and non-state variable name.
          this.info.name = 'Johny';
        })
    }
  }
}
```

In the preceding code, an alarm is reported during compilation because the \@SyncMonitor input parameter transfers a non-state variable **name**. You are advised to remove the listening from the **name** attribute or use \@Trace to decorate the **name** attribute as a state variable.

When you click to change the state variable age and non-state variable name at the same time, the following log is generated:

```text
property path:age change from 24 to 25
```

[Correct Usage 1]

<!-- @[monitor_non_state_variable_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorNonStateVariablePositive.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // Observe only the state variable age
  @SyncMonitor('age')
  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  build() {
    Column() {
      Button('change age&name')
        .onClick(() => {
          this.info.age = 25; // The state variable "age" is changed.
          this.info.name = 'Johny';
        })
    }
  }
}
```

[Negative example 2]

<!-- @[monitor_non_computed_getter_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorNonComputedGetterNegative.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  public age: number = 24;

  get myAge() {
    return this.age; // age is a non-state variable.
  }

  // Listen to the non-@Computed decorated getter accessor. An alarm is reported during compilation.
  @SyncMonitor('myAge')
  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  build() {
    Column() {
      Button('change age')
        .onClick(() => {
          this.info.age = 25; // The state variable "age" is changed.
        })
    }
  }
}
```

In the preceding code, the input parameter of \@SyncMonitor is the name of a **getter** accessor. This accessor is not decorated by \@Computed and is not a variable that can be listened for. You are advised to add an \@Computed decorator to **myAge** or directly listen for the state variable itself when the **getter** accessor returns the state variable.

[Correct Usage 2]

Change **myAge** to a state variable:

<!-- @[monitor_computed_variable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorComputedVariable.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // Add @Computed to make myAge a state variable
  @Computed
  get myAge() {
    return this.age;
  }

  // Observe the @Computed-decorated getter accessor
  @SyncMonitor('myAge')
  onPropertyChange() {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'age changed');
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  build() {
    Column() {
      Button('change age')
        .onClick(() => {
          this.info.age = 25; // The state variable "age" is changed.
        })
    }
  }
}
```

Alternatively, listen to the state variable itself.

<!-- @[monitor_state_variable_directly](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorStateVariableDirectly.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // Observe the state variable age directly
  @SyncMonitor('age')
  onPropertyChange() {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'age changed');
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  build() {
    Column() {
      Button('change age')
        .onClick(() => {
          this.info.age = 25; // The state variable "age" is changed.
        })
    }
  }
}
```

### Invalid Path Using Wildcards

Valid listening path rules are as follows:

* The path must end with an asterisk (*).

* `*` cannot appear at the beginning of a path or inside a path.

Invalid wildcards are used in the following paths: An error is reported during compilation.

* **@SyncMonitor('*.propA')** - Error. The wildcard cannot be at the beginning of the path.

* **@SyncMonitor('arr.*.propA')** - Error. The wildcard cannot be in the middle of the path.

* **@SyncMonitor('obsArr.*.*')** - Error. Double wildcards are not allowed. Any attribute or array item supports only one level.

* **@SyncMonitor('obsArr.**')** - Error. The attribute or array item name ****** is invalid.

* **@SyncMonitor('obsObj*')** - Error. The attribute name **obsObj*** is invalid.

* `@SyncMonitor('obsObj.objObj2*')` - Error. The attribute name `obsObj2*` is invalid.

* `@SyncMonitor('*')` - Error. No attribute name exists.

### Observed Variables During Accessibility Changes

\@Monitor only saves values when variables are accessible. When a state variable becomes inaccessible, value changes aren't recorded. Since API version 20, if you need to observe accessibility changes (from accessible to inaccessible or vice versa), use [addMonitor](./arkts-new-addMonitor-clearMonitor.md#listening-for-variable-accessibility-changes).

\@SyncMonitor can listen to the change of a variable from accessible to inaccessible or from inaccessible to accessible. In the following example, the onChange callback is triggered when the three buttons are clicked.

<!-- @[monitor_variable_from_accessible_to_inaccessible](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorVariableFromAccessibleToInaccessible.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class User {
  @Trace public age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User | undefined | null = new User();

  @SyncMonitor('user.age')
  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`User age ${this.user?.age}`).fontSize(20)
      Button('set user to undefined').onClick(() => {
        // age: from accessible to inaccessible
        this.user = undefined;
      })
      Button('set user to User').onClick(() => {
        // age: from inaccessible to accessible
        this.user = new User();
      })
      Button('set user to null').onClick(() => {
        // age: from accessible to inaccessible
        this.user = null;
      })
    }
  }
}
```