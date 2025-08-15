# LifecycleData接口切换
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


  | FA模型接口 | Stage模型接口对应d.ts文件 | Stage模型对应接口 | 
| -------- | -------- | -------- |
| update?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;rdb.ValuesBucket,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [update?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataSharePredicates.DataSharePredicates,&nbsp;valueBucket:&nbsp;ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#update) |
| query?(uri:&nbsp;string,&nbsp;columns:&nbsp;Array&lt;string&gt;,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [query?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataSharePredicates.DataSharePredicates,&nbsp;columns:&nbsp;Array&lt;string&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;Object&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#query) |
| delete?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [delete?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataSharePredicates.DataSharePredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#delete) |
| normalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [normalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#normalizeuri) |
| batchInsert?(uri:&nbsp;string,&nbsp;valueBuckets:&nbsp;Array&lt;rdb.ValuesBucket&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [batchInsert?(uri:&nbsp;string,&nbsp;valueBuckets:&nbsp;Array&lt;ValuesBucket&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#batchinsert) |
| denormalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [denormalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#denormalizeuri) |
| insert?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;rdb.ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [insert?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#insert) |
| openFile?(uri:&nbsp;string,&nbsp;mode:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void; | Stage模型无对应接口 | Stage模型不支持uri跨进程访问，建议通过want携带fd和文件信息进行跨进程文件访问，参考[通过startAbility拉起文件处理类应用](file-processing-apps-startup.md)。 |
| getFileTypes?(uri:&nbsp;string,&nbsp;mimeTypeFilter:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;string&gt;&gt;):&nbsp;void; | Stage模型无对应接口 | Stage模型不支持uri跨进程访问，建议通过want携带fd和文件信息进行跨进程文件访问，参考[通过startAbility拉起文件处理类应用](file-processing-apps-startup.md)。 |
| onInitialized?(info:&nbsp;AbilityInfo):&nbsp;void; | \@ohos.application.DataShareExtensionAbility.d.ts | [onCreate?(want:&nbsp;Want,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void;](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md#oncreate) |
| getType?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void; | Stage模型无对应接口 | Stage模型不支持uri跨进程访问，建议通过want携带fd和文件信息进行跨进程文件访问，参考[通过startAbility拉起文件处理类应用](file-processing-apps-startup.md)。 |
| executeBatch?(ops:&nbsp;Array&lt;DataAbilityOperation&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;DataAbilityResult&gt;&gt;):&nbsp;void; | Stage模型无对应接口 | 暂时未提供对应接口 |
| call?(method:&nbsp;string,&nbsp;arg:&nbsp;string,&nbsp;extras:&nbsp;PacMap,&nbsp;callback:&nbsp;AsyncCallback&lt;PacMap&gt;):&nbsp;void; | Stage模型无对应接口 | 暂时未提供对应接口 |
