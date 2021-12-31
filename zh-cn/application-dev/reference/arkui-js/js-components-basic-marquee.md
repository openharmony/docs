# marquee<a name="ZH-CN_TOPIC_0000001173324593"></a>

跑马灯组件，用于展示一段单行滚动的文字。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>scrollamount</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>6</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>跑马灯每次滚动时移动的最大长度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>loop</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>跑马灯滚动的次数。如果未指定，则默认值为-1，当该值小于等于零时表示marquee将连续滚动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>direction</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>left</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置跑马灯的文字滚动方向，可选值为left和right。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section14898114221220"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.137986201379864%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.968603139686032%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.358164183581643%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p>#e5000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置跑马灯中文字的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p>37.5</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置跑马灯中文字的文本尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置跑马灯中文字的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置跑马灯中文字的字体的粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置跑马灯中文字的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section3892191911214"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>bounce(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当文本滚动到末尾时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>finish(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当完成滚动次数时触发该事件。需要在 loop 属性值大于 0 时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>start(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当文本滚动开始时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.689999999999998%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="6.5600000000000005%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="76.75%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.689999999999998%" headers="mcps1.1.4.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="76.75%" headers="mcps1.1.4.1.3 "><p>开始滚动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.689999999999998%" headers="mcps1.1.4.1.1 "><p>stop</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="76.75%" headers="mcps1.1.4.1.3 "><p>停止滚动。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section198211501414"></a>

```
<!-- xxx.hml -->
<div class="container">
  <marquee id="customMarquee" class="customMarquee" scrollamount="{{scrollAmount}}" loop="{{loop}}"direction="{{marqueeDir}}"
    onbounce="onMarqueeBounce" onstart="onMarqueeStart" onfinish="onMarqueeFinish">{{marqueeCustomData}}</marquee>
  <div class="content">
    <button class="controlButton" onclick="onStartClick">Start</button>
    <button class="controlButton" onclick="onStopClick">Stop</button>
  </div>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #ffffff;
}
.customMarquee {
  width: 100%;
  height: 80px;
  padding: 10px;
  margin: 20px;
  border: 4px solid #ff8888;
  border-radius: 20px;
  font-size: 40px;
  color: #ff8888;
  font-weight: bolder;
  font-family: serif;
  background-color: #ffdddd;
}
.content {
  flex-direction: row;
}
.controlButton {
  flex-grow: 1;
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
```

```
// xxx.js
export default {
  data: {
    scrollAmount: 30,
    loop: 3,
    marqueeDir: 'left',
    marqueeCustomData: 'Custom marquee',
  },
  onMarqueeBounce: function() {
    console.log("onMarqueeBounce");
  },
  onMarqueeStart: function() {
    console.log("onMarqueeStart");
  },
  onMarqueeFinish: function() {
    console.log("onMarqueeFinish");
  },
  onStartClick (evt) {
    this.$element('customMarquee').start();
  },
  onStopClick (evt) {
    this.$element('customMarquee').stop();
  }
}
```

![](figures/sample1.gif)

