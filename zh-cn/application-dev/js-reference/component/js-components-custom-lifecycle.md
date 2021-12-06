# 生命周期定义<a name="ZH-CN_TOPIC_0000001209570719"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

我们为自定义组件提供了一系列生命周期回调方法，便于开发者管理自定义组件的内部逻辑。生命周期主要包括：onInit，onAttached，onDetached，onLayoutReady，onDestroy，onPageShow和onPageHide。下面我们依次介绍一下各个生命周期回调的时机。

<a name="zh-cn_topic_0000001127125084_t7208da80646145cb86b25df20f52a5d4"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125084_r4bc39237158f4199b86d18d0784b005d"><th class="cellrowborder" valign="top" width="14.441444144414442%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125084_aa7d8254f7b0f495e8a38fc76d3508fc4"><a name="zh-cn_topic_0000001127125084_aa7d8254f7b0f495e8a38fc76d3508fc4"></a><a name="zh-cn_topic_0000001127125084_aa7d8254f7b0f495e8a38fc76d3508fc4"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="10.121012101210122%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125084_a037ba3feced74d36ae28ca2414da39a2"><a name="zh-cn_topic_0000001127125084_a037ba3feced74d36ae28ca2414da39a2"></a><a name="zh-cn_topic_0000001127125084_a037ba3feced74d36ae28ca2414da39a2"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125084_aac19d68c24f6444095fd09939256ea10"><a name="zh-cn_topic_0000001127125084_aac19d68c24f6444095fd09939256ea10"></a><a name="zh-cn_topic_0000001127125084_aac19d68c24f6444095fd09939256ea10"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="56.685668566856684%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125084_a80a1ef722e3f4008961e97ea3db877ef"><a name="zh-cn_topic_0000001127125084_a80a1ef722e3f4008961e97ea3db877ef"></a><a name="zh-cn_topic_0000001127125084_a80a1ef722e3f4008961e97ea3db877ef"></a>触发时机</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125084_rb52da1ffb529417c9f0290d1f122a87e"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_acd1fd04acf1f4b789a178ecc66e8c27c"><a name="zh-cn_topic_0000001127125084_acd1fd04acf1f4b789a178ecc66e8c27c"></a><a name="zh-cn_topic_0000001127125084_acd1fd04acf1f4b789a178ecc66e8c27c"></a>onInit</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_a86ee0c2879d744c9a7c81908ddc5be08"><a name="zh-cn_topic_0000001127125084_a86ee0c2879d744c9a7c81908ddc5be08"></a><a name="zh-cn_topic_0000001127125084_a86ee0c2879d744c9a7c81908ddc5be08"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_a50617b80389e45b58dd015e4db4ac094"><a name="zh-cn_topic_0000001127125084_a50617b80389e45b58dd015e4db4ac094"></a><a name="zh-cn_topic_0000001127125084_a50617b80389e45b58dd015e4db4ac094"></a>初始化自定义组件</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_p1395313418212"><a name="zh-cn_topic_0000001127125084_p1395313418212"></a><a name="zh-cn_topic_0000001127125084_p1395313418212"></a>自定义组件初始化生命周期回调，当自定义组件创建时，触发该回调，主要用于自定义组件中必须使用的数据初始化，该回调只会触发一次调用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125084_r57dd28dbf8a243cdad002d8599eda15f"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_af6a0fe8473a54e71be833ea3c4135328"><a name="zh-cn_topic_0000001127125084_af6a0fe8473a54e71be833ea3c4135328"></a><a name="zh-cn_topic_0000001127125084_af6a0fe8473a54e71be833ea3c4135328"></a>onAttached</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_a5d96ae01ba73452e9aef97a5547c5df9"><a name="zh-cn_topic_0000001127125084_a5d96ae01ba73452e9aef97a5547c5df9"></a><a name="zh-cn_topic_0000001127125084_a5d96ae01ba73452e9aef97a5547c5df9"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_aa80d3cebd7f64e97ac348b8f034efc04"><a name="zh-cn_topic_0000001127125084_aa80d3cebd7f64e97ac348b8f034efc04"></a><a name="zh-cn_topic_0000001127125084_aa80d3cebd7f64e97ac348b8f034efc04"></a>自定义组件装载</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_a2e00e7dee8164661b4244c4a34ae9b2c"><a name="zh-cn_topic_0000001127125084_a2e00e7dee8164661b4244c4a34ae9b2c"></a><a name="zh-cn_topic_0000001127125084_a2e00e7dee8164661b4244c4a34ae9b2c"></a>自定义组件被创建后，加入到Page组件树时，触发该回调，该回调触发时，表示组件将被进行显示，该声明周期可用于初始化显示相关数据，通常用于加载图片资源、开始执行动画等场景。。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125084_r1dd8a5bfd50043eeb2fff708e728a9fa"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_ae46609ef4ad2444fb4befc1ac552eb88"><a name="zh-cn_topic_0000001127125084_ae46609ef4ad2444fb4befc1ac552eb88"></a><a name="zh-cn_topic_0000001127125084_ae46609ef4ad2444fb4befc1ac552eb88"></a>onLayoutReady</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_a4b3c794964514f988757cd639964b7a8"><a name="zh-cn_topic_0000001127125084_a4b3c794964514f988757cd639964b7a8"></a><a name="zh-cn_topic_0000001127125084_a4b3c794964514f988757cd639964b7a8"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_a147a1ab39d2043f2a22c62b3483335b6"><a name="zh-cn_topic_0000001127125084_a147a1ab39d2043f2a22c62b3483335b6"></a><a name="zh-cn_topic_0000001127125084_a147a1ab39d2043f2a22c62b3483335b6"></a>自定义组件布局完成</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_a23c4cbd18ad24bd8a496dbc487dd5400"><a name="zh-cn_topic_0000001127125084_a23c4cbd18ad24bd8a496dbc487dd5400"></a><a name="zh-cn_topic_0000001127125084_a23c4cbd18ad24bd8a496dbc487dd5400"></a>自定义组件插入Page组件树后，将会对自定义组件进行布局计算，调整其内容元素尺寸与位置，当布局计算结束后触发该回调。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125084_r4247056b80864bb7ab5678341dc8c29a"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_a973949fa33de41ca9a53c43e98b47f63"><a name="zh-cn_topic_0000001127125084_a973949fa33de41ca9a53c43e98b47f63"></a><a name="zh-cn_topic_0000001127125084_a973949fa33de41ca9a53c43e98b47f63"></a>onDetached</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_a245d96bb028641d492503489b54c4c2c"><a name="zh-cn_topic_0000001127125084_a245d96bb028641d492503489b54c4c2c"></a><a name="zh-cn_topic_0000001127125084_a245d96bb028641d492503489b54c4c2c"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_a169e08a844b2452d85acfaca01ea20ee"><a name="zh-cn_topic_0000001127125084_a169e08a844b2452d85acfaca01ea20ee"></a><a name="zh-cn_topic_0000001127125084_a169e08a844b2452d85acfaca01ea20ee"></a>自定义组件摘除</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_ae54d3a1f653c495ba8950e82c0fb3db4"><a name="zh-cn_topic_0000001127125084_ae54d3a1f653c495ba8950e82c0fb3db4"></a><a name="zh-cn_topic_0000001127125084_ae54d3a1f653c495ba8950e82c0fb3db4"></a>自定义组件摘除时，触发该回调，常用于停止动画或异步逻辑停止执行的场景。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125084_ra205abdcebf94a5583cdbd422211dd4b"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_aeb5a3893eb974dd88a762adc8077ed54"><a name="zh-cn_topic_0000001127125084_aeb5a3893eb974dd88a762adc8077ed54"></a><a name="zh-cn_topic_0000001127125084_aeb5a3893eb974dd88a762adc8077ed54"></a>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_a3b98923b60554564b67d28a3ac2bb562"><a name="zh-cn_topic_0000001127125084_a3b98923b60554564b67d28a3ac2bb562"></a><a name="zh-cn_topic_0000001127125084_a3b98923b60554564b67d28a3ac2bb562"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_a1f2cd15604434b1f8c1ad075db3ec76d"><a name="zh-cn_topic_0000001127125084_a1f2cd15604434b1f8c1ad075db3ec76d"></a><a name="zh-cn_topic_0000001127125084_a1f2cd15604434b1f8c1ad075db3ec76d"></a>自定义组件销毁</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_aab6fb684fd454b41a6f701628f9c2307"><a name="zh-cn_topic_0000001127125084_aab6fb684fd454b41a6f701628f9c2307"></a><a name="zh-cn_topic_0000001127125084_aab6fb684fd454b41a6f701628f9c2307"></a>自定义组件销毁时，触发该回调，常用于资源释放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125084_row153141111450"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_p031461114513"><a name="zh-cn_topic_0000001127125084_p031461114513"></a><a name="zh-cn_topic_0000001127125084_p031461114513"></a>onPageShow</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_p1031441116514"><a name="zh-cn_topic_0000001127125084_p1031441116514"></a><a name="zh-cn_topic_0000001127125084_p1031441116514"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_p3315111550"><a name="zh-cn_topic_0000001127125084_p3315111550"></a><a name="zh-cn_topic_0000001127125084_p3315111550"></a>自定义组件Page显示</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_p831518111558"><a name="zh-cn_topic_0000001127125084_p831518111558"></a><a name="zh-cn_topic_0000001127125084_p831518111558"></a>自定义组件所在Page显示后，触发该回调。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125084_row153471627274"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125084_p13481927174"><a name="zh-cn_topic_0000001127125084_p13481927174"></a><a name="zh-cn_topic_0000001127125084_p13481927174"></a>onPageHide</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125084_p43489271277"><a name="zh-cn_topic_0000001127125084_p43489271277"></a><a name="zh-cn_topic_0000001127125084_p43489271277"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125084_p434816271172"><a name="zh-cn_topic_0000001127125084_p434816271172"></a><a name="zh-cn_topic_0000001127125084_p434816271172"></a>自定义组件Page隐藏</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125084_p73481627873"><a name="zh-cn_topic_0000001127125084_p73481627873"></a><a name="zh-cn_topic_0000001127125084_p73481627873"></a>自定义组件所在Page隐藏后，触发该回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001127125084_section14938111864313"></a>

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

