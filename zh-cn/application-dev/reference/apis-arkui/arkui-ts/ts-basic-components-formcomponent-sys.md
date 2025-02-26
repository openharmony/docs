# FormComponent (系统接口)

提供卡片组件，实现卡片的显示功能。

>  **说明：**
>
> - 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 该组件为卡片组件的使用方，对应提供方的使用参考文档[JS服务卡片UI组件](../js-service-widget-ui/js-service-widget-file.md)。
>
> - 该组件使用需要具有系统签名。
>
> - 本模块为系统接口。

## 权限

ohos.permission.REQUIRE_FORM, ohos.permission.GET_BUNDLE_INFO_PRIVILEGED


## 子组件

无


## 接口

FormComponent (value: FormInfo)

创建卡片组件，用于显示提供的卡片。

**参数：**

| 参数名    | 参数类型                        | 必填 | 参数描述                                                                |
| --------- | ------------------------------- | ---- | ----------------------------------------------------------------------- |
| value        | [FormInfo](#forminfo12)                 | 是   | 卡片信息。   |

## FormInfo<sup>12+</sup>

卡片信息。

| 参数名    | 参数类型                        | 必填 | 参数描述                                                                |
| --------- | ------------------------------- | ---- |-------|
| id        | number \| string                    | 是   | 卡片标识（新建卡片填0）。<br/>**说明：**<br>不同使用方不可使用相同id。<br/>同一使用方使用相同id时，显示后添加的卡片。                                        |
| name      | string                          | 是   | 卡片名称。                                                              |
| bundle    | string                          | 是   | 目标卡片包名。                                                          |
| ability   | string                          | 是   | 目标卡片Ability名称。                                                   |
| module    | string                          | 是   | 卡片模块名称。                                                          |
| dimension | [FormDimension](#formdimension) | 否   | 卡片尺寸，支持2 * 2，4 * 4，4 * 2类型卡片。<br/>默认值：Dimension_2_2。 |
| temporary | boolean                         | 否   | 卡片是否为临时卡片。                                                    |
| renderingMode | [FormRenderingMode](#formrenderingmode11) | 否   | 卡片渲染模式。取值如下，默认值为 FULL_COLOR。<br>- FULL_COLOR：代表全色模式，卡片框架不会对卡片效果做出修改，保持和卡片开发者设置的效果不变。<br>- SINGLE_COLOR：代表单色模式，卡片框架会把卡片背景设为透明，开发者需按最佳实践设置卡片风格。<br>**说明：**<br/>如果系统不支持统一渲染模式，卡片框架在单色模式下也不会把卡片背景设为透明。 |

## FormCallbackInfo<sup>12+</sup>

卡片查询或者卸载时获取formId的参数。

| 参数名    | 参数类型                        | 必填 | 参数描述                                                                |
| --------- | ------------------------------- | ---- | ----------------------------------------------------------------------- |
| id        | number                 | 是   | 卡片标识（number类型）。<br/>**说明：**<br>如果获取到的id为-1，说明id大于等于2^53，需要使用idString获取。                                        |
| idString      | string            | 是           | 卡片标识（string类型）。                             |
| isLocked<sup>16+</sup>  |boolean  | 是           | 标识卡片是否为[管控状态](../../apis-form-kit/js-apis-app-form-formHost-sys.md#updateformlockedstate16)，true表示管控状态，false表示非管控状态。     |

## FormDimension

| 名称                       | 描述     |
| -------------------------- | -------- |
| Dimension_1_2              | 1*2 卡片 |
| Dimension_2_2              | 2*2 卡片 |
| Dimension_2_4              | 2*4 卡片 |
| Dimension_4_4              | 4*4 卡片 |
| Dimension_2_1<sup>9+</sup> | 2*1 卡片 |
| Dimension_1_1<sup>11+</sup> | 1*1 卡片 |
| Dimension_6_4<sup>12+</sup> | 6*4 卡片 |
| Dimension_2_3<sup>14+</sup> | 2*3 卡片为穿戴设备使用 |
| Dimension_3_3<sup>14+</sup> | 3*3 卡片为穿戴设备使用 |

## FormRenderingMode<sup>11+</sup>
| 名称                       | 描述     |
| -------------------------- | -------- |
| FULL_COLOR                 | 全色模式。|
| SINGLE_COLOR               | 单色模式。|

## 属性

### size

size(value: { width: number; height: number })

设置高宽尺寸。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                      | 必填 | 说明       |
| ------ | --------------------------------------------------------- | ---- | ---------- |
| value  | {<br/>width?:&nbsp;number,<br/>height?:&nbsp;number<br/>} | 是   | 宽高尺寸。 |

### moduleName

moduleName(value: string)

设置卡片模块名称。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| value  | string | 是   | 卡片模块名称。 |

### dimension

dimension(value: FormDimension)

设置卡片尺寸，支持2 * 2，4 * 4，4 * 2类型卡片。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                            | 必填 | 说明                                 |
| ------ | ------------------------------- | ---- | ------------------------------------ |
| value  | [FormDimension](#formdimension) | 是   | 卡片尺寸。<br/>默认值：Dimension_2_2 |

### allowUpdate

allowUpdate(value: boolean)

设置是否允许卡片更新。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                |
| ------ | ------- | ---- | ----------------------------------- |
| value  | boolean | 是   | 是否允许卡片更新。<br/>默认值：true |

### visibility

visibility(value: Visibility)

设置是否允许卡片可见。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                   |
| ------ | --------------------------------------------- | ---- | -------------------------------------- |
| value  | [Visibility](ts-appendix-enums.md#visibility) | 是   | 是否允许卡片可见。<br/>默认值：Visible |

## 事件

### onAcquired

onAcquired(callback:&nbsp;Callback[\<FormCallbackInfo>](#formcallbackinfo12)):&nbsp;FormComponentAttribute

获取到卡片后触发，返回卡片的id。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | ---------- |
| Callback | [FormCallbackInfo](#formcallbackinfo12) | 是   | 卡片的id。 |

### onError

onError(callback: (info: { errcode: number; msg: string }) => void)

组件加载错误回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                            |
| ------ | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| info   | &nbsp;{&nbsp;errcode:&nbsp;number,&nbsp;msg:&nbsp;string&nbsp;} | 是   | errcode:&nbsp;错误码。<br/>msg:&nbsp;错误信息。 |

### onRouter

onRouter(callback:&nbsp;(info:&nbsp;any)&nbsp;=&gt;&nbsp;void)

组件路由事件回调，返回[routerEvent](../js-service-widget-ui/js-service-widget-syntax-hml.md#事件绑定)中的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | ---- | ---- | ------------------------------------------------------------ |
| info   | any  | 是   | [routerEvent](../js-service-widget-ui/js-service-widget-syntax-hml.md#事件绑定)中的信息。 |

### onUninstall

onUninstall(callback:&nbsp;Callback[\<FormCallbackInfo>](#formcallbackinfo12)):&nbsp;FormComponentAttribute

组件卸载回调，返回卸载卡片的id。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | ---------- |
| Callback   | [FormCallbackInfo](#formcallbackinfo12) | 是   | 卡片的id。 |


## 示例

卡片示例。

该示例创建一张2 * 2尺寸大小的卡片，并注册事件回调。
```ts
//card.ets
@Entry
@Component
struct CardExample {
  @State formId:string = '0';
  build() {
    Column() {
      Text('this is a card')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      FormComponent({
        id:this.formId,
        name:"Form1",
        bundle:"com.example.cardexample",
        ability:"FormAbility",
        module:"entry",
        dimension:FormDimension.Dimension_2_2,
        temporary:false
      })
        .allowUpdate(true)
        .size({width:360,height:360})
        .visibility(Visibility.Visible)
        .onAcquired((form: FormCallbackInfo)=>{
          console.log(`form info : ${JSON.stringify(form)}`);
          // Invalid form id
          if (form.id == -1) {
            this.formId = form.idString;
          } else {
            this.formId = form.id.toString();
          }
        })
        .onError((err)=>{
          console.log(`fail to add form, err: ${JSON.stringify(err)}`);
        })
        .onUninstall((form: FormCallbackInfo)=>{
          console.log(`uninstall form success : ${JSON.stringify(form)}`);
          // Invalid form id
          if (form.id == -1) {
            this.formId = form.idString;
          } else {
            this.formId = form.id.toString();
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![Form](figures/form.png)