# select<a name="ZH-CN_TOPIC_0000001173164719"></a>

下拉选择按钮，可让用户在多个选项之间选择。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持<[option](js-components-basic-option.md)\>。

## 属性<a name="section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md)。

## 样式<a name="section648514244510"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table2017217206553"></a>
<table><thead align="left"><tr id="row17172152010556"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p1117215208557"><a name="p1117215208557"></a><a name="p1117215208557"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p11172120175513"><a name="p11172120175513"></a><a name="p11172120175513"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p21721420155517"><a name="p21721420155517"></a><a name="p21721420155517"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p917211203552"><a name="p917211203552"></a><a name="p917211203552"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p101721020175516"><a name="p101721020175516"></a><a name="p101721020175516"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1917292016550"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p9172162095516"><a name="p9172162095516"></a><a name="p9172162095516"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p181721120165512"><a name="p181721120165512"></a><a name="p181721120165512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1117282018556"><a name="p1117282018556"></a><a name="p1117282018556"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p517218202558"><a name="p517218202558"></a><a name="p517218202558"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p17172120195510"><a name="p17172120195510"></a><a name="p17172120195510"></a>字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section3892191911214"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row166321742154511"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p169871843194513"><a name="p169871843194513"></a><a name="p169871843194513"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19988164384513"><a name="p19988164384513"></a><a name="p19988164384513"></a>{newValue: newValue}</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p298824384514"><a name="p298824384514"></a><a name="p298824384514"></a>下拉选择新值后触发该事件，newValue的值为子组件option的value属性值。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   select组件不支持click事件。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section18261242145416"></a>

```
<!-- xxx.hml -->
<div class="container">
  <select @change="changeFruit">
    <option value="bananaValue">
      Banana
    </option>
    <option value="appleValue" selected="true">
      Apple
    </option>
    <option value="pearValue">
      Pear
    </option>
  </select>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
```

![](figures/zh-cn_image_0000001152588538.png)

