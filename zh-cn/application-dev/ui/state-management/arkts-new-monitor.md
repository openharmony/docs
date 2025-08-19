# \@Monitor装饰器：状态变量修改监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了增强状态管理框架对状态变量变化的监听能力，开发者可以使用\@Monitor装饰器对状态变量进行监听。


\@Monitor提供了对V2状态变量的监听。在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-new-componentV2.md)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，[\@Local](./arkts-new-local.md)。

>**说明：**
>
> \@Monitor装饰器从API version 12开始支持。
>
> 从API version 12开始，该装饰器支持在原子化服务中使用。

## 概述

\@Monitor装饰器用于监听状态变量修改，使得状态变量具有深度监听的能力：

- \@Monitor装饰器支持在\@ComponentV2装饰的自定义组件中使用，未被状态变量装饰器[\@Local](arkts-new-local.md)、[\@Param](arkts-new-param.md)、[\@Provider](arkts-new-Provider-and-Consumer.md)、[\@Consumer](arkts-new-Provider-and-Consumer.md)、[\@Computed](arkts-new-Computed.md)装饰的变量无法被\@Monitor监听到变化。

- \@Monitor装饰器支持在类中与[\@ObservedV2、\@Trace](arkts-new-observedV2-and-trace.md)配合使用，不允许在未被\@ObservedV2装饰的类中使用\@Monitor装饰器。未被\@Trace装饰的属性无法被\@Monitor监听到变化。
- 当观测的属性变化时，\@Monitor装饰器定义的回调方法将被调用。判断属性是否变化使用的是严格相等（===），当严格相等判断的结果是false（即不相等）的情况下，就会触发\@Monitor的回调。当在一次事件中多次改变同一个属性时，将会使用初始值和最终值进行比较以判断是否变化。
- 单个\@Monitor装饰器能够同时监听多个属性的变化，当这些属性在一次事件中共同变化时，只会触发一次\@Monitor的回调方法。
- \@Monitor装饰器具有深度监听的能力，能够监听嵌套类、多维数组、对象数组中指定项的变化。对于嵌套类、对象数组中成员属性变化的监听要求该类被\@ObservedV2装饰且该属性被\@Trace装饰。
- 在继承类场景中，可以在父子组件中对同一个属性分别定义\@Monitor进行监听，当属性变化时，父子组件中定义的\@Monitor回调均会被调用。
- 和[\@Watch装饰器](arkts-watch.md)类似，开发者需要自己定义回调函数，区别在于\@Watch装饰器将函数名作为参数，而\@Monitor直接装饰回调函数。\@Monitor与\@Watch的对比可以查看[\@Monitor与\@Watch的对比](#monitor与watch对比)。

## 状态管理V1版本\@Watch装饰器的局限性

现有状态管理V1版本无法实现对对象、数组中某一单个属性或数组项变化的监听，且无法获取变化之前的值。

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
    console.info(`info after change name: ${this.info.name}, age: ${this.info.age} `);
  }
  onNumArrChange() {
    console.info(`numArr after change ${this.numArr}`);
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

上述代码中，点击"change info name"更改info中的name属性或点击"change info age"更改age时，均会触发info注册的\@Watch回调。点击"change numArr[2]"更改numArr中的第3个元素或点击"change numArr[3]"更改第4个元素时，均会触发numArr注册的\@Watch回调。在这两个回调中，由于无法获取数据更改前的值，在业务逻辑更加复杂的场景下，无法准确知道是哪一个属性或元素发生了改变从而触发了\@Watch事件，这不便于开发者对变量的更改进行准确监听。因此推出\@Monitor装饰器实现对对象、数组中某一单个属性或数组项变化的监听，并且能够获取到变化之前的值。

## 装饰器说明

| \@Monitor属性装饰器 | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数          | 字符串类型的对象属性名。可同时监听多个对象属性，每个属性以逗号隔开，例如@Monitor("prop1", "prop2")。可监听深层的属性变化，如多维数组中的某一个元素，嵌套对象或对象数组中的某一个属性。详见[监听变化](#监听变化)。 |
| 装饰对象            | \@Monitor装饰成员方法。当监听的属性发生变化时，会触发该回调方法。该回调方法以[IMonitor类型](../../reference/apis-arkui/arkui-ts/ts-state-management-watch-monitor.md#imonitor12)的变量作为参数，开发者可以从该参数中获取变化前后的相关信息。 |

## 接口说明

IMonitor类型和IMonitorValue\<T\>类型的接口说明参考API文档：[状态变量变化监听](../../reference/apis-arkui/arkui-ts/ts-state-management-watch-monitor.md)。

## 监听变化

### 在\@ComponentV2装饰的自定义组件中使用\@Monitor

使用\@Monitor监听的状态变量发生变化时，会触发\@Monitor的回调方法。

- \@Monitor监听的变量需要被\@Local、\@Param、\@Provider、\@Consumer、\@Computed装饰，未被状态变量装饰器装饰的变量在变化时无法被监听。\@Monitor可以同时监听多个状态变量，这些变量名之间用","隔开。

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
        console.info(`${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
      });
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

- \@Monitor监听的状态变量为类对象时，仅能监听对象整体的变化。监听类属性的变化需要类属性被\@Trace装饰。

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
      console.info(`info change`);
    }
    @Monitor("info.name")
    infoPropertyChange(monitor: IMonitor) {
      console.info(`info name change`);
    }
    build() {
      Column() {
        Text(`name: ${this.info.name}, age: ${this.info.age}`)
        Button("change info")
          .onClick(() => {
            this.info = new Info("Lucy", 18); // 能够监听到
          })
        Button("change info.name")
          .onClick(() => {
            this.info.name = "Jack"; // 监听不到
          })
      }
    }
  }
  ```

### 在\@ObservedV2装饰的类中使用\@Monitor

使用\@Monitor监听的属性发生变化时，会触发\@Monitor的回调方法。

- \@Monitor监听的对象属性需要被\@Trace装饰，未被\@Trace装饰的属性的变化无法被监听。\@Monitor可以同时监听多个属性，这些属性之间用","隔开。

```ts
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace region: string = "North";
  @Trace job: string = "Teacher";
  age: number = 25;
  // name被@Trace装饰，能够监听变化
  @Monitor("name")
  onNameChange(monitor: IMonitor) {
    console.info(`name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  // age未被@Trace装饰，不能监听变化
  @Monitor("age")
  onAgeChange(monitor: IMonitor) {
    console.info(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  // region与job均被@Trace装饰，能够监听变化
  @Monitor("region", "job")
  onChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
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
          this.info.name = "Jack"; // 能够触发onNameChange方法
        })
      Button("change age")
        .onClick(() => {
          this.info.age = 26; // 不能够触发onAgeChange方法
        })
      Button("change region")
        .onClick(() => {
          this.info.region = "South"; // 能够触发onChange方法
        })
      Button("change job")
        .onClick(() => {
          this.info.job = "Driver"; // 能够触发onChange方法
        })
    }
  }
}
```

- \@Monitor可以监听深层属性的变化，该深层属性需要被@Trace装饰。

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
    console.info(`inner.num change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@Entry
@ComponentV2
struct Index {
  outer: Outer = new Outer();
  build() {
    Column() {
      Button("change num")
        .onClick(() => {
          this.outer.inner.num = 100; // 能够触发onChange方法
        })
    }
  }
}
```

- 在继承类场景下，可以在继承链中对同一个属性进行多次监听。

```ts
@ObservedV2
class Base {
  @Trace name: string;
  // 基类监听name属性
  @Monitor("name")
  onBaseNameChange(monitor: IMonitor) {
    console.info(`Base Class name change`);
  }
  constructor(name: string) {
    this.name = name;
  }
}
@ObservedV2
class Derived extends Base {
  // 继承类监听name属性
  @Monitor("name")
  onDerivedNameChange(monitor: IMonitor) {
    console.info(`Derived Class name change`);
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
          this.derived.name = "BBB"; // 能够先后触发onBaseNameChange、onDerivedNameChange方法
        })
    }
  }
}
```

### 通用监听能力

\@Monitor还有一些通用的监听能力。

- \@Monitor支持对数组中的项进行监听，包括多维数组，对象数组。\@Monitor无法监听内置类型（Array、Map、Date、Set）的API调用引起的变化。当\@Monitor监听数组整体时，只能观测到数组整体的赋值。可以通过监听数组的长度变化来判断数组是否有插入、删除等变化。当前仅支持使用"."的方式表达深层属性、数组项的监听。

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
  // dimensionTwo为二维简单类型数组，且被@Trace装饰，能够观测里面的元素变化
  @Monitor("dimensionTwo.0.0", "dimensionTwo.1.1")
  onDimensionTwoChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`dimensionTwo path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
  // dimensionThree为三维简单类型数组，且被@Trace装饰，能够观测里面的元素变化
  @Monitor("dimensionThree.0.0.0", "dimensionThree.1.1.0")
  onDimensionThreeChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`dimensionThree path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
  // Info类中属性name、age均被@Trace装饰，能够监听到变化
  @Monitor("infoArr.0.name", "infoArr.1.age")
  onInfoArrPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`infoArr path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
  // infoArr被@Trace装饰，能够监听到infoArr整体赋值的变化
  @Monitor("infoArr")
  onInfoArrChange(monitor: IMonitor) {
    console.info(`infoArr whole change`);
  }
  // 能够监听到infoArr的长度变化
  @Monitor("infoArr.length")
  onInfoArrLengthChange(monitor: IMonitor) {
    console.info(`infoArr length change`);
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
          // 能够触发onDimensionTwoChange方法  
          this.arrMonitor.dimensionTwo[0][0]++; 
          this.arrMonitor.dimensionTwo[1][1]++; 
        })
      Button("Change dimensionThree")
        .onClick(() => {
          // 能够触发onDimensionThreeChange方法
          this.arrMonitor.dimensionThree[0][0][0]++;
          this.arrMonitor.dimensionThree[1][1][0]++; 
        })
      Button("Change info property")
        .onClick(() => {
          // 能够触发onInfoArrPropertyChange方法
          this.arrMonitor.infoArr[0].name = "Tom"; 
          this.arrMonitor.infoArr[1].age = 19; 
        })
      Button("Change whole infoArr")
        .onClick(() => {
          // 能够触发onInfoArrChange、onInfoArrPropertyChange、onInfoArrLengthChange方法
          this.arrMonitor.infoArr = [new Info("Cindy", 8)]; 
        })
      Button("Push new info to infoArr")
        .onClick(() => {
          // 能够触发onInfoArrPropertyChange、onInfoArrLengthChange方法
          this.arrMonitor.infoArr.push(new Info("David", 50)); 
        })
    }
  }
}
```

- 对象整体改变，但监听的属性不变时，不触发\@Monitor回调。

下面的示例按照Step1-Step2-Step3的顺序点击，表现为代码注释中的行为。

如果只点击Step2或Step3，改变name、age的值，此时会触发onNameChange和onAgeChange方法。

```ts
@ObservedV2
class Info {
  @Trace person: Person;
  @Monitor("person.name")
  onNameChange(monitor: IMonitor) {
    console.info(`name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor("person.age")
  onAgeChange(monitor: IMonitor) {
    console.info(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
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
      Button("Step1、Only change name")
        .onClick(() => {
          this.info.person = new Person("Jack", 25);  // 能够触发onNameChange方法，不触发onAgeChange方法
        })
      Button("Step2、Only change age")
        .onClick(() => {
          this.info.person = new Person("Jack", 18);  // 能够触发onAgeChange方法，不触发onNameChange方法
        })
      Button("Step3、Change name and age")
        .onClick(() => {
          this.info.person = new Person("Lucy", 19);  // 能够触发onNameChange、onAgeChange方法
        })
    }
  }
}
```

- 在一次事件中多次改变被\@Monitor监听的属性，以最后一次修改为准。

```ts
@ObservedV2
class Frequency {
  @Trace count: number = 0;

  @Monitor("count")
  onCountChange(monitor: IMonitor) {
    console.info(`count change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}

@Entry
@ComponentV2
struct Index {
  frequency: Frequency = new Frequency();

  build() {
    Column() {
      Button("change count to 1000")
        .onClick(() => {
          for (let i = 1; i <= 1000; i++) {
            this.frequency.count = i;
          }
        })
      Button("change count to 0 then to 1000")
        .onClick(() => {
          for (let i = 999; i >= 0; i--) {
            this.frequency.count = i;
          }
          this.frequency.count = 1000; // 最终不触发onCountChange方法
        })
    }
  }
}
```

在点击按钮"change count to 1000"后，会触发一次onCountChange方法，并输出日志"count change from 0 to 1000"。在点击按钮"change count to 0 then to 1000"后，由于事件前后属性count的值并没有改变，都为1000，所以不触发onCountChange方法。

## 限制条件

使用\@Monitor需要注意如下限制条件：

- 不建议在一个类中对同一个属性进行多次\@Monitor的监听。当一个类中存在对一个属性的多次监听时，只有最后一个定义的监听方法会生效。

```ts
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Monitor("name")
  onNameChange(monitor: IMonitor) {
    console.info(`onNameChange`);
  }
  @Monitor("name")
  onNameChangeDuplicate(monitor: IMonitor) {
    console.info(`onNameChangeDuplicate`);
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
          this.info.name = "Jack"; // 仅会触发onNameChangeDuplicate方法
        })
    }
  }
}
```

- 当@Monitor传入多个路径参数时，以参数的全拼接结果判断是否重复监听。以下示例中，`Monitor 1`、`Monitor 2`与`Monitor 3`都监听了name属性的变化。由于`Monitor 2`与`Monitor 3`的入参全拼接相等，因此`Monitor 2`不生效，仅`Monitor 3`生效。当name属性变化时，将同时触发onNameAgeChange与onNamePositionChangeDuplicate方法。但请注意，`Monitor 2`与`Monitor 3`的写法仍然被视作在一个类中对同一个属性进行多次@Monitor的监听，这是不建议的。

```ts
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace age: number = 25;
  @Trace position: string = "North";
  @Monitor("name", "age") // Monitor 1
  onNameAgeChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`onNameAgeChange path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }
  @Monitor("name", "position") // Monitor 2
  onNamePositionChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`onNamePositionChange path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }
  // 重复监听name、position，仅最后定义的生效
  @Monitor("name", "position") // Monitor3
  onNamePositionChangeDuplicate(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`onNamePositionChangeDuplicate path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
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
          this.info.name = "Jack"; // 同时触发onNameAgeChange与onNamePositionChangeDuplicate方法
        })
    }
  }
}
```

- \@Monitor的参数需要为监听属性名的字符串，仅可以使用字符串字面量、const常量、enum枚举值作为参数。如果使用变量作为参数，仅会监听\@Monitor初始化时，变量值所对应的属性。当更改变量时，\@Monitor无法实时改变监听的属性，即\@Monitor监听的目标属性从初始化时便已经确定，无法动态更改。不建议开发者使用变量作为\@Monitor的参数进行初始化。

```ts
const t2: string = "t2"; // const常量
enum ENUM {
  T3 = "t3" // enum枚举值
};
let t4: string = "t4"; // 变量
@ObservedV2
class Info {
  @Trace t1: number = 0;
  @Trace t2: number = 0;
  @Trace t3: number = 0;
  @Trace t4: number = 0;
  @Trace t5: number = 0;
  @Monitor("t1") // 字符串字面量
  onT1Change(monitor: IMonitor) {
    console.info(`t1 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor(t2)
  onT2Change(monitor: IMonitor) {
    console.info(`t2 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor(ENUM.T3)
  onT3Change(monitor: IMonitor) {
    console.info(`t3 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor(t4)
  onT4Change(monitor: IMonitor) {
    console.info(`t4 change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
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
          this.info.t1++; // 能够触发onT1Change方法
        })
      Button("Change t2")
        .onClick(() => {
          this.info.t2++; // 能够触发onT2Change方法
        })
      Button("Change t3")
        .onClick(() => {
          this.info.t3++; // 能够触发onT3Change方法
        })
      Button("Change t4")
        .onClick(() => {
          this.info.t4++; // 能够触发onT4Change方法
        })
      Button("Change var t4 to t5")
        .onClick(() => {
          t4 = "t5"; // 更改变量值为"t5"
        })
      Button("Change t5")
        .onClick(() => {
          this.info.t5++; // onT4Change仍监听t4，不会触发
        })
      Button("Change t4 again")
        .onClick(() => {
          this.info.t4++; // 能够触发onT4Change方法
        })
    }
  }
}
```

- 建议开发者避免在\@Monitor中再次更改被监听的属性，这会导致无限循环。

```ts
@ObservedV2
class Info {
  @Trace count: number = 0;
  @Monitor("count")
  onCountChange(monitor: IMonitor) {
    this.count++; // 应避免这种写法，会导致无限循环
  }
}
```

## \@Monitor与\@Watch对比

\@Monitor与\@Watch的用法、功能对比如下：

|                    | \@Watch                                 | \@Monitor                                                    |
| ------------------ | --------------------------------------- | ------------------------------------------------------------ |
| 参数               | 回调方法名。                              | 监听状态变量名、属性名。                                       |
| 监听目标数         | 只能监听单个状态变量。                    | 能同时监听多个状态变量。                                       |
| 监听能力           | 跟随状态变量观察能力（一层）。           | 跟随状态变量观察能力（深层）。                                 |
| 能否获取变化前的值 | 不能获取变化前的值。                      | 能获取变化前的值。                                             |
| 监听条件           | 监听对象为状态变量。                      | 监听对象为状态变量或为\@Trace装饰的类成员属性。                |
| 使用限制           | 仅能在\@Component装饰的自定义组件中使用。 | 能在\@ComponentV2装饰的自定义组件中使用，也能在\@ObservedV2装饰的类中使用。 |

## 使用场景

### 监听深层属性变化

\@Monitor可以监听深层属性的变化，并能够根据更改前后的值做分类处理。

下面的示例中监听了属性value的变化，并根据变化的幅度改变Text组件显示的样式。

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

## 常见问题

### 自定义组件中\@Monitor对变量监听的生效及失效时间

当\@Monitor定义在\@ComponentV2装饰的自定义组件中时，\@Monitor会在状态变量初始化完成之后生效，并在组件销毁时失效。

```ts
@ObservedV2
class Info {
  @Trace message: string = "not initialized";

  constructor() {
    console.info("in constructor message change to initialized");
    this.message = "initialized";
  }
}
@ComponentV2
struct Child {
  @Param info: Info = new Info();
  @Monitor("info.message")
  onMessageChange(monitor: IMonitor) {
    console.info(`Child message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  aboutToAppear(): void {
    this.info.message = "Child aboutToAppear";
  }
  aboutToDisappear(): void {
    console.info("Child aboutToDisappear");
    this.info.message = "Child aboutToDisappear";
  }
  build() {
    Column() {
      Text("Child")
      Button("change message in Child")
        .onClick(() => {
          this.info.message = "Child click to change Message";
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
  @Monitor("info.message")
  onMessageChange(monitor: IMonitor) {
    console.info(`Index message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column() {
      Button("show/hide Child")
        .onClick(() => {
          this.flag = !this.flag
        })
      Button("change message in Index")
        .onClick(() => {
          this.info.message = "Index click to change Message";
        })
      if (this.flag) {
        Child({ info: this.info })
      }
    }
  }
}
```

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

```ts
@ObservedV2
class Info {
  @Trace message: string = "not initialized";

  constructor() {
    this.message = "initialized";
  }
  @Monitor("message")
  onMessageChange(monitor: IMonitor) {
    console.info(`message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();

  aboutToAppear(): void {
    this.info.message = "Index aboutToAppear";
  }

  build() {
    Column() {
      Button("change message")
        .onClick(() => {
          this.info.message = "Index click to change message";
        })
    }
  }
}
```

上面的例子中，\@Monitor会在info创建完成后生效，这个时机晚于类的constructor，早于自定义组件的aboutToAppear。当界面加载完成后，点击“change message”，修改message变量。此时日志输出信息如下：

```ts
message change from initialized to Index aboutToAppear
message change from Index aboutToAppear to Index click to change message
```

类中定义的\@Monitor随着类的销毁失效。而由于类的实际销毁释放依赖于垃圾回收机制，因此会出现即使所在自定义组件已经销毁，类却还未及时销毁，导致类中定义的\@Monitor仍在监听变化的情况。

```ts
@ObservedV2
class InfoWrapper {
  info?: Info;
  constructor(info: Info) {
    this.info = info;
  }
  @Monitor("info.age")
  onInfoAgeChange(monitor: IMonitor) {
    console.info(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@ObservedV2
class Info {
  @Trace age: number;
  constructor(age: number) {
    this.age = age;
  }
}
@ComponentV2
struct Child {
  @Param @Require infoWrapper: InfoWrapper;
  aboutToDisappear(): void {
    console.info("Child aboutToDisappear", this.infoWrapper.info?.age);
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
      Button("change showFlag")
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
      Button("change number")
        .onClick(() => {
          console.info("click to change age");
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          });
        })
      if (this.showFlag) {
        Column() {
          Text("Childs")
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

在上面的例子中，当点击“change showFlag”切换if组件的条件时，Child组件会被销毁。此时，点击“change number”修改age的值时，可以通过日志观察到InfoWrapper中定义的\@Monitor回调仍然被触发了。这是因为此时自定义组件Child虽然执行了aboutToDisappear，但是其成员变量infoWrapper还没有被立刻回收，当变量发生变化时，依然能够调用到infoWrapper中定义的onInfoAgeChange方法，所以从现象上看\@Monitor回调仍会被触发。

借助垃圾回收机制去取消\@Monitor的监听是不稳定的，开发者可以采用以下两种方式去管理\@Monitor的失效时间：

1、将\@Monitor定义在自定义组件中。由于自定义组件在销毁时，状态管理框架会手动取消\@Monitor的监听，因此在自定义组件调用完aboutToDisappear，尽管自定义组件的数据不一定已经被释放，但\@Monitor回调已不会再被触发。

```ts
@ObservedV2
class InfoWrapper {
  info?: Info;
  constructor(info: Info) {
    this.info = info;
  }
}
@ObservedV2
class Info {
  @Trace age: number;
  constructor(age: number) {
    this.age = age;
  }
}
@ComponentV2
struct Child {
  @Param @Require infoWrapper: InfoWrapper;
  @Monitor("infoWrapper.info.age")
  onInfoAgeChange(monitor: IMonitor) {
    console.info(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  aboutToDisappear(): void {
    console.info("Child aboutToDisappear", this.infoWrapper.info?.age);
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
      Button("change showFlag")
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
      Button("change number")
        .onClick(() => {
          console.info("click to change age");
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          })
        })
      if (this.showFlag) {
        Column() {
          Text("Childs")
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

2、主动置空监听的对象。当自定义组件即将销毁时，主动置空\@Monitor的监听目标，这样\@Monitor无法再监听原监听目标的变化，达到取消\@Monitor监听的效果。

```ts
@ObservedV2
class InfoWrapper {
  info?: Info;
  constructor(info: Info) {
    this.info = info;
  }
  @Monitor("info.age")
  onInfoAgeChange(monitor: IMonitor) {
    console.info(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@ObservedV2
class Info {
  @Trace age: number;
  constructor(age: number) {
    this.age = age;
  }
}
@ComponentV2
struct Child {
  @Param @Require infoWrapper: InfoWrapper;
  aboutToDisappear(): void {
    console.info("Child aboutToDisappear", this.infoWrapper.info?.age);
    this.infoWrapper.info = undefined; // 使InfoWrapper对info.age的监听失效
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
      Button("change showFlag")
        .onClick(() => {
          this.showFlag = !this.showFlag;
        })
      Button("change number")
        .onClick(() => {
          console.info("click to change age");
          this.dataArray.forEach((info: Info) => {
            info.age += 100;
          })
        })
      if (this.showFlag) {
        Column() {
          Text("Childs")
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

### 正确设置\@Monitor入参

由于\@Monitor无法对入参做编译时校验，当前存在以下写法不符合\@Monitor监听条件但\@Monitor仍会触发的情况。开发者应当正确传入\@Monitor入参，不传入非状态变量，避免造成功能异常或行为表现不符合预期。

【反例1】

```ts
@ObservedV2
class Info {
  name: string = "John";
  @Trace age: number = 24;
  @Monitor("age", "name") // 同时监听状态变量age和非状态变量name
  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change age&name")
        .onClick(() => {
          this.info.age = 25; // 同时改变状态变量age和非状态变量name
          this.info.name = "Johny";
        })
    }
  }
}
```

上面的代码中，当点击按钮同时更改状态变量age和非状态变量name时，会输出以下日志：

```
property path:age change from 24 to 25
property path:name change from John to Johny
```

实际上name属性本身并不是可被观测的变量，不应被加入到\@Monitor的入参当中。建议开发者去除对name属性的监听或者给name加上\@Trace装饰成为状态变量。

【正例1】

```ts
@ObservedV2
class Info {
  name: string = "John";
  @Trace age: number = 24;
  @Monitor("age") // 仅监听状态变量age
  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change age&name")
        .onClick(() => {
          this.info.age = 25; // 状态变量age改变
          this.info.name = "Johny";
        })
    }
  }
}
```

【反例2】

```ts
@ObservedV2
class Info {
  name: string = "John";
  @Trace age: number = 24;
  get myAge() {
    return this.age; // age为状态变量
  }
  @Monitor("myAge") // 监听非@Computed装饰的getter访问器
  onPropertyChange() {
    console.info("age changed");
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change age")
        .onClick(() => {
          this.info.age = 25; // 状态变量age改变
        })
    }
  }
}
```

上面的代码中，\@Monitor的入参为一个getter访问器的名字，但该getter访问器本身并未被\@Computed装饰，不是一个可被监听的变量。但由于使用了状态变量参与了计算，在状态变量变化后，myAge也被认为发生了变化，因此触发了\@Monitor回调。建议开发者给myAge添加\@Computed装饰器或当getter访问器直接返回状态变量时，不监听getter访问器而是直接监听状态变量本身。

【正例2】

将myAge变为状态变量：

```ts
@ObservedV2
class Info {
  name: string = "John";
  @Trace age: number = 24;
  @Computed // 给myAge添加@Computed成为状态变量
  get myAge() {
    return this.age;
  }
  @Monitor("myAge") // 监听@Computed装饰的getter访问器
  onPropertyChange() {
    console.info("age changed");
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change age")
        .onClick(() => {
          this.info.age = 25; // 状态变量age改变
        })
    }
  }
}
```

或直接监听状态变量本身：

```ts
@ObservedV2
class Info {
  name: string = "John";
  @Trace age: number = 24;
  @Monitor("age") // 监听状态变量age
  onPropertyChange() {
    console.info("age changed");
  }
}
@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button("change age")
        .onClick(() => {
          this.info.age = 25; // 状态变量age改变
        })
    }
  }
}
```
### 无法监听变量从可访问变为不可访问和从不可访问变为可访问
\@Monitor仅会保存变量可访问时的值，当状态变量变为不可访问的状态时，并不会记录其值的变化。在下面的例子中，点击三个Button，均不会触发`onChange`的回调。
如果需要监听可访问到不可访问和不可访问到可访问的状态变化，可以使用[addMonitor](./arkts-new-addMonitor-clearMonitor.md#监听变量从可访问到不访问和从不可访问到可访问)。

```ts
@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User | undefined | null = new User();

  @Monitor('user.age')
  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
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
