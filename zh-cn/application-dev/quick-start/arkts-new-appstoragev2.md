# AppStorageV2: 应用全局UI状态存储

为了增强状态管理框架对应用全局UI状态变量存储的能力，开发者可以使用AppStorageV2存储应用全局UI状态变量数据。

AppStorageV2是提供状态变量在应用级全局共享的能力，开发者可以通过connect绑定同一个key，进行跨ability的数据共享。

在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-new-componentV2.md)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，配合阅读：[AppStorageV2-API文档](../reference/apis-arkui/js-apis-StateManagement.md#appstoragev2)。

>**说明：**
>
>AppStorageV2从API version 12开始支持。
>


## 概述

AppStorageV2是在应用UI启动时会被创建的单例。它的目的是为了提供应用状态数据的中心存储，这些状态数据在应用级别都是可访问的。AppStorageV2将在应用运行过程保留其数据。数据通过唯一的键字符串值访问。

AppStorageV2可以和UI组件同步，且可以在应用业务逻辑中被访问。

AppStorageV2支持应用的[主线程](../application-models/thread-model-stage.md)内多个UIAbility实例间的状态共享。


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
>1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器（第二个参数非法也使用第三个参数作为默认构造器）。
>
>2、确保数据已经存储在AppStorageV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常。
>
>3、同一个key，connect不同类型的数据会导致应用异常，应用需要确保类型匹配。
>
>4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的。
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
>删除AppStorageV2中不存在的key会报警告。

### keys：返回所有AppStorageV2中的key

```JavaScript
static keys(): Array<string>;
```

| keys         | 说明                                                  |
| ------------ | ----------------------------------------------------- |
| 参数         | 无。                                         |
| 返回值       | 所有AppStorageV2中的key。 |


## 使用限制

1、需要配合UI使用（UI线程），不能在其他线程使用，如不支持@Sendable。

2、不支持collections.Set、collections.Map等类型。

3、不支持非buildin类型，如PixelMap、NativePointer、ArrayList等Native类型。

## 使用场景

### 在两个页面之间存储数据

页面1
```ts
import { AppStorageV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Entry
@ComponentV2
struct Page1 {
  // 在AppStorageV2中创建一个key为Sample的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
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
            // 在AppStorageV2中创建一个key为Sample的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
            this.prop = AppStorageV2.connect(Sample, 'Sample', () => new Sample())!;
          })

        Button('Page1 remove the key Sample')
          .onClick(() => {
            // 从AppStorageV2中删除后，prop将不会再与key为Sample的值关联
            AppStorageV2.remove(Sample);
          })

        Text(`Page1 add 1 to prop.p1: ${this.prop.p1}`)
          .fontSize(30)
          .onClick(() => {
            this.prop.p1++;
          })

        Text(`Page1 add 1 to prop.p2: ${this.prop.p2}`)
          .fontSize(30)
          .onClick(() => {
            // 页面不刷新，但是p2的值改变了
            this.prop.p2++;
          })

        // 获取当前AppStorageV2里面的所有key
        Text(`all keys in AppStorage: ${AppStorageV2.keys()}`)
          .fontSize(30)
      }
    }
  }
}
```

页面2
```ts
import { AppStorageV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  // 在AppStorageV2中创建一个key为Sample的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Button('Page2 connect the key Sample1')
          .onClick(() => {
            // 在AppStorageV2中创建一个key为Sample1的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
            this.prop = AppStorageV2.connect(Sample, 'Sample1', () => new Sample())!;
          })

        Text(`Page2 add 1 to prop.p1: ${this.prop.p1}`)
          .fontSize(30)
          .onClick(() => {
            this.prop.p1++;
          })

        Text(`Page2 add 1 to prop.p2: ${this.prop.p2}`)
          .fontSize(30)
          .onClick(() => {
            // 页面不刷新，但是p2的值改变了；只有重新初始化才会改变
            this.prop.p2++;
          })

        // 获取当前AppStorageV2里面的所有key
        Text(`all keys in AppStorage: ${AppStorageV2.keys()}`)
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
      "pageSourceFile": "src/main/ets/pages/PersistenceV2-2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "PersistenceV2 example"
      }
    }
  ]
}
```

数据页面
```ts
// 数据中心
@ObservedV2
export class Sample {
  @Trace p1: number = 0;
  p2: number = 10;
}
```
