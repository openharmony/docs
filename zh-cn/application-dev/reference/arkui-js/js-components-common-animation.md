# 动画样式<a name="ZH-CN_TOPIC_0000001173164765"></a>

组件支持动态的旋转、平移、缩放效果，可在style或css中设置。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="26.02%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.529999999999998%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.900000000000002%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="41.55%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>transform-origin</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string<sup>6+</sup> | &lt;percentage&gt; | &lt;length&gt; string<sup>6+</sup> | &lt;percentage&gt; | &lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>center center</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>变换对象的原点位置，支持px和百分比(相对于动画目标组件)，如果仅设置一个值，另一个值为50%，第一个string的可选值为：left | center | right ，第二个string的可选值为：top | center | bottom。</p>
<p>示例：</p>
<p>transform-origin: 200px 30%。</p>
<p>transform-origin: 100px top。</p>
<p>transform-origin: center center。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>transform</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>支持同时设置平移/旋转/缩放的属性。</p>
<p>详见<a href="#table28802443315">表1</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>0s ease 0s 1 normal none running none</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>格式：duration | timing-function | delay | iteration-count | direction | fill-mode | play-state | name，每个字段不区分先后，但是 duration / delay 按照出现的先后顺序解析。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-name</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>指定@keyframes，详见<a href="#t48a722bba37a44c883ed4e046a4cf82e">表2</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-delay</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>定义动画播放的延迟时间。支持的单位为[s(秒)|ms(毫秒) ]，默认单位为ms，格式为：1000ms或1s。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-duration</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>定义一个动画周期。支持的单位为[s(秒)|ms(毫秒) ]，默认单位为ms，格式为：1000ms或1s。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>animation-duration 样式必须设置，否则时长为 0，则不会播放动画。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-iteration-count</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>number  | infinite</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>定义动画播放的次数，默认播放一次，可通过设置为infinite无限次播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>ease</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>描述动画执行的速度曲线，用于使动画更为平滑。</p>
<p>可选项有：</p>
<ul><li>linear：表示动画从头到尾的速度都是相同的。</li><li>ease：表示动画以低速开始，然后加快，在结束前变慢，cubic-bezier(0.25, 0.1, 0.25, 1.0)。</li><li>ease-in：表示动画以低速开始，cubic-bezier(0.42, 0.0, 1.0, 1.0)。</li><li>ease-out：表示动画以低速结束，cubic-bezier(0.0, 0.0, 0.58, 1.0)。</li><li>ease-in-out：表示动画以低速开始和结束，cubic-bezier(0.42, 0.0, 0.58, 1.0)。</li><li>friction：阻尼曲线，cubic-bezier(0.2, 0.0, 0.2, 1.0)。</li><li>extreme-deceleration：急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。</li><li>sharp：锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。</li><li>rhythm：节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。</li><li>smooth：平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。</li><li>cubic-bezier：在三次贝塞尔函数中定义动画变化过程，入参的x和y值必须处于0-1之间。</li><li>steps: 阶梯曲线<sup><span>6+</span></sup>。语法：steps(number[, end|start])；number必须设置，支持的类型为正整数。第二个参数可选，表示在每个间隔的起点或是终点发生阶跃变化，支持设置end或start，默认值为end。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-direction<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>指定动画的播放模式：</p>
<ul><li>normal： 动画正向循环播放。</li><li>reverse： 动画反向循环播放。</li><li>alternate：动画交替循环播放，奇数次正向播放，偶数次反向播放。</li><li>alternate-reverse：动画反向交替循环播放，奇数次反向播放，偶数次正向播放。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-fill-mode</p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>指定动画开始和结束的状态：</p>
<ul><li>none：在动画执行之前和之后都不会应用任何样式到目标上。</li><li>forwards：在动画结束后，目标将保留动画结束时的状态（在最后一个关键帧中定义）。</li><li>backwards<sup><span>6+</span></sup>：动画将在animation-delay期间应用第一个关键帧中定义的值。当animation-direction为"normal"或"alternate"时应用from关键帧中的值，当animation-direction为"reverse"或"alternate-reverse"时应用to关键帧中的值。</li><li>both<sup><span>6+</span></sup>：动画将遵循forwards和backwards的规则，从而在两个方向上扩展动画属性。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>animation-play-state<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>running</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>指定动画的当前状态：</p>
<ul><li>paused：动画状态为暂停。</li><li>running：动画状态为播放。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.5.1.1 "><p>transition<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.529999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.900000000000002%" headers="mcps1.1.5.1.3 "><p>all 0 ease 0</p>
</td>
<td class="cellrowborder" valign="top" width="41.55%" headers="mcps1.1.5.1.4 "><p>指定组件状态切换时的过渡效果，可以通过transition属性设置如下四个属性：</p>
<ul><li>transition-property：规定设置过渡效果的 CSS 属性的名称，目前支持宽、高、背景色。</li><li>transition-duration：规定完成过渡效果需要的时间，单位秒。</li><li>transition-timing-function：规定过渡效果的时间曲线，支持样式动画提供的曲线。</li><li>transition-delay：规定过渡效果延时启动时间，单位秒。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 1**  transform操作说明

<a name="table28802443315"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.04%" id="mcps1.2.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.71%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="54.25%" id="mcps1.2.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>none<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>不进行任何转换。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>matrix<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>入参为六个值的矩阵，6个值分别代表：scaleX, skewY, skewX, scaleY, translateX, translateY。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>matrix3d<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>入参为十六个值的4X4矩阵。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>translate</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;length&gt;<span>| &lt;percent&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>平移动画属性，支持设置x轴和y轴两个维度的平移参数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>translate3d<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;length&gt;| &lt;percent&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>三个入参，分别代表X轴、Y轴、Z轴的平移距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>translateX</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;length&gt;<span>| &lt;percent&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>X轴方向平移动画属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>translateY</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;length&gt;<span>| &lt;percent&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Y轴方向平移动画属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>translateZ<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;length&gt;| &lt;percent&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Z轴的平移距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>scale</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>缩放动画属性，支持设置x轴和y轴两个维度的缩放参数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>scale3d<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>三个入参，分别代表X轴、Y轴、Z轴的缩放参数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>scaleX</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>X轴方向缩放动画属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>scaleY</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Y轴方向缩放动画属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>scaleZ<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Z轴的缩放参数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt;<sup>6+</sup> | &lt;turn&gt;<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>旋转动画属性<span>，支持设置x轴和y轴两个维度的选中参数。</span></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>rotate3d<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>四个入参，前三个分别为X轴、Y轴、Z轴的旋转向量，第四个是旋转角度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>rotateX</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt;<sup>6+</sup> | &lt;turn&gt;<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>X轴方向旋转动画属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>rotateY</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt;<sup>6+</sup> | &lt;turn&gt;<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Y轴方向旋转动画属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>rotateZ<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Z轴方向的旋转角度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>skew<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>两个入参，分别为X轴和Y轴的2D倾斜角度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>skewX<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>X轴的2D倾斜角度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>skewY<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>Y轴的2D倾斜角度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p>perspective<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p>3D透视场景下镜头距离元素表面的距离。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  @keyframes属性说明

<a name="t48a722bba37a44c883ed4e046a4cf82e"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.242424242424242%" id="mcps1.2.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.581758175817583%" id="mcps1.2.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.71117111711171%" id="mcps1.2.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="46.464646464646464%" id="mcps1.2.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="17.581758175817583%" headers="mcps1.2.5.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.71117111711171%" headers="mcps1.2.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p>动画执行后应用到组件上的背景颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="17.581758175817583%" headers="mcps1.2.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.71117111711171%" headers="mcps1.2.5.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p>动画执行后应用到组件上的不透明度值，为介于0到1间的数值，默认为1。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="17.581758175817583%" headers="mcps1.2.5.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.71117111711171%" headers="mcps1.2.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p>动画执行后应用到组件上的宽度值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="17.581758175817583%" headers="mcps1.2.5.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.71117111711171%" headers="mcps1.2.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p>动画执行后应用到组件上的高度值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p>transform</p>
</td>
<td class="cellrowborder" valign="top" width="17.581758175817583%" headers="mcps1.2.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.71117111711171%" headers="mcps1.2.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p>定义应用在组件上的变换类型，见<a href="#table28802443315">表1</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p>background-position<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.581758175817583%" headers="mcps1.2.5.1.2 "><p>string | &lt;percentage&gt; | &lt;length&gt; string | &lt;percentage&gt; | &lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.71117111711171%" headers="mcps1.2.5.1.3 "><p>50% 50%</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p>背景图位置。单位支持百分比和px，第一个值是水平位置，第二个值是垂直位置。如果仅设置一个值，另一个值为50%。第一个string的可选值为：left | center | right ，第二个string的可选值为：top | center | bottom。</p>
<p>示例：</p>
<ul><li>background-position: 200px 30%</li><li>background-position: 100px top</li><li>background-position: center center</li></ul>
</td>
</tr>
</tbody>
</table>

对于不支持起始值或终止值缺省的情况，可以通过from和to显示指定起始和结束。可以通过百分比指定动画运行的中间状态<sup>6+</sup>。示例：

```
<div class="container">
  <div class="rect">
  </div>
</div>
```

```
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.rect{
  width: 200px;
  height: 200px;
  background-color: #f76160;
  animation: Go 3s infinite;
}
@keyframes Go
{
  from {
    background-color: #f76160;
    transform:translate(100px) rotate(0deg) scale(1.0);
  }
  /* 可以通过百分比指定动画运行的中间状态6+ */
  50% {
    background-color: #f76160;
    transform:translate(100px) rotate(60deg) scale(1.3);
  }
  to {
    background-color: #09ba07;
    transform:translate(100px) rotate(180deg) scale(2.0);
  }
}
```

![](figures/zh-cn_image_0000001173324797.gif)

```
<!-- xxx.hml -->
<div class="container">
  <div class="simpleAnimation simpleSize" style="animation-play-state: {{playState}}"></div>
  <text onclick="toggleState">animation-play-state: {{playState}}</text>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.simpleSize {
  background-color: blue;
  width: 100px;
  height: 100px;
}
.simpleAnimation {
  animation: simpleFrames 9s;
}
@keyframes simpleFrames {
  from { transform: translateX(0px); }
  to { transform: translateX(100px); }
}
```

```
// xxx.js
export default {
  data: {
    title: "",
    playState: "running"
  },
  toggleState() {
    if (this.playState ===  "running") {
      this.playState = "paused";
    } else {
      this.playState = "running";
    }
  }
}
```

![](figures/zh-cn_image_0000001127285034.gif)

```
<!-- xxx.hml -->
<div id='img' class="img"></div>
```

```
/* xxx.css */
.img {
  width: 294px;
  height: 233px;
  background-image: url('common/heartBeat.jpg');
  background-repeat: no-repeat;
  background-position: 0% 0%;
  background-size: 900%;
  animation-name: heartBeating;
  animation-duration: 1s;
  animation-delay: 0s;
  animation-fill-mode: forwards;
  animation-iteration-count: -1;
  animation-timing-function: steps(8, end);
}

@keyframes heartBeating {
  from { background-position: 0% 0%;}
  to { background-position: 100% 0%;}
}
```

```
<!-- xxx.hml -->
<div class="container">
  <div class="content"></div>
</div>
```

```
/* xxx.css */
.container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}
.content { /* 组件状态1 */
    height: 200px;
    width: 200px;
    background-color: red;
    transition: all 5s ease 0s;
}
.content:active { /* 组件状态2 */
    height: 400px;
    width: 400px;
    background-color: blue;
    transition: all 5s linear 0s;
}
```

![](figures/zh-cn_image_0000001152833768.gif)

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>@keyframes的from/to不支持动态绑定。
>steps函数的end和start含义如下图所示。
>![](figures/zh-cn_image_0000001127125220.png)

