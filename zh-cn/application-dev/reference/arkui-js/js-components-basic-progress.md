# progress<a name="ZH-CN_TOPIC_0000001173324665"></a>

进度条，用于显示内容加载或操作处理进度。

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>horizontal</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置进度条的类型，该属性不支持动态修改，可选值为：</p>
<ul><li>horizontal：线性进度条；</li><li>circular：loading样式进度条；</li><li>ring：圆环形进度条；</li><li>scale-ring：带刻度圆环形进度条</li><li>arc：弧形进度条。</li><li>eclipse<sup>5+</sup>：圆形进度条，展现类似月圆月缺的进度展示效果。</li></ul>
</td>
</tr>
</tbody>
</table>

不同类型的进度条还支持不同的属性：

-   类型为horizontal、ring、scale-ring时，支持如下属性：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p>percent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p>当前进度。取值范围为0-100。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p>secondarypercent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p>次级进度。取值范围为0-100。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   类型为ring、scale-ring时，支持如下属性：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="23%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.6.1.1 "><p>clockwise</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p>圆环形进度条是否采用顺时针。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   类型为arc、eclipse<sup>5+</sup>时，支持如下属性：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p>percent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p>当前进度。取值范围为0-100。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 样式<a name="section5775351116"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

type=horizontal

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.941194119411943%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="26.672667266726673%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>设置进度条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p>4px</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>设置进度条的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>设置进度条的背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>secondary-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>设置次级进度条的颜色。</p>
</td>
</tr>
</tbody>
</table>

type=circular

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.881188118811883%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="26.732673267326728%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="11.881188118811883%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.732673267326728%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>loading进度条上的圆点颜色。</p>
</td>
</tr>
</tbody>
</table>

type=ring, scale-ring

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.152415241524153%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.461446144614461%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt; | &lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>环形进度条的颜色，ring类型支持线性渐变色设置。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>线性渐变色仅支持两个颜色参数设置格式，如color = linear-gradient(#ff0000, #00ff00)。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>环形进度条的背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>secondary-color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>环形次级进度条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p>10px</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>环形进度条的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>scale-width</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>带刻度的环形进度条的刻度粗细，类型为scale-ring生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p>scale-number</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p>120</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p>带刻度的环形进度条的刻度数量，类型为scale-ring生效。</p>
</td>
</tr>
</tbody>
</table>

type=arc

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.851385138513853%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.004200420042004%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>-</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>-</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条的背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>4px</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条的宽度。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>进度条宽度越大，进度条越靠近圆心，进度条始终在半径区域内。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>240</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条起始角度，以时钟0点为基线，取值范围为0到360（顺时针）。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>240</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条总长度，范围为-360到360，负数标识起点到终点为逆时针。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>弧形进度条宽度的一半</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条中心位置，（坐标原点为组件左上角顶点）。该样式需要和center-y和radius一起使用。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>弧形进度条高度的一半</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条中心位置，（坐标原点为组件左上角顶点）。该样式需要和center-x和radius一起使用。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>radius</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>弧形进度条宽高最小值的一半</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条半径，该样式需要和center-x和center-y一起使用。</p>
</td>
</tr>
</tbody>
</table>

type=eclipse<sup>5+</sup>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.851385138513853%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.004200420042004%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>圆形进度条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p>弧形进度条的背景色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section16580153964314"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section493033510346"></a>

```
<!--xxx.hml -->
<div class="container">
  <progress class="min-progress" type="scale-ring"  percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="horizontal" percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="arc" percent= "10"></progress>
  <progress class="min-progress" type="ring" percent= "10" secondarypercent="50"></progress>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  height: 100%;
  width: 100%;
  align-items: center;
}
.min-progress {
  width: 300px;
  height: 300px;
}
```

![](figures/progress.png)

