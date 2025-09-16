# AppStorage：应用全局的UI状态存储
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

在阅读本文档前，建议提前阅读：[状态管理概述](./arkts-state-management-overview.md)，从而对状态管理框架中AppStorage的定位有一个宏观了解。

AppStorage是与应用进程绑定的全局UI状态存储中心，由UI框架在应用启动时创建，将UI状态数据存储于运行内存，实现应用级全局状态共享。

作为应用的“中枢”，AppStorage是[持久化数据PersistentStorage](arkts-persiststorage.md)和[环境变量Environment](arkts-environment.md)与UI交互的中转桥梁。其核心价值在于为开发者提供跨ability的大范围UI状态数据共享能力。

AppStorage提供了API接口，允许开发者在自定义组件外手动触发AppStorage对应属性的增、删、改、查操作。建议配合[AppStorage API文档](../../reference/apis-arkui/arkui-ts/ts-state-management.md#appstorage)阅读。最佳实践请参考[状态管理最佳实践](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-status-management)。

## 概述

AppStorage是在应用启动时创建的单例，用于提供应用状态数据的中心存储。这些状态数据在应用级别可访问。AppStorage在应用运行过程中保留其属性。

AppStorage中保存的属性通过唯一的字符串类型属性名（key）访问，该属性可以和UI组件同步，且可以在应用业务逻辑中被访问。

AppStorage支持应用的[主线程](../../application-models/thread-model-stage.md)内多个[UIAbility](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)实例间的UI状态数据共享。

AppStorage中的属性通过唯一的字符串类型key值访问，支持与UI组件同步，并可在应用业务逻辑中被访问。其支持应用的[主线程](../../application-models/thread-model-stage.md)内多个[UIAbility](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)实例间的UI状态数据共享。

AppStorage中的属性可以被双向同步，并具有不同的功能，比如数据持久化（详见[PersistentStorage](arkts-persiststorage.md)）。这些UI状态是通过业务逻辑实现，与UI解耦，如果希望这些UI状态在UI中使用，需要用到[@StorageProp](#storageprop)和[@StorageLink](#storagelink)。

## \@StorageProp

\@StorageProp与AppStorage中对应的属性建立单向数据同步。

> **说明：**
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

### 装饰器使用规则说明

| \@StorageProp变量装饰器 | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| 装饰器参数              | 常量字符串，必填（字符串需要有引号）。<br/>**说明：**<br/>使用null和undefined作为key时，会隐式转换为对应的字符串，不建议该用法。                |
| 允许装饰的变量类型      | Object、class、string、number、boolean、enum类型，以及这些类型的数组。<br/>API Version 12及以上，支持Map、Set、Date、undefined和null类型，嵌套类型的场景请参考[观察变化和行为表现](#观察变化和行为表现)。<br/>同时，API Version 12及以上还支持上述支持类型的联合类型，比如string \| number, string \| undefined 或者 ClassA \| null，示例见[AppStorage支持联合类型](#appstorage支持联合类型)。 <br/>**说明：**<br/>变量类型必须被指定，建议和AppStorage中对应属性类型相同，否则会发生类型隐式转换，从而导致应用行为异常。|
| 不允许装饰的变量类型                | 不支持装饰Function类型。 |
| 同步类型                | 单向同步：从AppStorage的对应属性到组件的状态变量。<br/>组件本地的修改是允许的，但是AppStorage中给定的属性一旦发生变化，将覆盖本地的修改。 |
| 被装饰变量的初始值      | 必须本地初始化，如果AppStorage实例中不存在属性，则用该初始值初始化该属性，并存入AppStorage中。 |

### 变量的传递/访问规则说明

| 传递/访问      | 说明                                       |
| ---------- | ---------------------------------------- |
| 从父节点初始化和更新 | 禁止从父节点初始化和更新@StorageProp。仅支持使用AppStorage中对应key的属性进行初始化，如果不存在对应key，则使用本地默认值进行初始化。 |
| 初始化子节点     | 支持，可用于初始化[\@State](./arkts-state.md)、[\@Link](./arkts-link.md)、[\@Prop](./arkts-prop.md)、[\@Provide](./arkts-provide-and-consume.md)。 |
| 是否支持组件外访问  | 否。                                       |

  **图1** \@StorageProp初始化规则图示  

![zh-cn_image_0000001552978157](figures/zh-cn_image_0000001552978157.png)

### 观察变化和行为表现

**观察变化**

- 当装饰的类型为boolean、string、number时，可以观察到数值的变化。

- 当装饰的数据类型为class或者Object时，可以观察到对象整体赋值和属性变化（详见[从ui内部使用appstorage](#从ui内部使用appstorage)）。

- 当装饰的对象是数组时，可以观察到数组添加、删除、更新数组单元的变化。

- 当装饰的对象是Date时，可以观察到Date整体的赋值，以及通过调用Date的接口`setFullYear`、`setMonth`、`setDate`、`setHours`、`setMinutes`、`setSeconds`、`setMilliseconds`、`setTime`、`setUTCFullYear`、`setUTCMonth`、`setUTCDate`、`setUTCHours`、`setUTCMinutes`、`setUTCSeconds`、`setUTCMilliseconds`更新Date的属性。详见[装饰Date类型变量](#装饰date类型变量)。

- 当装饰的变量是Map时，可以观察到Map整体的赋值，以及通过调用Map的接口`set`、`clear`、`delete`更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰的变量是Set时，可以观察到Set整体的赋值，以及通过调用Set的接口`add`、`clear`、`delete`更新Set的值。详见[装饰Set类型变量](#装饰set类型变量)。

**框架行为**

1. \@StorageProp(key)装饰的数值发生变化，不会同步写回AppStorage对应的属性；变化会触发自定义组件重新渲染，并且该变动仅作用于当前组件的私有成员变量，其他绑定该key的数据不会同步改变。

2. 当AppStorage中对应key的属性发生改变时，所有\@StorageProp(key)装饰的变量都会同步更新，本地的修改将被覆盖。

## \@StorageLink

\@StorageLink与AppStorage中对应的属性建立双向数据同步。

> **说明：**
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

### 装饰器使用规则说明

| \@StorageLink变量装饰器 | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| 装饰器参数              | key：常量字符串，必填（字符串需要有引号）。<br/>**注意：**<br/>使用null和undefined作为key时，会隐式转换为对应的字符串，不建议该用法。                  |
| 允许装饰的变量类型      | Object、class、string、number、boolean、enum类型，以及这些类型的数组。<br/>API Version 12及以上支持Map、Set、Date、undefined和null类型。嵌套类型的场景请参考[观察变化和行为表现](#观察变化和行为表现-1)。<br/>API Version 12及以上还支持上述支持类型的联合类型，比如string \| number, string \| undefined 或者 ClassA \| null，示例见[AppStorage支持联合类型](#appstorage支持联合类型)。 <br/>**注意：**<br/>变量类型必须被指定，建议和AppStorage中对应属性类型相同，否则会发生类型隐式转换，从而导致应用行为异常。 |
| 不允许装饰的变量类型                | 不支持装饰Function类型。 |
| 同步类型                | 双向同步：从AppStorage的对应属性到自定义组件，从自定义组件到AppStorage对应属性。 |
| 被装饰变量的初始值      | 必须本地初始化，如果AppStorage实例中不存在属性，则用该初始值初始化该属性，并存入AppStorage中。 |


### 变量的传递/访问规则说明

| 传递/访问      | 说明                                       |
| ---------- | ---------------------------------------- |
| 从父节点初始化和更新 | 禁止。                                      |
| 初始化子节点     | 支持，可用于初始化常规变量、\@State、\@Link、\@Prop、\@Provide。 |
| 是否支持组件外访问  | 否。                                       |

  **图2** \@StorageLink初始化规则图示  

![zh-cn_image_0000001501938718](figures/zh-cn_image_0000001501938718.png)

### 观察变化和行为表现

**观察变化**

- 装饰的数据类型为boolean、string、number时，可以观察到数值变化。

- 装饰的数据类型为class或Object时，可以观察到对象整体赋值和属性变化。（详见[从ui内部使用appstorage](#从ui内部使用appstorage)）。

- 当装饰的对象是数组时，可以观察到数组添加、删除、更新数组单元的变化。

- 当装饰的对象是Date时，可以观察到Date整体的赋值，以及通过调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 更新Date的属性。详见[装饰Date类型变量](#装饰date类型变量)。

- 当装饰的变量是Map时，可以观察到Map整体的赋值，以及通过调用Map的接口`set`、`clear`、`delete`更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰的变量是Set时，可以观察到Set的整体赋值，以及通过调用Set的接口`add`、`clear`、`delete`更新Set的值。详见[装饰Set类型变量](#装饰set类型变量)。

**框架行为**

1. 当\@StorageLink(key)装饰的数值发生变化时，修改将被同步回AppStorage对应key的属性中。

2. AppStorage中key对应的数据一旦改变，其绑定的所有的数据（包括双向\@StorageLink和单向\@StorageProp）都将被同步修改。

3. `@StorageLink(key)`装饰的数据是状态变量，其变化不仅会同步到AppStorage，还会触发自定义组件的重新渲染。


## 限制条件

1. \@StorageProp/\@StorageLink的参数必须为string类型，否则编译期会报错。

    ```ts
    AppStorage.setOrCreate('propA', 47);

    // 错误写法，编译报错
    @StorageProp() storageProp: number = 1;
    @StorageLink() storageLink: number = 2;

    // 正确写法
    @StorageProp('propA') storageProp: number = 1;
    @StorageLink('propA') storageLink: number = 2;
    ```

2. \@StorageProp与\@StorageLink不支持装饰Function类型的变量，框架会抛出运行时错误。

3. AppStorage与[PersistentStorage](arkts-persiststorage.md)以及[Environment](arkts-environment.md)配合使用时，需要注意以下几点：

    1. 在AppStorage中创建属性后，调用PersistentStorage.[persistProp](../../reference/apis-arkui/arkui-ts/ts-state-management.md#persistpropdeprecated)接口时，会使用AppStorage中已存在的值，并覆盖PersistentStorage中的同名属性。因此，建议使用相反的调用顺序。反例可见[在PersistentStorage之前访问AppStorage中的属性](arkts-persiststorage.md#在persistentstorage之前访问appstorage中的属性)。

    2. 如果在AppStorage中已创建属性，再调用Environment.[envProp](../../reference/apis-arkui/arkui-ts/ts-state-management.md#envprop10)创建同名属性，会调用失败。因为AppStorage已有同名属性，Environment环境变量不会再写入AppStorage中，所以建议不要在AppStorage中使用Environment预置环境变量名。

4. 状态装饰器装饰的变量，改变会引起UI的渲染更新。如果改变的变量仅用于消息传递，不用于UI更新，推荐使用emitter方式。具体示例可见[不建议借助@StorageLink的双向同步机制实现事件通知](#不建议借助storagelink的双向同步机制实现事件通知)。

5. AppStorage同一进程内共享，UIAbility和<!--Del-->[<!--DelEnd-->UIExtensionAbility<!--Del-->](../../application-models/uiextensionability.md)<!--DelEnd-->是两个进程，所以在<!--Del-->[<!--DelEnd-->UIExtensionAbility<!--Del-->](../../application-models/uiextensionability.md)<!--DelEnd-->中不共享主进程的AppStorage。

## 使用场景

### 从应用逻辑使用AppStorage和LocalStorage

AppStorage是单例，其所有API均为静态方法，使用方法类似于LocalStorage中对应的非静态方法。

```ts
AppStorage.setOrCreate('propA', 47);

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('propA',17);
let propA: number | undefined = AppStorage.get('propA'); // propA in AppStorage == 47, propA in LocalStorage == 17
let link1: SubscribedAbstractProperty<number> = AppStorage.link('propA'); // link1.get() == 47
let link2: SubscribedAbstractProperty<number> = AppStorage.link('propA'); // link2.get() == 47
let prop: SubscribedAbstractProperty<number> = AppStorage.prop('propA'); // prop.get() == 47

link1.set(48); // 双向同步: link1.get() == link2.get() == prop.get() == 48
prop.set(1); // 单向同步: prop.get() == 1; 但 link1.get() == link2.get() == 48
link1.set(49); // 双向同步: link1.get() == link2.get() == prop.get() == 49

storage.get<number>('propA') // == 17
storage.set('propA', 101);
storage.get<number>('propA') // == 101

AppStorage.get<number>('propA') // == 49
link1.get() // == 49
link2.get() // == 49
prop.get() // == 49
```


### 从UI内部使用AppStorage

@StorageLink与AppStorage配合使用，通过AppStorage中的属性创建双向数据同步。
@StorageProp与AppStorage配合使用，通过AppStorage中的属性创建单向数据同步。

```ts
class Data {
  code: number;

  constructor(code: number) {
    this.code = code;
  }
}

AppStorage.setOrCreate('propA', 47);
AppStorage.setOrCreate('propB', new Data(50));
let storage = new LocalStorage();
storage.setOrCreate('linkA', 48);
storage.setOrCreate('linkB', new Data(100));

@Entry(storage)
@Component
struct Index {
  @StorageLink('propA') storageLink: number = 1;
  @StorageProp('propA') storageProp: number = 1;
  @StorageLink('propB') storageLinkObject: Data = new Data(1);
  @StorageProp('propB') storagePropObject: Data = new Data(1);

  build() {
    Column({ space: 20 }) {
      // @StorageLink与AppStorage建立双向联系，更改数据会同步回AppStorage中key为'propA'的值
      Text(`storageLink ${this.storageLink}`)
        .onClick(() => {
          this.storageLink += 1;
        })

      // @StorageProp与AppStorage建立单向联系，更改数据不会同步AppStoragekey为'propA'的值
      // 但能被AppStorage的set/setorCreate更新值
      Text(`storageProp ${this.storageProp}`)
        .onClick(() => {
          this.storageProp += 1;
        })

      // AppStorage的API虽然能获取值，但是不具有刷新UI的能力，日志能看到数值更改
      // 依赖@StorageLink/@StorageProp才能建立起与自定义组件的联系，刷新UI
      Text(`change by AppStorage: ${AppStorage.get<number>('propA')}`)
        .onClick(() => {
          console.info(`Appstorage.get: ${AppStorage.get<number>('propA')}`);
          AppStorage.set<number>('propA', 100);
        })

      Text(`storageLinkObject ${this.storageLinkObject.code}`)
        .onClick(() => {
          this.storageLinkObject.code += 1;
        })

      Text(`storagePropObject ${this.storagePropObject.code}`)
        .onClick(() => {
          this.storagePropObject.code += 1;
        })
    }
  }
}
```

### AppStorage支持联合类型

在下面的示例中，变量linkA的类型为number | null，变量linkB的类型为number | undefined。Text组件初始化分别显示为null和undefined，点击切换为数字，再次点击切换回null和undefined。

```ts
@Component
struct StorageLinkComponent {
  @StorageLink('linkA') linkA: number | null = null;
  @StorageLink('linkB') linkB: number | undefined = undefined;

  build() {
    Column() {
      Text('@StorageLink接口初始化，@StorageLink取值')
      Text(`${this.linkA}`).fontSize(20).onClick(() => {
        this.linkA ? this.linkA = null : this.linkA = 1;
      })
      Text(`${this.linkB}`).fontSize(20).onClick(() => {
        this.linkB ? this.linkB = undefined : this.linkB = 1;
      })
    }
    .borderWidth(3).borderColor(Color.Red)
  }
}

@Component
struct StoragePropComponent {
  @StorageProp('propA') propA: number | null = null;
  @StorageProp('propB') propB: number | undefined = undefined;

  build() {
    Column() {
      Text('@StorageProp接口初始化，@StorageProp取值')
      Text(`${this.propA}`).fontSize(20).onClick(() => {
        this.propA ? this.propA = null : this.propA = 1;
      })
      Text(`${this.propB}`).fontSize(20).onClick(() => {
        this.propB ? this.propB = undefined : this.propB = 1;
      })
    }
    .borderWidth(3).borderColor(Color.Blue)
  }
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        StorageLinkComponent()
        StoragePropComponent()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 装饰Date类型变量

> **说明：**
>
> 从API version 12开始，AppStorage支持Date类型。

在下面的示例中，@StorageLink装饰的selectedDate类型为Date。点击Button改变selectedDate的值，视图会随之刷新。

```ts
@Entry
@Component
struct DateSample {
  @StorageLink('date') selectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('set selectedDate to 2023-07-08')
        .margin(10)
        .onClick(() => {
          AppStorage.setOrCreate('date', new Date('2023-07-08'));
        })
      Button('increase the year by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
        })
      Button('increase the month by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
        })
      Button('increase the day by 1')
        .margin(10)
        .onClick(() => {
          this.selectedDate.setDate(this.selectedDate.getDate() + 1);
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: $$this.selectedDate
      })
    }.width('100%')
  }
}
```

### 装饰Map类型变量

> **说明：**
>
> 从API version 12开始，AppStorage支持Map类型。

在下面的示例中，@StorageLink装饰的message类型为Map\<number, string\>，点击Button改变message的值，视图会随之刷新。

```ts
@Entry
@Component
struct MapSample {
  @StorageLink('map') message: Map<number, string> = new Map([[0, 'a'], [1, 'b'], [3, 'c']]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
          Text(`${item[0]}`).fontSize(30)
          Text(`${item[1]}`).fontSize(30)
          Divider()
        })
        Button('init map').onClick(() => {
          this.message = new Map([[0, 'a'], [1, 'b'], [3, 'c']]);
        })
        Button('set new one').onClick(() => {
          this.message.set(4, 'd');
        })
        Button('clear').onClick(() => {
          this.message.clear();
        })
        Button('replace the existing one').onClick(() => {
          this.message.set(0, 'aa');
        })
        Button('delete the existing one').onClick(() => {
          AppStorage.get<Map<number, string>>('map')?.delete(0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 装饰Set类型变量

> **说明：**
>
> 从API version 12开始，AppStorage支持Set类型。

在下面的示例中，@StorageLink装饰的memberSet类型为Set\<number\>，点击Button改变memberSet的值，视图会随之刷新。

```ts
@Entry
@Component
struct SetSample {
  @StorageLink('set') memberSet: Set<number> = new Set([0, 1, 2, 3, 4]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.memberSet.entries()), (item: [number, number]) => {
          Text(`${item[0]}`)
            .fontSize(30)
          Divider()
        })
        Button('init set')
          .onClick(() => {
            this.memberSet = new Set([0, 1, 2, 3, 4]);
          })
        Button('set new one')
          .onClick(() => {
            AppStorage.get<Set<number>>('set')?.add(5);
          })
        Button('clear')
          .onClick(() => {
            this.memberSet.clear();
          })
        Button('delete the first one')
          .onClick(() => {
            this.memberSet.delete(0);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## AppStorage使用建议

### 不建议借助@StorageLink的双向同步机制实现事件通知

不建议使用@StorageLink和AppStorage的双向同步机制来实现事件通知。AppStorage中的变量可能绑定在多个页面的组件中，但事件通知不一定需要通知到所有这些组件。此外，当这些@StorageLink装饰的变量在UI中使用时，会触发UI刷新，造成不必要的性能影响。

示例代码中，`TapImage`中的点击事件会触发`AppStorage`中`tapIndex`对应属性的改变。由于`@StorageLink`是双向同步的，修改会同步回`AppStorage`中，因此所有绑定`AppStorage`的`tapIndex`自定义组件都能感知到`tapIndex`的变化。使用`@Watch`监听到`tapIndex`的变化后，修改状态变量`tapColor`，从而触发UI刷新（此处`tapIndex`未直接绑定在UI上，因此`tapIndex`的变化不会直接触发UI刷新）。

使用该机制实现事件通知时，应确保AppStorage中的变量不直接被绑定到UI上，同时控制[@Watch](./arkts-watch.md)函数的复杂度。如果@Watch函数执行时间过长，会影响UI刷新效率。

```ts
// xxx.ets
class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri;
  }
}

@Entry
@Component
struct Gallery {
  // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))];
  scroller: Scroller = new Scroller();

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData, index?: number) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: index
            })
          }.aspectRatio(1)

        }, (item: ViewData, index?: number) => {
          return JSON.stringify(item) + index;
        })
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @StorageLink('tapIndex') @Watch('onTapIndexChange') tapIndex: number = -1;
  @State tapColor: Color = Color.Black;
  private index: number = 0;
  private uri: Resource = {
    id: 0,
    type: 0,
    moduleName: '',
    bundleName: ''
  };

  // 判断是否被选中
  onTapIndexChange() {
    if (this.tapIndex >= 0 && this.index === this.tapIndex) {
      console.info(`tapindex: ${this.tapIndex}, index: ${this.index}, red`);
      this.tapColor = Color.Red;
    } else {
      console.info(`tapindex: ${this.tapIndex}, index: ${this.index}, black`);
      this.tapColor = Color.Black;
    }
  }

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .onClick(() => {
          this.tapIndex = this.index;
        })
        .border({ width: 5, style: BorderStyle.Dotted, color: this.tapColor })
    }

  }
}
```

相比借助@StorageLink的双向同步机制实现事件通知，开发者可以使用emit订阅某个事件并接收事件回调的方式来减少开销，增强代码的可读性。

> **说明：**
>
> emit接口不支持在Previewer预览器中使用。


```ts
// xxx.ets
import { emitter } from '@kit.BasicServicesKit';

let nextId: number = 0;

class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;
  id: number;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri;
    this.id = nextId++;
  }
}

@Entry
@Component
struct Gallery {
  // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))];
  scroller: Scroller = new Scroller();
  private preIndex: number = -1;

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: item.id
            })
          }.aspectRatio(1)
          .onClick(() => {
            if (this.preIndex === item.id) {
              return;
            }
            let innerEvent: emitter.InnerEvent = { eventId: item.id };
            // 选中态：黑变红
            let eventData: emitter.EventData = {
              data: {
                'colorTag': 1
              }
            };
            emitter.emit(innerEvent, eventData);

            if (this.preIndex != -1) {
              console.info(`preIndex: ${this.preIndex}, index: ${item.id}, black`);
              let innerEvent: emitter.InnerEvent = { eventId: this.preIndex };
              // 取消选中态：红变黑
              let eventData: emitter.EventData = {
                data: {
                  'colorTag': 0
                }
              };
              emitter.emit(innerEvent, eventData);
            }
            this.preIndex = item.id;
          })
        }, (item: ViewData) => JSON.stringify(item))
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @State tapColor: Color = Color.Black;
  private index: number = 0;
  private uri: Resource = {
    id: 0,
    type: 0,
    moduleName: '',
    bundleName: ''
  };

  onTapIndexChange(colorTag: emitter.EventData) {
    if (colorTag.data != null) {
      this.tapColor = colorTag.data.colorTag ? Color.Red : Color.Black;
    }
  }

  aboutToAppear() {
    //定义事件ID
    let innerEvent: emitter.InnerEvent = { eventId: this.index };
    emitter.on(innerEvent, data => {
      this.onTapIndexChange(data);
    });
  }

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .border({ width: 5, style: BorderStyle.Dotted, color: this.tapColor })
    }
  }
}
```

以上通知事件逻辑简单，也可以简化成三元表达式。

```ts
// xxx.ets
class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri;
  }
}

@Entry
@Component
struct Gallery {
  // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))];
  scroller: Scroller = new Scroller();

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData, index?: number) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: index
            })
          }.aspectRatio(1)

        }, (item: ViewData, index?: number) => {
          return JSON.stringify(item) + index;
        })
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @StorageLink('tapIndex') tapIndex: number = -1;
  private index: number = 0;
  private uri: Resource = {
    id: 0,
    type: 0,
    moduleName: '',
    bundleName: ''
  };

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .onClick(() => {
          this.tapIndex = this.index;
        })
        .border({
          width: 5,
          style: BorderStyle.Dotted,
          color: (this.tapIndex >= 0 && this.index === this.tapIndex) ? Color.Red : Color.Black
        })
    }
  }
}
```


### \@StorageProp和AppStorage接口配合使用时，需要注意更新规则

使用setOrCreate/set接口更新key的值时，如果值相同，setOrCreate不会通知\@StorageLink/\@StorageProp更新，但因为\@StorageProp本身有数据副本，更改值不会同步给AppStorage，这会导致开发者误认己通过AppStorage改了值，但实际上未通知\@StorageProp更新值的情况。
示例如下。

```ts
AppStorage.setOrCreate('propA', false);

@Entry
@Component
struct Index {
  @StorageProp('propA') @Watch('onChange') propA: boolean = false;

  onChange() {
    console.info(`propA change`);
  }

  aboutToAppear(): void {
    this.propA = true;
  }

  build() {
    Column() {
      Text(`${this.propA}`)
      Button('change')
        .onClick(() => {
          AppStorage.setOrCreate('propA', false);
          console.info(`propA: ${this.propA}`);
        })
    }
  }
}
```

上述示例，在点击事件之前，propA的值已经在本地被更改为true，而AppStorage中存的值仍为false。当点击事件通过setOrCreate接口尝试更新propA的值为false时，由于AppStorage中的值为false，两者相等，不会触发更新同步，因此@StorageProp的值仍为true。

实现二者同步有以下两种方式：
1. 将\@StorageProp更改为\@StorageLink。
2. 本地更改值的方式变为使用AppStorage.setOrCreate('propA', true)的方式。