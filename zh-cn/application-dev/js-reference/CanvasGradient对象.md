# CanvasGradient对象<a name="ZH-CN_TOPIC_0000001162494623"></a>

-   [addColorStop\(\)](#zh-cn_topic_0000001058460513_section12691015917)

渐变对象。

## addColorStop\(\)<a name="zh-cn_topic_0000001058460513_section12691015917"></a>

设置渐变断点值，包括偏移和颜色。

-   参数

    <a name="zh-cn_topic_0000001058460513_table1032173253712"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058460513_row166643263712"><th class="cellrowborder" valign="top" width="21.69%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001058460513_p1966932123714"><a name="zh-cn_topic_0000001058460513_p1966932123714"></a><a name="zh-cn_topic_0000001058460513_p1966932123714"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.74%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001058460513_p10661232173710"><a name="zh-cn_topic_0000001058460513_p10661232173710"></a><a name="zh-cn_topic_0000001058460513_p10661232173710"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.57%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001058460513_p66673283719"><a name="zh-cn_topic_0000001058460513_p66673283719"></a><a name="zh-cn_topic_0000001058460513_p66673283719"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058460513_row1166193243714"><td class="cellrowborder" valign="top" width="21.69%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058460513_p96673263717"><a name="zh-cn_topic_0000001058460513_p96673263717"></a><a name="zh-cn_topic_0000001058460513_p96673263717"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.74%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058460513_p1674323372"><a name="zh-cn_topic_0000001058460513_p1674323372"></a><a name="zh-cn_topic_0000001058460513_p1674323372"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.57%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058460513_p12672326374"><a name="zh-cn_topic_0000001058460513_p12672326374"></a><a name="zh-cn_topic_0000001058460513_p12672326374"></a>设置渐变点距离起点的位置占总体长度的比例，范围为0到1。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058460513_row146783253715"><td class="cellrowborder" valign="top" width="21.69%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058460513_p46773203715"><a name="zh-cn_topic_0000001058460513_p46773203715"></a><a name="zh-cn_topic_0000001058460513_p46773203715"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.74%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058460513_p1967173213712"><a name="zh-cn_topic_0000001058460513_p1967173213712"></a><a name="zh-cn_topic_0000001058460513_p1967173213712"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.57%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058460513_p1467123233710"><a name="zh-cn_topic_0000001058460513_p1467123233710"></a><a name="zh-cn_topic_0000001058460513_p1467123233710"></a>设置渐变的颜色。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    const gradient = ctx.createLinearGradient(0,0,100,0);
    gradient.addColorStop(0,'#00ffff');
    gradient.addColorStop(1,'#ffff00');
    ```


