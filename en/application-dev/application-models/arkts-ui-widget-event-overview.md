# Widget Event Capability Overview

For dynamic ATS widgets, the [postCardAction()](../reference/apis/js-apis-postCardAction.md#postcardaction) API is provided for interaction between the widget internal and the provider application. Currently, this API supports the router, message, and call events and can be called only in the widget.

For static ATS widgets, the [FormLink](../reference/arkui-ts/ts-container-formlink.md) component is provided for interaction between the widget internal and the provider application.

## Dynamic Widget Event Capability
![WidgetPostCardAction](figures/WidgetPostCardAction.png)

Dynamic widget events are used in the following scenarios:
- Router event: Use to redirect to a UIAbility and update the widget content.
- Call event: Use to start a UIAbility in the background and update the widget content.
- Message event: Use to start a FormExtensionAbility, which then updates the widget content.

## Static Widget Event Capability
See [FormLink](../reference/arkui-ts/ts-container-formlink.md).
