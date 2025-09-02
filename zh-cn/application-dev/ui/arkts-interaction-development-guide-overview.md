# 添加交互响应
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

ArkUI框架提供了丰富的接口，用于处理用户通过不同外设生成的基础输入事件，同时提供了高级接口封装，以响应用户归一化的交互行为，如手势、拖拽、焦点等。

相较于基础输入事件，应优先采用手势处理用户交互，因为手势作为用户交互的识别结果，能够屏蔽不同基础事件的差异。例如，点击操作既可通过手指触控实现，也可通过鼠标点击完成，应用程序只需对接一个TapGesture即可在各类输入设备上支持点击交互。

[交互基础机制说明](arkts-interaction-basic-principles.md)：交互处理的基本概念和原理。

[输入设备与事件](arkts-interaction-development-guide-raw-input-event.md)：不同的输入设备会产生哪些基础输入事件，以及如何处理它们。

[添加手势响应](arkts-interaction-development-guide-support-gesture.md)：处理归一化手势交互。

[支持统一拖拽](arkts-common-events-drag-event.md)：了解如何适配统一拖拽。

[支持焦点处理](arkts-common-events-focus-event.md)：了解如何控制和管理界面中的组件焦点。

通过以下链接了解使用`NDK`开发UI界面时，如何为组件添加交互响应：
- [监听组件事件](ndk-listen-to-component-events.md)：通过NDK为组件添加基础事件响应。
- [绑定手势事件](ndk-bind-gesture-events.md)：通过NDK为组件添加手势交互。
- [拖拽事件](ndk-drag-event.md)：通过NDK为组件支持统一拖拽。