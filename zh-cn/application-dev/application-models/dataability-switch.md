# DataAbility切换

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

[FA模型](ability-terminology.md#fa模型)中的DataAbility对应[Stage模型](ability-terminology.md#stage模型)中的DataShareExtensionAbility。


与ServiceExtensionAbility类似，Stage模型下的DataShareExtensionAbility为系统API，只有系统应用才可以创建。因此，FA模型的DataAbility的切换，对于系统应用和三方应用策略有所不同。下面分别介绍这两种场景。


## 系统应用DataAbility切换至DataShareExtensionAbility

迁移步骤和PageAbility基本一致。

1. 在Stage应用中创建DataShareExtensionAbility。

2. 将FA应用中DataAbility的业务代码迁移到新创建的DataShareExtensionAbility中。
     DataAbility和DataShareExtensionAbility生命周期对比见下表。
     | FA的DataAbility | Stage的DataShareExtensionAbility | 对比描述 |
   | -------- | -------- | -------- |
   | onInitialized?(info:&nbsp;AbilityInfo):&nbsp;void | onCreate?(want:&nbsp;Want,&nbsp;callback:<br/>AsyncCallback&lt;void&gt;):&nbsp;void | 两者调用时机一致，函数名即入参都不一样，Stage模型下增加了入参want以便开发者在创建时获取参数。 |
   | update?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;rdb.ValuesBucket,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | update?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataSharePredicates.DataSharePredicates,&nbsp;value:&nbsp;ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 两者意义和调用时机一致，参数顺序和参数类型略有不同，需要简单改造。 |
   | query?(uri:&nbsp;string,&nbsp;columns:&nbsp;Array&lt;string&gt;,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):&nbsp;void | query?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataSharePredicates.DataSharePredicates,&nbsp;columns:&nbsp;Array&lt;string&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;Object&gt;):&nbsp;void | 两者意义和调用时机一致，参数顺序和参数类型略有不同，需要简单改造。 |
   | delete?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | delete?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataSharePredicates.DataSharePredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 两者意义和调用时机一致，参数类型略有不同，需要简单改造。 |
   | normalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | normalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | 两者意义和调用时机一致，参数也一致。 |
   | batchInsert?(uri:&nbsp;string,&nbsp;valueBuckets:&nbsp;Array&lt;rdb.ValuesBucket&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | batchInsert?(uri:&nbsp;string,&nbsp;values:&nbsp;Array&lt;ValuesBucket&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 两者意义和调用时机一致，参数类型略有不同，需要简单改造。 |
   | denormalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | denormalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | 两者意义和调用时机一致，参数也一致。 |
   | insert?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;rdb.ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | insert?(uri:&nbsp;string,&nbsp;value:&nbsp;ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 两者意义和调用时机一致，参数类型略有不同，需要简单改造。 |
   | openFile?(uri:&nbsp;string,&nbsp;mode:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | NA | Stage模型不支持uri跨进程访问，建议通过[want携带FD和文件信息](file-processing-apps-startup.md)进行跨进程文件访问。 |
   | getFileTypes?(uri:&nbsp;string,&nbsp;mimeTypeFilter:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;string&gt;&gt;):&nbsp;void | NA | Stage模型不支持uri跨进程访问，建议通过[want携带FD和文件信息](file-processing-apps-startup.md)进行跨进程文件访问。 |
   | getType?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | NA | Stage模型不支持uri跨进程访问，建议通过[want携带FD和文件信息](file-processing-apps-startup.md)进行跨进程文件访问。 |
   | executeBatch?(ops:&nbsp;Array&lt;DataAbilityOperation&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;DataAbilityResult&gt;&gt;):&nbsp;void | NA | DataShareExtensionAbility不提供该接口，开发者需根据业务功能重新实现。 |
   | call?(method:&nbsp;string,&nbsp;arg:&nbsp;string,&nbsp;extras:&nbsp;PacMap,&nbsp;callback:&nbsp;AsyncCallback&lt;PacMap&gt;):&nbsp;void | NA | DataShareExtensionAbility不提供该接口，开发者需根据业务功能重新实现。 |


## 三方应用DataAbility改造为公共模块

Stage模型三方应用不能对其他三方提供数据，应用需要根据具体业务选择切换方案。

| DataAbility业务类型 | 切换DataShareExtension策略 |
| -------- | -------- |
| 对三方提供数据 | 需根据业务场景匹配到系统对应的场景化[ExtensionAbility](../reference/apis-ability-kit/js-apis-bundleManager.md#extensionabilitytype)。 |
| 应用内使用的数据 | 对应用内其他组件提供数据，建议提取公共模块。 |
