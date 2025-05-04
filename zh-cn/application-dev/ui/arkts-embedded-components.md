# EmbeddedComponent组件

EmbeddedComponent组件是一个用于在应用中嵌入其他应用或服务的组件，主要用于在应用中实现跨模块、跨进程的嵌入式界面集成，其核心目的是通过模块化设计提升应用灵活性和用户体验。

EmbeddedComponent组件允许在当前页面中嵌入同一应用内其他EmbeddedUIExtensionAbility提供的UI内容，这些UI运行在独立进程中，提供了更高的安全性和稳定性。

## 基本概念

- [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)组件

  EmbeddedComponent组件用于在当前页面嵌入本应用内其他EmbeddedUIExtensionAbility提供的UI。它允许开发者将应用的某些功能或界面嵌入到另一个界面中，实现更灵活的用户界面设计，通常用于需要进程隔离的模块化开发场景。

- [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)组件

  提供方应用中定义使用，用于实现跨进程界面嵌入功能，仅能被同应用的UIAbility拉起，并需在拥有多进程权限的场景下使用。

## 主要特性

- 进程隔离

  被嵌入的UI运行在独立进程，与主UIAbility进程隔离，提高了应用稳定性。

- 模块化开发

  可以将功能模块拆分为独立的EmbeddedUIExtensionAbility，便于团队协作和维护。

## 使用约束

- 设备要求

  EmbeddedComponent组件仅支持在拥有多进程权限的设备上使用。

- 应用范围

  EmbeddedComponent组件只能在UIAbility中使用，且被拉起的EmbeddedUIExtensionAbility需与UIAbility属于同一应用。

- 属性限制

  EmbeddedComponent组件支持[通用属性](../reference/apis-arkui/arkui-js/js-components-common-attributes.md)，且宽高默认值和最小值均为10vp；
  
  不支持如下与宽高相关的属性：
  "constraintSize"、"aspectRatio"、"layoutWeight"、"flexBasis"、"flexGrow"和"flexShrink"。

## 事件调用

与屏幕坐标相关的事件信息会基于EmbeddedComponent的位置宽高进行坐标转换后传递给被拉起的EmbeddedUIExtensionAbility处理。

EmbeddedComponent组件不支持[点击](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md)等通用事件，仅支持onTerminated事件和onError事件。

### onTerminated事件

```ts
onTerminated(callback: Callback<TerminationInfo>)
```

被拉起的EmbeddedUIExtensionAbility通过调用`terminateSelfWithResult`或者`terminateSelf`正常退出时，触发本回调函数。

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------  | ------ | ---------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| callback | [Callback](../reference/apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](#terminationinfo)> | 是 | 回调函数，入参用于接收EmbeddedUIExtensionAbility的返回结果，类型为[TerminationInfo](#terminationinfo)。 |

> **说明：**
>
> - 若EmbeddedUIExtensionAbility通过调用`terminateSelfWithResult`退出，其携带的信息会传给回调函数的入参；
> - 若EmbeddedUIExtensionAbility通过调用`terminateSelf`退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"。

### onError事件

```ts
onError(callback: ErrorCallback)
```

被拉起的EmbeddedUIExtensionAbility在运行过程中发生异常时触发本回调。

**参数：**

| 参数名 | 类型                                                                         | 必填                                                                       | 说明      |
| ------ | ---------------------------------------------------------------------------- | --------- | --------- |
| callback    | [ErrorCallback](../reference/apis-basic-services-kit/js-apis-base.md#errorcallback) | 是 | 回调函数，入参用于接收异常信息，类型为[BusinessError](../reference/apis-basic-services-kit/js-apis-base.md#businesserror)，可通过参数中的`code`、`name`和`message`获取错误信息并做处理。 |

> **说明：**
>
> 如下情形会触发本回调：
> - 通知提供方拉起EmbeddedUIExtensionAbility失败。
> - 通知提供方EmbeddedUIExtensionAbility切后台失败。
> - 通知提供方销毁EmbeddedUIExtensionAbility失败。
> - 提供方EmbeddedUIExtensionAbility异常退出。
> - 在EmbeddedUIExtensionAbility中嵌套使用EmbeddedComponent。

## 场景示例

该示例简单展示了EmbeddedComponent组件和EmbeddedUIExtensionAbility的基础使用方式。

### 预期效果

1. 启动应用，由于手机默认未开启多进程，会出现报错信息；

2. 手机测试开启多进程后重启手机，开启多进程的hdc命令如下：

```bash
hdc shell param set persist.sys.abilityms.multi_process_model true
```

3. 启动应用，界面显示正常；

4. 点击 terminateSelfWithResult 按钮，提供方内容小时，页面显示 onTerminated 信息。

### 加载项首页

```ts
import { Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'Message: '
  private want: Want = {
    bundleName: "com.example.embeddeddemo",
    abilityName: "ExampleEmbeddedAbility",
  }

  build() {
    Row() {
      Column() {
        Text(this.message).fontSize(30)
        EmbeddedComponent(this.want, EmbeddedType.EMBEDDED_UI_EXTENSION)
          .width('100%')
          .height('90%')
          .onTerminated((info) => {
            // 点击extension页面内的terminateSelfWithResult按钮后触发onTerminated回调，文本框显示如下信息
            this.message = 'Termination: code = ' + info.code + ', want = ' + JSON.stringify(info.want);
          })
          .onError((error) => {
            // 失败或异常触发onError回调，文本框显示如下报错内容
            this.message = 'Error: code = ' + error.code;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### EmbeddedComponent拉起的ExampleEmbeddedAbility实现代码

```ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[ExampleEmbeddedAbility]'

export default class ExampleEmbeddedAbility extends EmbeddedUIExtensionAbility {
  onCreate() {
    console.log(TAG, `onCreate`);
  }

  onForeground() {
    console.log(TAG, `onForeground`);
  }

  onBackground() {
    console.log(TAG, `onBackground`);
  }

  onDestroy() {
    console.log(TAG, `onDestroy`);
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.log(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
    let param: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(param);
    // 加载pages/extension.ets页面内容
    session.loadContent('pages/extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `onSessionDestroy`);
  }
}
```

### ExampleEmbeddedAbility的入口页面文件实现代码

该代码文件需要在 main_pages.json 中配置该页面路径

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

let storage = LocalStorage.getShared()

@Entry(storage)
@Component
struct Extension {
  @State message: string = 'EmbeddedUIExtensionAbility Index';
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');

  build() {
    Column() {
      Text(this.message)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Button("terminateSelfWithResult").fontSize(20).onClick(() => {
        // 点击按钮后调用terminateSelfWithResult退出
        this.session?.terminateSelfWithResult({
          resultCode: 1,
          want: {
            bundleName: "com.example.embeddeddemo",
            abilityName: "ExampleEmbeddedAbility",
          }
        });
      })
    }.width('100%').height('100%')
  }
}
```

### 添加配置项

在 module.json5 配置文件的 "extensionAbilities" 标签下增加 ExampleEmbeddedAbility 配置

```json
{
  "name": "ExampleEmbeddedAbility",
  "srcEntry": "./ets/extensionAbility/ExampleEmbeddedAbility.ets",
  "type": "embeddedUI"
}
```

![zh-cn_image_0000001502261185](figures/zh-cn_image_0000001502261185.jpg)
![zh-cn_image_0000001502261065](figures/zh-cn_image_0000001502261065.jpg)
![zh-cn_image_0000001502263453](figures/zh-cn_image_0000001502263453.jpg)
<!--RP1--><!--RP1End-->