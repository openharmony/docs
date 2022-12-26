# Stage卡片开发指导

## 卡片概述

卡片是一种界面展示形式，可以将应用的重要信息或操作前置到卡片，以达到服务直达，减少体验层级的目的。

卡片常用于嵌入到其他应用（当前只支持系统应用）中作为其界面的一部分显示，并支持拉起页面，发送消息等基础的交互功能。卡片使用方负责显示卡片。

卡片的基本概念：

- 卡片提供方：提供卡片显示内容原子化服务，控制卡片的显示内容、控件布局以及控件点击事件。
- 卡片使用方：显示卡片内容的宿主应用，控制卡片在宿主中展示的位置。
- 卡片管理服务：用于管理系统中所添加卡片的常驻代理服务，包括卡片对象的管理与使用，以及卡片周期性刷新等。

> **说明：**
> 卡片使用方和提供方不要求常驻运行，在需要添加/删除/请求更新卡片时，卡片管理服务会拉起卡片提供方获取卡片信息。

开发者仅需作为卡片提供方进行卡片内容的开发，卡片使用方和卡片管理服务由系统自动处理。

卡片提供方控制卡片实际显示的内容、控件布局以及点击事件。

## 场景介绍

Stage卡片开发，即基于[Stage模型](stage-brief.md)的卡片提供方开发，主要涉及如下功能逻辑：

- 卡片生命周期回调函数FormExtension开发。
- 创建卡片数据FormBindingData对象。
- 通过FormProvider更新卡片。
- 卡片页面开发。

## 接口说明

FormExtension类拥有如下API接口，具体的API介绍详见[接口文档](../reference/apis/js-apis-app-form-formExtensionAbility.md)。

**表1** FormExtension API接口功能介绍

| 接口名                                                       | 描述                                         |
| :----------------------------------------------------------- | :------------------------------------------- |
| onCreate(want: Want): formBindingData.FormBindingData        | 卡片提供方接收创建卡片的通知接口。           |
| onCastToNormal(formId: string): void                         | 卡片提供方接收临时卡片转常态卡片的通知接口。 |
| onUpdate(formId: string): void                               | 卡片提供方接收更新卡片的通知接口。           |
| onVisibilityChange(newStatus: { [key: string]: number }): void | 卡片提供方接收修改可见性的通知接口。         |
| onEvent(formId: string, message: string): void               | 卡片提供方接收处理卡片事件的通知接口。       |
| onDestroy(formId: string): void                              | 卡片提供方接收销毁卡片的通知接口。           |
| onConfigurationUpdated(config: Configuration): void;         | 当系统配置更新时调用。                       |

FormExtension类还拥有成员context，为FormExtensionContext类，具体的API介绍详见[接口文档](../reference/apis/js-apis-inner-application-formExtensionContext.md)。

**表2** FormExtensionContext API接口功能介绍

| 接口名                                                       | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void | 回调形式拉起一个卡片所属应用的Ability（系统接口，三方应用不支持调用）。 |
| startAbility(want: Want): Promise&lt;void&gt;                | Promise形式拉起一个卡片所属应用的Ability（系统接口，三方应用不支持调用）。 |

FormProvider类具体的API介绍详见[接口文档](../reference/apis/js-apis-application-formProvider.md)。

**表3** FormProvider API接口功能介绍

| 接口名                                                       | 描述                                              |
| :----------------------------------------------------------- | :------------------------------------------------ |
| setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void; | 设置指定卡片的下一次更新时间。                    |
| setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;; | 设置指定卡片的下一次更新时间，以promise方式返回。 |
| updateForm(formId: string, formBindingData: FormBindingData, callback: AsyncCallback&lt;void&gt;): void; | 更新指定的卡片。                                  |
| updateForm(formId: string, formBindingData: FormBindingData): Promise&lt;void&gt;; | 更新指定的卡片，以promise方式返回。               |

## 开发步骤

### 创建卡片FormExtension

创建Stage模型的卡片，需实现FormExtension生命周期接口。具体示例代码如下：

1. 导入相关模块

   ```javascript
   import FormExtension from '@ohos.application.FormExtension'
   import formBindingData from '@ohos.application.formBindingData'
   import formInfo from '@ohos.application.formInfo'
   import formProvider from '@ohos.application.formProvider'
   ```

2. 实现FormExtension生命周期接口

   ```javascript
   export default class FormAbility extends FormExtension {
       onCreate(want) {
           console.log('FormAbility onCreate');
           // 由开发人员自行实现，将创建的卡片信息持久化，以便在下次获取/更新该卡片实例时进行使用
           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       }
       onCastToNormal(formId) {
           // 使用方将临时卡片转换为常态卡片触发，提供方需要做相应的处理
           console.log('FormAbility onCastToNormal');
       }
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
       }
       onVisibilityChange(newStatus) {
           // 使用方发起可见或者不可见通知触发，提供方需要做相应的处理
           console.log('FormAbility onVisibilityChange');
       }
       onEvent(formId, message) {
           // 若卡片支持触发事件，则需要重写该方法并实现对事件的触发
           console.log('FormAbility onEvent');
       }
       onDestroy(formId) {
           // 删除卡片实例数据
           console.log('FormAbility onDestroy');
       }
       onConfigurationUpdated(config) {
           console.log('FormAbility onConfigurationUpdated, config:' + JSON.stringify(config));
       }
   }
   ```

### 配置卡片配置文件

- 卡片需要在应用配置文件module.json5中的extensionAbilities标签下，配置ExtensionAbility相关信息，内部字段结构说明：

  | 属性名称    | 含义                                                         | 数据类型   | 是否可缺省           |
  | ----------- | ------------------------------------------------------------ | ---------- | -------------------- |
  | name        | 表示ExtensionAbility的名字，该标签不可缺省。                 | 字符串     | 否                   |
  | srcEntrance | 表示ExtensionAbility所对应的生命周期代码的路径，该标签不可缺省。 | 字符串     | 否                   |
  | description | 表示ExtensionAbility的描述。可以是表示描述内容的字符串，也可以是对描述内容的资源索引以支持多语言。 | 字符串     | 可缺省，缺省值为空。 |
  | icon        | 表示ExtensionAbility的图标资源文件的索引。                   | 字符串     | 可缺省，缺省值为空。 |
  | label       | 表示ExtensionAbility的标签信息，即ExtensionAbility对外显示的文字描述信息。取值可以是描述性内容，也可以是标识label的资源索引。 | 字符串     | 可缺省，缺省值为空。 |
  | type        | 表示ExtensionAbility的类型，对于当前FormExtensionAbility的开发，需要将其配置为form。 | 字符串     | 否                   |
  | permissions | 表示其他应用的Ability调用此Ability时需要申请的权限。         | 字符串数组 | 可缺省，缺省值为空。 |
  | metadata    | 表示ExtensionAbility的元信息，用于描述ExtensionAbility的配置信息。 | 对象       | 可缺省，缺省值为空   |

  对于FormExtensionAbility来说，需要填写metadata元信息标签，其中键名称为固定字符串"ohos.extension.form"，资源为卡片的具体配置信息的索引。

  配置示例如下：

     ```json
  "extensionAbilities": [{
      "name": "FormAbility",
      "srcEntrance": "./ets/FormAbility/FormAbility.ts",
      "label": "$string:form_FormAbility_label",
      "description": "$string:form_FormAbility_desc",
      "type": "form",
      "metadata": [{
          "name": "ohos.extension.form",
          "resource": "$profile:form_config"
      }]
  }]
     ```

- 卡片的具体配置信息。在上述 FormExtensionAbility 的元信息中，指定了的卡片具体配置信息的资源索引，如使用  $profile:form_config 指定开发视图的 resources/base/profile/ 目录下的 form_config.json 作为卡片profile配置文件。

  内部字段结构说明：
  
  | 属性名称            | 含义                                                         | 数据类型   | 是否可缺省               |
  | ------------------- | ------------------------------------------------------------ | ---------- | ------------------------ |
  | name                | 表示卡片的类名，字符串最大长度为127字节。                    | 字符串     | 否                       |
  | description         | 表示卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串     | 可缺省，缺省为空。       |
  | src                 | 表示卡片对应的UI代码的完整路径。                             | 字符串     | 否                       |
  | window              | 用于定义与显示窗口相关的配置。                               | 对象       | 可缺省                   |
  | isDefault           | 表示该卡片是否为默认卡片，每个Ability有且只有一个默认卡片。<br />true：默认卡片。<br />false：非默认卡片。 | 布尔值     | 否                       |
  | colorMode           | 表示卡片的主题样式，取值范围如下：<br />auto：自适应。<br />dark：深色主题。<br />light：浅色主题。 | 字符串     | 可缺省，缺省值为“auto”。 |
  | supportDimensions   | 表示卡片支持的外观规格，取值范围：<br />1 * 2：表示1行2列的二宫格。<br />2 * 2：表示2行2列的四宫格。<br />2 * 4：表示2行4列的八宫格。<br />4 * 4：表示4行4列的十六宫格。 | 字符串数组 | 否                       |
  | defaultDimension    | 表示卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串     | 否                       |
  | updateEnabled       | 表示卡片是否支持周期性刷新，取值范围：<br />true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，优先选择定时刷新。<br />false：表示不支持周期性刷新。 | 布尔类型   | 否                       |
  | scheduledUpdateTime | 表示卡片的定点刷新的时刻，采用24小时制，精确到分钟。<br />updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 字符串     | 可缺省，缺省值为“0:0”。  |
  | updateDuration      | 表示卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br />当取值为0时，表示该参数不生效。<br />当取值为正整数N时，表示刷新周期为30*N分钟。<br />updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 数值       | 可缺省，缺省值为“0”。    |
  | formConfigAbility   | 表示卡片的配置跳转链接，采用URI格式。                        | 字符串     | 可缺省，缺省值为空。     |
  | formVisibleNotify   | 标识是否允许卡片使用卡片可见性通知。                         | 字符串     | 可缺省，缺省值为空。     |
  | metaData            | 表示卡片的自定义信息，包含customizeData数组标签。            | 对象       | 可缺省，缺省值为空。     |

     配置示例如下：
  
     ```json
  {
      "forms": [{
          "name": "widget",
          "description": "This is a service widget.",
          "src": "./js/widget/pages/index/index",
          "window": {
              "autoDesignWidth": true,
              "designWidth": 720
          },
          "isDefault": true,
          "colorMode": "auto",
          "supportDimensions": ["2*2"],
          "defaultDimension": "2*2",
          "updateEnabled": true,
          "scheduledUpdateTime": "10:30",
          "formConfigAbility": "ability://ohos.samples.FormApplication.MainAbility"
      }]
  }
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
           // storeFormInfo 接口未在此处实现，具体实现请参考：相关实例 章节中的 FormExtAbility Stage模型卡片 实例
           storeFormInfo(formId, formName, tempFlag, want);

           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       }
```

且需要适配onDestroy卡片删除通知接口，在其中实现卡片实例数据的删除。

```javascript
       onDestroy(formId) {
           console.log('FormAbility onDestroy');

           // 由开发人员自行实现，删除之前持久化的卡片实例数据
           // deleteFormInfo 接口未在此处实现，具体实现请参考：相关实例 章节中的 FormExtAbility Stage模型卡片 实例
           deleteFormInfo(formId);
       }
```

具体的持久化方法可以参考[轻量级数据存储开发指导](../database/database-preference-guidelines.md)。

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

> **说明：**
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
         "abilityName": "MainAbility",
         "params": {
           "message": "add detail"
         }
       }
     }
   }
   ```

最终可以得到如下卡片：

![fa-form-example](figures/fa-form-example.png)

### 开发卡片事件

卡片支持为组件设置action，包括router事件和message事件，其中router事件用于Ability跳转，message事件用于卡片开发人员自定义点击事件。关键步骤说明如下：

1. 在hml中为组件设置onclick属性，其值对应到json文件的actions字段中。
2. 若设置router事件，则
   - action属性值为"router"；
   - abilityName为跳转目标的Ability名，如目前DevEco创建的Stage模型的MainAbility默认名为MainAbility；
   - params为跳转目标Ability的自定义参数，可以按需填写。其值可以在目标Ability启动时的want中的parameters里获取。如Stage模型MainAbility的onCreate生命周期里的入参want的parameters字段下获取到配置的参数；
3. 若设置message事件，则
   - action属性值为"message"；
   - params为message事件的用户自定义参数，可以按需填写。其值可以在卡片生命周期函数onEvent中的message里获取；

示例如下：

   - hml:
   ```html
   <div class="container">
       <stack>
           <div class="container-img">
               <image src="/common/widget.png" class="bg-img"></image>
           </div>
           <div class="container-inner">
               <text class="title" onclick="routerEvent">{{title}}</text>
               <text class="detail_text" onclick="messageEvent">{{detail}}</text>
           </div>
       </stack>
   </div>
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
         "abilityName": "MainAbility",
         "params": {
           "message": "add detail"
         }
       },
       "messageEvent": {
         "action": "message",
         "params": {
           "message": "add detail"
         }
       }
     }
   }
   ```
## 相关实例

针对Stage模型卡片提供方的开发，有以下相关实例可供参考：
- [`FormExtAbility`：Stage模型卡片（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/FormExtAbility)
- [`GalleryForm`：图库卡片（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/GalleryForm)