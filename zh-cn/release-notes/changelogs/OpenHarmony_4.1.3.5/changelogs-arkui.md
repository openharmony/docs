# ArkUI子系统ChangeLog

##  cl.arkui.1 工具链对Scroll的拦截规则变更

**访问级别**

公开接口

**变更原因**

[Scroll](../../../application-dev/reference/arkui-ts/ts-container-scroll.md)组件仅支持设置单个子组件。为了避免开发者为Scroll组件添加多个子组件，编译器添加报错提示。

**变更影响**

该变更为非兼容性变更。编译器对添加了多个子组件的Scroll组件添加报错提示，不会改变其布局和行为。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

Scroll

**适配指导**

删除Scroll组件下添加的多余子组件。

##  cl.arkui.2 形状裁剪clip接口变更说明

**访问级别**

公开接口

**变更原因**

Text组件为基础文本组件，其截断与裁剪由textOverflow属性控制，clip属性不应当在Text组件上使用，否则会与textOverflow属性冲突，在复杂场景下影响Text组件正常显示。

**变更影响**

该变更为不兼容变更，修改后Text组件不支持使用clip属性。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的组件**

受影响的组件有：Text。

**适配指导**

变更前：Text组件支持使用clip属性。

```typescript
Text('Text Demo').clip(true)
```

变更后：Text组件不支持使用clip属性，如需设置文本裁剪，请开发者设置textOverflow属性。

```typescript
Text('Text Demo').textOverflow({ overflow: TextOverflow.Clip })
```