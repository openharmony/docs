## cl.arkui.1 UIExtensionComponent以及CreateModalUIExtension增加使用约束

**访问级别**

系统接口

**变更原因**

UIExtensionComponent以及CreateModalUIExtension增加使用约束

**变更影响**

该变更为非兼容性变更。

UIExtensionComponent增加系统应用访问校验

CreateModalUIExtension增加禁止其他组件遮挡的校验逻辑

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

UIExtensionComponent以及CreateModalUIExtension

**适配指导**

使用UIExtensionComponent的必须为系统应用

CreateModalUIExtension禁止其他组件遮挡

## cl.arkui.2 DatePickerDialog显示时间时分割线延长

**访问级别**

公开接口

**变更原因**

修正视觉效果以获得更好的用户体验。

**变更影响**

该变更为非兼容性变更。

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

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.3 hideNonSecureWindows接口行为变更

**访问级别**

系统接口

**变更原因**



**变更影响**

该变更为非兼容性变更。

非安全窗口的定义新增宿主创建的Dialog窗口，变更前后非安全窗口包含的窗口类型如下表所示

| 变更前 | 变更后 |
| --- | --- |
| <br>非系统悬浮窗 <br>宿主窗口的非系统子窗 | <br>非系统悬浮窗 <br>宿主窗口的非系统子窗 <br>**宿主窗口创建的非系统Dialog窗口** |

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

hideNonSecureWindows

**适配指导**

接口行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。