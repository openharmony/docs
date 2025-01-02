# ArkUI Subsystem Changelog

## cl.arkui.1 Change in Handling of Invalid animationDuration Values for the \<Tabs> Component

**Access Level**

Other

**Reason for Change**

When the **animationDuration** attribute is set to **null**, the default value should be used.

**Change Impact**

This change is a non-compatible change.

In API version 10 and earlier versions, when the **animationDuration** attribute is set to **null**, no tab switching animation is played.

Since API version 11, if the **animationDuration** attribute is set to **null**, the default value is used. In this case, when the tab bar is set to **BottomTabBarStyle**,no tab switching animation is played; when the tab bar is any other style, a 300 ms tab switching animation is played.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

\<Tabs>

**Adaptation Guide**

Since API version 11, if you want to disable the tab switching animation, you must set **animationDuration** to **0**, rather than **null**.
