# ArkUI Subsystem Changelog

## cl.arkui.1 Removal of ArkTS Widgets from Applicability of draggable in the \<Image> Component

**Change Level**

Open API

**Reason for Change**

The **draggable** API of the **\<Image>** component is not supported in ArkTS widgets.

**Change Impact**

This change is a non-compatible change. After the **@form** tag is removed from the **draggable** API, the **draggable** API cannot be used for the **\<Image>** component in ArkTS widgets.

**API Level**

Since API version 9

**Key API/Component Changes**

Before change, the **draggable** API of the **\<Image>** component has the **@form** tag.

After change, the **draggable** API of the **\<Image>** component does not have the **@form** tag and cannot be used in ArkTS widgets.

**Adaptation Guide**

N/A (The **draggable** API of the **\<Image>** component is not supported in ArkTS widgets before and after change.)
