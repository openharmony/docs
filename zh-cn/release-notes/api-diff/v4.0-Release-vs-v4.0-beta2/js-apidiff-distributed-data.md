| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：DistributedObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DistributedObject;<br>方法or属性：on(<br><br>      type: 'status',<br><br>      callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：on(<br><br>      type: 'status',<br><br>      callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DistributedObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DistributedObject;<br>方法or属性：off(<br><br>      type: 'status',<br><br>      callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：DataObject;<br>方法or属性：off(<br><br>      type: 'status',<br><br>      callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|删除|类名：Preferences;<br>方法or属性：on(type: 'change', callback: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|删除|类名：Preferences;<br>方法or属性：on(type: 'multiProcessChange', callback: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|删除|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|删除|类名：Preferences;<br>方法or属性：off(type: 'multiProcessChange', callback?: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|删除|类名：UDMF;<br>方法or属性：type Options = {<br>    /**<br>     * indicates the target Intention<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    intention?: Intention;<br><br>    /**<br>     * indicates the unique identifier of target UnifiedData<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    key?: string;<br>  };|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function insertData(options: Options, data: UnifiedData): Promise\<string>;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function updateData(options: Options, data: UnifiedData): Promise\<void>;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function queryData(options: Options): Promise\<Array\<UnifiedData>>;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UDMF;<br>方法or属性：function deleteData(options: Options): Promise\<Array\<UnifiedData>>;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：TEXT = 'Text'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：PLAIN_TEXT = 'Text.PlainText'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：HYPERLINK = 'Text.Hyperlink'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：HTML = 'Text.HTML'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：FILE = 'File'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：IMAGE = 'File.Media.Image'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：VIDEO = 'File.Media.Video'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：AUDIO = 'File.Media.Audio'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：FOLDER = 'File.Folder'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：SYSTEM_DEFINED_RECORD = 'SystemDefinedType'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：SYSTEM_DEFINED_FORM = 'SystemDefinedType.Form'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：SYSTEM_DEFINED_APP_ITEM = 'SystemDefinedType.AppItem'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：SYSTEM_DEFINED_PIXEL_MAP = 'SystemDefinedType.PixelMap'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedDataType;<br>方法or属性：APPLICATION_DEFINED_RECORD = 'ApplicationDefinedType'|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedData;<br>方法or属性：constructor(record: UnifiedRecord);|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedData;<br>方法or属性：addRecord(record: UnifiedRecord): void;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedData;<br>方法or属性：getRecords(): Array\<UnifiedRecord>;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Summary;<br>方法or属性：summary: { [key: string]: number };|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Summary;<br>方法or属性：totalSize: number;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：UnifiedRecord;<br>方法or属性：getType(): string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Text;<br>方法or属性：details?: { [key: string]: string };|NA|@ohos.data.UDMF.d.ts|
|删除|类名：File;<br>方法or属性：details?: { [key: string]: string };|NA|@ohos.data.UDMF.d.ts|
|删除|类名：PlainText;<br>方法or属性：textContent: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：PlainText;<br>方法or属性：abstract?: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Hyperlink;<br>方法or属性：url: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Hyperlink;<br>方法or属性：description?: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：HTML;<br>方法or属性：htmlContent: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：HTML;<br>方法or属性：plainContent?: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：File;<br>方法or属性：uri: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Image;<br>方法or属性：imageUri: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Video;<br>方法or属性：videoUri: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Audio;<br>方法or属性：audioUri: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Folder;<br>方法or属性：folderUri: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedRecord;<br>方法or属性：details?: { [key: string]: number \| string \| Uint8Array };|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedForm;<br>方法or属性：formId: number;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedForm;<br>方法or属性：formName: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedForm;<br>方法or属性：bundleName: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedAppItem;<br>方法or属性：bundleName: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedForm;<br>方法or属性：abilityName: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedAppItem;<br>方法or属性：abilityName: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedForm;<br>方法or属性：module: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedAppItem;<br>方法or属性：appId: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedAppItem;<br>方法or属性：appName: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedAppItem;<br>方法or属性：appIconId: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedAppItem;<br>方法or属性：appLabelId: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：SystemDefinedPixelMap;<br>方法or属性：rawData: Uint8Array;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：ApplicationDefinedRecord;<br>方法or属性：rawData: Uint8Array;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：ApplicationDefinedRecord;<br>方法or属性：applicationDefinedType: string;|NA|@ohos.data.UDMF.d.ts|
|删除|类名：Intention;<br>方法or属性：DATA_HUB = 'DataHub'|NA|@ohos.data.UDMF.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：on(<br><br>      type: 'status',<br><br>      callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：on(<br><br>      type: 'status',<br><br>      callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DistributedObject;<br>方法or属性：off(<br><br>      type: 'status',<br><br>      callback?: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：DataObject;<br>方法or属性：off(<br><br>      type: 'status',<br><br>      callback?: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function getPreferencesSync(context: Context, options: Options): Preferences;|@ohos.data.preferences.d.ts|
|新增|NA|类名：preferences;<br>方法or属性：function removePreferencesFromCacheSync(context: Context, options: Options): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：on(type: 'change', callback: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：on(type: 'multiProcessChange', callback: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：off(type: 'change', callback?: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|新增|NA|类名：Preferences;<br>方法or属性：off(type: 'multiProcessChange', callback?: (key: string) => void): void;|@ohos.data.preferences.d.ts|
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
