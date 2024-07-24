# 卡片数据交互说明

ArkTS卡片框架提供了[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform)接口和requestForm接口主动触发卡片的页面刷新，通过[LocalStorageProp](../quick-start/arkts-localstorage.md#localstorageprop)确认需要刷新的卡片数据。

![WidgetLocalStorageProp](figures/WidgetLocalStorageProp.png)


| 接口 | 是否系统能力 | 约束 |
| -------- | -------- | -------- |
| updateForm | 否 | 1.&nbsp;提供方调用。<br/>2.&nbsp;提供方仅允许刷新自己的卡片，其他提供方的卡片无法刷新。 |
| requestForm | 是 | 1.&nbsp;使用方调用。<br/>2.&nbsp;仅允许刷新添加到当前使用方的卡片，添加到其他使用方的卡片无法刷新。 |

下面介绍卡片页面刷新的典型场景。

- [卡片定时刷新和定点刷新](arkts-ui-widget-update-by-time.md)
- [刷新本地图片和网络图片](arkts-ui-widget-image-update.md)
- [根据卡片状态刷新不同内容](arkts-ui-widget-update-by-status.md)
