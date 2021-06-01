# Transition Styles<a name="EN-US_TOPIC_0000001162494591"></a>

-   [Transition of Shared Elements](#en-us_topic_0000001058460505_section1884520391817)
-   [Precautions for Shared Elements](#en-us_topic_0000001058460505_section91806261439)
-   [Sample Code](#en-us_topic_0000001058460505_section1568117161452)
-   [Card Transition](#en-us_topic_0000001058460505_section765051220203)
-   [Example Code](#en-us_topic_0000001058460505_section814213323271)
-   [Page Transition Styles](#en-us_topic_0000001058460505_section0565021620)
-   [Precautions for Page Transition](#en-us_topic_0000001058460505_section99079442062)

## Transition of Shared Elements<a name="en-us_topic_0000001058460505_section1884520391817"></a>

**Table  1**  Transition of shared elements

<a name="en-us_topic_0000001058460505_table74342031134012"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058460505_row16523131144020"><th class="cellrowborder" valign="top" width="30%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000001058460505_p1752416310408"><a name="en-us_topic_0000001058460505_p1752416310408"></a><a name="en-us_topic_0000001058460505_p1752416310408"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.150000000000002%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000001058460505_p552423110408"><a name="en-us_topic_0000001058460505_p552423110408"></a><a name="en-us_topic_0000001058460505_p552423110408"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.31%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000001058460505_p18524103164010"><a name="en-us_topic_0000001058460505_p18524103164010"></a><a name="en-us_topic_0000001058460505_p18524103164010"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="41.54%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000001058460505_p85241931154019"><a name="en-us_topic_0000001058460505_p85241931154019"></a><a name="en-us_topic_0000001058460505_p85241931154019"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058460505_row5524631174014"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p452483174010"><a name="en-us_topic_0000001058460505_p452483174010"></a><a name="en-us_topic_0000001058460505_p452483174010"></a>shareid</p>
</td>
<td class="cellrowborder" valign="top" width="16.150000000000002%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p3524143118404"><a name="en-us_topic_0000001058460505_p3524143118404"></a><a name="en-us_topic_0000001058460505_p3524143118404"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p2524431164017"><a name="en-us_topic_0000001058460505_p2524431164017"></a><a name="en-us_topic_0000001058460505_p2524431164017"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="41.54%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p135243315406"><a name="en-us_topic_0000001058460505_p135243315406"></a><a name="en-us_topic_0000001058460505_p135243315406"></a>Used for the transition of shared elements and takes effect only when it is configured. <strong id="en-us_topic_0000001058460505_b1743713743518"><a name="en-us_topic_0000001058460505_b1743713743518"></a><a name="en-us_topic_0000001058460505_b1743713743518"></a>list-item</strong>, <strong id="en-us_topic_0000001058460505_b19535113911356"><a name="en-us_topic_0000001058460505_b19535113911356"></a><a name="en-us_topic_0000001058460505_b19535113911356"></a>image</strong>, <strong id="en-us_topic_0000001058460505_b5615541133512"><a name="en-us_topic_0000001058460505_b5615541133512"></a><a name="en-us_topic_0000001058460505_b5615541133512"></a>text</strong>, <strong id="en-us_topic_0000001058460505_b5965124213359"><a name="en-us_topic_0000001058460505_b5965124213359"></a><a name="en-us_topic_0000001058460505_b5965124213359"></a>button</strong>, <strong id="en-us_topic_0000001058460505_b1414994417359"><a name="en-us_topic_0000001058460505_b1414994417359"></a><a name="en-us_topic_0000001058460505_b1414994417359"></a>label</strong> components are supported for the transition of shared elements.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Transition styles of shared elements

<a name="en-us_topic_0000001058460505_t8a80feb634c14ee59413c6f7c9fed858"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058460505_rc8f205abe50c4069b741f1d3085b82bb"><th class="cellrowborder" valign="top" width="26.780000000000005%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000001058460505_a6da2878dff98420d811406562c90f38e"><a name="en-us_topic_0000001058460505_a6da2878dff98420d811406562c90f38e"></a><a name="en-us_topic_0000001058460505_a6da2878dff98420d811406562c90f38e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000001058460505_a3e96e3cd29684dd59c65defd1d8e7f89"><a name="en-us_topic_0000001058460505_a3e96e3cd29684dd59c65defd1d8e7f89"></a><a name="en-us_topic_0000001058460505_a3e96e3cd29684dd59c65defd1d8e7f89"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000001058460505_a1f58fb2c54054fd980aab5656afa864c"><a name="en-us_topic_0000001058460505_a1f58fb2c54054fd980aab5656afa864c"></a><a name="en-us_topic_0000001058460505_a1f58fb2c54054fd980aab5656afa864c"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="42.260000000000005%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000001058460505_a03f3c47f058d4a26bb5b19a5b7468ac8"><a name="en-us_topic_0000001058460505_a03f3c47f058d4a26bb5b19a5b7468ac8"></a><a name="en-us_topic_0000001058460505_a03f3c47f058d4a26bb5b19a5b7468ac8"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058460505_rd2368edf2c9e438c88e941389eb4f0ea"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p874892402117"><a name="en-us_topic_0000001058460505_p874892402117"></a><a name="en-us_topic_0000001058460505_p874892402117"></a>shared-transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_ab1c301abb41c4c21867fd512f37311e9"><a name="en-us_topic_0000001058460505_ab1c301abb41c4c21867fd512f37311e9"></a><a name="en-us_topic_0000001058460505_ab1c301abb41c4c21867fd512f37311e9"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_ab2ca6af17390483ea2a1b24486cdce9e"><a name="en-us_topic_0000001058460505_ab2ca6af17390483ea2a1b24486cdce9e"></a><a name="en-us_topic_0000001058460505_ab2ca6af17390483ea2a1b24486cdce9e"></a>exchange</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p1599914412216"><a name="en-us_topic_0000001058460505_p1599914412216"></a><a name="en-us_topic_0000001058460505_p1599914412216"></a>Entry style of shared elements during the transition, which can be <strong id="en-us_topic_0000001058460505_b1518610917494"><a name="en-us_topic_0000001058460505_b1518610917494"></a><a name="en-us_topic_0000001058460505_b1518610917494"></a>exchange</strong> or <strong id="en-us_topic_0000001058460505_b999421164912"><a name="en-us_topic_0000001058460505_b999421164912"></a><a name="en-us_topic_0000001058460505_b999421164912"></a>static</strong>.</p>
<p id="en-us_topic_0000001058460505_p10999194192114"><a name="en-us_topic_0000001058460505_p10999194192114"></a><a name="en-us_topic_0000001058460505_p10999194192114"></a>During the transition, the style configured on the target page takes effect preferentially.</p>
<a name="en-us_topic_0000001058460505_ul1231001135311"></a><a name="en-us_topic_0000001058460505_ul1231001135311"></a><ul id="en-us_topic_0000001058460505_ul1231001135311"><li><strong id="en-us_topic_0000001058460505_b17798014123719"><a name="en-us_topic_0000001058460505_b17798014123719"></a><a name="en-us_topic_0000001058460505_b17798014123719"></a>exchange</strong>: The source page element is moved to the position of the target page element and is zoomed in or out properly.</li><li><strong id="en-us_topic_0000001058460505_b711910329372"><a name="en-us_topic_0000001058460505_b711910329372"></a><a name="en-us_topic_0000001058460505_b711910329372"></a>static</strong>: The position of the target page element remains unchanged. You can configure the transparency animation. Currently, only the static effect configured on the target page takes effect.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058460505_row2544647142116"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p254415477214"><a name="en-us_topic_0000001058460505_p254415477214"></a><a name="en-us_topic_0000001058460505_p254415477214"></a>shared-transition-name</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p454484719213"><a name="en-us_topic_0000001058460505_p454484719213"></a><a name="en-us_topic_0000001058460505_p454484719213"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p1544204722119"><a name="en-us_topic_0000001058460505_p1544204722119"></a><a name="en-us_topic_0000001058460505_p1544204722119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p45835515223"><a name="en-us_topic_0000001058460505_p45835515223"></a><a name="en-us_topic_0000001058460505_p45835515223"></a>During the transition, the style configured on the target page takes effect preferentially. This style is used to configure the animation effect of shared elements. The animation effect is an animation sequence defined by @keyframes supporting transform and transparency animations. If the effect of the shared element conflicts with the custom animation, the latter is used.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058460505_row642791311221"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p34274132224"><a name="en-us_topic_0000001058460505_p34274132224"></a><a name="en-us_topic_0000001058460505_p34274132224"></a>shared-transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p1342771362219"><a name="en-us_topic_0000001058460505_p1342771362219"></a><a name="en-us_topic_0000001058460505_p1342771362219"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p8427101342213"><a name="en-us_topic_0000001058460505_p8427101342213"></a><a name="en-us_topic_0000001058460505_p8427101342213"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p1979164818229"><a name="en-us_topic_0000001058460505_p1979164818229"></a><a name="en-us_topic_0000001058460505_p1979164818229"></a>During the transition, the style configured on the target page takes effect preferentially. This attribute defines the difference curve during the transition of shared elements. The friction curve is used by default if this parameter is not configured.</p>
</td>
</tr>
</tbody>
</table>

## Precautions for Shared Elements<a name="en-us_topic_0000001058460505_section91806261439"></a>

1. If shared element transition style and customized page transition style are both configured, the latter is used.

2. The exchange effect of the shared element is similar to the transition shown in the following figure.

**Figure  1**  Default transition effect of shared elements<a name="en-us_topic_0000001058460505_fig69431331672"></a>  
![](figures/default-transition-effect-of-shared-elements.png "default-transition-effect-of-shared-elements")

3. The shared element animation does not take effect for the border and background color of the element.

4. During the transition of a shared element, the page element is hidden. Therefore, the animation style and function set for the page element are invalid.

5. During the dynamic change of  **shareid**, if the  **shareid**  value in component A is overwritten by that in component B, the shared element effect of component A becomes ineffective and will not be restored even if the  **shareid**  value is changed in component B.  <sup>5+</sup>

## Sample Code<a name="en-us_topic_0000001058460505_section1568117161452"></a>

Page A jumps to Page B. The shared element is  **image**, and the  **shareid**  is "shareImage".

```
<!-- PageA -->
<!-- xxx.hml -->
<div>
  <list>
    <list-item type="description">
      <image src="item.jpg" shareid="shareImage" onclick="jump" class="shared-transition-style"></image>
      <text onclick="jump">Click on picture to Jump to ths details</text>
    </list-item>
  </list>
</div>
```

```
// xxx.js
import router from '@system.router';
export default {
  jump() {
    router.push({
      uri: 'detailpage',
    });
  },
}
```

```
/* xxx.css */
.shared-transition-style {
  shared-transition-effect: exchange;
  shared-transition-name: shared-transition;
}
@keyframes shared-transition {
  from { opacity: 0; }
  to { opacity: 1; }
}
```

```
<!-- PageB -->
<!-- xxx.hml -->
<div>
  <image src="itemDetail.jpg" shareid="shareImage" onclick="jumpBack" class="shared-transition-style"></image>
</div>
```

```
// xxx.js
import router from '@system.router';
export default {
  jumpBack() {
    router.back();
  },
}
```

```
/* xxx.css */
.shared-transition-style {
  shared-transition-effect: exchange;
  shared-transition-name: shared-transition;
}
@keyframes shared-transition {
  from { opacity: 0; }
  to { opacity: 1; }
}
```

## Card Transition<a name="en-us_topic_0000001058460505_section765051220203"></a>

**Table  3**  Card transition style

<a name="en-us_topic_0000001058460505_table14211104092012"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058460505_row112112406202"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000001058460505_p62118408204"><a name="en-us_topic_0000001058460505_p62118408204"></a><a name="en-us_topic_0000001058460505_p62118408204"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000001058460505_p19211144052019"><a name="en-us_topic_0000001058460505_p19211144052019"></a><a name="en-us_topic_0000001058460505_p19211144052019"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000001058460505_p6211134012207"><a name="en-us_topic_0000001058460505_p6211134012207"></a><a name="en-us_topic_0000001058460505_p6211134012207"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000001058460505_p10211144052012"><a name="en-us_topic_0000001058460505_p10211144052012"></a><a name="en-us_topic_0000001058460505_p10211144052012"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058460505_row1821274092016"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p20212740102017"><a name="en-us_topic_0000001058460505_p20212740102017"></a><a name="en-us_topic_0000001058460505_p20212740102017"></a>transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p1721219403209"><a name="en-us_topic_0000001058460505_p1721219403209"></a><a name="en-us_topic_0000001058460505_p1721219403209"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p42121340102014"><a name="en-us_topic_0000001058460505_p42121340102014"></a><a name="en-us_topic_0000001058460505_p42121340102014"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p721204092018"><a name="en-us_topic_0000001058460505_p721204092018"></a><a name="en-us_topic_0000001058460505_p721204092018"></a>Whether a component on the current page displays the transition effect during a card transition. Available values are as follows:</p>
<a name="en-us_topic_0000001058460505_ul2107101914291"></a><a name="en-us_topic_0000001058460505_ul2107101914291"></a><ul id="en-us_topic_0000001058460505_ul2107101914291"><li><strong id="en-us_topic_0000001058460505_b11897457195815"><a name="en-us_topic_0000001058460505_b11897457195815"></a><a name="en-us_topic_0000001058460505_b11897457195815"></a>unfold</strong>: The component will move upwards by one card height if the component locates above the card tapped by users, or move downwards by one card height if the component locates below the card.</li><li><strong id="en-us_topic_0000001058460505_b981213488710"><a name="en-us_topic_0000001058460505_b981213488710"></a><a name="en-us_topic_0000001058460505_b981213488710"></a>none</strong>: No transition effect is displayed.</li></ul>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Card transitions are not available when other transitions \(including shared element transitions and custom transitions\) are used.

## Example Code<a name="en-us_topic_0000001058460505_section814213323271"></a>

The  **source\_page**  has a title area on the top and a card list. Users can tap a card to switch to the  **target\_page**.

```
<!-- source_page -->
<!-- xxx.hml -->
<div class="container">
  <div class="outer">
    <text style="font-size: 23px; margin-bottom: 20px" >MAIN TITLE</text>
  </div>
  <list style="width:340px;height:600px;flex-direction:column;justify-content:center;align-items:center">
    <list-item type="listItem" class="item" card="true" for="list" id="{{$item.id}}"
        onclick="jumpPage({{$item.id}}, {{$item.uri}})">
      <text style="margin-left: 10px; font-size: 23px;">{{$item.title}}</text>
    </list-item>
  </list>
</div>
```

```
// xxx.js
import router from '@system.router'
export default {
  data: { list: [] },
  onInit() {
    for(var i = 0; i < 10; i++) {
      var item = { uri: "pages/card_transition/target_page/index", 
                   title: "this is title" + i, id: "item_" + i }
      this.list.push(item);
    }
  },
  jumpPage(id, uri) {
    var cardId = this.$element(id).ref;
    router.push({ uri: uri, params : { ref : cardId } });
  }
}
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  background-color: #ABDAFF;
}
.item {
  height: 80px;
  background-color: #FAFAFA;
  margin-top: 2px;
}
.outer {
  width: 300px;
  height: 100px;
  align-items: flex-end;
  transition-effect: unfold;
}
```

```
<!-- target_page -->
<!-- xxx.hml -->
<div class="container">
    <div class="div">
        <text style="font-size: 30px">this is detail</text>
    </div>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  background-color: #EBFFD7;
}
.div {
  height: 600px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
```

![](figures/卡片转场.gif)

## Page Transition Styles<a name="en-us_topic_0000001058460505_section0565021620"></a>

**Table  4**  Page transition styles

<a name="en-us_topic_0000001058460505_table486753518541"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058460505_row0935835125411"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000001058460505_p1893512352542"><a name="en-us_topic_0000001058460505_p1893512352542"></a><a name="en-us_topic_0000001058460505_p1893512352542"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000001058460505_p693503525419"><a name="en-us_topic_0000001058460505_p693503525419"></a><a name="en-us_topic_0000001058460505_p693503525419"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000001058460505_p1493523565414"><a name="en-us_topic_0000001058460505_p1493523565414"></a><a name="en-us_topic_0000001058460505_p1493523565414"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000001058460505_p1693518359542"><a name="en-us_topic_0000001058460505_p1693518359542"></a><a name="en-us_topic_0000001058460505_p1693518359542"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058460505_row10935173519540"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p9935103575411"><a name="en-us_topic_0000001058460505_p9935103575411"></a><a name="en-us_topic_0000001058460505_p9935103575411"></a>transition-enter</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p1193512354547"><a name="en-us_topic_0000001058460505_p1193512354547"></a><a name="en-us_topic_0000001058460505_p1193512354547"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p1493563516544"><a name="en-us_topic_0000001058460505_p1493563516544"></a><a name="en-us_topic_0000001058460505_p1493563516544"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p493619354540"><a name="en-us_topic_0000001058460505_p493619354540"></a><a name="en-us_topic_0000001058460505_p493619354540"></a>Related to @keyframes, which supports transform and transparent animations. For details, see <a href="animation-styles.md#en-us_topic_0000001058830799_t48a722bba37a44c883ed4e046a4cf82e">Table 2</a>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058460505_row193633565417"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p1993693511546"><a name="en-us_topic_0000001058460505_p1993693511546"></a><a name="en-us_topic_0000001058460505_p1993693511546"></a>transition-exit</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p19361035165410"><a name="en-us_topic_0000001058460505_p19361035165410"></a><a name="en-us_topic_0000001058460505_p19361035165410"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p1293663519545"><a name="en-us_topic_0000001058460505_p1293663519545"></a><a name="en-us_topic_0000001058460505_p1293663519545"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p149361335125410"><a name="en-us_topic_0000001058460505_p149361335125410"></a><a name="en-us_topic_0000001058460505_p149361335125410"></a>Related to @keyframes, which supports transform and transparent animations. For details, see <a href="animation-styles.md#en-us_topic_0000001058830799_t48a722bba37a44c883ed4e046a4cf82e">Table 2</a>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058460505_row129362359540"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p49367357548"><a name="en-us_topic_0000001058460505_p49367357548"></a><a name="en-us_topic_0000001058460505_p49367357548"></a>transition-duration</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p11936183525411"><a name="en-us_topic_0000001058460505_p11936183525411"></a><a name="en-us_topic_0000001058460505_p11936183525411"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p1793614351547"><a name="en-us_topic_0000001058460505_p1793614351547"></a><a name="en-us_topic_0000001058460505_p1793614351547"></a>Follows the default page transition time of the device.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p4936113565416"><a name="en-us_topic_0000001058460505_p4936113565416"></a><a name="en-us_topic_0000001058460505_p4936113565416"></a>The unit can be s or ms. The default unit is ms.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058460505_row1693643515414"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001058460505_p189368357548"><a name="en-us_topic_0000001058460505_p189368357548"></a><a name="en-us_topic_0000001058460505_p189368357548"></a>transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001058460505_p1493612358548"><a name="en-us_topic_0000001058460505_p1493612358548"></a><a name="en-us_topic_0000001058460505_p1493612358548"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001058460505_p393693555411"><a name="en-us_topic_0000001058460505_p393693555411"></a><a name="en-us_topic_0000001058460505_p393693555411"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001058460505_p7936173505418"><a name="en-us_topic_0000001058460505_p7936173505418"></a><a name="en-us_topic_0000001058460505_p7936173505418"></a>Speed curve of executing transition animation for smoother transition. For details about the parameters, see the description of the valid values of <strong id="en-us_topic_0000001058460505_b32887548111"><a name="en-us_topic_0000001058460505_b32887548111"></a><a name="en-us_topic_0000001058460505_b32887548111"></a>animation-timing-function</strong> in <a href="animation-styles.md#EN-US_TOPIC_0000001162414609">Animation Styles</a>.</p>
</td>
</tr>
</tbody>
</table>

## Precautions for Page Transition<a name="en-us_topic_0000001058460505_section99079442062"></a>

1.  When you set a customized transition, set the background color of the page to an opaque color. Otherwise, the transition effect can be harsh.
2.  The  **transition-enter**  and  **transition-exit**  parameters can be configured separately. The default parameters are used if they are not configured.
3.  The default value is used if  **transition-duration**  is not configured.
4.  Notes on the  **transition-enter**  and  **transition-exit**  parameters:
    1.  In the push scenario, enter the animation described by  **transition-enter**  of the  **Page2.js**  application in the page stack; enter the animation described by  **transition-exit**  of the  **Page1.js**  application in the second position of the page stack;

        ![](figures/en-us_image_0000001058830762.png)

    2.  In the back scenario, exit the animation described by  **transition-enter**  of the  **Page2.js**  application in the page stack and play the animation in reverse sequence; exit the animation described by  **transition-exit**  of the Page1.js application in the second position of the page stack and play the animation in reverse sequence.

        ![](figures/en-us_image_0000001058670863.png)



