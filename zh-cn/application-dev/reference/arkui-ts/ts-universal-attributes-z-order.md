# Z序控制

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| zIndex | number | 0 | 同一容器中兄弟组件显示层级关系，z值越大，显示层级越高。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ZIndexExample {
  build() {
    Column() {
      Stack() {
        // stack会重叠组件, 默认后定义的在最上面
        Text('first child, zIndex(2)')
          .size({width: '40%', height: '30%'}).backgroundColor(0xbbb2cb)
          .zIndex(2)
        // 默认值0
        Text('second child, default zIndex(0)')
          .size({width: '90%', height: '80%'}).backgroundColor(0xd2cab3).align(Alignment.TopStart)
        Text('third child, zIndex(1)')
          .size({width: '70%', height: '50%'}).backgroundColor(0xc1cbac).align(Alignment.TopStart)
          .zIndex(1)
      }
    }.width('100%').height(200)
  }
}
```

![zh-cn_image_0000001174582860](figures/zh-cn_image_0000001174582860.png)
