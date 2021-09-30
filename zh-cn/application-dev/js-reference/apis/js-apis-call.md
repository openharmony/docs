# 拨打电话<a name="ZH-CN_TOPIC_0000001148697292"></a>

-   [导入模块](#section111401036143)
-   [call.dial](#section1961259194312)
-   [call.dial](#section387281814438)
-   [call.dial](#section37173354913)
-   [call.hasCall](#section19558123217015)
-   [call.hasCall](#section12874319303)
-   [call.getCallState](#section5882223124910)
-   [call.getCallState](#section198597561794)
-   [call.isEmergencyPhoneNumber7+](#section8560112174319)
-   [call.isEmergencyPhoneNumber7+](#section9565131204319)
-   [call.isEmergencyPhoneNumber7+](#section5569131234312)
-   [call.formatPhoneNumber7+](#section1532018310579)
-   [call.formatPhoneNumber7+](#section1832553165720)
-   [call.formatPhoneNumber7+](#section1933033195716)
-   [call.formatPhoneNumberToE1647+](#section10285180112418)
-   [call.formatPhoneNumberToE1647+](#section142931509247)
-   [DialOptions](#section12262183471518)
-   [CallState](#section345181318300)
-   [EmergencyNumberOptions7+](#section03689893518)
-   [NumberFormatOptions7+](#section23348305716)

>**说明：** 
>
>标记7+的表示从API Version 7开始支持，未标记的表示从API Version 6开始支持。


## 导入模块<a name="section111401036143"></a>

```
import call from '@ohos.telephony.call';
```

## call.dial<a name="section1961259194312"></a>

dial\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

拨打电话，使用callback方式作为异步方法。

需要权限：ohos.permission.PLACE\_CALL权限，该权限为系统权限。

-   参数

    <a name="table37717572535"></a>
    <table><thead align="left"><tr id="row97755715537"><th class="cellrowborder" valign="top" width="19.009999999999998%" id="mcps1.1.5.1.1"><p id="p37714572534"><a name="p37714572534"></a><a name="p37714572534"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.939999999999998%" id="mcps1.1.5.1.2"><p id="p277105735313"><a name="p277105735313"></a><a name="p277105735313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.459999999999999%" id="mcps1.1.5.1.3"><p id="p377195716532"><a name="p377195716532"></a><a name="p377195716532"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.589999999999996%" id="mcps1.1.5.1.4"><p id="p878957125311"><a name="p878957125311"></a><a name="p878957125311"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row117810571533"><td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.1 "><p id="p1778145716538"><a name="p1778145716538"></a><a name="p1778145716538"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.939999999999998%" headers="mcps1.1.5.1.2 "><p id="p1978165711532"><a name="p1978165711532"></a><a name="p1978165711532"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p207815717533"><a name="p207815717533"></a><a name="p207815717533"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p11781757155320"><a name="p11781757155320"></a><a name="p11781757155320"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row185881325515"><td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.1 "><p id="p35931313554"><a name="p35931313554"></a><a name="p35931313554"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.939999999999998%" headers="mcps1.1.5.1.2 "><p id="p75971305516"><a name="p75971305516"></a><a name="p75971305516"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p125951305519"><a name="p125951305519"></a><a name="p125951305519"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p1276320184611"><a name="p1276320184611"></a><a name="p1276320184611"></a>回调函数：</p>
    <a name="ul1468142292116"></a><a name="ul1468142292116"></a><ul id="ul1468142292116"><li>true：成功。</li><li>false：失败。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.dial("138xxxxxxxx", (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.dial<a name="section387281814438"></a>

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean\>\): void

拨打电话，可设置通话参数，使用callback方式作为异步方法。

需要权限：ohos.permission.PLACE\_CALL权限，该权限为系统权限。

-   参数

    <a name="table11872418104316"></a>
    <table><thead align="left"><tr id="row13873518134320"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p1873111820437"><a name="p1873111820437"></a><a name="p1873111820437"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p687301844313"><a name="p687301844313"></a><a name="p687301844313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p19873318114314"><a name="p19873318114314"></a><a name="p19873318114314"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p1087316184438"><a name="p1087316184438"></a><a name="p1087316184438"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1587321816434"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p13873218194315"><a name="p13873218194315"></a><a name="p13873218194315"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p11873818114315"><a name="p11873818114315"></a><a name="p11873818114315"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p14873018194316"><a name="p14873018194316"></a><a name="p14873018194316"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p19874418104310"><a name="p19874418104310"></a><a name="p19874418104310"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row1268000144419"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p46801407448"><a name="p46801407448"></a><a name="p46801407448"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p206811503445"><a name="p206811503445"></a><a name="p206811503445"></a>DialOptions</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1468111016441"><a name="p1468111016441"></a><a name="p1468111016441"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p8681200174415"><a name="p8681200174415"></a><a name="p8681200174415"></a>通话参数，参考<a href="#section12262183471518">DialOptions</a>。</p>
    </td>
    </tr>
    <tr id="row0874181814310"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p88742018194313"><a name="p88742018194313"></a><a name="p88742018194313"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p15874718174310"><a name="p15874718174310"></a><a name="p15874718174310"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p11874151814438"><a name="p11874151814438"></a><a name="p11874151814438"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p2051315401127"><a name="p2051315401127"></a><a name="p2051315401127"></a>回调函数：</p>
    <a name="ul7523151914208"></a><a name="ul7523151914208"></a><ul id="ul7523151914208"><li>true：成功。</li><li>false：失败。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.dial("138xxxxxxxx", {
        extras: false
    }, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.dial<a name="section37173354913"></a>

dial\(phoneNumber: string, options?: DialOptions\): Promise<boolean\>

拨打电话，可设置通话参数，使用promise方式作为异步方法。

需要权限：ohos.permission.PLACE\_CALL权限，该权限为系统权限。

- 参数

  <a name="table1170025144917"></a>

  <table><thead align="left"><tr id="row14171425124919"><th class="cellrowborder" valign="top" width="19.259999999999998%" id="mcps1.1.5.1.1"><p id="p1617102513494"><a name="p1617102513494"></a><a name="p1617102513494"></a>参数名</p>
  </th>
  <th class="cellrowborder" valign="top" width="20.599999999999998%" id="mcps1.1.5.1.2"><p id="p181711025174911"><a name="p181711025174911"></a><a name="p181711025174911"></a>类型</p>
  </th>
  <th class="cellrowborder" valign="top" width="12.35%" id="mcps1.1.5.1.3"><p id="p61711625174917"><a name="p61711625174917"></a><a name="p61711625174917"></a>必填</p>
  </th>
  <th class="cellrowborder" valign="top" width="47.79%" id="mcps1.1.5.1.4"><p id="p181715257498"><a name="p181715257498"></a><a name="p181715257498"></a>说明</p>
  </th>
  </tr>
  </thead>
  <tbody><tr id="row18171162511494"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p617113255493"><a name="p617113255493"></a><a name="p617113255493"></a>phoneNumber</p>
  </td>
  <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p1817102504916"><a name="p1817102504916"></a><a name="p1817102504916"></a>string</p>
  </td>
  <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p3171162554917"><a name="p3171162554917"></a><a name="p3171162554917"></a>是</p>
  </td>
  <td class="cellrowborder" valign="top" width="47.79%" headers="mcps1.1.5.1.4 "><p id="p13171132514919"><a name="p13171132514919"></a><a name="p13171132514919"></a>电话号码。</p>
  </td>
  </tr>
  <tr id="row1717292510494"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p7172925154911"><a name="p7172925154911"></a><a name="p7172925154911"></a>options</p>
  </td>
  <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p5552285116"><a name="p5552285116"></a><a name="p5552285116"></a>DialOptions</p>
  </td>
  <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p131725254492"><a name="p131725254492"></a><a name="p131725254492"></a>否</p>
  </td>
  <td class="cellrowborder" valign="top" width="47.79%" headers="mcps1.1.5.1.4 "><p id="p15172625154920"><a name="p15172625154920"></a><a name="p15172625154920"></a>通话参数，参考<a href="#section12262183471518">DialOptions</a>。</p>
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
    <tbody><tr id="row2184132316110"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p1218415231011"><a name="p1218415231011"></a><a name="p1218415231011"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p1218411231411"><a name="p1218411231411"></a><a name="p1218411231411"></a>以Promise形式返回拨打电话的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.dial("138xxxxxxxx", {
        extras: false
    });
    promise.then(data => {
        console.log(`dial success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`dial fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## call.hasCall<a name="section19558123217015"></a>

hasCall\(callback: AsyncCallback<boolean\>\): void

判断是否存在通话，使用callback方式作为异步方法。

-   参数

    <a name="table82297481245"></a>
    <table><thead align="left"><tr id="row1023013489414"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p122303481944"><a name="p122303481944"></a><a name="p122303481944"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p823018480414"><a name="p823018480414"></a><a name="p823018480414"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p723013484415"><a name="p723013484415"></a><a name="p723013484415"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p92305481844"><a name="p92305481844"></a><a name="p92305481844"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row72317481449"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p723154815414"><a name="p723154815414"></a><a name="p723154815414"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p02317481547"><a name="p02317481547"></a><a name="p02317481547"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p82311648043"><a name="p82311648043"></a><a name="p82311648043"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p16933172513276"><a name="p16933172513276"></a><a name="p16933172513276"></a>回调函数：</p>
    <a name="ul8778181216283"></a><a name="ul8778181216283"></a><ul id="ul8778181216283"><li>true：当前存在通话。</li><li>false：当前不存在通话。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.hasCall((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.hasCall<a name="section12874319303"></a>

hasCall\(\): Promise<boolean\>

判断是否存在通话，使用Promise方式作为异步方法。

-   返回值

    <a name="table1123111015394"></a>
    <table><thead align="left"><tr id="row0231309398"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p162311609398"><a name="p162311609398"></a><a name="p162311609398"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p923118010397"><a name="p923118010397"></a><a name="p923118010397"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row82319033919"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p223130143914"><a name="p223130143914"></a><a name="p223130143914"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p15231809396"><a name="p15231809396"></a><a name="p15231809396"></a>以Promise形式异步返回判断是否存在通话。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.hasCall();
    promise.then(data => {
        console.log(`hasCall success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`hasCall fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## call.getCallState<a name="section5882223124910"></a>

getCallState\(callback: AsyncCallback<CallState\>\): void

获取通话状态，使用callback方式作为异步方法。

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
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p2401103617217"><a name="p2401103617217"></a><a name="p2401103617217"></a>AsyncCallback&lt;<a href="#section345181318300">CallState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p4401036423"><a name="p4401036423"></a><a name="p4401036423"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p440103618212"><a name="p440103618212"></a><a name="p440103618212"></a>回调函数，异步返回获取到的通话状态。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.getCallState((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.getCallState<a name="section198597561794"></a>

getCallState\(\): Promise<CallState\>

获取通话状态，使用Promise方式作为异步方法。

-   返回值

    <a name="table58590561095"></a>
    <table><thead align="left"><tr id="row118591561193"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p7859056599"><a name="p7859056599"></a><a name="p7859056599"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p085913569919"><a name="p085913569919"></a><a name="p085913569919"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row28591856299"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p28631116886"><a name="p28631116886"></a><a name="p28631116886"></a>Promise&lt;<a href="#section345181318300">CallState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p1785920561591"><a name="p1785920561591"></a><a name="p1785920561591"></a>以Promise形式异步返回获取通话状态的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.getCallState();
    promise.then(data => {
        console.log(`getCallState success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`getCallState fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## call.isEmergencyPhoneNumber<sup>7+</sup><a name="section8560112174319"></a>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

判断是否是紧急电话号码，使用callback方式作为异步方法。

-   参数

    <a name="table3561612104315"></a>
    <table><thead align="left"><tr id="row1856113129437"><th class="cellrowborder" valign="top" width="18.399148277197057%" id="mcps1.1.5.1.1"><p id="p756191234312"><a name="p756191234312"></a><a name="p756191234312"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.010065814943864%" id="mcps1.1.5.1.2"><p id="p105611512184318"><a name="p105611512184318"></a><a name="p105611512184318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.775067750677508%" id="mcps1.1.5.1.3"><p id="p556131217439"><a name="p556131217439"></a><a name="p556131217439"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.81571815718158%" id="mcps1.1.5.1.4"><p id="p14561111294319"><a name="p14561111294319"></a><a name="p14561111294319"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row205611412144315"><td class="cellrowborder" valign="top" width="18.399148277197057%" headers="mcps1.1.5.1.1 "><p id="p18562912194314"><a name="p18562912194314"></a><a name="p18562912194314"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.010065814943864%" headers="mcps1.1.5.1.2 "><p id="p16562131284317"><a name="p16562131284317"></a><a name="p16562131284317"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.775067750677508%" headers="mcps1.1.5.1.3 "><p id="p125621123439"><a name="p125621123439"></a><a name="p125621123439"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.81571815718158%" headers="mcps1.1.5.1.4 "><p id="p1956231274315"><a name="p1956231274315"></a><a name="p1956231274315"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row75623121435"><td class="cellrowborder" valign="top" width="18.399148277197057%" headers="mcps1.1.5.1.1 "><p id="p185621812124310"><a name="p185621812124310"></a><a name="p185621812124310"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.010065814943864%" headers="mcps1.1.5.1.2 "><p id="p2056281215434"><a name="p2056281215434"></a><a name="p2056281215434"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.775067750677508%" headers="mcps1.1.5.1.3 "><p id="p7562112144311"><a name="p7562112144311"></a><a name="p7562112144311"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.81571815718158%" headers="mcps1.1.5.1.4 "><p id="p14704625153512"><a name="p14704625153512"></a><a name="p14704625153512"></a>回调函数，返回判断是否是紧急电话号码的结果：</p>
    <a name="ul148351751154917"></a><a name="ul148351751154917"></a><ul id="ul148351751154917"><li>true：是紧急电话号码。</li><li>false：不是紧急电话号码。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.isEmergencyPhoneNumber("138xxxxxxxx", (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.isEmergencyPhoneNumber<sup>7+</sup><a name="section9565131204319"></a>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback<boolean\>\): void

判断是否是紧急电话号码，使用callback方式作为异步方法。

- 参数

    <a name="table356561244318"></a>

    <table><thead align="left"><tr id="row6565101294319"><th class="cellrowborder" valign="top" width="17.65%" id="mcps1.1.5.1.1"><p id="p1956541212432"><a name="p1956541212432"></a><a name="p1956541212432"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.189999999999998%" id="mcps1.1.5.1.2"><p id="p25651124437"><a name="p25651124437"></a><a name="p25651124437"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p1956531210439"><a name="p1956531210439"></a><a name="p1956531210439"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p1456531218431"><a name="p1456531218431"></a><a name="p1456531218431"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1656581284313"><td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.5.1.1 "><p id="p8565141264311"><a name="p8565141264311"></a><a name="p8565141264311"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.189999999999998%" headers="mcps1.1.5.1.2 "><p id="p856521210433"><a name="p856521210433"></a><a name="p856521210433"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p05661012194319"><a name="p05661012194319"></a><a name="p05661012194319"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p756631218431"><a name="p756631218431"></a><a name="p756631218431"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row185660125434"><td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.5.1.1 "><p id="p1756620123431"><a name="p1756620123431"></a><a name="p1756620123431"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.189999999999998%" headers="mcps1.1.5.1.2 "><p id="p185661712164316"><a name="p185661712164316"></a><a name="p185661712164316"></a>EmergencyNumberOptions</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p95660122437"><a name="p95660122437"></a><a name="p95660122437"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p15566131219439"><a name="p15566131219439"></a><a name="p15566131219439"></a>手机参数，参考<a href="#section03689893518">EmergencyNumberOptions</a>。</p>
    </td>
    </tr>
    <tr id="row1556601211432"><td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.5.1.1 "><p id="p35663128439"><a name="p35663128439"></a><a name="p35663128439"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.189999999999998%" headers="mcps1.1.5.1.2 "><p id="p16566151212434"><a name="p16566151212434"></a><a name="p16566151212434"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1856618121435"><a name="p1856618121435"></a><a name="p1856618121435"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p66331949173811"><a name="p66331949173811"></a><a name="p66331949173811"></a>回调函数，返回判断是否是紧急电话号码的结果：</p>
    <a name="ul131711033508"></a><a name="ul131711033508"></a><ul id="ul131711033508"><li>true：是紧急电话号码。</li><li>false：不是紧急电话号码。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, value) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.isEmergencyPhoneNumber<sup>7+</sup><a name="section5569131234312"></a>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise<boolean\>

判断是否是紧急电话号码，使用promise方式作为异步方法。

- 参数

  <a name="table456911211435"></a>

  <table><thead align="left"><tr id="row10569171214431"><th class="cellrowborder" valign="top" width="19.259999999999998%" id="mcps1.1.5.1.1"><p id="p7569112164319"><a name="p7569112164319"></a><a name="p7569112164319"></a>参数名</p>
  </th>
  <th class="cellrowborder" valign="top" width="20.599999999999998%" id="mcps1.1.5.1.2"><p id="p257010121433"><a name="p257010121433"></a><a name="p257010121433"></a>类型</p>
  </th>
  <th class="cellrowborder" valign="top" width="12.35%" id="mcps1.1.5.1.3"><p id="p557061274313"><a name="p557061274313"></a><a name="p557061274313"></a>必填</p>
  </th>
  <th class="cellrowborder" valign="top" width="47.79%" id="mcps1.1.5.1.4"><p id="p10570181254320"><a name="p10570181254320"></a><a name="p10570181254320"></a>说明</p>
  </th>
  </tr>
  </thead>
  <tbody><tr id="row1656581284313"><td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.5.1.1 "><p id="p8565141264311"><a name="p8565141264311"></a><a name="p8565141264311"></a>phoneNumber</p>
  </td>
  <td class="cellrowborder" valign="top" width="28.189999999999998%" headers="mcps1.1.5.1.2 "><p id="p856521210433"><a name="p856521210433"></a><a name="p856521210433"></a>string</p>
  </td>
  <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p05661012194319"><a name="p05661012194319"></a><a name="p05661012194319"></a>是</p>
  </td>
  <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p756631218431"><a name="p756631218431"></a><a name="p756631218431"></a>电话号码。</p>
  </td>
  </tr>
  <tr id="row1571151274314"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p15571512134310"><a name="p15571512134310"></a><a name="p15571512134310"></a>options</p>
  </td>
  <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p165712012204313"><a name="p165712012204313"></a><a name="p165712012204313"></a>EmergencyNumberOptions</p>
  </td>
  <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p1457151211438"><a name="p1457151211438"></a><a name="p1457151211438"></a>否</p>
  </td>
  <td class="cellrowborder" valign="top" width="47.79%" headers="mcps1.1.5.1.4 "><p id="p6571111219434"><a name="p6571111219434"></a><a name="p6571111219434"></a>手机参数，参考<a href="#section03689893518">EmergencyNumberOptions</a>。</p>
  </td>
  </tr>
  </tbody>
  </table>

- 返回值

    <a name="table1757101214316"></a>

    <table><thead align="left"><tr id="row95711912194319"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p9571612184311"><a name="p9571612184311"></a><a name="p9571612184311"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p15716124437"><a name="p15716124437"></a><a name="p15716124437"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14571171294316"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p175711412184317"><a name="p175711412184317"></a><a name="p175711412184317"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p17572181218439"><a name="p17572181218439"></a><a name="p17572181218439"></a>以Promise形式异步返回判断是否是紧急电话号码的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.isEmergencyPhoneNumber("138xxxxxxxx", {slotId: 1});
    promise.then(data => {
        console.log(`isEmergencyPhoneNumber success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`isEmergencyPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## call.formatPhoneNumber<sup>7+</sup><a name="section1532018310579"></a>

formatPhoneNumber\(phoneNumber: string, callback: AsyncCallback<string\>\): void

格式化电话号码，使用callback方式作为异步方法。

-   参数

    <a name="table17320153175717"></a>
    <table><thead align="left"><tr id="row193205315577"><th class="cellrowborder" valign="top" width="19.009999999999998%" id="mcps1.1.5.1.1"><p id="p113201315710"><a name="p113201315710"></a><a name="p113201315710"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.939999999999998%" id="mcps1.1.5.1.2"><p id="p63211137575"><a name="p63211137575"></a><a name="p63211137575"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.459999999999999%" id="mcps1.1.5.1.3"><p id="p173211133571"><a name="p173211133571"></a><a name="p173211133571"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.589999999999996%" id="mcps1.1.5.1.4"><p id="p2032113335712"><a name="p2032113335712"></a><a name="p2032113335712"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row03216319579"><td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.1 "><p id="p193214385720"><a name="p193214385720"></a><a name="p193214385720"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.939999999999998%" headers="mcps1.1.5.1.2 "><p id="p632113175715"><a name="p632113175715"></a><a name="p632113175715"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p732113175714"><a name="p732113175714"></a><a name="p732113175714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p5321103115716"><a name="p5321103115716"></a><a name="p5321103115716"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row4321193135718"><td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.1 "><p id="p133228375712"><a name="p133228375712"></a><a name="p133228375712"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.939999999999998%" headers="mcps1.1.5.1.2 "><p id="p132212319575"><a name="p132212319575"></a><a name="p132212319575"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p163226335710"><a name="p163226335710"></a><a name="p163226335710"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p1732216385712"><a name="p1732216385712"></a><a name="p1732216385712"></a>回调函数，返回格式化电话号码的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.formatPhoneNumber("138xxxxxxxx", (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.formatPhoneNumber<sup>7+</sup><a name="section1832553165720"></a>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback<string\>\): void

格式化电话号码，可设置格式化参数，使用callback方式作为异步方法。

-   参数

    <a name="table193251239574"></a>
    <table><thead align="left"><tr id="row1032553195719"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p53251333571"><a name="p53251333571"></a><a name="p53251333571"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p19326193135718"><a name="p19326193135718"></a><a name="p19326193135718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p10326193145710"><a name="p10326193145710"></a><a name="p10326193145710"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p123267314571"><a name="p123267314571"></a><a name="p123267314571"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row73261035576"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p3326132579"><a name="p3326132579"></a><a name="p3326132579"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p2326123145710"><a name="p2326123145710"></a><a name="p2326123145710"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1932613318575"><a name="p1932613318575"></a><a name="p1932613318575"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p1232693125716"><a name="p1232693125716"></a><a name="p1232693125716"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row13263315573"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p43261395713"><a name="p43261395713"></a><a name="p43261395713"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p73271355710"><a name="p73271355710"></a><a name="p73271355710"></a>NumberFormatOptions</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p1832723125714"><a name="p1832723125714"></a><a name="p1832723125714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p17327831577"><a name="p17327831577"></a><a name="p17327831577"></a>格式化参数，参考<a href="#section23348305716">NumberFormatOptions</a>。</p>
    </td>
    </tr>
    <tr id="row16327035571"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p1132711325712"><a name="p1132711325712"></a><a name="p1132711325712"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p1432715365718"><a name="p1432715365718"></a><a name="p1432715365718"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p43271432575"><a name="p43271432575"></a><a name="p43271432575"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p143271737573"><a name="p143271737573"></a><a name="p143271737573"></a>回调函数，返回格式化电话号码的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.formatPhoneNumber("138xxxxxxxx",{
        countryCode: "CN"
    }, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.formatPhoneNumber<sup>7+</sup><a name="section1933033195716"></a>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

格式化电话号码，可设置格式化参数，使用promise方式作为异步方法。

-   参数

    <a name="table183300310578"></a>
    <table><thead align="left"><tr id="row183316315578"><th class="cellrowborder" valign="top" width="19.259999999999998%" id="mcps1.1.5.1.1"><p id="p33319314570"><a name="p33319314570"></a><a name="p33319314570"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.599999999999998%" id="mcps1.1.5.1.2"><p id="p433193155713"><a name="p433193155713"></a><a name="p433193155713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.36%" id="mcps1.1.5.1.3"><p id="p123316311576"><a name="p123316311576"></a><a name="p123316311576"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.78%" id="mcps1.1.5.1.4"><p id="p10331193155710"><a name="p10331193155710"></a><a name="p10331193155710"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row933113325719"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p163311038579"><a name="p163311038579"></a><a name="p163311038579"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p163323312579"><a name="p163323312579"></a><a name="p163323312579"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.36%" headers="mcps1.1.5.1.3 "><p id="p033213305715"><a name="p033213305715"></a><a name="p033213305715"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p7332531578"><a name="p7332531578"></a><a name="p7332531578"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row633243175715"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p16332133125717"><a name="p16332133125717"></a><a name="p16332133125717"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p1233212315572"><a name="p1233212315572"></a><a name="p1233212315572"></a>NumberFormatOptions</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.36%" headers="mcps1.1.5.1.3 "><p id="p153331032575"><a name="p153331032575"></a><a name="p153331032575"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p133316365712"><a name="p133316365712"></a><a name="p133316365712"></a>格式化参数，参考<a href="#section23348305716">NumberFormatOptions</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table43332033571"></a>
    <table><thead align="left"><tr id="row9333183165715"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p23331439577"><a name="p23331439577"></a><a name="p23331439577"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p633320345719"><a name="p633320345719"></a><a name="p633320345719"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2033343125720"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p733317335716"><a name="p733317335716"></a><a name="p733317335716"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p1133443125713"><a name="p1133443125713"></a><a name="p1133443125713"></a>以Promise形式异步返回格式化电话号码的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.formatPhoneNumber("138xxxxxxxx", {
        countryCode: "CN"
    });
    promise.then(data => {
        console.log(`formatPhoneNumber success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`formatPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## call.formatPhoneNumberToE164<sup>7+</sup><a name="section10285180112418"></a>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string, callback: AsyncCallback<string\>\): void

将电话号码格式化为E.164表示形式，使用callback方式作为异步方法。

需要格式化的电话号码需要与传入国家码相匹配，如中国手机号需要传入国家码CN，否则格式化后的手机号为null。

支持所有国家码。

-   参数

    <a name="table192869052411"></a>
    <table><thead align="left"><tr id="row928613082414"><th class="cellrowborder" valign="top" width="17.66%" id="mcps1.1.5.1.1"><p id="p1328716012245"><a name="p1328716012245"></a><a name="p1328716012245"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.18%" id="mcps1.1.5.1.2"><p id="p6287160182414"><a name="p6287160182414"></a><a name="p6287160182414"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.06%" id="mcps1.1.5.1.3"><p id="p172872013241"><a name="p172872013241"></a><a name="p172872013241"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p82877020245"><a name="p82877020245"></a><a name="p82877020245"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row112871803241"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p528717014242"><a name="p528717014242"></a><a name="p528717014242"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p428717082415"><a name="p428717082415"></a><a name="p428717082415"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p142872015249"><a name="p142872015249"></a><a name="p142872015249"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p528860162412"><a name="p528860162412"></a><a name="p528860162412"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row828800102417"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p1328812042412"><a name="p1328812042412"></a><a name="p1328812042412"></a>countryCode</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p2125659164714"><a name="p2125659164714"></a><a name="p2125659164714"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p9288140112413"><a name="p9288140112413"></a><a name="p9288140112413"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p1754915382910"><a name="p1754915382910"></a><a name="p1754915382910"></a>国家码，支持所有国家码，如：中国（CN）。</p>
    </td>
    </tr>
    <tr id="row1228890122414"><td class="cellrowborder" valign="top" width="17.66%" headers="mcps1.1.5.1.1 "><p id="p1528813082412"><a name="p1528813082412"></a><a name="p1528813082412"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.18%" headers="mcps1.1.5.1.2 "><p id="p028810102420"><a name="p028810102420"></a><a name="p028810102420"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.06%" headers="mcps1.1.5.1.3 "><p id="p2289505245"><a name="p2289505245"></a><a name="p2289505245"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p192897082415"><a name="p192897082415"></a><a name="p192897082415"></a>回调函数，返回将电话号码格式化为E.164表示形式的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    call.formatPhoneNumberToE164("138xxxxxxxx",{
        countryCode: "CN"
    }, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## call.formatPhoneNumberToE164<sup>7+</sup><a name="section142931509247"></a>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string\): Promise<string\>

将电话号码格式化为E.164表示形式，使用promise方式作为异步方法。

需要格式化的手机号码需要与传入国家码相匹配，如中国手机号需要传入国家码CN，否则格式化后的手机号为null。

支持所有国家码。

-   参数

    <a name="table929450172416"></a>
    <table><thead align="left"><tr id="row629417018244"><th class="cellrowborder" valign="top" width="19.259999999999998%" id="mcps1.1.5.1.1"><p id="p6294140192412"><a name="p6294140192412"></a><a name="p6294140192412"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.599999999999998%" id="mcps1.1.5.1.2"><p id="p142951704244"><a name="p142951704244"></a><a name="p142951704244"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.36%" id="mcps1.1.5.1.3"><p id="p17295100192410"><a name="p17295100192410"></a><a name="p17295100192410"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.78%" id="mcps1.1.5.1.4"><p id="p02952012244"><a name="p02952012244"></a><a name="p02952012244"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row62951502248"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p1929519042412"><a name="p1929519042412"></a><a name="p1929519042412"></a>phoneNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p12951018248"><a name="p12951018248"></a><a name="p12951018248"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.36%" headers="mcps1.1.5.1.3 "><p id="p17296190132415"><a name="p17296190132415"></a><a name="p17296190132415"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p02966032415"><a name="p02966032415"></a><a name="p02966032415"></a>电话号码。</p>
    </td>
    </tr>
    <tr id="row1929620042416"><td class="cellrowborder" valign="top" width="19.259999999999998%" headers="mcps1.1.5.1.1 "><p id="p129617032419"><a name="p129617032419"></a><a name="p129617032419"></a>countryCode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p22961403241"><a name="p22961403241"></a><a name="p22961403241"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.36%" headers="mcps1.1.5.1.3 "><p id="p179217422351"><a name="p179217422351"></a><a name="p179217422351"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p172967019245"><a name="p172967019245"></a><a name="p172967019245"></a>国家码，如：中国（CN）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table029711018249"></a>
    <table><thead align="left"><tr id="row429710013243"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p162971007247"><a name="p162971007247"></a><a name="p162971007247"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p8298109247"><a name="p8298109247"></a><a name="p8298109247"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2298100132414"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p1229819082416"><a name="p1229819082416"></a><a name="p1229819082416"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p329830142410"><a name="p329830142410"></a><a name="p329830142410"></a>以Promise形式异步返回将电话号码格式化为E.164表示形式的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = call.formatPhoneNumberToE164("138xxxxxxxx", {
        countryCode: "CN"
    });
    promise.then(data => {
        console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## DialOptions<a name="section12262183471518"></a>

拨打电话的可选参数。

<a name="table426533441512"></a>

<table><thead align="left"><tr id="row1626518342159"><th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.5.1.1"><p id="p178726479354"><a name="p178726479354"></a><a name="p178726479354"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.06%" id="mcps1.1.5.1.2"><p id="p1426519342153"><a name="p1426519342153"></a><a name="p1426519342153"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.299999999999999%" id="mcps1.1.5.1.3"><p id="p17265143471517"><a name="p17265143471517"></a><a name="p17265143471517"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="64.12%" id="mcps1.1.5.1.4"><p id="p1126583411512"><a name="p1126583411512"></a><a name="p1126583411512"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row126610344150"><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.5.1.1 "><p id="p010712258546"><a name="p010712258546"></a><a name="p010712258546"></a>extras</p>
</td>
<td class="cellrowborder" valign="top" width="14.06%" headers="mcps1.1.5.1.2 "><p id="p92665347159"><a name="p92665347159"></a><a name="p92665347159"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.299999999999999%" headers="mcps1.1.5.1.3 "><p id="p17266183451512"><a name="p17266183451512"></a><a name="p17266183451512"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="64.12%" headers="mcps1.1.5.1.4 "><p id="p1958121815414"><a name="p1958121815414"></a><a name="p1958121815414"></a>根据extras的值判断是否为视频通话，默认为语音通话。</p>
<a name="ul123261340174514"></a><a name="ul123261340174514"></a><ul id="ul123261340174514"><li>true：视频通话。</li><li>fasle：语音通话。</li></ul>
</td>
</tbody>
</table>

## CallState<a name="section345181318300"></a>

通话状态码。

<a name="table126934822015"></a>

<table><thead align="left"><tr id="row1369315832016"><th class="cellrowborder" valign="top" width="23.79%" id="mcps1.1.4.1.1"><p id="p1871313815402"><a name="p1871313815402"></a><a name="p1871313815402"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="18.61%" id="mcps1.1.4.1.2"><p id="p93231392263"><a name="p93231392263"></a><a name="p93231392263"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="57.599999999999994%" id="mcps1.1.4.1.3"><p id="p145500193814"><a name="p145500193814"></a><a name="p145500193814"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row206942882013"><td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.1 "><p id="p971155020221"><a name="p971155020221"></a><a name="p971155020221"></a>CALL_STATE_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="18.61%" headers="mcps1.1.4.1.2 "><p id="p2032318912262"><a name="p2032318912262"></a><a name="p2032318912262"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p85619013384"><a name="p85619013384"></a><a name="p85619013384"></a>无效状态，当获取呼叫状态失败时返回。</p>
</td>
</tr>
<tr id="row116945832019"><td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.1 "><p id="p78281110123613"><a name="p78281110123613"></a><a name="p78281110123613"></a>CALL_STATE_IDLE</p>
</td>
<td class="cellrowborder" valign="top" width="18.61%" headers="mcps1.1.4.1.2 "><p id="p10323097261"><a name="p10323097261"></a><a name="p10323097261"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p55617011389"><a name="p55617011389"></a><a name="p55617011389"></a>表示没有正在进行的呼叫。</p>
</td>
</tr>
<tr id="row253218315237"><td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.1 "><p id="p619455134615"><a name="p619455134615"></a><a name="p619455134615"></a>CALL_STATE_RINGING</p>
</td>
<td class="cellrowborder" valign="top" width="18.61%" headers="mcps1.1.4.1.2 "><p id="p632313942617"><a name="p632313942617"></a><a name="p632313942617"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p55610014386"><a name="p55610014386"></a><a name="p55610014386"></a>表示来电正在振铃或等待。</p>
</td>
</tr>
<tr id="row859720172311"><td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.1 "><p id="p106062072312"><a name="p106062072312"></a><a name="p106062072312"></a>CALL_STATE_OFFHOOK</p>
</td>
<td class="cellrowborder" valign="top" width="18.61%" headers="mcps1.1.4.1.2 "><p id="p1432310992611"><a name="p1432310992611"></a><a name="p1432310992611"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="57.599999999999994%" headers="mcps1.1.4.1.3 "><p id="p16572083814"><a name="p16572083814"></a><a name="p16572083814"></a>表示至少有一个呼叫处于拨号、通话中或呼叫保持状态，并且没有新的来电振铃或等待。</p>
</td>
</tr>
</tbody>
</table>

## EmergencyNumberOptions<sup>7+</sup><a name="section03689893518"></a>

判断是否是紧急电话号码的可选参数。

<a name="table16368168133516"></a>
<table><thead align="left"><tr id="row1736813813513"><th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.5.1.1"><p id="p153686819354"><a name="p153686819354"></a><a name="p153686819354"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.06%" id="mcps1.1.5.1.2"><p id="p113698823512"><a name="p113698823512"></a><a name="p113698823512"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.299999999999999%" id="mcps1.1.5.1.3"><p id="p7369188183517"><a name="p7369188183517"></a><a name="p7369188183517"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="64.12%" id="mcps1.1.5.1.4"><p id="p17369118123514"><a name="p17369118123514"></a><a name="p17369118123514"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13696810352"><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.5.1.1 "><p id="p2036911812355"><a name="p2036911812355"></a><a name="p2036911812355"></a>slotId</p>
</td>
<td class="cellrowborder" valign="top" width="14.06%" headers="mcps1.1.5.1.2 "><p id="p63691085356"><a name="p63691085356"></a><a name="p63691085356"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.299999999999999%" headers="mcps1.1.5.1.3 "><p id="p036938163510"><a name="p036938163510"></a><a name="p036938163510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="64.12%" headers="mcps1.1.5.1.4 "><p id="p111750457258"><a name="p111750457258"></a><a name="p111750457258"></a>卡槽ID：</p>
<a name="ul134537519529"></a><a name="ul134537519529"></a><ul id="ul134537519529"><li>0：卡槽1。</li><li>1：卡槽2。</li></ul>
</td>
</tr>
</tbody>
</table>

## NumberFormatOptions<sup>7+</sup><a name="section23348305716"></a>

格式化号码的可选参数。

<a name="table13344318576"></a>
<table><thead align="left"><tr id="row53356315717"><th class="cellrowborder" valign="top" width="13.489999999999998%" id="mcps1.1.5.1.1"><p id="p8335536577"><a name="p8335536577"></a><a name="p8335536577"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="12.09%" id="mcps1.1.5.1.2"><p id="p203357395714"><a name="p203357395714"></a><a name="p203357395714"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.299999999999999%" id="mcps1.1.5.1.3"><p id="p23355355711"><a name="p23355355711"></a><a name="p23355355711"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="64.12%" id="mcps1.1.5.1.4"><p id="p63359315715"><a name="p63359315715"></a><a name="p63359315715"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row5335183165719"><td class="cellrowborder" valign="top" width="13.489999999999998%" headers="mcps1.1.5.1.1 "><p id="p733573105712"><a name="p733573105712"></a><a name="p733573105712"></a>countryCode</p>
</td>
<td class="cellrowborder" valign="top" width="12.09%" headers="mcps1.1.5.1.2 "><p id="p3335735578"><a name="p3335735578"></a><a name="p3335735578"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.299999999999999%" headers="mcps1.1.5.1.3 "><p id="p73353313575"><a name="p73353313575"></a><a name="p73353313575"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="64.12%" headers="mcps1.1.5.1.4 "><p id="p16200121925613"><a name="p16200121925613"></a><a name="p16200121925613"></a>国家码，支持所有国家的国家码，如：中国（CN），默认为：CN。</p>
</td>
</tr>
</tbody>
</table>