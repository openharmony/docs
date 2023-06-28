| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.file.backup<br>Class name: backup|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: FileMeta|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: FileMeta<br>Method or attribute name: bundleName: string;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: FileMeta<br>Method or attribute name: uri: string;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: FileData|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: FileData<br>Method or attribute name: fd: number;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: File|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: backup<br>Method or attribute name: function getLocalCapabilities(): Promise\<FileData>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: backup<br>Method or attribute name: function getLocalCapabilities(callback: AsyncCallback\<FileData>): void;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: GeneralCallbacks|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: GeneralCallbacks<br>Method or attribute name: onFileReady: AsyncCallback\<File>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: GeneralCallbacks<br>Method or attribute name: onBundleBegin: AsyncCallback\<string>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: GeneralCallbacks<br>Method or attribute name: onBundleEnd: AsyncCallback\<string>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: GeneralCallbacks<br>Method or attribute name: onAllBundlesEnd: AsyncCallback\<undefined>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: GeneralCallbacks<br>Method or attribute name: onBackupServiceDied: Callback\<undefined>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionBackup|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionBackup<br>Method or attribute name: constructor(callbacks: GeneralCallbacks);|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionBackup<br>Method or attribute name: appendBundles(bundlesToBackup: string[]): Promise\<void>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionBackup<br>Method or attribute name: appendBundles(bundlesToBackup: string[], callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: constructor(callbacks: GeneralCallbacks);|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[]): Promise\<void>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: publishFile(fileMeta: FileMeta): Promise\<void>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: publishFile(fileMeta: FileMeta, callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: getFileHandle(fileMeta: FileMeta): Promise\<void>;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.backup<br>Class name: SessionRestore<br>Method or attribute name: getFileHandle(fileMeta: FileMeta, callback: AsyncCallback\<void>): void;|@ohos.file.backup.d.ts|
|Added|NA|Module name: ohos.file.cloudSyncManager<br>Class name: cloudSyncManager|@ohos.file.cloudSyncManager.d.ts|
|Added|NA|Module name: ohos.file.cloudSyncManager<br>Class name: cloudSyncManager<br>Method or attribute name: function changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|Added|NA|Module name: ohos.file.cloudSyncManager<br>Class name: cloudSyncManager<br>Method or attribute name: function changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSyncManager.d.ts|
|Added|NA|Module name: ohos.file.cloudSyncManager<br>Class name: cloudSyncManager<br>Method or attribute name: function notifyDataChange(accountId: string, bundleName: string): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|Added|NA|Module name: ohos.file.cloudSyncManager<br>Class name: cloudSyncManager<br>Method or attribute name: function notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSyncManager.d.ts|
|Added|NA|Class name: FileInfo<br>Method or attribute name: relativePath: string;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: RootInfo<br>Method or attribute name: relativePath: string;|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: CopyResult|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: CopyResult<br>Method or attribute name: sourceUri: string;|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: CopyResult<br>Method or attribute name: destUri: string;|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: CopyResult<br>Method or attribute name: errCode: number;|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: CopyResult<br>Method or attribute name: errMsg: string;|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: DISPLAY_NAME = 'display_name'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: DATE_ADDED = 'date_added'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: DATE_MODIFIED = 'date_modified'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: RELATIVE_PATH = 'relative_path'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: FILE_SIZE = 'size'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: WIDTH = 'width'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: HEIGHT = 'height'|@ohos.file.fileAccess.d.ts|
|Added|NA|Module name: ohos.file.fileAccess<br>Class name: FileKey<br>Method or attribute name: DURATION = 'duration'|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: copy(sourceUri: string, destUri: string, force?: boolean): Promise\<Array\<CopyResult>>;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: copy(sourceUri: string, destUri: string, callback: AsyncCallback\<Array\<CopyResult>>): void;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: copy(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback\<Array\<CopyResult>>): void;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: query(uri: string, metaJson: string): Promise\<string>;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: query(uri: string, metaJson: string, callback: AsyncCallback\<string>): void;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: getFileInfoFromUri(uri: string): Promise\<FileInfo>;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: getFileInfoFromUri(uri: string, callback: AsyncCallback\<FileInfo>): void;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: getFileInfoFromRelativePath(relativePath: string): Promise\<FileInfo>;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: getFileInfoFromRelativePath(relativePath: string, callback: AsyncCallback\<FileInfo>): void;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: getThumbnail(uri: string, size: image.Size): Promise\<image.PixelMap>;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: FileAccessHelper<br>Method or attribute name: getThumbnail(uri: string, size: image.Size, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.file.fileAccess.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function copyDir(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function copyDir(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function createWatcher(path: string, events: number, listener: WatchEventListener): Watcher;|@ohos.file.fs.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function moveDir(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function moveDir(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Class name: fileIo<br>Method or attribute name: function moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: WatchEventListener|@ohos.file.fs.d.ts|
|Added|NA|Class name: WatchEventListener<br>Method or attribute name: |@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: WatchEventListener<br>Method or attribute name: (event: WatchEvent): void;|@ohos.file.fs.d.ts|
|Added|NA|Class name: WatchEventListener<br>Method or attribute name: (event: WatchEvent): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: WatchEvent|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: WatchEvent<br>Method or attribute name: readonly fileName: string;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: WatchEvent<br>Method or attribute name: readonly event: number;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: WatchEvent<br>Method or attribute name: readonly cookie: number;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: Watcher|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: Watcher<br>Method or attribute name: start(): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.file.fs<br>Class name: Watcher<br>Method or attribute name: stop(): void;|@ohos.file.fs.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PhotoSubType|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PhotoSubType<br>Method or attribute name: DEFAULT|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PhotoSubType<br>Method or attribute name: SCREENSHOT|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PhotoSubType<br>Method or attribute name: CAMERA|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PositionType|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PositionType<br>Method or attribute name: LOCAL = 1|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PositionType<br>Method or attribute name: CLOUD|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PositionType<br>Method or attribute name: BOTH|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: FileAsset<br>Method or attribute name: setHidden(hiddenState: boolean, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: FileAsset<br>Method or attribute name: setHidden(hiddenState: boolean): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ImageVideoKey<br>Method or attribute name: POSITION|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ImageVideoKey<br>Method or attribute name: DATE_TRASHED|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ImageVideoKey<br>Method or attribute name: HIDDEN|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PhotoCreateOptions|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: PhotoCreateOptions<br>Method or attribute name: subType?: PhotoSubType;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: FetchResult<br>Method or attribute name: getAllObject(callback: AsyncCallback\<Array\<T>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: FetchResult<br>Method or attribute name: getAllObject(): Promise\<Array\<T>>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumType|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumType<br>Method or attribute name: USER = 0|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumType<br>Method or attribute name: SYSTEM = 1024|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: USER_GENERIC = 1|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: FAVORITE = 1025|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: VIDEO|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: HIDDEN|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: TRASH|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: SCREENSHOT|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: CAMERA|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: AlbumSubType<br>Method or attribute name: ANY = 2147483647|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: AbsAlbum<br>Method or attribute name: readonly albumType: AlbumType;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: AbsAlbum<br>Method or attribute name: readonly albumSubType: AlbumSubType;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: AbsAlbum<br>Method or attribute name: coverUri: string;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: addPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: addPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: addPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: addPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: removePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: removePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: removePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: removePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: recoverPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: recoverPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: recoverPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: recoverPhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: deletePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: deletePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: Album<br>Method or attribute name: deletePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: Album<br>Method or attribute name: deletePhotoAssets(assets: Array\<FileAsset>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: createAudioAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: createAudioAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: createAudioAsset(displayName: string): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: createAudioAsset(displayName: string): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: createAlbum(name: string, callback: AsyncCallback\<Album>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: createAlbum(name: string, callback: AsyncCallback\<Album>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: createAlbum(name: string): Promise\<Album>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: createAlbum(name: string): Promise\<Album>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: deleteAlbums(albums: Array\<Album>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: deleteAlbums(albums: Array\<Album>): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: getAlbums(<br>      type: AlbumType,<br>      subType: AlbumSubType,<br>      options: FetchOptions,<br>      callback: AsyncCallback\<FetchResult\<Album>><br>    ): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: getAlbums(<br>      type: AlbumType,<br>      subType: AlbumSubType,<br>      options: FetchOptions,<br>      callback: AsyncCallback\<FetchResult\<Album>><br>    ): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback\<FetchResult\<Album>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback\<FetchResult\<Album>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise\<FetchResult\<Album>>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise\<FetchResult\<Album>>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: on(uri: string, forSubUri: boolean, callback: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: on(uri: string, forSubUri: boolean, callback: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: UserFileManager<br>Method or attribute name: off(uri: string, callback?: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Class name: UserFileManager<br>Method or attribute name: off(uri: string, callback?: Callback\<ChangeData>): void;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: NotifyType|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: NotifyType<br>Method or attribute name: NOTIFY_ADD|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: NotifyType<br>Method or attribute name: NOTIFY_UPDATE|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: NotifyType<br>Method or attribute name: NOTIFY_REMOVE|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: NotifyType<br>Method or attribute name: NOTIFY_ALBUM_ADD_ASSET|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: NotifyType<br>Method or attribute name: NOTIFY_ALBUM_REMOVE_ASSET|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: DefaultChangeUri|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: DefaultChangeUri<br>Method or attribute name: DEFAULT_PHOTO_URI|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: DefaultChangeUri<br>Method or attribute name: DEFAULT_ALBUM_URI|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: DefaultChangeUri<br>Method or attribute name: DEFAULT_AUDIO_URI|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ChangeData|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ChangeData<br>Method or attribute name: type: NotifyType;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ChangeData<br>Method or attribute name: uris: Array\<string>;|@ohos.filemanagement.userFileManager.d.ts|
|Added|NA|Module name: ohos.filemanagement.userFileManager<br>Class name: ChangeData<br>Method or attribute name: subUris: Array\<string>;|@ohos.filemanagement.userFileManager.d.ts|
|Model changed|Class name: FileAccessHelper<br>Model: @StageModelOnly|Class name: FileAccessHelper<br>Model: N/A|@ohos.file.fileAccess.d.ts|
|Model changed|Class name: FileAccessHelper<br>Method or attribute name: getRoots(): Promise\<RootIterator>;<br>Model: @StageModelOnly|Class name: FileAccessHelper<br>Method or attribute name: getRoots(): Promise\<RootIterator>;<br>Model: N/A|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: FileInfo<br>Method or attribute name: uri: string;<br>Permission: N/A|Class name: FileInfo<br>Method or attribute name: uri: string;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: FileInfo<br>Method or attribute name: fileName: string;<br>Permission: N/A|Class name: FileInfo<br>Method or attribute name: fileName: string;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: FileInfo<br>Method or attribute name: mode: number;<br>Permission: N/A|Class name: FileInfo<br>Method or attribute name: mode: number;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: FileInfo<br>Method or attribute name: size: number;<br>Permission: N/A|Class name: FileInfo<br>Method or attribute name: size: number;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: FileInfo<br>Method or attribute name: mtime: number;<br>Permission: N/A|Class name: FileInfo<br>Method or attribute name: mtime: number;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: FileInfo<br>Method or attribute name: mimeType: string;<br>Permission: N/A|Class name: FileInfo<br>Method or attribute name: mimeType: string;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: RootInfo<br>Method or attribute name: deviceType: number;<br>Permission: N/A|Class name: RootInfo<br>Method or attribute name: deviceType: number;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: RootInfo<br>Method or attribute name: uri: string;<br>Permission: N/A|Class name: RootInfo<br>Method or attribute name: uri: string;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: RootInfo<br>Method or attribute name: displayName: string;<br>Permission: N/A|Class name: RootInfo<br>Method or attribute name: displayName: string;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Permission added|Class name: RootInfo<br>Method or attribute name: deviceFlags: number;<br>Permission: N/A|Class name: RootInfo<br>Method or attribute name: deviceFlags: number;<br>Permission: ohos.permission.FILE_ACCESS_MANAGER|@ohos.file.fileAccess.d.ts|
|Function changed|Class name: fileIo<br>Method or attribute name: function closeSync(fd: number \| File): void;<br>|Class name: fileIo<br>Method or attribute name: function closeSync(file: number \| File): void;<br>|@ohos.file.fs.d.ts|
