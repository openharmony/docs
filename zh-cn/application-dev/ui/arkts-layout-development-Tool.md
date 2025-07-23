# 定位UI显示异常问题

UI显示异常问题主要是通过分析UI布局信息来定位。

## 分析UI布局

当前分析UI布局主要通过getInspectorTree接口获取组件树信息，或者通过getRectangleById接口获取单个节点的信息。

### 组件树

从API version 9开始，可以使用[getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9)接口获取组件树及其属性。

### 单个节点

从API version 10开始，可以使用[getRectangleById](../reference/apis-arkui/arkts-apis-uicontext-componentutils.md#getrectanglebyid)接口获取组件的大小、位置、平移、缩放、旋转及仿射矩阵等属性信息。
