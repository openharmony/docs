# Native API 差异报告

OpenHarmony 3.2 Beta2相较于OpenHarmony 3.2 Beta1版本的API变更如下:

## 标准系统接口变更

| 模块名称 | 接口名称                                                     | 变更类型 | 变更说明                                        |
| -------- | ------------------------------------------------------------ | -------- | ----------------------------------------------- |
| 包管理-BundleFramework | OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo() | 新增     | 获取当前应用的包名和指纹信息 |
| 图形-NativeWindow | int32_t OH_NativeWindow_NativeWindowSetScalingMode(OHNativeWindow *window, uint32_t sequence, OHScalingMode scalingMode) | 新增 | 新增通过NativeWindow设置缩放模式的接口 |
| 图形-NativeWindow | int32_t OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow *window, uint32_t sequence, int32_t size, const OHHDRMetaData *metaData) | 新增 | 新增通过NativeWindow设置HDR元数据的接口 |
| 图形-NativeWindow | int32_t OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t *metaData) | 新增 | 新增通过NativeWindow设置HDR元数据集的接口 |
| 图形-NativeWindow | int32_t OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow *window, const OHExtDataHandle *handle) | 新增 | 新增通过NativeWindow设置tunnelhandle的接口 |