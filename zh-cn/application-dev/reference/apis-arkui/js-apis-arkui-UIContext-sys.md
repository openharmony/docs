# @ohos.arkui.UIContext (UIContext)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

在Stage模型中，WindowStage/Window可以通过[loadContent](arkts-apis-window-Window.md#loadcontent9)接口加载页面并创建UI实例，并将页面内容渲染到关联窗口中，因此UI实例和窗口一一关联。与具体UI实例执行上下文相关的全局UI接口，在调用时会通过追溯调用链跟踪UI上下文，确定具体的UI实例。若在非UI页面中或者未绑定当前UI上下文的异步回调中调用这类接口，可能无法跟踪到当前UI上下文，导致接口执行失败。

UIContext用于获取与具体UI实例关联的上下文，使开发者可在对应UI实例上调用上下文相关的UI接口。本模块提供组件压暗和冻结、键盘样式配置、资源缓存清理、背景亮度取色、不可见Image组件图像内存回收以及组件截图等系统能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[Class (UIContext)](arkts-apis-uicontext-uicontext.md)。

## UIContext

以下API需先使用ohos.window中的[getUIContext()](arkts-apis-window-Window.md#getuicontext10)方法获取UIContext实例，再通过此实例调用对应方法。或者可以通过自定义组件内置方法[getUIContext()](arkui-ts/ts-custom-component-api.md#getuicontext)获取。本文中UIContext对象以uiContext表示。

### setDynamicDimming<sup>12+<sup>

setDynamicDimming(id: string, value: number): void

通过该方法设置组件的压暗程度。


> **说明：**
>
> 设置该属性后设置其他效果类属性会导致效果冲突。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| id | string | 是 | 组件id。 |
| value | number | 是 | 组件压暗程度取值范围[0,1], 由0到1逐渐变亮。 |

**示例：**

```ts
@Entry
@Component
struct Index {
  @State
  myCount : number = 100

  build() {
    Column(){
      Image($r('app.media.testImage')).width(500).height(800).id("test")
    }.width("100%").height("100%").onClick(()=>{
      this.getUIContext().setDynamicDimming("test",1)
      this.getUIContext()?.animateTo({duration:5000 },()=>{
        this.getUIContext().setDynamicDimming("test",0)
      })
    })
  }
}
```
![api-switch-overview](../apis-arkui/figures/dynamicDimming.gif)

### freezeUINode<sup>18+</sup>

freezeUINode(id: string, isFrozen: boolean): void

通过id设置组件冻结状态，防止组件被标记为脏从而触发布局更新。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型    | 必填   | 说明      |
| --- | --- | --- | --- |
| id | string | 是 | 组件的id。|
| isFrozen | boolean | 是 | 是否冻结组件。<br>true表示冻结组件，false表示不冻结组件。<br>默认值为false，传入`undefined`时按false处理。|

**错误码：**

以下错误码详情请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The caller is not a system application. |

```ts
@Entry
@Component
struct Index {
  @State columnWidth1: string = '100%';
  @State currentIndex: number = 0;
  private controller: TabsController = new TabsController();

  build() {
    Column() {
      Tabs({ 
        barPosition: BarPosition.Start, 
        index: this.currentIndex, 
        controller: this.controller 
      }) {
        TabContent() {
          Column()
          .width(this.columnWidth1)
          .height('100%')
          .backgroundColor('#00CB87')
        }
        .tabBar('green')
        .id('tab1')
        .onWillHide(() => {
          // id为tab1的TabContent隐藏的时候设置该节点的冻结状态为true。
          this.getUIContext().freezeUINode('tab1', true);
        })
        .onWillShow(() => {
          // id为tab1的TabContent显示的时候设置该节点的冻结状态为false。
          this.getUIContext().freezeUINode('tab1', false);
        })

        TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#007DFF')
        }
        .tabBar('blue')
        .id('tab2')
        .onWillHide(() => {
          // id为tab2的TabContent隐藏的时候设置该节点的冻结状态为true。
          this.getUIContext().freezeUINode('tab2', true);
        })
        .onWillShow(() => {
          // 当id为tab2的TabContent显示的时候，将id为tab1的节点的冻结状态设置为true。
          // 通过状态变量改变id为tab1的节点中Column的宽度。因该节点的冻结状态为true，标脏至TabContent时终止标记，不触发布局。
          this.getUIContext().freezeUINode('tab1', true);
          this.columnWidth1 = '50%';
          // 配置延时任务。
          setTimeout(() => {
            // 将id为tab1的节点的冻结状态设置为false，重新触发标记和布局。
            this.getUIContext().freezeUINode('tab1', false);
            // 通过状态变量更新tab1内部Column节点的宽度，设置this.columnWidth1为'20%'。
            this.columnWidth1 = '20%';
          }, 5000);
        })

         TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#FFBF00')
        }
        .tabBar('yellow')
        .id('tab3')
        .onWillHide(() => {
          // 当id为tab3的TabContent隐藏的时候设置该节点的冻结状态为true。
          this.getUIContext().freezeUINode('tab3', true);
        })
        .onWillShow(() => {
          // id为tab3的TabContent显示的时候设置该节点的冻结状态为false。
          this.getUIContext().freezeUINode('tab3', false);
        })

      }
      .vertical(false)
      .barMode(BarMode.Fixed)
      .barWidth(360)
      .barHeight(56)
      .animationDuration(0)
      .onChange((index: number) => {
        this.currentIndex = index;
      })
      .width(360)
      .height(296)
      .margin({ top: 52 })
      .backgroundColor('#F1F3F5')
    }.width('100%')
  }
}
```

### freezeUINode<sup>18+</sup>

freezeUINode(uniqueId: number, isFrozen: boolean): void

通过uniqueId设置组件的冻结状态，防止组件被标记为脏从而触发布局更新。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型    | 必填   | 说明      |
| --- | --- | --- | --- |
| uniqueId | number | 是 | 组件的uniqueId。|
| isFrozen | boolean | 是 | 是否冻结组件。<br>true表示冻结组件，false表示不冻结组件。<br>默认值为false，传入`undefined`时按false处理。|

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The caller is not a system application. |

```ts
@Entry
@Component
struct Index {
  @State columnWidth1: string = '100%';
  @State currentIndex: number = 0;
  private controller: TabsController = new TabsController();

  build() {
    Column() {
      Tabs({ 
        barPosition: BarPosition.Start, 
        index: this.currentIndex, 
        controller: this.controller 
      }) {
        TabContent() {
          Column()
          .width(this.columnWidth1)
          .height('100%')
          .backgroundColor('#00CB87')
        }
        .tabBar('green')
        .id('tab1')
        .onWillHide(() => {
          // 通过id查询以获取对应节点的uniqueId。
          const node = this.getUIContext().getFrameNodeById('tab1');
          if (node !== null) {
            const uniqueId = node.getUniqueId();
            // 当id为tab1的TabContent隐藏的时候，通过uniqueId设置该节点的冻结状态为true。
            this.getUIContext().freezeUINode(uniqueId, true);
          }
        })
        .onWillShow(() => {
          // 通过id查询以获取对应节点的uniqueId。
          const node = this.getUIContext().getFrameNodeById('tab1');
          if (node !== null) {
            const uniqueId = node.getUniqueId();
            // 当id为tab1的TabContent显示的时候，通过uniqueId设置该节点的冻结状态为false。
            this.getUIContext().freezeUINode(uniqueId, false);
          }
        })

        TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#007DFF')
        }
        .tabBar('blue')
        .id('tab2')
        .onWillHide(() => {
          // 通过id查询以获取对应节点的uniqueId。
          const node = this.getUIContext().getFrameNodeById('tab2');
          if (node !== null) {
            const uniqueId = node.getUniqueId();
            // 当id为tab2的TabContent隐藏的时候，通过uniqueId设置该节点的冻结状态为true。
            this.getUIContext().freezeUINode(uniqueId, true);
          }
        })
        .onWillShow(() => {
          // 通过id查询以获取对应节点的uniqueId。
          const node = this.getUIContext().getFrameNodeById('tab1');
          if (node !== null) {
            const uniqueId = node.getUniqueId();
            // 当id为tab2的TabContent显示的时候，通过uniqueId设置id为tab1的节点的冻结状态为true。
            // 通过状态变量改变id为tab1的节点内部Column节点的宽度。由于id为tab1的节点冻结状态为true，标脏至该TabContent时会终止标记，并且不会从该节点开始触发布局。
            this.getUIContext().freezeUINode(uniqueId, true);
            this.columnWidth1 = '50%';

            // 设置延时任务。
            setTimeout(() => {
              // 将id为tab1的节点的冻结状态设置为false，以重新触发标记和布局。
              this.getUIContext().freezeUINode(uniqueId, false);
              this.columnWidth1 = '20%';
            }, 5000);
          }
        })

         TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#FFBF00')
        }
        .tabBar('yellow')
        .id('tab3')
        .onWillHide(() => {
          // 通过id查询以获取对应节点的uniqueId。
          const node = this.getUIContext().getFrameNodeById('tab3');
          if (node !== null) {
            const uniqueId = node.getUniqueId();
            // 当id为tab3的TabContent隐藏时，通过uniqueId将该节点的冻结状态设置为true。
            this.getUIContext().freezeUINode(uniqueId, true);
          }
        })
        .onWillShow(() => {
          // 通过id查询以获取对应节点的uniqueId。
          const node = this.getUIContext().getFrameNodeById('tab3');
          if (node !== null) {
            const uniqueId = node.getUniqueId();
            // 当id为tab3的TabContent显示的时候，通过uniqueId设置该节点的冻结状态为false。
            this.getUIContext().freezeUINode(uniqueId, false);
          }
        })

      }
      .vertical(false)
      .barMode(BarMode.Fixed)
      .barWidth(360)
      .barHeight(56)
      .animationDuration(0)
      .onChange((index: number) => {
        this.currentIndex = index;
      })
      .width(360)
      .height(296)
      .margin({ top: 52 })
      .backgroundColor('#F1F3F5')
    }.width('100%')
  }
}
```

### setKeyboardAppearanceConfig<sup>20+</sup>

setKeyboardAppearanceConfig(uniqueId: number, config: KeyboardAppearanceConfig): void

设置键盘样式，包括模糊效果和流光效果，仅在沉浸式模式下生效，沉浸式定义可参见[KeyboardAppearance](../apis-arkui/arkui-ts/ts-text-common.md#keyboardappearance15枚举说明)。其中，流光效果依赖于模糊效果，若需启用流光效果，则需同时开启模糊效果，最终显示效果取决于输入法处理。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型    | 必填   | 说明      |
| --- | --- | --- | --- |
| uniqueId | number | 是 | 组件节点对应的UniqueId。取值范围大于等于0。 |
| config | [KeyboardAppearanceConfig](../apis-arkui/arkui-ts/ts-text-common-sys.md#keyboardappearanceconfig20) | 是 | 键盘样式配置参数。|

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The caller is not a system application. |

输入框和搜索框组件设置键盘样式使用示例：

```ts
@Entry
@Component
struct IMEGradient {
  textInputController: TextInputController = new TextInputController();
  searchController: SearchController = new SearchController();

  build() {
    Column() {
      TextInput({ controller: this.textInputController})
        .margin(10)
        .border({ width: 1 })
        .onWillAttachIME((client) => {
          this.getUIContext().setKeyboardAppearanceConfig(client.nodeId,
            {
              gradientMode: KeyboardGradientMode.LINEAR_GRADIENT,
              fluidLightMode: KeyboardFluidLightMode.BACKGROUND_FLUID_LIGHT
            })
        })
        .keyboardAppearance(KeyboardAppearance.IMMERSIVE)

      Search({ controller: this.searchController })
        .margin(10)
        .border({ width: 1 })
        .onWillAttachIME((client) => {
          this.getUIContext().setKeyboardAppearanceConfig(client.nodeId,
            {
              gradientMode: KeyboardGradientMode.LINEAR_GRADIENT,
              fluidLightMode: KeyboardFluidLightMode.BACKGROUND_FLUID_LIGHT
            })
        })
        .keyboardAppearance(KeyboardAppearance.IMMERSIVE)
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)
  }
}
```

### clearResourceCache<sup>12+</sup>

clearResourceCache(): void

清除跨模块（[HSP](../../quick-start/in-app-hsp.md)包）访问资源时生成的资源对象缓存。清除缓存后，下次访问该模块资源的加载时间会增加。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
@Entry
@Component
struct MyStateSample {
  build() {
    Column() {
      Button("clearResourceCache")
        .onClick((event: ClickEvent) => {
          this.getUIContext().clearResourceCache()
        })
        .width('100%')
    }
  }
}
```

### getLuminanceSampler<sup>23+</sup>

getLuminanceSampler(target: TargetInfo): LuminanceSampler | undefined

获取[LuminanceSampler](arkts-apis-uicontext-luminancesampler-sys.md)取色对象，通过该对象设置背景亮度取色参数、注册亮度变化监听回调、取消注册监听回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。 

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型    | 必填   | 说明      |
| --- | --- | --- | --- |
| target | [TargetInfo](arkts-apis-uicontext-i.md#targetinfo18) | 是 | 目标组件的标识。 |

**返回值**：

| 类型                                              | 说明                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [LuminanceSampler](arkts-apis-uicontext-luminancesampler-sys.md) | 返回背景亮度取色器。 |

**示例：**

参考[offBackgroundLuminanceChange](arkts-apis-uicontext-luminancesampler-sys.md#offbackgroundluminancechange23)接口的示例。

### recycleInvisibleImageMemory<sup>23+</sup>

recycleInvisibleImageMemory(enabled: boolean): void

设置不可见Image组件的内存回收开关（[组件可见性](../../../application-dev/ui/arkts-manage-components-visibility.md)是指组件在屏幕上的显示状态）。开启后，当Image组件不参与渲染时，其内部持有的图像内存资源将在系统空闲时（如应用退后台）主动回收，以降低应用系统内存占用；当组件重新参与渲染时，将按需重新加载相关图像资源。

该接口主要用于内存敏感场景下的优化，适用于图片数量较多、页面频繁切换前后台或组件可见性变化较为明显的场景。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。 

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明 |
| -------- | ------- | ---- | ---- |
| enabled  | boolean | 是   | 是否开启不可见Image组件的内存回收能力。<br/>true表示开启内存回收，Image组件在不可见时将主动释放图像内存资源；<br/>false表示关闭内存回收，Image组件在不可见时仍保留图像内存资源。<br/>默认值为false，传入`undefined`时将恢复为默认值。 |

**示例：**

```ts
@Entry
@Component
struct ImageRecycleSample {
  build() {
    Column({ space: 12 }) {
      Button('Enable recycle invisible image memory')
        .onClick(() => {
          this.getUIContext().recycleInvisibleImageMemory(true)
        })

      Button('Disable recycle invisible image memory')
        .onClick(() => {
          this.getUIContext().recycleInvisibleImageMemory(false)
        })
    }
    .width('100%')
    .padding(16)
  }
}
```

## ComponentSnapshot<sup>12+</sup>

以下API需先使用UIContext中的[getComponentSnapshot()](arkts-apis-uicontext-uicontext.md#getcomponentsnapshot12)方法获取ComponentSnapshot对象，再通过此实例调用对应方法。

缩放、平移、旋转等图形变换属性只对被截图组件的子组件生效；对目标组件本身应用图形变换属性不生效，显示的是还是图形变换前的效果。

### getWithRange<sup>20+</sup>
getWithRange(start: NodeIdentity, end: NodeIdentity, isStartRect: boolean, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>;

传入两个组件的ID，获取范围内的组件的截图，并通过Promise返回结果。

> **说明：**
>
> start对应的组件和end对应的组件必须为同一棵组件树上的组件，且start对应的组件需要为end对应的组件的祖先组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ------- |
| start   | [NodeIdentity](arkts-apis-uicontext-t.md#nodeidentity20) | 是    | 范围开始的组件的ID。 |
| end   | [NodeIdentity](arkts-apis-uicontext-t.md#nodeidentity20) | 是    | 范围结束的组件的ID。 |
| isStartRect   | boolean | 是    | 范围是否以开始组件的外接矩形为准。<br/>true表示以开始组件的外接矩形为准，false表示以结束组件的外接矩形为准。<br/>默认值为true。 |
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | 否    | 截图相关的自定义参数，不支持region参数。 |

**返回值：**

| 类型                            | 说明       |
| -------- | -------- |
| image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 截图返回的结果。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)、[截图错误码](errorcode-snapshot.md)和[接口调用异常错误码](errorcode-internal.md)。

| 错误码ID  | 错误信息                |
| ------ | ------- |
| 202    | The caller is not a system application. |
| 100001 | Invalid ID detected. |
| 160003 | Unsupported color space or dynamic range mode in snapshot options. |

**示例：** 

```ts
import { image } from '@kit.ImageKit';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined

  build() {
    Column() {
      Row() {
        Row() {
          Row() {
            Column() {
              Text('Text1').id('text1')
              Text('Text2').id('text2')
              Row() {
                Text('Text3').id('text3')
              }.id('root5').backgroundColor('#E4E8F0')
            }
            .width('80%')
            .height('80%')
            .justifyContent(FlexAlign.SpaceAround)
            .backgroundColor('#C1D1F0')
            .id('root4')
          }
          .width('80%')
          .height('80%')
          .justifyContent(FlexAlign.Center)
          .backgroundColor('#FFEEF0')
          .id('root3')
          .backgroundBlurStyle(BlurStyle.Thin, { colorMode: ThemeColorMode.LIGHT })
        }
        .width('80%')
        .height('80%')
        .justifyContent(FlexAlign.Center)
        .backgroundColor('#D5D5D5')
        .id('root2')
      }
      .width('50%')
      .height('50%')
      .justifyContent(FlexAlign.Center)
      .backgroundColor('#E4E8F0')
      .id('root1')

      Row() {
        Button("getWithRange")
          .onClick(() => {
            this.getUIContext()
              .getComponentSnapshot()
              .getWithRange('root2', 'root4', true)
              .then((pixmap: image.PixelMap) => {
                this.pixmap = pixmap
              })
              .catch((err: Error) => {
                console.error("error: " + err)
              })
          }).margin(10)
      }.justifyContent(FlexAlign.SpaceAround)

      Row() {
        Image(this.pixmap).width(200).height(300).border({ color: Color.Black, width: 2 }).margin(5)
      }.justifyContent(FlexAlign.SpaceAround)
    }
    .id('root')
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

![zh-cn_image_getWithRange](figures/image-getWithRange.gif)
