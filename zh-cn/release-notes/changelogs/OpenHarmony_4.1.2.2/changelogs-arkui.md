# Arkui子系统变更说明
## cl.Arkui.1 QRCode组件的默认颜色、默认背景颜色和默认尺寸变更

**访问级别**

公开接口

**变更原因**

当前QRCode组件的默认颜色和默认尺寸不符合UX规范，因此依照UX规范做出变更。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的显示颜色和尺寸，提升了组件的默认显示效果。

**API Level**

7

**变更的接口/组件**

API 11前，二维码默认颜色是Color.Black，默认背景颜色是Color.White，组件默认宽高是父组件大小。

![qrcode](figures/qrcodeApi10.png)

API 11及以后，二维码默认颜色是系统资源中的`ohos_id_color_foreground`，默认背景颜色是系统资源中的`ohos_id_color_background`，组件默认宽度和高度都是240vp。

![qrcode](figures/qrcodeApi11.png)

**适配指导**

请查阅[QRCode组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-qrcode.md)文档进行适配。

示例代码:
```ts
// xxx.ets
@Entry
@Component
struct QRCodeExample {
  private value: string = 'hello world'
  build() {
    Column() {
      QRCode(this.value)
    }.width('100%').height('100%')
  }
}
```
## cl.arkui.2 Refresh变更

**访问级别**

公开接口

**变更原因**

UX增强导致的规格变更。

**变更影响**

1、默认刷新场景

API 11以前，Refresh组件嵌套子组件，默认场景，刷新组件下拉，子组件不跟随下移。滑动组件的边缘回弹效果和loading的移动是相互独立的。

![refresh](figures/refreshApi9Default.gif)

API 11及以后，Refresh组件嵌套子组件，刷新组件下拉，子组件下移。

![refresh](figures/refreshApi11Default.gif)

2、使用builder接口自定义刷新组件

API 11以前，Refresh组件嵌套子组件，自定义刷新组件，刷新组件的高度不大于64vp。滑动组件的边缘回弹效果和builder下拉同时生效。

![refresh](figures/refreshApi9Builder.gif)

API 11及以后，Refresh组件嵌套子组件，刷新组件下拉，子组件下移。自定义刷新组件builder的高度没有限制。

![refresh](figures/refreshApi11Builder.gif)

3、friction接口变更

API 11以前，Refresh下拉使用固定跟手系数，跟手系数可以通过friction接口设置。
API 11及以后，Refresh下拉使用动态跟手系数，下拉距离越大，跟手系数越小。通过friction设置的跟手系数不生效。

4、offset接口变更

API 11以前，Refresh组件可以使用offset接口设置loadingProgress开始显示时的下拉距离。
API 11以后，Refresh组件下拉16vp后开始显示loadingProgress图标，offset接口设置不生效。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.2.2 开始。

**变更的接口/组件**

Refresh

**适配指导**

1、默认刷新场景

请查阅[Refresh组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-refresh.md)文档进行适配

示例代码:

```ts
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State arr: String[] = ['0', '1', '2', '3', '4','5','6','7','8','9','10']

  build() {
    Column() {
      Refresh({ refreshing: $$this.isRefreshing}) {
        List() {
          ForEach(this.arr, (item: string) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }
          }, (item: string) => item)
        }
        .onScrollIndex((first: number) => {
          console.info(first.toString())
        })
        .width('100%')
        .height('100%')
        .divider({strokeWidth:1,color:Color.Yellow,startMargin:10,endMargin:10})
        .scrollBar(BarState.Off)
        .backgroundColor(Color.Yellow)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
      .onRefreshing(() => {
        setTimeout(() => {
          this.isRefreshing = false
        }, 2000)
        console.log('onRefreshing test')
      })
      .backgroundColor(0x89CFF0)
    }
  }
}
```

2、使用builder接口自定义刷新组件

请查阅[Refresh组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-refresh.md)文档进行适配

示例代码:

```ts
// xxx.ets
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State arr: String[] = ['0', '1', '2', '3', '4','5','6','7','8','9','10']
  @Builder
  customRefreshComponent()
  {
    Stack()
    {
      Row()
      {
        LoadingProgress().height(32)
        Text("正在刷新...").fontSize(16).margin({left:20})
      }
      .alignItems(VerticalAlign.Center)
    }.width("100%").align(Alignment.Center)
  }

  build() {
    Column() {
      Refresh({ refreshing: $$this.isRefreshing,builder:this.customRefreshComponent()}) {
        List() {
          ForEach(this.arr, (item: string) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }
          }, (item: string) => item)
        }
        .onScrollIndex((first: number) => {
          console.info(first.toString())
        })
        .width('100%')
        .height('100%')
        .divider({strokeWidth:1,color:Color.Yellow,startMargin:10,endMargin:10})
        .scrollBar(BarState.Off)
        .backgroundColor(Color.Yellow)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
      .onRefreshing(() => {
        setTimeout(() => {
          this.isRefreshing = false
        }, 2000)
        console.log('onRefreshing test')
      })
      .backgroundColor(0x89CFF0)
    }
  }
}
```

3、friction和offset接口变更

API 11及以后，friction和offset设置不生效，按系统默认UX效果实现，无需适配。