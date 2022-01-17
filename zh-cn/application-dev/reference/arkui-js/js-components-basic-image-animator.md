# image-animator<a name="ZH-CN_TOPIC_0000001173324625"></a>

图片帧动画播放器。

## 子组件<a name="section393521619565"></a>

不支持。

## 属性<a name="section1342212415618"></a>

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>images</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>Array&lt;ImageFrame&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置图片帧信息集合。每一帧的帧信息包含图片路径、图片大小和图片位置信息。目前支持以下图片格式：png、jpg。ImageFrame的详细说明请见<a href="#table67453165913">表1</a>。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用时需要使用数据绑定的方式，如images = {{images}}，js中声明相应变量：images: [{src: "/common/heart-rate01.png"}, {src: "/common/heart-rate02.png"}]。</p>
<p>js中声明相应变量：images: [{src: "/common/heart-rate01.png", duration: "100"}, {src: "/common/heart-rate02.png", duration: "200"}]。支持配置每一帧图片的时长，单位毫秒。<sup><span>6+</span></sup></p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>predecode<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>是否启用预解码，默认值为0，即不启用预解码，如该值设为2，则播放当前页时会提前加载后面两张图片至缓存以提升性能。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>iteration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>infinite</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置帧动画播放次数。number表示固定次数，infinite枚举表示无限次数播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>reverse</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置播放顺序。false表示从第1张图片播放到最后1张图片； true表示从最后1张图片播放到第1张图片。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>fixedsize</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置图片大小是否固定为组件大小。 true表示图片大小与组件大小一致，此时设置图片的width 、height 、top 和left属性是无效的。false表示每一张图片的 width 、height 、top和left属性都要单独设置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>duration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置单次播放时长。单位支持[s(秒)|ms(毫秒)]，默认单位为ms。 duration为0时，不播放图片。 值改变只会在下一次循环开始时生效，当images中设置了单独的duration后，该属性设置无效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>fillmode<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>forwards</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>指定帧动画执行结束后的状态。可选项有：</p>
<ul><li>none：恢复初始状态。</li><li>forwards：保持帧动画结束时的状态（在最后一个关键帧中定义）。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 1**  ImageFrame说明

<a name="table67453165913"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.330000000000002%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.860000000000001%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.000000000000002%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="58.00000000000001%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p>src</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;uri&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p>图片路径<span>，图片格式为svg，png和jpg</span>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p>图片宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p>图片高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p>top</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p>图片相对于组件左上角的纵向坐标。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p>left</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p>图片相对于组件左上角的横向坐标。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p>duration<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p>每一帧图片的播放时长，单位毫秒。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section1774719169253"></a>

支持[通用样式](js-components-common-styles.md)。

## 事件<a name="section17969351566"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>帧动画启动时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>帧动画暂停时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>stop</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>帧动画结束时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>resume</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>帧动画恢复时触发。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section1428810433566"></a>

支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="10.89%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="78.21000000000001%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p>开始播放图片帧动画。再次调用，重新从第1帧开始播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p>pause</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p>暂停播放图片帧动画。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p>stop</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p>停止播放图片帧动画。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p>resume</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p>继续播放图片帧。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p>getState</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p>获取播放状态。可能值有：</p>
<ul><li>playing：播放中</li><li>paused：已暂停</li><li>stopped：已停止。</li></ul>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section118221913375"></a>

```
<!-- xxx.hml -->
<div class="container">
  <image-animator class="animator" ref="animator" images="{{frames}}" duration="1s" />
  <div class="btn-box">
    <input class="btn" type="button" value="start" @click="handleStart" />
    <input class="btn" type="button" value="stop" @click="handleStop" />
    <input class="btn" type="button" value="pause" @click="handlePause" />
    <input class="btn" type="button" value="resume" @click="handleResume" />
  </div>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.animator {
  width: 70px;
  height: 70px;
}
.btn-box {
  width: 264px;
  height: 120px;
  flex-wrap: wrap;
  justify-content: space-around;
  align-items: center;
}
.btn {
  border-radius: 8px;
  width: 120px;
  margin-top: 8px;
}
```

```
//xxx.js
export default {
  data: {
    frames: [
      {
        src: "/common/asserts/heart78.png",
      },
      {
        src: "/common/asserts/heart79.png",
      },
      {
        src: "/common/asserts/heart80.png",
      },
      {
        src: "/common/asserts/heart81.png",
      },
      {
        src: "/common/asserts/heart82.png",
      },
      {
        src: "/common/asserts/heart83.png",
      },
      {
        src: "/common/asserts/heart84.png",
      },
      {
        src: "/common/asserts/heart85.png",
      },
      {
        src: "/common/asserts/heart86.png",
      },
      {
        src: "/common/asserts/heart87.png",
      },
      {
        src: "/common/asserts/heart88.png",
      },
      {
        src: "/common/asserts/heart89.png",
      },
      {
        src: "/common/asserts/heart90.png",
      },
      {
        src: "/common/asserts/heart91.png",
      },
      {
        src: "/common/asserts/heart92.png",
      },
      {
        src: "/common/asserts/heart93.png",
      },
      {
        src: "/common/asserts/heart94.png",
      },
      {
        src: "/common/asserts/heart95.png",
      },
      {
        src: "/common/asserts/heart96.png",
      },
    ],
  },
  handleStart() {
    this.$refs.animator.start();
  },
  handlePause() {
    this.$refs.animator.pause();
  },
  handleResume() {
    this.$refs.animator.resume();
  },
  handleStop() {
    this.$refs.animator.stop();
  },
};
```

![](figures/image-animator.gif)

