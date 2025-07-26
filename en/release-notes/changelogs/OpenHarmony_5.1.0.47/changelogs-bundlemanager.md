# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 installSource Field Specification Change

**Access Level**

Public API

**Reason for Change**

The **installSource** field is updated to allow you to determine whether an application is a preset one.

**Impact of the Change**

This change requires application adaptation.

Before the change:
The value of **installSource** changes with application updates.

Values of **installSource** before change:
- **pre-installed**: The application is a preset one installed at initial device startup.
- Bundle name of an application: The preset application is installed from the application mapping to the bundle name.
- **unknown**: The installation source is unknown.

After the change:
The value of **installSource** does not change with application updates.

Values of **installSource** after change:
- **pre-installed**: The application is a preset one installed at initial device startup.
- **ota**: The application is a preset one added during system upgrade.
- **recovery**: The preset application is uninstalled and then restored.
- Bundle name of an application: The preset application is installed from the application mapping to the bundle name.
- **unknown**: The installation source is unknown.

For example, if a preset application whose **installSource** is **pre-installed** is updated on AppGallery, **installSource** is changed to the AppGallery app package name before change and retained as **pre-installed** after change.

**Start API Level**

API 12

**Change Since**

OpenHarmony 5.1.0.47

**Key API/Component Changes**

**installSource** field in [ApplicationInfo](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md)

**Adaptation Guide**

Adapt the preset application to the new specifications. This way, you can determine whether an application is a preset one based on the **installSource** field in [ApplicationInfo](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md).
