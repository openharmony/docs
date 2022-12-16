# 文件管理子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，文件管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.volumeManager | Volume | diskId: string; | 新增 |
| ohos.volumeManager | volumeManager | partition(volId: string, fstype: string, callback: AsyncCallback\<void>): void;<br>partition(volId: string, fstype: string): Promise\<void>; | 变更 |
| ohos.volumeManager | volumeManager | format(volId: string, callback: AsyncCallback\<void>): void;<br>format(volId: string): Promise\<void>; | 变更 |
| ohos.volumeManager | volumeManager | old :<br>getVolumeById(id: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeById(id: string): Promise\<Volume>;<br>new :<br>getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeById(volumeId: string): Promise\<Volume> | 变更 |
| ohos.volumeManager | volumeManager | old :<br>format(volId: string, callback: AsyncCallback\<void>): void;<br>format(volId: string): Promise\<void>;<br>new :<br>format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;<br>format(volumeId: string, fsType: string): Promise\<void>; | 变更 |
| ohos.volumeManager | volumeManager | old :<br>partition(volId: string, fstype: string, callback: AsyncCallback\<void>): void;<br>partition(volId: string, fstype: string): Promise\<void>;<br>new :<br>partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;<br>partition(diskId: string, type: number): Promise\<void>; | 变更 |