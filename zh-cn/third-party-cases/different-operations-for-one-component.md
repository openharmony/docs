# 如何为同一组件在不同场景下绑定不同的业务逻辑

## 场景介绍
在应用开发过程中经常遇到这样的场景：在不同的地方需要呈现同样的UI效果，为了简化处理，往往会把对应的UI元素封装成自定义组件，然后在用到的地方进行调用。但是，通常情况下，UI展示往往伴随着动态交互，而且在不同场景下需要做不同的交互处理。

*比如：A、B两个页面都有返回按钮，但是在A页面中点击返回按钮是返回上一页，在B页面点击返回按钮是直接退出当前应用。同样是点击返回按钮，但是业务处理逻辑是不同的。*
那么在不同场景下调用同一组件的时候如何实现不同的交互逻辑呢？这就引出了本文要讲的内容。

## 实现思路
要使同一组件实现不同效果，我们很容易就想到通过变量传参进行控制，而不是直接在程序中采用固定值，这样就可以根据不同场景传入不同参数从而实现不同效果。
通过传参的方式改变组件的属性，比如：大小、边框、背景色、字体等等，同样的，也可以通过传参的方式改变组件绑定的业务逻辑，只不过此时传入的是含有业务逻辑的方法。
接下来我们用一个简单的例子讲解如何实现。

## 开发示例

本示例将在一个页面中两次引用同一个按钮，然后为两次引用加入不同的处理逻辑，第一次引用中，点击按钮跳转到“Hello World!”页面；第二次引用中，点击按钮跳转到“Hello ArkTS!”页面。

### 环境要求
- IDE：DevEco Studio 3.1 Beta1
- SDK：Ohos_sdk_public 3.2.11.9 (API Version 9 Release)

### 开发步骤
1. 创建按钮组件

    首先，创建被引用的按钮组件。
    这里需要注意的是，由于按钮要绑定不同的处理逻辑，所以我们在点击事件中不要写入固定的处理逻辑，而是传入一个自定义的空方法，该方法的逻辑在父组件中实现，然后传入。具体代码如下：
    ```ts
    @Component
    struct ChildComponent{
      @State button_text:string = 'hi'
      // 定义一个空函数
      child_func:()=>void
      build(){
        Button(`${this.button_text}`)
          .height(100)
          .width(200)
          .onClick(() => {
            // 在组件的点击事件中绑定之前定义的空函数
            this.child_func()
        })
      }
    }
    ```

2. 在父组件中引用按钮组件

    接下来，我们在父组件中引用两次第1步中创建的按钮组件。具体代码如下：
    ```ts
    @Entry
    @Component
    struct  FuncTransition{
      build() {
        Column(){
          // 引用按钮组件
          ChildComponent({button_text:'Hello World'})
            .margin(50)
          ChildComponent({button_text:'Hello ArkTS'})
        }
        .width('100%')
        .height('100%')
        .justifyContent(FlexAlign.Center)
      }
    }
    ```

3. 在父组件中传入处理逻辑

    以上两步已经把页面框架搭好了，接下来给按钮组件传入处理逻辑，这也是最重要的一步。
    在第1步中为按钮组件的点击事件绑定了一个空函数，现在我们在父组件中创建一个带有具体处理逻辑的函数，并将其传入按钮组件中。在父组件中可以通过为同一函数传入不同参数来为两个按钮组件绑定不同逻辑，也可以通过不同函数来实现，本例中采用前者进行实现。具体代码如下：
    ```ts
    import router from '@ohos.router'
    @Entry
    @Component
    struct  FuncTransition{
      // 在父组件中创建逻辑处理函数，此处逻辑为页面跳转。
      parent_func(page_url){
        router.pushUrl({
          url:page_url
        })
      }
      build() {
        Column(){
          // 在第1处引用的子组件中传入父组件中定义的函数，此处为跳转到''Hello World!''页面
          ChildComponent({child_func:()=>{this.parent_func('pages/HelloWorld')},button_text:'Hello World'})
            .margin(50)
          // 在第2处引用的子组件中传入父组件中定义的函数，此处为跳转到''Hello ArkTS!''页面
          ChildComponent({child_func:()=>{this.parent_func('pages/HelloArkTS')},button_text:'Hello ArkTS'})
        }
        .width('100%')
        .height('100%')
        .justifyContent(FlexAlign.Center)
      }
    }
    ```

    通过以上步骤我们实现了在为同一按钮组件绑定不同的业务处理逻辑，接下来看下效果吧！
    注意：文中的“Hello World!”页面和“Hello ArkTS!”页面不是本文说明的重点，所以本文中不做开发介绍。

    ![相同子组件不同业务逻辑](figures/different-operations-one-component.gif)

## 完整代码
示例完整代码如下：
```ts
import router from '@ohos.router'
@Entry
@Component
struct  FuncTransition{
  parent_func(page_url){
    router.pushUrl({
      url:page_url
    })
  }
  build() {
    Column(){
      ChildComponent({child_func:()=>{this.parent_func('pages/HelloWorld')},button_text:'Hello World'})
        .margin(50)
      ChildComponent({child_func:()=>{this.parent_func('pages/HelloArkTS')},button_text:'Hello ArkTS'})
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}

@Component
struct ChildComponent{
  @State button_text:string = 'hi'
  child_func:()=>void
  build(){
    Button(`${this.button_text}`)
      .height(100)
      .width(200)
      .onClick(() => {
        this.child_func()
    })
  }
}
```