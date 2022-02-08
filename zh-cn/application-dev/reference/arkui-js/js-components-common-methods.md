# 通用方法<a name="ZH-CN_TOPIC_0000001127284884"></a>

当组件通过id属性标识后，可以使用该id获取组件对象并调用相关组件方法。

## animate<a name="section16276192233016"></a>

animate\( keyframes: Keyframes, options: Options\)：void

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.18%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.119999999999997%" id="mcps1.1.5.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="19.18%" headers="mcps1.1.5.1.1 "><p>keyframes</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.5.1.2 "><p><a href="#table13611943164319">keyframes</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>设置动画样式</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="19.18%" headers="mcps1.1.5.1.1 "><p>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.5.1.2 "><p><a href="js-components-common-methods.md#table1519818133494">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>用于设置动画属性的对象列表。options请见<a href="#table703167514">Options说明</a></p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  keyframes

    <a name="table13611943164319"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="30.503050305030506%" id="mcps1.2.4.1.1"><p>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.642664266426646%" id="mcps1.2.4.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.85428542854285%" id="mcps1.2.4.1.3"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="30.503050305030506%" headers="mcps1.2.4.1.1 "><p>frames</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.642664266426646%" headers="mcps1.2.4.1.2 "><p>Array&lt;Style&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.85428542854285%" headers="mcps1.2.4.1.3 "><p>用于设置动画样式的对象列表。Style类型说明请见<a href="#table15168543143">Style类型说明</a></p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 2**  Style类型说明

    <a name="table15168543143"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="22.91%" id="mcps1.2.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.2.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.52%" id="mcps1.2.5.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.9%" id="mcps1.2.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>动画执行过程中设置到组件上的宽度值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>动画执行过程中设置到组件上的高度值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>backgroundColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>&lt;color&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>none</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>动画执行过程中设置到组件上的背景颜色。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>opacity</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>设置到组件上的透明度（介于0到1之间）。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>backgroundPosition</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>格式为"x y"，单位为百分号或者px。</p>
    <p>第一个值是水平位置，第二个值是垂直位置。</p>
    <p>如果仅规定了一个值，另一个值为 50%。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>transformOrigin</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>'center center'</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>变换对象的中心点。</p>
    <p>第一个参数表示x轴的值，可以设置为left、center、right、长度值或百分比值。</p>
    <p>第二个参数表示y轴的值，可以设置为top、center、bottom、长度值或百分比值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>transform</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p><a href="js-components-common-animation.md#table28802443315">Transform</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p>设置到变换对象上的类型。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><ul><li>offset值（如果提供）必须在0.0到1.0（含）之间，并以升序排列。</li><li>若只有两帧，可以不填offset。</li><li>若超过两帧，offset必填。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

    **表 3**  Options说明

    <a name="table703167514"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.89%" id="mcps1.2.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.560000000000002%" id="mcps1.2.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.22%" id="mcps1.2.5.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.33%" id="mcps1.2.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p>指定当前动画的运行时长（单位毫秒）。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p>easing</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p>linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p>描述动画的时间曲线，支持类型见<a href="#table12317161054">easing有效值说明</a>。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p>设置动画执行的延迟时间（默认值表示无延迟）。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p>iterations</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p>设置动画执行的次数。number表示固定次数，Infinity枚举表示无限次数播放。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p>direction<sup>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p>normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p>指定动画的播放模式：</p>
    <p>normal： 动画正向循环播放；</p>
    <p>reverse： 动画反向循环播放；</p>
    <p>alternate：动画交替循环播放，奇数次正向播放，偶数次反向播放；</p>
    <p>alternate-reverse：动画反向交替循环播放，奇数次反向播放，偶数次正向播放。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p>fill</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p>none</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p>指定动画开始和结束的状态：</p>
    <p>none：在动画执行之前和之后都不会应用任何样式到目标上。</p>
    <p>forwards：在动画结束后，目标将保留动画结束时的状态（在最后一个关键帧中定义）。</p>
    <p>backwards<sup>6+</sup>：动画将在animation-delay期间应用第一个关键帧中定义的值。当animation-direction为"normal"或"alternate"时应用from关键帧中的值，当animation-direction为"reverse"或"alternate-reverse"时应用to关键帧中的值。</p>
    <p>both<sup>6+</sup>：动画将遵循forwards和backwards的规则，从而在两个方向上扩展动画属性。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 4**  easing有效值说明

    <a name="table12317161054"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="37.940000000000005%" id="mcps1.2.3.1.1"><p>值</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.06%" id="mcps1.2.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>动画线性变化。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>ease-in</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>动画速度先慢后快，cubic-bezier(0.42, 0.0, 1.0, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>ease-out</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>动画速度先快后慢，cubic-bezier(0.0, 0.0, 0.58, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>ease-in-out</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>动画先加速后减速，cubic-bezier(0.42, 0.0, 0.58, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>friction</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>阻尼曲线，cubic-bezier(0.2, 0.0, 0.2, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>extreme-deceleration</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>sharp</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>rhythm</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>smooth</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>cubic-bezier(x1, y1, x2, y2)</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>在三次贝塞尔函数中定义动画变化过程，入参的x和y值必须处于0-1之间。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p>steps(number, step-position)<sup>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p>Step曲线。</p>
    <p>number必须设置，支持的类型为int。</p>
    <p>step-position参数可选，支持设置start或end，默认值为end。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    animation对象属性：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.48%" id="mcps1.1.4.1.1"><p>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.46%" id="mcps1.1.4.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.06%" id="mcps1.1.4.1.3"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p>finished</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p>只读，用于表示当前动画是否已播放完成。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p>pending</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p>只读，用于表示当前动画是否处于等待其他异步操作完成的等待状态（例如启动一个延时播放的动画）。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p>playState</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p>可读可写，动画的执行状态：</p>
    <ul><li>idle：未执行状态，包括已结束或未开始。</li><li>running：动画正在运行。</li><li>paused：动画暂停。</li><li>finished：动画播放完成。</li></ul>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p>startTime</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p>可读可写，动画播放开始的预定时间，用途类似于options参数中的delay。</p>
    </td>
    </tr>
    </tbody>
    </table>

    animation对象方法：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="30.86%" id="mcps1.1.4.1.1"><p>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.58%" id="mcps1.1.4.1.2"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.56%" id="mcps1.1.4.1.3"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p>play</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p>组件播放动画。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p>组件完成动画。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p>pause</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p>组件暂停动画。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p>组件取消动画。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p>reverse</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p>组件倒播动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

    animation对象事件：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.79%" id="mcps1.1.3.1.1"><p>事件</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.21000000000001%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p>start<sup><span>6+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p>动画开始事件。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p>动画被强制取消。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p>动画播放完成。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p>动画重播事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div id="idName" class="box"></div>
      <div class="buttonBox">
        <button @click="start">
          start
        </button>
        <button @click="cancel">
          cancels
        </button>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
    }
    .box{
      width: 200px;
      height: 200px;
      background-color: #ff0000;
      margin-top: 30px;
    }
    .buttonBox{
      margin-top: 30px;
      width: 250px;
      justify-content: space-between;
    }
    button{
      background-color: #8e8b89;
      color: white;
      width: 100px;
      height: 40px;
      font-size: 24px;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt';
    export default{
      data:{
        animation:'',
      },
      onInit(){
      },
      onShow(){
        var options = {
          duration: 1500,
          easing: 'friction',
          delay: 500,
          fill: 'forwards',
          iterations: 2,
          direction: 'normal',
        };
        var frames = [
          {transform: {translate: '-120px -0px'}, opacity: 0.1, offset: 0.0},
          {transform: {translate: '120px 0px'}, opacity: 1.0, offset: 1.0}
        ];
        this.animation = this.$element('idName').animate(frames, options);
        // handle finish event
        this.animation.onfinish = function(){
          prompt.showToast({
            message: "The animation is finished."
          });
        };
        // handle cancel event
        this.animation.oncancel = function(){
          prompt.showToast({
            message: "The animation is canceled."
          });
        };
        // handle repeat event
        this.animation.onrepeat = function(){
           prompt.showToast({
              message: "The animation is repeated."
           });
        };
      },
      start(){
        this.animation.play();
      },
      cancel(){
        this.animation.cancel();
      }
    }
    ```

    ![](figures/AnimationAPI裁剪.gif)


## getBoundingClientRect<a name="section11967381328"></a>

getBoundingClientRect\(\):  [ <Rect\>](#table1650917111414)

获取元素的大小及其相对于窗口的位置。

-   返回值

    **表 5**  Rect对象说明<sup>6+</sup>

    <a name="table1650917111414"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>该元素的宽度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>该元素的高度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>left</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>该元素左边界距离窗口的偏移。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>top</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>该元素上边界距离窗口的偏移。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // xxx.js
    var rect = this.$element('id').getBoundingClientRect();
    console.info(`current element position is ${rect.left}, ${rect.top}`);
    ```


## createIntersectionObserver<a name="section7425195215615"></a>

createIntersectionObserver\(param?：ObserverParam\): Observer)

监听元素在当前页面的可见范围。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.2%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.1%" id="mcps1.1.5.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.5.1.1 "><p>param</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p>ObserverParam</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>获取observer的回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 6**  ObserverParam对象说明<sup>6+</sup>

    <a name="table1335524911817"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>ratios</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>Array&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>组件超出或小于范围时触发observer的回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    **表 7**  Observer对象支持的方法<sup>6+</sup>

    <a name="table4506633141711"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>observe</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>callback: function</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>开启observer的订阅方法。超出或小于阈值时触发callback。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>unobserve</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>取消observer的订阅方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // xxx.js
    let observer = this.$element('broad').createIntersectionObserver({
      ratios: [0.2, 0.5], // number
    });
    
    observer.observe((isVisible, ratio)=> {
        console.info('this element is ' + isVisible + 'ratio is ' + ratio)
    })
    
    observer.unobserve()
    ```


