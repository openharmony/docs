| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: Action;<br>Method or attribute name: CLEAR_CLOUD_INFO|NA|@ohos.data.cloudData.d.ts|
|Deleted|Class name: Action;<br>Method or attribute name: CLEAR_CLOUD_DATA_AND_INFO|NA|@ohos.data.cloudData.d.ts|
|Added|NA|Class name: ClearAction;<br>Method or attribute name: CLEAR_CLOUD_INFO|@ohos.data.cloudData.d.ts|
|Added|NA|Class name: ClearAction;<br>Method or attribute name: CLEAR_CLOUD_DATA_AND_INFO|@ohos.data.cloudData.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: static clear(<br>      accountId: string,<br>      appActions: { [bundleName: string]: ClearAction },<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.cloudData.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise\<void>;|@ohos.data.cloudData.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function getPreferences(context: Context, options: Options, callback: AsyncCallback\<Preferences>): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function getPreferences(context: Context, options: Options): Promise\<Preferences>;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function deletePreferences(context: Context, options: Options, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function deletePreferences(context: Context, options: Options): Promise\<void>;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function removePreferencesFromCache(context: Context, options: Options, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function removePreferencesFromCache(context: Context, options: Options): Promise\<void>;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function removePreferencesFromCacheSync(context: Context, name: string): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Options;<br>Method or attribute name: name: string;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Options;<br>Method or attribute name: dataGroupId?: string;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: getSync(key: string, defValue: ValueType): ValueType;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: getAllSync(): Object;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: hasSync(key: string): boolean;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: putSync(key: string, value: ValueType): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: deleteSync(key: string): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: clearSync(): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: on(type: 'multiProcessChange', callback: Callback\<{ key: string }>): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: off(type: 'multiProcessChange', callback?: Callback\<{ key: string }>): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: relationalStore;<br>Method or attribute name: type Assets = Asset[];|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: relationalStore;<br>Method or attribute name: type PRIKeyType = number \| string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: relationalStore;<br>Method or attribute name: type UTCTime = Date;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: relationalStore;<br>Method or attribute name: type ModifyTime = Map\<PRIKeyType, UTCTime>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: relationalStore;<br>Method or attribute name: function deleteRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: relationalStore;<br>Method or attribute name: function deleteRdbStore(context: Context, config: StoreConfig): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: AssetStatus;<br>Method or attribute name: ASSET_NORMAL|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: AssetStatus;<br>Method or attribute name: ASSET_INSERT|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: AssetStatus;<br>Method or attribute name: ASSET_UPDATE|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: AssetStatus;<br>Method or attribute name: ASSET_DELETE|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: AssetStatus;<br>Method or attribute name: ASSET_ABNORMAL|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: AssetStatus;<br>Method or attribute name: ASSET_DOWNLOADING|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: name: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: uri: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: path: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: createTime: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: modifyTime: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: size: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Asset;<br>Method or attribute name: status?: AssetStatus;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: StoreConfig;<br>Method or attribute name: dataGroupId?: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: SYNC_BEGIN|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: SYNC_IN_PROGRESS|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: SYNC_FINISH|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Statistic;<br>Method or attribute name: total: number;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Statistic;<br>Method or attribute name: successful: number;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Statistic;<br>Method or attribute name: failed: number;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: Statistic;<br>Method or attribute name: remained: number;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: TableDetails;<br>Method or attribute name: upload: Statistic;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: TableDetails;<br>Method or attribute name: download: Statistic;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: SUCCESS|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: UNKNOWN_ERROR|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: NETWORK_ERROR|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: CLOUD_DISABLED|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: LOCKED_BY_OTHERS|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: RECORD_LIMIT_EXCEEDED|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressCode;<br>Method or attribute name: NO_SPACE_FOR_ASSET|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressDetails;<br>Method or attribute name: schedule: Progress;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressDetails;<br>Method or attribute name: code: ProgressCode;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ProgressDetails;<br>Method or attribute name: details: {<br>      [table: string]: TableDetails;<br>    };|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: SyncMode;<br>Method or attribute name: SYNC_MODE_TIME_FIRST|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: SyncMode;<br>Method or attribute name: SYNC_MODE_NATIVE_FIRST|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: SyncMode;<br>Method or attribute name: SYNC_MODE_CLOUD_FIRST|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: SubscribeType;<br>Method or attribute name: SUBSCRIBE_TYPE_CLOUD_DETAILS|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeType;<br>Method or attribute name: DATA_CHANGE|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeType;<br>Method or attribute name: ASSET_CHANGE|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeInfo;<br>Method or attribute name: table: string;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeInfo;<br>Method or attribute name: type: ChangeType;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeInfo;<br>Method or attribute name: inserted: Array\<string> \| Array\<number>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeInfo;<br>Method or attribute name: updated: Array\<string> \| Array\<number>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ChangeInfo;<br>Method or attribute name: deleted: Array\<string> \| Array\<number>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: DistributedType;<br>Method or attribute name: DISTRIBUTED_DEVICE|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: DistributedType;<br>Method or attribute name: DISTRIBUTED_CLOUD|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: DistributedConfig;<br>Method or attribute name: autoSync: boolean;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ResultSet;<br>Method or attribute name: getAsset(columnIndex: number): Asset;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: ResultSet;<br>Method or attribute name: getAssets(columnIndex: number): Assets;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise\<ModifyTime>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: getModifyTime(<br>      table: string,<br>      columnName: string,<br>      primaryKeys: PRIKeyType[],<br>      callback: AsyncCallback\<ModifyTime><br>    ): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: setDistributedTables(tables: Array\<string>, type: DistributedType, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: setDistributedTables(<br>      tables: Array\<string>,<br>      type: DistributedType,<br>      config: DistributedConfig,<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: setDistributedTables(tables: Array\<string>, type?: DistributedType, config?: DistributedConfig): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: cloudSync(mode: SyncMode, progress: Callback\<ProgressDetails>, callback: AsyncCallback\<void>): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: cloudSync(mode: SyncMode, progress: Callback\<ProgressDetails>): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: cloudSync(<br>      mode: SyncMode,<br>      tables: string[],<br>      progress: Callback\<ProgressDetails>,<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: cloudSync(mode: SyncMode, tables: string[], progress: Callback\<ProgressDetails>): Promise\<void>;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>> \| Callback\<Array\<ChangeInfo>>): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: on(event: string, interProcess: boolean, observer: Callback\<void>): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: off(<br>      event: 'dataChange',<br>      type: SubscribeType,<br>      observer?: Callback\<Array\<string>> \| Callback\<Array\<ChangeInfo>><br>    ): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: off(event: string, interProcess: boolean, observer?: Callback\<void>): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: RdbStore;<br>Method or attribute name: emit(event: string): void;|@ohos.data.relationalStore.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: type Options = {<br>    /**<br>     * indicates the target Intention<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    intention?: Intention;<br><br>    /**<br>     * indicates the unique identifier of target UnifiedData<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    key?: string;<br>  };|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function insertData(options: Options, data: UnifiedData): Promise\<string>;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function updateData(options: Options, data: UnifiedData): Promise\<void>;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function queryData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UDMF;<br>Method or attribute name: function deleteData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: UnifiedDataType;<br>Method or attribute name: AUDIO = 'File.Media.Audio'|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: Audio;<br>Method or attribute name: audioUri: string;|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: Intention;<br>Method or attribute name: DATA_HUB = 'DataHub'|@ohos.data.UDMF.d.ts|
|Error code changed|Class name: DataAbilityPredicates;<br>Method or attribute name: limitAs(value: number): DataAbilityPredicates;<br>Old version information: IllegalPredicateException|Class name: DataAbilityPredicates;<br>Method or attribute name: limitAs(value: number): DataAbilityPredicates;<br>New version information: |@ohos.data.dataAbility.d.ts|
|Error code changed|Class name: relationalStore;<br>Method or attribute name: function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>Old version information: 401,14800000,14800010,14800011|Class name: relationalStore;<br>Method or attribute name: function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>New version information: 401,14800000,14800010,14800011,14801001,14801002|@ohos.data.relationalStore.d.ts|
|Error code changed|Class name: relationalStore;<br>Method or attribute name: function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>Old version information: 401,14800000,14800010,14800011|Class name: relationalStore;<br>Method or attribute name: function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>New version information: 401,14800000,14800010,14800011,14801001,14801002|@ohos.data.relationalStore.d.ts|
|Access level changed|Class name: dataSharePredicates;<br>Method or attribute name: declare dataSharePredicates<br>Old version information: systemapi|Class name: dataSharePredicates;<br>Method or attribute name: declare dataSharePredicates<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: class DataSharePredicates<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: class DataSharePredicates<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: equalTo(field: string, value: ValueType): DataSharePredicates;<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: equalTo(field: string, value: ValueType): DataSharePredicates;<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: and(): DataSharePredicates;<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: and(): DataSharePredicates;<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: orderByAsc(field: string): DataSharePredicates;<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: orderByAsc(field: string): DataSharePredicates;<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: orderByDesc(field: string): DataSharePredicates;<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: orderByDesc(field: string): DataSharePredicates;<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: limit(total: number, offset: number): DataSharePredicates;<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: limit(total: number, offset: number): DataSharePredicates;<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: DataSharePredicates;<br>Method or attribute name: in(field: string, value: Array\<ValueType>): DataSharePredicates;<br>Old version information: systemapi|Class name: DataSharePredicates;<br>Method or attribute name: in(field: string, value: Array\<ValueType>): DataSharePredicates;<br>New version information: |@ohos.data.dataSharePredicates.d.ts|
|Access level changed|Class name: sourcefile;<br>Method or attribute name: export type ValueType = number \| string \| boolean;<br>Old version information: systemapi|Class name: sourcefile;<br>Method or attribute name: export type ValueType = number \| string \| boolean;<br>New version information: |@ohos.data.ValuesBucket.d.ts|
|Access level changed|Class name: sourcefile;<br>Method or attribute name: export type ValuesBucket = {<br><br>  [key: string]: ValueType \| Uint8Array \| null;<br><br>};<br>Old version information: systemapi|Class name: sourcefile;<br>Method or attribute name: export type ValuesBucket = {<br><br>  [key: string]: ValueType \| Uint8Array \| null;<br><br>};<br>New version information: |@ohos.data.ValuesBucket.d.ts|
|Type changed|Class name: DataShareExtensionAbility;<br>Method or attribute name: context: ExtensionContext;<br>Old version information: |Class name: DataShareExtensionAbility;<br>Method or attribute name: context: ExtensionContext;<br>New version information: ExtensionContext|@ohos.application.DataShareExtensionAbility.d.ts|
|Function changed|Class name: DataShareExtensionAbility;<br>Method or attribute name: context?: ExtensionContext;|Class name: DataShareExtensionAbility;<br>Method or attribute name: context: ExtensionContext;|@ohos.application.DataShareExtensionAbility.d.ts|
|Function changed|Class name: PublishedItem;<br>Method or attribute name: data: string \| Ashmem;|Class name: PublishedItem;<br>Method or attribute name: data: string \| ArrayBuffer;|@ohos.data.dataShare.d.ts|
|Function changed|Class name: relationalStore;<br>Method or attribute name: type ValueType = null \| number \| string \| boolean \| Uint8Array;|Class name: relationalStore;<br>Method or attribute name: type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;|@ohos.data.relationalStore.d.ts|
