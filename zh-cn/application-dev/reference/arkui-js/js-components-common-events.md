# 通用事件<a name="ZH-CN_TOPIC_0000001173324611"></a>

## 事件说明<a name="section05041657172410"></a>

-   事件绑定在组件上，当组件达到事件触发条件时，会执行JS中对应的事件回调函数，实现页面UI视图和页面JS逻辑层的交互；
-   事件回调函数中通过参数可以携带额外的信息，如组件上的数据对象dataset，事件特有的回调参数。

相对于私有事件，大部分组件都可以绑定如下事件。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.96149614961496%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.242024202420243%" id="mcps1.1.5.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.34453445344535%" id="mcps1.1.5.1.3"><p>描述</p>
</th>
<th class="cellrowborder" valign="top" width="19.451945194519453%" id="mcps1.1.5.1.4"><p>是否支持冒泡</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指刚触摸屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>是<sup>5+</sup></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指触摸屏幕后移动时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>是<sup>5+</sup></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指触摸屏幕中动作被打断时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>是<sup>5+</sup></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指触摸结束离开屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>是<sup>5+</sup></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>click</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>点击动作触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>是<sup>6+</sup></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>doubleclick<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>双击动作触发该事件</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>长按动作触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>swipe<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>组件上快速滑动后触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>attached<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>当前组件节点挂载在渲染树后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>detached<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>当前组件节点从渲染树中移除后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>pinchstart<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指开始执行捏合操作时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>pinchupdate<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指执行捏合操作过程中触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>pinchend<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指捏合操作结束离开屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>pinchcancel<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>手指捏合操作被打断时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>dragstart<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>用户开始拖拽时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>drag<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>拖拽过程中触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>dragend<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>用户拖拽完成后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>dragenter<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>进入释放目标时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>dragover<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>在释放目标内拖动时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>dragleave<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>离开释放目标区域时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p>drop<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p>在可释放目标区域内释放时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p>否</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>除上述事件外，其他事件均为非冒泡事件，如[input的change事件](js-components-basic-input.md#section1721512551218)，详见各个组件。

**表 1**  BaseEvent对象属性列表

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="14.14%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="68.69%" id="mcps1.2.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p>当前事件的类型，比如click、longpress等。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p>该事件触发时的时间戳。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  TouchEvent对象属性列表\(继承BaseEvent\)

<a name="tdb541af4e4db41d7a92e9b6e3c93f606"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.439999999999998%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="20.14%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="60.419999999999995%" id="mcps1.2.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p>touches</p>
</td>
<td class="cellrowborder" valign="top" width="20.14%" headers="mcps1.2.4.1.2 "><p>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="60.419999999999995%" headers="mcps1.2.4.1.3 "><p>触摸事件时的属性集合，包含屏幕触摸点的信息数组。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p>changedTouches</p>
</td>
<td class="cellrowborder" valign="top" width="20.14%" headers="mcps1.2.4.1.2 "><p>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="60.419999999999995%" headers="mcps1.2.4.1.3 "><p>触摸事件时的属性集合，包括产生变化的屏幕触摸点的信息数组。数据格式和touches一样。该属性表示有变化的触摸点，如从无变有，位置变化，从有变无。例如用户手指刚接触屏幕时，touches数组中有数据，但changedTouches无数据。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  TouchInfo

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.060000000000002%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.2.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p>距离屏幕左上角（不包括状态栏）横向距离。屏幕的左上角为原点。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p>距离屏幕左上角（不包括状态栏）纵向距离。屏幕的左上角为原点。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p>localX</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p>距离被触摸组件左上角横向距离。组件的左上角为原点。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p>localY</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p>距离被触摸组件左上角纵向距离。组件的左上角为原点。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p>触摸接触面积。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p>force<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p>接触力信息。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  SwipeEvent 基础事件对象属性列表（继承BaseEvent）

<a name="table111811577714"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p>direction</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p>滑动方向，可能值有：</p>
<ol><li>left：向左滑动；</li><li>right：向右滑动；</li><li>up：向上滑动；</li><li>down：向下滑动。</li></ol>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p>distance<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p>在滑动方向上的滑动距离。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  PinchEvent 对象属性列表<sup>7+</sup>

<a name="table1828625919617"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p>scale</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p>缩放比例</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p>pinchCenterX</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p>捏合中心点X轴坐标，单位px</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p>pinchCenterY</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p>捏合中心点Y轴坐标，单位px</p>
</td>
</tr>
</tbody>
</table>

**表 6**  DragEvent对象属性列表\(继承BaseEvent\)<sup>7+</sup>

<a name="table95551461358"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="20.06%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="62.94%" id="mcps1.2.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p>事件名称。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p>距离屏幕左上角坐标原点横向距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p>距离屏幕左上角坐标原点纵向距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p>时间戳。</p>
</td>
</tr>
</tbody>
</table>

## 事件对象<a name="section18787165861818"></a>

当组件触发事件后，事件回调函数默认会收到一个事件对象，通过该事件对象可以获取相应的信息。

**target对象：**

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p>dataSet<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p>Object</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p><span>组件上通过通用属性设置的</span><a href="js-components-common-attributes.md">data-*</a><span>的自定义属性组成的集合。</span></p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
<!-- xxx.hml -->
<div>
  <div data-a="dataA" data-b="dataB" 
    style="width: 100%; height: 50%; background-color: saddlebrown;"@touchstart='touchstartfunc'></div>
</div>
```

```
// xxx.js
export default {
  touchstartfunc(msg) {
    console.info(`on touch start, point is: ${msg.touches[0].globalX}`);
    console.info(`on touch start, data is: ${msg.target.dataSet.a}`);
  }
}
```

