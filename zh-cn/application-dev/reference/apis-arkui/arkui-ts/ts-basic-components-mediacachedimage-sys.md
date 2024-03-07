# MediaCachedImage (系统接口)

MediaCachedImage继承自Image，新增了纹理资源的加载能力，常用于应用中批量显示图片。MediaCachedImage支持加载媒体库资源，包括png、jpg、jpeg、webp、gif（首帧）、视频缩略图（首帧）、纹理等格式，暂不支持Resource格式和网络图片。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 
> 本模块为系统接口

## 子组件

无

## 接口

MediaCachedImage(src: PixelMap | ResourceStr | DrawableDescriptor | ASTCResource)

通过图片数据源获取图片，用于后续渲染展示。

**需要权限：** ohos.permission.READ_IMAGEVIDEO（访问媒体库资源时才需要此权限）

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 参数类型                                     | 必填   | 参数描述                                     |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| src  | [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor)&nbsp;\|&nbsp;[ASTCResource](ts-types.md#astcresource12) | 是    | 图片的数据源，支持媒体库资源，PixMap、ResourceStr、DrawableDescriptor的引用方式可参考Image的[加载图片资源](../../../ui/arkts-graphics-display.md#加载图片资源)，ASTCResource为纹理资源，其中ResourceStr中的resources、rawfile、base64字符串暂不支持 |

## 属性

支持Image的[通用属性](ts-universal-attributes-size.md)和部分[特有属性](ts-basic-components-image.md#属性)，其中特有属性alt、fillColor、syncLoad、opacity、enableAnalyzer、 resizable不支持

## 事件

支持Image的[通用事件](ts-universal-events-click.md)和部分[特有事件](ts-basic-components-image.md#事件)，其中特有事件onFinish不支持
## 示例

加载纹理资源示例

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import common from '@ohos.app.ability.common';
import MyDataSource from './MyDataSource';

@Entry
@Component
struct MediaCachedImageExample {
  private data: MyDataSource = new MyDataSource();
  aboutToAppear() {
    this.initASTCData();
  }

  async initASTCData() {
    // 获取媒体库所有图片
    let context = getContext() as common.UIAbilityContext;
    let phAccessHelper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [photoAccessHelper.PhotoKeys.DATE_ADDED],
      predicates: predicates
    };

    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let imageAssets: photoAccessHelper.PhotoAsset[] = await fetchResult.getAllObjects();
    imageAssets.reverse();

    // 获取纹理资源，每64张图片拼接一张纹理
    let len = 10;
    let count = 0;
    let astcNumber: number = imageAssets.length / 64;
    if (imageAssets.length % 64 != 0) {
      ++astcNumber;
    }

    for (let i = 0; i < astcNumber; i++) {
      let srcs: string[] = [];
      for (let j = 0; j < 64; j++) {
        if (count >= imageAssets.length) {
          break;
        }
        srcs.push(imageAssets[count].uri + '?oper=astc&width=128&height=128&time_id=' + imageAssets[count].get('date_added')
          .toString() + (Array(len).join('0') + imageAssets[count].get('file_id')).slice(-len));
        count++;
      }
      this.data.pushData({ sources: srcs, column: 8 });
    }
  }

  build() {
    Scroll() {
      Column() {
        Grid() {
          LazyForEach(this.data, (item: ASTCResource) => {
            GridItem() {
              MediaCachedImage(item)
                .width('100%')
                .height('50%')
                .sourceSize({
                  width: px2vp(128),
                  height: px2vp(128)
                })
                .objectFit(ImageFit.Fill)
            }
          })
        }
        .columnsTemplate('1fr') // 一排一张纹理图片
        .rowsGap(10)
      }
      .height('100%')
      .width('100%')
      .margin({ top: 5 })
    }
    .margin({ top: 5 })
    .width('100%')
    .height('100%')
  }
}
```

```ts
export default class MyDataSource implements IDataSource {
  private dataArray: Array<ASTCResource | string> = [];
  listeners: DataChangeListener[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): ASTCResource | string {
    return this.dataArray[index];
  }

  public pushData(data: ASTCResource | string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }

  public deleteAll(length: number): void {
    for (let i = length - 1; i >= 0; i--) {
      this.dataArray.splice(i, 1);
      this.notifyDataDelete(i);
    }
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}
```

![zh-cn_image_ASTC](figures/zh-cn_image_ASTC.jpg)


