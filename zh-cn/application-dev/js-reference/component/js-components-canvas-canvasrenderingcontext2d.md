# CanvasRenderingContext2D对象<a name="ZH-CN_TOPIC_0000001164130772"></a>

-   [fillRect\(\)](#zh-cn_topic_0000001173164707_section16678142165920)
-   [fillStyle](#zh-cn_topic_0000001173164707_section159395553313)
-   [clearRect\(\)](#zh-cn_topic_0000001173164707_section205940367194)
-   [strokeRect\(\)](#zh-cn_topic_0000001173164707_section18427819195711)
-   [fillText\(\)](#zh-cn_topic_0000001173164707_section114524106587)
-   [strokeText\(\)](#zh-cn_topic_0000001173164707_section4144191355810)
-   [measureText\(\)](#zh-cn_topic_0000001173164707_section378313153588)
-   [lineWidth](#zh-cn_topic_0000001173164707_section652391716583)
-   [strokeStyle](#zh-cn_topic_0000001173164707_section1191517562337)
-   [stroke\(\)](#zh-cn_topic_0000001173164707_section1071523411019)
-   [beginPath\(\)](#zh-cn_topic_0000001173164707_section12670134392)
-   [moveTo\(\)](#zh-cn_topic_0000001173164707_section16813157310)
-   [lineTo\(\)](#zh-cn_topic_0000001173164707_section4767915838)
-   [closePath\(\)](#zh-cn_topic_0000001173164707_section86825473917)
-   [lineCap](#zh-cn_topic_0000001173164707_section6852133718410)
-   [lineJoin](#zh-cn_topic_0000001173164707_section395812401442)
-   [miterLimit](#zh-cn_topic_0000001173164707_section429711421945)
-   [font](#zh-cn_topic_0000001173164707_section17597332121110)
-   [textAlign](#zh-cn_topic_0000001173164707_section15681153321114)
-   [textBaseline](#zh-cn_topic_0000001173164707_section77981136141111)
-   [createPattern\(\)](#zh-cn_topic_0000001173164707_section1034582183919)
-   [bezierCurveTo\(\)](#zh-cn_topic_0000001173164707_section450521614318)
-   [quadraticCurveTo\(\)](#zh-cn_topic_0000001173164707_section12938183173)
-   [arc\(\)](#zh-cn_topic_0000001173164707_section102329511716)
-   [arcTo\(\)](#zh-cn_topic_0000001173164707_section3172156571)
-   [ellipse\(\)6+](#zh-cn_topic_0000001173164707_section918313239192)
-   [rect\(\)](#zh-cn_topic_0000001173164707_section1351519304107)
-   [fill\(\)](#zh-cn_topic_0000001173164707_section14842031151015)
-   [clip\(\)](#zh-cn_topic_0000001173164707_section1355171921416)
-   [rotate\(\)](#zh-cn_topic_0000001173164707_section7682182091419)
-   [scale\(\)](#zh-cn_topic_0000001173164707_section157714218144)
-   [transform\(\)](#zh-cn_topic_0000001173164707_section1675964717570)
-   [setTransform\(\)](#zh-cn_topic_0000001173164707_section1439382216440)
-   [translate\(\)](#zh-cn_topic_0000001173164707_section931011253449)
-   [createPath2D\(\)6+](#zh-cn_topic_0000001173164707_section6654994314)
-   [globalAlpha](#zh-cn_topic_0000001173164707_section188252174810)
-   [drawImage\(\)](#zh-cn_topic_0000001173164707_section1953117410488)
-   [restore\(\)](#zh-cn_topic_0000001173164707_section64027684817)
-   [save\(\)](#zh-cn_topic_0000001173164707_section410672635214)
-   [createLinearGradient\(\)6+](#zh-cn_topic_0000001173164707_section1696310905)
-   [createRadialGradient\(\)6+](#zh-cn_topic_0000001173164707_section121861417143711)
-   [createImageData\(\)](#zh-cn_topic_0000001173164707_section2021142714524)
-   [getImageData\(\)](#zh-cn_topic_0000001173164707_section92731528205217)
-   [putImageData\(\)](#zh-cn_topic_0000001173164707_section15774154925515)
-   [setLineDash\(\)](#zh-cn_topic_0000001173164707_section1934985155516)
-   [getLineDash\(\)](#zh-cn_topic_0000001173164707_section522105285519)
-   [lineDashOffset](#zh-cn_topic_0000001173164707_section8283548889)
-   [globalCompositeOperation](#zh-cn_topic_0000001173164707_section123871750284)
-   [shadowBlur](#zh-cn_topic_0000001173164707_section6207051888)
-   [shadowColor](#zh-cn_topic_0000001173164707_section42724396120)
-   [shadowOffsetX](#zh-cn_topic_0000001173164707_section1616174021219)
-   [shadowOffsetY](#zh-cn_topic_0000001173164707_section272013417128)
-   [imageSmoothingEnabled6+](#zh-cn_topic_0000001173164707_section770341132716)
-   [transferFromImageBitmap\(\)7+](#zh-cn_topic_0000001173164707_section9849145418469)

使用CanvasRenderingContext2D在canvas画布组件上进行绘制，绘制对象可以是矩形、文本、图片等。

-   示例

    ```
    <!-- xxx.hml -->
    <div>
      <canvas ref="canvas1" style="width: 200px; height: 150px; background-color: #ffff00;"></canvas>
      <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
      <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="antialias" />
    </div>
    ```

    ```
    // xxx.js
    export default {
      handleClick() {
        const el = this.$refs.canvas1;
        const ctx = el.getContext('2d');
        ctx.beginPath();
        ctx.arc(100, 75, 50, 0, 6.28);
        ctx.stroke();
      },
      antialias() {
        const el = this.$refs.canvas1;
        const ctx = el.getContext('2d', { antialias: true });
        ctx.beginPath();
        ctx.arc(100, 75, 50, 0, 6.28);
        ctx.stroke();
      }
    }
    ```


-   示意图（关闭抗锯齿）

    ![](figures/zh-cn_image_0000001127125160.png)

-   示意图（开启抗锯齿）

    ![](figures/zh-cn_image_0000001127125162.png)


## fillRect\(\)<a name="zh-cn_topic_0000001173164707_section16678142165920"></a>

填充一个矩形。

-   参数

    <a name="zh-cn_topic_0000001173164707_table116784429596"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row167864213591"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p8678134225914"><a name="zh-cn_topic_0000001173164707_p8678134225914"></a><a name="zh-cn_topic_0000001173164707_p8678134225914"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p567911425597"><a name="zh-cn_topic_0000001173164707_p567911425597"></a><a name="zh-cn_topic_0000001173164707_p567911425597"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p116798423594"><a name="zh-cn_topic_0000001173164707_p116798423594"></a><a name="zh-cn_topic_0000001173164707_p116798423594"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row46791042125917"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1467911422593"><a name="zh-cn_topic_0000001173164707_p1467911422593"></a><a name="zh-cn_topic_0000001173164707_p1467911422593"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1967994235916"><a name="zh-cn_topic_0000001173164707_p1967994235916"></a><a name="zh-cn_topic_0000001173164707_p1967994235916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1367984295913"><a name="zh-cn_topic_0000001173164707_p1367984295913"></a><a name="zh-cn_topic_0000001173164707_p1367984295913"></a>指定矩形左上角点的x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1667911426594"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p7679154225917"><a name="zh-cn_topic_0000001173164707_p7679154225917"></a><a name="zh-cn_topic_0000001173164707_p7679154225917"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p867984219592"><a name="zh-cn_topic_0000001173164707_p867984219592"></a><a name="zh-cn_topic_0000001173164707_p867984219592"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p567964295917"><a name="zh-cn_topic_0000001173164707_p567964295917"></a><a name="zh-cn_topic_0000001173164707_p567964295917"></a>指定矩形左上角点的y坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row13679114214590"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p126791642105910"><a name="zh-cn_topic_0000001173164707_p126791642105910"></a><a name="zh-cn_topic_0000001173164707_p126791642105910"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p26792422594"><a name="zh-cn_topic_0000001173164707_p26792422594"></a><a name="zh-cn_topic_0000001173164707_p26792422594"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p899913810401"><a name="zh-cn_topic_0000001173164707_p899913810401"></a><a name="zh-cn_topic_0000001173164707_p899913810401"></a>指定矩形的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row156796426598"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1567944235917"><a name="zh-cn_topic_0000001173164707_p1567944235917"></a><a name="zh-cn_topic_0000001173164707_p1567944235917"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p10679642185915"><a name="zh-cn_topic_0000001173164707_p10679642185915"></a><a name="zh-cn_topic_0000001173164707_p10679642185915"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1668013426599"><a name="zh-cn_topic_0000001173164707_p1668013426599"></a><a name="zh-cn_topic_0000001173164707_p1668013426599"></a>指定矩形的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillRect(20, 20, 200, 150);
    ```

    ![](figures/zh-cn_image_0000001127125134.png)


## fillStyle<a name="zh-cn_topic_0000001173164707_section159395553313"></a>

指定绘制的填充色。

-   参数

    <a name="zh-cn_topic_0000001173164707_table11871845480"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row8211446487"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p172111344482"><a name="zh-cn_topic_0000001173164707_p172111344482"></a><a name="zh-cn_topic_0000001173164707_p172111344482"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p921110413486"><a name="zh-cn_topic_0000001173164707_p921110413486"></a><a name="zh-cn_topic_0000001173164707_p921110413486"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1221111444810"><a name="zh-cn_topic_0000001173164707_p1221111444810"></a><a name="zh-cn_topic_0000001173164707_p1221111444810"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row92116414485"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p3211242481"><a name="zh-cn_topic_0000001173164707_p3211242481"></a><a name="zh-cn_topic_0000001173164707_p3211242481"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p3211164124812"><a name="zh-cn_topic_0000001173164707_p3211164124812"></a><a name="zh-cn_topic_0000001173164707_p3211164124812"></a>&lt;color&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p42117420487"><a name="zh-cn_topic_0000001173164707_p42117420487"></a><a name="zh-cn_topic_0000001173164707_p42117420487"></a>设置填充区域的颜色。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row19211345485"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p42124414813"><a name="zh-cn_topic_0000001173164707_p42124414813"></a><a name="zh-cn_topic_0000001173164707_p42124414813"></a>gradient</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p52124494812"><a name="zh-cn_topic_0000001173164707_p52124494812"></a><a name="zh-cn_topic_0000001173164707_p52124494812"></a>CanvasGradient</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1721217418484"><a name="zh-cn_topic_0000001173164707_p1721217418484"></a><a name="zh-cn_topic_0000001173164707_p1721217418484"></a>渐变对象，使用 createLinearGradient()方法创建。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row621218424815"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p02127464814"><a name="zh-cn_topic_0000001173164707_p02127464814"></a><a name="zh-cn_topic_0000001173164707_p02127464814"></a>pattern</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1921284174819"><a name="zh-cn_topic_0000001173164707_p1921284174819"></a><a name="zh-cn_topic_0000001173164707_p1921284174819"></a>CanvasPattern</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1821210414486"><a name="zh-cn_topic_0000001173164707_p1821210414486"></a><a name="zh-cn_topic_0000001173164707_p1821210414486"></a>使用 createPattern()方法创建。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillStyle = '#0000ff';
    ctx.fillRect(20, 20, 150, 100);
    ```

    ![](figures/zh-cn_image_0000001127284942.png)


## clearRect\(\)<a name="zh-cn_topic_0000001173164707_section205940367194"></a>

删除指定区域内的绘制内容。

-   参数

    <a name="zh-cn_topic_0000001173164707_table17906135163511"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1293515173513"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p9935195111353"><a name="zh-cn_topic_0000001173164707_p9935195111353"></a><a name="zh-cn_topic_0000001173164707_p9935195111353"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p993516515354"><a name="zh-cn_topic_0000001173164707_p993516515354"></a><a name="zh-cn_topic_0000001173164707_p993516515354"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1893510517352"><a name="zh-cn_topic_0000001173164707_p1893510517352"></a><a name="zh-cn_topic_0000001173164707_p1893510517352"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row109351051153516"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p29357518355"><a name="zh-cn_topic_0000001173164707_p29357518355"></a><a name="zh-cn_topic_0000001173164707_p29357518355"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1093510513353"><a name="zh-cn_topic_0000001173164707_p1093510513353"></a><a name="zh-cn_topic_0000001173164707_p1093510513353"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1893545115356"><a name="zh-cn_topic_0000001173164707_p1893545115356"></a><a name="zh-cn_topic_0000001173164707_p1893545115356"></a>指定矩形上的左上角x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row49351651123519"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p14935145119354"><a name="zh-cn_topic_0000001173164707_p14935145119354"></a><a name="zh-cn_topic_0000001173164707_p14935145119354"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1993595111355"><a name="zh-cn_topic_0000001173164707_p1993595111355"></a><a name="zh-cn_topic_0000001173164707_p1993595111355"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p14935135103519"><a name="zh-cn_topic_0000001173164707_p14935135103519"></a><a name="zh-cn_topic_0000001173164707_p14935135103519"></a>指定矩形上的左上角y坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row11935551173517"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p129351251173520"><a name="zh-cn_topic_0000001173164707_p129351251173520"></a><a name="zh-cn_topic_0000001173164707_p129351251173520"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p159351516351"><a name="zh-cn_topic_0000001173164707_p159351516351"></a><a name="zh-cn_topic_0000001173164707_p159351516351"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p7935195113515"><a name="zh-cn_topic_0000001173164707_p7935195113515"></a><a name="zh-cn_topic_0000001173164707_p7935195113515"></a>指定矩形的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row13935145118355"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p69361451113519"><a name="zh-cn_topic_0000001173164707_p69361451113519"></a><a name="zh-cn_topic_0000001173164707_p69361451113519"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p893611511357"><a name="zh-cn_topic_0000001173164707_p893611511357"></a><a name="zh-cn_topic_0000001173164707_p893611511357"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p11936155183515"><a name="zh-cn_topic_0000001173164707_p11936155183515"></a><a name="zh-cn_topic_0000001173164707_p11936155183515"></a>指定矩形的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillStyle = 'rgb(0,0,255)';
    ctx.fillRect(0, 0, 400, 200);
    ctx.clearRect(20, 20, 150, 100);
    ```

    ![](figures/zh-cn_image_0000001173164831.png)


## strokeRect\(\)<a name="zh-cn_topic_0000001173164707_section18427819195711"></a>

绘制具有边框的矩形，矩形内部不填充。

-   参数

    <a name="zh-cn_topic_0000001173164707_table18471143916378"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1849515396371"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p5495133918379"><a name="zh-cn_topic_0000001173164707_p5495133918379"></a><a name="zh-cn_topic_0000001173164707_p5495133918379"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p10495103913717"><a name="zh-cn_topic_0000001173164707_p10495103913717"></a><a name="zh-cn_topic_0000001173164707_p10495103913717"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1949515397379"><a name="zh-cn_topic_0000001173164707_p1949515397379"></a><a name="zh-cn_topic_0000001173164707_p1949515397379"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1449512396370"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p15495143917372"><a name="zh-cn_topic_0000001173164707_p15495143917372"></a><a name="zh-cn_topic_0000001173164707_p15495143917372"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1949514399373"><a name="zh-cn_topic_0000001173164707_p1949514399373"></a><a name="zh-cn_topic_0000001173164707_p1949514399373"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1149513912372"><a name="zh-cn_topic_0000001173164707_p1149513912372"></a><a name="zh-cn_topic_0000001173164707_p1149513912372"></a>指定矩形的左上角x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1049543973713"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p3495193913379"><a name="zh-cn_topic_0000001173164707_p3495193913379"></a><a name="zh-cn_topic_0000001173164707_p3495193913379"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1349513391377"><a name="zh-cn_topic_0000001173164707_p1349513391377"></a><a name="zh-cn_topic_0000001173164707_p1349513391377"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p84961139193711"><a name="zh-cn_topic_0000001173164707_p84961139193711"></a><a name="zh-cn_topic_0000001173164707_p84961139193711"></a>指定矩形的左上角y坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row12496139143718"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1049633918378"><a name="zh-cn_topic_0000001173164707_p1049633918378"></a><a name="zh-cn_topic_0000001173164707_p1049633918378"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p184961039113711"><a name="zh-cn_topic_0000001173164707_p184961039113711"></a><a name="zh-cn_topic_0000001173164707_p184961039113711"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p18496183918373"><a name="zh-cn_topic_0000001173164707_p18496183918373"></a><a name="zh-cn_topic_0000001173164707_p18496183918373"></a>指定矩形的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1842894223717"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p03284623713"><a name="zh-cn_topic_0000001173164707_p03284623713"></a><a name="zh-cn_topic_0000001173164707_p03284623713"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p83204615372"><a name="zh-cn_topic_0000001173164707_p83204615372"></a><a name="zh-cn_topic_0000001173164707_p83204615372"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p333154663711"><a name="zh-cn_topic_0000001173164707_p333154663711"></a><a name="zh-cn_topic_0000001173164707_p333154663711"></a>指定矩形的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.strokeRect(30, 30, 200, 150);
    ```

    ![](figures/zh-cn_image_0000001173164817.png)


## fillText\(\)<a name="zh-cn_topic_0000001173164707_section114524106587"></a>

绘制填充类文本。

-   参数

    <a name="zh-cn_topic_0000001173164707_table19120835143816"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row9150835103813"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p915043533812"><a name="zh-cn_topic_0000001173164707_p915043533812"></a><a name="zh-cn_topic_0000001173164707_p915043533812"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p19150193515381"><a name="zh-cn_topic_0000001173164707_p19150193515381"></a><a name="zh-cn_topic_0000001173164707_p19150193515381"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p31501935153812"><a name="zh-cn_topic_0000001173164707_p31501935153812"></a><a name="zh-cn_topic_0000001173164707_p31501935153812"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row191502350385"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1115017358383"><a name="zh-cn_topic_0000001173164707_p1115017358383"></a><a name="zh-cn_topic_0000001173164707_p1115017358383"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p815043517389"><a name="zh-cn_topic_0000001173164707_p815043517389"></a><a name="zh-cn_topic_0000001173164707_p815043517389"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1150193510385"><a name="zh-cn_topic_0000001173164707_p1150193510385"></a><a name="zh-cn_topic_0000001173164707_p1150193510385"></a>需要绘制的文本内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row81501835173814"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1215093523810"><a name="zh-cn_topic_0000001173164707_p1215093523810"></a><a name="zh-cn_topic_0000001173164707_p1215093523810"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p7150173583813"><a name="zh-cn_topic_0000001173164707_p7150173583813"></a><a name="zh-cn_topic_0000001173164707_p7150173583813"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p515011352383"><a name="zh-cn_topic_0000001173164707_p515011352383"></a><a name="zh-cn_topic_0000001173164707_p515011352383"></a>需要绘制的文本的左下角x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row11150135183813"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p61506358386"><a name="zh-cn_topic_0000001173164707_p61506358386"></a><a name="zh-cn_topic_0000001173164707_p61506358386"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1515018356386"><a name="zh-cn_topic_0000001173164707_p1515018356386"></a><a name="zh-cn_topic_0000001173164707_p1515018356386"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p51503354387"><a name="zh-cn_topic_0000001173164707_p51503354387"></a><a name="zh-cn_topic_0000001173164707_p51503354387"></a>需要绘制的文本的左下角y坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.font = '35px sans-serif';
    ctx.fillText("Hello World!", 20, 60);
    ```

    ![](figures/zh-cn_image_0000001173164833.png)


## strokeText\(\)<a name="zh-cn_topic_0000001173164707_section4144191355810"></a>

绘制描边类文本。

-   参数

    <a name="zh-cn_topic_0000001173164707_table26917485393"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row7719748133917"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p19719548153913"><a name="zh-cn_topic_0000001173164707_p19719548153913"></a><a name="zh-cn_topic_0000001173164707_p19719548153913"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p8719114812395"><a name="zh-cn_topic_0000001173164707_p8719114812395"></a><a name="zh-cn_topic_0000001173164707_p8719114812395"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p9719648163917"><a name="zh-cn_topic_0000001173164707_p9719648163917"></a><a name="zh-cn_topic_0000001173164707_p9719648163917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1571915482398"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p9719204813392"><a name="zh-cn_topic_0000001173164707_p9719204813392"></a><a name="zh-cn_topic_0000001173164707_p9719204813392"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p371924883918"><a name="zh-cn_topic_0000001173164707_p371924883918"></a><a name="zh-cn_topic_0000001173164707_p371924883918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1345116461512"><a name="zh-cn_topic_0000001173164707_p1345116461512"></a><a name="zh-cn_topic_0000001173164707_p1345116461512"></a>需要绘制的文本内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row187191548183919"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p13719204810398"><a name="zh-cn_topic_0000001173164707_p13719204810398"></a><a name="zh-cn_topic_0000001173164707_p13719204810398"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1371912484399"><a name="zh-cn_topic_0000001173164707_p1371912484399"></a><a name="zh-cn_topic_0000001173164707_p1371912484399"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p245110469119"><a name="zh-cn_topic_0000001173164707_p245110469119"></a><a name="zh-cn_topic_0000001173164707_p245110469119"></a>需要绘制的文本的左下角x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row5719114803911"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p671984814397"><a name="zh-cn_topic_0000001173164707_p671984814397"></a><a name="zh-cn_topic_0000001173164707_p671984814397"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p37192048113917"><a name="zh-cn_topic_0000001173164707_p37192048113917"></a><a name="zh-cn_topic_0000001173164707_p37192048113917"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p245114610113"><a name="zh-cn_topic_0000001173164707_p245114610113"></a><a name="zh-cn_topic_0000001173164707_p245114610113"></a>需要绘制的文本的左下角y坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.font = '25px sans-serif';
    ctx.strokeText("Hello World!", 20, 60);
    ```

    ![](figures/zh-cn_image_0000001127125156.png)


## measureText\(\)<a name="zh-cn_topic_0000001173164707_section378313153588"></a>

该方法返回一个文本测算的对象，通过该对象可以获取指定文本的宽度值。

-   参数

    <a name="zh-cn_topic_0000001173164707_table9108632184010"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1412483234017"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p14124183212408"><a name="zh-cn_topic_0000001173164707_p14124183212408"></a><a name="zh-cn_topic_0000001173164707_p14124183212408"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p141241328404"><a name="zh-cn_topic_0000001173164707_p141241328404"></a><a name="zh-cn_topic_0000001173164707_p141241328404"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p15124632194011"><a name="zh-cn_topic_0000001173164707_p15124632194011"></a><a name="zh-cn_topic_0000001173164707_p15124632194011"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row2124153244019"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p51241332134014"><a name="zh-cn_topic_0000001173164707_p51241332134014"></a><a name="zh-cn_topic_0000001173164707_p51241332134014"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p4124232134013"><a name="zh-cn_topic_0000001173164707_p4124232134013"></a><a name="zh-cn_topic_0000001173164707_p4124232134013"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p412413244010"><a name="zh-cn_topic_0000001173164707_p412413244010"></a><a name="zh-cn_topic_0000001173164707_p412413244010"></a>需要进行测量的文本。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="zh-cn_topic_0000001173164707_table7220542174013"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row423494215402"><th class="cellrowborder" valign="top" width="19.75%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p17234942104015"><a name="zh-cn_topic_0000001173164707_p17234942104015"></a><a name="zh-cn_topic_0000001173164707_p17234942104015"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.25%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p523424244012"><a name="zh-cn_topic_0000001173164707_p523424244012"></a><a name="zh-cn_topic_0000001173164707_p523424244012"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row112341042174013"><td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p82348423405"><a name="zh-cn_topic_0000001173164707_p82348423405"></a><a name="zh-cn_topic_0000001173164707_p82348423405"></a>TextMetrics</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.25%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p0234134218407"><a name="zh-cn_topic_0000001173164707_p0234134218407"></a><a name="zh-cn_topic_0000001173164707_p0234134218407"></a>包含指定字体的宽度，该宽度可以通过TextMetrics.width来获取。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    ctx.font = '25px sans-serif';
    var txt = 'Hello World';
    ctx.fillText("width:" + ctx.measureText(txt).width, 20, 60);
    ctx.fillText(txt, 20, 110);
    ```

    ![](figures/zh-cn_image_0000001127284960.png)


## lineWidth<a name="zh-cn_topic_0000001173164707_section652391716583"></a>

指定绘制线条的宽度值。

-   参数

    <a name="zh-cn_topic_0000001173164707_table17891539144119"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1809639144111"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1180913399418"><a name="zh-cn_topic_0000001173164707_p1180913399418"></a><a name="zh-cn_topic_0000001173164707_p1180913399418"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p480923915415"><a name="zh-cn_topic_0000001173164707_p480923915415"></a><a name="zh-cn_topic_0000001173164707_p480923915415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p580983913417"><a name="zh-cn_topic_0000001173164707_p580983913417"></a><a name="zh-cn_topic_0000001173164707_p580983913417"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row380920398414"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p180913920418"><a name="zh-cn_topic_0000001173164707_p180913920418"></a><a name="zh-cn_topic_0000001173164707_p180913920418"></a>lineWidth</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p19809203918412"><a name="zh-cn_topic_0000001173164707_p19809203918412"></a><a name="zh-cn_topic_0000001173164707_p19809203918412"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p10809183919414"><a name="zh-cn_topic_0000001173164707_p10809183919414"></a><a name="zh-cn_topic_0000001173164707_p10809183919414"></a>设置绘制线条的宽度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.lineWidth = 5;
    ctx.strokeRect(25, 25, 85, 105);
    ```

    ![](figures/zh-cn_image_0000001127125166.png)


## strokeStyle<a name="zh-cn_topic_0000001173164707_section1191517562337"></a>

设置描边的颜色。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1534725211489"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1536918529482"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p18369145254815"><a name="zh-cn_topic_0000001173164707_p18369145254815"></a><a name="zh-cn_topic_0000001173164707_p18369145254815"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p173696523483"><a name="zh-cn_topic_0000001173164707_p173696523483"></a><a name="zh-cn_topic_0000001173164707_p173696523483"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p936975274812"><a name="zh-cn_topic_0000001173164707_p936975274812"></a><a name="zh-cn_topic_0000001173164707_p936975274812"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row20369155219485"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p13369152194810"><a name="zh-cn_topic_0000001173164707_p13369152194810"></a><a name="zh-cn_topic_0000001173164707_p13369152194810"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p236911525481"><a name="zh-cn_topic_0000001173164707_p236911525481"></a><a name="zh-cn_topic_0000001173164707_p236911525481"></a>&lt;color&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p133695524481"><a name="zh-cn_topic_0000001173164707_p133695524481"></a><a name="zh-cn_topic_0000001173164707_p133695524481"></a>指定描边使用的颜色。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row6369175274810"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p136985218484"><a name="zh-cn_topic_0000001173164707_p136985218484"></a><a name="zh-cn_topic_0000001173164707_p136985218484"></a>gradient</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p43691152174819"><a name="zh-cn_topic_0000001173164707_p43691152174819"></a><a name="zh-cn_topic_0000001173164707_p43691152174819"></a>CanvasGradient</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p143696525482"><a name="zh-cn_topic_0000001173164707_p143696525482"></a><a name="zh-cn_topic_0000001173164707_p143696525482"></a>通过createLinearGradient()方法创建。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row636925214814"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p936995210482"><a name="zh-cn_topic_0000001173164707_p936995210482"></a><a name="zh-cn_topic_0000001173164707_p936995210482"></a>pattern</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p836945224820"><a name="zh-cn_topic_0000001173164707_p836945224820"></a><a name="zh-cn_topic_0000001173164707_p836945224820"></a>CanvasPattern</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p17369105219485"><a name="zh-cn_topic_0000001173164707_p17369105219485"></a><a name="zh-cn_topic_0000001173164707_p17369105219485"></a>通过createPattern()方法创建。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.lineWidth = 10;
    ctx.strokeStyle = '#0000ff';
    ctx.strokeRect(25, 25, 155, 105);
    ```

    ![](figures/zh-cn_image_0000001173324719.png)


## stroke\(\)<a name="zh-cn_topic_0000001173164707_section1071523411019"></a>

进行边框绘制操作。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.moveTo(25, 25);
    ctx.lineTo(25, 105);
    ctx.strokeStyle = 'rgb(0,0,255)';
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001173164819.png)


## beginPath\(\)<a name="zh-cn_topic_0000001173164707_section12670134392"></a>

创建一个新的绘制路径。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.beginPath();              
    ctx.lineWidth = '6';
    ctx.strokeStyle = '#0000ff';
    ctx.moveTo(15, 80); 
    ctx.lineTo(280, 160);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127125164.png)


## moveTo\(\)<a name="zh-cn_topic_0000001173164707_section16813157310"></a>

路径从当前点移动到指定点。

-   参数

    <a name="zh-cn_topic_0000001173164707_table6168163119523"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row718813118525"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1018812317521"><a name="zh-cn_topic_0000001173164707_p1018812317521"></a><a name="zh-cn_topic_0000001173164707_p1018812317521"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1718812319522"><a name="zh-cn_topic_0000001173164707_p1718812319522"></a><a name="zh-cn_topic_0000001173164707_p1718812319522"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1818893118526"><a name="zh-cn_topic_0000001173164707_p1818893118526"></a><a name="zh-cn_topic_0000001173164707_p1818893118526"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row918893175210"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p11188231135210"><a name="zh-cn_topic_0000001173164707_p11188231135210"></a><a name="zh-cn_topic_0000001173164707_p11188231135210"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p151888317527"><a name="zh-cn_topic_0000001173164707_p151888317527"></a><a name="zh-cn_topic_0000001173164707_p151888317527"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p2018811311525"><a name="zh-cn_topic_0000001173164707_p2018811311525"></a><a name="zh-cn_topic_0000001173164707_p2018811311525"></a>指定位置的x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row7188731185211"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p161881131155213"><a name="zh-cn_topic_0000001173164707_p161881131155213"></a><a name="zh-cn_topic_0000001173164707_p161881131155213"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1118863119528"><a name="zh-cn_topic_0000001173164707_p1118863119528"></a><a name="zh-cn_topic_0000001173164707_p1118863119528"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p121881431135219"><a name="zh-cn_topic_0000001173164707_p121881431135219"></a><a name="zh-cn_topic_0000001173164707_p121881431135219"></a>指定位置的y坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.moveTo(10, 10);
    ctx.lineTo(280, 160);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127125152.png)


## lineTo\(\)<a name="zh-cn_topic_0000001173164707_section4767915838"></a>

从当前点到指定点进行路径连接。

-   参数

    <a name="zh-cn_topic_0000001173164707_table05782010185317"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row115971910155315"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p10597310185318"><a name="zh-cn_topic_0000001173164707_p10597310185318"></a><a name="zh-cn_topic_0000001173164707_p10597310185318"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p659741010538"><a name="zh-cn_topic_0000001173164707_p659741010538"></a><a name="zh-cn_topic_0000001173164707_p659741010538"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p859731055315"><a name="zh-cn_topic_0000001173164707_p859731055315"></a><a name="zh-cn_topic_0000001173164707_p859731055315"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row65971610135310"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p135975108534"><a name="zh-cn_topic_0000001173164707_p135975108534"></a><a name="zh-cn_topic_0000001173164707_p135975108534"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1259751035317"><a name="zh-cn_topic_0000001173164707_p1259751035317"></a><a name="zh-cn_topic_0000001173164707_p1259751035317"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p6597161085317"><a name="zh-cn_topic_0000001173164707_p6597161085317"></a><a name="zh-cn_topic_0000001173164707_p6597161085317"></a>指定位置的x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row9597111045310"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p105977106537"><a name="zh-cn_topic_0000001173164707_p105977106537"></a><a name="zh-cn_topic_0000001173164707_p105977106537"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p7597110205313"><a name="zh-cn_topic_0000001173164707_p7597110205313"></a><a name="zh-cn_topic_0000001173164707_p7597110205313"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p175971010185313"><a name="zh-cn_topic_0000001173164707_p175971010185313"></a><a name="zh-cn_topic_0000001173164707_p175971010185313"></a>指定位置的y坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.moveTo(10, 10);
    ctx.lineTo(280, 160);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001173324711.png)


## closePath\(\)<a name="zh-cn_topic_0000001173164707_section86825473917"></a>

结束当前路径形成一个封闭路径。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.moveTo(30, 30);
    ctx.lineTo(110, 30);
    ctx.lineTo(70, 90);
    ctx.closePath();
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127284950.png)


## lineCap<a name="zh-cn_topic_0000001173164707_section6852133718410"></a>

指定线端点的样式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table370016264426"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row197237269420"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p172302664212"><a name="zh-cn_topic_0000001173164707_p172302664212"></a><a name="zh-cn_topic_0000001173164707_p172302664212"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p672392611421"><a name="zh-cn_topic_0000001173164707_p672392611421"></a><a name="zh-cn_topic_0000001173164707_p672392611421"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p18723142620426"><a name="zh-cn_topic_0000001173164707_p18723142620426"></a><a name="zh-cn_topic_0000001173164707_p18723142620426"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row4723142619429"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p172302620422"><a name="zh-cn_topic_0000001173164707_p172302620422"></a><a name="zh-cn_topic_0000001173164707_p172302620422"></a>lineCap</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p572313267429"><a name="zh-cn_topic_0000001173164707_p572313267429"></a><a name="zh-cn_topic_0000001173164707_p572313267429"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1772310269428"><a name="zh-cn_topic_0000001173164707_p1772310269428"></a><a name="zh-cn_topic_0000001173164707_p1772310269428"></a>线条的端点样式，可选值为：</p>
    <a name="zh-cn_topic_0000001173164707_ul9807121877"></a><a name="zh-cn_topic_0000001173164707_ul9807121877"></a><ul id="zh-cn_topic_0000001173164707_ul9807121877"><li>butt（默认）：线端点以方形结束。</li><li>round：线端点以圆形结束。</li><li>square：线端点以方形结束，该样式下会增加一个长度和线段厚度相同，宽度是线段厚度一半的矩形。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.lineWidth = 8;
    ctx.beginPath();
    ctx.lineCap = 'round';
    ctx.moveTo(30, 50);
    ctx.lineTo(220, 50);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127125144.png)


## lineJoin<a name="zh-cn_topic_0000001173164707_section395812401442"></a>

指定线段间相交的交点样式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table32162018433"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1825620104314"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1425122074313"><a name="zh-cn_topic_0000001173164707_p1425122074313"></a><a name="zh-cn_topic_0000001173164707_p1425122074313"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p425112004316"><a name="zh-cn_topic_0000001173164707_p425112004316"></a><a name="zh-cn_topic_0000001173164707_p425112004316"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p142515206438"><a name="zh-cn_topic_0000001173164707_p142515206438"></a><a name="zh-cn_topic_0000001173164707_p142515206438"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1251220154315"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1825132016431"><a name="zh-cn_topic_0000001173164707_p1825132016431"></a><a name="zh-cn_topic_0000001173164707_p1825132016431"></a>lineJoin</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p152562012436"><a name="zh-cn_topic_0000001173164707_p152562012436"></a><a name="zh-cn_topic_0000001173164707_p152562012436"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p125162019435"><a name="zh-cn_topic_0000001173164707_p125162019435"></a><a name="zh-cn_topic_0000001173164707_p125162019435"></a>线条的交点样式，可选值为：</p>
    <a name="zh-cn_topic_0000001173164707_ul1717215412215"></a><a name="zh-cn_topic_0000001173164707_ul1717215412215"></a><ul id="zh-cn_topic_0000001173164707_ul1717215412215"><li>round：在线段相连处绘制一个扇形，扇形的圆角半径是线段的宽度。</li><li>bevel：在线段相连处使用三角形为底填充， 每个部分矩形拐角独立。</li><li>miter（默认）：在相连部分的外边缘处进行延伸，使其相交于一点，形成一个菱形区域，该属性可以通过设置miterLimit属性展现效果。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.lineWidth = 8;
    ctx.lineJoin = 'miter';
    ctx.moveTo(30, 30);
    ctx.lineTo(120, 60);
    ctx.lineTo(30, 110);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127125140.png)


## miterLimit<a name="zh-cn_topic_0000001173164707_section429711421945"></a>

设置斜接面限制值，该值指定了线条相交处内角和外角的距离。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1097514385448"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row20997538104419"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p699753818446"><a name="zh-cn_topic_0000001173164707_p699753818446"></a><a name="zh-cn_topic_0000001173164707_p699753818446"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p59971338204410"><a name="zh-cn_topic_0000001173164707_p59971338204410"></a><a name="zh-cn_topic_0000001173164707_p59971338204410"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p119970385446"><a name="zh-cn_topic_0000001173164707_p119970385446"></a><a name="zh-cn_topic_0000001173164707_p119970385446"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1599711383441"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p13997203818448"><a name="zh-cn_topic_0000001173164707_p13997203818448"></a><a name="zh-cn_topic_0000001173164707_p13997203818448"></a>miterLimit</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1099773884410"><a name="zh-cn_topic_0000001173164707_p1099773884410"></a><a name="zh-cn_topic_0000001173164707_p1099773884410"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1799711382448"><a name="zh-cn_topic_0000001173164707_p1799711382448"></a><a name="zh-cn_topic_0000001173164707_p1799711382448"></a>斜接面限制值，该属性默认值为10。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.lineWidth = 8;
    ctx.lineJoin = 'miter';
    ctx.miterLimit = 3;
    ctx.moveTo(30, 30);
    ctx.lineTo(60, 35);
    ctx.lineTo(30, 37);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127284966.png)


## font<a name="zh-cn_topic_0000001173164707_section17597332121110"></a>

设置文本绘制中的字体样式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table0971429451"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row71163425451"><th class="cellrowborder" valign="top" width="10.525252525252524%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p20116144294520"><a name="zh-cn_topic_0000001173164707_p20116144294520"></a><a name="zh-cn_topic_0000001173164707_p20116144294520"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.131313131313131%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p6116114214454"><a name="zh-cn_topic_0000001173164707_p6116114214454"></a><a name="zh-cn_topic_0000001173164707_p6116114214454"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.34343434343435%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p181162042194519"><a name="zh-cn_topic_0000001173164707_p181162042194519"></a><a name="zh-cn_topic_0000001173164707_p181162042194519"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row21171642124516"><td class="cellrowborder" valign="top" width="10.525252525252524%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p15117642164510"><a name="zh-cn_topic_0000001173164707_p15117642164510"></a><a name="zh-cn_topic_0000001173164707_p15117642164510"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.131313131313131%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p8117742114515"><a name="zh-cn_topic_0000001173164707_p8117742114515"></a><a name="zh-cn_topic_0000001173164707_p8117742114515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.34343434343435%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1711724219453"><a name="zh-cn_topic_0000001173164707_p1711724219453"></a><a name="zh-cn_topic_0000001173164707_p1711724219453"></a>字体样式支持：sans-serif, serif, monospace，<span id="zh-cn_topic_0000001173164707_ph065925143115"><a name="zh-cn_topic_0000001173164707_ph065925143115"></a><a name="zh-cn_topic_0000001173164707_ph065925143115"></a>该属性默认值为14px sans-serif</span>。</p>
    <p id="zh-cn_topic_0000001173164707_p436195718191"><a name="zh-cn_topic_0000001173164707_p436195718191"></a><a name="zh-cn_topic_0000001173164707_p436195718191"></a>语法：ctx.font="font-style font-weight font-size font-family"<sup id="zh-cn_topic_0000001173164707_sup17486202715112"><a name="zh-cn_topic_0000001173164707_sup17486202715112"></a><a name="zh-cn_topic_0000001173164707_sup17486202715112"></a><span>5+</span></sup></p>
    <p id="zh-cn_topic_0000001173164707_p152526210221"><a name="zh-cn_topic_0000001173164707_p152526210221"></a><a name="zh-cn_topic_0000001173164707_p152526210221"></a>默认值："normal normal 14px sans-serif"</p>
    <a name="zh-cn_topic_0000001173164707_ul1984020379012"></a><a name="zh-cn_topic_0000001173164707_ul1984020379012"></a><ul id="zh-cn_topic_0000001173164707_ul1984020379012"><li>font-style(可选)，用于指定字体样式，支持如下几种样式：normal, italic。</li><li>font-weight(可选)，用于指定字体的粗细，支持如下几种类型：normal, bold, bolder, lighter, 100, 200, 300, 400, 500, 600, 700, 800, 900。</li><li>font-size(可选)，指定字号和行高，单位只支持px，默认值14px。</li><li>font-family(可选)，指定字体系列，支持如下几种类型：sans-serif, serif, monospace。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.font = '30px sans-serif';
    ctx.fillText("Hello World", 20, 60);
    ```

    ![](figures/zh-cn_image_0000001173324725.png)


## textAlign<a name="zh-cn_topic_0000001173164707_section15681153321114"></a>

设置文本绘制中的文本对齐方式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table73131824144612"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row532818249469"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p132816246468"><a name="zh-cn_topic_0000001173164707_p132816246468"></a><a name="zh-cn_topic_0000001173164707_p132816246468"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p532882424617"><a name="zh-cn_topic_0000001173164707_p532882424617"></a><a name="zh-cn_topic_0000001173164707_p532882424617"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p15328122415465"><a name="zh-cn_topic_0000001173164707_p15328122415465"></a><a name="zh-cn_topic_0000001173164707_p15328122415465"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row103286247461"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p132917244468"><a name="zh-cn_topic_0000001173164707_p132917244468"></a><a name="zh-cn_topic_0000001173164707_p132917244468"></a>align</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p123296247468"><a name="zh-cn_topic_0000001173164707_p123296247468"></a><a name="zh-cn_topic_0000001173164707_p123296247468"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p6170185410516"><a name="zh-cn_topic_0000001173164707_p6170185410516"></a><a name="zh-cn_topic_0000001173164707_p6170185410516"></a>可选值为：</p>
    <a name="zh-cn_topic_0000001173164707_ul12274577810"></a><a name="zh-cn_topic_0000001173164707_ul12274577810"></a><ul id="zh-cn_topic_0000001173164707_ul12274577810"><li>left（默认）：文本左对齐。</li><li>right：文本右对齐。</li><li>center：文本居中对齐。</li><li>start：文本对齐界线开始的地方。</li><li>end：文本对齐接线结束的地方。</li></ul>
    <div class="note" id="zh-cn_topic_0000001173164707_note1344535811710"><a name="zh-cn_topic_0000001173164707_note1344535811710"></a><a name="zh-cn_topic_0000001173164707_note1344535811710"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173164707_p1854535417539"><a name="zh-cn_topic_0000001173164707_p1854535417539"></a><a name="zh-cn_topic_0000001173164707_p1854535417539"></a>ltr布局模式下start和left一致，rtl布局模式下start和right一致&middot;。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.strokeStyle = '#0000ff';
    ctx.moveTo(140, 10);
    ctx.lineTo(140, 160);
    ctx.stroke();
    
    ctx.font = '18px sans-serif';    
    
    // Show the different textAlign values
    ctx.textAlign = 'start';      
    ctx.fillText('textAlign=start', 140, 60);        
    ctx.textAlign = 'end';      
    ctx.fillText('textAlign=end', 140, 80);  
    ctx.textAlign = 'left';      
    ctx.fillText('textAlign=left', 140, 100);
    ctx.textAlign = 'center';     
    ctx.fillText('textAlign=center',140, 120);              
    ctx.textAlign = 'right';      
    ctx.fillText('textAlign=right',140, 140);
    ```

    ![](figures/zh-cn_image_0000001173164795.png)


## textBaseline<a name="zh-cn_topic_0000001173164707_section77981136141111"></a>

设置文本绘制中的水平对齐方式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table7291181034711"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row20362910144715"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p143621010174717"><a name="zh-cn_topic_0000001173164707_p143621010174717"></a><a name="zh-cn_topic_0000001173164707_p143621010174717"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.939393939393941%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1336201014716"><a name="zh-cn_topic_0000001173164707_p1336201014716"></a><a name="zh-cn_topic_0000001173164707_p1336201014716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.727272727272734%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p18362310124718"><a name="zh-cn_topic_0000001173164707_p18362310124718"></a><a name="zh-cn_topic_0000001173164707_p18362310124718"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row11362141010475"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p163621110144715"><a name="zh-cn_topic_0000001173164707_p163621110144715"></a><a name="zh-cn_topic_0000001173164707_p163621110144715"></a>textBaseline</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.939393939393941%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p183621610104715"><a name="zh-cn_topic_0000001173164707_p183621610104715"></a><a name="zh-cn_topic_0000001173164707_p183621610104715"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.727272727272734%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p711415819554"><a name="zh-cn_topic_0000001173164707_p711415819554"></a><a name="zh-cn_topic_0000001173164707_p711415819554"></a>可选值为：</p>
    <a name="zh-cn_topic_0000001173164707_ul155261019389"></a><a name="zh-cn_topic_0000001173164707_ul155261019389"></a><ul id="zh-cn_topic_0000001173164707_ul155261019389"><li>alphabetic（默认）：文本基线是标准的字母基线。</li><li>top：文本基线在文本块的顶部。</li><li>hanging：文本基线是悬挂基线。</li><li>middle：文本基线在文本块的中间。</li><li>ideographic：文字基线是表意字基线；如果字符本身超出了alphabetic 基线，那么ideograhpic基线位置在字符本身的底部。</li><li>bottom：文本基线在文本块的底部。 与 ideographic 基线的区别在于 ideographic 基线不需要考虑下行字母。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.strokeStyle = '#0000ff';
    ctx.moveTo(0, 120);
    ctx.lineTo(400, 120);
    ctx.stroke();
    
    ctx.font = '20px sans-serif';
    
    ctx.textBaseline = 'top'; 
    ctx.fillText('Top', 10, 120); 
    ctx.textBaseline = 'bottom'; 
    ctx.fillText('Bottom', 55, 120); 
    ctx.textBaseline = 'middle'; 
    ctx.fillText('Middle', 125, 120); 
    ctx.textBaseline = 'alphabetic'; 
    ctx.fillText('Alphabetic', 195, 120); 
    ctx.textBaseline = 'hanging'; 
    ctx.fillText('Hanging', 295, 120);
    ```

    ![](figures/zh-cn_image_0000001173324713.png)


## createPattern\(\)<a name="zh-cn_topic_0000001173164707_section1034582183919"></a>

通过指定图像和重复方式创建图片填充的模板。

-   参数

    <a name="zh-cn_topic_0000001173164707_table10856104714495"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row6877547164915"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p087713474499"><a name="zh-cn_topic_0000001173164707_p087713474499"></a><a name="zh-cn_topic_0000001173164707_p087713474499"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1877147104920"><a name="zh-cn_topic_0000001173164707_p1877147104920"></a><a name="zh-cn_topic_0000001173164707_p1877147104920"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p17877144714910"><a name="zh-cn_topic_0000001173164707_p17877144714910"></a><a name="zh-cn_topic_0000001173164707_p17877144714910"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1387716471496"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p16877134713496"><a name="zh-cn_topic_0000001173164707_p16877134713496"></a><a name="zh-cn_topic_0000001173164707_p16877134713496"></a>image</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p12877174784912"><a name="zh-cn_topic_0000001173164707_p12877174784912"></a><a name="zh-cn_topic_0000001173164707_p12877174784912"></a>Image</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p12877164716490"><a name="zh-cn_topic_0000001173164707_p12877164716490"></a><a name="zh-cn_topic_0000001173164707_p12877164716490"></a>图源对象，具体参考<a href="js-components-canvas-image.md#ZH-CN_TOPIC_0000001164290722">Image对象</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1887711479493"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p787764720494"><a name="zh-cn_topic_0000001173164707_p787764720494"></a><a name="zh-cn_topic_0000001173164707_p787764720494"></a>repetition</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p387724714916"><a name="zh-cn_topic_0000001173164707_p387724714916"></a><a name="zh-cn_topic_0000001173164707_p387724714916"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1787724716495"><a name="zh-cn_topic_0000001173164707_p1787724716495"></a><a name="zh-cn_topic_0000001173164707_p1787724716495"></a>设置图像重复的方式，取值为：'repeat'、'repeat-x'、 'repeat-y'、'no-repeat'。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="zh-cn_topic_0000001173164707_table1693355133112"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row49339514317"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p17933145116314"><a name="zh-cn_topic_0000001173164707_p17933145116314"></a><a name="zh-cn_topic_0000001173164707_p17933145116314"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p15933155113310"><a name="zh-cn_topic_0000001173164707_p15933155113310"></a><a name="zh-cn_topic_0000001173164707_p15933155113310"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row10934951103110"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p11934145123116"><a name="zh-cn_topic_0000001173164707_p11934145123116"></a><a name="zh-cn_topic_0000001173164707_p11934145123116"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p16934351123117"><a name="zh-cn_topic_0000001173164707_p16934351123117"></a><a name="zh-cn_topic_0000001173164707_p16934351123117"></a>指定图像填充的Pattern对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    var pat = ctx.createPattern(img, 'repeat');
    ctx.fillStyle = pat;
    ctx.fillRect(0, 0, 20, 20);
    ```

    ![](figures/zh-cn_image_0000001173164829.png)


## bezierCurveTo\(\)<a name="zh-cn_topic_0000001173164707_section450521614318"></a>

创建三次贝赛尔曲线的路径。

-   参数

    <a name="zh-cn_topic_0000001173164707_table20386105825314"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row15411458165315"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1411155895315"><a name="zh-cn_topic_0000001173164707_p1411155895315"></a><a name="zh-cn_topic_0000001173164707_p1411155895315"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1541119580533"><a name="zh-cn_topic_0000001173164707_p1541119580533"></a><a name="zh-cn_topic_0000001173164707_p1541119580533"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p84112058145319"><a name="zh-cn_topic_0000001173164707_p84112058145319"></a><a name="zh-cn_topic_0000001173164707_p84112058145319"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row194112586539"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p23609395194"><a name="zh-cn_topic_0000001173164707_p23609395194"></a><a name="zh-cn_topic_0000001173164707_p23609395194"></a>cp1x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p173603394190"><a name="zh-cn_topic_0000001173164707_p173603394190"></a><a name="zh-cn_topic_0000001173164707_p173603394190"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p18360203981915"><a name="zh-cn_topic_0000001173164707_p18360203981915"></a><a name="zh-cn_topic_0000001173164707_p18360203981915"></a>第一个贝塞尔参数的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row141135810535"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p336023910194"><a name="zh-cn_topic_0000001173164707_p336023910194"></a><a name="zh-cn_topic_0000001173164707_p336023910194"></a>cp1y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p20360173918194"><a name="zh-cn_topic_0000001173164707_p20360173918194"></a><a name="zh-cn_topic_0000001173164707_p20360173918194"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p13605397190"><a name="zh-cn_topic_0000001173164707_p13605397190"></a><a name="zh-cn_topic_0000001173164707_p13605397190"></a>第一个贝塞尔参数的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row164111358105315"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p17361123981919"><a name="zh-cn_topic_0000001173164707_p17361123981919"></a><a name="zh-cn_topic_0000001173164707_p17361123981919"></a>cp2x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p5361173901917"><a name="zh-cn_topic_0000001173164707_p5361173901917"></a><a name="zh-cn_topic_0000001173164707_p5361173901917"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p736183918197"><a name="zh-cn_topic_0000001173164707_p736183918197"></a><a name="zh-cn_topic_0000001173164707_p736183918197"></a>第二个贝塞尔参数的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row185982415541"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p5361113911199"><a name="zh-cn_topic_0000001173164707_p5361113911199"></a><a name="zh-cn_topic_0000001173164707_p5361113911199"></a>cp2y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p15361139171916"><a name="zh-cn_topic_0000001173164707_p15361139171916"></a><a name="zh-cn_topic_0000001173164707_p15361139171916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p23611039151912"><a name="zh-cn_topic_0000001173164707_p23611039151912"></a><a name="zh-cn_topic_0000001173164707_p23611039151912"></a>第二个贝塞尔参数的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row826242931913"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p17361143918198"><a name="zh-cn_topic_0000001173164707_p17361143918198"></a><a name="zh-cn_topic_0000001173164707_p17361143918198"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p173611539131920"><a name="zh-cn_topic_0000001173164707_p173611539131920"></a><a name="zh-cn_topic_0000001173164707_p173611539131920"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p10361339111918"><a name="zh-cn_topic_0000001173164707_p10361339111918"></a><a name="zh-cn_topic_0000001173164707_p10361339111918"></a>路径结束时的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1045602931913"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p14361193916194"><a name="zh-cn_topic_0000001173164707_p14361193916194"></a><a name="zh-cn_topic_0000001173164707_p14361193916194"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p23612039131914"><a name="zh-cn_topic_0000001173164707_p23612039131914"></a><a name="zh-cn_topic_0000001173164707_p23612039131914"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p183611739201916"><a name="zh-cn_topic_0000001173164707_p183611739201916"></a><a name="zh-cn_topic_0000001173164707_p183611739201916"></a>路径结束时的y坐标值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.moveTo(10, 10);
    ctx.bezierCurveTo(20, 100, 200, 100, 200, 20);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001152610854.png)


## quadraticCurveTo\(\)<a name="zh-cn_topic_0000001173164707_section12938183173"></a>

创建二次贝赛尔曲线的路径。

-   参数

    <a name="zh-cn_topic_0000001173164707_table109941430581"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1499443014812"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p179941301485"><a name="zh-cn_topic_0000001173164707_p179941301485"></a><a name="zh-cn_topic_0000001173164707_p179941301485"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p09941330382"><a name="zh-cn_topic_0000001173164707_p09941330382"></a><a name="zh-cn_topic_0000001173164707_p09941330382"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p499411309812"><a name="zh-cn_topic_0000001173164707_p499411309812"></a><a name="zh-cn_topic_0000001173164707_p499411309812"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row189942307819"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1541115588531"><a name="zh-cn_topic_0000001173164707_p1541115588531"></a><a name="zh-cn_topic_0000001173164707_p1541115588531"></a>cpx</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p5411158115317"><a name="zh-cn_topic_0000001173164707_p5411158115317"></a><a name="zh-cn_topic_0000001173164707_p5411158115317"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p14111558175312"><a name="zh-cn_topic_0000001173164707_p14111558175312"></a><a name="zh-cn_topic_0000001173164707_p14111558175312"></a>贝塞尔参数的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row179951630484"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p641135820539"><a name="zh-cn_topic_0000001173164707_p641135820539"></a><a name="zh-cn_topic_0000001173164707_p641135820539"></a>cpy</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1441111584532"><a name="zh-cn_topic_0000001173164707_p1441111584532"></a><a name="zh-cn_topic_0000001173164707_p1441111584532"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p44114580539"><a name="zh-cn_topic_0000001173164707_p44114580539"></a><a name="zh-cn_topic_0000001173164707_p44114580539"></a>贝塞尔参数的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row13995183015811"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p44111958135320"><a name="zh-cn_topic_0000001173164707_p44111958135320"></a><a name="zh-cn_topic_0000001173164707_p44111958135320"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p14111358115313"><a name="zh-cn_topic_0000001173164707_p14111358115313"></a><a name="zh-cn_topic_0000001173164707_p14111358115313"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p2411115835318"><a name="zh-cn_topic_0000001173164707_p2411115835318"></a><a name="zh-cn_topic_0000001173164707_p2411115835318"></a>路径结束时的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row149953301482"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p173571755546"><a name="zh-cn_topic_0000001173164707_p173571755546"></a><a name="zh-cn_topic_0000001173164707_p173571755546"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p43588511540"><a name="zh-cn_topic_0000001173164707_p43588511540"></a><a name="zh-cn_topic_0000001173164707_p43588511540"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1635875105417"><a name="zh-cn_topic_0000001173164707_p1635875105417"></a><a name="zh-cn_topic_0000001173164707_p1635875105417"></a>路径结束时的y坐标值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.moveTo(20, 20);
    ctx.quadraticCurveTo(100, 100, 200, 20);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001173324723.png)


## arc\(\)<a name="zh-cn_topic_0000001173164707_section102329511716"></a>

绘制弧线路径。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1924242125518"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1127315218557"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p227311285518"><a name="zh-cn_topic_0000001173164707_p227311285518"></a><a name="zh-cn_topic_0000001173164707_p227311285518"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p162737213553"><a name="zh-cn_topic_0000001173164707_p162737213553"></a><a name="zh-cn_topic_0000001173164707_p162737213553"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p11273123553"><a name="zh-cn_topic_0000001173164707_p11273123553"></a><a name="zh-cn_topic_0000001173164707_p11273123553"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1527314215554"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p82737245518"><a name="zh-cn_topic_0000001173164707_p82737245518"></a><a name="zh-cn_topic_0000001173164707_p82737245518"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p92733211553"><a name="zh-cn_topic_0000001173164707_p92733211553"></a><a name="zh-cn_topic_0000001173164707_p92733211553"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p5273423558"><a name="zh-cn_topic_0000001173164707_p5273423558"></a><a name="zh-cn_topic_0000001173164707_p5273423558"></a>弧线圆心的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row132733255519"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1527352175511"><a name="zh-cn_topic_0000001173164707_p1527352175511"></a><a name="zh-cn_topic_0000001173164707_p1527352175511"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p192731220550"><a name="zh-cn_topic_0000001173164707_p192731220550"></a><a name="zh-cn_topic_0000001173164707_p192731220550"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p527320245513"><a name="zh-cn_topic_0000001173164707_p527320245513"></a><a name="zh-cn_topic_0000001173164707_p527320245513"></a>弧线圆心的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row82734214551"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p42737218552"><a name="zh-cn_topic_0000001173164707_p42737218552"></a><a name="zh-cn_topic_0000001173164707_p42737218552"></a>radius</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1827312295511"><a name="zh-cn_topic_0000001173164707_p1827312295511"></a><a name="zh-cn_topic_0000001173164707_p1827312295511"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1827315217559"><a name="zh-cn_topic_0000001173164707_p1827315217559"></a><a name="zh-cn_topic_0000001173164707_p1827315217559"></a>弧线的圆半径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row132731724552"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1727310213555"><a name="zh-cn_topic_0000001173164707_p1727310213555"></a><a name="zh-cn_topic_0000001173164707_p1727310213555"></a>startAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p112731628552"><a name="zh-cn_topic_0000001173164707_p112731628552"></a><a name="zh-cn_topic_0000001173164707_p112731628552"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p13273132135514"><a name="zh-cn_topic_0000001173164707_p13273132135514"></a><a name="zh-cn_topic_0000001173164707_p13273132135514"></a>弧线的起始弧度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row4273728559"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p122730214554"><a name="zh-cn_topic_0000001173164707_p122730214554"></a><a name="zh-cn_topic_0000001173164707_p122730214554"></a>endAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p162747217557"><a name="zh-cn_topic_0000001173164707_p162747217557"></a><a name="zh-cn_topic_0000001173164707_p162747217557"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1274112145513"><a name="zh-cn_topic_0000001173164707_p1274112145513"></a><a name="zh-cn_topic_0000001173164707_p1274112145513"></a>弧线的终止弧度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1227416285512"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p92747265520"><a name="zh-cn_topic_0000001173164707_p92747265520"></a><a name="zh-cn_topic_0000001173164707_p92747265520"></a>anticlockwise</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p327410216554"><a name="zh-cn_topic_0000001173164707_p327410216554"></a><a name="zh-cn_topic_0000001173164707_p327410216554"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p102742026555"><a name="zh-cn_topic_0000001173164707_p102742026555"></a><a name="zh-cn_topic_0000001173164707_p102742026555"></a>是否逆时针绘制圆弧。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.arc(100, 75, 50, 0, 6.28);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001127125154.png)


## arcTo\(\)<a name="zh-cn_topic_0000001173164707_section3172156571"></a>

依据圆弧经过的点和圆弧半径创建圆弧路径。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1320614135617"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1423481125614"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p723412110565"><a name="zh-cn_topic_0000001173164707_p723412110565"></a><a name="zh-cn_topic_0000001173164707_p723412110565"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p123411135619"><a name="zh-cn_topic_0000001173164707_p123411135619"></a><a name="zh-cn_topic_0000001173164707_p123411135619"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p82341216569"><a name="zh-cn_topic_0000001173164707_p82341216569"></a><a name="zh-cn_topic_0000001173164707_p82341216569"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row523414155610"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1423461105617"><a name="zh-cn_topic_0000001173164707_p1423461105617"></a><a name="zh-cn_topic_0000001173164707_p1423461105617"></a>x1</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p12347118565"><a name="zh-cn_topic_0000001173164707_p12347118565"></a><a name="zh-cn_topic_0000001173164707_p12347118565"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p18234618568"><a name="zh-cn_topic_0000001173164707_p18234618568"></a><a name="zh-cn_topic_0000001173164707_p18234618568"></a>圆弧经过的第一个点的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row15234515560"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p0234131195618"><a name="zh-cn_topic_0000001173164707_p0234131195618"></a><a name="zh-cn_topic_0000001173164707_p0234131195618"></a>y1</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1223418112569"><a name="zh-cn_topic_0000001173164707_p1223418112569"></a><a name="zh-cn_topic_0000001173164707_p1223418112569"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p2023411135618"><a name="zh-cn_topic_0000001173164707_p2023411135618"></a><a name="zh-cn_topic_0000001173164707_p2023411135618"></a>圆弧经过的第一个点的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row823411114560"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1123513125614"><a name="zh-cn_topic_0000001173164707_p1123513125614"></a><a name="zh-cn_topic_0000001173164707_p1123513125614"></a>x2</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p112351415564"><a name="zh-cn_topic_0000001173164707_p112351415564"></a><a name="zh-cn_topic_0000001173164707_p112351415564"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1923513165616"><a name="zh-cn_topic_0000001173164707_p1923513165616"></a><a name="zh-cn_topic_0000001173164707_p1923513165616"></a>圆弧经过的第二个点的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1923518155616"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1623511155613"><a name="zh-cn_topic_0000001173164707_p1623511155613"></a><a name="zh-cn_topic_0000001173164707_p1623511155613"></a>y2</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p13235113569"><a name="zh-cn_topic_0000001173164707_p13235113569"></a><a name="zh-cn_topic_0000001173164707_p13235113569"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p32351913568"><a name="zh-cn_topic_0000001173164707_p32351913568"></a><a name="zh-cn_topic_0000001173164707_p32351913568"></a>圆弧经过的第二个点的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row122350195613"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p32354116565"><a name="zh-cn_topic_0000001173164707_p32354116565"></a><a name="zh-cn_topic_0000001173164707_p32354116565"></a>radius</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p623561195612"><a name="zh-cn_topic_0000001173164707_p623561195612"></a><a name="zh-cn_topic_0000001173164707_p623561195612"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p42356185615"><a name="zh-cn_topic_0000001173164707_p42356185615"></a><a name="zh-cn_topic_0000001173164707_p42356185615"></a>圆弧的圆半径值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.moveTo(100, 20);
    ctx.arcTo(150, 20, 150, 70, 50); // Create an arc
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001173164807.png)


## ellipse\(\)<sup>6+</sup><a name="zh-cn_topic_0000001173164707_section918313239192"></a>

在规定的矩形区域绘制一个椭圆。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1918352314192"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row4184523111911"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p418492351918"><a name="zh-cn_topic_0000001173164707_p418492351918"></a><a name="zh-cn_topic_0000001173164707_p418492351918"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.34343434343434%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p17184172391915"><a name="zh-cn_topic_0000001173164707_p17184172391915"></a><a name="zh-cn_topic_0000001173164707_p17184172391915"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.323232323232325%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p11184523161913"><a name="zh-cn_topic_0000001173164707_p11184523161913"></a><a name="zh-cn_topic_0000001173164707_p11184523161913"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row71841423161917"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1018414236191"><a name="zh-cn_topic_0000001173164707_p1018414236191"></a><a name="zh-cn_topic_0000001173164707_p1018414236191"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p2184723201917"><a name="zh-cn_topic_0000001173164707_p2184723201917"></a><a name="zh-cn_topic_0000001173164707_p2184723201917"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p01841723151917"><a name="zh-cn_topic_0000001173164707_p01841723151917"></a><a name="zh-cn_topic_0000001173164707_p01841723151917"></a>椭圆圆心的x轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row171846239199"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p6185122311911"><a name="zh-cn_topic_0000001173164707_p6185122311911"></a><a name="zh-cn_topic_0000001173164707_p6185122311911"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1818582316192"><a name="zh-cn_topic_0000001173164707_p1818582316192"></a><a name="zh-cn_topic_0000001173164707_p1818582316192"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1353402619228"><a name="zh-cn_topic_0000001173164707_p1353402619228"></a><a name="zh-cn_topic_0000001173164707_p1353402619228"></a>椭圆圆心的y轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row151221733163013"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1112243316308"><a name="zh-cn_topic_0000001173164707_p1112243316308"></a><a name="zh-cn_topic_0000001173164707_p1112243316308"></a>radiusX</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p141221133193020"><a name="zh-cn_topic_0000001173164707_p141221133193020"></a><a name="zh-cn_topic_0000001173164707_p141221133193020"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p056816461311"><a name="zh-cn_topic_0000001173164707_p056816461311"></a><a name="zh-cn_topic_0000001173164707_p056816461311"></a>椭圆x轴的半径长度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1660574219308"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p126058426309"><a name="zh-cn_topic_0000001173164707_p126058426309"></a><a name="zh-cn_topic_0000001173164707_p126058426309"></a>radiusY</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p6605742183011"><a name="zh-cn_topic_0000001173164707_p6605742183011"></a><a name="zh-cn_topic_0000001173164707_p6605742183011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p31691408321"><a name="zh-cn_topic_0000001173164707_p31691408321"></a><a name="zh-cn_topic_0000001173164707_p31691408321"></a>椭圆y轴的半径长度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row2849135183011"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1984915356302"><a name="zh-cn_topic_0000001173164707_p1984915356302"></a><a name="zh-cn_topic_0000001173164707_p1984915356302"></a>rotation</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p11849193510302"><a name="zh-cn_topic_0000001173164707_p11849193510302"></a><a name="zh-cn_topic_0000001173164707_p11849193510302"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p5849103517308"><a name="zh-cn_topic_0000001173164707_p5849103517308"></a><a name="zh-cn_topic_0000001173164707_p5849103517308"></a>椭圆的旋转角度，单位为弧度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row3789194613307"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1278934610303"><a name="zh-cn_topic_0000001173164707_p1278934610303"></a><a name="zh-cn_topic_0000001173164707_p1278934610303"></a>startAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p19789164643015"><a name="zh-cn_topic_0000001173164707_p19789164643015"></a><a name="zh-cn_topic_0000001173164707_p19789164643015"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1588673153311"><a name="zh-cn_topic_0000001173164707_p1588673153311"></a><a name="zh-cn_topic_0000001173164707_p1588673153311"></a>椭圆绘制的起始点角度，以弧度表示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row181851723131918"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p20439192711202"><a name="zh-cn_topic_0000001173164707_p20439192711202"></a><a name="zh-cn_topic_0000001173164707_p20439192711202"></a>endAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1118512314194"><a name="zh-cn_topic_0000001173164707_p1118512314194"></a><a name="zh-cn_topic_0000001173164707_p1118512314194"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p101851623151913"><a name="zh-cn_topic_0000001173164707_p101851623151913"></a><a name="zh-cn_topic_0000001173164707_p101851623151913"></a>椭圆绘制的结束点角度，以弧度表示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row3185172371917"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p161851423121917"><a name="zh-cn_topic_0000001173164707_p161851423121917"></a><a name="zh-cn_topic_0000001173164707_p161851423121917"></a>anticlockwise</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.34343434343434%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1518512311915"><a name="zh-cn_topic_0000001173164707_p1518512311915"></a><a name="zh-cn_topic_0000001173164707_p1518512311915"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.323232323232325%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p11857237193"><a name="zh-cn_topic_0000001173164707_p11857237193"></a><a name="zh-cn_topic_0000001173164707_p11857237193"></a>是否以逆时针方向绘制椭圆，0为顺时针，1为逆时针。(可选参数，默认为0)</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.beginPath();
    ctx.ellipse(200, 200, 50, 100, Math.PI * 0.25, Math.PI * 0.5, Math.PI, 1);
    ctx.stroke();
    ```

    ![](figures/ellipse.png)


## rect\(\)<a name="zh-cn_topic_0000001173164707_section1351519304107"></a>

创建矩形路径。

-   参数

    <a name="zh-cn_topic_0000001173164707_table92131548185610"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row9238348185613"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p723854810561"><a name="zh-cn_topic_0000001173164707_p723854810561"></a><a name="zh-cn_topic_0000001173164707_p723854810561"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p2238144885615"><a name="zh-cn_topic_0000001173164707_p2238144885615"></a><a name="zh-cn_topic_0000001173164707_p2238144885615"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p223814486561"><a name="zh-cn_topic_0000001173164707_p223814486561"></a><a name="zh-cn_topic_0000001173164707_p223814486561"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row5238104813569"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1423864816566"><a name="zh-cn_topic_0000001173164707_p1423864816566"></a><a name="zh-cn_topic_0000001173164707_p1423864816566"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p3238194814560"><a name="zh-cn_topic_0000001173164707_p3238194814560"></a><a name="zh-cn_topic_0000001173164707_p3238194814560"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p9238204818566"><a name="zh-cn_topic_0000001173164707_p9238204818566"></a><a name="zh-cn_topic_0000001173164707_p9238204818566"></a>指定矩形的左上角x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1423884816562"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p132383488563"><a name="zh-cn_topic_0000001173164707_p132383488563"></a><a name="zh-cn_topic_0000001173164707_p132383488563"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p02395487560"><a name="zh-cn_topic_0000001173164707_p02395487560"></a><a name="zh-cn_topic_0000001173164707_p02395487560"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p523934819568"><a name="zh-cn_topic_0000001173164707_p523934819568"></a><a name="zh-cn_topic_0000001173164707_p523934819568"></a>指定矩形的左上角y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row723954815563"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p182391481565"><a name="zh-cn_topic_0000001173164707_p182391481565"></a><a name="zh-cn_topic_0000001173164707_p182391481565"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p142391648145610"><a name="zh-cn_topic_0000001173164707_p142391648145610"></a><a name="zh-cn_topic_0000001173164707_p142391648145610"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p523919486569"><a name="zh-cn_topic_0000001173164707_p523919486569"></a><a name="zh-cn_topic_0000001173164707_p523919486569"></a>指定矩形的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1723924885618"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1923934820561"><a name="zh-cn_topic_0000001173164707_p1923934820561"></a><a name="zh-cn_topic_0000001173164707_p1923934820561"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p13239448135615"><a name="zh-cn_topic_0000001173164707_p13239448135615"></a><a name="zh-cn_topic_0000001173164707_p13239448135615"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p523924819568"><a name="zh-cn_topic_0000001173164707_p523924819568"></a><a name="zh-cn_topic_0000001173164707_p523924819568"></a>指定矩形的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.rect(20, 20, 100, 100); // Create a 100*100 rectangle at (20, 20)
    ctx.stroke(); // Draw it
    ```

    ![](figures/zh-cn_image_0000001127125130.png)


## fill\(\)<a name="zh-cn_topic_0000001173164707_section14842031151015"></a>

对封闭路径进行填充。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.rect(20, 20, 100, 100); // Create a 100*100 rectangle at (20, 20)
    ctx.fill(); // Draw it in default setting
    ```

    ![](figures/zh-cn_image_0000001127284940.png)


## clip\(\)<a name="zh-cn_topic_0000001173164707_section1355171921416"></a>

设置当前路径为剪切路径。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.rect(0, 0, 200, 200);
    ctx.stroke();
    ctx.clip();
    // Draw red rectangle after clip
    ctx.fillStyle = "rgb(255,0,0)";
    ctx.fillRect(0, 0, 150, 150);
    ```

    ![](figures/zh-cn_image_0000001127284956.png)


## rotate\(\)<a name="zh-cn_topic_0000001173164707_section7682182091419"></a>

针对当前坐标轴进行顺时针旋转。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1670853610595"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row572823665918"><th class="cellrowborder" valign="top" width="17.22172217221722%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p57281836155917"><a name="zh-cn_topic_0000001173164707_p57281836155917"></a><a name="zh-cn_topic_0000001173164707_p57281836155917"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.5015501550155%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p207281636145914"><a name="zh-cn_topic_0000001173164707_p207281636145914"></a><a name="zh-cn_topic_0000001173164707_p207281636145914"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.27672767276727%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1472873645916"><a name="zh-cn_topic_0000001173164707_p1472873645916"></a><a name="zh-cn_topic_0000001173164707_p1472873645916"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row272813675911"><td class="cellrowborder" valign="top" width="17.22172217221722%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p7728113655914"><a name="zh-cn_topic_0000001173164707_p7728113655914"></a><a name="zh-cn_topic_0000001173164707_p7728113655914"></a>rotate</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.5015501550155%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1372863618596"><a name="zh-cn_topic_0000001173164707_p1372863618596"></a><a name="zh-cn_topic_0000001173164707_p1372863618596"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.27672767276727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p47285363596"><a name="zh-cn_topic_0000001173164707_p47285363596"></a><a name="zh-cn_topic_0000001173164707_p47285363596"></a>设置顺时针旋转的弧度值，可以通过Math.PI / 180将角度转换为弧度值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.rotate(45 * Math.PI / 180); // Rotate the rectangle 45 degrees
    ctx.fillRect(70, 20, 50, 50);
    ```

    ![](figures/zh-cn_image_0000001127125146.png)


## scale\(\)<a name="zh-cn_topic_0000001173164707_section157714218144"></a>

设置canvas画布的缩放变换属性，后续的绘制操作将按照缩放比例进行缩放。

-   参数

    <a name="zh-cn_topic_0000001173164707_table23481973415"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row9366771547"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p43665716410"><a name="zh-cn_topic_0000001173164707_p43665716410"></a><a name="zh-cn_topic_0000001173164707_p43665716410"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p173667718418"><a name="zh-cn_topic_0000001173164707_p173667718418"></a><a name="zh-cn_topic_0000001173164707_p173667718418"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p183661172419"><a name="zh-cn_topic_0000001173164707_p183661172419"></a><a name="zh-cn_topic_0000001173164707_p183661172419"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row33666717414"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p113661711419"><a name="zh-cn_topic_0000001173164707_p113661711419"></a><a name="zh-cn_topic_0000001173164707_p113661711419"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p33671879413"><a name="zh-cn_topic_0000001173164707_p33671879413"></a><a name="zh-cn_topic_0000001173164707_p33671879413"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p5367870415"><a name="zh-cn_topic_0000001173164707_p5367870415"></a><a name="zh-cn_topic_0000001173164707_p5367870415"></a>设置水平方向的缩放值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row13367271645"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1836717943"><a name="zh-cn_topic_0000001173164707_p1836717943"></a><a name="zh-cn_topic_0000001173164707_p1836717943"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p33671371347"><a name="zh-cn_topic_0000001173164707_p33671371347"></a><a name="zh-cn_topic_0000001173164707_p33671371347"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p203671878419"><a name="zh-cn_topic_0000001173164707_p203671878419"></a><a name="zh-cn_topic_0000001173164707_p203671878419"></a>设置垂直方向的缩放值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.strokeRect(10, 10, 25, 25);
    ctx.scale(2, 2);// Scale to 200%
    ctx.strokeRect(10, 10, 25, 25);
    ```

    ![](figures/zh-cn_image_0000001173164805.png)


## transform\(\)<a name="zh-cn_topic_0000001173164707_section1675964717570"></a>

transform\(\)方法对应一个变换矩阵，想对一个图形进行变化的时候，只要设置此变换矩阵相应的参数，对图形的各个定点的坐标分别乘以这个矩阵，就能得到新的定点的坐标。矩阵变换效果可叠加。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>变换后的坐标计算方式（x和y为变换前坐标，x'和y'为变换后坐标）：
>-   x' = scaleX \* x + skewY \* y + translateX
>-   y' = skewX \* x + scaleY \* y + translateY

-   参数

    <a name="zh-cn_topic_0000001173164707_table2760124718578"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row676054716572"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p47602476571"><a name="zh-cn_topic_0000001173164707_p47602476571"></a><a name="zh-cn_topic_0000001173164707_p47602476571"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p5760164710579"><a name="zh-cn_topic_0000001173164707_p5760164710579"></a><a name="zh-cn_topic_0000001173164707_p5760164710579"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p97601147105711"><a name="zh-cn_topic_0000001173164707_p97601147105711"></a><a name="zh-cn_topic_0000001173164707_p97601147105711"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row57601477578"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p197611471576"><a name="zh-cn_topic_0000001173164707_p197611471576"></a><a name="zh-cn_topic_0000001173164707_p197611471576"></a>scaleX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1576144725710"><a name="zh-cn_topic_0000001173164707_p1576144725710"></a><a name="zh-cn_topic_0000001173164707_p1576144725710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p17761647135713"><a name="zh-cn_topic_0000001173164707_p17761647135713"></a><a name="zh-cn_topic_0000001173164707_p17761647135713"></a>指定水平缩放值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row976184735711"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1761947175714"><a name="zh-cn_topic_0000001173164707_p1761947175714"></a><a name="zh-cn_topic_0000001173164707_p1761947175714"></a>skewX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p177611647125715"><a name="zh-cn_topic_0000001173164707_p177611647125715"></a><a name="zh-cn_topic_0000001173164707_p177611647125715"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p876244725717"><a name="zh-cn_topic_0000001173164707_p876244725717"></a><a name="zh-cn_topic_0000001173164707_p876244725717"></a>指定水平倾斜值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row5762847175716"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1776215478578"><a name="zh-cn_topic_0000001173164707_p1776215478578"></a><a name="zh-cn_topic_0000001173164707_p1776215478578"></a>skewY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p2762154745716"><a name="zh-cn_topic_0000001173164707_p2762154745716"></a><a name="zh-cn_topic_0000001173164707_p2762154745716"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p13762164795712"><a name="zh-cn_topic_0000001173164707_p13762164795712"></a><a name="zh-cn_topic_0000001173164707_p13762164795712"></a>指定垂直倾斜值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row876284716577"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1076254775718"><a name="zh-cn_topic_0000001173164707_p1076254775718"></a><a name="zh-cn_topic_0000001173164707_p1076254775718"></a>scaleY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p276210474575"><a name="zh-cn_topic_0000001173164707_p276210474575"></a><a name="zh-cn_topic_0000001173164707_p276210474575"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p776234716577"><a name="zh-cn_topic_0000001173164707_p776234716577"></a><a name="zh-cn_topic_0000001173164707_p776234716577"></a>指定垂直缩放值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row07621847165720"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p6762154795717"><a name="zh-cn_topic_0000001173164707_p6762154795717"></a><a name="zh-cn_topic_0000001173164707_p6762154795717"></a>translateX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p376234720578"><a name="zh-cn_topic_0000001173164707_p376234720578"></a><a name="zh-cn_topic_0000001173164707_p376234720578"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p3763114705715"><a name="zh-cn_topic_0000001173164707_p3763114705715"></a><a name="zh-cn_topic_0000001173164707_p3763114705715"></a>指定水平移动值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row8763104718572"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p97631647185712"><a name="zh-cn_topic_0000001173164707_p97631647185712"></a><a name="zh-cn_topic_0000001173164707_p97631647185712"></a>translateY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p18763194716579"><a name="zh-cn_topic_0000001173164707_p18763194716579"></a><a name="zh-cn_topic_0000001173164707_p18763194716579"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p15763847155713"><a name="zh-cn_topic_0000001173164707_p15763847155713"></a><a name="zh-cn_topic_0000001173164707_p15763847155713"></a>指定垂直移动值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillStyle = 'rgb(0,0,0)';
    ctx.fillRect(0, 0, 100, 100)
    ctx.transform(1, 0.5, -0.5, 1, 10, 10);
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(0, 0, 100, 100);
    ctx.transform(1, 0.5, -0.5, 1, 10, 10);
    ctx.fillStyle = 'rgb(0,0,255)';
    ctx.fillRect(0, 0, 100, 100);
    ```

    ![](figures/zh-cn_image_0000001173164809.png)


## setTransform\(\)<a name="zh-cn_topic_0000001173164707_section1439382216440"></a>

setTransfrom\(\)方法使用的参数和transform\(\)方法相同，但setTransform\(\)方法会重置现有的变换矩阵并创建新的变换矩阵。

-   参数

    <a name="zh-cn_topic_0000001173164707_table13369145118412"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row133954517420"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1039545113413"><a name="zh-cn_topic_0000001173164707_p1039545113413"></a><a name="zh-cn_topic_0000001173164707_p1039545113413"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1439516511649"><a name="zh-cn_topic_0000001173164707_p1439516511649"></a><a name="zh-cn_topic_0000001173164707_p1439516511649"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1639517511547"><a name="zh-cn_topic_0000001173164707_p1639517511547"></a><a name="zh-cn_topic_0000001173164707_p1639517511547"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row339510515415"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p43951951246"><a name="zh-cn_topic_0000001173164707_p43951951246"></a><a name="zh-cn_topic_0000001173164707_p43951951246"></a>scaleX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p93952511042"><a name="zh-cn_topic_0000001173164707_p93952511042"></a><a name="zh-cn_topic_0000001173164707_p93952511042"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p17552452132316"><a name="zh-cn_topic_0000001173164707_p17552452132316"></a><a name="zh-cn_topic_0000001173164707_p17552452132316"></a>指定水平缩放值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row63951511948"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p63957511243"><a name="zh-cn_topic_0000001173164707_p63957511243"></a><a name="zh-cn_topic_0000001173164707_p63957511243"></a>skewX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p93959515413"><a name="zh-cn_topic_0000001173164707_p93959515413"></a><a name="zh-cn_topic_0000001173164707_p93959515413"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p855205232313"><a name="zh-cn_topic_0000001173164707_p855205232313"></a><a name="zh-cn_topic_0000001173164707_p855205232313"></a>指定水平倾斜值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row16395351149"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p12395751249"><a name="zh-cn_topic_0000001173164707_p12395751249"></a><a name="zh-cn_topic_0000001173164707_p12395751249"></a>skewY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p20396165115411"><a name="zh-cn_topic_0000001173164707_p20396165115411"></a><a name="zh-cn_topic_0000001173164707_p20396165115411"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p3552852152318"><a name="zh-cn_topic_0000001173164707_p3552852152318"></a><a name="zh-cn_topic_0000001173164707_p3552852152318"></a>指定垂直倾斜值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row0396125117417"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p8396145114418"><a name="zh-cn_topic_0000001173164707_p8396145114418"></a><a name="zh-cn_topic_0000001173164707_p8396145114418"></a>scaleY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1239605116410"><a name="zh-cn_topic_0000001173164707_p1239605116410"></a><a name="zh-cn_topic_0000001173164707_p1239605116410"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p6552205292319"><a name="zh-cn_topic_0000001173164707_p6552205292319"></a><a name="zh-cn_topic_0000001173164707_p6552205292319"></a>指定垂直缩放值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row71371555047"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p51681035892"><a name="zh-cn_topic_0000001173164707_p51681035892"></a><a name="zh-cn_topic_0000001173164707_p51681035892"></a>translateX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p816815351895"><a name="zh-cn_topic_0000001173164707_p816815351895"></a><a name="zh-cn_topic_0000001173164707_p816815351895"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p16552135220230"><a name="zh-cn_topic_0000001173164707_p16552135220230"></a><a name="zh-cn_topic_0000001173164707_p16552135220230"></a>指定水平移动值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row23751855744"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1216810351597"><a name="zh-cn_topic_0000001173164707_p1216810351597"></a><a name="zh-cn_topic_0000001173164707_p1216810351597"></a>translateY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1916813355910"><a name="zh-cn_topic_0000001173164707_p1916813355910"></a><a name="zh-cn_topic_0000001173164707_p1916813355910"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p15553352102320"><a name="zh-cn_topic_0000001173164707_p15553352102320"></a><a name="zh-cn_topic_0000001173164707_p15553352102320"></a>指定垂直移动值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(0, 0, 100, 100)
    ctx.setTransform(1,0.5, -0.5, 1, 10, 10);
    ctx.fillStyle = 'rgb(0,0,255)';
    ctx.fillRect(0, 0, 100, 100);
    ```

    ![](figures/zh-cn_image_0000001173164791.png)


## translate\(\)<a name="zh-cn_topic_0000001173164707_section931011253449"></a>

移动当前坐标系的原点。

-   参数

    <a name="zh-cn_topic_0000001173164707_table256392291115"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row5585122161117"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1458552217113"><a name="zh-cn_topic_0000001173164707_p1458552217113"></a><a name="zh-cn_topic_0000001173164707_p1458552217113"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p17585112213118"><a name="zh-cn_topic_0000001173164707_p17585112213118"></a><a name="zh-cn_topic_0000001173164707_p17585112213118"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p758592281116"><a name="zh-cn_topic_0000001173164707_p758592281116"></a><a name="zh-cn_topic_0000001173164707_p758592281116"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row358510226116"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p4585162231115"><a name="zh-cn_topic_0000001173164707_p4585162231115"></a><a name="zh-cn_topic_0000001173164707_p4585162231115"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p13585152221111"><a name="zh-cn_topic_0000001173164707_p13585152221111"></a><a name="zh-cn_topic_0000001173164707_p13585152221111"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p11585102251118"><a name="zh-cn_topic_0000001173164707_p11585102251118"></a><a name="zh-cn_topic_0000001173164707_p11585102251118"></a>设置水平平移量。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row205858225118"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1058532211120"><a name="zh-cn_topic_0000001173164707_p1058532211120"></a><a name="zh-cn_topic_0000001173164707_p1058532211120"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1858582281116"><a name="zh-cn_topic_0000001173164707_p1858582281116"></a><a name="zh-cn_topic_0000001173164707_p1858582281116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1058572221115"><a name="zh-cn_topic_0000001173164707_p1058572221115"></a><a name="zh-cn_topic_0000001173164707_p1058572221115"></a>设置竖直平移量。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillRect(10, 10, 50, 50);
    ctx.translate(70, 70);
    ctx.fillRect(10, 10, 50, 50);
    ```

    ![](figures/zh-cn_image_0000001127125158.png)


## createPath2D\(\)<sup>6+</sup><a name="zh-cn_topic_0000001173164707_section6654994314"></a>

创建一个Path2D对象。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1358920321431"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row105901132194317"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p17590932124319"><a name="zh-cn_topic_0000001173164707_p17590932124319"></a><a name="zh-cn_topic_0000001173164707_p17590932124319"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p859017328430"><a name="zh-cn_topic_0000001173164707_p859017328430"></a><a name="zh-cn_topic_0000001173164707_p859017328430"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p259063217431"><a name="zh-cn_topic_0000001173164707_p259063217431"></a><a name="zh-cn_topic_0000001173164707_p259063217431"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row25906327439"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p459013326436"><a name="zh-cn_topic_0000001173164707_p459013326436"></a><a name="zh-cn_topic_0000001173164707_p459013326436"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p5590153284315"><a name="zh-cn_topic_0000001173164707_p5590153284315"></a><a name="zh-cn_topic_0000001173164707_p5590153284315"></a>Path2D</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1059012327435"><a name="zh-cn_topic_0000001173164707_p1059012327435"></a><a name="zh-cn_topic_0000001173164707_p1059012327435"></a>Path2D对象。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row359083216435"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p3590173219438"><a name="zh-cn_topic_0000001173164707_p3590173219438"></a><a name="zh-cn_topic_0000001173164707_p3590173219438"></a>cmds</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1659143214317"><a name="zh-cn_topic_0000001173164707_p1659143214317"></a><a name="zh-cn_topic_0000001173164707_p1659143214317"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p125911432154314"><a name="zh-cn_topic_0000001173164707_p125911432154314"></a><a name="zh-cn_topic_0000001173164707_p125911432154314"></a>SVG的Path描述字符串。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    Path2D对象

-   示例

    ```
    var path1 = ctx.createPath2D();
    path1.moveTo(100, 100);
    path1.lineTo(200, 100);
    path1.lineTo(100, 200);
    path1.closePath();
    ctx.stroke(path1);
    var path2 = ctx.createPath2D("M150 150 L50 250 L250 250 Z");
    ctx.stroke(path2);
    var path3 = ctx.createPath2D(path2);
    ctx.stroke(path3);
    ```

    ![](figures/zh-cn_image_0000001152770830.png)


## globalAlpha<a name="zh-cn_topic_0000001173164707_section188252174810"></a>

设置透明度。

-   参数

    <a name="zh-cn_topic_0000001173164707_table93426123121"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row123641312141218"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p15364121218129"><a name="zh-cn_topic_0000001173164707_p15364121218129"></a><a name="zh-cn_topic_0000001173164707_p15364121218129"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1136401214122"><a name="zh-cn_topic_0000001173164707_p1136401214122"></a><a name="zh-cn_topic_0000001173164707_p1136401214122"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p19364121291215"><a name="zh-cn_topic_0000001173164707_p19364121291215"></a><a name="zh-cn_topic_0000001173164707_p19364121291215"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row236412121129"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p43641512121219"><a name="zh-cn_topic_0000001173164707_p43641512121219"></a><a name="zh-cn_topic_0000001173164707_p43641512121219"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p236416122128"><a name="zh-cn_topic_0000001173164707_p236416122128"></a><a name="zh-cn_topic_0000001173164707_p236416122128"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1254548152511"><a name="zh-cn_topic_0000001173164707_p1254548152511"></a><a name="zh-cn_topic_0000001173164707_p1254548152511"></a>0.0为完全透明，1.0为完全不透明。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(0, 0, 50, 50);
    ctx.globalAlpha = 0.4;
    ctx.fillStyle = 'rgb(0,0,255)'; 
    ctx.fillRect(50, 50, 50, 50); 
    ```

    ![](figures/zh-cn_image_0000001127125168.png)


## drawImage\(\)<a name="zh-cn_topic_0000001173164707_section1953117410488"></a>

进行图像绘制。

-   参数

    <a name="zh-cn_topic_0000001173164707_table32431032122019"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row32931532152016"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p12931532192013"><a name="zh-cn_topic_0000001173164707_p12931532192013"></a><a name="zh-cn_topic_0000001173164707_p12931532192013"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.858585858585858%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p18293153216204"><a name="zh-cn_topic_0000001173164707_p18293153216204"></a><a name="zh-cn_topic_0000001173164707_p18293153216204"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.80808080808081%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1529333214208"><a name="zh-cn_topic_0000001173164707_p1529333214208"></a><a name="zh-cn_topic_0000001173164707_p1529333214208"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row14293732192019"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p32933328202"><a name="zh-cn_topic_0000001173164707_p32933328202"></a><a name="zh-cn_topic_0000001173164707_p32933328202"></a>image</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p14293163232017"><a name="zh-cn_topic_0000001173164707_p14293163232017"></a><a name="zh-cn_topic_0000001173164707_p14293163232017"></a>Image</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p8293193262017"><a name="zh-cn_topic_0000001173164707_p8293193262017"></a><a name="zh-cn_topic_0000001173164707_p8293193262017"></a>图片资源，请参考<a href="js-components-canvas-image.md#ZH-CN_TOPIC_0000001164290722">Image对象</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row3301829154419"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p183191137184416"><a name="zh-cn_topic_0000001173164707_p183191137184416"></a><a name="zh-cn_topic_0000001173164707_p183191137184416"></a>sx</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p16319103734413"><a name="zh-cn_topic_0000001173164707_p16319103734413"></a><a name="zh-cn_topic_0000001173164707_p16319103734413"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p123191537154414"><a name="zh-cn_topic_0000001173164707_p123191537154414"></a><a name="zh-cn_topic_0000001173164707_p123191537154414"></a>裁切源图像时距离源图像左上角的x坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row12670183194416"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p173195371449"><a name="zh-cn_topic_0000001173164707_p173195371449"></a><a name="zh-cn_topic_0000001173164707_p173195371449"></a>sy</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p7319337144420"><a name="zh-cn_topic_0000001173164707_p7319337144420"></a><a name="zh-cn_topic_0000001173164707_p7319337144420"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p11320537124417"><a name="zh-cn_topic_0000001173164707_p11320537124417"></a><a name="zh-cn_topic_0000001173164707_p11320537124417"></a>裁切源图像时距离源图像左上角的y坐标值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row106131433144418"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p18320037144416"><a name="zh-cn_topic_0000001173164707_p18320037144416"></a><a name="zh-cn_topic_0000001173164707_p18320037144416"></a>sWidth</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p232016373443"><a name="zh-cn_topic_0000001173164707_p232016373443"></a><a name="zh-cn_topic_0000001173164707_p232016373443"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p2320173713449"><a name="zh-cn_topic_0000001173164707_p2320173713449"></a><a name="zh-cn_topic_0000001173164707_p2320173713449"></a>裁切源图像时需要裁切的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row9578335104413"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p63201037144415"><a name="zh-cn_topic_0000001173164707_p63201037144415"></a><a name="zh-cn_topic_0000001173164707_p63201037144415"></a>sHeight</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1032043713440"><a name="zh-cn_topic_0000001173164707_p1032043713440"></a><a name="zh-cn_topic_0000001173164707_p1032043713440"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p143201937174418"><a name="zh-cn_topic_0000001173164707_p143201937174418"></a><a name="zh-cn_topic_0000001173164707_p143201937174418"></a>裁切源图像时需要裁切的高度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row82931325201"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p142931032122010"><a name="zh-cn_topic_0000001173164707_p142931032122010"></a><a name="zh-cn_topic_0000001173164707_p142931032122010"></a>dx</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p7293123218208"><a name="zh-cn_topic_0000001173164707_p7293123218208"></a><a name="zh-cn_topic_0000001173164707_p7293123218208"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p329363211208"><a name="zh-cn_topic_0000001173164707_p329363211208"></a><a name="zh-cn_topic_0000001173164707_p329363211208"></a>绘制区域左上角在x轴的位置。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1829323292013"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p112931232152014"><a name="zh-cn_topic_0000001173164707_p112931232152014"></a><a name="zh-cn_topic_0000001173164707_p112931232152014"></a>dy</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1829393215206"><a name="zh-cn_topic_0000001173164707_p1829393215206"></a><a name="zh-cn_topic_0000001173164707_p1829393215206"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p20293183219208"><a name="zh-cn_topic_0000001173164707_p20293183219208"></a><a name="zh-cn_topic_0000001173164707_p20293183219208"></a>绘制区域左上角在y 轴的位置。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1929303232015"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p12931632122013"><a name="zh-cn_topic_0000001173164707_p12931632122013"></a><a name="zh-cn_topic_0000001173164707_p12931632122013"></a>dWidth</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p18293132102011"><a name="zh-cn_topic_0000001173164707_p18293132102011"></a><a name="zh-cn_topic_0000001173164707_p18293132102011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p62937321203"><a name="zh-cn_topic_0000001173164707_p62937321203"></a><a name="zh-cn_topic_0000001173164707_p62937321203"></a>绘制区域的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row15293163262011"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p029315329203"><a name="zh-cn_topic_0000001173164707_p029315329203"></a><a name="zh-cn_topic_0000001173164707_p029315329203"></a>dHeight</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.858585858585858%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p72931432192011"><a name="zh-cn_topic_0000001173164707_p72931432192011"></a><a name="zh-cn_topic_0000001173164707_p72931432192011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.80808080808081%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p2029363215202"><a name="zh-cn_topic_0000001173164707_p2029363215202"></a><a name="zh-cn_topic_0000001173164707_p2029363215202"></a>绘制区域的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    var test = this.$element('drawImage');
    var ctx = test.getContext('2d');
    var img = new Image();
    img.src = 'common/image/test.jpg';
    ctx.drawImage(img, 50, 80, 80, 80);
    ```

    ![](figures/zh-cn_image_0000001173164821.png)


## restore\(\)<a name="zh-cn_topic_0000001173164707_section64027684817"></a>

对保存的绘图上下文进行恢复。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.restore();
    ```


## save\(\)<a name="zh-cn_topic_0000001173164707_section410672635214"></a>

对当前的绘图上下文进行保存。

-   参数

    无

-   返回值

    无

-   示例

    ```
    ctx.save();
    ```


## createLinearGradient\(\)<sup>6+</sup><a name="zh-cn_topic_0000001173164707_section1696310905"></a>

创建一个线性渐变色，返回CanvasGradient对象，请参考[CanvasGradient对象](js-components-canvas-canvasgradient.md#ZH-CN_TOPIC_0000001209210715)。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1796312016012"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1096414014011"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1596430101"><a name="zh-cn_topic_0000001173164707_p1596430101"></a><a name="zh-cn_topic_0000001173164707_p1596430101"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.39393939393939%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p296410702"><a name="zh-cn_topic_0000001173164707_p296410702"></a><a name="zh-cn_topic_0000001173164707_p296410702"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.27272727272727%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p1596412017016"><a name="zh-cn_topic_0000001173164707_p1596412017016"></a><a name="zh-cn_topic_0000001173164707_p1596412017016"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row69641801501"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p59641405011"><a name="zh-cn_topic_0000001173164707_p59641405011"></a><a name="zh-cn_topic_0000001173164707_p59641405011"></a>x0</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p7964602011"><a name="zh-cn_topic_0000001173164707_p7964602011"></a><a name="zh-cn_topic_0000001173164707_p7964602011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p139648012011"><a name="zh-cn_topic_0000001173164707_p139648012011"></a><a name="zh-cn_topic_0000001173164707_p139648012011"></a>起点的x轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row13964130401"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p09641909020"><a name="zh-cn_topic_0000001173164707_p09641909020"></a><a name="zh-cn_topic_0000001173164707_p09641909020"></a>y0</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p18965001203"><a name="zh-cn_topic_0000001173164707_p18965001203"></a><a name="zh-cn_topic_0000001173164707_p18965001203"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p19653020019"><a name="zh-cn_topic_0000001173164707_p19653020019"></a><a name="zh-cn_topic_0000001173164707_p19653020019"></a>起点的y轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row19965104011"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p29653012013"><a name="zh-cn_topic_0000001173164707_p29653012013"></a><a name="zh-cn_topic_0000001173164707_p29653012013"></a>x1</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p49653018012"><a name="zh-cn_topic_0000001173164707_p49653018012"></a><a name="zh-cn_topic_0000001173164707_p49653018012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p19965704015"><a name="zh-cn_topic_0000001173164707_p19965704015"></a><a name="zh-cn_topic_0000001173164707_p19965704015"></a>终点的x轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row139652017014"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p496690407"><a name="zh-cn_topic_0000001173164707_p496690407"></a><a name="zh-cn_topic_0000001173164707_p496690407"></a>y1</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1296650207"><a name="zh-cn_topic_0000001173164707_p1296650207"></a><a name="zh-cn_topic_0000001173164707_p1296650207"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p69661401507"><a name="zh-cn_topic_0000001173164707_p69661401507"></a><a name="zh-cn_topic_0000001173164707_p69661401507"></a>终点的y轴坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="zh-cn_topic_0000001173164707_table15966200609"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row29668020014"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p1696712015020"><a name="zh-cn_topic_0000001173164707_p1696712015020"></a><a name="zh-cn_topic_0000001173164707_p1696712015020"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p19671901603"><a name="zh-cn_topic_0000001173164707_p19671901603"></a><a name="zh-cn_topic_0000001173164707_p19671901603"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row89671800010"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p2967308018"><a name="zh-cn_topic_0000001173164707_p2967308018"></a><a name="zh-cn_topic_0000001173164707_p2967308018"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p1967801012"><a name="zh-cn_topic_0000001173164707_p1967801012"></a><a name="zh-cn_topic_0000001173164707_p1967801012"></a>返回创建的CanvasGradient对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    <!-- xxx.hml -->
    <canvas ref="canvas" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
    <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
    ```

    ```
    // xxx.js
    export default {
      handleClick() {
        const el = this.$refs.canvas;
        const ctx = el.getContext('2d');
        // Linear gradient: start(50,0) end(300,100)
        var gradient = ctx.createLinearGradient(50,0, 300,100);
        // Add three color stops
        gradient.addColorStop(0.0, 'red');
        gradient.addColorStop(0.5, 'white');
        gradient.addColorStop(1.0, 'green');
        // Set the fill style and draw a rectangle
        ctx.fillStyle = gradient;
        ctx.fillRect(0, 0, 500, 500);
      }
    }
    ```

    ![](figures/zh-cn_image_0000001173164827.png)


## createRadialGradient\(\)<sup>6+</sup><a name="zh-cn_topic_0000001173164707_section121861417143711"></a>

创建一个径向渐变色，返回CanvasGradient对象，请参考CanvasGradient

-   参数

    <a name="zh-cn_topic_0000001173164707_table618713176372"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row41871717143716"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p01871817143717"><a name="zh-cn_topic_0000001173164707_p01871817143717"></a><a name="zh-cn_topic_0000001173164707_p01871817143717"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.39393939393939%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p171871617123712"><a name="zh-cn_topic_0000001173164707_p171871617123712"></a><a name="zh-cn_topic_0000001173164707_p171871617123712"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.27272727272727%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p518781723714"><a name="zh-cn_topic_0000001173164707_p518781723714"></a><a name="zh-cn_topic_0000001173164707_p518781723714"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1618751723711"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p9187191793711"><a name="zh-cn_topic_0000001173164707_p9187191793711"></a><a name="zh-cn_topic_0000001173164707_p9187191793711"></a>x0</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p218871714374"><a name="zh-cn_topic_0000001173164707_p218871714374"></a><a name="zh-cn_topic_0000001173164707_p218871714374"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p71886176371"><a name="zh-cn_topic_0000001173164707_p71886176371"></a><a name="zh-cn_topic_0000001173164707_p71886176371"></a>起始圆的x轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row12188117173710"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p15188141793710"><a name="zh-cn_topic_0000001173164707_p15188141793710"></a><a name="zh-cn_topic_0000001173164707_p15188141793710"></a>y0</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p91889174371"><a name="zh-cn_topic_0000001173164707_p91889174371"></a><a name="zh-cn_topic_0000001173164707_p91889174371"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p8188417183712"><a name="zh-cn_topic_0000001173164707_p8188417183712"></a><a name="zh-cn_topic_0000001173164707_p8188417183712"></a>起始圆的y轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row618881793711"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p9188217143711"><a name="zh-cn_topic_0000001173164707_p9188217143711"></a><a name="zh-cn_topic_0000001173164707_p9188217143711"></a>r0</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p418811175377"><a name="zh-cn_topic_0000001173164707_p418811175377"></a><a name="zh-cn_topic_0000001173164707_p418811175377"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p81887176371"><a name="zh-cn_topic_0000001173164707_p81887176371"></a><a name="zh-cn_topic_0000001173164707_p81887176371"></a>起始圆的半径。必须是非负且有限的。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row9504115563915"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p5504205583914"><a name="zh-cn_topic_0000001173164707_p5504205583914"></a><a name="zh-cn_topic_0000001173164707_p5504205583914"></a>x1</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p2505155512392"><a name="zh-cn_topic_0000001173164707_p2505155512392"></a><a name="zh-cn_topic_0000001173164707_p2505155512392"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p11505355123913"><a name="zh-cn_topic_0000001173164707_p11505355123913"></a><a name="zh-cn_topic_0000001173164707_p11505355123913"></a>终点圆的x轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row9799138204017"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p625322234019"><a name="zh-cn_topic_0000001173164707_p625322234019"></a><a name="zh-cn_topic_0000001173164707_p625322234019"></a>y1</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1799158174015"><a name="zh-cn_topic_0000001173164707_p1799158174015"></a><a name="zh-cn_topic_0000001173164707_p1799158174015"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1879910812408"><a name="zh-cn_topic_0000001173164707_p1879910812408"></a><a name="zh-cn_topic_0000001173164707_p1879910812408"></a>终点圆的y轴坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row16617135918397"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p995672413403"><a name="zh-cn_topic_0000001173164707_p995672413403"></a><a name="zh-cn_topic_0000001173164707_p995672413403"></a>r1</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1561785983914"><a name="zh-cn_topic_0000001173164707_p1561785983914"></a><a name="zh-cn_topic_0000001173164707_p1561785983914"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p76171459163916"><a name="zh-cn_topic_0000001173164707_p76171459163916"></a><a name="zh-cn_topic_0000001173164707_p76171459163916"></a>终点圆的半径。必须为非负且有限的。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="zh-cn_topic_0000001173164707_table14189717203712"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row171899172372"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p518914177378"><a name="zh-cn_topic_0000001173164707_p518914177378"></a><a name="zh-cn_topic_0000001173164707_p518914177378"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p5189417143715"><a name="zh-cn_topic_0000001173164707_p5189417143715"></a><a name="zh-cn_topic_0000001173164707_p5189417143715"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1518961763716"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p1318991713712"><a name="zh-cn_topic_0000001173164707_p1318991713712"></a><a name="zh-cn_topic_0000001173164707_p1318991713712"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p1818911174376"><a name="zh-cn_topic_0000001173164707_p1818911174376"></a><a name="zh-cn_topic_0000001173164707_p1818911174376"></a>返回创建的CanvasGradient对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    <!-- xxx.hml -->
    <canvas ref="canvas" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
    <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
    ```

    ```
    // xxx.js
    export default {
      handleClick() {
        const el = this.$refs.canvas;
        const ctx = el.getContext('2d');
        // Radial gradient: inner circle(200,200,r:50) outer circle(200,200,r:200)
        var gradient = ctx.createRadialGradient(200,200,50, 200,200,200);
        // Add three color stops
        gradient.addColorStop(0.0, 'red');
        gradient.addColorStop(0.5, 'white');
        gradient.addColorStop(1.0, 'green');
        // Set the fill style and draw a rectangle
        ctx.fillStyle = gradient;
        ctx.fillRect(0, 0, 500, 500);
      }
    }
    ```

    ![](figures/zh-cn_image_0000001173164813.png)


## createImageData\(\)<a name="zh-cn_topic_0000001173164707_section2021142714524"></a>

创建新的ImageData 对象，请参考[ImageData对象](js-components-canvas-imagedata.md#ZH-CN_TOPIC_0000001209570711)。

-   参数

    <a name="zh-cn_topic_0000001173164707_table129117962316"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row19361699239"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1293615917238"><a name="zh-cn_topic_0000001173164707_p1293615917238"></a><a name="zh-cn_topic_0000001173164707_p1293615917238"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.39393939393939%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1693612912237"><a name="zh-cn_topic_0000001173164707_p1693612912237"></a><a name="zh-cn_topic_0000001173164707_p1693612912237"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.27272727272727%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p13936189122313"><a name="zh-cn_topic_0000001173164707_p13936189122313"></a><a name="zh-cn_topic_0000001173164707_p13936189122313"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row59364982313"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p19364919234"><a name="zh-cn_topic_0000001173164707_p19364919234"></a><a name="zh-cn_topic_0000001173164707_p19364919234"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p69368972314"><a name="zh-cn_topic_0000001173164707_p69368972314"></a><a name="zh-cn_topic_0000001173164707_p69368972314"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p10936179162310"><a name="zh-cn_topic_0000001173164707_p10936179162310"></a><a name="zh-cn_topic_0000001173164707_p10936179162310"></a>ImageData的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row593620917239"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p129361199237"><a name="zh-cn_topic_0000001173164707_p129361199237"></a><a name="zh-cn_topic_0000001173164707_p129361199237"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p793613982319"><a name="zh-cn_topic_0000001173164707_p793613982319"></a><a name="zh-cn_topic_0000001173164707_p793613982319"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p139365917231"><a name="zh-cn_topic_0000001173164707_p139365917231"></a><a name="zh-cn_topic_0000001173164707_p139365917231"></a>ImageData的高度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row109361902317"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1093620932310"><a name="zh-cn_topic_0000001173164707_p1093620932310"></a><a name="zh-cn_topic_0000001173164707_p1093620932310"></a>imagedata</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.39393939393939%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p119372911232"><a name="zh-cn_topic_0000001173164707_p119372911232"></a><a name="zh-cn_topic_0000001173164707_p119372911232"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.27272727272727%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p109371902312"><a name="zh-cn_topic_0000001173164707_p109371902312"></a><a name="zh-cn_topic_0000001173164707_p109371902312"></a>复制现有的ImageData对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="zh-cn_topic_0000001173164707_table17718181510238"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row17736101592319"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p7736415102313"><a name="zh-cn_topic_0000001173164707_p7736415102313"></a><a name="zh-cn_topic_0000001173164707_p7736415102313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p1873610154234"><a name="zh-cn_topic_0000001173164707_p1873610154234"></a><a name="zh-cn_topic_0000001173164707_p1873610154234"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1673601532316"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p10736191518237"><a name="zh-cn_topic_0000001173164707_p10736191518237"></a><a name="zh-cn_topic_0000001173164707_p10736191518237"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p7736315122311"><a name="zh-cn_topic_0000001173164707_p7736315122311"></a><a name="zh-cn_topic_0000001173164707_p7736315122311"></a>返回创建的ImageData对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    imageData = ctx.createImageData(50, 100);  // Create ImageData with 50px width and 100px height
    newImageData = ctx.createImageData(imageData);  // Create ImageData using the input imageData
    ```


## getImageData\(\)<a name="zh-cn_topic_0000001173164707_section92731528205217"></a>

以当前canvas指定区域内的像素创建ImageData对象。

-   参数

    <a name="zh-cn_topic_0000001173164707_table290615162313"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row18931185132316"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p189319518233"><a name="zh-cn_topic_0000001173164707_p189319518233"></a><a name="zh-cn_topic_0000001173164707_p189319518233"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p99311751122319"><a name="zh-cn_topic_0000001173164707_p99311751122319"></a><a name="zh-cn_topic_0000001173164707_p99311751122319"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p59312514236"><a name="zh-cn_topic_0000001173164707_p59312514236"></a><a name="zh-cn_topic_0000001173164707_p59312514236"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row5931175152317"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1393165162311"><a name="zh-cn_topic_0000001173164707_p1393165162311"></a><a name="zh-cn_topic_0000001173164707_p1393165162311"></a>sx</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1193118517235"><a name="zh-cn_topic_0000001173164707_p1193118517235"></a><a name="zh-cn_topic_0000001173164707_p1193118517235"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p9931195122316"><a name="zh-cn_topic_0000001173164707_p9931195122316"></a><a name="zh-cn_topic_0000001173164707_p9931195122316"></a>需要输出的区域的左上角x坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row119316511234"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p12931155142311"><a name="zh-cn_topic_0000001173164707_p12931155142311"></a><a name="zh-cn_topic_0000001173164707_p12931155142311"></a>sy</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p10931145112232"><a name="zh-cn_topic_0000001173164707_p10931145112232"></a><a name="zh-cn_topic_0000001173164707_p10931145112232"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1393125112230"><a name="zh-cn_topic_0000001173164707_p1393125112230"></a><a name="zh-cn_topic_0000001173164707_p1393125112230"></a>需要输出的区域的左上角y坐标。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row11931951142315"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p59311051112311"><a name="zh-cn_topic_0000001173164707_p59311051112311"></a><a name="zh-cn_topic_0000001173164707_p59311051112311"></a>sw</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p12931351162314"><a name="zh-cn_topic_0000001173164707_p12931351162314"></a><a name="zh-cn_topic_0000001173164707_p12931351162314"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p16932165172315"><a name="zh-cn_topic_0000001173164707_p16932165172315"></a><a name="zh-cn_topic_0000001173164707_p16932165172315"></a>需要输出的区域的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row593215132316"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p199321451132315"><a name="zh-cn_topic_0000001173164707_p199321451132315"></a><a name="zh-cn_topic_0000001173164707_p199321451132315"></a>sh</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p89321851182311"><a name="zh-cn_topic_0000001173164707_p89321851182311"></a><a name="zh-cn_topic_0000001173164707_p89321851182311"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p10932105102314"><a name="zh-cn_topic_0000001173164707_p10932105102314"></a><a name="zh-cn_topic_0000001173164707_p10932105102314"></a>需要输出的区域的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="zh-cn_topic_0000001173164707_table062115912238"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1264005902317"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p0640195910233"><a name="zh-cn_topic_0000001173164707_p0640195910233"></a><a name="zh-cn_topic_0000001173164707_p0640195910233"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p4640155922319"><a name="zh-cn_topic_0000001173164707_p4640155922319"></a><a name="zh-cn_topic_0000001173164707_p4640155922319"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row15640359162318"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p964035912238"><a name="zh-cn_topic_0000001173164707_p964035912238"></a><a name="zh-cn_topic_0000001173164707_p964035912238"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p464055982312"><a name="zh-cn_topic_0000001173164707_p464055982312"></a><a name="zh-cn_topic_0000001173164707_p464055982312"></a>返回包含指定区域像素的ImageData对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    var test = this.$element('getImageData');
    var ctx = test.getContext('2d');
    var imageData = ctx.getImageData(0, 0, 280, 300);
    ```


## putImageData\(\)<a name="zh-cn_topic_0000001173164707_section15774154925515"></a>

使用ImageData数据填充新的矩形区域。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1915122872412"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1619052872418"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p3190122872418"><a name="zh-cn_topic_0000001173164707_p3190122872418"></a><a name="zh-cn_topic_0000001173164707_p3190122872418"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p5190528172413"><a name="zh-cn_topic_0000001173164707_p5190528172413"></a><a name="zh-cn_topic_0000001173164707_p5190528172413"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p2019072814241"><a name="zh-cn_topic_0000001173164707_p2019072814241"></a><a name="zh-cn_topic_0000001173164707_p2019072814241"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1819032813242"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1819052882414"><a name="zh-cn_topic_0000001173164707_p1819052882414"></a><a name="zh-cn_topic_0000001173164707_p1819052882414"></a>imagedata</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p16190112815243"><a name="zh-cn_topic_0000001173164707_p16190112815243"></a><a name="zh-cn_topic_0000001173164707_p16190112815243"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1190102816243"><a name="zh-cn_topic_0000001173164707_p1190102816243"></a><a name="zh-cn_topic_0000001173164707_p1190102816243"></a>包含像素值的ImageData对象。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1219012882416"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p51901828112411"><a name="zh-cn_topic_0000001173164707_p51901828112411"></a><a name="zh-cn_topic_0000001173164707_p51901828112411"></a>dx</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p14190202892413"><a name="zh-cn_topic_0000001173164707_p14190202892413"></a><a name="zh-cn_topic_0000001173164707_p14190202892413"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p171911828202414"><a name="zh-cn_topic_0000001173164707_p171911828202414"></a><a name="zh-cn_topic_0000001173164707_p171911828202414"></a>填充区域在x轴方向的偏移量。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row12191102872416"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p0191122802417"><a name="zh-cn_topic_0000001173164707_p0191122802417"></a><a name="zh-cn_topic_0000001173164707_p0191122802417"></a>dy</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p519118288246"><a name="zh-cn_topic_0000001173164707_p519118288246"></a><a name="zh-cn_topic_0000001173164707_p519118288246"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p7191328102418"><a name="zh-cn_topic_0000001173164707_p7191328102418"></a><a name="zh-cn_topic_0000001173164707_p7191328102418"></a>填充区域在y轴方向的偏移量。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1319120283245"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p419112283249"><a name="zh-cn_topic_0000001173164707_p419112283249"></a><a name="zh-cn_topic_0000001173164707_p419112283249"></a>dirtyX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1419117288248"><a name="zh-cn_topic_0000001173164707_p1419117288248"></a><a name="zh-cn_topic_0000001173164707_p1419117288248"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p8191128172412"><a name="zh-cn_topic_0000001173164707_p8191128172412"></a><a name="zh-cn_topic_0000001173164707_p8191128172412"></a>源图像数据矩形裁切范围左上角距离源图像左上角的x轴偏移量。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row14191128142419"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p131911528162418"><a name="zh-cn_topic_0000001173164707_p131911528162418"></a><a name="zh-cn_topic_0000001173164707_p131911528162418"></a>dirtyY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p1919119281244"><a name="zh-cn_topic_0000001173164707_p1919119281244"></a><a name="zh-cn_topic_0000001173164707_p1919119281244"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p11191728132414"><a name="zh-cn_topic_0000001173164707_p11191728132414"></a><a name="zh-cn_topic_0000001173164707_p11191728132414"></a>源图像数据矩形裁切范围左上角距离源图像左上角的y轴偏移量。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row14191182813241"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p191911728162419"><a name="zh-cn_topic_0000001173164707_p191911728162419"></a><a name="zh-cn_topic_0000001173164707_p191911728162419"></a>dirtyWidth</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p3191162815245"><a name="zh-cn_topic_0000001173164707_p3191162815245"></a><a name="zh-cn_topic_0000001173164707_p3191162815245"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p119162813242"><a name="zh-cn_topic_0000001173164707_p119162813242"></a><a name="zh-cn_topic_0000001173164707_p119162813242"></a>源图像数据矩形裁切范围的宽度。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row519113281242"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p19191122832420"><a name="zh-cn_topic_0000001173164707_p19191122832420"></a><a name="zh-cn_topic_0000001173164707_p19191122832420"></a>dirtyHeight</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p31910280243"><a name="zh-cn_topic_0000001173164707_p31910280243"></a><a name="zh-cn_topic_0000001173164707_p31910280243"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p10191172842415"><a name="zh-cn_topic_0000001173164707_p10191172842415"></a><a name="zh-cn_topic_0000001173164707_p10191172842415"></a>源图像数据矩形裁切范围的高度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    var test = this.$element('putImageData');
    var ctx = test.getContext('2d');
    var imgData = ctx.createImageData(100, 100);
    for (var i = 0; i < imgData.data.length; i += 4) {
      imgData.data[i + 0] = 255;
      imgData.data[i + 1] = 0;
      imgData.data[i + 2] = 0;
      imgData.data[i + 3] = 255;
    }
    ctx.putImageData(imgData, 10, 10);
    ```

    ![](figures/zh-cn_image_0000001198530737.png)


## setLineDash\(\)<a name="zh-cn_topic_0000001173164707_section1934985155516"></a>

设置画布的虚线样式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table7928161714252"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row2946131732512"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p12946171742513"><a name="zh-cn_topic_0000001173164707_p12946171742513"></a><a name="zh-cn_topic_0000001173164707_p12946171742513"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p9946517172511"><a name="zh-cn_topic_0000001173164707_p9946517172511"></a><a name="zh-cn_topic_0000001173164707_p9946517172511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p0946121762513"><a name="zh-cn_topic_0000001173164707_p0946121762513"></a><a name="zh-cn_topic_0000001173164707_p0946121762513"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1694611713251"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1494621722516"><a name="zh-cn_topic_0000001173164707_p1494621722516"></a><a name="zh-cn_topic_0000001173164707_p1494621722516"></a>segments</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p139471217152513"><a name="zh-cn_topic_0000001173164707_p139471217152513"></a><a name="zh-cn_topic_0000001173164707_p139471217152513"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p10947141782515"><a name="zh-cn_topic_0000001173164707_p10947141782515"></a><a name="zh-cn_topic_0000001173164707_p10947141782515"></a>作为数组用来描述线段如何交替和间距长度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.arc(100, 75, 50, 0, 6.28);
    ctx.setLineDash([10,20]);
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001152770952.png)


## getLineDash\(\)<a name="zh-cn_topic_0000001173164707_section522105285519"></a>

获得当前画布的虚线样式。

-   参数

    无

-   返回值

    <a name="zh-cn_topic_0000001173164707_table7827188122614"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row58489882610"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p084898122610"><a name="zh-cn_topic_0000001173164707_p084898122610"></a><a name="zh-cn_topic_0000001173164707_p084898122610"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p58488817262"><a name="zh-cn_topic_0000001173164707_p58488817262"></a><a name="zh-cn_topic_0000001173164707_p58488817262"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row138486802613"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p38481582261"><a name="zh-cn_topic_0000001173164707_p38481582261"></a><a name="zh-cn_topic_0000001173164707_p38481582261"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p784813811263"><a name="zh-cn_topic_0000001173164707_p784813811263"></a><a name="zh-cn_topic_0000001173164707_p784813811263"></a>返回数组，该数组用来描述线段如何交替和间距长度。。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    var info = ctx.getLineDash();
    ```


## lineDashOffset<a name="zh-cn_topic_0000001173164707_section8283548889"></a>

设置画布的虚线偏移量。

-   参数

    <a name="zh-cn_topic_0000001173164707_table661840172615"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row147974012263"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p137944010269"><a name="zh-cn_topic_0000001173164707_p137944010269"></a><a name="zh-cn_topic_0000001173164707_p137944010269"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p879340142613"><a name="zh-cn_topic_0000001173164707_p879340142613"></a><a name="zh-cn_topic_0000001173164707_p879340142613"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p167912409261"><a name="zh-cn_topic_0000001173164707_p167912409261"></a><a name="zh-cn_topic_0000001173164707_p167912409261"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1793401268"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p679940122610"><a name="zh-cn_topic_0000001173164707_p679940122610"></a><a name="zh-cn_topic_0000001173164707_p679940122610"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p16801740132611"><a name="zh-cn_topic_0000001173164707_p16801740132611"></a><a name="zh-cn_topic_0000001173164707_p16801740132611"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p980174016264"><a name="zh-cn_topic_0000001173164707_p980174016264"></a><a name="zh-cn_topic_0000001173164707_p980174016264"></a>精度为float，默认为0.0。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.arc(100, 75, 50, 0, 6.28);
    ctx.setLineDash([10,20]);
    ctx.lineDashOffset = 10.0;
    ctx.stroke();
    ```

    ![](figures/zh-cn_image_0000001198530815.png)


## globalCompositeOperation<a name="zh-cn_topic_0000001173164707_section123871750284"></a>

设置合成操作的方式。

-   参数

    <a name="zh-cn_topic_0000001173164707_table894332519273"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1961162592715"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p7961132562710"><a name="zh-cn_topic_0000001173164707_p7961132562710"></a><a name="zh-cn_topic_0000001173164707_p7961132562710"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p18961025162717"><a name="zh-cn_topic_0000001173164707_p18961025162717"></a><a name="zh-cn_topic_0000001173164707_p18961025162717"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p3961192502717"><a name="zh-cn_topic_0000001173164707_p3961192502717"></a><a name="zh-cn_topic_0000001173164707_p3961192502717"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row10961162532713"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p1896112258278"><a name="zh-cn_topic_0000001173164707_p1896112258278"></a><a name="zh-cn_topic_0000001173164707_p1896112258278"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p8961142512276"><a name="zh-cn_topic_0000001173164707_p8961142512276"></a><a name="zh-cn_topic_0000001173164707_p8961142512276"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1796132510275"><a name="zh-cn_topic_0000001173164707_p1796132510275"></a><a name="zh-cn_topic_0000001173164707_p1796132510275"></a>合成操作的类型字段。可选值有source-over(默认值)，source-atop，source-in，source-out，destination-over，destination-atop，destination-in，destination-out，lighter，copy，xor。</p>
    </td>
    </tr>
    </tbody>
    </table>

    属性值：

    <a name="zh-cn_topic_0000001173164707_table16858736162715"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1789616363276"><th class="cellrowborder" valign="top" width="12.78%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001173164707_p3896113612272"><a name="zh-cn_topic_0000001173164707_p3896113612272"></a><a name="zh-cn_topic_0000001173164707_p3896113612272"></a>值</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.22%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001173164707_p1389653616271"><a name="zh-cn_topic_0000001173164707_p1389653616271"></a><a name="zh-cn_topic_0000001173164707_p1389653616271"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row5896163615275"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p148962361278"><a name="zh-cn_topic_0000001173164707_p148962361278"></a><a name="zh-cn_topic_0000001173164707_p148962361278"></a>source-over</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p4897123622710"><a name="zh-cn_topic_0000001173164707_p4897123622710"></a><a name="zh-cn_topic_0000001173164707_p4897123622710"></a>在现有绘制内容上显示新绘制内容，属于默认值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row1789713361277"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p08971936182713"><a name="zh-cn_topic_0000001173164707_p08971936182713"></a><a name="zh-cn_topic_0000001173164707_p08971936182713"></a>source-atop</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p489743619271"><a name="zh-cn_topic_0000001173164707_p489743619271"></a><a name="zh-cn_topic_0000001173164707_p489743619271"></a>在现有绘制内容顶部显示新绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row38977367271"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p1897183620278"><a name="zh-cn_topic_0000001173164707_p1897183620278"></a><a name="zh-cn_topic_0000001173164707_p1897183620278"></a>source-in</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p4897173615271"><a name="zh-cn_topic_0000001173164707_p4897173615271"></a><a name="zh-cn_topic_0000001173164707_p4897173615271"></a>在现有绘制内容中显示新绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row38971336142717"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p158971136112719"><a name="zh-cn_topic_0000001173164707_p158971136112719"></a><a name="zh-cn_topic_0000001173164707_p158971136112719"></a>source-out</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p2897103642715"><a name="zh-cn_topic_0000001173164707_p2897103642715"></a><a name="zh-cn_topic_0000001173164707_p2897103642715"></a>在现有绘制内容之外显示新绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row889714368273"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p138974368279"><a name="zh-cn_topic_0000001173164707_p138974368279"></a><a name="zh-cn_topic_0000001173164707_p138974368279"></a>destination-over</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p11897123622719"><a name="zh-cn_topic_0000001173164707_p11897123622719"></a><a name="zh-cn_topic_0000001173164707_p11897123622719"></a>在新绘制内容上方显示现有绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row28972366277"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p148971836152715"><a name="zh-cn_topic_0000001173164707_p148971836152715"></a><a name="zh-cn_topic_0000001173164707_p148971836152715"></a>destination-atop</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p1789783602717"><a name="zh-cn_topic_0000001173164707_p1789783602717"></a><a name="zh-cn_topic_0000001173164707_p1789783602717"></a>在新绘制内容顶部显示现有绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row198971836162712"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p17897536112720"><a name="zh-cn_topic_0000001173164707_p17897536112720"></a><a name="zh-cn_topic_0000001173164707_p17897536112720"></a>destination-in</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p789783692713"><a name="zh-cn_topic_0000001173164707_p789783692713"></a><a name="zh-cn_topic_0000001173164707_p789783692713"></a>在新绘制内容中显示现有绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row138978361271"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p1589753622718"><a name="zh-cn_topic_0000001173164707_p1589753622718"></a><a name="zh-cn_topic_0000001173164707_p1589753622718"></a>destination-out</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p19897036192710"><a name="zh-cn_topic_0000001173164707_p19897036192710"></a><a name="zh-cn_topic_0000001173164707_p19897036192710"></a>在新绘制内容外显示现有绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row2897143622719"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p489733613272"><a name="zh-cn_topic_0000001173164707_p489733613272"></a><a name="zh-cn_topic_0000001173164707_p489733613272"></a>lighter</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p589793615274"><a name="zh-cn_topic_0000001173164707_p589793615274"></a><a name="zh-cn_topic_0000001173164707_p589793615274"></a>显示新绘制内容和现有绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row289716361272"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p1389720362272"><a name="zh-cn_topic_0000001173164707_p1389720362272"></a><a name="zh-cn_topic_0000001173164707_p1389720362272"></a>copy</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p589719364271"><a name="zh-cn_topic_0000001173164707_p589719364271"></a><a name="zh-cn_topic_0000001173164707_p589719364271"></a>显示新绘制内容而忽略现有绘制内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164707_row16897103652713"><td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001173164707_p1489793612279"><a name="zh-cn_topic_0000001173164707_p1489793612279"></a><a name="zh-cn_topic_0000001173164707_p1489793612279"></a>xor</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.22%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001173164707_p789718368275"><a name="zh-cn_topic_0000001173164707_p789718368275"></a><a name="zh-cn_topic_0000001173164707_p789718368275"></a>使用异或操作对新绘制内容与现有绘制内容进行融合。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(20, 20, 50, 50);
    ctx.globalCompositeOperation = 'source-over';
    ctx.fillStyle = 'rgb(0,0,255)';
    ctx.fillRect(50, 50, 50, 50);
    // Start drawing second example
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(120, 20, 50, 50);
    ctx.globalCompositeOperation = 'destination-over';
    ctx.fillStyle = 'rgb(0,0,255)';
    ctx.fillRect(150, 50, 50, 50);
    ```

    ![](figures/zh-cn_image_0000001173324717.png)

    示例中，新绘制内容是蓝色矩形，现有绘制内容是红色矩形。


## shadowBlur<a name="zh-cn_topic_0000001173164707_section6207051888"></a>

设置绘制阴影时的模糊级别，默认值为0.0。

-   参数

    <a name="zh-cn_topic_0000001173164707_table9996192417289"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1512122513281"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p15127251281"><a name="zh-cn_topic_0000001173164707_p15127251281"></a><a name="zh-cn_topic_0000001173164707_p15127251281"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1812152514289"><a name="zh-cn_topic_0000001173164707_p1812152514289"></a><a name="zh-cn_topic_0000001173164707_p1812152514289"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p14125256281"><a name="zh-cn_topic_0000001173164707_p14125256281"></a><a name="zh-cn_topic_0000001173164707_p14125256281"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row171242519288"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p151210252280"><a name="zh-cn_topic_0000001173164707_p151210252280"></a><a name="zh-cn_topic_0000001173164707_p151210252280"></a>blur</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p31212513284"><a name="zh-cn_topic_0000001173164707_p31212513284"></a><a name="zh-cn_topic_0000001173164707_p31212513284"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p61202519282"><a name="zh-cn_topic_0000001173164707_p61202519282"></a><a name="zh-cn_topic_0000001173164707_p61202519282"></a>设置模糊效果的程度值，值越大越模糊，精度为float 。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.shadowBlur = 30;
    ctx.shadowColor = 'rgb(0,0,0)';
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(20, 20, 100, 80);
    ```

    ![](figures/zh-cn_image_0000001127284952.png)


## shadowColor<a name="zh-cn_topic_0000001173164707_section42724396120"></a>

设置绘制阴影时的阴影颜色。

-   参数

    <a name="zh-cn_topic_0000001173164707_table2196196152919"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row221256162918"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1621219612291"><a name="zh-cn_topic_0000001173164707_p1621219612291"></a><a name="zh-cn_topic_0000001173164707_p1621219612291"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p112127613291"><a name="zh-cn_topic_0000001173164707_p112127613291"></a><a name="zh-cn_topic_0000001173164707_p112127613291"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p102121966294"><a name="zh-cn_topic_0000001173164707_p102121966294"></a><a name="zh-cn_topic_0000001173164707_p102121966294"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1321219682914"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p6212186142912"><a name="zh-cn_topic_0000001173164707_p6212186142912"></a><a name="zh-cn_topic_0000001173164707_p6212186142912"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p221236122920"><a name="zh-cn_topic_0000001173164707_p221236122920"></a><a name="zh-cn_topic_0000001173164707_p221236122920"></a>&lt;color&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p112223307597"><a name="zh-cn_topic_0000001173164707_p112223307597"></a><a name="zh-cn_topic_0000001173164707_p112223307597"></a>阴影的颜色值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.shadowBlur = 30;
    ctx.shadowColor = 'rgb(0,0,255)';
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(30, 30, 100, 100);
    ```

    ![](figures/zh-cn_image_0000001127284944.png)


## shadowOffsetX<a name="zh-cn_topic_0000001173164707_section1616174021219"></a>

设置绘制阴影时和原有对象的水平偏移值。

-   参数

    <a name="zh-cn_topic_0000001173164707_table2274164413292"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row229011445292"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p1329034420297"><a name="zh-cn_topic_0000001173164707_p1329034420297"></a><a name="zh-cn_topic_0000001173164707_p1329034420297"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p19290444112916"><a name="zh-cn_topic_0000001173164707_p19290444112916"></a><a name="zh-cn_topic_0000001173164707_p19290444112916"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p529054472920"><a name="zh-cn_topic_0000001173164707_p529054472920"></a><a name="zh-cn_topic_0000001173164707_p529054472920"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row122901544132911"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p2029084482915"><a name="zh-cn_topic_0000001173164707_p2029084482915"></a><a name="zh-cn_topic_0000001173164707_p2029084482915"></a>offsetX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p122901744162919"><a name="zh-cn_topic_0000001173164707_p122901744162919"></a><a name="zh-cn_topic_0000001173164707_p122901744162919"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1429084432917"><a name="zh-cn_topic_0000001173164707_p1429084432917"></a><a name="zh-cn_topic_0000001173164707_p1429084432917"></a>阴影距离原有对象的x轴方向偏移值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.shadowBlur = 10;
    ctx.shadowOffsetX = 20;
    ctx.shadowColor = 'rgb(0,0,0)';
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(20, 20, 100, 80);
    ```

    ![](figures/zh-cn_image_0000001127125148.png)


## shadowOffsetY<a name="zh-cn_topic_0000001173164707_section272013417128"></a>

设置绘制阴影时和原有对象的垂直偏移值。

-   参数

    <a name="zh-cn_topic_0000001173164707_table20807026143014"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row18231126113017"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p7823192615306"><a name="zh-cn_topic_0000001173164707_p7823192615306"></a><a name="zh-cn_topic_0000001173164707_p7823192615306"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p88231426193012"><a name="zh-cn_topic_0000001173164707_p88231426193012"></a><a name="zh-cn_topic_0000001173164707_p88231426193012"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p16823626193018"><a name="zh-cn_topic_0000001173164707_p16823626193018"></a><a name="zh-cn_topic_0000001173164707_p16823626193018"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row178231526113019"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p13823172643018"><a name="zh-cn_topic_0000001173164707_p13823172643018"></a><a name="zh-cn_topic_0000001173164707_p13823172643018"></a>offsetY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p482312683018"><a name="zh-cn_topic_0000001173164707_p482312683018"></a><a name="zh-cn_topic_0000001173164707_p482312683018"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p4823182619305"><a name="zh-cn_topic_0000001173164707_p4823182619305"></a><a name="zh-cn_topic_0000001173164707_p4823182619305"></a>阴影距离原有对象的y轴方向偏移值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    ctx.shadowBlur = 10;
    ctx.shadowOffsetY = 20;
    ctx.shadowColor = 'rgb(0,0,0)';
    ctx.fillStyle = 'rgb(255,0,0)';
    ctx.fillRect(30, 30, 100, 100);
    ```

    ![](figures/zh-cn_image_0000001173164825.png)


## imageSmoothingEnabled<sup>6+</sup><a name="zh-cn_topic_0000001173164707_section770341132716"></a>

用于设置绘制图片时是否进行图像平滑度调整。

-   参数

    <a name="zh-cn_topic_0000001173164707_table4704181112718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row77044112276"><th class="cellrowborder" valign="top" width="14.202020202020202%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p87041811112710"><a name="zh-cn_topic_0000001173164707_p87041811112710"></a><a name="zh-cn_topic_0000001173164707_p87041811112710"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.717171717171716%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p47040117279"><a name="zh-cn_topic_0000001173164707_p47040117279"></a><a name="zh-cn_topic_0000001173164707_p47040117279"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.08080808080808%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p870471116273"><a name="zh-cn_topic_0000001173164707_p870471116273"></a><a name="zh-cn_topic_0000001173164707_p870471116273"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row1370461142715"><td class="cellrowborder" valign="top" width="14.202020202020202%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p77051611172716"><a name="zh-cn_topic_0000001173164707_p77051611172716"></a><a name="zh-cn_topic_0000001173164707_p77051611172716"></a>enabled</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.717171717171716%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p4705141112718"><a name="zh-cn_topic_0000001173164707_p4705141112718"></a><a name="zh-cn_topic_0000001173164707_p4705141112718"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.08080808080808%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p17314141615520"><a name="zh-cn_topic_0000001173164707_p17314141615520"></a><a name="zh-cn_topic_0000001173164707_p17314141615520"></a>是否进行图像平滑度调整，默认值为true，即启用。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    var img = new Image();
    img.src = 'common/image/huawei.jpg';
    img.onload = function() {
      ctx.imageSmoothingEnabled = false;
      ctx.drawImage(img, 0, 0, 400, 200);
    };
    ```

    ![](figures/smoothOff.png)


## transferFromImageBitmap\(\)<sup>7+</sup><a name="zh-cn_topic_0000001173164707_section9849145418469"></a>

显示给定的ImageBitmap对象。

-   参数

    <a name="zh-cn_topic_0000001173164707_table1182233717517"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164707_row1982219374511"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164707_p19822133713519"><a name="zh-cn_topic_0000001173164707_p19822133713519"></a><a name="zh-cn_topic_0000001173164707_p19822133713519"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164707_p1282353716519"><a name="zh-cn_topic_0000001173164707_p1282353716519"></a><a name="zh-cn_topic_0000001173164707_p1282353716519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164707_p88231837195120"><a name="zh-cn_topic_0000001173164707_p88231837195120"></a><a name="zh-cn_topic_0000001173164707_p88231837195120"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164707_row13823143745115"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164707_p882313775110"><a name="zh-cn_topic_0000001173164707_p882313775110"></a><a name="zh-cn_topic_0000001173164707_p882313775110"></a>bitmap</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164707_p12823183714517"><a name="zh-cn_topic_0000001173164707_p12823183714517"></a><a name="zh-cn_topic_0000001173164707_p12823183714517"></a>ImageBitmap</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164707_p1563323875414"><a name="zh-cn_topic_0000001173164707_p1563323875414"></a><a name="zh-cn_topic_0000001173164707_p1563323875414"></a>待显示的ImageBitmap对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    无

-   示例

    ```
    var canvas = this.$refs.canvasId.getContext('2d');
    var offscreen = new OffscreenCanvas(500,500);
    var offscreenCanvasCtx = offscreen.getContext("2d");
    offscreenCanvasCtx.fillRect(0, 0, 200, 200);
    
    var bitmap = offscreen.transferToImageBitmap();
    canvas.transferFromImageBitmap(bitmap);
    ```

    ![](figures/zh-cn_image_0000001198690237.png)


