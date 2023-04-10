| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFile(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): Promise\<string[]>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFile(path: string, callback: AsyncCallback\<string[]>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFile(path: string, options: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}, callback: AsyncCallback\<string[]>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFileSync(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): string[];|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFile(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFileSync(src: string, dest: string, mode?: number): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: lock(exclusive?: boolean): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: lock(callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: lock(exclusive: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: tryLock(exclusive?: boolean): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: unlock(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: hash|@ohos.file.hash.d.ts|
|新增|NA|类名：hash<br>方法or属性：|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: hash<br>方法 or 属性：function hash(path: string, algorithm: string): Promise\<string>;|@ohos.file.hash.d.ts|
|新增|NA|类名：hash<br>方法or属性：function hash(path: string, algorithm: string): Promise\<string>;|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: hash<br>方法 or 属性：function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|@ohos.file.hash.d.ts|
|新增|NA|类名：hash<br>方法or属性：function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: picker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes<br>方法 or 属性: IMAGE_TYPE = "image/*"|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes<br>方法 or 属性: VIDEO_TYPE = "video/*"|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes<br>方法 or 属性: IMAGE_VIDEO_TYPE = "*/*"|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectOptions<br>方法 or 属性: MIMEType?: PhotoViewMIMETypes;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectOptions<br>方法 or 属性: maxSelectNumber?: number;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectResult|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectResult<br>方法 or 属性: photoUris: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectResult<br>方法 or 属性: isOriginalPhoto: boolean;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSaveOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSaveOptions<br>方法 or 属性: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: select(option?: PhotoSelectOptions) : Promise\<PhotoSelectResult>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: select(option: PhotoSelectOptions, callback: AsyncCallback\<PhotoSelectResult>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: select(callback: AsyncCallback\<PhotoSelectResult>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: save(option?: PhotoSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: save(option: PhotoSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentSelectOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentSaveOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentSaveOptions<br>方法 or 属性: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: select(option?: DocumentSelectOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: select(option: DocumentSelectOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: select(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: save(option?: DocumentSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: save(option: DocumentSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioSelectOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioSaveOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioSaveOptions<br>方法 or 属性: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: select(option?: AudioSelectOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: select(option: AudioSelectOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: select(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: save(option?: AudioSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: save(option: AudioSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|类名：DataLevel<br>方法or属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|类名：DataLevel<br>方法or属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|类名：DataLevel<br>方法or属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|类名：DataLevel<br>方法or属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|类名：DataLevel<br>方法or属性：type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs|@ohos.file.statvfs.d.ts|
|新增|NA|类名：statfs<br>方法or属性：|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性：function getFreeSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|类名：statfs<br>方法or属性：function getFreeSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性：function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|类名：statfs<br>方法or属性：function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性：function getTotalSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|类名：statfs<br>方法or属性：function getTotalSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性：function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|类名：statfs<br>方法or属性：function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats<br>方法 or 属性: appSize: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats<br>方法 or 属性: cacheSize: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats<br>方法 or 属性: dataSize: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getBundleStats(packageName: string): Promise\<BundleStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getCurrentBundleStats(): Promise\<BundleStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getSystemSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getSystemSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: total: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: audio: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: video: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: image: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: file: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: app: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(): Promise\<StorageStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(userId: number): Promise\<StorageStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: id: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: uuid: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: diskId: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: description: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: removable: boolean;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: state: number;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: path: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getAllVolumes(): Promise\<Array\<Volume>>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function mount(volumeId: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function mount(volumeId: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function unmount(volumeId: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function unmount(volumeId: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeByUuid(uuid: string): Promise\<Volume>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeById(volumeId: string): Promise\<Volume>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function setVolumeDescription(uuid: string, description: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function format(volumeId: string, fsType: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function partition(diskId: string, type: number): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|删除|模块名: ohos.file.hash<br>类名: Hash|NA|@ohos.file.hash.d.ts|
|删除|模块名: ohos.file.hash<br>类名: Hash<br>方法 or 属性：function hash(path: string, algorithm: string): Promise\<string>;|NA|@ohos.file.hash.d.ts|
|删除|模块名: ohos.file.hash<br>类名: Hash<br>方法 or 属性：function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|NA|@ohos.file.hash.d.ts|
|删除|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|删除|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|删除|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|删除|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|删除|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|删除|模块名: ohos.file.statvfs<br>类名: Statfs|NA|@ohos.file.statvfs.d.ts|
|删除|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性：function getFreeSize(path: string): Promise\<number>;|NA|@ohos.file.statvfs.d.ts|
|删除|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性：function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|NA|@ohos.file.statvfs.d.ts|
|删除|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性：function getTotalSize(path: string): Promise\<number>;|NA|@ohos.file.statvfs.d.ts|
|删除|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性：function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|NA|@ohos.file.statvfs.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: BundleStats|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: BundleStats<br>方法 or 属性：appSize: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: BundleStats<br>方法 or 属性：cacheSize: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: BundleStats<br>方法 or 属性：dataSize: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getBundleStats(packageName: string): Promise\<BundleStats>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getCurrentBundleStats(): Promise\<BundleStats>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getSystemSize(callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getSystemSize(): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats<br>方法 or 属性：total: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats<br>方法 or 属性：audio: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats<br>方法 or 属性：video: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats<br>方法 or 属性：image: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats<br>方法 or 属性：file: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: StorageStats<br>方法 or 属性：app: number;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getUserStorageStats(userId?: number): Promise\<StorageStats>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getTotalSize(callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getTotalSize(): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getFreeSize(callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getFreeSize(): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：id: string;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：uuid: string;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：diskId: string;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：description: string;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：removable: boolean;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：state: number;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: Volume<br>方法 or 属性：path: string;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function getAllVolumes(): Promise\<Array\<Volume>>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function mount(volumeId: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function mount(volumeId: string): Promise\<boolean>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function unmount(volumeId: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function unmount(volumeId: string): Promise\<boolean>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function getVolumeById(volumeId: string): Promise\<Volume>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function format(volumeId: string, fsType: string): Promise\<void>;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;|NA|@ohos.volumeManager.d.ts|
|删除|模块名: ohos.volumeManager<br>类名: volumeManager<br>方法 or 属性：function partition(diskId: string, type: number): Promise\<void>;|NA|@ohos.volumeManager.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function opendir(path: string): Promise\<Dir>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function opendir(path: string): Promise\<Dir>;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：read(): Promise\<Dirent>;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：read(): Promise\<Dirent>;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：read(callback: AsyncCallback\<Dirent>): void;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：read(callback: AsyncCallback\<Dirent>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：readSync(): Dirent;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：readSync(): Dirent;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：close(): Promise\<void>;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：close(): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：closeSync(): void;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：closeSync(): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>废弃版本：N/A|类名：Dirent<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：readonly name: string;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：readonly name: string;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isBlockDevice(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isBlockDevice(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isCharacterDevice(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isCharacterDevice(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isDirectory(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isDirectory(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isFIFO(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isFIFO(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isFile(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isFile(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isSocket(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isSocket(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isSymbolicLink(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isSymbolicLink(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|起始版本有变化|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>起始版本：N/A|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>起始版本：6|@ohos.fileio.d.ts|
|函数有变化|类名：securityLabel<br>方法 or 属性：function setSecurityLabel(path: string, type: dataLevel): Promise\<void>;<br>|类名：securityLabel<br>方法 or 属性：function setSecurityLabel(path: string, type: DataLevel): Promise\<void>;<br>|@ohos.file.securityLabel.d.ts|
|函数有变化|类名：securityLabel<br>方法 or 属性：function setSecurityLabel(path: string, type: dataLevel, callback: AsyncCallback\<void>): void;<br>|类名：securityLabel<br>方法 or 属性：function setSecurityLabel(path: string, type: DataLevel, callback: AsyncCallback\<void>): void;<br>|@ohos.file.securityLabel.d.ts|
|函数有变化|类名：securityLabel<br>方法 or 属性：function setSecurityLabelSync(path: string, type: dataLevel): void;<br>|类名：securityLabel<br>方法 or 属性：function setSecurityLabelSync(path: string, type: DataLevel): void;<br>|@ohos.file.securityLabel.d.ts|
