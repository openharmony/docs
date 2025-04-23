# 其他状态管理概述


除了前面章节提到的组件状态管理和应用状态管理，ArkTS还提供了\@Watch、$$运算符和\@Track来为开发者提供更多功能：


- [\@Watch](arkts-watch.md)：用于监听状态变量的变化。

- [$$运算符](arkts-two-way-sync.md)：给系统组件提供TS变量的引用，使得TS变量和系统组件的内部状态保持同步。

- [\@Track](arkts-track.md)：应用于class对象的属性级更新。\@Track装饰的属性变化时，只会触发该属性关联的UI更新。

- [自定义组件冻结](arkts-custom-components-freeze.md)：当自定义组件处于非激活状态时，状态变量将不响应更新。
