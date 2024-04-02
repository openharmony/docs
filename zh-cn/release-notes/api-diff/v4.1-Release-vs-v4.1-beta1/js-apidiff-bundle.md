| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增API|NA|类名：bundleManager；<br>API声明：function deleteAbc(abcPath: string): Promise\<void>;<br>差异内容：function deleteAbc(abcPath: string): Promise\<void>;|api/@ohos.bundle.bundleManager.d.ts|
|新增API|NA|类名：HapModuleInfo；<br>API声明：readonly fileContextMenuConfig: string;<br>差异内容：readonly fileContextMenuConfig: string;|api/bundleManager/HapModuleInfo.d.ts|
|删除API|类名：bundleManager；<br>API声明： export enum ApplicationReservedFlag<br>差异内容： export enum ApplicationReservedFlag|NA|api/@ohos.bundle.bundleManager.d.ts|
|删除API|类名：ApplicationReservedFlag；<br>API声明：ENCRYPTED_APPLICATION = 0x00000001<br>差异内容：ENCRYPTED_APPLICATION = 0x00000001|NA|api/@ohos.bundle.bundleManager.d.ts|
|删除API|类名：ApplicationInfo；<br>API声明：readonly applicationReservedFlag: number;<br>差异内容：readonly applicationReservedFlag: number;|NA|api/bundleManager/ApplicationInfo.d.ts|
|删除API|类名：HapModuleInfo；<br>API声明：readonly fileContextMenu: string;<br>差异内容：readonly fileContextMenu: string;|NA|api/bundleManager/HapModuleInfo.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.bundle.bundleManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.bundle.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.bundle.defaultAppManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.bundle.overlay.d.ts|
|kit变更|Basic Services Kit|BasicServicesKit|api/@ohos.zlib.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@system.package.d.ts|
