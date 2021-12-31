# video<a name="ZH-CN_TOPIC_0000001173164749"></a>

视频播放组件。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   需要在config.json配置
>    ```
>    "configChanges": ["orientation"]
>    ```

## 权限列表<a name="section11257113618419"></a>

## 子组件<a name="sc18e8342b29747dbbd70887cc3c0a22d"></a>

不支持。

## 属性<a name="s50d82bce96774b86846ab2739d7ce18d"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.479999999999999%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.04%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.41%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.73%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.339999999999996%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p>muted</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p>视频是否静音播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p>src</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p>播放视频内容的路径。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p>autoplay</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p>视频是否自动播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p>controls</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p>控制视频播放的控制栏是否显示，如果设置为false，则不显示控制栏。默认为true，由系统决定显示或隐藏控制栏。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="sfbde25405aca4513a9c938f2f339b770"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>object-fit</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>contain</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>视频源的缩放类型，如果poster设置了值，那么此配置还会影响视频海报的缩放类型，可选值参考<a href="#t8eca568266d54af484fec0f84185e923">表1</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  object-fit 类型说明

<a name="t8eca568266d54af484fec0f84185e923"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.2.3.1.1"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="84.98%" id="mcps1.2.3.1.2"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p>fill</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p>不保持宽高比进行放大缩小，使得图片填充满显示边界。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section4181420161817"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>prepared</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ duration: value }<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>视频准备完成时触发该事件，通过duration可以获取视频时长，单位为s。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>播放时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>暂停时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>finish</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>播放结束时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>error</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>播放失败时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>seeking</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>操作进度条过程时上报时间信息，单位为s。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>seeked</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>操作进度条完成后，上报播放时间信息，单位为s。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>timeupdate</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>播放进度变化时触发该事件，单位为s，更新时间间隔为250ms。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="s557cc2f457ff42a193807500adae2f91"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="28.000000000000004%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.82%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.18%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.82%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.18%" headers="mcps1.1.4.1.3 "><p>请求播放视频。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.82%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.18%" headers="mcps1.1.4.1.3 "><p>请求暂停播放视频。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p>setCurrentTime</p>
</td>
<td class="cellrowborder" valign="top" width="29.82%" headers="mcps1.1.4.1.2 "><p>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="42.18%" headers="mcps1.1.4.1.3 "><p>指定视频播放的进度位置，单位为s。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>在attached组件生命周期回调后，可以调用上述组件方法。

