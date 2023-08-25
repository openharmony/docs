| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：Action;<br>方法or属性：CLEAR_CLOUD_INFO|NA|@ohos.data.cloudData.d.ts|
|删除|类名：Action;<br>方法or属性：CLEAR_CLOUD_DATA_AND_INFO|NA|@ohos.data.cloudData.d.ts|
|新增|NA|类名：ClearAction;<br>方法or属性：CLEAR_CLOUD_INFO|@ohos.data.cloudData.d.ts|
|新增|NA|类名：ClearAction;<br>方法or属性：CLEAR_CLOUD_DATA_AND_INFO|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static clear(<br>      accountId: string,<br>      appActions: { [bundleName: string]: ClearAction },<br>      callback: AsyncCallback\<void><br>    ): void;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：Config;<br>方法or属性：static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise\<void>;|@ohos.data.cloudData.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferences(context: Context, options: Options, callback: AsyncCallback\<Preferences>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferences(context: Context, options: Options): Promise\<Preferences>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, options: Options, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function deletePreferences(context: Context, options: Options): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, options: Options, callback: AsyncCallback\<void>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCache(context: Context, options: Options): Promise\<void>;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCacheSync(context: Context, name: string): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Options;<br>方法or属性：name: string;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Options;<br>方法or属性：dataGroupId?: string;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：getSync(key: string, defValue: ValueType): ValueType;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：getAllSync(): Object;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：hasSync(key: string): boolean;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：putSync(key: string, value: ValueType): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：deleteSync(key: string): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：clearSync(): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：on(type: 'multiProcessChange', callback: Callback\<{ key: string }>): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：off(type: 'multiProcessChange', callback?: Callback\<{ key: string }>): void;|@ohos.data.preferences.d.ts|
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
|新增|NA|类名：Asset;<br>方法or属性：name: string;|@ohos.data.relationalStore.d.ts|
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
|新增|NA|类名：ResultSet;<br>方法or属性：getAsset(columnIndex: number): Asset;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：ResultSet;<br>方法or属性：getAssets(columnIndex: number): Assets;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise\<ModifyTime>;|@ohos.data.relationalStore.d.ts|
|新增|NA|类名：RdbStore;<br>方法or属性：getModifyTime(<br>      table: string,<br>      columnName: string,<br>      primaryKeys: PRIKeyType[],<br>      callback: AsyncCallback\<ModifyTime><br>    ): void;|@ohos.data.relationalStore.d.ts|
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
|新增|NA|类名：UDMF;<br>方法or属性：type Options = {<br>    /**<br>     * indicates the target Intention<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    intention?: Intention;<br><br>    /**<br>     * indicates the unique identifier of target UnifiedData<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    key?: string;<br>  };|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function insertData(options: Options, data: UnifiedData): Promise\<string>;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function updateData(options: Options, data: UnifiedData): Promise\<void>;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function queryData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UDMF;<br>方法or属性：function deleteData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：UnifiedDataType;<br>方法or属性：AUDIO = 'File.Media.Audio'|@ohos.data.UDMF.d.ts|
|新增|NA|类名：Audio;<br>方法or属性：audioUri: string;|@ohos.data.UDMF.d.ts|
|新增|NA|类名：Intention;<br>方法or属性：DATA_HUB = 'DataHub'|@ohos.data.UDMF.d.ts|
|错误码有变化|类名：DataAbilityPredicates;<br>方法or属性：limitAs(value: number): DataAbilityPredicates;<br>旧版本信息：IllegalPredicateException|类名：DataAbilityPredicates;<br>方法or属性：limitAs(value: number): DataAbilityPredicates;<br>新版本信息：|@ohos.data.dataAbility.d.ts|
|错误码有变化|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>旧版本信息：401,14800000,14800010,14800011|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void;<br>新版本信息：401,14800000,14800010,14800011,14801001,14801002|@ohos.data.relationalStore.d.ts|
|错误码有变化|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>旧版本信息：401,14800000,14800010,14800011|类名：relationalStore;<br>方法or属性：function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>;<br>新版本信息：401,14800000,14800010,14800011,14801001,14801002|@ohos.data.relationalStore.d.ts|
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
|type有变化|类名：DataShareExtensionAbility;<br>方法or属性：context: ExtensionContext;<br>旧版本信息：|类名：DataShareExtensionAbility;<br>方法or属性：context: ExtensionContext;<br>新版本信息：ExtensionContext|@ohos.application.DataShareExtensionAbility.d.ts|
|函数有变化|类名：DataShareExtensionAbility;<br>方法or属性：context?: ExtensionContext;|类名：DataShareExtensionAbility;<br>方法or属性：context: ExtensionContext;|@ohos.application.DataShareExtensionAbility.d.ts|
|函数有变化|类名：PublishedItem;<br>方法or属性：data: string \| Ashmem;|类名：PublishedItem;<br>方法or属性：data: string \| ArrayBuffer;|@ohos.data.dataShare.d.ts|
|函数有变化|类名：relationalStore;<br>方法or属性：type ValueType = null \| number \| string \| boolean \| Uint8Array;|类名：relationalStore;<br>方法or属性：type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;|@ohos.data.relationalStore.d.ts|
