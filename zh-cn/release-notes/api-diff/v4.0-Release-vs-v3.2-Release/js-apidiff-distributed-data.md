| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：DistributedObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DistributedObject;<br>方法or属性：on(type: 'status',<br><br>           callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：on(type: 'status',<br><br>           callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DistributedObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DistributedObject;<br>方法or属性：off(type: 'status',<br><br>            callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：off(type: 'status',<br><br>            callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：name: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ClearAction;<br>方法or属性：CLEAR_CLOUD_INFO|@ohos.data.cloudData.d.ts|
|新增|NA|类名：ClearAction;<br>方法or属性：CLEAR_CLOUD_DATA_AND_INFO|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static enableCloud(<br>      accountId: string,<br>      switches: { [bundleName: string]: boolean },<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static enableCloud(accountId: string, switches: { [bundleName: string]: boolean }): Promise\<void>;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static disableCloud(accountId: string, callback: AsyncCallback\<void>): void;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static disableCloud(accountId: string): Promise\<void>;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static changeAppCloudSwitch(<br>      accountId: string,<br>      bundleName: string,<br>      status: boolean,<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise\<void>;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static notifyDataChange(accountId: string, bundleName: string): Promise\<void>;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static clear(<br>      accountId: string,<br>      appActions: { [bundleName: string]: ClearAction },<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise\<void>;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：dataShare;<br>方法or属性：function createDataShareHelper(<br>    context: Context,<br>    uri: string,<br>    options: DataShareHelperOptions,<br>    callback: AsyncCallback\<DataShareHelper><br>  ): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelperOptions;<br>方法or属性：isProxy?: boolean;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：TemplateId;<br>方法or属性：subscriberId: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：PublishedItem;<br>方法or属性：subscriberId: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：TemplateId;<br>方法or属性：bundleNameOfOwner: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：PublishedItem;<br>方法or属性：key: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：OperationResult;<br>方法or属性：key: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：PublishedItem;<br>方法or属性：data: string \| ArrayBuffer;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：RdbDataChangeNode;<br>方法or属性：uri: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：RdbDataChangeNode;<br>方法or属性：templateId: TemplateId;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：RdbDataChangeNode;<br>方法or属性：data: Array\<string>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：PublishedDataChangeNode;<br>方法or属性：bundleName: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：PublishedDataChangeNode;<br>方法or属性：data: Array\<PublishedItem>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：Template;<br>方法or属性：predicates: { [key: string]: string };|@ohos.data.dataShare.d.ts|
|新增|NA|类名：Template;<br>方法or属性：scheduler: string;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：OperationResult;<br>方法or属性：result: number;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：on(<br>      type: 'rdbDataChange',<br>      uris: Array\<string>,<br>      templateId: TemplateId,<br>      callback: AsyncCallback\<RdbDataChangeNode><br>    ): Array\<OperationResult>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：on(<br>      type: 'publishedDataChange',<br>      uris: Array\<string>,<br>      subscriberId: string,<br>      callback: AsyncCallback\<PublishedDataChangeNode><br>    ): Array\<OperationResult>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：off(<br>      type: 'rdbDataChange',<br>      uris: Array\<string>,<br>      templateId: TemplateId,<br>      callback?: AsyncCallback\<RdbDataChangeNode><br>    ): Array\<OperationResult>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：off(<br>      type: 'publishedDataChange',<br>      uris: Array\<string>,<br>      subscriberId: string,<br>      callback?: AsyncCallback\<PublishedDataChangeNode><br>    ): Array\<OperationResult>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：addTemplate(uri: string, subscriberId: string, template: Template): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：delTemplate(uri: string, subscriberId: string): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：publish(<br>      data: Array\<PublishedItem>,<br>      bundleName: string,<br>      version: number,<br>      callback: AsyncCallback\<Array\<OperationResult>><br>    ): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：publish(<br>      data: Array\<PublishedItem>,<br>      bundleName: string,<br>      callback: AsyncCallback\<Array\<OperationResult>><br>    ): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：publish(data: Array\<PublishedItem>, bundleName: string, version?: number): Promise\<Array\<OperationResult>>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：getPublishedData(bundleName: string, callback: AsyncCallback\<Array\<PublishedItem>>): void;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DataShareHelper;<br>方法or属性：getPublishedData(bundleName: string): Promise\<Array\<PublishedItem>>;|@ohos.data.dataShare.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：on(<br><br>      type: 'status',<br><br>      callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：on(<br><br>      type: 'status',<br><br>      callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：off(<br><br>      type: 'status',<br><br>      callback?: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：off(<br><br>      type: 'status',<br><br>      callback?: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferences(context: Context, options: Options, callback: AsyncCallback\<Preferences>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferences(context: Context, options: Options): Promise\<Preferences>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferencesSync(context: Context, options: Options): Preferences;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, options: Options, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, options: Options): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, options: Options, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, options: Options): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCacheSync(context: Context, name: string): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCacheSync(context: Context, options: Options): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Options;<br>方法or属性：name: string;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Options;<br>方法or属性：dataGroupId?: string;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：getSync(key: string, defValue: ValueType): ValueType;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：getAllSync(): Object;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：hasSync(key: string): boolean;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：putSync(key: string, value: ValueType): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：deleteSync(key: string): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：clearSync(): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：type Assets = Asset[];|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：type PRIKeyType = number \| string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：type UTCTime = Date;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：type ModifyTime = Map\<PRIKeyType, UTCTime>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, config: StoreConfig): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：AssetStatus;<br>方法or属性：ASSET_NORMAL|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：AssetStatus;<br>方法or属性：ASSET_INSERT|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：AssetStatus;<br>方法or属性：ASSET_UPDATE|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：AssetStatus;<br>方法or属性：ASSET_DELETE|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：AssetStatus;<br>方法or属性：ASSET_ABNORMAL|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：AssetStatus;<br>方法or属性：ASSET_DOWNLOADING|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：uri: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：path: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：createTime: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：modifyTime: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：size: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Asset;<br>方法or属性：status?: AssetStatus;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：StoreConfig;<br>方法or属性：dataGroupId?: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：SYNC_BEGIN|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：SYNC_IN_PROGRESS|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：SYNC_FINISH|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Statistic;<br>方法or属性：total: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Statistic;<br>方法or属性：successful: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Statistic;<br>方法or属性：failed: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：Statistic;<br>方法or属性：remained: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：TableDetails;<br>方法or属性：upload: Statistic;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：TableDetails;<br>方法or属性：download: Statistic;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：SUCCESS|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：UNKNOWN_ERROR|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：NETWORK_ERROR|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：CLOUD_DISABLED|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：LOCKED_BY_OTHERS|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：RECORD_LIMIT_EXCEEDED|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressCode;<br>方法or属性：NO_SPACE_FOR_ASSET|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressDetails;<br>方法or属性：schedule: Progress;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressDetails;<br>方法or属性：code: ProgressCode;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ProgressDetails;<br>方法or属性：details: {<br>      [table: string]: TableDetails;<br>    };|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：SYNC_MODE_TIME_FIRST|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：SYNC_MODE_NATIVE_FIRST|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SyncMode;<br>方法or属性：SYNC_MODE_CLOUD_FIRST|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_CLOUD|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_CLOUD_DETAILS|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeType;<br>方法or属性：DATA_CHANGE|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeType;<br>方法or属性：ASSET_CHANGE|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeInfo;<br>方法or属性：table: string;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeInfo;<br>方法or属性：type: ChangeType;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeInfo;<br>方法or属性：inserted: Array\<string> \| Array\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeInfo;<br>方法or属性：updated: Array\<string> \| Array\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ChangeInfo;<br>方法or属性：deleted: Array\<string> \| Array\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：DistributedType;<br>方法or属性：DISTRIBUTED_DEVICE|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：DistributedType;<br>方法or属性：DISTRIBUTED_CLOUD|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：DistributedConfig;<br>方法or属性：autoSync: boolean;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ConflictResolution;<br>方法or属性：ON_CONFLICT_NONE = 0|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ConflictResolution;<br>方法or属性：ON_CONFLICT_ROLLBACK = 1|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ConflictResolution;<br>方法or属性：ON_CONFLICT_ABORT = 2|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ConflictResolution;<br>方法or属性：ON_CONFLICT_FAIL = 3|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ConflictResolution;<br>方法or属性：ON_CONFLICT_IGNORE = 4|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ConflictResolution;<br>方法or属性：ON_CONFLICT_REPLACE = 5|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getAsset(columnIndex: number): Asset;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getAssets(columnIndex: number): Assets;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：version: number;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, conflict: ConflictResolution, callback: AsyncCallback\<number>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, conflict: ConflictResolution): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：update(<br>      values: ValuesBucket,<br>      predicates: RdbPredicates,<br>      conflict: ConflictResolution,<br>      callback: AsyncCallback\<number><br>    ): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution): Promise\<number>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：query(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：querySql(sql: string, callback: AsyncCallback\<ResultSet>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise\<ModifyTime>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：getModifyTime(<br>      table: string,<br>      columnName: string,<br>      primaryKeys: PRIKeyType[],<br>      callback: AsyncCallback\<ModifyTime><br>    ): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：executeSql(sql: string, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, type: DistributedType, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：setDistributedTables(<br>      tables: Array\<string>,<br>      type: DistributedType,<br>      config: DistributedConfig,<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, type?: DistributedType, config?: DistributedConfig): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：cloudSync(mode: SyncMode, progress: Callback\<ProgressDetails>, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：cloudSync(mode: SyncMode, progress: Callback\<ProgressDetails>): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：cloudSync(<br>      mode: SyncMode,<br>      tables: string[],<br>      progress: Callback\<ProgressDetails>,<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：cloudSync(mode: SyncMode, tables: string[], progress: Callback\<ProgressDetails>): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>> \| Callback\<Array\<ChangeInfo>>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：on(event: string, interProcess: boolean, observer: Callback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：off(<br>      event: 'dataChange',<br>      type: SubscribeType,<br>      observer?: Callback\<Array\<string>> \| Callback\<Array\<ChangeInfo>><br>    ): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：off(event: string, interProcess: boolean, observer?: Callback\<void>): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：emit(event: string): void;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：type Options = {<br>    /**<br>     * Indicates the target Intention<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    intention?: Intention;<br><br>    /**<br>     * Indicates the unique identifier of target UnifiedData<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    key?: string;<br>  };|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function insertData(options: Options, data: UnifiedData): Promise\<string>;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function updateData(options: Options, data: UnifiedData): Promise\<void>;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function queryData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：unifiedDataChannel;<br>方法or属性：function deleteData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：UnifiedData;<br>方法or属性：constructor(record: UnifiedRecord);|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：UnifiedData;<br>方法or属性：addRecord(record: UnifiedRecord): void;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：UnifiedData;<br>方法or属性：getRecords(): Array\<UnifiedRecord>;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Summary;<br>方法or属性：summary: { [key: string]: number };|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Summary;<br>方法or属性：totalSize: number;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：UnifiedRecord;<br>方法or属性：getType(): string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Text;<br>方法or属性：details?: { [key: string]: string };|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：File;<br>方法or属性：details?: { [key: string]: string };|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：PlainText;<br>方法or属性：textContent: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：PlainText;<br>方法or属性：abstract?: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Hyperlink;<br>方法or属性：url: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Hyperlink;<br>方法or属性：description?: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：HTML;<br>方法or属性：htmlContent: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：HTML;<br>方法or属性：plainContent?: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：File;<br>方法or属性：uri: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Image;<br>方法or属性：imageUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Video;<br>方法or属性：videoUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Audio;<br>方法or属性：audioUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Folder;<br>方法or属性：folderUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedRecord;<br>方法or属性：details?: { [key: string]: number \| string \| Uint8Array };|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedForm;<br>方法or属性：formId: number;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedForm;<br>方法or属性：formName: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedForm;<br>方法or属性：bundleName: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedAppItem;<br>方法or属性：bundleName: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedForm;<br>方法or属性：abilityName: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedAppItem;<br>方法or属性：abilityName: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedForm;<br>方法or属性：module: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedAppItem;<br>方法or属性：appId: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedAppItem;<br>方法or属性：appName: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedAppItem;<br>方法or属性：appIconId: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedAppItem;<br>方法or属性：appLabelId: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：SystemDefinedPixelMap;<br>方法or属性：rawData: Uint8Array;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：ApplicationDefinedRecord;<br>方法or属性：rawData: Uint8Array;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：ApplicationDefinedRecord;<br>方法or属性：applicationDefinedType: string;|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：Intention;<br>方法or属性：DATA_HUB = 'DataHub'|@ohos.data.unifiedDataChannel.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：TEXT = 'general.text'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：PLAIN_TEXT = 'general.plain-text'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：HYPERLINK = 'general.hyperlink'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：HTML = 'general.html'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：FILE = 'general.file'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：IMAGE = 'general.image'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：VIDEO = 'general.video'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：AUDIO = 'general.audio'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：FOLDER = 'general.folder'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：OPENHARMONY_FORM = 'openharmony.form'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：OPENHARMONY_APP_ITEM = 'openharmony.app-item'|@ohos.data.uniformTypeDescriptor.d.ts|
|新增|NA|类名：UniformDataType;<br>方法or属性：OPENHARMONY_PIXEL_MAP = 'openharmony.pixel-map'|@ohos.data.uniformTypeDescriptor.d.ts|
|错误码有变化|类名：DataAbilityPredicates;<br>方法or属性：limitAs(value: number): DataAbilityPredicates;<br>旧版本信息：IllegalPredicateException|类名：DataAbilityPredicates;<br>方法or属性：limitAs(value: number): DataAbilityPredicates;<br>新版本信息：|@ohos.data.dataAbility.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean): Promise\<void>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：put(key: string, value: Uint8Array \| string \| number \| boolean): Promise\<void>;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：putBatch(entries: Entry[], callback: AsyncCallback\<void>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：putBatch(entries: Entry[], callback: AsyncCallback\<void>): void;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：putBatch(entries: Entry[]): Promise\<void>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：putBatch(entries: Entry[]): Promise\<void>;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：putBatch(value: Array\<ValuesBucket>, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：putBatch(value: Array\<ValuesBucket>, callback: AsyncCallback\<void>): void;<br>新版本信息：401,202,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：putBatch(value: Array\<ValuesBucket>): Promise\<void>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：putBatch(value: Array\<ValuesBucket>): Promise\<void>;<br>新版本信息：401,202,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：delete(key: string): Promise\<void>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：delete(key: string): Promise\<void>;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void>);<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void>);<br>新版本信息：401,202,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：delete(predicates: dataSharePredicates.DataSharePredicates): Promise\<void>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：delete(predicates: dataSharePredicates.DataSharePredicates): Promise\<void>;<br>新版本信息：401,202,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：deleteBatch(keys: string[], callback: AsyncCallback\<void>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：deleteBatch(keys: string[], callback: AsyncCallback\<void>): void;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：deleteBatch(keys: string[]): Promise\<void>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：deleteBatch(keys: string[]): Promise\<void>;<br>新版本信息：401,15100003,15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KVStoreResultSet>;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(query: Query): Promise\<KVStoreResultSet>;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,202,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,202,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：SingleKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;<br>新版本信息：401,202,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;<br>新版本信息：401,202,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：startTransaction(callback: AsyncCallback\<void>): void;<br>旧版本信息：15100005|类名：SingleKVStore;<br>方法or属性：startTransaction(callback: AsyncCallback\<void>): void;<br>新版本信息：15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：SingleKVStore;<br>方法or属性：startTransaction(): Promise\<void>;<br>旧版本信息：15100005|类名：SingleKVStore;<br>方法or属性：startTransaction(): Promise\<void>;<br>新版本信息：15100005,14800047|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, keyPrefix: string): Promise\<KVStoreResultSet>;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KVStoreResultSet>): void;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, query: Query): Promise\<KVStoreResultSet>;<br>新版本信息：401,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(<br>      deviceId: string,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      callback: AsyncCallback\<KVStoreResultSet><br>    ): void;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(<br>      deviceId: string,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      callback: AsyncCallback\<KVStoreResultSet><br>    ): void;<br>新版本信息：401,202,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;<br>旧版本信息：401,15100003,15100005|类名：DeviceKVStore;<br>方法or属性：getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>;<br>新版本信息：401,202,15100001,15100003,15100005|@ohos.data.distributedKVStore.d.ts|
|错误码有变化|类名：Preferences;<br>方法or属性：on(type: 'multiProcessChange', callback: (key: string) => void): void;<br>旧版本信息：401|类名：Preferences;<br>方法or属性：on(type: 'multiProcessChange', callback: (key: string) => void): void;<br>新版本信息：401,15500019|@ohos.data.preferences.d.ts|
|错误码有变化|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>旧版本信息：401,14800010,14800011|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>新版本信息：401,14800000,14800010,14800011,14801001,14801002|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>旧版本信息：401,14800010,14800011|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>新版本信息：401,14800000,14800010,14800011,14801001,14801002|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,14800010|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>新版本信息：401,14800000,14800010|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;<br>旧版本信息：401,14800010|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;<br>新版本信息：401,14800000,14800010|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：update(<br>      table: string,<br>      values: ValuesBucket,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      callback: AsyncCallback\<number><br>    ): void;<br>旧版本信息：401,202|类名：RdbStore;<br>方法or属性：update(<br>      table: string,<br>      values: ValuesBucket,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      callback: AsyncCallback\<number><br>    ): void;<br>新版本信息：14800047,401,14800000,202|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;<br>旧版本信息：401,202|类名：RdbStore;<br>方法or属性：update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;<br>新版本信息：14800047,401,14800000,202|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：401,202|类名：RdbStore;<br>方法or属性：delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：14800047,401,14800000,202|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;<br>旧版本信息：401,202|类名：RdbStore;<br>方法or属性：delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>;<br>新版本信息：14800047,401,14800000,202|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：query(<br>      table: string,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      columns: Array\<string>,<br>      callback: AsyncCallback\<ResultSet><br>    ): void;<br>旧版本信息：401,202|类名：RdbStore;<br>方法or属性：query(<br>      table: string,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      columns: Array\<string>,<br>      callback: AsyncCallback\<ResultSet><br>    ): void;<br>新版本信息：401,14800000,202|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：query(<br>      table: string,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      columns?: Array\<string><br>    ): Promise\<ResultSet>;<br>旧版本信息：401,202|类名：RdbStore;<br>方法or属性：query(<br>      table: string,<br>      predicates: dataSharePredicates.DataSharePredicates,<br>      columns?: Array\<string><br>    ): Promise\<ResultSet>;<br>新版本信息：401,14800000,202|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：beginTransaction(): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：beginTransaction(): void;<br>新版本信息：14800047,401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：backup(destName: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：backup(destName: string, callback: AsyncCallback\<void>): void;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：backup(destName: string): Promise\<void>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：backup(destName: string): Promise\<void>;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：restore(srcName: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：restore(srcName: string, callback: AsyncCallback\<void>): void;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：restore(srcName: string): Promise\<void>;<br>旧版本信息：401|类名：RdbStore;<br>方法or属性：restore(srcName: string): Promise\<void>;<br>新版本信息：401,14800000|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：setDistributedTables(tables: Array\<string>): Promise\<void>;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：obtainDistributedTableName(device: string, table: string): Promise\<string>;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[string, number]>>): void;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[string, number]>>): void;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>>;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>>;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：remoteQuery(<br>      device: string,<br>      table: string,<br>      predicates: RdbPredicates,<br>      columns: Array\<string>,<br>      callback: AsyncCallback\<ResultSet><br>    ): void;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：remoteQuery(<br>      device: string,<br>      table: string,<br>      predicates: RdbPredicates,<br>      columns: Array\<string>,<br>      callback: AsyncCallback\<ResultSet><br>    ): void;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：RdbStore;<br>方法or属性：remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>;<br>旧版本信息：401,801|类名：RdbStore;<br>方法or属性：remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>;<br>新版本信息：401,14800000,801|@ohos.data.relationalStore.d.ts|
|访问级别有变化|类名：dataSharePredicates;<br>方法or属性：declare dataSharePredicates<br>旧版本信息：systemapi|类名：dataSharePredicates;<br>方法or属性：declare dataSharePredicates<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：class DataSharePredicates<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：class DataSharePredicates<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：equalTo(field: string, value: ValueType): DataSharePredicates;<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：equalTo(field: string, value: ValueType): DataSharePredicates;<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：and(): DataSharePredicates;<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：and(): DataSharePredicates;<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：orderByAsc(field: string): DataSharePredicates;<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：orderByAsc(field: string): DataSharePredicates;<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：orderByDesc(field: string): DataSharePredicates;<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：orderByDesc(field: string): DataSharePredicates;<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：limit(total: number, offset: number): DataSharePredicates;<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：limit(total: number, offset: number): DataSharePredicates;<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：DataSharePredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): DataSharePredicates;<br>旧版本信息：systemapi|类名：DataSharePredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): DataSharePredicates;<br>新版本信息：|@ohos.data.dataSharePredicates.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export type ValueType = number \| string \| boolean;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export type ValueType = number \| string \| boolean;<br>新版本信息：|@ohos.data.ValuesBucket.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export type ValuesBucket = {<br><br>  [key: string]: ValueType \| Uint8Array \| null;<br><br>};<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export type ValuesBucket = {<br><br>  [key: string]: ValueType \| Uint8Array \| null;<br><br>};<br>新版本信息：|@ohos.data.ValuesBucket.d.ts|
|权限有变化|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.rdb.d.ts|
|权限有变化|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0<br>旧版本信息：|类名：SubscribeType;<br>方法or属性：SUBSCRIBE_TYPE_REMOTE = 0<br>新版本信息：ohos.permission.DISTRIBUTED_DATASYNC|@ohos.data.relationalStore.d.ts|
|type有变化|类名：DataShareExtensionAbility;<br>方法or属性：context: ExtensionContext;<br>旧版本信息：|类名：DataShareExtensionAbility;<br>方法or属性：context: ExtensionContext;<br>新版本信息：ExtensionContext|@ohos.application.DataShareExtensionAbility.d.ts|
|函数有变化|类名：DataShareExtensionAbility;<br>方法or属性：context?: ExtensionContext;|类名：DataShareExtensionAbility;<br>方法or属性：context: ExtensionContext;|@ohos.application.DataShareExtensionAbility.d.ts|
|函数有变化|类名：dataShare;<br>方法or属性：function createDataShareHelper(context: Context, uri: string): Promise\<DataShareHelper>;|类名：dataShare;<br>方法or属性：function createDataShareHelper(<br>    context: Context,<br>    uri: string,<br>    options?: DataShareHelperOptions<br>  ): Promise\<DataShareHelper>;|@ohos.data.dataShare.d.ts|
|函数有变化|类名：KVManagerConfig;<br>方法or属性：context: Context;|类名：KVManagerConfig;<br>方法or属性：context: BaseContext;|@ohos.data.distributedKVStore.d.ts|
|函数有变化|类名：Preferences;<br>方法or属性：on(type: 'change', callback: Callback\<{ key: string }>): void;|类名：Preferences;<br>方法or属性：on(type: 'change', callback: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|函数有变化|类名：Preferences;<br>方法or属性：on(type: 'change', callback: Callback\<{ key: string }>): void;|类名：Preferences;<br>方法or属性：on(type: 'multiProcessChange', callback: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|函数有变化|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: Callback\<{ key: string }>): void;|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|函数有变化|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: Callback\<{ key: string }>): void;|类名：Preferences;<br>方法or属性：off(type: 'multiProcessChange', callback?: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|函数有变化|类名：relationalStore;<br>方法or属性：type ValueType = number \| string \| boolean \| Uint8Array;|类名：relationalStore;<br>方法or属性：type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;|@ohos.data.relationalStore.d.ts|
|函数有变化|类名：relationalStore;<br>方法or属性：type ValuesBucket = { [key:string]: ValueType \| Uint8Array \| null;}|类名：relationalStore;<br>方法or属性：type ValuesBucket = { [key: string]: ValueType; };|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：declare preferences<br>旧版本信息：|类名：preferences;<br>方法or属性：declare preferences<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：function getPreferences(context: Context, name: string, callback: AsyncCallback\<Preferences>): void;<br>旧版本信息：|类名：preferences;<br>方法or属性：function getPreferences(context: Context, name: string, callback: AsyncCallback\<Preferences>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：function getPreferences(context: Context, name: string): Promise\<Preferences>;<br>旧版本信息：|类名：preferences;<br>方法or属性：function getPreferences(context: Context, name: string): Promise\<Preferences>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, name: string): Promise\<void>;<br>旧版本信息：|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, name: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, name: string): Promise\<void>;<br>旧版本信息：|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, name: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：interface Preferences<br>旧版本信息：|类名：Preferences;<br>方法or属性：interface Preferences<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：get(key: string, defValue: ValueType): Promise\<ValueType>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：get(key: string, defValue: ValueType): Promise\<ValueType>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：getAll(callback: AsyncCallback\<Object>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：getAll(callback: AsyncCallback\<Object>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：getAll(): Promise\<Object>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：getAll(): Promise\<Object>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：has(key: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：has(key: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：has(key: string): Promise\<boolean>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：has(key: string): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：put(key: string, value: ValueType, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：put(key: string, value: ValueType): Promise\<void>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：put(key: string, value: ValueType): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：delete(key: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：delete(key: string): Promise\<void>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：delete(key: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：clear(): Promise\<void>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：clear(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：flush(): Promise\<void>;<br>旧版本信息：|类名：Preferences;<br>方法or属性：flush(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：on(type: 'change', callback: (key: string) => void): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：on(type: 'change', callback: (key: string) => void): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: (key: string) => void): void;<br>旧版本信息：|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: (key: string) => void): void;<br>新版本信息：crossplatform|@ohos.data.preferences.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：declare relationalStore<br>旧版本信息：|类名：relationalStore;<br>方法or属性：declare relationalStore<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>旧版本信息：|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>旧版本信息：|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;<br>旧版本信息：|类名：relationalStore;<br>方法or属性：function deleteRdbStore(context: Context, name: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;<br>旧版本信息：|类名：relationalStore;<br>方法or属性：type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：relationalStore;<br>方法or属性：type ValuesBucket = { [key: string]: ValueType; };<br>旧版本信息：|类名：relationalStore;<br>方法or属性：type ValuesBucket = { [key: string]: ValueType; };<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：StoreConfig;<br>方法or属性：interface StoreConfig<br>旧版本信息：|类名：StoreConfig;<br>方法or属性：interface StoreConfig<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：StoreConfig;<br>方法or属性：name: string;<br>旧版本信息：|类名：StoreConfig;<br>方法or属性：name: string;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：StoreConfig;<br>方法or属性：securityLevel: SecurityLevel;<br>旧版本信息：|类名：StoreConfig;<br>方法or属性：securityLevel: SecurityLevel;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：SecurityLevel;<br>方法or属性：enum SecurityLevel<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：enum SecurityLevel<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：SecurityLevel;<br>方法or属性：S1 = 1<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S1 = 1<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：SecurityLevel;<br>方法or属性：S2 = 2<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S2 = 2<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：SecurityLevel;<br>方法or属性：S3 = 3<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S3 = 3<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：SecurityLevel;<br>方法or属性：S4 = 4<br>旧版本信息：|类名：SecurityLevel;<br>方法or属性：S4 = 4<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：interface RdbStore<br>旧版本信息：|类名：RdbStore;<br>方法or属性：interface RdbStore<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：insert(table: string, values: ValuesBucket): Promise\<number>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：delete(predicates: RdbPredicates): Promise\<number>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：query(predicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：beginTransaction(): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：beginTransaction(): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：commit(): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：commit(): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：rollBack(): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：rollBack(): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：backup(destName: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：backup(destName: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：backup(destName: string): Promise\<void>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：backup(destName: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：restore(srcName: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：restore(srcName: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbStore;<br>方法or属性：restore(srcName: string): Promise\<void>;<br>旧版本信息：|类名：RdbStore;<br>方法or属性：restore(srcName: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：class RdbPredicates<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：class RdbPredicates<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：constructor(name: string);<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：constructor(name: string);<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：equalTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：equalTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：notEqualTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：notEqualTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：beginWrap(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：beginWrap(): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：endWrap(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：endWrap(): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：or(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：or(): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：and(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：and(): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：contains(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：contains(field: string, value: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：beginsWith(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：beginsWith(field: string, value: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：endsWith(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：endsWith(field: string, value: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：isNull(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：isNull(field: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：isNotNull(field: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：like(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：like(field: string, value: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：glob(field: string, value: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：glob(field: string, value: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：between(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：between(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：greaterThan(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：greaterThan(field: string, value: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：lessThan(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：lessThan(field: string, value: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：orderByAsc(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：orderByAsc(field: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：orderByDesc(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：orderByDesc(field: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：distinct(): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：distinct(): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：limitAs(value: number): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：limitAs(value: number): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：offsetAs(rowOffset: number): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：offsetAs(rowOffset: number): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：groupBy(fields: Array\<string>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：groupBy(fields: Array\<string>): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：indexedBy(field: string): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：indexedBy(field: string): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：in(field: string, value: Array\<ValueType>): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：RdbPredicates;<br>方法or属性：notIn(field: string, value: Array\<ValueType>): RdbPredicates;<br>旧版本信息：|类名：RdbPredicates;<br>方法or属性：notIn(field: string, value: Array\<ValueType>): RdbPredicates;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：interface ResultSet<br>旧版本信息：|类名：ResultSet;<br>方法or属性：interface ResultSet<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：columnNames: Array\<string>;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：columnNames: Array\<string>;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：columnCount: number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：columnCount: number;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：rowCount: number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：rowCount: number;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：rowIndex: number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：rowIndex: number;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：isAtFirstRow: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isAtFirstRow: boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：isAtLastRow: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isAtLastRow: boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：isEnded: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isEnded: boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：isStarted: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isStarted: boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：isClosed: boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isClosed: boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：getColumnIndex(columnName: string): number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getColumnIndex(columnName: string): number;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：getColumnName(columnIndex: number): string;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getColumnName(columnIndex: number): string;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：goTo(offset: number): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goTo(offset: number): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：goToRow(position: number): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToRow(position: number): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：goToFirstRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToFirstRow(): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：goToLastRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToLastRow(): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：goToNextRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToNextRow(): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：goToPreviousRow(): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：goToPreviousRow(): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：getBlob(columnIndex: number): Uint8Array;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getBlob(columnIndex: number): Uint8Array;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：getString(columnIndex: number): string;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getString(columnIndex: number): string;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：getLong(columnIndex: number): number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getLong(columnIndex: number): number;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：getDouble(columnIndex: number): number;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：getDouble(columnIndex: number): number;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：isColumnNull(columnIndex: number): boolean;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：isColumnNull(columnIndex: number): boolean;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
|跨平台能力有变化|类名：ResultSet;<br>方法or属性：close(): void;<br>旧版本信息：|类名：ResultSet;<br>方法or属性：close(): void;<br>新版本信息：crossplatform|@ohos.data.relationalStore.d.ts|
