# 元能力子系统Changelog

## cl.ability.1  三方应用间显示拉起增加限制

**访问级别**

公开接口

**变更原因**

三方应用间跳转方式提供了link方案。

**变更影响**

该变更为非兼容性变更。

API version 11及以前，三方应用之间跳转可以通过显示拉起。

API version 12及以后，三方应用之间跳转需要通过link方式进行跳转，限制显式拉起。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**示例：**

无

**变更的接口/组件**

 - 涉及的应用组件
   - Stage模型
     - UIAbilityContext
     - UIExtensionContext
 - 涉及接口
   - Stage模型
     - UIAbilityContext
       - startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;
       - startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;
       - startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;
       - startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;
       - startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;
       - startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;
     - UIExtensionContext
       - startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;
       - startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;
       - startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;
       - startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;
       - startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;;AbilityResult&gt;): void;
       - startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

**适配指导**

请查阅[Stage模型应用间跳转适配](../../../application-dev/application-models/uiability-startup-adjust.md)文档进行适配。