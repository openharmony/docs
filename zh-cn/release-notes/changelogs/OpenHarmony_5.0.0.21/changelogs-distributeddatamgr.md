# 分布式数据管理子系统Changelog

## cl.distributeddatamgr.1 新增错误码

针对分布式数据管理子系统relationalStore的API存在错误码笼统不清晰的问题，从API12开始作以下变更：
将14800000错误码进行分裂，分裂之后，原有14800000仅表示系统错误，将sql执行异常、内部状态异常和错误地使用接口分裂出来，具体如下：

- 新增错误码：
     * 14800014 - Already closed.
     * 14800017 - Config changed.
     * 14800018 - No data meets the condition.
     * 14800019 - The SQL must be a query statement.
     * 14800021 - SQLite: Generic error.
     * 14800022 - SQLite: Callback routine requested an abort.
     * 14800023 - SQLite: Access permission denied.
     * 14800024 - SQLite: The database file is locked.
     * 14800025 - SQLite: A table in the database is locked.
     * 14800026 - SQLite: The database is out of memory.
     * 14800027 - SQLite: Attempt to write a readonly database.
     * 14800028 - SQLite: Some kind of disk I/O error occurred.
     * 14800029 - SQLite: The database is full.
     * 14800030 - SQLite: Unable to open the database file.
     * 14800031 - SQLite: TEXT or BLOB exceeds size limit.
     * 14800032 - SQLite: Abort due to constraint violation.
     * 14800033 - SQLite: Data type mismatch.
     * 14800034 - SQLite: Library used incorrectly.

     变更后的错误码详细介绍请参见[关系型数据库错误码](../../../application-dev/reference//apis-arkdata/errorcode-data-rdb.md)。

**变更影响**

影响API12版本的ArkTS接口，新增错误码,可提高问题定位效率，不涉及适配问题。

**关键接口/组件变更**

以下接口涉及新增错误码：
  - interface ResultSet
    - getColumnIndex(columnName: string): number;
    - getColumnName(columnIndex: number): string;
    - goTo(offset: number): boolean;
    - goToRow(position: number): boolean;
    - goToFirstRow(): boolean;
    - goToLastRow(): boolean;
    - goToNextRow(): boolean;
    - goToPreviousRow(): boolean;
    - getBlob(columnIndex: number): Uint8Array;
    - getString(columnIndex: number): string;
    - getLong(columnIndex: number): number;
    - getDouble(columnIndex: number): number;
    - getAsset(columnIndex: number): Asset;
    - getAssets(columnIndex: number): Assets;
    - getValue(columnIndex: number): ValueType;
    - getFloat32Array(columnIndex: number): Float32Array;
    - getRow(): ValuesBucket;
    - isColumnNull(columnIndex: number): boolean;
    - close(): void;
  - interface RdbStore
    - version: number;
    - insert(table: string, values: ValuesBucket, callback: AsyncCallback<number>): void;
    - insert(table: string, values: ValuesBucket, conflict: ConflictResolution, callback: AsyncCallback<number>): void;
    - insert(table: string, values: ValuesBucket): Promise<number>;
    - insert(table: string, values: ValuesBucket, conflict: ConflictResolution): Promise<number>;
    - insertSync(table: string, values: ValuesBucket, conflict?: ConflictResolution): number;
    - batchInsert(table: string, values: Array<ValuesBucket>, callback: AsyncCallback<number>): void;
    - batchInsert(table: string, values: Array<ValuesBucket>): Promise<number>;
    - batchInsertSync(table: string, values: Array<ValuesBucket>): number;
    - update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback<number>): void;
    - update(
        values: ValuesBucket,
        predicates: RdbPredicates,
        conflict: ConflictResolution,
        callback: AsyncCallback<number>
      ): void;
    - update(values: ValuesBucket, predicates: RdbPredicates): Promise<number>;
    - update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution): Promise<number>;
    - updateSync(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): number;
    - update(
        table: string,
        values: ValuesBucket,
        predicates: dataSharePredicates.DataSharePredicates,
        callback: AsyncCallback<number>
      ): void;
    - update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise<number>;
    - delete(predicates: RdbPredicates, callback: AsyncCallback<number>): void;
    - delete(predicates: RdbPredicates): Promise<number>;
    - deleteSync(predicates: RdbPredicates): number;
    - delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback<number>): void;
    - delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise<number>;
    - query(predicates: RdbPredicates, callback: AsyncCallback<ResultSet>): void;
    - query(predicates: RdbPredicates, columns: Array<string>, callback: AsyncCallback<ResultSet>): void;
    - query(predicates: RdbPredicates, columns?: Array<string>): Promise<ResultSet>;
    - query(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback<ResultSet>): void;
    - query(
        table: string,
        predicates: dataSharePredicates.DataSharePredicates,
        columns: Array<string>,
        callback: AsyncCallback<ResultSet>
      ): void;
    - query(
        table: string,
        predicates: dataSharePredicates.DataSharePredicates,
        columns?: Array<string>
      ): Promise<ResultSet>;
    - querySync(predicates: RdbPredicates, columns?: Array<string>): ResultSet;
    - querySql(sql: string, callback: AsyncCallback<ResultSet>): void;
    - querySql(sql: string, bindArgs: Array<ValueType>, callback: AsyncCallback<ResultSet>): void;
    - querySql(sql: string, bindArgs?: Array<ValueType>): Promise<ResultSet>;
    - querySqlSync(sql: string, bindArgs?: Array<ValueType>): ResultSet;
    - getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise<ModifyTime>;
    - getModifyTime(
        table: string,
        columnName: string,
        primaryKeys: PRIKeyType[],
        callback: AsyncCallback<ModifyTime>
      ): void;
    - cleanDirtyData(table: string, cursor: number, callback: AsyncCallback<void>): void;
    - cleanDirtyData(table: string, callback: AsyncCallback<void>): void;
    - cleanDirtyData(table: string, cursor?: number): Promise<void>;
    - querySharingResource(predicates: RdbPredicates, columns?: Array<string>): Promise<ResultSet>;
    - querySharingResource(predicates: RdbPredicates, callback: AsyncCallback<ResultSet>): void;
    - querySharingResource(predicates: RdbPredicates, columns: Array<string>, callback: AsyncCallback<ResultSet>): void;
    - executeSql(sql: string, callback: AsyncCallback<void>): void;
    - executeSql(sql: string, bindArgs: Array<ValueType>, callback: AsyncCallback<void>): void;
    - executeSql(sql: string, bindArgs?: Array<ValueType>): Promise<void>;
    - execute(sql: string, args?: Array<ValueType>): Promise<ValueType>;
    - execute(sql: string, txId: number, args?: Array<ValueType>): Promise<ValueType>;
    - executeSync(sql: string, args?: Array<ValueType>): ValueType;
    - beginTransaction(): void;
    - beginTrans(): Promise<number>;
    - commit(): void;
    - commit(txId : number): Promise<void>;
    - rollBack(): void;
    - rollback(txId : number): Promise<void>;
    - backup(destName: string, callback: AsyncCallback<void>): void;
    - backup(destName: string): Promise<void>;
    - restore(srcName: string, callback: AsyncCallback<void>): void;
    - restore(srcName: string): Promise<void>;
    - setDistributedTables(tables: Array<string>, callback: AsyncCallback<void>): void;
    - setDistributedTables(tables: Array<string>): Promise<void>;
    - setDistributedTables(tables: Array<string>, type: DistributedType, callback: AsyncCallback<void>): void;
    - setDistributedTables(
        tables: Array<string>,
        type: DistributedType,
        config: DistributedConfig,
        callback: AsyncCallback<void>
      ): void;
    - setDistributedTables(tables: Array<string>, type?: DistributedType, config?: DistributedConfig): Promise<void>;
    - obtainDistributedTableName(device: string, table: string, callback: AsyncCallback<string>): void;
    - obtainDistributedTableName(device: string, table: string): Promise<string>;
    - sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback<Array<[string, number]>>): void;
    - sync(mode: SyncMode, predicates: RdbPredicates): Promise<Array<[string, number]>>;
    - cloudSync(mode: SyncMode, progress: Callback<ProgressDetails>, callback: AsyncCallback<void>): void;
    - cloudSync(mode: SyncMode, progress: Callback<ProgressDetails>): Promise<void>;
    - cloudSync(
        mode: SyncMode,
        tables: string[],
        progress: Callback<ProgressDetails>,
        callback: AsyncCallback<void>
      ): void;
    - cloudSync(mode: SyncMode, tables: string[], progress: Callback<ProgressDetails>): Promise<void>;
    - cloudSync(
        mode: SyncMode,
        predicates: RdbPredicates,
        progress: Callback<ProgressDetails>,
        callback: AsyncCallback<void>
      ): void;
    - cloudSync(mode: SyncMode, predicates: RdbPredicates, progress: Callback<ProgressDetails>): Promise<void>;
    - remoteQuery(
        device: string,
        table: string,
        predicates: RdbPredicates,
        columns: Array<string>,
        callback: AsyncCallback<ResultSet>
      ): void;
    - remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array<string>): Promise<ResultSet>;
    - on(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>>): void;
    - on(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>> | Callback<Array<ChangeInfo>>): void;
    - on(event: string, interProcess: boolean, observer: Callback<void>): void;
    - on(event: 'autoSyncProgress', progress: Callback<ProgressDetails>): void;
    - off(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>>): void;
    - off(
        event: 'dataChange',
        type: SubscribeType,
        observer?: Callback<Array<string>> | Callback<Array<ChangeInfo>>
      ): void;
    - off(event: string, interProcess: boolean, observer?: Callback<void>): void;
    - off(event: 'autoSyncProgress', progress?: Callback<ProgressDetails>): void;
    - emit(event: string): void;
    - attach(fullPath: string, attachName: string, waitTime?: number) : Promise<number>;
    - attach(context: Context, config: StoreConfig, attachName: string, waitTime?: number) : Promise<number>;
    - detach(attachName: string, waitTime?: number) : Promise<number>;
    - lockRow(predicates: RdbPredicates): Promise<void>;
    - unlockRow(predicates: RdbPredicates): Promise<void>;
    - queryLockedRow(predicates: RdbPredicates, columns?: Array<string>): Promise<ResultSet>;
    - on(event: 'autoSyncProgress', progress: Callback<ProgressDetails>): void;
  - function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback<RdbStore>): void;
  - function getRdbStore(context: Context, config: StoreConfig): Promise<RdbStore>;
  - function deleteRdbStore(context: Context, config: StoreConfig): Promise<void>;
