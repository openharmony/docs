# ArkUI子系统Changelog

## cl.arkui.1 List组件首次创建布局时，Scroller控制器的跳转方法优先级变更为高于initialIndex的优先级

**访问级别**

公开接口

**变更原因**

initialIndex仅支持设定起始index，并默认将列表头部对齐，这使得开发者无法自定义对齐策略。scrollToIndex允许指定index与对齐方式，然而其效果会被 initialIndex覆盖。因此，需要提升scrollToIndex的优先级，使其高于initialIndex。这样一来，在组件初次布局时，如果开发者希望设定起始index并同时指定对齐方式，即可通过使用scrollToIndex来达成目标。


**变更影响**

该变更为不兼容变更。

场景1：List设置initialIndex为0 (默认也是0)，并在首次布局前调用scrollToIndex(1)。

| 变更前 | 变更后 |
|------ |--------|
|List首次布局将从index为0的ListItem开始布局。</br>![listdemo1](figures/listdemo1.png)|List首次布局将从index为1的ListItem开始布局。</br>![listdemo2](figures/listdemo2.png)|

场景2：List设置initialIndex为0 (默认也是0)，并在首次布局前调用scrollEdge(Edge.Bottom)。

| 变更前 | 变更后 |
|------ |--------|
|List首次布局将展示在顶部，即index为0的ListItem处于顶部。</br>![listdemo1](figures/listdemo1.png)|List首次布局将展示在底部，即index为最大值的ListItem处于底部。</br>![listdemo3](figures/listdemo3.png)|


**起始API Level**

API 7

**变更发生版本**

从OpenHarmony 5.0.0.57开始。

**变更的接口/组件**

List组件的initialIndex接口和Scroller控制器的跳转接口（scrollToIndex、scrollToItemInGroup和scrollEdge）。

**适配指导**

需要对使用List组件的页面进行排查，检查是否在onAppear或其他List组件首次布局之前的阶段，同时设置了initialIndex并调用了scrollToIndex,、scrollToItemInGroup或scrollEdge接口。在变更后，initialIndex的生效优先级将低于scrollToIndex、scrollToItemInGroup或scrollEdge的优先级。

## cl.arkui.2 Canvas使用toDataURL接口生成图片，对于带有透明度的图片，创建为“image/png”或“image/webp”格式时，其效果可能会发生变更

**访问级别**

公开接口

**变更原因**

变更前效果未达到预期。

**变更影响**

该变更为不兼容变更。

变更前：Canvas使用toDataURL接口生成图片，对于带有透明度的图片，创建为“image/png”或“image/webp”格式时，带透明度部分会与黑色背景混合，效果与原图有色差。

变更后：Canvas使用toDataURL接口生成图片，对于带有透明度的图片，创建为“image/png”或“image/webp”格式时，变更为与原图一致。

|                   变更前                   |                 变更后                  |
| :----------------------------------------: | :-------------------------------------: |
| ![toDataURLDemo](figures/toDataURLDemo1.png) | ![toDataURLDemo](figures/toDataURLDemo2.png) |

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.0.0.57开始。

**变更的接口/组件**

Canvas组件的toDataURL接口。

**适配指导**

默认效果变更，无需适配，但应注意变更后的效果是否符合预期。

## cl.arkui.3 RichEditor（富文本）预上屏候选词替换已上屏内容行为变更

**访问级别**

公开接口

**变更原因**

通过输入法点击候选词来替换富文本中已显示的单词，这种替换被视为正式内容的一部分，且能够被富文本的输入相关回调aboutToIMEInput所拦截。

**变更影响**

此变更涉及应用适配。

变更前：
当aboutToIMEInput回调返回false时，点击输入法候选词替换已上屏内容，候选词能够正常上屏，不会被拦截。


变更后：
当aboutToIMEInput回调返回false时，点击输入法候选词替换已上屏内容，候选词不可以上屏，会被拦截。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

RichEditor

**适配指导**

应用可以根据aboutToIMEInput回调入参中RichEditorInsertValue#previewText是否有值，判断此次插入是否是预上屏内容插入，进而执行对应逻辑。

## cl.arkui.4 RichEditor（富文本）设置提示文本时鼠标拖动光标回调变更。

**访问级别**

公开接口

**变更原因**

当组件设置了提示文本且无内容时，按住鼠标左键拖动会触发onSelect和onSelectionChange异常回调。

**变更影响**

此变更不涉及应用适配。

变更前：
当组件设置了提示文本且无内容时，若按住鼠标左键进行拖动操作，将触发onSelect和onSelectionChange异常回调，回调的范围界定为鼠标拖动时所覆盖的提示文本区域。

变更后：
当组件设置了提示文本且无内容时，若按住鼠标左键进行拖动操作，不触发onSelect和onSelectionChange回调。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配。

## cl.arkui.5 RichEditor（富文本）onDeleteComplete回调变更。

**访问级别**

公开接口

**变更原因**

在组件填充内容时，从内容的起始位置向前删除将触发onDeleteComplete回调，而从内容的末尾向后删除则不会触发onDeleteComplete回调，两者的表现不一致。

**变更影响**

此变更不涉及应用适配。

变更前：
在组件填充内容时，从内容的末尾向后删除不触发onDeleteComplete回调。

变更后：
在组件填充内容时，从内容的末尾向后删除触发onDeleteComplete回调。


**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配。