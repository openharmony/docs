# search

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<search>** component provides an input area for users to search.


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name                       | Type                     | Default Value | Mandatory  | Description                               |
| ------------------------- | ----------------------- | ---- | ---- | --------------------------------- |
| icon                      | string                  | -    | No   | Search icon. By default, the system search icon is used. The supported icon format is SVG, JPG, and PNG.|
| hint                      | string                  | -    | No   | Hint text.                          |
| value                     | string                  | -    | No   | Text in the search box.                        |
| searchbutton<sup>5+</sup> | string                  | -    | No   | Text on the search button at the end of the search box.                    |
| menuoptions<sup>5+</sup>  | Array&lt;MenuOption&gt; | -    | No   | Menu options displayed after users click the **More** button.          |

**Table 1** MenuOption<sup>5+</sup>

| Name     | Type    | Description         |
| ------- | ------ | ----------- |
| icon    | string | Path of the icon for a menu option.|
| content | string | Text content of a menu option.|


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name                      | Type                        | Default Value            | Mandatory  | Description                                      |
| ------------------------ | -------------------------- | --------------- | ---- | ---------------------------------------- |
| color                    | &lt;color&gt;              | \#e6000000      | No   | Font color of the search box.                               |
| font-size                | &lt;length&gt;             | 16px            | No   | Font size of the search box.                               |
| allow-scale              | boolean                    | true            | No   | Whether the font size changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| placeholder-color        | &lt;color&gt;              | \#99000000<br>| No   | Color of the hint text.                             |
| font-weight              | number \| string | normal          | No   | Font weight. For details, see [font-weight](js-components-basic-text.md#styles) of the **\<text>** component.|
| font-family              | string                     | sans-serif      | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](js-components-common-customizing-font.md) is used for the text.|
| caret-color<sup>6+</sup> | &lt;color&gt;              | -               | No   | Color of the caret.                              |


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name                       | Parameter                                      | Description                                      |
| ------------------------- | ---------------------------------------- | ---------------------------------------- |
| change                    | { text:newText }               | Triggered when the content entered in the text box changes.<br>If you change the **value** attribute directly, this event will not be triggered.     |
| submit                    | { text:submitText }            | Triggered when users click the search icon or the search button<sup>5+</sup>, or tap the search button on a soft keyboard. |
| translate<sup>5+</sup>    | { value: selectedText }   | Triggered when users click the translate button in the menu displayed after they select a text segment. The selected text content is returned.|
| share<sup>5+</sup>        | { value: selectedText }   | Triggered when users click the share button in the menu displayed after they select a text segment. The selected text content is returned.|
| search<sup>5+</sup>       | { value: selectedText }   | Triggered when users click the search button in the menu displayed after they select a text segment. The selected text content is returned.|
| optionselect<sup>5+</sup> | { index:optionIndex, value: selectedText } | Triggered when users click a menu option in the menu displayed after they select a text segment. This event is valid only when the **menuoptions** attribute is set. The option index and selected text content are returned.|


## Methods

The [universal methods](js-components-common-methods.md) are supported.


## Example

```html
<!-- xxx.hml -->
<div class="container">
    <search hint="Enter keywords" searchbutton="Search" @search="search">
  </search>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
```

![en-us_image_0000001153427082](figures/en-us_image_0000001153427082.png)
