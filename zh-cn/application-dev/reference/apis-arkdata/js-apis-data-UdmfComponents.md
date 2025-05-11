# ContentFormCard


针对[ContentForm](js-apis-data-uniformDataStruct.md#contentform)数据结构的内容卡片，支持设置标题（必选）、描述、应用图标、应用名称、跳转链接、内容图片。


> **说明：**
>
> 该组件从API Version 20开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```js
import { ContentFormCard, FormType } from '@kit.ArkData';
```

## 子组件

无

## ContentFormCard

ContentFormCard({contentFormData: uniformDataStruct.ContentForm, formType: FormType, formWidth?: number, formHeight?: number, handleOnClick?: Function})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| contentFormData | [uniformDataStruct.ContentForm](js-apis-data-uniformDataStruct.md#contentform) | 是 | 内容卡片数据。 |
| formType | [FormType](#formtype) | 是 | 内容卡片类型。 |
| formWidth | number | 否 | 卡片宽度。 |
| formHeight | number | 否 | 卡片高度。 |
| handleOnClick | Function | 否 | 点击事件回调函数。 |

## FormType

内容卡片类型，提供了大、中、小三种尺寸。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称          | 值 | 说明                |
|-------------|---|-------------------|
| TYPE_BIG | 0 | 表示 4 x 4 的尺寸。 |
| TYPE_MID | 1 | 表示 4 x 2 的尺寸。 |
| TYPE_SMALL | 2 | 表示 2 x 1 的尺寸。 |

## 示例

```ts
import { uniformDataStruct } from '@kit.ArkData'
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  @State contentForms: uniformDataStruct.ContentForm[] = [];

  aboutToAppear(): void {
    this.initData();
  }

  async initData() {
    let context = getContext(this) as common.UIAbilityContext;
    try {
      let appIcon = await context.resourceManager.getMediaContent($r('app.media.appIcon').id);
      let thumbImage = await context.resourceManager.getMediaContent($r('app.media.thumbImage').id);
      this.contentForms.push({
        uniformDataType: 'general.content-form',
        title: "Content form title",
        thumbData: appIcon,
        description: "Content form description",
        appIcon: thumbImage,
        appName: "com.test.demo"
      });
    } catch (err) {
      console.info("Init data error");
    }
  }

  build() {
    Column() {
      if (this.contentForms.length > 0) {
        ContentFormCard({
          contentFormData: this.contentForms[0],
          formType: FormType.TYPE_SMALL,
          formWidth: 110,
          formHeight: 50,
          handleOnClick: () => {
            console.info("Clicked card");
          }
        })
      }
    }
  }
}
```

