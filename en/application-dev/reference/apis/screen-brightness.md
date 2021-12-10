# Screen Brightness<a name="EN-US_TOPIC_0000001162494637"></a>

## Modules to Import<a name="en-us_topic_0000001101127828_s56d19203690d4782bfc74069abb6bd71"></a>

```
import brightness from '@ohos.brightness.d.ts'.
```

## Functions<a name="en-us_topic_0000001101127828_section1998783153219"></a>

## setValue\(value: number\)<a name="en-us_topic_0000001101127828_section1853612361618"></a>

Sets the screen brightness.

**Parameters**

<a name="en-us_topic_0000001101127828_table888613685714"></a>
<table><thead align="left"><tr id="en-us_topic_0000001101127828_row1988683685713"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001101127828_p1488693625712"><a name="en-us_topic_0000001101127828_p1488693625712"></a><a name="en-us_topic_0000001101127828_p1488693625712"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001101127828_p1886173613571"><a name="en-us_topic_0000001101127828_p1886173613571"></a><a name="en-us_topic_0000001101127828_p1886173613571"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001101127828_p128861336155714"><a name="en-us_topic_0000001101127828_p128861336155714"></a><a name="en-us_topic_0000001101127828_p128861336155714"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001101127828_p3886143617571"><a name="en-us_topic_0000001101127828_p3886143617571"></a><a name="en-us_topic_0000001101127828_p3886143617571"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001101127828_row9886133613577"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001101127828_p14886163695720"><a name="en-us_topic_0000001101127828_p14886163695720"></a><a name="en-us_topic_0000001101127828_p14886163695720"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001101127828_p9886123605716"><a name="en-us_topic_0000001101127828_p9886123605716"></a><a name="en-us_topic_0000001101127828_p9886123605716"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001101127828_p988723618577"><a name="en-us_topic_0000001101127828_p988723618577"></a><a name="en-us_topic_0000001101127828_p988723618577"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001101127828_p2512184017289"><a name="en-us_topic_0000001101127828_p2512184017289"></a><a name="en-us_topic_0000001101127828_p2512184017289"></a>Brightness value, ranging from 0 to 255</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None

-   Example

    ```
    import brightness from '@ohos.brightness.d.ts'
    brightness.setValue(128);
    ```


