# Common Events of the Bundle Management Subsystem
This document lists the common system events provided by the Bundle Management subsystem to applications.

## COMMON_EVENT_PACKAGE_ADDED

Indicates that a new application package has been installed on the device.

- Value: "usual.event.PACKAGE_ADDED"
- Required subscriber permissions: none

When a new application is installed by a specified user on the device, the event notification service is triggered to publish this event.

APIs related to this event: **install**. For details, see [API Reference](../js-apis-installer.md#bundleinstallerinstall).

## COMMON_EVENT_PACKAGE_REMOVED

Indicates that an application has been uninstalled from the device with the application data retained.

- Value: "usual.event.PACKAGE_REMOVED"
- Required subscriber permissions: none

When a specified application package is removed by a specified user on the device, the event notification service is triggered to publish this event.

APIs related to this event: **uninstall**. For details, see [API Reference](../js-apis-installer.md#bundleinstalleruninstall).

## COMMON_EVENT_PACKAGE_CHANGED

Indicates that an application package has been changed (for example, an ability in the package has been enabled or disabled).

- Value: "usual.event.PACKAGE_CHANGED"
- Required subscriber permissions: none

When an application package installed on the device is updated or an ability in the package is enabled or disabled, the event notification service is triggered to publish this event.

APIs related to this event: **setApplicationEnabled** and **setAbilityEnabled**. For details, see [API Reference](../js-apis-bundleManager.md#bundlemanagersetapplicationenabled).

## COMMON_EVENT_PACKAGE_CACHE_CLEARED

Indicates that the user cleared the application package cache.

- Value: "usual.event.PACKAGE_CACHE_CLEARED"
- Required subscriber permissions: none

When the cache of an application package installed on the device is cleared, the event notification service is triggered to publish this event.

APIs related to this event: **cleanBundleCacheFiles**. For details, see [API Reference](../js-apis-bundleManager.md#bundlemanagercleanbundlecachefiles).
