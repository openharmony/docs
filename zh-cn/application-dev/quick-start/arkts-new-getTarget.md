# getTarget接口：获取状态管理框架代理前的原始对象

为了获取状态管理框架代理前的原始对象，开发者可以使用[getTarget接口](../reference/apis-arkui/js-apis-StateManagement.md#gettarget12)。

在阅读本文档前，建议提前阅读：[\@Observed](./arkts-observed-and-objectlink.md)，[\@ObservedV2](./arkts-new-observedV2-and-trace.md)。

>**说明：**
>
>从API version 12开始，开发者可以使用UIUtils中的getTarget接口获取状态管理框架代理前的原始对象。

## 概述

状态管理框架会对Class、Date、Map、Set、Array类型的原始对象添加代理，用于观测属性变化与API调用。这一层代理会使得变量类型改变，在类型判断、NAPI调用等场景，会由于类型并非原始对象的类型产生预料之外的结果。

- 使用getTarget接口需要导入UIUtils工具。

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```

- 状态管理V1中，会给\@Observed装饰的类对象以及使用状态变量装饰器如\@State装饰的Class、Date、Map、Set、Array添加一层代理用于观测一层属性或API调用产生的变化。
- 状态管理V2中，会给使用状态变量装饰器如\@Trace、\@Local装饰的Date、Map、Set、Array添加一层代理用于观测API调用产生的变化。

使用getTarget接口可以获取这些代理对象的原始对象。

## 限制条件

- getTarget仅支持对象类型传参

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  let res = UIUtils.getTarget(2); // 非对象类型入参，错误用法
  @Observed
  class Info {
    name: string = "Tom";
  }
  let info: Info = new Info();
  let rawInfo: Info = UIUtils.getTarget(info); // 正确用法
  ```

- 更改getTarget获取的原始对象中的内容不会被观察到变化，也不会触发UI刷新。

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  @Observed
  class Info {
    name: string = "Tom";
  }
  @Entry
  @Component
  struct Index {
    @State info: Info = new Info();
    
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
        Button(`更改代理对象的属性`)
          .onClick(() => {
            this.info.name = "Alice"; // Text组件能够刷新
          })
        Button(`更改原始对象的属性`)
          .onClick(() => {
            let rawInfo: Info = UIUtils.getTarget(this.info);
            rawInfo.name = "Bob"; // Text组件不能刷新
          })
      }
    }
  }
  ```

## 使用场景

### 获取状态管理V1代理前的原始对象

状态管理V1有两种场景会给对象增加代理：

【1】\@Observed装饰的类实例。在创建\@Observed装饰的类实例时，会给该实例添加代理。该过程发生在new对象的过程中，没有经过new操作符创建的对象是不被代理的。

```ts
@Observed
class ObservedClass {
  name: string = "Tom";
}
class NonObservedClass {
  name: string = "Tom";
}
let observedClass: ObservedClass = new ObservedClass(); // 被代理
let nonObservedClass: NonObservedClass = new NonObservedClass(); // 不被代理
```

【2】状态变量装饰器装饰的复杂类型对象。使用\@State、\@Prop等状态变量装饰器装饰Class、Map、Set、Date、Array时，会添加代理。若该对象已经是代理对象，则不会重复创建代理。

```ts
@Observed
class ObservedClass {
  name: string = "Tom";
}
class NonObservedClass {
  name: string = "Tom";
}
let observedClass: ObservedClass = new ObservedClass(); // 被代理
let nonObservedClass: NonObservedClass = new NonObservedClass(); // 不被代理
@Entry
@Component
struct Index {
  @State observedObject: ObservedClass = observedClass; // 已被代理数据不会重复创建代理
  @State nonObservedObject: NonObservedClass = nonObservedClass; // 创建代理
  @State numberList: number[] = [1, 2, 3]; // Array类型创建代理
  @State sampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // Map类型创建代理
  @State sampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // Set类型创建代理
  @State sampleDate: Date = new Date(); // Date类型创建代理
  
  build() {
    Column() {
      Text(`this.observedObject === observedClass: ${this.observedObject === observedClass}`) // true
      Text(`this.nonObservedObject === nonObservedClass: ${this.nonObservedObject === nonObservedClass}`) // false
    }
  }
}
```

使用UIUtils.getTarget接口可以获取代理前的原始对象。

```ts
import { UIUtils } from '@kit.ArkUI';
@Observed
class ObservedClass {
  name: string = "Tom";
}
class NonObservedClass {
  name: string = "Tom";
}
let observedClass: ObservedClass = new ObservedClass(); // 被代理
let nonObservedClass: NonObservedClass = new NonObservedClass(); // 不被代理
let globalNumberList: number[] = [1, 2, 3]; // 不被代理
let globalSampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // 不被代理
let globalSampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // 不被代理
let globalSampleDate: Date = new Date(); // 不被代理
@Entry
@Component
struct Index {
  @State observedObject: ObservedClass = observedClass; // 已被代理数据不会重复创建代理
  @State nonObservedObject: NonObservedClass = nonObservedClass; // 创建代理
  @State numberList: number[] = globalNumberList; // Array类型创建代理
  @State sampleMap: Map<number, string> = globalSampleMap; // Map类型创建代理
  @State sampleSet: Set<number> = globalSampleSet; // Set类型创建代理
  @State sampleDate: Date = globalSampleDate; // Date类型创建代理
  
  build() {
    Column() {
      Text(`this.observedObject === observedClass: ${this.observedObject ===
           observedClass}`) // true
      Text(`UIUtils.getTarget(this.nonObservedObject) === nonObservedClass: ${UIUtils.getTarget(this.nonObservedObject) ===
           nonObservedClass}`) // true
      Text(`UIUtils.getTarget(this.numberList) === globalNumberList: ${UIUtils.getTarget(this.numberList) ===
           globalNumberList}`) // true
      Text(`UIUtils.getTarget(this.sampleMap) === globalSampleMap: ${UIUtils.getTarget(this.sampleMap) ===
           globalSampleMap}`) // true
      Text(`UIUtils.getTarget(this.sampleSet) === globalSampleSet: ${UIUtils.getTarget(this.sampleSet) ===
           globalSampleSet}`) // true
      Text(`UIUtils.getTarget(this.sampleDate) === globalSampleDate: ${UIUtils.getTarget(this.sampleDate) ===
           globalSampleDate}`) // true
    }
  }
}
```

### 获取状态管理V2代理前的原始对象

状态管理V2会给状态变量装饰器如\@Trace、\@Local装饰的Map、Set、Date、Array添加一层代理。和V1不同的是，状态管理V2不会对类对象实例进行代理。

```ts
@ObservedV2
class ObservedClass {
  @Trace name: string = "Tom";
}
let globalObservedObject: ObservedClass = new ObservedClass(); // 不被代理
let globalNumberList: number[] = [1, 2, 3]; // 不被代理
let globalSampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // 不被代理
let globalSampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // 不被代理
let globalSampleDate: Date = new Date(); // 不被代理
@Entry
@ComponentV2
struct Index {
  @Local observedObject: ObservedClass = globalObservedObject; // V2中对象不被代理
  @Local numberList: number[] = globalNumberList; // Array类型创建代理
  @Local sampleMap: Map<number, string> = globalSampleMap; // Map类型创建代理
  @Local sampleSet: Set<number> = globalSampleSet; // Set类型创建代理
  @Local sampleDate: Date = globalSampleDate; // Date类型创建代理
  
  build() {
    Column() {
      Text(`this.observedObject === globalObservedObject ${this.observedObject === globalObservedObject}`) // true
      Text(`this.numberList === globalNumberList ${this.numberList === globalNumberList}`) // false
    }
  }
}
```

使用UIUtils.getTarget接口可以获取代理前的原始对象。

```ts
import { UIUtils } from '@kit.ArkUI';
@ObservedV2
class ObservedClass {
  @Trace name: string = "Tom";
}
let globalObservedObject: ObservedClass = new ObservedClass(); // 不被代理
let globalNumberList: number[] = [1, 2, 3]; // 不被代理
let globalSampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // 不被代理
let globalSampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // 不被代理
let globalSampleDate: Date = new Date(); // 不被代理
@Entry
@ComponentV2
struct Index {
  @Local observedObject: ObservedClass = globalObservedObject; // V2中对象不被代理
  @Local numberList: number[] = globalNumberList; // Array类型创建代理
  @Local sampleMap: Map<number, string> = globalSampleMap; // Map类型创建代理
  @Local sampleSet: Set<number> = globalSampleSet; // Set类型创建代理
  @Local sampleDate: Date = globalSampleDate; // Date类型创建代理
  
  build() {
    Column() {
      Text(`this.observedObject === globalObservedObject ${this.observedObject ===
           globalObservedObject}`) // true
      Text(`UIUtils.getTarget(this.numberList) === globalNumberList: ${UIUtils.getTarget(this.numberList) ===
           globalNumberList}`) // true
      Text(`UIUtils.getTarget(this.sampleMap) === globalSampleMAP: ${UIUtils.getTarget(this.sampleMap) ===
           globalSampleMap}`) // true
      Text(`UIUtils.getTarget(this.sampleSet) === globalSampleSet: ${UIUtils.getTarget(this.sampleSet) ===
           globalSampleSet}`) // true
      Text(`UIUtils.getTarget(this.sampleDate) === globalSampleDate: ${UIUtils.getTarget(this.sampleDate) ===
           globalSampleDate}`) // true
    }
  }
}
```

状态管理V2装饰器会为装饰的变量生成getter和setter方法，同时为原有变量名添加"\_\_ob\_"的前缀。出于性能考虑，getTarget接口不会对V2装饰器生成的前缀进行处理，因此向getTarget接口传入\@ObservedV2装饰的类对象实例时，返回的对象依旧为对象本身，且被\@Trace装饰的属性名仍有"\_\_ob\_"前缀。

该前缀会导致某些NAPI接口无法按预期处理对象的属性，以下面的对象为例，目前已知影响的NAPI接口如下：

```ts
// ObservedV2装饰的类
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace age: number = 24;
}
let info: Info = new Info(); // NAPI接口传入info实例
```

| 影响接口名              | 影响结果                                       |
| ----------------------- | ---------------------------------------------- |
| napi_get_property_names | 返回值为"\_\_ob\_name"，"\_\_ob\_age"。        |
| napi_set_property       | 使用"name"，"\_\_ob\_name"均能赋值成功。       |
| napi_get_property       | 使用"name"，"\_\_ob\_name"均能获取到值。       |
| napi_has_property       | 使用"name"，"\_\_ob\_name"均返回true。         |
| napi_delete_property    | 删除属性时需要加上"\_\_ob\_"前缀才能删除成功。 |
| napi_has_own_property   | 使用"name"，"\_\_ob\_name"均返回true。         |
| napi_set_named_property | 使用"name"，"\_\_ob\_name"均能赋值成功。       |
| napi_get_named_property | 使用"name"，"\_\_ob\_name"均能获取到值。       |
| napi_has_named_property | 使用"name"，"\_\_ob\_name"均返回true。         |