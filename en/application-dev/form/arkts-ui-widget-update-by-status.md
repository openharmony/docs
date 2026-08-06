# Updating Widget Content by State

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=6b0733adc9a538f18ea8143587feeecb737929d9 translatedAt=2026-08-03T02:29:46.762Z pushedAt=2026-08-03T07:33:55.880Z -->

Multiple copies of the same widget can be added to the home screen to serve different purposes. For example, you can add two copies of a weather widget, with one displaying the weather for Hangzhou and the other for Beijing. A scheduled refresh is configured to trigger at 10:30 AM every day. The widget must detect whether its current configuration is for Hangzhou or Beijing, and then refresh the corresponding city's weather information on the widget. The following example demonstrates how to dynamically select the content to refresh based on the widget status.

- Widget configuration file: Configure the widget to be automatically refreshed every 30 minutes.

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

- Widget page: The widget supports different status selections, and different content needs to be refreshed under different statuses. Therefore, when the status changes, `postCardAction` is used to notify `UpdateByStatusFormAbility`.

    <!-- @[widget_update_by_status_card](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/widgetupdatebystatus/pages/WidgetUpdateByStatusCard.ets) --> 

    ``` TypeScript
    // entry/src/main/ets/widgetupdatebystatus/pages/WidgetUpdateByStatusCard.ets
    let storageUpdateByStatus = new LocalStorage();
    
    @Entry(storageUpdateByStatus)
    @Component
    struct WidgetUpdateByStatusCard {
      // Replace $r('app.string.to_be_refreshed') with the resource file you use.
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
              // Replace $r('app.string.status_a') with the resource file you use.
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
              // Replace $r('app.string.status_b') with the resource file you use.
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
            Row() {
              // Content that is updated only in state A.
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
    
            Row() {
              // Content that is updated only in state B.
              Text($r('app.string.status_b'))
                .fontColor('#000000')
                .opacity(0.4)
                .fontSize(12)
              Text(this.textB)
                .fontColor('#000000')
                .opacity(0.4)
                .fontSize(12)
            }
            .margin({
              top: '12px',
              bottom: '21px',
              left: 26,
              right: '26px'
            })
          }
          .margin({ top: 80 })
          .width('100%')
          .alignItems(HorizontalAlign.Start)
        }.width('100%').height('100%')
        // Replace $r('app.media.CardUpdateByStatus') with the resource file you use.
        .backgroundImage($r('app.media.CardUpdateByStatus'))
        .backgroundImageSize(ImageSize.Cover)
      }
    }
    ```

- `UpdateByStatusFormAbility`: Stores the widget status in a local database. When the refresh event callback is triggered, the current widget status is obtained through `formId`, and then different refresh content is selected based on the widget status.

    <!-- @[update_by_status_form_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/updatebystatusformability/UpdateByStatusFormAbility.ts) --> 

    ``` TypeScript
    // entry/src/main/ets/updatebystatusformability/UpdateByStatusFormAbility.ts
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
        if (want.parameters) {
          formId = want.parameters[formInfo.FormParam.IDENTITY_KEY].toString();
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
    
      // This callback function is not required for the widget host.
      onCastToNormalForm(formId: string): void {
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
> When persisting widget information via a local database, it is recommended to first perform the persistence during the [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform) lifecycle. Additionally, when a widget is destroyed (using [onRemoveForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonremoveform)), you should delete its persisted data to prevent the database file from growing continuously due to repeated addition and removal of widgets.