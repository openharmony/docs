# UIExtensionComponent (系统接口)

UIExtensionComponent用于支持在本页面内嵌入其他应用提供的UI。展示的内容在另外一个进程中运行，本应用并不参与其中的布局和渲染。

通常用于有进程隔离诉求的模块化开发场景。

> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块为系统接口。

## 使用约束

本组件不支持预览。

被拉起的Ability必须是带UI的Ability扩展，如何实现带UI的Ability扩展请参考[实现带UI的Ability扩展](../../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)。

必须显示设置组件宽高为非0有效值。

不支持滚动到边界后，传递至上层继续滚动的场景。当UIExtensionComponent组件使用方和扩展Ability都支持内容滚动时，通过手势滚动会导致UIExtensionComponent内外同时响应，包括但不限于[Scroll](ts-container-scroll.md)、[Swiper](ts-container-swiper.md)、[List](ts-container-list.md)、[Grid](ts-container-grid.md)等滚动容器。内外手势同时滚动场景的规避方法可参考[示例2](#示例2)。


## 子组件

无

## 接口

UIExtensionComponent(want: Want, options?: UIExtensionOptions)

**参数：**

| 参数名                | 参数类型                                                   | 必填 | 参数描述           |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| want                  | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 要加载的Ability。  |
| options<sup>11+</sup> | [UIExtensionOptions](#uiextensionoptions11)                | 否   | 需要传递的构造项。 |

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

## 事件

不支持[点击](ts-universal-events-click.md)等通用事件。

将事件经过坐标转换后传递给对端Ability处理。

支持以下事件：

### onRemoteReady

onRemoteReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<UIExtensionProxy>)

UIExtensionAbility连接完成时的回调，之后可使用proxy向被拉起的Ability发送数据。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| proxy                        | UIExtensionProxy | 用于向对端Ability发送数据。                          |

### onReceive

onReceive(callback: ReceiveCallback)

收到被拉起的Ability发送的数据时触发的回调。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| data                        | [ReceiveCallback](#receivecallback14) | 收到来自对端Ability的数据。                 |

### onResult<sup>(deprecated)</sup>

onResult(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<{code: number; want?: Want}>)

被拉起的Ability扩展调用terminateSelfWithResult时会先触发本回调函数，再触发OnRelease。

本回调内可处理对端Ability的结果数据，可参考[AbilityResult](../../apis-ability-kit/js-apis-inner-ability-abilityResult.md)。

> **说明：**
> 从 API version 10 开始支持，从 API version 12 开始废弃，建议使用[onTerminated](#onterminated12)替代。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| code                        | number | 收到来自对端Ability的处理結果code。                          |
| want                        | Want | 收到来自对端Ability的处理結果[Want](../../apis-ability-kit/js-apis-app-ability-want.md)。 |

### onRelease<sup>(deprecated)</sup>

onRelease(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number>)

用于处理被拉起的Ability销毁时的回调。

被拉起的Ability扩展调用terminateSelfWithResult或者terminateSelf时会触发本回调，此时releaseCode为0，即正常销毁。

被拉起的Ability扩展意外Crash或被kill时，触发本回调，此时releaseCode为1。

> **说明：**
> 从 API version 10 开始支持，从 API version 12 开始废弃，建议使用[onTerminated](#onterminated12)或者[onError](#onerror)替代。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| releaseCode                        | number | 对端Ability销毁时的code，0为正常销毁，1为异常销毁。                          |

### onError

onError(callback:[ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback))

被拉起的Ability扩展在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| err                        | [BusinessError](../../apis-basic-services-kit/js-apis-base.md#businesserror) | 报错信息。    |

### onTerminated<sup>12+<sup>

onTerminated(callback: Callback&lt;TerminationInfo&gt;)

被拉起的UIExtensionAbility通过调用`terminateSelfWithResult`或者`terminateSelf`正常退出时，触发本回调函数。

**参数：**

| 参数名   | 类型   | 说明                                                                                     |
| -------  | ------ | ---------------------------------------------------------------------------------------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](#terminationinfo12)> | 回调函数，入参用于接收UIExtensionAbility的返回结果，类型为[TerminationInfo](#terminationinfo12)。 |

> **说明：**
>
> - 若UIExtensionAbility通过调用`terminateSelfWithResult`退出，其携带的信息会传给回调函数的入参；
> - 若UIExtensionAbility通过调用`terminateSelf`退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"。

### TerminationInfo<sup>12+<sup>

用于表示被拉起的UIExtensionAbility通过调用`terminateSelfWithResult`或者`terminateSelf`正常退出时的返回结果。

| 属性名  | 类型   | 说明                                                 |
| ------- | ------ | ---------------------------------------------------  |
| code    | number | 被拉起UIExtensionAbility退出时返回的结果码。 |
| want    | [Want](../../apis-ability-kit/js-apis-app-ability-want.md)   | 被拉起UIExtensionAbility退出时返回的数据。   |

## ReceiveCallback<sup>14+<sup>
type ReceiveCallback = Callback\<Record\<string, Object\>\>

用于封装被拉起的Ability发送的数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| data                        | Record\<string, Object\> | 收到来自对端Ability的数据。                 |

## UIExtensionOptions<sup>11+</sup>
用于在UIExtensionComponent进行构造的时传递可选的构造参数。

**参数：**

| 参数名               | 参数类型                                 | 必填 | 参数描述                                                                                                      |
| ----                 | ---------------------------------------- | ---- | ---------------                                                                                               |
| isTransferringCaller | boolean                                  | 否   | 在使用UIExtensionComponent嵌套时，设置当前UIExtensionComponent是否转发上一级的Caller信息。</br> 默认值：false。 |
| placeholder<sup>12+<sup> | [ComponentContent](../js-apis-arkui-ComponentContent.md)       | 否   | 设置占位符，在UIExtensionComponent与UIExtensionAbility建立连接前显示。 |
| dpiFollowStrategy<sup>12+<sup> | [DpiFollowStrategy](ts-container-ui-extension-component-sys.md#dpifollowstrategy12)                  | 否   | 提供接口支持设置DPI跟随宿主或跟随UIExtensionAbility。</br> 默认值：FOLLOW_UI_EXTENSION_ABILITY_DPI。 |
| areaChangePlaceholder<sup>14+<sup> | Record<string, [ComponentContent](../js-apis-arkui-ComponentContent.md)>       | 否   | 设置尺寸变化占位符，在UIExtensionComponent尺寸发生变化并且UIExtension内部渲染未完成时显示, key值支持"FOLD_TO_EXPAND"(折叠展开尺寸变化)、"UNDEFINED"(默认尺寸变化)。 |

## DpiFollowStrategy<sup>12+</sup>

| 名称                             | 描述             |
| -------------------------------- | --------------- |
| FOLLOW_HOST_DPI                  | 表示DPI跟随宿主。 |
| FOLLOW_UI_EXTENSION_ABILITY_DPI  | 表示DPI跟随UIExtensionAbility。 |

## UIExtensionProxy

用于在双方建立连接成功后，组件使用方向被拉起的Ability发送数据、订阅和取消订阅注册。

### send

send(data: Record\<string, Object\>): void

用于在双方建立连接成功后，组件使用方向被拉起的Ability发送数据的场景，提供异步发送数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 参数类型                                     | 必填   | 参数描述            |
| ---- | ---------------------------------------- | ---- | --------------- |
| data | Record\<string, Object\> | 是    | 异步发送给被拉起的扩展Ability的数据。 |

### sendSync<sup>11+</sup>

sendSync(data: Record\<string, Object\>): Record\<string, Object\>

用于在双方建立连接成功后，组件使用方向被拉起的Ability发送数据的场景，提供同步发送数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 参数类型                                     | 必填   | 参数描述            |
| ---- | ---------------------------------------- | ---- | --------------- |
| data | Record\<string, Object\> | 是    | 同步发送给被拉起的扩展Ability的数据。 |

**返回值：**

| 类型 | 描述 |
| ---- | ----|
| Record\<string, Object\> | 扩展Ability回复的数据。 |

**错误码：**

| 错误号 | 描述 |
| ---- | ----|
| 100011 | 扩展Ability未注册同步回调 |
| 100012 | 数据发送失败 |

### on('asyncReceiverRegister')<sup>11+</sup>

on(type: 'asyncReceiverRegister', callback: Callback\<UIExtensionProxy\>): void

用于在双方建立连接成功后，组件使用方订阅被拉起的Ability发生异步注册的场景。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 参数类型 |必填 | 参数描述 |
| ------ | -------- |---- | ------- |
| type   | string | 是 | 代表订阅扩展Ability发生异步注册回调。 |
| callback   | Callback\<UIExtensionProxy\> | 是 | 订阅扩展Ability注册setReceiveDataCallback后触发的回调。 |

### on('syncReceiverRegister')<sup>11+</sup>

on(type: 'syncReceiverRegister', callback: Callback\<UIExtensionProxy\>): void;

用于在双方建立连接成功后，组件使用方订阅被拉起的Ability发生同步注册的场景。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 参数类型 |必填 | 参数描述 |
| ------ | -------- |---- | ------- |
| type   | string | 是 | 订阅扩展Ability发生同步注册回调。 |
| callback   | Callback\<UIExtensionProxy\> | 是 | 扩展Ability注册setReceiveDataForResultCallback后触发的回调。 |

### off('asyncReceiverRegister')<sup>11+</sup>

off(type: 'asyncReceiverRegister', callback?: Callback\<UIExtensionProxy\>): void

用于在双方建立连接成功后，组件使用方取消订阅被拉起的Ability发生异步注册的场景。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 参数类型 | 必填 | 参数描述 |
| ------ | -------- | ----- | ------- |
| type   | string | 是 | 取消订阅扩展Ability发生异步注册回调。 |
| callback | Callback\<UIExtensionProxy\> | 否 | 为空代表取消订阅所有扩展Ability异步注册后触发回调。<br> 非空代表取消订阅异步对应回调。 |

### off('syncReceiverRegister')<sup>11+</sup>

off(type: 'syncReceiverRegister', callback?: Callback\<UIExtensionProxy\>): void

用于在双方建立连接成功后，组件使用方取消订阅被拉起的Ability发生同步注册的场景。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 参数类型 | 必填 | 参数描述 |
| ------ | -------- | ----- | ------- |
| type   | string | 是 | 取消订阅扩展Ability发生同步注册回调。 |
| callback | Callback\<UIExtensionProxy\> | 否 | 为空代表取消订阅所有扩展Ability同步注册后触发回调<br> 非空代表取消订阅同步对应回调。 |

## 示例

### 示例1 (加载UIextension)

本示例仅展示组件使用的方法和扩展的Ability，实际运行需在设备中安装bundleName为"com.example.uiextensionprovider"，abilityName为"UIExtensionProvider"的Ability扩展。

```ts
// 组件使用示例：
import { ComponentContent } from '@kit.ArkUI';
class Params {
}
@Builder
function LoadingBuilder(params: Params) {
  Column() {
   LoadingProgress()
      .color(Color.Blue)
  }
}
@Builder
function AreaChangePlaceholderBuilder(params: Params) {
  Column() {
  }
  .width('100%')
  .height('100%')
  .backgroundColor(Color.Orange)
}
@Entry
@Component
struct Second {
  @State message1: string = 'Hello World 1'
  @State message2: string = 'Hello World 2'
  @State message3: string = 'Hello World 3'
  @State visible: Visibility = Visibility.Hidden
  @State wid: number = 300
  @State hei: number = 300
  private proxy: UIExtensionProxy | null = null;
  private initPlaceholder = new ComponentContent(this.getUIContext(), wrapBuilder(LoadingBuilder), new Params);
  private areaChangePlaceholder = new ComponentContent(this.getUIContext(), wrapBuilder(AreaChangePlaceholderBuilder), new Params);


  build() {
    Row() {
      Column() {
        Text(this.message1).fontSize(30)
        Text(this.message2).fontSize(30)
        Text(this.message3).fontSize(30)
        UIExtensionComponent({
          bundleName : "com.example.newdemo",
          abilityName: "UIExtensionProvider",
          parameters: {
            "ability.want.params.uiExtensionType": "sys/commonUI"
          }},
          {
            placeholder: this.initPlaceholder,
            areaChangePlaceholder: {
              "FOLD_TO_EXPAND" : this.areaChangePlaceholder,
            }
          })
          .width(this.wid)
          .height(this.hei)
          .border({width: 5, color: Color.Blue})
          .onReceive((data) => {
            console.info('Lee onReceive, for test')
            this.message3 = JSON.stringify(data['data'])
          })
          .onTerminated((info) => {
            console.info('onTerminated: code =' + info.code + ', want = ' + JSON.stringify(info.want));
          })
          .onRemoteReady((proxy) => {
            console.info('onRemoteReady, for test')
            this.proxy = proxy

            this.proxy.on("syncReceiverRegister", syncRegisterCallback1);
            // this.proxy.on("syncReceiverRegister", syncRegisterCallback2);


            // this.proxy.off("syncReceiverRegister");

            // this.proxy.off("syncReceiverRegister", (proxy) => {
            //   console.info("off invoke for test, type is syncReceiverRegister");
            // });

            this.proxy.on("asyncReceiverRegister", (proxy1) => {
              console.info("on invoke for test, type is asyncReceiverRegister");
            });
            //
            // this.proxy.off("asyncReceiverRegister");
          })

        Button("点击向UIExtensionAbility发送数据").onClick(() => {
          if (this.proxy != undefined) {
            this.proxy.send({data: "你好1"})

            try {
              let re = this.proxy.sendSync({data: "你好2"})
              console.info("for test, re=" + JSON.stringify(re));
            } catch (err) {
              console.error(`sendSync failed for test. errCode=${err.code}, msg=${err.message}`);
            }
          }
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}

function syncRegisterCallback1(proxy: UIExtensionProxy) {
  console.info("on invoke for test, syncRegisterCallback1, type is syncReceiverRegister");
}

function syncRegisterCallback2(proxy: UIExtensionProxy) {
  console.info("on invoke for test, syncRegisterCallback2, type is syncReceiverRegister");
}
```

```ts
// 扩展入口文件UIExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[UIExtAbility]'
export default class UIExtAbility extends UIExtensionAbility {
  
  onCreate() {
    console.log(TAG, `UIExtAbility onCreate`)
  }

  onForeground() {
    console.log(TAG, `UIExtAbility onForeground`)
  }

  onBackground() {
    console.log(TAG, `UIExtAbility onBackground`)
  }

  onDestroy() {
    console.log(TAG, `UIExtAbility onDestroy`)
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionCreate, want: ${JSON.stringify(want)}`)
    let param: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(param);
    session.loadContent('pages/extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`)
  }
}
```

```ts
// 扩展Ability入口页面文件extension.ets
import { UIExtensionContentSession } from '@kit.AbilityKit';

let storage = LocalStorage.getShared()
AppStorage.setOrCreate('message', 'UIExtensionAbility')

@Entry(storage)
@Component
struct Extension {
  @StorageLink('message') storageLink: string = '';
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
  pathStack: NavPathStack = new NavPathStack()

  @Builder
  PageMap(name: string) {
    if (name === "hello") {
      pageOneTmp()
    }
  }

  onPageShow() {
    if (this.session != undefined) {
      this.session.setReceiveDataCallback((data)=> {
        this.storageLink = JSON.stringify(data)
        console.info("invoke for test, handle callback set by setReceiveDataCallback successfully");
      })

      this.session.setReceiveDataForResultCallback(func1)
    }
  }

  build() {
    Navigation(this.pathStack) {
      Row() {
        Column() {
          Text(this.storageLink)
            .fontSize(20)
            .fontWeight(FontWeight.Bold)
          Button("点击向Component发送数据").onClick(()=>{
            if (this.session != undefined) {
              this.session.sendData({"data": 543321})
              console.info('send 543321, for test')
            }
          })
          Button("terminate").onClick(()=> {
            if (this.session != undefined) {
              this.session.terminateSelf();
            }
            storage.clear()
          })
          Button("terminate with result").onClick(()=>{
            if (this.session != undefined) {
              this.session.terminateSelfWithResult({
                resultCode: 0,
                want: {
                  bundleName: "myBundleName",
                  parameters: { "result": 123456 }
                }
              })
            }
            storage.clear()
          })

          Button("点击跳转").onClick(()=> {
            this.pathStack.pushPath({ name: "hello"})
          })
        }
      }
      .height('100%')
    }.navDestination(this.PageMap)
    .mode(NavigationMode.Stack)
  }
}

// pageOne
@Component
export struct pageOneTmp {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    NavDestination() {
      Column() {
        Text("Hello World")
      }.width('100%').height('100%')
    }.title("pageOne")
    .onBackPressed(() => {
      const popDestinationInfo = this.pathStack.pop() // 弹出路由栈栈顶元素
      console.log('pop' + '返回值' + JSON.stringify(popDestinationInfo))
      return true
    })
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack
    })
  }
}

function func1(data: Record<string, Object>): Record<string, Object> {
  let linkToMsg: SubscribedAbstractProperty<string> = AppStorage.link('message');
  linkToMsg.set(JSON.stringify(data))
  console.info("invoke for test, handle callback set by setReceiveDataForResultCallback successfully");
  return data;
}

```

### 示例2 (设置滚动手势)

本示例展示了当UIExtensionComponent组件使用方和扩展的Ability同时使用[Scroll](ts-container-scroll.md)容器的场景，通过对UIExtensionComponent设置手势拦截处理，实现当UIExtensionComponent内部滚动时，外部组件不响应滚动。

手势使用方式：  
组件内部滚动：手指在组件内部进行滚动操作；
组件外部滚动：拖动外部滚动条进行滚动。

实际运行时需先在设备中安装bundleName为"com.example.uiextensionprovider"，abilityName为"UIExtensionProvider"的Ability扩展。

```ts
// 组件使用示例
@Entry
@Component
struct Second {
  @State message1: string = 'Hello World 1'
  @State message2: string = 'Hello World 2'
  @State message3: string = 'Hello World 3'
  @State visible: Visibility = Visibility.Hidden
  @State wid: number = 300
  @State hei: number = 300
  private scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6]

  build() {
    Column() {
      // 可滚动的容器组件
      Scroll(this.scroller) {
        Column() {
          Text(this.message1).fontSize(30)
          Text(this.message2).fontSize(30)
          Text(this.message3).fontSize(30)

          // 重复设置组件，构造滚动内容
          ForEach(this.arr, (item: number) => {
            UIExtensionComponent({
                bundleName: "com.example.newdemo",
                abilityName: "UIExtensionProvider",
                parameters: {
                  "ability.want.params.uiExtensionType": "sys/commonUI"
                }
              })
              .width(this.wid)
              .height(this.hei)
               // 设置手势拦截，UEC外部组件不响应滚动
              .gesture(PanGesture().onActionStart(() => {
                console.info('UIExtensionComponent PanGesture onAction')
              }))
              .border({ width: 5, color: Color.Blue })
              .onReceive((data) => {
                console.info('Lee onReceive, for test')
                this.message3 = JSON.stringify(data['data'])
              })
              .onTerminated((info) => {
                console.info('onTerminated: code =' + info.code + ', want = ' + JSON.stringify(info.want));
              })
              .onRemoteReady((proxy) => {
                console.info('onRemoteReady, for test')
              })
            }, (item: string) => item)
        }
        .width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)
      .onWillScroll((xOffset: number, yOffset: number, scrollState: ScrollState) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollStop(() => {
        console.info('Scroll Stop')
      })
    }
    .height('100%')
  }
}
```

```ts
// 扩展入口文件UIExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[UIExtAbility]'
export default class UIExtAbility extends UIExtensionAbility {
  
  onCreate() {
    console.log(TAG, `UIExtAbility onCreate`)
  }

  onForeground() {
    console.log(TAG, `UIExtAbility onForeground`)
  }

  onBackground() {
    console.log(TAG, `UIExtAbility onBackground`)
  }

  onDestroy() {
    console.log(TAG, `UIExtAbility onDestroy`)
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionCreate, want: ${JSON.stringify(want)}`)
    let param: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(param);
    session.loadContent('pages/extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`)
  }
}
```

```ts
// 扩展Ability入口页面文件extension.ets
@Entry
@Component
struct Extension {
  @StorageLink('message') storageLink: string = '';
  private scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8]

  build() {
    Column() {
      // 可滚动的容器组件
      Scroll(this.scroller) {
        Column() {
          Text('Test demo')
            .fontSize(20)
            .fontWeight(FontWeight.Bold)
          // 重复设置组件，构造滚动内容
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(Color.Pink)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: string) => item)
        }
      }

    }
    .height('100%')
  }
}
```
