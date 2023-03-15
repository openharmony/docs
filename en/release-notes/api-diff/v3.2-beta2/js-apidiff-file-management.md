# JS API Changes of the File Management Subsystem

The table below lists the APIs changes of the file management subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.volumeManager | Volume | diskId: string; | Added|
| ohos.volumeManager | volumeManager | partition(volId: string, fstype: string, callback: AsyncCallback\<void>): void;<br>partition(volId: string, fstype: string): Promise\<void>; | Updated|
| ohos.volumeManager | volumeManager | format(volId: string, callback: AsyncCallback\<void>): void;<br>format(volId: string): Promise\<void>; | Updated|
| ohos.volumeManager | volumeManager | old :<br>getVolumeById(id: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeById(id: string): Promise\<Volume>;<br>new :<br>getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;<br>getVolumeById(volumeId: string): Promise\<Volume> | Updated|
| ohos.volumeManager | volumeManager | old :<br>format(volId: string, callback: AsyncCallback\<void>): void;<br>format(volId: string): Promise\<void>;<br>new :<br>format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;<br>format(volumeId: string, fsType: string): Promise\<void>; | Updated|
| ohos.volumeManager | volumeManager | old :<br>partition(volId: string, fstype: string, callback: AsyncCallback\<void>): void;<br>partition(volId: string, fstype: string): Promise\<void>;<br>new :<br>partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;<br>partition(diskId: string, type: number): Promise\<void>; | Updated|
