# \@Monitor装饰器：状态变量修改异步监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了增强状态管理框架对状态变量变化的监听能力，开发者可以使用[\@Monitor](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md#monitor)装饰器对状态变量进行监听。


\@Monitor提供了对V2状态变量的监听。在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-create-custom-components.md#componentv2)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，[\@Local](./arkts-new-local.md)。

>**说明：**
>
>\@Monitor装饰器从API version 12开始支持。
>
>从API version 12开始，该装饰器支持在原子化服务中使用。
>
>从API version 23开始，该装饰器支持在ArkTS卡片中使用。
>
>从API版本26.0.0开始，该装饰器新增支持通配符能力。

## 概述

\@Monitor装饰器用于监听状态变量修改，使得状态变量具有深度监听的能力：

- \@Monitor装饰器支持在\@ComponentV2装饰的自定义组件中使用，未被状态变量装饰器[\@Local](arkts-new-local.md)、[\@Param](arkts-new-param.md)、[\@Provider](arkts-new-provider-and-consumer.md)、[\@Consumer](arkts-new-provider-and-consumer.md)、[\@Computed](arkts-new-computed.md)装饰的变量无法被\@Monitor监听到变化。

- \@Monitor装饰器支持在类中与[\@ObservedV2、\@Trace](arkts-new-observedV2-and-trace.md)配合使用，不允许在未被\@ObservedV2装饰的类中使用\@Monitor装饰器。未被\@Trace装饰的属性无法被\@Monitor监听到变化。
- 当观测的属性变化时，\@Monitor装饰器定义的回调方法将被调用。判断属性是否变化使用的是严格相等（===），当严格相等判断的结果是false（即不相等）的情况下，就会触发\@Monitor的回调。当在一次事件中多次改变同一个属性时，将会使用初始值和最终值进行比较以判断是否变化。
- 单个\@Monitor装饰器能够同时监听多个属性的变化，当这些属性在一次事件中共同变化时，只会触发一次\@Monitor的回调方法。
- \@Monitor装饰器具有深度监听的能力，能够监听嵌套类、多维数组、对象数组中指定项的变化。对于嵌套类、对象数组中成员属性变化的监听要求该类被\@ObservedV2装饰且该属性被\@Trace装饰。
- 当\@Monitor监听整个数组时，更改数组的某一项不会被监听到。无法监听内置类型（Array、Map、Date、Set）的API调用引起的变化。
- 在继承类场景中，可以在父子组件中对同一个属性分别定义\@Monitor进行监听，当属性变化时，父子组件中定义的\@Monitor回调均会被调用。
- 和[\@Watch装饰器](arkts-watch.md)类似，开发者需要自己定义回调函数，区别在于\@Watch装饰器将函数名作为参数，而\@Monitor直接装饰回调函数。\@Monitor与\@Watch的对比可以查看[\@Monitor与\@Watch的对比](#monitor与watch对比)。

从API版本26.0.0开始，支持配置[MonitorDecoratorOptions](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md#monitordecoratoroptions)来获得以下能力增强：

- 支持在监听路径中设置通配符“*”，用于模糊监听对象内部变化，包括@ObservedV2中任意@Trace属性变化，内置类型（Array、Map、Date、Set）的API调用引起的变化等。详情见[监听包含通配符的路径](#监听包含通配符的路径)。
- 对@Monitor部分能力进行修正，详情见[@Monitor使用配置项前后的对比](#monitor使用配置项前后的对比)。

## 状态管理V1版本\@Watch装饰器的局限性

现有状态管理V1版本无法实现对对象、数组中某一单个属性或数组项变化的监听，且无法获取变化之前的值。
<!-- @[monitor_watch_decorator_limitations_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/WatchDecoratorLimitationsV1.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@Observed
class Info {
  public name: string = 'Tom';
  public age: number = 25;
}

@Entry
@Component
struct Index {
  @State @Watch('onInfoChange') info: Info = new Info();
  @State @Watch('onNumArrChange') numArr: number[] = [1, 2, 3, 4, 5];

  onInfoChange() {
    hilog.info(0xFF00, 'testTag', '%{public}s', `info after change name: ${this.info.name}, age: ${this.info.age} `);
  }

  onNumArrChange() {
    hilog.info(0xFF00, 'testTag', '%{public}s', `numArr after change ${this.numArr}`);
  }

  build() {
    Row() {
      Column() {
        // 对象、数组中某一单个属性或数组项变化，不会触发UI刷新
        Button('change info name')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.name = 'Jack';
          })
        Button('change info age')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.age = 30;
          })
        Button('change numArr[2]')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.numArr[2] = 5;
          })
        Button('change numArr[3]')
          .width(300)
          .margin(10)
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

![monitor-sync-0](./figures/monitor-sync-0.png)

上述代码中，点击"change info name"更改info中的name属性或点击"change info age"更改age时，均会触发info注册的\@Watch回调。点击"change numArr[2]"更改numArr中的第3个元素或点击"change numArr[3]"更改第4个元素时，均会触发numArr注册的\@Watch回调。在这两个回调中，由于无法获取数据更改前的值，在业务逻辑更加复杂的场景下，无法准确知道是哪一个属性或元素发生了改变从而触发了\@Watch事件，这不便于开发者对变量的更改进行准确监听。因此推出\@Monitor装饰器实现对对象、数组中某一单个属性或数组项变化的监听，并且能够获取到变化之前的值。

## 装饰器说明

| \@Monitor属性装饰器 | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数          | API版本26.0.0之前，参数为字符串类型的对象属性名。<br>从API版本26.0.0开始，第一个参数也可以为[MonitorDecoratorOptions](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md#monitordecoratoroptions)配置项。<br>可同时监听多个对象属性，每个属性以逗号隔开，例如@Monitor('prop1', 'prop2')。可监听深层的属性变化，如多维数组中的某一个元素，嵌套对象或对象数组中的某一个属性。详见[监听变化](#监听变化)。 |
| 装饰对象            | \@Monitor装饰成员方法。当监听的属性发生变化时，会触发该回调方法。该回调方法以[IMonitor类型](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md#imonitor)的变量作为参数，开发者可以从该参数中获取变化前后的相关信息。 |

### 语法

>**说明：**
>
>为简化说明，下文将传入MonitorDecoratorOptions的@Monitor调用称为**使用配置项的@Monitor**。将未传入MonitorDecoratorOptions的@Monitor调用称为**未使用配置项的@Monitor**。

未使用配置项的@Monitor语法：

```typescript
@Monitor('path')
onValueChange(monitor: IMonitor) {
}
```

使用配置项的@Monitor语法：

``` ts
@Monitor({ enableWildcard: false }, 'path') // 使用配置项，显式配置不使能通配符
onValueChanged1(monitor: IMonitor) {
}
@Monitor({}, 'path.*') // 使用配置项，默认使能通配符，监听path对象内任意可观察变化
onValueChange2(monitor: IMonitor) {
}
@Monitor({ enableWildcard: true }, 'path.*') // 使用配置项，显式配置使能通配符
onValueChange3(monitor: IMonitor) {
}
```

### @Monitor使用配置项前后的对比

| 场景             | 未使用配置项的@Monitor                                       | 使用配置项的@Monitor                                         |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 使用通配符       | 不支持。                                                     | 支持。                                                       |
| 监听不可监听变量 | 存在被连带触发监听的可能，详情见[正确设置@Monitor入参](#正确设置monitor入参)。 | 忽略不可监听变量，对路径的监听变为互相独立的监听。           |
| 变量可访问性变化 | 仅记录变量可访问时的状态，无法正常处理变量变为不可访问的情况。 | 变量从可访问变为不可访问，或从不可访问变为可访问，均能正常处理。 |

使用配置项的@Monitor在以上场景的表现，将与[@SyncMonitor](arkts-new-syncmonitor.md)、[addMonitor](./arkts-new-addMonitor-clearMonitor.md)保持一致。

## 接口说明

IMonitor类型、IMonitorValue\<T\>类型以及MonitorDecoratorOptions的接口说明参考API文档：[@Monitor：状态变量修改监听](../../reference/apis-arkui/arkui-ts/ts-state-management-monitor.md)。

## 监听变化

### 在\@ComponentV2装饰的自定义组件中使用\@Monitor

使用\@Monitor监听的状态变量发生变化时，会触发\@Monitor的回调方法。

- \@Monitor监听的变量需要被\@Local、\@Param、\@Provider、\@Consumer、\@Computed装饰，未被状态变量装饰器装饰的变量在变化时无法被监听。\@Monitor可以同时监听多个状态变量，这些变量名之间用","隔开。

  <!-- @[monitor_decorator_multi_watch_comp_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorMultiWatchCompV2.ets) -->  
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @Entry
  @ComponentV2
  struct Index {
    @Local message: string = 'Hello World';
    @Local name: string = 'Tom';
    @Local age: number = 24;
  
    @Monitor('message', 'name')
    onStrChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
    }
  
    build() {
      Column() {
        // 点击Button更新message和name，触发onStrChange回调
        Button('change string')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.message += '!';
            this.name = 'Jack';
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-1](./figures/monitor-sync-1.png)

- \@Monitor监听的状态变量为类对象时，仅能监听对象整体的变化。监听类属性的变化需要类属性被\@Trace装饰。

  <!-- @[monitor_decorator_object_trace_comp_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorObjectTraceCompV2.ets) --> 
  
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
  
    @Monitor('info')
    infoChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `info change`);
    }
  
    @Monitor('info.name')
    infoPropertyChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `info name change`);
    }
  
    build() {
      Column() {
        Text(`name: ${this.info.name}, age: ${this.info.age}`)
          .fontSize(20)
          .margin(10)
        Button('change info')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info = new Info('Lucy', 18); // 能够监听到
          })
        Button('change info.name')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.name = 'Jack'; // 监听不到
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-2](./figures/monitor-sync-2.gif)

### 在\@ObservedV2装饰的类中使用\@Monitor

使用\@Monitor监听的属性发生变化时，会触发\@Monitor的回调方法。

- \@Monitor监听的对象属性需要被\@Trace装饰，未被\@Trace装饰的属性的变化无法被监听。\@Monitor可以同时监听多个属性，这些属性之间用","隔开。
  <!-- @[monitor_decorator_multi_watch_observed_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorMultiWatchObservedV2.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public name: string = 'Tom';
    @Trace public region: string = 'North';
    @Trace public job: string = 'Teacher';
    public age: number = 25;
  
    // name被@Trace装饰，能够监听变化
    @Monitor('name')
    onNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    // age未被@Trace装饰，不能监听变化
    @Monitor('age')
    onAgeChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    // region与job均被@Trace装饰，能够监听变化
    @Monitor('region', 'job')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.name = 'Jack'; // 能够触发onNameChange方法
          })
        Button('change age')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.age = 26; // 不能够触发onAgeChange方法
          })
        Button('change region')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.region = 'South'; // 能够触发onChange方法
          })
        Button('change job')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.job = 'Driver'; // 能够触发onChange方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-3](./figures/monitor-sync-3.png)

- \@Monitor可以监听深层属性的变化，该深层属性需要被@Trace装饰。
  <!-- @[monitor_decorator_object_trace_observed_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorObjectTraceObservedV2.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Inner {
    @Trace public num: number = 0;
  }
  
  @ObservedV2
  class Outer {
    public inner: Inner = new Inner();
  
    @Monitor('inner.num')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            this.outer.inner.num = 100; // 能够触发onChange方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-4](./figures/monitor-sync-4.png)

- 在继承类场景下，可以在继承链中对同一个属性进行多次监听。
  <!-- @[monitor_decorator_inheritance_support_observed_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorInheritanceSupportObservedV2.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Base {
    @Trace public name: string;
  
    // 基类监听name属性
    @Monitor('name')
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
    @Monitor('name')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            this.derived.name = 'BBB'; // 能够先后触发onBaseNameChange、onDerivedNameChange方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-5](./figures/monitor-sync-5.png)

### 通用监听能力

\@Monitor还有一些通用的监听能力。

- \@Monitor支持对数组中的项进行监听，包括多维数组，对象数组。\@Monitor无法监听内置类型（Array、Map、Date、Set）的API调用引起的变化。当\@Monitor监听数组整体时，只能观测到数组整体的赋值。可以通过监听数组的长度变化来判断数组是否有插入、删除等变化。当前仅支持使用"."的方式表达深层属性、数组项的监听。
  <!-- @[monitor_decorator_array_support](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorArraySupport.ets) --> 
  
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
    @Monitor('dimensionTwo.0.0', 'dimensionTwo.1.1')
    onDimensionTwoChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `dimensionTwo path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // dimensionThree为三维简单类型数组，且被@Trace装饰，能够观测里面的元素变化
    @Monitor('dimensionThree.0.0.0', 'dimensionThree.1.1.0')
    onDimensionThreeChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `dimensionThree path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // Info类中属性name、age均被@Trace装饰，能够监听到变化
    @Monitor('infoArr.0.name', 'infoArr.1.age')
    onInfoArrPropertyChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `infoArr path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      })
    }
  
    // infoArr被@Trace装饰，能够监听到infoArr整体赋值的变化
    @Monitor('infoArr')
    onInfoArrChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `infoArr whole change`);
    }
  
    // 能够监听到infoArr的长度变化
    @Monitor('infoArr.length')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            // 能够触发onDimensionTwoChange方法
            this.arrMonitor.dimensionTwo[0][0]++;
            this.arrMonitor.dimensionTwo[1][1]++;
          })
        Button('Change dimensionThree')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 能够触发onDimensionThreeChange方法
            this.arrMonitor.dimensionThree[0][0][0]++;
            this.arrMonitor.dimensionThree[1][1][0]++;
          })
        Button('Change info property')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 能够触发onInfoArrPropertyChange方法
            this.arrMonitor.infoArr[0].name = 'Tom';
            this.arrMonitor.infoArr[1].age = 19;
          })
        Button('Change whole infoArr')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 能够触发onInfoArrChange、onInfoArrPropertyChange、onInfoArrLengthChange方法
            this.arrMonitor.infoArr = [new Info('Cindy', 8)];
          })
        Button('Push new info to infoArr')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 能够触发onInfoArrPropertyChange、onInfoArrLengthChange方法
            this.arrMonitor.infoArr.push(new Info('David', 50));
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-6](./figures/monitor-sync-6.png)

- 对象整体改变，但监听的属性不变时，不触发\@Monitor回调。

  下面的示例按照Step1-Step2-Step3的顺序点击，表现为代码注释中的行为。

  如果只点击Step2或Step3，改变name、age的值，此时会触发onNameChange和onAgeChange方法。
  <!-- @[monitor_decorator_object_support](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorObjectSupport.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public person: Person;
  
    @Monitor('person.name')
    onNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    @Monitor('person.age')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.person = new Person('Jack', 25); // 能够触发onNameChange方法，不触发onAgeChange方法
          })
        Button('Step2: Only change age')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.person = new Person('Jack', 18); // 能够触发onAgeChange方法，不触发onNameChange方法
          })
        Button('Step3: Change name and age')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.person = new Person('Lucy', 19); // 能够触发onNameChange、onAgeChange方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-7](./figures/monitor-sync-7.png)

- 在一次事件中多次改变被\@Monitor监听的属性，以最后一次修改为准。
  <!-- @[monitor_decorator_last_write](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorDecoratorLastWrite.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Frequency {
    @Trace public count: number = 0;
  
    @Monitor('count')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            for (let i = 1; i <= 1000; i++) {
              this.frequency.count = i;
            }
          })
        Button('change count to 0 then to 1000')
          .width(300)
          .margin(10)
          .onClick(() => {
            for (let i = 999; i >= 0; i--) {
              this.frequency.count = i;
            }
            this.frequency.count = 1000; // 最终不触发onCountChange方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-8](./figures/monitor-sync-8.png)

在点击按钮"change count to 1000"后，会触发一次onCountChange方法，并输出日志"count change from 0 to 1000"。在点击按钮"change count to 0 then to 1000"后，由于事件前后属性count的值并没有改变，都为1000，所以不触发onCountChange方法。

## 监听包含通配符的路径

从API版本26.0.0开始，@Monitor支持通配符能力。当使用配置项MonitorDecoratorOptions时，将默认开启通配符支持。通配符可以作为路径中的后缀，监听该路径最后确定值中的变化。该变化包括如@Trace属性的变化、内置类型（Array、Map、Set、Date）的API调用引起的变化等。

通配符路径的语法规则为：

- 通配符只能出现在路径末尾。
- 通配符不能出现在路径开头，也不能出现在路径中间。
- 一个路径中最多仅可以出现一个通配符。

合法的通配符路径示例为：

| 路径       | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| obj.*      | obj为@ObservedV2装饰的对象。监听该路径的@Monitor将在以下情况触发：<br>1、对obj整体赋值。<br>2、obj任意@Trace属性变化。 |
| arr.*      | arr为可观察数组。监听该路径的@Monitor将在以下情况触发：<br/>1、对arr整体赋值。<br>2、arr任意元素变化或数组长度变化。<br>3、调用数组的API（如push、pop、sort、fill、copyWithin等）。 |
| obj.objA.* | objA为@ObservedV2装饰的嵌套对象。监听该路径的@Monitor将在以下情况触发：<br>1、对obj整体赋值且objA变化。<br>2、对objA整体赋值。<br>3、objA任意@Trace属性变化。 |
| arr.1.*    | arr为嵌套可观察数组。监听该路径的@Monitor将在以下情况触发：<br/>1、对arr整体赋值且下标为1的数组发生变化。<br>2、arr下标为1的数组任意元素变化或数组长度变化。<br>3、调用arr下标为1的数组的API。 |

当修改嵌套对象中任意对象时，监听包含该对象的通配符路径遵循最终确定值原则，即通配符前的最后一个确定值变化时，才会触发监听回调。例如，监听上表的路径“obj.objA.*”时，”objA“为通配符前的最后一个确定值，对”obj“整体赋值，若”objA“赋值前后引用同一个对象，则不会触发回调。

此外，使用通配符时，IMonitor的dirty数组能正常包含通配符路径，但其对应的IMonitorValue的before值与now值都将为undefined。

### 使用通配符监听对象属性变化

当使用通配符监听对象时，对象的任意@Trace装饰的属性变化，或者对象本身被整体赋新值时，触发@Monitor回调。

<!-- @[monitor_wildcard_support_object_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorWildcardSupportObjectProperty.ets) --> 

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
struct MonitorWildcardObject {
  @Local cls: ClassA = new ClassA(100, 100);

  // 使能通配符
  @Monitor({}, 'cls.*')
  onClsChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onClsChanged, dirty: ${m.dirty.toString()}`);
  }

  build() {
    Column() {
      Button(`Change propA: ${this.cls.propA}`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.cls.propA += 1; // 触发onClsChanged
        })
      Button(`Change propB: ${this.cls.propB}`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.cls.propB += 1; // 触发onClsChanged
        })
      Button('Assign new object')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.cls = new ClassA(-200, -200); // 触发onClsChanged
        })
    }
    .width('100%')
  }
}
```

  ![monitor-sync-9](./figures/monitor-sync-9.gif)

### 使用通配符监听嵌套对象属性变化

观察嵌套对象属性变化的示例如下。

<!-- @[monitor_wildcard_support_nested_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorWildcardSupportNestedObject.ets) --> 

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
struct MonitorWildcardNestedObject {
  @Local class0: Class0 | number = new Class0();

  // 使能通配符，监听嵌套对象
  @Monitor({}, 'class0.class1.person.*')
  onPersonChange(info: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'onPersonChange, dirty: ' + info.dirty.toString());
  }

  build() {
    Column({ space: 5 }) {
      Button('1. Class0 = new Class')
        .width(300)
        .margin(10)
        .onClick(() => {
          // @Monitor回调触发
          // 原因：class0, class1, person变更为新对象
          this.class0 = new Class0();
        })
      Button('2. Class0 = new Class, keep Class1')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 当class0为Class0类型时，@Monitor回调不触发
          // 原因：即使class0变化了，路径'class0.class1.person.*'中通配符前最后一个确定值person也没有改变
          if (this.class0 instanceof Class0) {
            let newClass0 = new Class0();
            newClass0.class1.person = (this.class0 as Class0).class1.person;
            this.class0 = newClass0;
          }
        })
      Button('3. Class0.class1 = new Class1')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 当class0为Class0类型时，@Monitor回调触发
          // 原因：class1、person变更为新对象
          if (this.class0 instanceof Class0) {
            (this.class0 as Class0).class1 = new Class1();
          }
        })
      Button('4. Class0.class1.person = new Person')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 当class0为Class0类型时，@Monitor回调触发
          // 原因：person变更为新对象
          if (this.class0 instanceof Class0) {
            (this.class0 as Class0).class1.person = new Person();
          }
        })
      Button('5. Class0....person.last update')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 当class0为Class0类型时，@Monitor回调触发
          // 原因：person的属性发生变化
          if (this.class0 instanceof Class0) {
            (this.class0 as Class0).class1.person.lastName += '+';
          }
        })
      Button('6. Class0 toggle number <=> new Class0')
        .width(300)
        .margin(10)
        .onClick(() => {
          // @Monitor回调触发
          // 原因：person在可访问与不可访问之间切换
          this.class0 = (typeof this.class0 === 'object') ? 500 : new Class0();
        })
    }
  }
}
```

![monitor-sync-10](./figures/monitor-sync-10.png)

当使用配置项的@Monitor监听的变量在可访问和不可访问之间切换时，都会触发@Monitor回调。

### 使用通配符监听数组对象的变化

使用配置项的@Monitor可以监听到数组的API调用。任意数组的方法被调用时，@Monitor回调都会被执行，即使数组为空或并未实际修改数组的内容。API包括`push`、`pop`、`shift`、`splice`、`unshift`、`copyWithin`、`fill`、`reverse`、`sort`。

<!-- @[monitor_wildcard_support_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorWildcardSupportArray.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Person {
  @Trace public firstName: string = 'first';
  @Trace public lastName: string = 'last';

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
struct MonitorWildcardArray {
  @Local topArray: TopArray = this.makeNewTopArray();

  // 使能通配符
  @Monitor({}, 'topArray.1.*')
  topArrayMonitor1Star(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray[1]: ${monitor.dirty.toString()}`);
  }

  // 使能通配符
  @Monitor({}, 'topArray.*')
  topArrayMonitorStar(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray: ${monitor.dirty.toString()}`);
  }

  makeNewTopArray(): TopArray {
    // 初始化数组
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
        .width(300)
        .margin(10)
        .onClick(() => {
          this.topArray = this.makeNewTopArray();
        })

      // 当topArray[1][0]存在时，topArrayMonitor1Star回调触发，topArrayMonitorStar回调不触发
      Button('topArray[1][0] = new Person')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0) {
            this.topArray[1][0] = new Person();
          }
        })

      // 当topArray[0][1]存在时，topArrayMonitor1Star与topArrayMonitorStar回调均不触发
      Button('topArray[0][1] = new Person')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.topArray.length > 0 && this.topArray[0].length > 1) {
            this.topArray[0][1] = new Person();
          }
        })

      // 当topArray[1]存在时，topArrayMonitor1Star回调触发，topArrayMonitorStar回调不触发
      Button('topArray[1].push')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1] instanceof ArrayOfPerson) {
            this.topArray[1].push(new Person());
          }
        })

      // 当topArray的length大于2时，topArrayMonitor1Star与topArrayMonitorStar回调均触发
      Button('topArray.shift (length>2)')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.topArray.length > 2) {
            this.topArray.shift();
          }
        })

      // 当topArray[0]存在时，topArrayMonitor1Star回调不触发，topArrayMonitorStar回调触发
      Button('topArray[0] = new ArrayOfPerson')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.topArray.length > 0) {
            this.topArray[0] = new ArrayOfPerson(new Person(), new Person());
          }
        })

      // 当topArray[1][0]存在时，topArrayMonitor1Star与topArrayMonitorStar回调均不触发
      Button('topArray[1][0].last update')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0 && this.topArray[1][0] instanceof Person) {
            this.topArray[1][0].lastName += '~';
          }
        })

      // topArrayMonitor1Star回调不触发，topArrayMonitorStar回调触发
      Button('topArray = new TopArray, keep [1]')
        .width(300)
        .margin(10)
        .onClick(() => {
          let newTop = this.makeNewTopArray();
          newTop[1] = this.topArray[1]; // topArray.1未改变，路径'topArray.1.*'中通配符前最后一个确定值未改变
          this.topArray = newTop;
        })

      // topArrayMonitor1Star回调不触发，topArrayMonitorStar回调触发
      Button('topArray.push')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.topArray.push(new ArrayOfPerson(new Person(), new Person()));
        })
    }
    .width('100%')
  }
}
```

![monitor-sync-11](./figures/monitor-sync-11.png)

### 使用通配符监听Date对象的变化

使用通配符可以监听Date对象的API调用。

```ts
@Monitor({}, 'dateInstance.*')
onDateChange(m: IMonitor) {
}
```

@Monitor会在以下情况回调：

- `dateInstance`被赋新值。
- 调用Date的任意API，包括`setFullYear`、`setMonth`、`setDate`、`setHours`、`setMinutes`、`setSeconds`、`setMilliseconds`、`setTime`、`setUTCFullYear`、`setUTCMonth`、`setUTCDate`、`setUTCHours`、`setUTCMinutes`、`setUTCSeconds`、`setUTCMilliseconds`。即使这些API未实际对Date的值产生更改，@Monitor回调也会触发。

使用通配符监听Date对象的示例如下。

<!-- @[monitor_wildcard_support_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorWildcardSupportDate.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2
struct MonitorWildcardDate {
  @Local date: Date = new Date();

  // 使能通配符
  @Monitor({}, 'date.*')
  onDateChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onDateChanged, dirty: ${m.dirty.toString()}`);
  }

  build() {
    Column({ space: 5 }) {
      // API调用触发onDateChanged
      Button(`date.setMilliseconds(1000)`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.date.setMilliseconds(1000);
        })
      // API调用触发onDateChanged
      Button(`date.setTime(1000)`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.date.setTime(1000000);
        })
      // API调用触发onDateChanged
      Button(`Assign new Date`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.date = new Date();
        })
      // 整体赋相同值，不触发onDateChanged
      Button(`Re-assign the same Date`)
        .width(300)
        .margin(10)
        .onClick(() => {
          let sameDate = this.date;
          this.date = sameDate;
        })
    }
  }
}
```

![monitor-sync-12](./figures/monitor-sync-12.png)

### 使用通配符监听Map对象的变化

使用通配符可以监听Map对象的API调用。

```ts
@Monitor({}, 'mapInstance.*')
onMapChange(m: IMonitor) {
}
```

@Monitor会在以下情况回调：

- `mapInstance`被赋新值。
- 调用Map的API，例如`set`、`delete`、`clear`时触发。与Array、Date不同的是，只有当变化真的发生时，回调才会触发。这意味着，当对空Map调用`clear`，对不存在的Map键值调用`delete`，以及不实际改变值的`set`调用都不会触发@Monitor回调。

与Array不同，@Monitor无法对Map的某一个key做监听。

使用通配符监听Map对象的示例如下。

<!-- @[monitor_wildcard_support_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorWildcardSupportMap.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2
struct MonitorWildcardMap {
  @Local map: Map<string, string> = new Map<string, string>();
  cnt: number = 0;

  @Monitor({ enableWildcard: false }, 'map.size')
  onMapSizeChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onMapSizeChanged, size dirty: ${m.dirty.toString()}`);
  }

  // 使能通配符
  @Monitor({}, 'map.*')
  onMapChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onMapChanged, dirty: ${m.dirty.toString()}`);
  }

  build() {
    Column({ space: 5 }) {
      Text(`map.size: ${this.map.size}`)
        .fontSize(20)
        .margin(10)
      Text(`map.get('one'): ${this.map.get('one')}`)
        .fontSize(20)
        .margin(10)
      // 在首次点击时，onMapSizeChanged、onMapChanged回调都触发
      Button(`Init, map.set('one', 'A'), map.set('two', 'B')`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.map.set('one', 'A');
          this.map.set('two', 'B');
        })
      // onMapSizeChanged、onMapChanged回调都触发
      Button(`Add new, map.set('three' + this.cnt, 'C')`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.cnt++;
          this.map.set('three' + this.cnt, 'C')
        })
      // 当'one'不存在时，onMapSizeChanged、onMapChanged回调都不触发
      // 当'one'存在时，onMapSizeChanged、onMapChanged回调都触发
      Button(`Delete from map: map.delete('one')`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.map.delete('one')
        })
      // 当map不为空时，onMapSizeChanged、onMapChanged回调都触发
      // 当map为空时，onMapSizeChanged、onMapChanged回调都不触发
      Button(`Clear map`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.map.clear();
        })
      // 在首次点击且假设存在（'one' -> 'A'）时，仅onMapChanged回调触发
      // 若已经设置过（'one' -> 'TWO'），则onMapSizeChanged、onMapChanged回调都不触发
      Button(`Update one to 'TWO' - map.set('one', 'TWO')`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.map.set('one', 'TWO');
        })
      // 当Map不存在'one'时，onMapSizeChanged、onMapChanged回调都触发
      // 当Map存在'one'时，onMapSizeChanged、onMapChanged回调都不会触发
      Button(`Update one to the same - map.set('one', sameval)`)
        .width(300)
        .margin(10)
        .onClick(() => {
          const sameval = this.map.get('one') ?? 'one';
          this.map.set('one', sameval);
        })
      // 当Map不存在'one'时，onMapSizeChanged、onMapChanged回调都触发
      // 当Map存在'one'时，仅onMapChanged回调触发
      Button(`Update one to new value - map.set('one', newval)`)
        .width(300)
        .margin(10)
        .onClick(() => {
          let newval = 'x' + (++this.cnt);
          this.map.set('one', newval);
        })
      // 当map为空时，仅onMapChanged回调触发
      // 当map不为空时，onMapChanged、onMapSizeChanged回调都触发
      Button(`new map`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.map = new Map();
        })
    }
  }
}
```

![monitor-sync-13](./figures/monitor-sync-13.gif)

### 使用通配符监听Set对象的变化

使用通配符可以监听Set对象的API调用。

```ts
@Monitor({}, 'setInstance.*')
onSetChange(m: IMonitor) {
}
```

@Monitor会在以下情况回调：

- `setInstance`被赋新值。
- 调用Set的API，例如`add`、`delete`、`clear`时触发。与Array、Date不同的是，只有当变化真的发生时，回调才会触发。这意味着，当对空Set调用`clear`，对不存在的Set元素调用`delete`，以及不实际新增元素的`add`调用都不会触发@Monitor回调。

与Array不同，@Monitor无法对Set的某一个key做监听。

使用通配符监听Set对象的示例如下。

<!-- @[monitor_wildcard_support_set](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorWildcardSupportSet.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2
struct MonitorWildcardSet {
  @Local set: Set<string> = new Set<string>();
  cnt: number = 0;

  // 使能通配符
  @Monitor({}, 'set.*')
  onSetChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onSetChanged, dirty: ${m.dirty.toString()}`);
  }

  @Monitor({ enableWildcard: false }, 'set.size')
  onSetSizeChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onSetSizeChanged, size dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    this.set.add('one');
    this.set.add('two');
  }

  build() {
    Column({ space: 5 }) {
      // onSetChanged、onSetSizeChanged回调都触发
      Button(`Add three<Num> to the set`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.cnt++;
          this.set.add('three' + this.cnt);
        })
      // 当元素不存在时，onSetChanged、onSetSizeChanged回调都不触发
      // 当元素存在时，onSetChanged、onSetSizeChanged回调都触发
      Button(`Delete 'three<Num>' from the set - set.delete(...)`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.set.delete('three' + this.cnt);
        })
      // 当set不为空时，onSetChanged、onSetSizeChanged回调都触发
      // 当set为空时，onSetChanged、onSetSizeChanged回调都不触发
      Button(`Clear the set - set.clear()`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.set.clear();
        })
      // 当set不为空时，onSetChanged、onSetSizeChanged回调都触发
      // 当set为空时，仅onSetChanged回调触发
      Button(`Assign new set`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.set = new Set();
        })
      // 当set不包含'one'时，onSetChanged、onSetSizeChanged回调都触发
      // 当set包含'one'时，onSetChanged、onSetSizeChanged回调都不触发
      Button(`Add 'one' to the set`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.set.add('one');
        })
    }
  }
}
```

![monitor-sync-14](./figures/monitor-sync-14.png)

## 限制条件

使用\@Monitor需要注意如下限制条件：

- 不建议在一个类中对同一个属性进行多次\@Monitor的监听。当一个类中存在对一个属性的多次监听时，只有最后一个定义的监听方法会生效。
  <!-- @[monitor_limitation_last_listener_wins](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorLimitationLastListenerWins.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public name: string = 'Tom';
  
    @Monitor('name')
    onNameChange(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `onNameChange`);
    }
  
    @Monitor('name')
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
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.name = 'Jack'; // 仅会触发onNameChangeDuplicate方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-15](./figures/monitor-sync-15.png)

- 当@Monitor传入多个路径参数时，以参数的全拼接结果判断是否重复监听。全拼接时会在参数间加空格，以区分不同参数。例如，`'ab', 'c'`的全拼接结果为`'ab c'`，`'a', 'bc'`的全拼接结果为`'a bc'`，二者全拼接不相等。以下示例中，`Monitor 1`、`Monitor 2`与`Monitor 3`都监听了name属性的变化。由于`Monitor 2`与`Monitor 3`的入参全拼接相等（都为`'name position'`），因此`Monitor 2`不生效，仅`Monitor 3`生效。当name属性变化时，将同时触发onNameAgeChange与onNamePositionChangeDuplicate方法。但请注意，`Monitor 2`与`Monitor 3`的写法仍然被视作在一个类中对同一个属性进行多次@Monitor的监听，这是不建议的。
  <!-- @[monitor_limitation_multiple_path_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorLimitationMultiplePathParams.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  @ObservedV2
  class Info {
    @Trace public name: string = 'Tom';
    @Trace public age: number = 25;
    @Trace public position: string = 'North';
  
    @Monitor('name', 'age') // Monitor 1
    onNameAgeChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `onNameAgeChange path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
    }
  
    @Monitor('name', 'position') // Monitor 2
    onNamePositionChange(monitor: IMonitor) {
      monitor.dirty.forEach((path: string) => {
        hilog.info(0xFF00, 'testTag', '%{public}s',
          `onNamePositionChange path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
    }
  
    // 重复监听name、position，仅最后定义的生效
    @Monitor('name', 'position') // Monitor3
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
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.name = 'Jack'; // 同时触发onNameAgeChange与onNamePositionChangeDuplicate方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-16](./figures/monitor-sync-16.png)

- \@Monitor的参数需要为监听属性名的字符串，仅可以使用字符串字面量、const常量、enum枚举值作为参数。如果使用变量作为参数，仅会监听\@Monitor初始化时，变量值所对应的属性。当更改变量时，\@Monitor无法实时改变监听的属性，即\@Monitor监听的目标属性从初始化时便已经确定，无法动态更改。不建议开发者使用变量作为\@Monitor的参数进行初始化。

  <!-- @[monitor_limitation_parameter_string_constraint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorLimitationParameterStringConstraint.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const t2: string = 't2'; // const常量
  
  enum ENUM {
    T3 = 't3' // enum枚举值
  };
  let t4: string = 't4'; // 变量
  
  @ObservedV2
  class Info {
    @Trace public t1: number = 0;
    @Trace public t2: number = 0;
    @Trace public t3: number = 0;
    @Trace public t4: number = 0;
    @Trace public t5: number = 0;
  
    // 字符串字面量
    @Monitor('t1')
    onT1Change(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `t1 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    @Monitor(t2)
    onT2Change(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `t2 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    @Monitor(ENUM.T3)
    onT3Change(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `t3 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  
    @Monitor(t4)
    onT4Change(monitor: IMonitor) {
      hilog.info(0xFF00, 'testTag', '%{public}s', `t4 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    info: Info = new Info();
  
    build() {
      Column() {
        Button('Change t1')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.t1++; // 能够触发onT1Change方法
          })
        Button('Change t2')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.t2++; // 能够触发onT2Change方法
          })
        Button('Change t3')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.t3++; // 能够触发onT3Change方法
          })
        Button('Change t4')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.t4++; // 能够触发onT4Change方法
          })
        Button('Change var t4 to t5')
          .width(300)
          .margin(10)
          .onClick(() => {
            t4 = 't5'; // 更改变量值为't5'
          })
        Button('Change t5')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.t5++; // onT4Change仍监听t4，不会触发
          })
        Button('Change t4 again')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.info.t4++; // 能够触发onT4Change方法
          })
      }
      .width('100%')
    }
  }
  ```

  ![monitor-sync-17](./figures/monitor-sync-17.png)

- 建议开发者避免在\@Monitor中再次更改被监听的属性，这会导致无限循环。

  ```ts
  @ObservedV2
  class Info {
    @Trace count: number = 0;
    @Monitor('count')
    onCountChange(monitor: IMonitor) {
      this.count++; // 应避免这种写法，会导致无限循环
    }
  }
  ```

## \@Monitor与\@Watch对比

\@Monitor与\@Watch的用法、功能对比如下：

| 用法               | \@Watch                                   | \@Monitor                                                    |
| ------------------ | ----------------------------------------- | ------------------------------------------------------------ |
| 参数               | 回调方法名。                              | 监听状态变量名、属性名。                                     |
| 监听目标数         | 只能监听单个状态变量。                    | 能同时监听多个状态变量。                                     |
| 监听能力           | 跟随状态变量观察能力（一层）。            | 跟随状态变量观察能力（深层）。                               |
| 能否获取变化前的值 | 不能获取变化前的值。                      | 能获取变化前的值。                                           |
| 监听条件           | 监听对象为状态变量。                      | 监听对象为状态变量或为\@Trace装饰的类成员属性。              |
| 使用限制           | 仅能在\@Component装饰的自定义组件中使用。 | 能在\@ComponentV2装饰的自定义组件中使用，也能在\@ObservedV2装饰的类中使用。 |

## 使用场景

### 监听深层属性变化

\@Monitor可以监听深层属性的变化，并能够根据更改前后的值做分类处理。

下面的示例中监听了属性value的变化，并根据变化的幅度改变Text组件显示的样式。

<!-- @[monitor_scene_deep_attribute_changes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorSceneDeepAttributeChanges.ets) -->  

``` TypeScript
@ObservedV2
class Info {
  @Trace public value: number = 50;
}

@ObservedV2
class UIStyle {
  @Trace public info: Info = new Info();
  @Trace public color: Color = Color.Black;
  @Trace public fontSize: number = 45;

  @Monitor('info.value')
  onValueChange(monitor: IMonitor) {
    let lastValue: number = monitor.value()?.before as number;
    let curValue: number = monitor.value()?.now as number;
    if (lastValue != 0) {
      let diffPercent: number = (curValue - lastValue) / lastValue;
      // 通过info.value变化的幅度，改变Text组件显示的样式
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
        .margin(10)
      Button('change!')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.textStyle.info.value = Math.floor(Math.random() * 100) + 1;
        })
    }
    .width('100%')
  }
}
```

![monitor-sync-18](./figures/monitor-sync-18.gif)

## 常见问题

### 自定义组件中\@Monitor对变量监听的生效及失效时间

当\@Monitor定义在\@ComponentV2装饰的自定义组件中时，\@Monitor会在状态变量初始化完成之后生效，并在组件销毁时失效。

<!-- @[monitor_problem_effect_time_comp_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemEffectTimeCompV2.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  @Trace public message: string = 'not initialized';

  constructor() {
    hilog.info(0xFF00, 'testTag', '%{public}s', 'in constructor message change to initialized');
    // 此时@Monitor还未初始化成功，因此不会监听到message的变化
    this.message = 'initialized';
  }
}

@ComponentV2
struct Child {
  @Param info: Info = new Info();

  @Monitor('info.message')
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
        .fontSize(20)
        .margin(10)
      Button('change message in Child')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.info.message = 'Child click to change Message';
        })
    }
    .width('95%')
    .borderColor(Color.Red)
    .borderWidth(2)

  }
}

@Entry
@ComponentV2
struct Index {
  @Local info: Info = new Info();
  @Local flag: boolean = false;

  @Monitor('info.message')
  onMessageChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `Index message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column() {
      Button('show/hide Child')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.flag = !this.flag
        })
      Button('change message in Index')
        .width(300)
        .margin(10)
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

![monitor-sync-19](./figures/monitor-sync-19.gif)

在上面的例子中，可以通过创建和销毁Child组件来观察定义在自定义组件中的\@Monitor的生效和失效时机。推荐按如下顺序进行操作：

- 当Index组件创建Info类实例时，日志输出`in constructor message change to initialized`。此时Index组件的\@Monitor还未初始化成功，因此不会监听到message的变化。
- 当Index组件创建完成，页面加载完成后，点击按钮“change message in Index”，此时Index组件中的\@Monitor能够监听到变化，日志输出`Index message change from initialized to Index click to change Message`。
- 点击按钮“show/hide Child”，创建Child组件，在Child组件初始化\@Param装饰的变量以及\@Monitor之后，调用Child组件的aboutToAppear回调，改变message。此时Index组件与Child组件的\@Monitor均能监听到变化，日志输出`Index message change from Index click to change Message to Child aboutToAppear`以及`Child message change from Index click to change Message to Child aboutToAppear`。
- 点击按钮“change message in Child”，改变message。此时Index组件与Child组件的\@Monitor均能监听到变化，日志输出`Index message change from Child aboutToAppear to Child click to change Message`以及`Child message change from Child aboutToAppear to Child click to change Message`。
- 点击按钮”show/hide Child“，销毁Child组件，调用Child组件的aboutToDisappear回调，改变message。此时Index组件与Child组件的\@Monitor均能监听到变化，日志输出`Child aboutToDisappear`，`Index message change from Child click to change Message to Child aboutToDisappear`以及`Child message change from Child click to change Message to Child aboutToDisappear`。
- 点击按钮“change message in Index”，改变message。此时Child组件已销毁，其注册的\@Monitor监听也被解注册，仅有Index组件的\@Monitor能够监听到变化，日志输出`Index message change from Child aboutToDisappear to Index click to change Message`。

这表明Child组件中定义的\@Monitor监听随着Child组件的创建初始化生效，随着Child组件的销毁失效。

### 类中\@Monitor对变量监听的生效及失效时间

当\@Monitor定义在\@ObservedV2装饰的类中时，\@Monitor会在类的实例创建完成后生效，在类的实例销毁时失效。

<!-- @[monitor_problem_effect_time_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemEffectTimeClass.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  @Trace public message: string = 'not initialized';

  constructor() {
    // 此时@Monitor还未生效，因此不会监听到message的变化
    this.message = 'initialized';
  }

  @Monitor('message')
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
        .width(300)
        .margin(10)
        .onClick(() => {
          this.info.message = 'Index click to change message';
        })
    }
  }
}
```

![monitor-sync-20](./figures/monitor-sync-20.png)

上面的例子中，\@Monitor会在info创建完成后生效，这个时机晚于类的constructor，早于自定义组件的aboutToAppear。当界面加载完成后，点击“change message”，修改message变量。此时日志输出信息如下：

```ts
message change from initialized to Index aboutToAppear
message change from Index aboutToAppear to Index click to change message
```

类中定义的\@Monitor随着类的销毁失效。而由于类的实际销毁释放依赖于垃圾回收机制，因此会出现即使所在自定义组件已经销毁，类却还未及时销毁，导致类中定义的\@Monitor仍在监听变化的情况。

<!-- @[monitor_problem_class_delayed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemClassDelayed.ets) -->   

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class InfoWrapper {
  public info?: Info;

  constructor(info: Info) {
    this.info = info;
  }

  @Monitor('info.age')
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
    hilog.info(0xFF00, 'testTag', '%{public}s', `Child aboutToDisappear, age: ${this.infoWrapper.info?.age}`);
  }

  build() {
    Column() {
      Text(`${this.infoWrapper.info?.age}`)
        .fontSize(20)
        .margin(10)
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
      // 点击Button切换showFlag，触发Child组件的创建/销毁
      Button('change showFlag')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
      Button('change number')
        .width(300)
        .margin(10)
        .onClick(() => {
          hilog.info(0xFF00, 'testTag', '%{public}s', 'click to change age');
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          });
        })
      if (this.showFlag) {
        Column() {
          Text('Children')
            .fontSize(20)
            .margin(10)
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

![monitor-sync-21](./figures/monitor-sync-21.gif)

在上面的例子中，当点击“change showFlag”切换if组件的条件时，Child组件会被销毁。此时，点击“change number”修改age的值时，可以通过日志观察到InfoWrapper中定义的\@Monitor回调仍然被触发了。这是因为此时自定义组件Child虽然执行了aboutToDisappear，但是其成员变量infoWrapper还没有被立刻回收，当变量发生变化时，依然能够调用到infoWrapper中定义的onInfoAgeChange方法，所以从现象上看\@Monitor回调仍会被触发。

借助垃圾回收机制去取消\@Monitor的监听是不稳定的，开发者可以采用以下两种方式去管理\@Monitor的失效时间：

1、将\@Monitor定义在自定义组件中。由于自定义组件在销毁时，状态管理框架会手动取消\@Monitor的监听，因此在自定义组件调用完aboutToDisappear，尽管自定义组件的数据不一定已经被释放，但\@Monitor回调已不会再被触发。

<!-- @[monitor_problem_class_failure_time_set_comp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemClassFailureTimeSetComp.ets) -->   

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

  @Monitor('infoWrapper.info.age')
  onInfoAgeChange(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s',
      `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  aboutToDisappear(): void {
    hilog.info(0xFF00, 'testTag', '%{public}s', `Child aboutToDisappear, age: ${this.infoWrapper.info?.age}`);
  }

  build() {
    Column() {
      Text(`${this.infoWrapper.info?.age}`)
        .fontSize(20)
        .margin(10)
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
      // 点击Button切换showFlag，触发Child组件的创建/销毁
      Button('change showFlag')
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
        .margin(10)
      Button('change number')
        .onClick(() => {
          hilog.info(0xFF00, 'testTag', '%{public}s', 'click to change age');
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          })
        })
        .margin(10)
      if (this.showFlag) {
        Column() {
          Text('Children')
            .fontSize(20)
            .margin(10)
          ForEach(this.dataArray, (info: Info) => {
            Child({ infoWrapper: new InfoWrapper(info) })
          })
        }
        .borderColor(Color.Red)
        .borderWidth(2)
      }
    }
    .width('100%')
  }
}
```

![monitor-sync-22](./figures/monitor-sync-22.gif)

2、主动置空监听的对象。当自定义组件即将销毁时，主动置空\@Monitor的监听目标，这样\@Monitor无法再监听原监听目标的变化，达到取消\@Monitor监听的效果。

<!-- @[monitor_problem_class_failure_time_empty_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemClassFailureTimeEmptyObject.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class InfoWrapper {
  public info?: Info;

  constructor(info: Info) {
    this.info = info;
  }

  @Monitor('info.age')
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
    hilog.info(0xFF00, 'testTag', '%{public}s', `Child aboutToDisappear, age: ${this.infoWrapper.info?.age}`);
    this.infoWrapper.info = undefined; // 使InfoWrapper对info.age的监听失效
  }

  build() {
    Column() {
      Text(`${this.infoWrapper.info?.age}`)
        .fontSize(20)
        .margin(10)
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
        .margin(10)
      Button('change number')
        .onClick(() => {
          hilog.info(0xFF00, 'testTag', '%{public}s', 'click to change age');
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          })
        })
        .margin(10)
      if (this.showFlag) {
        Column() {
          Text('Children')
            .fontSize(20)
            .margin(10)
          ForEach(this.dataArray, (info: Info) => {
            Child({ infoWrapper: new InfoWrapper(info) })
          })
        }
        .borderColor(Color.Red)
        .borderWidth(2)
      }
    }
    .width('100%')
  }
}
```

![monitor-sync-23](./figures/monitor-sync-23.gif)

### 正确设置\@Monitor入参

从API version 23起，增加了对\@Monitor入参的编译时校验。当\@Monitor的入参不符合监听条件时（如传入非状态变量、不存在的变量等），将会有编辑、编译告警，但\@Monitor回调仍会被触发。开发者应正确传入\@Monitor入参，避免监听非状态变量，防止功能异常或行为与预期不符。

【反例1】

<!-- @[monitor_problem_param_counter_example_1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemParamCounterExample1.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 同时监听状态变量age和非状态变量name
  // 此时会编辑、编译告警，提示`The '@Monitor' decorator needs to monitor the state variables that exist.`
  @Monitor('age', 'name')
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
    .width('100%')
  }
}
```

![monitor-sync-24](./figures/monitor-sync-24.png)

上面的代码中，当点击按钮同时更改状态变量age和非状态变量name时，会输出以下日志：

```text
property path:age change from 24 to 25
property path:name change from John to Johny
```

实际上name属性本身并不是可被观测的变量，不应被加入到\@Monitor的入参当中。

从API版本26.0.0开始，使用配置项的\@Monitor对路径的监听变为互相独立的监听，各路径互不影响。若改为使用配置项的\@Monitor（如`@Monitor({}, 'age', 'name')`），非状态变量name将被忽略，不参与监听。仅当状态变量age变化时才会触发回调，且dirty中仅包含age；当仅修改name时不会触发回调。在这种情况下，点击按钮同时修改age和name时，会输出以下日志：

```text
property path:age change from 24 to 25
```

建议开发者去除对name属性的监听，或给name加上\@Trace装饰使其成为状态变量；也可改为使用配置项的\@Monitor。

【正例1】

<!-- @[monitor_problem_param_positive_example_1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemParamPositiveExample1.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 仅监听状态变量age
  @Monitor('age')
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
    .width('100%')
  }
}
```

![monitor-sync-25](./figures/monitor-sync-25.png)

【反例2】

<!-- @[monitor_problem_param_counter_example_2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemParamCounterExample2.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  get myAge() {
    return this.age; // age为状态变量
  }

  // 监听非@Computed装饰的getter访问器
  @Monitor('myAge')
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

上面的代码中，\@Monitor的入参为一个getter访问器的名字，但该getter访问器本身并未被\@Computed装饰，不是一个可被监听的变量。但由于使用了状态变量参与了计算，在状态变量变化后，myAge也被认为发生了变化，因此触发了\@Monitor回调。从API版本26.0.0开始，若改为使用配置项的\@Monitor（如`@Monitor({}, 'myAge')`），由于读取myAge时仍会读取状态变量age，因此行为不变，依然会触发回调。

建议开发者给myAge添加\@Computed装饰器使其成为状态变量，或直接监听状态变量本身。

【正例2】

将myAge变为状态变量：
<!-- @[monitor_problem_param_positive_example_2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemParamPositiveExample2.ets) --> 

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
  @Monitor('myAge')
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
    .width('100%')
  }
}
```

![monitor-sync-26](./figures/monitor-sync-26.png)

或直接监听状态变量本身：
<!-- @[monitor_problem_param_state_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemParamStateVariables.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Info {
  public name: string = 'John';
  @Trace public age: number = 24;

  // 监听状态变量age
  @Monitor('age')
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
    .width('100%')
  }
}
```

![monitor-sync-27](./figures/monitor-sync-27.png)

### 无法监听变量从可访问变为不可访问和从不可访问变为可访问
\@Monitor仅会保存变量可访问时的值，当状态变量变为不可访问的状态时，并不会记录其值的变化。在下面的例子中，点击三个Button，均不会触发`onChange`的回调。

从API version 20开始，如果需要监听可访问到不可访问和不可访问到可访问的状态变化，可以使用[addMonitor](./arkts-new-addMonitor-clearMonitor.md#监听变量从可访问到不访问和从不可访问到可访问)。

从API版本26.0.0开始，使用配置项的\@Monitor能够正常处理变量在可访问与不可访问之间的切换。在下面的例子中，若将`@Monitor('user.age')`改写为使用配置项的形式`@Monitor({}, 'user.age')`，则点击三个Button均会触发`onChange`回调，dirty中将包含路径`user.age`，其对应的IMonitorValue的before值与now值会分别反映可访问性切换前后的状态（变量可访问时为实际值，变量不可访问时为undefined）。

<!-- @[monitor_problem_state_change_use_addMonitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/monitor/MonitorProblemStateChangeUseAddMonitor.ets) --> 

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

  @Monitor('user.age')
  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      hilog.info(0xFF00, 'testTag', '%{public}s',
        `onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`User age ${this.user?.age}`)
        .fontSize(20)
        .margin(10)
      Button('set user to undefined')
        .width(300)
        .margin(10)
        .onClick(() => {
          // age：可访问 -> 不可访问
          this.user = undefined;
        })
      Button('set user to User')
        .width(300)
        .margin(10)
        .onClick(() => {
          // age：不可访问 ->可访问
          this.user = new User();
        })
      Button('set user to null')
        .width(300)
        .margin(10)
        .onClick(() => {
          // age：可访问->不可访问
          this.user = null;
        })
    }
  }
}
```

![monitor-sync-28](./figures/monitor-sync-28.gif)
