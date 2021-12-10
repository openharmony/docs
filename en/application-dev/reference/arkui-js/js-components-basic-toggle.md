# toggle<a name="EN-US_TOPIC_0000001127125082"></a>

The  **<toggle\>**  component allows your user to select from a group of options and may display the selection result in real time. Generally, the option group consists of many toggles.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Not supported

## Attribute<a name="section2598341175212"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p2063810588455"><a name="p2063810588455"></a><a name="p2063810588455"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row128581827123812"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p158151581017"><a name="p158151581017"></a><a name="p158151581017"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p98151887118"><a name="p98151887118"></a><a name="p98151887118"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p78158817112"><a name="p78158817112"></a><a name="p78158817112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p8638135854515"><a name="p8638135854515"></a><a name="p8638135854515"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1981514819118"><a name="p1981514819118"></a><a name="p1981514819118"></a>Text value of the toggle.</p>
</td>
</tr>
<tr id="row1314733811"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p14144703815"><a name="p14144703815"></a><a name="p14144703815"></a>checked</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p174104714389"><a name="p174104714389"></a><a name="p174104714389"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p174134719389"><a name="p174134719389"></a><a name="p174134719389"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p86381558144516"><a name="p86381558144516"></a><a name="p86381558144516"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p184114763819"><a name="p184114763819"></a><a name="p184114763819"></a>Whether the toggle is selected.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section3655917541"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table83631117191317"></a>
<table><thead align="left"><tr id="row336351719135"><th class="cellrowborder" valign="top" width="17.928207179282072%" id="mcps1.1.6.1.1"><p id="p736319179132"><a name="p736319179132"></a><a name="p736319179132"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.088591140885912%" id="mcps1.1.6.1.2"><p id="p736311741311"><a name="p736311741311"></a><a name="p736311741311"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="21.41785821417858%" id="mcps1.1.6.1.3"><p id="p836331716138"><a name="p836331716138"></a><a name="p836331716138"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="6.979302069793021%" id="mcps1.1.6.1.4"><p id="p836314176137"><a name="p836314176137"></a><a name="p836314176137"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="39.58604139586041%" id="mcps1.1.6.1.5"><p id="p10363151721312"><a name="p10363151721312"></a><a name="p10363151721312"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row203632017171314"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="p8363111761310"><a name="p8363111761310"></a><a name="p8363111761310"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="p18363101741314"><a name="p18363101741314"></a><a name="p18363101741314"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="p17456195124520"><a name="p17456195124520"></a><a name="p17456195124520"></a>#E5000000</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="p18363317181316"><a name="p18363317181316"></a><a name="p18363317181316"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="p2363151712139"><a name="p2363151712139"></a><a name="p2363151712139"></a>Text color of the toggle.</p>
</td>
</tr>
<tr id="row15363111781318"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="p18363111712132"><a name="p18363111712132"></a><a name="p18363111712132"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="p12364101716134"><a name="p12364101716134"></a><a name="p12364101716134"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="p0364117101318"><a name="p0364117101318"></a><a name="p0364117101318"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="p6364161719139"><a name="p6364161719139"></a><a name="p6364161719139"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="p2364201716136"><a name="p2364201716136"></a><a name="p2364201716136"></a>Font size of the toggle.</p>
</td>
</tr>
<tr id="row1836411177134"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="p11364161781315"><a name="p11364161781315"></a><a name="p11364161781315"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="p133641917161317"><a name="p133641917161317"></a><a name="p133641917161317"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="p1336415173138"><a name="p1336415173138"></a><a name="p1336415173138"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="p536415173134"><a name="p536415173134"></a><a name="p536415173134"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="p536491719137"><a name="p536491719137"></a><a name="p536491719137"></a>Whether the font size changes with the system's font size settings.</p>
<div class="note" id="note236431714138"><a name="note236431714138"></a><a name="note236431714138"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p6364161721312"><a name="p6364161721312"></a><a name="p6364161721312"></a>If the <strong id="b9631151853613"><a name="b9631151853613"></a><a name="b9631151853613"></a>config-changes</strong> tag of <strong id="b15641171817360"><a name="b15641171817360"></a><a name="b15641171817360"></a>fontSize</strong> is configured for abilities in the <strong id="b20644418103618"><a name="b20644418103618"></a><a name="b20644418103618"></a>config.json</strong> file, the setting takes effect without application restart.</p>
</div></div>
</td>
</tr>
<tr id="row736421781317"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="p6364717181310"><a name="p6364717181310"></a><a name="p6364717181310"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="p18364121761313"><a name="p18364121761313"></a><a name="p18364121761313"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="p236413174139"><a name="p236413174139"></a><a name="p236413174139"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="p153646178137"><a name="p153646178137"></a><a name="p153646178137"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="p7364131711318"><a name="p7364131711318"></a><a name="p7364131711318"></a>Font style of the toggle.</p>
</td>
</tr>
<tr id="row636418171130"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="p7364817161320"><a name="p7364817161320"></a><a name="p7364817161320"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="p103641917161316"><a name="p103641917161316"></a><a name="p103641917161316"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="p1436451761313"><a name="p1436451761313"></a><a name="p1436451761313"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="p143641717171314"><a name="p143641717171314"></a><a name="p143641717171314"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="p1736431716139"><a name="p1736431716139"></a><a name="p1736431716139"></a>Font weight of the toggle. For details, see <strong id="b738112421315"><a name="b738112421315"></a><a name="b738112421315"></a>font-weight</strong> of the <a href="js-components-basic-text.md#section5775351116">text</a> component.</p>
</td>
</tr>
<tr id="row53641817161320"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="p19364171718135"><a name="p19364171718135"></a><a name="p19364171718135"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="p336415178135"><a name="p336415178135"></a><a name="p336415178135"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="p10365131761314"><a name="p10365131761314"></a><a name="p10365131761314"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="p2036581716132"><a name="p2036581716132"></a><a name="p2036581716132"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="p133656177131"><a name="p133656177131"></a><a name="p133656177131"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> is used for the text.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section3892191911214"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table101871711203115"></a>
<table><thead align="left"><tr id="row1718751111316"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row105681412318"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p18889152411316"><a name="p18889152411316"></a><a name="p18889152411316"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p138891924103112"><a name="p138891924103112"></a><a name="p138891924103112"></a>{ checked: isChecked }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1889002418312"><a name="p1889002418312"></a><a name="p1889002418312"></a>Triggered when the toggle is selected or unselected.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example<a name="section520313404174"></a>

```
<!-- xxx.hml -->
<div style="flex-direction: column;">
  <text class="margin">1. Multiple choice example</text>
  <div style="flex-wrap: wrap">
    <toggle class="margin" for="{{toggles}}">{{$item}}</toggle>
  </div>
  <text class="margin">2. Single choice example</text>
  <div style="flex-wrap: wrap">
    <toggle class="margin" for="{{toggle_list}}" id="{{$item.id}}" checked="{{$item.checked}}" 
      value="{{$item.name}}" @change="allchange" @click="allclick({{$item.id}})"></toggle>
  </div>
</div>
```

```
/* xxx.css */
.margin {
  margin: 7px;
}
```

```
// xxx.js
export default {
  data: {
    toggle_list: [
      { "id":"1001", "name":"Living room", "checked":true },
      { "id":"1002", "name":"Bedroom", "checked":false },
      { "id":"1003", "name":"Second bedroom", "checked":false },
      { "id":"1004", "name":"Kitchen", "checked":false },
      { "id":"1005", "name":"Study", "checked":false },
      { "id":"1006", "name":"Garden", "checked":false },
      { "id":"1007", "name":"Bathroom", "checked":false },
      { "id":"1008", "name":"Balcony", "checked":false },
    ],
    toggles: ["Living room","Bedroom","Kitchen","Study"],
    idx: ""
  },
  allclick(arg) {
    this.idx = arg
  },
  allchange(e) {
    if (e.checked === true) {
      for (var i = 0; i < this.toggle_list.length; i++) {
        if (this.toggle_list[i].id === this.idx) {
          this.toggle_list[i].checked = true
        } else {
          this.toggle_list[i].checked = false
        }
      }
    }
  }
}
```

![](figures/screenshot.png)

