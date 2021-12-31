# option<a name="ZH-CN_TOPIC_0000001127125028"></a>

当作为<[select](js-components-basic-select.md)\>的子组件时用来展示下拉选择的具体项目。

当作为<[menu](js-components-basic-menu.md)\>的子组件时用来展示弹出菜单的具体项目。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：↵

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>选择项是否为下拉列表的默认项，仅在父组件是select时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>选择项的值，作为select、menu父组件的selected事件中的返回值。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>option选项的UI展示值需要放在标签内，如&lt;option value="10"&gt;十月&lt;/option&gt;</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>icon</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>图标资源路径，该图标展示在选项文本前，图标格式为jpg，png和svg。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section5775351116"></a>

支持如下样式。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.81188118811881%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.752475247524753%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.900990099009901%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="30.693069306930692%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p>选择项的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p>16px</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p>选择项的文本尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p>选择项的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p>选择项的字体粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p>选择项的文本修饰，见<a href="js-components-basic-text.md#section5775351116">text组件text-decoration的样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p>选择项的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1013173520328"></a>

不支持。

## 方法<a name="section45101363326"></a>

不支持。

## 示例<a name="section7566164416325"></a>

详见[menu示例](js-components-basic-menu.md#section54636714136)。

