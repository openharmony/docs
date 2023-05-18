# 卡片生命周期管理


创建ArkTS卡片，需实现[FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md)生命周期接口。


1. 在EntryFormAbility.ts中，导入相关模块。
   
   ```ts
   import formInfo from '@ohos.app.form.formInfo';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formProvider from '@ohos.app.form.formProvider';
   ```

2. 在EntryFormAbility.ts中，实现[FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md)生命周期接口，其中在onAddForm的入参want中可以通过[FormParam](../reference/apis/js-apis-app-form-formInfo.md#formparam)取出卡片的相关信息。
   
   ```typescript
   import formInfo from '@ohos.app.form.formInfo';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formProvider from '@ohos.app.form.formProvider';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     onAddForm(want) {
       console.info('[EntryFormAbility] onAddForm');
       // 在入参want中可以取出卡片的唯一标识：formId
       let formId: string = want.parameters[formInfo.FormParam.IDENTITY_KEY];
       // 使用方创建卡片时触发，提供方需要返回卡片数据绑定类
       let obj = {
         'title': 'titleOnAddForm',
         'detail': 'detailOnAddForm'
       };
       let formData = formBindingData.createFormBindingData(obj);
       return formData;
     }
   
     onCastToNormalForm(formId) {
       // Called when the form provider is notified that a temporary form is successfully
       // converted to a normal form.
       // 使用方将临时卡片转换为常态卡片触发，提供方需要做相应的处理
       console.info(`[EntryFormAbility] onCastToNormalForm, formId: ${formId}`);
     }
   
     onUpdateForm(formId) {
       // 若卡片支持定时更新/定点更新/卡片使用方主动请求更新功能，则提供方需要重写该方法以支持数据更新
       console.info('[EntryFormAbility] onUpdateForm');
       let obj = {
         'title': 'titleOnUpdateForm',
         'detail': 'detailOnUpdateForm'
       };
       let formData = formBindingData.createFormBindingData(obj);
       formProvider.updateForm(formId, formData).catch((err) => {
         if (err) {
           // 异常分支打印
           console.error(`[EntryFormAbility] Failed to updateForm. Code: ${err.code}, message: ${err.message}`);
           return;
         }
       });
     }
   
     onChangeFormVisibility(newStatus) {
       // Called when the form provider receives form events from the system.
       // 需要配置formVisibleNotify为true，且为系统应用才会回调
       console.info('[EntryFormAbility] onChangeFormVisibility');
     }
   
     onFormEvent(formId, message) {
       // Called when a specified message event defined by the form provider is triggered.
       // 若卡片支持触发事件，则需要重写该方法并实现对事件的触发
       console.info('[EntryFormAbility] onFormEvent');
     }
   
     onRemoveForm(formId) {
       // Called to notify the form provider that a specified form has been destroyed.
       // 当对应的卡片删除时触发的回调，入参是被删除的卡片ID
       console.info('[EntryFormAbility] onRemoveForm');
     }
   
     onConfigurationUpdate(config) {
       // 当系统配置信息置更新时触发的回调
       console.info('[EntryFormAbility] configurationUpdate:' + JSON.stringify(config));
     }
   
     onAcquireFormState(want) {
       // Called to return a {@link FormState} object.
       // 卡片提供方接收查询卡片状态通知接口，默认返回卡片初始状态。
       return formInfo.FormState.READY;
     }
   }
   ```


> **说明：**
>
> FormExtensionAbility进程不能常驻后台，即在卡片生命周期回调函数中无法处理长时间的任务，在生命周期调度完成后会继续存在5秒，如5秒内没有新的生命周期回调触发则进程自动退出。针对可能需要5秒以上才能完成的业务逻辑，建议[拉起主应用](arkts-ui-widget-event-uiability.md)进行处理，处理完成后使用[`updateForm()`](../reference/apis/js-apis-app-form-formProvider.md#updateform)通知卡片进行刷新。
