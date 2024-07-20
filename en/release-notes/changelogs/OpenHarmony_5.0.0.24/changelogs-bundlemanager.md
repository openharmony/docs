# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Type of the data Field in RouterItem Is Changed

**Access Level**

Public API

**Change Reason**

In the previous routing table configuration file, only a key of the string type can be configured for the **data** field. The query interface provided by the bundle manager module parses the field value. In this version, this restriction is removed, and the field can be set to a JSON string of any type. The query interface does not parse the field value. Instead, it returns the JSON string, which needs to be parsed by the caller. The type of the **data** field in the query interface is changed from a DataItem array to a string.

**Change Impact**

This change is a non-compatible change. The build will fail if you do not change the type of the **data** field in your code.

**Change Since**

OpenHarmony SDK 5.0.0.24

**Key API/Component Changes**

The type of the **data** field in the **RouterItem** struct provided by the bundle manager module is changed from a DataItem array to a string.

**Adaptation Guide**

Manually parse the JSON string in **data**.

## cl.bundlemanager.2 Third-Party Applications Cannot Be Installed on Illegally Activated Devices

**Access Level**

Other

**Change Reason**

For security purposes, application installation on devices that are activated through illegal channels should be restricted.

**Change Impact**

This change is a non-compatible change. Third-party applications can no longer be installed on illegally activated devices.

**Change Since**

OpenHarmony SDK 5.0.0.24

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

No adaptation is required. Just notice that third-party applications can no longer be installed on illegally activated devices.
