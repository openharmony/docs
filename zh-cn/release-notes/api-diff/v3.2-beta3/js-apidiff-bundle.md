# 包管理子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，包管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| dispatchInfo | DispatchInfo         | readonly version: string;                                                                                                                                                                                  | 新增 |
| ohos.bundle  | bundle               | function getBundleInfoSync(bundleName: string, bundleFlags: number, options: BundleOptions): BundleInfo;<br>function getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo;               | 新增 |
| ohos.bundle  | bundle               | function getApplicationInfoSync(bundleName: string, bundleFlags: number, userId: number) : ApplicationInfo;<br>function getApplicationInfoSync(bundleName: string, bundleFlags: number) : ApplicationInfo; | 新增 |
| ohos.bundle  | ExtensionAbilityType | PREVIEW = 14                                                                                                                                                                                               | 新增 |
| ohos.bundle  | ExtensionAbilityType | THUMBNAIL = 13                                                                                                                                                                                             | 新增 |
| dispatchInfo | DispatchInfo | readonly verison: string; | 删除 |