# UIExtensionComponent

UIExtensionComponent用于支持在本页面内嵌入其他应用提供的UI。展示的内容在另外一个进程中运行，本应用并不参与其中的布局和渲染。

通常用于有进程隔离诉求的模块化开发场景。

> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本组件为系统接口。

## 使用约束

本组件不支持预览。

被拉起的Ability必须是带UI的Ability扩展，如何实现带UI的Ability扩展请参考[实现带UI的Ability扩展](../apis/js-apis-app-ability-uiExtensionAbility.md)。

必须显示设置组件宽高为非0有效值。

## 子组件

无

## 接口

UIExtensionComponent(want: Want, options?: UIExtensionOptions)

**参数：**

| 参数名                | 参数类型                                    | 必填 | 参数描述           |
| ----                  | ----------------------------------------    | ---- | ---------------    |
| want                  | [Want](../apis/js-apis-app-ability-want.md) | 是   | 要加载的Ability。  |
| options<sup>11+</sup> | [UIExtensionOptions](#uiextensionoptions11) | 否   | 需要传递的构造项。 |

## UIExtensionOptions<sup>11+</sup>
用于在UIExtensionComponent进行构造的时传递可选的构造参数。

**参数：**

| 参数名               | 参数类型                                 | 必填 | 参数描述                                                                                                      |
| ----                 | ---------------------------------------- | ---- | ---------------                                                                                               |
| isTransferringCaller | boolean                                  | 否   | 在使用UIExtensionComponent嵌套时，设置当前UIExtensionComponent是否转发上一级的Caller信息。</br> 默认值：false |

## UIExtensionProxy

用于在双方建立连接成功后，组件使用方向被拉起的Ability发送数据的场景，提供send方法。

### send

send(data: { [key: string]: Object }): void

**参数：**

| 参数名  | 参数类型                                     | 必填   | 参数描述            |
| ---- | ---------------------------------------- | ---- | --------------- |
| data | { [key: string]: Object } | 是    | 发送给被拉起的扩展Ability的数据。 |

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

## 事件

不支持[通用事件](ts-universal-events-click.md)。

将事件经过坐标转换后传递给对端Ability处理。

支持以下事件：

### onRemoteReady

onRemoteReady(callback: [Callback](../apis/js-apis-base.md#callback)\<UIExtensionProxy>)

UIExtensionAbility连接完成时的回调，之后可使用proxy向被拉起的Ability发送数据。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| proxy                        | UIExtensionProxy | 用于向对端Ability发送数据。                          |

### onReceive

onReceive(callback: [Callback](../apis/js-apis-base.md#callback)\<{ [key: string]: Object }>)

收到被拉起的Ability发送的数据时触发的回调。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| data                        | { [key: string]: Object } | 收到来自对端Ability的数据。                 |

### onResult

onResult(callback: [Callback](../apis/js-apis-base.md#callback)\<{code: number; want?: Want}>)

被拉起的Ability扩展调用terminateSelfWithResult时会先触发本回调函数，再触发OnRelease。

本回调内可处理对端Ability的结果数据，可参考[AbilityResult](../apis/js-apis-inner-ability-abilityResult.md)。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| code                        | number | 收到来自对端Ability的处理結果code。                          |
| want                        | Want | 收到来自对端Ability的处理結果[Want](../apis/js-apis-app-ability-want.md)。 |

### onRelease

onRelease(callback: [Callback](../apis/js-apis-base.md#callback)\<number>)

用于处理被拉起的Ability销毁时的回调。

被拉起的Ability扩展调用terminateSelfWithResult或者terminateSelf时会触发本回调，此时releaseCode为0，即正常销毁。

被拉起的Ability扩展意外Crash或被kill时，触发本回调，此时releaseCode为1。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| releaseCode                        | number | 对端Ability销毁时的code，0为正常销毁，1为异常销毁。                          |

### onError

onError(callback:[ErrorCallback](../apis/js-apis-base.md#errorcallback))

被拉起的Ability扩展在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| err                        | [BusinessError](../apis/js-apis-base.md#businesserror) | 报错信息。    |

## 示例

本示例仅展示组件使用的方法和扩展的Ability，实际运行需在设备中安装bundleName为"com.example.uiextensionprovider"，abilityName为"UIExtensionProvider"的Ability扩展。

```ts
// 组件使用示例：
import Want from '@ohos.app.ability.Want';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  private myProxy: UIExtensionProxy | null = null;
  want: Want = {
    bundleName: "com.example.uiextensionprovider",
    abilityName: "UIExtensionProvider",
    parameters: { "x": 12345, "y": "data" }
  }

  build() {
    Row() {
      Column() {
        Text(this.message).fontColor(Color.Red)
        UIExtensionComponent(this.want)
          .size({ width: "100%", height: "100%" })
          .onRemoteReady((proxy: UIExtensionProxy) => {
            this.message = "remote ready"
            this.myProxy = proxy
          })
          .onReceive((data: Object) => {
            this.message = JSON.stringify(data)
          })
          .onRelease((releaseCode: number) => {
            this.message = "Release: " + releaseCode
          })
          .onResult((data: Object) => {
            this.message = JSON.stringify(data)
          })
          .onError((error: ErrorObject) => {
            this.message = "onError: " + error.code + ", name: " + error.name + ", message: " + error.message
          })
        Button("sendData").onClick(() => {
          if (this.myProxy != null) {
            let a: Record<string, number> = { "x": 5678910 };
            this.myProxy.send(a)
          }
        })
      }
      .width("100%")
    }
    .height('100%')
  }
}

interface ErrorObject {
  code: number;
  name: string;
  message: string;
}
```

```ts
// 扩展入口文件UIExtensionProvider.ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility'
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'
import Want from '@ohos.app.ability.Want';
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
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'

let storage = LocalStorage.GetShared()

@Entry(storage)
@Component
struct Index {
  @State message: string = 'UIExtension'
  @State message2: string = 'message from comp'
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
  controller: TextInputController = new TextInputController()

  onPageShow() {
    if (this.session != undefined) { 
      this.session.setReceiveDataCallback((data: Object) => {
        this.message2 = "data come from comp"
        this.message = JSON.stringify(data)
      })
    }
  }

  build() {
    Row() {
      Column() {
        Text(this.message2)
        Text(this.message)
        Button("sendData")
          .onClick(() => {
            if (this.session != undefined) {
              let a: Record<string, string> = {"xxx": "data from extension"};
              this.session.sendData(a)
            }
          })
        Button("terminateSelf")
          .onClick(() => {
            if (this.session != undefined) {
              this.session.terminateSelf();
              storage.clear();
            }
          }).margin(5)
        Button("TerminateSelfWithResult")
          .onClick(() => {
            if (this.session != undefined) {
              this.session.terminateSelfWithResult({
                "resultCode": 0,
                "want": {
                  "bundleName": "myName"
                }
              });
              storage.clear();
            }
          }).margin(5)
      }
      .width('100%')
    }
    .height('100%')
  }
}

```
