# 使用inspector检查页面布局

从API version 9开始，inspector主要用于UI调试和分析，提高开发效率。

## 基本概念

inspector双向定位功能帮助开发者在IDE中快速定位组件、修改属性和调试组件，从而提高开发效率。
ArkUI获取当前显示页面中所有控件的信息，包括控件树的父子结构、大小、位置、样式、属性和状态。IDE获取控件树信息后，生成并展示为inspector控件树，IDE的使用具体可以参考[页面布局检查器ArkUI Inspector使用指导](../performance/arkUI-inspector.md)。

## 使用约束

1. 不支持动效类组件的控件树实时刷新功能。

2. 支持获取组件的属性和样式，但不支持获取controller和Builder对象。

3. 不支持获取组件的方法、事件和API。

## UIContext查询组件树和组件信息能力

@ohos.arkui.UIContext(UIContext)扩展能力，使用[getFilteredInspectorTree](../reference/apis-arkui/js-apis-arkui-UIContext.md#getfilteredinspectortree12)获取组件树及组件属性。支持设置过滤条件进行查询。

@ohos.arkui.UIContext(UIContext)扩展能力，使用[getFilteredInspectorTreeById](../reference/apis-arkui/js-apis-arkui-UIContext.md#getfilteredinspectortreebyid12)获取指定的组件及其子组件的属性。支持设置过滤条件进行查询。

## 布局回调

提供注册组件布局和组件绘制完成的回调通知能力，具体参考[@ohos.arkui.arkui.inspector(布局回调)](../reference/apis-arkui/js-apis-arkui-inspector.md)。

## 组件标识属性的扩展能力

提供以下能力：
- 获取指定id的组件的所有属性，参考[getInspectorByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectorbykey9)。
- 获取组件树及组件属性，参考[getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9)。
- 给指定id的组件发送事件，参考[sendEventByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#sendeventbykey9)。
