# Extensible Authentication

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @foredward-->
<!--Designer: @h00918518-->
<!--Tester: @WIFIroam-test-->
<!--Adviser: @zhang_yixin13-->

## Introduction

Extensible authentication is a mechanism provided by the **eap** module to enable third-party clients to participate in custom 802.1X (a port-based network access control protocol) authentication, such as Extensible Authentication Protocol (EAP) authentication.

> **NOTE**
>
> This functionality is supported since API version 20.

To implement extensible authentication, the clients should be able to:

1. Encapsulate private data into EAP protocol packets based on the data structure agreed upon by the client and authentication server.
2. During the authentication, perform custom actions such as security check scanning on the local host, and send an authentication response after the custom action is complete.
   The OS is required to provide a mechanism for third-party clients to participate in 802.1X authentication.


To meet the preceding requirements, the custom 802.1X authentication mechanism should be able to support:

1. Customizing the listening for 802.1X packets and adapt the packet exchange process.
2. Initiating 802.1X authentication and deauthentication on the **eth** network port.

## When to Use

Typical application scenarios of the custom 802.1X authentication include:

1. For enterprise network management applications, custom security verification needs to be added to the enterprise Wi-Fi's 802.1X authentication process to access the enterprise intranet. The required functions include:

   - Customization of the packet type and EAP type for custom authentication.
   - Setting of the standard authentication result based on the custom authentication result.

2. For enterprise network management applications, 802.1X authentication needs to be implemented on the **eth** network port to access the enterprise intranet. The required functions include:

   - Support for the standard 802.1X authentication process.
   - Customization of the 802.1X authentication process.

The following describes the development procedure specific to each application scenario.

## Adding Custom Security Verification to the 802.1X Authentication Process

1. Import the **eap** namespace from **@kit.NetworkKit**.
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   ```
2. Call [regCustomEapHandler](../reference/apis-network-kit/js-apis-net-eap.md#eapregcustomeaphandler) to register the EAP packet types to listen for. During 802.1X authentication, the system will encapsulate the eligible EAP packets into the callback function for enterprise applications to retrieve.
   
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
3. After the EAP packets are transferred to the callback function, block the 802.1X authentication process so that the enterprise applications can retrieve the complete packet content.
4. If the packets of the registered packet type are sent from the server to the client, they include the custom content added by the server. Determine whether to continue the subsequent steps based on the custom content, and call [replyCustomEapData](../reference/apis-network-kit/js-apis-net-eap.md#eapreplycustomeapdata) to send the packets to the system.
   
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
5. If the packets of the registered packet type are sent from the client to the server, they are the original 802.1X authentication packets. Add the custom content to the original packets, and then call [replyCustomEapData](../reference/apis-network-kit/js-apis-net-eap.md#eapreplycustomeapdata) to send the packets to the system.
   
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
6. To cancel custom security verification in the 802.1X authentication process, call [unregCustomEapHandler](../reference/apis-network-kit/js-apis-net-eap.md#eapunregcustomeaphandler).
   
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

## Initiating 802.1X Authentication on the eth Network Port

1. Use a network cable to connect the device to the **eth** network port.
2. Import the **eap** namespace from **@kit.NetworkKit**.
   
   ```ts
   import {eap} from '@kit.NetworkKit';
   ```
3. If authentication is required for the network management applications, call [startEthEap](../reference/apis-network-kit/js-apis-net-eap.md#eapstartetheap) to initiate the 802.1X authentication process.
   
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
4. If authentication is not required for the network management applications, call [logOffEthEap](../reference/apis-network-kit/js-apis-net-eap.md#eaplogoffetheap) to initiate the 802.1X deauthentication process.
   
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
