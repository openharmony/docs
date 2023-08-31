# SwipeRefresher


内容加载指获取内容并加载出来。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件及其子组件从 API Version 10 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { SwipeRefresher } from '@ohos.arkui.advacned.SwipeRefresher'
```


## 子组件

无


## 接口

SwipeRefresher ({content: string, isLoading: boolean})

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数值 | 参数类型 | 必填 | 装饰器类型 | 参数描述 | 
| -------- | -------- | -------- | -------- | -------- |
| content | string | 否 | \@Prop | 内容加载时显示的文本。 | 
| isLoading | boolean | 是 | \@Prop | 当前是否正在加载。 | 


## 示例

```ts
import { SwipeRefresher } from '@ohos.arkui.advaned.SwipeRefresher';

@Entry
@Component
struct Index {
  build() {
    Column() {
      SwipeRefresher({
        content: '正在加载中',
        isLoading: true })
      SwipeRefresher({
        isLoading: true })
      SwipeRefresher({
        content: '正在加载中',
        isLoading: false })
    }
  }
}
```

![Snipaste_2023-07-24_11-35-40](figures/Snipaste_2023-07-24_11-35-40.png)
