# Native API Differences

This document describes the changes of APIs in OpenHarmony 3.1 Beta when compared with OpenHarmony 3.0 LTS.

## Standard System API Changes

| Module| API| Change Type| Change Description|
| ------------------ | ------------------------------------------------------------ | -------- | ------------------------------------------------- |
| bundle             | napi_value ClearBundleCache(napi_env env, napi_callback_info info) | Added| Added the API for clearing the cache of an application.|
| bundle             | napi_value SetApplicationEnabled(napi_env env, napi_callback_info info) | Added| Added the API for setting whether to enable an application.|
| bundle             | napi_value SetAbilityEnabled(napi_env env, napi_callback_info info) | Added| Added the API for setting whether to enable an ability.|
| innerbundlemanager | napi_value JSGetLauncherAbilityInfos(napi_env env, napi_callback_info info) | Added| Added the API for obtaining the launcher ability information by **bundleName**.|
| innerbundlemanager | napi_value JSLauncherServiceOn(napi_env env, napi_callback_info info) | Added| Added the API for subscribing to bundle status changes.|
| innerbundlemanager | napi_value JSLauncherServiceOff(napi_env env, napi_callback_info info) | Added| Added the API for unsubscribing from bundle status changes.|
| innerbundlemanager | napi_value JSGetAllLauncherAbilityInfos(napi_env env, napi_callback_info info) | Added| Added the API for obtaining the application abilities on all launchers by **userId**.|
| innerbundlemanager | napi_value JSGetShortcutInfos(napi_env env, napi_callback_info info) | Added| Added the API for obtaining the application shortcut information by **bundleName**.|
