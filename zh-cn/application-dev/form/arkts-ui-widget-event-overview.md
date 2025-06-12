# ArkTS卡片页面交互概述

ArkTS卡片中提供了[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction)接口和[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)用于页面跳转、拉起应用和消息传递等卡片内部和提供方应用间的交互，当前支持router、message和call三种类型的事件，仅在卡片中可以调用。

卡片事件的主要使用场景如下：
- router事件：可以使用router事件跳转到指定UIAbility，以完成点击卡片跳转应用内页面的交互功能。对于非系统应用仅支持跳转到自己应用内的UIAbility。
- call事件：可以使用call事件拉起指定UIAbility到后台，再通过UIAbility申请对应后台长时任务完成音乐播放等功能。
- message事件：可以使用message拉起FormExtensionAbility，通过onFormEvent接口回调通知，以完成卡片内控件点击消息传递，从而更新卡片内容。
