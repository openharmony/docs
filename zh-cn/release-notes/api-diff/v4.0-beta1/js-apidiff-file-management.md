| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.file.backup<br>类名: backup|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: FileMeta|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: FileMeta<br>方法 or 属性: bundleName: string;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: FileMeta<br>方法 or 属性: uri: string;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: FileData|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: FileData<br>方法 or 属性: fd: number;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: File|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: backup<br>方法 or 属性: function getLocalCapabilities(): Promise\<FileData>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: backup<br>方法 or 属性: function getLocalCapabilities(callback: AsyncCallback\<FileData>): void;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: GeneralCallbacks|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: GeneralCallbacks<br>方法 or 属性: onFileReady: AsyncCallback\<File>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: GeneralCallbacks<br>方法 or 属性: onBundleBegin: AsyncCallback\<string>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: GeneralCallbacks<br>方法 or 属性: onBundleEnd: AsyncCallback\<string>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: GeneralCallbacks<br>方法 or 属性: onAllBundlesEnd: AsyncCallback\<undefined>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: GeneralCallbacks<br>方法 or 属性: onBackupServiceDied: Callback\<undefined>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionBackup|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionBackup<br>方法 or 属性: constructor(callbacks: GeneralCallbacks);|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionBackup<br>方法 or 属性: appendBundles(bundlesToBackup: string[]): Promise\<void>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionBackup<br>方法 or 属性: appendBundles(bundlesToBackup: string[], callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: constructor(callbacks: GeneralCallbacks);|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[]): Promise\<void>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: publishFile(fileMeta: FileMeta): Promise\<void>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: publishFile(fileMeta: FileMeta, callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: getFileHandle(fileMeta: FileMeta): Promise\<void>;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.backup<br>类名: SessionRestore<br>方法 or 属性: getFileHandle(fileMeta: FileMeta, callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|新增|NA|模块名: ohos.file.cloudSyncManager<br>类名: cloudSyncManager|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|模块名: ohos.file.cloudSyncManager<br>类名: cloudSyncManager<br>方法 or 属性: function changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|模块名: ohos.file.cloudSyncManager<br>类名: cloudSyncManager<br>方法 or 属性: function changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|模块名: ohos.file.cloudSyncManager<br>类名: cloudSyncManager<br>方法 or 属性: function notifyDataChange(accountId: string, bundleName: string): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|模块名: ohos.file.cloudSyncManager<br>类名: cloudSyncManager<br>方法 or 属性: function notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：FileInfo<br>方法or属性：relativePath: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：RootInfo<br>方法or属性：relativePath: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: CopyResult|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: CopyResult<br>方法 or 属性：sourceUri: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: CopyResult<br>方法 or 属性：destUri: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: CopyResult<br>方法 or 属性：errCode: number;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: CopyResult<br>方法 or 属性：errMsg: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：DISPLAY_NAME = 'display_name'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：DATE_ADDED = 'date_added'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：DATE_MODIFIED = 'date_modified'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：RELATIVE_PATH = 'relative_path'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：FILE_SIZE = 'size'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：WIDTH = 'width'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：HEIGHT = 'height'|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileKey<br>方法 or 属性：DURATION = 'duration'|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：copy(sourceUri: string, destUri: string, force?: boolean): Promise\<Array\<CopyResult>>;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：copy(sourceUri: string, destUri: string, callback: AsyncCallback\<Array\<CopyResult>>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：copy(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback\<Array\<CopyResult>>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：query(uri: string, metaJson: string): Promise\<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：query(uri: string, metaJson: string, callback: AsyncCallback\<string>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：getFileInfoFromUri(uri: string): Promise\<FileInfo>;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：getFileInfoFromUri(uri: string, callback: AsyncCallback\<FileInfo>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：getFileInfoFromRelativePath(relativePath: string): Promise\<FileInfo>;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：getFileInfoFromRelativePath(relativePath: string, callback: AsyncCallback\<FileInfo>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：getThumbnail(uri: string, size: image.Size): Promise\<image.PixelMap>;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：FileAccessHelper<br>方法or属性：getThumbnail(uri: string, size: image.Size, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyDir(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyDir(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function createWatcher(path: string, events: number, listener: WatchEventListener): Watcher;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function moveDir(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function moveDir(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: WatchEventListener|@ohos.file.fs.d.ts|
|新增|NA|类名：WatchEventListener<br>方法or属性：|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: WatchEventListener<br>方法 or 属性：(event: WatchEvent): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：WatchEventListener<br>方法or属性：(event: WatchEvent): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: WatchEvent|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: WatchEvent<br>方法 or 属性：readonly fileName: string;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: WatchEvent<br>方法 or 属性：readonly event: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: WatchEvent<br>方法 or 属性：readonly cookie: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Watcher|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Watcher<br>方法 or 属性：start(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Watcher<br>方法 or 属性：stop(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PhotoSubType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PhotoSubType<br>方法 or 属性：DEFAULT|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PhotoSubType<br>方法 or 属性：SCREENSHOT|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PhotoSubType<br>方法 or 属性：CAMERA|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PositionType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PositionType<br>方法 or 属性：LOCAL = 1|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PositionType<br>方法 or 属性：CLOUD|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PositionType<br>方法 or 属性：BOTH|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性：setHidden(hiddenState: boolean, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性：setHidden(hiddenState: boolean): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性：POSITION|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性：DATE_TRASHED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性：HIDDEN|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PhotoCreateOptions|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PhotoCreateOptions<br>方法 or 属性：subType?: PhotoSubType;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性：getAllObject(callback: AsyncCallback\<Array\<T>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性：getAllObject(): Promise\<Array\<T>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumType<br>方法 or 属性：USER = 0|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumType<br>方法 or 属性：SYSTEM = 1024|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：USER_GENERIC = 1|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：FAVORITE = 1025|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：VIDEO|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：HIDDEN|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：TRASH|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：SCREENSHOT|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：CAMERA|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumSubType<br>方法 or 属性：ANY = 2147483647|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：AbsAlbum<br>方法or属性：readonly albumType: AlbumType;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：AbsAlbum<br>方法or属性：readonly albumSubType: AlbumSubType;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：AbsAlbum<br>方法or属性：coverUri: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：addPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：addPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：addPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：addPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：removePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：removePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：removePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：removePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：recoverPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：recoverPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：recoverPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：recoverPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：deletePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：deletePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性：deletePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：Album<br>方法or属性：deletePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：createAudioAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：createAudioAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：createAudioAsset(displayName: string): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：createAudioAsset(displayName: string): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：createAlbum(name: string, callback: AsyncCallback\<Album>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：createAlbum(name: string, callback: AsyncCallback\<Album>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：createAlbum(name: string): Promise\<Album>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：createAlbum(name: string): Promise\<Album>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：deleteAlbums(albums: Array\<Album>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：deleteAlbums(albums: Array\<Album>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：getAlbums(<br>      type: AlbumType,<br>      subType: AlbumSubType,<br>      options: FetchOptions,<br>      callback: AsyncCallback\<FetchResult\<Album>><br>    ): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：getAlbums(<br>      type: AlbumType,<br>      subType: AlbumSubType,<br>      options: FetchOptions,<br>      callback: AsyncCallback\<FetchResult\<Album>><br>    ): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback\<FetchResult\<Album>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback\<FetchResult\<Album>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise\<FetchResult\<Album>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise\<FetchResult\<Album>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：on(uri: string, forSubUri: boolean, callback: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：on(uri: string, forSubUri: boolean, callback: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性：off(uri: string, callback?: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|类名：UserFileManager<br>方法or属性：off(uri: string, callback?: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: NotifyType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: NotifyType<br>方法 or 属性：NOTIFY_ADD|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: NotifyType<br>方法 or 属性：NOTIFY_UPDATE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: NotifyType<br>方法 or 属性：NOTIFY_REMOVE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: NotifyType<br>方法 or 属性：NOTIFY_ALBUM_ADD_ASSET|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: NotifyType<br>方法 or 属性：NOTIFY_ALBUM_REMOVE_ASSET|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: DefaultChangeUri|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: DefaultChangeUri<br>方法 or 属性：DEFAULT_PHOTO_URI|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: DefaultChangeUri<br>方法 or 属性：DEFAULT_ALBUM_URI|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: DefaultChangeUri<br>方法 or 属性：DEFAULT_AUDIO_URI|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeData|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeData<br>方法 or 属性：type: NotifyType;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeData<br>方法 or 属性：uris: Array\<string>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeData<br>方法 or 属性：subUris: Array\<string>;|@ohos.filemanagement.userFileManager.d.ts|
|model有变化|类名：FileAccessHelper<br>model:@StageModelOnly|类名：FileAccessHelper<br>model:N/A|@ohos.file.fileAccess.d.ts|
|model有变化|类名：FileAccessHelper<br>方法 or 属性：getRoots(): Promise\<RootIterator>;<br>model:@StageModelOnly|类名：FileAccessHelper<br>方法 or 属性：getRoots(): Promise\<RootIterator>;<br>model:N/A|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：FileInfo<br>方法 or 属性：uri: string;<br>权限:N/A|类名：FileInfo<br>方法 or 属性：uri: string;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：FileInfo<br>方法 or 属性：fileName: string;<br>权限:N/A|类名：FileInfo<br>方法 or 属性：fileName: string;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：FileInfo<br>方法 or 属性：mode: number;<br>权限:N/A|类名：FileInfo<br>方法 or 属性：mode: number;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：FileInfo<br>方法 or 属性：size: number;<br>权限:N/A|类名：FileInfo<br>方法 or 属性：size: number;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：FileInfo<br>方法 or 属性：mtime: number;<br>权限:N/A|类名：FileInfo<br>方法 or 属性：mtime: number;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：FileInfo<br>方法 or 属性：mimeType: string;<br>权限:N/A|类名：FileInfo<br>方法 or 属性：mimeType: string;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：RootInfo<br>方法 or 属性：deviceType: number;<br>权限:N/A|类名：RootInfo<br>方法 or 属性：deviceType: number;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：RootInfo<br>方法 or 属性：uri: string;<br>权限:N/A|类名：RootInfo<br>方法 or 属性：uri: string;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：RootInfo<br>方法 or 属性：displayName: string;<br>权限:N/A|类名：RootInfo<br>方法 or 属性：displayName: string;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|新增(权限)|类名：RootInfo<br>方法 or 属性：deviceFlags: number;<br>权限:N/A|类名：RootInfo<br>方法 or 属性：deviceFlags: number;<br>权限:ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|函数有变化|类名：fileIo<br>方法 or 属性：function closeSync(fd: number \| File): void;<br>|类名：fileIo<br>方法 or 属性：function closeSync(file: number \| File): void;<br>|@ohos.file.fs.d.ts|
