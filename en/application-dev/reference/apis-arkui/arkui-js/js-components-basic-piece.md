# piece

>  **NOTE**
>
>  This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The **\<piece>** component provides an entrance piece that can contain images and text. It is usually used to display receivers, for example, email recipients or message recipients.

## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name    | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| content  | string  | Yes  | Text content of the operational piece.                                            |
| closable | boolean | No  | Whether to display the delete icon for the operational piece. When users click the delete icon, it triggers the close event.<br>Default value: **false**|
| icon     | string  | No  | URL of the delete icon for the operational piece. The value can be a local path.                         |


## Styles

The [universal styles](js-components-common-styles.md) are supported.

>  **NOTE**
>
>  By default, text and images are placed in the middle of the **\<piece>** component.


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name   | Parameter  | Description                                 |
| ----- | ---- | ----------------------------------- |
| close | -    | Triggered when users click the delete icon of the operational piece. You can delete this component by using the **if** directive.|

## Methods

The [universal methods](js-components-common-methods.md) are supported.


## Example

```html
<!-- xxx.hml-->
<div class="container" >
  <piece if="{{first}}" content="example"></piece>
  <piece if="{{second}}" content="example" closable="true" onclose="closeSecond"></piece>
</div>
```

```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  align-items: center;
  justify-content: center;
}
```

```js
// xxx.js
export default {
  data: {
    first: true,
    second: true
  },
  closeSecond(e) {
    this.second = false;
  }
}
```

![11-5](figures/11-5.gif)
