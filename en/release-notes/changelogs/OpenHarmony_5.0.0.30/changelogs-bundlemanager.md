# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Type of the data Field in the RouterItem Struct and in the Routing Table Configuration File Is Changed

**Access Level**

Public API

**Reason for Change**

An incompatible change is introduced in the [data field change in the routing table](../OpenHarmony_5.0.0.24/changelogs-bundlemanager.md), and this incompatible change is rolled back.

**Change Impact**

This change is a non-compatible change. If you use any type of user-defined data in the routing table configuration file, a compilation error is reported. The build will fail if you do not change the type of the **data** field in your code.

**Change Since**

OpenHarmony SDK 5.0.0.30

**Key API/Component Changes**

Previously, the **data** field in the routing table configuration file can be set to user-defined data of any data type. From now on, it can be set to only user-defined data of the string type. The type of the **data** field in the **RouterItem** struct provided by the bundleManager module is changed to a DataItem array.

**Adaptation Guide**

In the routing table configuration file, the **data** field can be configured only with key-value pairs of the string type. If you want to configure any type of user-defined data, use the **customData** field.
If the **data** field in the **RouterItem** struct provided by the bundleManager module is used in your code, change the field type.
