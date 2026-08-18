# AppStorageV2: 应用全局UI状态存储
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了增强状态管理框架对应用全局UI状态变量的共享能力，开发者可以使用AppStorageV2存储应用全局UI的状态变量数据。

AppStorageV2提供应用级全局共享状态变量的能力，开发者可以通过connect绑定同一个key，进行跨UIAbility的数据共享。

在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-create-custom-components.md#componentv2)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，配合阅读：[AppStorageV2-API文档](../../reference/apis-arkui/js-apis-stateManagement.md#appstoragev2)。

>**说明：**
>
>AppStorageV2从API version 12开始支持。
>

## 概述

AppStorageV2是在应用UI启动时会被创建的单例。它用于提供应用状态数据的中心存储，这些状态数据在应用级别都是可访问的。AppStorageV2将在应用运行过程保留其数据。数据通过唯一的键字符串值访问。需要注意的是，AppStorage与AppStorageV2之间的数据互不共享。

通过修改AppStorageV2的connect接口返回值，可以实现数据与UI组件的同步。

AppStorageV2支持应用的[主线程](../../application-models/thread-model-stage.md)内多个UIAbility实例间的状态共享。

## 使用说明

- connect：创建或获取存储的数据。

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

- remove：删除指定key的存储数据。

>**说明：**
>
>删除AppStorageV2中不存在的key会报警告。

- keys：返回所有AppStorageV2中的key。

以上接口详细描述请参考状态管理API文档中的[AppStorageV2](../../reference/apis-arkui/js-apis-stateManagement.md#appstoragev2)。


## 使用限制

1、只支持class类型，否则会抛出运行时报错，从API version 23开始，将返回错误码[140103](../../reference/apis-arkui/errorcode-stateManagement.md#140103-appstoragev2和persistencev2使用不支持的数据类型)。

2、需要配合UI使用（UI线程），不能在其他线程使用，如不支持[@Sendable](../../arkts-utils/arkts-sendable.md)。

3、不支持[collections.Set](../../reference/apis-arkts/arkts-apis-arkts-collections-Set.md)、[collections.Map](../../reference/apis-arkts/arkts-apis-arkts-collections-Map.md)等类型。

4、不支持非built-in类型，如[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)、NativePointer、[ArrayList](../../reference/apis-arkts/js-apis-arraylist.md)等Native类型。

5、不支持存储基本类型，如string、number、boolean等。注意：不支持存储基本类型意味着connect接口传入的类型不能是基本类型，但connect传入的class中可以包含基本类型。

## 使用场景

### 使用AppStorageV2

AppStorageV2使用connect接口即可实现对AppStorageV2中数据的修改和同步，如果修改的数据被@Trace装饰，该数据的修改会同步更新UI。需要注意的是，使用remove接口只会将数据从AppStorageV2中删除，不影响组件中已创建的数据，详见以下示例代码：

<!-- @[appStorageV2_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AppStorageV2/entry/src/main/ets/pages/AppStorageV2.ets) -->

``` TypeScript
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
class Message {
  @Trace public userID: number;
  public userName: string;

  constructor(userID?: number, userName?: string) {
    this.userID = userID ?? 1;
    this.userName = userName ?? 'Jack';
  }
}

@Entry
@ComponentV2
struct Index {
  // 使用connect在AppStorageV2中创建一个key为Message的对象
  // 修改connect的返回值即可同步回AppStorageV2
  @Local message: Message = AppStorageV2.connect<Message>(Message, () => new Message())!;

  build() {
    Column() {
      // 修改@Trace装饰的类属性，UI能同步刷新
      Button(`Index userID: ${this.message.userID}`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.userID += 1;
        })
      // 修改非@Trace装饰的类属性，UI不会同步刷新，但修改的类属性已同步回AppStorageV2
      Button(`Index userName: ${this.message.userName}`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.userName += 'suf';
        })
      // remove key Message, 会从AppStorageV2中删除key为Message的对象
      // remove之后，修改父组件的userID，子组件能同步变化，因为remove只是从AppStorageV2删除，不会影响组件中已存在的数据
      Button('remove key: Message')
        .width(300)
        .margin(10)
        .onClick(() => {
          AppStorageV2.remove<Message>(Message);
        })
      // connect key Message, 会从AppStorageV2中添加key为Message的对象
      // remove之后，重新添加，修改父子组件的userID，可以发现数据已经不同步，子组件重新connect之后，数据一致
      Button('connect key: Message')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message = AppStorageV2.connect<Message>(Message, () => new Message(5, 'Rose'))!;
        })
      Divider()
      Child()
    }
    .width('100%')
    .height('100%')
  }
}

@ComponentV2
struct Child {
  // 使用connect在AppStorageV2中取出一个key为Message的对象，已在父组件中创建
  @Local message: Message = AppStorageV2.connect<Message>(Message, () => new Message())!;
  @Local name: string = this.message.userName;

  build() {
    Column() {
      // 修改@Trace装饰的类属性，UI同步刷新，父组件能感知该变化
      Button(`Child userID: ${this.message.userID}`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.userID += 5;
        })
      // 修改父组件中的userName属性，点击name可以同步父组件的类属性修改
      Button(`Child name: ${this.name}`)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.name = this.message.userName;
        })
      // remove key Message, 会从AppStorageV2中删除key为Message的对象
      // remove之后，修改父子组件的userID，父子组件同步变化，因为remove只是从AppStorageV2删除，不会影响组件中已存在的数据
      Button('remove key: Message')
        .width(300)
        .margin(10)
        .onClick(() => {
          AppStorageV2.remove<Message>(Message);
        })
      // connect key Message, 会从AppStorageV2中添加key为Message的对象
      // remove之后，重新添加，修改父子组件的userID，可以发现数据已经不同步，父组件重新connect之后，数据一致
      Button('connect key: Message')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message = AppStorageV2.connect<Message>(Message, () => new Message(10, 'Lucy'))!;
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![appstoragev2-sync-0](./figures/appstoragev2-sync-0.gif)

### 在两个页面之间存储数据

数据页面
<!-- @[appStorageV2_sample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AppStorageV2/entry/src/main/ets/pages/Sample.ets) -->

``` TypeScript
// 数据中心
// Sample.ets
@ObservedV2
export class Sample {
  @Trace public p1: number = 0;
  public p2: number = 10;
}
```

页面1
<!-- @[appStorageV2_pageOne](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AppStorageV2/entry/src/main/ets/pages/PageOne.ets) -->

``` TypeScript
import { AppStorageV2 } from '@kit.ArkUI';
import { Sample } from './Sample';

@Entry
@ComponentV2
struct PageOne {
  // 在AppStorageV2中创建一个key为Sample的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Button('Go to pageTwo')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.pageStack.pushPathByName('PageTwo', null);
          })

        Button('PageOne connect the key Sample')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 在AppStorageV2中创建一个key为Sample的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
            this.prop = AppStorageV2.connect(Sample, 'Sample', () => new Sample())!;
          })

        Button('PageOne remove the key Sample')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 从AppStorageV2中删除后，prop将不会再与key为Sample的值关联
            AppStorageV2.remove(Sample);
          })

        Text(`PageOne add 1 to prop.p1: ${this.prop.p1}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            this.prop.p1++;
          })

        Text(`PageOne add 1 to prop.p2: ${this.prop.p2}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            // 页面不刷新，但是p2的值改变了
            this.prop.p2++;
          })

        // 获取当前AppStorageV2里面的所有key
        Text(`all keys in AppStorageV2: ${AppStorageV2.keys()}`)
          .fontSize(30)
          .margin(10)
      }
    }
  }
}
```

页面2
<!-- @[appStorageV2_pageTwo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AppStorageV2/entry/src/main/ets/pages/PageTwo.ets) -->

``` TypeScript
import { AppStorageV2 } from '@kit.ArkUI';
import { Sample } from './Sample';

@Builder
export function PageTwoBuilder() {
  PageTwo()
}

@ComponentV2
struct PageTwo {
  // 在AppStorageV2中创建一个key为Sample的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Button('PageTwo connect the key Sample1')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 在AppStorageV2中创建一个key为Sample1的键值对（如果存在，则返回AppStorageV2中的数据），并且和prop关联
            this.prop = AppStorageV2.connect(Sample, 'Sample1', () => new Sample())!;
          })

        Text(`PageTwo add 1 to prop.p1: ${this.prop.p1}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            this.prop.p1++;
          })

        Text(`PageTwo add 1 to prop.p2: ${this.prop.p2}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            // 页面不刷新，但是p2的值改变了；只有重新初始化才会改变
            this.prop.p2++;
          })

        // 获取当前AppStorageV2里面的所有key
        Text(`all keys in AppStorageV2: ${AppStorageV2.keys()}`)
          .fontSize(30)
          .margin(10)
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为PageTwo页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。

```json
{
  "routerMap": [
    {
      "name": "PageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder",
      "data": {
        "description" : "AppStorageV2 example"
      }
    }
  ]
}
```

![appstoragev2-sync-1](./figures/appstoragev2-sync-1.gif)