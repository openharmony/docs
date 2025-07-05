# UI显示异常问题定位工具

UI显示异常问题主要是通过分析UI布局信息来定位。

## 分析UI布局的工具

### 组件树

可以通过[getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md)接口获取组件树及组件属性。

### 单个节点

可以通过[getRectangleById](../reference/apis-arkui/js-apis-arkui-UIContext.md#getrectanglebyid)接口获取组件大小、位置、平移、缩放、旋转及仿射矩阵属性信息。
