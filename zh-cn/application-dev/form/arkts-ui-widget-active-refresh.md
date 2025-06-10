# ArkTS卡片主动刷新

本文主要提供主动刷新的开发指导，刷新流程请参考[主动刷新概述](./arkts-ui-widget-interaction-overview.md#主动刷新)。

## 卡片提供方主动刷新卡片内容

卡片提供方可以通过[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口进行主动刷新。推荐与卡片生命周期回调[onFormEvent](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent)、[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)、[onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform)接口搭配使用。

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();
const TAG: string = 'Index';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry(storage)
@Component
struct Index {
  @StorageLink('formId') formId: number = 0;
  @StorageLink('formData') formData: Object | string = {};

  build() {
    Column() {
      Column() {
        //...
        Button() {
          //...
        }
        .onClick(() => {
          console.info(DOMAIN_NUMBER, TAG, `click to check updateForm, formId: ${this.formId}`);
          const formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(this.formData);
          // formId需要为实际需要刷新的卡片ID
          formProvider.updateForm(this.formId, formInfo).then(() => {
            console.info(DOMAIN_NUMBER, TAG, 'updateForm success.');
          }).catch((error: BusinessError) => {
            console.error(DOMAIN_NUMBER, TAG, `updateForm fail, code: ${error?.code}, message: ${error?.message}`);
          })
        })
        .margin(5)
      }
      //...
    }
    //...
  }
}
```
<!--Del-->

## 卡片使用方主动刷新卡片内容（仅对系统应用开放）

由于定时、定点刷新存在时间限制，卡片使用方可以通过调用[requestForm](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md#requestform)接口向卡片管理服务请求主动触发卡片的刷新。卡片管理服务触发卡片提供方FormExtensionAbility中的[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)生命周期回调，回调中可以使用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口刷新卡片内容。

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();
const TAG: string = 'Index';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry(storage)
@Component
struct Index {
  @StorageLink('formId') formId: number = 0;

  build() {
    Column() {
      Column() {
        //...
        Button() {
          //...
        }
        .onClick(() => {
          console.info(DOMAIN_NUMBER, TAG, `click to check requestForm, formId: ${this.formId}`);
          // formId需要为实际需要刷新的卡片ID
          formHost.requestForm(this.formId.toString()).then(() => {
            console.info(DOMAIN_NUMBER, TAG, 'requestForm success.');
          }).catch((error: BusinessError) => {
            console.error(DOMAIN_NUMBER, TAG, `requestForm fail, code: ${error?.code}, message: ${error?.message}`);
          })
        })
        .margin(5)
      }
      //...
    }
    //...
  }
}
```
<!--DelEnd-->
