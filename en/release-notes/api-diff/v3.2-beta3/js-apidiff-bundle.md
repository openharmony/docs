# JS API Changes of the Bundle Management Framework

The table below lists the APIs changes of the bundle management framework in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| dispatchInfo | DispatchInfo         | readonly version: string;                                                                                                                                                                                  | Added|
| ohos.bundle  | bundle               | function getBundleInfoSync(bundleName: string, bundleFlags: number, options: BundleOptions): BundleInfo;<br>function getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo;               | Added|
| ohos.bundle  | bundle               | function getApplicationInfoSync(bundleName: string, bundleFlags: number, userId: number) : ApplicationInfo;<br>function getApplicationInfoSync(bundleName: string, bundleFlags: number) : ApplicationInfo; | Added|
| ohos.bundle  | ExtensionAbilityType | PREVIEW = 14                                                                                                                                                                                               | Added|
| ohos.bundle  | ExtensionAbilityType | THUMBNAIL = 13                                                                                                                                                                                             | Added|
| dispatchInfo | DispatchInfo | readonly verison: string; | Deleted|
