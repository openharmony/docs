# 根据卡片状态刷新不同内容


相同的卡片可以添加到桌面上实现不同的功能，比如添加两张桌面的卡片，一张显示杭州的天气，一张显示北京的天气，设置每天早上7点触发定时刷新，卡片需要感知当前的配置是杭州还是北京，然后将对应城市的天气信息刷新到卡片上，以下示例介绍了如何根据卡片的状态动态选择需要刷新的内容。


- 卡片配置文件：配置每30分钟自动刷新。

  ```json
  {
    "forms": [
      {
        "name": "WidgetUpdateByStatus",
        "description": "$string:UpdateByStatusFormAbility_desc",
        "src": "./ets/widgetupdatebystatus/pages/WidgetUpdateByStatusCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "updateDuration": 1,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

- 卡片页面：卡片具备不同的状态选择，在不同的状态下需要刷新不同的内容，因此在状态发生变化时通过postCardAction通知EntryFormAbility。

  ```ts
  let storageUpdateByStatus = new LocalStorage();
  
  @Entry(storageUpdateByStatus)
  @Component
  struct WidgetUpdateByStatusCard {
    @LocalStorageProp('textA') textA: Resource = $r('app.string.to_be_refreshed');
    @LocalStorageProp('textB') textB: Resource = $r('app.string.to_be_refreshed');
    @State selectA: boolean = false;
    @State selectB: boolean = false;
  
    build() {
      Column() {
        Column() {
          Row() {
            Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
              .padding(0)
              .select(false)
              .margin({ left: 26 })
              .onChange((value: boolean) => {
                this.selectA = value;
                postCardAction(this, {
                  action: 'message',
                  params: {
                    selectA: JSON.stringify(value)
                  }
                });
              })
            Text($r('app.string.status_a'))
              .fontColor('#000000')
              .opacity(0.9)
              .fontSize(14)
              .margin({ left: 8 })
          }
          .width('100%')
          .padding(0)
          .justifyContent(FlexAlign.Start)
  
          Row() {
            Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
              .padding(0)
              .select(false)
              .margin({ left: 26 })
              .onChange((value: boolean) => {
                this.selectB = value;
                postCardAction(this, {
                  action: 'message',
                  params: {
                    selectB: JSON.stringify(value)
                  }
                });
              })
            Text($r('app.string.status_b'))
              .fontColor('#000000')
              .opacity(0.9)
              .fontSize(14)
              .margin({ left: 8 })
          }
          .width('100%')
          .position({ y: 32 })
          .padding(0)
          .justifyContent(FlexAlign.Start)
        }
        .position({ y: 12 })
  
        Column() {
          Row() { // 选中状态A才会进行刷新的内容
            Text($r('app.string.status_a'))
              .fontColor('#000000')
              .opacity(0.4)
              .fontSize(12)
  
            Text(this.textA)
              .fontColor('#000000')
              .opacity(0.4)
              .fontSize(12)
          }
          .margin({ top: '12px', left: 26, right: '26px' })
  
          Row() { // 选中状态B才会进行刷新的内容
            Text($r('app.string.status_b'))
              .fontColor('#000000')
              .opacity(0.4)
              .fontSize(12)
            Text(this.textB)
              .fontColor('#000000')
              .opacity(0.4)
              .fontSize(12)
          }.margin({ top: '12px', bottom: '21px', left: 26, right: '26px' })
        }
        .margin({ top: 80 })
        .width('100%')
        .alignItems(HorizontalAlign.Start)
      }.width('100%').height('100%')
      .backgroundImage($r('app.media.CardUpdateByStatus'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```

- EntryFormAbility：将卡片的状态存储在本地数据库中，在刷新事件回调触发时，通过formId获取当前卡片的状态，然后根据卡片的状态选择不同的刷新内容。

  ```ts
  import { Want } from '@kit.AbilityKit';
  import { preferences } from '@kit.ArkData';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const TAG: string = 'UpdateByStatusFormAbility';
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class UpdateByStatusFormAbility extends FormExtensionAbility {
    onAddForm(want: Want): formBindingData.FormBindingData {
      let formId: string = '';
      let isTempCard: boolean;
      if (want.parameters) {
        formId = want.parameters[formInfo.FormParam.IDENTITY_KEY].toString();
        isTempCard = want.parameters[formInfo.FormParam.TEMPORARY_KEY] as boolean;
        if (isTempCard === false) { // 如果为常态卡片，直接进行信息持久化
          hilog.info(DOMAIN_NUMBER, TAG, 'Not temp card, init db for:' + formId);
          let promise: Promise<preferences.Preferences> = preferences.getPreferences(this.context, 'myStore');
          promise.then(async (storeDB: preferences.Preferences) => {
            hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded to get preferences.');
            await storeDB.put('A' + formId, 'false');
            await storeDB.put('B' + formId, 'false');
            await storeDB.flush();
          }).catch((err: BusinessError) => {
            hilog.info(DOMAIN_NUMBER, TAG, `Failed to get preferences. ${JSON.stringify(err)}`);
          });
        }
    }
      let formData: Record<string, Object | string> = {};
      return formBindingData.createFormBindingData(formData);
    }
  
    onRemoveForm(formId: string): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onRemoveForm, formId:' + formId);
      let promise = preferences.getPreferences(this.context, 'myStore');
      promise.then(async (storeDB) => {
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded to get preferences.');
        await storeDB.delete('A' + formId);
        await storeDB.delete('B' + formId);
      }).catch((err: BusinessError) => {
      hilog.info(DOMAIN_NUMBER, TAG, `Failed to get preferences. ${JSON.stringify(err)}`);
      });
    }
  
    // 如果在添加时为临时卡片，则建议转为常态卡片时进行信息持久化
    onCastToNormalForm(formId: string): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onCastToNormalForm, formId:' + formId);
      let promise: Promise<preferences.Preferences> = preferences.getPreferences(this.context, 'myStore');
      promise.then(async (storeDB: preferences.Preferences) => {
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded to get preferences.');
        await storeDB.put('A' + formId, 'false');
        await storeDB.put('B' + formId, 'false');
        await storeDB.flush();
      }).catch((err: BusinessError) => {
      hilog.info(DOMAIN_NUMBER, TAG, `Failed to get preferences. ${JSON.stringify(err)}`);
      });
    }
  
    onUpdateForm(formId: string): void {
      let promise: Promise<preferences.Preferences> = preferences.getPreferences(this.context, 'myStore');
      promise.then(async (storeDB: preferences.Preferences) => {
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded to get preferences from onUpdateForm.');
        let stateA = await storeDB.get('A' + formId, 'false');
        let stateB = await storeDB.get('B' + formId, 'false');
        // A状态选中则更新textA
        if (stateA === 'true') {
          let param: Record<string, string> = {
            'textA': 'AAA'
          };
          let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
          await formProvider.updateForm(formId, formInfo);
        }
        // B状态选中则更新textB
        if (stateB === 'true') {
          let param: Record<string, string> = {
            'textB': 'BBB'
          };
          let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
        await formProvider.updateForm(formId, formInfo);
        }
        hilog.info(DOMAIN_NUMBER, TAG, `Update form success stateA:${stateA} stateB:${stateB}.`);
      }).catch((err: BusinessError) => {
        hilog.info(DOMAIN_NUMBER, TAG, `Failed to get preferences. ${JSON.stringify(err)}`);
      });
    }
  
    onFormEvent(formId: string, message: string): void {
      // 存放卡片状态
      hilog.info(DOMAIN_NUMBER, TAG, 'onFormEvent formId:' + formId + 'msg:' + message);
      let promise: Promise<preferences.Preferences> = preferences.getPreferences(this.context, 'myStore');
      promise.then(async (storeDB: preferences.Preferences) => {
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded to get preferences.');
        let msg: Record<string, string> = JSON.parse(message);
        if (msg.selectA !== undefined) {
          hilog.info(DOMAIN_NUMBER, TAG, 'onFormEvent selectA info:' + msg.selectA);
          await storeDB.put('A' + formId, msg.selectA);
        }
        if (msg.selectB !== undefined) {
          hilog.info(DOMAIN_NUMBER, TAG, 'onFormEvent selectB info:' + msg.selectB);
          await storeDB.put('B' + formId, msg.selectB);
        }
        await storeDB.flush();
      }).catch((err: BusinessError) => {
        hilog.info(DOMAIN_NUMBER, TAG, `Failed to get preferences. ${JSON.stringify(err)}`);
      });
    }
  }
  ```


> **说明：**
>
> 通过本地数据库进行卡片信息的持久化时，建议先在[**onAddForm**](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform)生命周期中通过[**TEMPORARY_KEY**](../reference/apis-form-kit/js-apis-app-form-formInfo.md#formparam)判断当前添加的卡片是否为常态卡片：如果是常态卡片，则直接进行卡片信息持久化；如果为临时卡片，则可以在卡片转为常态卡片(**[onCastToNormalForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityoncasttonormalform)**)时进行持久化；同时需要在卡片销毁(**[onRemoveForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonremoveform)**)时删除当前卡片存储的持久化信息，避免反复添加删除卡片导致数据库文件持续变大。

