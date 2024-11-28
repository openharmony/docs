# PersistenceV2: 持久化储存UI状态

为了增强状态管理框架对持久化存储UI的能力，开发者可以使用PersistenceV2存储持久化的数据。AppStorageV2是运行时内存，但是在应用退出再次启动后，依然能保存选定的结果，是应用开发中十分常见的现象，这就需要用到PersistenceV2。

PersistenceV2是应用程序中的可选单例对象。此对象的作用是持久化存储UI相关的数据，以确保这些属性在应用程序重新启动时的值与应用程序关闭时的值相同。

PersistentV2提供状态变量持久化能力，开发者可以通过connect绑定同一个key，在状态变量变换和应用冷启动时，实现持久化能力。

在阅读本文当前，建议提前阅读：[\@ComponentV2](./arkts-new-componentV2.md)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，配合阅读：[PersistentV2-API文档](../reference/apis-arkui/js-apis-StateManagement.md#persistencev2)

>**说明：**
>
>PersistenceV2从API version 12开始支持。
>


## 概述

PersistenceV2是在应用UI启动时会被创建的单例。它的目的是为了提供应用状态数据的中心存储，这些状态数据在应用级别都是可访问的。数据通过唯一的键字符串值访问。不同于AppStorageV2，PersistenceV2还将最新数据储存在设备磁盘上（持久化）。这意味着，应用退出再次启动后，依然能保存选定的结果。

对于与PersistenceV2关联的[\@ObservedV2](arkts-new-observedV2-and-trace.md)对象，该对象的[\@Trace](arkts-new-observedV2-and-trace.md)属性的变化，会触发**整个关联对象的自动持久化**；非[\@Trace](arkts-new-observedV2-and-trace.md)属性的变化则不会，如有必要，可调用PersistenceV2 API手动持久化。

PersistenceV2可以和UI组件同步，且可以在应用业务逻辑中被访问。

PersistenceV2支持应用的[主线程](../application-models/thread-model-stage.md)内多个UIAbility实例间的状态共享。


## 使用说明

### connect：创建或获取储存的数据

```JavaScript
static connect<T extends object>(
    type: TypeConstructorWithArgs<T>,
    keyOrDefaultCreator?: string | StorageDefaultCreator<T>,
    defaultCreator?: StorageDefaultCreator<T> 
): T | undefined;
```

| connect      | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | type：指定的类型，若未指定key，则使用type的name作为key；</br > keyOrDefaultCreater：指定的key，或者是默认数据的构造器；</br > defaultCreator：默认数据的构造器。                                          |
| 返回值       | 创建或获取数据成功时，返回数据；否则返回undefined。 |

>**说明：**
>
>1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器（第二个参数非法也使用第三个参数作为默认构造器）；
>
>2、确保数据已经存储在PersistenceV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常；
>
>3、同一个key，connect不同类型的数据会导致应用异常，应用需要确保类型匹配；
>
>4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的；
>
>5、关联[\@Observed](arkts-observed-and-objectlink.md)对象时，由于该类型的name属性未定义，需要指定key或者自定义name属性。

### remove：删除指定key的储存数据

```JavaScript
static remove<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| remove       | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | keyOrType：需要删除的key；如果指定的是type类型，删除的key为type的name。                                          |
| 返回值       | 无。 |

>**说明：**
>
>删除PersistenceV2中不存在的key会报警告。

### keys：返回所有PersistenceV2中的key

```JavaScript
static keys(): Array<string>;
```

| keys         | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | 无。                                         |
| 返回值       | 所有PersistenceV2中的key。 |


### save：手动持久化数据

```JavaScript
static save<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| save         | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | keyOrType：需要手动持久化的key；如果指定的是type类型，key为type的name。                                          |
| 返回值       | 无。 |

>**说明：**
>
>由于非[\@Trace](arkts-new-observedV2-and-trace.md)的数据改变不会触发PersistenceV2的自动持久化，如有必要，可调用该接口持久化对应key的数据；
>
>手动持久化当前内存中不处于connect状态的key是无意义的。


### notifyOnError：响应序列化或反序列化失败的回调

```JavaScript
static notifyOnError(callback: PersistenceErrorCallback | undefined): void;
```

| notifyOnError| 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | callback：当序列化或者反序列化失败时，执行该回调；若传入undefined，取消该回调。|
| 返回值       | 无。 |

>**说明：**
>
>将数据存入磁盘时，需要对数据进行序列化；当某个key序列化失败时，错误是不可预知的；可调用该接口捕获异常。


## 使用限制

1、需要配合UI使用（UI线程），不能在其他线程使用，如不支持@Sendable；

2、不支持collections.Set、collections.Map等类型；

3、不支持非buildin类型，如PixelMap、NativePointer、ArrayList等Native类型；

4、单个key支持数据大小约8k，过大会导致持久化失败；

5、持久化的数据必须是class对象，不能是容器（如Array、Set、Map），不能是buildin的构造对象（如Date、Number）；

6、不支持循环引用的对象；

7、只有[\@Trace](arkts-new-observedV2-and-trace.md)的数据改变会触发自动持久化，如V1状态变量、[\@Observed](arkts-observed-and-objectlink.md)对象、普通数据的改变不会触发持久化；

8、不宜大量持久化数据，可能会导致页面卡顿。

## 使用场景

### 在两个页面之间存储数据

页面1
```ts
import { router, PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@Entry
@ComponentV2
struct Page1 {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
  // 对于需要换connect对象的prop属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Button('Go to page2')
        .onClick(() => {
          router.pushUrl({
            url: 'pages/Page2'
          })
        })

      Button('Page1 connect the key Sample')
        .onClick(() => {
          // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
          // 不建议对prop属性换connect的对象
          this.prop = PersistenceV2.connect(Sample, 'Sample', () => new Sample())!;
        })

      Button('Page1 remove the key Sample')
        .onClick(() => {
          // 从PersistenceV2中删除后，prop将不会再与key为Sample的值关联
          PersistenceV2.remove(Sample);
        })

      Button('Page1 save the key Sample')
        .onClick(() => {
          // 如果处于connect状态，持久化key为Sample的键值对
          PersistenceV2.save(Sample);
        })

      Text(`Page1 add 1 to prop.p1: ${this.prop.f.p1}`)
        .fontSize(30)
        .onClick(() => {
          this.prop.f.p1++;
        })

      Text(`Page1 add 1 to prop.p2: ${this.prop.f.p2}`)
        .fontSize(30)
        .onClick(() => {
          // 页面不刷新，但是p2的值改变了
          this.prop.f.p2++;
        })

      // 获取当前PersistenceV2里面的所有key
      Text(`all keys in PersistenceV2: ${PersistenceV2.keys()}`)
        .fontSize(30)
    }
  }
}
```

页面2
```ts
import { PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Entry
@ComponentV2
struct Page2 {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
  // 对于需要换connect对象的prop属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Button('Page2 connect the key Sample1')
        .onClick(() => {
          // 在PersistenceV2中创建一个key为Sample1的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
          // 不建议对prop属性换connect的对象
          this.prop = PersistenceV2.connect(Sample, 'Sample1', () => new Sample())!;
        })

      Text(`Page2 add 1 to prop.p1: ${this.prop.f.p1}`)
        .fontSize(30)
        .onClick(() => {
          this.prop.f.p1++;
        })

      Text(`Page2 add 1 to prop.p2: ${this.prop.f.p2}`)
        .fontSize(30)
        .onClick(() => {
          // 页面不刷新，但是p2的值改变了；只有重新初始化才会改变
          this.prop.f.p2++;
        })

      // 获取当前PersistenceV2里面的所有key
      Text(`all keys in PersistenceV2: ${PersistenceV2.keys()}`)
        .fontSize(30)
    }
  }
}
```

数据页面
```ts
import { Type } from '@kit.ArkUI';

// 数据中心
@ObservedV2
class SampleChild {
  @Trace p1: number = 0;
  p2: number = 10;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace f: SampleChild = new SampleChild();
}
```

