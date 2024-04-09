# ArkUI Subsystem Changelog

## cl.arkui.1 Optimization of Coordinates in Gesture Event Return Value

**Access Level**

Public

**Reason for Change**

In earlier versions, after a component is translated, rotated, or scaled, the coordinates returned from the event are incorrect and cannot be mapped to the coordinate system.

**Change Impact**

The returned coordinates can be mapped to the coordinate system.

**Change Since**

OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**

* **offsetX**, **offsetY**, **pinchCenterX**, **pinchCenterY**, and **speed** in **GestureEvent**

* **localX** and **localY** in **FingerInfo**

* **x** and **y** in **ClickEvent**

* **x** and **y** in **TouchObject**

**Adaptation Guide**

N/A

## cl.ArkUI.2 Change to the selectBackgroundColor Attribute of the \<TextInput> Component

**Access Level**
Public

**Reason for Change**
If the **ResourceColor** value of **selectedBackgroundColor** does not have the opacity specified, text will be masked when selected.

**Change Impact**
This change is a compatible change. If the **ResourceColor** value of **selectedBackgroundColor** does not have the opacity specified, a 20% opacity will be used.

**Change Since**
OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**
**selectedBackgroundColor** attribute of the **\<TextInput>** component

**Adaptation Guide**
N/A

## cl.ArkUI.3 Change to the Default Behavior for the animationDuration Attribute of the \<Tabs> Component

**Access Level**

Public

**Reason for Change**

The **\<Tabs>** component's **animationDuration** attribute did not exhibit consistent default behaviors:
If **animationDuration** is not set, no tab switching animation is displayed when a specific tab is clicked; if it is set to a value less than 0, a tab switching animation is displayed when a specific tab is clicked, and the default value 300 ms is used.

**Change Impact**

This change is a non-compatible change.
In API version 10 and earlier versions, if **animationDuration** is not set, no tab switching animation is displayed when a specific tab is clicked.
Since API version 11, if **animationDuration** is not set, a tab switching animation is displayed when a specific tab is clicked, and the default value 300 ms is used.

**Change Since**

OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**

**animationDuration** attribute of the **\<Tabs>** component

**Adaptation Guide**

Before the change, if you do not want to display a tab switching animation when a specific tab is clicked, set **animationDuration** to **0** or do not set it at all.
After the change, if you do not want to display a tab switching animation when a specific tab is clicked:<br>API version 11 or later: Set **animationDuration** to **0**.<br>API version 10 or earlier: Set **animationDuration** to **0** or do not set it at all.

## cl.ArkUI.4 Change to the padding Attribute of the \<TextInput> Component

**Access Level**

Public

**Reason for Change**

When **padding** is set to **{left:10vp}**, the top, bottom, and right paddings are at 0, instead of at their default values.

**Change Impact**

This change is a non-compatible change. When **padding** is set to **{left:10vp}**, the top, bottom, and right paddings are at their default values, which are 16 vp, 16 vp, and 8 vp, respectively.

**Change Since**

All versions

**Key API/Component Changes**

**padding** attribute of the **\<TextInput>** component

**Adaptation Guide**

If you want to set the left padding of the **\<TextInput>** component to 10 vp and other paddings to 0, set **padding** to **{left:10vp, right:0vp, top:0vp, bottom:0vp}**. If the padding for a specific direction is not specified, the default value is used.

## cl.ArkUI.5 Change to the Line Height of the \<Text> component

**Access Level**

Other

**Reason for Change**

The line height of the **\<Text>** component must be the same as the font size, instead of being fixed at 14 px.

**Change Impact**

This change is a non-compatible change.

In API version 10 and earlier versions, when **fontSize('20px')** is set, the line height of the **\<Text>** component is 14 px, and the line height of its child component **\<Span>** is also fixed at 14 px.

Since API version 11, when **fontSize('20px')** is set, the line height of the **\<Text>** component is 20 px, and the line height of its child component **\<Span>** is fixed at 14 px.

**Change Since**

OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**

**\<Text>** component

**Adaptation Guide**

N/A

## cl.ArkUI.6 Bug Fix for scrollTo Calls in the Scroller

**Access Level**

Public

**Reason for Change**

 This change is made to fix the following bug: When the scroller calls the **scrollTo** method, if the scrolling distance of the **\<Grid>** component is beyond the current page height along the main axis, the target position has an error of **rowsGap** multiplied by number of rows.  

**Change Impact**

This change is a compatible change. After change, a **scrollTo** method call will scroll the **\<Grid>** component to a more precise position.

**API Level**

7

**Change Since**

OpenHarmony 4.1.3.3

**Key API/Component Changes**

**\<Grid>** component

**Adaptation Guide**

N/A
