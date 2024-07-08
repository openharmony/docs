## cl.arkui.1 UIExtensionComponent以及CreateModalUIExtension增加使用约束

**访问级别**

系统接口

**变更原因**

UIExtensionComponent以及CreateModalUIExtension增加使用约束。

**变更影响**

该变更为非兼容性变更。

UIExtensionComponent增加系统应用访问校验。

CreateModalUIExtension增加禁止其他组件遮挡的校验逻辑。

CreateModalUIExtension更改默认行为为防不安全窗口遮挡，且不允许取消防遮挡。

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

UIExtensionComponent以及CreateModalUIExtension。

**适配指导**

使用UIExtensionComponent的必须为系统应用。

CreateModalUIExtension禁止其他组件和非安全窗口遮挡。

## cl.arkui.2 DatePickerDialog显示时间时分割线延长

**访问级别**

公开接口

**变更原因**

修正视觉效果以获得更好的用户体验。

**变更影响**

该变更为不兼容变更。

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

默认行为变更，无需适配。

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

## cl.arkui.7 hideNonSecureWindows接口行为变更

**访问级别**

系统接口

**变更原因**

不安全窗口类型扩展以及CreateModalUIExtension防不安全窗口遮挡行为变更。

**变更影响**

该变更为非兼容性变更。

不安全窗口的定义新增宿主创建的Dialog窗口，变更前后不安全窗口包含的窗口类型如下表所示。

| 变更前 | 变更后 |
| --- | --- |
| <br>非系统全局悬浮窗 <br>宿主创建的非系统子窗 | <br>非系统全局悬浮窗 <br>宿主创建的非系统子窗 <br>宿主创建的非系统Dialog窗口 |


CreateModalUIExtension防不安全遮挡行为变更，变更前后行为如下表所示
| 变更前 | 变更后 |
| --- | --- |
| CreateModalUIExtension默认行为为不防不安全窗口遮挡，允许系统应用设置防不安全窗口遮挡 | CreateModalUIExtension默认行为为防不安全窗口遮挡，且不允许取消防遮挡 |

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

hideNonSecureWindows接口。

**适配指导**

接口行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.8 AlphabetIndexer组件autoCollapse属性默认值由false改为true

**访问级别**

公开接口

**变更原因**

自适应折叠模式使用场景更广，显示效果更加灵活，默认开启自适应折叠模式更符合开发者期望。

**变更影响**

该变更为不兼容变更。

API version 12之前：autoCollapse属性默认值为false，当AlphabetIndexer组件高度不足时，不会折叠显示。

![AlphabetIndexer_Before](figures/AlphabetIndexer_Before.png)

API version 12及之后：autoCollapse属性默认值为true，当AlphabetIndexer组件高度不足时，会折叠显示。

![AlphabetIndexer_After](figures/AlphabetIndexer_After.png)

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

AlphabetIndexer组件

**适配指导**

默认行为变更，默认开启自适应折叠模式，若要关闭自适应折叠模式，可通过设置[autoCollapse](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md#autocollapse11)属性进行适配。

## cl.arkui.9 RichEditor组件builderSpan支持绑定自定义菜单

**访问级别**

公开接口

**变更原因**

富文本支持builderSpan绑定自定义菜单。

**变更影响**

该变更为不兼容变更。

变更前：右击或长按builderSpan会弹出对RichEditorSpanType.IMAGE类型绑定的自定义菜单。

变更后：新增自定义菜单绑定类型RichEditorSpanType.BUILDER，builderSpan和imageSpan分开绑定和弹出自定义菜单。右击或长按builderSpan不再弹出对RichEditorSpanType.IMAGE类型绑定的自定义菜单，而是弹出对RichEditorSpanType.BUILDER类型绑定的自定义菜单。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

RichEditor组件的RichEditorSpanType接口。

**适配指导**

若开发者需要右击或长按builderSpan时弹出RichEditorSpanType.IMAGE类型的自定义菜单，需要对该自定义菜单绑定RichEditorSpanType.BUILDER类型。
```ts
@Entry
@Component
struct Example {
    @Builder
    menu() {
        Column() {
            Text("自定义菜单");
        }
    }
    build() {
        Column() {
            RichEditor({controller： new RichEditorController()})
                // 变更前
                .bindSelectionMenu(RichEditorSpanType.IMAGE, this.menu(), ResponseType.LongPress)

                // 变更后
                .bindSelectionMenu(RichEditorSpanType.IMAGE, this.menu(), ResponseType.LongPress)
                // 绑定RichEditorSpanType.BUILDER类型
                .bindSelectionMenu(RichEditorSpanType.BUILDER, this.menu(), ResponseType.LongPress)
        }
    }
}