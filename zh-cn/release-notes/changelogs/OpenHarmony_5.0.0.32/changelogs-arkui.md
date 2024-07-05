## cl.arkui.1 UIExtensionComponent以及CreateModalUIExtension增加使用约束

**访问级别**

系统接口

**变更原因**

UIExtensionComponent以及CreateModalUIExtension增加使用约束

**变更影响**

该变更为非兼容性变更。

UIExtensionComponent增加系统应用访问校验

CreateModalUIExtension增加禁止其他组件遮挡的校验逻辑

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

UIExtensionComponent以及CreateModalUIExtension

**适配指导**

使用UIExtensionComponent的必须为系统应用

CreateModalUIExtension禁止其他组件遮挡

## cl.arkui.2 DatePickerDialog显示时间时分割线延长

**访问级别**

公开接口

**变更原因**

修正视觉效果以获得更好的用户体验。

**变更影响**

该变更为非兼容性变更。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/DatePickerDialogDivider_Before.jpg) | ![](figures/DatePickerDialogDivider_After.jpg) |

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

涉及的组件：DatePickerDialog。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.3 Menu组件箭头离宿主节点默认安全边距变更

**访问级别**

公开接口

**变更原因**

带箭头菜单离宿主节点过远，变更后效果更佳。

**变更影响**

API12变更之前：箭头离宿主节点16vp。

API12变更之后：箭头离宿主节点8vp。

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

带箭头菜单离宿主节点的默认安全距离变小，若需要更大的间距，可设置菜单的offset进行调整。

## cl.arkui.4 Menu组件上下文菜单点击关闭行为变更

**访问级别**

公开接口

**变更原因**

当前上下文菜单手指按下即关闭，为了更好支持后续交互体验，变更为抬手时关闭。

**变更影响**

API12变更之前：手指按下时，上下文菜单关闭。

API12变更之后：手指按下并抬手，上下文菜单关闭。

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

菜单关闭行为变更，应用无需适配。

## cl.arkui.5 Grid和List组件onItemDrag接口拖拽出窗口外行为变更
**访问级别**

公开接口

**变更原因**

由于窗口提供的拖拽窗口类型变更，新的窗口类型无法超出父窗口，导致onItemDrag拖拽窗口无法拖出应用窗口外。

**变更影响**

该变更为非兼容性变更。

API version 12之前，onItemDrag拖起的拖拽窗口可以拖出当前应用窗口外。

API version 12及以后，onItemDrag拖起的拖拽窗口不可以拖出当前应用窗口外。

**起始API Level**

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

Grid组件的onItemDragStart、onItemDragMove、onItemDragEnter、onItemDragLeave和onItemDrop方法

List组件的onItemDragStart、onItemDragMove、onItemDragEnter、onItemDragLeave和onItemDrop方法

**适配指导**

默认行为变更，无需适配。

## cl.arkui.6 List的ConstraintSize设置生效

**访问级别**

公开接口

**变更原因**

List的布局行为和当前通用的布局约束优先的规格不一致。

**变更影响**

该变更为非兼容性变更。

变更前，List不设置Height时，Constraint的minHeight设置不生效。

变更后，List不设置Height时，Constraint的minHeight设置会生效。

**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

List组件的ConstraintSize接口。

**适配指导**

默认行为变更，无需适配。