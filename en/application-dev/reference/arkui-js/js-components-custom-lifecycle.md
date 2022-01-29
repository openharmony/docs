# Lifecycle Definition<a name="EN-US_TOPIC_0000001127125084"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

We provide a range of lifecycle callbacks for custom components, including  **onInit**,  **onAttached**,  **onDetached**,  **onLayoutReady**,  **onDestroy**,  **onPageShow**, and  **onPageHide**. You can use these callbacks to manage the internal logic of your custom components. The following describes the times when the lifecycle callbacks are invoked.

<a name="t7208da80646145cb86b25df20f52a5d4"></a>
<table><thead align="left"><tr id="r4bc39237158f4199b86d18d0784b005d"><th class="cellrowborder" valign="top" width="14.441444144414442%" id="mcps1.1.5.1.1"><p id="aa7d8254f7b0f495e8a38fc76d3508fc4"><a name="aa7d8254f7b0f495e8a38fc76d3508fc4"></a><a name="aa7d8254f7b0f495e8a38fc76d3508fc4"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="10.121012101210122%" id="mcps1.1.5.1.2"><p id="a037ba3feced74d36ae28ca2414da39a2"><a name="a037ba3feced74d36ae28ca2414da39a2"></a><a name="a037ba3feced74d36ae28ca2414da39a2"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.1.5.1.3"><p id="aac19d68c24f6444095fd09939256ea10"><a name="aac19d68c24f6444095fd09939256ea10"></a><a name="aac19d68c24f6444095fd09939256ea10"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="56.685668566856684%" id="mcps1.1.5.1.4"><p id="a80a1ef722e3f4008961e97ea3db877ef"><a name="a80a1ef722e3f4008961e97ea3db877ef"></a><a name="a80a1ef722e3f4008961e97ea3db877ef"></a>Called When</p>
</th>
</tr>
</thead>
<tbody><tr id="rb52da1ffb529417c9f0290d1f122a87e"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="acd1fd04acf1f4b789a178ecc66e8c27c"><a name="acd1fd04acf1f4b789a178ecc66e8c27c"></a><a name="acd1fd04acf1f4b789a178ecc66e8c27c"></a>onInit</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="a86ee0c2879d744c9a7c81908ddc5be08"><a name="a86ee0c2879d744c9a7c81908ddc5be08"></a><a name="a86ee0c2879d744c9a7c81908ddc5be08"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="a50617b80389e45b58dd015e4db4ac094"><a name="a50617b80389e45b58dd015e4db4ac094"></a><a name="a50617b80389e45b58dd015e4db4ac094"></a>Custom component initialization</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="p1395313418212"><a name="p1395313418212"></a><a name="p1395313418212"></a>Triggered once, when a custom component is created.</p>
</td>
</tr>
<tr id="r57dd28dbf8a243cdad002d8599eda15f"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="af6a0fe8473a54e71be833ea3c4135328"><a name="af6a0fe8473a54e71be833ea3c4135328"></a><a name="af6a0fe8473a54e71be833ea3c4135328"></a>onAttached</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="a5d96ae01ba73452e9aef97a5547c5df9"><a name="a5d96ae01ba73452e9aef97a5547c5df9"></a><a name="a5d96ae01ba73452e9aef97a5547c5df9"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="aa80d3cebd7f64e97ac348b8f034efc04"><a name="aa80d3cebd7f64e97ac348b8f034efc04"></a><a name="aa80d3cebd7f64e97ac348b8f034efc04"></a>Custom component loading</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="a2e00e7dee8164661b4244c4a34ae9b2c"><a name="a2e00e7dee8164661b4244c4a34ae9b2c"></a><a name="a2e00e7dee8164661b4244c4a34ae9b2c"></a>Triggered when a custom component is added to the <strong id="b22203210291"><a name="b22203210291"></a><a name="b22203210291"></a>&lt;Page&gt;</strong> component tree. When this callback is triggered, related data can be displayed during the lifecycle in scenarios such as image loading and animation playback.</p>
</td>
</tr>
<tr id="r1dd8a5bfd50043eeb2fff708e728a9fa"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="ae46609ef4ad2444fb4befc1ac552eb88"><a name="ae46609ef4ad2444fb4befc1ac552eb88"></a><a name="ae46609ef4ad2444fb4befc1ac552eb88"></a>onLayoutReady</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="a4b3c794964514f988757cd639964b7a8"><a name="a4b3c794964514f988757cd639964b7a8"></a><a name="a4b3c794964514f988757cd639964b7a8"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="a147a1ab39d2043f2a22c62b3483335b6"><a name="a147a1ab39d2043f2a22c62b3483335b6"></a><a name="a147a1ab39d2043f2a22c62b3483335b6"></a>Component layout completion</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="a23c4cbd18ad24bd8a496dbc487dd5400"><a name="a23c4cbd18ad24bd8a496dbc487dd5400"></a><a name="a23c4cbd18ad24bd8a496dbc487dd5400"></a>Triggered when layout calculation, including content size and position adjustment, is complete for a custom component.</p>
</td>
</tr>
<tr id="r4247056b80864bb7ab5678341dc8c29a"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="a973949fa33de41ca9a53c43e98b47f63"><a name="a973949fa33de41ca9a53c43e98b47f63"></a><a name="a973949fa33de41ca9a53c43e98b47f63"></a>onDetached</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="a245d96bb028641d492503489b54c4c2c"><a name="a245d96bb028641d492503489b54c4c2c"></a><a name="a245d96bb028641d492503489b54c4c2c"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="a169e08a844b2452d85acfaca01ea20ee"><a name="a169e08a844b2452d85acfaca01ea20ee"></a><a name="a169e08a844b2452d85acfaca01ea20ee"></a>Custom component removal</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="ae54d3a1f653c495ba8950e82c0fb3db4"><a name="ae54d3a1f653c495ba8950e82c0fb3db4"></a><a name="ae54d3a1f653c495ba8950e82c0fb3db4"></a>Triggered when a custom component is removed. It is usually used to stop animation or asynchronous logic execution.</p>
</td>
</tr>
<tr id="ra205abdcebf94a5583cdbd422211dd4b"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="aeb5a3893eb974dd88a762adc8077ed54"><a name="aeb5a3893eb974dd88a762adc8077ed54"></a><a name="aeb5a3893eb974dd88a762adc8077ed54"></a>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="a3b98923b60554564b67d28a3ac2bb562"><a name="a3b98923b60554564b67d28a3ac2bb562"></a><a name="a3b98923b60554564b67d28a3ac2bb562"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="a1f2cd15604434b1f8c1ad075db3ec76d"><a name="a1f2cd15604434b1f8c1ad075db3ec76d"></a><a name="a1f2cd15604434b1f8c1ad075db3ec76d"></a>Custom component destruction</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="aab6fb684fd454b41a6f701628f9c2307"><a name="aab6fb684fd454b41a6f701628f9c2307"></a><a name="aab6fb684fd454b41a6f701628f9c2307"></a>Triggered when a custom component is destroyed. It is usually used to release resources.</p>
</td>
</tr>
<tr id="row153141111450"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="p031461114513"><a name="p031461114513"></a><a name="p031461114513"></a>onPageShow</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="p1031441116514"><a name="p1031441116514"></a><a name="p1031441116514"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="p3315111550"><a name="p3315111550"></a><a name="p3315111550"></a>Page display of a custom component</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="p831518111558"><a name="p831518111558"></a><a name="p831518111558"></a>Triggered when the page where a custom component is located is displayed.</p>
</td>
</tr>
<tr id="row153471627274"><td class="cellrowborder" valign="top" width="14.441444144414442%" headers="mcps1.1.5.1.1 "><p id="p13481927174"><a name="p13481927174"></a><a name="p13481927174"></a>onPageHide</p>
</td>
<td class="cellrowborder" valign="top" width="10.121012101210122%" headers="mcps1.1.5.1.2 "><p id="p43489271277"><a name="p43489271277"></a><a name="p43489271277"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.1.5.1.3 "><p id="p434816271172"><a name="p434816271172"></a><a name="p434816271172"></a>Page hiding of a custom component</p>
</td>
<td class="cellrowborder" valign="top" width="56.685668566856684%" headers="mcps1.1.5.1.4 "><p id="p73481627873"><a name="p73481627873"></a><a name="p73481627873"></a>Triggered when the page where a custom component is located is hidden.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section14938111864313"></a>

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
    value: "Create a component."
  },
  onInit() {
    console.log("Component created.")
  },
  onAttached() {
    this.value = "Load the component."
  },
  onDetached() {
    this.value = ""
  },
  onPageShow() {
    console.log ("Page displayed.")
  },
  onPageHide() {
    console.log ("Page hidden.")
  }
}
```

