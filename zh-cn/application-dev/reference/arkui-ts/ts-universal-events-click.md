# 点击事件

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 事件

| 名称 | 支持冒泡 | 功能描述 | 
| -------- | -------- | -------- |
| onClick(callback:&nbsp;(event?:&nbsp;ClickEvent)&nbsp;=&gt;&nbsp;void) | 否 | 点击动作触发该方法调用，event参数见ClickEvent介绍。 | 

### ClickEvent对象说明
  | 属性名称 | 类型 | 描述 |
  | -------- | -------- | -------- |
  | screenX | number | 点击点相对于设备屏幕左边沿的X坐标。 |
  | screenY | number | 点击点相对于设备屏幕上边沿的Y坐标。 |
  | x | number | 点击点相对于被点击元素左边沿的X坐标。 |
  | y | number | 点击点相对于被点击元素上边沿的Y坐标。 |
  | target<sup>8+</sup> | EventTarget | 被点击元素对象。 |
  | timestamp | number | 事件时间戳。 |

- EventTarget<sup>8+</sup>对象说明
  | 名称 | 参数类型 | 描述 |
  | -------- | -------- | -------- |
  | area | Area | 目标元素的区域信息。 |

- Area<sup>8+</sup>对象说明
  | 属性名称 | 类型 | 描述 |
  | -------- | -------- | -------- |
  | width | number | 目标元素的宽度，单位为vp。 |
  | height | number | 目标元素的高度，单位为vp。 |
  | position | Position | 目标元素左上角相对父元素左上角的位置。 |
  | globalPosition | Position | 目标元素左上角相对页面左上角的位置。 |

- Position<sup>8+</sup>对象说明
  | 属性名称 | 参数类型 | 描述 | 
  | -------- | -------- | -------- |
  | x | number | x轴坐标，单位为vp。 | 
  | y | number | y轴坐标，单位为vp。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ClickExample {
  @State text: string = ''

  build() {
    Column() {
      Button('Click').backgroundColor(0x2788D9).width(100).height(40)
        .onClick((event: ClickEvent) => {
          console.info(this.text = 'Click Point:' + '\n  screenX:' + event.screenX + '\n  screenY:' + event.screenY
          + '\n  x:' + event.x + '\n  y:' + event.y + '\ntarget:' + '\n  component globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\n  width:'
          + event.target.area.width + '\n  height:' + event.target.area.height)
        })
      Text(this.text).padding(15)
    }.height(350).width('100%').padding(10)
  }
}
```


![zh-cn_image_0000001210353788](figures/zh-cn_image_0000001210353788.gif)
