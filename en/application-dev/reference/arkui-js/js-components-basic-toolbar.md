# toolbar

The **\<toolbar>** component provides a bar that is usually placed at the bottom of a page to display operation options for the page.

## Required Permissions

None

## Child Component

Only the **\<toolbar-item>** component is supported.

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** A maximum of five **\<toolbar-item>** components can be contained in a **\<toolbar>** component. If there are six or more, only the first four are displayed, and the rest items are hidden in the **More** list of the toolbar. Users can click **More** to view the hidden items. The list is displayed in the default style instead of a customized style set for the **\<toolbar-item>** component.

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

## Styles

Styles in [Universal Styles](js-components-common-styles.md) are supported.

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** The **height** style is not supported. The height is fixed at 56px.

## Events

None

## Method

None

## Example Code

For details, see the [toolbar-item example code](js-components-basic-toolbar-item.md).