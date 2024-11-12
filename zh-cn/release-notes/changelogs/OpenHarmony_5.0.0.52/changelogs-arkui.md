# ArkUI子系统Changelog

## cl.arkui.1 RichEditor（富文本）onDidChange接口变更

**访问级别**

公开接口

**变更原因**

在用户执行删除操作，但实际未删除内容时（例如在aboutToDelete接口中拦截了删除操作），也回调了OnDidChange接口，不符合接口行为定义。

**变更影响**

该变更为不兼容变更。

变更前：
在用户执行删除操作，但实际未删除内容时回调了OnDidChange接口。

变更后：
在用户执行删除操作，但实际未删除内容时不回调OnDidChange接口。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.52开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.2 RichEditor（富文本）删除完成后光标位置变更

**访问级别**

公开接口

**变更原因**

开发者在aboutToDelete回调中设置光标/选中区后，删除完成后，光标位置异常。

**变更影响**

该变更为不兼容变更。

变更前：

1、开发者在aboutToDelete回调中设置光标，删除完成后，光标位置为开发者设置的光标位置。

2、开发者在aboutToDelete回调中设置选中区，删除完成后，光标位置为开发者设置的选中区的右边界。

变更后：
开发者在aboutToDelete回调中设置光标/选中区，删除完成后，光标位置为被删除内容的起始索引位置。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.52开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。


## cl.arkui.3 RichEditor（富文本）从组件外拖入内容onWillChange、onDidChange回调变更

**访问级别**

公开接口

**变更原因**

从组件外拖入内容时，onWillChange、onDidChange多回调了一次相同的内容，不符合实际文本变化情况。

**变更影响**

该变更为不兼容变更。

变更前：
从组件外拖入内容时，onWillChange、onDidChange回调了两次同样的内容。

变更后：
从组件外拖入时，onWillChange、onDidChange回调一次。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.52开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.4 RichEditor（富文本）onWillChange接口返回值变更

**访问级别**

公开接口

**变更原因**

在添加Symbol时onWillChange接口返回值中缺少了SymbolId。

**变更影响**

该变更为不兼容变更。

变更前：
在使用addSymbolSpan接口添加symbol时，onWillChange接口返回的RichEditorTextSpanResult中的value字段为空。

变更后：
在使用addSymbolSpan接口添加symbol时，onWillChange接口返回的RichEditorTextSpanResult中的value字段返回SymboId。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.52开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.5 RichEditor（富文本）TypingStyle默认字体大小变更

**访问级别**

公开接口

**变更原因**

开发者在设置TypingStyle但是没有设置其中的字体大小时，TypingStyle的默认字体大小为14px，显示效果异常。

**变更影响**

该变更为不兼容变更。

变更前：
开发者使用setTypingStyle接口设置TypingStyle但是没有设置其中的字体大小时，输入新的内容，新输入的文本字体大小为14px。

变更后：
开发者使用setTypingStyle接口设置TypingStyle但是没有设置其中的字体大小时，输入新的内容，新输入的文本字体大小为16fp。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.52开始。

**变更的接口/组件**

RichEditor

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。