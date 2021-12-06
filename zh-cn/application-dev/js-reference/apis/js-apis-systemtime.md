# 时间设置<a name="ZH-CN_TOPIC_0000001209417001"></a>

## 导入模块<a name="zh-cn_topic_0000001162403059_s56d19203690d4782bfc74069abb6bd71"></a>

```
import systemTime from '@ohos.systemTime';
```

## 权限列表<a name="zh-cn_topic_0000001162403059_section11257113618419"></a>

无。

## setTime\(number, AsyncCallback<boolean\>\)<a name="zh-cn_topic_0000001162403059_section1524014116262"></a>

设置系统时间

**参数：**

<a name="zh-cn_topic_0000001162403059_table112401811122614"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001162403059_row124031142616"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001162403059_p2240131132615"><a name="zh-cn_topic_0000001162403059_p2240131132615"></a><a name="zh-cn_topic_0000001162403059_p2240131132615"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001162403059_p624051162618"><a name="zh-cn_topic_0000001162403059_p624051162618"></a><a name="zh-cn_topic_0000001162403059_p624051162618"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001162403059_p20240191112614"><a name="zh-cn_topic_0000001162403059_p20240191112614"></a><a name="zh-cn_topic_0000001162403059_p20240191112614"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001162403059_p5241141142613"><a name="zh-cn_topic_0000001162403059_p5241141142613"></a><a name="zh-cn_topic_0000001162403059_p5241141142613"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001162403059_row424121182620"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001162403059_p172419113264"><a name="zh-cn_topic_0000001162403059_p172419113264"></a><a name="zh-cn_topic_0000001162403059_p172419113264"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001162403059_p92417114267"><a name="zh-cn_topic_0000001162403059_p92417114267"></a><a name="zh-cn_topic_0000001162403059_p92417114267"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001162403059_p62410118264"><a name="zh-cn_topic_0000001162403059_p62410118264"></a><a name="zh-cn_topic_0000001162403059_p62410118264"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001162403059_p1824111117261"><a name="zh-cn_topic_0000001162403059_p1824111117261"></a><a name="zh-cn_topic_0000001162403059_p1824111117261"></a>目标时间戳（毫秒）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001162403059_row52411911172613"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001162403059_p024131132620"><a name="zh-cn_topic_0000001162403059_p024131132620"></a><a name="zh-cn_topic_0000001162403059_p024131132620"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001162403059_p192411611192615"><a name="zh-cn_topic_0000001162403059_p192411611192615"></a><a name="zh-cn_topic_0000001162403059_p192411611192615"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001162403059_p524131111267"><a name="zh-cn_topic_0000001162403059_p524131111267"></a><a name="zh-cn_topic_0000001162403059_p524131111267"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001162403059_p92411811172612"><a name="zh-cn_topic_0000001162403059_p92411811172612"></a><a name="zh-cn_topic_0000001162403059_p92411811172612"></a>回调函数，可以在回调函数中处理接口返回值。</p>
<a name="zh-cn_topic_0000001162403059_ul3241511112612"></a><a name="zh-cn_topic_0000001162403059_ul3241511112612"></a><ul id="zh-cn_topic_0000001162403059_ul3241511112612"><li>返回值为true，表示设置系统时间成功；</li><li>返回值为false，表示设置系统时间失败。</li></ul>
</td>
</tr>
</tbody>
</table>

**示例：**

```
// time对应的时间为2021-01-20 02:36:25
var time = 1611081385000;
systemTime.setTime(time, (err, value) => {
    if (err) {
        // 设置时间失败，err非空，value为空。
        console.error(`failed to systemTime.setTime because ${err.message}`);
        return;
    }

    // 设置时间成功，err为空，value非空。
    console.log(`success to systemTime.setTime: ${value}`);
});
```

## setTime\(number\) : Promise<boolean\><a name="zh-cn_topic_0000001162403059_section1853612361618"></a>

设置系统时间

**参数：**

<a name="zh-cn_topic_0000001162403059_table888613685714"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001162403059_row1988683685713"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001162403059_p1488693625712"><a name="zh-cn_topic_0000001162403059_p1488693625712"></a><a name="zh-cn_topic_0000001162403059_p1488693625712"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001162403059_p1886173613571"><a name="zh-cn_topic_0000001162403059_p1886173613571"></a><a name="zh-cn_topic_0000001162403059_p1886173613571"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001162403059_p128861336155714"><a name="zh-cn_topic_0000001162403059_p128861336155714"></a><a name="zh-cn_topic_0000001162403059_p128861336155714"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001162403059_p3886143617571"><a name="zh-cn_topic_0000001162403059_p3886143617571"></a><a name="zh-cn_topic_0000001162403059_p3886143617571"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001162403059_row9886133613577"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001162403059_p14886163695720"><a name="zh-cn_topic_0000001162403059_p14886163695720"></a><a name="zh-cn_topic_0000001162403059_p14886163695720"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001162403059_p9886123605716"><a name="zh-cn_topic_0000001162403059_p9886123605716"></a><a name="zh-cn_topic_0000001162403059_p9886123605716"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001162403059_p988723618577"><a name="zh-cn_topic_0000001162403059_p988723618577"></a><a name="zh-cn_topic_0000001162403059_p988723618577"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001162403059_p733604215450"><a name="zh-cn_topic_0000001162403059_p733604215450"></a><a name="zh-cn_topic_0000001162403059_p733604215450"></a>目标时间戳（毫秒）。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001162403059_table106721328171713"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001162403059_row9672122817176"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001162403059_p106728288171"><a name="zh-cn_topic_0000001162403059_p106728288171"></a><a name="zh-cn_topic_0000001162403059_p106728288171"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001162403059_p5672112817178"><a name="zh-cn_topic_0000001162403059_p5672112817178"></a><a name="zh-cn_topic_0000001162403059_p5672112817178"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001162403059_row06721528191711"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001162403059_p107821612171919"><a name="zh-cn_topic_0000001162403059_p107821612171919"></a><a name="zh-cn_topic_0000001162403059_p107821612171919"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><a name="zh-cn_topic_0000001162403059_ul17920183121211"></a><a name="zh-cn_topic_0000001162403059_ul17920183121211"></a><ul id="zh-cn_topic_0000001162403059_ul17920183121211"><li>返回值为true，表示设置系统时间成功；</li><li>返回值为false，表示设置系统时间失败。</li></ul>
</td>
</tr>
</tbody>
</table>

**示例：**

```
// time对应的时间为2021-01-20 02:36:25
var time = 1611081385000;
systemTime.setTime(time)
    .then((value) => {
        // 设置时间成功
        console.log(`success to systemTime.setTime: ${value}`);
    }).catch((err) => {
        // 设置时间失败
        console.error(`failed to systemTime.setTime because ${err.message}`);
    });
```

