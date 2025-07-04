# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Prohibition of shortcutId Field Configuration via a Resource Index (Starting with $Character) in the Shortcut Configuration File

**Access Level**

Public API

**Reason for Change**

The [shortcutId field](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/module-configuration-file.md#shortcuts) cannot be configured via a resource index (starting with **$**) in the application shortcut configuration file.

**Impact of the Change**

Application adaptation is required.

Before change: **shortcutId** fields can be configured via a resource index (starting with **$**) in the application shortcut configuration file.

After change: **shortcutId** fields cannot be configured via a resource index (starting with **$**) in the application shortcut configuration file.

**Start API Level**

API 8

**Change Since**

OpenHarmony 5.1.0.50

**Key API/Component Changes**

**shortcuts** in **module.json5**

**Adaptation Guide**

Do not configure **shortcutId** fields with a resource index (starting with **$**) in the application shortcut configuration file. Use a regular string (not starting with **$**) instead.
