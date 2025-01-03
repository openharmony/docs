# ArkUI子系统Changelog

## cl.arkui.1 半模态弹簧曲线时长设置默认值

**访问级别**

公开接口

**变更原因**

开发者拉起用SheetSize.FIT_CONTENT声明的半模态的同时，立刻变更了半模态面板高度，造成半模态连续做了两个弹簧曲线动效。

半模态高度动效是没有设置时长的弹簧曲线，如果对高度值连续做两次动效，那么后一个动效会停止前面所有动效，只执行第二个动效，效果上为跳变现象，体验不佳。

**变更影响**

该变更为不兼容变更。

变更前：在拉起半模态的过程中同时更改半模态高度，半模态会做两次弹簧曲线动效，第一次动效直接到达终点，第二次动效从起点执行到终点，半模态onAppear和高度回调立即执行。

变更后：在拉起半模态的过程中同时更改半模态高度，半模态会做两次弹簧曲线动效，第一次动效和第二次动效都从起点执行到终点，半模态onAppear和高度回调在第一次动效结束后执行。

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.59开始。

**变更的接口/组件**

bindSheet的SheetSize.FIT_CONTENT属性。

**适配指导**

1、开发者在该场景下动效体验更优，回调时机更接近动效结束时间。

2、若对回调时机有严格要求，需避免异步触发两次动效，不要在拉起半模态的时候改变半模态高度。

## cl.arkui.2 半模态SheetMode.EMBEDDED模式支持响应ESC键退出

**访问级别**

公开接口

**变更原因**

半模态SheetMode.EMBEDDED模式不支持ESC键退出，变更后，支持SheetMode.EMBEDDED模式ESC键退出。

**变更影响**

该变更为不兼容变更。

变更前：SheetMode.OVERLAY模式的半模态响应ESC键退出，SheetMode.EMBEDDED模式的半模态不响应ESC键退出。

变更后：两种模式的半模态都响应ESC键，ESC键退出与手机侧滑体验保持一致。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.59开始。

**变更的接口/组件**

bindSheet的SheetMode.EMBEDDED属性。

**适配指导**

变更后，若开发者仍不期望ESC键退出半模态，可以通过半模态的[onWillDismiss](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions)回调控制是否响应ESC和侧滑关闭半模态。
```ts
onWillDismiss: ((DismissSheetAction: DismissSheetAction) => {
    if (DismissSheetAction.reason == DismissReason.PRESS_BACK) {
    } else {
        DismissSheetAction.dismiss() //注册dismiss行为会关闭半模态
    }
}),
```

## cl.arkui.3 RichEditor（富文本）RichEditorTextSpanResult接口返回值变更

**访问级别**

公开接口

**变更原因**

在应用添加文本或更新文本样式时，若未指定fontFamily，通过getSpans接口获取的文本信息中，fontFamily将显示默认值"HarmonyOS Sans"。然而，此默认值可能与系统实际应用的字体不一致，从而可能导致应用判断出现偏差。

**变更影响**

此变更不涉及应用适配。

变更前：
在应用中添加文本或更新文本样式时，若未指定fontFamily，通过getSpans接口获取的文本信息中，fontFamily将采用默认值"HarmonyOS Sans"。 

变更后：
在应用中添加文本或更新文本样式时，若未指定fontFamily，通过getSpans接口获取的文本信息中，fontFamily为""。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.59开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配。