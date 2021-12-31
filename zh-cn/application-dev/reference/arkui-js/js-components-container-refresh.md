# refresh<a name="ZH-CN_TOPIC_0000001173164669"></a>

下拉刷新容器。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持。

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>offset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>刷新组件静止时距离父组件顶部的距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>refreshing</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p><span>boolean</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>用于标识刷新组件当前是否正在刷新。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p><span>string</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置组件刷新时的动效。两个可选值，不支持动态修改。</p>
<ul><li>auto: 默认效果，列表界面拉到顶后，列表不移动，下拉后有转圈弹出。</li><li>pulldown: 列表界面拉到顶后，可以继续往下滑动一段距离触发刷新，刷新完成后有回弹效果（如果子组件含有list，防止下拉效果冲突，需将list的scrolleffect设置为no）。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>lasttime</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>是否显示上次更新时间，字符串格式为：“上次更新时间：XXXX ”，XXXX 按照时间日期显示规范显示，不可动态修改（建议type为pulldown时使用，固定距离位于内容下拉区域底部，使用时注意offset属性设置，防止出现重叠）。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>timeoffset<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置更新时间距离父组件顶部的距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>friction</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>42</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>下拉摩擦系数，取值范围：0-100，数值越大refresh组件跟手性高，数值越小refresh跟手性低。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机、平板和智能穿戴设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section1893981522413"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.03%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.86%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.76%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.449999999999999%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="37.9%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.1.6.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.86%" headers="mcps1.1.6.1.2 "><p><span>&lt;</span><span>color</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.76%" headers="mcps1.1.6.1.3 "><p>white</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.9%" headers="mcps1.1.6.1.5 "><p>用于设置刷新组件的背景颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.1.6.1.1 "><p>progress-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.86%" headers="mcps1.1.6.1.2 "><p><span>&lt;</span><span>color</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.76%" headers="mcps1.1.6.1.3 "><p>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.9%" headers="mcps1.1.6.1.5 "><p>用于设置刷新组件的loading颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section3892191911214"></a>

仅支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.79%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.74999999999999%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>refresh</p>
</td>
<td class="cellrowborder" valign="top" width="30.79%" headers="mcps1.1.4.1.2 "><p>{ refreshing: refreshingValue }</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.4.1.3 "><p>下拉刷新状态变化时触发。可能值：</p>
<ul><li>false：当前处于下拉刷新过程中。</li><li>true：当前未处于下拉刷新过程中。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>pulldown</p>
</td>
<td class="cellrowborder" valign="top" width="30.79%" headers="mcps1.1.4.1.2 "><p>{ state: string }</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.4.1.3 "><p>下拉开始和松手时触发。可能值：</p>
<ul><li>start：表示开始下拉。</li><li>end：表示结束下拉。</li></ul>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section2279124532420"></a>

不支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section1050103282219"></a>

```
<!-- xxx.hml -->
<div class="container">
  <refresh refreshing="{{fresh}}" onrefresh="refresh">
    <list class="list" scrolleffect="no">
      <list-item class="listitem" for="list">
        <div class="content">
          <text class="text">{{$item}}</text>
        </div>
      </list-item>
    </list>
  </refresh>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  width: 100%;
  height: 100%;
}

.list {
  width: 100%;
  height: 100%;
}

.listitem {
  width: 100%;
  height: 150px;
}

.content {
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}

.text {
  font-size: 35px;
  font-weight: bold;
}
```

```
// xxx.js
import prompt from '@system.prompt';
export default {
  data: {
    list:[],
    fresh:false
  },
  onInit() {
    this.list = [];
    for (var i = 0; i <= 3; i++) {
      var item = '列表元素' + i;
      this.list.push(item);
    }
  },
  refresh: function (e) {
    prompt.showToast({
      message: '刷新中...'
    })
    var that = this;
    that.fresh = e.refreshing;
    setTimeout(function () {
      that.fresh = false;
      var addItem = '更新元素';
      that.list.unshift(addItem);
      prompt.showToast({
        message: '刷新完成!'
      })
    }, 2000)
  }
}
```

![](figures/zh-cn_image_0000001150719520.gif)

