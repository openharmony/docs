# 分布式数据管理子系统JS API变更

OpenHarmony 3.2 Canary1版本相较于OpenHarmony 3.1 Release版本，分布式数据管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.data.dataShare | DataShareHelper | notifyChange(uri: string, callback: AsyncCallback\<void>): void;<br>notifyChange(uri: string): Promise\<void>; | 新增 |
| ohos.data.dataShare | DataShareHelper | denormalizeUri(uri: string, callback: AsyncCallback\<string>): void;<br>denormalizeUri(uri: string): Promise\<string>; | 新增 |
| ohos.data.dataShare | DataShareHelper | normalizeUri(uri: string, callback: AsyncCallback\<string>): void;<br>normalizeUri(uri: string): Promise\<string>; | 新增 |
| ohos.data.dataShare | DataShareHelper | getFileTypes(uri: string,  mimeTypeFilter:string, callback: AsyncCallback\<Array\<string>>): void;<br>getFileTypes(uri: string,  mimeTypeFilter: string): Promise\<Array\<string>>; | 新增 |
| ohos.data.dataShare | DataShareHelper | getType(uri: string, callback: AsyncCallback\<string>): void;<br>getType(uri: string): Promise\<string>; | 新增 |
| ohos.data.dataShare | DataShareHelper | batchInsert(uri: string, values: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void;<br>batchInsert(uri: string, values: Array\<rdb.ValuesBucket>): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | update(uri: string, value: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void;<br>update(uri: string, value: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void;<br>query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates): Promise\<ResultSet>; | 新增 |
| ohos.data.dataShare | DataShareHelper | delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void;<br>delete(uri: string, predicates: dataAbility.DataAbilityPredicates): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | insert(uri: string, value: rdb.ValuesBucket, callback: AsyncCallback\<number>): void;<br>insert(uri: string, value: rdb.ValuesBucket): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void; | 新增 |
| ohos.data.dataShare | DataShareHelper | on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.data.dataShare | dataShare | createDataShareHelper(context: Context, want: Want, uri: string): DataShareHelper; | 新增 |
