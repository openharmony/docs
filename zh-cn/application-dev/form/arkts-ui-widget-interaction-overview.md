# ArkTS卡片页面刷新概述

卡片使用方（例如：桌面）和卡片提供方均可以主动触发卡片页面刷新；另外卡片框架还会通过开发者声明的定时信息按需通知卡片提供方进行卡片刷新。因此卡片刷新包括卡片提供方主动触发刷新、卡片使用方主动触发刷新、卡片定时定点刷新，这些刷新方式均需要由卡片提供方推送需要刷新的卡片数据。

## 卡片数据交互

ArkTS卡片框架提供卡片提供方（例如：应用）和卡片的数据交互能力。其中卡片通过[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction-1)传递数据给卡片提供方，卡片提供方可以通过[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口传递数据给卡片。卡片提供方将数据提供给卡片后，可以用于卡片页面刷新等。

由于卡片提供方和卡片为相互独立的进程，两者间的数据共享只能通过[LocalStorageProp](../ui/state-management/arkts-localstorage.md#localstorageprop)传递，不能使用getContext方法。因此卡片提供方推送数据后，卡片UI需要通过LocalStorageProp接收数据，且接收数据时，卡片数据会被转换成string类型。

## 页面刷新分类

根据触发方式的差异，卡片刷新分为主动刷新和被动刷新。

### 主动刷新

主动刷新包括卡片提供方主动刷新卡片和卡片使用方主动刷新卡片。开发指导请参考[ArkTS卡片主动刷新](arkts-ui-widget-active-refresh.md)。

**图1 卡片提供方主动刷新卡片流程图**

![updateForm](figures/updateForm.PNG)

卡片提供方应用运行过程中，如果识别到有要更新卡片数据的诉求，可以主动通过formProvider提供的[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口更新卡片。

**图2 卡片使用方主动刷新卡片流程图**

![requestForm](figures/requestForm.PNG)

卡片使用方在运行过程中，如果检测到系统语言、深浅色有变化时，可以主动通过formHost提供的requestForm（仅支持系统应用使用）接口请求更新卡片，卡片管理服务会进而通知卡片提供方完成卡片更新。

### 被动刷新

被动刷新包括定时刷新、定点刷新<!--Del-->和条件刷新<!--DelEnd-->。开发指导请参考[ArkTS卡片被动刷新](arkts-ui-widget-passive-refresh.md)。

卡片定时刷新：表示在一定时间间隔内调用[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)的生命周期回调函数自动刷新卡片内容。

卡片定点刷新：表示在每天的某个特定时间点自动刷新卡片内容。

<!--Del-->
卡片条件刷新：触发某种条件时的刷新，当前支持从无网络到有网络的条件时触发条件刷新。
<!--DelEnd-->

**图3 卡片框架通知卡片提供方定时定点刷新卡片流程图**

![timer_updateForm](figures/timer_updateForm.PNG)

根据卡片提供方开发者提前配置声明的定时刷新信息，卡片管理服务会根据定时信息、卡片可见状态、刷新次数等因素综合判断是否需要通知卡片提供方更新卡片。

## 约束与限制

1.卡片提供方仅允许刷新自己的卡片，其他提供方的卡片无法刷新。

2.卡片使用方仅允许刷新添加到自己的卡片，添加到其他使用方的卡片无法刷新。
