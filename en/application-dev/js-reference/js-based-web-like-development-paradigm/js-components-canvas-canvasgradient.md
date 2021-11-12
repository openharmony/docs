# CanvasGradient<a name="EN-US_TOPIC_0000001173164733"></a>

**CanvasGradient**  provides a gradient object.

## addColorStop<a name="section12691015917"></a>

addColorStop\(offset: number, color: string\): void

Adds a color stop for the** CanvasGradient**  object based on the specified offset and gradient color.

-   Parameter

    <a name="table1032173253712"></a>
    <table><thead align="left"><tr id="row166643263712"><th class="cellrowborder" valign="top" width="21.69%" id="mcps1.1.4.1.1"><p id="p1966932123714"><a name="p1966932123714"></a><a name="p1966932123714"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.74%" id="mcps1.1.4.1.2"><p id="p10661232173710"><a name="p10661232173710"></a><a name="p10661232173710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.57%" id="mcps1.1.4.1.3"><p id="p66673283719"><a name="p66673283719"></a><a name="p66673283719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1166193243714"><td class="cellrowborder" valign="top" width="21.69%" headers="mcps1.1.4.1.1 "><p id="p96673263717"><a name="p96673263717"></a><a name="p96673263717"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.74%" headers="mcps1.1.4.1.2 "><p id="p1674323372"><a name="p1674323372"></a><a name="p1674323372"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.57%" headers="mcps1.1.4.1.3 "><p id="p12672326374"><a name="p12672326374"></a><a name="p12672326374"></a>Proportion of the distance between the color stop and the start point to the total length. The value ranges from 0 to 1.</p>
    </td>
    </tr>
    <tr id="row146783253715"><td class="cellrowborder" valign="top" width="21.69%" headers="mcps1.1.4.1.1 "><p id="p46773203715"><a name="p46773203715"></a><a name="p46773203715"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.74%" headers="mcps1.1.4.1.2 "><p id="p1967173213712"><a name="p1967173213712"></a><a name="p1967173213712"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.57%" headers="mcps1.1.4.1.3 "><p id="p1467123233710"><a name="p1467123233710"></a><a name="p1467123233710"></a>Gradient color to set.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example Code

    ```
    const gradient = ctx.createLinearGradient(0,0,100,0);
    gradient.addColorStop(0,'#00ffff');
    gradient.addColorStop(1,'#ffff00');
    ```

    ![](figures/en-us_image_0000001152610806.png)


