# PhotoEditorExtensionContext
PhotoEditorExtensionContext是PhotoEditorExtensionAbility的上下文，继承自ExtensionContext，提供PhotoEditorExtensionAbility的相关配置信息以及保存图片等。
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。
> - 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。

## 导入模块
`import { common } from '@kit.AbilityKit';`

## PhotoEditorExtensionContext.saveEditedContentWithUri
saveEditedContentWithUri(uri: string): Promise\<AbilityResult\>
传入编辑过的图片的沙箱地址并保存。
**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension
**参数：**
| 参数名  | 类型  | 必填  | 说明  |
| ------------ | ------------ | ------------ | ------------ |
| uri | string  | 是  | 编辑过的图片的沙箱地址。  |
**返回值：**
|  类型 | 说明  |
| ------------ | ------------ |
| Promise\<AbilityResult\> | Promise对象，保存的结果，结果的want.uri存有编辑过的图片地址。  |

**错误码：**
|  错误码ID | 错误信息  |
| ------------ | ------------ |
| 401  | Invalid input parameter.  |
| 29600001  | Internal error. |
| 29600002  |  Image input error. |
| 29600003  |  Image too big error. |

**示例：**
```
import { common, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import hilog from '@ohos.hilog';
import fs from '@ohos.file.fs';
import { image } from '@kit.ImageKit';

const TAG = '[ExamplePhotoEditorAbility]';

@Entry
@Component
struct Index {
    // 原始图片
    @State originalImage: PixelMap | null = null;

    build() {
        Row() {
            Column() {
                Button("旋转90度并保存").onClick(event => {
                    hilog.info(0x0000, TAG, `Start to edit image and save.`);

                    this.originalImage?.rotate(90).then(() => {
                        const imagePackerApi: image.ImagePacker = image.createImagePacker();
                        let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
                        imagePackerApi.packing(this.originalImage, packOpts).then((data: ArrayBuffer) => {
                            let context = getContext(this) as common.PhotoEditorExtensionContext;                            
                            let filePath = context.filesDir + "/edited.jpg";
                            let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE 
                            | fs.OpenMode.CREATE | fs.OpenMode.TRUNC);
                            let writeLen = fs.writeSync(file.fd, data);
                            hilog.info(0x0000, TAG, "write data to file succeed and size is:" 
                            + writeLen);
                            fs.closeSync(file);

                            context.saveEditedContentWithUri(filePath).then
                                (data => {
                                    hilog.info(0x0000, TAG,
                                        `saveContentEditingWithUri result: ${JSON.stringify(data)}`);
                                });

                        }).catch((error: BusinessError) => {
                            hilog.error(0x0000, TAG,
                                'Failed to pack the image. And the error is: ' + String(error));
                        })
                    })
                }).margin({ top: 10 })
            }
        }
    }
}

```
## PhotoEditorExtensionContext.saveEditedContentWithImage
saveEditedContentWithImage(image: image.PixelMap, option: image.PackingOption): Promise\<AbilityResult\>
传入编辑过的图片的PixMap对象并保存。
**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension
**参数：**
| 参数名  | 类型  | 必填  | 说明  |
| ------------ | ------------ | ------------ | ------------ |
| image | image.PixelMap  | 是  | 编辑过的图片image.PixelMap。  |
| option  | image.PackingOption  |  是 | 设置打包参数。  |
**返回值：**
|  类型 | 说明  |
| ------------ | ------------ |
| Promise\<AbilityResult\> | Promise对象，保存的结果，结果的want.uri存有编辑过的图片地址。  |
**错误码：**
|  错误码ID | 错误信息  |
| ------------ | ------------ |
| 401  | Invalid input parameter.  |
| 29600002  | Internal error. |
| 29600003  |  Image input error. |
| 29600004  |  Image too big error. |

**示例：**
```
import { common, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import hilog from '@ohos.hilog';
import fs from '@ohos.file.fs';
import { image } from '@kit.ImageKit';

const TAG = '[ExamplePhotoEditorAbility]';

@Entry
@Component
struct Index {
    // 原始图片
    @State originalImage: PixelMap | null = null;

    build() {
        Row() {
            Column() {
                Button("旋转90度并保存").onClick(event => {
                    hilog.info(0x0000, TAG, `Start to edit image and save.`);

                    this.originalImage?.rotate(90).then(() => {
                        const imagePackerApi: image.ImagePacker = image.createImagePacker();
                        let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
                        try {
                            let context = getContext(this) as common.PhotoEditorExtensionContext; 
                            context.saveEditedContentWithImage(this.originalImage as image.PixelMap,
                                    packOpts).then(data => {
                                        hilog.info(0x0000, TAG,
                                            `saveContentEditingWithImage result: ${JSON.stringify(data)}`);
                                    });
                        } catch (e) {
                            hilog.error(0x0000, TAG, `saveContentEditingWithImage failed:${e}`);
                            return;
                        }
                    })
                }).margin({ top: 10 })
            }
        }
    }
}

```