# 基本语法概述


在初步了解了ArkTS语言之后，我们以一个具体的示例来说明ArkTS的基本组成。如下图所示，当开发者点击按钮时，文本内容从“Hello World”变为“Hello ArkUI”。


  **图1** 示例效果图  

![Video_2023-03-06_152548](figures/Video_2023-03-06_152548.gif)


本示例中，ArkTS的基本组成如下所示。


  **图2** ArkTS的基本组成  

![arkts-basic-grammar](figures/arkts-basic-grammar.png)


> **说明：**
>
> 自定义变量不能与基础通用属性/事件名重复。


- 装饰器： 用于装饰类、结构、方法以及变量，并赋予其特殊的含义。如上述示例中\@Entry、\@Component和\@State都是装饰器，[@Component](arkts-create-custom-components.md#component)表示自定义组件，[@Entry](arkts-create-custom-components.md#entry)表示该自定义组件为入口组件，[@State](arkts-state.md)表示组件中的状态变量，状态变量变化会触发UI刷新。

- [UI描述](arkts-declarative-ui-description.md)：以声明式的方式来描述UI的结构，例如build()方法中的代码块。

- [自定义组件](arkts-create-custom-components.md)：可复用的UI单元，可组合其他组件，如上述被\@Component装饰的struct Hello。

- 系统组件：ArkUI框架中默认内置的基础和容器组件，可直接被开发者调用，比如示例中的Column、Text、Divider、Button。

- [属性方法](../reference/apis-arkui/arkui-ts/ts-component-general-attributes.md)：组件可以通过链式调用配置多项属性，如fontSize()、width()、height()、backgroundColor()等。

- [事件方法](../reference/apis-arkui/arkui-ts/ts-component-general-events.md)：组件可以通过链式调用设置多个事件的响应逻辑，如跟随在Button后面的onClick()。


除此之外，ArkTS扩展了多种语法范式来使开发更加便捷：


- [@Builder](arkts-builder.md)/[@BuilderParam](arkts-builderparam.md)：特殊的封装UI描述的方法，细粒度的封装和复用UI描述。

- [@Extend](arkts-extend.md)/[@Styles](arkts-style.md)：扩展内置组件和封装属性样式，更灵活地组合内置组件。

- [stateStyles](arkts-statestyles.md)：多态样式，可以依据组件的内部状态的不同，设置不同样式。

## 相关实例

针对ArkTS开发和基础知识，有以下相关实例可供参考：

- [ArkTS基础知识（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/RankingDemo)

- [目标管理（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/TargetManagement)