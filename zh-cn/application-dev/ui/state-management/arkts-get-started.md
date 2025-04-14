# 初识ArkTS语言


ArkTS是OpenHarmony优选的主力应用开发语言。ArkTS围绕应用开发在[TypeScript](https://www.typescriptlang.org/)（简称TS）生态基础上做了进一步扩展，保持了TS的基本风格，同时通过规范定义强化开发期静态检查和分析，提升程序执行稳定性和性能。


从API version 10开始，ArkTS进一步通过规范强化静态检查和分析，对比标准TS的差异可以参考[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md)：


- 强制使用静态类型：静态类型是ArkTS最重要的特性之一。如果使用静态类型，那么程序中变量的类型就是确定的。同时，由于所有类型在程序实际运行前都是已知的，编译器可以验证代码的正确性，从而减少运行时的类型检查，有助于性能提升。

- 禁止在运行时改变对象布局：为实现最大性能，ArkTS要求在程序执行期间不能更改对象布局。

- 限制运算符语义：为获得更好的性能并鼓励开发者编写更清晰的代码，ArkTS限制了一些运算符的语义。比如，一元加法运算符只能作用于数字，不能用于其他类型的变量。

- 不支持Structural typing：对Structural typing的支持需要在语言、编译器和运行时进行大量的考虑和仔细的实现，当前ArkTS不支持该特性。根据实际场景的需求和反馈，我们后续会重新考虑。


当前，在UI开发框架中，ArkTS主要扩展了如下能力：


- [基本语法](arkts-basic-syntax-overview.md)：ArkTS定义了声明式UI描述、自定义组件和动态扩展UI元素的能力，再配合ArkUI开发框架中的系统组件及其相关的事件方法、属性方法等共同构成了UI开发的主体。

- [状态管理](arkts-state-management-overview.md)：ArkTS提供了多维度的状态管理机制。在UI开发框架中，与UI相关联的数据可以在组件内使用，也可以在不同组件层级间传递，比如父子组件之间、爷孙组件之间，还可以在应用全局范围内传递或跨设备传递。另外，从数据的传递形式来看，可分为只读的单向传递和可变更的双向传递。开发者可以灵活地利用这些能力来实现数据和UI的联动。

- [渲染控制](arkts-rendering-control-overview.md)：ArkTS提供了渲染控制的能力。条件渲染可根据应用的不同状态，渲染对应状态下的UI内容。循环渲染可从数据源中迭代获取数据，并在每次迭代过程中创建相应的组件。数据懒加载从数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。


ArkTS兼容TS/JavaScript(简称JS)生态，开发者可以使用TS/JS进行开发或复用已有代码。OpenHarmony系统对TS/JS支持的详细情况参见[兼容TS/JS的约束](arkts-migration-background.md#方舟运行时兼容tsjs)。


未来，ArkTS会结合应用开发/运行的需求持续演进，逐步提供并行和并发能力增强、系统类型增强、分布式开发范式等更多特性。

如需更详细了解ArkTS语言，可见[ArkTS具体指南](../arkts-utils/arkts-overview.md)。