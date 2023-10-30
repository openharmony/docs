# ArkUI Subsystem Changelog

## cl.arkui.1 Removal of Padding Effect from List Scrollbar Margin

**Change Impact**

In versions earlier than API version 10, the scrollbar margin in the **\<List>** component is affected by padding. When padding is set for the component, the space of the scrollbar is squeezed inward.

Since API version 10, the scrollbar margin in the **\<List>** component fixed at 4 vp, not affected by padding.

## cl.arkui.2 Change of Space Reserved for Scrollbar Top and Bottom

**Change Impact**

Before change, the space reserved for the top and bottom of a vertical scrollbar (or left and right of a horizontal scrollbar) is fixed, as a result of which the scrollbar may be cut by the rounded corners of the scrollable container component.

After change, the space reserved for the top and bottom of a vertical scrollbar (or left and right of a horizontal scrollbar) is dynamically calculated based on the rounded corner radius of the scrollable container component. For example, when the rounded corner radius of a **\<Scroll>** component is 0, the space reserved for the top and bottom of its vertical scrollbar is 0, which means that the scrollbar can scroll to the bottom of the **\<Scroll>** component.
