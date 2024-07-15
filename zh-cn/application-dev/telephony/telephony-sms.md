# 短信服务

## 场景介绍

短信服务模块提供了管理短信的一些基础能力，包括创建、发送短信，获取、设置发送短信的默认SIM卡槽ID，获取、设置短信服务中心地址，以及检查当前设备是否具备短信发送和接收能力等。

## 基本概念

- 短信服务

  即SMS（Short Messaging Service），是一种存储和转发服务。用户的移动电话可以通过它进行相互收发短信，内容以文本、数字或二进制非文本数据为主。发送方的信息通过短信服务中心进行储存并转发给接收方。

- 短信服务中心

  即SMSC（Short Message Service Center），负责在基站和移动设备间中继、储存或转发短消息。移动设备到短信服务中心的协议能传输来自移动设备或朝向移动设备的短消息，协议内容遵从GSM 03.40协议。

- 协议数据单元

  即PDU（Protocol Data Unit），PDU模式收发短信可以使用3种编码：7-bit、8-bit和UCS-2编码。7-bit编码用于发送普通的ASCII字符，8-bit编码通常用于发送数据短信，UCS-2编码用于发送Unicode字符。

## 约束与限制

1. 仅支持在标准系统上运行。
2. 需授予发送短信权限且插入SIM卡才可成功发送短信。


## 接口说明

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用callback函数，更多方式可以查阅[API参考](../reference/apis-telephony-kit/js-apis-sms.md)。

| 接口名                                                       | 描述                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| sendShortMessage(options: SendMessageOptions, callback: AsyncCallback\<void\>): void              | 发送文本或数据SMS消息。                                                      |
| createMessage(pdu: Array\<number\>, specification: string, callback: AsyncCallback\<ShortMessage\>): void | 基于协议数据单元（PDU）和指定的SMS协议创建SMS消息实例。 |
| getDefaultSmsSlotId(callback: AsyncCallback\<number\>): void   | 获取用于发送短信的默认SIM卡。                                                |
| setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void\>): void | 根据指定的插槽ID设置短信服务中心的地址。                |
| getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void | 根据指定的插槽ID获取短信服务中心地址。                                  |

<!--Del-->
## 开发步骤（仅供系统应用使用）

1. 声明接口调用所需要的权限：
   - 如果是想发送短信，则调用sendShortMessage接口，需要配置ohos.permission.SEND_MESSAGES权限，权限级别为system_basic。
   - 如果是想设置短信服务中心地址，则调用setSmscAddr接口，需要配置ohos.permission.SET_TELEPHONY_STATE权限，权限级别为system_basic。
   - 如果是想获取短信服务中心地址，则调用getSmscAddr接口，需要配置ohos.permission.GET_TELEPHONY_STATE权限，权限级别为system_basic。
   在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)声明对应权限。

2. import需要的模块。

3. 发送SMS消息。

```ts
// 示例代码
import { sms } from '@kit.TelephonyKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

let sendCallback: AsyncCallback<sms.ISendShortMessageCallback> = (err: BusinessError, data: sms.ISendShortMessageCallback) => {
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let deliveryCallback: AsyncCallback<sms.IDeliveryShortMessageCallback> = (err: BusinessError, data: sms.IDeliveryShortMessageCallback) => {
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let slotId: number = 0;
let content: string = '短信内容';
let destinationHost: string = '+861xxxxxxxxxx';
let serviceCenter: string = '+861xxxxxxxxxx';
let destinationPort: number = 1000;
let options: sms.SendMessageOptions = {slotId, content, destinationHost, serviceCenter, destinationPort, sendCallback, deliveryCallback};
sms.sendShortMessage(options, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});

```
<!--DelEnd-->

## 开发步骤

若需要在应用内实现跳转到短信编辑的功能，并且需要携带编辑内容和收件人号码，可以通过调用元能力 startAbility 接口指定号码并跳转到发送短信页面的方式实现。

```ts
// 示例代码
import { common, Want } from '@kit.AbilityKit';

const MMS_BUNDLE_NAME = "com.ohos.mms";
const MMS_ABILITY_NAME = "com.ohos.mms.MainAbility";
const MMS_ENTITIES = "entity.system.home";

export class Contact {
    contactsName: string;
    telephone: number;

    constructor(contactsName: string, telephone: number) {
        this.contactsName = contactsName;
        this.telephone = telephone;
    }
}

@Entry
@Component
struct JumpMessage {
    private context = getContext(this) as common.UIAbilityContext;

    startMMSAbilityExplicit() {
        // 这里完善联系人和号码；姓名主要是通过手机号来查询实际联系人名称，因此这种方式还是以手机号码为主。
        let params: Array<Object> = [new Contact("张三", 13344556677)];

        let want: Want = {
            bundleName: "com.ohos.mms",
            abilityName: "com.ohos.mms.MainAbility",
            parameters: {
                contactObjects: JSON.stringify(params),
                pageFlag: "conversation",
                // 这里填写短信内容。
                content: "我是短信具体内容"
            }
        };

        this.context.startAbilityForResult(want).then((data) => {
            console.log("Success" + JSON.stringify(data));
        }).catch(() => {
            console.log("error");
        });
    }

    build() {
        Row() {
            Column() {
                Button('发送短信')
                  .onClick(() => {
                      this.startMMSAbilityExplicit();
                  })
            }
            .width('100%')
        }
        .height('100%')
    }
}

```

## 相关实例

针对短信的使用，有以下相关实例可供参考：

- [短信服务（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Telephony/Message)
