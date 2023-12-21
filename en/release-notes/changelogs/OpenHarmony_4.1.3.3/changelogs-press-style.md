# ArkUI Changelog
## cl.ArkUI.1 Behavior Changes of Component Pressed State

**Access Level**

Open API

**Reason for Change**

Optimized the pressed state style in the polymorphic style attribute.

**Change Impact**

This change affects the validation or cancellation of the pressed state in the polymorphic style attribute.

**Change Since**

OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**

In versions earlier than API version 11:

* A component enters the pressed state when touched, and remains in this state, even after the user's finger leaves the component touch target, until the finger is lifted.
* If the component is touched with multiple fingers, it remains in the pressed state until some of the fingers are lifted.
* If a component is placed in a scroll container component (such as **\<List>**), it will enter the pressed state when swiped on, and then immediately exit that state.

Since API version 11:

* A component enters the pressed state when touched and remains in this state until the user's finger leaves the component touch target.
* If the component is touched with multiple fingers, it remains in the pressed state until all of the fingers are lifted.
* If a component is placed in a scroll container component (such as **\<List>**), it will not enter the pressed state when swiped on.

**Adaptation Guide**

N/A