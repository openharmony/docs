# 声明式UI开发指导

## 开发说明

声明式UI的工程结构还请参考[OpenHarmony APP工程结构介绍](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-project-overview-0000001218440650#section133380945818)。其中，.ets结尾的ArkTS文件用于描述UI布局、样式、事件交互和页面逻辑，支持导入TypeScript和JavaScript文件。资源目录resources文件夹位于src/main下，此目录下资源文件的详细规范以及子目录结构规范参看[资源分类与访问](../quick-start/resource-categories-and-access.md)。

在开发页面之前，请先[学习ArkTS语言](../quick-start/arkts-get-started.md)了解声明式UI的基本语法。

在开发页面时，可先根据使用场景，在[常见布局](ui-ts-layout-linear.md)中选择合适的布局。再根据页面需要实现的内容，为页面添加系统内置组件，更新组件状态。页面开发过程中请参考[自定义组件的生命周期](ui-ts-custom-component-lifecycle-callbacks.md)了解如何添加需要的生命周期回调方法。

也可在页面中添加[绘图](../reference/arkui-ts/ts-drawing-components-circle.md)和[动画](../reference/arkui-ts/ts-animatorproperty.md)，丰富页面的展现形态。还可以使用[路由](../reference/apis/js-apis-router.md)实现多个页面之间的跳转和数据传递。

另外请参考[性能提升的推荐方法](ui-ts-performance-improvement-recommendation.md)，避免低性能代码对应用的性能造成负面影响。

## 创建页面

请先根据页面预期效果选择布局结构创建页面，并在页面中添加基础的系统内置组件。下述示例采用了[弹性布局（Flex）](ui-ts-layout-flex.md)，对页面中的Text组件进行横纵向居中布局显示。

   ```ts
    // xxx.ets
    @Entry
    @Component
    struct MyComponent {
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Text('Hello')
        }        
        .width('100%')
        .height('100%')
      }
    }
   ```

## 修改组件样式

创建系统内置组件时，若不设置属性方法，则会显示其默认样式。通过更改组件的属性样式或者组件支持的[通用属性](../reference/arkui-ts/ts-universal-attributes-size.md)样式，设置可以改变组件的UI显示。

1. 通过修改Text组件的构造参数，将Text组件的显示内容修改为“Tomato”。

2. 修改Text组件的fontSize属性更改组件的字体大小，将字体大小设置为26，通过fontWeight属性更改字体粗细，将其设置为500。fontWeight属性支持三种设置方式：

   a. number类型的取值范围为100到900，取值间隔为100，默认为400，取值越大，字体越粗。

   b. FontWeight为内置枚举类型，取值支持FontWeight.Lighter、FontWeight.Normal、FontWeight.Regular、FontWeight.Medium、FontWeight.Bold、FontWeight.Bolder。FontWeight.Normal即为400数值的字体粗细。

   c. string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。设置其他字符串则为无效，保持默认字体粗细显示。

   属性方法要紧随组件，通过“.”操作符连接，也可以通过链式调用的方式配置组件的多个属性。

   ```ts
    // xxx.ets
    @Entry
    @Component
    struct MyComponent {
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Text('Tomato')
            .fontSize(26)
            .fontWeight(500)
        }
        .width('100%')
        .height('100%')
      }
    }
   ```

   ![zh-cn_image_0000001168888224](figures/zh-cn_image_0000001168888224.png)

## 组件成员变量初始化

自定义组件的成员变量可以通过[本地初始化](../quick-start/arkts-restrictions-and-extensions.md#自定义组件成员变量初始化的方式与约束)和[在构造组件时通过构造参数初始化](../quick-start/arkts-restrictions-and-extensions.md#自定义组件成员变量初始化的方式与约束)两种方式实现，具体允许哪种方式取决于该变量所使用的装饰器：


**示例：**

```ts
// xxx.ets
class ClassA {
  public str: string

  constructor(str: string) {
    this.str = str
  }
}

@Entry
@Component
struct Parent {
  // Parent的变量parentState进行本地初始化
  @State parentState: ClassA = new ClassA('hello')

  build() {
    Column() {
      Row() {
        CompA({ aState: new ClassA('Tomato'), aLink: $parentState })
      }
      // aState在CompA中已进行初始化，因此可以缺省
      Row() {
        CompA({ aLink: $parentState })
      }
    }.width('100%')
  }
}

@Component
struct CompA {
  // CompA中的变量aState进行本地初始化，aLink在Parent中使用时通过构造参数初始化
  @State aState: any = new ClassA('CompA')
  @Link aLink: ClassA

  build() {
    Row() {
      Text(JSON.stringify(this.aState)).fontSize(20).margin(30)
      Text(JSON.stringify(this.aLink)).fontSize(20).margin(30)
    }
  }
}
```

![component](figures/component.PNG)

## 组件的状态更新

组件的状态可以通过动态修改组件成员变量的值来更新，下面以示例来进行说明。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct ParentComp {
  @State isCountDown: boolean = true

  build() {
    Column() {
      Text(this.isCountDown ? 'Count Down' : 'Stopwatch').fontSize(20).margin(20)
      if (this.isCountDown) {
        // 图片资源放在media目录下
        Image($r("app.media.countdown")).width(120).height(120)
        TimerComponent({ counter: 10, changePerSec: -1, showInColor: Color.Red })
      } else {
        // 图片资源放在media目录下
        Image($r("app.media.stopwatch")).width(120).height(120)
        TimerComponent({ counter: 0, changePerSec: +1, showInColor: Color.Black })
      }
      Button(this.isCountDown ? 'Switch to Stopwatch' : 'Switch to Count Down')
        .onClick(() => {
          this.isCountDown = !this.isCountDown
        })
    }.width('100%')
  }
}

// 自定义计时器/倒计时组件
@Component
struct TimerComponent {
  @State counter: number = 0
  private changePerSec: number = -1
  private showInColor: Color = Color.Black
  private timerId: number = -1

  build() {
    Text(`${this.counter}sec`)
      .fontColor(this.showInColor)
      .fontSize(20)
      .margin(20)
  }

  aboutToAppear() {
    this.timerId = setInterval(() => {
      this.counter += this.changePerSec
    }, 1000)
  }

  aboutToDisappear() {
    if (this.timerId > 0) {
      clearTimeout(this.timerId)
      this.timerId = -1
    }
  }
}
```

![component](figures/component.gif)

**初始创建和渲染：**

1. 创建父组件ParentComp；

2. 本地初始化ParentComp的状态变量isCountDown；

3. 执行ParentComp的build函数；

4. 创建Column组件；
   1. 创建Text组件，设置其文本展示内容，并将Text组件实例添加到Column中；
   2. 判断if条件，创建true条件下的元素；
       1. 创建Image组件，并设置其图片源地址；
       2. 使用给定的构造函数创建TimerComponent；
           1. 创建TimerComponent对象；
           2. 本地初始化成员变量初始值；
           3. 使用TimerComponent构造函数提供的参数更新成员变量的值；
           4. 执行TimerComponent的aboutToAppear函数；
           5. 执行TimerComponent的build函数，创建相应的UI描述结构；
   3. 创建Button内置组件，设置相应的内容。

**状态更新：**

用户单击按钮时：

1. ParentComp的isCountDown状态变量的值更改为false；

2. 执行ParentComp的build函数；

3. Column组件被重用并执行重新初始化；

4. Column的子组件会重用内存中的对象，但会进行重新初始化；
   1. Text组件会被重用，但使用新的文本内容进行重新初始化；
   2. 判断if条件，使用false条件下的元素；
       1. 原来true条件的组件不再使用，将这些组件销毁；
           1. 销毁Image组件实例；
           2. 销毁TimerComponent组件实例，aboutToDisappear函数被调用；
       2. 创建false条件下的组件；
           1. 创建Image组件，并设置其图片源地址；
           2. 使用给定的构造函数重新创建TimerComponent；
           3. 初始化TimerComponent，并调用aboutToAppear函数和build函数。
   3. 重用Button组件，使用新的图片源地址。
