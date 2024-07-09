# ArkUI子系统Changelog

## cl.arkui.1 Navigation分割线触摸直接响应

**访问级别**

公开接口

**变更原因**

手指触摸Navigation分割线后可立即响应分割线的滑动。

**变更影响**

该变更为不兼容性变更。

API version 11及以前：手指需长按500ms，Navigation的分割线才可响应滑动。

API version 12及以后：手指触摸Navigation的分割线可立即响应滑动。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**适配指导**

默认行为变更，无需适配。