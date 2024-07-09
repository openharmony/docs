# 拉起图片编辑类应用编辑图片
## 概述
[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)是PhotoEditor类型的ExtensionAbility组件，提供了在应用中图片编辑的能力。

[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)需要与startAbilityByType一起配合使用，开发者可以通过startAbilityByType拉起图片编辑面板，面板上将展示基于[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)实现的应用。[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)会在独立于拉起方的进程中运行，完成其页面的布局和渲染。流程示意图如下：

![](figures/photoEditorExtensionAbility.png)

[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)通过[PhotoEditorExtensionContext](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionContext.md)和UIExtensionContentSession提供相关能力。本文描述中称被启动的[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)为目标方，称通过startAbilityByType启动[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)的为调用方。
## 开发PhotoEditorExtensionAbility目标方
### 生命周期
[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)提供了onCreate、onForeground、onBackground、onDestroy、onStartContentEditing生命周期回调，根据需要重写对应的回调方法。

- onCreate：当[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)创建时回调，执行初始化业务逻辑操作。
- onForeground：当[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)从后台转到前台时触发。
- onBackground：当[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)从前台转到后台时触发。
- onDestroy：当[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)销毁时回调，可以执行资源清理等操作。
- onStartContentEditing：当[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)界面内容对象创建后调用，可以执行读取原始图片、加载page等操作。

### 开发步骤
开发者在实现一个[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)目标方时，需要在DevEco Studio工程中手动新建一个[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)，具体步骤如下：
1. 在工程Module对应的ets目录下，右键选择“New > Directory”，新建一个目录并可命名为[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)。
2. 在PhotoEditorUIExtAbility目录，右键选择“New > File”，新建一个.ets文件并可命名为PhotoEditorUIExtAbility.ets。
3. 打开PhotoEditorUIExtAbility.ets文件，导入[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)的依赖包，自定义类继承[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)并实现onCreate、onForeground、onBackground、onDestroy和onStartContentEditing生命周期回调。

    ```ts
    import { PhotoEditorExtensionAbility,UIExtensionContentSession,Want } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG = '[ExamplePhotoEditorAbility]';
    export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
      onCreate() {
        hilog.info(0x0000, TAG, 'onCreate');
      }

      onStartContentEditing(uri: string, want: Want, session: UIExtensionContentSession): void {
        hilog.info(0x0000, TAG, `onStartContentEditing want: ${JSON.stringify(want)}, uri: ${uri}`);

        const storage: LocalStorage = new LocalStorage({
          "session": session,
          "uri": uri
        } as Record<string, Object>);

        session.loadContent('pages/Index', storage);
      }

      onForeground() {
        hilog.info(0x0000, TAG, 'onForeground');
      }

      onBackground() {
        hilog.info(0x0000, TAG, 'onBackground');
      }

      onDestroy() {
        hilog.info(0x0000, TAG, 'onDestroy');
      }
    }

    ```
4. [PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)的onStartContentEditing中加载了入口页面文件pages/Index.ets，并将session、uri、实例对象等保存在LocalStorage中。

    ```ts
    import { common } from '@kit.AbilityKit';
    import { UIExtensionContentSession, Want } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { fileIo } from '@kit.CoreFileKit';
    import { image } from '@kit.ImageKit';

    const storage = LocalStorage.getShared()
    const TAG = '[ExamplePhotoEditorAbility]';

    @Entry
    @Component
    struct Index {
      @State message: string = 'editImg';
      @State originalImage: PixelMap | null = null;
      @State editedImage: PixelMap | null = null;
      private newWant ?: Want;

      aboutToAppear(): void {
        let originalImageUri = storage?.get<string>("uri") ?? "";
        hilog.info(0x0000, TAG, `OriginalImageUri: ${originalImageUri}.`);

        this.readImageByUri(originalImageUri).then(imagePixMap => {
          this.originalImage = imagePixMap;
        })
      }

      async readImageByUri(uri: string): Promise < PixelMap | null > {
        hilog.info(0x0000, TAG, "uri: " + uri);
        let file: fileIo.File | undefined;
        try {
          file = await fileIo.open(uri, fileIo.OpenMode.READ_ONLY);
          hilog.info(0x0000, TAG, "Original image file id: " + file.fd);

          let imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
          if(!imageSourceApi) {
            hilog.info(0x0000, TAG, "ImageSourceApi failed");
            return null;
          }
          let pixmap: image.PixelMap = await imageSourceApi.createPixelMap();
          if(!pixmap) {
            hilog.info(0x0000, TAG, "createPixelMap failed");
            return null;
          }
          this.originalImage = pixmap;
          fileIo.closeSync(file);
          return pixmap;
        } catch(e) {
          hilog.info(0x0000, TAG, `ReadImage failed:${e}`);
        } finally {
          fileIo.close(file);
        }
        return null;
      }

      build() {
        Row() {
          Column() {
            Text(this.message)
              .fontSize(50)
              .fontWeight(FontWeight.Bold)

            Button("RotateAndSaveImg").onClick(event => {
              hilog.info(0x0000, TAG, `Start to edit image and save.`);

              this.originalImage?.rotate(90).then(() => {
                let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
                try {
                  (getContext(this) as common.PhotoEditorExtensionContext).saveEditedContentWithImage(this.originalImage as image.PixelMap,
                    packOpts).then(data => {
                    if (data.resultCode == 0) {
                      hilog.info(0x0000, TAG, `Save succeed.`);
                    }
                    hilog.info(0x0000, TAG,
                        `saveContentEditingWithImage result: ${JSON.stringify(data)}`);
                    this.newWant = data.want;
                    // data.want.uri存有编辑过图片的uri
                    this.readImageByUri(this.newWant?.uri ?? "").then(imagePixMap => {
                      this.editedImage = imagePixMap;
                    })
                  })
                } catch (e) {
                  hilog.error(0x0000, TAG, `saveContentEditingWithImage failed:${e}`);
                  return;
                }
              })
            }).margin({ top: 10 })

            Button("terminateSelfWithResult").onClick((event => {
              hilog.info(0x0000, TAG, `Finish the current editing.`);

              let session = storage.get('session') as UIExtensionContentSession;
              session.terminateSelfWithResult({ resultCode: 0, want: this.newWant });

            })).margin({ top: 10 })

            Image(this.originalImage).width("100%").height(200).margin({ top: 10 }).objectFit(ImageFit.Contain)

            Image(this.editedImage).width("100%").height(200).margin({ top: 10 }).objectFit(ImageFit.Contain)
          }
                .width('100%')
        }
            .height('100%')
        .backgroundColor(Color.Pink)
        .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.BOTTOM])
      }
    }

    ```
1. 在工程Module对应的module.json5配置文件中注册[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)，type标签需要设置为"photoEditor"，srcEntry标签表示当前[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)组件所对应的代码路径。

    ```json
    {
      "module": {
        "extensionAbilities": [
          {
            "name": "ExamplePhotoEditorAbility",
            "icon": "$media:icon",
            "description": "ExamplePhotoEditorAbility",
            "type": "photoEditor",
            "exported": true,
            "srcEntry": "./ets/PhotoEditorUIExtAbility/ExamplePhotoEditorAbility.ets",
            "label": "$string:EntryAbility_label",
            "extensionProcessMode": "bundle"
          },
        ]
      }
    }
    ```
## 开发PhotoEditorExtensionAbility调用方
开发者可以在UIAbility或者UIExtensionAbility的页面中通过接口startAbilityByType拉起图片编辑面板，系统将自动查找并在面板上展示基于[PhotoEditorExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md)实现的图片编辑应用，并由用户选择某个应用来完成图片编辑的功能，并最终将编辑的结果返回给到调用方。

```ts
import { common, wantConstant } from '@kit.AbilityKit';
import { fileUri, picker } from '@kit.CoreFileKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { fileIo } from '@kit.CoreFileKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { JSON } from '@kit.ArkTS';

const TAG = 'PhotoEditorCaller';

@Entry
@Component
struct Index {
  @State message: string = 'selectImg';
  @State originalImage: ResourceStr = "";
  @State editedImage: PixelMap | null = null;
  private filePath: string = "";

  async readImage(uri: string): Promise < PixelMap | null > {
    hilog.info(0x0000, TAG, "image uri: " + uri);
    let file: fileIo.File | undefined;
    try {
      file = await fileIo.open(uri, fileIo.OpenMode.READ_ONLY);
      hilog.info(0x0000, TAG, "file: " + file.fd);

      let imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
      if(!imageSourceApi) {
        hilog.info(0x0000, TAG, "imageSourceApi failed");
        return null;
      }
      let pixmap: image.PixelMap = await imageSourceApi.createPixelMap();
      if(!pixmap) {
        hilog.info(0x0000, TAG, "createPixelMap failed");
        return null;
      }
      this.editedImage = pixmap;
      fileIo.closeSync(file);
      return pixmap;
    } catch(e) {
      hilog.info(0x0000, TAG, `readImage failed:${e}`);
    } finally {
      fileIo.close(file);
    }
    return null;
  }

  async photoPickerGetUri(): Promise < string > {
    try {
      let PhotoSelectOptions = new picker.PhotoSelectOptions();
      PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
      PhotoSelectOptions.maxSelectNumber = 1;
      let photoPicker = new picker.PhotoViewPicker();
      let photoSelectResult: picker.PhotoSelectResult = await photoPicker.select(PhotoSelectOptions);
      hilog.info(0x0000, TAG,
        'PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(photoSelectResult));
      return photoSelectResult.photoUris[0];
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      hilog.info(0x0000, TAG, 'PhotoViewPicker failed with err: ' + JSON.stringify(err));
    }
    return "";
  }

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)

        Button("selectImg").onClick(event => {
          this.photoPickerGetUri().then(uri => {
            hilog.info(0x0000, TAG, "uri: " + uri);

            let context = getContext(this) as common.UIAbilityContext;
            let file: fileIo.File | undefined;
            try {
              file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
              hilog.info(0x0000, TAG, "file: " + file.fd);

              let timeStamp = Date.now();
              fileIo.copyFileSync(file.fd, context.filesDir + `/original-${timeStamp}.jpg`);
              fileIo.closeSync(file);

              this.filePath = context.filesDir + `/original-${timeStamp}.jpg`;
              this.originalImage = fileUri.getUriFromPath(this.filePath);
            } catch (e) {
              hilog.info(0x0000, TAG, `readImage failed:${e}`);
            } finally {
              fileIo.close(file);
            }
          })

        }).width('200').margin({ top: 20 })

        Button("editImg").onClick(event => {
          let context = getContext(this) as common.UIAbilityContext;
          let abilityStartCallback: common.AbilityStartCallback = {
            onError: (code, name, message) => {
              const tip: string = `code:` + code + ` name:` + name + ` message:` + message;
              hilog.error(0x0000, TAG, "startAbilityByType:", tip);
            },
            onResult: (result) => {
              let uri = result.want?.uri ?? "";
              hilog.info(0x0000, TAG, "PhotoEditorCaller result: " + JSON.stringify(result));
              this.readImage(uri).then(imagePixMap => {
                this.editedImage = imagePixMap;
              });
            }
          }

          let uri = fileUri.getUriFromPath(this.filePath);

          context.startAbilityByType("photoEditor", {
            "ability.params.stream": [uri], // 原始图片的uri,只支持传入一个uri
            "ability.want.params.uriPermissionFlag": wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION // 至少需要分享读权限给到图片编辑面板
          } as Record<string, Object>, abilityStartCallback, (err) => {
            let tip: string;
            if (err) {
              tip = `Start error: ${JSON.stringify(err)}`;
              hilog.error(0x0000, TAG, `startAbilityByType: fail, err: ${JSON.stringify(err)}`);
            } else {
              tip = `Start success`;
              hilog.info(0x0000, TAG, "startAbilityByType: ", `success`);
            }
          });

        }).width('200').margin({ top: 20 })

        Image(this.originalImage).width("100%").height(200).margin({ top: 20 }).objectFit(ImageFit.Contain)

        Image(this.editedImage).width("100%").height(200).margin({ top: 20 }).objectFit(ImageFit.Contain)
      }
            .width('100%')
    }
      .height('100%')
      .backgroundColor(Color.Orange)
      .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.BOTTOM])
  }
}

```