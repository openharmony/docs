# 文件管理子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，文件管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.securityLabel | securityLabel | function getSecurityLabelSync(path:string): string; | 新增 |
| ohos.securityLabel | securityLabel | function getSecurityLabel(path:string, callback: AsyncCallback<string>): void;<br>function getSecurityLabel(path:string): Promise<string>; | 新增 |
| ohos.securityLabel | securityLabel | function setSecurityLabelSync(path:string, type:dataLevel): void; | 新增 |
| ohos.securityLabel | securityLabel | function setSecurityLabel(path:string, type:dataLevel, callback: AsyncCallback<void>): void;<br>function setSecurityLabel(path:string, type:dataLevel): Promise<void>; | 新增 |
| ohos.storageStatistics | storageStatistics | function getFreeSize(callback: AsyncCallback<number>): void;<br>function getFreeSize(): Promise<number>; | 新增 |
| ohos.storageStatistics | storageStatistics | function getTotalSize(callback: AsyncCallback<number>): void;<br>function getTotalSize(): Promise<number>; | 新增 |
| ohos.storageStatistics | storageStatistics | function getUserStorageStats(userId?: number): Promise<StorageStats>;<br>function getUserStorageStats(callback: AsyncCallback<StorageStats>): void;<br>function getUserStorageStats(userId: number, callback: AsyncCallback<StorageStats>): void; | 新增 |
| ohos.storageStatistics | StorageStats | app: number; | 新增 |
| ohos.storageStatistics | StorageStats | file: number; | 新增 |
| ohos.storageStatistics | StorageStats | image: number; | 新增 |
| ohos.storageStatistics | StorageStats | video: number; | 新增 |
| ohos.storageStatistics | StorageStats | audio: number; | 新增 |
| ohos.storageStatistics | StorageStats | total: number; | 新增 |
| ohos.storageStatistics | storageStatistics | function getSystemSize(callback: AsyncCallback<number>): void;<br>function getSystemSize(): Promise<number>; | 新增 |
| ohos.storageStatistics | storageStatistics | function getCurrentBundleStats(callback: AsyncCallback<BundleStats>): void;<br>function getCurrentBundleStats(): Promise<BundleStats>; | 新增 |
| ohos.storageStatistics | storageStatistics | function getBundleStats(packageName: string,  callback: AsyncCallback<BundleStats>): void;<br>function getBundleStats(packageName: string): Promise<BundleStats>; | 新增 |
| ohos.storageStatistics | BundleStats | dataSize: number; | 新增 |
| ohos.storageStatistics | BundleStats | cacheSize: number; | 新增 |
| ohos.storageStatistics | BundleStats | appSize: number; | 新增 |
| ohos.volumeManager | volumeManager | function partition(volId: string, fstype: string, callback: AsyncCallback<void>): void;<br>function partition(volId: string, fstype: string): Promise<void>; | 新增 |
| ohos.volumeManager | volumeManager | function format(volId: string, callback: AsyncCallback<void>): void;<br>function format(volId: string): Promise<void>; | 新增 |
| ohos.volumeManager | volumeManager | function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback<void>): void;<br>function setVolumeDescription(uuid: string, description: string): Promise<void>; | 新增 |
| ohos.volumeManager | volumeManager | function getVolumeById(id: string, callback: AsyncCallback<Volume>): void;<br>function getVolumeById(id: string): Promise<Volume>; | 新增 |
| ohos.volumeManager | volumeManager | function getVolumeByUuid(uuid: string, callback: AsyncCallback<Volume>): void;<br>function getVolumeByUuid(uuid: string): Promise<Volume>; | 新增 |
| ohos.volumeManager | volumeManager | function unmount(volumeId: string, callback: AsyncCallback<boolean>): void;<br>function unmount(volumeId: string): Promise<boolean>; | 新增 |
| ohos.volumeManager | volumeManager | function mount(volumeId: string, callback: AsyncCallback<boolean>): void;<br>function mount(volumeId: string): Promise<boolean>; | 新增 |
| ohos.volumeManager | volumeManager | function getAllVolumes(callback: AsyncCallback<Array<Volume>>): void;<br>function getAllVolumes(): Promise<Array<Volume>>; | 新增 |
| ohos.volumeManager | Volume | path: string; | 新增 |
| ohos.volumeManager | Volume | state: number; | 新增 |
| ohos.volumeManager | Volume | removable: boolean; | 新增 |
| ohos.volumeManager | Volume | description: string; | 新增 |
| ohos.volumeManager | Volume | uuid: string; | 新增 |
| ohos.volumeManager | Volume | id: string; | 新增 |

