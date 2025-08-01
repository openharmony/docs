# 交互响应概述
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

ArkUI框架提供了丰富的交互功能，支持直接处理基础输入事件，以及由这些事件驱动的手势系统，同时支持拖拽、焦点切换等复杂交互。

## 基础输入事件

当用户操作输入设备（例如触摸屏、键盘、鼠标、触控板）时，底层设备驱动会产生操作信号。系统捕捉这些信号并传递给应用程序，这些信号即为基础事件。

根据基础事件特点总体上分为两类，**指向性**与**非指向性**事件。

### 指向性事件

指向性事件是指包含事件发生位置信息的事件，此类事件以此次交互的第一个事件（Down/Begin类型）发生时所命中的组件来确定派发目标。

包括：[触摸事件](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md)，[鼠标事件](../reference/apis-arkui/arkui-ts/ts-universal-mouse-key.md)，[轴事件](../reference/apis-arkui/arkui-ts/ts-universal-events-axis.md)。


### 非指向性事件

非指向性事件是指没有具体位置信息的事件，即事件的发生不依赖于特定的操作位置信息。此类事件以当前焦点组件为派发目标。

包括：[按键事件](../reference/apis-arkui/arkui-ts/ts-universal-events-key.md)，[表冠事件](../reference/apis-arkui/arkui-ts/ts-universal-events-crown.md)，[焦点轴事件](../reference/apis-arkui/arkui-ts/ts-universal-events-focus_axis.md)。


### 其他说明

基础事件通常以一个标志开始的事件作为起始，以一个标志结束的事件作为结尾。在两者之间，会持续上报众多移动或更新事件。例如，触控事件的序列通常为Down, Move, Move..., Up；鼠标滚轮操作产生的轴事件的序列为Begin, Update, Update, ... End。

部分基础事件不具备此类特征，例如按键事件，仅存在Down和Up两种状态，且Down状态可在持续按压时不间断地上报。

对于指向性事件，系统会尽可能保证参与响应的组件可以得到完整的序列，这可以帮助你掌握处理开始与结束的时机；但对于非指向事件，系统并没有这样的保障，由于焦点的变化，开始与结束可能被分发到不同的组件上。

## 手势系统

手势是一系列基础事件不断上报积累后，达成一定特点时所被识别成的交互结果，如点击：按下并在较短时间内抬起。

如果使用ArkUI系统组件，系统会自动识别和响应这些组件上的手势，如按钮、列表，也可以在组件上绑定处理手势。一个组件上可绑定多个手势，这些手势可以由组件内置默认绑定，也可以由应用显式绑定。这些手势会在用户按下时，通过命中测试被收集上来，由系统统一管理，所有手势都会持续接收到输入事件，直到有一个手势满足条件，在这之后，就只有这一个手势可以继续接收和处理输入事件。

如果希望两个手势非此即彼，则可以考虑使用互斥手势，如果希望两个手势互不影响，则可以考虑使用并行手势，请参考[组合手势](arkts-gesture-events-combined-gestures.md)；

如果希望在用户按下时，才动态决定哪些手势能够参与处理，请参考[手势拦截](arkts-gesture-events-gesture-judge.md)。


## 统一拖拽

请参考[支持统一拖拽](arkts-common-events-drag-event.md)。

## 焦点系统

请参考[支持焦点处理](arkts-common-events-focus-event.md)。

