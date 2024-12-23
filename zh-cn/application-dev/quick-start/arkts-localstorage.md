# LocalStorage：页面级UI状态存储


LocalStorage是页面级的UI状态存储，通过\@Entry装饰器接收的参数可以在页面内共享同一个LocalStorage实例。LocalStorage支持UIAbility实例内多个页面间状态共享。


本文仅介绍LocalStorage使用场景和相关的装饰器：\@LocalStorageProp和\@LocalStorageLink。


在阅读本文档前，建议开发者对状态管理框架有基本的了解。建议提前阅读：[状态管理概述](./arkts-state-management-overview.md)。

LocalStorage还提供了API接口，可以让开发者通过接口在自定义组件外手动触发Storage对应key的增删改查，建议配合[LocalStorage API文档](../reference/apis-arkui/arkui-ts/ts-state-management.md#localstorage9)阅读。

> **说明：**
>
> LocalStorage从API version 9开始支持。


## 概述

LocalStorage是ArkTS为构建页面级别状态变量提供存储的内存内的“数据库”。

- 应用程序可以创建多个LocalStorage实例，LocalStorage实例可以在页面内共享，也可以通过GetShared接口，实现跨页面、UIAbility实例内共享。

- 组件树的根节点，即被\@Entry装饰的\@Component，可以被分配一个LocalStorage实例，此组件的所有子组件实例将自动获得对该LocalStorage实例的访问权限。

- 被\@Component装饰的组件最多可以访问一个LocalStorage实例和[AppStorage](arkts-appstorage.md)，未被\@Entry装饰的组件不可被独立分配LocalStorage实例，只能接受父组件通过\@Entry传递来的LocalStorage实例。一个LocalStorage实例在组件树上可以被分配给多个组件。

- LocalStorage中的所有属性都是可变的。

应用程序决定LocalStorage对象的生命周期。当应用释放最后一个指向LocalStorage的引用时，比如销毁最后一个自定义组件，LocalStorage将被JS Engine垃圾回收。

LocalStorage根据与\@Component装饰的组件的同步类型不同，提供了两个装饰器：

- [@LocalStorageProp](#localstorageprop)：\@LocalStorageProp装饰的变量与LocalStorage中给定属性建立单向同步关系。

- [@LocalStorageLink](#localstoragelink)：\@LocalStorageLink装饰的变量与LocalStorage中给定属性建立双向同步关系。


## \@LocalStorageProp

在上文中已经提到，如果要建立LocalStorage和自定义组件的联系，需要使用\@LocalStorageProp和\@LocalStorageLink装饰器。使用\@LocalStorageProp(key)/\@LocalStorageLink(key)装饰组件内的变量，key标识了LocalStorage的属性。


当自定义组件初始化的时候，\@LocalStorageProp(key)/\@LocalStorageLink(key)装饰的变量会通过给定的key，绑定LocalStorage对应的属性，完成初始化。本地初始化是必要的，因为无法保证LocalStorage一定存在给定的key（这取决于应用逻辑是否在组件初始化之前在LocalStorage实例中存入对应的属性）。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

\@LocalStorageProp(key)是和LocalStorage中key对应的属性建立单向数据同步，ArkUI框架支持修改@LocalStorageProp(key)在本地的值，但是对本地值的修改不会同步回LocalStorage中。相反，如果LocalStorage中key对应的属性值发生改变，例如通过set接口对LocalStorage中的值进行修改，改变会同步给\@LocalStorageProp(key)，并覆盖掉本地的值。


### 装饰器使用规则说明

| \@LocalStorageProp变量装饰器 | 说明                                       |
| ----------------------- | ---------------------------------------- |
| 装饰器参数                   | key：常量字符串，必填（字符串需要有引号）。                  |
| 允许装饰的变量类型               | Object、class、string、number、boolean、enum类型，以及这些类型的数组。<br/>API12及以上支持Map、Set、Date类型。嵌套类型的场景请参考[观察变化和行为表现](#观察变化和行为表现)。<br/>类型必须被指定，建议和LocalStorage中对应属性类型相同，否则会发生类型隐式转换，从而导致应用行为异常。<br/>不支持any，API12及以上支持undefined和null类型。<br/>API12及以上支持上述支持类型的联合类型，比如string \| number, string \| undefined 或者 ClassA \| null，示例见[LocalStorage支持联合类型](#localstorage支持联合类型)。 <br/>**注意**<br/>当使用undefined和null的时候，建议显式指定类型，遵循TypeScript类型校验，比如：`@LocalStorageProp("AA") a: number \| null = null`是推荐的，不推荐`@LocalStorageProp("AA") a: number = null`。 |
| 同步类型                    | 单向同步：从LocalStorage的对应属性到组件的状态变量。组件本地的修改是允许的，但是LocalStorage中给定的属性一旦发生变化，将覆盖本地的修改。 |
| 被装饰变量的初始值               | 必须指定，如果LocalStorage实例中不存在属性，则用该初始值初始化该属性，并存入LocalStorage中。 |


### 变量的传递/访问规则说明

| 传递/访问      | 说明                                       |
| ---------- | ---------------------------------------- |
| 从父节点初始化和更新 | 禁止，\@LocalStorageProp不支持从父节点初始化，只能从LocalStorage中key对应的属性初始化，如果没有对应key的话，将使用本地默认值初始化。 |
| 初始化子节点     | 支持，可用于初始化\@State、\@Link、\@Prop、\@Provide。 |
| 是否支持组件外访问  | 否。                                       |

  **图1** \@LocalStorageProp初始化规则图示  

![zh-cn_image_0000001501936014](figures/zh-cn_image_0000001501936014.png)


### 观察变化和行为表现

**观察变化**


- 当装饰的数据类型为boolean、string、number类型时，可以观察到数值的变化。

- 当装饰的数据类型为class或者Object时，可以观察到对象整体赋值和对象属性变化（详见[从ui内部使用localstorage](#从ui内部使用localstorage)）。

- 当装饰的对象是array时，可以观察到数组添加、删除、更新数组单元的变化。

- 当装饰的对象是Date时，可以观察到Date整体的赋值，同时可通过调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 更新Date的属性。详见[装饰Date类型变量](#装饰date类型变量)。

- 当装饰的变量是Map时，可以观察到Map整体的赋值，同时可通过调用Map的接口`set`, `clear`, `delete` 更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰的变量是Set时，可以观察到Set整体的赋值，同时可通过调用Set的接口`add`, `clear`, `delete` 更新Set的值。详见[装饰Set类型变量](#装饰set类型变量)。


**框架行为**


- 被\@LocalStorageProp装饰的变量的值的变化不会同步回LocalStorage里。

- \@LocalStorageProp装饰的变量变化会使当前自定义组件中关联的组件刷新。

- LocalStorage(key)中值的变化会引发所有被\@LocalStorageProp对应key装饰的变量的变化，会覆盖\@LocalStorageProp本地的改变。

![LocalStorageProp_framework_behavior](figures/LocalStorageProp_framework_behavior.png)


## \@LocalStorageLink

> **说明：**
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

如果我们需要将自定义组件的状态变量的更新同步回LocalStorage，就需要用到\@LocalStorageLink。

\@LocalStorageLink(key)是和LocalStorage中key对应的属性建立双向数据同步：

1. 本地修改发生，该修改会被写回LocalStorage中；

2. LocalStorage中的修改发生后，该修改会被同步到所有绑定LocalStorage对应key的属性上，包括单向（\@LocalStorageProp和通过prop创建的单向绑定变量）、双向（\@LocalStorageLink和通过link创建的双向绑定变量）变量。

### 装饰器使用规则说明

| \@LocalStorageLink变量装饰器 | 说明                                       |
| ----------------------- | ---------------------------------------- |
| 装饰器参数                   | key：常量字符串，必填（字符串需要有引号）。                  |
| 允许装饰的变量类型               | Object、class、string、number、boolean、enum类型，以及这些类型的数组。<br/>API12及以上支持Map、Set、Date类型。嵌套类型的场景请参考[观察变化和行为表现](#观察变化和行为表现)。<br/>类型必须被指定，建议和LocalStorage中对应属性类型相同，否则会发生类型隐式转换，从而导致应用行为异常。<br/>不支持any，API12及以上支持undefined和null类型。<br/>API12及以上支持上述支持类型的联合类型，比如string \| number, string \| undefined 或者 ClassA \| null，示例见[LocalStorage支持联合类型](#localstorage支持联合类型)。 <br/>**注意**<br/>当使用undefined和null的时候，建议显式指定类型，遵循TypeScript类型校验，比如：`@LocalStorageLink("AA") a: number \| null = null`是推荐的，不推荐`@LocalStorageLink("AA") a: number = null`。 |
| 同步类型                    | 双向同步：从LocalStorage的对应属性到自定义组件，从自定义组件到LocalStorage对应属性。 |
| 被装饰变量的初始值               | 必须指定，如果LocalStorage实例中不存在属性，则用该初始值初始化该属性，并存入LocalStorage中。 |


### 变量的传递/访问规则说明

| 传递/访问      | 说明                                       |
| ---------- | ---------------------------------------- |
| 从父节点初始化和更新 | 禁止，\@LocalStorageLink不支持从父节点初始化，只能从LocalStorage中key对应的属性初始化，如果没有对应key的话，将使用本地默认值初始化。 |
| 初始化子节点     | 支持，可用于初始化\@State、\@Link、\@Prop、\@Provide。 |
| 是否支持组件外访问  | 否。                                       |


  **图2** \@LocalStorageLink初始化规则图示  


![zh-cn_image_0000001552855957](figures/zh-cn_image_0000001552855957.png)


### 观察变化和行为表现

**观察变化**


- 当装饰的数据类型为boolean、string、number类型时，可以观察到数值的变化。

- 当装饰的数据类型为class或者Object时，可以观察到对象整体赋值和对象属性变化（详见[从ui内部使用localstorage](#从ui内部使用localstorage)）。

- 当装饰的对象是array时，可以观察到数组添加、删除、更新数组单元的变化。

- 当装饰的对象是Date时，可以观察到Date整体的赋值，同时可通过调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 更新Date的属性。详见[装饰Date类型变量](#装饰date类型变量)。

- 当装饰的变量是Map时，可以观察到Map整体的赋值，同时可通过调用Map的接口`set`, `clear`, `delete` 更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰的变量是Set时，可以观察到Set整体的赋值，同时可通过调用Set的接口`add`, `clear`, `delete` 更新Set的值。详见[装饰Set类型变量](#装饰set类型变量)。


**框架行为**


1. 当\@LocalStorageLink(key)装饰的数值改变被观察到时，修改将被同步回LocalStorage对应属性键值key的属性中。

2. LocalStorage中属性键值key对应的数据一旦改变，属性键值key绑定的所有的数据（包括双向\@LocalStorageLink和单向\@LocalStorageProp）都将同步修改。

3. 当\@LocalStorageLink(key)装饰的数据本身是状态变量，它的改变不仅仅会同步回LocalStorage中，还会引起所属的自定义组件的重新渲染。

![LocalStorageLink_framework_behavior](figures/LocalStorageLink_framework_behavior.png)


## 限制条件

1. \@LocalStorageProp/\@LocalStorageLink的参数必须为string类型，否则编译期会报错。

```ts
let storage = new LocalStorage();
storage.setOrCreate('PropA', 48);

// 错误写法，编译报错
@LocalStorageProp() localStorageProp: number = 1;
@LocalStorageLink() localStorageLink: number = 2;

// 正确写法
@LocalStorageProp('PropA') localStorageProp: number = 1;
@LocalStorageLink('PropA') localStorageLink: number = 2;
```

2. \@StorageProp与\@StorageLink不支持装饰Function类型的变量，框架会抛出运行时错误。

3. LocalStorage创建后，命名属性的类型不可更改。后续调用Set时必须使用相同类型的值。

4. LocalStorage是页面级存储，[getShared](../reference/apis-arkui/arkui-ts/ts-state-management.md#getshared10)接口仅能获取当前Stage通过[windowStage.loadContent](../reference/apis-arkui/js-apis-window.md#loadcontent9)传入的LocalStorage实例，否则返回undefined。例子可见[将LocalStorage实例从UIAbility共享到一个或多个视图](#将localstorage实例从uiability共享到一个或多个视图)。


## 使用场景


### 应用逻辑使用LocalStorage


```ts
let para: Record<string,number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para); // 创建新实例并使用给定对象初始化
let propA: number | undefined = storage.get('PropA') // propA == 47
let link1: SubscribedAbstractProperty<number> = storage.link('PropA'); // link1.get() == 47
let link2: SubscribedAbstractProperty<number> = storage.link('PropA'); // link2.get() == 47
let prop: SubscribedAbstractProperty<number> = storage.prop('PropA'); // prop.get() == 47
link1.set(48); // 双向同步: link1.get() == link2.get() == prop.get() == 48
prop.set(1); // 单向同步: prop.get() == 1; 但 link1.get() == link2.get() == 48
link1.set(49); // 双向同步: link1.get() == link2.get() == prop.get() == 49
```


### 从UI内部使用LocalStorage

除了应用程序逻辑使用LocalStorage，还可以借助LocalStorage相关的两个装饰器\@LocalStorageProp和\@LocalStorageLink，在UI组件内部获取到LocalStorage实例中存储的状态变量。

本示例以\@LocalStorageLink为例，展示了：

- 使用构造函数创建LocalStorage实例storage；

- 使用\@Entry装饰器将storage添加到Parent顶层组件中；

- \@LocalStorageLink绑定LocalStorage对给定的属性，建立双向数据同步。

 ```ts
class Data {
  code: number;

  constructor(code: number) {
    this.code = code;
  }
}
// 创建新实例并使用给定对象初始化
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
storage.setOrCreate('PropB', new Data(50));

@Component
struct Child {
  // @LocalStorageLink变量装饰器与LocalStorage中的'PropA'属性建立双向绑定
  @LocalStorageLink('PropA') childLinkNumber: number = 1;
  // @LocalStorageLink变量装饰器与LocalStorage中的'PropB'属性建立双向绑定
  @LocalStorageLink('PropB') childLinkObject: Data = new Data(0);

  build() {
    Column({ space: 15 }) {
      Button(`Child from LocalStorage ${this.childLinkNumber}`) // 更改将同步至LocalStorage中的'PropA'以及Parent.parentLinkNumber
        .onClick(() => {
          this.childLinkNumber += 1;
        })

      Button(`Child from LocalStorage ${this.childLinkObject.code}`) // 更改将同步至LocalStorage中的'PropB'以及Parent.parentLinkObject.code
        .onClick(() => {
          this.childLinkObject.code += 1;
        })
    }
  }
}
// 使LocalStorage可从@Component组件访问
@Entry(storage)
@Component
struct Parent {
  // @LocalStorageLink变量装饰器与LocalStorage中的'PropA'属性建立双向绑定
  @LocalStorageLink('PropA') parentLinkNumber: number = 1;
  // @LocalStorageLink变量装饰器与LocalStorage中的'PropB'属性建立双向绑定
  @LocalStorageLink('PropB') parentLinkObject: Data = new Data(0);

  build() {
    Column({ space: 15 }) {
      Button(`Parent from LocalStorage ${this.parentLinkNumber}`) // 由于LocalStorage中PropA已经被初始化，因此this.parentLinkNumber的值为47
        .onClick(() => {
          this.parentLinkNumber += 1;
        })

      Button(`Parent from LocalStorage ${this.parentLinkObject.code}`) // 由于LocalStorage中PropB已经被初始化，因此this.parentLinkObject.code的值为50
        .onClick(() => {
          this.parentLinkObject.code += 1;
        })
      // @Component子组件自动获得对Parent LocalStorage实例的访问权限。
      Child()
    }
  }
}
```


### \@LocalStorageProp和LocalStorage单向同步的简单场景

在下面的示例中，Parent 组件和Child组件分别在本地创建了与storage的'PropA'对应属性的单向同步的数据，我们可以看到：

- Parent中对this.storageProp1的修改，只会在Parent中生效，并没有同步回storage；

- Child组件中，Text绑定的storageProp2 依旧显示47。

```ts
// 创建新实例并使用给定对象初始化
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
// 使LocalStorage可从@Component组件访问
@Entry(storage)
@Component
struct Parent {
  // @LocalStorageProp变量装饰器与LocalStorage中的'PropA'属性建立单向绑定
  @LocalStorageProp('PropA') storageProp1: number = 1;

  build() {
    Column({ space: 15 }) {
      // 点击后从47开始加1，只改变当前组件显示的storageProp1，不会同步到LocalStorage中
      Button(`Parent from LocalStorage ${this.storageProp1}`)
        .onClick(() => {
          this.storageProp1 += 1
        })
      Child()
    }
  }
}

@Component
struct Child {
  // @LocalStorageProp变量装饰器与LocalStorage中的'PropA'属性建立单向绑定
  @LocalStorageProp('PropA') storageProp2: number = 2;

  build() {
    Column({ space: 15 }) {
      // 当Parent改变时，当前storageProp2不会改变，显示47
      Text(`Parent from LocalStorage ${this.storageProp2}`)
    }
  }
}
```


### \@LocalStorageLink和LocalStorage双向同步的简单场景

下面的示例展示了\@LocalStorageLink装饰的数据和LocalStorage双向同步的场景：


```ts
// 构造LocalStorage实例
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
// 调用link（api9以上）接口构造'PropA'的双向同步数据，linkToPropA 是全局变量
let linkToPropA: SubscribedAbstractProperty<object> = storage.link('PropA');

@Entry(storage)
@Component
struct Parent {

  // @LocalStorageLink('PropA')在Parent自定义组件中创建'PropA'的双向同步数据，初始值为47，因为在构造LocalStorage已经给“PropA”设置47
  @LocalStorageLink('PropA') storageLink: number = 1;

  build() {
    Column() {
      Text(`incr @LocalStorageLink variable`)
        // 点击“incr @LocalStorageLink variable”，this.storageLink加1，改变同步回storage，全局变量linkToPropA也会同步改变

        .onClick(() => {
          this.storageLink += 1
        })

      // 并不建议在组件内使用全局变量linkToPropA.get()，因为可能会有生命周期不同引起的错误。
      Text(`@LocalStorageLink: ${this.storageLink} - linkToPropA: ${linkToPropA.get()}`)
    }
  }
}
```


### 兄弟组件之间同步状态变量

下面的示例展示了通过\@LocalStorageLink双向同步兄弟组件之间的状态。

先看Parent自定义组件中发生的变化：

1. 点击“playCount ${this.playCount} dec by 1”，this.playCount减1，修改同步回LocalStorage中，Child组件中的playCountLink绑定的组件会同步刷新；

2. 点击“countStorage ${this.playCount} incr by 1”，调用LocalStorage的set接口，更新LocalStorage中“countStorage”对应的属性，Child组件中的playCountLink绑定的组件会同步刷新；

3. Text组件“playCount in LocalStorage for debug ${storage.get&lt;number&gt;('countStorage')}”没有同步刷新，因为storage.get&lt;number&gt;('countStorage')返回的是常规变量，常规变量的更新并不会引起Text组件的重新渲染。

Child自定义组件中的变化：

1. playCountLink的刷新会同步回LocalStorage，并且引起兄弟组件和父组件相应的刷新。

```ts
let count: Record<string, number> = { 'countStorage': 1 }
let storage: LocalStorage = new LocalStorage(count);

@Component
struct Child {
  // 子组件实例的名字
  label: string = 'no name';
  // 和LocalStorage中“countStorage”的双向绑定数据
  @LocalStorageLink('countStorage') playCountLink: number = 0;

  build() {
    Row() {
      Text(this.label)
        .width(50).height(60).fontSize(12)
      Text(`playCountLink ${this.playCountLink}: inc by 1`)
        .onClick(() => {
          this.playCountLink += 1;
        })
        .width(200).height(60).fontSize(12)
    }.width(300).height(60)
  }
}

@Entry(storage)
@Component
struct Parent {
  @LocalStorageLink('countStorage') playCount: number = 0;

  build() {
    Column() {
      Row() {
        Text('Parent')
          .width(50).height(60).fontSize(12)
        Text(`playCount ${this.playCount} dec by 1`)
          .onClick(() => {
            this.playCount -= 1;
          })
          .width(250).height(60).fontSize(12)
      }.width(300).height(60)

      Row() {
        Text('LocalStorage')
          .width(50).height(60).fontSize(12)
        Text(`countStorage ${this.playCount} incr by 1`)
          .onClick(() => {
            storage.set<number | undefined>('countStorage', Number(storage.get<number>('countStorage')) + 1);
          })
          .width(250).height(60).fontSize(12)
      }.width(300).height(60)

      Child({ label: 'ChildA' })
      Child({ label: 'ChildB' })

      Text(`playCount in LocalStorage for debug ${storage.get<number>('countStorage')}`)
        .width(300).height(60).fontSize(12)
    }
  }
}
```


### 将LocalStorage实例从UIAbility共享到一个或多个视图

上面的实例中，LocalStorage的实例仅仅在一个\@Entry装饰的组件和其所属的子组件（一个页面）中共享，如果希望其在多个视图中共享，可以在所属UIAbility中创建LocalStorage实例，并调用windowStage.[loadContent](../reference/apis-arkui/js-apis-window.md#loadcontent9)。


```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
para:Record<string, number> = { 'PropA': 47 };
storage: LocalStorage = new LocalStorage(this.para);

onWindowStageCreate(windowStage: window.WindowStage) {
windowStage.loadContent('pages/Index', this.storage);
}
}
```
> **说明：**
>
> 在UI页面通过getShared接口获取通过loadContent共享的LocalStorage实例。
>
> LocalStorage.getShared()只在模拟器或者实机上才有效，在Previewer预览器中使用不生效。


在下面的用例中，Index页面中的propA通过getShared()方法获取到共享的LocalStorage实例。点击Button跳转到Page页面，点击Change propA改变propA的值，back回Index页面后，页面中propA的值也同步修改。
```ts
// index.ets

// 通过getShared接口获取stage共享的LocalStorage实例
@Entry({ storage: LocalStorage.getShared() })
@Component
struct Index {
  // 可以使用@LocalStorageLink/Prop与LocalStorage实例中的变量建立联系
  @LocalStorageLink('PropA') propA: number = 1;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Row(){
        Column() {
          Text(`${this.propA}`)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
          Button("To Page")
            .onClick(() => {
              this.pageStack.pushPathByName('Page', null);
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
}
```

```ts
// Page.ets

@Builder
export function PageBuilder() {
  Page()
}

// Page组件获得了父亲Index组件的LocalStorage实例
@Component
struct Page {
  @LocalStorageLink('PropA') propA: number = 2;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Row(){
        Column() {
          Text(`${this.propA}`)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)

          Button("Change propA")
            .onClick(() => {
              this.propA = 100;
            })

          Button("Back Index")
            .onClick(() => {
              this.pathStack.pop();
            })
        }
        .width('100%')
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page页面的路径。
```json
{
  "routerMap": [
    {
      "name": "Page",
      "pageSourceFile": "src/main/ets/pages/Page.ets",
      "buildFunction": "PageBuilder",
      "data": {
        "description" : "LocalStorage example"
      }
    }
  ]
}
```

> **说明：**
>
> 对于开发者更建议使用这个方式来构建LocalStorage的实例，并且在创建LocalStorage实例的时候就写入默认值，因为默认值可以作为运行异常的备份，也可以用作页面的单元测试。


### 自定义组件接收LocalStorage实例

除了根节点可通过@Entry来接收LocalStorage实例，自定义组件（子节点）也可以通过构造参数来传递LocalStorage实例。

本示例以\@LocalStorageLink为例，展示了：

- 父组件中的Text，显示LocalStorage实例localStorage1中PropA的值为“PropA”。

- Child组件中，Text绑定的PropB，显示LocalStorage实例localStorage2中PropB的值为“PropB”。

> **说明：**
>
> 从API version 12开始，自定义组件支持接收LocalStorage实例。
> 当自定义组件作为子节点，定义了成员属性时，LocalStorage实例必须要放在第二个参数位置传递，否则会报类型不匹配的编译问题。
> 当在自定义组件中定义了属性时，暂时不支持只有一个LocalStorage实例作为入参。如果没定义属性，可以只传入一个LocalStorage实例作为入参。
> 如果定义的属性不需要从父组件初始化变量，则第一个参数需要传{}。
> 作为构造参数传给子组件的LocalStorage实例在初始化时就会被决定，可以通过@LocalStorageLink或者LocalStorage的API修改LocalStorage实例中保存的属性值，但LocalStorage实例自身不能被动态修改。

```ts
let localStorage1: LocalStorage = new LocalStorage();
localStorage1.setOrCreate('PropA', 'PropA');

let localStorage2: LocalStorage = new LocalStorage();
localStorage2.setOrCreate('PropB', 'PropB');

@Entry(localStorage1)
@Component
struct Index {
  // 'PropA'，和localStorage1中'PropA'的双向同步
  @LocalStorageLink('PropA') PropA: string = 'Hello World';
  @State count: number = 0;

  build() {
    Row() {
      Column() {
        Text(this.PropA)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        // 使用LocalStorage 实例localStorage2
        Child({ count: this.count }, localStorage2)
      }
      .width('100%')
    }
    .height('100%')
  }
}


@Component
struct Child {
  @Link count: number;
  //  'Hello World'，和localStorage2中'PropB'的双向同步，localStorage2中没有'PropB'，则使用默认值'Hello World'
  @LocalStorageLink('PropB') PropB: string = 'Hello World';

  build() {
    Text(this.PropB)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

1. 当自定义组件没有定义属性时，可以只传入一个LocalStorage实例作为入参。

```ts
let localStorage1: LocalStorage = new LocalStorage();
localStorage1.setOrCreate('PropA', 'PropA');

let localStorage2: LocalStorage = new LocalStorage();
localStorage2.setOrCreate('PropB', 'PropB');

@Entry(localStorage1)
@Component
struct Index {
  // 'PropA'，和localStorage1中'PropA'的双向同步
  @LocalStorageLink('PropA') PropA: string = 'Hello World';
  @State count: number = 0;

  build() {
    Row() {
      Column() {
        Text(this.PropA)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        // 使用LocalStorage 实例localStorage2
        Child(localStorage2)
      }
      .width('100%')
    }
    .height('100%')
  }
}


@Component
struct Child {
  build() {
    Text("hello")
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

2. 当定义的属性不需要从父组件初始化变量时，第一个参数需要传{}。

```ts
let localStorage1: LocalStorage = new LocalStorage();
localStorage1.setOrCreate('PropA', 'PropA');

let localStorage2: LocalStorage = new LocalStorage();
localStorage2.setOrCreate('PropB', 'PropB');

@Entry(localStorage1)
@Component
struct Index {
  // 'PropA'，和localStorage1中'PropA'的双向同步
  @LocalStorageLink('PropA') PropA: string = 'Hello World';
  @State count: number = 0;

  build() {
    Row() {
      Column() {
        Text(this.PropA)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        // 使用LocalStorage 实例localStorage2
        Child({}, localStorage2)
      }
      .width('100%')
    }
    .height('100%')
  }
}


@Component
struct Child {
  @State count: number = 5;
  // 'Hello World'，和localStorage2中'PropB'的双向同步，localStorage2中没有'PropB'，则使用默认值'Hello World'
  @LocalStorageLink('PropB') PropB: string = 'Hello World';

  build() {
    Text(this.PropB)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```


### Navigation组件和LocalStorage联合使用

可以通过传递不同的LocalStorage实例给自定义组件，从而实现在navigation跳转到不同的页面时，绑定不同的LocalStorage实例，显示对应绑定的值。

本示例以\@LocalStorageLink为例，展示了：

- 点击父组件中的Button "Next Page",创建并跳转到name为"pageOne"的子页面，Text显示信息为LocalStorage实例localStorageA中绑定的PropA的值，为"PropA"。

- 继续点击页面上的Button "Next Page",创建并跳转到name为"pageTwo"的子页面，Text显示信息为LocalStorage实例localStorageB中绑定的PropB的值，为"PropB"。

- 继续点击页面上的Button "Next Page",创建并跳转到name为"pageTree"的子页面，Text显示信息为LocalStorage实例localStorageC中绑定的PropC的值，为"PropC"。

- 继续点击页面上的Button "Next Page",创建并跳转到name为"pageOne"的子页面，Text显示信息为LocalStorage实例localStorageA中绑定的PropA的值，为"PropA"。

- NavigationContentMsgStack自定义组件中的Text组件，共享对应自定义组件树上LocalStorage实例绑定的PropA的值。


```ts
let localStorageA: LocalStorage = new LocalStorage();
localStorageA.setOrCreate('PropA', 'PropA');

let localStorageB: LocalStorage = new LocalStorage();
localStorageB.setOrCreate('PropB', 'PropB');

let localStorageC: LocalStorage = new LocalStorage();
localStorageC.setOrCreate('PropC', 'PropC');

@Entry
@Component
struct MyNavigationTestStack {
  @Provide('pageInfo') pageInfo: NavPathStack = new NavPathStack();

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      // 传递不同的LocalStorage实例
      pageOneStack({}, localStorageA)
    } else if (name === 'pageTwo') {
      pageTwoStack({}, localStorageB)
    } else if (name === 'pageThree') {
      pageThreeStack({}, localStorageC)
    }
  }

  build() {
    Column({ space: 5 }) {
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); //将name指定的NavDestination页面信息入栈
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
      .borderWidth(1)
    }
  }
}

@Component
struct pageOneStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('PropA') PropA: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack()
        // 显示绑定的LocalStorage中PropA的值'PropA'
        Text(`${this.PropA}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageTwoStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('PropB') PropB: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack()
        // 如果绑定的LocalStorage中没有PropB,显示本地初始化的值 'Hello World'
        Text(`${this.PropB}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })

      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageThreeStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('PropC') PropC: string = 'pageThreeStack';

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack()

        // 如果绑定的LocalStorage中没有PropC,显示本地初始化的值 'pageThreeStack'
        Text(`${this.PropC}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })

      }.width('100%').height('100%')
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct NavigationContentMsgStack {
  @LocalStorageLink('PropA') PropA: string = 'Hello';

  build() {
    Column() {
      Text(`${this.PropA}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```


### LocalStorage支持联合类型

在下面的示例中，变量A的类型为number | null，变量B的类型为number | undefined。Text组件初始化分别显示为null和undefined，点击切换为数字，再次点击切换回null和undefined。

```ts
@Component
struct LocalStorLink {
  @LocalStorageLink("LinkA") LinkA: number | null = null;
  @LocalStorageLink("LinkB") LinkB: number | undefined = undefined;

  build() {
    Column() {
      Text("@LocalStorageLink接口初始化，@LocalStorageLink取值")
      Text(this.LinkA + "").fontSize(20).onClick(() => {
        this.LinkA ? this.LinkA = null : this.LinkA = 1;
      })
      Text(this.LinkB + "").fontSize(20).onClick(() => {
        this.LinkB ? this.LinkB = undefined : this.LinkB = 1;
      })
    }
    .borderWidth(3).borderColor(Color.Green)

  }
}

@Component
struct LocalStorProp {
  @LocalStorageProp("PropA") PropA: number | null = null;
  @LocalStorageProp("PropB") PropB: number | undefined = undefined;

  build() {
    Column() {
      Text("@LocalStorageProp接口初始化，@LocalStorageProp取值")
      Text(this.PropA + "").fontSize(20).onClick(() => {
        this.PropA ? this.PropA = null : this.PropA = 1;
      })
      Text(this.PropB + "").fontSize(20).onClick(() => {
        this.PropB ? this.PropB = undefined : this.PropB = 1;
      })
    }
    .borderWidth(3).borderColor(Color.Yellow)

  }
}

let storage: LocalStorage = new LocalStorage();

@Entry(storage)
@Component
struct Index {
  build() {
    Row() {
      Column() {
        LocalStorLink()
        LocalStorProp()
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
> 从API version 12开始，LocalStorage支持Date类型。

在下面的示例中，@LocalStorageLink装饰的selectedDate类型为Date，点击Button改变selectedDate的值，视图会随之刷新。

```ts
@Entry
@Component
struct LocalDateSample {
  @LocalStorageLink("date") selectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('set selectedDate to 2023-07-08')
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-07-08');
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
> 从API version 12开始，LocalStorage支持Map类型。

在下面的示例中，@LocalStorageLink装饰的message类型为Map\<number, string\>，点击Button改变message的值，视图会随之刷新。

```ts
@Entry
@Component
struct LocalMapSample {
  @LocalStorageLink("map") message: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
          Text(`${item[0]}`).fontSize(30)
          Text(`${item[1]}`).fontSize(30)
          Divider()
        })
        Button('init map').onClick(() => {
          this.message = new Map([[0, "a"], [1, "b"], [3, "c"]]);
        })
        Button('set new one').onClick(() => {
          this.message.set(4, "d");
        })
        Button('clear').onClick(() => {
          this.message.clear();
        })
        Button('replace the existing one').onClick(() => {
          this.message.set(0, "aa");
        })
        Button('delete the existing one').onClick(() => {
          this.message.delete(0);
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
> 从API version 12开始，LocalStorage支持Set类型。

在下面的示例中，@LocalStorageLink装饰的memberSet类型为Set\<number\>，点击Button改变memberSet的值，视图会随之刷新。

```ts
@Entry
@Component
struct LocalSetSample {
  @LocalStorageLink("set") memberSet: Set<number> = new Set([0, 1, 2, 3, 4]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.memberSet.entries()), (item: [number, string]) => {
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
            this.memberSet.add(5);
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

### 自定义组件外改变状态变量

```ts
let storage = new LocalStorage();
storage.setOrCreate('count', 47);

class Model {
  storage: LocalStorage = storage;

  call(propName: string, value: number) {
    this.storage.setOrCreate<number>(propName, value);
  }
}

let model: Model = new Model();

@Entry({ storage: storage })
@Component
struct Test {
  @LocalStorageLink('count') count: number = 0;

  build() {
    Column() {
      Text(`count值: ${this.count}`)
      Button('change')
        .onClick(() => {
          model.call('count', this.count + 1);
        })
    }
  }
}
```

<!--no_check-->
