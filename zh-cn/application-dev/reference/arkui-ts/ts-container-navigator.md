# Navigator

路由容器组件，提供路由跳转能力。

> **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。


## 接口

Navigator(value?: {target: string, type?: NavigationType})

**参数：**

| 参数名 | 参数类型       | 必填 | 参数描述                                       |
| ------ | -------------- | ---- | ---------------------------------------------- |
| target | string         | 是   | 指定跳转目标页面的路径。     |
| type   | [NavigationType](#navigationtype枚举说明) | 否   | 指定路由方式。<br/>默认值：NavigationType.Push |

## NavigationType枚举说明

| 名称      | 描述                         |
| ------- | -------------------------- |
| Push    | 跳转到应用内的指定页面。               |
| Replace | 用应用内的某个页面替换当前页面，并销毁被替换的页面。 |
| Back    | 返回到指定的页面。指定的页面不存在栈中时不响应。未传入指定的页面时返回上一页。 |


## 属性

| 名称   | 参数    | 描述                                                         |
| ------ | ------- | ------------------------------------------------------------ |
| active | boolean | 当前路由组件是否处于激活状态，处于激活状态时，会生效相应的路由操作。 |
| params | object  | 跳转时要同时传递到目标页面的数据，可在目标页面使用[router.getParams()](../apis/js-apis-router.md#routergetparams)获得。 |
| target | string         | 设置跳转目标页面的路径。 目标页面需加入main_pages.json文件中。                         |
| type   | [NavigationType](#navigationtype枚举说明)  | 设置路由方式。<br/>默认值：NavigationType.Push |


## 示例

```ts
// Navigator.ets
@Entry
@Component
struct NavigatorExample {
  @State active: boolean = false
  @State Text: object = {name: 'news'}

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Detail', type: NavigationType.Push }) {
        Text('Go to ' + this.Text['name'] + ' page')
          .width('100%').textAlign(TextAlign.Center)
      }.params({ text: this.Text }) // 传参数到Detail页面

      Navigator() {
        Text('Back to previous page').width('100%').textAlign(TextAlign.Center)
      }.active(this.active)
      .onClick(() => {
        this.active = true
      })
    }.height(150).width(350).padding(35)
  }
}
```

```ts
// Detail.ets
import router from '@ohos.router'

@Entry
@Component
struct DetailExample {
  // 接收Navigator.ets的传参
  @State text: any = router.getParams()['text']

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Back', type: NavigationType.Push }) {
        Text('Go to back page').width('100%').height(20)
      }

      Text('This is ' + this.text['name'] + ' page')
        .width('100%').textAlign(TextAlign.Center)
    }
    .width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}

```

```ts
// Back.ets
@Entry
@Component
struct BackExample {
  build() {
    Column() {
      Navigator({ target: 'pages/container/navigator/Navigator', type: NavigationType.Back }) {
        Text('Return to Navigator Page').width('100%').textAlign(TextAlign.Center)
      }
    }.width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![zh-cn_image_0000001219864145](figures/zh-cn_image_0000001219864145.gif)
