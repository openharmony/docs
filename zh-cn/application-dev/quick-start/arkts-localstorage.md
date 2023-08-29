# LocalStorage：页面级UI状态存储


LocalStorage是页面级的UI状态存储，通过\@Entry装饰器接受的参数可以在页面内共享同一个LocalStorage实例。LocalStorage也可以在UIAbility内，页面间共享状态。


本文仅介绍LocalStorage使用场景和相关的装饰器：\@LocalStorageProp和\@LocalStorageLink。


> **说明：**
>
> 本模块从API version 9开始支持。


## 概述

LocalStorage是ArkTS为构建页面级别状态变量提供存储的内存内“数据库”。

- 应用程序可以创建多个LocalStorage实例，LocalStorage实例可以在页面内共享，也可以通过GetShared接口，获取在UIAbility里创建的GetShared，实现跨页面、UIAbility内共享。

- 组件树的根节点，即被\@Entry装饰的\@Component，可以被分配一个LocalStorage实例，此组件的所有子组件实例将自动获得对该LocalStorage实例的访问权限；

- 被\@Component装饰的组件最多可以访问一个LocalStorage实例和[AppStorage](arkts-appstorage.md)，未被\@Entry装饰的组件不可被独立分配LocalStorage实例，只能接受父组件通过\@Entry传递来的LocalStorage实例。一个LocalStorage实例在组件树上可以被分配给多个组件。

- LocalStorage中的所有属性都是可变的。

应用程序决定LocalStorage对象的生命周期。当应用释放最后一个指向LocalStorage的引用时，比如销毁最后一个自定义组件，LocalStorage将被JS Engine垃圾回收。

LocalStorage根据与\@Component装饰的组件的同步类型不同，提供了两个装饰器：

- [@LocalStorageProp](#localstorageprop)：\@LocalStorageProp装饰的变量和与LocalStorage中给定属性建立单行同步关系。

- [@LocalStorageLink](#localstoragelink)：\@LocalStorageLink装饰的变量和在\@Component中创建与LocalStorage中给定属性建立双向同步关系。


## 限制条件

- LocalStorage创建后，命名属性的类型不可更改。后续调用Set时必须使用相同类型的值。
- LocalStorage是页面级存储，[GetShared](../reference/arkui-ts/ts-state-management.md#getshared9)接口仅能获取当前Stage通过[windowStage.loadContent](../reference/apis/js-apis-window.md#loadcontent9)传入的LocalStorage实例，否则返回undefined。例子可见[将LocalStorage实例从UIAbility共享到一个或多个视图](#将localstorage实例从uiability共享到一个或多个视图)。


## \@LocalStorageProp

在上文中已经提到，如果要建立LocalStorage和自定义组件的联系，需要使用\@LocalStorageProp和\@LocalStorageLink装饰器。使用\@LocalStorageProp(key)/\@LocalStorageLink(key)装饰组件内的变量，key标识了LocalStorage的属性。


当自定义组件初始化的时候，\@LocalStorageProp(key)/\@LocalStorageLink(key)装饰的变量会通过给定的key，绑定在LocalStorage对应的属性，完成初始化。本地初始化是必要的，因为无法保证LocalStorage一定存在给定的key（这取决于应用逻辑，是否在组件初始化之前在LocalStorage实例中存入对应的属性）。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。


\@LocalStorageProp(key)是和LocalStorage中key对应的属性建立单向数据同步，我们允许本地改变的发生，但是对于\@LocalStorageProp，本地的修改永远不会同步回LocalStorage中，相反，如果LocalStorage给定key的属性发生改变，改变会被同步给\@LocalStorageProp，并覆盖掉本地的修改。


### 装饰器使用规则说明

| \@LocalStorageProp变量装饰器 | 说明                                       |
| ----------------------- | ---------------------------------------- |
| 装饰器参数                   | key：常量字符串，必填（字符串需要有引号）。                  |
| 允许装饰的变量类型               | Object、class、string、number、boolean、enum类型，以及这些类型的数组。嵌套类型的场景请参考[观察变化和行为表现](#观察变化和行为表现)。<br/>类型必须被指定，且必须和LocalStorage中对应属性相同。不支持any，不允许使用undefined和null。 |
| 同步类型                    | 单向同步：从LocalStorage的对应属性到组件的状态变量。组件本地的修改是允许的，但是LocalStorage中给定的属性一旦发生变化，将覆盖本地的修改。 |
| 被装饰变量的初始值               | 必须指定，如果LocalStorage实例中不存在属性，则作为初始化默认值，并存入LocalStorage中。 |


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

- 当装饰的数据类型为class或者Object时，可以观察到赋值和属性赋值的变化，即Object.keys(observedObject)返回的所有属性。

- 当装饰的对象是array时，可以观察到数组添加、删除、更新数组单元的变化。


**框架行为**


- 当\@LocalStorageProp(key)装饰的数值改变被观察到时，修改不会被同步回LocalStorage对应属性键值key的属性中。

- 当前\@LocalStorageProp(key)单向绑定的数据会被修改，即仅限于当前组件的私有成员变量改变，其他的绑定该key的数据不会同步改变。

- 当\@LocalStorageProp(key)装饰的数据本身是状态变量，它的改变虽然不会同步回LocalStorage中，但是会引起所属的自定义组件的重新渲染。

- 当LocalStorage中key对应的属性发生改变时，会同步给所有\@LocalStorageProp(key)装饰的数据，\@LocalStorageProp(key)本地的修改将被覆盖。


## \@LocalStorageLink

如果我们需要将自定义组件的状态变量的更新同步回LocalStorage，就需要用到\@LocalStorageLink。

\@LocalStorageLink(key)是和LocalStorage中key对应的属性建立双向数据同步：

1. 本地修改发生，该修改会被回LocalStorage中；

2. LocalStorage中的修改发生后，该修改会被同步到所有绑定LocalStorage对应key的属性上，包括单向（\@LocalStorageProp和通过prop创建的单向绑定变量）、双向（\@LocalStorageLink和通过link创建的双向绑定变量）变量。


### 装饰器使用规则说明

| \@LocalStorageLink变量装饰器 | 说明                                       |
| ----------------------- | ---------------------------------------- |
| 装饰器参数                   | key：常量字符串，必填（字符串需要有引号）。                  |
| 允许装饰的变量类型               | Object、class、string、number、boolean、enum类型，以及这些类型的数组。嵌套类型的场景请参考[观察变化和行为表现](#观察变化和行为表现)。<br/>类型必须被指定，且必须和LocalStorage中对应属性相同。不支持any，不允许使用undefined和null。 |
| 同步类型                    | 双向同步：从LocalStorage的对应属性到自定义组件，从自定义组件到LocalStorage对应属性。 |
| 被装饰变量的初始值               | 必须指定，如果LocalStorage实例中不存在属性，则作为初始化默认值，并存入LocalStorage中。 |


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

- 当装饰的数据类型为class或者Object时，可以观察到赋值和属性赋值的变化，即Object.keys(observedObject)返回的所有属性。

- 当装饰的对象是array时，可以观察到数组添加、删除、更新数组单元的变化。


**框架行为**


1. 当\@LocalStorageLink(key)装饰的数值改变被观察到时，修改将被同步回LocalStorage对应属性键值key的属性中。

2. LocalStorage中属性键值key对应的数据一旦改变，属性键值key绑定的所有的数据（包括双向\@LocalStorageLink和单向\@LocalStorageProp）都将同步修改；

3. 当\@LocalStorageLink(key)装饰的数据本身是状态变量，它的改变不仅仅会同步回LocalStorage中，还会引起所属的自定义组件的重新渲染。


## 使用场景


### 应用逻辑使用LocalStorage


```ts
let storage = new LocalStorage({ 'PropA': 47 }); // 创建新实例并使用给定对象初始化
let propA = storage.get('PropA') // propA == 47
let link1 = storage.link('PropA'); // link1.get() == 47
let link2 = storage.link('PropA'); // link2.get() == 47
let prop = storage.prop('PropA'); // prop.get() = 47
link1.set(48); // two-way sync: link1.get() == link2.get() == prop.get() == 48
prop.set(1); // one-way sync: prop.get()=1; but link1.get() == link2.get() == 48
link1.set(49); // two-way sync: link1.get() == link2.get() == prop.get() == 49
```


### 从UI内部使用LocalStorage

除了应用程序逻辑使用LocalStorage，还可以借助LocalStorage相关的两个装饰器\@LocalStorageProp和\@LocalStorageLink，在UI组件内部获取到LocalStorage实例中存储的状态变量。

本示例以\@LocalStorage为例，展示了：

- 使用构造函数创建LocalStorage实例storage；

- 使用\@Entry装饰器将storage添加到CompA顶层组件中；

- \@LocalStorageLink绑定LocalStorage对给定的属性，建立双向数据同步。

  ```ts
  // 创建新实例并使用给定对象初始化
  let storage = new LocalStorage({ 'PropA': 47 });

  @Component
  struct Child {
    // @LocalStorageLink变量装饰器与LocalStorage中的'ProA'属性建立双向绑定
    @LocalStorageLink('PropA') storLink2: number = 1;

    build() {
      Button(`Child from LocalStorage ${this.storLink2}`)
        // 更改将同步至LocalStorage中的'ProA'以及Parent.storLink1
        .onClick(() => this.storLink2 += 1)
    }
  }
  // 使LocalStorage可从@Component组件访问
  @Entry(storage)
  @Component
  struct CompA {
    // @LocalStorageLink变量装饰器与LocalStorage中的'ProA'属性建立双向绑定
    @LocalStorageLink('PropA') storLink1: number = 1;

    build() {
      Column({ space: 15 }) {
        Button(`Parent from LocalStorage ${this.storLink1}`) // initial value from LocalStorage will be 47, because 'PropA' initialized already
          .onClick(() => this.storLink1 += 1)
        // @Component子组件自动获得对CompA LocalStorage实例的访问权限。
        Child()
      }
    }
  }
  ```


### \@LocalStorageProp和LocalStorage单向同步的简单场景

在下面的示例中，CompA 组件和Child组件分别在本地创建了与storage的'PropA'对应属性的单向同步的数据，我们可以看到：

- CompA中对this.storProp1的修改，只会在CompA中生效，并没有同步回storage；

- Child组件中，Text绑定的storProp2 依旧显示47。

  ```ts
  // 创建新实例并使用给定对象初始化
  let storage = new LocalStorage({ 'PropA': 47 });
  // 使LocalStorage可从@Component组件访问
  @Entry(storage)
  @Component
  struct CompA {
    // @LocalStorageProp变量装饰器与LocalStorage中的'ProA'属性建立单向绑定
    @LocalStorageProp('PropA') storProp1: number = 1;

    build() {
      Column({ space: 15 }) {
        // 点击后从47开始加1，只改变当前组件显示的storProp1，不会同步到LocalStorage中
        Button(`Parent from LocalStorage ${this.storProp1}`)
          .onClick(() => this.storProp1 += 1)
        Child()
      }
    }
  }

  @Component
  struct Child {
    // @LocalStorageProp变量装饰器与LocalStorage中的'ProA'属性建立单向绑定
    @LocalStorageProp('PropA') storProp2: number = 2;

    build() {
      Column({ space: 15 }) {
        // 当CompA改变时，当前storProp2不会改变，显示47
        Text(`Parent from LocalStorage ${this.storProp2}`)
      }
    }
  }
  ```


### \@LocalStorageLink和LocalStorage双向同步的简单场景

下面的示例展示了\@LocalStorageLink装饰的数据和LocalStorage双向同步的场景


```ts
// 构造LocalStorage实例
let storage = new LocalStorage({ 'PropA': 47 });
// 调用link9+接口构造'PropA'的双向同步数据，linkToPropA 是全局变量
let linkToPropA = storage.link('PropA');

@Entry(storage)
@Component
struct CompA {

  // @LocalStorageLink('PropA')在CompA自定义组件中创建'PropA'的双向同步数据，初始值为47，因为在构造LocalStorage已经给“PropA”设置47
  @LocalStorageLink('PropA') storLink: number = 1;

  build() {
    Column() {
      Text(`incr @LocalStorageLink variable`)
        // 点击“incr @LocalStorageLink variable”，this.storLink加1，改变同步回storage，全局变量linkToPropA也会同步改变 

        .onClick(() => this.storLink += 1)

      // 并不建议在组件内使用全局变量linkToPropA.get()，因为可能会有生命周期不同引起的错误。
      Text(`@LocalStorageLink: ${this.storLink} - linkToPropA: ${linkToPropA.get()}`)
    }
  }
}
```


### 兄弟组件之间同步状态变量

下面的示例展示了通过\@LocalStorageLink双向同步兄弟组件之间的状态。

先看Parent自定义组件中发生的变化：

1. 点击“playCount ${this.playCount} dec by 1”，this.playCount减1，修改同步回LocalStorage中，Child组件中的playCountLink绑定的组件会同步刷新；

2. 点击“countStorage ${this.playCount} incr by 1”，调用LocalStorage的set接口，更新LocalStorage中“countStorage”对应的属性，Child组件中的playCountLink绑定的组件会同步刷新；

3. Text组件“playCount in LocalStorage for debug ${storage.get&lt;number&gt;('countStorage')}”没有同步刷新，原因是因为storage.get&lt;number&gt;('countStorage')返回的是常规变量，常规变量的更新并不会引起Text组件的重新渲染。

Child自定义组件中的变化：

1. playCountLink的刷新会同步回LocalStorage，并且引起兄弟组件和父组件相应的刷新。

   ```ts
   let storage = new LocalStorage({ countStorage: 1 });

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
               storage.set<number>('countStorage', 1 + storage.get<number>('countStorage'));
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

上面的实例中，LocalStorage的实例仅仅在一个\@Entry装饰的组件和其所属的子组件（一个页面）中共享，如果希望其在多个视图中共享，可以在所属UIAbility中创建LocalStorage实例，并调用windowStage.[loadContent](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-window.md#loadcontent9)。


```ts
// EntryAbility.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  storage: LocalStorage = new LocalStorage({
    'PropA': 47
  });

  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', this.storage);
  }
}
```

在UI页面通过GetShared接口获取在通过loadContent共享的LocalStorage实例。


```ts
// 通过GetShared接口获取stage共享的LocalStorage实例
let storage = LocalStorage.GetShared()

@Entry(storage)
@Component
struct CompA {
  // can access LocalStorage instance using 
  // @LocalStorageLink/Prop decorated variables
  @LocalStorageLink('PropA') varA: number = 1;

  build() {
    Column() {
      Text(`${this.varA}`).fontSize(50)
    }
  }
}
```


> **说明：**
>
> 对于开发者更建议使用这个方式来构建LocalStorage的实例，并且在创建LocalStorage实例的时候就写入默认值，因为默认值可以作为运行异常的备份，也可以用作页面的单元测试。

<!--no_check-->