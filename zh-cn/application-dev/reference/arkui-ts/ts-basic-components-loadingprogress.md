# LoadingProgress

>  **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

用于显示加载进展。


## 权限列表

无


## 子组件

无


## 接口

LoadingProgress()

创建加载进展组件。



## 属性

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| color | Color | - | 设置加载进度条前景色。 |



## 示例

```ts
// xxx.ets
@Entry
@Component
struct LoadingProgressExample {
  build() {
    Column({ space: 5 }) {
      Text('Orbital LoadingProgress ').fontSize(9).fontColor(0xCCCCCC).width('90%')
      LoadingProgress()
        .color(Color.Blue)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001198839004](figures/loadingProgress.png)
