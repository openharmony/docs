# JS API Changes of the File Management Subsystem

The table below lists the APIs changes of the file management subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.securityLabel | securityLabel | getSecurityLabelSync(path:string): string; | Added|
| ohos.securityLabel | securityLabel | getSecurityLabel(path:string, callback: AsyncCallback\<string>): void;<br>getSecurityLabel(path:string): Promise\<string>; | Added|
| ohos.securityLabel | securityLabel | setSecurityLabelSync(path:string, type:dataLevel): void; | Added|
| ohos.securityLabel | securityLabel | setSecurityLabel(path:string, type:dataLevel, callback: AsyncCallback\<void>): void;<br>setSecurityLabel(path:string, type:dataLevel): Promise\<void>; | Added|
| ohos.storageStatistics | storageStatistics | getFreeSize(callback: AsyncCallback\<number>): void;<br>getFreeSize(): Promise\<number>; | Added|
| ohos.storageStatistics | storageStatistics | getTotalSize(callback: AsyncCallback\<number>): void;<br>getTotalSize(): Promise\<number>; | Added|
| ohos.storageStatistics | storageStatistics | getUserStorageStats(userId?: number): Promise\<StorageStats>;<br>getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;<br>getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void; | Added|
| ohos.storageStatistics | StorageStats | app: number; | Added|
| ohos.storageStatistics | StorageStats | file: number; | Added|
| ohos.storageStatistics | StorageStats | image: number; | Added|
| ohos.storageStatistics | StorageStats | video: number; | Added|
| ohos.storageStatistics | StorageStats | audio: number; | Added|
| ohos.storageStatistics | StorageStats | total: number; | Added|
| ohos.storageStatistics | storageStatistics | getSystemSize(callback: AsyncCallback\<number>): void;<br>getSystemSize(): Promise\<number>; | Added|
| ohos.storageStatistics | storageStatistics | getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;<br>getCurrentBundleStats(): Promise\<BundleStats>; | Added|
| ohos.storageStatistics | storageStatistics | getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;<br>getBundleStats(packageName: string): Promise\<BundleStats>; | Added|
| ohos.storageStatistics | BundleStats | dataSize: number; | Added|
| ohos.storageStatistics | BundleStats | cacheSize: number; | Added|
| ohos.storageStatistics | BundleStats | appSize: number; | Added|
| ohos.volumeManager | volumeManager | partition(volId: string, fstype: string, callback: AsyncCallback\<void>): void;<br>partition(volId: string, fstype: string): Promise\<void>; | Added|
| ohos.volumeManager | volumeManager | format(volId: string, callback: AsyncCallback\<void>): void;<br>format(volId: string): Promise\<void>; | Added|
| ohos.volumeManager | volumeManager | setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;<br>setVolumeDescription(uuid: string, description: string): Promise\<void>; | Added|
| ohos.volumeManager | volumeManager | getVolumeById(id: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeById(id: string): Promise\<Volume>; | Added|
| ohos.volumeManager | volumeManager | getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeByUuid(uuid: string): Promise\<Volume>; | Added|
| ohos.volumeManager | volumeManager | unmount(volumeId: string, callback: AsyncCallback\<boolean>): void;<br>unmount(volumeId: string): Promise\<boolean>; | Added|
| ohos.volumeManager | volumeManager | mount(volumeId: string, callback: AsyncCallback\<boolean>): void;<br>mount(volumeId: string): Promise\<boolean>; | Added|
| ohos.volumeManager | volumeManager | getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;<br>getAllVolumes(): Promise\<Array\<Volume>>; | Added|
| ohos.volumeManager | Volume | path: string; | Added|
| ohos.volumeManager | Volume | state: number; | Added|
| ohos.volumeManager | Volume | removable: boolean; | Added|
| ohos.volumeManager | Volume | description: string; | Added|
| ohos.volumeManager | Volume | uuid: string; | Added|
| ohos.volumeManager | Volume | id: string; | Added|
