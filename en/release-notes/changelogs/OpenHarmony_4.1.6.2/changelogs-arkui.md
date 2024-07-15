# ArkUI Subsystem Changelog

OpenHarmony 4.1.6.2 has the following changes.

## cl.arkui.1 Change in Display of Overflowing Title Text for Alert Dialog Boxes and Action Sheets

**Access Level**

Public

**Reason for Change**

Specification optimization.

**Change Impact**

This change is a compatible change.

When **title** and **subtitle** are set for an alert dialog box or action sheet:

a. If the value of **title** does not fit in the display area:

Before change: A maximum of one line of text is displayed, and an ellipsis (...) is used to represent clipped text.

After change: The font size is first decreased incrementally until it reaches 16 fp, then text is wrapped onto a new line, and finally an ellipsis (...) is used to represent clipped text.

b. If the value of **subtitle** does not fit in the display area:

Before change: A maximum of one line of text is displayed, and an ellipsis (...) is used to represent clipped text.

After change: The font size is first decreased incrementally until it reaches 12 fp, then text is wrapped onto a new line, and finally an ellipsis (...) is used to represent clipped text.

**API Level** 

**title** and **subtitle** of **AlertDialog** are supported since API version 7 and API version 10, respectively.

**title** and **subtitle** of **ActionSheet** are supported since API version 8 and API version 10, respectively.

**Change Since**

OpenHarmony SDK 4.1.6.2

**Key API/Component Changes**

AlertDialog and ActionSheet

**Adaptation Guide**

This change is about the default settings, and no adaptation is required.

## cl.arkui.2 Change in Display of Overflowing Title Text Set Through promptAction.showDialog

**Access Level**

Public

**Reason for Change**

Specification optimization.

**Change Impact**

This change is a compatible change.

**promptAction.showDialog** can take the **title** parameter.

If the value of **title** does not fit in the display area:

Before change: A maximum of one line of text is displayed, and an ellipsis (...) is used to represent clipped text.

After change: The font size is first decreased incrementally until it reaches 16 fp, then text is wrapped onto a new line, and finally an ellipsis (...) is used to represent clipped text.

**API Level** 

9

**Change Since**

OpenHarmony SDK 4.1.6.2

**Key API/Component Changes**

promptAction.showDialog

**Adaptation Guide**

This change is about the default settings, and no adaptation is required.
