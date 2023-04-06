# 文件管理子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，文件管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.securityLabel | securityLabel | getSecurityLabelSync(path:string): string; | 新增 |
| ohos.securityLabel | securityLabel | getSecurityLabel(path:string, callback: AsyncCallback\<string>): void;<br>getSecurityLabel(path:string): Promise\<string>; | 新增 |
| ohos.securityLabel | securityLabel | setSecurityLabelSync(path:string, type:dataLevel): void; | 新增 |
| ohos.securityLabel | securityLabel | setSecurityLabel(path:string, type:dataLevel, callback: AsyncCallback\<void>): void;<br>setSecurityLabel(path:string, type:dataLevel): Promise\<void>; | 新增 |
| ohos.storageStatistics | storageStatistics | getFreeSize(callback: AsyncCallback\<number>): void;<br>getFreeSize(): Promise\<number>; | 新增 |
| ohos.storageStatistics | storageStatistics | getTotalSize(callback: AsyncCallback\<number>): void;<br>getTotalSize(): Promise\<number>; | 新增 |
| ohos.storageStatistics | storageStatistics | getUserStorageStats(userId?: number): Promise\<StorageStats>;<br>getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void; | 新增 |
| ohos.storageStatistics | StorageStats | app: number; | 新增 |
| ohos.storageStatistics | StorageStats | file: number; | 新增 |
| ohos.storageStatistics | StorageStats | image: number; | 新增 |
| ohos.storageStatistics | StorageStats | video: number; | 新增 |
| ohos.storageStatistics | StorageStats | audio: number; | 新增 |
| ohos.storageStatistics | StorageStats | total: number; | 新增 |
| ohos.storageStatistics | storageStatistics | getSystemSize(callback: AsyncCallback\<number>): void;<br>getSystemSize(): Promise\<number>; | 新增 |
| ohos.storageStatistics | storageStatistics | getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;<br>getCurrentBundleStats(): Promise\<BundleStats>; | 新增 |
| ohos.storageStatistics | storageStatistics | getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;<br>getBundleStats(packageName: string): Promise\<BundleStats>; | 新增 |
| ohos.storageStatistics | BundleStats | dataSize: number; | 新增 |
| ohos.storageStatistics | BundleStats | cacheSize: number; | 新增 |
| ohos.storageStatistics | BundleStats | appSize: number; | 新增 |
| ohos.volumeManager | volumeManager | partition(volId: string, fstype: string, callback: AsyncCallback\<void>): void;<br>partition(volId: string, fstype: string): Promise\<void>; | 新增 |
| ohos.volumeManager | volumeManager | format(volId: string, callback: AsyncCallback\<void>): void;<br>format(volId: string): Promise\<void>; | 新增 |
| ohos.volumeManager | volumeManager | setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;<br>setVolumeDescription(uuid: string, description: string): Promise\<void>; | 新增 |
| ohos.volumeManager | volumeManager | getVolumeById(id: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeById(id: string): Promise\<Volume>; | 新增 |
| ohos.volumeManager | volumeManager | getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeByUuid(uuid: string): Promise\<Volume>; | 新增 |
| ohos.volumeManager | volumeManager | unmount(volumeId: string, callback: AsyncCallback\<boolean>): void;<br>unmount(volumeId: string): Promise\<boolean>; | 新增 |
| ohos.volumeManager | volumeManager | mount(volumeId: string, callback: AsyncCallback\<boolean>): void;<br>mount(volumeId: string): Promise\<boolean>; | 新增 |
| ohos.volumeManager | volumeManager | getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;<br>getAllVolumes(): Promise\<Array\<Volume>>; | 新增 |
| ohos.volumeManager | Volume | path: string; | 新增 |
| ohos.volumeManager | Volume | state: number; | 新增 |
| ohos.volumeManager | Volume | removable: boolean; | 新增 |
| ohos.volumeManager | Volume | description: string; | 新增 |
| ohos.volumeManager | Volume | uuid: string; | 新增 |
| ohos.volumeManager | Volume | id: string; | 新增 |

