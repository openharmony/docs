## cl.arkui.1 移动窗口布局模式瀑布流行为变更

**访问级别**

公开接口

**变更原因**

优化[移动窗口布局模式](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md#waterflowlayoutmode12)瀑布流使用LazyForEach增删节点时布局方式。

**变更影响**

变更前：在显示范围上方增加节点，显示范围节点会下移；在显示范围上方删除节点，显示范围节点会上移

变更后：在显示范围上方增删节点，显示范围不变

下表显示在显示范围上方增加一个节点时变更前后的效果对比：
| 增加节点前|变更前：N4显示到原N5的位置 | 变更后：N5位置不变 |
| --- |--- | --- |
|![waterflow](figures/waterflow.png) |![waterflow-before](figures/waterflow-before.png) |![waterflow-after](figures/waterflow-after.png)  |


**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony 5.0.0.36 版本开始。

**变更的接口/组件**

WaterFlow组件。

**适配指导**

默认行为变更，无需适配。
