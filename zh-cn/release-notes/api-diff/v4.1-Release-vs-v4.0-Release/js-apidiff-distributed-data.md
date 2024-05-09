| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：SystemCapability.DistributedDataManager.DataObject.DistributedObject|api/@ohos.data.distributedDataObject.d.ts|
|syscap变更|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：SystemCapability.DistributedDataManager.DataObject.DistributedObject|api/@ohos.data.distributedDataObject.d.ts|
|syscap变更|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：SystemCapability.DistributedDataManager.DataObject.DistributedObject|api/@ohos.data.distributedDataObject.d.ts|
|错误码变更|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：15400001,201,401|api/@ohos.data.distributedDataObject.d.ts|
|错误码变更|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：15400001,201,401|api/@ohos.data.distributedDataObject.d.ts|
|错误码变更|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：15400001,201,401|api/@ohos.data.distributedDataObject.d.ts|
|权限变更|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：ohos.permission.DISTRIBUTED_DATASYNC|api/@ohos.data.distributedDataObject.d.ts|
|权限变更|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：ohos.permission.DISTRIBUTED_DATASYNC|api/@ohos.data.distributedDataObject.d.ts|
|权限变更|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：ohos.permission.DISTRIBUTED_DATASYNC|api/@ohos.data.distributedDataObject.d.ts|
|函数变更|类名：Preferences；<br>API声明：on(type: 'change', callback: (key: string) => void): void;<br>差异内容：callback: (key: string) => void|类名：Preferences；<br>API声明：on(type: 'change', callback: Callback\<string>): void;<br>差异内容：callback: Callback\<string>|api/@ohos.data.preferences.d.ts|
|函数变更|类名：Preferences；<br>API声明：on(type: 'multiProcessChange', callback: (key: string) => void): void;<br>差异内容：callback: (key: string) => void|类名：Preferences；<br>API声明：on(type: 'multiProcessChange', callback: Callback\<string>): void;<br>差异内容：callback: Callback\<string>|api/@ohos.data.preferences.d.ts|
|函数变更|类名：Preferences；<br>API声明：off(type: 'change', callback?: (key: string) => void): void;<br>差异内容：callback?: (key: string) => void|类名：Preferences；<br>API声明：off(type: 'change', callback?: Callback\<string>): void;<br>差异内容：callback?: Callback\<string>|api/@ohos.data.preferences.d.ts|
|函数变更|类名：Preferences；<br>API声明：off(type: 'multiProcessChange', callback?: (key: string) => void): void;<br>差异内容：callback?: (key: string) => void|类名：Preferences；<br>API声明：off(type: 'multiProcessChange', callback?: Callback\<string>): void;<br>差异内容：callback?: Callback\<string>|api/@ohos.data.preferences.d.ts|
|属性变更|类名：ProgressDetails；<br>API声明：details: {<br>            [table: string]: TableDetails;<br>        };<br>差异内容：{<br>            [table: string]: TableDetails;<br>        }|类名：ProgressDetails；<br>API声明：details: Record\<string, TableDetails>;<br>差异内容：Record\<string, TableDetails>|api/@ohos.data.relationalStore.d.ts|
|属性变更|类名：Summary；<br>API声明：summary: {<br>            [key: string]: number;<br>        };<br>差异内容：{<br>            [key: string]: number;<br>        }|类名：Summary；<br>API声明：summary: Record\<string, number>;<br>差异内容：Record\<string, number>|api/@ohos.data.unifiedDataChannel.d.ts|
|属性变更|类名：Text；<br>API声明：details?: {<br>            [key: string]: string;<br>        };<br>差异内容：{<br>            [key: string]: string;<br>        }|类名：Text；<br>API声明：details?: Record\<string, string>;<br>差异内容：Record\<string, string>|api/@ohos.data.unifiedDataChannel.d.ts|
|属性变更|类名：File；<br>API声明：details?: {<br>            [key: string]: string;<br>        };<br>差异内容：{<br>            [key: string]: string;<br>        }|类名：File；<br>API声明：details?: Record\<string, string>;<br>差异内容：Record\<string, string>|api/@ohos.data.unifiedDataChannel.d.ts|
|属性变更|类名：Options；<br>API声明：dataGroupId?: string;<br>差异内容：string|类名：Options；<br>API声明：dataGroupId?: string \| null \| undefined;<br>差异内容：string,null,undefined|api/@ohos.data.preferences.d.ts|
|属性变更|类名：SystemDefinedRecord；<br>API声明：details?: {<br>            [key: string]: number \| string \| Uint8Array;<br>        };<br>差异内容：{<br>            [key: string]: number \| string \| Uint8Array;<br>        }|类名：SystemDefinedRecord；<br>API声明：details?: Record\<string, number \| string \| Uint8Array>;<br>差异内容：Record\<string, number \| string \| Uint8Array>|api/@ohos.data.unifiedDataChannel.d.ts|
|自定义类型变更|类名：relationalStore；<br>API声明：type ValuesBucket = {<br>        [key: string]: ValueType;<br>    };<br>差异内容：{<br>        [key: string]: ValueType;<br>    }|类名：relationalStore；<br>API声明：type ValuesBucket = Record\<string, ValueType>;<br>差异内容：Record\<string, ValueType>|api/@ohos.data.relationalStore.d.ts|
|自定义类型变更|类名：unifiedDataChannel；<br>API声明：type Options = {<br>        /**<br>         * Indicates the target Intention<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        intention?: Intention;<br>        /**<br>         * Indicates the unique identifier of target UnifiedData<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        key?: string;<br>    };<br>差异内容：{<br>        /**<br>         * Indicates the target Intention<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        intention?: Intention;<br>        /**<br>         * Indicates the unique identifier of target UnifiedData<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        key?: string;<br>    }|类名：unifiedDataChannel；<br>API声明：type Options = {<br>        /**<br>         * Indicates the target Intention<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        /**<br>         * Indicates the target Intention<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @atomicservice<br>         * @since 11<br>         */<br>        intention?: Intention;<br>        /**<br>         * Indicates the unique identifier of target UnifiedData<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        /**<br>         * Indicates the unique identifier of target UnifiedData<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @atomicservice<br>         * @since 11<br>         */<br>        key?: string;<br>    };<br>差异内容：{<br>        /**<br>         * Indicates the target Intention<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        /**<br>         * Indicates the target Intention<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @atomicservice<br>         * @since 11<br>         */<br>        intention?: Intention;<br>        /**<br>         * Indicates the unique identifier of target UnifiedData<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @since 10<br>         */<br>        /**<br>         * Indicates the unique identifier of target UnifiedData<br>         *<br>         * @syscap SystemCapability.DistributedDataManager.UDMF.Core<br>         * @atomicservice<br>         * @since 11<br>         */<br>        key?: string;<br>    }|api/@ohos.data.unifiedDataChannel.d.ts|
|自定义类型变更|类名：preferences；<br>API声明：type ValueType = number \| string \| boolean \| Array\<number> \| Array\<string> \| Array\<boolean>;<br>差异内容：number,string,boolean,Array\<number>,Array\<string>,Array\<boolean>|类名：preferences；<br>API声明：type ValueType = number \| string \| boolean \| Array\<number> \| Array\<string> \| Array\<boolean> \| Uint8Array;<br>差异内容：number,string,boolean,Array\<number>,Array\<string>,Array\<boolean>,Uint8Array|api/@ohos.data.preferences.d.ts|
|自定义类型变更|类名：global；<br>API声明：export type ValuesBucket = {<br>    [key: string]: ValueType \| Uint8Array \| null;<br>};<br>差异内容：{<br>    [key: string]: ValueType \| Uint8Array \| null;<br>}|类名：global；<br>API声明：export type ValuesBucket = Record\<string, ValueType \| Uint8Array \| null>;<br>差异内容：Record\<string, ValueType \| Uint8Array \| null>|api/@ohos.data.ValuesBucket.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace cloudExtension<br>差异内容： declare namespace cloudExtension|api/@ohos.data.cloudExtension.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace commonType<br>差异内容： declare namespace commonType|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：commonType；<br>API声明： enum AssetStatus<br>差异内容： enum AssetStatus|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：AssetStatus；<br>API声明：ASSET_NORMAL<br>差异内容：ASSET_NORMAL|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：AssetStatus；<br>API声明：ASSET_INSERT<br>差异内容：ASSET_INSERT|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：AssetStatus；<br>API声明：ASSET_UPDATE<br>差异内容：ASSET_UPDATE|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：AssetStatus；<br>API声明：ASSET_DELETE<br>差异内容：ASSET_DELETE|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：AssetStatus；<br>API声明：ASSET_ABNORMAL<br>差异内容：ASSET_ABNORMAL|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：AssetStatus；<br>API声明：ASSET_DOWNLOADING<br>差异内容：ASSET_DOWNLOADING|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：commonType；<br>API声明： interface Asset<br>差异内容： interface Asset|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：name: string;<br>差异内容：name: string;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：uri: string;<br>差异内容：uri: string;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：path: string;<br>差异内容：path: string;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：createTime: string;<br>差异内容：createTime: string;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：modifyTime: string;<br>差异内容：modifyTime: string;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：size: string;<br>差异内容：size: string;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：Asset；<br>API声明：status?: AssetStatus;<br>差异内容：status?: AssetStatus;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：commonType；<br>API声明：type Assets = Array\<Asset>;<br>差异内容：type Assets = Array\<Asset>;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：commonType；<br>API声明：type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;<br>差异内容：type ValueType = null \| number \| string \| boolean \| Uint8Array \| Asset \| Assets;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：commonType；<br>API声明：type ValuesBucket = Record\<string, ValueType>;<br>差异内容：type ValuesBucket = Record\<string, ValueType>;|api/@ohos.data.commonType.d.ts|
|新增API|NA|类名：distributedDataObject；<br>API声明： interface BindInfo<br>差异内容： interface BindInfo|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：BindInfo；<br>API声明：storeName: string;<br>差异内容：storeName: string;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：BindInfo；<br>API声明：tableName: string;<br>差异内容：tableName: string;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：BindInfo；<br>API声明：primaryKey: commonType.ValuesBucket;<br>差异内容：primaryKey: commonType.ValuesBucket;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：BindInfo；<br>API声明：field: string;<br>差异内容：field: string;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：BindInfo；<br>API声明：assetName: string;<br>差异内容：assetName: string;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：DataObject；<br>API声明：bindAssetStore(assetKey: string, bindInfo: BindInfo, callback: AsyncCallback\<void>): void;<br>差异内容：bindAssetStore(assetKey: string, bindInfo: BindInfo, callback: AsyncCallback\<void>): void;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：DataObject；<br>API声明：bindAssetStore(assetKey: string, bindInfo: BindInfo): Promise\<void>;<br>差异内容：bindAssetStore(assetKey: string, bindInfo: BindInfo): Promise\<void>;|api/@ohos.data.distributedDataObject.d.ts|
|新增API|NA|类名：StoreConfig；<br>API声明：customDir?: string;<br>差异内容：customDir?: string;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：StoreConfig；<br>API声明：autoCleanDirtyData?: boolean;<br>差异内容：autoCleanDirtyData?: boolean;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：relationalStore；<br>API声明： enum Origin<br>差异内容： enum Origin|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Origin；<br>API声明：LOCAL<br>差异内容：LOCAL|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Origin；<br>API声明：CLOUD<br>差异内容：CLOUD|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Origin；<br>API声明：REMOTE<br>差异内容：REMOTE|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：relationalStore；<br>API声明： enum Field<br>差异内容： enum Field|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Field；<br>API声明：CURSOR_FIELD = '#_cursor'<br>差异内容：CURSOR_FIELD = '#_cursor'|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Field；<br>API声明：ORIGIN_FIELD = '#_origin'<br>差异内容：ORIGIN_FIELD = '#_origin'|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Field；<br>API声明：DELETED_FLAG_FIELD = '#_deleted_flag'<br>差异内容：DELETED_FLAG_FIELD = '#_deleted_flag'|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Field；<br>API声明：OWNER_FIELD = '#_cloud_owner'<br>差异内容：OWNER_FIELD = '#_cloud_owner'|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Field；<br>API声明：PRIVILEGE_FIELD = '#_cloud_privilege'<br>差异内容：PRIVILEGE_FIELD = '#_cloud_privilege'|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：Field；<br>API声明：SHARING_RESOURCE_FIELD = '#_sharing_resource_field'<br>差异内容：SHARING_RESOURCE_FIELD = '#_sharing_resource_field'|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：ResultSet；<br>API声明：getRow(): ValuesBucket;<br>差异内容：getRow(): ValuesBucket;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：RdbStore；<br>API声明：cleanDirtyData(table: string, cursor: number, callback: AsyncCallback\<void>): void;<br>差异内容：cleanDirtyData(table: string, cursor: number, callback: AsyncCallback\<void>): void;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：RdbStore；<br>API声明：cleanDirtyData(table: string, callback: AsyncCallback\<void>): void;<br>差异内容：cleanDirtyData(table: string, callback: AsyncCallback\<void>): void;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：RdbStore；<br>API声明：cleanDirtyData(table: string, cursor?: number): Promise\<void>;<br>差异内容：cleanDirtyData(table: string, cursor?: number): Promise\<void>;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：RdbStore；<br>API声明：on(event: 'autoSyncProgress', progress: Callback\<ProgressDetails>): void;<br>差异内容：on(event: 'autoSyncProgress', progress: Callback\<ProgressDetails>): void;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：RdbStore；<br>API声明：off(event: 'autoSyncProgress', progress?: Callback\<ProgressDetails>): void;<br>差异内容：off(event: 'autoSyncProgress', progress?: Callback\<ProgressDetails>): void;|api/@ohos.data.relationalStore.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：ENTITY = 'general.entity'<br>差异内容：ENTITY = 'general.entity'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：OBJECT = 'general.object'<br>差异内容：OBJECT = 'general.object'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：COMPOSITE_OBJECT = 'general.composite-object'<br>差异内容：COMPOSITE_OBJECT = 'general.composite-object'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：XML = 'general.xml'<br>差异内容：XML = 'general.xml'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：SOURCE_CODE = 'general.source-code'<br>差异内容：SOURCE_CODE = 'general.source-code'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：SCRIPT = 'general.script'<br>差异内容：SCRIPT = 'general.script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：SHELL_SCRIPT = 'general.shell-script'<br>差异内容：SHELL_SCRIPT = 'general.shell-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：CSH_SCRIPT = 'general.csh-script'<br>差异内容：CSH_SCRIPT = 'general.csh-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PERL_SCRIPT = 'general.perl-script'<br>差异内容：PERL_SCRIPT = 'general.perl-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PHP_SCRIPT = 'general.php-script'<br>差异内容：PHP_SCRIPT = 'general.php-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PYTHON_SCRIPT = 'general.python-script'<br>差异内容：PYTHON_SCRIPT = 'general.python-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：RUBY_SCRIPT = 'general.ruby-script'<br>差异内容：RUBY_SCRIPT = 'general.ruby-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：TYPE_SCRIPT = 'general.type-script'<br>差异内容：TYPE_SCRIPT = 'general.type-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：JAVA_SCRIPT = 'general.java-script'<br>差异内容：JAVA_SCRIPT = 'general.java-script'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：C_HEADER = 'general.c-header'<br>差异内容：C_HEADER = 'general.c-header'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：C_SOURCE = 'general.c-source'<br>差异内容：C_SOURCE = 'general.c-source'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：C_PLUS_PLUS_HEADER = 'general.c-plus-plus-header'<br>差异内容：C_PLUS_PLUS_HEADER = 'general.c-plus-plus-header'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：C_PLUS_PLUS_SOURCE = 'general.c-plus-plus-source'<br>差异内容：C_PLUS_PLUS_SOURCE = 'general.c-plus-plus-source'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：JAVA_SOURCE = 'general.java-source'<br>差异内容：JAVA_SOURCE = 'general.java-source'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：EBOOK = 'general.ebook'<br>差异内容：EBOOK = 'general.ebook'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：EPUB = 'general.epub'<br>差异内容：EPUB = 'general.epub'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：AZW = 'com.amazon.azw'<br>差异内容：AZW = 'com.amazon.azw'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：AZW3 = 'com.amazon.azw3'<br>差异内容：AZW3 = 'com.amazon.azw3'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：KFX = 'com.amazon.kfx'<br>差异内容：KFX = 'com.amazon.kfx'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：MOBI = 'com.amazon.mobi'<br>差异内容：MOBI = 'com.amazon.mobi'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：MEDIA = 'general.media'<br>差异内容：MEDIA = 'general.media'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：JPEG = 'general.jpeg'<br>差异内容：JPEG = 'general.jpeg'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PNG = 'general.png'<br>差异内容：PNG = 'general.png'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：RAW_IMAGE = 'general.raw-image'<br>差异内容：RAW_IMAGE = 'general.raw-image'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：TIFF = 'general.tiff'<br>差异内容：TIFF = 'general.tiff'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：BMP = 'com.microsoft.bmp'<br>差异内容：BMP = 'com.microsoft.bmp'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：ICO = 'com.microsoft.ico'<br>差异内容：ICO = 'com.microsoft.ico'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PHOTOSHOP_IMAGE = 'com.adobe.photoshop-image'<br>差异内容：PHOTOSHOP_IMAGE = 'com.adobe.photoshop-image'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：AI_IMAGE = 'com.adobe.illustrator.ai-image'<br>差异内容：AI_IMAGE = 'com.adobe.illustrator.ai-image'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WORD_DOC = 'com.microsoft.word.doc'<br>差异内容：WORD_DOC = 'com.microsoft.word.doc'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：EXCEL = 'com.microsoft.excel.xls'<br>差异内容：EXCEL = 'com.microsoft.excel.xls'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PPT = 'com.microsoft.powerpoint.ppt'<br>差异内容：PPT = 'com.microsoft.powerpoint.ppt'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PDF = 'com.adobe.pdf'<br>差异内容：PDF = 'com.adobe.pdf'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：POSTSCRIPT = 'com.adobe.postscript'<br>差异内容：POSTSCRIPT = 'com.adobe.postscript'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：ENCAPSULATED_POSTSCRIPT = 'com.adobe.encapsulated-postscript'<br>差异内容：ENCAPSULATED_POSTSCRIPT = 'com.adobe.encapsulated-postscript'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：AVI = 'general.avi'<br>差异内容：AVI = 'general.avi'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：MPEG = 'general.mpeg'<br>差异内容：MPEG = 'general.mpeg'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：MPEG4 = 'general.mpeg-4'<br>差异内容：MPEG4 = 'general.mpeg-4'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：VIDEO_3GPP = 'general.3gpp'<br>差异内容：VIDEO_3GPP = 'general.3gpp'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：VIDEO_3GPP2 = 'general.3gpp2'<br>差异内容：VIDEO_3GPP2 = 'general.3gpp2'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WM = 'com.microsoft.windows-media-wm'<br>差异内容：WINDOWS_MEDIA_WM = 'com.microsoft.windows-media-wm'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WMV = 'com.microsoft.windows-media-wmv'<br>差异内容：WINDOWS_MEDIA_WMV = 'com.microsoft.windows-media-wmv'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WMP = 'com.microsoft.windows-media-wmp'<br>差异内容：WINDOWS_MEDIA_WMP = 'com.microsoft.windows-media-wmp'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：AAC = 'general.aac'<br>差异内容：AAC = 'general.aac'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：AIFF = 'general.aiff'<br>差异内容：AIFF = 'general.aiff'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：ALAC = 'general.alac'<br>差异内容：ALAC = 'general.alac'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：FLAC = 'general.flac'<br>差异内容：FLAC = 'general.flac'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：MP3 = 'general.mp3'<br>差异内容：MP3 = 'general.mp3'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：OGG = 'general.ogg'<br>差异内容：OGG = 'general.ogg'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：PCM = 'general.pcm'<br>差异内容：PCM = 'general.pcm'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WMA = 'com.microsoft.windows-media-wma'<br>差异内容：WINDOWS_MEDIA_WMA = 'com.microsoft.windows-media-wma'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WAVEFORM_AUDIO = 'com.microsoft.waveform-audio'<br>差异内容：WAVEFORM_AUDIO = 'com.microsoft.waveform-audio'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WMX = 'com.microsoft.windows-media-wmx'<br>差异内容：WINDOWS_MEDIA_WMX = 'com.microsoft.windows-media-wmx'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WVX = 'com.microsoft.windows-media-wvx'<br>差异内容：WINDOWS_MEDIA_WVX = 'com.microsoft.windows-media-wvx'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：WINDOWS_MEDIA_WAX = 'com.microsoft.windows-media-wax'<br>差异内容：WINDOWS_MEDIA_WAX = 'com.microsoft.windows-media-wax'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：DIRECTORY = 'general.directory'<br>差异内容：DIRECTORY = 'general.directory'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：SYMLINK = 'general.symlink'<br>差异内容：SYMLINK = 'general.symlink'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：ARCHIVE = 'general.archive'<br>差异内容：ARCHIVE = 'general.archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：BZ2_ARCHIVE = 'general.bz2-archive'<br>差异内容：BZ2_ARCHIVE = 'general.bz2-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：DISK_IMAGE = 'general.disk-image'<br>差异内容：DISK_IMAGE = 'general.disk-image'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：TAR_ARCHIVE = 'general.tar-archive'<br>差异内容：TAR_ARCHIVE = 'general.tar-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：ZIP_ARCHIVE = 'general.zip-archive'<br>差异内容：ZIP_ARCHIVE = 'general.zip-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：JAVA_ARCHIVE = 'com.sun.java-archive'<br>差异内容：JAVA_ARCHIVE = 'com.sun.java-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：GNU_TAR_ARCHIVE = 'org.gnu.gnu-tar-archive'<br>差异内容：GNU_TAR_ARCHIVE = 'org.gnu.gnu-tar-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：GNU_ZIP_ARCHIVE = 'org.gnu.gnu-zip-archive'<br>差异内容：GNU_ZIP_ARCHIVE = 'org.gnu.gnu-zip-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：GNU_ZIP_TAR_ARCHIVE = 'org.gnu.gnu-zip-tar-archive'<br>差异内容：GNU_ZIP_TAR_ARCHIVE = 'org.gnu.gnu-zip-tar-archive'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：CALENDAR = 'general.calendar'<br>差异内容：CALENDAR = 'general.calendar'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：CONTACT = 'general.contact'<br>差异内容：CONTACT = 'general.contact'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：DATABASE = 'general.database'<br>差异内容：DATABASE = 'general.database'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：MESSAGE = 'general.message'<br>差异内容：MESSAGE = 'general.message'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：VCARD = 'general.vcard'<br>差异内容：VCARD = 'general.vcard'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：NAVIGATION = 'general.navigation'<br>差异内容：NAVIGATION = 'general.navigation'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：LOCATION = 'general.location'<br>差异内容：LOCATION = 'general.location'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：OPENHARMONY_ATOMIC_SERVICE = 'openharmony.atomic-service'<br>差异内容：OPENHARMONY_ATOMIC_SERVICE = 'openharmony.atomic-service'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：OPENHARMONY_PACKAGE = 'openharmony.package'<br>差异内容：OPENHARMONY_PACKAGE = 'openharmony.package'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：UniformDataType；<br>API声明：OPENHARMONY_HAP = 'openharmony.hap'<br>差异内容：OPENHARMONY_HAP = 'openharmony.hap'|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：uniformTypeDescriptor；<br>API声明： class TypeDescriptor<br>差异内容： class TypeDescriptor|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：readonly typeId: string;<br>差异内容：readonly typeId: string;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：readonly belongingToTypes: Array\<string>;<br>差异内容：readonly belongingToTypes: Array\<string>;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：readonly description: string;<br>差异内容：readonly description: string;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：readonly referenceURL: string;<br>差异内容：readonly referenceURL: string;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：readonly iconFile: string;<br>差异内容：readonly iconFile: string;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：belongsTo(type: string): boolean;<br>差异内容：belongsTo(type: string): boolean;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：isLowerLevelType(type: string): boolean;<br>差异内容：isLowerLevelType(type: string): boolean;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：isHigherLevelType(type: string): boolean;<br>差异内容：isHigherLevelType(type: string): boolean;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：TypeDescriptor；<br>API声明：equals(typeDescriptor: TypeDescriptor): boolean;<br>差异内容：equals(typeDescriptor: TypeDescriptor): boolean;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：uniformTypeDescriptor；<br>API声明：function getTypeDescriptor(typeId: string): TypeDescriptor;<br>差异内容：function getTypeDescriptor(typeId: string): TypeDescriptor;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：uniformTypeDescriptor；<br>API声明：function getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string;<br>差异内容：function getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|新增API|NA|类名：uniformTypeDescriptor；<br>API声明：function getUniformDataTypeByMIMEType(mimeType: string, belongsTo?: string): string;<br>差异内容：function getUniformDataTypeByMIMEType(mimeType: string, belongsTo?: string): string;|api/@ohos.data.uniformTypeDescriptor.d.ts|
|起始版本有变化|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId: string, callback: AsyncCallback\<void>): void;<br>差异内容：9|api/@ohos.data.distributedDataObject.d.ts|
|起始版本有变化|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(callback: AsyncCallback\<void>): void;<br>差异内容：9|api/@ohos.data.distributedDataObject.d.ts|
|起始版本有变化|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：NA|类名：DataObject；<br>API声明：setSessionId(sessionId?: string): Promise\<void>;<br>差异内容：9|api/@ohos.data.distributedDataObject.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.dataAbility.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.dataSharePredicates.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.distributedData.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.distributedDataObject.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.distributedKVStore.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.preferences.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.rdb.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.relationalStore.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.storage.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.unifiedDataChannel.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.uniformTypeDescriptor.d.ts|
|kit变更|NA|ArkData|api/@ohos.data.ValuesBucket.d.ts|
|kit变更|NA|ArkData|api/@system.storage.d.ts|
