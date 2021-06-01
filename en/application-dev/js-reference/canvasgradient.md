# CanvasGradient<a name="EN-US_TOPIC_0000001162494623"></a>

-   [addColorStop\(\)](#en-us_topic_0000001058460513_section12691015917)

**CanvasGradient**  provides a gradient object.

## addColorStop\(\)<a name="en-us_topic_0000001058460513_section12691015917"></a>

Adds a color stop for the** CanvasGradient**  object based on the specified offset and gradient color.

-   Parameter

    <a name="en-us_topic_0000001058460513_table1032173253712"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058460513_row166643263712"><th class="cellrowborder" valign="top" width="21.69%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058460513_p1966932123714"><a name="en-us_topic_0000001058460513_p1966932123714"></a><a name="en-us_topic_0000001058460513_p1966932123714"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.74%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058460513_p10661232173710"><a name="en-us_topic_0000001058460513_p10661232173710"></a><a name="en-us_topic_0000001058460513_p10661232173710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.57%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058460513_p66673283719"><a name="en-us_topic_0000001058460513_p66673283719"></a><a name="en-us_topic_0000001058460513_p66673283719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058460513_row1166193243714"><td class="cellrowborder" valign="top" width="21.69%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058460513_p96673263717"><a name="en-us_topic_0000001058460513_p96673263717"></a><a name="en-us_topic_0000001058460513_p96673263717"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.74%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058460513_p1674323372"><a name="en-us_topic_0000001058460513_p1674323372"></a><a name="en-us_topic_0000001058460513_p1674323372"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.57%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058460513_p12672326374"><a name="en-us_topic_0000001058460513_p12672326374"></a><a name="en-us_topic_0000001058460513_p12672326374"></a>Proportion of the distance between the color stop and the start point to the total length. The value ranges from 0 to 1.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058460513_row146783253715"><td class="cellrowborder" valign="top" width="21.69%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058460513_p46773203715"><a name="en-us_topic_0000001058460513_p46773203715"></a><a name="en-us_topic_0000001058460513_p46773203715"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.74%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058460513_p1967173213712"><a name="en-us_topic_0000001058460513_p1967173213712"></a><a name="en-us_topic_0000001058460513_p1967173213712"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.57%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058460513_p1467123233710"><a name="en-us_topic_0000001058460513_p1467123233710"></a><a name="en-us_topic_0000001058460513_p1467123233710"></a>Gradient color to set.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Returned Value

    N/A

-   Example

    ```
    const gradient = ctx.createLinearGradient(0,0,100,0);
    gradient.addColorStop(0,'#00ffff');
    gradient.addColorStop(1,'#ffff00');
    ```


