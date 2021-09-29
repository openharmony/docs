# 短信服务<a name="ZH-CN_TOPIC_0000001150660760"></a>

-   [导入模块](#section111401036143)
-   [sms.createMessage](#section3831173019331)
-   [sms.createMessage](#section9796242123511)
-   [sms.sendMessage](#section128401423810)
-   [sms.getDefaultSmsSlotId7+](#section46193383478)
-   [sms.getDefaultSmsSlotId7+](#section19981626114817)
-   [sms.setSmscAddr7+](#section155849574485)
-   [sms.setSmscAddr7+](#section7801426144910)
-   [sms.getSmscAddr7+](#section347174613494)
-   [sms.getSmscAddr7+](#section1178428175016)
-   [ShortMessage](#section345181318300)
-   [ShortMessageClass](#section141712166453)
-   [SendMessageOptions](#section12262183471518)
-   [ISendShortMessageCallback](#section16646146115317)
-   [IDeliveryShortMessageCallback](#section12183749531)
-   [SendSmsResult](#section13290132311575)

>**说明：** 
>
>标记7+的表示从API Version 7开始支持，未标记的表示从API Version 6开始支持。

## 导入模块<a name="section111401036143"></a>

```
import sms from '@ohos.telephony.sms';
```

## sms.createMessage<a name="section3831173019331"></a>

createMessage\(pdu: Array<number\>, specification: string, callback: AsyncCallback<ShortMessage\>\): void

根据协议数据单元（PDU）和指定的短信协议创建短信实例，使用callback方式作为异步方法。

- 参数

  <a name="table11872418104316"></a>

  <table><thead align="left"><tr id="row13873518134320"><th class="cellrowborder" valign="top" width="15.53%" id="mcps1.1.5.1.1"><p id="p1873111820437"><a name="p1873111820437"></a><a name="p1873111820437"></a>参数名</p>
  </th>
  <th class="cellrowborder" valign="top" width="31.47%" id="mcps1.1.5.1.2"><p id="p687301844313"><a name="p687301844313"></a><a name="p687301844313"></a>类型</p>
  </th>
  <th class="cellrowborder" valign="top" width="6.9%" id="mcps1.1.5.1.3"><p id="p19873318114314"><a name="p19873318114314"></a><a name="p19873318114314"></a>必填</p>
  </th>
  <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p1087316184438"><a name="p1087316184438"></a><a name="p1087316184438"></a>说明</p>
  </th>
  </tr>
  </thead>
  <tbody><tr id="row1587321816434"><td class="cellrowborder" valign="top" width="15.53%" headers="mcps1.1.5.1.1 "><p id="p13873218194315"><a name="p13873218194315"></a><a name="p13873218194315"></a>pdu</p>
  </td>
  <td class="cellrowborder" valign="top" width="31.47%" headers="mcps1.1.5.1.2 "><p id="p11873818114315"><a name="p11873818114315"></a><a name="p11873818114315"></a>Array&lt;number&gt;</p>
  </td>
  <td class="cellrowborder" valign="top" width="6.9%" headers="mcps1.1.5.1.3 "><p id="p14873018194316"><a name="p14873018194316"></a><a name="p14873018194316"></a>是</p>
  </td>
  <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p19874418104310"><a name="p19874418104310"></a><a name="p19874418104310"></a>协议数据单元，从收到的信息中获取。</p>
  </td>
  </tr>
  <tr id="row1268000144419"><td class="cellrowborder" valign="top" width="15.53%" headers="mcps1.1.5.1.1 "><p id="p46801407448"><a name="p46801407448"></a><a name="p46801407448"></a>specification</p>
  </td>
  <td class="cellrowborder" valign="top" width="31.47%" headers="mcps1.1.5.1.2 "><p id="p206811503445"><a name="p206811503445"></a><a name="p206811503445"></a>string</p>
  </td>
  <td class="cellrowborder" valign="top" width="6.9%" headers="mcps1.1.5.1.3 "><p id="p1468111016441"><a name="p1468111016441"></a><a name="p1468111016441"></a>是</p>
  </td>
  <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p041710431522"><a name="p041710431522"></a><a name="p041710431522"></a>短信协议类型。</p>
  <a name="ul331674955216"></a><a name="ul331674955216"></a><ul id="ul331674955216"><li>3gpp表示GSM/UMTS/LTE SMS</li><li>3gpp2表示CDMA SMS</li></ul>
  </td>
  </tr>
  <tr id="row0874181814310"><td class="cellrowborder" valign="top" width="15.53%" headers="mcps1.1.5.1.1 "><p id="p88742018194313"><a name="p88742018194313"></a><a name="p88742018194313"></a>callback</p>
  </td>
  <td class="cellrowborder" valign="top" width="31.47%" headers="mcps1.1.5.1.2 "><p id="p15874718174310"><a name="p15874718174310"></a><a name="p15874718174310"></a>AsyncCallback&lt;<a href="#section345181318300">ShortMessage</a>&gt;</p>
  </td>
  <td class="cellrowborder" valign="top" width="6.9%" headers="mcps1.1.5.1.3 "><p id="p11874151814438"><a name="p11874151814438"></a><a name="p11874151814438"></a>是</p>
  </td>
  <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p16874618124315"><a name="p16874618124315"></a><a name="p16874618124315"></a>回调函数。</p>
  </td>
  </tr>
  </tbody>
  </table>

-   示例

    ```
    let specification = '3gpp';
    let pdu = [0x08, 0x91, ...];
    sms.createMessage(pdu, specification, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.createMessage<a name="section9796242123511"></a>

createMessage\(pdu: Array<number\>, specification: string\): Promise<ShortMessage\>

根据协议数据单元（PDU）和指定的短信协议创建短信实例，使用Promise方式作为异步方法。

-   参数

    <a name="table1435974516216"></a>
    <table><thead align="left"><tr id="row1235934514212"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p635914451725"><a name="p635914451725"></a><a name="p635914451725"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p12359154517217"><a name="p12359154517217"></a><a name="p12359154517217"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p113593454216"><a name="p113593454216"></a><a name="p113593454216"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p15359154514213"><a name="p15359154514213"></a><a name="p15359154514213"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8359104519214"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p143596451823"><a name="p143596451823"></a><a name="p143596451823"></a>pdu</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p6359104512212"><a name="p6359104512212"></a><a name="p6359104512212"></a>Array&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p936013452211"><a name="p936013452211"></a><a name="p936013452211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p1436004511214"><a name="p1436004511214"></a><a name="p1436004511214"></a>协议数据单元，从收到的信息中获取。</p>
    </td>
    </tr>
    <tr id="row63606450217"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p2036011451325"><a name="p2036011451325"></a><a name="p2036011451325"></a>specification</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p18360164515210"><a name="p18360164515210"></a><a name="p18360164515210"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p83600454219"><a name="p83600454219"></a><a name="p83600454219"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p758422312366"><a name="p758422312366"></a><a name="p758422312366"></a>短信协议类型。</p>
    <a name="ul178213302362"></a><a name="ul178213302362"></a><ul id="ul178213302362"><li>3gpp表示GSM/UMTS/LTE SMS</li><li>3gpp2表示CDMA SMS</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table1918382310112"></a>
    <table><thead align="left"><tr id="row7183202315119"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p1918414230115"><a name="p1918414230115"></a><a name="p1918414230115"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p1918412232014"><a name="p1918412232014"></a><a name="p1918412232014"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2184132316110"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p1218415231011"><a name="p1218415231011"></a><a name="p1218415231011"></a>Promise&lt;<a href="#section345181318300">ShortMessage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p1218411231411"><a name="p1218411231411"></a><a name="p1218411231411"></a>以Promise形式返回创建的短信实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let specification = '3gpp';
    let pdu = [0x08, 0x91, ...];
    let promise = sms.createMessage(pdu, specification);
    promise.then(data => {
        console.log(`createMessage success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`createMessage fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sms.sendMessage<a name="section128401423810"></a>

sendMessage\(options: SendMessageOptions\): void

发送短信。

需要ohos.permission.SEND\_MESSAGES权限。

-   参数

    <a name="table1170025144917"></a>
    <table><thead align="left"><tr id="row14171425124919"><th class="cellrowborder" valign="top" width="19.259999999999998%" id="mcps1.1.5.1.1"><p id="p1617102513494"><a name="p1617102513494"></a><a name="p1617102513494"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.599999999999998%" id="mcps1.1.5.1.2"><p id="p181711025174911"><a name="p181711025174911"></a><a name="p181711025174911"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.36%" id="mcps1.1.5.1.3"><p id="p61711625174917"><a name="p61711625174917"></a><a name="p61711625174917"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.78%" id="mcps1.1.5.1.4"><p id="p181715257498"><a name="p181715257498"></a><a name="p181715257498"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1717292510494"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p7172925154911"><a name="p7172925154911"></a><a name="p7172925154911"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p5552285116"><a name="p5552285116"></a><a name="p5552285116"></a><a href="#section12262183471518">SendMessageOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.36%" headers="mcps1.1.5.1.3 "><p id="p131725254492"><a name="p131725254492"></a><a name="p131725254492"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p15172625154920"><a name="p15172625154920"></a><a name="p15172625154920"></a>发送短信的参数和回调，参考<a href="#section12262183471518">SendMessageOptions</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let sendCallback = function (err, data) {    
        console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
    }
    let deliveryCallback = function (err, data) {    
        console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
    }
    let slotId = 0;
    let content = '短信内容';
    let destinationHost = '+861xxxxxxxxxx';
    let serviceCenter = '+861xxxxxxxxxx';
    let destinationPort = 1000;
    let options = {slotId, content, destinationHost, serviceCenter, destinationPort, sendCallback, deliveryCallback};
    sms.sendMessage(options);
    ```


## sms.getDefaultSmsSlotId<sup>7+</sup><a name="section46193383478"></a>

getDefaultSmsSlotId\(callback: AsyncCallback<number\>\): void

获取发送短信的默认SIM卡槽ID，使用callback方式作为异步方法。

-   参数

    <a name="table640016365210"></a>
    <table><thead align="left"><tr id="row11401163612219"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p1340115368214"><a name="p1340115368214"></a><a name="p1340115368214"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p840110366210"><a name="p840110366210"></a><a name="p840110366210"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p240115363216"><a name="p240115363216"></a><a name="p240115363216"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p1940116361021"><a name="p1940116361021"></a><a name="p1940116361021"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1140120361522"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p9401103618216"><a name="p9401103618216"></a><a name="p9401103618216"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p2401103617217"><a name="p2401103617217"></a><a name="p2401103617217"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p4401036423"><a name="p4401036423"></a><a name="p4401036423"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p440103618212"><a name="p440103618212"></a><a name="p440103618212"></a>回调函数。</p>
    <a name="ul9211219141510"></a><a name="ul9211219141510"></a><ul id="ul9211219141510"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sms.getDefaultSmsSlotId((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.getDefaultSmsSlotId<sup>7+</sup><a name="section19981626114817"></a>

getDefaultSmsSlotId\(\): Promise<number\>

获取发送短信的默认SIM卡槽ID，使用Promise方式作为异步方法。

-   返回值

    <a name="table58590561095"></a>
    <table><thead align="left"><tr id="row118591561193"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p7859056599"><a name="p7859056599"></a><a name="p7859056599"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p085913569919"><a name="p085913569919"></a><a name="p085913569919"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row28591856299"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p28631116886"><a name="p28631116886"></a><a name="p28631116886"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p1785920561591"><a name="p1785920561591"></a><a name="p1785920561591"></a>以Promise形式返回发送短信的默认SIM卡：</p>
    <a name="ul297310284152"></a><a name="ul297310284152"></a><ul id="ul297310284152"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.getDefaultSmsSlotId();
    promise.then(data => {
        console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`getDefaultSmsSlotId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sms.setSmscAddr<sup>7+</sup><a name="section155849574485"></a>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

设置短信服务中心（SMSC）地址，使用callback方式作为异步方法。

需要ohos.permission.SET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table16426938237"></a>
    <table><thead align="left"><tr id="row94271538039"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p12427738837"><a name="p12427738837"></a><a name="p12427738837"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p104274381133"><a name="p104274381133"></a><a name="p104274381133"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p24274381834"><a name="p24274381834"></a><a name="p24274381834"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p3427738938"><a name="p3427738938"></a><a name="p3427738938"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row184651552734"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p546614524317"><a name="p546614524317"></a><a name="p546614524317"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p104661852439"><a name="p104661852439"></a><a name="p104661852439"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1635101510417"><a name="p1635101510417"></a><a name="p1635101510417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p34931544121518"><a name="p34931544121518"></a><a name="p34931544121518"></a>SIM卡槽ID：</p>
    <a name="ul3493164411516"></a><a name="ul3493164411516"></a><ul id="ul3493164411516"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
    </td>
    </tr>
    <tr id="row8924552151"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p119251252255"><a name="p119251252255"></a><a name="p119251252255"></a>smscAddr</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p129253521658"><a name="p129253521658"></a><a name="p129253521658"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p8958171314615"><a name="p8958171314615"></a><a name="p8958171314615"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p14925352154"><a name="p14925352154"></a><a name="p14925352154"></a>短信服务中心地址。</p>
    </td>
    </tr>
    <tr id="row4427938632"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p64275383316"><a name="p64275383316"></a><a name="p64275383316"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p11427183811320"><a name="p11427183811320"></a><a name="p11427183811320"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p20427238435"><a name="p20427238435"></a><a name="p20427238435"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p174278382318"><a name="p174278382318"></a><a name="p174278382318"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let smscAddr = '+861xxxxxxxxxx';
    sms.setSmscAddr(slotId, smscAddr, (err,data) => {
          console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.setSmscAddr<sup>7+</sup><a name="section7801426144910"></a>

setSmscAddr\(slotId: number, smscAddr: string\): Promise<void\>

设置短信服务中心（SMSC）地址，使用Promise方式作为异步方法。

需要ohos.permission.SET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table1859188171115"></a>
    <table><thead align="left"><tr id="row9592801111"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p115948161111"><a name="p115948161111"></a><a name="p115948161111"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p1598881115"><a name="p1598881115"></a><a name="p1598881115"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p25948131119"><a name="p25948131119"></a><a name="p25948131119"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p55910812119"><a name="p55910812119"></a><a name="p55910812119"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row155911811114"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p105912821114"><a name="p105912821114"></a><a name="p105912821114"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p16014811114"><a name="p16014811114"></a><a name="p16014811114"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p96078111114"><a name="p96078111114"></a><a name="p96078111114"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p11572145614159"><a name="p11572145614159"></a><a name="p11572145614159"></a>SIM卡槽ID：</p>
    <a name="ul1357255618156"></a><a name="ul1357255618156"></a><ul id="ul1357255618156"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
    </td>
    </tr>
    <tr id="row66015813112"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p106014821119"><a name="p106014821119"></a><a name="p106014821119"></a>smscAddr</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p66088151118"><a name="p66088151118"></a><a name="p66088151118"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1860208141117"><a name="p1860208141117"></a><a name="p1860208141117"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p1760108101119"><a name="p1760108101119"></a><a name="p1760108101119"></a>短信服务中心地址。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table119691243144714"></a>
    <table><thead align="left"><tr id="row096954364719"><th class="cellrowborder" valign="top" width="26.69%" id="mcps1.1.3.1.1"><p id="p897019436475"><a name="p897019436475"></a><a name="p897019436475"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.31%" id="mcps1.1.3.1.2"><p id="p16970114344720"><a name="p16970114344720"></a><a name="p16970114344720"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16970443194710"><td class="cellrowborder" valign="top" width="26.69%" headers="mcps1.1.3.1.1 "><p id="p19970343174717"><a name="p19970343174717"></a><a name="p19970343174717"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.31%" headers="mcps1.1.3.1.2 "><p id="p169703434472"><a name="p169703434472"></a><a name="p169703434472"></a>以Promise形式异步返回设置结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let smscAddr = '+861xxxxxxxxxx';
    let promise = sms.setSmscAddr(slotId, smscAddr);
    promise.then(data => {
        console.log(`setSmscAddr success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`setSmscAddr fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sms.getSmscAddr<sup>7+</sup><a name="section347174613494"></a>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

获取短信服务中心（SMSC）地址，使用callback方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table1688918415185"></a>
    <table><thead align="left"><tr id="row108899481812"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p10889242180"><a name="p10889242180"></a><a name="p10889242180"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p13889142181"><a name="p13889142181"></a><a name="p13889142181"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p089019419181"><a name="p089019419181"></a><a name="p089019419181"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p48901943187"><a name="p48901943187"></a><a name="p48901943187"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1789084151812"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p16890124201811"><a name="p16890124201811"></a><a name="p16890124201811"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p138907411185"><a name="p138907411185"></a><a name="p138907411185"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p789064191816"><a name="p789064191816"></a><a name="p789064191816"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p1085441121615"><a name="p1085441121615"></a><a name="p1085441121615"></a>SIM卡槽ID：</p>
    <a name="ul285420116165"></a><a name="ul285420116165"></a><ul id="ul285420116165"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
    </td>
    </tr>
    <tr id="row18906441819"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p78915410183"><a name="p78915410183"></a><a name="p78915410183"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p1789116417184"><a name="p1789116417184"></a><a name="p1789116417184"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p108912047185"><a name="p108912047185"></a><a name="p108912047185"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p188916414188"><a name="p188916414188"></a><a name="p188916414188"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    sms.getSmscAddr(slotId, (err, data) => {
          console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.getSmscAddr<sup>7+</sup><a name="section1178428175016"></a>

getSmscAddr\(slotId: number\): Promise<string\>

获取短信服务中心（SMSC）地址，使用Promise方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table789120415189"></a>
    <table><thead align="left"><tr id="row18924416186"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p38921346181"><a name="p38921346181"></a><a name="p38921346181"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p78924412188"><a name="p78924412188"></a><a name="p78924412188"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p1789211412185"><a name="p1789211412185"></a><a name="p1789211412185"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p16892104181816"><a name="p16892104181816"></a><a name="p16892104181816"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1892643184"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p12892184171813"><a name="p12892184171813"></a><a name="p12892184171813"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p989215451810"><a name="p989215451810"></a><a name="p989215451810"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1889217491813"><a name="p1889217491813"></a><a name="p1889217491813"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p8956122311162"><a name="p8956122311162"></a><a name="p8956122311162"></a>SIM卡槽ID：</p>
    <a name="ul1495632314162"></a><a name="ul1495632314162"></a><ul id="ul1495632314162"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table989334161814"></a>
    <table><thead align="left"><tr id="row198934419185"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p1889312413181"><a name="p1889312413181"></a><a name="p1889312413181"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p1389316413180"><a name="p1389316413180"></a><a name="p1389316413180"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1789312451812"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p1893134121818"><a name="p1893134121818"></a><a name="p1893134121818"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p68944416186"><a name="p68944416186"></a><a name="p68944416186"></a>以Promise形式返回获取短信服务中心地址的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let promise = sms.getSmscAddr(slotId);
    promise.then(data => {
        console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`getSmscAddr fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## ShortMessage<a name="section345181318300"></a>

短信实例

<a name="table126934822015"></a>

<table><thead align="left"><tr id="row1369315832016"><th class="cellrowborder" valign="top" width="23.34%" id="mcps1.1.4.1.1"><p id="p1871313815402"><a name="p1871313815402"></a><a name="p1871313815402"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="19.06%" id="mcps1.1.4.1.2"><p id="p93231392263"><a name="p93231392263"></a><a name="p93231392263"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="57.599999999999994%" id="mcps1.1.4.1.3"><p id="p145500193814"><a name="p145500193814"></a><a name="p145500193814"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13344184392519"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p85256525218"><a name="p85256525218"></a><a name="p85256525218"></a>emailAddress</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p107115501923"><a name="p107115501923"></a><a name="p107115501923"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p202695241341"><a name="p202695241341"></a><a name="p202695241341"></a>电子邮件地址。</p>
</td>
</tr>
<tr id="row206942882013"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p773310541229"><a name="p773310541229"></a><a name="p773310541229"></a>emailMessageBody</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p181441457223"><a name="p181441457223"></a><a name="p181441457223"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p15573202884013"><a name="p15573202884013"></a><a name="p15573202884013"></a>电子邮件正文。</p>
</td>
</tr>
<tr id="row116945832019"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p12155162811211"><a name="p12155162811211"></a><a name="p12155162811211"></a>hasReplyPath</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p14794525926"><a name="p14794525926"></a><a name="p14794525926"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p13754174585919"><a name="p13754174585919"></a><a name="p13754174585919"></a>收到的短信是否包含“TP-Reply-Path”，默认为false。</p>
<a name="ul1470498307"></a><a name="ul1470498307"></a><ul id="ul1470498307"><li>“TP-Reply-Path”：移动电话根据发送SMS消息的短消息中心进行回复。</li></ul>
</td>
</tr>
<tr id="row253218315237"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p140111161132"><a name="p140111161132"></a><a name="p140111161132"></a>isEmailMessage</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p146951018131"><a name="p146951018131"></a><a name="p146951018131"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p887603743519"><a name="p887603743519"></a><a name="p887603743519"></a>收到的短信是否为电子邮件。</p>
</td>
</tr>
<tr id="row859720172311"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p166361920323"><a name="p166361920323"></a><a name="p166361920323"></a>isReplaceMessage</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p01812236216"><a name="p01812236216"></a><a name="p01812236216"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p022761413014"><a name="p022761413014"></a><a name="p022761413014"></a>收到的短信是否为“替换短信”，默认为false。</p>
<a name="ul42891226707"></a><a name="ul42891226707"></a><ul id="ul42891226707"><li>“替换短信”有关详细信息，参见 “3GPP TS 23.040 9.2.3.9”。</li></ul>
</td>
</tr>
<tr id="row764111193410"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p1410313450214"><a name="p1410313450214"></a><a name="p1410313450214"></a>isSmsStatusReportMessage</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p1644311475213"><a name="p1644311475213"></a><a name="p1644311475213"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p5701488344"><a name="p5701488344"></a><a name="p5701488344"></a>当前消息是否为“短信状态报告”，默认为false。</p>
<a name="ul14539561111"></a><a name="ul14539561111"></a><ul id="ul14539561111"><li>“短信状态报告”是一种特定格式的短信，被用来从Service Center到Mobile Station传送状态报告。</li></ul>
</td>
</tr>
<tr id="row109475100345"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p19837318220"><a name="p19837318220"></a><a name="p19837318220"></a>messageClass</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p161336593118"><a name="p161336593118"></a><a name="p161336593118"></a><a href="#section141712166453">ShortMessageClass</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p55610014386"><a name="p55610014386"></a><a name="p55610014386"></a>短信类型。</p>
</td>
</tr>
<tr id="row13623612346"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p5114831626"><a name="p5114831626"></a><a name="p5114831626"></a>pdu</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p17402133611219"><a name="p17402133611219"></a><a name="p17402133611219"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p177241026133411"><a name="p177241026133411"></a><a name="p177241026133411"></a>SMS消息中的协议数据单元 （PDU）。</p>
</td>
</tr>
<tr id="row498012918341"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p4552841928"><a name="p4552841928"></a><a name="p4552841928"></a>protocolId</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p11390871024"><a name="p11390871024"></a><a name="p11390871024"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p16572083814"><a name="p16572083814"></a><a name="p16572083814"></a>发送短信时使用的协议标识。</p>
</td>
</tr>
<tr id="row87231262349"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p32951810223"><a name="p32951810223"></a><a name="p32951810223"></a>scAddress</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p4631111219219"><a name="p4631111219219"></a><a name="p4631111219219"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p136431815349"><a name="p136431815349"></a><a name="p136431815349"></a>短消息服务中心（SMSC）地址。</p>
</td>
</tr>
<tr id="row1294964403418"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p1253815422"><a name="p1253815422"></a><a name="p1253815422"></a>scTimestamp</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p1498814171127"><a name="p1498814171127"></a><a name="p1498814171127"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p294716100345"><a name="p294716100345"></a><a name="p294716100345"></a>SMSC时间戳。</p>
</td>
</tr>
<tr id="row169548183414"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p16266133910216"><a name="p16266133910216"></a><a name="p16266133910216"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p1955441329"><a name="p1955441329"></a><a name="p1955441329"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p59491344113419"><a name="p59491344113419"></a><a name="p59491344113419"></a>SMS-STATUS-REPORT消息中的短信状态指示短信服务中心（SMSC）发送的短信状态。</p>
</td>
</tr>
<tr id="row1526817245344"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p156631801631"><a name="p156631801631"></a><a name="p156631801631"></a>userRawData</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p861981315311"><a name="p861981315311"></a><a name="p861981315311"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p8487922358"><a name="p8487922358"></a><a name="p8487922358"></a>除数据头外的用户数据。</p>
</td>
</tr>
<tr id="row183801940133512"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p396619450120"><a name="p396619450120"></a><a name="p396619450120"></a>visibleMessageBody</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p819218501110"><a name="p819218501110"></a><a name="p819218501110"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p85619013384"><a name="p85619013384"></a><a name="p85619013384"></a>短信正文。</p>
</td>
</tr>
<tr id="row98751137153511"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p12309536110"><a name="p12309536110"></a><a name="p12309536110"></a>visibleRawAddress</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p559135510111"><a name="p559135510111"></a><a name="p559135510111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p55617011389"><a name="p55617011389"></a><a name="p55617011389"></a>发送者地址。</p>
</td>
</tr>
</tbody>
</table>

## ShortMessageClass<a name="section141712166453"></a>

短信类型。

<a name="table12281144104511"></a>
<table><thead align="left"><tr id="row10281144124514"><th class="cellrowborder" valign="top" width="23.34%" id="mcps1.1.4.1.1"><p id="p128194419456"><a name="p128194419456"></a><a name="p128194419456"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="19.06%" id="mcps1.1.4.1.2"><p id="p1528204484519"><a name="p1528204484519"></a><a name="p1528204484519"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="57.599999999999994%" id="mcps1.1.4.1.3"><p id="p82824447459"><a name="p82824447459"></a><a name="p82824447459"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row12821744124513"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p1366413819465"><a name="p1366413819465"></a><a name="p1366413819465"></a>UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p182826444455"><a name="p182826444455"></a><a name="p182826444455"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p4282244154515"><a name="p4282244154515"></a><a name="p4282244154515"></a>未知类型。</p>
</td>
</tr>
<tr id="row1828218449455"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p20401438488"><a name="p20401438488"></a><a name="p20401438488"></a>INSTANT_MESSAGE</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p9282184418454"><a name="p9282184418454"></a><a name="p9282184418454"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p1728234434513"><a name="p1728234434513"></a><a name="p1728234434513"></a>即时消息，收到后立即显示。</p>
</td>
</tr>
<tr id="row1528364416454"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p17720456485"><a name="p17720456485"></a><a name="p17720456485"></a>OPTIONAL_MESSAGE</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p928314454518"><a name="p928314454518"></a><a name="p928314454518"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p1428354414451"><a name="p1428354414451"></a><a name="p1428354414451"></a>存储在设备或SIM卡上的短信。</p>
</td>
</tr>
<tr id="row676864804613"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p1724510489488"><a name="p1724510489488"></a><a name="p1724510489488"></a>SIM_MESSAGE</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p1176924824615"><a name="p1176924824615"></a><a name="p1176924824615"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p157698488462"><a name="p157698488462"></a><a name="p157698488462"></a>包含SIM卡信息的短信，需要存储在SIM卡中。</p>
</td>
</tr>
<tr id="row17327345184610"><td class="cellrowborder" valign="top" width="23.34%" headers="mcps1.1.4.1.1 "><p id="p17950155010481"><a name="p17950155010481"></a><a name="p17950155010481"></a>FORWARD_MESSAGE</p>
</td>
<td class="cellrowborder" valign="top" width="19.06%" headers="mcps1.1.4.1.2 "><p id="p6328134594614"><a name="p6328134594614"></a><a name="p6328134594614"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p183286452464"><a name="p183286452464"></a><a name="p183286452464"></a>要转发到另一台设备的短信。</p>
</td>
</tr>
</tbody>
</table>

## SendMessageOptions<a name="section12262183471518"></a>

发送短信的参数和回调。

根据SendMessageOptions中的可选参数content的值判断短信类型。

<a name="table426533441512"></a>
<table><thead align="left"><tr id="row1626518342159"><th class="cellrowborder" valign="top" width="18.69%" id="mcps1.1.5.1.1"><p id="p178726479354"><a name="p178726479354"></a><a name="p178726479354"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="22.07%" id="mcps1.1.5.1.2"><p id="p1426519342153"><a name="p1426519342153"></a><a name="p1426519342153"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.88%" id="mcps1.1.5.1.3"><p id="p17265143471517"><a name="p17265143471517"></a><a name="p17265143471517"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.35999999999999%" id="mcps1.1.5.1.4"><p id="p1126583411512"><a name="p1126583411512"></a><a name="p1126583411512"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row126610344150"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p414313350720"><a name="p414313350720"></a><a name="p414313350720"></a>slotId</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p19298134416718"><a name="p19298134416718"></a><a name="p19298134416718"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p17266183451512"><a name="p17266183451512"></a><a name="p17266183451512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p1563734381412"><a name="p1563734381412"></a><a name="p1563734381412"></a>用于发送短信的SIM卡槽ID：</p>
<a name="ul1226144151514"></a><a name="ul1226144151514"></a><ul id="ul1226144151514"><li>0：卡槽1</li><li>1：卡槽2</li></ul>
</td>
</tr>
<tr id="row11791572064"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p11588175111715"><a name="p11588175111715"></a><a name="p11588175111715"></a>destinationHost</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p52991257274"><a name="p52991257274"></a><a name="p52991257274"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p181791171161"><a name="p181791171161"></a><a name="p181791171161"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p2017987066"><a name="p2017987066"></a><a name="p2017987066"></a>短信的发送地址。</p>
</td>
</tr>
<tr id="row16360111493118"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p76811119810"><a name="p76811119810"></a><a name="p76811119810"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p153513192820"><a name="p153513192820"></a><a name="p153513192820"></a>string | Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p482451216615"><a name="p482451216615"></a><a name="p482451216615"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p15340948132416"><a name="p15340948132416"></a><a name="p15340948132416"></a>如果内容是字符串，则这是一条文本短信。</p>
<p id="p12824111212619"><a name="p12824111212619"></a><a name="p12824111212619"></a>如果内容是字节数组，则这是一条数据短信。</p>
</td>
</tr>
<tr id="row17902109267"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p1441441820"><a name="p1441441820"></a><a name="p1441441820"></a>serviceCenter</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p1755119718816"><a name="p1755119718816"></a><a name="p1755119718816"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p990279068"><a name="p990279068"></a><a name="p990279068"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p1890229663"><a name="p1890229663"></a><a name="p1890229663"></a>短信中心地址。默认使用SIM卡中的短信中心地址。</p>
</td>
</tr>
<tr id="row12412215961"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p750262516813"><a name="p750262516813"></a><a name="p750262516813"></a>destinationPort</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p1727917299816"><a name="p1727917299816"></a><a name="p1727917299816"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p10412111519610"><a name="p10412111519610"></a><a name="p10412111519610"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p1541319151266"><a name="p1541319151266"></a><a name="p1541319151266"></a>如果发送数据消息，destinationPort 是必需的。否则是可选的。</p>
</td>
</tr>
<tr id="row169402191669"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p82028327818"><a name="p82028327818"></a><a name="p82028327818"></a>sendCallback</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p835213618913"><a name="p835213618913"></a><a name="p835213618913"></a>AsyncCallback</p>
<p id="p449664817810"><a name="p449664817810"></a><a name="p449664817810"></a>&lt;<a href="#section16646146115317">ISendShortMessageCallback</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p1940131914612"><a name="p1940131914612"></a><a name="p1940131914612"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p9940151920617"><a name="p9940151920617"></a><a name="p9940151920617"></a>短信发送结果回调，返回短信发送的结果，参考<a href="#section16646146115317">ISendShortMessageCallback</a>。</p>
</td>
</tr>
<tr id="row196683176615"><td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.1.5.1.1 "><p id="p1764495320816"><a name="p1764495320816"></a><a name="p1764495320816"></a>deliveryCallback</p>
</td>
<td class="cellrowborder" valign="top" width="22.07%" headers="mcps1.1.5.1.2 "><p id="p3892339195"><a name="p3892339195"></a><a name="p3892339195"></a>AsyncCallback</p>
<p id="p8149858286"><a name="p8149858286"></a><a name="p8149858286"></a>&lt;<a href="#section12183749531">IDeliveryShortMessageCallback</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.88%" headers="mcps1.1.5.1.3 "><p id="p176695171565"><a name="p176695171565"></a><a name="p176695171565"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.5.1.4 "><p id="p3669151714610"><a name="p3669151714610"></a><a name="p3669151714610"></a>短信送达结果回调，返回短信递送报告，参考<a href="#section12183749531">IDeliveryShortMessageCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

## ISendShortMessageCallback<a name="section16646146115317"></a>

回调实例。返回短信发送结果、存储已发送短信的URI和是否为长短信的最后一部分。

<a name="table1964615620539"></a>
<table><thead align="left"><tr id="row964614675318"><th class="cellrowborder" valign="top" width="11.940000000000001%" id="mcps1.1.5.1.1"><p id="p1964613635311"><a name="p1964613635311"></a><a name="p1964613635311"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="23.27%" id="mcps1.1.5.1.2"><p id="p16646136115317"><a name="p16646136115317"></a><a name="p16646136115317"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.8100000000000005%" id="mcps1.1.5.1.3"><p id="p76461662532"><a name="p76461662532"></a><a name="p76461662532"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="56.98%" id="mcps1.1.5.1.4"><p id="p1664611620539"><a name="p1664611620539"></a><a name="p1664611620539"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row71461356335"><td class="cellrowborder" valign="top" width="11.940000000000001%" headers="mcps1.1.5.1.1 "><p id="p6680712195510"><a name="p6680712195510"></a><a name="p6680712195510"></a>isLastPart</p>
</td>
<td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.1.5.1.2 "><p id="p10985814205514"><a name="p10985814205514"></a><a name="p10985814205514"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="p19647176105316"><a name="p19647176105316"></a><a name="p19647176105316"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="56.98%" headers="mcps1.1.5.1.4 "><p id="p391010266511"><a name="p391010266511"></a><a name="p391010266511"></a>指定这是否是长短信的最后一部分。true表示这是长短信的最后一部分，false表示不是。默认为false。</p>
</td>
</tr>
<tr id="row66462665318"><td class="cellrowborder" valign="top" width="11.940000000000001%" headers="mcps1.1.5.1.1 "><p id="p12719120115514"><a name="p12719120115514"></a><a name="p12719120115514"></a>result</p>
</td>
<td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.1.5.1.2 "><p id="p118240345516"><a name="p118240345516"></a><a name="p118240345516"></a><a href="#section13290132311575">SendSmsResult</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="p8647465537"><a name="p8647465537"></a><a name="p8647465537"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.98%" headers="mcps1.1.5.1.4 "><p id="p364756125310"><a name="p364756125310"></a><a name="p364756125310"></a>短信发送结果。</p>
</td>
</tr>
<tr id="row86473614538"><td class="cellrowborder" valign="top" width="11.940000000000001%" headers="mcps1.1.5.1.1 "><p id="p01183720558"><a name="p01183720558"></a><a name="p01183720558"></a>url</p>
</td>
<td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.1.5.1.2 "><p id="p1994379185512"><a name="p1994379185512"></a><a name="p1994379185512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="p116472685320"><a name="p116472685320"></a><a name="p116472685320"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.98%" headers="mcps1.1.5.1.4 "><p id="p176471666538"><a name="p176471666538"></a><a name="p176471666538"></a>存储发送短信的URI。</p>
</td>
</tr>
</tbody>
</table>

## IDeliveryShortMessageCallback<a name="section12183749531"></a>

回调实例。返回短信送达报告。

<a name="table218311405312"></a>
<table><thead align="left"><tr id="row1618314495318"><th class="cellrowborder" valign="top" width="11.940000000000001%" id="mcps1.1.5.1.1"><p id="p17183849534"><a name="p17183849534"></a><a name="p17183849534"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="23.27%" id="mcps1.1.5.1.2"><p id="p2184945531"><a name="p2184945531"></a><a name="p2184945531"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.8100000000000005%" id="mcps1.1.5.1.3"><p id="p41841749538"><a name="p41841749538"></a><a name="p41841749538"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="56.98%" id="mcps1.1.5.1.4"><p id="p131841745531"><a name="p131841745531"></a><a name="p131841745531"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row17184446536"><td class="cellrowborder" valign="top" width="11.940000000000001%" headers="mcps1.1.5.1.1 "><p id="p13636519105610"><a name="p13636519105610"></a><a name="p13636519105610"></a>pdu</p>
</td>
<td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.1.5.1.2 "><p id="p1762201610565"><a name="p1762201610565"></a><a name="p1762201610565"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="p018415405317"><a name="p018415405317"></a><a name="p018415405317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.98%" headers="mcps1.1.5.1.4 "><p id="p18584153316316"><a name="p18584153316316"></a><a name="p18584153316316"></a>短信送达报告。</p>
</td>
</tr>
</tbody>
</table>

## SendSmsResult<a name="section13290132311575"></a>

短信发送结果。

<a name="table102901123175720"></a>
<table><thead align="left"><tr id="row13290023145720"><th class="cellrowborder" valign="top" width="43.47%" id="mcps1.1.4.1.1"><p id="p629042314578"><a name="p629042314578"></a><a name="p629042314578"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="9.51%" id="mcps1.1.4.1.2"><p id="p16291323135715"><a name="p16291323135715"></a><a name="p16291323135715"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="47.02%" id="mcps1.1.4.1.3"><p id="p62916234577"><a name="p62916234577"></a><a name="p62916234577"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row12911223125718"><td class="cellrowborder" valign="top" width="43.47%" headers="mcps1.1.4.1.1 "><p id="p59203610580"><a name="p59203610580"></a><a name="p59203610580"></a>SEND_SMS_SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="9.51%" headers="mcps1.1.4.1.2 "><p id="p1529172310579"><a name="p1529172310579"></a><a name="p1529172310579"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="47.02%" headers="mcps1.1.4.1.3 "><p id="p1329122335715"><a name="p1329122335715"></a><a name="p1329122335715"></a>发送短信成功。</p>
</td>
</tr>
<tr id="row458123655717"><td class="cellrowborder" valign="top" width="43.47%" headers="mcps1.1.4.1.1 "><p id="p478263820580"><a name="p478263820580"></a><a name="p478263820580"></a>SEND_SMS_FAILURE_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="9.51%" headers="mcps1.1.4.1.2 "><p id="p458223645713"><a name="p458223645713"></a><a name="p458223645713"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="47.02%" headers="mcps1.1.4.1.3 "><p id="p558253614573"><a name="p558253614573"></a><a name="p558253614573"></a>发送短信失败，原因未知。</p>
</td>
</tr>
<tr id="row2045810344577"><td class="cellrowborder" valign="top" width="43.47%" headers="mcps1.1.4.1.1 "><p id="p13459184185812"><a name="p13459184185812"></a><a name="p13459184185812"></a>SEND_SMS_FAILURE_RADIO_OFF</p>
</td>
<td class="cellrowborder" valign="top" width="9.51%" headers="mcps1.1.4.1.2 "><p id="p164591834155714"><a name="p164591834155714"></a><a name="p164591834155714"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="47.02%" headers="mcps1.1.4.1.3 "><p id="p4459734125717"><a name="p4459734125717"></a><a name="p4459734125717"></a>发送短信失败，原因为调制解调器关机。</p>
</td>
</tr>
<tr id="row0114132105714"><td class="cellrowborder" valign="top" width="43.47%" headers="mcps1.1.4.1.1 "><p id="p1586519435581"><a name="p1586519435581"></a><a name="p1586519435581"></a>SEND_SMS_FAILURE_SERVICE_UNAVAILABLE</p>
</td>
<td class="cellrowborder" valign="top" width="9.51%" headers="mcps1.1.4.1.2 "><p id="p1111493218571"><a name="p1111493218571"></a><a name="p1111493218571"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="47.02%" headers="mcps1.1.4.1.3 "><p id="p159271549104318"><a name="p159271549104318"></a><a name="p159271549104318"></a>发送短信失败，原因为网络不可用、不支持发送或接收短信。</p>
</td>
</tr>
</tbody>
</table>
