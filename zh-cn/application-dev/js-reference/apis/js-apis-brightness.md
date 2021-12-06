# 设置系统屏幕亮度<a name="ZH-CN_TOPIC_0000001209252189"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001163808920_s56d19203690d4782bfc74069abb6bd71"></a>

```
import brightness from '@ohos.brightness.d.ts'.
```

## brightness.setValue<a name="zh-cn_topic_0000001163808920_section1853612361618"></a>

setValue\(value: number\)

设置系统的屏幕亮度。

-   参数：

    <a name="zh-cn_topic_0000001163808920_table888613685714"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163808920_row1988683685713"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163808920_p1488693625712"><a name="zh-cn_topic_0000001163808920_p1488693625712"></a><a name="zh-cn_topic_0000001163808920_p1488693625712"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163808920_p1886173613571"><a name="zh-cn_topic_0000001163808920_p1886173613571"></a><a name="zh-cn_topic_0000001163808920_p1886173613571"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163808920_p128861336155714"><a name="zh-cn_topic_0000001163808920_p128861336155714"></a><a name="zh-cn_topic_0000001163808920_p128861336155714"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163808920_p3886143617571"><a name="zh-cn_topic_0000001163808920_p3886143617571"></a><a name="zh-cn_topic_0000001163808920_p3886143617571"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163808920_row9886133613577"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163808920_p14886163695720"><a name="zh-cn_topic_0000001163808920_p14886163695720"></a><a name="zh-cn_topic_0000001163808920_p14886163695720"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163808920_p9886123605716"><a name="zh-cn_topic_0000001163808920_p9886123605716"></a><a name="zh-cn_topic_0000001163808920_p9886123605716"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163808920_p988723618577"><a name="zh-cn_topic_0000001163808920_p988723618577"></a><a name="zh-cn_topic_0000001163808920_p988723618577"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163808920_p2512184017289"><a name="zh-cn_topic_0000001163808920_p2512184017289"></a><a name="zh-cn_topic_0000001163808920_p2512184017289"></a><span>亮度的值</span>（0~255）</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import brightness from '@ohos.brightness.d.ts'
    brightness.setValue(128);
    ```


