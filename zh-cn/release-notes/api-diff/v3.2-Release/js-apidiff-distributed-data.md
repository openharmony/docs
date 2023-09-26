| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：KVStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, observer: Callback\<ChangeNotification>): void;|NA|@ohos.data.distributedData.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void;|@ohos.data.distributedData.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void;|@ohos.data.distributedData.d.ts|
| 新增 | NA   | 类名：DataObject; <br>方法or属性：setSessionId(sessionId: string, callback: AsyncCallback<void>): void; | @ohos.data.distributedDataObject.d.ts |
| 新增 | NA   | 类名：DataObject;<br/> 方法or属性：setSessionId(sessionId?: string): Promise<void>; | @ohos.data.distributedDataObject.d.ts |
|新增|NA|类名：DataObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：on(type: 'status',<br><br>           callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：off(type: 'status',<br><br>            callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：context?: ExtensionContext;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：onCreate?(want: Want, callback: AsyncCallback\<void>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback\<number>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket,<br>        callback: AsyncCallback\<number>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>,<br>        callback: AsyncCallback\<Object>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：batchInsert?(uri: string, valueBuckets: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：normalizeUri?(uri: string, callback: AsyncCallback\<string>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：DataShareExtensionAbility;<br>方法or属性：denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void;|@ohos.application.DataShareExtensionAbility.d.ts|
|新增|NA|类名：dataShare;<br>方法or属性：function createDataShareHelper(context: Context, uri: string, callback: AsyncCallback\<DataShareHelper>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：dataShare;<br>方法or属性：function createDataShareHelper(context: Context, uri: string): Promise\<DataShareHelper>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：insert(uri: string, value: ValuesBucket, callback: AsyncCallback\<number>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：insert(uri: string, value: ValuesBucket): Promise\<number>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>,<br>              callback: AsyncCallback\<DataShareResultSet>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：query(uri: string, predicates: dataSharePredicates.DataSharePredicates,<br>              columns: Array\<string>): Promise\<DataShareResultSet>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket,<br>               callback: AsyncCallback\<number>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise\<number>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：batchInsert(uri: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：batchInsert(uri: string, values: Array\<ValuesBucket>): Promise\<number>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：normalizeUri(uri: string, callback: AsyncCallback\<string>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：normalizeUri(uri: string): Promise\<string>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：denormalizeUri(uri: string, callback: AsyncCallback\<string>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：denormalizeUri(uri: string): Promise\<string>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：notifyChange(uri: string, callback: AsyncCallback\<void>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：notifyChange(uri: string): Promise\<void>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：equalTo(field: string, value: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：notEqualTo(field: string, value: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：beginWrap(): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：endWrap(): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：or(): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：and(): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：contains(field: string, value: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：beginsWith(field: string, value: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：endsWith(field: string, value: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：isNull(field: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：isNotNull(field: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：like(field: string, value: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：unlike(field: string, value: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：glob(field: string, value: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：between(field: string, low: ValueType, high: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：greaterThan(field: string, value: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：lessThan(field: string, value: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：orderByAsc(field: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：orderByDesc(field: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：distinct(): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：limit(total: number, offset: number): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：groupBy(fields: Array\<string>): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：indexedBy(field: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：notIn(field: string, value: Array\<ValueType>): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：prefixKey(prefix: string): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataSharePredicates;<br>方法or属性：inKeys(keys: Array\<string>): DataSharePredicates;|@ohos.data.dataSharePredicates.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：TYPE_NULL = 0|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：TYPE_LONG = 1|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：TYPE_DOUBLE = 2|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：TYPE_STRING = 3|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：TYPE_BLOB = 4|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：columnNames: Array\<string>;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：columnCount: number;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：rowCount: number;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：isClosed: boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：goToFirstRow(): boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：goToLastRow(): boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：goToNextRow(): boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：goToPreviousRow(): boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：goTo(offset: number): boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：goToRow(position: number): boolean;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getBlob(columnIndex: number): Uint8Array;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getString(columnIndex: number): string;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getLong(columnIndex: number): number;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getDouble(columnIndex: number): number;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：close(): void;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getColumnIndex(columnName: string): number;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getColumnName(columnIndex: number): string;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：DataShareResultSet;<br>方法or属性：getDataType(columnIndex: number): DataType;|@ohos.data.DataShareResultSet.d.ts|
|新增|NA|类名：KVStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void;|@ohos.data.distributedData.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void;|@ohos.data.distributedData.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void;|@ohos.data.distributedData.d.ts|
|新增|NA|类名：distributedDataObject;<br>方法or属性：function create(context: Context, source: object): DataObject;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：SaveSuccessResponse;<br>方法or属性：sessionId: string;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：RevokeSaveSuccessResponse;<br>方法or属性：sessionId: string;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：SaveSuccessResponse;<br>方法or属性：version: number;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：SaveSuccessResponse;<br>方法or属性：deviceId: string;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：setSessionId(callback: AsyncCallback\<void>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：save(deviceId: string, callback: AsyncCallback\<SaveSuccessResponse>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：save(deviceId: string): Promise\<SaveSuccessResponse>;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：revokeSave(callback: AsyncCallback\<RevokeSaveSuccessResponse>): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：revokeSave(): Promise\<RevokeSaveSuccessResponse>;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：distributedKVStore;<br>方法or属性：function createKVManager(config: KVManagerConfig): KVManager;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManagerConfig;<br>方法or属性：bundleName: string;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManagerConfig;<br>方法or属性：context: Context;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Constants;<br>方法or属性：readonly MAX_KEY_LENGTH: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Constants;<br>方法or属性：readonly MAX_VALUE_LENGTH: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Constants;<br>方法or属性：readonly MAX_KEY_LENGTH_DEVICE: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Constants;<br>方法or属性：readonly MAX_STORE_ID_LENGTH: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Constants;<br>方法or属性：readonly MAX_QUERY_LENGTH: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Constants;<br>方法or属性：readonly MAX_BATCH_SIZE: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ValueType;<br>方法or属性：STRING|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ValueType;<br>方法or属性：INTEGER|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ValueType;<br>方法or属性：FLOAT|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ValueType;<br>方法or属性：BYTE_ARRAY|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ValueType;<br>方法or属性：BOOLEAN|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ValueType;<br>方法or属性：DOUBLE|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Value;<br>方法or属性：type: ValueType;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Value;<br>方法or属性：value: Uint8Array \| string \| number \| boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Entry;<br>方法or属性：key: string;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Entry;<br>方法or属性：value: Value;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ChangeNotification;<br>方法or属性：insertEntries: Entry[];|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ChangeNotification;<br>方法or属性：updateEntries: Entry[];|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ChangeNotification;<br>方法or属性：deleteEntries: Entry[];|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：ChangeNotification;<br>方法or属性：deviceId: string;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：PULL_ONLY|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：PUSH_ONLY|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：PUSH_PULL|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_LOCAL|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_ALL|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreType;<br>方法or属性：DEVICE_COLLABORATION|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreType;<br>方法or属性：SINGLE_VERSION|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S1|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S2|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S3|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S4|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：createIfMissing?: boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：encrypt?: boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：backup?: boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：autoSync?: boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：kvStoreType?: KVStoreType;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：securityLevel: SecurityLevel;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Options;<br>方法or属性：schema?: Schema;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Schema;<br>方法or属性：constructor()|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：constructor()|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Schema;<br>方法or属性：root: FieldNode;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Schema;<br>方法or属性：indexes: Array\<string>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Schema;<br>方法or属性：mode: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Schema;<br>方法or属性：skip: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：FieldNode;<br>方法or属性：constructor(name: string)|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：FieldNode;<br>方法or属性：appendChild(child: FieldNode): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：FieldNode;<br>方法or属性：default: string;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：FieldNode;<br>方法or属性：nullable: boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：FieldNode;<br>方法or属性：type: number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：getCount(): number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：getPosition(): number;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：moveToFirst(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：moveToLast(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：moveToNext(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：moveToPrevious(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：move(offset: number): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：moveToPosition(position: number): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：isFirst(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：isLast(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：isBeforeFirst(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：isAfterLast(): boolean;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVStoreResultSet;<br>方法or属性：getEntry(): Entry;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：reset(): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：equalTo(field: string, value: number \| string \| boolean): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：notEqualTo(field: string, value: number \| string \| boolean): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：greaterThan(field: string, value: number \| string \| boolean): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：lessThan(field: string, value: number \| string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：greaterThanOrEqualTo(field: string, value: number \| string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：lessThanOrEqualTo(field: string, value: number \| string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：isNull(field: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：inNumber(field: string, valueList: number[]): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：inString(field: string, valueList: string[]): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：notInNumber(field: string, valueList: number[]): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：notInString(field: string, valueList: string[]): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：like(field: string, value: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：unlike(field: string, value: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：and(): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：or(): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：orderByAsc(field: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：orderByDesc(field: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：limit(total: number, offset: number): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：isNotNull(field: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：beginGroup(): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：endGroup(): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：prefixKey(prefix: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：setSuggestIndex(index: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：deviceId(deviceId: string): Query;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：Query;<br>方法or属性：getSqlLike(): string;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：putBatch(entries: Entry[], callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：putBatch(entries: Entry[]): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：putBatch(value: Array\<ValuesBucket>, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：putBatch(value: Array\<ValuesBucket>): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：delete(key: string): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void>);|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：delete(predicates: dataSharePredicates.DataSharePredicates): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：deleteBatch(keys: string[], callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：deleteBatch(keys: string[]): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：removeDeviceData(deviceId: string): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：get(key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：get(key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：get(key: string): Promise\<boolean \| string \| number \| Uint8Array>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：get(key: string): Promise\<boolean \| string \| number \| Uint8Array>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getEntries(keyPrefix: string): Promise\<Entry[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(keyPrefix: string): Promise\<Entry[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getEntries(query: Query): Promise\<Entry[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(query: Query): Promise\<Entry[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：closeResultSet(resultSet: KVStoreResultSet, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：closeResultSet(resultSet: KVStoreResultSet): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSize(query: Query, callback: AsyncCallback\<number>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSize(query: Query, callback: AsyncCallback\<number>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getResultSize(query: Query): Promise\<number>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSize(query: Query): Promise\<number>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：backup(file: string, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：backup(file: string): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：restore(file: string, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：restore(file: string): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：deleteBackup(files: Array\<string>, callback: AsyncCallback\<Array\<[string, number]>>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：deleteBackup(files: Array\<string>): Promise\<Array\<[string, number]>>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：startTransaction(callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：startTransaction(): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：commit(callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：commit(): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：rollback(callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：rollback(): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：enableSync(enabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：enableSync(enabled: boolean): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：setSyncParam(defaultAllowedDelayMs: number): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：sync(deviceIds: string[], query: Query, mode: SyncMode, delayMs?: number): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getSecurityLevel(callback: AsyncCallback\<SecurityLevel>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：SingleKVStore;<br>方法or属性：getSecurityLevel(): Promise\<SecurityLevel>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：get(deviceId: string, key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：get(deviceId: string, key: string): Promise\<boolean \| string \| number \| Uint8Array>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, keyPrefix: string): Promise\<Entry[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, query: Query, callback: AsyncCallback\<Entry[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, query: Query): Promise\<Entry[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSize(deviceId: string, query: Query, callback: AsyncCallback\<number>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：DeviceKVStore;<br>方法or属性：getResultSize(deviceId: string, query: Query): Promise\<number>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：getKVStore\<T>(storeId: string, options: Options, callback: AsyncCallback\<T>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：getKVStore\<T>(storeId: string, options: Options): Promise\<T>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：closeKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：closeKVStore(appId: string, storeId: string): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：deleteKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：deleteKVStore(appId: string, storeId: string): Promise\<void>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：getAllKVStoreId(appId: string, callback: AsyncCallback\<string[]>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：getAllKVStoreId(appId: string): Promise\<string[]>;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：on(event: 'distributedDataServiceDie', deathCallback: Callback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：KVManager;<br>方法or属性：off(event: 'distributedDataServiceDie', deathCallback?: Callback\<void>): void;|@ohos.data.distributedKVStore.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferences(context: Context, name: string, callback: AsyncCallback\<Preferences>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferences(context: Context, name: string): Promise\<Preferences>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, name: string, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, name: string): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, name: string): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：type ValueType = number \| string \| boolean \| Array\<number> \| Array\<string> \| Array\<boolean>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：get(key: string, defValue: ValueType): Promise\<ValueType>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：getAll(callback: AsyncCallback\<Object>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：getAll(): Promise\<Object>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：has(key: string, callback: AsyncCallback\<boolean>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：has(key: string): Promise\<boolean>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：put(key: string, value: ValueType): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：delete(key: string): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：clear(): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：flush(): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：on(type: 'change', callback: Callback\<{ key: string }>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: Callback\<{ key: string }>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：rdb;<br>方法or属性：export type ResultSet = _ResultSet;|@ohos.data.rdb.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;|@ohos.data.rdb.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;|@ohos.data.rdb.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：type ValueType = number \| string \| boolean \| Uint8Array;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：type ValuesBucket = { [key:string]: ValueType \| Uint8Array \| null;}|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：StoreConfig;<br>方法or属性：name: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：StoreConfig;<br>方法or属性：securityLevel: SecurityLevel;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：StoreConfig;<br>方法or属性：encrypt ?: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S1 = 1|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S2 = 2|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S3 = 3|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SecurityLevel;<br>方法or属性：S4 = 4|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：SYNC_MODE_PUSH = 0|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：SYNC_MODE_PULL = 1|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns ?: Array\<string>): Promise\<ResultSet>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns ?: Array\<string>): Promise\<ResultSet>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs ?: Array\<ValueType>): Promise\<ResultSet>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs ?: Array\<ValueType>): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：beginTransaction(): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：commit(): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：rollBack(): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：backup(destName: string, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：backup(destName: string): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：restore(srcName: string, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：restore(srcName: string): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[ string, number ]>>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[ string, number ]>>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：off(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：constructor(name: string)|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：inDevices(devices: Array\<string>): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：inAllDevices(): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：equalTo(field: string, value: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：notEqualTo(field: string, value: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：beginWrap(): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：endWrap(): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：or(): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：and(): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：contains(field: string, value: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：beginsWith(field: string, value: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：endsWith(field: string, value: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：isNull(field: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：like(field: string, value: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：glob(field: string, value: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：between(field: string, low: ValueType, high: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：greaterThan(field: string, value: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：lessThan(field: string, value: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：orderByAsc(field: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：orderByDesc(field: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：distinct(): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：limitAs(value: number): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：offsetAs(rowOffset: number): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：groupBy(fields: Array\<string>): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：indexedBy(field: string): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbPredicates;<br>方法or属性：notIn(field: string, value: Array\<ValueType>): RdbPredicates;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：columnNames: Array\<string>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：columnCount: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：rowCount: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：rowIndex: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：isAtFirstRow: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：isAtLastRow: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：isEnded: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：isStarted: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：isClosed: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getColumnIndex(columnName: string): number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getColumnName(columnIndex: number): string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：goTo(offset: number): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：goToRow(position: number): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：goToFirstRow(): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：goToLastRow(): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：goToNextRow(): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：goToPreviousRow(): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getBlob(columnIndex: number): Uint8Array;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getString(columnIndex: number): string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getLong(columnIndex: number): number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getDouble(columnIndex: number): number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：isColumnNull(columnIndex: number): boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：close(): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type ValueType = number \| string \| boolean;|@ohos.data.ValuesBucket.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type ValuesBucket = {<br><br>    [key: string]: ValueType \| Uint8Array \| null;<br><br>}|@ohos.data.ValuesBucket.d.ts|
|废弃版本有变化|类名：distributedData;<br>方法or属性：declare distributedData<br>旧版本信息：|类名：distributedData;<br>方法or属性：declare distributedData<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：distributedData;<br>方法or属性：function createKVManager(config: KVManagerConfig, callback: AsyncCallback\<KVManager>): void;<br>旧版本信息：|类名：distributedData;<br>方法or属性：function createKVManager(config: KVManagerConfig, callback: AsyncCallback\<KVManager>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore#createKVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：distributedData;<br>方法or属性：function createKVManager(config: KVManagerConfig): Promise\<KVManager>;<br>旧版本信息：|类名：distributedData;<br>方法or属性：function createKVManager(config: KVManagerConfig): Promise\<KVManager>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore#createKVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManagerConfig;<br>方法or属性：interface KVManagerConfig<br>旧版本信息：|类名：KVManagerConfig;<br>方法or属性：interface KVManagerConfig<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManagerConfig|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManagerConfig;<br>方法or属性：userInfo: UserInfo;<br>旧版本信息：|类名：KVManagerConfig;<br>方法or属性：userInfo: UserInfo;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManagerConfig|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManagerConfig;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：KVManagerConfig;<br>方法or属性：bundleName: string;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManagerConfig#bundleName|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：UserInfo;<br>方法or属性：interface UserInfo<br>旧版本信息：|类名：UserInfo;<br>方法or属性：interface UserInfo<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：UserInfo;<br>方法or属性：userId?: string;<br>旧版本信息：|类名：UserInfo;<br>方法or属性：userId?: string;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：UserInfo;<br>方法or属性：userType?: UserType;<br>旧版本信息：|类名：UserInfo;<br>方法or属性：userType?: UserType;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：UserType;<br>方法or属性：enum UserType<br>旧版本信息：|类名：UserType;<br>方法or属性：enum UserType<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：UserType;<br>方法or属性：SAME_USER_ID = 0<br>旧版本信息：|类名：UserType;<br>方法or属性：SAME_USER_ID = 0<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Constants;<br>方法or属性：Constants<br>旧版本信息：|类名：Constants;<br>方法or属性：Constants<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Constants|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：enum ValueType<br>旧版本信息：|类名：ValueType;<br>方法or属性：enum ValueType<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：STRING = 0<br>旧版本信息：|类名：ValueType;<br>方法or属性：STRING = 0<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType#STRING|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：INTEGER = 1<br>旧版本信息：|类名：ValueType;<br>方法or属性：INTEGER = 1<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType#INTEGER|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：FLOAT = 2<br>旧版本信息：|类名：ValueType;<br>方法or属性：FLOAT = 2<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType#FLOAT|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：BYTE_ARRAY = 3<br>旧版本信息：|类名：ValueType;<br>方法or属性：BYTE_ARRAY = 3<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType#BYTE_ARRAY|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：BOOLEAN = 4<br>旧版本信息：|类名：ValueType;<br>方法or属性：BOOLEAN = 4<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType#BOOLEAN|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ValueType;<br>方法or属性：DOUBLE = 5<br>旧版本信息：|类名：ValueType;<br>方法or属性：DOUBLE = 5<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ValueType#DOUBLE|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Value;<br>方法or属性：interface Value<br>旧版本信息：|类名：Value;<br>方法or属性：interface Value<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Value|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Value;<br>方法or属性：type: ValueType;<br>旧版本信息：|类名：Value;<br>方法or属性：type: ValueType;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Value#type|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Value;<br>方法or属性：value: Uint8Array \| string \| number \| boolean;<br>旧版本信息：|类名：Value;<br>方法or属性：value: Uint8Array \| string \| number \| boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Value#value|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Entry;<br>方法or属性：interface Entry<br>旧版本信息：|类名：Entry;<br>方法or属性：interface Entry<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Entry|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Entry;<br>方法or属性：key: string;<br>旧版本信息：|类名：Entry;<br>方法or属性：key: string;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Entry#key|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Entry;<br>方法or属性：value: Value;<br>旧版本信息：|类名：Entry;<br>方法or属性：value: Value;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Entry#value|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ChangeNotification;<br>方法or属性：interface ChangeNotification<br>旧版本信息：|类名：ChangeNotification;<br>方法or属性：interface ChangeNotification<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ChangeNotification|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ChangeNotification;<br>方法or属性：insertEntries: Entry[];<br>旧版本信息：|类名：ChangeNotification;<br>方法or属性：insertEntries: Entry[];<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ChangeNotification#insertEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ChangeNotification;<br>方法or属性：updateEntries: Entry[];<br>旧版本信息：|类名：ChangeNotification;<br>方法or属性：updateEntries: Entry[];<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ChangeNotification#updateEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ChangeNotification;<br>方法or属性：deleteEntries: Entry[];<br>旧版本信息：|类名：ChangeNotification;<br>方法or属性：deleteEntries: Entry[];<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ChangeNotification#deleteEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：ChangeNotification;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ChangeNotification;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.ChangeNotification#deviceId|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：enum SyncMode<br>旧版本信息：|类名：SyncMode;<br>方法or属性：enum SyncMode<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SyncMode|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：PULL_ONLY = 0<br>旧版本信息：|类名：SyncMode;<br>方法or属性：PULL_ONLY = 0<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SyncMode#PULL_ONLY|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：PUSH_ONLY = 1<br>旧版本信息：|类名：SyncMode;<br>方法or属性：PUSH_ONLY = 1<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SyncMode#PUSH_ONLY|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：PUSH_PULL = 2<br>旧版本信息：|类名：SyncMode;<br>方法or属性：PUSH_PULL = 2<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SyncMode#PUSH_PULL|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SubscribeType;<br>方法or属性：enum SubscribeType<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：enum SubscribeType<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SubscribeType|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_LOCAL = 0<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_LOCAL = 0<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SubscribeType#SUBSCRIBE_TYPE_LOCAL|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 1<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 1<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SubscribeType#SUBSCRIBE_TYPE_REMOTE|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_ALL = 2<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_ALL = 2<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SubscribeType#SUBSCRIBE_TYPE_ALL|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStoreType;<br>方法or属性：enum KVStoreType<br>旧版本信息：|类名：KVStoreType;<br>方法or属性：enum KVStoreType<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreType|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStoreType;<br>方法or属性：DEVICE_COLLABORATION = 0<br>旧版本信息：|类名：KVStoreType;<br>方法or属性：DEVICE_COLLABORATION = 0<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreType#DEVICE_COLLABORATION|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStoreType;<br>方法or属性：SINGLE_VERSION = 1<br>旧版本信息：|类名：KVStoreType;<br>方法or属性：SINGLE_VERSION = 1<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreType#SINGLE_VERSION|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStoreType;<br>方法or属性：MULTI_VERSION = 2<br>旧版本信息：|类名：KVStoreType;<br>方法or属性：MULTI_VERSION = 2<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreType|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：enum SecurityLevel<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：enum SecurityLevel<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：NO_LEVEL = 0<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：NO_LEVEL = 0<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：S0 = 1<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S0 = 1<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：S1 = 2<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S1 = 2<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel#S1|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：S2 = 3<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S2 = 3<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel#S2|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：S3 = 5<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S3 = 5<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel#S3|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SecurityLevel;<br>方法or属性：S4 = 6<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S4 = 6<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SecurityLevel#S4|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：interface Options<br>旧版本信息：|类名：Options;<br>方法or属性：interface Options<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：createIfMissing?: boolean;<br>旧版本信息：|类名：Options;<br>方法or属性：createIfMissing?: boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#createIfMissing|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：encrypt?: boolean;<br>旧版本信息：|类名：Options;<br>方法or属性：encrypt?: boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#encrypt|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：backup?: boolean;<br>旧版本信息：|类名：Options;<br>方法or属性：backup?: boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#backup|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：autoSync?: boolean;<br>旧版本信息：|类名：Options;<br>方法or属性：autoSync?: boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#autoSync|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：kvStoreType?: KVStoreType;<br>旧版本信息：|类名：Options;<br>方法or属性：kvStoreType?: KVStoreType;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#kvStoreType|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：securityLevel?: SecurityLevel;<br>旧版本信息：|类名：Options;<br>方法or属性：securityLevel?: SecurityLevel;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#securityLevel|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Options;<br>方法or属性：schema?: Schema;<br>旧版本信息：|类名：Options;<br>方法or属性：schema?: Schema;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Options#schema|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Schema;<br>方法or属性：class Schema<br>旧版本信息：|类名：Schema;<br>方法or属性：class Schema<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Schema|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Schema;<br>方法or属性：constructor()<br>旧版本信息：|类名：Schema;<br>方法or属性：constructor()<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Schema#constructor|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：constructor()<br>旧版本信息：|类名：Query;<br>方法or属性：constructor()<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#constructor|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Schema;<br>方法or属性：root: FieldNode;<br>旧版本信息：|类名：Schema;<br>方法or属性：root: FieldNode;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Schema#root|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Schema;<br>方法or属性：indexes: Array\<string>;<br>旧版本信息：|类名：Schema;<br>方法or属性：indexes: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Schema#indexes|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Schema;<br>方法or属性：mode: number;<br>旧版本信息：|类名：Schema;<br>方法or属性：mode: number;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Schema#mode|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Schema;<br>方法or属性：skip: number;<br>旧版本信息：|类名：Schema;<br>方法or属性：skip: number;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Schema#skip|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：FieldNode;<br>方法or属性：class FieldNode<br>旧版本信息：|类名：FieldNode;<br>方法or属性：class FieldNode<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.FieldNode|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：FieldNode;<br>方法or属性：constructor(name: string)<br>旧版本信息：|类名：FieldNode;<br>方法or属性：constructor(name: string)<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.FieldNode#constructor|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：FieldNode;<br>方法or属性：appendChild(child: FieldNode): boolean;<br>旧版本信息：|类名：FieldNode;<br>方法or属性：appendChild(child: FieldNode): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.FieldNode#appendChild|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：FieldNode;<br>方法or属性：default: string;<br>旧版本信息：|类名：FieldNode;<br>方法or属性：default: string;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.FieldNode#default|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：FieldNode;<br>方法or属性：nullable: boolean;<br>旧版本信息：|类名：FieldNode;<br>方法or属性：nullable: boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.FieldNode#nullable|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：FieldNode;<br>方法or属性：type: number;<br>旧版本信息：|类名：FieldNode;<br>方法or属性：type: number;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.FieldNode#type|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：interface KvStoreResultSet<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：interface KvStoreResultSet<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：getCount(): number;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：getCount(): number;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#getCount|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：getPosition(): number;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：getPosition(): number;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#getPosition|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：moveToFirst(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：moveToFirst(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#moveToFirst|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：moveToLast(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：moveToLast(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#moveToLast|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：moveToNext(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：moveToNext(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#moveToNext|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：moveToPrevious(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：moveToPrevious(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#moveToPrevious|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：move(offset: number): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：move(offset: number): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#move|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：moveToPosition(position: number): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：moveToPosition(position: number): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#moveToPosition|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：isFirst(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：isFirst(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#isFirst|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：isLast(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：isLast(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#isLast|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：isBeforeFirst(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：isBeforeFirst(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#isBeforeFirst|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：isAfterLast(): boolean;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：isAfterLast(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#isAfterLast|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KvStoreResultSet;<br>方法or属性：getEntry(): Entry;<br>旧版本信息：|类名：KvStoreResultSet;<br>方法or属性：getEntry(): Entry;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVStoreResultSet#getEntry|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：class Query<br>旧版本信息：|类名：Query;<br>方法or属性：class Query<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：reset(): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：reset(): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#reset|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：equalTo(field: string, value: number \| string \| boolean): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：equalTo(field: string, value: number \| string \| boolean): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#equalTo|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：notEqualTo(field: string, value: number \| string \| boolean): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：notEqualTo(field: string, value: number \| string \| boolean): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#notEqualTo|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：greaterThan(field: string, value: number \| string \| boolean): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：greaterThan(field: string, value: number \| string \| boolean): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#greaterThan|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：lessThan(field: string, value: number \| string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：lessThan(field: string, value: number \| string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#lessThan|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：greaterThanOrEqualTo(field: string, value: number \| string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：greaterThanOrEqualTo(field: string, value: number \| string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#greaterThanOrEqualTo|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：lessThanOrEqualTo(field: string, value: number \| string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：lessThanOrEqualTo(field: string, value: number \| string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#lessThanOrEqualTo|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：isNull(field: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：isNull(field: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#isNull|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：inNumber(field: string, valueList: number[]): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：inNumber(field: string, valueList: number[]): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#inNumber|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：inString(field: string, valueList: string[]): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：inString(field: string, valueList: string[]): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#inString|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：notInNumber(field: string, valueList: number[]): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：notInNumber(field: string, valueList: number[]): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#notInNumber|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：notInString(field: string, valueList: string[]): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：notInString(field: string, valueList: string[]): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#notInString|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：like(field: string, value: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：like(field: string, value: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#like|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：unlike(field: string, value: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：unlike(field: string, value: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#unlike|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：and(): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：and(): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#and|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：or(): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：or(): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#or|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：orderByAsc(field: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：orderByAsc(field: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#orderByAsc|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：orderByDesc(field: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：orderByDesc(field: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#orderByDesc|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：limit(total: number, offset: number): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：limit(total: number, offset: number): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#limit|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：isNotNull(field: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：isNotNull(field: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#isNotNull|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：beginGroup(): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：beginGroup(): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#beginGroup|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：endGroup(): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：endGroup(): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#endGroup|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：prefixKey(prefix: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：prefixKey(prefix: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#prefixKey|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：setSuggestIndex(index: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：setSuggestIndex(index: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#setSuggestIndex|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：deviceId(deviceId: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：deviceId(deviceId: string): Query;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#deviceId|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：Query;<br>方法or属性：getSqlLike(): string;<br>旧版本信息：|类名：Query;<br>方法or属性：getSqlLike(): string;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.Query#getSqlLike|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：interface KVStore<br>旧版本信息：|类名：KVStore;<br>方法or属性：interface KVStore<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#put|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#delete|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：delete(key: string): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：delete(key: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#on|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#on|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#on|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#off|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#off|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#off|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#off|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：putBatch(entries: Entry[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：putBatch(entries: Entry[], callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#putBatch|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：putBatch(entries: Entry[]): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：putBatch(entries: Entry[]): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：deleteBatch(keys: string[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：deleteBatch(keys: string[], callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#deleteBatch|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：deleteBatch(keys: string[]): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：deleteBatch(keys: string[]): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：startTransaction(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：startTransaction(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#startTransaction|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：startTransaction(): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：startTransaction(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：commit(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：commit(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#commit|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：commit(): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：commit(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：rollback(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：rollback(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#rollback|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：rollback(): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：rollback(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：enableSync(enabled: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：enableSync(enabled: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#enableSync|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：enableSync(enabled: boolean): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：enableSync(enabled: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVStore;<br>方法or属性：setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#setSyncRange|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVStore;<br>方法or属性：setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise\<void>;<br>旧版本信息：|类名：KVStore;<br>方法or属性：setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：interface SingleKVStore<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：interface SingleKVStore<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：get(key: string, callback: AsyncCallback\<Uint8Array \| string \| boolean \| number>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：get(key: string, callback: AsyncCallback\<Uint8Array \| string \| boolean \| number>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#get|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：get(key: string): Promise\<Uint8Array \| string \| boolean \| number>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：get(key: string): Promise\<Uint8Array \| string \| boolean \| number>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#getEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getEntries(keyPrefix: string): Promise\<Entry[]>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getEntries(keyPrefix: string): Promise\<Entry[]>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#getEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getEntries(query: Query): Promise\<Entry[]>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getEntries(query: Query): Promise\<Entry[]>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getEntries(query: Query): Promise\<Entry[]>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getEntries(query: Query): Promise\<Entry[]>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#getResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KvStoreResultSet>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KvStoreResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#getResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KvStoreResultSet>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KvStoreResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KvStoreResultSet>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KvStoreResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#closeResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#closeResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet): Promise\<void>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet): Promise\<void>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：closeResultSet(resultSet: KvStoreResultSet): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getResultSize(query: Query, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getResultSize(query: Query, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#getResultSize|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSize(query: Query, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSize(query: Query, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getResultSize|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getResultSize(query: Query): Promise\<number>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getResultSize(query: Query): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSize(query: Query): Promise\<number>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSize(query: Query): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#removeDeviceData|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#removeDeviceData|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：removeDeviceData(deviceId: string): Promise\<void>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：removeDeviceData(deviceId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：removeDeviceData(deviceId: string): Promise\<void>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：removeDeviceData(deviceId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#sync|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#sync|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#setSyncParam|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：setSyncParam(defaultAllowedDelayMs: number): Promise\<void>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：setSyncParam(defaultAllowedDelayMs: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getSecurityLevel(callback: AsyncCallback\<SecurityLevel>): void;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getSecurityLevel(callback: AsyncCallback\<SecurityLevel>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore#getSecurityLevel|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：SingleKVStore;<br>方法or属性：getSecurityLevel(): Promise\<SecurityLevel>;<br>旧版本信息：|类名：SingleKVStore;<br>方法or属性：getSecurityLevel(): Promise\<SecurityLevel>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.SingleKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：interface DeviceKVStore<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：interface DeviceKVStore<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：get(deviceId: string, key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：get(deviceId: string, key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#get|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：get(deviceId: string, key: string): Promise\<boolean \| string \| number \| Uint8Array>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：get(deviceId: string, key: string): Promise\<boolean \| string \| number \| Uint8Array>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, keyPrefix: string): Promise\<Entry[]>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, keyPrefix: string): Promise\<Entry[]>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, query: Query, callback: AsyncCallback\<Entry[]>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, query: Query, callback: AsyncCallback\<Entry[]>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getEntries|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, query: Query): Promise\<Entry[]>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getEntries(deviceId: string, query: Query): Promise\<Entry[]>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string): Promise\<KvStoreResultSet>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string): Promise\<KvStoreResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getResultSet|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query): Promise\<KvStoreResultSet>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query): Promise\<KvStoreResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSize(deviceId: string, query: Query, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSize(deviceId: string, query: Query, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore#getResultSize|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：DeviceKVStore;<br>方法or属性：getResultSize(deviceId: string, query: Query): Promise\<number>;<br>旧版本信息：|类名：DeviceKVStore;<br>方法or属性：getResultSize(deviceId: string, query: Query): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.DeviceKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：interface KVManager<br>旧版本信息：|类名：KVManager;<br>方法or属性：interface KVManager<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：getKVStore\<T extends KVStore>(storeId: string, options: Options): Promise\<T>;<br>旧版本信息：|类名：KVManager;<br>方法or属性：getKVStore\<T extends KVStore>(storeId: string, options: Options): Promise\<T>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager#getKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：getKVStore\<T extends KVStore>(storeId: string, options: Options, callback: AsyncCallback\<T>): void;<br>旧版本信息：|类名：KVManager;<br>方法or属性：getKVStore\<T extends KVStore>(storeId: string, options: Options, callback: AsyncCallback\<T>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：closeKVStore(appId: string, storeId: string, kvStore: KVStore, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVManager;<br>方法or属性：closeKVStore(appId: string, storeId: string, kvStore: KVStore, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager#closeKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：closeKVStore(appId: string, storeId: string, kvStore: KVStore): Promise\<void>;<br>旧版本信息：|类名：KVManager;<br>方法or属性：closeKVStore(appId: string, storeId: string, kvStore: KVStore): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：deleteKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：KVManager;<br>方法or属性：deleteKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager#deleteKVStore|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：deleteKVStore(appId: string, storeId: string): Promise\<void>;<br>旧版本信息：|类名：KVManager;<br>方法or属性：deleteKVStore(appId: string, storeId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：getAllKVStoreId(appId: string, callback: AsyncCallback\<string[]>): void;<br>旧版本信息：|类名：KVManager;<br>方法or属性：getAllKVStoreId(appId: string, callback: AsyncCallback\<string[]>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager#getAllKVStoreId|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：getAllKVStoreId(appId: string): Promise\<string[]>;<br>旧版本信息：|类名：KVManager;<br>方法or属性：getAllKVStoreId(appId: string): Promise\<string[]>;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：on(event: 'distributedDataServiceDie', deathCallback: Callback\<void>): void;<br>旧版本信息：|类名：KVManager;<br>方法or属性：on(event: 'distributedDataServiceDie', deathCallback: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager#on|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：KVManager;<br>方法or属性：off(event: 'distributedDataServiceDie', deathCallback?: Callback\<void>): void;<br>旧版本信息：|类名：KVManager;<br>方法or属性：off(event: 'distributedDataServiceDie', deathCallback?: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.distributedKVStore.KVManager#off|@ohos.data.distributedData.d.ts|
|废弃版本有变化|类名：distributedDataObject;<br>方法or属性：function createDistributedObject(source: object): DistributedObject;<br>旧版本信息：|类名：distributedDataObject;<br>方法or属性：function createDistributedObject(source: object): DistributedObject;<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.create|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：DistributedObject;<br>方法or属性：interface DistributedObject<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：interface DistributedObject<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.DataObject|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：DistributedObject;<br>方法or属性：setSessionId(sessionId?: string): boolean;<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：setSessionId(sessionId?: string): boolean;<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.DataObject.setSessionId|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：DistributedObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.DataObject.on|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：DistributedObject;<br>方法or属性：on(type: 'status',<br><br>           callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void;<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：on(type: 'status',<br><br>           callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void;<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.DataObject.on|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：DistributedObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.DataObject.off|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：DistributedObject;<br>方法or属性：off(type: 'status',<br><br>            callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void;<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：off(type: 'status',<br><br>            callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void;<br>新版本信息：9<br>代替接口： ohos.distributedDataObject.DataObject.off|@ohos.data.distributedDataObject.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：declare rdb<br>旧版本信息：|类名：rdb;<br>方法or属性：declare rdb<br>新版本信息：9<br>代替接口： ohos.data.relationalStore|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback\<RdbStore>): void;<br>旧版本信息：|类名：rdb;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback\<RdbStore>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.getRdbStore|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, version: number): Promise\<RdbStore>;<br>旧版本信息：|类名：rdb;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, version: number): Promise\<RdbStore>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.getRdbStore|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：rdb;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.deleteRdbStore|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;<br>旧版本信息：|类名：rdb;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.deleteRdbStore|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：type ValueType = number \| string \| boolean;<br>旧版本信息：|类名：rdb;<br>方法or属性：type ValueType = number \| string \| boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ValueType|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：rdb;<br>方法or属性：type ValuesBucket = { [key:string]: ValueType \| Uint8Array \| null;<br>}<br>旧版本信息：|类名：rdb;<br>方法or属性：type ValuesBucket = { [key:string]: ValueType \| Uint8Array \| null;<br>}<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ValuesBucket|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：enum SyncMode<br>旧版本信息：|类名：SyncMode;<br>方法or属性：enum SyncMode<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.SyncMode|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：SYNC_MODE_PUSH = 0<br>旧版本信息：|类名：SyncMode;<br>方法or属性：SYNC_MODE_PUSH = 0<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.SyncMode.SYNC_MODE_PUSH|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：SyncMode;<br>方法or属性：SYNC_MODE_PULL = 1<br>旧版本信息：|类名：SyncMode;<br>方法or属性：SYNC_MODE_PULL = 1<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.SyncMode.SYNC_MODE_PULL|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：SubscribeType;<br>方法or属性：enum SubscribeType<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：enum SubscribeType<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.SubscribeType|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：interface RdbStore<br>旧版本信息：|类名：RdbStore;<br>方法or属性：interface RdbStore<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.insert|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.insert|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.update|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.update|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.delete|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.delete|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.query|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns ?: Array\<string>): Promise\<ResultSet>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns ?: Array\<string>): Promise\<ResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.query|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.querySql|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs ?: Array\<ValueType>): Promise\<ResultSet>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs ?: Array\<ValueType>): Promise\<ResultSet>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.querySql|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.executeSql|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs ?: Array\<ValueType>): Promise\<void>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs ?: Array\<ValueType>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.executeSql|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：beginTransaction(): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：beginTransaction(): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.beginTransaction|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：commit(): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：commit(): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.commit|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：rollBack(): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：rollBack(): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.rollBack|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.setDistributedTables|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.setDistributedTables|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.obtainDistributedTableName|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.obtainDistributedTableName|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[ string, number ]>>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[ string, number ]>>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.sync|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[ string, number ]>>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[ string, number ]>>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.sync|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.on|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbStore;<br>方法or属性：off(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：off(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbStore.off|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：StoreConfig;<br>方法or属性：interface StoreConfig<br>旧版本信息：|类名：StoreConfig;<br>方法or属性：interface StoreConfig<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.StoreConfig|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：StoreConfig;<br>方法or属性：name: string;<br>旧版本信息：|类名：StoreConfig;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.StoreConfig|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：class RdbPredicates<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：class RdbPredicates<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：constructor(name: string)<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：constructor(name: string)<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.constructor|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：inDevices(devices: Array\<string>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：inDevices(devices: Array\<string>): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.inDevices|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：inAllDevices(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：inAllDevices(): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.inAllDevices|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：equalTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：equalTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.equalTo|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：notEqualTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：notEqualTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.notEqualTo|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：beginWrap(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：beginWrap(): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.beginWrap|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：endWrap(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：endWrap(): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.endWrap|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：or(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：or(): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.or|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：and(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：and(): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.and|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：contains(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：contains(field: string, value: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.contains|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：beginsWith(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：beginsWith(field: string, value: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.beginsWith|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：endsWith(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：endsWith(field: string, value: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.endsWith|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：isNull(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：isNull(field: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.isNull|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.isNotNull|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：like(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：like(field: string, value: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.like|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：glob(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：glob(field: string, value: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.glob|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：between(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：between(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.between|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.notBetween|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：greaterThan(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：greaterThan(field: string, value: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.greaterThan|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：lessThan(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：lessThan(field: string, value: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.lessThan|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.greaterThanOrEqualTo|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.lessThanOrEqualTo|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：orderByAsc(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：orderByAsc(field: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.orderByAsc|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：orderByDesc(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：orderByDesc(field: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.orderByDesc|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：distinct(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：distinct(): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.distinct|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：limitAs(value: number): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：limitAs(value: number): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.limitAs|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：offsetAs(rowOffset: number): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：offsetAs(rowOffset: number): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.offsetAs|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：groupBy(fields: Array\<string>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：groupBy(fields: Array\<string>): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.groupBy|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：indexedBy(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：indexedBy(field: string): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.indexedBy|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.in|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：RdbPredicates;<br>方法or属性：notIn(field: string, value: Array\<ValueType>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：notIn(field: string, value: Array\<ValueType>): RdbPredicates;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.RdbPredicates.notIn|@ohos.data.rdb.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：declare storage<br>旧版本信息：|类名：storage;<br>方法or属性：declare storage<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function getStorageSync(path: string): Storage;<br>旧版本信息：|类名：storage;<br>方法or属性：function getStorageSync(path: string): Storage;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.getPreferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function getStorage(path: string, callback: AsyncCallback\<Storage>): void;<br>旧版本信息：|类名：storage;<br>方法or属性：function getStorage(path: string, callback: AsyncCallback\<Storage>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function getStorage(path: string): Promise\<Storage>;<br>旧版本信息：|类名：storage;<br>方法or属性：function getStorage(path: string): Promise\<Storage>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function deleteStorageSync(path: string): void;<br>旧版本信息：|类名：storage;<br>方法or属性：function deleteStorageSync(path: string): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.deletePreferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function deleteStorage(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：storage;<br>方法or属性：function deleteStorage(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function deleteStorage(path: string): Promise\<void>;<br>旧版本信息：|类名：storage;<br>方法or属性：function deleteStorage(path: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function removeStorageFromCacheSync(path: string): void;<br>旧版本信息：|类名：storage;<br>方法or属性：function removeStorageFromCacheSync(path: string): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.removePreferencesFromCache|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function removeStorageFromCache(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：storage;<br>方法or属性：function removeStorageFromCache(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：function removeStorageFromCache(path: string): Promise\<void>;<br>旧版本信息：|类名：storage;<br>方法or属性：function removeStorageFromCache(path: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：storage;<br>方法or属性：type ValueType = number \| string \| boolean;<br>旧版本信息：|类名：storage;<br>方法or属性：type ValueType = number \| string \| boolean;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：interface Storage<br>旧版本信息：|类名：Storage;<br>方法or属性：interface Storage<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：getSync(key: string, defValue: ValueType): ValueType;<br>旧版本信息：|类名：Storage;<br>方法or属性：getSync(key: string, defValue: ValueType): ValueType;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.get|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：get(key: string, defValue: ValueType): Promise\<ValueType>;<br>旧版本信息：|类名：Storage;<br>方法or属性：get(key: string, defValue: ValueType): Promise\<ValueType>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：hasSync(key: string): boolean;<br>旧版本信息：|类名：Storage;<br>方法or属性：hasSync(key: string): boolean;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.has|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：has(key: string, callback: AsyncCallback\<boolean>): boolean;<br>旧版本信息：|类名：Storage;<br>方法or属性：has(key: string, callback: AsyncCallback\<boolean>): boolean;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：has(key: string): Promise\<boolean>;<br>旧版本信息：|类名：Storage;<br>方法or属性：has(key: string): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：putSync(key: string, value: ValueType): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：putSync(key: string, value: ValueType): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.put|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：put(key: string, value: ValueType): Promise\<void>;<br>旧版本信息：|类名：Storage;<br>方法or属性：put(key: string, value: ValueType): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：deleteSync(key: string): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：deleteSync(key: string): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.delete|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：delete(key: string): Promise\<void>;<br>旧版本信息：|类名：Storage;<br>方法or属性：delete(key: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：clearSync(): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：clearSync(): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.clear|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：clear(): Promise\<void>;<br>旧版本信息：|类名：Storage;<br>方法or属性：clear(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：flushSync(): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：flushSync(): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.flush|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：flush(): Promise\<void>;<br>旧版本信息：|类名：Storage;<br>方法or属性：flush(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：on(type: 'change', callback: Callback\<StorageObserver>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：on(type: 'change', callback: Callback\<StorageObserver>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.on|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：off(type: 'change', callback: Callback\<StorageObserver>): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：off(type: 'change', callback: Callback\<StorageObserver>): void;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences.off|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：StorageObserver;<br>方法or属性：interface StorageObserver<br>旧版本信息：|类名：StorageObserver;<br>方法or属性：interface StorageObserver<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：StorageObserver;<br>方法or属性：key: string;<br>旧版本信息：|类名：StorageObserver;<br>方法or属性：key: string;<br>新版本信息：9<br>代替接口： ohos.preferences.preferences|@ohos.data.storage.d.ts|
|废弃版本有变化|类名：GetStorageOptions;<br>方法or属性：export interface GetStorageOptions<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：export interface GetStorageOptions<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：GetStorageOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：key: string;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：SetStorageOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：key: string;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：DeleteStorageOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：key: string;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：GetStorageOptions;<br>方法or属性：default?: string;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：default?: string;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：GetStorageOptions;<br>方法or属性：success?: (data: any) => void;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：success?: (data: any) => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：GetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：SetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：ClearStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：DeleteStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：GetStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：SetStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：ClearStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：DeleteStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：SetStorageOptions;<br>方法or属性：export interface SetStorageOptions<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：export interface SetStorageOptions<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：SetStorageOptions;<br>方法or属性：value: string;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：value: string;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：SetStorageOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：success?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：ClearStorageOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：success?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：DeleteStorageOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：success?: () => void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：ClearStorageOptions;<br>方法or属性：export interface ClearStorageOptions<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：export interface ClearStorageOptions<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：DeleteStorageOptions;<br>方法or属性：export interface DeleteStorageOptions<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：export interface DeleteStorageOptions<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：export default class Storage<br>旧版本信息：|类名：Storage;<br>方法or属性：export default class Storage<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：static get(options: GetStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static get(options: GetStorageOptions): void;<br>新版本信息：6<br>代替接口： ohos.preferences.preferences.get|@system.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：static set(options: SetStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static set(options: SetStorageOptions): void;<br>新版本信息：6<br>代替接口：|@system.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：static clear(options?: ClearStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static clear(options?: ClearStorageOptions): void;<br>新版本信息：6<br>代替接口： ohos.preferences.preferences.clear|@system.storage.d.ts|
|废弃版本有变化|类名：Storage;<br>方法or属性：static delete(options: DeleteStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static delete(options: DeleteStorageOptions): void;<br>新版本信息：6<br>代替接口： ohos.preferences.preferences.delete|@system.storage.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：export interface ResultSet<br>旧版本信息：|类名：ResultSet;<br>方法or属性：export interface ResultSet<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：columnNames: Array\<string>;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：columnNames: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.columnNames|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：columnCount: number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：columnCount: number;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.columnCount|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：rowCount: number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：rowCount: number;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.rowCount|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：rowIndex: number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：rowIndex: number;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.rowIndex|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：isAtFirstRow: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isAtFirstRow: boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.isAtFirstRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：isAtLastRow: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isAtLastRow: boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.isAtLastRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：isEnded: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isEnded: boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.isEnded|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：isStarted: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isStarted: boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.isStarted|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：isClosed: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isClosed: boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.isClosed|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：getColumnIndex(columnName: string): number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getColumnIndex(columnName: string): number;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.getColumnIndex|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：getColumnName(columnIndex: number): string;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getColumnName(columnIndex: number): string;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.getColumnName|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：goTo(offset: number): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goTo(offset: number): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.goTo|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：goToRow(position: number): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToRow(position: number): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.goToRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：goToFirstRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToFirstRow(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.goToFirstRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：goToLastRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToLastRow(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.goToLastRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：goToNextRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToNextRow(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.goToNextRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：goToPreviousRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToPreviousRow(): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.goToPreviousRow|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：getBlob(columnIndex: number): Uint8Array;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getBlob(columnIndex: number): Uint8Array;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.getBlob|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：getString(columnIndex: number): string;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getString(columnIndex: number): string;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.getString|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：getLong(columnIndex: number): number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getLong(columnIndex: number): number;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.getLong|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：getDouble(columnIndex: number): number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getDouble(columnIndex: number): number;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.getDouble|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：isColumnNull(columnIndex: number): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isColumnNull(columnIndex: number): boolean;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.isColumnNull|resultSet.d.ts|
|废弃版本有变化|类名：ResultSet;<br>方法or属性：close(): void;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：close(): void;<br>新版本信息：9<br>代替接口： ohos.data.relationalStore.ResultSet.close|resultSet.d.ts|
|新增(错误码)|类名：Query;<br>方法or属性：deviceId(deviceId: string): Query;<br>旧版本信息：|类名：Query;<br>方法or属性：deviceId(deviceId: string): Query;<br>新版本信息：Throws|@ohos.data.distributedData.d.ts|
|新增(错误码)|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;<br>新版本信息：401|@ohos.data.rdb.d.ts|
|权限有变化|类名：DistributedObject;<br>方法or属性：setSessionId(sessionId?: string): boolean;<br>旧版本信息：|类名：DistributedObject;<br>方法or属性：setSessionId(sessionId?: string): boolean;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.distributedDataObject.d.ts|
|权限有变化|类名：SubscribeType;<br>方法or属性：enum SubscribeType<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：enum SubscribeType<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[ string, number ]>>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[ string, number ]>>): void;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[ string, number ]>>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[ string, number ]>>;<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|model有变化|类名：GetStorageOptions;<br>方法or属性：export interface GetStorageOptions<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：export interface GetStorageOptions<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：GetStorageOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：key: string;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：SetStorageOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：key: string;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：DeleteStorageOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：key: string;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：GetStorageOptions;<br>方法or属性：default?: string;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：default?: string;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：GetStorageOptions;<br>方法or属性：success?: (data: any) => void;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：success?: (data: any) => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：GetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：SetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：ClearStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：DeleteStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：GetStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：SetStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：ClearStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：DeleteStorageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：SetStorageOptions;<br>方法or属性：export interface SetStorageOptions<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：export interface SetStorageOptions<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：SetStorageOptions;<br>方法or属性：value: string;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：value: string;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：SetStorageOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：SetStorageOptions;<br>方法or属性：success?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：ClearStorageOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：success?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：DeleteStorageOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：success?: () => void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：ClearStorageOptions;<br>方法or属性：export interface ClearStorageOptions<br>旧版本信息：|类名：ClearStorageOptions;<br>方法or属性：export interface ClearStorageOptions<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：DeleteStorageOptions;<br>方法or属性：export interface DeleteStorageOptions<br>旧版本信息：|类名：DeleteStorageOptions;<br>方法or属性：export interface DeleteStorageOptions<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：Storage;<br>方法or属性：export default class Storage<br>旧版本信息：|类名：Storage;<br>方法or属性：export default class Storage<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：Storage;<br>方法or属性：static get(options: GetStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static get(options: GetStorageOptions): void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：Storage;<br>方法or属性：static set(options: SetStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static set(options: SetStorageOptions): void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：Storage;<br>方法or属性：static clear(options?: ClearStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static clear(options?: ClearStorageOptions): void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|model有变化|类名：Storage;<br>方法or属性：static delete(options: DeleteStorageOptions): void;<br>旧版本信息：|类名：Storage;<br>方法or属性：static delete(options: DeleteStorageOptions): void;<br>新版本信息：FAModelOnly|@system.storage.d.ts|
|函数有变化|类名：KVStore;<br>方法or属性：off(event:'dataChange', observer?: Callback\<ChangeNotification>): void;|类名：KVStore;<br>方法or属性：off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void;|@ohos.data.distributedData.d.ts|
|函数有变化|类名：KVStore;<br>方法or属性：off(event:'dataChange', observer?: Callback\<ChangeNotification>): void;|类名：KVStore;<br>方法or属性：off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void;|@ohos.data.distributedData.d.ts|
|函数有变化|类名：SingleKVStore;<br>方法or属性：sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void;|类名：SingleKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void;|@ohos.data.distributedData.d.ts|
|函数有变化|类名：DeviceKVStore;<br>方法or属性：sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void;|类名：DeviceKVStore;<br>方法or属性：sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void;|@ohos.data.distributedData.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：insert(name: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：insert(name: string, values: ValuesBucket): Promise\<number>;|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback\<number>): void;|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, rdbPredicates: RdbPredicates): Promise\<number>;|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：delete(rdbPredicates: RdbPredicates, callback: AsyncCallback\<number>): void;|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：delete(rdbPredicates: RdbPredicates): Promise\<number>;|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：query(rdbPredicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.rdb.d.ts|
|函数有变化|类名：RdbStore;<br>方法or属性：query(rdbPredicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>;|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns ?: Array\<string>): Promise\<ResultSet>;|@ohos.data.rdb.d.ts|
