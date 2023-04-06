# Native API Differences

The table below lists the native APIs changes in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## Standard System API Changes

| Module| API                                                    | Change Type| Change Description                                       |
| -------- | ------------------------------------------------------------ | -------- | ----------------------------------------------- |
| Bundle Management - BundleFramework| OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo() | Added    | Added the APIs for obtaining the bundle name and fingerprint information of the current application.|
| Graphics - NativeWindow| int32_t OH_NativeWindow_NativeWindowSetScalingMode(OHNativeWindow *window, uint32_t sequence, OHScalingMode scalingMode) | Added| Added the API for setting the scaling mode.|
| Graphics - NativeWindow| int32_t OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow *window, uint32_t sequence, int32_t size, const OHHDRMetaData *metaData) | Added| Added the API for setting the HDR metadata.|
| Graphics - NativeWindow| int32_t OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t *metaData) | Added| Added the API for setting the HDR metadata set.|
| Graphics - NativeWindow| int32_t OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow *window, const OHExtDataHandle *handle) | Added| Added the API for setting the tunnel handle.|
