# richtext


>  **NOTE**
>
> - This component is supported since API version 6. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The rich text content must be written in the content area.

The **\<richtext>** component displays rich text information.

## Required Permissions

None


## Attributes

Only the **id**, **style**, and **class** attributes in [Universal Attributes](js-components-common-attributes.md) are supported.


## Styles

Only the **display** and **visibility** styles in [Universal Styles](js-components-common-styles.md) are supported.


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name| Parameter| Description|
| -------- | -------- | -------- |
| start | - | Triggered when the loading starts.|
| complete | - | Triggered when the loading is complete.|

>  **NOTE**
> - The **focus**, **blur**, and **key** events are not supported.
> 
> - Accessibility events are not supported.
> 
> - When a page containing **\<richtext>** is returned, the page's transition effect does not apply to the area where the rich text is displayed.
> 
> - Make sure the rich text does not go beyond the height of the screen. Otherwise, the excess content will not be displayed.
> 
> - The width cannot be set. By default, the rich text is displayed in full screen.


## Methods

Not supported


## Example

```html
<!-- xxx.hml -->
<div style="flex-direction: column;width: 100%;">
  <richtext @start="onLoadStart" @complete="onLoadEnd">{{content}}</richtext>
</div>
```

```js
// xxx.js
export default {
  data: {
    content: `
    <div class="flex-direction: column; background-color: #ffffff; padding: 30px; margin-bottom: 30px;"  style="background-color: #FFFFFF">
      <style>h1{color: yellow;}</style>
      <p class="item-title">h1</p>
      <h1>Text test (h1 test)</h1>
      <p class="item-title">h2</p>
      <h2>Text test (h2 test)</h2>
    </div>
    `,
  },
  onLoadStart() {
    console.error("start load rich text:" + JSON.stringify())
  },
  onLoadEnd() {
    console.error("end load rich text:" + JSON.stringify())
  }
}
```
