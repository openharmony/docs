# 转场样式<a name="ZH-CN_TOPIC_0000001127125110"></a>

## 共享元素转场<a name="section1884520391817"></a>

### 属性<a name="section179214816810"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.920000000000002%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="16.41%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="55.300000000000004%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.5.1.1 "><p>shareid</p>
</td>
<td class="cellrowborder" valign="top" width="12.920000000000002%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="16.41%" headers="mcps1.1.5.1.3 "><p>无</p>
</td>
<td class="cellrowborder" valign="top" width="55.300000000000004%" headers="mcps1.1.5.1.4 "><p>进行共享元素转场时使用，若不配置，则转场样式不生效。共享元素转场当前支持的组件：list-item、image、text、button、label。</p>
</td>
</tr>
</tbody>
</table>

### 样式<a name="section416125511818"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="26.780000000000005%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.480000000000002%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.260000000000005%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.1.5.1.1 "><p>shared-transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.3 "><p>exchange</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.1.5.1.4 "><p>配置共享元素转场时的入场样式。</p>
<ul><li>exchange（默认值）：源页面元素移动到目的页元素位置，并进行适当缩放。</li><li>static：目的页元素位置不变，用户可配置透明度动画。当前仅跳转目标页配置的static效果生效。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.1.5.1.1 "><p>shared-transition-name</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.1.5.1.4 "><p>转场时，目的页配置的样式优先生效。该样式用于配置共享元素的动画效果，一个由@keyframes定义的动画序列，支持transform和透明度动画。若共享元素效果与自定义的动画冲突，以自定义动画为准。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.780000000000005%" headers="mcps1.1.5.1.1 "><p>shared-transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.480000000000002%" headers="mcps1.1.5.1.3 "><p>friction</p>
</td>
<td class="cellrowborder" valign="top" width="42.260000000000005%" headers="mcps1.1.5.1.4 "><p>转场时，目的页配置的样式优先生效。该属性定义了共享元素转场时的差值曲线。若不配置，默认使用friction曲线。</p>
</td>
</tr>
</tbody>
</table>

### 注意事项<a name="section181291131395"></a>

1. 若同时配置了共享元素转场和自定义页面转场样式，页面转场效果以自定义效果为准。

2. 共享元素的exchange效果类似下图。

**图 1**  共享元素转场默认效果  
![](figures/共享元素转场默认效果.png "共享元素转场默认效果")

3. 共享元素动画对元素的边框、背景色不生效。

4. 共享元素转场时，由于页面元素会被隐藏，故页面元素配置的动画样式/动画方法失效。

5. 动态修改shareid<sup>5+</sup>：组件A的shareid被组件B的shareid覆盖，则组件A的共享元素效果失效，即使组件B的shareid被修改，此时组件A的共享元素效果也不会恢复。

### 示例<a name="section11396118910"></a>

PageA跳转到PageB，跳转的共享元素为image， shareid为“shareImage”。

```
<!-- PageA -->
<!-- xxx.hml -->
<div>
    <list>
        <list-item type="description">
            <div>
                <image src="item.jpg" shareid="shareImage" onclick="jump" class="shared-transition-style"></image>
                <text onclick="jump">Click on picture to Jump to ths details</text>
            </div>
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

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>卡片转场无法和其他转场\(包括共享元素转场和自定义转场\)共同使用。

### 样式<a name="section1242474714118"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>transition-effect</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p>用于配置当前页面中的某个组件在卡片转场过程中是否进行转场动效，当前支持如下配置：</p>
<ul><li>unfold：配置这个属性的组件，如在卡片的上方，则向上移动一个卡片的高度，如在卡片的下方，则向下移动一个卡片的高度。</li><li>none：转场过程中没有动效。</li></ul>
</td>
</tr>
</tbody>
</table>

### 示例<a name="section13120105991118"></a>

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

### 样式<a name="section11765348111217"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="32.62%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>transition-enter</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p>与@keyframes配套使用，支持transform和透明度动画，详见<a href="js-components-common-animation.md#t48a722bba37a44c883ed4e046a4cf82e">表2</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>transition-exit</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p>与@keyframes配套使用，支持transform和透明度动画，详见<a href="js-components-common-animation.md#t48a722bba37a44c883ed4e046a4cf82e">表2</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>transition-duration</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p>跟随设备默认的页面转场时间</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p>支持的单位为[s(秒)|ms(毫秒) ]，默认单位为ms，未配置时使用系统默认值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>transition-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.1.5.1.3 "><p>friction</p>
</td>
<td class="cellrowborder" valign="top" width="32.62%" headers="mcps1.1.5.1.4 "><p>描述转场动画执行的速度曲线，用于使转场更为平滑。详细参数见<a href="js-components-common-animation.md">动画样式</a>中“animation-timing-function”有效值说明。</p>
</td>
</tr>
</tbody>
</table>

### 注意事项<a name="section16968142012132"></a>

1.  配置自定义转场时，建议配置页面背景色为不透明颜色，否则在转场过程中可能会出现衔接不自然的现象。
2.  transition-enter和transition-exit可单独配置，没有配置时使用系统默认的参数。
3.  transition-enter/transition-exit说明如下：
    1.  push场景下：进入页面栈的Page2.js应用transition-enter描述的动画配置；进入页面栈第二位置的Page1.js应用transition-exit描述的动画配置。

        ![](figures/zh-cn_image_0000001193704354.png)

    2.  back场景下：退出页面栈的Page2.js应用transition-enter描述的动画配置，并进行倒播；从页面栈第二位置进入栈顶位置的Page1.js应用transition-exit描述的动画配置，并进行倒播。

        ![](figures/zh-cn_image_0000001238184345.png)



