# 组件扩展概述

ArkUI通过@Builder装饰器为开发者提供代码精简解决方案，该装饰器不仅能通过模块化封装简化UI开发流程，还衍生出@BuilderParam装饰器、@LocalBuilder装饰器和wrapBuilder，形成完整的组件复用技术链。

> **说明：**
>
> @Builder装饰器是@BuilderParam装饰器、@LocalBuilder装饰器和wrapBuilder的基石。

## @Builder装饰器

[@Builder装饰器](./arkts-builder.md)适用于模块化/可复用的UI结构，内部不能定义状态变量和调用组件的生命周期，仅与使用方（调用方）进行数据传递。

## @BuilderParam装饰器

当多个场景同时调用@Builder时，要给某一个场景的@Builder增加特定功能的使用，类似于slot占位符。[@BuilderParam装饰器](./arkts-builderparam.md)只能用来承接@Builder函数。

## @LocalBuilder装饰器

当使用@Builder进行数据传递时，开发者需要考虑组件间的层级关系，使用bind(this)之后，组件的父子关系和状态管理的父子关系并不一致，为了解决这一问题，引入[@LocalBuilder装饰器](./arkts-localBuilder.md)。

## wrapBuilder

当一个页面内存在多个全局@Builder，并且每个全局@Builder都有不同的UI结构时，会导致开发者维护起来比较困难，故引入[wrapBuilder](./arkts-wrapBuilder.md)。