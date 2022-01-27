# Native API 差异报告

OpenHarmony 3.1 Beta相较于OpenHarmony 3.0 LTS版本的API变更如下:

## 标准系统接口变更

| 模块名称           | 接口名称                                                     | 变更类型 | 变更说明                                          |
| ------------------ | ------------------------------------------------------------ | -------- | ------------------------------------------------- |
| bundle             | napi_value ClearBundleCache(napi_env env, napi_callback_info info) | 新增     | 新增清理应用缓存接口                              |
| bundle             | napi_value SetApplicationEnabled(napi_env env, napi_callback_info info) | 新增     | 新增设置应用使能接口                              |
| bundle             | napi_value SetAbilityEnabled(napi_env env, napi_callback_info info) | 新增     | 新增设置ability使能接口                           |
| innerbundlemanager | napi_value JSGetLauncherAbilityInfos(napi_env env, napi_callback_info info) | 新增     | 新增通过包名获取应用LauncherAbility接口           |
| innerbundlemanager | napi_value JSLauncherServiceOn(napi_env env, napi_callback_info info) | 新增     | 新增注册监听包状态变化接口                        |
| innerbundlemanager | napi_value JSLauncherServiceOff(napi_env env, napi_callback_info info) | 新增     | 新增注销监听包状态变化接口                        |
| innerbundlemanager | napi_value JSGetAllLauncherAbilityInfos(napi_env env, napi_callback_info info) | 新增     | 新增通过userId获取所有launcher上应用的ability接口 |
| innerbundlemanager | napi_value JSGetShortcutInfos(napi_env env, napi_callback_info info) | 新增     | 新增通过bundleName获取应用的shortcutInfo接口      |