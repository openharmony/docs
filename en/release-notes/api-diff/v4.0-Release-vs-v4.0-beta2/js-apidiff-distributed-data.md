| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: DistributedObject;<br>Method or attribute name: on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DataObject;<br>Method or attribute name: on(type: 'change', callback: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DistributedObject;<br>Method or attribute name: on(<br><br>      type: 'status',<br><br>      callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DataObject;<br>Method or attribute name: on(<br><br>      type: 'status',<br><br>      callback: Callback\<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DistributedObject;<br>Method or attribute name: off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DataObject;<br>Method or attribute name: off(type: 'change', callback?: Callback\<{ sessionId: string, fields: Array\<string> }>): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DistributedObject;<br>Method or attribute name: off(<br><br>      type: 'status',<br><br>      callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: DataObject;<br>Method or attribute name: off(<br><br>      type: 'status',<br><br>      callback?: Callback\<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }><br><br>    ): void;|NA|@ohos.data.distributedDataObject.d.ts|
|Deleted|Class name: Preferences;<br>Method or attribute name: on(type: 'change', callback: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|Deleted|Class name: Preferences;<br>Method or attribute name: on(type: 'multiProcessChange', callback: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|Deleted|Class name: Preferences;<br>Method or attribute name: off(type: 'change', callback?: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|Deleted|Class name: Preferences;<br>Method or attribute name: off(type: 'multiProcessChange', callback?: Callback\<{ key: string }>): void;|NA|@ohos.data.preferences.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: type Options = {<br>    /**<br>     * indicates the target Intention<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    intention?: Intention;<br><br>    /**<br>     * indicates the unique identifier of target UnifiedData<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    key?: string;<br>  };|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function insertData(options: Options, data: UnifiedData): Promise\<string>;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function updateData(options: Options, data: UnifiedData): Promise\<void>;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function queryData(options: Options): Promise\<Array\<UnifiedData>>;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UDMF;<br>Method or attribute name: function deleteData(options: Options): Promise\<Array\<UnifiedData>>;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: TEXT = 'Text'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: PLAIN_TEXT = 'Text.PlainText'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: HYPERLINK = 'Text.Hyperlink'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: HTML = 'Text.HTML'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: FILE = 'File'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: IMAGE = 'File.Media.Image'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: VIDEO = 'File.Media.Video'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: AUDIO = 'File.Media.Audio'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: FOLDER = 'File.Folder'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: SYSTEM_DEFINED_RECORD = 'SystemDefinedType'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: SYSTEM_DEFINED_FORM = 'SystemDefinedType.Form'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: SYSTEM_DEFINED_APP_ITEM = 'SystemDefinedType.AppItem'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: SYSTEM_DEFINED_PIXEL_MAP = 'SystemDefinedType.PixelMap'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedDataType;<br>Method or attribute name: APPLICATION_DEFINED_RECORD = 'ApplicationDefinedType'|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedData;<br>Method or attribute name: constructor(record: UnifiedRecord);|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedData;<br>Method or attribute name: addRecord(record: UnifiedRecord): void;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedData;<br>Method or attribute name: getRecords(): Array\<UnifiedRecord>;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Summary;<br>Method or attribute name: summary: { [key: string]: number };|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Summary;<br>Method or attribute name: totalSize: number;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: UnifiedRecord;<br>Method or attribute name: getType(): string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Text;<br>Method or attribute name: details?: { [key: string]: string };|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: File;<br>Method or attribute name: details?: { [key: string]: string };|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: PlainText;<br>Method or attribute name: textContent: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: PlainText;<br>Method or attribute name: abstract?: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Hyperlink;<br>Method or attribute name: url: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Hyperlink;<br>Method or attribute name: description?: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: HTML;<br>Method or attribute name: htmlContent: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: HTML;<br>Method or attribute name: plainContent?: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: File;<br>Method or attribute name: uri: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Image;<br>Method or attribute name: imageUri: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Video;<br>Method or attribute name: videoUri: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Audio;<br>Method or attribute name: audioUri: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Folder;<br>Method or attribute name: folderUri: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedRecord;<br>Method or attribute name: details?: { [key: string]: number \| string \| Uint8Array };|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedForm;<br>Method or attribute name: formId: number;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedForm;<br>Method or attribute name: formName: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedForm;<br>Method or attribute name: bundleName: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedAppItem;<br>Method or attribute name: bundleName: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedForm;<br>Method or attribute name: abilityName: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedAppItem;<br>Method or attribute name: abilityName: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedForm;<br>Method or attribute name: module: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedAppItem;<br>Method or attribute name: appId: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedAppItem;<br>Method or attribute name: appName: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedAppItem;<br>Method or attribute name: appIconId: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedAppItem;<br>Method or attribute name: appLabelId: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: SystemDefinedPixelMap;<br>Method or attribute name: rawData: Uint8Array;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: ApplicationDefinedRecord;<br>Method or attribute name: rawData: Uint8Array;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: ApplicationDefinedRecord;<br>Method or attribute name: applicationDefinedType: string;|NA|@ohos.data.UDMF.d.ts|
|Deleted|Class name: Intention;<br>Method or attribute name: DATA_HUB = 'DataHub'|NA|@ohos.data.UDMF.d.ts|
|Added|NA|Class name: DistributedObject;<br>Method or attribute name: on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DataObject;<br>Method or attribute name: on(type: 'change', callback: (sessionId: string, fields: Array\<string>) => void ): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DistributedObject;<br>Method or attribute name: on(<br><br>      type: 'status',<br><br>      callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DataObject;<br>Method or attribute name: on(<br><br>      type: 'status',<br><br>      callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DistributedObject;<br>Method or attribute name: off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DataObject;<br>Method or attribute name: off(type: 'change', callback?: (sessionId: string, fields: Array\<string>) => void ): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DistributedObject;<br>Method or attribute name: off(<br><br>      type: 'status',<br><br>      callback?: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: DataObject;<br>Method or attribute name: off(<br><br>      type: 'status',<br><br>      callback?: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void<br><br>    ): void;|@ohos.data.distributedDataObject.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function getPreferencesSync(context: Context, options: Options): Preferences;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: preferences;<br>Method or attribute name: function removePreferencesFromCacheSync(context: Context, options: Options): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: on(type: 'change', callback: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: on(type: 'multiProcessChange', callback: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: off(type: 'change', callback?: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: Preferences;<br>Method or attribute name: off(type: 'multiProcessChange', callback?: (key: string) => void): void;|@ohos.data.preferences.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: type Options = {<br>    /**<br>     * Indicates the target Intention<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    intention?: Intention;<br><br>    /**<br>     * Indicates the unique identifier of target UnifiedData<br>     *<br>     * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>     * @since 10<br>     */<br>    key?: string;<br>  };|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function insertData(options: Options, data: UnifiedData): Promise\<string>;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function updateData(options: Options, data: UnifiedData): Promise\<void>;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function queryData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: unifiedDataChannel;<br>Method or attribute name: function deleteData(options: Options): Promise\<Array\<UnifiedData>>;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: UnifiedData;<br>Method or attribute name: constructor(record: UnifiedRecord);|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: UnifiedData;<br>Method or attribute name: addRecord(record: UnifiedRecord): void;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: UnifiedData;<br>Method or attribute name: getRecords(): Array\<UnifiedRecord>;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Summary;<br>Method or attribute name: summary: { [key: string]: number };|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Summary;<br>Method or attribute name: totalSize: number;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: UnifiedRecord;<br>Method or attribute name: getType(): string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Text;<br>Method or attribute name: details?: { [key: string]: string };|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: File;<br>Method or attribute name: details?: { [key: string]: string };|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: PlainText;<br>Method or attribute name: textContent: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: PlainText;<br>Method or attribute name: abstract?: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Hyperlink;<br>Method or attribute name: url: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Hyperlink;<br>Method or attribute name: description?: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: HTML;<br>Method or attribute name: htmlContent: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: HTML;<br>Method or attribute name: plainContent?: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: File;<br>Method or attribute name: uri: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: imageUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Video;<br>Method or attribute name: videoUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Audio;<br>Method or attribute name: audioUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Folder;<br>Method or attribute name: folderUri: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedRecord;<br>Method or attribute name: details?: { [key: string]: number \| string \| Uint8Array };|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedForm;<br>Method or attribute name: formId: number;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedForm;<br>Method or attribute name: formName: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedForm;<br>Method or attribute name: bundleName: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedAppItem;<br>Method or attribute name: bundleName: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedForm;<br>Method or attribute name: abilityName: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedAppItem;<br>Method or attribute name: abilityName: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedForm;<br>Method or attribute name: module: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedAppItem;<br>Method or attribute name: appId: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedAppItem;<br>Method or attribute name: appName: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedAppItem;<br>Method or attribute name: appIconId: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedAppItem;<br>Method or attribute name: appLabelId: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: SystemDefinedPixelMap;<br>Method or attribute name: rawData: Uint8Array;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: ApplicationDefinedRecord;<br>Method or attribute name: rawData: Uint8Array;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: ApplicationDefinedRecord;<br>Method or attribute name: applicationDefinedType: string;|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: Intention;<br>Method or attribute name: DATA_HUB = 'DataHub'|@ohos.data.unifiedDataChannel.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: TEXT = 'general.text'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: PLAIN_TEXT = 'general.plain-text'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: HYPERLINK = 'general.hyperlink'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: HTML = 'general.html'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: FILE = 'general.file'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: IMAGE = 'general.image'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: VIDEO = 'general.video'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: AUDIO = 'general.audio'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: FOLDER = 'general.folder'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: OPENHARMONY_FORM = 'openharmony.form'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: OPENHARMONY_APP_ITEM = 'openharmony.app-item'|@ohos.data.uniformTypeDescriptor.d.ts|
|Added|NA|Class name: UniformDataType;<br>Method or attribute name: OPENHARMONY_PIXEL_MAP = 'openharmony.pixel-map'|@ohos.data.uniformTypeDescriptor.d.ts|
