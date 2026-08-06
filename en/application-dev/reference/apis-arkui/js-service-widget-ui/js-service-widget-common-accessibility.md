# Accessibility

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:28:32.855Z pushedAt=2026-07-27T09:23:36.770Z -->

You can set accessibility attributes and events for components, such as the accessibility group, accessibility text, accessibility description, and accessibility importance. In addition, events dispatched by the accessibility service can be received, enabling custom accessibility interactions. This is suitable for scenarios where screen reader and other accessibility features need to be provided for service widgets, helping visually impaired users and other special groups clearly understand the currently selected component and the consequences of operations, and improving the accessibility and reachability of the app.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Accessibility

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| accessibilitygroup | boolean | false | Whether to enable accessibility grouping. The value **true** means to enable accessibility grouping, and **false** means the opposite. When accessibility grouping is enabled, the component and all its child components are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components. |
| accessibilitytext | string | - | Accessibility text. If a component does not contain text content (such as the **Image** component), it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for such components. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected. If a component has both text content and accessibility text, only the accessibility text is announced. |
| accessibilitydescription | string | - | Accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. You can set a detailed description text for the attribute of the component to help users understand the operation to be performed. If a component contains both text content and the accessibility description, the screen reader announces the text first, followed by the accessibility description, when the component is selected. |
| accessibilityimportance | string | auto | Accessibility importance, which is used to decide whether a component can be identified by the accessibility service. The value can be **auto**, **yes**, **no**, or **no-hide-descendants**. **auto**: The system automatically determines whether the component can be identified by the accessibility service based on the component type. **yes**: The current component can be identified by the accessibility service. **no**: The current component cannot be identified by the accessibility service. **no-hide-descendants**: The accessibility service ignores the current component and all its child components. |

- accessibilitygroup

  ```html
  <div accessibilitygroup="true">
    <text>text1</text>
    <text>text2</text>
  </div>
  ```

- accessibilitytext

  ```html
  <image src="common/image/barrierfree.jpg" accessibilitytext=" This is a landscape image. "></image>
  ```

- accessibilitydescription

  ```html
  <!-- showDialog is a custom event processing function, which must be defined in the .js file. -->
  <button accessibilitydescription="Click this button to open a dialog box" onclick="showDialog">button</button>
  ```

- accessibilityimportance

By default (when **accessibilityimportance** is set to **auto**), the container and text components without interactive semantics, such as **div** and **text**, are not selected by the accessibility service. To select a component that is unselected by default, add **accessibilityimportance="yes"** to the component. The following example shows that when **accessibilityimportance** is set to **no-hide-descendants**, the current component and its child components are ignored by the accessibility service:

  ```html
  <div accessibilityimportance="no-hide-descendants">
    <text>text</text>
  </div>
  ```

## Accessibility Events

| Name| Parameter| Description|
| -------- | -------- | -------- |
| accessibility | AbilityEvent | Event dispatched by the accessibility service, which is triggered when the accessibility service (such as the screen reader) interacts with the component. You can handle accessibility focus changes or respond to custom accessibility interactions based on the **eventType** parameter in the callback. |

  **Table 1** AbilityEvent properties

| Name| Type| Description|
| -------- | -------- | -------- |
| eventType | number | Event type.<br/>-&nbsp;**0**: custom&nbsp;event<br/>-&nbsp;**1**: accessibility&nbsp;focus<br/>-&nbsp;**2**: clear&nbsp;accessibility&nbsp;focus<br/>For custom events dispatched by the accessibility system, the **eventType** value is **0**. For focused events dispatched by the accessibility system, the **eventType** value is **1**. For unfocused events dispatched by the accessibility system, the **eventType** value is **2**. |
| param | Object | Parameter object to be passed when the accessibility app sends a custom event. The parameter content depends on the specific service scenario of the custom event and may contain service data fields related to the event. |