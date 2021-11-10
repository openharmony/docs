# 转场样式<a name="ZH-CN_TOPIC_0000001127125110"></a>

## 共享元素转场<a name="section1884520391817"></a>

**表 1**  共享元素转场属性

<a name="table74342031134012"></a>
<table><thead align="left"><tr id="row16523131144020"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.2.5.1.1"><p id="p1752416310408"><a name="p1752416310408"></a><a name="p1752416310408"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.920000000000002%" id="mcps1.2.5.1.2"><p id="p552423110408"><a name="p552423110408"></a><a name="p552423110408"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="16.41%" id="mcps1.2.5.1.3"><p id="p18524103164010"><a name="p18524103164010"></a><a name="p18524103164010"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="55.300000000000004%" id="mcps1.2.5.1.4"><p id="p85241931154019"><a name="p85241931154019"></a><a name="p85241931154019"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row5524631174014"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.5.1.1 "><p id="p452483174010"><a name="p452483174010"></a><a name="p452483174010"></a>shareid</p>
</td>
<td class="cellrowborder" valign="top" width="12.920000000000002%" headers="mcps1.2.5.1.2 "><p id="p3524143118404"><a name="p3524143118404"></a><a name="p3524143118404"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16.41%" headers="mcps1.2.5.1.3 "><p id="p2524431164017"><a name="p2524431164017"></a><a name="p2524431164017"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="55.300000000000004%" headers="mcps1.2.5.1.4 "><p id="p135243315406"><a name="p135243315406"></a><a name="p135243315406"></a>进行共享元素转场时使用，若不配置，则转场样式不生效。共享元素转场当前支持的组件：list-item、image、text、button、label。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  共享元素转场样式

<a name="t8a80feb634c14ee59413c6f7c9fed858"></a>
<table><thead align="left"><tr id="rc8f205abe50c4069b741f1d3085b82bb"><th class="cellrowborder" valign="top" width="26.780000000000005%" id="mcps1.2.5.1.1"><p id="a6da2878dff98420d811406562c90f38e"><a name="a6da2878dff98420d811406562c90f38e"></a><a name="a6da2878dff98420d811406562c90f38e"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.2.5.1.2"><p id="a3e96e3cd29684dd59c65defd1d8e7f89"><a name="a3e96e3cd29684dd59c65defd1d8e7f89"></a><a name="a3e96e3cd29684dd59c65defd1d8e7f89"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.2.5.1.3"><p id="a1f58fb2c54054fd980aab5656afa864c"><a name="a1f58fb2c54054fd980aab5656afa864c"></a><a name="a1f58fb2c54054fd980aab5656afa864c"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.260000000000005%" id="mcps1.2.5.1.4"><p id="a03f3c47f058d4a26bb5b19a5b7468ac8"><a name="a03f3c47f058d4a26bb5b19a5b7468ac8"></a><a name="a03f3c47f058d4a26bb5b19a5b7468ac8"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="rd2368edf2c9e438c88e941389eb4f0ea"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.2.5.1.1 "><p id="p874892402117"><a name="p874892402117"></a><a name="p874892402117"></a>shared-transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.2 "><p id="ab1c301abb41c4c21867fd512f37311e9"><a name="ab1c301abb41c4c21867fd512f37311e9"></a><a name="ab1c301abb41c4c21867fd512f37311e9"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.3 "><p id="ab2ca6af17390483ea2a1b24486cdce9e"><a name="ab2ca6af17390483ea2a1b24486cdce9e"></a><a name="ab2ca6af17390483ea2a1b24486cdce9e"></a>exchange</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.2.5.1.4 "><p id="p1599914412216"><a name="p1599914412216"></a><a name="p1599914412216"></a>配置共享元素转场时的入场样式。</p>
<p id="p12999641122118"><a name="p12999641122118"></a><a name="p12999641122118"></a>当前支持：exchange或static，默认为exchange。</p>
<p id="p10999194192114"><a name="p10999194192114"></a><a name="p10999194192114"></a>转场时，目的页配置的样式优先生效。</p>
<a name="ul1231001135311"></a><a name="ul1231001135311"></a><ul id="ul1231001135311"><li>exchange表示源页面元素移动到目的页元素位置，并进行适当缩放。</li><li>static表示目的页元素位置不变，用户可配置透明度动画。当前仅跳转目标页配置的static效果生效。</li></ul>
</td>
</tr>
<tr id="row2544647142116"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.2.5.1.1 "><p id="p254415477214"><a name="p254415477214"></a><a name="p254415477214"></a>shared-transition-name</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.2 "><p id="p454484719213"><a name="p454484719213"></a><a name="p454484719213"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.3 "><p id="p1544204722119"><a name="p1544204722119"></a><a name="p1544204722119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.2.5.1.4 "><p id="p45835515223"><a name="p45835515223"></a><a name="p45835515223"></a>转场时，目的页配置的样式优先生效。该样式用于配置共享元素的动画效果，一个由@keyframes定义的动画序列，支持transform和透明度动画。若共享元素效果与自定义的动画冲突，以自定义动画为准。</p>
</td>
</tr>
<tr id="row642791311221"><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.2.5.1.1 "><p id="p34274132224"><a name="p34274132224"></a><a name="p34274132224"></a>shared-transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.2 "><p id="p1342771362219"><a name="p1342771362219"></a><a name="p1342771362219"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.2.5.1.3 "><p id="p8427101342213"><a name="p8427101342213"></a><a name="p8427101342213"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.2.5.1.4 "><p id="p1979164818229"><a name="p1979164818229"></a><a name="p1979164818229"></a>转场时，目的页配置的样式优先生效。该属性定义了共享元素转场时的差值曲线。若不配置，默认使用friction曲线。</p>
</td>
</tr>
</tbody>
</table>

## 共享元素注意事项<a name="section91806261439"></a>

1. 若同时配置了共享元素转场和自定义页面转场样式，页面转场效果以自定义效果为准；

2. 共享元素的exchange效果类似下图：

**图 1**  共享元素转场默认效果<a name="fig69431331672"></a>  
![](figures/共享元素转场默认效果.png "共享元素转场默认效果")

3. 共享元素动画对元素的边框、背景色不生效。

4. 共享元素转场时，由于页面元素会被隐藏，故页面元素配置的动画样式/动画方法失效。

5. 动态修改shareid：组件A的shareid被组件B的shareid覆盖，则组件A的共享元素效果失效，即使组件B的shareid被修改，此时组件A的共享元素效果也不会恢复。<sup>5+</sup>

## 共享元素示例代码<a name="section1568117161452"></a>

PageA跳转到PageB，跳转的共享元素为image， shareid为“shareImage”。

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

## 卡片转场样式<a name="section765051220203"></a>

<a name="table14211104092012"></a>
<table><thead align="left"><tr id="row112112406202"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p62118408204"><a name="p62118408204"></a><a name="p62118408204"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.2"><p id="p19211144052019"><a name="p19211144052019"></a><a name="p19211144052019"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.1.5.1.3"><p id="p6211134012207"><a name="p6211134012207"></a><a name="p6211134012207"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.1.5.1.4"><p id="p10211144052012"><a name="p10211144052012"></a><a name="p10211144052012"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1821274092016"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p20212740102017"><a name="p20212740102017"></a><a name="p20212740102017"></a>transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p id="p1721219403209"><a name="p1721219403209"></a><a name="p1721219403209"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p id="p42121340102014"><a name="p42121340102014"></a><a name="p42121340102014"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p id="p721204092018"><a name="p721204092018"></a><a name="p721204092018"></a>用于配置当前页面中的某个组件在卡片转场过程中是否进行转场动效，当前支持如下配置：</p>
<a name="ul2107101914291"></a><a name="ul2107101914291"></a><ul id="ul2107101914291"><li>unfold：配置这个属性的组件，如在卡片的上方，则向上移动一个卡片的高度，如在卡片的下方，则向下移动一个卡片的高度。</li><li>none：转场过程中没有动效。</li></ul>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>卡片转场无法和其他转场\(包括共享元素转场和自定义转场\)共同使用。

## 示例<a name="section814213323271"></a>

source\_page包含顶部内容以及卡片列表，点击卡片可以跳转到target\_page。

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

![](figures/卡片转场.gif)

## 页面转场样式<a name="section0565021620"></a>

**表 3**  页面转场样式

<a name="table486753518541"></a>
<table><thead align="left"><tr id="row0935835125411"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p1893512352542"><a name="p1893512352542"></a><a name="p1893512352542"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.2.5.1.2"><p id="p693503525419"><a name="p693503525419"></a><a name="p693503525419"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.2.5.1.3"><p id="p1493523565414"><a name="p1493523565414"></a><a name="p1493523565414"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.2.5.1.4"><p id="p1693518359542"><a name="p1693518359542"></a><a name="p1693518359542"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row10935173519540"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p9935103575411"><a name="p9935103575411"></a><a name="p9935103575411"></a>transition-enter</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.2.5.1.2 "><p id="p1193512354547"><a name="p1193512354547"></a><a name="p1193512354547"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1493563516544"><a name="p1493563516544"></a><a name="p1493563516544"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.2.5.1.4 "><p id="p493619354540"><a name="p493619354540"></a><a name="p493619354540"></a>与@keyframes配套使用，支持transform和透明度动画，详见<a href="js-components-common-animation.md#t48a722bba37a44c883ed4e046a4cf82e">表2</a>。</p>
</td>
</tr>
<tr id="row193633565417"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1993693511546"><a name="p1993693511546"></a><a name="p1993693511546"></a>transition-exit</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.2.5.1.2 "><p id="p19361035165410"><a name="p19361035165410"></a><a name="p19361035165410"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1293663519545"><a name="p1293663519545"></a><a name="p1293663519545"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.2.5.1.4 "><p id="p149361335125410"><a name="p149361335125410"></a><a name="p149361335125410"></a>与@keyframes配套使用，支持transform和透明度动画，详见<a href="js-components-common-animation.md#t48a722bba37a44c883ed4e046a4cf82e">表2</a>。</p>
</td>
</tr>
<tr id="row129362359540"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p49367357548"><a name="p49367357548"></a><a name="p49367357548"></a>transition-duration</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.2.5.1.2 "><p id="p11936183525411"><a name="p11936183525411"></a><a name="p11936183525411"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1793614351547"><a name="p1793614351547"></a><a name="p1793614351547"></a>跟随设备默认的页面转场时间</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.2.5.1.4 "><p id="p4936113565416"><a name="p4936113565416"></a><a name="p4936113565416"></a>支持的单位为[s(秒)|ms(毫秒) ]，默认单位为ms。</p>
</td>
</tr>
<tr id="row1693643515414"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p189368357548"><a name="p189368357548"></a><a name="p189368357548"></a>transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.2.5.1.2 "><p id="p1493612358548"><a name="p1493612358548"></a><a name="p1493612358548"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p393693555411"><a name="p393693555411"></a><a name="p393693555411"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.2.5.1.4 "><p id="p7936173505418"><a name="p7936173505418"></a><a name="p7936173505418"></a>描述转场动画执行的速度曲线，用于使转场更为平滑。详细参数见<a href="js-components-common-animation.md">动画样式</a>中“animation-timing-function”有效值说明。</p>
</td>
</tr>
</tbody>
</table>

## 页面转场注意事项<a name="section99079442062"></a>

1.  配置自定义转场时，建议配置页面背景色为不透明颜色，否则在转场过程中可能会出现衔接不自然的现象。
2.  transition-enter和transition-exit可单独配置，没有配置时使用系统默认的参数；
3.  transition-duration没有配置的时候使用系统默认值；
4.  transition-enter/transition-exit说明如下：
    1.  push场景下：进入页面栈的Page2.js应用transition-enter描述的动画配置；进入页面栈第二位置的Page1.js应用transition-exit描述的动画配置；

        ![](figures/zh-cn_image_0000001173324847.png)

    2.  back场景下：退出页面栈的Page2.js应用transition-enter描述的动画配置，并进行倒播；从页面栈第二位置进入栈顶位置的Page1.js应用transition-exit描述的动画配置，并进行倒播。

        ![](figures/zh-cn_image_0000001127125268.png)



