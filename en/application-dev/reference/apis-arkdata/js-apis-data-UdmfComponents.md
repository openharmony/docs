# @ohos.data.UdmfComponents (Content Card)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

A content card designed in the [ContentForm](js-apis-data-uniformDataStruct.md#contentform14) struct. You can set the title (mandatory), description, application icon, application name, redirection link, and content image for the content card. When a user taps the card, a callback of the pass event is triggered to redirect the user to the specified page if the target link is set.

> **NOTE**
>
> This component is supported since API version 20. Updates will be marked with a superscript to indicate their earliest API version.

## Module to Import

```js
import { ContentFormCard, FormType } from '@kit.ArkData';
```

## Child Component

N/A

## ContentFormCard

ContentFormCard({contentFormData: uniformDataStruct.ContentForm, formType: FormType, formWidth?: number, formHeight?: number, handleOnClick?: Function})

Defines the information of a content card component that displayed in an application, including the title, description, content image, application information, and the like.

**Decorator**: \@Component

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| contentFormData | [uniformDataStruct.ContentForm](js-apis-data-uniformDataStruct.md#contentform14) | Yes| - | Content card data.|
| formType | [FormType](#formtype) | Yes| @Prop | Content card type, which affects the size of the content card.|
| formWidth | number | No| @Prop | Card width. The value ranges from 0.8 to 1.2 times the default width of the content card type. If **formType** is set to **TYPE_SMALL**, the value ranges from 0.4 to 1.2 times the default width of the content card type.|
| formHeight | number | No| @Prop | Card height. If title in **contentFormData** is an empty string, the card height is the passed value. Otherwise, the value is 0.8 to 1.2 times the default width of the content card type. If **formType** is set to **TYPE_SMALL**, the value is 0.4 to 1.2 times the default width of the content card type.|
| handleOnClick | Function | No| - | Callback for the click event.|

## FormType

Enumerates content card types, including large, medium, and small.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name         | Value| Description               |
|-------------|---|-------------------|
| TYPE_BIG | 0 | 4 × 4. The default card width and height are both 200.|
| TYPE_MID | 1 | 4 × 2. The default card width and height are 200 and 100, respectively.|
| TYPE_SMALL | 2 | 2 × 1. The default card width and height are 137 and 83, respectively.|

## Example

```ts
import { uniformDataStruct } from '@kit.ArkData'

@Entry
@Component
struct Index {
  @State contentForm: uniformDataStruct.ContentForm = {
    uniformDataType: 'general.content-form',
    title: ''
  };
  @State startToShow: boolean = false;

  aboutToAppear(): void {
    this.initData();
  }

  async initData() {
    let context = this.getUIContext().getHostContext();
    if (!context) {
      return;
    }
    try {
      let appIcon = await context.resourceManager.getMediaContent($r('app.media.startIcon').id);
      let thumbImage = await context.resourceManager.getMediaContent($r('app.media.foreground').id);
      this.contentForm = {
        uniformDataType: 'general.content-form',
        title: "Content form title",
        thumbData: appIcon,
        description: "Content form description",
        appIcon: thumbImage,
        appName: "com.test.demo"
      };
    } catch (err) {
      console.error("Init data error");
    }
  }

  build() {
    Column() {
      Button('show card')
        .onClick(() => {
          this.startToShow = true;
        })
      if (this.startToShow) {
        ContentFormCard({
          contentFormData: this.contentForm,
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
