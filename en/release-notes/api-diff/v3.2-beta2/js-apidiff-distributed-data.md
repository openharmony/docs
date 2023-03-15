# JS API Changes of the Distributed Data Management Subsystem

The table below lists the APIs changes of the distributed data management subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.data.dataShare | DataShareHelper | notifyChange(uri: string, callback: AsyncCallback\<void>): void;<br>notifyChange(uri: string): Promise\<void>; | Added|
| ohos.data.dataShare | DataShareHelper | denormalizeUri(uri: string, callback: AsyncCallback\<string>): void;<br>denormalizeUri(uri: string): Promise\<string>; | Added|
| ohos.data.dataShare | DataShareHelper | normalizeUri(uri: string, callback: AsyncCallback\<string>): void;<br>normalizeUri(uri: string): Promise\<string>; | Added|
| ohos.data.dataShare | DataShareHelper | getFileTypes(uri: string,  mimeTypeFilter:string, callback: AsyncCallback\<Array\<string>>): void;<br>getFileTypes(uri: string,  mimeTypeFilter: string): Promise\<Array\<string>>; | Added|
| ohos.data.dataShare | DataShareHelper | getType(uri: string, callback: AsyncCallback\<string>): void;<br>getType(uri: string): Promise\<string>; | Added|
| ohos.data.dataShare | DataShareHelper | batchInsert(uri: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>batchInsert(uri: string, values: Array\<ValuesBucket>): Promise\<number>; | Added|
| ohos.data.dataShare | DataShareHelper | update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback\<number>): void;<br>update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise\<number>; | Added|
| ohos.data.dataShare | DataShareHelper | query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>, callback: AsyncCallback\<DataShareResultSet>): void;<br>query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>): Promise\<DataShareResultSet>; | Added|
| ohos.data.dataShare | DataShareHelper | delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;<br>delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>; | Added|
| ohos.data.dataShare | DataShareHelper | insert(uri: string, value: ValuesBucket, callback: AsyncCallback\<number>): void;<br>insert(uri: string, value: ValuesBucket): Promise\<number>; | Added|
| ohos.data.dataShare | DataShareHelper | off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void; | Added|
| ohos.data.dataShare | DataShareHelper | on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void; | Added|
| ohos.data.dataShare | DataShareHelper | openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void;<br>openFile(uri: string, mode: string): Promise\<number>; | Added|
| ohos.data.dataShare | dataShare | function createDataShareHelper(context: Context, uri: string, callback: AsyncCallback\<DataShareHelper>): void;<br>function createDataShareHelper(context: Context, uri: string): Promise\<DataShareHelper>; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | inKeys(keys: Array\<string>): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | prefixKey(prefix: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | notIn(field: string, value: Array\<ValueType>): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | in(field: string, value: Array\<ValueType>): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | indexedBy(field: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | groupBy(fields: Array\<string>): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | limit(total: number, offset: number): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | distinct(): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | orderByDesc(field: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | orderByAsc(field: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | lessThan(field: string, value: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | greaterThan(field: string, value: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | between(field: string, low: ValueType, high: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | glob(field: string, value: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | unlike(field: string, value: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | like(field: string, value: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | isNotNull(field: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | isNull(field: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | endsWith(field: string, value: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | beginsWith(field: string, value: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | contains(field: string, value: string): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | and(): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | or(): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | endWrap(): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | beginWrap(): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | notEqualTo(field: string, value: ValueType): DataSharePredicates; | Added|
| ohos.data.dataSharePredicates | DataSharePredicates | equalTo(field: string, value: ValueType): DataSharePredicates; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getDataType(columnIndex: number): DataType; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getColumnName(columnIndex: number): string; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getColumnIndex(columnName: string): number; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | close(): void; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getDouble(columnIndex: number): number; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getLong(columnIndex: number): number; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getString(columnIndex: number): string; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | getBlob(columnIndex: number): Uint8Array; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | goToRow(position: number): boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | goTo(offset: number): boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | goToPreviousRow(): boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | goToNextRow(): boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | goToLastRow(): boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | goToFirstRow(): boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | isClosed: boolean; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | rowCount: number; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | columnCount: number; | Added|
| ohos.data.DataShareResultSet | DataShareResultSet | columnNames: Array\<string>; | Added|
| ohos.data.DataShareResultSet | DataType | TYPE_BLOB = 4 | Added|
| ohos.data.DataShareResultSet | DataType | TYPE_STRING = 3 | Added|
| ohos.data.DataShareResultSet | DataType | TYPE_DOUBLE = 2 | Added|
| ohos.data.DataShareResultSet | DataType | TYPE_LONG = 1 | Added|
| ohos.data.DataShareResultSet | DataType | TYPE_NULL = 0 | Added|
| ohos.data.distributedData | DeviceKVStore | off(event:'dataChange', listener?: Callback\<ChangeNotification>): void; | Added|
| ohos.data.distributedData | DeviceKVStore | on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void; | Added|
| ohos.data.distributedData | SingleKVStore | off(event:'dataChange', listener?: Callback\<ChangeNotification>): void; | Added|
| ohos.data.distributedData | SingleKVStore | on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void; | Added|
| ohos.data.distributedData | KVStore | off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void; | Added|
| ohos.data.distributedData | KVManagerConfig | context: Context; | Added|
| ohos.data.distributedDataObject | DistributedObject | revokeSave(callback: AsyncCallback\<RevokeSaveSuccessResponse>): void;<br>revokeSave(): Promise\<RevokeSaveSuccessResponse>; | Added|
| ohos.data.distributedDataObject | DistributedObject | save(deviceId: string, callback: AsyncCallback\<SaveSuccessResponse>): void;<br>save(deviceId: string): Promise\<SaveSuccessResponse>; | Added|
| ohos.data.distributedDataObject | RevokeSaveSuccessResponse | sessionId: string; | Added|
| ohos.data.distributedDataObject | SaveSuccessResponse | deviceId: string; | Added|
| ohos.data.distributedDataObject | SaveSuccessResponse | version: number; | Added|
| ohos.data.distributedDataObject | SaveSuccessResponse | sessionId: string; | Added|
| ohos.data.rdb | RdbStore | restore(srcName:string, callback: AsyncCallback\<void>):void;<br>restore(srcName:string): Promise\<void>; | Added|
| ohos.data.rdb | RdbStore | backup(destName:string, callback: AsyncCallback\<void>):void;<br>backup(destName:string): Promise\<void>; | Added|
