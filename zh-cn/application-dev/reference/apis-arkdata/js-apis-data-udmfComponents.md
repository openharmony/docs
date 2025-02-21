# @ohos.data.udmfComponents(udmf卡片控件)


udmf卡片控件。


> **说明：**
>
> 该组件从API Version 16开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { ContentFormCard, FormType, uniformDataStruct } from '@kit.ArkData';
```

## 子组件

无

## 属性

不支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md).

## ContentFormCard

ContentFormCard({ contentFormData: uniformDataStruct.ContentForm, formType: FormType, formWidth?: number })

ContentForm卡片控件，将 ContentForm数据展示在卡片控件中。
> **说明：**
>
> 如果要显示复杂类型卡片，建议使用4x2或2x1卡片，请将卡片要显示内容生成图片，作为ContentForm的thumbData参数，title传入空字符串，卡片会只显示thumbData图片，底部显示信息来源。

**装饰器类型：**@Component

**系统能力：**SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 名称 | 参数类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| contentFormData | uniformDataStruct.ContentForm | 是 | - | contentForm数据<br />4x4卡片：样式固定，有缺省参数时显示占位图<br />4x2卡片：thumbData缺省时显示纯文本卡片，title为空字符串时显示图片卡片，其他信息缺省时显示占位图<br />2x1卡片：显示纯文本卡片，title为空字符串时显示图片卡片，其他信息缺省时显示占位图|
| formType | [FormType](#FormType) | 是 | \@Prop | 卡片类型 |
| formWidth | number | 否 | \@Prop | 卡片宽度<br />不传时使用默认卡片宽度：<br />4x4卡片：200；<br />4x2卡片：200；<br />2x1卡片：100<br />最大宽度为默认宽度的1.2倍<br />最小宽度4x4/4x2卡片时为默认宽度的0.8倍，2x1卡片时为默认宽度的0.6倍<br /> |

## FormType

| 名称       | 值   | 说明          |
| ---------- | ---- | ------------- |
| TYPE_BIG   | 0    | 4X4卡片类型。 |
| TYPE_MID   | 1    | 4X2卡片类型。 |
| TYPE_SAMLL | 2    | 2x1卡片类型。 |


## 示例

```ts
import common from '@ohos.app.ability.common';
import { FormType, ContentFormCard, uniformDataStruct } from '@kit.ArkData';

@Entry
@Component
struct Normal {
  @State contentForms: uniformDataStruct.ContentForm[] = [];
  @State formWidth: number = 200;
  @State formType: FormType = FormType.TYPE_BIG;

  aboutToAppear(): void {
    this.initData();
  }

  async initData() {
    let context = getContext(this) as common.UIAbilityContext;
    try {
      let appIcon = await context.resourceManager.getMediaContent($r('app.media.startIcon').id);
      let thumb2 = await context.resourceManager.getMediaContent($r('app.media.thumb2').id);
      this.contentForms.push({
        uniformDataType: 'general.content-form',
        title: '为什么微博微博微博微博微博',
        thumbData: thumb2,
        description: '是不是很多人好奇，是不是很多人好奇是不是很多人好奇',
        appName: '今日头条',
        linkUri: 'https://appgallery.huawei.com/app/detail?id=com.huawei.hmos.wallet',
        appIcon: appIcon
      })
    } catch (err) {
      console.info(`failed getMediaContent.`);
    }

  }

  build() {
    Column({ space: 10 }) {
      if (this.contentForms.length > 0) {
        Text(`标准卡片，formWidth：${this.formWidth}, this.formType: ${this.formType}`)
        ContentFormCard({
          contentFormData: this.contentForms[0],
          formType: this.formType,
          formWidth: this.formWidth
        })
        Button('卡片类型动态变化')
          .width('70%')
          .height(50)
          .onClick(() => {
            switch (this.formType) {
              case FormType.TYPE_BIG:
                this.formType = FormType.TYPE_MID;
                this.formWidth = 200;
                break;
              case FormType.TYPE_MID:
                this.formType = FormType.TYPE_SMALL;
                this.formWidth = 137;
                break;
              case FormType.TYPE_SMALL:
                this.formType = FormType.TYPE_BIG;
                this.formWidth = 200;
                break;
              default:
                break;
            }
          })
        Button('每次宽度加1')
          .width('70%')
          .height(50)
          .onClick(() => {
            this.formWidth++;
          })
        Button('每次宽度减1')
          .width('70%')
          .height(50)
          .onClick(() => {
            this.formWidth--;
          })
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#15000000')
  }
}
```

