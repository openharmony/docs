# 生命周期定义<a name="ZH-CN_TOPIC_0000001127125084"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

我们为自定义组件提供了一系列生命周期回调方法，便于开发者管理自定义组件的内部逻辑。生命周期主要包括：onInit，onAttached，onDetached，onLayoutReady，onDestroy，onPageShow和onPageHide。下面我们依次介绍一下各个生命周期回调的时机。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.441444144414442%" id="mcps1.1.5.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="10.121012101210122%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.1.5.1.3"><p>描述</p>
</th>
<th class="cellrowborder" valign="top" width="56.685668566856684%" id="mcps1.1.5.1.4"><p>触发时机</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onInit</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>初始化自定义组件</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件初始化生命周期回调，当自定义组件创建时，触发该回调，主要用于自定义组件中必须使用的数据初始化，该回调只会触发一次调用。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onAttached</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>自定义组件装载</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件被创建后，加入到Page组件树时，触发该回调，该回调触发时，表示组件将被进行显示，该生命周期可用于初始化显示相关数据，通常用于加载图片资源、开始执行动画等场景。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onLayoutReady</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>自定义组件布局完成</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件插入Page组件树后，将会对自定义组件进行布局计算，调整其内容元素尺寸与位置，当布局计算结束后触发该回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onDetached</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>自定义组件摘除</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件摘除时，触发该回调，常用于停止动画或异步逻辑停止执行的场景。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>自定义组件销毁</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件销毁时，触发该回调，常用于资源释放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onPageShow</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>自定义组件Page显示</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件所在Page显示后，触发该回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p>onPageHide</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p>自定义组件Page隐藏</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p>自定义组件所在Page隐藏后，触发该回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section14938111864313"></a>

```
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">{{value}}</text>  
</div>
```

```
//comp.js
export default {
  data: {
    value: "组件创建"
  },
  onInit() {
    console.log("组件创建")
  },
  onAttached() {
    this.value = "组件挂载"
  },
  onDetached() {
    this.value = ""
  },
  onPageShow() {
    console.log("Page显示")
  },
  onPageHide() {
    console.log("Page隐藏")
  }
}
```

