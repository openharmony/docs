# 文件管理子系统JS API变更

OpenHarmony 3.2 Canary1版本相较于OpenHarmony 3.1 Release版本，文件管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.storageStatistics | storageStatistics | getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;<br>getBundleStats(packageName: string): Promise\<BundleStats>; | 新增 |
| ohos.storageStatistics | BundleStats | dataSize: number; | 新增 |
| ohos.storageStatistics | BundleStats | cacheSize: number; | 新增 |
| ohos.storageStatistics | BundleStats | appSize: number; | 新增 |
| ohos.volumeManager | volumeManager | unmount(volumeId: string, callback: AsyncCallback\<boolean>): void;<br>unmount(volumeId: string): Promise\<boolean>; | 新增 |
| ohos.volumeManager | volumeManager | mount(volumeId: string, callback: AsyncCallback\<boolean>): void;<br>mount(volumeId: string): Promise\<boolean>; | 新增 |
| ohos.volumeManager | volumeManager | getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;<br>getAllVolumes(): Promise\<Array\<Volume>>; | 新增 |
| ohos.volumeManager | Volume | path: string; | 新增 |
| ohos.volumeManager | Volume | state: number; | 新增 |
| ohos.volumeManager | Volume | removable: boolean; | 新增 |
| ohos.volumeManager | Volume | description: string; | 新增 |
| ohos.volumeManager | Volume | uuid: string; | 新增 |
| ohos.volumeManager | Volume | id: string; | 新增 |

