# richtext<a name="EN-US_TOPIC_0000001173164701"></a>

The  **<richtext\>**  component displays rich text information.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   This component is supported since API version 6.
>-   The rich text content must be written in the content area.

## Required Permissions<a name="section11257113618419"></a>

None

## Attribute<a name="section2907183951110"></a>

Only the  **id**,  **style**, and  **class**  attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Style<a name="section5775351116"></a>

Only the  **display**  and** visibility**  styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Event<a name="section17878123517511"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table13878203565113"></a>
<table><thead align="left"><tr id="row18789355519"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p08781335165113"><a name="p08781335165113"></a><a name="p08781335165113"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p6878123595117"><a name="p6878123595117"></a><a name="p6878123595117"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p28783359518"><a name="p28783359518"></a><a name="p28783359518"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2087803565116"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p3878113518516"><a name="p3878113518516"></a><a name="p3878113518516"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p187813511516"><a name="p187813511516"></a><a name="p187813511516"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1269067752"><a name="p1269067752"></a><a name="p1269067752"></a>Triggered when the loading starts.</p>
</td>
</tr>
<tr id="row28781235145111"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p118810157518"><a name="p118810157518"></a><a name="p118810157518"></a>complete</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19878535135111"><a name="p19878535135111"></a><a name="p19878535135111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p13878335145119"><a name="p13878335145119"></a><a name="p13878335145119"></a>Triggered when the loading is complete.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **focus**,  **blur**, and  **key**  events are not supported.
>-   Accessibility events are not supported.
>-   When a page containing  **<richtext\>**  is returned, the page's transition effect does not apply to the area where the rich text is displayed.
>-   Make sure the rich text does not go beyond the height of the screen. Otherwise, the excess content will not be displayed.

## Method<a name="section14703165113610"></a>

Not supported

## Example Code<a name="section581819591666"></a>

```
<!-- xxx.hml -->
<div style="flex-direction: column;width: 100%;">
  <richtext @start="onLoadStart" @complete="onLoadEnd">{{content}}</richtext>
</div>
```

```
// xxx.js
export default {
  data: {
    content: `
    <div class="flex-direction: column; background-color: #ffffff; padding: 30px; margin-bottom: 30px;"  style="background-color: #FFFFFF">
      <style>h1{color: yellow;}</style>
      <p class="item-title">h1</p>
          <h1>Text test (H1 test)</h1>
      <p class="item-title">h2</p>
          <h2>Text test (H2 test)</h2>
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

