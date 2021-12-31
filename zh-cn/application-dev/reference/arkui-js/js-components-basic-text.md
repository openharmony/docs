# text<a name="ZH-CN_TOPIC_0000001127125018"></a>

文本，用于呈现一段信息。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   文本的展示内容需要写在元素标签内。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持<[span](js-components-basic-span.md)\>。

## 属性<a name="section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md)。

## 样式<a name="section5775351116"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.548345165483454%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.898610138986104%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.428057194280573%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="5.959404059594041%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.16558344165583%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>#e5000000</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>30px</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果需要支持动态生效，请参看config描述文件中config-changes标签。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>letter-spacing</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>0px</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的字符间距。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>word-spacing<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt; | &lt;percentage&gt; | string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本之间的间距，string可选值为：</p>
<p>normal：默认的字间距。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的字体样式，可选值为：</p>
<ul><li>normal：标准的字体样式；</li><li>italic：斜体的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的字体粗细，number类型取值[100, 900]，默认为400，取值越大，字体越粗。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>number取值必须为100的整数倍。</p>
</div></div>
<p>string类型取值支持如下四个值：lighter、normal、bold、bolder。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的文本修饰，可选值为：</p>
<ul><li>underline：文字下划线修饰；</li><li>line-through：穿过文本的修饰线n</li><li>none：标准文本。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>text-decoration-color<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本修饰线的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>text-align</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的文本对齐方式，可选值为：</p>
<ul><li>left：文本左对齐；</li><li>center：文本居中对齐；</li><li>right：文本右对齐；</li><li>start：根据文字书写相同的方向对齐；</li><li>end：根据文字书写相反的方向对齐。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如文本宽度未指定大小，文本的宽度和父容器的宽度大小相等的情况下，对齐效果可能会不明显。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>line-height</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt; | &lt;percentage&gt;<sup><span>7+</span></sup> | string<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>0px<sup>1-6</sup></p>
<p>normal<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的文本行高，设置为0px时，不限制文本行高，自适应字体大小。string可选值为：</p>
<p>normal<sup><span>7+</span></sup>：默认的行高。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>text-overflow</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>clip</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p><span>在设置了最大行数的情况下生效，</span>可选值为：</p>
<ul><li>clip：将文本根据父容器大小进行裁剪显示；</li><li>ellipsis：根据父容器大小显示，显示不下的文本用省略号代替。需配合max-lines使用。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>max-lines</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>number | string<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本的最大行数，string类型可选值为：</p>
<ul><li>auto<sup>7+</sup>：文本行数自适应容器高度。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>min-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>文本最小字号，需要和文本最大字号同时设置，支持文本字号动态变化。设置最大最小字体样式后，font-size不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>max-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>文本最大字号，需要和文本最小字号同时设置，支持文本字号动态变化。设置最大最小字体样式后，font-size不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>font-size-step</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>1px</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>文本动态调整字号时的步长，需要设置最小，最大字号样式生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>prefer-font-sizes</p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;array&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>预设的字号集合，在动态尺寸调整时，优先使用预设字号集合中的字号匹配设置的最大行数，如果预设字号集合未设置，则使用最大最小和步长调整字号。针对仍然无法满足最大行数要求的情况，使用text-overflow设置项进行截断，设置预设尺寸集后，font-size、max-font-size、min-font-size和font-size-step不生效。</p>
<p>如：prefer-font-sizes: 12px,14px,16px</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>word-break<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置文本折行模式，可选值为：</p>
<ul><li>normal：默认换行规则，依据各自语言的规则，允许在字间发生换行。</li><li>break-all：对于非中文/日文/韩文的文本，可在任意字符间断行。</li><li>break-word：与break-all相同，不同的地方在于它要求一个没有断行破发点的词必须保持为一个整体单位。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>text-indent<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置首行缩进量。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>white-space<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>pre</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>设置处理元素中空白的模式，可选值为：</p>
<ul><li>normal：所有空格、回车、制表符都合并成一个空格，文本自动换行；</li><li>nowrap：所有空格、回车、制表符都合并成一个空格，文本不换行；</li><li>pre：所有东西原样输出；</li><li>pre-wrap：所有东西原样输出，文本换行；</li><li>pre-line：所有空格、制表符合并成一个空格，回车不变，文本换行。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.548345165483454%" headers="mcps1.1.6.1.1 "><p>adapt-height<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.898610138986104%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.428057194280573%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="5.959404059594041%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.16558344165583%" headers="mcps1.1.6.1.5 "><p>文本大小是否自适应容器高度。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>设置字体大小自适应相关样式后生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   字体动态缩放：预设尺寸集合和最小最大字号调节基于是否满足最大行数要求，预设尺寸集合会按照从左到右顺序查看是否满足最大行数要求，最小最大字号调节则基于从大到小顺序查看是否满足最大行数要求。
>-   文本换行：文本可以通过转义字符\\r\\n进行换行。
>-   文本标签内支持以下转义字符：\\a，\\b，\\f，\\n，\\r，\\t，\\v，\\'，\\"，\\0。
>-   当使用子组件span组成文本段落时，如果span属性样式异常，将导致text段落无法显示。
>-   letter-spacing、text-align、line-height、text-overflow和max-lines样式作用于text及其子组件（span）组成的文本内容。
>-   text组件说明：不支持text内同时存在文本内容和span子组件。（如果同时存在，只显示span内的内容\)

## 事件<a name="section1948820711216"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section13294026042"></a>

```
<!-- xxx.hml -->
<div class="container">
  <div class="content">
    <text class="title">
      Hello {{ title }}
    </text>
  </div>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.content{
  width: 400px;
  height: 400px;
  border: 20px;
  border-image-source: url("/common/images/landscape.jpg");
  border-image-slice: 20px;
  border-image-width: 30px;
  border-image-outset: 10px;
  border-image-repeat: round;
}
.title {
  font-size: 80px;
  text-align: center;
  width: 400px;
  height: 400px;
}
```

```
// xxx.js
export default {
  data: {
    title: 'World'
  }
}
```

![](figures/3.png)

```
<!-- xxx.hml -->
<div class="container">
  <text class="text1">
    This is a passage
  </text>
  <text class="text2">
    This is a passage
  </text>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  background-color: #F1F3F5;
  justify-content: center;
}
.text1{
  word-spacing: 10px;
  adapt-height: true;
}
.text2{
  width: 200px;
  max-lines: 1;
  text-overflow: ellipsis;
  text-valign: middle;
  line-height: 40px;
  text-decoration: underline;
  text-decoration-color: red;
  text-indent: 20px;
  white-space: pre;
}
```

![](figures/2.png)

