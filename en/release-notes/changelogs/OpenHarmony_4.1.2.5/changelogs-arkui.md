#  ArkUI Subsystem Changelog

## cl.arkui.1 Change to the padding API of the \<Flex> Component

**Access Level**

Public

**Reason for Change**

In previous versions, there is a sudden change of the child components in the **\<Flex>** container as its paddings along the main or cross axis increase to such an extent that the container width is exceeded.

**Change Impact**

This change is a compatible change.

Before change: When the container's paddings gradually increase along the main axis, the child components suddenly move rightward once the container width is exceeded. (The same applies to padding increase along the cross axis.)

Before change: When the container's paddings gradually increase along the main axis, the child components gradually move rightward until they disappear as the container width is exceeded. (The same applies to padding increase along the cross axis.)

**Change Since**

OpenHarmony SDK 4.1.2.5

**Key API/Component Changes**

**\<Flex>** component

**Adaptation Guide**

If the sum of paddings does not cause the width or height of the component to be exceeded, no adaptation is required. Since API version 11, if the child components become invisible due to excessively large paddings, maintain the same effect for padding increase.
