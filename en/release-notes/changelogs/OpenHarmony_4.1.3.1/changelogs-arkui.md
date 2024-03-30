#  ArkUI Subsystem Changelog

## cl.arkui.1 Change in the Effect of Setting constraintSize minWidth Alone in the \<TextInput> or \<TextArea> Component

**Access Level**

Public

**Reason for Change**

The effect of **constraintSize minWidth** on API version 10 does not meet the application expectation and needs to be corrected on API version 11.

**Change Impact**

This change is a non-compatible change.

**Change Since**

OpenHarmony SDK 4.1.3.1

**Key API/Component Changes**

TextInput/TextArea

Before change: If **constraintSize({minWidth:100})** is set and the **width** attribute is not specified for a **\<TextInput>** component, the width of the component is the maximum width passed by the parent component.

After change: If **constraintSize({minWidth:100})** is set and the **width** attribute is not specified for a **\<TextInput>** component, the width of the **\<TextInput>** component is 100 at minimum when the width of the parent component is greater than or equal to 100, and automatically increases to adapt to the content.

**Adaptation Guide**

N/A

## cl.arkui.2 Change of hideNavBar Effectiveness for the \<Navigation> Component

**Access Level**

Public

**Reason for Change**

The effectiveness of the **hideNavBar** API is increased from the dual-column mode only to both single-column and dual-column modes.

**Change Impact**

This change is a non-compatible change. Before change: The **hideNavBar** API has no effect in the single-column mode.<br>After change: The **hideNavBar** API works for both single-column and dual-column modes. If no target page is available, using this API may result in a blank screen.

**API Level**

9

**Change Since**

OpenHarmony SDK 4.1.3.1

**Adaptation Guide**

When this API is used, the navigation bar, including the title bar, content area, and toolbar, is hidden. In this case, if there is a navigation destination page in the navigation stack, the page at the top of the stack is displayed. Otherwise, a blank screen is displayed In versions earlier than API version 11, this API takes effect only in dual-column mode. Since API version 11, this API works for the single-column, dual-column, and adaptive modes. If a blank screen occurs due to the use of this API, you can remove this API or provide a navigation destination page in the navigation stack.
