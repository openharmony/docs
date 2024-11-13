# SwipeRefresher


内容加载指获取内容并加载出来，常用于衔接展示下拉加载的内容。

> **说明：**
>
> 该组件及其子组件从 API Version 10 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { SwipeRefresher } from '@kit.ArkUI'
```


## 子组件

无

## 属性
支持[通用属性](ts-universal-attributes-size.md)


## SwipeRefresher

SwipeRefresher ({content?: string, isLoading: boolean})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | string | 否 | \@Prop | 内容加载时显示的文本。 |
| isLoading | boolean | 是 | \@Prop | 当前是否正在加载。<br> isLoading为true时，表示正在加载。<br> isLoading为false时，表示未在加载。 |

## 事件
支持[通用事件](ts-universal-events-click.md)

## 示例
```ts
import { SwipeRefresher } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      SwipeRefresher({
        content: '正在加载中',
        isLoading: true
      })
      SwipeRefresher({
        content: '',
        isLoading: true
      })
      SwipeRefresher({
        content: '正在加载中',
        isLoading: false
      })
    }
  }
}
```

![Snipaste_2023-07-24_11-35-40](figures/Snipaste_2023-07-24_11-35-40.gif)
