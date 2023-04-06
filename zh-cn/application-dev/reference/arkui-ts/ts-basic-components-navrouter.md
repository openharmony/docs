# NavRouter

导航组件，默认提供点击响应处理，不需要开发者自定义点击事件逻辑。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

必须包含两个子组件，其中第二个子组件必须为[NavDestination](ts-basic-components-navdestination.md)。

> **说明：**
>
> 子组件个数异常时：
> 1. 有且仅有1个时，触发路由到NavDestination的能力失效。
> 2. 有且仅有1个时，且使用NavDestination场景下，不进行路由。
> 3. 大于2个时，后续的子组件不显示。
> 4. 第二个子组件不为NavDestination时，触发路由功能失效。

## 接口

NavRouter()


## 事件

| 名称                                                    | 功能描述                                                     |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| onStateChange(callback: (isActivated: boolean) => void) | 组件激活状态切换时触发该回调。返回值isActivated为true时表示激活，为false时表示未激活。<br/> **说明：** <br/>开发者点击激活NavRouter，加载对应的NavDestination子组件时，回调onStateChange(true)。NavRouter对应的NavDestination子组件不再显示时，回调onStateChange(false)。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct NavRouterExample {
  private arr: number[] = [0, 1, 2, 3]
  @State isActive: boolean = false
  @State dex: number = 0

  build() {
    Column() {
      Navigation() {
        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.arr, (item: number, index: number) => {
            ListItem() {
              NavRouter() {
                Row() {
                  Image($r('app.media.icon')).width(30).height(30).borderRadius(30).margin({ left: 3, right: 10 })
                  Text(`NavRouter${item + 1}`)
                    .fontSize(22)
                    .fontWeight(500)
                    .textAlign(TextAlign.Center)
                }
                .width(180)
                .height(72)
                .backgroundColor(this.dex === index ? '#ccc' : '#fff')
                .borderRadius(24)

                NavDestination() {
                  Text(`我是NavDestination第${item + 1}页内容`).fontSize(50)
                  Flex({ direction: FlexDirection.Row }) {
                    Row() {
                      Image($r('app.media.icon')).width(40).height(40).borderRadius(40).margin({ right: 15 })
                      Text('今天共有七节课').fontSize(30)
                    }.padding({ left: 15 })
                  }
                }.backgroundColor('#ccc')
                .title(`NavDestination${item + 1}`)
              }.onStateChange((isActivated: boolean) => {
                this.dex = index
              })
            }
          }, item => item)
        }
        .height('100%')
        .margin({ top: 12, left: 12 })
      }
      .mode(NavigationMode.Split)
      .hideTitleBar(true)
      .hideToolBar(true)
    }.height('100%')
  }
}
```

