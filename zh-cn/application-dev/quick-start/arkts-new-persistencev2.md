# PersistenceV2: 持久化储存UI状态

为了增强状态管理框架对持久化存储UI的能力，开发者可以使用PersistenceV2存储持久化的数据。

PersistenceV2是应用程序中的可选单例对象。此对象的作用是持久化存储UI相关的数据，以确保这些属性在应用程序重新启动时的值与应用程序关闭时的值相同。

PersistenceV2提供状态变量持久化能力，开发者可以通过connect或者globalConnect绑定同一个key，在状态变量变换和应用冷启动时，实现持久化能力。

在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-new-componentV2.md)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，配合阅读：[PersistentV2-API文档](../reference/apis-arkui/js-apis-StateManagement.md#persistencev2)。

>**说明：**
>
>PersistenceV2从API version 12开始支持。
>
>globalConnect从API version 18开始支持，行为和connect保持一致，唯一的区别为connect的底层存储路径为module级别的路径，而globalConnect的底层存储路径为应用级别，详细区别见使用场景[在不同的module中使用connect和globalConnect](#在不同的module中使用connect和globalconnect)。


## 概述

PersistenceV2是在应用UI启动时会被创建的单例。它的目的是为了提供应用状态数据的中心存储，这些状态数据在应用级别都是可访问的。数据通过唯一的键字符串值访问。不同于AppStorageV2，PersistenceV2还将最新数据储存在设备磁盘上（持久化）。这意味着，应用退出再次启动后，依然能保存选定的结果。

对于与PersistenceV2关联的[\@ObservedV2](./arkts-new-observedV2-and-trace.md)对象，该对象的[\@Trace](./arkts-new-observedV2-and-trace.md)属性的变化，会触发**整个关联对象的自动持久化**；非[\@Trace](./arkts-new-observedV2-and-trace.md)属性的变化则不会，如有必要，可调用PersistenceV2 API手动持久化。

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
| 参数         | type：指定的类型，若未指定key，则使用type的name作为key；</br > keyOrDefaultCreator：指定的key，或者是默认数据的构造器；</br > defaultCreator：默认数据的构造器。                                          |
| 返回值       | 创建或获取数据成功时，返回数据；否则返回undefined。 |

>**说明：**
>
>1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器（第二个参数非法也使用第三个参数作为默认构造器）。
>
>2、确保数据已经存储在PersistenceV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常。
>
>3、同一个key，connect不同类型的数据会导致应用异常，应用需要确保类型匹配。
>
>4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的。
>
>5、关联[\@Observed](./arkts-observed-and-objectlink.md)对象时，由于该类型的name属性未定义，需要指定key或者自定义name属性。
>
>6、数据存储路径为module级别，即哪个module调用了connect，数据副本存入对应module的持久化文件中。如果多个module使用相同的key，则数据为最先使用connect的module，并且PersistenceV2中的数据也会存入最先使用connect的module里。
>
>7、因为存储路径在应用第一个ability启动时就已确定，为该ability所属的module。如果一个ability调用了connect，并且该ability能被不同module的拉起， 那么ability存在多少种启动方式，就会有多少份数据副本。

### globalConnect：创建或获取储存的数据

```ts
// globalConnect 接口
static globalConnect<T extends object>(
    type: ConnectOptions<T>
  ): T | undefined;
```

```ts
// ConnectOptions参数
class ConnectOptions<T extends object> {
  type: TypeConstructorWithArgs<T>;	// 必选，指定的类型；
  key?: string;	// 可选，传入的key，若未指定key，则使用type的name作为key；
  defaultCreator?: StorageDefaultCreator<T>;	// 默认数据的构造器，建议填写；
  areaMode?: contextConstant.AreaMode;	// 可选，加密参数；
}
```

| globalConnect | 说明                                                      |
| ------------- | --------------------------------------------------------- |
| 参数          | type：传入的connect参数，详细说明见ConnectOptions参数说明。 |
| 返回值        | 创建或获取数据成功时，返回数据；否则返回undefined。       |

| ConnectOptions参数 | 说明                                                         |
| :----------------: | :----------------------------------------------------------- |
|        type        | TypeConstructorWithArgs\<T\>，必选参数，指定的类型。         |
|        key         | string，传入的key，不传则使用type的名字作为key。             |
|   defaultCreator   | StorageDefaultCreator\<T\>，默认数据的构造器，建议传递，如果globalConnect是第一次连接key，不传会报错。 |
|      areaMode      | contextConstant.AreaMode，加密级别：EL1-EL5，详见[加密级别](../application-models/application-context-stage.md#获取和修改加密分区)，对应数值：0-4，不传时默认为EL2，不同加密级别对应不同的加密分区，即不同的存储路径，传入的加密等级数值不在0-4会直接运行crash。 |

> **说明：**
>
> 1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器（第二个参数非法也使用第三个参数作为默认构造器）。
>
> 2、确保数据已经存储在PersistenceV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常。
>
> 3、同一个key，globalConnect不同类型的数据会导致应用异常，应用需要确保类型匹配。
>
> 4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的。
>
> 5、关联[\@Observed](./arkts-observed-and-objectlink.md)对象时，因为该类型的name属性未定义，需要指定key或者自定义name属性。
>
> 6、数据的存储为应用级别的路径，不同module使用相同的key和相同的加密分区进行globalConnect，存储的数据副本应用仅有一份。
>
> 7、globalConnect使用同一个key但设置了不同的加密级别，数据为第一个使用globalConnect的加密级别，并且PersistenceV2中的数据也会存入最先使用key的加密级别。
>
> 8、connect和globalConnect不建议混用，因为数据副本路径不同，如果混用，则key不可以一样，否则会crash。
>
> 9、EL5加密要想生效，需要开发者在module.json中配置字段ohos.permission.PROTECT_SCREEN_LOCK_DATA，使用说明见[声明权限](../security/AccessToken/declare-permissions.md)。

### remove：删除指定key的储存数据

```ts
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

```ts
static keys(): Array<string>;
```

| keys         | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | 无。                                         |
| 返回值       | 所有PersistenceV2中的key。 |

> **说明：**
>
> keys会从返回module级别存储路径和应用级别存储路径中的所有key。

### save：手动持久化数据

```ts
static save<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| save         | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | keyOrType：需要手动持久化的key；如果指定的是type类型，key为type的name。                                          |
| 返回值       | 无。 |

>**说明：**
>
>由于非[\@Trace](./arkts-new-observedV2-and-trace.md)的数据改变不会触发PersistenceV2的自动持久化，如有必要，可调用该接口持久化对应key的数据。
>
>手动持久化当前内存中不处于connect状态的key是无意义的。


### notifyOnError：响应序列化或反序列化失败的回调

```ts
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

1、需要配合UI使用（UI线程），不能在其他线程使用，如不支持@Sendable。

2、不支持collections.Set、collections.Map等类型。

3、不支持非buildin类型，如PixelMap、NativePointer、ArrayList等Native类型。

4、单个key支持数据大小约8k，过大会导致持久化失败。

5、持久化的数据必须是class对象，不能是容器（如Array、Set、Map），不能是buildin的构造对象（如Date、Number）。

6、不支持循环引用的对象。

7、只有[\@Trace](./arkts-new-observedV2-and-trace.md)的数据改变会触发自动持久化，如V1状态变量、[\@Observed](./arkts-observed-and-objectlink.md)对象、普通数据的改变不会触发持久化。

8、不宜大量持久化数据，可能会导致页面卡顿。

9、connect和globalConnect不建议混用，如果混用，key不能一样，否则应用crash。

10、不支持存储基本类型，如string、number、boolean等。

## 使用场景

### 在两个页面之间存储数据

数据页面
```ts
// Sample.ets
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

页面1
```ts
// Page1.ets
import { PersistenceV2 } from '@kit.ArkUI';
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
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Button('Go to page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
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
}
```

页面2
```ts
// Page2.ets
import { PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
  // 对于需要换connect对象的prop属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
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
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page2页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。
```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "PersistenceV2 example"
      }
    }
  ]
}
```

### 使用globalConnect存储数据

```ts
import { PersistenceV2, Type, ConnectOptions } from '@kit.ArkUI';
import { contextConstant } from '@kit.AbilityKit';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace childId: number = 0;
  groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // key不传入尝试用为type的name作为key，加密参数不传入默认加密等级为EL2
  @Local p: Sample = PersistenceV2.globalConnect({type: Sample, defaultCreator:() => new Sample()})!;

  // 使用key:global1连接，传入加密等级为EL1
  @Local p1: Sample = PersistenceV2.globalConnect({type: Sample, key:'global1', defaultCreator:() => new Sample(), areaMode: contextConstant.AreaMode.EL1})!;

  // 使用key:global2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
  options: ConnectOptions<Sample> = {type: Sample, key: 'global2', defaultCreator:() => new Sample()};
  @Local p2: Sample = PersistenceV2.globalConnect(this.options)!;

  // 使用key:global3连接，直接写加密数值，范围只能在0-4，否则运行会crash,例如加密设置为EL3
  @Local p3: Sample = PersistenceV2.globalConnect({type: Sample, key:'global3', defaultCreator:() => new Sample(), areaMode: 3})!;

  build() {
    Column() {
      /**************************** 显示数据 **************************/
      // 被@Trace修饰的数据可以自动持久化进磁盘
      Text('Key Sample: ' + this.p.father.childId.toString())
        .onClick(()=> {
          this.p.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
      Text('Key global1: ' + this.p1.father.childId.toString())
        .onClick(()=> {
          this.p1.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
      Text('Key global2: ' + this.p2.father.childId.toString())
        .onClick(()=> {
          this.p2.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
      Text('Key global3: ' + this.p3.father.childId.toString())
        .onClick(()=> {
          this.p3.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
      /**************************** keys接口 **************************/
      // keys 本身不会刷新，需要借助状态变量刷新
      Text('Persist keys: ' + PersistenceV2.keys().toString() + ' refresh: ' + this.refresh)
        .onClick(() => {
          this.refresh += 1;
        })
        .fontSize(25)

      /**************************** remove接口 **************************/
      Text('Remove key Sample: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p失去联系，之后p无法存储，即使reconnect
          PersistenceV2.remove(Sample);
          this.refresh += 1;
        })
        .fontSize(25)
      Text('Remove key global1: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p失去联系，之后p无法存储，即使reconnect
          PersistenceV2.remove('global1');
          this.refresh += 1;
        })
        .fontSize(25)
      Text('Remove key global2: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p失去联系，之后p无法存储，即使reconnect
          PersistenceV2.remove('global2');
          this.refresh += 1;
        })
        .fontSize(25)
      Text('Remove key global3: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p失去联系，之后p无法存储，即使reconnect
          PersistenceV2.remove('global3');
          this.refresh += 1;
        })
        .fontSize(25)
      /**************************** reConnect **************************/
      // 重新连接也无法和之前的状态变量建立联系，因此无法保存数据
      Text('ReConnect key global2: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p失去联系，之后p无法存储，即使reconnect
          PersistenceV2.globalConnect(this.options);
          this.refresh += 1;
        })
        .fontSize(25)

      /**************************** save接口 **************************/
      Text('not save key Sample: ' + this.p.father.groupId.toString() + ' refresh: ' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储
          this.p.father.groupId += 1;
          this.refresh += 1;
        })
        .fontSize(25)
      Text('save key Sample: ' + this.p.father.groupId.toString() + ' refresh: ' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用key存储
          this.p.father.groupId += 1;
          PersistenceV2.save(Sample);
          this.refresh += 1;
        })
        .fontSize(25)
    }
    .width('100%')
  }
}
```

### 在不同的module中使用connect和globalConnect

**connect的存储路径需要注意以下两点：**

1、connect使用module级别的存储路径，以最先启动的module的路径作为存储路径，从内存回写磁盘时会回写到第一个连接该module的路径。应用如果之后先从另一个module启动，则会以新module的路径作为存储路径。

2、当不同module使用相同的key时，哪个module先启动，数据就为哪个module中保存的键值对，回写到对应的module中。

**globalConnect的存储路径需要注意：**

globalConnect虽然是应用级别的路径，但是可以设置不同的加密分区，不同加密分区即代表不同的存储路径。connect不支持设置加密分区，但是module自身切换加密级别时，module存储路径也会切换成对应加密分区路径。

示例代码如下：开发者需要在项目基础上，新建一个module，并按照示例代码跳转到新module中。

```ts
// 模块1
import { PersistenceV2, Type } from '@kit.ArkUI';
import { contextConstant, common, Want } from '@kit.AbilityKit';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace childId: number = 0;
  groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:global1连接，传入加密等级为EL1
  @Local p1: Sample = PersistenceV2.globalConnect({type: Sample, key:'globalConnect1', defaultCreator:() => new Sample()})!;

  // 使用key:global2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
  @Local p2: Sample = PersistenceV2.connect(Sample, 'connect2', () => new Sample())!;

  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Column() {
      /**************************** 显示数据 **************************/
      Text('Key globalConnect1: ' + this.p1.father.childId.toString())
        .onClick(()=> {
          this.p1.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
      Text('Key connect2: ' + this.p2.father.childId.toString())
        .onClick(()=> {
          this.p2.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)

      /**************************** 跳转 **************************/
      Button('跳转newModule').onClick(() => { // 不同module之间使用，建议使用globalConnect
        let want: Want = {
          deviceId: '', // deviceId为空代表本设备
          bundleName: 'com.example.myPersistenceV2', // 在app.json5中查看
          moduleName: 'newModule', // 在需要跳转的moudle的module.json5中查看，非必选参数
          abilityName: 'NewModuleAbility',  // 跳转启动的abiltity，在跳转模块对应的ability.ets文件中查看
          uri:'src/main/ets/pages/Index'
        }
        // context为调用方UIAbility的UIAbilityContext
        this.context.startAbility(want).then(() => {
          console.info('start ability success');
        }).catch((err: Error) => {
          console.error(`start ability failed. code is ${err.name}, message is ${err.message}`);
        })
      })
    }
    .width('100%')
    .borderWidth(3)
    .borderColor(Color.Blue)
    .margin({top: 5, bottom: 5})
  }
}
```

```ts
// 模块2
import { PersistenceV2, Type } from '@kit.ArkUI';
import { contextConstant } from '@kit.AbilityKit';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace childId: number = 0;
  groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local a: number = 0;
  // 使用key:global1连接，传入加密等级为EL1
  @Local p1: Sample = PersistenceV2.globalConnect({type: Sample, key:'globalConnect1', defaultCreator:() => new Sample()})!;

  // 使用key:global2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
  @Local p2: Sample = PersistenceV2.connect(Sample, 'connect2', () => new Sample())!;

  build() {
    Column() {
      /**************************** 显示数据 **************************/
      Text('Key globalConnect1: ' + this.p1.father.childId.toString())
        .onClick(()=> {
          this.p1.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
      Text('Key connect2: ' + this.p2.father.childId.toString())
        .onClick(()=> {
          this.p2.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)
    }
    .width('100%')
  }
}
```

当开发者对newModule使用不同启动方式会有以下现象：

*   开发者直接启动newModule，分别修改globalConnect1和connect2绑定的变量，例如将childId都改成5。
* 应用退出并清空后台，启动模块entry，通过跳转按键启动newModule，会发现globalConnect1值为5，而connect2值为1未修改。
* globalConnect为应用级别存储，对于一个key，整个应用在对应加密分区只有一份存储路径；connect为module级别的存储路径，会因为module的启动方式不同而在各自的加密分区对应不同的存储路径。

## 使用建议

建议开发者使用新接口globalConnect创建和获取数据。globalConnect的存储规格和内存规格一致，对于应用只有一份，并且支持设置加密级别，不需要去切换ability的加密才能设置数据的加密级别。当然如果开发者应用不涉及多模块，保持使用connect也不会有影响。

### connect向globalConnect迁移实现

```ts
// 使用connect存储数据
import { PersistenceV2, Type } from '@kit.ArkUI';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace childId: number = 0;
  groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:connect2存储
  @Local p: Sample = PersistenceV2.connect(Sample, 'connect2', () => new Sample())!;

  build() {
    Column({space: 5}) {
      /**************************** 显示数据 **************************/
      Text('Key connect2: ' + this.p.father.childId.toString())
        .onClick(() => {
          this.p.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)

      /**************************** save接口 **************************/
      // 非状态变量需要借助状态变量refresh才能刷新
      Text('save key Sample: ' + this.p.father.groupId.toString() + ' refresh:' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用key存储
          this.p.father.groupId += 1;
          PersistenceV2.save('connect2');
          this.refresh += 1
        })
        .fontSize(25)
    }
    .width('100%')
  }
}
```

```ts
// 迁移到globalConnect
import { PersistenceV2, Type } from '@kit.ArkUI';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace childId: number = 0;
  groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace father: SampleChild = new SampleChild();
}

// 用于判断是否完成数据迁移的辅助数据
@ObservedV2
class StorageState {
  @Trace isCompleteMoving: boolean = false;
}

function move() {
  let movingState = PersistenceV2.globalConnect({type: StorageState, defaultCreator: () => new StorageState()})!;
  if (!movingState.isCompleteMoving) {
    let p: Sample = PersistenceV2.connect(Sample, 'connect2', () => new Sample())!;
    PersistenceV2.remove('connect2');
    let p1 = PersistenceV2.globalConnect({type: Sample, key: 'connect2', defaultCreator: () => p})!;  // 使用默认构造函数也可以
    // 赋值数据，@Trace修饰的会自动保存
    p1.father = p.father;
    // 将迁移标志设置为true
    movingState.isCompleteMoving = true;
  }
}

move();

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:connect2存入数据
  @Local p: Sample = PersistenceV2.globalConnect({type: Sample, key:'connect2', defaultCreator:() => new Sample()})!;

  build() {
    Column({space: 5}) {
      /**************************** 显示数据 **************************/
      Text('Key connect2: ' + this.p.father.childId.toString())
        .onClick(() => {
          this.p.father.childId += 1;
        })
        .fontSize(25)
        .fontColor(Color.Red)

      /**************************** save接口 **************************/
      // 非状态变量需要借助状态变量refresh才能刷新
      Text('save key connect2: ' + this.p.father.groupId.toString() + ' refresh:' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用key存储
          this.p.father.groupId += 1;
          PersistenceV2.save('connect2');
          this.refresh += 1
        })
        .fontSize(25)
    }
    .width('100%')
  }
}
```

connect向globalConnect迁移，需要将key绑定的value赋值给globalConnect进行存储，之后当自定义组件使用globalConnect连接时，globalConnect绑定的数据即为之前使用connect保存的数据，开发者可以自定义move函数，并将其放在合适位置迁移即可。