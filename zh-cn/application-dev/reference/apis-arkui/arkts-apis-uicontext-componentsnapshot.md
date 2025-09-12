# Class (ComponentSnapshot)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->
提供获取组件截图的能力，包括已加载的组件的截图和没有加载的组件的截图。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 以下API需先使用UIContext中的[getComponentSnapshot()](./arkts-apis-uicontext-uicontext.md#getcomponentsnapshot12)方法获取ComponentSnapshot对象，再通过此实例调用对应方法。
>
> - 缩放、平移、旋转等图形变换属性只对被截图组件的子组件生效；对目标组件本身应用图形变换属性不生效，显示的是还是图形变换前的效果。

## get<sup>12+</sup>

get(id: string, callback: AsyncCallback<image.PixelMap>, options?: componentSnapshot.SnapshotOptions): void

获取已加载的组件的截图，传入组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)，找到对应组件进行截图。通过回调返回结果。

> **说明：** 
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| id       | string                                                       | 是   | 目标组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)。<br/>**说明：** 不支持未挂树组件，当传入的组件标识是离屏或缓存未挂树的节点时，系统不会对其进行截图。 |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | 是   | 截图返回结果的回调。                                         |
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | 否    | 截图相关的自定义参数。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Invalid ID.                                                  |

**示例：** 

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(150).height(150).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.img'))
          .autoResize(true)
          .width(150)
          .height(150)
          .margin(5)
          .id("root")
      }

      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot().get("root", (error: Error, pixmap: image.PixelMap) => {
            if (error) {
              console.error('error: ${JSON.stringify(error)}');
              return;
            }
            this.pixmap = pixmap;
          }, { scale: 2, waitUntilRenderFinished: true });
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## get<sup>12+</sup>

get(id: string, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

获取已加载的组件的截图，传入组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)，找到对应组件进行截图。使用Promise异步回调。

> **说明：**
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| id     | string | 是   | 目标组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)。<br/>**说明：** 不支持未挂树组件，当传入的组件标识是离屏或缓存未挂树的节点时，系统不会对其进行截图。 |
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | 否    | 截图相关的自定义参数。 |

**返回值：**

| 类型                                                         | 说明             |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象，返回组件截图对象。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Invalid ID.                                                  |

**示例：** 

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(150).height(150).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.icon'))
          .autoResize(true)
          .width(150)
          .height(150)
          .margin(5)
          .id("root")
      }

      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot()
            .get("root", { scale: 2, waitUntilRenderFinished: true })
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap;
            })
            .catch((err: Error) => {
              console.error("error: " + err);
            })
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## createFromBuilder<sup>12+</sup>

createFromBuilder(builder: CustomBuilder, callback: AsyncCallback<image.PixelMap>, delay?: number, checkImageStatus?: boolean, options?: componentSnapshot.SnapshotOptions): void

传入[CustomBuilder](arkui-ts/ts-types.md#custombuilder8)自定义组件，系统对其进行离屏构建后进行截图，并通过回调返回结果。
> **说明：** 
>
> 由于需要等待组件构建、渲染成功，离屏截图的回调有500ms以内的延迟，不适宜使用在对性能敏感的场景。
>
> 部分执行耗时任务的组件可能无法及时在截图前加载完成，因此会截取不到加载成功后的图像。例如：加载网络图片的[Image](arkui-ts/ts-basic-components-image.md)组件、[Web](../apis-arkweb/arkts-basic-components-web.md)组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8)         | 是   | 自定义组件构建函数。<br/>**说明：** 不支持全局builder。<br/>builder的根组件宽高为0时，截图操作会失败并抛出100001错误码。      |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | 是   | 截图返回结果的回调。支持在回调中获取离屏组件绘制区域坐标和大小。 |
| delay   | number | 否    | 指定触发截图指令的延迟时间。当布局中使用了图片组件时，需要指定延迟时间，以便系统解码图片资源。资源越大，解码需要的时间越长，建议尽量使用不需要解码的PixelMap资源。<br/> 当使用PixelMap资源或对Image组件设置syncload为true时，可以配置delay为0，强制不等待触发截图。该延迟时间并非指接口从调用到返回的时间，由于系统需要对传入的builder进行临时离屏构建，因此返回的时间通常要比该延迟时间长。<br/>**说明：** 截图接口传入的builder中，不应使用状态变量控制子组件的构建，如果必须要使用，在调用截图接口时，也不应再有变化，以避免出现截图不符合预期的情况。<br/> 默认值：300 <br/> 单位：毫秒 <br/> 取值范围：[0, +∞)，小于0时按默认值处理。 |
| checkImageStatus  | boolean | 否    | 指定是否允许在截图之前，校验图片解码状态。如果为true，则会在截图之前检查所有Image组件是否已经解码完成，如果没有完成检查，则会放弃截图并返回异常。<br/>默认值：false|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12) | 否    | 截图相关的自定义参数。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | The builder is not a valid build function.                   |
| 160001   | An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled. |

**示例：** 

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct ComponentSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();

  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }

  build() {
    Column() {
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot().createFromBuilder(() => {
            this.RandomBuilder()
          },
            (error: Error, pixmap: image.PixelMap) => {
              if (error) {
                console.error('error: ${JSON.stringify(error)}');
                return;
              }
              this.pixmap = pixmap;
            }, 320, true, { scale: 2, waitUntilRenderFinished: true });
        })
      Image(this.pixmap)
        .margin(10)
        .height(200)
        .width(200)
        .border({ color: Color.Black, width: 2 })
    }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
  }
}
```

## createFromBuilder<sup>12+</sup>

createFromBuilder(builder: CustomBuilder, delay?: number, checkImageStatus?: boolean, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

传入[CustomBuilder](arkui-ts/ts-types.md#custombuilder8)自定义组件，系统对其进行离屏构建后进行截图，并通过回调返回结果。

> **说明：** 
>
> 由于需要等待组件构建、渲染成功，离屏截图的回调有500ms以内的延迟，不适宜使用在对性能敏感的场景。
>
> 部分执行耗时任务的组件可能无法及时在截图前加载完成，因此会截取不到加载成功后的图像。例如：加载网络图片的[Image](arkui-ts/ts-basic-components-image.md)组件、[Web](../apis-arkweb/arkts-basic-components-web.md)组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                                    |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------------------------- |
| builder | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8) | 是   | 自定义组件构建函数。<br/>**说明：** 不支持全局builder。<br/>builder的根组件宽高为0时，截图操作会失败并抛出100001错误码。 |
| delay   | number | 否    | 指定触发截图指令的延迟时间。当布局中使用了图片组件时，需要指定延迟时间，以便系统解码图片资源。资源越大，解码需要的时间越长，建议尽量使用不需要解码的PixelMap资源。<br/> 当使用PixelMap资源或对Image组件设置syncload为true时，可以配置delay为0，强制不等待触发截图。该延迟时间并非指接口从调用到返回的时间，由于系统需要对传入的builder进行临时离屏构建，因此返回的时间通常要比该延迟时间长。<br/>**说明：** 截图接口传入的builder中，不应使用状态变量控制子组件的构建，如果必须要使用，在调用截图接口时，也不应再有变化，以避免出现截图不符合预期的情况。<br/> 默认值：300 <br/> 单位：毫秒<br/> 取值范围：[0, +∞)，小于0时按默认值处理。|
| checkImageStatus  | boolean | 否    | 指定是否允许在截图之前，校验图片解码状态。如果为true，则会在截图之前检查所有Image组件是否已经解码完成，如果没有完成检查，则会放弃截图并返回异常。<br/>默认值：false|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)           | 否    | 截图相关的自定义参数。 |

**返回值：**

| 类型                                                         | 说明             |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象，返回组件截图对象。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | The builder is not a valid build function.                   |
| 160001   | An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled. |

**示例：** 

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct ComponentSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();

  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }

  build() {
    Column() {
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot()
            .createFromBuilder(() => {
              this.RandomBuilder()
            }, 320, true, { scale: 2, waitUntilRenderFinished: true })
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap;
            })
            .catch((err: Error) => {
              console.error("error: " + err);
            })
        })
      Image(this.pixmap)
        .margin(10)
        .height(200)
        .width(200)
        .border({ color: Color.Black, width: 2 })
    }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
  }
}
```

## getSync<sup>12+</sup>

getSync(id: string, options?: componentSnapshot.SnapshotOptions): image.PixelMap

获取已加载的组件的截图。传入组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)，找到对应组件进行截图，同步等待截图完成返回[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)。本方法会阻塞主线程，请谨慎使用。接口的最大等待时间为3s，如果3s后未返回将会抛出异常。

> **说明：**
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| id   | string | 是    | 目标组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)。 <br/>**说明：** 不支持未挂树组件，当传入的组件标识是离屏或缓存未挂树的节点时，系统不会对其进行截图。|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | 否    | 截图相关的自定义参数。 |

**返回值：**

| 类型                            | 说明       |
| ----------------------------- | -------- |
| image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 截图返回的结果。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID  | 错误信息                |
| ------ | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001 | Invalid ID. |
| 160002 | Timeout. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(200).height(200).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.img'))
          .autoResize(true)
          .width(200)
          .height(200)
          .margin(5)
          .id("root")
      }

      Button("click to generate UI snapshot")   
        .onClick(() => {
          try {
            let pixelmap =
              this.getUIContext().getComponentSnapshot().getSync("root", { scale: 2, waitUntilRenderFinished: true });
            this.pixmap = pixelmap;
          } catch (error) {
            console.error("getSync errorCode: " + error.code + " message: " + error.message);
          }
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## getWithUniqueId<sup>15+</sup>

getWithUniqueId(uniqueId: number, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

获取已加载的组件的截图，传入组件的[uniqueId](js-apis-arkui-frameNode.md#getuniqueid12)，找到对应组件进行截图。使用Promise异步回调。

> **说明：**
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| uniqueId   | number | 是    | 目标组件的[uniqueId](js-apis-arkui-frameNode.md#getuniqueid12) <br/>**说明：** 不支持未挂树组件，当传入的组件标识是离屏或缓存未挂树的节点时，系统不会对其进行截图。|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | 否    | 截图相关的自定义参数。 |

**返回值：**

| 类型                                                         | 说明             |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象，返回组件截图对象。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Invalid ID.                                                  |

**示例：**

```ts
import { NodeController, FrameNode, typeNode } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public node: FrameNode | null = null;
  public imageNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.node = new FrameNode(uiContext);
    this.node.commonAttribute.width('100%').height('100%');

    let image = typeNode.createNode(uiContext, 'Image');
    image.initialize($r('app.media.img')).width('100%').height('100%').autoResize(true);
    this.imageNode = image;

    this.node.appendChild(image);
    return this.node;
  }
}

@Entry
@Component
struct SnapshotExample {
  private myNodeController: MyNodeController = new MyNodeController();
  @State pixmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(200).height(200).border({ color: Color.Black, width: 2 }).margin(5)
        NodeContainer(this.myNodeController).width(200).height(200).margin(5)
      }

      Button("UniqueId get snapshot")
        .onClick(() => {
          try {
            this.getUIContext()
              .getComponentSnapshot()
              .getWithUniqueId(this.myNodeController.imageNode?.getUniqueId(),
                { scale: 2, waitUntilRenderFinished: true })
              .then((pixmap: image.PixelMap) => {
                this.pixmap = pixmap;
              })
              .catch((err: Error) => {
                console.log("error: " + err);
              })
          } catch (error) {
            console.error('UniqueId get snapshot Error: ${JSON.stringify(error)}');
          }
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## getSyncWithUniqueId<sup>15+</sup>

getSyncWithUniqueId(uniqueId: number, options?: componentSnapshot.SnapshotOptions): image.PixelMap

获取已加载的组件的截图，传入组件的[uniqueId](js-apis-arkui-frameNode.md#getuniqueid12)，找到对应组件进行截图。同步等待截图完成返回[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)。

> **说明：**
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| uniqueId   | number | 是    | 目标组件的[uniqueId](js-apis-arkui-frameNode.md#getuniqueid12)。<br/>**说明：** 不支持未挂树组件，当传入的组件标识是离屏或缓存未挂树的节点时，系统不会对其进行截图。|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | 否    | 截图相关的自定义参数。 |

**返回值：**

| 类型                            | 说明       |
| ----------------------------- | -------- |
| image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 截图返回的结果。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID  | 错误信息                |
| ------ | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001 | Invalid ID. |
| 160002 | Timeout. |

**示例：**

```ts
import { NodeController, FrameNode, typeNode } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public node: FrameNode | null = null;
  public imageNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.node = new FrameNode(uiContext);
    this.node.commonAttribute.width('100%').height('100%');

    let image = typeNode.createNode(uiContext, 'Image');
    image.initialize($r('app.media.img')).width('100%').height('100%').autoResize(true);
    this.imageNode = image;

    this.node.appendChild(image);
    return this.node;
  }
}

@Entry
@Component
struct SnapshotExample {
  private myNodeController: MyNodeController = new MyNodeController();
  @State pixmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(200).height(200).border({ color: Color.Black, width: 2 }).margin(5)
        NodeContainer(this.myNodeController).width(200).height(200).margin(5)
      }

      Button("UniqueId getSync snapshot")
        .onClick(() => {
          try {
            this.pixmap = this.getUIContext()
              .getComponentSnapshot()
              .getSyncWithUniqueId(this.myNodeController.imageNode?.getUniqueId(),
                { scale: 2, waitUntilRenderFinished: true });
          } catch (error) {
            console.error('UniqueId getSync snapshot Error: ${JSON.stringify(error)}');
          }
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## createFromComponent<sup>18+</sup>

createFromComponent\<T extends Object>(content: ComponentContent\<T>, delay?: number, checkImageStatus?: boolean, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

将传入的content对象进行截图，使用Promise异步回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| content  | [ComponentContent\<T>](./js-apis-arkui-ComponentContent.md)         | 是   | 当前UIContext显示的组件内容。      |
| delay   | number | 否    | 指定触发截图指令的延迟时间。当布局中使用了图片组件时，需要指定延迟时间，以便系统解码图片资源。资源越大，解码需要的时间越长，建议尽量使用不需要解码的PixelMap资源。<br/> 当使用PixelMap资源或对Image组件设置syncload为true时，可以配置delay为0，强制不等待触发截图。该延迟时间并非指接口从调用到返回的时间，由于系统需要对传入的builder进行临时离屏构建，因此返回的时间通常要比该延迟时间长。<br/>**说明：** 截图接口传入的builder中，不应使用状态变量控制子组件的构建，如果必须要使用，在调用截图接口时，也不应再有变化，以避免出现截图不符合预期的情况。<br/> 取值范围：[0,+∞) ，小于0时按默认值处理。<br/>默认值：300 <br/> 单位：毫秒|
| checkImageStatus  | boolean | 否    | 指定是否允许在截图之前，校验图片解码状态。如果为true，则会在截图之前检查所有Image组件是否已经解码完成，如果没有完成检查，则会放弃截图并返回异常。<br/>默认值：false|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12) | 否    | 截图相关的自定义参数。可以指定截图时图形侧绘制pixelmap的缩放比例与是否强制等待系统执行截图指令前所有绘制指令都执行完成之后再截图。 |

**返回值：**

| 类型                            | 说明       |
| ----------------------------- | -------- |
| Promise<image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)>  | Promise对象，返回组件截图对象。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[截图错误码](errorcode-snapshot.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | The builder is not a valid build function.                   |
| 160001   | An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled. |

**示例：** 

```ts
import { image } from '@kit.ImageKit';
import { ComponentContent } from '@kit.ArkUI';

class Params {
  text: string | undefined | null = "";

  constructor(text: string | undefined | null) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  ReusableChildComponent({ text: params.text })
}

@Component
struct ReusableChildComponent {
  @Prop text: string | undefined | null = "";

  aboutToReuse(params: Record<string, object>) {
    console.error('ReusableChildComponent Reusable ${JSON.stringify(error)}');
  }

  aboutToRecycle(): void {
    console.log("ReusableChildComponent aboutToRecycle " + this.text);
  }

  build() {
    Column() {
      Text(this.text)
        .fontSize(90)
        .fontWeight(FontWeight.Bold)
        .margin({ bottom: 36 })
        .width('100%')
        .height('100%')
    }.backgroundColor('#FFF0F0F0')
  }
}

@Entry
@Component
struct Index {
  @State pixmap: image.PixelMap | undefined = undefined;
  @State message: string | undefined | null = "hello";
  uiContext: UIContext = this.getUIContext();

  build() {
    Row() {
      Column() {
        Button("点击生成组件截图")
          .onClick(() => {
            let uiContext = this.getUIContext();
            let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
            this.uiContext.getComponentSnapshot()
              .createFromComponent(contentNode
                , 320, true, { scale: 2, waitUntilRenderFinished: true })
              .then((pixmap: image.PixelMap) => {
                this.pixmap = pixmap;
              })
              .catch((err: Error) => {
                console.error("error: " + err);
              })
          })
        Image(this.pixmap)
          .margin(10)
          .height(200)
          .width(200)
          .border({ color: Color.Black, width: 2 })
      }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
    }
    .width('100%')
    .height('100%')
  }
}
```

