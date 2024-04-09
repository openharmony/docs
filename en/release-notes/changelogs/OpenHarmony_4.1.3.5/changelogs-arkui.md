# ArkUI Subsystem Changelog

##  cl.arkui.1 Change in Check Rules on the \<Scroll> Component

**Access Level**

Public

**Reason for Change**

The [\<Scroll>](../../../application-dev/reference/arkui-ts/ts-container-scroll.md) component supports a single child component. To prevent multiple child components from being added, a check rule is added to the compiler to warn of such attempts.

**Change Impact**

This change is a non-compatible change. The new check rule does not affect the layout or behavior of the **\<Scroll>** component.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

**\<Scroll>** component

**Adaptation Guide**

Make sure the **\<Scroll>** component contains only one child component.

##  cl.arkui.2 Determination of the Cross Axis Size and stretch Alignment Mode in the \<Flex> Component

**Access Level**

Public

**Reason for Change**

In the **\<Flex>** container, the priority of the child component size is higher than that of the **stretch** alignment mode along the cross axis. If both are set, only the cross axis size of the child component takes effect.

**Change Impact**

This change is a compatible change.

API version 9 and earlier versions: If both the child component size and the **stretch** alignment mode are set for the cross axis, the cross axis size of the child component does not take effect.

API version 10 and later: If both the child component size and the **stretch** alignment mode are set for the cross axis, the **stretch** alignment mode does not take effect.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

**\<Flex>** component

**Adaptation Guide**

To make the **stretch** alignment mode for the cross axis take effect, remove the cross axis size settings of the child component.
