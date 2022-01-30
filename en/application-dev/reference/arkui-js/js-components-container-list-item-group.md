# list-item-group<a name="EN-US_TOPIC_0000001127284878"></a>

**<list-item-group\>**  is a child component of  **<[list](js-components-container-list.md)\>**  and is used to group items in a list. By default, the width of  **<list-item-group\>**  is equal to that of  **<list\>**.

-   To use this component, you must set the  **columns**  attribute of the parent component  **<list\>**  to  **1**. Otherwise,  **<list-item-group\>**  is not displayed.
-   You can customize the width of each  **<list-item-group\>**. However, if you retain the default value  **stretch**  of  **align-items**  for the parent component  **<list\>**, the width of  **<list-item-group\>**  is equal to that of  **<list\>**. You can set  **align-items**  to other values rather than  **stretch**  to make the customized  **<list-item-group\>**  width take effect.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

Only  **<[list-item](js-components-container-list-item.md)\>**  are supported.

## Attributes<a name="section2907183951110"></a>

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
<tbody><tr id="row527211401068"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p6939184510610"><a name="p6939184510610"></a><a name="p6939184510610"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p69393453620"><a name="p69393453620"></a><a name="p69393453620"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p193911451767"><a name="p193911451767"></a><a name="p193911451767"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p119391458611"><a name="p119391458611"></a><a name="p119391458611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p139402451361"><a name="p139402451361"></a><a name="p139402451361"></a>Type of the list-item-group. A list supports multiple list-item-group types. The same type of list-item-groups should have the same view layout after being rendered. When the type is fixed, replace the <strong id="b263714289617"><a name="b263714289617"></a><a name="b263714289617"></a>if</strong> attribute with the <strong id="b5356231164"><a name="b5356231164"></a><a name="b5356231164"></a>show</strong> attribute to ensure that the view layout remains unchanged.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   **id**  in the common attributes is used to identify a group. The input parameters of related functions and event information in the list also use  **id**  to uniquely identify a group.

## Styles<a name="section16337145611017"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table9906310171012"></a>
<table><thead align="left"><tr id="row6906101041013"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p1890611016103"><a name="p1890611016103"></a><a name="p1890611016103"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p1990610101108"><a name="p1990610101108"></a><a name="p1990610101108"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p159061109106"><a name="p159061109106"></a><a name="p159061109106"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p7906810181014"><a name="p7906810181014"></a><a name="p7906810181014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p109068103102"><a name="p109068103102"></a><a name="p109068103102"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1490613102106"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p7906161013101"><a name="p7906161013101"></a><a name="p7906161013101"></a>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p7906161061013"><a name="p7906161061013"></a><a name="p7906161061013"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p16906110121010"><a name="p16906110121010"></a><a name="p16906110121010"></a>row</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p7906181014108"><a name="p7906181014108"></a><a name="p7906181014108"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p17906191012103"><a name="p17906191012103"></a><a name="p17906191012103"></a>Main axis direction of the container. Available values are as follows:</p>
<a name="ul19906161071012"></a><a name="ul19906161071012"></a><ul id="ul19906161071012"><li><strong id="b166702410642221"><a name="b166702410642221"></a><a name="b166702410642221"></a>column</strong>: Items are placed vertically from top to bottom.</li><li><strong id="b45570924842221"><a name="b45570924842221"></a><a name="b45570924842221"></a>row</strong>: Items are placed horizontally from left to right.</li></ul>
</td>
</tr>
<tr id="row17907410111012"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p20907510121020"><a name="p20907510121020"></a><a name="p20907510121020"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1907510191019"><a name="p1907510191019"></a><a name="p1907510191019"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p39071110141015"><a name="p39071110141015"></a><a name="p39071110141015"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1690711091015"><a name="p1690711091015"></a><a name="p1690711091015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p5907171091012"><a name="p5907171091012"></a><a name="p5907171091012"></a>How items are aligned along the main axis of the current row in the container. Available values are as follows:</p>
<a name="ul39078107107"></a><a name="ul39078107107"></a><ul id="ul39078107107"><li><strong id="b38994401942221"><a name="b38994401942221"></a><a name="b38994401942221"></a>flex-start</strong>: Items are packed towards the start row.</li><li><strong id="b37986692242221"><a name="b37986692242221"></a><a name="b37986692242221"></a>flex-end</strong>: Items are packed towards the end row.</li><li><strong id="b156136190042221"><a name="b156136190042221"></a><a name="b156136190042221"></a>center</strong>: Items are centered along the row.</li><li><strong id="b42407860542221"><a name="b42407860542221"></a><a name="b42407860542221"></a>space-between</strong>: Items are positioned with space between the rows.</li><li><strong id="b182089689442221"><a name="b182089689442221"></a><a name="b182089689442221"></a>space-around</strong>: Items are positioned with space before, between, and after the rows.</li><li><strong id="b1452413538376"><a name="b1452413538376"></a><a name="b1452413538376"></a>space-evenly</strong><sup id="sup109071710111017"><a name="sup109071710111017"></a><a name="sup109071710111017"></a>5+</sup>: Items are arranged with even space between each two.</li></ul>
</td>
</tr>
</tbody>
</table>

## Events<a name="section1052914819116"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table185296841112"></a>
<table><thead align="left"><tr id="row0529118181119"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p105291481111"><a name="p105291481111"></a><a name="p105291481111"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.21242124212421%" id="mcps1.1.4.1.2"><p id="p75291381118"><a name="p75291381118"></a><a name="p75291381118"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.935093509350935%" id="mcps1.1.4.1.3"><p id="p17529108181117"><a name="p17529108181117"></a><a name="p17529108181117"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row853019819112"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p25301383111"><a name="p25301383111"></a><a name="p25301383111"></a>groupclick</p>
</td>
<td class="cellrowborder" valign="top" width="24.21242124212421%" headers="mcps1.1.4.1.2 "><p id="p953038201119"><a name="p953038201119"></a><a name="p953038201119"></a>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="50.935093509350935%" headers="mcps1.1.4.1.3 "><p id="p65301486113"><a name="p65301486113"></a><a name="p65301486113"></a>Triggered when a group is clicked.</p>
<p id="p9530128111113"><a name="p9530128111113"></a><a name="p9530128111113"></a><strong id="b6723111191819"><a name="b6723111191819"></a><a name="b6723111191819"></a>groupid</strong>: ID of the group that is clicked.</p>
</td>
</tr>
<tr id="row155301861119"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1853015818117"><a name="p1853015818117"></a><a name="p1853015818117"></a>groupcollapse</p>
</td>
<td class="cellrowborder" valign="top" width="24.21242124212421%" headers="mcps1.1.4.1.2 "><p id="p353011810115"><a name="p353011810115"></a><a name="p353011810115"></a>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="50.935093509350935%" headers="mcps1.1.4.1.3 "><p id="p65305861116"><a name="p65305861116"></a><a name="p65305861116"></a>Triggered when a group is collapsed.</p>
<p id="p1353016817113"><a name="p1353016817113"></a><a name="p1353016817113"></a><strong id="b171612547175"><a name="b171612547175"></a><a name="b171612547175"></a>groupid</strong>: ID of the group collapsed.</p>
<p id="p11530168201111"><a name="p11530168201111"></a><a name="p11530168201111"></a>If the parameter is not carried or <strong id="b033817189188"><a name="b033817189188"></a><a name="b033817189188"></a>groupid</strong> is left empty, all groups are collapsed.</p>
</td>
</tr>
<tr id="row1453014801111"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p18530383117"><a name="p18530383117"></a><a name="p18530383117"></a>groupexpand</p>
</td>
<td class="cellrowborder" valign="top" width="24.21242124212421%" headers="mcps1.1.4.1.2 "><p id="p753068161115"><a name="p753068161115"></a><a name="p753068161115"></a>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="50.935093509350935%" headers="mcps1.1.4.1.3 "><p id="p175301087114"><a name="p175301087114"></a><a name="p175301087114"></a>Triggered when a group is expanded.</p>
<p id="p1653058181112"><a name="p1653058181112"></a><a name="p1653058181112"></a><strong id="b2662173016182"><a name="b2662173016182"></a><a name="b2662173016182"></a>groupid</strong>: ID of the group expanded.</p>
<p id="p1653078131118"><a name="p1653078131118"></a><a name="p1653078131118"></a>If the parameter is not carried or <strong id="b16727027389"><a name="b16727027389"></a><a name="b16727027389"></a>groupid</strong> is left empty, all groups are expanded.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example<a name="section1159816598218"></a>

```
<!-- xxx.hml -->
<div class="doc-page">
  <list style="width: 100%;" id="mylist">
    <list-item class="top-list-item" clickeffect="false">
      <div class="item-div">
        <div class="item-child">
          <button type="capsule" value="Collapse first" onclick="collapseOne"></button>
          <button type="capsule" value="Expand first" onclick="expandOne"></button>
        </div>
        <div class="item-child">
          <button type="capsule" value="Collapse all" onclick="collapseAll"></button>
          <button type="capsule" value="Expand all" onclick="expandAll"></button>
        </div>
      </div>
    </list-item>
    <list-item-group for="listgroup in list" id="{{listgroup.value}}" ongroupcollapse="collapse" ongroupexpand="expand">
      <list-item type="item" style="background-color:#FFF0F5;height:95px;">
        <div class="item-group-child">
          <text>One---{{listgroup.value}}</text>
        </div>
      </list-item>
      <list-item type="item" style="background-color: #87CEFA;height:145px;" primary="true">
        <div class="item-group-child">
          <text>Primary---{{listgroup.value}}</text>
        </div>
      </list-item>
    </list-item-group>
  </list>
</div>
```

```
/* xxx.css */
.doc-page {
  flex-direction: column;
}
.top-list-item {
  width:100%;
  background-color:#D4F2E7;
}
.item-div {
  flex-direction:column;
  align-items:center;
  justify-content:space-around;
  height:240px;
}
.item-child {
  width:100%;
  height:60px;
  justify-content:space-around;
  align-items:center;
}
.item-group-child {
  justify-content: center;
  align-items: center;
  width:100%;
}
```

```
// xxx.js
import prompt from '@system.prompt';
export default {
  data: {
    direction: 'column',
    list: []
  },
  onInit() {
    this.list = []
    this.listAdd = []
    for (var i = 1; i <= 3; i++) {
      var dataItem = {
        value: 'GROUP' + i,
      };
      this.list.push(dataItem);
    }
  },
  collapseOne(e) {
    this.$element('mylist').collapseGroup({
      groupid: 'GROUP1'
    })
  },
  expandOne(e) {
    this.$element('mylist').expandGroup({
      groupid: 'GROUP1'
    })
  },
  collapseAll(e) {
    this.$element('mylist').collapseGroup()
  },
  expandAll(e) {
    this.$element('mylist').expandGroup()
  },
  collapse(e) {
    prompt.showToast({
      message: 'Close ' + e.groupid
    })
  },
  expand(e) {
    prompt.showToast({
      message: 'Open ' + e.groupid
    })
  }
}
```

![](figures/list6.gif)

