# swiper<a name="ZH-CN_TOPIC_0000001173164745"></a>

滑动容器，提供切换子组件显示的能力。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持除<list\>之外的子组件。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>index</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>当前在容器中显示的子组件的索引值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>autoplay</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>子组件是否自动播放，自动播放状态下，导航点不可操作<sup><span>5+</span></sup>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>interval</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>3000</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>使用自动播放时播放的时间间隔，单位为ms。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>indicator</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>是否启用导航点指示器，默认true。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>digital<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>是否启用数字导航点，默认为false。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>必须设置indicator时才能生效数字导航点。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>indicatordisabled<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>指示器是否禁止用户手势操作，设置为true时，指示器不会响应用户的点击拖拽。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>loop</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>是否开启循环滑动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>duration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>子组件切换的动画时长。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>是否为纵向滑动，纵向滑动时采用纵向的指示器。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>cachedsize<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>swiper延迟加载时item最少缓存数量。-1表示全部缓存。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>scrolleffect<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>spring</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>滑动效果。目前支持如下：</p>
<ul><li>spring：弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。</li><li>fade：渐隐物理动效，滑动到边缘后展示一个波浪形的渐隐，根据速度和滑动距离的变化渐隐也会发送一定的变化</li><li>none：滑动到边缘后无效果。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>该属性仅在loop属性为false时生效。</p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section08721578337"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.08769123087691%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.94810518948105%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.428957104289571%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.08769123087691%" headers="mcps1.1.6.1.1 "><p>indicator-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.94810518948105%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.428957104289571%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>导航点指示器的填充颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.08769123087691%" headers="mcps1.1.6.1.1 "><p>indicator-selected-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.94810518948105%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.428957104289571%" headers="mcps1.1.6.1.3 "><p>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>导航点指示器选中的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.08769123087691%" headers="mcps1.1.6.1.1 "><p>indicator-size</p>
</td>
<td class="cellrowborder" valign="top" width="18.94810518948105%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.428957104289571%" headers="mcps1.1.6.1.3 "><p>4px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>导航点指示器的直径大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.08769123087691%" headers="mcps1.1.6.1.1 "><p>indicator-top|left|right|bottom</p>
</td>
<td class="cellrowborder" valign="top" width="18.94810518948105%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.428957104289571%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>导航点指示器在swiper中的相对位置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.08769123087691%" headers="mcps1.1.6.1.1 "><p>next-margin<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.94810518948105%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.428957104289571%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>后边距，用于露出后一项的一小部分。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.08769123087691%" headers="mcps1.1.6.1.1 "><p>previous-margin<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.94810518948105%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.428957104289571%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>前边距，用于露出前一项的一小部分。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section5891352194417"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.452945294529453%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.69456945694569%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.452945294529453%" headers="mcps1.1.4.1.2 "><p>{ index: currentIndex }</p>
</td>
<td class="cellrowborder" valign="top" width="45.69456945694569%" headers="mcps1.1.4.1.3 "><p>当前显示的组件索引变化时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>rotation</p>
</td>
<td class="cellrowborder" valign="top" width="29.452945294529453%" headers="mcps1.1.4.1.2 "><p>{ value: rotationValue }</p>
</td>
<td class="cellrowborder" valign="top" width="45.69456945694569%" headers="mcps1.1.4.1.3 "><p>智能穿戴表冠旋转事件触发时的回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>animationfinish<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.452945294529453%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.69456945694569%" headers="mcps1.1.4.1.3 "><p>动画结束时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.439999999999998%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.56%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.1.4.1.1 "><p>swipeTo</p>
</td>
<td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.4.1.2 "><p>{ index: number(指定位置) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p>切换到index位置的子组件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.1.4.1.1 "><p>showNext</p>
</td>
<td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.4.1.2 "><p>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p>显示下一个子组件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.1.4.1.1 "><p>showPrevious</p>
</td>
<td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.4.1.2 "><p>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p>显示上一个子组件。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1933534232313"></a>

```
<!-- xxx.hml -->
<div class="container">
  <swiper class="swiper" id="swiper" index="0" indicator="true" loop="true" digital="false" cachedsize="-1"
    scrolleffect="spring">
    <div class = "swiperContent1" >
      <text class = "text">First screen</text>
    </div>
    <div class = "swiperContent2">
      <text class = "text">Second screen</text>
    </div>
    <div class = "swiperContent3">
      <text class = "text">Third screen</text>
    </div>
  </swiper>
  <input class="button" type="button" value="swipeTo" onclick="swipeTo"></input>
  <input class="button" type="button" value="showNext" onclick="showNext"></input>
  <input class="button" type="button" value="showPrevious" onclick="showPrevious"></input>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  width: 100%;
  height: 100%;
  align-items: center;
}
.swiper {
  flex-direction: column;
  align-content: center;
  align-items: center;
  width: 70%;
  height: 130px;
  border: 1px solid #000000;
  indicator-color: #cf2411;
  indicator-size: 14px;
  indicator-bottom: 20px;
  indicator-right: 30px;
  margin-top: 100px;
  next-margin:20px;
  previous-margin:20px;
}
.swiperContent1{
  height: 100%;
  justify-content: center;
  background-color: #007dff;
}
.swiperContent2{
  height: 100%;
  justify-content: center;
  background-color: #ff7500;
}
.swiperContent3{
  height: 100%;
  justify-content: center;
  background-color: #41ba41;
}
.button {
  width: 70%;
  margin: 10px;
}
.text {
  font-size: 40px;
}
```

```
// xxx.js
export default {
  swipeTo() {
    this.$element('swiper').swipeTo({index: 2});
  },
  showNext() {
    this.$element('swiper').showNext();
  },
  showPrevious() {
    this.$element('swiper').showPrevious();
  }
}
```

![](figures/4-0.gif)

