# 虚拟屏的创建和使用 (ArkTS) (仅对系统应用开放)

## 场景介绍

虚拟屏是系统中的一种抽象，允许应用创建一个虚拟显示设备，不依赖于物理显示器。它通过Surface提供一个渲染目标，应用可以将图像、视频等内容渲染到这个虚拟显示设备上。

## 接口说明

以下为虚拟屏的常用接口。更多接口说明请参考[ @ohos.screen (屏幕)(系统接口)](../reference/apis-arkui/js-apis-screen-sys.md)。

| 接口名                                                       | 描述                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| createVirtualScreen(options:VirtualScreenOption): Promise&lt;Screen&gt; | 创建虚拟屏幕，使用Promise异步回调。          |
| setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt; | 设置虚拟屏幕的Surface，使用Promise异步回调。 |
| makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;): Promise&lt;number&gt; | 将屏幕设置为镜像模式，使用Promise异步回调。  |
| stopMirror(mirrorScreen:Array&lt;number&gt;): Promise&lt;void&gt; | 停止屏幕的镜像模式，使用Promise异步回调。    |
| destroyVirtualScreen(screenId:number): Promise&lt;void&gt;   | 销毁虚拟屏幕，使用Promise异步回调。          |

## 开发步骤

1. 创建虚拟屏。

   - 定义用于创建虚拟屏的各项参数。

   - 通过createVirtualScreen()创建虚拟屏。

   需特别注意的是，使用createVirtualScreen()创建虚拟屏时，需要申请`ohos.permission.CAPTURE_SCREEN`权限，配置方式请参见[申请使用受限权限](../security/AccessToken/declare-permissions-in-acl.md)。

2. 将渲染目标SurfaceID绑定在虚拟屏上。

   为了使虚拟屏能够准确呈现所需的图像内容，需要将渲染目标的SurfaceID绑定到虚拟屏上。具体操作分为两步：

   - 首先，通过getXComponentSurfaceId()方法获取Surface的唯一标识符SurfaceID。SurfaceID作为一个关键标识，承载着与屏幕图像信息相关的重要数据，借助它可以获取并灵活设置当前屏幕的各种图像属性，例如图像的分辨率、像素格式等。

   - 然后，使用setVirtualScreenSurface()方法将获取到的SurfaceID与虚拟屏进行关联设置，从而确保虚拟屏能够正确接收和处理对应的图像数据。

3. 通过makeMirror()创建物理屏的镜像，并映射到虚拟屏上。

   在成功创建虚拟屏之后，应用程序可依据具体的业务需求，通过调用makeMirror()方法来开启物理屏的镜像功能。该方法会将物理屏幕上正在显示的内容完整地复制，并映射到之前创建的虚拟屏上，实现物理屏与虚拟屏之间的实时同步显示。

4. 停止镜像。

   当不再需要物理屏与虚拟屏之间的镜像同步功能时，可通过调用stopMirror()方法来停止镜像。这一操作将终止物理屏内容向虚拟屏的映射过程，使虚拟屏恢复到独立状态。

5. 销毁虚拟屏。

   当整个业务流程结束，不再需要使用虚拟屏时，应及时释放相关资源，以避免内存泄漏和系统资源的浪费。通过调用destroyVirtualScreen接口，可安全、有效地将虚拟屏销毁，释放其所占用的系统资源。

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { screen } from '@kit.ArkUI';

@Entry
@Component
struct VirtualScreen {
  xComponentController: XComponentController = new XComponentController();

  build() {
    RelativeContainer() {
      Column() {
        XComponent({
          type: XComponentType.SURFACE,
          controller: this.xComponentController
        })
      }
      Button('虚拟屏')
        .onClick(() => {
          // screenVirtualScreen用于存储创建的虚拟屏对象
          let screenVirtualScreen: screen.Screen | null = null;
          class VirtualScreenOption {
            name: string = '';
            width: number = 0;
            height: number = 0;
            density: number = 0;
            surfaceId: string = '';
          }
          // option定义创建虚拟屏所需的参数
          let option: VirtualScreenOption = {
            name: 'screen01',
            width: 1080,
            height: 2340,
            density: 2,
            surfaceId: ''
          };
          // 创建虚拟屏
          screen.createVirtualScreen(option, (err: BusinessError, data: screen.Screen) => {
            const errCode: number = err.code;
            if (errCode) {
              console.error(`Failed to create the virtual screen. Code:${err.code},message is ${err.message}`);
              return;
            }
            screenVirtualScreen = data;
            console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));
            // 获取surfaceId
            let surfaceId = this.xComponentController.getXComponentSurfaceId();
            screen.setVirtualScreenSurface(screenVirtualScreen.id, surfaceId, (err: BusinessError) => {
              const errCode: number = err.code;
              if (errCode) {
                console.error(`Failed to set the surface for the virtual screen. Code:${err.code},message is ${err.message}`);
                return;
              }
              console.info('Succeeded in setting the surface for the virtual screen.');
            });
            let mirrorScreenIds: Array<number> = [screenVirtualScreen.id];
            // 获取当前所有屏幕
            screen.getAllScreens((err: BusinessError, data: Array<screen.Screen>) => {
              const errCode: number = err.code;
              if (errCode) {
                console.error(`Failed to get all screens. Code:${err.code},message is ${err.message}`);
                return;
              }
              // 通过makeMirror创建物理屏的镜像，并映射到虚拟屏上
              let mainScreenId = data.find(item => item.sourceMode === 0)?.id;
              screen.makeMirror(mainScreenId, mirrorScreenIds, (err: BusinessError, data: number) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to set screen mirroring. Code:${err.code},message is ${err.message}`);
                  return;
                }
                console.info(`Succeeded in setting screen mirroring. Data:${data}`);
              });
              // 停止镜像
              screen.stopMirror(mirrorScreenIds, (err: BusinessError) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to stop mirror screens. Code:${err.code},message is ${err.message}`);
                  return;
                }
                console.info('Succeeded in stopping mirror screens.');
              });
              // 销毁虚拟屏
              screen.destroyVirtualScreen(mirrorScreenIds[0], (err: BusinessError) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to destroy the virtual screen. Code:${err.code},message is ${err.message}`);
                  return;
                }
                console.info('Succeeded in destroying the virtual screen.');
              });
            });
          });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```