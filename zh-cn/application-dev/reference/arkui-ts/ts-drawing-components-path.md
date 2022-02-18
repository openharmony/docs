# Path

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


路径绘制组件。


## 权限列表

无


## 子组件

无


## 属性

| 参数名称 | 参数类型 | 默认值 | 必填 | 参数描述 | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | 否 | 路径所在矩形的宽度。 | 
| height | Length | 0 | 否 | 路径所在矩形的高度。 | 
| commands | string | '' | 是 | 路径绘制的命令字符串。 | 


支持的绘制命令如下：


- M = moveto

- L = lineto

- H = horizontal lineto

- V = vertical lineto

- C = curveto

- S = smooth curveto

- Q = quadratic Belzier curve

- T = smooth quadratic Belzier curveto

- A = elliptical Arc

- Z = closepath


如 commands('M0 20 L50 50 L50 100 Z')定义了一条路径，开始于位置（0，20），到达位置（50，50）后再到（50，100），最后在（0，20）处关闭路径。


## 示例

```
@Entry
@Component
struct PathExample {
  build() {
    Column({ space: 5 }) {
      Text('Straight line').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Path().width(300).height(10).commands('M0 0 L900 0').stroke(Color.Black).strokeWidth(3)

      Text('Straight line graph').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // 先后执行MoveTo(150, 0), LineTo(300, 300), LineTo(0, 300), ClosePath()
        Path().width(100).height(100).commands('M150 0 L300 300 L0 300 Z')
        // 先后执行MoveTo(0, 0), HorizontalLineto(300), VerticalLineto(300), HorizontalLineto(0), ClosePath()
        Path().width(100).height(100).commands('M0 0 H300 V300 H0 Z')
        // 先后执行MoveTo(150, 0), LineTo(0, 150), LineTo(60, 300), LineTo(240, 300), LineTo(300, 150), ClosePath()
        Path().width(100).height(100).commands('M150 0 L0 150 L60 300 L240 300 L300 150 Z')
      }.width('100%')

      Text('Curve graphics').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // 先后执行MoveTo(0, 300),(150, 0)(300, 300)两点之间画曲线, ClosePath()
        Path().width(100).height(100).commands("M0 300 S150 0 300 300 Z")
        // 先后执行MoveTo(0, 150),(0, 150)(150, 0)(300, 150)三点之间依次画曲线, LineTo(150, 300),ClosePath()
        Path().width(100).height(100).commands('M0 150 C0 150 150 0 300 150 L150 300 Z')
      }
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001219744193](figures/zh-cn_image_0000001219744193.png)
