# ArkWeb Subsystem Changelog

## cl.arkweb.1 nestdScroll Behavior Change

**Access Level**

Public

**Change Reason**

The nested scrolling options of the **\<Web>** component, **scrollForward** and **scrollBackward**,were incorrectly implemented.

**Change Impact**

This change is a non-compatible change. You need to change the nested scrolling option in use based on the new implementation.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

Before change

| Name            | Type              | Description                  |
| -------------- | ---------------- | -------------------- |
| scrollForward  | NestedScrollMode | Nested scrolling options when the component scrolls backward.|
| scrollBackward | NestedScrollMode | Nested scrolling options when the component scrolls forward.|

After change

| Name            | Type              | Description                  |
| -------------- | ---------------- | -------------------- |
| scrollForward  | NestedScrollMode | Nested scrolling options when the component scrolls forward.|
| scrollBackward | NestedScrollMode | Nested scrolling options when the component scrolls backward.|

**Adaptation Guide**

For details, see [Implementing Nested Scrolling](../../../application-dev/web/web-nested-scrolling.md).
