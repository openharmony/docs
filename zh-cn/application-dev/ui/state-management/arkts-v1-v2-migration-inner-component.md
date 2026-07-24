# 组件内状态变量迁移
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

本文档主要介绍组件内的状态变量的迁移场景，包含以下场景：

| V1装饰器名                | V2装饰器名                  |
|------------------------|--------------------------|
| [\@State](./arkts-state.md)                 | 无外部初始化：[\@Local](./arkts-new-local.md)<br/>外部初始化一次：[\@Param](./arkts-new-param.md)/[\@Once](./arkts-new-once.md) |
| [\@Prop](./arkts-prop.md)                   | [\@Param](./arkts-new-param.md)                   |
| [\@Link](./arkts-link.md)                  | [\@Param](./arkts-new-param.md)/[\@Event](./arkts-new-event.md)    |
|  [\@ObjectLink](./arkts-observed-and-objectlink.md)           |[\@Param](./arkts-new-param.md)                   |
|  [\@Provide](./arkts-provide-and-consume.md)               |[\@Provider](./arkts-new-provider-and-consumer.md)                | 
| [\@Consume](./arkts-provide-and-consume.md)               |[\@Consumer](./arkts-new-provider-and-consumer.md)                |
| [\@Watch](./arkts-watch.md)               |[\@Monitor](./arkts-new-monitor.md)                |
| 无计算属性相关能力，需要重复计算 | [\@Computed](./arkts-new-computed.md)                |


## 各装饰器迁移示例

### \@State -> \@Local

**迁移规则**

在V1中，\@State装饰器用于装饰组件内部的状态变量，在V2中提供了\@Local作为其替代能力，但两者在观察能力和初始化规则上存在明显差异。针对不同的使用场景，迁移策略如下：

- 简单类型：对于简单类型的变量，可以直接将\@State替换为\@Local。

- 复杂类型：V1中的\@State可以观察复杂对象的第一层属性变化，而V2中的\@Local只能观察对象自身的变化。如果需要追踪对象内部的属性变化，可以结合使用\@ObservedV2和\@Trace。

- 外部初始化：V1中，\@State支持从外部传递初始值；但在V2中，\@Local禁止外部初始化。若需要从外部传递初始值，可以使用\@Param和\@Once装饰器来实现类似的效果。

**示例**

**简单类型**

对于简单类型变量，V1的\@State可以直接替换为V2的\@Local。

V1：

<!-- @[Child1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/StateEasyV1.ets) --> 

``` TypeScript
const INITIAL_VALUE = 10;

@Entry
@Component
struct Child {
  // V1的@State装饰简单类型变量
  @State val: number = INITIAL_VALUE;

  build() {
    Column() {
      Text(this.val.toString())
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}
```

V2迁移策略：直接替换。

<!-- @[Child2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/StateEasyV2.ets) --> 

``` TypeScript
const INITIAL_VALUE = 10;

@Entry
@ComponentV2
struct Child {
  // V2的@Local装饰简单类型变量
  @Local val: number = INITIAL_VALUE;

  build() {
    Column() {
      Text(this.val.toString())
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}
```

示例效果图：

![state-easy](figures/migration-state-easy.png)

**复杂类型**

V1的\@State能够观察复杂对象的第一层属性变化，但V2的\@Local无法观察对象内部变化。为了解决这个问题，需要在类上添加\@ObservedV2，并在需要观察的属性上添加\@Trace。这样，框架就能追踪对象内部的属性变化。

V1：

<!-- @[example1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/StateComplexV1.ets) -->

``` TypeScript
const INITIAL_VALUE = 10;

class Child {
  public value: number = INITIAL_VALUE;
}

@Component
@Entry
struct Example {
  // @State可以观察第一层变化
  @State child: Child = new Child();

  build() {
    Column() {
      Text(this.child.value.toString())
        .fontSize(20)
        .margin(10)
      Button('value+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.child.value++; // 修改对象属性，触发UI刷新
        })
    }
    .width('100%')
  }
}
```

V2迁移策略：使用\@ObservedV2和\@Trace。

<!-- @[example2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/StateComplexV2.ets) -->

``` TypeScript
const INITIAL_VALUE = 10;

@ObservedV2
class Child {
  @Trace public value: number = INITIAL_VALUE;
}

@ComponentV2
@Entry
struct Example {
  // @Local只能观察自身，需要给Child加上@ObservedV2和@Trace
  @Local child: Child = new Child();

  build() {
    Column() {
      Text(this.child.value.toString())
        .fontSize(20)
        .margin(10)
      Button('value+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.child.value++; // 修改对象属性，触发UI刷新
        })
    }
    .width('100%')
  }
}
```

示例效果图：

![state-complex](figures/migration-state-complex.gif)

**外部初始化状态变量**

V1的\@State变量可以从外部初始化，V2的\@Local禁止外部初始化。为实现类似功能，需要用\@Param和\@Once代替\@State，允许外部传入初始值，并确保该值只初始化时同步一次。

V1实现：

<!-- @[Parent5_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/StateExternalInitializationV1.ets) -->

``` TypeScript
@Component
struct Child {
  @State value: number = 0;

  build() {
    Text(this.value.toString())
      .fontSize(20)
      .margin(10)
  }
}

@Entry
@Component
struct Parent {
  build() {
    Column() {
      // @State可以从外部初始化
      Child({ value: 30 })
    }
    .width('100%')
  }
}
```

V2迁移策略：使用\@Param和\@Once。

<!-- @[Parent6_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/StateExternalInitializationV2.ets) -->

``` TypeScript
@ComponentV2
struct Child {
  @Param @Once value: number = 0;

  build() {
    Text(this.value.toString())
      .fontSize(20)
      .margin(10)
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column() {
      // @Local禁止从外部初始化，可以用@Param和@Once替代实现
      Child({ value: 30 })
    }
    .width('100%')
  }
}
```


示例效果图：

![state-external-init](figures/migration-state-external-init.png)

### \@Prop -> \@Param

**迁移规则**

在V1中，\@Prop装饰器用于从父组件传递参数给子组件，这些参数在子组件中可以被直接修改。在V2中，\@Param取代了\@Prop的作用，但\@Param是只读的，子组件不能直接修改参数的值。因此，根据场景的不同，有3种迁移策略：

- 简单类型：对于简单类型的参数，将\@Prop替换为\@Param。

- 复杂类型：如果传递的是复杂对象且需要严格的单向数据绑定，需要深拷贝对象，防止子组件修改父组件的数据。

- 子组件修改变量：如果子组件需要修改传入的参数，使用\@Once允许子组件在本地修改该变量。但需要注意，使用\@Once修饰符后，当前子组件只会被初始化一次，后续无父组件到子组件的同步能力。

**示例**

**简单类型**

对于简单类型变量，V1的\@Prop可以直接替换为V2的\@Param。

V1实现：

<!-- @[Parent9_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropEasyV1.ets) --> 

``` TypeScript
@Component
struct Child {
  // V1的@Prop装饰简单类型变量
  @Prop value: number;

  build() {
    Text(this.value.toString())
      .fontSize(20)
      .margin(10)
  }
}

@Entry
@Component
struct Parent {
  build() {
    Column() {
      Child({ value: 30 })
    }
    .width('100%')
  }
}
```

V2迁移策略：直接替换。

<!-- @[Parent10_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropEasyV2.ets) -->

``` TypeScript
@ComponentV2
struct Child {
  // V2的@Param装饰简单类型变量
  @Param value: number = 0;

  build() {
    Text(this.value.toString())
      .fontSize(20)
      .margin(10)
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column() {
      Child({ value: 30 })
    }
    .width('100%')
  }
}
```

示例效果图：

![prop-easy](figures/migration-prop-easy.png)

**复杂类型的单向数据传递**

在V2中，传递复杂类型时，如果希望实现严格的单向数据绑定，防止子组件修改父组件的数据，需要在使用\@Param传递复杂对象时进行深拷贝以避免传递对象的引用。

V1实现：

<!-- @[Parent11_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropComplexV1.ets) -->

``` TypeScript
const APPLE_INITIAL_COUNT = 5;
const ORANGE_INITIAL_COUNT = 10;

class Fruit {
  public apple: number = APPLE_INITIAL_COUNT;
  public orange: number = ORANGE_INITIAL_COUNT;
}

@Component
struct Child {
  // @Prop传递Fruit类，当子类修改属性，父类不受影响
  @Prop fruit: Fruit;

  build() {
    Column() {
      Text('child apple: ' + this.fruit.apple.toString())
        .fontSize(20)
        .margin(10)
      Text('child orange: ' + this.fruit.orange.toString())
        .fontSize(20)
        .margin(10)
      Button('apple+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.fruit.apple++; // 修改子组件@Prop对象，父组件不受影响
        })
      Button('orange+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.fruit.orange++;
        })
    }
    .width('100%')
  }
}

@Entry
@Component
struct Parent {
  @State parentFruit: Fruit = new Fruit();

  build() {
    Column() {
      Text('parent apple: ' + this.parentFruit.apple.toString())
        .fontSize(20)
        .margin(10)
      Text('parent orange: ' + this.parentFruit.orange.toString())
        .fontSize(20)
        .margin(10)
      Child({ fruit: this.parentFruit })
    }
    .width('100%')
  }
}
```

V2迁移策略：使用深拷贝。

<!-- @[Parent12_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropComplexV2.ets) -->

``` TypeScript
const APPLE_INITIAL_COUNT = 5;
const ORANGE_INITIAL_COUNT = 10;

@ObservedV2
class Fruit {
  @Trace public apple: number = APPLE_INITIAL_COUNT;
  @Trace public orange: number = ORANGE_INITIAL_COUNT;

  // 实现深拷贝，子组件不会修改父组件的数据
  clone(): Fruit {
    let newFruit: Fruit = new Fruit();
    newFruit.apple = this.apple;
    newFruit.orange = this.orange;
    return newFruit;
  }
}

@ComponentV2
struct Child {
  @Param fruit: Fruit = new Fruit();

  build() {
    Column() {
      Text('child apple: ' + this.fruit.apple.toString())
        .fontSize(20)
        .margin(10)
      Text('child orange: ' + this.fruit.orange.toString())
        .fontSize(20)
        .margin(10)
      Button('apple+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.fruit.apple++; // 修改深拷贝对象，父组件不受影响
        })
      Button('orange+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.fruit.orange++;
        })
    }
    .width('100%')
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local parentFruit: Fruit = new Fruit();

  build() {
    Column() {
      Text('parent apple: ' + this.parentFruit.apple.toString())
        .fontSize(20)
        .margin(10)
      Text('parent orange: ' + this.parentFruit.orange.toString())
        .fontSize(20)
        .margin(10)
      Child({ fruit: this.parentFruit.clone() })
    }
    .width('100%')
  }
}
```

示例效果图：

![prop-complex](figures/migration-prop-complex.gif)

**子组件修改变量**

在V1中，子组件可以修改\@Prop的变量，然而在V2中，\@Param是只读的。如果子组件需要修改传入的值，可以使用\@Param和\@Once允许子组件在本地修改。

V1实现：

<!-- @[Parent13_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropSubComponentUpdateVarV1.ets) -->

``` TypeScript
@Component
struct Child {
  // @Prop可以直接修改变量值
  @Prop value: number;

  build() {
    Column() {
      Text(this.value.toString())
        .fontSize(20)
        .margin(10)
      Button('+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.value++; // 本地修改，不会同步回父组件
        })
    }
    .width('100%')
  }
}

@Entry
@Component
struct Parent {
  build() {
    Column() {
      Child({ value: 30 })
    }
    .width('100%')
  }
}
```

V2迁移策略：使用\@Param和\@Once。

<!-- @[Parent14_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropSubComponentUpdateVarV2.ets) -->

``` TypeScript
@ComponentV2
struct Child {
  // @Param搭配@Once使用，可以在本地修改@Param变量
  @Param @Once value: number = 0;

  build() {
    Column() {
      Text(this.value.toString())
        .fontSize(20)
        .margin(10)
      Button('+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.value++; // 本地修改，不会同步回父组件
        })
    }
    .width('100%')
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column() {
      Child({ value: 30 })
    }
    .width('100%')
  }
}
```

示例效果图：

![prop-update-var](figures/migration-prop-update-var.gif)

在V1中，子组件可以修改\@Prop的变量，且只会在本地更新，不会同步回父组件。父组件数据源更新时，会通知子组件更新，并覆写子组件本地\@Prop的值。

V1：

- 改变子组件Child的localValue，不会同步回父组件Parent。
- 父组件更新value，通知子组件Child更新，并覆写本地子组件localValue的值。

<!-- @[Parent15_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropSubComponentUpdateVarLocalV1.ets) -->

``` TypeScript
const PARENT_INITIAL_STATE_VALUE = 10;

@Component
struct Child {
  @Prop localValue: number = 0;

  build() {
    Column() {
      Text(`${this.localValue}`)
        .fontSize(20)
        .margin(10)
      Button('Child +100')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 改变localValue不会传递给父组件Parent
          this.localValue += 100;
        })
    }
    .width('100%')
  }
}

@Entry
@Component
struct Parent {
  @State value: number = PARENT_INITIAL_STATE_VALUE;

  build() {
    Column() {
      Button('Parent +1')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 改变value的值，通知子组件Child value更新
          this.value += 1;
        })
      Child({ localValue: this.value })
    }
    .width('100%')
  }
}
```

V2中，\@Param本地不可写，与\@Once搭配使用时只同步一次。若要实现子组件本地可写，且父组件后续更新仍能通知子组件，可借助\@Monitor实现。

V2实现：

- 父组件Parent更新通知子组件value的刷新，并回调\@Monitor修饰的onValueChange回调方法，onValueChange将更新后的值赋值给localValue。
- 子组件Child改变localValue的值，不会同步给父组件Parent。
- 父组件Parent中再次改变value，将会继续通知给子组件，并覆写子组件本地localValue的值。

<!-- @[Parent16_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/PropSubComponentUpdateVarLocalV2.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';
const DOMAIN = 0xFF00;
const TAG = '[Sample_StateMigration_App]';
const PARENT_INITIAL_LOCAL_VALUE = 10;

@ComponentV2
struct Child {
  @Param value: number = 0;
  @Local localValue: number = this.value;

  @Monitor('value')
  onValueChange(mon: IMonitor) {
    hilog.info(DOMAIN, TAG, `value has been changed from ${mon.value()?.before} to ${mon.value()?.now}`);
    // 父组件value变化时，通知子组件value更新，回调Monitor函数，将更新的值覆写给本地的localValue
    this.localValue = this.value;
  }

  build() {
    Column() {
      Text(`${this.localValue}`)
        .fontSize(20)
        .margin(10)
      Button('Child +100')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 改变localValue不会传递给父组件Parent
          this.localValue += 100;
        })
    }
    .width('100%')
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local value: number = PARENT_INITIAL_LOCAL_VALUE;

  build() {
    Column() {
      Button('Parent +1')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 改变value的值，通知子组件Child value更新
          this.value += 1;
        })
      Child({ value: this.value })
    }
    .width('100%')
  }
}
```


示例效果图：

![prop-update-var-local](figures/migration-prop-update-var-local.gif)

### \@Link -> \@Param/\@Event

**迁移规则**

在V1中，\@Link允许父组件和子组件之间进行双向数据绑定。迁移到V2时，可以用\@Param和\@Event模拟双向同步。\@Param实现父到子的单向传递，子组件再通过\@Event回调函数触发父组件的状态更新。

**示例**

V1实现：

<!-- @[Parent7_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/LinkMiigrationV1.ets) -->

``` TypeScript
const INITIAL_MYVAL = 10;

@Component
struct Child {
  // @Link可以双向同步数据
  @Link val: number;

  build() {
    Column() {
      Text('child: ' + this.val.toString())
        .fontSize(20)
        .margin(10)
      Button('+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.val++; // 子组件修改val，父子组件同步刷新
        })
    }
    .width('100%')
  }
}

@Entry
@Component
struct Parent {
  @State myVal: number = INITIAL_MYVAL;

  build() {
    Column() {
      Text('parent: ' + this.myVal.toString())
        .fontSize(20)
        .margin(10)
      Child({ val: this.myVal }) // 通过@Link建立父子双向同步
    }
    .width('100%')
  }
}
```

V2迁移策略：使用\@Param和\@Event。

<!-- @[Parent8_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/LinkMiigrationV2.ets) -->

``` TypeScript
const INITIAL_MYVAL = 10;

@ComponentV2
struct Child {
  // @Param搭配@Event回调实现数据双向同步
  @Param val: number = 0;
  @Event addOne: () => void;

  build() {
    Column() {
      Text('child: ' + this.val.toString())
        .fontSize(20)
        .margin(10)
      Button('+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.addOne(); // 通过@Event回调通知父组件更新
        })
    }
    .width('100%')
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local myVal: number = INITIAL_MYVAL;

  build() {
    Column() {
      Text('parent: ' + this.myVal.toString())
        .fontSize(20)
        .margin(10)
      Child({ val: this.myVal, addOne: () => this.myVal++ }) // @Param传递数据，@Event传递回调，实现双向同步
    }
    .width('100%')
  }
}
```


示例效果图：

![link](figures/migration-link.gif)

### \@ObjectLink -> \@Param

**迁移规则**

在V1中，\@ObjectLink用于接收父组件传递的\@Observed装饰的类对象，实现嵌套对象的同步。父组件整体赋值会单向同步给子组件，子组件不允许整体赋值，但可以修改对象属性，属性变化在父子组件间双向同步。

迁移到V2时，子组件使用\@Param接收对象，同步行为与\@ObjectLink一致。

**示例**

V1实现：

<!-- @[Parent23_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ObjectLinkMigrationV1.ets) -->

``` TypeScript
@Observed
class Person {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

@Component
struct Child {
  // @ObjectLink接收@Observed装饰的类对象，属性变化双向同步
  @ObjectLink person: Person;

  build() {
    Column() {
      Text(`Child name: ${this.person.name}`)
        .fontSize(20)
        .margin(10)
      Text(`Child age: ${this.person.age}`)
        .fontSize(20)
        .margin(10)
      Button('age+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.person.age++; // 子组件修改对象属性，父子组件同步刷新
        })
    }
    .width('100%')
  }
}

@Entry
@Component
struct Parent {
  @State person: Person = new Person('Alice', 20);

  build() {
    Column() {
      Text(`Parent name: ${this.person.name}`)
        .fontSize(20)
        .margin(10)
      Text(`Parent age: ${this.person.age}`)
        .fontSize(20)
        .margin(10)
      Child({ person: this.person }) // 传递对象给子组件
    }
    .width('100%')
  }
}
```

V2迁移策略：使用\@Param接收对象。

<!-- @[Parent24_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ObjectLinkMigrationV2.ets) -->

``` TypeScript
@ObservedV2
class Person {
  @Trace public name: string;
  @Trace public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

@ComponentV2
struct Child {
  // @Param接收类对象，属性变化双向同步
  @Param person: Person = new Person('', 0);

  build() {
    Column() {
      Text(`Child name: ${this.person.name}`)
        .fontSize(20)
        .margin(10)
      Text(`Child age: ${this.person.age}`)
        .fontSize(20)
        .margin(10)
      Button('age+1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.person.age++; // 子组件修改对象属性，父子组件同步刷新
        })
    }
    .width('100%')
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local person: Person = new Person('Alice', 20);

  build() {
    Column() {
      Text(`Parent name: ${this.person.name}`)
        .fontSize(20)
        .margin(10)
      Text(`Parent age: ${this.person.age}`)
        .fontSize(20)
        .margin(10)
      Child({ person: this.person }) // 传递对象给子组件
    }
    .width('100%')
  }
}
```


示例效果图：

![objectlink](figures/migration-objectlink.gif)

### \@Provide/\@Consume -> \@Provider/\@Consumer

**迁移规则**

V1的\@Provide和\@Consume与V2的\@Provider和\@Consumer定位和作用类似，基本可以实现丝滑替换，但存在以下细微差异，开发者可根据自己代码实现情况参考是否需要调整：

在V1中，\@Provide和\@Consume用于父子组件之间的数据共享，可以通过alias（别名）或属性名匹配，同时\@Consume依赖父组件的\@Provide，API version 20以前不允许本地初始化。V2中，\@Provider和\@Consumer增强了这些特性，使数据共享更加灵活。根据不同的场景，有以下迁移策略：

- V1中\@Provide和\@Consume在没有指定alias的情况下，可以直接使用。V2中\@Provider和\@Consumer是标准装饰器，且参数可选，所以不管有无指定alias后面需要必须跟随“()”。

- alias和属性名匹配规则：V1中，\@Provide和\@Consume可以通过alias或属性名匹配；V2中，alias是唯一的匹配key，指定alias后只能通过alias匹配。

- 本地初始化支持：API version 20以前，\@Consume不允许本地初始化，必须依赖父组件；从API version 20开始，\@Consume支持本地初始化，当找不到对应的\@Provide时使用本地默认值，详见[@Consume装饰的变量支持设置默认值](./arkts-provide-and-consume.md#consume装饰的变量支持设置默认值)；V2中，\@Consumer支持本地初始化，当找不到对应的\@Provider时使用本地默认值。

- 从父组件初始化：V1中，\@Provide可以直接从父组件初始化；V2中，\@Provider不支持外部初始化，需用\@Param和\@Once接受初始值并赋给\@Provider。

- 重载支持：V1中，\@Provide默认不支持重载，需设置 allowOverride；V2中，\@Provider默认支持重载，\@Consumer会向上查找最近的\@Provider。

**示例**

**alias和属性名匹配规则**

在V1中，\@Provide和\@Consume的匹配既可以通过alias，也可以通过属性名。在V2中，alias成为唯一的key，如果在\@Consumer中制定了alias，只能通过alias而非属性名进行匹配。

V1实现：

<!-- @[Parent17_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideAliasV1.ets) -->

``` TypeScript
@Component
struct Child {
  // alias和属性名都为key，alias和属性名都可以匹配
  @Consume('text') childMessage: string;
  @Consume message: string;

  build() {
    Column() {
      Text(this.childMessage)
        .fontSize(20)
        .margin(10)
      Text(this.message)
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}

@Entry
@Component
struct Parent {
  @Provide('text') message: string = 'Hello World';

  build() {
    Column() {
      Child()
    }
    .width('100%')
  }
}
```

V2迁移策略：确保alias一致，没有指定alias的情况下，依赖属性名进行匹配。

<!-- @[Parent18_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideAliasV2.ets) -->

``` TypeScript
@ComponentV2
struct Child {
  @Consumer('text') childMessage: string = 'default'; // 指定alias时，通过alias匹配
  @Consumer() message: string = 'default'; // 未指定alias时，通过属性名匹配

  build() {
    Column() {
      Text(this.childMessage)
        .fontSize(20)
        .margin(10)
      Text(this.message)
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}

@Entry
@ComponentV2
struct Parent {
  @Provider('text') parentMessage: string = 'Hello World';
  @Provider() message: string = 'Hello World';

  build() {
    Column() {
      Child()
    }
    .width('100%')
  }
}
```

示例效果图：

![provide-alias](figures/migration-provide-alias.png)

**V1的\@Consume不支持本地初始化，V2支持**

V1中，API version 20之前，\@Consume不允许本地初始化变量，必须依赖父组件的\@Provide，否则会抛出异常。迁移到V2后，\@Consumer允许本地初始化，当找不到对应的\@Provider，会使用本地默认值。

V1实现：

<!-- @[Parent19_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideConsumeNoInitV1.ets) -->

``` TypeScript
@Component
struct Child {
  // @Consume禁止本地初始化，当找不到对应的@Provide时抛出异常
  @Consume message: string;

  build() {
    Text(this.message)
      .fontSize(20)
      .margin(10)
  }
}

@Entry
@Component
struct Parent {
  @Provide message: string = 'Hello World';

  build() {
    Column() {
      Child()
    }
    .width('100%')
  }
}
```

V2迁移策略：\@Consumer可以本地初始化。

<!-- @[Parent20_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideConsumeInitV2.ets) -->

``` TypeScript
@ComponentV2
struct Child {
  // @Consumer允许本地初始化，当找不到@Provider的时候使用本地默认值
  @Consumer() message: string = 'Hello World';

  build() {
    Text(this.message)
      .fontSize(20)
      .margin(10)
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column() {
      Child()
    }
    .width('100%')
  }
}
```

示例效果图：

![provide-no-init](figures/migration-provide-no-init.png)

**V1的\@Provide可以从父组件初始化，V2不支持**

在V1中，\@Provide允许从父组件初始化，可以直接通过组件参数传递初始值。在V2中，\@Provider禁止从外部初始化。为实现相同功能，可以在子组件中使用\@Param \@Once接受初始值，然后将其赋值给\@Provider变量。

V1实现：

<!-- @[Parent21_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideParentInitV1.ets) -->

``` TypeScript
const STATE_INITIAL_PARENT_VALUE = 42;

@Entry
@Component
struct Parent {
  @State parentValue: number = STATE_INITIAL_PARENT_VALUE;

  build() {
    Column() {
      // @Provide可以从父组件初始化
      Child({ childValue: this.parentValue })
    }
    .width('100%')
  }
}

@Component
struct Child {
  @Provide childValue: number = 0;

  build() {
    Column() {
      Text(this.childValue.toString())
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}
```

V2迁移策略：使用\@Param接受初始值，再赋值给\@Provider。

<!-- @[Parent22_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideParentNoInitV2.ets) -->

``` TypeScript
const LOCAL_INITIAL_PARENT_VALUE = 42;

@Entry
@ComponentV2
struct Parent {
  @Local parentValue: number = LOCAL_INITIAL_PARENT_VALUE;

  build() {
    Column() {
      // @Provider禁止从父组件初始化，替代方案为先用@Param接受，再赋值给@Provider
      Child({ initialValue: this.parentValue })
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Param @Once initialValue: number = 0;
  @Provider() childValue: number = this.initialValue;

  build() {
    Column() {
      Text(this.childValue.toString())
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}
```

示例效果图：

![provide-parent-init](figures/migration-provide-parent-init.png)

**V1的\@Provide默认不支持重载，V2默认支持**

在V1中，\@Provide默认不支持重载，无法覆盖上层组件的同名\@Provide。若需支持重载，必须设置allowOverride。在V2中，\@Provider默认支持重载，\@Consumer会向上查找最近的\@Provider，无需额外设置。

V1实现：

<!-- @[GrandParent1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideNoAllowOverrideV1.ets) --> 

``` TypeScript
const GRANDPARENT_REVIEW_VOTES_INITIAL = 40;
const PARENT_REVIEW_VOTES_INITIAL = 20;

@Entry
@Component
struct GrandParent {
  @Provide('reviewVotes') reviewVotes: number = GRANDPARENT_REVIEW_VOTES_INITIAL;

  build() {
    Column() {
      Parent()
    }
    .width('100%')
  }
}

@Component
struct Parent {
  // @Provide默认不支持重载，支持重载需设置allowOverride选项
  @Provide({ allowOverride: 'reviewVotes' }) reviewVotes: number = PARENT_REVIEW_VOTES_INITIAL;

  build() {
    Child()
  }
}

@Component
struct Child {
  @Consume('reviewVotes') reviewVotes: number;

  build() {
    Text(this.reviewVotes.toString())
      .fontSize(20)
      .margin(10)
  }
}
```

V2迁移策略：取消allowOverride设置。

<!-- @[GrandParent2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ProvideAllowOverrideV2.ets) -->

``` TypeScript
const GRANDPARENT_REVIEW_VOTES_INITIAL = 40;
const PARENT_REVIEW_VOTES_INITIAL = 20;

@Entry
@ComponentV2
struct GrandParent {
  @Provider('reviewVotes') reviewVotes: number = GRANDPARENT_REVIEW_VOTES_INITIAL;

  build() {
    Column() {
      Parent()
    }
    .width('100%')
  }
}

@ComponentV2
struct Parent {
  // @Provider默认支持重载，@Consumer向上查找最近的@Provider
  @Provider() reviewVotes: number = PARENT_REVIEW_VOTES_INITIAL;

  build() {
    Child()
  }
}

@ComponentV2
struct Child {
  @Consumer() reviewVotes: number = 0;

  build() {
    Text(this.reviewVotes.toString())
      .fontSize(20)
      .margin(10)
  }
}
```


示例效果图：

![provide-override](figures/migration-provide-override.png)

### \@Watch -> \@Monitor

**迁移规则**

在V1中，\@Watch用于监听状态变量的变化，并在变量变化时触发指定回调函数。在V2中，\@Monitor替代了\@Watch，可以更灵活地监听变量的变化，并获取变量变化前后的值。具体的迁移策略如下：

- 单变量监听：对于简单的场景，可以直接用\@Monitor替换\@Watch，效果一致。

- 多变量监听：V1的\@Watch无法获取变化前的值。在V2中，\@Monitor支持同时监听多个变量，并可以访问变量变化前后的状态。

**示例**

**单变量监听**

对于简单案例，V1的\@Watch可以直接替换为V2的\@Monitor。

V1实现：

<!-- @[WatchExample1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/WatchSingleVarV1.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0xFF00;
const TAG = '[Sample_StateMigration_App]';

@Entry
@Component
struct WatchExample {
  @State @Watch('onAppleChange') apple: number = 0;

  onAppleChange(): void {
    hilog.info(DOMAIN, TAG, 'apple count changed to ' + this.apple);
  }

  build() {
    Column() {
      Text(`apple count: ${this.apple}`)
        .fontSize(20)
        .margin(10)
      // 点击Button累加apple，触发UI刷新
      Button('add apple')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.apple++;
        })
    }
    .width('100%')
  }
}
```

V2迁移策略：直接替换。

<!-- @[MonitorExample1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/WatchSingleVarV2.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0xFF00;
const TAG = '[Sample_StateMigration_App]';

@Entry
@ComponentV2
struct MonitorExample {
  @Local apple: number = 0;

  @Monitor('apple')
  onFruitChange(monitor: IMonitor) {
    hilog.info(DOMAIN, TAG, `apple changed from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column() {
      Text(`apple count: ${this.apple}`)
        .fontSize(20)
        .margin(10)
      // 点击Button累加apple，触发UI刷新
      Button('add apple')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.apple++;
        })
    }
    .width('100%')
  }
}
```

示例效果图：

![watch-single](figures/migration-watch-single.gif)

**多变量监听**

在V1中，每个\@Watch回调函数只能监听一个变量，且无法获取变化前的值。迁移到V2后，可以使用一个\@Monitor同时监听多个变量，并获取监听变量变化前后的值。

V1实现：

<!-- @[WatchExample2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/WatchMoreVarV1.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0xFF00;
const TAG = '[Sample_StateMigration_App]';

@Entry
@Component
struct WatchExample {
  @State @Watch('onAppleChange') apple: number = 0;
  @State @Watch('onOrangeChange') orange: number = 0;

  // @Watch回调，只能监听单个变量，不能获取变化前的值
  onAppleChange(): void {
    hilog.info(DOMAIN, TAG, 'apple count changed to ' + this.apple);
  }

  onOrangeChange(): void {
    hilog.info(DOMAIN, TAG, 'orange count changed to ' + this.orange);
  }

  build() {
    Column() {
      Text(`apple count: ${this.apple}`)
        .fontSize(20)
        .margin(10)
      Text(`orange count: ${this.orange}`)
        .fontSize(20)
        .margin(10)
      Button('add apple')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.apple++; // 点击触发onAppleChange回调
        })
      Button('add orange')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.orange++; // 点击触发onOrangeChange回调
        })
    }
    .width('100%')
  }
}

```

V2迁移策略：同时监听多个变量，以及获取变化前的值。

<!-- @[MonitorExample2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/WatchMoreVarV2.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0xFF00;
const TAG = '[Sample_StateMigration_App]';

@Entry
@ComponentV2
struct MonitorExample {
  @Local apple: number = 0;
  @Local orange: number = 0;

  // @Monitor回调，支持监听多个变量，可以获取变化前的值
  @Monitor('apple','orange')
  onFruitChange(monitor: IMonitor) {
    monitor.dirty.forEach((name: string) => {
      hilog.info(DOMAIN, TAG, `${name} changed from ${monitor.value(name)?.before} to ${monitor.value(name)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`apple count: ${this.apple}`)
        .fontSize(20)
        .margin(10)
      Text(`orange count: ${this.orange}`)
        .fontSize(20)
        .margin(10)
      Button('add apple')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.apple++; // 点击触发onFruitChange回调
        })
      Button('add orange')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.orange++; // 点击触发onFruitChange回调
        })
    }
    .width('100%')
  }
}
```


示例效果图：

![watch-multi](figures/migration-watch-multi.gif)

### 重复计算 -> \@Computed计算属性

**迁移规则**

V1中并没有提供计算属性的概念，所以对于UI中的冗余计算，并没有办法可以减少重复计算。V2针对该场景，提供了\@Computed装饰器，可以帮助开发者减少重复计算。

V1：

在下面的示例中，每次改变lastName都会触发Text组件的刷新，每次Text组件的刷新，都需要重复计算this.lastName + ' ' + this.firstName。

<!-- @[ComputedV1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ComputedV1.ets) -->

``` TypeScript
@Entry
@Component
struct Index {
  @State firstName: string = 'Li';
  @State lastName: string = 'Hua';

  build() {
    Column() {
      Text(this.firstName + ' ' + this.lastName)
        .fontSize(20)
        .margin(10)
      Text(this.firstName + ' ' + this.lastName)
        .fontSize(20)
        .margin(10)
      // 每次改变lastName都会触发Text组件的刷新
      Button('changed lastName')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.lastName += 'a';
        })
    }
    .width('100%')
  }
}
```

V2:

使用V2中的\@Computed，每次改变lastName仅会触发一次计算。

<!-- @[ComputedV2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateMigrationProject/entry/src/main/ets/pages/componentstatemigration/ComputedV2.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct Index {
  @Local firstName: string = 'Li';
  @Local lastName: string = 'Hua';

  @Computed
  get fullName() {
    // 每次改变lastName仅会触发一次计算
    return this.firstName + ' ' + this.lastName;
  }

  build() {
    Column() {
      Text(this.fullName)
        .fontSize(20)
        .margin(10)
      Text(this.fullName)
        .fontSize(20)
        .margin(10)
      Button('changed lastName')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.lastName += 'a';
        })
    }
    .width('100%')
  }
}
```


示例效果图：

![computed](figures/migration-computed.gif)

### 双向绑定由$$迁移!!

状态管理V1中，推荐使用[$$](./arkts-two-way-sync.md)实现系统组件的双向绑定；在状态管理V2中，推荐使用[!!](./arkts-new-binding.md)语法糖统一处理双向绑定。

> **说明：**
> 
> !!语法从API version 12开始支持。

**迁移策略**

对于系统组件参数，V1的$$直接替换为V2的!!。

V1实现：

<!-- @[Migration_Sync_Dollar_Dollar](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/migrationDataObjectVariables/MigrationSyncDollarDollar.ets) -->

``` TypeScript
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  controller: TextInputController = new TextInputController();

  build() {
    Column({ space: 20 }) {
      Text(this.text)
        .fontSize(20)
        .margin(10)
      // $$运算符为系统组件提供TS变量的引用，使得TS变量和系统组件的内部状态保持同步
      TextInput({ text: $$this.text, placeholder: 'input your word...', controller: this.controller })
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .caretColor(Color.Blue)
        .width(300)
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

V2迁移策略：装饰器修改为V2的同时，$$直接替换为!!。

<!-- @[sync_state_manager_!!](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/syncStateManager/SyncUsageExampleV2.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct TextInputExampleV2 {
  @Local text: string = '';
  controller: TextInputController = new TextInputController();

  build() {
    Column({ space: 20 }) {
      Text(this.text)
        .fontSize(20)
        .margin(10)
      // V2中直接用!!替换$$
      TextInput({ text: this.text!!, placeholder: 'input your word...', controller: this.controller })
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .caretColor(Color.Blue)
        .width(300)
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

示例效果图：

![sync](figures/migration-sync.gif)