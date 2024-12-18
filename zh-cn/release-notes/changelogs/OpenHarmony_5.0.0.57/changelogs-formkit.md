# 元能力子系统Changelog

## cl.formkit.1 FormMgrAdapter::RouterEvent接口内调用StartAbility和StartAbilityManagerSpecifyTokenId改为调用StartAbilityOnlyUIAbility。

**访问级别**

公开接口

**变更原因**

FormMgrAdapter::RouterEvent预期设计要求仅支持拉起UIAbility，但变更前可以拉起所有类型的Ability，存在安全漏洞

**变更影响**

该变更为不兼容变更。


变更前：通过FormMgrAdapter::RouterEvent接口可以拉起所有类型的Ability。


变更后：通过FormMgrAdapter::RouterEvent接口只能拉起UIAbility。

**起始 API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

FormMgrAdapter::RouterEvent

**适配指导**

应用侧使用postCardAction接口拉起Ability时，需确保拉起的目标Ability属于UIAbility。若需要拉起其他类型的Ability，应考虑使用postCardAction之外的其他接口。