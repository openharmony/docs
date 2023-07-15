# \@Link装饰器：父子双向同步


子组件中被\@Link装饰的变量与其父组件中对应的数据源建立双向数据绑定。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。


## 概述

\@Link装饰的变量与其父组件中的数据源共享相同的值。


## 装饰器使用规则说明

| \@Link变量装饰器 | 说明                                       |
| ----------- | ---------------------------------------- |
| 装饰器参数       | 无                                        |
| 同步类型        | 双向同步。<br/>父组件中\@State,&nbsp;\@StorageLink和\@Link&nbsp;和子组件\@Link可以建立双向数据同步，反之亦然。 |
| 允许装饰的变量类型   | Object、class、string、number、boolean、enum类型，以及这些类型的数组。<br/>支持Date类型。支持类型的场景请参考[观察变化](#观察变化)。<br/>类型必须被指定，且和双向绑定状态变量的类型相同。<br/>不支持any，不支持简单类型和复杂类型的联合类型，不允许使用undefined和null。<br/>**说明：**<br/>不支持Length、ResourceStr、ResourceColor类型，Length、ResourceStr、ResourceColor为简单类型和复杂类型的联合类型。 |
| 被装饰变量的初始值   | 无，禁止本地初始化。                               |


## 变量的传递/访问规则说明

| 传递/访问      | 说明                                       |
| ---------- | ---------------------------------------- |
| 从父组件初始化和更新 | 必选。与父组件\@State,&nbsp;\@StorageLink和\@Link&nbsp;建立双向绑定。允许父组件中\@State、\@Link、\@Prop、\@Provide、\@Consume、\@ObjectLink、\@StorageLink、\@StorageProp、\@LocalStorageLink和\@LocalStorageProp装饰变量初始化子组件\@Link。<br/>从API&nbsp;version&nbsp;9开始，\@Link子组件从父组件初始化\@State的语法为Comp({&nbsp;aLink:&nbsp;this.aState&nbsp;})。同样Comp({aLink:&nbsp;$aState})也支持。 |
| 用于初始化子组件   | 允许，可用于初始化常规变量、\@State、\@Link、\@Prop、\@Provide。 |
| 是否支持组件外访问  | 私有，只能在所属组件内访问。                           |

  **图1** 初始化规则图示  

![zh-cn_image_0000001502092556](figures/zh-cn_image_0000001502092556.png)


## 观察变化和行为表现


### 观察变化

- 当装饰的数据类型为boolean、string、number类型时，可以同步观察到数值的变化，示例请参考[简单类型和类对象类型的@Link](#简单类型和类对象类型的link)。

- 当装饰的数据类型为class或者Object时，可以观察到赋值和属性赋值的变化，即Object.keys(observedObject)返回的所有属性，示例请参考[简单类型和类对象类型的@Link](#简单类型和类对象类型的link)。

- 当装饰的对象是array时，可以观察到数组添加、删除、更新数组单元的变化，示例请参考[数组类型的@Link](#数组类型的link)。

- 当装饰的对象是Date时，可以观察到Date整体的赋值，同时可通过调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 更新Date的属性。

```ts
@Component
struct DateComponent {
  @Link selectedDate: Date;

  build() {
    Column() {
      Button(`child increase the year by 1`).onClick(() => {
        this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1)
      })
      Button('child update the new date')
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-09-09')
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate
      })
    }

  }
}

@Entry
@Component
struct ParentComponent {
  @State parentSelectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('parent increase the month by 1')
        .margin(10)
        .onClick(() => {
          this.parentSelectedDate.setMonth(this.parentSelectedDate.getMonth() + 1)
        })
      Button('parent update the new date')
        .margin(10)
        .onClick(() => {
          this.parentSelectedDate = new Date('2023-07-07')
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.parentSelectedDate
      })

      DateComponent({selectedDate:this.parentSelectedDate})
    }
  }
}
```

### 框架行为

\@Link装饰的变量和其所述的自定义组件共享生命周期。

为了了解\@Link变量初始化和更新机制，有必要先了解父组件和拥有\@Link变量的子组件的关系，初始渲染和双向更新的流程（以父组件为\@State为例）。

1. 初始渲染：执行父组件的build()函数后将创建子组件的新实例。初始化过程如下：
   1. 必须指定父组件中的\@State变量，用于初始化子组件的\@Link变量。子组件的\@Link变量值与其父组件的数据源变量保持同步（双向数据同步）。
   2. 父组件的\@State状态变量包装类通过构造函数传给子组件，子组件的\@Link包装类拿到父组件的\@State的状态变量后，将当前\@Link包装类this指针注册给父组件的\@State变量。

2. \@Link的数据源的更新：即父组件中状态变量更新，引起相关子组件的\@Link的更新。处理步骤：
   1. 通过初始渲染的步骤可知，子组件\@Link包装类把当前this指针注册给父组件。父组件\@State变量变更后，会遍历更新所有依赖它的系统组件（elementid）和状态变量（比如\@Link包装类）。
   2. 通知\@Link包装类更新后，子组件中所有依赖\@Link状态变量的系统组件（elementId）都会被通知更新。以此实现父组件对子组件的状态数据同步。

3. \@Link的更新：当子组件中\@Link更新后，处理步骤如下（以父组件为\@State为例）：
   1. \@Link更新后，调用父组件的\@State包装类的set方法，将更新后的数值同步回父组件。
   2. 子组件\@Link和父组件\@State分别遍历依赖的系统组件，进行对应的UI的更新。以此实现子组件\@Link同步回父组件\@State。


## 使用场景


### 简单类型和类对象类型的\@Link

以下示例中，点击父组件ShufflingContainer中的“Parent View: Set yellowButton”和“Parent View: Set GreenButton”，可以从父组件将变化同步给子组件，子组件GreenButton和YellowButton中\@Link装饰变量的变化也会同步给其父组件。


```ts
class GreenButtonState {
  width: number = 0;
  constructor(width: number) {
    this.width = width;
  }
}
@Component
struct GreenButton {
  @Link greenButtonState: GreenButtonState;
  build() {
    Button('Green Button')
      .width(this.greenButtonState.width)
      .height(150.0)
      .backgroundColor('#00ff00')
      .onClick(() => {
        if (this.greenButtonState.width < 700) {
          // 更新class的属性，变化可以被观察到同步回父组件
          this.greenButtonState.width += 125;
        } else {
          // 更新class，变化可以被观察到同步回父组件
          this.greenButtonState = new GreenButtonState(100);
        }
      })
  }
}
@Component
struct YellowButton {
  @Link yellowButtonState: number;
  build() {
    Button('Yellow Button')
      .width(this.yellowButtonState)
      .height(150.0)
      .backgroundColor('#ffff00')
      .onClick(() => {
        // 子组件的简单类型可以同步回父组件
        this.yellowButtonState += 50.0;
      })
  }
}
@Entry
@Component
struct ShufflingContainer {
  @State greenButtonState: GreenButtonState = new GreenButtonState(300);
  @State yellowButtonProp: number = 100;
  build() {
    Column() {
      // 简单类型从父组件@State向子组件@Link数据同步
      Button('Parent View: Set yellowButton')
        .onClick(() => {
          this.yellowButtonProp = (this.yellowButtonProp < 700) ? this.yellowButtonProp + 100 : 100;
        })
      // class类型从父组件@State向子组件@Link数据同步
      Button('Parent View: Set GreenButton')
        .onClick(() => {
          this.greenButtonState.width = (this.greenButtonState.width < 700) ? this.greenButtonState.width + 100 : 100;
        })
      // class类型初始化@Link
      GreenButton({ greenButtonState: $greenButtonState })
      // 简单类型初始化@Link
      YellowButton({ yellowButtonState: $yellowButtonProp })
    }
  }
}
```


### 数组类型的\@Link


```ts
@Component
struct Child {
  @Link items: number[];

  build() {
    Column() {
      Button(`Button1: push`).onClick(() => {
        this.items.push(this.items.length + 1);
      })
      Button(`Button2: replace whole item`).onClick(() => {
        this.items = [100, 200, 300];
      })
    }
  }
}

@Entry
@Component
struct Parent {
  @State arr: number[] = [1, 2, 3];

  build() {
    Column() {
      Child({ items: $arr })
      ForEach(this.arr,
        item => {
          Text(`${item}`)
        },
        item => item.toString()
      )
    }
  }
}
```


上文所述，ArkUI框架可以观察到数组元素的添加，删除和替换。在该示例中\@State和\@Link的类型是相同的number[]，不允许将\@Link定义成number类型（\@Link item : number），并在父组件中用\@State数组中每个数据项创建子组件。如果要使用这个场景，可以参考[\@Prop](arkts-prop.md)和\@Observed。

<!--no_check-->
