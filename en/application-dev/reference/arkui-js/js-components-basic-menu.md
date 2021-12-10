# menu<a name="EN-US_TOPIC_0000001173164715"></a>

The  **<menu\>**  component provides menus as temporary pop-up windows to display operations that can be performed by users.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

**[<option\>](js-components-basic-option.md)**

## Attribute<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row20739039202112"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p12805174016214"><a name="p12805174016214"></a><a name="p12805174016214"></a>target</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p0805154015212"><a name="p0805154015212"></a><a name="p0805154015212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p14805134011215"><a name="p14805134011215"></a><a name="p14805134011215"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p17805194002114"><a name="p17805194002114"></a><a name="p17805194002114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p168053400214"><a name="p168053400214"></a><a name="p168053400214"></a>Target element selector. After the target element selector is used, a menu is automatically displayed when you click the target element. The pop-up menu is preferentially displayed in the lower right corner of the target element. When the visible space on the right is insufficient, the menu is moved leftward. When the visible space in the lower part is insufficient, the menu is moved upward.</p>
</td>
</tr>
<tr id="row1131933611219"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p380514401217"><a name="p380514401217"></a><a name="p380514401217"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p380511401214"><a name="p380511401214"></a><a name="p380511401214"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p3805174011211"><a name="p3805174011211"></a><a name="p3805174011211"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1805124013218"><a name="p1805124013218"></a><a name="p1805124013218"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p11805124032118"><a name="p11805124032118"></a><a name="p11805124032118"></a>Mode in which the target element triggers the pop-up window. Available values are as follows:</p>
<a name="ul168051640152119"></a><a name="ul168051640152119"></a><ul id="ul168051640152119"><li><strong id="b363812611517"><a name="b363812611517"></a><a name="b363812611517"></a>click</strong>: Click the element to trigger the pop-up window.</li><li><strong id="b193081910125114"><a name="b193081910125114"></a><a name="b193081910125114"></a>longpress</strong>: Press and hold the element to trigger the pop-up window.</li></ul>
</td>
</tr>
<tr id="row142917338215"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p6805840192110"><a name="p6805840192110"></a><a name="p6805840192110"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p7805640162120"><a name="p7805640162120"></a><a name="p7805640162120"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1805104018214"><a name="p1805104018214"></a><a name="p1805104018214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p158051240102116"><a name="p158051240102116"></a><a name="p158051240102116"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p780544014218"><a name="p780544014218"></a><a name="p780544014218"></a>Title of the pop-up window.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **focusable**  and  **disabled**  attributes are not supported.

## Style<a name="section1382826121311"></a>

Only the following style attributes are supported.

<a name="table1382926171312"></a>
<table><thead align="left"><tr id="row4827267131"><th class="cellrowborder" valign="top" width="19.038096190380962%" id="mcps1.1.6.1.1"><p id="p14838267137"><a name="p14838267137"></a><a name="p14838267137"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.847615238476152%" id="mcps1.1.6.1.2"><p id="p283172611317"><a name="p283172611317"></a><a name="p283172611317"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.118788121187881%" id="mcps1.1.6.1.3"><p id="p88312621315"><a name="p88312621315"></a><a name="p88312621315"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="8.269173082691731%" id="mcps1.1.6.1.4"><p id="p2083112611314"><a name="p2083112611314"></a><a name="p2083112611314"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="36.72632736726327%" id="mcps1.1.6.1.5"><p id="p1783122611133"><a name="p1783122611133"></a><a name="p1783122611133"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3836265139"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p1983152617134"><a name="p1983152617134"></a><a name="p1983152617134"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p128332611313"><a name="p128332611313"></a><a name="p128332611313"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p283192611138"><a name="p283192611138"></a><a name="p283192611138"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p38312262131"><a name="p38312262131"></a><a name="p38312262131"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p1283152651317"><a name="p1283152651317"></a><a name="p1283152651317"></a>Font color of the menu.</p>
</td>
</tr>
<tr id="row483152611133"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p88319262136"><a name="p88319262136"></a><a name="p88319262136"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p584192617139"><a name="p584192617139"></a><a name="p584192617139"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p168412265131"><a name="p168412265131"></a><a name="p168412265131"></a>30px</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p884112616132"><a name="p884112616132"></a><a name="p884112616132"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p138462651315"><a name="p138462651315"></a><a name="p138462651315"></a>Font size of the menu.</p>
</td>
</tr>
<tr id="row984102651311"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p208462681319"><a name="p208462681319"></a><a name="p208462681319"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p1584626161319"><a name="p1584626161319"></a><a name="p1584626161319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p1184192681319"><a name="p1184192681319"></a><a name="p1184192681319"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p1184142612131"><a name="p1184142612131"></a><a name="p1184142612131"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p6849264138"><a name="p6849264138"></a><a name="p6849264138"></a>Whether the font size changes with the system's font size settings.</p>
<div class="note" id="note984226191312"><a name="note984226191312"></a><a name="note984226191312"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p58442621310"><a name="p58442621310"></a><a name="p58442621310"></a>If the <strong id="b3847171311256"><a name="b3847171311256"></a><a name="b3847171311256"></a>config-changes</strong> tag of <strong id="b38541913152512"><a name="b38541913152512"></a><a name="b38541913152512"></a>fontSize</strong> is configured for abilities in the <strong id="b15854713182513"><a name="b15854713182513"></a><a name="b15854713182513"></a>config.json</strong> file, the setting takes effect without application restart.</p>
</div></div>
</td>
</tr>
<tr id="row0848266134"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p108417267136"><a name="p108417267136"></a><a name="p108417267136"></a>letter-spacing</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p19851226111314"><a name="p19851226111314"></a><a name="p19851226111314"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p11851526131317"><a name="p11851526131317"></a><a name="p11851526131317"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p1085112601315"><a name="p1085112601315"></a><a name="p1085112601315"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p1585102611312"><a name="p1585102611312"></a><a name="p1585102611312"></a>Character spacing of the menu.</p>
</td>
</tr>
<tr id="row198512611311"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p58542612137"><a name="p58542612137"></a><a name="p58542612137"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p1385526141314"><a name="p1385526141314"></a><a name="p1385526141314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p0854265135"><a name="p0854265135"></a><a name="p0854265135"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p68511266136"><a name="p68511266136"></a><a name="p68511266136"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p1985126101319"><a name="p1985126101319"></a><a name="p1985126101319"></a>Font style of the menu. For details, see <a href="js-components-basic-text.md#section5775351116">font-style</a> of the <strong id="b15474121215508"><a name="b15474121215508"></a><a name="b15474121215508"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row1485326141319"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p78572651318"><a name="p78572651318"></a><a name="p78572651318"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p4856268132"><a name="p4856268132"></a><a name="p4856268132"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p68572616131"><a name="p68572616131"></a><a name="p68572616131"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p168572615134"><a name="p168572615134"></a><a name="p168572615134"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p138542681312"><a name="p138542681312"></a><a name="p138542681312"></a>Font weight of the menu. For details, see <a href="js-components-basic-text.md#section5775351116">font-weight</a> of the <strong id="b254187164920"><a name="b254187164920"></a><a name="b254187164920"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row88516264133"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="p28512618133"><a name="p28512618133"></a><a name="p28512618133"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="p285182651315"><a name="p285182651315"></a><a name="p285182651315"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="p16851626111320"><a name="p16851626111320"></a><a name="p16851626111320"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="p12856267138"><a name="p12856267138"></a><a name="p12856267138"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="p178632614139"><a name="p178632614139"></a><a name="p178632614139"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> in the family is selected as the font for the text.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section5624519222"></a>

The following events are supported.

<a name="table116210562217"></a>
<table><thead align="left"><tr id="row2062135192210"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p166255172219"><a name="p166255172219"></a><a name="p166255172219"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p76225152215"><a name="p76225152215"></a><a name="p76225152215"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p0621562216"><a name="p0621562216"></a><a name="p0621562216"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row19622532212"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p5629512216"><a name="p5629512216"></a><a name="p5629512216"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p6621258220"><a name="p6621258220"></a><a name="p6621258220"></a>{ value:value }</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p963205112214"><a name="p963205112214"></a><a name="p963205112214"></a>Triggered when a value in the menu is selected. The returned value is the <strong id="b8348518817"><a name="b8348518817"></a><a name="b8348518817"></a>value</strong> attribute of the <strong id="b46757201362"><a name="b46757201362"></a><a name="b46757201362"></a>&lt;option&gt;</strong> component.</p>
</td>
</tr>
<tr id="row13636516229"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p463550229"><a name="p463550229"></a><a name="p463550229"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p17633542217"><a name="p17633542217"></a><a name="p17633542217"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p6639512225"><a name="p6639512225"></a><a name="p6639512225"></a>Triggered when an operation is canceled by the user</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section47669296127"></a>

The following methods are supported.

<a name="table5423142414911"></a>
<table><thead align="left"><tr id="row342362484919"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p2423924114916"><a name="p2423924114916"></a><a name="p2423924114916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p124231524104914"><a name="p124231524104914"></a><a name="p124231524104914"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p104230246498"><a name="p104230246498"></a><a name="p104230246498"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1642392418498"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p165281286428"><a name="p165281286428"></a><a name="p165281286428"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p9528428204212"><a name="p9528428204212"></a><a name="p9528428204212"></a>{ x:x,  y:y }</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p11528112816422"><a name="p11528112816422"></a><a name="p11528112816422"></a>Displays the menu. <em id="i41846563220"><a name="i41846563220"></a><a name="i41846563220"></a>x</em> and <em id="i9806858529"><a name="i9806858529"></a><a name="i9806858529"></a>y</em> specify the position of the displayed menu. <em id="i1683071319418"><a name="i1683071319418"></a><a name="i1683071319418"></a>x</em> indicates the X-axis coordinate from the left edge of the visible area, and does not include any scrolling offset. <em id="i1864241546"><a name="i1864241546"></a><a name="i1864241546"></a>y</em> indicates the Y-axis coordinate from the upper edge of the visible area, and does not include any scrolling offset or a status bar. The menu is preferentially displayed in the lower right corner. When the visible space on the right is insufficient, the menu is moved leftward. When the visible space in the lower part is insufficient, the menu is moved upward.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section54636714136"></a>

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
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: flex-start;
  justify-content: center;
}
.title-text {
  margin: 20px;
}
```

```
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

![](figures/menu13.gif)

