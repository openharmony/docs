# 交互事件概述


通用事件按照触发类型来分类，包括触屏事件、键鼠事件、焦点事件和拖拽事件。


- [触屏事件](arkts-common-events-touch-screen-event.md)：手指或手写笔在触屏上的单指或单笔操作。

- [键鼠事件](arkts-common-events-device-input-event.md)：包括外设鼠标或触控板的操作事件和外设键盘的按键事件。
  - 鼠标事件是指通过连接和使用外设鼠标/触控板操作时所响应的事件。
  - 按键事件是指通过连接和使用外设键盘操作时所响应的事件。

- [焦点事件](arkts-common-events-focus-event.md)：通过以上方式控制组件焦点的能力和响应的事件。

- [拖拽事件](arkts-common-events-drag-event.md)：由触屏事件和键鼠事件发起，包括手指/手写笔长按组件拖拽和鼠标拖拽。

- [事件分发](arkts-common-events-distribute.md)：描述触控类事件（不包括按键，焦点）响应链的命中收集过程。

手势事件由绑定手势方法和绑定的手势组成，绑定的手势可以分为单一手势和组合手势两种类型，根据手势的复杂程度进行区分。


- [绑定手势方法](arkts-gesture-events-binding.md)：用于在组件上绑定单一手势或组合手势，并声明所绑定的手势的响应优先级。

- [单一手势](arkts-gesture-events-single-gesture.md)：手势的基本单元，是所有复杂手势的组成部分。

- [组合手势](arkts-gesture-events-combined-gestures.md)：由多个单一手势组合而成，可以根据声明的类型将多个单一手势按照一定规则组合成组合手势，并进行使用。
