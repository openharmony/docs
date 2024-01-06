#  ArkUI Subsystem Changelog

## cl.arkui.1 Change in minWidth of constraintSize

**Access Level**

Public

**Reason for Change**

An error occurs when **minWidth** of **constraintSize** is used on API version 10 or earlier versions. Therefore, **minWidth** must be confined to API version 11 and later versions.

**Change Impact**

This change is a non-compatible change.

**Change Since**

OpenHarmony SDK 4.1.3.1

**\<Flex>** component:

Before change: **minWidth** of **constraintSize** can be used on API version 10.

After change: **minWidth** of **constraintSize** work only when the API version is 11 or later.  

**Adaptation Guide**

If the SDK of API version 10 or earlier is used, and **minWidth** of **constraintSize** is used to restrict the component's minimum width, you must modify the code. If the component width changes to one less than the value specified by **minWidth**, the component width is directly used.
