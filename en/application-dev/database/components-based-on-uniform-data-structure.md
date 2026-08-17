# Content Cards Based on Uniform Data Structs (ArkTS)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=814e5538573180f4836543a1c6592fa1ff24a7c3 translatedAt=2026-08-15T01:41:50.309Z pushedAt=2026-08-15T06:12:22.557Z -->

## When to Use

Preset cards provided by the system allow you to quickly display data of uniform data structs.

## Content Card

You can use the content cards to quickly display content (including the title, description, image, and application information) and redirect to the corresponding source upon a tap. Passing the [ContentForm](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#contentform14) data, card width and height, and tap event callback in the [ContentFormCard](../reference/apis-arkdata/js-apis-data-UdmfComponents.md#contentformcard) API can achieve a good display effect.

Starting from API version 20, you can use the content card component [UdmfComponents](../reference/apis-arkdata/js-apis-data-UdmfComponents.md).

### Available APIs

The following table describes the **ContentFormCard** API.

| Name                                                                                   | Description                                         |
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| ContentFormCard({contentFormData: uniformDataStruct.ContentForm, formType: FormType, formWidth?: number, formHeight?: number, handleOnClick?: Function}) | Displays the passed content card data in a fixed style, invokes the callback upon a tap, and redirects to the configured page.|

### How to Develop

<!-- @[components_based_on_uniform_data_structure](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/ContentForm/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 1. Import required modules.
import { ContentFormCard, FormType, uniformDataStruct } from '@kit.ArkData';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  @State contentForm: uniformDataStruct.ContentForm = {
    uniformDataType: 'general.content-form',
    title: ''
  };
  @State startToShow: boolean = false;

  aboutToAppear(): void {
    // 2. Initialize data.
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
        title: 'Content form title',
        thumbData: appIcon,
        description: 'Content form description',
        appIcon: thumbImage,
        appName: 'com.test.demo'
      };
    } catch (err) {
      hilog.error(0xFF00, '[Sample_Udmf]', 'Init data error');
    }
  }

  build() {
    Column() {
      Button('show card').fontSize(30)
        .onClick(() => {
          // 3. startToShow is changed to true upon a tap, and the page is re-rendered.
          this.startToShow = true;
        })
      if (this.startToShow) {
        // 4. Pass in corresponding parameters to the ContentFormCard API.
        ContentFormCard({
          contentFormData: this.contentForm,
          formType: FormType.TYPE_SMALL,
          formWidth: 220,
          formHeight: 100,
          handleOnClick: () => {
            hilog.info(0xFF00, '[Sample_Udmf]', 'Clicked card');
          }
        })
      }
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```