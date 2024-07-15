# DataAbility的生命周期


应用开发者可以根据业务场景实现data.js/data.ets中的生命周期相关接口。DataAbility生命周期接口说明见下表。


  **表1** DataAbility相关生命周期API功能介绍

| 接口名 | 描述 | 
| -------- | -------- |
| onInitialized?(info:&nbsp;AbilityInfo):&nbsp;void | 在Ability初始化调用，通过此回调方法执行RDB等初始化操作。 | 
| update?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;rdb.ValuesBucket,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 更新数据库中的数据。 | 
| query?(uri:&nbsp;string,&nbsp;columns:&nbsp;Array&lt;string&gt;,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):&nbsp;void | 查询数据库中的数据。 | 
| delete?(uri:&nbsp;string,&nbsp;predicates:&nbsp;dataAbility.DataAbilityPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 删除一条或多条数据。 | 
| normalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | 对URI进行规范化。一个规范化的URI可以支持跨设备使用、持久化、备份和还原等，当上下文改变时仍然可以引用到相同的数据项。 | 
| batchInsert?(uri:&nbsp;string,&nbsp;valueBuckets:&nbsp;Array&lt;rdb.ValuesBucket&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 向数据库中插入多条数据。 | 
| denormalizeUri?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | 将一个由normalizeUri生产的规范化URI转换成非规范化的URI。 | 
| insert?(uri:&nbsp;string,&nbsp;valueBucket:&nbsp;rdb.ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 向数据中插入一条数据。 | 
| openFile?(uri:&nbsp;string,&nbsp;mode:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 打开一个文件。 | 
| getFileTypes?(uri:&nbsp;string,&nbsp;mimeTypeFilter:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;string&gt;&gt;):&nbsp;void | 获取文件的MIME类型。 | 
| getType?(uri:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp;void | 获取URI指定数据相匹配的MIME类型。 | 
| executeBatch?(ops:&nbsp;Array&lt;DataAbilityOperation&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;DataAbilityResult&gt;&gt;):&nbsp;void | 批量操作数据库中的数据。 | 
| call?(method:&nbsp;string,&nbsp;arg:&nbsp;string,&nbsp;extras:&nbsp;PacMap,&nbsp;callback:&nbsp;AsyncCallback&lt;PacMap&gt;):&nbsp;void | 自定义方法。 | 
