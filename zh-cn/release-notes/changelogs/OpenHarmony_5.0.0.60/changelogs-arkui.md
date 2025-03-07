# ArkUI子系统Changelog

## cl.ArkUI.1 FormMenu实现的功能变更为不支持穿戴设备

**访问级别**

公开接口

**变更原因**

穿戴设备上禁止使用FormMenu创建“添加至桌面”菜单。

**变更影响**

该变更为不兼容变更。

变更前：FormMenu组件在穿戴设备上允许使用。

变更后：FormMenu组件在穿戴设备上禁止使用。


**起始 API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.60开始。

**变更的接口/组件**  

@ohos.arkui.advanced.FormMenu.d.ets文件的AddFormMenuItem接口

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.2 半模态在2in1设备的阴影参数变更

**访问级别**

公开接口

**变更原因**

ux规格变更

**变更影响**

此变更不涉及应用适配。

| 变更前                                                                                                                     | 变更后                                                                                                                   |
| -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| 半模态在2in1设备的获焦态阴影参数和失焦态阴影参数都为[OUTER_FLOATING_MD](../../../application-dev/reference//apis-arkui//arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10枚举说明)。<br>![gauge_before](figures/sheet_focus.png)| 半模态在2in1设备的获焦态阴影参数为OUTER_FLOATING_MD，失焦态阴影参数为[OUTER_FLOATING_SM](../../../application-dev/reference//apis-arkui//arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10枚举说明)。<br>![gauge_after](figures/sheet_unfocus.png) |

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.60开始。

**变更的接口/组件**

bindSheet。

**适配指导**

默认效果变更，无需适配。