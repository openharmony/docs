# Updating Widget Content by State


There are cases where multiple copies of the same widget are added to the home screen to accommodate different needs. In these cases, the widget content needs to be dynamically updated based on the state. This topic exemplifies how this is implemented. In the following example, two weather widgets are added to the home screen: one for displaying the weather of London, and the other Beijing, both configured to be updated at 07:00 every morning. The widget provider detects the target city, and then displays the city-specific weather information on the widgets.


- Widget configuration file: Configure the widget to be updated at 07:00 every morning.
  
  ```json
  {
    "forms": [
      {
        "name": "widget",
        "description": "This is a service widget.",
        "src": "./ets/widget/pages/WidgetCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,"scheduledUpdateTime": "07:00",
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": ["2*2"]
      }
    ]
  }
  ```

- Widget page: A widget has different states and needs to be updated by state. When the state changes, **postCardAction** is called to notify the EntryFormAbility.
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('textA') textA: string = 'To be updated...';
    @LocalStorageProp('textB') textB: string ='To be updated...';
    @State selectA: boolean = false;
    @State selectB: boolean = false;
  
    build() {
      Column() {
        Row() {
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
            .select(false)
            .onChange((value: boolean) => {
              this.selectA = value;
              postCardAction(this, {
                'action': 'message',
                'params': {
                  'selectA': JSON.stringify(value)
                }
              });
            })
          Text ('State A')
        }
  
        Row() {
          Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
            .select(false)
            .onChange((value: boolean) => {
              this.selectB = value;
              postCardAction(this, {
                'action': 'message',
                'params': {
                  'selectB': JSON.stringify(value)
                }
              });
            })
          Text ('State B')
        }
  
        Row() {// Content that is updated only in state A
          Text ('State A:')
          Text(this.textA)
        }
  
        Row() { // Content that is updated only in state B
          Text ('State B:')
          Text(this.textB)
        }
      }.padding('10%')
    }
  }
  ```
  
- EntryFormAbility: The widget state data is stored in the local database. When the update event callback is triggered, the current widget state is obtained through **formId**, and then content is updated based on the state obtained.
  
  ```ts
  import formInfo from '@ohos.app.form.formInfo'
  import formProvider from '@ohos.app.form.formProvider';
  import formBindingData from '@ohos.app.form.formBindingData';
  import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
  import dataStorage from '@ohos.data.storage'
  
  export default class EntryFormAbility extends FormExtensionAbility {
    onAddForm(want) {
      let formId = want.parameters[formInfo.FormParam.IDENTITY_KEY];
      let isTempCard: boolean = want.parameters[formInfo.FormParam.TEMPORARY_KEY];
      if (isTempCard === false) {// If the widget is a normal one, the widget information is persisted.
        console.info('Not temp card, init db for:' + formId);
        let storeDB = dataStorage.getStorageSync(this.context.filesDir + 'myStore')
        storeDB.putSync('A' + formId, 'false');
        storeDB.putSync('B' + formId, 'false');
        storeDB.flushSync();
      }
      let formData = {};
      return formBindingData.createFormBindingData(formData);
    }
  
    onRemoveForm(formId) {
      console.info('onRemoveForm, formId:' + formId);
      let storeDB = dataStorage.getStorageSync(this.context.filesDir + 'myStore')
      storeDB.deleteSync('A' + formId);
      storeDB.deleteSync('B' + formId);
    }
  
    // If the widget is a temporary one, it is recommended that the widget information be persisted when the widget is converted to a normal one.
    onCastToNormalForm(formId) {
      console.info('onCastToNormalForm, formId:' + formId);
      let storeDB = dataStorage.getStorageSync(this.context.filesDir + 'myStore')
      storeDB.putSync('A' + formId, 'false');
      storeDB.putSync('B' + formId, 'false');
      storeDB.flushSync();
    }
  
    onUpdateForm(formId) {
      let storeDB = dataStorage.getStorageSync(this.context.filesDir + 'myStore')
      let stateA = storeDB.getSync('A' + formId, 'false').toString()
      let stateB = storeDB.getSync('B' + formId, 'false').toString()
      // Update textA in state A.
      if (stateA === 'true') {
        let formInfo = formBindingData.createFormBindingData({
          'textA': 'AAA'
        })
        formProvider.updateForm(formId, formInfo)
      }
      // Update textB in state B.
      if (stateB === 'true') {
        let formInfo = formBindingData.createFormBindingData({
          'textB': 'BBB'
        })
        formProvider.updateForm(formId, formInfo)
      }
    }
  
    onFormEvent(formId, message) {
      // Store the widget state.
      console.info('onFormEvent formId:' + formId + 'msg:' + message);
      let storeDB = dataStorage.getStorageSync(this.context.filesDir + 'myStore')
      let msg = JSON.parse(message)
      if (msg.selectA != undefined) {
        console.info('onFormEvent selectA info:' + msg.selectA);
        storeDB.putSync('A' + formId, msg.selectA);
      }
      if (msg.selectB != undefined) {
        console.info('onFormEvent selectB info:' + msg.selectB);
        storeDB.putSync('B' + formId, msg.selectB);
      }
      storeDB.flushSync();
    }
  };
  ```


> **NOTE**
>
> When the local database is used for widget information persistence, it is recommended that [TEMPORARY_KEY](../reference/apis/js-apis-app-form-formInfo.md#formparam) be used to determine whether the currently added widget is a normal one in the [onAddForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#onaddform) lifecycle callback. If the widget is a normal one, the widget information is directly persisted. If the widget is a temporary one, the widget information is persisted when the widget is converted to a normal one ([onCastToNormalForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#oncasttonormalform)). In addition, the persistent widget information needs to be deleted when the widget is destroyed ([onRemoveForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#onremoveform)), preventing the database size from continuously increasing due to repeated widget addition and deletion.
