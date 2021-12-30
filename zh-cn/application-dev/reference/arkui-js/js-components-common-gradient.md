# 渐变样式<a name="ZH-CN_TOPIC_0000001127284866"></a>

组件普遍支持的在style或css中设置的 可以平稳过渡两个或多个指定的颜色。

开发框架支持线性渐变 \(linear-gradient\)和重复线性渐变 \(repeating-linear-gradient\)两种渐变效果。

## 线性渐变/重复线性渐变<a name="s9fb0b2412d2843e4b06e05acc39dc394"></a>

使用渐变样式，需要定义过渡方向和过渡颜色。

### 过渡方向<a name="section10661986163"></a>

通过direction或者angle指定过渡方向。

-   direction：进行方向渐变。
-   angle：进行角度渐变。

```
background: linear-gradient(direction/angle, color, color, ...);
background: repeating-linear-gradient(direction/angle, color, color, ...);
```

### 过渡颜色<a name="section7598115010167"></a>

支持以下四种方式：\#ff0000、\#ffff0000、rgb\(255, 0, 0\)、rgba\(255, 0, 0, 1\)，需要指定至少两种颜色。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.13131313131313%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.292929292929294%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.14141414141414%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.09090909090909%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.34343434343434%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.1.6.1.1 "><p>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.292929292929294%" headers="mcps1.1.6.1.2 "><p>to &lt;side-or-corner&gt;  &lt;side-or-corner&gt; = [left | right] || [top | bottom]</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.14141414141414%" headers="mcps1.1.6.1.3 "><p>to bottom (由上到下渐变)</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09090909090909%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.34343434343434%" headers="mcps1.1.6.1.5 "><p>指定过渡方向，如：to left (从右向左渐变)  ；或者</p>
    <p>to bottom right (从左上角到右下角)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.1.6.1.1 "><p>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.292929292929294%" headers="mcps1.1.6.1.2 "><p>&lt;deg&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.14141414141414%" headers="mcps1.1.6.1.3 "><p>180deg</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09090909090909%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.34343434343434%" headers="mcps1.1.6.1.5 "><p>指定过渡方向，以元素几何中心为坐标原点，水平方向为X轴，angle指定了渐变线与Y轴的夹角(顺时针方向)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.1.6.1.1 "><p>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.292929292929294%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt; [&lt;length&gt;|&lt;percentage&gt;]</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.14141414141414%" headers="mcps1.1.6.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09090909090909%" headers="mcps1.1.6.1.4 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.34343434343434%" headers="mcps1.1.6.1.5 "><p>定义使用渐变样式区域内颜色的渐变效果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    1. 默认渐变方向为从上向下渐变

    ```
    #gradient {
      height: 300px;
      width: 600px;
      /* 从顶部开始向底部由红色向绿色渐变 */
      background: linear-gradient(red, #00ff00);
    }
    ```

    ![](figures/111.png)

    2. 45度夹角渐变

    ```
      /* 45度夹角，从红色渐变到绿色 */
      background: linear-gradient(45deg, rgb(255,0,0),rgb(0, 255, 0));
    ```

    ![](figures/222.png)

    3. 设置方向从左向右渐变

    ```
    /* 从左向右渐变，在距离左边90px和距离左边360px (600*0.6) 之间270px宽度形成渐变 */
    background: linear-gradient(to right, rgb(255,0,0) 90px, rgb(0, 255, 0) 60%);
    ```

    ![](figures/333.png)

    4. 重复渐变

    ```
    /* 从左向右重复渐变，重复渐变区域30px（60-30）透明度0.5 */
    background: repeating-linear-gradient(to right, rgba(255, 255, 0, 1) 30px,rgba(0, 0, 255, .5) 60px);
    ```

    ![](figures/444.png)


