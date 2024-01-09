# 卡片事件能力说明

针对动态卡片，ArkTS卡片中提供了[postCardAction()](../reference/apis/js-apis-postCardAction.md#postcardaction)接口用于卡片内部和提供方应用间的交互，当前支持router、message和call三种类型的事件，仅在卡片中可以调用。
<br/>针对静态卡片，ArkTS卡片提供了[FormLink](../reference/arkui-ts/ts-container-formlink.md)用于卡片内部和提供方应用间的交互。

## 动态卡片事件能力说明
![WidgetPostCardAction](figures/WidgetPostCardAction.png)

动态卡片事件包括三种类型：
- [使用router事件跳转到指定UIAbility](arkts-ui-widget-event-router.md)
- [使用call事件拉起指定UIAbility到后台](arkts-ui-widget-event-call.md)
- [通过message事件刷新卡片内容](arkts-ui-widget-event-formextensionability.md)

## 静态卡片事件能力说明
请参见[FormLink](../reference/arkui-ts/ts-container-formlink.md)
