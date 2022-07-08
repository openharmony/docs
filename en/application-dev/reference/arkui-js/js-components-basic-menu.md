# menu

The **\<menu>** component provides menus as temporary pop-up windows to display operations that can be performed by users.

## Required Permissions

None

## Child Components

**[option](js-components-basic-option.md)**

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name   | Type   | Default Value | Mandatory | Description                                                  |
| ------ | ------ | ------------- | --------- | ------------------------------------------------------------ |
| target | string | -             | No        | Target element selector. After the target element selector is used, a menu is automatically displayed when you click the target element. The pop-up menu is preferentially displayed in the lower right corner of the target element. When the visible space on the right is insufficient, the menu is moved leftward. When the visible space in the lower part is insufficient, the menu is moved upward. |
| type   | string | click         | No        | Mode in which the target element triggers the pop-up window. Available values are as follows:<br/>-**click**: Click the element to trigger the pop-up window.<br/>-**longpress**: Press and hold the element to trigger the pop-up window. |
| title  | string | -             | No        | Title of the pop-up window.                                  |

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** The **focusable** and **disabled** attributes are not supported.

## Styles

Only the following style attributes are supported.



| Name           | Type             | Default Value | Mandatory | Description                                                  |
| -------------- | ---------------- | ------------- | --------- | ------------------------------------------------------------ |
| text-color     | \<color>          | -             | No        | Font color of the menu.                                      |
| font-size      | \<length>         | 30px          | No        | Font size of the menu.                                       |
| allow-scale    | boolean          | true          | No        | Whether the font size changes with the system's font size settings.NOTE:If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart. |
| letter-spacing | \<length>         | 0             | No        | Character spacing of the menu.                               |
| font-style     | string           | normal        | No        | Font style of the menu. For details, see [font-style](js-components-basic-text.md#section5775351116) of the **text** component. |
| font-weight    | number \| string | normal        | No        | Font weight of the menu. For details, see [font-weight](js-components-basic-text.md#section5775351116) of the **text** component. |
| font-family    | string           | sans-serif    | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) in the family is selected as the font for the text. |

## Events

The following events are supported.



| Name     | Parameter       | Description                                                  |
| -------- | --------------- | ------------------------------------------------------------ |
| selected | { value:value } | Triggered when a value in the menu is selected. The returned value is the **value** attribute of the **\<option>** component. |
| cancel   | -               | Triggered when an operation is canceled by the user          |

## Methods

The following methods are supported.



| Name | Parameter    | Description                                                  |
| ---- | ------------ | ------------------------------------------------------------ |
| show | { x:x, y:y } | Displays the menu. *x* and *y* specify the position of the displayed menu. *x* indicates the X-axis coordinate from the left edge of the visible area, and does not include any scrolling offset. *y* indicates the Y-axis coordinate from the upper edge of the visible area, and does not include any scrolling offset or a status bar. The menu is preferentially displayed in the lower right corner. When the visible space on the right is insufficient, the menu is moved leftward. When the visible space in the lower part is insufficient, the menu is moved upward. |

## Example

```
<!-- xxx.hml -->
<div class="container">
  <text onclick="onTextClick" class="title-text">Show popup menu.</text>
  <menu id="apiMenu" onselected="onMenuSelected">
    <option value="Item 1">Item 1</option>
    <option value="Item 2">Item 2</option>
    <option value="Item 3">Item 3</option>
  </menu>
</div>
/* xxx.css */
.container {
  flex-direction: column;
  align-items: flex-start;
  justify-content: center;
}
.title-text {
  margin: 20px;
}
// xxx.js
import prompt from '@system.prompt';
export default {
  onMenuSelected(e) {
    prompt.showToast({
      message: e.value
    })
  },
  onTextClick() {
    this.$element("apiMenu").show({x:280,y:120});
  }
}
```

![img](figures/menu13.gif)