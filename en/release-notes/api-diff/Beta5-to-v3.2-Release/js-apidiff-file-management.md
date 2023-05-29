| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function listFile(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): Promise\<string[]>;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function listFile(path: string, callback: AsyncCallback\<string[]>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function listFile(path: string, options: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}, callback: AsyncCallback\<string[]>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function listFileSync(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): string[];|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function moveFile(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: fileIo<br>Method or attribute name: function moveFileSync(src: string, dest: string, mode?: number): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: File<br>Method or attribute name: lock(exclusive?: boolean): Promise\<void>;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: File<br>Method or attribute name: lock(callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: File<br>Method or attribute name: lock(exclusive: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: File<br>Method or attribute name: tryLock(exclusive?: boolean): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: File<br>Method or attribute name: unlock(): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.hash<br>Class name: hash|@ohos.file.hash.d.ts|
|Added|NA|Class name: hash<br>Method or attribute name: |@ohos.file.hash.d.ts|
|Added|NA|Module name: ohos.file.hash<br>Class name: hash<br>Method or attribute name: function hash(path: string, algorithm: string): Promise\<string>;|@ohos.file.hash.d.ts|
|Added|NA|Class name: hash<br>Method or attribute name: function hash(path: string, algorithm: string): Promise\<string>;|@ohos.file.hash.d.ts|
|Added|NA|Module name: ohos.file.hash<br>Class name: hash<br>Method or attribute name: function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|@ohos.file.hash.d.ts|
|Added|NA|Class name: hash<br>Method or attribute name: function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|@ohos.file.hash.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: picker|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewMIMETypes|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewMIMETypes<br>Method or attribute name: IMAGE_TYPE = "image/*"|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewMIMETypes<br>Method or attribute name: VIDEO_TYPE = "video/*"|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewMIMETypes<br>Method or attribute name: IMAGE_VIDEO_TYPE = "*/*"|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSelectOptions|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSelectOptions<br>Method or attribute name: MIMEType?: PhotoViewMIMETypes;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSelectOptions<br>Method or attribute name: maxSelectNumber?: number;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSelectResult|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSelectResult<br>Method or attribute name: photoUris: Array\<string>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSelectResult<br>Method or attribute name: isOriginalPhoto: boolean;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSaveOptions|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoSaveOptions<br>Method or attribute name: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker<br>Method or attribute name: select(option?: PhotoSelectOptions) : Promise\<PhotoSelectResult>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker<br>Method or attribute name: select(option: PhotoSelectOptions, callback: AsyncCallback\<PhotoSelectResult>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker<br>Method or attribute name: select(callback: AsyncCallback\<PhotoSelectResult>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker<br>Method or attribute name: save(option?: PhotoSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker<br>Method or attribute name: save(option: PhotoSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: PhotoViewPicker<br>Method or attribute name: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentSelectOptions|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentSaveOptions|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentSaveOptions<br>Method or attribute name: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker<br>Method or attribute name: select(option?: DocumentSelectOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker<br>Method or attribute name: select(option: DocumentSelectOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker<br>Method or attribute name: select(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker<br>Method or attribute name: save(option?: DocumentSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker<br>Method or attribute name: save(option: DocumentSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: DocumentViewPicker<br>Method or attribute name: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioSelectOptions|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioSaveOptions|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioSaveOptions<br>Method or attribute name: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker<br>Method or attribute name: select(option?: AudioSelectOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker<br>Method or attribute name: select(option: AudioSelectOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker<br>Method or attribute name: select(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker<br>Method or attribute name: save(option?: AudioSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker<br>Method or attribute name: save(option: AudioSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.picker<br>Class name: AudioViewPicker<br>Method or attribute name: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|Added|NA|Module name: ohos.file.securityLabel<br>Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Module name: ohos.file.securityLabel<br>Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Module name: ohos.file.securityLabel<br>Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Module name: ohos.file.securityLabel<br>Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Module name: ohos.file.securityLabel<br>Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Class name: DataLevel<br>Method or attribute name: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|Added|NA|Module name: ohos.file.statvfs<br>Class name: statfs|@ohos.file.statvfs.d.ts|
|Added|NA|Class name: statfs<br>Method or attribute name: |@ohos.file.statvfs.d.ts|
|Added|NA|Module name: ohos.file.statvfs<br>Class name: statfs<br>Method or attribute name: function getFreeSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|Added|NA|Class name: statfs<br>Method or attribute name: function getFreeSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|Added|NA|Module name: ohos.file.statvfs<br>Class name: statfs<br>Method or attribute name: function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|Added|NA|Class name: statfs<br>Method or attribute name: function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|Added|NA|Module name: ohos.file.statvfs<br>Class name: statfs<br>Method or attribute name: function getTotalSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|Added|NA|Class name: statfs<br>Method or attribute name: function getTotalSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|Added|NA|Module name: ohos.file.statvfs<br>Class name: statfs<br>Method or attribute name: function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|Added|NA|Class name: statfs<br>Method or attribute name: function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: BundleStats|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: BundleStats<br>Method or attribute name: appSize: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: BundleStats<br>Method or attribute name: cacheSize: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: BundleStats<br>Method or attribute name: dataSize: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getBundleStats(packageName: string): Promise\<BundleStats>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getCurrentBundleStats(): Promise\<BundleStats>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getSystemSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getSystemSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: total: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: audio: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: video: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: image: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: file: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: app: number;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(): Promise\<StorageStats>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(userId: number): Promise\<StorageStats>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: id: string;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: uuid: string;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: diskId: string;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: description: string;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: removable: boolean;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: state: number;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: Volume<br>Method or attribute name: path: string;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getAllVolumes(): Promise\<Array\<Volume>>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function mount(volumeId: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function mount(volumeId: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function unmount(volumeId: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function unmount(volumeId: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeByUuid(uuid: string): Promise\<Volume>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeById(volumeId: string): Promise\<Volume>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function setVolumeDescription(uuid: string, description: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function format(volumeId: string, fsType: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|Added|NA|Module name: ohos.file.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function partition(diskId: string, type: number): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|Deleted|Module name: ohos.file.hash<br>Class name: Hash|NA|@ohos.file.hash.d.ts|
|Deleted|Module name: ohos.file.hash<br>Class name: Hash<br>Method or attribute name: function hash(path: string, algorithm: string): Promise\<string>;|NA|@ohos.file.hash.d.ts|
|Deleted|Module name: ohos.file.hash<br>Class name: Hash<br>Method or attribute name: function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|NA|@ohos.file.hash.d.ts|
|Deleted|Module name: ohos.file.securityLabel<br>Class name: dataLevel<br>Method or attribute name: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|Deleted|Module name: ohos.file.securityLabel<br>Class name: dataLevel<br>Method or attribute name: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|Deleted|Module name: ohos.file.securityLabel<br>Class name: dataLevel<br>Method or attribute name: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|Deleted|Module name: ohos.file.securityLabel<br>Class name: dataLevel<br>Method or attribute name: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|Deleted|Module name: ohos.file.securityLabel<br>Class name: dataLevel<br>Method or attribute name: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.file.securityLabel.d.ts|
|Deleted|Module name: ohos.file.statvfs<br>Class name: Statfs|NA|@ohos.file.statvfs.d.ts|
|Deleted|Module name: ohos.file.statvfs<br>Class name: Statfs<br>Method or attribute name: function getFreeSize(path: string): Promise\<number>;|NA|@ohos.file.statvfs.d.ts|
|Deleted|Module name: ohos.file.statvfs<br>Class name: Statfs<br>Method or attribute name: function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|NA|@ohos.file.statvfs.d.ts|
|Deleted|Module name: ohos.file.statvfs<br>Class name: Statfs<br>Method or attribute name: function getTotalSize(path: string): Promise\<number>;|NA|@ohos.file.statvfs.d.ts|
|Deleted|Module name: ohos.file.statvfs<br>Class name: Statfs<br>Method or attribute name: function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|NA|@ohos.file.statvfs.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: BundleStats|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: BundleStats<br>Method or attribute name: appSize: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: BundleStats<br>Method or attribute name: cacheSize: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: BundleStats<br>Method or attribute name: dataSize: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getBundleStats(packageName: string): Promise\<BundleStats>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getCurrentBundleStats(): Promise\<BundleStats>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getSystemSize(callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getSystemSize(): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: total: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: audio: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: video: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: image: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: file: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: StorageStats<br>Method or attribute name: app: number;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(userId?: number): Promise\<StorageStats>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSize(callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getTotalSize(): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSize(callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.storageStatistics<br>Class name: storageStatistics<br>Method or attribute name: function getFreeSize(): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: id: string;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: uuid: string;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: diskId: string;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: description: string;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: removable: boolean;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: state: number;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: Volume<br>Method or attribute name: path: string;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getAllVolumes(): Promise\<Array\<Volume>>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function mount(volumeId: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function mount(volumeId: string): Promise\<boolean>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function unmount(volumeId: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function unmount(volumeId: string): Promise\<boolean>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeByUuid(uuid: string): Promise\<Volume>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function getVolumeById(volumeId: string): Promise\<Volume>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function setVolumeDescription(uuid: string, description: string): Promise\<void>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function format(volumeId: string, fsType: string): Promise\<void>;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;|NA|@ohos.volumeManager.d.ts|
|Deleted|Module name: ohos.volumeManager<br>Class name: volumeManager<br>Method or attribute name: function partition(diskId: string, type: number): Promise\<void>;|NA|@ohos.volumeManager.d.ts|
|Deprecated version changed|Class name: fileIO<br>Method or attribute name: function opendir(path: string): Promise\<Dir>;<br>Deprecated version: N/A|Class name: fileIO<br>Method or attribute name: function opendir(path: string): Promise\<Dir>;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: fileIO<br>Method or attribute name: function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>Deprecated version: N/A|Class name: fileIO<br>Method or attribute name: function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: fileIO<br>Method or attribute name: function opendirSync(path: string): Dir;<br>Deprecated version: N/A|Class name: fileIO<br>Method or attribute name: function opendirSync(path: string): Dir;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dir<br>Method or attribute name: read(): Promise\<Dirent>;<br>Deprecated version: N/A|Class name: Dir<br>Method or attribute name: read(): Promise\<Dirent>;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dir<br>Method or attribute name: read(callback: AsyncCallback\<Dirent>): void;<br>Deprecated version: N/A|Class name: Dir<br>Method or attribute name: read(callback: AsyncCallback\<Dirent>): void;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dir<br>Method or attribute name: readSync(): Dirent;<br>Deprecated version: N/A|Class name: Dir<br>Method or attribute name: readSync(): Dirent;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dir<br>Method or attribute name: close(): Promise\<void>;<br>Deprecated version: N/A|Class name: Dir<br>Method or attribute name: close(): Promise\<void>;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dir<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;<br>Deprecated version: N/A|Class name: Dir<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dir<br>Method or attribute name: closeSync(): void;<br>Deprecated version: N/A|Class name: Dir<br>Method or attribute name: closeSync(): void;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Deprecated version: N/A|Class name: Dirent<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: readonly name: string;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: readonly name: string;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isBlockDevice(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isBlockDevice(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isCharacterDevice(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isCharacterDevice(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isDirectory(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isDirectory(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isFIFO(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isFIFO(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isFile(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isFile(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isSocket(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isSocket(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Deprecated version changed|Class name: Dirent<br>Method or attribute name: isSymbolicLink(): boolean;<br>Deprecated version: N/A|Class name: Dirent<br>Method or attribute name: isSymbolicLink(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|Initial version changed|Class name: fileIO<br>Method or attribute name: function opendirSync(path: string): Dir;<br>Initial version: N/A|Class name: fileIO<br>Method or attribute name: function opendirSync(path: string): Dir;<br>Initial version: 6|@ohos.fileio.d.ts|
|Function changed|Class name: securityLabel<br>Method or attribute name: function setSecurityLabel(path: string, type: dataLevel): Promise\<void>;<br>|Class name: securityLabel<br>Method or attribute name: function setSecurityLabel(path: string, type: DataLevel): Promise\<void>;<br>|@ohos.file.securityLabel.d.ts|
|Function changed|Class name: securityLabel<br>Method or attribute name: function setSecurityLabel(path: string, type: dataLevel, callback: AsyncCallback\<void>): void;<br>|Class name: securityLabel<br>Method or attribute name: function setSecurityLabel(path: string, type: DataLevel, callback: AsyncCallback\<void>): void;<br>|@ohos.file.securityLabel.d.ts|
|Function changed|Class name: securityLabel<br>Method or attribute name: function setSecurityLabelSync(path: string, type: dataLevel): void;<br>|Class name: securityLabel<br>Method or attribute name: function setSecurityLabelSync(path: string, type: DataLevel): void;<br>|@ohos.file.securityLabel.d.ts|
