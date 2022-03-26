# 基本概念

基于TS扩展的声明式开发范式提供了一系列基础组件，这些组件以声明方式进行组合和扩展来描述应用程序的UI界面，并且还提供了基本的数据绑定和事件处理机制，帮助开发者实现应用交互逻辑。


## HelloWorld基本示例

```
// An example of displaying Hello World. After you click the button, Hello UI is displayed.
@Entry
@Component
struct Hello {
    @State myText: string = 'World'
    build() {
        Column() {
            Text('Hello')
                .fontSize(30)
            Text(this.myText)
                .fontSize(32)
            Divider()
            Button() {
                Text('Click me')
                .fontColor(Color.Red)
            }.onClick(() => {
                this.myText = 'UI'
            })
            .width(500)
            .height(200)
        }
    }
}
```


## 基本概念描述

上述示例代码描述了简单页面的结构，并介绍了以下基本概念：

- 装饰器：方舟开发框架定义了一些具有特殊含义的装饰器，用于装饰类、结构、方法和变量。例如，上例中的@Entry、@Component和@State都是装饰器。

- 自定义组件：可重用的UI单元，可以与其他组件组合，如@Component装饰的struct Hello。

- UI描述：声明性描述UI结构，例如build()方法中的代码块。

- 内置组件：框架中默认内置的基本组件和布局组件，开发者可以直接调用，如Column、Text、Divider、Button等。

- 属性方法：用于配置组件属性，如fontSize()、width()、height()、color()等。

- 事件方法：在事件方法的回调中添加组件响应逻辑。例如，为Button组件添加onClick方法，在onClick方法的回调中添加点击响应逻辑。
