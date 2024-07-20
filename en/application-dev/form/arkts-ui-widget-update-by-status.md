# Updating Widget Content by State

There are cases where multiple copies of the same widget are added to the home screen to accommodate different needs. In these cases, the widget content needs to be dynamically updated based on the state. This topic exemplifies how this is implemented.

In the following example, two copies of the weather widget are added to the home screen: one for displaying the weather of London, and the other Beijing, both configured to be updated at 07:00 every morning. The widget provider detects the target city, and then displays the city-specific weather information on the widgets.


- Widget configuration file: Configure the widget to be automatically updated every 30 minutes.

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

- Widget page: A widget has different states and needs to be updated by state. When the state changes, **postCardAction** is called to notify the EntryFormAbility.

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
          Row() { // Content that is updated only in state A
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
  
          Row() { // Content that is updated only in state B
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

- EntryFormAbility: The widget state data is stored in the local database. When the update event callback is triggered, the current widget state is obtained through **formId**, and then content is updated based on the state obtained.

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
        formId = JSON.stringify(want.parameters[formInfo.FormParam.IDENTITY_KEY]);
        isTempCard = want.parameters[formInfo.FormParam.TEMPORARY_KEY] as boolean;
        if (isTempCard === false) { // If the widget is a normal one, the widget information is persisted.
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
  
    // If the widget is a temporary one, it is recommended that the widget information be persisted when the widget is converted to a normal one.
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
        // Update textA in state A.
        if (stateA === 'true') {
          let param: Record<string, string> = {
            'textA': 'AAA'
          };
          let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
          await formProvider.updateForm(formId, formInfo);
        }
        // Update textB in state B.
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
      // Store the widget state.
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


> **NOTE**
>
> When the local database is used for widget information persistence, it is recommended that [TEMPORARY_KEY](../reference/apis-form-kit/js-apis-app-form-formInfo.md#formparam) be used in the [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onaddform) lifecycle callback to determine whether the currently added widget is a normal one. If the widget is a normal one, the widget information is directly persisted. If the widget is a temporary one, the widget information is persisted when the widget is converted to a normal one ([onCastToNormalForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#oncasttonormalform)). In addition, the persistent widget information needs to be deleted when the widget is destroyed ([onRemoveForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onremoveform)), preventing the database size from continuously increasing due to repeated widget addition and deletion.
