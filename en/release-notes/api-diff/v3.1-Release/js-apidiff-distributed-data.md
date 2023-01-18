# JS API Changes of the Distributed Data Management Subsystem

The table below lists the APIs changes of the distributed data management subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.data.rdb | RdbPredicates | inAllDevices(): RdbPredicates; | Added|
| ohos.data.rdb | RdbPredicates | inDevices(devices: Array\<string>): RdbPredicates; | Added|
| ohos.data.rdb | RdbStore | off(event:'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void; | Added|
| ohos.data.rdb | RdbStore | on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void; | Added|
| ohos.data.rdb | RdbStore | sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[string, number]>>): void;<br>sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>>; | Added|
| ohos.data.rdb | RdbStore | obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>obtainDistributedTableName(device: string, table: string): Promise\<string>; | Added|
| ohos.data.rdb | RdbStore | setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>setDistributedTables(tables: Array\<string>): Promise\<void>; | Added|
| ohos.data.rdb | RdbStore | rollBack():void; | Added|
| ohos.data.rdb | RdbStore | commit():void; | Added|
| ohos.data.rdb | RdbStore | beginTransaction():void; | Added|
| ohos.data.rdb | RdbStore | querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>; | Added|
| ohos.data.rdb | SubscribeType | SUBSCRIBE_TYPE_REMOTE = 0 | Added|
| ohos.data.rdb | SyncMode | SYNC_MODE_PULL = 1 | Added|
| ohos.data.rdb | SyncMode | SYNC_MODE_PUSH = 0 | Added|
| ohos.data.distributedDataObject | DistributedObject | off(type: 'status', callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void; | Added|
| ohos.data.distributedDataObject | DistributedObject | on(type: 'status', callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void; | Added|
| ohos.data.distributedDataObject | DistributedObject | off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void; | Added|
| ohos.data.distributedDataObject | DistributedObject | on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void; | Added|
| ohos.data.distributedDataObject | DistributedObject | setSessionId(sessionId?: string): boolean; | Added|
| ohos.data.distributedDataObject | distributedDataObject | genSessionId(): string; | Added|
| ohos.data.distributedDataObject | distributedDataObject | createDistributedObject(source: object): DistributedObject; | Added|
| ohos.data.distributedData | KVManager | off(event: 'distributedDataServiceDie', deathCallback?: Callback\<void>): void; | Added|
| ohos.data.distributedData | KVManager | on(event: 'distributedDataServiceDie', deathCallback: Callback\<void>): void; | Added|
| ohos.data.distributedData | KVManager | getAllKVStoreId(appId: string, callback: AsyncCallback\<string[]>): void;<br>getAllKVStoreId(appId: string): Promise\<string[]>; | Added|
| ohos.data.distributedData | KVManager | deleteKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void;<br>deleteKVStore(appId: string, storeId: string): Promise\<void>; | Added|
| ohos.data.distributedData | KVManager | closeKVStore(appId: string, storeId: string, kvStore: KVStore, callback: AsyncCallback\<void>): void;<br>closeKVStore(appId: string, storeId: string, kvStore: KVStore): Promise\<void>; | Added|
| ohos.data.distributedData | DeviceKVStore | off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void; | Added|
| ohos.data.distributedData | DeviceKVStore | on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void; | Added|
| ohos.data.distributedData | DeviceKVStore | sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void; | Added|
| ohos.data.distributedData | DeviceKVStore | removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;<br>removeDeviceData(deviceId: string): Promise\<void>; | Added|
| ohos.data.distributedData | DeviceKVStore | getResultSize(query: Query, callback: AsyncCallback\<number>): void;<br>getResultSize(query: Query): Promise\<number>;<br>getResultSize(deviceId: string, query: Query, callback: AsyncCallback\<number>): void;<br>getResultSize(deviceId: string, query: Query): Promise\<number>; | Added|
| ohos.data.distributedData | DeviceKVStore | closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void;<br>closeResultSet(resultSet: KvStoreResultSet): Promise\<void>; | Added|
| ohos.data.distributedData | DeviceKVStore | getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void;<br>getResultSet(deviceId: string, keyPrefix: string): Promise\<KvStoreResultSet>;<br>getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>getResultSet(query: Query): Promise\<KvStoreResultSet>;<br>getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>getResultSet(deviceId: string, query: Query): Promise\<KvStoreResultSet>; | Added|
| ohos.data.distributedData | DeviceKVStore | getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;<br>getEntries(deviceId: string, keyPrefix: string): Promise\<Entry[]>;<br>getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;<br>getEntries(query: Query): Promise\<Entry[]>;<br>getEntries(deviceId: string, query: Query, callback: AsyncCallback\<Entry[]>): void;<br>getEntries(deviceId: string, query: Query): Promise\<Entry[]>; | Added|
| ohos.data.distributedData | DeviceKVStore | get(deviceId: string, key: string, callback: AsyncCallback\<boolean\|string\|number\|Uint8Array>): void;<br>get(deviceId: string, key: string): Promise\<boolean\|string\|number\|Uint8Array>; | Added|
| ohos.data.distributedData | SingleKVStore | getSecurityLevel(callback: AsyncCallback\<SecurityLevel>): void;<br>getSecurityLevel(): Promise\<SecurityLevel>; | Added|
| ohos.data.distributedData | SingleKVStore | setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback\<void>): void;<br>setSyncParam(defaultAllowedDelayMs: number): Promise\<void>; | Added|
| ohos.data.distributedData | SingleKVStore | off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void; | Added|
| ohos.data.distributedData | SingleKVStore | on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void; | Added|
| ohos.data.distributedData | SingleKVStore | removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void;<br>removeDeviceData(deviceId: string): Promise\<void>; | Added|
| ohos.data.distributedData | SingleKVStore | getResultSize(query: Query, callback: AsyncCallback\<number>): void;<br>getResultSize(query: Query): Promise\<number>; | Added|
| ohos.data.distributedData | SingleKVStore | closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void;<br>closeResultSet(resultSet: KvStoreResultSet): Promise\<void>; | Added|
| ohos.data.distributedData | SingleKVStore | getResultSet(keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void;<br>getResultSet(keyPrefix: string): Promise\<KvStoreResultSet>;<br>getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void;<br>getResultSet(query: Query): Promise\<KvStoreResultSet>; | Added|
| ohos.data.distributedData | SingleKVStore | getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void;<br>getEntries(keyPrefix: string): Promise\<Entry[]>;<br>getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void;<br>getEntries(query: Query): Promise\<Entry[]>; | Added|
| ohos.data.distributedData | KVStore | setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback\<void>): void;<br>setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | enableSync(enabled: boolean, callback: AsyncCallback\<void>): void;<br>enableSync(enabled: boolean): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | rollback(callback: AsyncCallback\<void>): void;<br>rollback(): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | commit(callback: AsyncCallback\<void>): void;<br>commit(): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | startTransaction(callback: AsyncCallback\<void>): void;<br>startTransaction(): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | deleteBatch(keys: string[], callback: AsyncCallback\<void>): void;<br>deleteBatch(keys: string[]): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | putBatch(entries: Entry[], callback: AsyncCallback\<void>): void;<br>putBatch(entries: Entry[]): Promise\<void>; | Added|
| ohos.data.distributedData | KVStore | off(event:'dataChange', observer?: Callback\<ChangeNotification>): void; | Added|
| ohos.data.distributedData | Query | getSqlLike():string; | Added|
| ohos.data.distributedData | Query | deviceId(deviceId:string):Query; | Added|
| ohos.data.distributedData | Query | setSuggestIndex(index: string): Query; | Added|
| ohos.data.distributedData | Query | prefixKey(prefix: string): Query; | Added|
| ohos.data.distributedData | Query | endGroup(): Query; | Added|
| ohos.data.distributedData | Query | beginGroup(): Query; | Added|
| ohos.data.distributedData | Query | isNotNull(field: string): Query; | Added|
| ohos.data.distributedData | Query | limit(total: number, offset: number): Query; | Added|
| ohos.data.distributedData | Query | orderByDesc(field: string): Query; | Added|
| ohos.data.distributedData | Query | orderByAsc(field: string): Query; | Added|
| ohos.data.distributedData | Query | or(): Query; | Added|
| ohos.data.distributedData | Query | and(): Query; | Added|
| ohos.data.distributedData | Query | unlike(field: string, value: string): Query; | Added|
| ohos.data.distributedData | Query | like(field: string, value: string): Query; | Added|
| ohos.data.distributedData | Query | notInString(field: string, valueList: string[]): Query; | Added|
| ohos.data.distributedData | Query | notInNumber(field: string, valueList: number[]): Query; | Added|
| ohos.data.distributedData | Query | inString(field: string, valueList: string[]): Query; | Added|
| ohos.data.distributedData | Query | inNumber(field: string, valueList: number[]): Query; | Added|
| ohos.data.distributedData | Query | isNull(field: string): Query; | Added|
| ohos.data.distributedData | Query | lessThanOrEqualTo(field: string, value: number\|string): Query; | Added|
| ohos.data.distributedData | Query | greaterThanOrEqualTo(field: string, value: number\|string): Query; | Added|
| ohos.data.distributedData | Query | lessThan(field: string, value: number\|string): Query; | Added|
| ohos.data.distributedData | Query | greaterThan(field: string, value: number\|string\|boolean): Query; | Added|
| ohos.data.distributedData | Query | notEqualTo(field: string, value: number\|string\|boolean): Query; | Added|
| ohos.data.distributedData | Query | equalTo(field: string, value: number\|string\|boolean): Query; | Added|
| ohos.data.distributedData | Query | reset(): Query; | Added|
| ohos.data.distributedData | Query | constructor() | Added|
| ohos.data.distributedData | KvStoreResultSet | getEntry(): Entry; | Added|
| ohos.data.distributedData | KvStoreResultSet | isAfterLast(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | isBeforeFirst(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | isLast(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | isFirst(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | moveToPosition(position: number): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | move(offset: number): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | moveToPrevious(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | moveToNext(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | moveToLast(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | moveToFirst(): boolean; | Added|
| ohos.data.distributedData | KvStoreResultSet | getPosition(): number; | Added|
| ohos.data.distributedData | KvStoreResultSet | getCount(): number; | Added|
| ohos.data.distributedData | FieldNode | type: number; | Added|
| ohos.data.distributedData | FieldNode | nullable: boolean; | Added|
| ohos.data.distributedData | FieldNode | default: string; | Added|
| ohos.data.distributedData | FieldNode | appendChild(child: FieldNode): boolean; | Added|
| ohos.data.distributedData | FieldNode | constructor(name: string) | Added|
| ohos.data.distributedData | Schema | skip: number; | Added|
| ohos.data.distributedData | Schema | mode: number; | Added|
| ohos.data.distributedData | Schema | indexes: Array\<string>; | Added|
| ohos.data.distributedData | Schema | root: FieldNode; | Added|
| ohos.data.distributedData | Schema | constructor() | Added|
| ohos.data.distributedData | Options | schema?: Schema; | Added|
