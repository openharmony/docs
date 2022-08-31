# FA卡片开发指导

## 卡片概述
卡片是一种界面展示形式，可以将应用的重要信息或操作前置到卡片，以达到服务直达，减少体验层级的目的。

卡片常用于嵌入到其他应用（当前只支持系统应用）中作为其界面的一部分显示，并支持拉起页面，发送消息等基础的交互功能。卡片使用方负责显示卡片。

卡片的基本概念：
- 卡片提供方：提供卡片显示内容原子化服务，控制卡片的显示内容、控件布局以及控件点击事件。
- 卡片使用方：显示卡片内容的宿主应用，控制卡片在宿主中展示的位置。
- 卡片管理服务：用于管理系统中所添加卡片的常驻代理服务，包括卡片对象的管理与使用，以及卡片周期性刷新等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 卡片使用方和提供方不要求常驻运行，在需要添加/删除/请求更新卡片时，卡片管理服务会拉起卡片提供方获取卡片信息。

开发者仅需作为卡片提供方进行卡片内容的开发，卡片使用方和卡片管理服务由系统自动处理。

卡片提供方控制卡片实际显示的内容、控件布局以及点击事件。

## 场景介绍

FA卡片开发，即基于[FA模型](fa-brief.md)的卡片提供方开发，主要涉及如下功能逻辑：

- 开发卡片生命周期回调函数LifecycleForm。
- 创建卡片数据FormBindingData对象。
- 通过FormProvider更新卡片。
- 开发卡片页面。

## 接口说明

卡片生命周期回调函数LifecycleForm的接口如下：

**表1** LifecycleForm API接口功能介绍

| 接口名                                                       | 描述                                         |
| :----------------------------------------------------------- | :------------------------------------------- |
| onCreate(want: Want): formBindingData.FormBindingData        | 卡片提供方接收创建卡片的通知接口。           |
| onCastToNormal(formId: string): void                         | 卡片提供方接收临时卡片转常态卡片的通知接口。 |
| onUpdate(formId: string): void                               | 卡片提供方接收更新卡片的通知接口。           |
| onVisibilityChange(newStatus: { [key: string]: number }): void | 卡片提供方接收修改可见性的通知接口。         |
| onEvent(formId: string, message: string): void               | 卡片提供方接收处理卡片事件的通知接口。       |
| onDestroy(formId: string): void                              | 卡片提供方接收销毁卡片的通知接口。           |
| onAcquireFormState?(want: Want): formInfo.FormState          | 卡片提供方接收查询卡片状态的通知接口。       |

FormProvider类具体的API详见[接口文档](../reference/apis/js-apis-formprovider.md)。

**表2** FormProvider API接口功能介绍

| 接口名                                                       | 描述                                              |
| :----------------------------------------------------------- | :------------------------------------------------ |
| setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void; | 设置指定卡片的下一次更新时间。                    |
| setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;; | 设置指定卡片的下一次更新时间，以promise方式返回。 |
| updateForm(formId: string, formBindingData: FormBindingData, callback: AsyncCallback&lt;void&gt;): void; | 更新指定的卡片。                                  |
| updateForm(formId: string, formBindingData: FormBindingData): Promise&lt;void&gt;; | 更新指定的卡片，以promise方式返回。               |

## 开发步骤

### 创建LifecycleForm

创建FA模型的卡片，需实现LifecycleForm的生命周期接口。具体示例代码如下：

1. 导入相关模块。

   ```javascript
   import formBindingData from '@ohos.application.formBindingData'
   import formInfo from '@ohos.application.formInfo'
   import formProvider from '@ohos.application.formProvider'
   ```
   
2. 实现LifecycleForm生命周期接口。

   ```javascript
   export default {
       onCreate(want) {
           console.log('FormAbility onCreate');
           // 由开发人员自行实现，将创建的卡片信息持久化，以便在下次获取/更新该卡片实例时进行使用
           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       },
       onCastToNormal(formId) {
           // 使用方将临时卡片转换为常态卡片触发，提供方需要做相应的处理
           console.log('FormAbility onCastToNormal');
       },
       onUpdate(formId) {
           // 若卡片支持定时更新/定点更新/卡片使用方主动请求更新功能，则提供方需要重写该方法以支持数据更新
           console.log('FormAbility onUpdate');
           let obj = {
               "title": "titleOnUpdate",
               "detail": "detailOnUpdate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           formProvider.updateForm(formId, formData).catch((error) => {
               console.log('FormAbility updateForm, error:' + JSON.stringify(error));
           });
       },
       onVisibilityChange(newStatus) {
           // 使用方发起可见或者不可见通知触发，提供方需要做相应的处理
           console.log('FormAbility onVisibilityChange');
       },
       onEvent(formId, message) {
           // 若卡片支持触发事件，则需要重写该方法并实现对事件的触发
           console.log('FormAbility onEvent');
       },
       onDestroy(formId) {
           // 删除卡片实例数据
           console.log('FormAbility onDestroy');
       },
       onAcquireFormState(want) {
           console.log('FormAbility onAcquireFormState');
           return formInfo.FormState.READY;
       },
   }
   ```

### 配置卡片配置文件

卡片需要在应用配置文件config.json中进行配置。

- js模块，用于对应卡片的js相关资源，内部字段结构说明：

  | 属性名称 | 含义                                                         | 数据类型 | 是否可缺省               |
  | -------- | ------------------------------------------------------------ | -------- | ------------------------ |
  | name     | 表示JS Component的名字。该标签不可缺省，默认值为default。    | 字符串   | 否                       |
  | pages    | 表示JS Component的页面用于列举JS Component中每个页面的路由信息[页面路径+页面名称]。该标签不可缺省，取值为数组，数组第一个元素代表JS FA首页。 | 数组     | 否                       |
  | window   | 用于定义与显示窗口相关的配置。                               | 对象     | 可缺省                   |
  | type     | 表示JS应用的类型。取值范围如下：<br />normal：标识该JS Component为应用实例。<br />form：标识该JS Component为卡片实例。 | 字符串   | 可缺省，缺省值为“normal” |
  | mode     | 定义JS组件的开发模式。                                       | 对象     | 可缺省，缺省值为空       |

  配置示例如下：

  ```json
     "js": [{
         "name": "widget",
         "pages": ["pages/index/index"],
         "window": {
             "designWidth": 720,
             "autoDesignWidth": true
         },
         "type": "form"
     }]
  ```

- abilities模块，用于对应卡片的LifecycleForm，内部字段结构说明：

  | 属性名称            | 含义                                                         | 数据类型   | 是否可缺省               |
  | ------------------- | ------------------------------------------------------------ | ---------- | ------------------------ |
  | name                | 表示卡片的类名。字符串最大长度为127字节。                    | 字符串     | 否                       |
  | description         | 表示卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串     | 可缺省，缺省为空。       |
  | isDefault           | 表示该卡片是否为默认卡片，每个Ability有且只有一个默认卡片。<br />true：默认卡片。<br />false：非默认卡片。 | 布尔值     | 否                       |
  | type                | 表示卡片的类型。取值范围如下：<br />JS：JS卡片。             | 字符串     | 否                       |
  | colorMode           | 表示卡片的主题样式，取值范围如下：<br />auto：自适应。<br />dark：深色主题。<br />light：浅色主题。 | 字符串     | 可缺省，缺省值为“auto”。 |
  | supportDimensions   | 表示卡片支持的外观规格，取值范围：<br />1 * 2：表示1行2列的二宫格。<br />2 * 2：表示2行2列的四宫格。<br />2 * 4：表示2行4列的八宫格。<br />4 * 4：表示4行4列的十六宫格。 | 字符串数组 | 否                       |
  | defaultDimension    | 表示卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串     | 否                       |
  | updateEnabled       | 表示卡片是否支持周期性刷新，取值范围：<br />true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，优先选择定时刷新。<br />false：表示不支持周期性刷新。 | 布尔类型   | 否                       |
  | scheduledUpdateTime | 表示卡片的定点刷新的时刻，采用24小时制，精确到分钟。<br />updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 字符串     | 可缺省，缺省值为“0:0”。  |
  | updateDuration      | 表示卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br />当取值为0时，表示该参数不生效。<br />当取值为正整数N时，表示刷新周期为30*N分钟。<br />updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 数值       | 可缺省，缺省值为“0”。    |
  | formConfigAbility   | 表示卡片的配置跳转链接，采用URI格式。                        | 字符串     | 可缺省，缺省值为空。     |
  | formVisibleNotify   | 标识是否允许卡片使用卡片可见性通知。                         | 字符串     | 可缺省，缺省值为空。     |
  | jsComponentName     | 表示JS卡片的Component名称。字符串最大长度为127字节。         | 字符串     | 否                       |
  | metaData            | 表示卡片的自定义信息，包含customizeData数组标签。            | 对象       | 可缺省，缺省值为空。     |
  | customizeData       | 表示自定义的卡片信息。                                       | 对象数组   | 可缺省，缺省值为空。     |
  
  配置示例如下：

  ```json
     "abilities": [{
         "name": "FormAbility",
         "description": "This is a FormAbility",
         "formsEnabled": true,
         "icon": "$media:icon",
         "label": "$string:form_FormAbility_label",
         "srcPath": "FormAbility",
         "type": "service",
         "srcLanguage": "ets",
         "formsEnabled": true,
         "forms": [{
             "colorMode": "auto",
             "defaultDimension": "2*2",
             "description": "This is a service widget.",
             "formVisibleNotify": true,
             "isDefault": true,
             "jsComponentName": "widget",
             "name": "widget",
             "scheduledUpdateTime": "10:30",
             "supportDimensions": ["2*2"],
             "type": "JS",
             "updateEnabled": true
          }]
     }]
  ```


### 卡片信息的持久化

因大部分卡片提供方都不是常驻服务，只有在需要使用时才会被拉起获取卡片信息，且卡片管理服务支持对卡片进行多实例管理，卡片ID对应实例ID，因此若卡片提供方支持对卡片数据进行配置，则需要对卡片的业务数据按照卡片ID进行持久化管理，以便在后续获取、更新以及拉起时能获取到正确的卡片业务数据。

```javascript
       onCreate(want) {
           console.log('FormAbility onCreate');

           let formId = want.parameters["ohos.extra.param.key.form_identity"];
           let formName = want.parameters["ohos.extra.param.key.form_name"];
           let tempFlag = want.parameters["ohos.extra.param.key.form_temporary"];
           // 由开发人员自行实现，将创建的卡片信息持久化，以便在下次获取/更新该卡片实例时进行使用
           // storeFormInfo 接口未在此处实现，具体实现请参考：相关实例 章节中的 FormAbility FA模型卡片 实例
           storeFormInfo(formId, formName, tempFlag, want);

           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       }
```

同时需要适配onDestroy卡片删除通知接口，在其中实现卡片实例数据的删除。

```javascript
       onDestroy(formId) {
           console.log('FormAbility onDestroy');

           // 由开发人员自行实现，删除之前持久化的卡片实例数据
           // deleteFormInfo 接口未在此处实现，具体实现请参考：相关实例 章节中的 FormAbility FA模型卡片 实例
           deleteFormInfo(formId);
       }
```

具体的持久化方法可以参考[轻量级数据存储开发指导](../database/database-storage-guidelines.md)。

需要注意的是，卡片使用方在请求卡片时传递给提供方应用的Want数据中存在临时标记字段，表示此次请求的卡片是否为临时卡片：

- 常态卡片：卡片使用方会持久化的卡片；

- 临时卡片：卡片使用方不会持久化的卡片；

由于临时卡片的数据具有非持久化的特殊性，某些场景比如卡片服务框架死亡重启，此时临时卡片数据在卡片管理服务中已经删除，且对应的卡片ID不会通知到提供方，所以卡片提供方需要自己负责清理长时间未删除的临时卡片数据。同时对应的卡片使用方可能会将之前请求的临时卡片转换为常态卡片。如果转换成功，卡片提供方也需要对对应的临时卡片ID进行处理，把卡片提供方记录的临时卡片数据转换为常态卡片数据，防止提供方在清理长时间未删除的临时卡片时，把已经转换为常态卡片的临时卡片信息删除，导致卡片信息丢失。

### 卡片数据交互

当卡片应用需要更新数据时（如触发了定时更新或定点更新），卡片应用获取最新数据，并调用updateForm接口更新卡片。示例如下：

```javascript
onUpdate(formId) {
    // 若卡片支持定时更新/定点更新/卡片使用方主动请求更新功能，则提供方需要重写该方法以支持数据更新
    console.log('FormAbility onUpdate');
    let obj = {
        "title": "titleOnUpdate",
        "detail": "detailOnUpdate"
    };
    let formData = formBindingData.createFormBindingData(obj);
    // 调用updateForm接口去更新对应的卡片，仅更新入参中携带的数据信息，其他信息保持不变
    formProvider.updateForm(formId, formData).catch((error) => {
        console.log('FormAbility updateForm, error:' + JSON.stringify(error));
    });
}
```

### 开发卡片页面

开发者可以使用hml+css+json开发JS卡片页面：

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 当前仅支持JS扩展的类Web开发范式来实现卡片的UI页面。

   - hml:
   ```html
   <div class="container">
       <stack>
           <div class="container-img">
               <image src="/common/widget.png" class="bg-img"></image>
           </div>
           <div class="container-inner">
               <text class="title">{{title}}</text>
               <text class="detail_text" onclick="routerEvent">{{detail}}</text>
           </div>
       </stack>
   </div>
   ```

   - css:

   ```css
.container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.bg-img {
    flex-shrink: 0;
    height: 100%;
}

.container-inner {
    flex-direction: column;
    justify-content: flex-end;
    align-items: flex-start;
    height: 100%;
    width: 100%;
    padding: 12px;
}

.title {
    font-size: 19px;
    font-weight: bold;
    color: white;
    text-overflow: ellipsis;
    max-lines: 1;
}

.detail_text {
    font-size: 16px;
    color: white;
    opacity: 0.66;
    text-overflow: ellipsis;
    max-lines: 1;
    margin-top: 6px;
}
   ```

   - json:
   ```json
   {
     "data": {
       "title": "TitleDefault",
       "detail": "TextDefault"
     },
     "actions": {
       "routerEvent": {
         "action": "router",
         "abilityName": "com.example.MyApplication.hmservice.FormAbility",
         "params": {
           "message": "add detail"
         }
       }
     }
   }
   ```

最终可以得到如下卡片：

![fa-form-example](figures/fa-form-example.png)

## 相关实例

针对FA模型卡片提供方的开发，有以下相关实例可供参考：
- [`FormAbility`：FA模型卡片（eTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/FormAbility)
- [`FormLauncher`：卡片使用方（eTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/FormLauncher)