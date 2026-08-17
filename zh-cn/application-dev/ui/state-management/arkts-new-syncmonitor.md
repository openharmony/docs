# \@SyncMonitor装饰器：状态变量修改同步监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了增强状态管理框架对状态变量变化的监听能力，开发者可以使用[\@SyncMonitor](../../reference/apis-arkui/arkui-ts/ts-state-management-syncmonitor.md#syncmonitor)装饰器对状态变量进行监听。

\@SyncMonitor提供了对V2状态变量的同步监听。在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-create-custom-components.md#componentv2)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，[\@Local](./arkts-new-local.md)，[\@Monitor](./arkts-new-monitor.md)。

>**说明：**
>
> \@SyncMonitor装饰器从API version 23开始支持。
>
> 从API version 23开始，该装饰器支持在原子化服务中使用。

## 概述

\@SyncMonitor装饰器用于同步监听状态变量修改，使得状态变量具有深度监听的能力：

- \@SyncMonitor装饰器支持在\@ComponentV2装饰的自定义组件中使用，未被状态变量装饰器[\@Local](arkts-new-local.md)、[\@Param](arkts-new-param.md)、[\@Provider](arkts-new-provider-and-consumer.md)、[\@Consumer](arkts-new-provider-and-consumer.md)、[\@Computed](arkts-new-computed.md)装饰的变量无法被\@SyncMonitor监听到变化。

## 装饰器使用规则说明

- \@SyncMonitor装饰器支持在类中与[\@ObservedV2、\@Trace](arkts-new-observedV2-and-trace.md)配合使用，不允许在未被\@ObservedV2装饰的类中使用\@SyncMonitor装饰器。未被\@Trace装饰的属性无法被\@SyncMonitor监听到变化。当观测的属性变化时，\@SyncMonitor装饰器定义的回调方法将被调用。判断属性是否变化使用的是严格相等（===），当严格相等判断的结果是false（即不相等）的情况下，就会立即触发\@SyncMonitor的回调。同一事件内，当被观察的属性多次改变时，回调函数将在每次属性改变时被调用。

- 单个\@SyncMonitor装饰器能够同时监听多个属性的变化，当这些属性在一次事件中共同变化时，只会触发一次\@SyncMonitor的回调方法。 当\@SyncMonitor监听整个数组时，更改数组的某一项不会被监听到。

- 在继承类场景中，可以在父子类中对同一个属性分别定义\@SyncMonitor进行监听，当属性变化时，父子组件中定义的\@SyncMonitor回调均会被调用。

- \@SyncMonitor装饰器具有深度监听的能力，能够监听嵌套类、多维数组、对象数组中指定项的变化。对于嵌套类、对象数组中成员属性变化的监听要求该类被\@ObservedV2装饰且该属性被\@Trace装饰。

- \@SyncMonitor可以观察内置类型`Map`、`Set`、`Date`以及`Array`类型API调用引起的数据变化，详情参见[通用监听能力](#通用监听能力)。

- \@SyncMonitor装饰器新增[通配符('*')](#监听路径中通配符的说明)支持一层模糊监听，便于\@Watch装饰器向\@SyncMonitor装饰器迁移。

### 比较\@Monitor，\@SyncMonitor和\@Watch

与[\@Watch](arkts-watch.md)装饰器类似，开发者必须自己定义回调函数。不同之处在于，\@Watch使用函数名作为参数，而\@SyncMonitor直接装饰回调函数。带有通配符监听路径的\@SyncMonitor监听范围与\@Watch一致。\@Watch和\@SyncMonitor装饰的函数都同步执行。下表比较\@Monitor、\@SyncMonitor和\@Watch的用法和功能。

| 类别                   | \@Watch                                 | \@Monitor                                                    |\@SyncMonitor                                                  |
| ------------------ | --------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 参数              | 回调方法名称                             | 监听到的状态变量名称和属性名称                                      | 监听到的状态变量名称和属性名称                                      |
| 监听目标数量        | 单个状态变量                   | 多个状态变量                                      | 多个状态变量     |
| 监听类型          | 模糊监听          | 支持模糊监听和精准监听                         | 支持模糊监听和精准监听                                |
| 获取变更前的值| 否                     | 是                                            | 是                                            |
| 观察条件          | 被观察对象是状态变量                     | 被观察对象是状态变量或用\@Trace装饰的类成员属性               | 被观察对象是状态变量或用\@Trace装饰的类成员属性               |
| 约束条件          | 仅在\@Component装饰的自定义组件中| 在\@ComponentV2装饰的自定义组件和\@ObservedV2装饰的类中 | 在\@ComponentV2装饰的自定义组件和\@ObservedV2装饰的类中 |
| 通配符支持 | 否  | 默认不支持，从API版本26.0.0开始可以通过配置项支持 | 是（从API version 23开始） |
| 回调调用时机 | 立即（同步） | 状态变更函数结束后（异步），多次变更，只触发一次。 |  立即（同步） |

[addMonitor和clearMonitor](./arkts-new-addMonitor-clearMonitor.md)API允许在应用程序执行期间动态添加和清除监听器。当isSynchronous设置为true，addMonitor类似于\@SyncMonitor，当设置为false，addMonitor类似于\@Monitor功能。

\@Monitor和\@SyncMonitor分别是\@ComponentV2和\@ObservedV2类的成员函数装饰器，属于V2状态管理的一部分。\@Watch是[@Component](./arkts-create-custom-components.md#component)中使用的变量装饰器，属于V1状态管理的一部分。

\@Monitor装饰的函数会异步执行，在事件处理程序执行结束后执行。\@SyncMonitor和\@Watch函数在观察到的状态变量改变后，回调函数会立即同步执行。

\@Monitor函数的执行可以由一个或多个特定跟踪对象属性的值变化而触发。\@Watch函数会在任何被观察的对象属性或数组项发生变化时执行，它无法监听一个或多个特定属性。

路径中带有通配符的\@SyncMonitor的行为与\@Watch相同。这使得应用程序从V1状态管理迁移到V2状态管理更加容易。下面是一个例子：

V1状态管理\@Watch示例代码:

```typescript
@Component 
struct CompV1 {
  @State @Watch('watchFuncName') varName: ClassA = initialValue; // ClassA是Class类型
  watchFuncName(propertyStr: string) {
    // ....
  }
}
```

迁移成V2状态管理\@SyncMonitor示例代码:
```typescript
@ComponentV2 
struct CompV2 {
  @Local varName: ClassA = initialValue;
  @SyncMonitor('varName.*') monitorFuncName(m: IMonitor) {
    // ....
  }
}
```
其中，ClassA是指复杂对象类型。下面的例子使用\@SyncMonitor和\@Monitor来跟踪sum属性的变化。

代码计算数组元素的和，在循环中计算sum时，sum的值依次变为1, 3, 6。

\@Monitor只调用一次，before值为0，now值为6。

\@SyncMonitor将调用其回调3次，分别对应从0到1、1到3和3到6的变化。

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
         .onClick(() => {  // 修改sum时，syncSumMonitor会回调3次，asyncSumMonitor只回调1次。
           this.sum = 0;
           this.arr.forEach((element) => this.sum += element);
         })
     }
   }
 }
 ```

日志输出:

```typescript
SyncMonitor - sum changed from 0 to 1
SyncMonitor - sum changed from 1 to 3
SyncMonitor - sum changed from 3 to 6
Monitor - sum changed from 0 to 6
```

## 装饰器说明
|\@SyncMonitor属性装饰器| 说明                                                        |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数         | 字符串类型的对象属性名称。可同时监听多个对象属性，每个属性以逗号隔开，例如： @SyncMonitor('prop1', 'prop2')。此外，可监听深层的属性变化：多维数组中的元素、嵌套对象中的属性、对象数组中的属性。支持在路径末尾添加通配符'*'来监听任意被观察属性的变化。详情参见 [监听变化](#监听变化)。|
| 装饰内容           | 成员方法。在被观察属性变化时，该回调会被触发。该回调方法以[IMonitor](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md#imonitor)类型的变量作为参数，开发者可以从该参数中获取变化前后的相关信息。|

## 监听路径中通配符的说明

当\@SyncMonitor装饰器监听路径中使用了通配符('*')时：

  - 对象赋值或对象任意属性变化都会触发；
  - 数组赋值或数组任意项变化都会触发；
  - 即可以监听任意属性变化或任意数组项变化；
  - 使用通配符时，`before`和`now`返回的值均是undefined；

通配符(`*`)的路径语法规则：
* 通配符只能出现在路径末尾；
* 通配符不能出现在路径开头，也不能出现在路径中间；

如下给出合法路径示例：
* `obj.*`（观察含\@Trace的对象） 
  - 当给obj赋新值时触发；
  - 当obj的任何被\@Trace装饰的属性变化时触发；
* `arr.*`（观察数组）
  - 当给arr赋新值时触发；
  - 当数组中任意项或数组长度变化时触发；
  - 调用`Array`类型的API，比如`copyWithin`、`fill`、`sort`、`push`，\@SyncMonitor装饰的回调函数也会执行；
* `obj.ObjA.objB.*`（观察嵌套对象中的对象）
  - 当obj、ObjA被重新赋值且objB变化时触发；
  - 当objB被重新赋值时触发；
  - 当objB内任意被\@Trace装饰属性变化时触发；
* `arr.1.*`（多维观察数组）
  - 给arr赋新值，且第1项的值发生变化时触发；
  - 当嵌套数组项的任何项或长度更改时触发；

## 接口说明

IMonitor类型和IMonitorValue\<T\>类型的接口说明参考API文档：[@Monitor：状态变量修改监听](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md)。

## 监听变化

### 在\@ComponentV2装饰的自定义组件中使用\@SyncMonitor

使用\@SyncMonitor监听的状态变量发生变化时，会触发\@SyncMonitor的回调方法。

- \@SyncMonitor监听的变量需要被\@Local、\@Param、\@Provider、\@Consumer、\@Computed装饰，未被状态变量装饰器装饰的变量在变化时无法被监听。\@SyncMonitor可以同时监听多个状态变量，这些变量名之间用','隔开。

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

- \@SyncMonitor监听的状态变量为类对象时，仅能监听对象整体的变化。监听类属性的变化需要类属性被\@Trace装饰，无法监听非状态变量的变化。
  
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
              this.info = new Info('Lucy', 18); // 能够监听到
            })
        }
      }
    }
    ```

### 在\@ObservedV2装饰的类中使用\@SyncMonitor

使用\@SyncMonitor监听的属性发生变化时，会触发\@SyncMonitor的回调方法。

- \@SyncMonitor监听的对象属性需要被\@Trace装饰，未被\@Trace装饰的属性的变化无法被监听。\@SyncMonitor可以同时监听多个属性，这些属性之间用','隔开。
  
   <!-- @[monitor_variables_in_observedv2_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorVariablesInObservedV2Class.ets) -->
   
   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   @ObservedV2
   class Info {
     @Trace public name: string = 'Tom';
     @Trace public region: string = 'North';
     @Trace public job: string = 'Teacher';
     public age: number = 25;
   
     // name被@Trace装饰，能够监听变化
     @SyncMonitor('name')
     onNameChange(monitor: IMonitor) {
       hilog.info(0xFF00, 'testTag', '%{public}s',
         `name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
     }
   
     // age未被@Trace装饰，不能监听变化
     @SyncMonitor('age')
     onAgeChange(monitor: IMonitor) {
       hilog.info(0xFF00, 'testTag', '%{public}s',
         `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
     }
   
     // region与job均被@Trace装饰，能够监听变化
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
             this.info.name = 'Jack'; // 能够触发onNameChange方法
           })
         Button('change age')
           .onClick(() => {
             this.info.age = 26; // 不能够触发onAgeChange方法
           })
         Button('change region')
           .onClick(() => {
             this.info.region = 'South'; // 能够触发onChange方法
           })
         Button('change job')
           .onClick(() => {
             this.info.job = 'Driver'; // 能够触发onChange方法
           })
       }
     }
   }
   ```

- \@SyncMonitor可以监听深层属性的变化，该深层属性需要被@Trace装饰。
  
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
            this.outer.inner.num = 100; // 能够触发onChange方法
          })
      }
    }
  }
  ```

- 在继承类场景下，可以在继承链中对同一个属性进行多次监听，父子类中定义的\@SyncMonitor回调均会被调用。

  <!-- @[monitor_variable_base_derived_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorVariableInBaseDerivedClass.ets) -->
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Base {
    @Trace public name: string;
  
    // 基类监听name属性
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
    // 继承类监听name属性
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
            this.derived.name = 'BBB'; // onDerivedNameChange方法会调用，父类的onBaseNameChange也会回调
          })
      }
    }
  }
  ```

### 通用监听能力

\@SyncMonitor还有一些通用的监听能力。

- \@SyncMonitor支持对数组项进行监听，包括多维数组，对象数组。\@SyncMonitor支持使用通配符监听由调用`Array`的API引起的变化，比如`copyWithin`、`fill`、`sort`、`push`。

- \@SyncMonitor可以观察由调用内置类型`Map`，`Date`和`Set`的API引起的变化，例如，如果调用`set`、`add`、`delete`修改数据集合，则将执行监听函数。`Map`和`Set`中对应key的变化，不会执行监听函数，框架会打印错误日志。

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
  
    // dimensionTwo为二维简单类型数组，且被@Trace装饰，能够观测里面的元素变化
    @SyncMonitor('dimensionTwo.0.0', 'dimensionTwo.1.1')
    onDimensionTwoChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `dimensionTwo path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // dimensionThree为三维简单类型数组，且被@Trace装饰，能够观测里面的元素变化
    @SyncMonitor('dimensionThree.0.0.0', 'dimensionThree.1.1.0')
    onDimensionThreeChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `dimensionThree path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // Info类中属性name、age均被@Trace装饰，能够监听到变化
    @SyncMonitor('infoArr.0.name', 'infoArr.1.age')
    onInfoArrPropertyChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `infoArr path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // infoArr被@Trace装饰，能够监听到infoArr整体赋值的变化
    @SyncMonitor('infoArr')
    onInfoArrChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `infoArr whole change`);
    }
  
    // 能够监听到infoArr的长度变化
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
            // 能够触发onDimensionTwoChange方法
            this.arrMonitor.dimensionTwo[0][0]++;
            this.arrMonitor.dimensionTwo[1][1]++;
          })
        Button('Change dimensionThree')
          .onClick(() => {
            // 能够触发onDimensionThreeChange方法
            this.arrMonitor.dimensionThree[0][0][0]++;
            this.arrMonitor.dimensionThree[1][1][0]++;
          })
        Button('Change info property')
          .onClick(() => {
            // 能够触发onInfoArrPropertyChange方法
            this.arrMonitor.infoArr[0].name = 'Tom';
            this.arrMonitor.infoArr[1].age = 19;
          })
        Button('Change whole infoArr')
          .onClick(() => {
            // 能够触发onInfoArrChange、onInfoArrPropertyChange、onInfoArrLengthChange方法
            this.arrMonitor.infoArr = [new Info('Cindy', 8)];
          })
        Button('Push new info to infoArr')
          .onClick(() => {
            // 能够触发onInfoArrPropertyChange、onInfoArrLengthChange方法
            this.arrMonitor.infoArr.push(new Info('David', 50));
          })
      }
    }
  }
  ```

- 对象整体改变，但监听的属性不变时，不触发\@SyncMonitor回调。

  下面的示例按照Step1-Step2-Step3的顺序点击，表现为代码注释中的行为。

  如果只点击Step2或Step3，改变name、age的值，此时会触发onNameChange和onAgeChange方法。
  
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
            this.info.person = new Person('Jack', 25); // 能够触发onNameChange方法，不触发onAgeChange方法
          })
        Button('Step2: Only change age')
          .onClick(() => {
            this.info.person = new Person('Jack', 18); // 能够触发onAgeChange方法，不触发onNameChange方法
          })
        Button('Step3: Change name and age')
          .onClick(() => {
            this.info.person = new Person('Lucy', 19); // 能够触发onNameChange、onAgeChange方法
          })
      }
    }
  }
  ```

- 在一次事件中多次改变被\@SyncMonitor监听的属性，\@SyncMonitor回调将在该属性每次改变时被调用。

  \@SyncMonitor与\@Monitor行为不一样，\@Monitor只被调用一次并以最后一次修改为准。

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
            this.frequency.count = 1000; // 最终会触发onCountChange方法
          })
      }
    }
  }
  ```
  
  点击`change count to 1000`后，`onCountChange`方法被触发1000次，日志输出：
  
  ``` text
  count change from 0 to 1
  count change from 1 to 2
  count change from 2 to 3
  ...
  count change from 999 to 1000
  ```
  
  只点击`change count to 0 then to 1000`后，`onCountChange` 被触发1001次，日志输出：
  
  ``` text
  count change from 0 to 999
  count change from 999 to 998
  ...
  count change from 1 to 0
  count change from 0 to 1000
  ```
  
  与\@Monitor的区别：在上面的例子中将@SyncMonitor('count')替换为@Monitor('count')。按下任一按钮，@Monitor装饰的监听函数仅执行一次。

- 如果\@SyncMonitor观察的多个属性在不同的赋值操作中发生改变，则每次赋值操作后都会立即调用\@SyncMonitor回调函数。这与\@Monitor的行为相反，后者只调用一次并使用最后一次更改的值。调用Array的API可能会一次改变多个数组元素，但每次只会触发一次\@SyncMonitor装饰的回调函数。

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

  启动应用。按下`Change array by making separate assignments`按钮，代码执行流程如下:

  1. 执行`onClick`；
  2. 打印`arr[1] assign ...`；
  3. 执行`onArrChangedSync`，打印日志: '@SyncMonitor: arr: [0,100,2,3,4,5], m.dirty: [arr.1]'；
  4. 打印日志`arr[2] assign ...`；
  5. 执行`onArrChangedSync`, 打印日志: '@SyncMonitor: arr: [0,100,200,3,4,5], m.dirty: [arr.2]'；
  6. onClick执行完毕，打印日志`.. done`。

  启动应用。按下`Change array with array functions`按钮，代码执行流程如下:

  1. 执行`onClick`；
  2. 打印`splice execute ...`；
  3. 执行`onArrChangedSync`, 打印日志'@SyncMonitor: arr: [0,100,101,102,5], m.dirty: [arr.1,arr.2,arr.3,arr.4,arr.length]'；
  4. 打印日志`shift execute ...`；
  5. 执行`onArrChangedSync`， 打印日志'@SyncMonitor: arr: [100,101,102,5], m.dirty: [arr.0,arr.1,arr.2,arr.3,arr.4,arr.length]'；
  6. 打印`.. done`日志。

## 观察路径中的通配符

\@SyncMonitor路径中的通配符(*)可用于在任何对象属性或任何数组项更改时触发回调。

### 被观察属性变更或对象赋值时，监听函数自动执行

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
          this.cls.propA += 1; // 触发onClsChanged
        })
      Button(`#2 Change propB ${this.cls.propB}: +=1`)
        .onClick(() => {
          this.cls.propB += 1; // 触发onClsChanged
        })
      Button(`#3 Assign class object`)
        .onClick(() => {
          this.cls = new ClassA(-200, -200); // 触发onClsChanged
        })
    }
    .border({ style: BorderStyle.Solid, width: 2, color: Color.Green })
  }
}
```

点击按钮#1或#2（更新被监听对象`cls`的属性）时，`m.dirty`的值将相同，包含`m.dirty==['cls.*']`。框架无法准确告知是哪个属性触发了监听函数的执行。

对于按钮#3（给`cls`属性赋予新对象），框架会将`cls`传递给脏属性数组，即`m.dirty==['cls.*']`。

```text
点击Button #1, 输出日志：
### onClsChanged, dirty: cls.*

点击Button #2 输出日志：
### onClsChanged, dirty: cls.*

点击Button #3 输出日志：
### onClsChanged, dirty: cls.*
```

### 数组项更改及数组赋值时，监听函数会自动执行

同步监听的观察路径：`@SyncMonitor('arrayOfPerson.*')`

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
          // arrayOfPersonMonitor回调触发
          this.arrayOfPerson.push(new Person('Austin'));
        })
      Button('#2 arrayOfPerson.splice(0,1,P)')
        .onClick(() => {
          // arrayOfPersonMonitor回调触发
          this.arrayOfPerson.splice(0, 1, new Person('Addison'));
        })
      Button('#3 arrayOfPerson.assign new [1]')
        .onClick(() => {
          if (this.arrayOfPerson.length > 1) {
            // arrayOfPersonMonitor回调触发
            this.arrayOfPerson[1] = new Person('Andy');
          }
        })
      Button('#4 arrayOfPerson shift')
        .onClick(() => {
          if (this.arrayOfPerson.length > 2) {
            // arrayOfPersonMonitor回调触发
            this.arrayOfPerson.shift();
          }
        })
      Button('#5 arrayOfPerson length change')
        .onClick(() => {
          // arrayOfPersonMonitor回调触发
          this.arrayOfPerson.length = this.arrayOfPerson.length + 1;
        })
      Button('#6 arrayOfPerson = new Array')
        .onClick(() => {
          // arrayOfPersonMonitor回调触发
          this.arrayOfPerson = new ArrayOfPerson(new Person('Adrian'), new Person('Andrew'))
        })
      Button('#7 arrayOfPerson [1] last name')
        .onClick(() => {
          if (this.arrayOfPerson.length > 1 && this.arrayOfPerson[1] instanceof Person) {
            // arrayOfPersonMonitor回调不触发
            this.arrayOfPerson[1].lastName += '~'
          }
        })
    }
  }
}
```

当按下按钮1-6时，监听函数会被触发:

```text
### SyncMonitor dirty: arrayOfPerson.*
```

按下按钮7，监听函数不会被调用，因为没有数组项被更改。

### 嵌套被观察对象属性更改时，监听函数会执行

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
          // @SyncMonitor回调触发
          this.class0 = new Class0();
        })
      Button('#2 Class0 = new Class, keep Class1')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // 当class0为Class0类型时，@SyncMonitor回调也不触发
            let newClass0 = new Class0();
            newClass0.class1.person = (this.class0 as Class0).class1.person;
            this.class0 = newClass0;
          }
        })
      Button('#3 Class0.class1 = new Class1')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // 当class0为Class0类型时，@SyncMonitor回调触发
            (this.class0 as Class0).class1 = new Class1();
          }
        })
      Button('#4 Class0.class1.person = new Person')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // 当class0为Class0类型时，@SyncMonitor回调触发
            (this.class0 as Class0).class1.person = new Person();
          }
        })
      Button('#5 Class0....person.last update')
        .onClick(() => {
          if (this.class0 instanceof Class0) {
            // 当class0为Class0类型时，@SyncMonitor回调触发
            (this.class0 as Class0).class1.person.lastName += '+';
          }
        })
      Button('#6 Class0 toggle number <=> new Class0')
        .onClick(() => {
          // @SyncMonitor回调触发
          this.class0 = (typeof this.class0 === 'object') ? 500 : new Class0();
        })
    }
  }
}
```

启动应用程序。当按下按钮`#1 Class0 = new Class`时，由于`Person`对象已更改，监听函数将被触发。

```text
### onPersonChange, dirty: class0.class1.person.*
```

启动应用程序。当按下按钮`#2 Class0 = new Class, keep Class1`时，由于被监听的`Person`对象保持不变，监听函数不会执行。

启动应用程序。当按下按钮`#3 Class0.class1 = new Class1`时，由于`Person`对象已更改，监听函数将被触发。

```text
### onPersonChange, dirty: class0.class1.person.*
```

启动应用程序。当按下按钮`#4 Class0.class1.person = new Person`时，由于`Person`对象已更改，监听函数将被触发：
```text
### onPersonChange, dirty: class0.class1.person.*
```

启动应用程序。当按下按钮`#5 Class0....person.last update`时，由于`Person`对象属性已更改，监听函数将被触发：

```text
### onPersonChange, dirty: class0.class1.person.*
```

启动应用程序。当按下按钮`#6 Class0 toggle number <=> new Class0`时，由于路径值从`Person`类引用更改为`undefined`，监听函数将被触发：

```text
### onPersonChange, dirty: class0.class1.person.*
```
第二次按下同一个按钮`#6 Class0 toggle number <=> new Class0`时，框架将再次调用监听函数并通知它对象已从`undefined`更改为`Person`类的实例。

\@Monitor和\@SyncMonitor对路径变为不可用的处理方式存在差异。

\@SyncMonitor在两种情况下都会触发执行 - 当路径变为不可用时和当路径再次变为可用时。

\@Monitor只触发一种情况的执行 - 仅当路径再次变为可用时。当路径上的对象被赋值为undefined时，\@Monitor装饰的回调函数将不会触发执行。

如果在示例应用程序中有`@Monitor('class0.class1.person')`，那么当路径变为不可用时，\@Monitor将无法监听这个变化。当以`this.class0 = 500`的方式更改值时，\@Monitor装饰的回调函数不会被触发。当再次为`Class0`赋值时，即执行`this.class0 = new Class0`，\@Monitor装饰的回调函数将被触发。

### 模糊监听数组项的变化

嵌套的被观察对象的属性更改时，会执行监听函数。

观察数组及数组项更改时，也会执行监听函数。

在以下例子中，有两个\@SyncMonitor监听的路径分别为：`topArray.1.*`和`topArray.*`。

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
      // topArrayMonitor1Star与topArrayMonitorStar回调均触发
      Button('topArray = new TopArray')
        .onClick(() => {
          this.topArray = this.makeNewTopArray();
        })

      // 当topArray[1][0]存在时，topArrayMonitor1Star回调触发，topArrayMonitorStar回调不触发
      Button('topArray[1][0] = new Person')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0) {
            this.topArray[1][0] = new Person();
          }
        })

      // 当topArray[0][1]存在时，topArrayMonitor1Star与topArrayMonitorStar回调均不触发
      Button('topArray[0][1] = new Person')
        .onClick(() => {
          if (this.topArray.length > 0 && this.topArray[0].length > 1) {
            this.topArray[0][1] = new Person();
          }
        })

      // 当topArray[1]存在时，topArrayMonitor1Star回调触发，topArrayMonitorStar回调不触发
      Button('topArray[1].push')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1] instanceof ArrayOfPerson) {
            this.topArray[1].push(new Person());
          }
        })

      // 当topArray的length大于2时，topArrayMonitor1Star与topArrayMonitorStar回调均触发
      Button('topArray.shift (length>2)')
        .onClick(() => {
          if (this.topArray.length > 2) {
            this.topArray.shift();
          }
        })

      // 当topArray[0]存在时，topArrayMonitor1Star回调不触发，topArrayMonitorStar回调触发
      Button('topArray[0] = new ArrayOfPerson')
        .onClick(() => {
          if (this.topArray.length > 0) {
            this.topArray[0] = new ArrayOfPerson(new Person(), new Person());
          }
        })

      // 当topArray[1][0]存在时，topArrayMonitor1Star与topArrayMonitorStar回调均不触发
      Button('topArray[1][0].last update')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0 && this.topArray[1][0] instanceof Person) {
            this.topArray[1][0].lastName += '~';
          }
        })

      // topArrayMonitor1Star回调不触发，topArrayMonitorStar回调触发
      Button('topArray = new TopArray, keep [1]')
        .onClick(() => {
          let newTop = this.makeNewTopArray();
          newTop[1] = this.topArray[1]; // topArray.1未改变，路径'topArray.1.*'中通配符前最后一个确定值未改变
          this.topArray = newTop;
        })

      // topArrayMonitor1Star回调不触发，topArrayMonitorStar回调触发
      Button('topArray.push')
        .onClick(() => {
          this.topArray.push(new ArrayOfPerson(new Person(), new Person()));
        })
    }
  }
}
```

## 限制条件

使用\@SyncMonitor需要注意如下限制条件：

- 不建议在一个类中对同一个属性进行多次\@SyncMonitor的监听。当一个类中存在对一个属性的多次监听时，只有最后一个定义的监听方法会生效。
  
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
            this.info.name = 'Jack'; // 仅会触发onNameChangeDuplicate方法
          })
      }
    }
  }
  ```

- 当@SyncMonitor传入多个路径参数时，以参数的全拼接结果判断是否重复监听。全拼接时会在参数间加空格，以区分不同参数。例如，`'ab', 'c'`的全拼接结果为`'ab c'`，`'a', 'bc'`的全拼接结果为`'a bc'`，二者全拼接不相等。以下示例中，`SyncMonitor 1`、`SyncMonitor 2`与`SyncMonitor 3`都监听了name属性的变化。由于`SyncMonitor 2`与`SyncMonitor 3`的入参全拼接相等（都为`'name position'`），因此`SyncMonitor 2`不生效，仅`SyncMonitor 3`生效。当name属性变化时，将同时触发onNameAgeChange与onNamePositionChangeDuplicate方法。但请注意，`SyncMonitor 2`与`SyncMonitor 3`的写法仍然被视作在一个类中对同一个属性进行多次@SyncMonitor的监听，这是不建议的。

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
  
    // 重复监听name、position，仅最后定义的生效
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
            this.info.name = 'Jack'; // 同时触发onNameAgeChange与onNamePositionChangeDuplicate方法
          })
      }
    }
  }
  ```

- \@SyncMonitor的参数需要为监听属性名的字符串，仅可以使用字符串字面量，不支持const常量、enum枚举值及变量作为参数。如果使用const常量、enum枚举值及变量作为参数，会编译报错，如下提供用例展示@SyncMonitor正常使用场景。

  ```TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const propB: string = 'propB'; // const常量
  
  enum ENUM {
    propC = 'PropC' // enum枚举值
  };
  let propD: string = 'propD'; // 变量
  
  @ObservedV2
  class Info {
    @Trace public propA: number = 0;
    @Trace public propB: number = 0;
    @Trace public propC: number = 0;
    @Trace public propD: number = 0;
  
    // @SyncMonitor仅支持字符串字面量
    @SyncMonitor('propA')
    onPropAChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propA change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    // @SyncMonitor入参类型为const常量，编译会报错，提示`Only constant expressions are supported as parameters in '@SyncMonitor'. Variables are not allowed.`
    @SyncMonitor(propB)
    onPropBChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propB change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
    
    // @SyncMonitor入参类型为enum枚举值，编译会报错，提示`Only constant expressions are supported as parameters in '@SyncMonitor'. Variables are not allowed.`
    @SyncMonitor(ENUM.propC)
    onPropCChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `propC change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
    
    // @SyncMonitor入参类型为变量，编译会报错，提示`Only constant expressions are supported as parameters in '@SyncMonitor'. Variables are not allowed.`
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
            this.info.propA++; // 能够触发onPropAChange方法
          })
      }
    }
  }
  ```

- 建议开发者避免在\@SyncMonitor中再次更改被监听的属性，这会导致无限循环。

  ```ts
  @ObservedV2
  class Info {
    @Trace count: number = 0;
    @SyncMonitor('count')
    onCountChange(monitor: IMonitor) {
      this.count++; // 应避免这种写法，会导致无限循环
    }
  }
  ```

## 使用场景

### 监听深层属性变化

\@SyncMonitor可以监听深层属性的变化，并能够根据更改前后的值做分类处理。

下面的示例中监听了属性value的变化，并根据变化的幅度改变Text组件显示的样式。

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

## 常见问题

### 自定义组件中\@SyncMonitor对变量监听的生效及失效时间

当\@SyncMonitor定义在\@ComponentV2装饰的自定义组件中时，\@SyncMonitor会在状态变量初始化完成之后生效，并在组件销毁时失效。

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

在上面的例子中，可以通过创建和销毁Child组件来观察定义在自定义组件中的\@SyncMonitor的生效和失效时机。推荐按如下顺序进行操作：

- 当Index组件创建Info类实例时，日志输出`in constructor message change to initialized`。此时Index组件的\@SyncMonitor还未初始化成功，因此不会监听到message的变化。
- 当Index组件创建完成，页面加载完成后，点击按钮'change message in Index'，此时Index组件中的\@SyncMonitor能够监听到变化，日志输出`Index message change from initialized to Index click to change Message`。
- 点击按钮'show/hide Child'，创建Child组件，在Child组件初始化\@Param装饰的变量以及\@SyncMonitor之后，调用Child组件的aboutToAppear回调，改变message。此时Index组件与Child组件的\@SyncMonitor均能监听到变化，日志输出`Index message change from Index click to change Message to Child aboutToAppear`以及`Child message change from Index click to change Message to Child aboutToAppear`。
- 点击按钮'change message in Child'，改变message。此时Index组件与Child组件的\@SyncMonitor均能监听到变化，日志输出`Index message change from Child aboutToAppear to Child click to change Message`以及`Child message change from Child aboutToAppear to Child click to change Message`。
- 点击按钮'show/hide Child'，销毁Child组件，调用Child组件的aboutToDisappear回调，改变message。此时Index组件与Child组件的\@SyncMonitor均能监听到变化，日志输出`Child aboutToDisappear`，`Index message change from Child click to change Message to Child aboutToDisappear`以及`Child message change from Child click to change Message to Child aboutToDisappear`。
- 点击按钮'change message in Index'，改变message。此时Child组件已销毁，其注册的\@SyncMonitor监听也被解注册，仅有Index组件的\@SyncMonitor能够监听到变化，日志输出`Index message change from Child aboutToDisappear to Index click to change Message`。

这表明Child组件中定义的\@SyncMonitor监听随着Child组件的创建初始化生效，随着Child组件的销毁失效。

### 类中\@SyncMonitor对变量监听的生效及失效时间

当\@SyncMonitor定义在\@ObservedV2装饰的类中时，\@SyncMonitor会在类的实例创建完成后生效，在类的实例销毁时失效。

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

上面的例子中，\@SyncMonitor会在info创建完成后生效，这个时机晚于类的constructor，早于自定义组件的aboutToAppear。当界面加载完成后，点击'change message'，修改message变量。此时日志输出信息如下：

```ts
message change from initialized to Index aboutToAppear
message change from Index aboutToAppear to Index click to change message
```

类中定义的\@SyncMonitor随着类的销毁失效。而由于类的实际销毁释放依赖于垃圾回收机制，因此会出现即使所在自定义组件已经销毁，类却还未及时销毁，导致类中定义的\@SyncMonitor仍在监听变化的情况。

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

在上面的例子中，当点击'change showFlag'切换if组件的条件时，Child组件会被销毁。此时，点击'change number'修改age的值时，可以通过日志观察到InfoWrapper中定义的\@SyncMonitor回调仍然被触发了。这是因为此时自定义组件Child虽然执行了aboutToDisappear，但是其成员变量infoWrapper还没有被立刻回收，当变量发生变化时，依然能够调用到infoWrapper中定义的onInfoAgeChange方法，所以从现象上看\@SyncMonitor回调仍会被触发。

借助垃圾回收机制去取消\@SyncMonitor的监听是不稳定的，开发者可以采用以下方式去管理\@SyncMonitor的失效时间：

将\@SyncMonitor定义在自定义组件中。由于自定义组件在销毁时，状态管理框架会手动取消\@SyncMonitor的监听，因此在自定义组件调用完aboutToDisappear，尽管自定义组件的数据不一定已经被释放，但\@SyncMonitor回调已不会再被触发。与@Monitor不同的是，当自定义组件即将销毁时，主动置空\@SyncMonitor监听的对象，\@SyncMonitor依然能监听原监听目标的变化。

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

### 正确设置\@SyncMonitor入参

由于\@SyncMonitor无法对入参做编译时校验，当前存在以下写法不符合\@SyncMonitor监听条件但\@SyncMonitor仍会触发的情况。开发者应当正确传入\@SyncMonitor入参，不传入非状态变量，避免造成功能异常或行为表现不符合预期。

【反例1】

<!-- @[monitor_non_state_variable_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorNonStateVariableNegative.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 只允许监听状态变量age。监听非状态变量name，会编译告警，
  // 提示：`Cannot observe non-existent variables or non-state variables, except in wildcard-based monitoring scenarios.`
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
          this.info.age = 25; // 同时改变状态变量age和非状态变量name
          this.info.name = 'Johny';
        })
    }
  }
}
```

上面的代码中，由于\@SyncMonitor入参传入非状态变量'name'，编译会告警。建议开发者去除对name属性的监听或者给name加上\@Trace装饰成为状态变量。

当点击按钮同时更改状态变量age和非状态变量name时，会输出以下日志：
```text
property path:age change from 24 to 25
```

【正例1】

<!-- @[monitor_non_state_variable_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorNonStateVariablePositive.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 仅监听状态变量age
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
          this.info.age = 25; // 状态变量age改变
          this.info.name = 'Johny';
        })
    }
  }
}
```

【反例2】

<!-- @[monitor_non_computed_getter_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorNonComputedGetterNegative.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  public age: number = 24;

  get myAge() {
    return this.age; // age为非状态变量
  }

  // 监听非@Computed装饰的getter访问器，编译会告警
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
          this.info.age = 25; // 状态变量age改变
        })
    }
  }
}
```

上面的代码中，\@SyncMonitor的入参为一个getter访问器的名字，但该getter访问器本身并未被\@Computed装饰，不是一个可被监听的变量。建议开发者给myAge添加\@Computed装饰器或当getter访问器直接返回状态变量时，不监听getter访问器而是直接监听状态变量本身。

【正例2】

将myAge变为状态变量：

<!-- @[monitor_computed_variable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorComputedVariable.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 给myAge添加@Computed成为状态变量
  @Computed
  get myAge() {
    return this.age;
  }

  // 监听@Computed装饰的getter访问器
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
          this.info.age = 25; // 状态变量age改变
        })
    }
  }
}
```

或直接监听状态变量本身：

<!-- @[monitor_state_variable_directly](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/SyncMonitor/entry/src/main/ets/pages/MonitorStateVariableDirectly.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 监听状态变量age
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
          this.info.age = 25; // 状态变量age改变
        })
    }
  }
}
```

### 使用通配符的无效路径

有效的监听路径规则如下：

* 路径只能以`*`结尾；

* `*`不能出现在路径开头或路径内部；

以下路径均使用了无效的通配符。编译会报错。

* `@SyncMonitor('*.propA')` - 错误，通配符不能位于路径开头

* `@SyncMonitor('arr.*.propA')` - 错误，通配符不能位于路径中间

* `@SyncMonitor('obsArr.*.*')` - 错误，不允许使用双重通配符。任何属性或数组项都只支持一级

* `@SyncMonitor('obsArr.**')` - 错误，属性或数组项名称无效`**`

* `@SyncMonitor('obsObj*')` - 错误，属性名称`obsObj*`无效

* `@SyncMonitor('obsObj.objObj2*')` - 错误，属性名称`obsObj2*`无效

* `@SyncMonitor('*')` - 错误，不存在属性名称

### 监听变量从可访问变为不可访问和从不可访问变为可访问

\@Monitor仅会保存变量可访问时的值，当状态变量变为不可访问的状态时，并不会记录其值的变化。从API version 20开始，可以使用addMonitor[监听变量从可访问到不可访问和从不可访问到可访问](./arkts-new-addMonitor-clearMonitor.md#监听变量从可访问到不可访问和从不可访问到可访问)的状态变化。

\@SyncMonitor可以监听变量从可访问变为不可访问或从不可访问变为可访问的变化。在下面的例子中，点击三个Button，均会触发`onChange`的回调。

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
        // age：可访问 -> 不可访问
        this.user = undefined;
      })
      Button('set user to User').onClick(() => {
        // age：不可访问 ->可访问
        this.user = new User();
      })
      Button('set user to null').onClick(() => {
        // age：可访问->不可访问
        this.user = null;
      })
    }
  }
}
```