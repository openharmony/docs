# 组件扩展概述
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

ArkUI通过@Builder装饰器为开发者提供代码精简解决方案，该装饰器不仅能通过模块化封装简化UI开发流程，还衍生出@BuilderParam装饰器、@LocalBuilder装饰器和wrapBuilder，形成完整的可复用的UI结构体系。

> **说明：**
>
> @Builder装饰器是@BuilderParam装饰器、@LocalBuilder装饰器和wrapBuilder的基石。

## @Builder装饰器

[@Builder装饰器](./arkts-builder.md)装饰器专为构建模块化、可复用的UI结构而设计，其内部禁止定义状态变量和调用组件生命周期方法，仅支持通过参数与调用方进行数据交互。

## @LocalBuilder装饰器

在使用@Builder实现组件间数据传递时，开发者需注意组件层级关系。组件树中的父子关系可能与状态管理的父子关系产生不一致。为此，框架提供了[@LocalBuilder装饰器](./arkts-localBuilder.md)装饰器来解决这一特定问题。

## @BuilderParam装饰器

当多个场景共用同一个@Builder函数时，若需要为特定场景扩展功能（类似slot占位符机制），可通过[@BuilderParam装饰器](./arkts-builderparam.md)装饰器实现，该装饰器专门用于接收并封装@Builder函数。

## wrapBuilder

当页面中存在多个具有不同UI结构的全局@Builder函数时，开发者会面临较高的维护成本。为此，框架提供了[wrapBuilder](./arkts-wrapBuilder.md)机制来简化这一场景下的代码维护工作。