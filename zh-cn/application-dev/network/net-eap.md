# 扩展认证

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @foredward-->
<!--Designer: @h00918518-->
<!--Tester: @WIFIroam-test-->
<!--Adviser: @zhang_yixin13-->

## 简介

部分企业用户的PC网络接入认证使用802.1X认证方式，认证客户端由第三方厂商提供。

> **说明：**
>
> 扩展认证能力从API version 20开始支持。

认证客户端有以下定制行为：

1. 在EAP协议报文内封装私有数据，该私有数据遵循客户端与认证服务器约定的数据结构。
2. 在认证过程中，客户端在本地进行安检扫描等定制动作，定制动作结束后，客户端向接入设备回复认证消息。
   在这种机制下，需要操作系统提供三方客户端介入802.1X认证流程的机制，支撑客户端的定制认证。


为满足以上需求场景，定制化802.1X认证提供如下功能：

1. 定制化监听与修改802.1X报文交互流程的能力。
2. 对eth网口发起802.1X认证和去认证的能力。

## 场景介绍

定制化802.1X认证流程的典型场景如下：

1. 企业网管应用，需要在企业Wi-Fi的802.1X认证流程中加入自定义的安全校验，来接入企业内网。

   - 支持指定要进行定制化处理的报文类型和EAP类型。
   - 支持根据自定义的安全校验结果来指定标准认证流程的结果。

2. 企业网管应用，需要支持使用eth网口进行802.1X安全认证流程来接入企业内网。

   - 支持标准802.1X认证流程。
   - 支持定制化802.1X认证流程。

具体开发方式介绍如下。

## 802.1X认证流程中加入自定义的安全校验

1. 从@kit.NetworkKit中导入eap命名空间。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   ```
2. 调用[regCustomEapHandler](../reference/apis-network-kit/js-apis-net-eap.md#eapregcustomeaphandler)方法，注册所需监听的EAP报文类型。在802.1X认证过程中，系统会将符合条件的EAP报文传递至callback函数中，供企业应用获取。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   let netType = 1;
   let eapCode = 1;
   let eapType = 25;
   let eapData = (eapData:eap.EapData):void => {
       console.info("rsp result",JSON.stringify(eapData));
   }
   
   try {
       eap.regCustomEapHandler(netType, eapCode, eapType, eapData);
       console.info('regCustomEapHandler success');
   } catch (err) {
       console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
   }
   ```
3. 报文传递至callback函数后，802.1X认证流程会阻塞等待, 用户能够获取到完整的报文内容。
4. 若注册的是由服务器发送给客户端的报文类型，则此时可以从报文中看到由服务器加入的自定义内容。应用根据自定义内容，判断认证是否应该继续往后续步骤进行，并调用[replyCustomEapData](../reference/apis-network-kit/js-apis-net-eap.md#eapreplycustomeapdata)方法通知系统。
   
   ```ts
    import {eap} from '@kit.NetworkKit';
    let netType = 1;
    let eapCode= 1; // eap request
    let eapType= 25; // EAP_PEAP
    let result = 1;
    let eapData = (eapData:eap.EapData):void => {
        try{
        eap.replyCustomEapData(result, eapData);
        console.info('replyCustomEapData success');   
        } catch (err) {   
        console.error('errCode: ' + err.code + ' , errMessage: ' + err.message);
        }
    }
   
   try{
       eap.regCustomEapHandler(netType, eapCode, eapType, eapData);   
   	   console.info('regCustomEapHandler success');
   } catch (err) {
       console.error('errCode: ' + err.code + 'errMessage: ' + err.message);
   }
   ```
5. 若注册的报文类型是由客户端发给服务器的，则此时获取到的是原始的802.1X认证报文，应用需要在原始报文内容中加入自己的自定义内容，并将加入自定义内容后的报文内容调用[replyCustomEapData](../reference/apis-network-kit/js-apis-net-eap.md#eapreplycustomeapdata)方法通知系统。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   let netType = 1;
   let eapCode= 2; // eap response
   let eapType= 25; // EAP_PEAP
   let result = 1;
   let eapData = (eapData:eap.EapData):void => {
        try{
            eap.replyCustomEapData(result, eapData);
            console.info('replyCustomEapData success');   
        } catch (err) {   
            console.error('errCode: ' + err.code + ' , errMessage: ' + err.message);
        }
   }
   
   try{
       eap.regCustomEapHandler(netType, eapCode, eapType, eapData);   
       console.info('regCustomEapHandler success');
   } catch (err) {
       console.error('errCode: ' + err.code + 'errMessage: ' + err.message);
   }
   ```
6. 如此便从发送/接收两个方向上实现了对标准802.1X流程的定制化。需要取消定制化时，调用[unregCustomEapHandler](../reference/apis-network-kit/js-apis-net-eap.md#eapunregcustomeaphandler)方法。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   let netType = 1;
   let eapCode = 1;
   let eapType = 25;
   let eapData = (eapData:eap.EapData):void => {
       console.info("rsp result",JSON.stringify(eapData));
   }
   
   try {
       eap.unregCustomEapHandler(netType, eapCode, eapType, eapData);
       console.info('unregCustomEapHandler success');
   } catch (err) {
       console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
   }
   
   ```

## 使用eth接口发起802.1X认证流程

1. 设备通过硬件接口，插入网线。
2. 从@kit.NetworkKit中导入eap命名空间。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   ```
3. 当企业管理软件需要进行认证，调用[startEthEap](../reference/apis-network-kit/js-apis-net-eap.md#eapstartetheap)方法时，会发起802.1X认证流程。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   let netId = 100;
   let profile: eap.EthEapProfile = {
       eapMethod: eap.EapMethod.EAP_TTLS,
       phase2Method: eap.Phase2Method.PHASE2_AKA_PRIME,
       identity: "identity",
    	   anonymousIdentity: "anonymousIdentity",
    	   password: "password",
    	   caCertAliases: "caCertAliases",
    	   caPath: "caPath",
    	   clientCertAliases: "clientCertAliases",
    	   certEntry: new Uint8Array([5,6,7,8,9,10]),
    	   certPassword: "certPassword",
    	   altSubjectMatch: "altSubjectMatch",
    	   domainSuffixMatch: "domainSuffixMatch",
    	   realm: "realm",
    	   plmn: "plmn",
    	   eapSubId: 1
   };
   
   try {
    	   eap.startEthEap(netId, profile);
    	   console.info('startEthEap success');
   } catch (err) {
   	    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
   }
   ```
4. 当企业管理软件需要退出认证状态，调用[logOffEthEap](../reference/apis-network-kit/js-apis-net-eap.md#eaplogoffetheap)方法，即会发起802.1X去认证流程。
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   let netId = 100;    
   try{
     	   eap.logOffEthEap(netId);
     	   console.error("logOffEthEap success");
   } catch (err) {
          console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
   }
   ```