# Rating<a name="ZH-CN_TOPIC_0000001192595156"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

评分条组件。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section53281531154915"></a>

无

## 接口说明<a name="section1989913519718"></a>

Rating\(options?: \{ rating: number, indicator?: boolean \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>rating</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>设置并接收评分值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>indicator</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>仅作为指示器使用，不可操作。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section18430105671014"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.84%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.38%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="56.010000000000005%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.5.1.1 "><p>stars</p>
</td>
<td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.3 "><p>5</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p>设置评星总数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.5.1.1 "><p>stepSize</p>
</td>
<td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.3 "><p>0.5</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p>操作评级的步长。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.5.1.1 "><p>starStyle</p>
</td>
<td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>backgroundUri: string,</p>
<p>foregroundUri: string,</p>
<p>secondaryUri?: string</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p>backgroundSrc：未选中的星级的图片链接，可由用户自定义或使用系统默认图片，仅支持本地。</p>
<p>foregroundSrc：选中的星级的图片路径，可由用户自定义或使用系统默认图片，仅支持本地。</p>
<p>secondarySrc：部分选中的星级的图片路径，可由用户自定义或使用系统默认图片，仅支持本地。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section449664852016"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onChange(callback:(value: number) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>操作评分条的评星发生改变时触发该回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct RatingExample {
  @State rating: number = 1
  @State indicator: boolean = false

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('current score is ' + this.rating).fontSize(20)
      Rating({ rating: this.rating, indicator: this.indicator })
        .stars(5)
        .stepSize(0.5)
        .onChange((value: number) => {
          this.rating = value
        })
    }.width(350).height(200).padding(35)
  }
}
```

![](figures/Rating.gif)

