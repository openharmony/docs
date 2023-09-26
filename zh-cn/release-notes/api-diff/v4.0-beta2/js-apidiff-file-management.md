| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：SyncState;<br>方法or属性：UPLOADING|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncState;<br>方法or属性：UPLOAD_FAILED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncState;<br>方法or属性：DOWNLOADING|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncState;<br>方法or属性：DOWNLOAD_FAILED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncState;<br>方法or属性：COMPLETED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：State;<br>方法or属性：COMPLETED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncState;<br>方法or属性：STOPPED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：State;<br>方法or属性：STOPPED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：NO_ERROR|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：NETWORK_UNAVAILABLE|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：WIFI_UNAVAILABLE|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：BATTERY_LEVEL_LOW|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：BATTERY_LEVEL_WARNING|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：CLOUD_STORAGE_FULL|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：ErrorType;<br>方法or属性：LOCAL_STORAGE_FULL|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncProgress;<br>方法or属性：state: SyncState;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：SyncProgress;<br>方法or属性：error: ErrorType;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：constructor();|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：constructor();|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：on(evt: 'progress', callback: (pg: SyncProgress) => void): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：off(evt: 'progress'): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：off(evt: 'progress'): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：start(): Promise\<void>;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：stop(): Promise\<void>;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：GallerySync;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：State;<br>方法or属性：RUNNING|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：State;<br>方法or属性：FAILED|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：DownloadProgress;<br>方法or属性：state: State;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：DownloadProgress;<br>方法or属性：processed: number;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：DownloadProgress;<br>方法or属性：size: number;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：DownloadProgress;<br>方法or属性：uri: string;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：on(evt: 'progress', callback: (pg: DownloadProgress) => void): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：start(uri: string): Promise\<void>;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：start(uri: string, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：stop(uri: string): Promise\<void>;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：Download;<br>方法or属性：stop(uri: string, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSync.d.ts|
|新增|NA|类名：cloudSyncManager;<br>方法or属性：function enableCloud(accountId: string, switches: { [bundleName: string]: boolean }): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：cloudSyncManager;<br>方法or属性：function enableCloud(<br>    accountId: string,<br>    switches: { [bundleName: string]: boolean },<br>    callback: AsyncCallback\<void><br>  ): void;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：cloudSyncManager;<br>方法or属性：function disableCloud(accountId: string): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：cloudSyncManager;<br>方法or属性：function disableCloud(accountId: string, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：cloudSyncManager;<br>方法or属性：function clean(accountId: string, appActions: { [bundleName: string]: Action }): Promise\<void>;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：cloudSyncManager;<br>方法or属性：function clean(accountId: string, appActions: { [bundleName: string]: Action }, callback: AsyncCallback\<void>): void;|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：Action;<br>方法or属性：RETAIN_DATA|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：Action;<br>方法or属性：CLEAR_DATA|@ohos.file.cloudSyncManager.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：declare function createRandomAccessFile(file: string \| File, mode?: number): Promise\<RandomAccessFile>;|@ohos.file.fs.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：declare function createRandomAccessFile(file: string \| File, callback: AsyncCallback\<RandomAccessFile>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：declare function createRandomAccessFile(file: string \| File, mode: number, callback: AsyncCallback\<RandomAccessFile>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：declare function createRandomAccessFileSync(file: string \| File, mode?: number): RandomAccessFile;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：readonly fd: number;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：readonly filePointer: number;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：setFilePointer(filePointer: number): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：close(): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：write(<br>    buffer: ArrayBuffer \| string,<br>    options?: {<br>      offset?: number;<br>      length?: number;<br>      encoding?: string;<br>    }<br>  ): Promise\<number>;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：write(buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：write(<br>    buffer: ArrayBuffer \| string,<br>    options: {<br>      offset?: number;<br>      length?: number;<br>      encoding?: string;<br>    },<br>    callback: AsyncCallback\<number><br>  ): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：writeSync(<br>    buffer: ArrayBuffer \| string,<br>    options?: {<br>      offset?: number;<br>      length?: number;<br>      encoding?: string;<br>    }<br>  ): number;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：read(<br>    buffer: ArrayBuffer,<br>    options?: {<br>      offset?: number;<br>      length?: number;<br>    }<br>  ): Promise\<number>;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：read(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：read(<br>    buffer: ArrayBuffer,<br>    options: {<br>      offset?: number;<br>      length?: number;<br>    },<br>    callback: AsyncCallback\<number><br>  ): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：RandomAccessFile;<br>方法or属性：readSync(<br>    buffer: ArrayBuffer,<br>    options?: {<br>      offset?: number;<br>      length?: number;<br>    }<br>  ): number;|@ohos.file.fs.d.ts|
|新增|NA|类名：photoAccessHelper;<br>方法or属性：function getPhotoAccessHelper(context: Context): PhotoAccessHelper;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：photoAccessHelper;<br>方法or属性：type MemberType = number \| string \| boolean;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoType;<br>方法or属性：IMAGE = 1|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoType;<br>方法or属性：VIDEO|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：VIDEO|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoSubtype;<br>方法or属性：DEFAULT|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoSubtype;<br>方法or属性：SCREENSHOT|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：SCREENSHOT|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PositionType;<br>方法or属性：LOCAL = 1 \<\< 0|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PositionType;<br>方法or属性：CLOUD = 1 \<\< 1|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：readonly uri: string;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：readonly photoType: PhotoType;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：readonly displayName: string;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：get(member: string): MemberType;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：set(member: string, value: string): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：commitModify(callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：commitModify(callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：commitModify(): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：commitModify(): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：open(mode: string, callback: AsyncCallback\<number>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：open(mode: string): Promise\<number>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：getReadOnlyFd(callback: AsyncCallback\<number>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：getReadOnlyFd(): Promise\<number>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：close(fd: number, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：close(fd: number): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：getThumbnail(size: image.Size, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：getThumbnail(size?: image.Size): Promise\<image.PixelMap>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：setFavorite(favoriteState: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：setFavorite(favoriteState: boolean): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：setHidden(hiddenState: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAsset;<br>方法or属性：setHidden(hiddenState: boolean): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：URI = 'uri'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumKeys;<br>方法or属性：URI = 'uri'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：PHOTO_TYPE = 'media_type'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：DISPLAY_NAME = 'display_name'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：SIZE = 'size'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：DATE_ADDED = 'date_added'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：DATE_MODIFIED = 'date_modified'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：DURATION = 'duration'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：WIDTH = 'width'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：HEIGHT = 'height'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：DATE_TAKEN = 'date_taken'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：ORIENTATION = 'orientation'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：FAVORITE = 'is_favorite'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：TITLE = 'title'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：POSITION = 'position'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：DATE_TRASHED = 'date_trashed'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoKeys;<br>方法or属性：HIDDEN = 'hidden'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumKeys;<br>方法or属性：ALBUM_NAME = 'album_name'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchOptions;<br>方法or属性：fetchColumns: Array\<string>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchOptions;<br>方法or属性：predicates: dataSharePredicates.DataSharePredicates;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoCreateOptions;<br>方法or属性：subtype?: PhotoSubtype;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：CreateOptions;<br>方法or属性：title?: string;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getCount(): number;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：isAfterLast(): boolean;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getFirstObject(callback: AsyncCallback\<T>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getFirstObject(): Promise\<T>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getNextObject(callback: AsyncCallback\<T>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getNextObject(): Promise\<T>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getLastObject(callback: AsyncCallback\<T>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getLastObject(): Promise\<T>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getObjectByPosition(index: number, callback: AsyncCallback\<T>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getObjectByPosition(index: number): Promise\<T>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getAllObjects(callback: AsyncCallback\<Array\<T>>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：getAllObjects(): Promise\<Array\<T>>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：FetchResult;<br>方法or属性：close(): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumType;<br>方法or属性：USER = 0|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumType;<br>方法or属性：SYSTEM = 1024|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：USER_GENERIC = 1|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：FAVORITE = 1025|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：HIDDEN|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：TRASH|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：CAMERA|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AlbumSubtype;<br>方法or属性：ANY = 2147483647|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：readonly albumType: AlbumType;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：readonly albumSubtype: AlbumSubtype;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：albumName: string;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：readonly albumUri: string;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：readonly count: number;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：readonly coverUri: string;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：getAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<PhotoAsset>>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：getAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<PhotoAsset>>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：AbsAlbum;<br>方法or属性：getAssets(options: FetchOptions): Promise\<FetchResult\<PhotoAsset>>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：getAssets(options: FetchOptions): Promise\<FetchResult\<PhotoAsset>>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：addAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：addAssets(assets: Array\<PhotoAsset>): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：removeAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：removeAssets(assets: Array\<PhotoAsset>): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：recoverAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：recoverAssets(assets: Array\<PhotoAsset>): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：deleteAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：deleteAssets(assets: Array\<PhotoAsset>): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：setCoverUri(uri: string, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：Album;<br>方法or属性：setCoverUri(uri: string): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(displayName: string, callback: AsyncCallback\<PhotoAsset>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(displayName: string): Promise\<PhotoAsset>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(displayName: string, options: PhotoCreateOptions): Promise\<PhotoAsset>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(displayName: string, options: PhotoCreateOptions, callback: AsyncCallback\<PhotoAsset>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(photoType: PhotoType, extension: string, options: CreateOptions, callback: AsyncCallback\<string>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(photoType: PhotoType, extension: string, callback: AsyncCallback\<string>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAsset(photoType: PhotoType, extension: string, options?: CreateOptions): Promise\<string>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAlbum(name: string, callback: AsyncCallback\<Album>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：createAlbum(name: string): Promise\<Album>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：deleteAlbums(albums: Array\<Album>): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：getAlbums(<br>      type: AlbumType,<br>      subtype: AlbumSubtype,<br>      options: FetchOptions,<br>      callback: AsyncCallback\<FetchResult\<Album>><br>    ): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：getAlbums(type: AlbumType, subtype: AlbumSubtype, callback: AsyncCallback\<FetchResult\<Album>>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：getAlbums(type: AlbumType, subtype: AlbumSubtype, options?: FetchOptions): Promise\<FetchResult\<Album>>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：deleteAssets(uriList: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：deleteAssets(uriList: Array\<string>): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：registerChange(uri: string, forChildUris: boolean, callback: Callback\<ChangeData>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：unRegisterChange(uri: string, callback?: Callback\<ChangeData>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：PhotoAccessHelper;<br>方法or属性：release(): Promise\<void>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：NotifyType;<br>方法or属性：NOTIFY_ADD|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：NotifyType;<br>方法or属性：NOTIFY_UPDATE|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：NotifyType;<br>方法or属性：NOTIFY_REMOVE|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：NotifyType;<br>方法or属性：NOTIFY_ALBUM_ADD_ASSET|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：NotifyType;<br>方法or属性：NOTIFY_ALBUM_REMOVE_ASSET|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：DefaultChangeUri;<br>方法or属性：DEFAULT_PHOTO_URI = 'file://media/Photo'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：DefaultChangeUri;<br>方法or属性：DEFAULT_ALBUM_URI = 'file://media/PhotoAlbum'|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：ChangeData;<br>方法or属性：type: NotifyType;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：ChangeData;<br>方法or属性：uris: Array\<string>;|@ohos.file.photoAccessHelper.d.ts|
|新增|NA|类名：ChangeData;<br>方法or属性：extraUris: Array\<string>;|@ohos.file.photoAccessHelper.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function choose(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function choose(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口：|@ohos.document.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function choose(types: string[], callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function choose(types: string[], callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口：|@ohos.document.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function show(uri: string, type: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function show(uri: string, type: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.document.d.ts|
|废弃版本有变化|类名：document;<br>方法or属性：declare document<br>旧版本信息：|类名：document;<br>方法or属性：declare document<br>新版本信息：9<br>代替接口：|@ohos.document.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function access(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function access(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.access|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function access(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function access(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.access|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function close(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function close(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.close|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.copyFile|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function copyFile(<br>  src: string \| number,<br>  dest: string \| number,<br>  mode: number,<br>  callback: AsyncCallback\<void><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function copyFile(<br>  src: string \| number,<br>  dest: string \| number,<br>  mode: number,<br>  callback: AsyncCallback\<void><br>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.copyFile|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.createStream|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function chmod(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function chmod(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.truncate|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.truncate|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function fsync(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fsync(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.fsync|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function fstat(fd: number, callback: AsyncCallback\<Stat>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fstat(fd: number, callback: AsyncCallback\<Stat>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.stat|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function fdatasync(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fdatasync(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.fdatasync|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.fdopenStream|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.file.hash.hash|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function lstat(path: string, callback: AsyncCallback\<Stat>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function lstat(path: string, callback: AsyncCallback\<Stat>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.lstat|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.mkdir|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.mkdir|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.mkdtemp|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function open(path: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function open(path: string, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.open|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.open|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.open|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.listFile|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function readText(<br>  filePath: string,<br>  options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<string><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function readText(<br>  filePath: string,<br>  options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<string><br>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.readText|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.read|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function read(<br>  fd: number,<br>  buffer: ArrayBuffer,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>  },<br>  callback: AsyncCallback\<ReadOut><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function read(<br>  fd: number,<br>  buffer: ArrayBuffer,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>  },<br>  callback: AsyncCallback\<ReadOut><br>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.read|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.rename|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function rmdir(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function rmdir(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.rmdir|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function stat(path: string, callback: AsyncCallback\<Stat>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function stat(path: string, callback: AsyncCallback\<Stat>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.stat|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.symlink|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.truncate|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, len: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, len: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.truncate|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function unlink(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function unlink(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.unlink|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.write|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function write(<br>  fd: number,<br>  buffer: ArrayBuffer \| string,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<number><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function write(<br>  fd: number,<br>  buffer: ArrayBuffer \| string,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<number><br>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.write|@ohos.fileio.d.ts|
|废弃版本有变化|类名：sourcefile;<br>方法or属性：declare function createWatcher(filename: string, events: number, callback: AsyncCallback\<number>): Watcher;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function createWatcher(filename: string, events: number, callback: AsyncCallback\<number>): Watcher;<br>新版本信息：10<br>代替接口： ohos.file.fs.createWatcher|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir;<br>方法or属性：declare interface Dir<br>旧版本信息：|类名：Dir;<br>方法or属性：declare interface Dir<br>新版本信息：9<br>代替接口： ohos.file.fs.listFile|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir;<br>方法or属性：read(callback: AsyncCallback\<Dirent>): void;<br>旧版本信息：|类名：Dir;<br>方法or属性：read(callback: AsyncCallback\<Dirent>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.listFile|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Dir;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.fs.listFile|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Watcher;<br>方法or属性：declare interface Watcher<br>旧版本信息：|类名：Watcher;<br>方法or属性：declare interface Watcher<br>新版本信息：10<br>代替接口： ohos.file.fs.Watcher|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Watcher;<br>方法or属性：stop(): Promise\<void>;<br>旧版本信息：|类名：Watcher;<br>方法or属性：stop(): Promise\<void>;<br>新版本信息：10<br>代替接口： ohos.file.fs.Watcher.stop|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Watcher;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Watcher;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.Watcher.stop|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Statfs;<br>方法or属性：declare Statfs<br>旧版本信息：|类名：Statfs;<br>方法or属性：declare Statfs<br>新版本信息：9<br>代替接口： ohos.file.statvfs.statfs|@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs;<br>方法or属性：function getFreeBytes(path: string): Promise\<number>;<br>旧版本信息：|类名：Statfs;<br>方法or属性：function getFreeBytes(path: string): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.file.statvfs.getFreeSize|@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs;<br>方法or属性：function getTotalBytes(path: string): Promise\<number>;<br>旧版本信息：|类名：Statfs;<br>方法or属性：function getTotalBytes(path: string): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.file.statvfs.getTotalSize|@ohos.statfs.d.ts|
|废弃版本有变化|类名：FileResponse;<br>方法or属性：export interface FileResponse<br>旧版本信息：|类名：FileResponse;<br>方法or属性：export interface FileResponse<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileResponse;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileResponse;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileListOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileGetOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileGetOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileDeleteOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileDeleteOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileAccessOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileAccessOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMkdirOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileMkdirOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileRmdirOption;<br>方法or属性：uri: string;<br>旧版本信息：|类名：FileRmdirOption;<br>方法or属性：uri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileResponse;<br>方法or属性：length: number;<br>旧版本信息：|类名：FileResponse;<br>方法or属性：length: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileResponse;<br>方法or属性：lastModifiedTime: number;<br>旧版本信息：|类名：FileResponse;<br>方法or属性：lastModifiedTime: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileResponse;<br>方法or属性：type: 'dir' \| 'file';<br>旧版本信息：|类名：FileResponse;<br>方法or属性：type: 'dir' \| 'file';<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileResponse;<br>方法or属性：subFiles?: Array\<FileResponse>;<br>旧版本信息：|类名：FileResponse;<br>方法or属性：subFiles?: Array\<FileResponse>;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMoveOption;<br>方法or属性：export interface FileMoveOption<br>旧版本信息：|类名：FileMoveOption;<br>方法or属性：export interface FileMoveOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMoveOption;<br>方法or属性：srcUri: string;<br>旧版本信息：|类名：FileMoveOption;<br>方法or属性：srcUri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileCopyOption;<br>方法or属性：srcUri: string;<br>旧版本信息：|类名：FileCopyOption;<br>方法or属性：srcUri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMoveOption;<br>方法or属性：dstUri: string;<br>旧版本信息：|类名：FileMoveOption;<br>方法or属性：dstUri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileCopyOption;<br>方法or属性：dstUri: string;<br>旧版本信息：|类名：FileCopyOption;<br>方法or属性：dstUri: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMoveOption;<br>方法or属性：success?: (uri: string) => void;<br>旧版本信息：|类名：FileMoveOption;<br>方法or属性：success?: (uri: string) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileCopyOption;<br>方法or属性：success?: (uri: string) => void;<br>旧版本信息：|类名：FileCopyOption;<br>方法or属性：success?: (uri: string) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMoveOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileMoveOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileListOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileCopyOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileCopyOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileGetOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileGetOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileDeleteOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileDeleteOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileAccessOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileAccessOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMkdirOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileMkdirOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileRmdirOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：FileRmdirOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMoveOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileMoveOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileListOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileCopyOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileCopyOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileGetOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileGetOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileDeleteOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileDeleteOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileAccessOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileAccessOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMkdirOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileMkdirOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileRmdirOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：FileRmdirOption;<br>方法or属性：complete?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListResponse;<br>方法or属性：export interface FileListResponse<br>旧版本信息：|类名：FileListResponse;<br>方法or属性：export interface FileListResponse<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListResponse;<br>方法or属性：fileList: Array\<FileResponse>;<br>旧版本信息：|类名：FileListResponse;<br>方法or属性：fileList: Array\<FileResponse>;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListOption;<br>方法or属性：export interface FileListOption<br>旧版本信息：|类名：FileListOption;<br>方法or属性：export interface FileListOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileListOption;<br>方法or属性：success?: (data: FileListResponse) => void;<br>旧版本信息：|类名：FileListOption;<br>方法or属性：success?: (data: FileListResponse) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileCopyOption;<br>方法or属性：export interface FileCopyOption<br>旧版本信息：|类名：FileCopyOption;<br>方法or属性：export interface FileCopyOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileGetOption;<br>方法or属性：export interface FileGetOption<br>旧版本信息：|类名：FileGetOption;<br>方法or属性：export interface FileGetOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileGetOption;<br>方法or属性：recursive?: boolean;<br>旧版本信息：|类名：FileGetOption;<br>方法or属性：recursive?: boolean;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMkdirOption;<br>方法or属性：recursive?: boolean;<br>旧版本信息：|类名：FileMkdirOption;<br>方法or属性：recursive?: boolean;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileRmdirOption;<br>方法or属性：recursive?: boolean;<br>旧版本信息：|类名：FileRmdirOption;<br>方法or属性：recursive?: boolean;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileGetOption;<br>方法or属性：success?: (file: FileResponse) => void;<br>旧版本信息：|类名：FileGetOption;<br>方法or属性：success?: (file: FileResponse) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileDeleteOption;<br>方法or属性：export interface FileDeleteOption<br>旧版本信息：|类名：FileDeleteOption;<br>方法or属性：export interface FileDeleteOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileDeleteOption;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：FileDeleteOption;<br>方法or属性：success?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：success?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：success?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileAccessOption;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：FileAccessOption;<br>方法or属性：success?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMkdirOption;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：FileMkdirOption;<br>方法or属性：success?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileRmdirOption;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：FileRmdirOption;<br>方法or属性：success?: () => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：export interface FileWriteTextOption<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：export interface FileWriteTextOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：text: string;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：text: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextResponse;<br>方法or属性：text: string;<br>旧版本信息：|类名：FileReadTextResponse;<br>方法or属性：text: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：encoding?: string;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：encoding?: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：encoding?: string;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：encoding?: string;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteTextOption;<br>方法or属性：append?: boolean;<br>旧版本信息：|类名：FileWriteTextOption;<br>方法or属性：append?: boolean;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：append?: boolean;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：append?: boolean;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextResponse;<br>方法or属性：export interface FileReadTextResponse<br>旧版本信息：|类名：FileReadTextResponse;<br>方法or属性：export interface FileReadTextResponse<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：export interface FileReadTextOption<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：export interface FileReadTextOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：position?: number;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：position?: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：position?: number;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：position?: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：position?: number;<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：position?: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：length?: number;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：length?: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：length?: number;<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：length?: number;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadTextOption;<br>方法or属性：success?: (data: FileReadTextResponse) => void;<br>旧版本信息：|类名：FileReadTextOption;<br>方法or属性：success?: (data: FileReadTextResponse) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：export interface FileWriteArrayBufferOption<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：export interface FileWriteArrayBufferOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileWriteArrayBufferOption;<br>方法or属性：buffer: Uint8Array;<br>旧版本信息：|类名：FileWriteArrayBufferOption;<br>方法or属性：buffer: Uint8Array;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferResponse;<br>方法or属性：buffer: Uint8Array;<br>旧版本信息：|类名：FileReadArrayBufferResponse;<br>方法or属性：buffer: Uint8Array;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferResponse;<br>方法or属性：export interface FileReadArrayBufferResponse<br>旧版本信息：|类名：FileReadArrayBufferResponse;<br>方法or属性：export interface FileReadArrayBufferResponse<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：export interface FileReadArrayBufferOption<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：export interface FileReadArrayBufferOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileReadArrayBufferOption;<br>方法or属性：success?: (data: FileReadArrayBufferResponse) => void;<br>旧版本信息：|类名：FileReadArrayBufferOption;<br>方法or属性：success?: (data: FileReadArrayBufferResponse) => void;<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileAccessOption;<br>方法or属性：export interface FileAccessOption<br>旧版本信息：|类名：FileAccessOption;<br>方法or属性：export interface FileAccessOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileMkdirOption;<br>方法or属性：export interface FileMkdirOption<br>旧版本信息：|类名：FileMkdirOption;<br>方法or属性：export interface FileMkdirOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：FileRmdirOption;<br>方法or属性：export interface FileRmdirOption<br>旧版本信息：|类名：FileRmdirOption;<br>方法or属性：export interface FileRmdirOption<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：export default class File<br>旧版本信息：|类名：File;<br>方法or属性：export default class File<br>新版本信息：10<br>代替接口：|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static move(options: FileMoveOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static move(options: FileMoveOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.moveFile|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static copy(options: FileCopyOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static copy(options: FileCopyOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.copyFile|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static list(options: FileListOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static list(options: FileListOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.listFile|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static get(options: FileGetOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static get(options: FileGetOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.stat|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static delete(options: FileDeleteOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static delete(options: FileDeleteOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.unlink|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static writeText(options: FileWriteTextOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static writeText(options: FileWriteTextOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.write|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static readText(options: FileReadTextOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static readText(options: FileReadTextOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.readText|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static writeArrayBuffer(options: FileWriteArrayBufferOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static writeArrayBuffer(options: FileWriteArrayBufferOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.write|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static readArrayBuffer(options: FileReadArrayBufferOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static readArrayBuffer(options: FileReadArrayBufferOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.read|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static access(options: FileAccessOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static access(options: FileAccessOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.access|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static mkdir(options: FileMkdirOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static mkdir(options: FileMkdirOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.mkdir|@system.file.d.ts|
|废弃版本有变化|类名：File;<br>方法or属性：static rmdir(options: FileRmdirOption): void;<br>旧版本信息：|类名：File;<br>方法or属性：static rmdir(options: FileRmdirOption): void;<br>新版本信息：10<br>代替接口： ohos.file.fs.rmdir|@system.file.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function choose(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function choose(callback: AsyncCallback\<string>): void;<br>新版本信息：Parameter|@ohos.document.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function choose(types: string[], callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function choose(types: string[], callback: AsyncCallback\<string>): void;<br>新版本信息：Parameter|@ohos.document.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function show(uri: string, type: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function show(uri: string, type: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.document.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;<br>新版本信息：201,202,401,13600001,13600008,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;<br>新版本信息：201,202,401,13600001,13600008,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getBundleStats(packageName: string): Promise\<BundleStats>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getBundleStats(packageName: string): Promise\<BundleStats>;<br>新版本信息：201,202,401,13600001,13600008,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getCurrentBundleStats(): Promise\<BundleStats>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getCurrentBundleStats(): Promise\<BundleStats>;<br>新版本信息：401,13600001,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getSystemSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getSystemSize(): Promise\<number>;<br>新版本信息：201,202,401,13600001,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>新版本信息：201,202,401,13600001,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;<br>新版本信息：201,202,401,13600001,13600009,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getTotalSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getTotalSize(): Promise\<number>;<br>新版本信息：201,202,401,13600001,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：storageStatistics;<br>方法or属性：function getFreeSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getFreeSize(): Promise\<number>;<br>新版本信息：201,202,401,13600001,13900032|@ohos.file.storageStatistics.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function getAllVolumes(): Promise\<Array\<Volume>>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getAllVolumes(): Promise\<Array\<Volume>>;<br>新版本信息：201,202,401,13600001,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function mount(volumeId: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function mount(volumeId: string): Promise\<void>;<br>新版本信息：201,202,401,13600001,13600002,13600003,13600005,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function unmount(volumeId: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function unmount(volumeId: string): Promise\<void>;<br>新版本信息：201,202,401,13600001,13600002,13600004,13600005,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;<br>新版本信息：201,202,401,13600001,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function getVolumeById(volumeId: string): Promise\<Volume>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getVolumeById(volumeId: string): Promise\<Volume>;<br>新版本信息：201,202,401,13600001,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;<br>新版本信息：201,202,401,13600001,13600002,13600005,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function format(volumeId: string, fsType: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function format(volumeId: string, fsType: string): Promise\<void>;<br>新版本信息：201,202,401,13600001,13600002,13600005,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：volumeManager;<br>方法or属性：function partition(diskId: string, type: number): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function partition(diskId: string, type: number): Promise\<void>;<br>新版本信息：201,202,401,13600001,13600008,13900032|@ohos.file.volumeManager.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function access(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function access(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function access(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function access(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function close(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function close(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function copyFile(<br>  src: string \| number,<br>  dest: string \| number,<br>  mode: number,<br>  callback: AsyncCallback\<void><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function copyFile(<br>  src: string \| number,<br>  dest: string \| number,<br>  mode: number,<br>  callback: AsyncCallback\<void><br>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function chmod(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function chmod(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function fsync(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fsync(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function fstat(fd: number, callback: AsyncCallback\<Stat>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fstat(fd: number, callback: AsyncCallback\<Stat>): void;<br>新版本信息：fstat|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function fdatasync(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fdatasync(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function lstat(path: string, callback: AsyncCallback\<Stat>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function lstat(path: string, callback: AsyncCallback\<Stat>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function open(path: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function open(path: string, callback: AsyncCallback\<number>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function readText(<br>  filePath: string,<br>  options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<string><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function readText(<br>  filePath: string,<br>  options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<string><br>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function read(<br>  fd: number,<br>  buffer: ArrayBuffer,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>  },<br>  callback: AsyncCallback\<ReadOut><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function read(<br>  fd: number,<br>  buffer: ArrayBuffer,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>  },<br>  callback: AsyncCallback\<ReadOut><br>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function rmdir(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function rmdir(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function stat(path: string, callback: AsyncCallback\<Stat>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function stat(path: string, callback: AsyncCallback\<Stat>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, len: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function truncate(path: string, len: number, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function unlink(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function unlink(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：sourcefile;<br>方法or属性：declare function write(<br>  fd: number,<br>  buffer: ArrayBuffer \| string,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<number><br>): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function write(<br>  fd: number,<br>  buffer: ArrayBuffer \| string,<br>  options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>  },<br>  callback: AsyncCallback\<number><br>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Dir;<br>方法or属性：read(callback: AsyncCallback\<Dirent>): void;<br>旧版本信息：|类名：Dir;<br>方法or属性：read(callback: AsyncCallback\<Dirent>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Dir;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Dir;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：close|@ohos.fileio.d.ts|
|新增(错误码)|类名：Stream;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Stream;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：close|@ohos.fileio.d.ts|
|新增(错误码)|类名：Stream;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Stream;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Stream;<br>方法or属性：write(buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：Stream;<br>方法or属性：write(buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Stream;<br>方法or属性：write(<br>    buffer: ArrayBuffer \| string,<br>    options: {<br>      offset?: number;<br>      length?: number;<br>      position?: number;<br>      encoding?: string;<br>    },<br>    callback: AsyncCallback\<number><br>  ): void;<br>旧版本信息：|类名：Stream;<br>方法or属性：write(<br>    buffer: ArrayBuffer \| string,<br>    options: {<br>      offset?: number;<br>      length?: number;<br>      position?: number;<br>      encoding?: string;<br>    },<br>    callback: AsyncCallback\<number><br>  ): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Stream;<br>方法or属性：read(buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>旧版本信息：|类名：Stream;<br>方法or属性：read(buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Stream;<br>方法or属性：read(<br>    buffer: ArrayBuffer,<br>    options: {<br>      position?: number;<br>      offset?: number;<br>      length?: number;<br>    },<br>    callback: AsyncCallback\<ReadOut><br>  ): void;<br>旧版本信息：|类名：Stream;<br>方法or属性：read(<br>    buffer: ArrayBuffer,<br>    options: {<br>      position?: number;<br>      offset?: number;<br>      length?: number;<br>    },<br>    callback: AsyncCallback\<ReadOut><br>  ): void;<br>新版本信息：Parameter|@ohos.fileio.d.ts|
|新增(错误码)|类名：Watcher;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Watcher;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>新版本信息：stop|@ohos.fileio.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getBundleStats(packageName: string): Promise\<BundleStats>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getBundleStats(packageName: string): Promise\<BundleStats>;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getSystemSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getSystemSize(): Promise\<number>;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getTotalSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getTotalSize(): Promise\<number>;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：storageStatistics;<br>方法or属性：function getFreeSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getFreeSize(): Promise\<number>;<br>新版本信息：systemapi|@ohos.file.storageStatistics.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function getAllVolumes(): Promise\<Array\<Volume>>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getAllVolumes(): Promise\<Array\<Volume>>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function mount(volumeId: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function mount(volumeId: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function unmount(volumeId: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function unmount(volumeId: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function getVolumeById(volumeId: string): Promise\<Volume>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getVolumeById(volumeId: string): Promise\<Volume>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function format(volumeId: string, fsType: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function format(volumeId: string, fsType: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：volumeManager;<br>方法or属性：function partition(diskId: string, type: number): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function partition(diskId: string, type: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|访问级别有变化|类名：Volume;<br>方法or属性：path: string;<br>旧版本信息：|类名：Volume;<br>方法or属性：path: string;<br>新版本信息：systemapi|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getBundleStats(packageName: string): Promise\<BundleStats>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getBundleStats(packageName: string): Promise\<BundleStats>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getSystemSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getSystemSize(): Promise\<number>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getTotalSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getTotalSize(): Promise\<number>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：storageStatistics;<br>方法or属性：function getFreeSize(): Promise\<number>;<br>旧版本信息：|类名：storageStatistics;<br>方法or属性：function getFreeSize(): Promise\<number>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.storageStatistics.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function getAllVolumes(): Promise\<Array\<Volume>>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getAllVolumes(): Promise\<Array\<Volume>>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function mount(volumeId: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function mount(volumeId: string): Promise\<void>;<br>新版本信息：ohos.permission.MOUNT_UNMOUNT_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function unmount(volumeId: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function unmount(volumeId: string): Promise\<void>;<br>新版本信息：ohos.permission.MOUNT_UNMOUNT_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getVolumeByUuid(uuid: string): Promise\<Volume>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function getVolumeById(volumeId: string): Promise\<Volume>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function getVolumeById(volumeId: string): Promise\<Volume>;<br>新版本信息：ohos.permission.STORAGE_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function setVolumeDescription(uuid: string, description: string): Promise\<void>;<br>新版本信息：ohos.permission.MOUNT_UNMOUNT_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function format(volumeId: string, fsType: string): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function format(volumeId: string, fsType: string): Promise\<void>;<br>新版本信息：ohos.permission.MOUNT_FORMAT_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：volumeManager;<br>方法or属性：function partition(diskId: string, type: number): Promise\<void>;<br>旧版本信息：|类名：volumeManager;<br>方法or属性：function partition(diskId: string, type: number): Promise\<void>;<br>新版本信息：ohos.permission.MOUNT_FORMAT_MANAGER|@ohos.file.volumeManager.d.ts|
|权限有变化|类名：fileShare;<br>方法or属性：function grantUriPermission(<br>    uri: string,<br>    bundleName: string,<br>    flag: wantConstant.Flags,<br>    callback: AsyncCallback\<void><br>  ): void;<br>旧版本信息：|类名：fileShare;<br>方法or属性：function grantUriPermission(<br>    uri: string,<br>    bundleName: string,<br>    flag: wantConstant.Flags,<br>    callback: AsyncCallback\<void><br>  ): void;<br>新版本信息：ohos.permission.WRITE_MEDIA|@ohos.fileshare.d.ts|
|权限有变化|类名：fileShare;<br>方法or属性：function grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise\<void>;<br>旧版本信息：|类名：fileShare;<br>方法or属性：function grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise\<void>;<br>新版本信息：ohos.permission.WRITE_MEDIA|@ohos.fileshare.d.ts|
|type有变化|类名：PhotoSelectOptions;<br>方法or属性：MIMEType?: PhotoViewMIMETypes;<br>旧版本信息：PhotoViewMIMETypes|类名：PhotoSelectOptions;<br>方法or属性：MIMEType?: PhotoViewMIMETypes;<br>新版本信息：?PhotoViewMIMETypes|@ohos.file.picker.d.ts|
|type有变化|类名：PhotoSelectOptions;<br>方法or属性：maxSelectNumber?: number;<br>旧版本信息：number|类名：PhotoSelectOptions;<br>方法or属性：maxSelectNumber?: number;<br>新版本信息：?number|@ohos.file.picker.d.ts|
|type有变化|类名：PhotoSaveOptions;<br>方法or属性：newFileNames?: Array\<string>;<br>旧版本信息：Array\<string>|类名：PhotoSaveOptions;<br>方法or属性：newFileNames?: Array\<string>;<br>新版本信息：?Array\<string>|@ohos.file.picker.d.ts|
|type有变化|类名：DocumentSaveOptions;<br>方法or属性：newFileNames?: Array\<string>;<br>旧版本信息：Array\<string>|类名：DocumentSaveOptions;<br>方法or属性：newFileNames?: Array\<string>;<br>新版本信息：?Array\<string>|@ohos.file.picker.d.ts|
|type有变化|类名：AudioSaveOptions;<br>方法or属性：newFileNames?: Array\<string>;<br>旧版本信息：Array\<string>|类名：AudioSaveOptions;<br>方法or属性：newFileNames?: Array\<string>;<br>新版本信息：?Array\<string>|@ohos.file.picker.d.ts|
