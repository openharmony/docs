# ArkUI Subsystem Changelog

## cl.arkui.1 Change in Handling of Invalid arrowSize Values for the \<Swiper> Component

**Access Level**

Public

**Reason for Change**

An invalid string that contains digits is incorrectly parsed into digits.

**Change Impact**

This change is a compatible change. An invalid string that contains digits is not parsed into digits. Instead, it is regarded as an invalid value and is set to the default value according to predefined rules.
Before change: With the settings of **.arrowSize("100abc")**, the arrow is displayed in a 100 vp size.
After change: With the settings of **.arrowSize("100abc")**, the arrow is displayed in the default size.

**API Level**

10

**Change Since**

OpenHarmony SDK 4.1.3.2

**Key API/Component Changes**
**arrowSize** API of the **\<Swiper>** component

**Adaptation Guide**
N/A
