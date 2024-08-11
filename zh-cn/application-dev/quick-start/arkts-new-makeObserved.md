# makeObserved接口：将非观察数据变为可观察数据

为了将普通不可观察数据变为可观察数据，开发者可以使用[makeObserved接口](../reference/apis-arkui/js-apis-StateManagement.md#makeobserved12)。

>**说明：**
>
>从API version 12开始，开发者可以使用UIUtils中的makeObserved接口将普通不可观察数据变为可观察数据。

## 概述

- 状态管理框架已提供[@ObservedV2/@Trace](./arkts-new-observedV2-and-trace.md)用于观察类属性变化，makeObserved接口提供主要应用于@ObservedV2/@Trace无法涵盖的场景：

    - class的定义在三方包中：开发者无法手动对class中需要观察的属性加上@Trace标签，则可以使用makeObserved使得当前对象可以被观察。

    - 当前类的成员属性不能被修改：因为@Trace观察类属性会动态修改类的属性，这个行为在@Sendable修饰的class中是不被允许的，则可以使用makeObserved。

    - interface或者JSON.parse返回的匿名对象：这类场景往往没有明确的class声明，开发者无从使用@Trace标记当前属性是可以观察的，则可以使用makeObserved。


- 使用makeObserved接口需要导入UIUtils。
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```

## 限制条件

- makeObserved仅支持对象类型传参。

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  let res = UIUtils.makeObserved(2); // 非对象类型入参，错误用法
  class Info {
    id: number = 0
  }
  let rawInfo: Info = UIUtils.makeObserved(new Info()); // 正确用法
  ```

- makeObserved不支持传入[@ObservedV2](./arkts-new-observedV2-and-trace.md)和[@Observed](./arkts-observed-and-objectlink.md)修饰的class传入的实例，当发现当前实例为@ObservedV2/@Observed则返回自身。
为了防止双重代理，makeObserved不支持传入@ObservedV2/@Observed修饰的类的实例，一旦发现，则makeObserved会停止工作，不再进行深度观察。所以开发者在做类属性的观察时，需要考虑好使用@ObservedV2/@Observed还是makeObserved。

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  @ObservedV2
  class Info {
    @Trace id: number = 0;
  }
  // makeObserved发现传入的实例是@ObservedV2，则返回传入对象自身
  let rawInfo: Info = UIUtils.makeObserved(new Info());
  ```
- makeObserved可以用在@Component中，但不能和V1的状态变量装饰器连用。会抛出运行时异常。
  ```ts
  // 错误写法，运行时异常
  @State message: Info2 = UIUtils.makeObserved(new Info(20));
  ```

- makeObserved的返回值被赋值一个非可观察的数据后，会丧失观察能力，如果需要整体替换，需要再次使用makeObserved进行赋值。
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  class Info {
    id: number = 0
    constructor(id: number) {
      this.id = id;
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local message: Info = UIUtils.makeObserved(new Info(20));
    build() {
      Column() {
        Button(`change Info ${this.message.id}`).onClick(() =>{
          // 错误用法：this.message被赋值为不可观察数据，丧失深度观察能力
          this.message = new Info(30)
        })
        Button(`change Info1  ${this.message.id}`).onClick(() =>{
          // 正确用法
          this.message = UIUtils.makeObserved(new Info(30))
        })
        // 点击change Info后，点击change id，不会触发UI刷新
        // 因为this.message被赋值为普通变量，丧失深度观察能力，无法观察id的变化
        // 但因为this.message本身被@Local装饰的，可以观察到this.message整体赋值的变化
        Button(`change id`).onClick(() =>{
          this.message.id++;
        })
      }
    }
  }
  ```


## 支持类型和观察变化

### 支持类型

- 支持非@Observed和@ObserveV2修饰的class，JSON.parse返回的Object和@Sendable修饰的class。
- 支持Array、Map、Set和Date。
- 支持collection.Array, collection.Set和collection.Map。

### 观察变化

- makeObserved传入内置类型或collection类型的实例时，可以观测其API导致的变化：

  | 类型  | 可观测变化的API                                              |
  | ----- | ------------------------------------------------------------ |
  | Array | push、pop、shift、unshift、splice、copyWithin、fill、reverse、sort |
  | collections.Array | push、pop、shift、unshift、splice、fill、reverse、sort、shrinkTo、extendTo |
  | Map/collections.Map   | set, clear, delete                                 |
  | Set/collections.Set   | add, clear, delete                                 |
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |

## 使用场景

### makeObserved和@Sendable修饰的class连用

[@Sendable](../arkts-utils/arkts-sendable.md)主要是为了解决不同应用场景中的并发任务。和ArkUI makeObserved需要和sendable一起考虑的原因是，一般应用开发中，在子线程做大数据处理，在UI线程做ViewModel的显示和观察数据。

本章节不会重点讨论@Sendable的多线程能力和api，具体可参考[并发任务文档](../arkts-utils/multi-thread-concurrency-overview.md)。本章节将展示下面的场景：
- makeObserved在传入@Sendable类型的数据后有观察能力，且其变化可以触发UI刷新。
- 从子线程中获取一个整体数据，然后对UI线程的可观察数据做整体替换。
- 整体替换后，被替换的数据需要执行makeObserved，否则无观察能力。
- makeObserved返回值，即有观察能力的数据不能直接传给子线程，因为子线程非UI线程，无法进行数据的观察和触发UI刷新。

例子如下：

```ts
// SendableData.ets
@Sendable
export class SendableData  {
  name: string = 'Tom';
  age: number = 20;
  gender: number = 1;
  // .... more other properties
  likes: number = 1;
  follow: boolean = false;
}
```

```ts
import { taskpool } from '@kit.ArkTS';
import { SendableData } from './SendableData';
import { UIUtils } from '@kit.ArkUI';


@Concurrent
function threadGetData(param: string): SendableData {
  // 在子线程处理数据
  let ret = new SendableData();
  console.info(`Concurrent threadGetData, param ${param}`);
  ret.name =param + "-o";
  ret.age = Math.floor(Math.random()*40);
  ret.likes = Math.floor(Math.random()*100);
  return ret;
}

@Entry
@ComponentV2
struct ObservedSendableTest {
  // 通过makeObserved给普通对象或是Sendable对象添加可观察能力
  @Local send: SendableData = UIUtils.makeObserved(new SendableData());
  build() {
    Column() {
      Text(this.send.name)
      Button("change name").onClick(()=> {
        // ok 可以观察到属性的改变
        this.send.name += "0";
      })

      Button("task").onClick(()=>{
        // 将待执行的函数放入taskpool内部任务队列等待，等待分发到工作线程执行。
        taskpool.execute( threadGetData, this.send.name ).then( val => {
          // 和@Local一起使用，可以观察this.send的变化
          this.send = UIUtils.makeObserved(val as SendableData);
        })
      })
    }
  }
}
```
需要注意：数据的构建和处理可以在子线程，但有观察能力的数据或者操作可观察的数据是不能传给子线程，一定要回到主线程里做。所以上述例子中只是将`this.send.name`的属性传给子线程操作。

### makeObserved和collections.Array/Set/Map连用
collections提供ArkTS容器集，可用于并发场景下的高性能数据传递。详情见[@arkts.collections文档](../reference/apis-arkts/js-apis-arkts-collections.md)。

#### collections.Array例子

collections.Array触发UI刷新的API：
- 改变数组长度：push、pop、shift、unshift、splice、shrinkTo、extendTo。
- 改变数组项本身：sort、fill。

其他API不会改变原始数组，所以不会触发UI刷新。

```ts
import { collections } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';

@Sendable
class Info {
  id: number = 0;
  name: string = 'cc';

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@ComponentV2
struct Page30 {
  scroller: Scroller = new Scroller();
  @Local arrCollect: collections.Array<Info> =
    UIUtils.makeObserved(new collections.Array<Info>(new Info(1), new Info(2)));

  build() {
    Column() {
      // ForEach接口仅支持Array<any>，不支持collections.Array<any>。
      // 但ForEach的实现用到的Array的API,collections.Array都有提供。所以可以使用as类型断言Array。需要注意断言并不会改变原本的数据类型。
      ForEach(this.arrCollect as object as Array<Info>, (item: Info) => {
        Text(`${item.id}`).onClick(() => {
          item.id++;
        })
      }, (item: Info, index) => item.id.toString() + index.toString())
      Divider()
        .color('blue')
      if (this.arrCollect.length > 0) {
        Text(`the fist one ${this.arrCollect[this.arrCollect.length - this.arrCollect.length].id}`)
        Text(`the last one ${this.arrCollect[this.arrCollect.length - 1].id}`)
      }
      Divider()
        .color('blue')


      /****************************改变数据长度的api**************************/
      Scroll(this.scroller) {
        Column({space: 10}) {
          // push 操作
          Button('push').onClick(() => {
            this.arrCollect.push(new Info(30));
          })
          // pop: remove the last one
          Button('pop').onClick(() => {
            this.arrCollect.pop();
          })
          // shift: remove the first one
          Button('shift').onClick(() => {
            this.arrCollect.shift();
          })
          // unshift: insert the new item in the start of the array
          Button('unshift').onClick(() => {
            this.arrCollect.unshift(new Info(50));
          })
          // splice: Removes elements from the array at the specified position
          Button('splice').onClick(() => {
            this.arrCollect.splice(1);
          })

          // Shrinks the ArkTS array to the given arrayLength.
          Button('shrinkTo').onClick(() => {
            this.arrCollect.shrinkTo(1);
          })
          // Extends the ArkTS array to the given arrayLength,
          Button('extendTo').onClick(() => {
            this.arrCollect.extendTo(6, new Info(20));
          })

          Divider()
            .color('blue')

          /****************************************改变数组item本身*****************/
          // sort,从大到小排序
          Button('sort').onClick(() => {
            this.arrCollect.sort((a: Info, b: Info) => b.id - a.id);
          })
          // fill: filling the section identified by start and end with value
          Button('fill').onClick(() => {
            this.arrCollect.fill(new Info(5), 0, 2);
          })

          /*****************************不会改变数组本身API***************************/
          // slice：返回新的数组，根据start end对原数组的拷贝，不会改变原数组，所以直接调用slice不会触发UI刷新
          // 可以构建用例为返回的浅拷贝的数据赋值给this.arrCollect,需要注意这里依然要调用makeObserved，否则this.arr被普通变量赋值后，会丧失观察能力
          Button('slice').onClick(() => {
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.slice(0, 1));
          })
          // map：原理同上
          Button('map').onClick(() => {
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.map((value) => {
              value.id += 10;
              return value;
            }))
          })
          // filter：原理同上
          Button('filter').onClick(() => {
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.filter((value: Info) => value.id % 2 === 0));
          })

          // concat ： 原理同上
          Button('concat').onClick(() => {
            let array1 = new collections.Array(new Info(100))
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.concat(array1));
          })
        }.height(`200%`)
      }.height('60%')
    }
    .height('100%')
    .width('100%')
  }
}
```
#### collections.Map例子

collections.Map触发UI刷新的API：set、clear，delete。
```ts
import { collections } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';

@Sendable
class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@ComponentV2
struct CollectionMap {
  mapCollect: collections.Map<string, Info> = UIUtils.makeObserved(new collections.Map<string, Info>([['a', new Info(10)], ['b', new Info(20)]]));

  build() {
    Column() {
      // this.mapCollect.keys()返回迭代器。Foreach不支持迭代器，所以要Array.From浅拷贝生成数据。
      // 推荐使用使用key做循环, 原因是在绑定map的value在Text组件上的时候，可以使用get从而使得value收集到Text的组件id。否则改变value不会触发Text组件刷新。
      ForEach(Array.from(this.mapCollect.keys()), (item: string) => {
        Text(`${this.mapCollect.get(item)?.id}`).onClick(() =>{
          let value: Info|undefined = this.mapCollect.get(item)
          if (value) {
            value.id++;
          }
        })
      }, (item: string, index) => item + index.toString())

      // set c
      Button('set c').onClick(() => {
        this.mapCollect.set('c', new Info(30));
      })
      // delete c
      Button('delete c').onClick(() => {
        if (this.mapCollect.has('c')) {
          this.mapCollect.delete('c');
        }
      })
      // clear
      Button('clear').onClick(() => {
        this.mapCollect.clear();
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

#### collections.Set例子
collections.Set触发UI刷新的API：add、clear，delete。

```ts
import { collections } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';
@Sendable
class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@ComponentV2
struct Page30 {
  set1: collections.Set<Info> = UIUtils.makeObserved(new collections.Set<Info>([new Info(10), new Info(20)]));

  build() {
    Column() {
      // 因为ForEach不支持迭代器，所以需要使用Array.from浅拷贝生成数组。
      // 但是浅拷贝生成的新的数组没有观察能力，需要重新调用makeObserved，为了ForEach组件在访问item的时候是可观察的数据，从而使得Set的value可以收集到Text组件id，从而使得其在改变的时候可以触发Text组件的变化。
      ForEach((UIUtils.makeObserved(Array.from(this.set1.values()))), (item: Info) => {
        Text(`${item.id}`).onClick(() =>{
          item.id++;
        })
      }, (item: Info, index) => item.id + index.toString())

      // add
      Button('add').onClick(() => {
        this.set1.add(new Info(30));
        console.log('size:' + this.set1.size)
      })
      // delete
      Button('delete').onClick(() => {
        let iterator = this.set1.keys();
        this.set1.delete(iterator.next().value);
      })
      // clear
      Button('clear').onClick(() => {
        this.set1.clear();
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

### makeObserved的入参为JSON.parse的返回值
JSON.parse返回Object，无法使用@Trace修饰其属性，可以使用makeObserved使其变为可观察数据。

```ts
import { JSON } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';

class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}

let test: Record<string, number> = { "a": 123};
let testJsonStr :string = JSON.stringify(test);

let test2: Record<string, Info> = { "a": new Info(20) };

let test2JsonStr :string = JSON.stringify(test2);

@Entry
@ComponentV2
struct Page31 {
  message: Record<string, number>  = UIUtils.makeObserved<Record<string, number>>(JSON.parse(testJsonStr) as Record<string, number>);

  message2: Record<string, Info>  = UIUtils.makeObserved<Record<string, Info>>(JSON.parse(test2JsonStr) as Record<string, Info>);

  build() {
    Column() {
      Text(`${this.message.a}`)
        .fontSize(50)
        .onClick(() => {
          this.message.a++;
        })
      Text(`${this.message2.a.id}`)
        .fontSize(50)
        .onClick(() => {
          this.message2.a.id++;
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

### makeObserved和V2装饰器连用
makeObserved可以和V2的装饰器一起使用。对于@Monitor和@Computed，需要注意makeObserved遇到@Observed和ObservedV2修饰的class会截断，会返回其自身，所以@Monitor或者@Computed不能写到class里，所以只能放到自定义组件里。

例子如下：
```ts
import { UIUtils } from '@kit.ArkUI';

class Info {
  id: number = 0;
  age: number = 20;

  constructor(id: number) {
    this.id = id;
  }
}

@Entry
@ComponentV2
struct Page31 {
  @Local message: Info = UIUtils.makeObserved(new Info(20));

  @Monitor('message.id')
  onStrChange(monitor: IMonitor) {
    console.log(`name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  @Computed
  get ageId() {
    console.info("---------Computed----------");
    return this.message.id + ' ' + this.message.age;
  }

  build() {
    Column() {
      Text(`id: ${this.message.id}`)
        .fontSize(50)
        .onClick(() =>{
          this.message.id++;
        })

      Text(`age: ${this.message.age}`)
        .fontSize(50)
        .onClick(() =>{
          this.message.age++;
        })

      Text(`age+id: ${this.ageId}`)
        .fontSize(50)

      Button('change Info').onClick(() => {
        this.message = UIUtils.makeObserved(new Info(200));
      })

      Page31Child({message: this.message})
    }
    .height('100%')
    .width('100%')
  }
}

@ComponentV2
struct Page31Child {
  @Param@Require message: Info;
  build() {
    Text(`Child id: ${this.message.id}`)
  }
}
```

### makeObserved在@Component内使用
makeObserved不能和V1的状态变量装饰器一起使用，但可以和@Component一起使用。

```ts
import { UIUtils } from '@kit.ArkUI';
class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@Component
struct Page30 {
  // @State一起用会抛出运行时异常
  message: Info = UIUtils.makeObserved(new Info(20));

  build() {
    RelativeContainer() {
      Text(`${this.message.id}`)
        .onClick(() => {
          this.message.id++;
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

