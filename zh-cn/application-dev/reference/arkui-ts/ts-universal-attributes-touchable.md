# 点击控制<a name="ZH-CN_TOPIC_0000001192595170"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.46%" id="mcps1.1.5.1.1"><p><strong>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.19%" id="mcps1.1.5.1.2"><p><strong>参数类型</strong></p>
</th>
<th class="cellrowborder" valign="top" width="12.120000000000001%" id="mcps1.1.5.1.3"><p><strong>默认值</strong></p>
</th>
<th class="cellrowborder" valign="top" width="44.230000000000004%" id="mcps1.1.5.1.4"><p><strong>描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.1 "><p>touchable</p>
</td>
<td class="cellrowborder" valign="top" width="18.19%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.120000000000001%" headers="mcps1.1.5.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="44.230000000000004%" headers="mcps1.1.5.1.4 "><p>设置当前组件是否可以被触摸。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1693524132311"></a>

```
@Entry
@Component
struct TouchAbleExample {
  @State text1: string = ''
  @State text2: string = ''

  build() {
    Stack() {
      Rect()
        .fill(Color.Gray).width(150).height(150)
        .onClick(() => {
          console.info(this.text1 = 'Rect Clicked')
        })
        .overlay(this.text1, { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      Ellipse()
        .fill(Color.Pink).width(150).height(80)
        .touchable(false) // 点击Ellipse区域，不会打印 “Ellipse Clicked”
        .onClick(() => {
          console.info(this.text2 = 'Ellipse Clicked')
        })
        .overlay(this.text2, { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
    }.margin(100)
  }
}
```

![](figures/GIF2.gif)

