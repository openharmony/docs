# EmbeddedComponent

EmbeddedComponent用于支持在当前页面嵌入本应用内其他[EmbeddedUIExtensionAbility](../../apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)提供的UI。EmbeddedUIExtensionAbility在独立进程中运行，完成页面布局和渲染。

通常用于有进程隔离诉求的模块化开发场景。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 使用约束

EmbeddedComponent仅支持在拥有多进程权限的设备上使用。

EmbeddedComponent只能在UIAbility中使用，且被拉起的EmbeddedUIExtensionAbility需与UIAbility属于同一应用。

## 子组件

无

## 接口

EmbeddedComponent(loader: Want, type: EmbeddedType)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名                | 参数类型                                                   | 必填 | 参数描述                             |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------------------------ |
| loader                | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 要加载的EmbeddedUIExtensionAbility。 |
| type                  | [EmbeddedType](ts-appendix-enums.md#embeddedtype)                              | 是   | 提供方的类型。                       |

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

> **说明：**
>
> EmbeddedComponent组件宽高默认值和最小值均为10vp, 不支持如下与宽高相关的属性："constraintSize"、"aspectRatio"、"layoutWeight"、"flexBasis"、"flexGrow"和"flexShrink"。

## 事件

与屏幕坐标相关的事件信息会基于EmbeddedComponent的位置宽高进行坐标转换后传递给被拉起的EmbeddedUIExtensionAbility处理。

不支持[点击](ts-universal-events-click.md)等通用事件。仅支持以下事件：

### onTerminated

onTerminated(callback: Callback&lt;TerminationInfo&gt;)

被拉起的EmbeddedUIExtensionAbility通过调用`terminateSelfWithResult`或者`terminateSelf`正常退出时，触发本回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型   | 说明                                                                                     |
| -------  | ------ | ---------------------------------------------------------------------------------------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](#terminationinfo)> | 回调函数，入参用于接收EmbeddedUIExtensionAbility的返回结果，类型为[TerminationInfo](#terminationinfo)。 |

> **说明：**
>
> - 若EmbeddedUIExtensionAbility通过调用`terminateSelfWithResult`退出，其携带的信息会传给回调函数的入参；
> - 若EmbeddedUIExtensionAbility通过调用`terminateSelf`退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"。

### onError

onError(callback: ErrorCallback)

被拉起的EmbeddedUIExtensionAbility在运行过程中发生异常时触发本回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                                         | 说明      |
| ------ | ---------------------------------------------------------------------------- | --------- |
| callback    | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 回调函数，入参用于接收异常信息，类型为[BusinessError](../../apis-basic-services-kit/js-apis-base.md#businesserror)，可通过参数中的`code`、`name`和`message`获取错误信息并做处理。 |

> **说明：**
>
> 如下情形会触发本回调：
> - 通知提供方拉起EmbeddedUIExtensionAbility失败。
> - 通知提供方EmbeddedUIExtensionAbility切后台失败。
> - 通知提供方销毁EmbeddedUIExtensionAbility失败。
> - 提供方EmbeddedUIExtensionAbility异常退出。
> - 在EmbeddedUIExtensionAbility中嵌套使用EmbeddedComponent。

## TerminationInfo

用于表示被拉起的EmbeddedUIExtensionAbility的返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 属性名  | 类型   | 说明                                                 |
| ------- | ------ | ---------------------------------------------------  |
| code    | number | 被拉起EmbeddedUIExtensionAbility退出时返回的结果码。 |
| want    | [Want](../../apis-ability-kit/js-apis-app-ability-want.md)   | 被拉起EmbeddedUIExtensionAbility退出时返回的数据。   |

## 示例

本示例展示EmbeddedComponent组件和EmbeddedUIExtensionAbility的基础使用方式，示例应用的`bundleName`为"com.example.embeddeddemo", 被拉起的`EmbeddedUIExtensionAbility`为"ExampleEmbeddedAbility".

- 示例应用中的EntryAbility(UIAbility)加载首页文件：`pages/Index.ets`，其中内容如下：

  ```ts
  // pages/Index.ets -- UIAbility启动时加载此页面
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
            .onTerminated((info)=>{
              this.message = 'Termination: code = ' + info.code + ', want = ' + JSON.stringify(info.want);
            })
            .onError((error)=>{
              this.message = 'Error: code = ' + error.code;
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- EmbeddedComponent拉起的EmbeddedUIExtensionAbility在`ets/extensionAbility/ExampleEmbeddedAbility`文件中实现，内容如下：

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
      session.loadContent('pages/extension', storage);
    }

    onSessionDestroy(session: UIExtensionContentSession) {
      console.log(TAG, `onSessionDestroy`);
    }
  }
  ```

- EmbeddedUIExtensionAbility的入口页面文件`pages/extension.ets`内容如下：

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
          this.session?.terminateSelfWithResult({
            resultCode: 1,
            want: {
              bundleName: "com.example.embeddeddemo",
              abilityName: "ExampleEmbeddedAbility",
            }});
        })
      }.width('100%').height('100%')
    }
  }
  ```

- 最后，示例应用的`module.json5`中的"extensionAbilities"中需要增加一项，具体内容如下：
  ```json
  {
    "name": "ExampleEmbeddedAbility",
    "srcEntry": "./ets/extensionAbility/ExampleEmbeddedAbility.ets",
    "type": "embeddedUI"
  }
  ```
