# 矩阵变换<a name="ZH-CN_TOPIC_0000001192915104"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块<a name="section1727172013219"></a>

```
import matrix4 from '@ohos.matrix4'
```

## 权限列表<a name="section7743183014286"></a>

无

## matrix4.init<a name="section12864856072"></a>

init\(array: Array<number\>\): Object

Matrix的构造函数，可以通过传入的参数创建一个四阶矩阵，矩阵为列优先。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.790000000000003%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.410000000000004%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>array</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Array&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.790000000000003%" headers="mcps1.1.6.1.4 "><p>[1, 0, 0, 0,</p>
    <p>0, 1, 0, 0,</p>
    <p>0, 0, 1, 0,</p>
    <p>0, 0, 0, 1]</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.410000000000004%" headers="mcps1.1.6.1.5 "><p>参数为长度为16（4*4）的number数组, 详情见<a href="#li1515172020468">参数描述</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>根据入参创建的四阶矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1515172020468"></a>参数描述

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m00</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>x轴缩放值，单位矩阵默认为1。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m01</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>第2个值，xyz轴旋转会影响这个值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m02</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>第3个值，xyz轴旋转会影响这个值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m03</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>无实际意义。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m10</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>第5个值，xyz轴旋转会影响这个值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m11</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>y轴缩放值，单位矩阵默认为1。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m12</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>第7个值，xyz轴旋转会影响这个值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m13</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>无实际意义。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m20</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>第9个值，xyz轴旋转会影响这个值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m21</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>第10个值，xyz轴旋转会影响这个值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m22</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>z轴缩放值，单位矩阵默认为1。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m23</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>无实际意义。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m30</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>x轴平移值，单位px，单位矩阵默认为0。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m31</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>y轴平移值，单位px，单位矩阵默认为0。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m32</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>z轴平移值，单位px，单位矩阵默认为0。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p>m33</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p>齐次坐标下生效，产生透视投影效果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    // 创建一个四阶矩阵
    let matrix = Matrix4.init([1.0, 0.0, 0.0, 0.0,
                              0.0, 1.0, 0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0,
                              0.0, 0.0, 0.0, 1.0])
    ```


## matrix4.identity<a name="section042975416311"></a>

identity\(\): Object

Matrix的初始化函数，可以返回一个单位矩阵对象。

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>单位矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // matrix1 和 matrix2 效果一致
    import Matrix4 from '@ohos.matrix4'
    let matrix = Matrix4.init([1.0, 0.0, 0.0, 0.0,
                              0.0, 1.0, 0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0,
                              0.0, 0.0, 0.0, 1.0])
    let matrix2 = Matrix4.identity()
    ```


## matrix4.copy<a name="section9959103514339"></a>

copy\(\): Object

Matrix的拷贝函数，可以拷贝一份当前的矩阵对象。

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>当前矩阵的拷贝对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    @Entry
    @Component
    struct Test {
      private matrix1 = Matrix4.identity().translate({x:100})
      private matrix2 = this.matrix1.copy().scale({x:2})
      build() {
        Column() {
          Image($r("app.media.bg1"))
            .width("40%")
            .height(100)
            .transform(this.matrix1)
          Image($r("app.media.bg2"))
            .width("40%")
            .height(100)
            .margin({top:50})
            .transform(this.matrix2)
        }
      }
    }
    ```

    ![](figures/s1.png)


## Matrix4<a name="section118153513365"></a>

### combine<a name="section267686121415"></a>

combine\(matrix: Matrix4\): Object

Matrix的叠加函数，可以将两个矩阵的效果叠加起来生成一个新的矩阵对象。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.68%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>matrix</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Matrix4</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>待叠加的矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>矩阵叠加后的对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    @Entry
    @Component
    struct Test {
      private matrix1 = Matrix4.identity().translate({x:200}).copy()
      private matrix2 = Matrix4.identity().scale({x:2}).copy()
      build() {
        Column() {
         // 先平移x轴100px，再缩放两倍x轴
          Image($r("app.media.bg1")).transform(this.matrix1.combine(this.matrix2)) 
            .width("40%")
            .height(100)
            .margin({top:50})
        }
      }
    }
    ```

    ![](figures/q1.png)


### invert<a name="section592117351618"></a>

invert\(\): Object

Matrix的逆函数，可以返回一个当前矩阵对象的逆矩阵，即效果正好相反。

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>当前矩阵的逆矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    // matrix1(宽放大2倍) 和 matrix2(宽缩小2倍) 效果相反
    let matrix1 = Matrix4.identity().scale({x:2})
    let matrix2 = matrix1.invert()
    ```


### translate<a name="section39828585169"></a>

translate\(\{x?: number, y?: number, z?: number\}\): Object

Matrix的平移函数，可以为当前矩阵增加x轴/Y轴/Z轴平移效果。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.68%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>x轴的平移距离，单位px。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>y轴的平移距离，单位px。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>z</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>z轴的平移距离，单位px。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>增加好平移效果后的矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    @Entry
    @Component
    struct Test {
      private matrix1 = Matrix4.identity().translate({x:100, y:200, z:30})
      build() {
        Column() {
          Image($r("app.media.bg1")).transform(this.matrix1)
            .width("40%")
            .height(100)
        }
      }
    }
    ```

    ![](figures/s3.png)


### scale<a name="section835405115174"></a>

scale\(\{x?: number, y?: number, z?: number, centerX?: number, centerY?: number\}\): Object

Matrix的缩放函数，可以为当前矩阵增加x轴/Y轴/Z轴缩放效果。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.51%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.69%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.1.6.1.5 "><p>x轴的缩放倍数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.1.6.1.5 "><p>y轴的缩放倍数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>z</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.1.6.1.5 "><p>z轴的缩放倍数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>centerX</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.1.6.1.5 "><p>变换中心点x轴坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>centerY</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.1.6.1.5 "><p>变换中心点y轴坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>增加好缩放效果后的矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    @Entry
    @Component
    struct Test {
      private matrix1 = Matrix4.identity().scale({x:2, y:3, z:4, centerX:50, centerY:50})
      build() {
        Column() { 
          Image($r("app.media.bg1")).transform(this.matrix1)
            .width("40%")
            .height(100)
        }
      }
    }
    ```

    ![](figures/s4-(1).png)


### rotate<a name="section524516309189"></a>

rotate\(\{x?: number, y?: number, z?: number, angle?: number, centerX?: Length, centerY?: Length\}\): Object

Matrix的旋转函数，可以为当前矩阵增加x轴/Y轴/Z轴旋转效果。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.68%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>旋转轴向量x坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>旋转轴向量y坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>z</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>旋转轴向量z坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>旋转角度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>centerX</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>变换中心点x轴坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>centerY</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>变换中心点y轴坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>增加好旋转效果后的矩阵对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    @Entry
    @Component
    struct Test {
      private matrix1 = Matrix4.identity().rotate({x:1, y:1, z:2, angle:30})
      build() {
        Column() {
          Image($r("app.media.bg1")).transform(this.matrix1)
            .width("40%")
            .height(100)
        }.width("100%").margin({top:50})
      }
    }
    ```

    ![](figures/1.png)


### transformPoint<a name="section174811817131913"></a>

transformPoint\(point: Point\): Point

Matrix的坐标点转换函数，可以将当前的变换效果作用到一个坐标点上。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.68%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>point</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Point</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>需要转换的坐标点。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.380000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.62%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.380000000000003%" headers="mcps1.1.3.1.1 "><p>Point</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.62%" headers="mcps1.1.3.1.2 "><p>返回矩阵变换后的Point对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import Matrix4 from '@ohos.matrix4'
    import prompt from '@system.prompt'
    
    @Entry
    @Component
    struct Test {
      private matrix1 = Matrix4.identity().transformPoint([100, 10])
      build() {
        Column() {
         Button("get Point")
          .onClick(() => {
           prompt.showToast({message:JSON.stringify(this.matrix1),duration:2000})
          }).backgroundColor(0x2788D9)
        }.width("100%").padding(50)
      }
    }
    ```

    ![](figures/222.gif)


