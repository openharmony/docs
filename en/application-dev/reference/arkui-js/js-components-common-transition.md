# Transition Styles<a name="EN-US_TOPIC_0000001127125110"></a>


## Transition of Shared Elements<a name="section1884520391817"></a>

### Attributes<a name="section179214816810"></a>

<a name="table82912285910"></a>
<table><thead align="left"><tr id="row529115281090"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.5.1.1"><p id="p9291182819919"><a name="p9291182819919"></a><a name="p9291182819919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.920000000000002%" id="mcps1.1.5.1.2"><p id="p62914282912"><a name="p62914282912"></a><a name="p62914282912"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="16.41%" id="mcps1.1.5.1.3"><p id="p32927280919"><a name="p32927280919"></a><a name="p32927280919"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="55.300000000000004%" id="mcps1.1.5.1.4"><p id="p129213284914"><a name="p129213284914"></a><a name="p129213284914"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row22926284912"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.5.1.1 "><p id="p329212281397"><a name="p329212281397"></a><a name="p329212281397"></a>shareid</p>
</td>
<td class="cellrowborder" valign="top" width="12.920000000000002%" headers="mcps1.1.5.1.2 "><p id="p929217284919"><a name="p929217284919"></a><a name="p929217284919"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16.41%" headers="mcps1.1.5.1.3 "><p id="p629219281491"><a name="p629219281491"></a><a name="p629219281491"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="55.300000000000004%" headers="mcps1.1.5.1.4 "><p id="p102929286918"><a name="p102929286918"></a><a name="p102929286918"></a>Used for the transition of shared elements and takes effect only when it is configured. <strong id="b159773615015"><a name="b159773615015"></a><a name="b159773615015"></a>list-item</strong>, <strong id="b7597036606"><a name="b7597036606"></a><a name="b7597036606"></a>image</strong>, <strong id="b14597153611017"><a name="b14597153611017"></a><a name="b14597153611017"></a>text</strong>, <strong id="b4597183614014"><a name="b4597183614014"></a><a name="b4597183614014"></a>button</strong>, <strong id="b115983361506"><a name="b115983361506"></a><a name="b115983361506"></a>label</strong> components are supported for the transition of shared elements.</p>
</td>
</tr>
</tbody>
</table>

### Styles<a name="section416125511818"></a>

<a name="table479613353912"></a>
<table><thead align="left"><tr id="row679619351695"><th class="cellrowborder" valign="top" width="26.780000000000005%" id="mcps1.1.5.1.1"><p id="p379673515915"><a name="p379673515915"></a><a name="p379673515915"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.1.5.1.2"><p id="p379613510916"><a name="p379613510916"></a><a name="p379613510916"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.1.5.1.3"><p id="p479623512916"><a name="p479623512916"></a><a name="p479623512916"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="42.260000000000005%" id="mcps1.1.5.1.4"><p id="p779753510912"><a name="p779753510912"></a><a name="p779753510912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row157971351895"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.1.5.1.1 "><p id="p1479716351794"><a name="p1479716351794"></a><a name="p1479716351794"></a>shared-transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.2 "><p id="p137971935390"><a name="p137971935390"></a><a name="p137971935390"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.3 "><p id="p20797135992"><a name="p20797135992"></a><a name="p20797135992"></a>exchange</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p197971335193"><a name="p197971335193"></a><a name="p197971335193"></a>Entry style of a shared element during transition.</p>
<a name="ul27978351494"></a><a name="ul27978351494"></a><ul id="ul27978351494"><li><strong id="b1213145515110"><a name="b1213145515110"></a><a name="b1213145515110"></a>exchange</strong> (default): The source page element is moved to the position of the target page element and is zoomed in or out properly.</li><li><strong id="b17991612320"><a name="b17991612320"></a><a name="b17991612320"></a>static</strong>: The position of the target page element remains unchanged. You can configure the transparency animation. Currently, only the static effect configured on the target page takes effect.</li></ul>
</td>
</tr>
<tr id="row17797123514918"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.1.5.1.1 "><p id="p67971135595"><a name="p67971135595"></a><a name="p67971135595"></a>shared-transition-name</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.2 "><p id="p1479783510920"><a name="p1479783510920"></a><a name="p1479783510920"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.3 "><p id="p5797153514916"><a name="p5797153514916"></a><a name="p5797153514916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p1779714351097"><a name="p1779714351097"></a><a name="p1779714351097"></a>During the transition, the style configured on the target page takes effect preferentially. This style is used to configure the animation effect of shared elements. The animation effect is an animation sequence defined by @keyframes supporting transform and transparency animations. If the effect of the shared element conflicts with the custom animation, the latter is used.</p>
</td>
</tr>
<tr id="row079715351598"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.1.5.1.1 "><p id="p079714350916"><a name="p079714350916"></a><a name="p079714350916"></a>shared-transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.2 "><p id="p879714351498"><a name="p879714351498"></a><a name="p879714351498"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.3 "><p id="p1079718351991"><a name="p1079718351991"></a><a name="p1079718351991"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p37974351492"><a name="p37974351492"></a><a name="p37974351492"></a>During the transition, the style configured on the target page takes effect preferentially. This property defines the difference curve during the transition of shared elements. If this parameter is not configured, the friction curve is used by default.</p>
</td>
</tr>
</tbody>
</table>

### Important Notes<a name="section181291131395"></a>

1. If shared element transition style and customized page transition style are both configured, the latter is used.

2. The exchange effect of the shared element is similar to the transition shown in the following figure.

**Figure  1**  Default transition effect of shared elements<a name="fig85705915913"></a>  
![](figures/default-transition-effect-of-shared-elements.png "default-transition-effect-of-shared-elements")

3. The shared element animation does not take effect for the border and background color of the element.

4. During the transition of a shared element, the page element is hidden. Therefore, the animation style and function set for the page element are invalid.

5. During the dynamic change of  **shareid**<sup>5+</sup>, if the  **shareid**  value in component A is overwritten by that in component B, the shared element effect of component A becomes ineffective and will not be restored even if the  **shareid**  value is changed in component B.

### Example<a name="section11396118910"></a>

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

## Card Transition<a name="section765051220203"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Card transitions are not available when other transitions \(including shared element transitions and custom transitions\) are used.

### Styles<a name="section1242474714118"></a>

<a name="table12840103417146"></a>
<table><thead align="left"><tr id="row584013348142"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p384019348141"><a name="p384019348141"></a><a name="p384019348141"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.2"><p id="p3840334171415"><a name="p3840334171415"></a><a name="p3840334171415"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.1.5.1.3"><p id="p3840173441413"><a name="p3840173441413"></a><a name="p3840173441413"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.1.5.1.4"><p id="p7840203461411"><a name="p7840203461411"></a><a name="p7840203461411"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15840143471416"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p168401934161410"><a name="p168401934161410"></a><a name="p168401934161410"></a>transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p id="p16840134161418"><a name="p16840134161418"></a><a name="p16840134161418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p id="p1484033413147"><a name="p1484033413147"></a><a name="p1484033413147"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p id="p6840173431412"><a name="p6840173431412"></a><a name="p6840173431412"></a>Whether a component on the current page displays the transition effect during a card transition. Available values are as follows:</p>
<a name="ul188401834121413"></a><a name="ul188401834121413"></a><ul id="ul188401834121413"><li><strong id="b11897457195815"><a name="b11897457195815"></a><a name="b11897457195815"></a>unfold</strong>: The component will move upwards by one card height if the component locates above the card tapped by users, or move downwards by one card height if the component locates below the card.</li><li><strong id="b4547119463"><a name="b4547119463"></a><a name="b4547119463"></a>none</strong>: No transition effect is displayed.</li></ul>
</td>
</tr>
</tbody>
</table>

### Example<a name="section13120105991118"></a>

The  **source\_page**  has a title area on the top and a card list. Users can tap a card to switch to the  **target\_page**.

```
<!-- source_page -->
<!-- xxx.hml -->
<div class="container">
  <div class="outer">
    <text style="font-size: 23px; margin-bottom: 20px" >MAIN TITLE</text>
  </div>
  <list style="width:340px;height:600px;flex-direction:column;justify-content:center;align-items:center">
    <list-item type="listItem" class="item" card="true" for="list" id="{{$item.id}}" onclick="jumpPage({{$item.id}}, {{$item.uri}})">
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

![](figures/form-transfer.gif)

## Page Transition Styles<a name="section0565021620"></a>

### Styles<a name="section11765348111217"></a>

<a name="table98161918171415"></a>
<table><thead align="left"><tr id="row1681631813148"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p1581731891415"><a name="p1581731891415"></a><a name="p1581731891415"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.2"><p id="p8817141811410"><a name="p8817141811410"></a><a name="p8817141811410"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.1.5.1.3"><p id="p1081721851418"><a name="p1081721851418"></a><a name="p1081721851418"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.1.5.1.4"><p id="p18176188145"><a name="p18176188145"></a><a name="p18176188145"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2081761831417"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p88171218191412"><a name="p88171218191412"></a><a name="p88171218191412"></a>transition-enter</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p id="p5817101841414"><a name="p5817101841414"></a><a name="p5817101841414"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p id="p1817191813146"><a name="p1817191813146"></a><a name="p1817191813146"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p id="p1581715188146"><a name="p1581715188146"></a><a name="p1581715188146"></a>Related to @keyframes, which supports transform and transparent animations. For details, see <a href="js-components-common-animation.md#t48a722bba37a44c883ed4e046a4cf82e">Table 2</a>.</p>
</td>
</tr>
<tr id="row9817151815148"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1381771818142"><a name="p1381771818142"></a><a name="p1381771818142"></a>transition-exit</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p id="p181741871413"><a name="p181741871413"></a><a name="p181741871413"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p id="p118174184144"><a name="p118174184144"></a><a name="p118174184144"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p id="p4817121818148"><a name="p4817121818148"></a><a name="p4817121818148"></a>Related to @keyframes, which supports transform and transparent animations. For details, see <a href="js-components-common-animation.md#t48a722bba37a44c883ed4e046a4cf82e">Table 2</a>.</p>
</td>
</tr>
<tr id="row281791813147"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1781761810144"><a name="p1781761810144"></a><a name="p1781761810144"></a>transition-duration</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p id="p118171318121420"><a name="p118171318121420"></a><a name="p118171318121420"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p id="p1881716183145"><a name="p1881716183145"></a><a name="p1881716183145"></a>Follows the default page transition time of the device.</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p id="p118179184142"><a name="p118179184142"></a><a name="p118179184142"></a>The unit can be s or ms. The default unit is ms. If no value is specified, the default value is used.</p>
</td>
</tr>
<tr id="row28178189141"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p138173184141"><a name="p138173184141"></a><a name="p138173184141"></a>transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p id="p1081813181141"><a name="p1081813181141"></a><a name="p1081813181141"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p id="p281871817146"><a name="p281871817146"></a><a name="p281871817146"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p id="p5818118101412"><a name="p5818118101412"></a><a name="p5818118101412"></a>Speed curve of executing transition animation for smoother transition. For details about the parameters, see the description of the valid values of <strong id="b208543341576"><a name="b208543341576"></a><a name="b208543341576"></a>animation-timing-function</strong> in <a href="js-components-common-animation.md">Animation Styles</a>.</p>
</td>
</tr>
</tbody>
</table>

### Important Notes<a name="section16968142012132"></a>

1.  When you set a customized transition, set the background color of the page to an opaque color. Otherwise, the transition effect can be harsh.
2.  The  **transition-enter**  and  **transition-exit**  parameters can be configured separately. The default parameters are used if they are not configured.
3.  Notes on the  **transition-enter**  and  **transition-exit**  parameters:
    1.  In the push scenario, enter the animation described by  **transition-enter**  of the  **Page2.js**  application in the page stack; enter the animation described by  **transition-exit**  of the  **Page1.js**  application in the second position of the page stack.

        ![](figures/en-us_image_0000001193704354.png)

    2.  In the back scenario, exit the animation described by  **transition-enter**  of the  **Page2.js**  application in the page stack and play the animation in reverse sequence; exit the animation described by  **transition-exit**  of the Page1.js application in the second position of the page stack and play the animation in reverse sequence.

        ![](figures/en-us_image_0000001238184345.png)



