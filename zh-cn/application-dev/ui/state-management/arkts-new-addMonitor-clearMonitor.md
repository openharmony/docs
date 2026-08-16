# addMonitor/clearMonitor接口：动态添加/取消监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了动态添加或删除状态管理V2的状态变量的监听函数，开发者可以使用[addMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#addmonitor20)或[clearMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#clearmonitor20)。

在阅读本文档前，建议提前阅读：[\@ObservedV2/\@Trace](./arkts-new-observedV2-and-trace.md)、[\@Monitor](./arkts-new-monitor.md)。

>**说明：**
>
>从API version 20开始，开发者可以使用UIUtils中的addMonitor/clearMonitor接口动态给状态管理V2的状态变量添加或删除监听函数。


## 概述
装饰器[\@Monitor](./arkts-new-monitor.md)如果声明在[\@ObservedV2](./arkts-new-observedV2-and-trace.md)和[\@ComponentV2](./arkts-create-custom-components.md#componentv2)中，会使得开发者构造出的所有的\@ObservedV2和\@ComponentV2的实例，都默认有同样的\@Monitor的监听回调，且无法取消或删除对应的监听回调。

如果开发者希望动态给\@ObservedV2和\@ComponentV2实例添加或者删除监听函数，则可以使用[addMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#addmonitor20)和[clearMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#clearmonitor20)接口。

- 使用addMonitor/clearMonitor接口需要导入UIUtils工具。

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```
- 仅支持监听状态管理V2的状态变量的变化。

- clearMonitor仅可以删除addMonitor添加的监听函数，无法删除\@Monitor的监听函数。

## 使用规则
- addMonitor/clearMonitor可以传入数组一次性给多个状态变量添加或删除回调函数。
```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;
  @Trace name: string = 'Jack';

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, ['age', 'name'], this.onChange1);
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  build() {
    Column() {
      Text(`User name ${this.user.name}`)
        .fontSize(20)
        .onClick(() => {
          // 改变name，回调onChange1监听函数
          this.user.name += '!';
        })
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age自增，回调onChange1监听函数
          this.user.age++;
        })
      Button('clear name and age monitor fun')
        .onClick(() => {
          // 删除age和name的onChange1监听函数
          // 再次点击Text组件改变name和age，无监听函数回调
          UIUtils.clearMonitor(this.user, ['age', 'name'], this.user.onChange1);
        })
    }
  }
}
```
- addMonitor可以给path对应的状态变量添加多个监听函数，但是需要注意，如果开发者添加同名的监听函数，则会添加失败，打印错误日志。
```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  onChange2(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange2: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    // 正确用法，给age注册监听函数onChange1
    UIUtils.addMonitor(this, 'age', this.onChange1);
    // 正确用法，给age注册监听函数onChange2
    UIUtils.addMonitor(this, 'age', this.onChange2);
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1 in View: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear(): void {
    // 错误用法，已经给age注册过方法名为onChange1的函数，无法重复注册相同函数名的监听函数
    // 打印错误日志提示添加失败：FIX THIS APPLICATION ERROR: AddMonitor 'onChange1' owned by 'User' path: 'age' - failed when adding duplicate path
    UIUtils.addMonitor(this.user, 'age', this.onChange1);
  }

  build() {
    Column() {
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age自增，回调User中的onChange1和onChange2方法
          this.user.age++;
        })
    }
  }
}
```
- addMonitor设置[isSynchronous](../../reference/apis-arkui/js-apis-stateManagement.md#monitoroptions20)仅第一次有效，即其不能被更改，如果开发者更改`isSynchronous`，则会打印错误日志。
```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    // 正确用法，给age注册监听函数onChange1，没有设置options默认为异步监听回调
    UIUtils.addMonitor(this, 'age', this.onChange1);
    // 错误用法，不能改变this.onChange1的监听回调的方式
    // 打印错误日志提示： FIX THIS APPLICATION ERROR: addMonitor failed, current function onChange1 has already register as async, cannot change to sync anymore
    UIUtils.addMonitor(this, 'age', this.onChange1, { isSynchronous: true });
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  build() {
    Column() {
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age自增，回调onChange1，回调方式为异步回调
          // 监听回调的日志：onChange1: User property age change from 0 to 2
          this.user.age++;
          this.user.age++;
        })
    }
  }
}
```
- clearMonitor可以删除path对应的状态变量的监听函数，开发者可以通过传入监听回调函数来指定删除具体的监听函数，也可以不指定具体的监听函数，删除当前path对应状态变量的所有监听回调函数。

  需要注意：当调用clearMonitor时，如果发现当前回调函数没有在path对应的状态变量上注册过，或者当前状态变量没有任何监听函数，都会打印告警日志提示开发者删除失败。

  监听函数被删除后，状态变量的改变不会再回调对应的监听函数。
```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;
  @Trace name: string = 'Jack';

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  onChange2(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange2: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  onChange3(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange3: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, 'age', this.onChange1);
    UIUtils.addMonitor(this, 'age', this.onChange2);
    UIUtils.addMonitor(this, 'age', this.onChange3);
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  build() {
    Column() {
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // step1：点击age，回调onChange1，onChange2，onChange3
          this.user.age++;
        })
      Button('clear age onChange1').onClick(() => {
        // step2：第一次点击该Button。删除onChange1，删除成功。此时点击User age，仅会回调onChange2，onChange3
        // step3：再次点击该Button。再次删除onChange1，onChange1已经被删除，此次删除失败
        // 打印错误日志：FIX THIS APPLICATION ERROR: cannot clear path age for onChange1 because it was never registered with addMonitor
        UIUtils.clearMonitor(this.user, 'age', this.user.onChange1);
      })
      Button('clear age monitors').onClick(() => {
        // step4：删除age所有添加的监听函数。再次点击User age，无监听函数回调
        UIUtils.clearMonitor(this.user, 'age');
      })
      Button('clear name monitors').onClick(() => {
        // step5：删除name添加的监听方法。因为name无任何监听回调，删除失败
        // 打印错误日志：FIX THIS APPLICATION ERROR: cannot clear path name for current target User because no Monitor function for this path was registered
        UIUtils.clearMonitor(this.user, 'name');
      })
    }
  }
}
```

## 限制条件
- addMonitor/clearMonitor仅支持对\@ComponentV2和\@ObservedV2装饰（至少有一个\@Trace装饰的变量）的实例添加/取消回调，否则会有运行时报错，错误码为130000。

  下面为addMonitor的例子，clearMonitor同理。
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  
  @ObservedV2
  class A {
    @Trace a: number = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // 正确用法
      UIUtils.addMonitor(this, 'a', this.onChange);
    }
  }
  
  @Observed
  class B {
    @Track b: number = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`B property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // 目标对象非法入参，当前this为@Observed装饰的对象
      // Error code: 130000
      UIUtils.addMonitor(this, 'b', this.onChange);
    }
  }
  
  class C {
    @Track c: number = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`C property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // 错误用法：目标对象非法入参，当前this为普通class
      // Error code: 130000
      UIUtils.addMonitor(this, 'c', this.onChange);
      // 错误用法：目标对象非法入参undefined
      // Error code: 130000
      UIUtils.addMonitor(undefined, 'c', this.onChange);
    }
  }
  
  let a: A = new A();
  let b: B = new B();
  let c: C = new C();
  ```
- addMonitor/clearMonitor观察路径必须为string或者为数组，如果开发者传入不支持的类型，则会有运行时报错，错误码为130001。

  下面为addMonitor的例子，clearMonitor同理。
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  
  @ObservedV2
  class A {
    @Trace a: number = 0;
    @Trace b: number = 0;
    invalidPath: number | string = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to   ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // 正确用法
      UIUtils.addMonitor(this, 'a', this.onChange);
      // 正确用法
      UIUtils.addMonitor(this, ['a', 'b'], this.onChange);
      // 错误用法，path必须为string或数组，会发生运行时校验，错误码为130001
      UIUtils.addMonitor(this, this.invalidPath as string, this.onChange);
      // 错误用法，path必须为string或数组，会发生运行时校验，错误码为130001
      UIUtils.addMonitor(this, undefined, this.onChange);
    }
  }
  
  let a: A = new A();
  ```
- addMonitor的回调函数必须存在，类型必须为方法类型，且不能为匿名函数，如果开发者传入不支持的类型，则会有运行时报错，错误码为130002。

  clearMonitor开发者可以不设置回调函数，如果设置了，其类型必须为function类型，且不能为匿名函数。
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  
  @ObservedV2
  class A {
    @Trace a: number = 0;
    @Trace b: number = 0;
    invalidFunc: Function | number = 0;
  
    onChange1(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to   ${mon.value(path)?.now}`);
      });
    }
  
    onChange2(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to   ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // 正确用法，给变量a添加函数onChange1
      UIUtils.addMonitor(this, 'a', this.onChange1);
      // 正确用法，给变量a添加函数onChange2
      UIUtils.addMonitor(this, 'a', this.onChange2);
      // 正确用法，给变量b添加函数onChange1
      UIUtils.addMonitor(this, 'b', this.onChange1);
      // 错误用法。传入的回调函数为非function类型，错误码130002
      UIUtils.addMonitor(this, 'a', undefined);
      // 错误用法，传入的回调函数为匿名函数，错误码130002
      UIUtils.addMonitor(this, 'a', (mon: IMonitor) => {});
      // 错误用法，绕过编译器检查，传入的回调函数为非Function类型，错误码130002
      UIUtils.addMonitor(this, 'a', this.invalidFunc as (mon: IMonitor) => void);
    }
  }
  
  let a: A = new A();
  // 正确用法，删除a注册的监听函数onChange1
  UIUtils.clearMonitor(a, 'a', a.onChange1);
  // 正确用法，删除a所有的监听函数
  UIUtils.clearMonitor(a, 'a');
  // 正确用法。等于不传参数，删除a所有的监听函数
  UIUtils.clearMonitor(a, 'a', undefined);
  // 错误用法，传入的回调函数为匿名函数，错误码130002
  UIUtils.clearMonitor(a, 'a', (mon: IMonitor) => {});
  ```

## addMonitor监听变化的规则
addMonitor和装饰器[\@Monitor](./arkts-new-monitor.md)监听变化的主要规则大体保持一致，对比如下表：

|  场景 | addMonitor| @Monitor  |
|------|----|------|
| [监听\@ObservedV2类中@Trace修饰属性的变化](#监听observedv2类中trace修饰属性和componentv2组件中状态变量的变化)   | 支持 | 支持 |
| [监听\@ComponentV2组件中状态变量的变化](#监听observedv2类中trace修饰属性和componentv2组件中状态变量的变化) | 支持 | 支持 |
| [监听数组类型状态变量的下标和length的变化](#监听数组类型状态变量的下标和length的变化)  | 支持 | 支持 |
| [监听内置类型状态变量API调用](#监听内置类型状态变量api调用) | 默认不支持，从API版本26.0.0开始，可通过配置项支持 | 默认不支持，从API版本26.0.0开始，可通过配置项支持 |
| [独立监听path变化](#独立监听path) | 支持 | 默认不支持，从API版本26.0.0开始，可通过配置项支持 |
| [监听变量从可访问到不可访问和从不可访问到可访问](#监听变量从可访问到不可访问和从不可访问到可访问)  | 支持 | 默认不支持，从API版本26.0.0开始，可通过配置项支持 |
| [配置同步监听函数](#配置同步监听函数)  | 支持 | 不支持 |
| [监听构造函数中同步修改的状态变量的变化](#监听构造函数中同步修改的状态变量的变化)  | 支持 | 不支持 |
| [动态取消@ObservedV2/@ComponentV2实例的监听](#动态取消observedv2componentv2实例的监听)  | 支持 | 不支持 |
| [使用包含通配符的路径](#使用包含通配符的路径) | 默认不支持，从API版本26.0.0开始，可通过配置项支持 | 默认不支持，从API版本26.0.0开始，可通过配置项支持 |

## 使用场景
### 监听\@ObservedV2类中@Trace修饰属性和\@ComponentV2组件中状态变量的变化

在下面的例子中：
- 在User的构造函数中添加对`age`和`name`的监听函数`onChange`。
- 在自定义组件`Page`的`aboutToAppear`的生命周期中，添加对`user`的监听函数`onChangeInView`。
- 点击```Text(`User name ${this.user.name}`)```，改变`name`的值，触发`onChange`方法。
- 点击```Text(`User age ${this.user.age}`)```，改变`age`的值，触发`onChange`方法。
- 点击```Text(`reset User`)```，对`user`整体赋值，触发`onChangeInView`方法。
```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;
  @Trace name: string = 'Jack';

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, ['age', 'name'], this.onChange);
  }
}

@Entry
@ComponentV2
struct Page {
  @Local user: User = new User();

  onChangeInView(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange in View: View property ${path} change from ${JSON.stringify(mon.value(path)?.before)} to ${JSON.stringify(mon.value(path)?.now)}`);
    });
  }

  aboutToAppear(): void {
    UIUtils.addMonitor(this, 'user', this.onChangeInView);
  }

  build() {
    Column() {
      Text(`User name ${this.user.name}`)
        .fontSize(20)
        .onClick(() => {
          // 改变name，回调onChange监听函数
          this.user.name += '!';
        })
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age自增，回调onChange监听函数
          this.user.age++;
        })
      Text(`reset User`)
        .fontSize(20)
        .onClick(() => {
          // user整体赋值，回调onChangeInView监听函数
          this.user = new User();
        })
    }
  }
}
```

### 监听数组类型状态变量的下标和length的变化

下面的例子展示了对Array数组下标和length的监听。
```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Page {
  @Local arr: string[] = ['a', 'b', 'c']

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: View property ${path} change from ${JSON.stringify(mon.value(path)?.before)} to ${JSON.stringify(mon.value(path)?.now)}`);
    });
  }

  aboutToAppear(): void {
    // 添加对数组index为0,1,2和数组length的监听回调onChange
    UIUtils.addMonitor(this, ['arr.0', 'arr.1', 'arr.2', 'arr.length'], this.onChange);
  }

  build() {
    Column() {
      Text(`len ${this.arr.length}`).fontSize(20)
      Text(`${this.arr[0]}`).fontSize(20).onClick(() => {
        // 改变数组index为0的数组项
        // onChange回调：onChange: View property arr.0 change from "a" to "az"
        this.arr[0] += 'z';
      })
      Text(`${this.arr[1]}`).fontSize(20).onClick(() => {
        // 改变数组index为1的数组项
        // onChange回调：onChange: View property arr.1 change from "b" to "bz"
        this.arr[1] += 'z';
      })
      Text(`${this.arr[2]}`).fontSize(20).onClick(() => {
        // 改变数组index为2的数组项
        // onChange回调：onChange: View property arr.2 change from "c" to "cz"
        this.arr[2] += 'z';
      })
      Text(`push`).fontSize(20).onClick(() => {
        // 在数组末尾push新数组项'd'，其index为3，index为3没有被监听
        // 数组长度改变，length被监听
        // onChange回调：onChange: View property arr.length change from 3 to 4
        this.arr.push('d');
      })
      Text(`shift`).fontSize(20).onClick(() => {
        // 删除数组第一个元素
        // 0: az -> bz
        // 1: bz -> cz
        // 2: cz -> d
        // length: 4 -> 3
        // onChange回调：
        // onChange: View property arr.0 change from "az" to "bz"
        // onChange: View property arr.1 change from "bz" to "cz"
        // onChange: View property arr.2 change from "cz" to "d"
        // onChange: View property arr.length change from 4 to 3
        this.arr.shift();
      })
    }
  }
}
```

### 独立监听Path
\@Monitor没有对path独立监听，所以需要依赖开发者正确传入\@Monitor入参，[传入非状态变量时会造成被连带监听的情况](./arkts-new-monitor.md#正确设置monitor入参)。

对于addMonitor，对不同path采取了独立监听的机制，如下面的例子，点击`Button('change age&name')`，会输出以下日志：
``` ts
property path:age change from 24 to 25
```

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class Info {
  name: string = 'John';
  @Trace age: number = 24;

  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, ['age', 'name'], this.onPropertyChange);
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

### 监听变量从可访问到不可访问和从不可访问到可访问
[\@Monitor不会记录状态变量不可访问时的状态](./arkts-new-monitor.md#无法监听变量从可访问变为不可访问和从不可访问变为可访问)，所以其无法监听变量从可访问到不可访问和从不可访问到可访问。

addMonitor会记录变量不可访问的状态，所以可以监听变量从可访问到不可访问和从不可访问到可访问。例子如下。

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User | undefined | null = new User();

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear() {
    UIUtils.addMonitor(this, ['user.age'], this.onChange);
  }

  build() {
    Column() {
      Text(`User age ${this.user?.age}`).fontSize(20)
      Button('set user to undefined').onClick(() => {
          // age可访问->不可访问
          // 触发onChange监听回调：onChange: User property user.age change from 10 to undefined
          this.user = undefined;
        })
      Button('set user to User').onClick(() => {
        // age不可访问->可访问
        // 触发onChange监听回调：onChange: User property user.age change from undefined to 10
        this.user = new User();
      })
      Button('set user to null').onClick(() => {
        // age可访问->不可访问
        // 触发onChange监听回调：onChange: User property user.age change from 10 to undefined
        this.user = null;
      })
    }
  }
}
```
### 配置同步监听函数
和\@Monitor仅支持异步监听不同，addMonitor可支持配置成同步监听函数，在下面的例子中，点击```Text(`User age ${this.user.age}`)```，触发两次`age`的自增，回调两次`onChange`函数，日志打印如下：
``` ts
onChange: User property user.age change from 10 to 11
onChange: User property user.age change from 11 to 12
```
```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User = new User();

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear(): void {
    // addMonitor支持配置成同步监听函数
    UIUtils.addMonitor(this, 'user.age', this.onChange, { isSynchronous: true })
  }

  build() {
    Column() {
      Text(`User age ${this.user.age}`).fontSize(20).onClick(() => {
        this.user.age++;
        this.user.age++;
      })
    }
  }
}
```
如果将上面的例子改成\@Monitor，仅会打印一次回调，日志如下：
``` ts
onChange: User property user.age change from 10 to 12
```

```ts
@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User = new User();

  // @Monitor仅支持异步监听
  @Monitor('user.age')
  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`User age ${this.user.age}`).fontSize(20).onClick(() => {
        this.user.age++;
        this.user.age++;
      })
    }
  }
}
```

### 监听构造函数中同步修改的状态变量的变化
和[\@Monitor异步构造](./arkts-new-monitor.md#类中monitor对变量监听的生效及失效时间)不同，addMonitor是同步构造的，所以在开发者调用完`UIUtils.addMonitor(this, 'message', this.onMessageChange);`后就完成了对`message`添加监听函数`this.onMessageChange`。在下面的例子中：
- 拉起页面，构造`Info`的实例，回调`onMessageChange`监听函数。
- 点击```Button('change message')```，回调`onMessageChange`监听函数。

日志输出如下：
``` ts
message change from not initialized to initialized
message change from initialized to Index aboutToAppear
message change from Index aboutToAppear to Index click to change message
```

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class Info {
  @Trace message: string = 'not initialized';

  constructor() {
    // addMonitor可以监听构造函数中message的变化
    UIUtils.addMonitor(this, 'message', this.onMessageChange);
    this.message = 'initialized';
  }
  onMessageChange(monitor: IMonitor) {
    console.info(`message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}

@Entry
@ComponentV2
struct Page {
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

### 动态取消\@ObservedV2/\@ComponentV2实例的监听

和@Monitor不同，addMonitor/clearMonitor可以对不同的\@ObservedV2/\@ComponentV2实例动态添加监听函数。例子如下。

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 10;

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor(needMonitor: boolean) {
    if (needMonitor) {
      UIUtils.addMonitor(this, 'age', this.onChange);
    }
  }
}

@Entry
@ComponentV2
struct Page {
  @Local user1: User = new User(true);
  @Local user2: User = new User(false);
  @Local count: number = 10;

  build() {
    Column() {
      Text(`user1 age ${this.user1.age}`).fontSize(20).onClick(() => {
        // 有Monitor回调
        this.user1.age++;
      })
      Text(`user2 age ${this.user2.age}`).fontSize(20).onClick(() => {
        // 无Monitor回调
        this.user2.age++;
      })
      Button(`remove user1 monitor`).onClick(() => {
        UIUtils.clearMonitor(this.user1, 'age', this.user1.onChange);
      })

      Button(`change count`).onClick(() => {
        this.count++;
      })

      Child({ needMonitor: true, count: this.count })
      Child({ needMonitor: false, count: this.count })
    }
  }
}

@ComponentV2
struct Child {
  @Param needMonitor: boolean = false;
  @Param count: number = 0;

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`Child needMonitor ${this.needMonitor} onChange: property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear(): void {
    if (this.needMonitor) {
      UIUtils.addMonitor(this, 'count', this.onChange);
    }
  }

  build() {
    Column() {
      Text(`${this.count}`).fontSize(20)
    }
  }
}
```

### 使用包含通配符的路径

从API版本26.0.0开始，MonitorOptions新增`enableWildcard`配置项（默认值为false），当显式设置为true时，addMonitor可以支持使用通配符路径。当未配置`enableWildcard`为true，但使用通配符路径时，该路径被认为不合法，该次addMonitor的添加不会生效。

`enableWildcard`将在第一次为函数创建监听时生效，后续无法被更改。对`enableWildcard`值的检查发生在检测到路径中含有通配符时。当首次创建监听时，`enableWildcard`设置为true，后续路径中不含通配符时，将不会检查`enableWildcard`的值，因此即使此时传递`enableWildcard`为false，也会忽略该false，仍添加监听。当首次创建监听时，`enableWildcard`设置为false，若后续路径中含有通配符，无论`enableWildcard`是否传递为true，该路径都被认为不合法，该次addMonitor的添加不会生效。

正确使用通配符的方式如下：

```ts
UIUtils.addMonitor(this, 'obj.*', this.onChange, { enableWildcard: true });
```

以下写法将保持原有行为，不会生效：

```ts
// enableWildcard未配置为true，路径不合法
UIUtils.addMonitor(this, 'obj.*', this.onChange);
```

通配符路径的使用规则可以参考@Monitor文档中对[监听包含通配符的路径](arkts-new-monitor.md#监听包含通配符的路径)的说明。

addMonitor使用通配符观察对象属性变化的用例如下。

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { UIUtils } from '@kit.ArkUI';
@ObservedV2
class ClassA {
  @Trace propA: number = 8;
  @Trace propB: number = 99;

  constructor(a: number, b: number) {
    this.propA = a;
    this.propB = b;
  }
}

@Entry
@ComponentV2
struct MonitorWildcardObject {
  @Local cls: ClassA = new ClassA(100, 100);

  onClsChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onClsChanged, dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    UIUtils.addMonitor(this, 'cls.*', this.onClsChanged, { enableWildcard: true });
  }

  build() {
    Column() {
      Button(`Change propA: ${this.cls.propA}`)
        .onClick(() => {
          this.cls.propA += 1; // 触发onClsChanged
        })
      Button(`Change propB: ${this.cls.propB}`)
        .onClick(() => {
          this.cls.propB += 1; // 触发onClsChanged
        })
      Button('Assign new object')
        .onClick(() => {
          this.cls = new ClassA(-200, -200); // 触发onClsChanged
        })
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'cls.*'); // 取消监听
        })
    }
  }
}
```

### 监听内置类型状态变量API调用

从API版本26.0.0开始，可以通过配置使用通配符的方式，实现对Array、Map、Set、Date类型状态变量API调用的监听。

**使用通配符监听Array对象的变化**

使能通配符的addMonitor可以监听到数组的API调用。任意数组的方法被调用时，addMonitor注册的回调都会被执行，即使数组为空或并未实际修改数组的内容。API包括`push`、`pop`、`shift`、`splice`、`unshift`、`copyWithin`、`fill`、`reverse`、`sort`。

```ts
import { UIUtils } from '@kit.ArkUI';
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
class ArrayOfPerson extends Array<Person> {}

@ObservedV2
class TopArray extends Array<ArrayOfPerson> {}

@Entry
@ComponentV2
struct DocAddMonitorAPIArrayOfArrays {
  @Local topArray: TopArray = this.makeNewTopArray();

  topArrayMonitor1Star(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray[1]: ${monitor.dirty.toString()}`);
  }

  topArrayMonitorStar(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray: ${monitor.dirty.toString()}`);
  }

  makeNewTopArray(): TopArray {
    return new TopArray(
      new ArrayOfPerson(new Person('Adrian'), new Person('Andrew'), new Person('Aaliyah'), new Person('Amir'), new Person('Angel')),
      new ArrayOfPerson(new Person('Carter'), new Person('Charlie'), new Person('Cooper'), new Person('Cole'), new Person('Callie')),
      new ArrayOfPerson(new Person('Daniel'), new Person('Daisy'), new Person('Dawson'), new Person('Dana'), new Person('Dalton'))
    );
  }

  aboutToAppear(): void {
    // 使能通配符
    UIUtils.addMonitor(this, 'topArray.1.*', this.topArrayMonitor1Star, { enableWildcard: true });
    UIUtils.addMonitor(this, 'topArray.*', this.topArrayMonitorStar, { enableWildcard: true });
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

      // 取消监听
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'topArray.1.*');
          UIUtils.clearMonitor(this, 'topArray.*');
        })
    }
  }
}
```

**使用通配符监听Date对象的变化**

使用通配符可以监听Date对象的API调用。

```ts
UIUtils.addMonitor(target, 'dateInstance.*', callback, { enableWildcard: true });
```

addMonitor注册的监听会在以下情况回调：

- `dateInstance`被赋新值。
- 调用Date的任意API，包括`setFullYear`、`setMonth`、`setDate`、`setHours`、`setMinutes`、`setSeconds`、`setMilliseconds`、`setTime`、`setUTCFullYear`、`setUTCMonth`、`setUTCDate`、`setUTCHours`、`setUTCMinutes`、`setUTCSeconds`、`setUTCMilliseconds`。即使这些API未实际对Date的值产生更改，addMonitor注册的监听回调也会触发。

使用通配符监听Date对象的示例如下。

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2 struct DocAddMonitorAPIDate {
  @Local date: Date = new Date();

  onDateChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onDateChanged, dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    // 使能通配符
    UIUtils.addMonitor(this, 'date.*', this.onDateChanged, { enableWildcard: true });
  }

  build() {
    Column({ space: 5 }) {
      // API调用触发onDateChanged
      Button(`date.setMilliseconds(1000)`)
        .onClick(() => {
          this.date.setMilliseconds(1000);
        })
      // API调用触发onDateChanged
      Button(`date.setTime(1000000)`)
        .onClick(() => {
          this.date.setTime(1000000);
        })
      // API调用触发onDateChanged
      Button(`Assign new Date`)
        .onClick(() => {
          this.date = new Date();
        })
      // 整体赋相同值，不触发onDateChanged
      Button(`Re-assign the same Date`)
        .onClick(() => {
          let sameDate = this.date;
          this.date = sameDate;
        })
      // 取消监听
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'date.*');
        })
    }
  }
}
```

**使用通配符监听Map对象的变化**

使用通配符可以监听Map对象的API调用。

```ts
UIUtils.addMonitor(target, 'mapInstance.*', callback, { enableWildcard: true });
```

addMonitor注册的监听会在以下情况回调：

- `mapInstance`被赋新值。
- 调用Map的API，例如`set`、`delete`、`clear`时触发。与Array、Date不同的是，只有当变化真的发生时，回调才会触发。这意味着，当对空Map调用`clear`，对不存在的Map键值调用`delete`，以及不实际改变值的`set`调用都不会触发addMonitor注册的监听回调。

与Array不同，addMonitor无法对Map的某一个key做监听。

使用通配符监听Map对象的示例如下。

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2
struct DocAddMonitorAPIMap {
  @Local map: Map<string, string> = new Map<string, string>();
  cnt: number = 0;

  onMapSizeChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onMapSizeChanged, size dirty: ${m.dirty.toString()}`);
  }

  onMapChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onMapChanged, dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    UIUtils.addMonitor(this, 'map.size', this.onMapSizeChanged);
    // 使能通配符
    UIUtils.addMonitor(this, 'map.*', this.onMapChanged, { enableWildcard: true });
  }

  build() {
    Column({ space: 5 }) {
      Text(`map.size: ${this.map.size}`)
      Text(`map.get('one'): ${this.map.get('one')}`)
      // 在首次点击时，onMapSizeChanged、onMapChanged回调都触发
      Button(`Init, map.set('one', 'A'), map.set('two', 'B')`)
        .onClick(() => {
          this.map.set('one', 'A');
          this.map.set('two', 'B');
        })
      // onMapSizeChanged、onMapChanged回调都触发
      Button(`Add new, map.set('three' + this.cnt, 'C')`)
        .onClick(() => {
          this.cnt++;
          this.map.set('three' + this.cnt, 'C')
        })
      // 当'one'不存在时，onMapSizeChanged、onMapChanged回调都不触发
      // 当'one'存在时，onMapSizeChanged、onMapChanged回调都触发
      Button(`Delete from map: map.delete('one')`)
        .onClick(() => {
          this.map.delete('one')
        })
      // 当map不为空时，onMapSizeChanged、onMapChanged回调都触发
      // 当map为空时，onMapSizeChanged、onMapChanged回调都不触发
      Button(`Clear map`)
        .onClick(() => {
          this.map.clear();
        })
      // 在首次点击且假设存在（'one' -> 'A'）时，仅onMapChanged回调触发
      // 若已经设置过（'one' -> 'TWO'），则onMapSizeChanged、onMapChanged回调都不触发
      Button(`Update one to 'TWO' - map.set('one', 'TWO')`)
        .onClick(() => {
          this.map.set('one', 'TWO');
        })
      // 当Map不存在'one'时，onMapSizeChanged、onMapChanged回调都触发
      // 当Map存在'one'时，onMapSizeChanged、onMapChanged回调都不会触发
      Button(`Update one to the same - map.set('one', sameval)`)
        .onClick(() => {
          const sameval = this.map.get('one') ?? 'one' ;
          this.map.set('one', sameval);
        })
      // 当Map不存在'one'时，onMapSizeChanged、onMapChanged回调都触发
      // 当Map存在'one'时，仅onMapChanged回调触发
      Button(`Update one to new value - map.set('one', newval)`)
        .onClick(() => {
          let newval = 'x' + (++this.cnt);
          this.map.set('one', newval);
        })
      // 当map为空时，仅onMapChanged回调触发
      // 当map不为空时，onMapChanged、onMapSizeChanged回调都触发
      Button(`new map`)
        .onClick(() => {
          this.map = new Map();
        })
      // 取消监听
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'map.size');
          UIUtils.clearMonitor(this, 'map.*');
        })
    }
    .border({ style: BorderStyle.Solid, width: 2, color: Color.Green })
  }
}
```

**使用通配符监听Set对象的变化**

使用通配符可以监听Set对象的API调用。

```ts
UIUtils.addMonitor(target, 'setInstance.*', callback, { enableWildcard: true });
```

addMonitor注册的监听会在以下情况回调：

- `setInstance`被赋新值。
- 调用Set的API，例如`add`、`delete`、`clear`时触发。与Array、Date不同的是，只有当变化真的发生时，回调才会触发。这意味着，当对空Set调用`clear`，对不存在的Set元素调用`delete`，以及不实际新增元素的`add`调用都不会触发addMonitor注册的监听回调。

与Array不同，addMonitor无法对Set的某一个key做监听。

使用通配符监听Set对象的示例如下。

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2 struct DocAddMonitorAPISet {
  @Local set: Set<string> = new Set<string>();
  cnt: number = 0;

  onSetChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onSetChanged, dirty: ${m.dirty.toString()}`);
  }

  onSetSizeChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onSetSizeChanged, size dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    // 使能通配符
    UIUtils.addMonitor(this, 'set.*', this.onSetChanged, { enableWildcard: true });
    UIUtils.addMonitor(this, 'set.size', this.onSetSizeChanged);
    this.set.add('one');
    this.set.add('two');
  }

  build() {
    Column({ space: 5 }) {
      // onSetChanged、onSetSizeChanged回调都触发
      Button(`Add three<Num> to the set`)
        .onClick(() => {
          this.cnt++;
          this.set.add('three' + this.cnt);
        })
      // 当元素不存在时，onSetChanged、onSetSizeChanged回调都不触发
      // 当元素存在时，onSetChanged、onSetSizeChanged回调都触发
      Button(`Delete 'three<Num>' from the set - set.delete(...)`)
        .onClick(() => {
          this.set.delete('three' + this.cnt);
        })
      // 当set不为空时，onSetChanged、onSetSizeChanged回调都触发
      // 当set为空时，onSetChanged、onSetSizeChanged回调都不触发
      Button(`Clear the set - set.clear()`)
        .onClick(() => {
          this.set.clear();
        })
      // 当set不为空时，onSetChanged、onSetSizeChanged回调都触发
      // 当set为空时，仅onSetChanged回调触发
      Button(`Assign new set`)
        .onClick(() => {
          this.set = new Set();
        })
      // 当set不包含'one'时，onSetChanged、onSetSizeChanged回调都触发
      // 当set包含'one'时，onSetChanged、onSetSizeChanged回调都不触发
      Button(`Add 'one' to the set`)
        .onClick(() => {
          this.set.add('one');
        })
      // 取消监听
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'set.*');
          UIUtils.clearMonitor(this, 'set.size');
        })
    }
  }
}
```