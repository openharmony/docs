# ArkUI Subsystem Changelog

## cl.arkui.1 Change in the \<Button> Component Hover Effect

Changed the hover effect of the **\<Button>** component from scale-up by 100% to 105% to overlay of 0% to 5% opacity, and the pressed effect to overlay of 5% to 10% opacity.

**Change Impact**

The visual effect of the **\<Button>** component is affected.

## cl.arkui.2 Change in the Multi-line Text Alignment Mode of Toasts

Changed the alignment mode of multi-line text in toasts from center-aligned to left-aligned.

**Change Impact**

The visual effect of toasts is affected.

## cl.arkui.3 Change in \<SideBarContainer> Component Attributes and Display Modes

1. Added the **minContentWidth** attribute, whose default value is **360vp**. If this attribute is not set, the value **0vp** is used. If this attribute is set to a value less than 0, the default value is used. In Embed mode, when the component size is increased, only the content area is enlarged; when the component size is decreased, the content area is shrunk until its width reaches the value defined by **minContentWidth**, and then the sidebar is shrunk until its width reaches the value defined by **minSideBarWidth**; if the component size is further decreased, while respecting the minimum width of the sidebar, the content area is further shrunk, with the content clipped, until it is 0 vp large. **minContentWidth**, whether it is specified or kept at the default value, takes precedence over **minSideBarWidth** and **sideBarWidth** of the sidebar.
2. Changed the default value of **minSideBarWidth** and **SideBarWidth** to **200vp** in API version 9 and earlier versions, and **240vp** in API version 10.
3. Added the Auto display mode. The sidebar is displayed in Embed mode when the component size is greater than or equal to the sum of **minSideBarWidth** and **minContentWidth** and in Overlay mode otherwise. If **minSideBarWidth** or **minContentWidth** is not set, the default value will be used for calculation. If the calculation result is less than 600 vp, 600 vp will be used as the breakpoint value for mode switching.

**Change Impact**

The default visual effect of the **\<SideBarContainer>** component is affected in API version 10.
