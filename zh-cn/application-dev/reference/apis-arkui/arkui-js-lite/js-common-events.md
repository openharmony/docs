# 通用事件


相对于私有事件，大部分组件都可以绑定如下事件。


| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| click | - | 点击动作触发该事件。 |
| longpress | - | 长按动作触发该事件。 |
| swipe<sup>5+</sup> | SwipeEvent | 组件上快速滑动后触发。 |


SwipeEvent 基础事件对象属性列表（继承BaseEvent）

| 属性 | 类型 | 说明 |
| -------- | -------- | -------- |
| direction | string | 滑动方向，可能值有：<br/>1.&nbsp;left：向左滑动；<br/>2.&nbsp;right：向右滑动；<br/>3.&nbsp;up：向上滑动；<br/>4.&nbsp;down：向下滑动。 |
