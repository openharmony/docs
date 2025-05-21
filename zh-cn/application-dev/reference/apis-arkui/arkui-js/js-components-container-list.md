# list

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

## 权限列表

无


## 子组件

仅支持&lt;[list-item-group](js-components-container-list-item-group.md)&gt;和&lt;[list-item](js-components-container-list-item.md)&gt;。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称                          | 类型                                       | 默认值     | 必填   | 描述                                       |
| --------------------------- | ---------------------------------------- | ------- | ---- | ---------------------------------------- |
| scrollpage                  | boolean                                  | false   | 否    | 设置为true时，将&nbsp;list&nbsp;顶部页面中非&nbsp;list&nbsp;部分随&nbsp;list&nbsp;一起滑出可视区域，当list方向为row时，不支持此属性。 |
| cachedcount                 | number                                   | 0       | 否    | 长列表延迟加载时list-item最少缓存数量。<br/>可视区域外缓存的list-item数量少于该值时，会触发requestitem事件。 |
| scrollbar                   | string                                   | off     | 否    | 侧边滑动栏的显示模式（当前只支持纵向）：<br/>-&nbsp;off：不显示。<br/>-&nbsp;auto：按需显示(触摸时显示，2s后消失)。<br/>-&nbsp;on：常驻显示。 |
| scrolleffect                | string                                   | spring  | 否    | 滑动效果，目前支持如下滑动效果：<br/>-&nbsp;spring：弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。<br/>-&nbsp;fade：渐隐物理动效，滑动到边缘后展示一个波浪形的渐隐，根据速度和滑动距离的变化渐隐也会发生一定的变化。<br/>-&nbsp;no：滑动到边缘后无效果。 |
| indexer                     | boolean&nbsp;\|&nbsp;Array&lt;string&gt; | false   | 否    | 是否展示侧边栏快速字母索引栏。设置为true或者自定义索引时，索引栏会显示在列表右边界处。示例：<br/>"indexer"&nbsp;:&nbsp;"true"表示使用默认字母索引表。<br/>"indexer"&nbsp;:&nbsp;"false"表示无索引。<br/>"indexer"&nbsp;:&nbsp;['\#',‘1’,'2',‘3’,'4',‘5’,'6',‘7’,'8']表示自定义索引表。自定义时"\#"必须要存在。<br/>indexer属性生效需要flex-direction属性配合设置为column，且columns属性设置为1。<br/>点击索引条进行列表项索引需要list-item子组件配合设置相应的[section属性](js-components-container-list-item.md#属性)。 |
| indexercircle<sup>5+</sup>  | boolean                                  | -       | 否    | 是否为环形索引。<br/>穿戴设备默认为true，其他为false。indexer为false时不生效。 |
| indexermulti<sup>5+</sup>   | boolean                                  | false   | 否    | 是否开启索引条多语言功能。<br/>indexer为false时不生效。     |
| indexerbubble<sup>5+</sup>  | boolean                                  | true    | 否    | 是否开启索引切换的气泡提示。<br/>indexer为false时不生效。    |
| divider<sup>5+</sup>        | boolean                                  | false   | 否    | item是否自带分隔线。<br/>其样式参考样式列表的divider-color、divider-height、divider-length、divider-origin。 |
| shapemode                   | string                                   | default | 否    | 侧边滑动栏的形状类型。<br/>-&nbsp;default：不指定，跟随主题；<br/>-&nbsp;rect：矩形；<br/>-&nbsp;round：圆形。 |
| updateeffect                | boolean                                  | false   | 否    | 用于设置当list内部的item发生删除或新增时是否支持动效。<br/>-&nbsp;false：新增删除item时无过渡动效。<br/>-&nbsp;true：新增删除item时播放过程动效。 |
| chainanimation<sup>5+</sup> | boolean                                  | false   | 否    | 用于设置当前list是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。链式联动效果：list内的list-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。<br/>-&nbsp;false：不启用链式联动<br/>-&nbsp;true：启用链式联动<br/>不支持动态修改。<br/>同时配置了indexer，链式动效不生效。<br/>如配置了链式动效，list-item的sticky不生效。 |
| initialindex                | number                                   | 0       | 否    | 用于设置当前List初次加载时视口起始位置显示的item，默认为0，即显示第一个item，如设置的序号超过了最后一个item的序号，则设置不生效，当同时设置了initialoffset属性时，当前属性不生效。当indexer为true或者scrollpage为true时，不生效。 |
| initialoffset               | &lt;length&gt;                           | 0       | 否    | 用于设置当前List初次加载时视口的起始偏移量，偏移量无法超过当前List可滑动的范围，如果超过会被截断为可滑动范围的极限值。当indexer为true或者scrollpage为true时，不生效。 |
| selected<sup>5+</sup>       | string                                   | -       | 否    | 指定当前列表中被选中激活的项，可选值为list-item的section属性值。 |


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称                            | 类型                                       | 默认值         | 必填   | 描述                                       |
| ----------------------------- | ---------------------------------------- | ----------- | ---- | ---------------------------------------- |
| divider-color<sup>5+</sup>    | &lt;color&gt;                            | transparent | 否    | item分隔线颜色，仅当list的divider属性为true时生效。      |
| divider-height<sup>5+</sup>   | &lt;length&gt;                           | 1           | 否    | item分隔线高度，仅当list的divider属性为true时生效。      |
| divider-length<sup>5+</sup>   | &lt;length&gt;                           | 主轴宽度        | 否    | item分隔线长度，不设置时最大长度为主轴宽度，具体长度取决于divider-origin，仅当list的divider属性为true时生效。 |
| divider-origin<sup>5+</sup>   | &lt;length&gt;                           | 0           | 否    | item分隔线相对于item主轴起点位置的偏移量，仅当list的divider属性为true时生效。 |
| flex-direction                | string                                   | column      | 否    | 设置flex容器主轴的方向，指定flex项如何放置在flex容器中，可选值为：<br/>-&nbsp;column：主轴为纵向。<br/>-&nbsp;row：主轴为横向。<br/>其他组件默认值为row，在list组件中默认值为column。 |
| columns                       | number                                   | 1           | 否    | list交叉轴方向的显示列数，默认为1列。<br/>设置多列时，在list交叉轴上进行均分，每一列大小相同。 |
| align-items                   | string                                   | stretch     | 否    | list每一列交叉轴上的对齐格式，可选值为：<br/>-&nbsp;stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。<br/>-&nbsp;flex-start：元素向交叉轴起点对齐。<br/>-&nbsp;flex-end：元素向交叉轴终点对齐。<br/>-&nbsp;center：元素在交叉轴居中。<br/>align-items样式作用在每一列的子元素上，列与列之间采用均分方式布局。 |
| item-extent                   | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | -           | 否    | 设置内部item为固定大小，设置为百分比格式时，指相对于list的视口主轴方向长度的百分比。 |
| fade-color                    | &lt;color&gt;                            | grey        | 否    | 设置渐隐物理动效的颜色。当滑动效果设置为渐隐物理动效时生效。           |
| scrollbar-color<sup>6+</sup>  | &lt;color&gt;                            | -           | 否    | 设置滚动条的颜色。                                |
| scrollbar-width<sup>6+</sup>  | &lt;length&gt;                           | -           | 否    | 设置滚动条的宽度。                                |
| scrollbar-offset<sup>6+</sup> | &lt;length&gt;                           | 0           | 否    | 设置滚动条距离List默认位置的偏移量，只支持正数，默认位置在List右边缘，可以通过这个偏移量调整滚动条的水平位置，如果滚动条绘制在list外部，而list父组件有裁剪，会导致滚动条被裁剪。 |


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

| 名称                       | 参数                                                         | 描述                                                         |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| indexerchange<sup>5+</sup> | {&nbsp;local:&nbsp;booleanValue&nbsp;}                       | 多语言索引条切换事件，仅当indexer属性为true，indexermulti为true时生效。booleanValue取值为true或false：<br/>-&nbsp;true:&nbsp;当前展示本地索引。<br/>-&nbsp;false:&nbsp;当前展示字母索引。 |
| scroll                     | {&nbsp;scrollX:&nbsp;scrollXValue,&nbsp;scrollY:&nbsp;scrollYValue,&nbsp;scrollState:&nbsp;stateValue&nbsp;} | 列表滑动的偏移量和状态回调。<br/>stateValue为0时表示列表滑动已停止。<br/>stateValue为1时表示列表在用户触摸状态下处于滑动中。<br/>stateValue为2时表示列表在用户松手状态下处于滑动中。 |
| scrollbottom               | -                                                            | 当前列表已滑动到底部位置。                                   |
| scrolltop                  | -                                                            | 当前列表已滑动到顶部位置。                                   |
| scrollend                  | -                                                            | 列表滑动已经结束。                                           |
| scrolltouchup              | -                                                            | 手指已经抬起且列表仍在惯性滑动。                             |
| requestitem                | -                                                            | 请求创建新的list-item。<br/>长列表延迟加载时，可视区域外缓存的list-item数量少于cachedcount时，会触发该事件。 |
| rotation<sup>7+</sup>      | {&nbsp;rotateValue:&nbsp;number&nbsp;}                       | 返回表冠旋转角度增量值，仅智能穿戴支持。                     |


## 方法

支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

| 名称            | 参数                                       | 描述                                       |
| ------------- | ---------------------------------------- | ---------------------------------------- |
| scrollTo      | {&nbsp;index:&nbsp;number(指定位置)&nbsp;}   | list滑动到指定index的item位置。                   |
| scrollTop     | {&nbsp;smooth:&nbsp;boolean&nbsp;}       | smooth缺省为false，表示直接滚动到顶部。<br/>smooth为true，表示平滑滚动到顶部。 |
| scrollBottom  | {&nbsp;smooth:&nbsp;boolean&nbsp;}       | smooth缺省为false，表示直接滚动到底部。<br/>smooth为true，表示平滑滚动到底部。 |
| scrollPage    | {&nbsp;reverse:&nbsp;boolean,&nbsp;smooth:&nbsp;boolean&nbsp;} | reverse缺省值为false，表示下一页，无完整页则滚动到底部。<br/>reverse为true，表示上一页，无完整页则滚动到顶部。<br/>smooth缺省值为false，表示直接滚动一页。<br/>smooth为true，表示平滑滚动一页。 |
| scrollArrow   | {&nbsp;reverse:&nbsp;boolean,&nbsp;smooth:&nbsp;boolean&nbsp;} | reverse缺省值为false，表示向底部方向滑动一段距离，无足够距离则滚动到底部。<br/>reverse为true，表示向顶部方向滑动一段距离，无足够距离则滚动到顶部。<br/>smooth缺省值为false，表示直接滚动。<br/>smooth为true，表示平滑滚动。 |
| collapseGroup | {&nbsp;groupid:&nbsp;string&nbsp;}       | 收起指定的group。<br/>groupid：需要收拢的group的id。<br/>当未指定groupid时收起所有group。 |
| expandGroup   | {&nbsp;groupid:&nbsp;string&nbsp;}       | 展开指定的group。<br/>groupid：需要展开的group的id。<br/>当groupid未指定时展开所有的group。 |
| currentOffset | -                                        | 返回当前滑动的偏移量。返回值类型是Object，返回值说明请见表 currentOffset返回对象属性说明。 |

**表1** currentOffset返回对象属性说明

| 名称   | 类型     | 备注               |
| ---- | ------ | ---------------- |
| x    | number | 当前x轴滑动偏移量，单位为px。 |
| y    | number | 当前y轴滑动偏移量，单位为px。 |

## 示例

```html
<!-- index.hml -->
<div class="container">
  <list class="todo-wrapper">
    <list-item for="{{todolist}}" class="todo-item">
      <div style="flex-direction: column;align-items: center;justify-content: center;">
        <text class="todo-title">{{$item.title}}</text>
        <text class="todo-title">{{$item.date}}</text>
      </div>
    </list-item>
  </list>
</div>
```
```css
/* index.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 100%;
}
.todo-wrapper {
  width: 100%;
  height: 300px;
}
.todo-item {
  width: 100%;
  height: 120px;
  justify-content:center;
}
.todo-title {
  width: 100%;
  height: 80px;
  text-align: center;
}
```

```js
// index.js
export default {
  data: {
    todolist: [{
      title: '刷题',
      date: '2021-12-31 10:00:00'
    }, {
      title: '看电影',
      date: '2021-12-31 20:00:00'
    }],
  },
}
```



![zh-cn_image_0000001185033226](figures/zh-cn_image_0000001185033226.png)
