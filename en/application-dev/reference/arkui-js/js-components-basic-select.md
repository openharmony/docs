# select<a name="EN-US_TOPIC_0000001173164719"></a>

The  **<select\>**  component provides a drop-down list that allows users to select among multiple options.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

The  **<[option](js-components-basic-option.md)\>**  child component is supported.

## Attribute<a name="section2907183951110"></a>

Attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Style<a name="section648514244510"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table2017217206553"></a>
<table><thead align="left"><tr id="row17172152010556"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p1117215208557"><a name="p1117215208557"></a><a name="p1117215208557"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p11172120175513"><a name="p11172120175513"></a><a name="p11172120175513"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p21721420155517"><a name="p21721420155517"></a><a name="p21721420155517"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p917211203552"><a name="p917211203552"></a><a name="p917211203552"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p101721020175516"><a name="p101721020175516"></a><a name="p101721020175516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1917292016550"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p9172162095516"><a name="p9172162095516"></a><a name="p9172162095516"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p181721120165512"><a name="p181721120165512"></a><a name="p181721120165512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1117282018556"><a name="p1117282018556"></a><a name="p1117282018556"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p517218202558"><a name="p517218202558"></a><a name="p517218202558"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p17172120195510"><a name="p17172120195510"></a><a name="p17172120195510"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> in the family is selected as the font for the text.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section3892191911214"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row166321742154511"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p169871843194513"><a name="p169871843194513"></a><a name="p169871843194513"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19988164384513"><a name="p19988164384513"></a><a name="p19988164384513"></a>{newValue: newValue}</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p298824384514"><a name="p298824384514"></a><a name="p298824384514"></a>Triggered after a value is selected from the drop-down list. The value of <strong id="b91604451525"><a name="b91604451525"></a><a name="b91604451525"></a>newValue</strong> is the attribute value of the child component <strong id="b716613458211"><a name="b716613458211"></a><a name="b716613458211"></a>option</strong>.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **<select\>**  component does not support the  **click**  event.

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example Code<a name="section18261242145416"></a>

```
<!-- xxx.hml -->
<div class="container">
  <select @change="changeFruit">
    <option value="bananaValue">
      Banana
    </option>
    <option value="appleValue" selected="true">
      Apple
    </option>
    <option value="pearValue">
      Pear
    </option>
  </select>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
```

![](figures/en-us_image_0000001152588538.png)

