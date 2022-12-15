# 分布式数据管理子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，分布式数据管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.data.dataShare | DataShareHelper | notifyChange(uri: string, callback: AsyncCallback\<void>): void;<br>notifyChange(uri: string): Promise\<void>; | 新增 |
| ohos.data.dataShare | DataShareHelper | denormalizeUri(uri: string, callback: AsyncCallback\<string>): void;<br>denormalizeUri(uri: string): Promise\<string>; | 新增 |
| ohos.data.dataShare | DataShareHelper | normalizeUri(uri: string, callback: AsyncCallback\<string>): void;<br>normalizeUri(uri: string): Promise\<string>; | 新增 |
| ohos.data.dataShare | DataShareHelper | getFileTypes(uri: string,  mimeTypeFilter: string, callback: AsyncCallback\<Array\<string>>): void;<br>getFileTypes(uri: string,  mimeTypeFilter: string): Promise\<Array\<string>>; | 新增 |
| ohos.data.dataShare | DataShareHelper | getType(uri: string, callback: AsyncCallback\<string>): void;<br>getType(uri: string): Promise\<string>; | 新增 |
| ohos.data.dataShare | DataShareHelper | batchInsert(uri: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>batchInsert(uri: string, values: Array\<ValuesBucket>): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback\<number>): void;<br>update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>, callback: AsyncCallback\<DataShareResultSet>): void;<br>query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>): Promise\<DataShareResultSet>; | 新增 |
| ohos.data.dataShare | DataShareHelper | delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;<br>delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | insert(uri: string, value: ValuesBucket, callback: AsyncCallback\<number>): void;<br>insert(uri: string, value: ValuesBucket): Promise\<number>; | 新增 |
| ohos.data.dataShare | DataShareHelper | off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void; | 新增 |
| ohos.data.dataShare | DataShareHelper | on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.data.dataShare | DataShareHelper | openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void;<br>openFile(uri: string, mode: string): Promise\<number>; | 新增 |
| ohos.data.dataShare | dataShare | function createDataShareHelper(context: Context, uri: string, callback: AsyncCallback\<DataShareHelper>): void;<br>function createDataShareHelper(context: Context, uri: string): Promise\<DataShareHelper>; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | inKeys(keys: Array\<string>): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | prefixKey(prefix: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | notIn(field: string, value: Array\<ValueType>): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | in(field: string, value: Array\<ValueType>): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | indexedBy(field: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | groupBy(fields: Array\<string>): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | limit(total: number, offset: number): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | distinct(): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | orderByDesc(field: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | orderByAsc(field: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | lessThan(field: string, value: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | greaterThan(field: string, value: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | between(field: string, low: ValueType, high: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | glob(field: string, value: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | unlike(field: string, value: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | like(field: string, value: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | isNotNull(field: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | isNull(field: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | endsWith(field: string, value: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | beginsWith(field: string, value: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | contains(field: string, value: string): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | and(): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | or(): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | endWrap(): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | beginWrap(): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | notEqualTo(field: string, value: ValueType): DataSharePredicates; | 新增 |
| ohos.data.dataSharePredicates | DataSharePredicates | equalTo(field: string, value: ValueType): DataSharePredicates; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getDataType(columnIndex: number): DataType; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getColumnName(columnIndex: number): string; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getColumnIndex(columnName: string): number; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | close(): void; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getDouble(columnIndex: number): number; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getLong(columnIndex: number): number; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getString(columnIndex: number): string; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | getBlob(columnIndex: number): Uint8Array; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | goToRow(position: number): boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | goTo(offset: number): boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | goToPreviousRow(): boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | goToNextRow(): boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | goToLastRow(): boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | goToFirstRow(): boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | isClosed: boolean; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | rowCount: number; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | columnCount: number; | 新增 |
| ohos.data.DataShareResultSet | DataShareResultSet | columnNames: Array\<string>; | 新增 |
| ohos.data.DataShareResultSet | DataType | TYPE_BLOB = 4 | 新增 |
| ohos.data.DataShareResultSet | DataType | TYPE_STRING = 3 | 新增 |
| ohos.data.DataShareResultSet | DataType | TYPE_DOUBLE = 2 | 新增 |
| ohos.data.DataShareResultSet | DataType | TYPE_LONG = 1 | 新增 |
| ohos.data.DataShareResultSet | DataType | TYPE_NULL = 0 | 新增 |
| ohos.data.distributedData | DeviceKVStore | off(event:'dataChange', listener?: Callback\<ChangeNotification>): void; | 新增 |
| ohos.data.distributedData | DeviceKVStore | on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void; | 新增 |
| ohos.data.distributedData | SingleKVStore | off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void; | 新增 |
| ohos.data.distributedData | SingleKVStore | on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void; | 新增 |
| ohos.data.distributedData | KVStore | off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void; | 新增 |
| ohos.data.distributedData | KVManagerConfig | context: Context; | 新增 |
| ohos.data.distributedDataObject | DistributedObject | revokeSave(callback: AsyncCallback\<RevokeSaveSuccessResponse>): void;<br>revokeSave(): Promise\<RevokeSaveSuccessResponse>; | 新增 |
| ohos.data.distributedDataObject | DistributedObject | save(deviceId: string, callback: AsyncCallback\<SaveSuccessResponse>): void;<br>save(deviceId: string): Promise\<SaveSuccessResponse>; | 新增 |
| ohos.data.distributedDataObject | RevokeSaveSuccessResponse | sessionId: string; | 新增 |
| ohos.data.distributedDataObject | SaveSuccessResponse | deviceId: string; | 新增 |
| ohos.data.distributedDataObject | SaveSuccessResponse | version: number; | 新增 |
| ohos.data.distributedDataObject | SaveSuccessResponse | sessionId: string; | 新增 |
| ohos.data.rdb | RdbStore | restore(srcName: string, callback: AsyncCallback\<void>): void;<br>restore(srcName: string): Promise\<void>; | 新增 |
| ohos.data.rdb | RdbStore | backup(destName: string, callback: AsyncCallback\<void>): void;<br>backup(destName: string): Promise\<void>; | 新增 |


