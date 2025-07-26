# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 zlib.unzipFile and zlib.decompressFile Changed

**Access Level**

Public API

**Reason for Change**

During file decompression, the system intercepts compressed packages that do not meet the format requirements to avoid unexpected decompressed files.


**Change Impact**

This change requires application adaptation.

Before the change, incorrectly formatted compressed packages can be decompressed, but the decompressed content does not meet expectations.

After the change, decompression of incorrectly formatted compressed packages fails, and an error code indicating incorrect file format is thrown.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 6.0.0.39

**Key API/Component Changes**

[zlib.unzipFile](../../../application-dev/reference/apis-basic-services-kit/js-apis-zlib.md#zlibunzipfiledeprecated) and [zlib.decompressFile](../../../application-dev/reference/apis-basic-services-kit/js-apis-zlib.md#zlibdecompressfile10).


**Adaptation Guide**

When calling the **zlib.unzipFile** and **zlib.decompressFile** APIs, you need to catch interface exceptions, handle them based on the returned error code, and check for errors in the input compressed package.


## cl.bundlemanager.2 Parameter Type Changed for getDeveloperIds and sharedBundleDirPaths

**Access Level**

System API

**Reason for Change**

The return type of [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) and the parameter type of [sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam) are actually Array\<string>, but the APIs are declared as Array\<String>, which does not match the actual types and needs to be corrected.


**Change Impact**

This change requires application adaptation.

Before the change, the return type of [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) and the parameter type of [sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam) are Array\<String>. Applications can call them with the Array\<String> type, and the compilation can pass, but an exception is thrown at runtime.

After the change, the return type of [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) and the parameter type of [sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam) are Array\<string>. Applications can only call them with the Array\<string> type, and both compilation and runtime execution are normal.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 6.0.0.39

**Key API/Component Changes**

| Name| Before Change| After Change|
| -------- | -------- | ---|
| [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) | function getDeveloperIds(appDistributionType?: number): Array\<String> | function getDeveloperIds(appDistributionType?: number): Array\<string> |
| [InstallParam.sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam) | sharedBundleDirPaths?: Array\<String> | sharedBundleDirPaths?: Array\<string> |


**Adaptation Guide**

1. If the application uses the return value of [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) as an [getDeveloperIds](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetdeveloperids12) object, it needs to be changed to use it as an Array\<string>.
2. If the application uses the parameter of [InstallParam.sharedBundleDirPaths](../../../application-dev/reference/apis-ability-kit/js-apis-installer-sys.md#installparam) as an Array\<String> object, it needs to be changed to use it as an Array\<string>.


## cl.bundlemanager.3 enableDynamicIcon Changed

**Access Level**

System API

**Reason for Change**

To ensure that custom theme application icons have a higher priority than dynamic icons, after the change, if the application has a custom theme icon, calling the enable dynamic icon interface will fail, and the application icon on the home screen will not switch to a dynamic icon.


**Change Impact**

This change requires application adaptation.

Before the change, when custom theme application icon resources exist, the application can successfully call the **enableDynamicIcon** API.

After the change, when custom theme application icon resources exist, calling the **enableDynamicIcon** API fails, and error code 17700307 is thrown.


**Start API Level**

12

**Change Since**

OpenHarmony SDK 6.0.0.39

**Key API/Component Changes**

[enableDynamicIcon](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagerenabledynamicicon12)


**Adaptation Guide**

Applications need to catch the newly added error code 17700307 and handle it.


## cl.bundlemanager.4 Behavior Changed and Control Increased for Ability Kit Related Common Events

**Access Level**

Public API

**Reason for Change**

Some common events in Ability Kit contain application information, which poses a security risk of information leakage and requires increased control.

**Change Impact**

This change requires application adaptation.

Controls are added for subscribers of the following common events: [COMMON_EVENT_PACKAGE_ADDED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_added), [COMMON_EVENT_PACKAGE_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_removed), [COMMON_EVENT_PACKAGE_CHANGED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_changed), [COMMON_EVENT_PACKAGE_RESTARTED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_restarted), [COMMON_EVENT_PACKAGE_DATA_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_data_cleared), [COMMON_EVENT_PACKAGE_CACHE_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_cache_cleared), and [COMMON_EVENT_QUICK_FIX_APPLY_RESULT](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_quick_fix_apply_result).

Before the change, both system applications and third-party applications can listen for these events.

After the change, system applications can listen for events for their own applications and other applications, whereas third-party applications can only listen for events for their own applications.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 6.0.0.39

**Key API/Component Changes**

Changed common events:
| Event Name| Description|
| -------- | -------- |
| [COMMON_EVENT_PACKAGE_ADDED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_added) | Event indicating that an application is installed.|
| [COMMON_EVENT_PACKAGE_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_removed) | Event indicating that an application is uninstalled.|
| [COMMON_EVENT_PACKAGE_CHANGED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_changed) | Event indicating that an application is updated.|
| [COMMON_EVENT_PACKAGE_RESTARTED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_restarted) | Event indicating that an application is restarted.|
| [COMMON_EVENT_PACKAGE_DATA_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_data_cleared) | Event indicating that the application data is cleared.|
| [COMMON_EVENT_PACKAGE_CACHE_CLEARED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_cache_cleared) | Event indicating that the application cache data is cleared.|
| [COMMON_EVENT_QUICK_FIX_APPLY_RESULT](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_quick_fix_apply_result) | Event indicating that the application enables the quick fix package.|


**Adaptation Guide**

If you use the above common events to determine whether an application is installed, switch to using the [canOpenLink](../../../application-dev/reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagercanopenlink12) API to check whether the application exists.
