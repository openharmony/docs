# 根据卡片状态刷新不同内容


相同的卡片可以添加到桌面上实现不同的功能，比如添加两张桌面的卡片，一张显示杭州的天气，一张显示北京的天气，设置每天早上7点触发定时刷新，卡片需要感知当前的配置是杭州还是北京，然后将对应城市的天气信息刷新到卡片上，以下示例介绍了如何根据卡片的状态动态选择需要刷新的内容。


- 卡片配置文件：配置每天早上7点触发定时刷新
  
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

- 卡片页面：卡片具备不同的状态选择，在不同的状态下需要刷新不同的内容，因此在状态发生变化时通过postCardAction通知EntryFormAbility。
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('textA') textA: string = '待刷新...';
    @LocalStorageProp('textB') textB: string = '待刷新...';
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
          Text('状态A')
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
          Text('状态B')
        }
  
        Row() { // 选中状态A才会进行刷新的内容
          Text('状态A: ')
          Text(this.textA)
        }
  
        Row() { // 选中状态B才会进行刷新的内容
          Text('状态B: ')
          Text(this.textB)
        }
      }.padding('10%')
    }
  }
  ```
  
- EntryFormAbility：将卡片的状态存储在本地数据库中，在刷新事件回调触发时，通过formId获取当前卡片的状态，然后根据卡片的状态选择不同的刷新内容。
  
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
      if (isTempCard === false) { // 如果为常态卡片，直接进行信息持久化
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
  
    // 如果在添加时为临时卡片，则建议转为常态卡片时进行信息持久化
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
      // A状态选中则更新textA
      if (stateA === 'true') {
        let formInfo = formBindingData.createFormBindingData({
          'textA': 'AAA'
        })
        formProvider.updateForm(formId, formInfo)
      }
      // B状态选中则更新textB
      if (stateB === 'true') {
        let formInfo = formBindingData.createFormBindingData({
          'textB': 'BBB'
        })
        formProvider.updateForm(formId, formInfo)
      }
    }
  
    onFormEvent(formId, message) {
      // 存放卡片状态
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


> **说明：**
>
> 通过本地数据库进行卡片信息的持久化时，建议先在[**onAddForm**](../reference/apis/js-apis-app-form-formExtensionAbility.md#onaddform)生命周期中通过[**TEMPORARY_KEY**](../reference/apis/js-apis-app-form-formInfo.md#formparam)判断当前添加的卡片是否为常态卡片：如果是常态卡片，则直接进行卡片信息持久化；如果为临时卡片，则可以在卡片转为常态卡片(**[onCastToNormalForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#oncasttonormalform)**)时进行持久化；同时需要在卡片销毁(**[onRemoveForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#onremoveform)**)时删除当前卡片存储的持久化信息，避免反复添加删除卡片导致数据库文件持续变大。

