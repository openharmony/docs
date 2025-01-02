# 元能力子系统Changelog

## cl.formkit.1 PostCardAction的router事件允许拉起Ability类型范围变更

**访问级别**

公开接口

**变更原因**

PostCardAction的router事件当前未对被拉起的Ability类型进行校验，但实际此事件应只允许拉起UIAbility，针对使用router事件拉起非UIAbility的场景，需要做安全加固。

**变更影响**

该变更为不兼容变更。


变更前：通过PostCardAction接口的router事件，可以拉起所有类型的Ability。


变更后：通过PostCardAction接口的router事件，仅允许拉起UIAbility。

**起始 API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

PostCardAction

**适配指导**

应用侧使用PostCardAction接口的router事件拉起Ability时，需确保拉起的目标Ability属于UIAbility。若需要拉起其他类型的Ability，建议通过其他类型的事件，例如message事件， 跳转到FormExtensionAbility内处理。



## cl.formkit.2 FormLink的router事件允许拉起Ability类型范围变更

**访问级别**

公开接口

**变更原因**

FormLink的router事件当前未对被拉起的Ability类型进行校验，但实际此事件应只允许拉起UIAbility，针对使用router事件拉起非UIAbility的场景，需要做安全加固。

**变更影响**

该变更为不兼容变更。


变更前：通过FormLink接口的router事件，可以拉起所有类型的Ability。


变更后：通过FormLink接口的router事件，仅允许拉起UIAbility。

**起始 API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

FormLink

**适配指导**

应用侧使用FormLink接口的router事件拉起Ability时，需确保拉起的目标Ability属于UIAbility。若需要拉起其他类型的Ability，建议通过其他类型的事件，例如message事件， 跳转到FormExtensionAbility内处理。