# Common Type Changelog

## c1.commonType.1 Asset Property Type Change

**Access Level**

Public API

**Reason for Change**

Data is overwritten when distributed data objects are used to migrate assets.

**Change Impact**

This change is a non-compatible change. The undefined type is added to asset properties. Code compilation may fail due to type mismatch.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.25

**Key API/Component Changes**

Asset/**commonType**

**Adaptation Guide**

Set the mandatory properties of **Asset** to **undefined** to prevent data overwrites.
