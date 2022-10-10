# 分布式数据管理子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，分布式数据管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.data.distributedData | KVStore     | deleteBackup(files:Array\<string>, callback: AsyncCallback\<Array\<[string, number]>>):void;<br>deleteBackup(files:Array\<string>): Promise\<Array\<[string, number]>>;                                                                                       | 新增 |
| ohos.data.distributedData | KVStore     | restore(file:string, callback: AsyncCallback\<void>):void;<br>restore(file:string): Promise\<void>;                                                                                                                                                           | 新增 |
| ohos.data.distributedData | KVStore     | backup(file:string, callback: AsyncCallback\<void>):void;<br>backup(file:string): Promise\<void>;                                                                                                                                                             | 新增 |
| ohos.data.rdb             | StoreConfig | encrypt?: boolean;                                                                                                                                                                                                                                             | 新增 |
| ohos.data.rdb             | RdbStore    | remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>; | 新增 |
| ohos.data.rdb             | RdbStore    | batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;                                                                              | 新增 |
| ohos.data.dataShare | DataShareHelper | getFileTypes(uri: string,  mimeTypeFilter:string, callback: AsyncCallback\<Array\<string>>): void;<br>getFileTypes(uri: string,  mimeTypeFilter: string): Promise\<Array\<string>>; | 删除 |
| ohos.data.dataShare | DataShareHelper | getType(uri: string, callback: AsyncCallback\<string>): void;<br>getType(uri: string): Promise\<string>;                                                                       | 删除 |
| ohos.data.dataShare | DataShareHelper | openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void;<br>openFile(uri: string, mode: string): Promise\<number>;                                         | 删除 |