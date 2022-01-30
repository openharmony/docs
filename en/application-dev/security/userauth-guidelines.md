# User Authentication Development<a name="EN-US_TOPIC_0000001234020089"></a>

>**NOTE:** 
>This document applies to JS.

## When to Use<a name="section1410661605517"></a>

HarmonyOS supports 2D and 3D facial recognition that can be used for identity authentication during device unlocking, application login, and payment.

## Available APIs<a name="section187921265614"></a>

The  **userIAM\_userAuth**  module provides methods for checking the support for biometric authentication, and performing and canceling authentication. You can perform authentication based on biometric features such as facial characteristics. Before performing biometric authentication, check whether your device supports this capability, including the authentication type, security level, and whether local authentication is used. If biometric authentication is not supported, consider using another authentication type. The following table lists methods in the APIs available for biometric authentication.

**Table  1**  Methods available for biometric authentication

<a name="table1261657203"></a>
<table><thead align="left"><tr id="row76161273014"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p96161471303"><a name="p96161471303"></a><a name="p96161471303"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p13616107301"><a name="p13616107301"></a><a name="p13616107301"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14616874017"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p182909135717"><a name="p182909135717"></a><a name="p182909135717"></a>getAuthenticator(): Authenticator</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p052435213251"><a name="p052435213251"></a><a name="p052435213251"></a>Obtains an <strong id="b7528121952513"><a name="b7528121952513"></a><a name="b7528121952513"></a>Authenticator</strong> object for user authentication. <sup id="sup580316168261"><a name="sup580316168261"></a><a name="sup580316168261"></a>6+</sup></p>
<p id="p18224123611319"><a name="p18224123611319"></a><a name="p18224123611319"></a>Obtains an <strong id="b16234636102517"><a name="b16234636102517"></a><a name="b16234636102517"></a>Authenticator</strong> object to check the device's capability of user authentication, perform or cancel user authentication, and obtain the tips generated in the authentication process. <sup id="sup1832921092616"><a name="sup1832921092616"></a><a name="sup1832921092616"></a>7+</sup></p>
</td>
</tr>
<tr id="row106165720013"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p116992514713"><a name="p116992514713"></a><a name="p116992514713"></a>checkAvailability(type: AuthType, level: SecureLevel): number</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p695651014402"><a name="p695651014402"></a><a name="p695651014402"></a>Checks whether the device supports the specified authentication type and security level.</p>
</td>
</tr>
<tr id="row116161776012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6854332710"><a name="p6854332710"></a><a name="p6854332710"></a>execute(type: AuthType, level: SecureLevel, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p144141341165617"><a name="p144141341165617"></a><a name="p144141341165617"></a>Performs user authentication and returns the authentication result using an asynchronous callback.</p>
</td>
</tr>
<tr id="row17616370011"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p0175638178"><a name="p0175638178"></a><a name="p0175638178"></a>execute(type: AuthType, level: SecureLevel): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p8257141716153"><a name="p8257141716153"></a><a name="p8257141716153"></a>Performs user authentication and returns the authentication result using a promise.</p>
</td>
</tr>
<tr id="row9616871002"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p944814481776"><a name="p944814481776"></a><a name="p944814481776"></a>cancel(): void</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p175161740144013"><a name="p175161740144013"></a><a name="p175161740144013"></a>Cancels the current authentication.</p>
</td>
</tr>
<tr id="row1445813511477"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1679911511814"><a name="p1679911511814"></a><a name="p1679911511814"></a>on(type: "tip", callback: Callback&lt;Tip&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p44583514715"><a name="p44583514715"></a><a name="p44583514715"></a>Subscribes to the events of the specified type.</p>
</td>
</tr>
<tr id="row193552551676"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11019121988"><a name="p11019121988"></a><a name="p11019121988"></a>off(type: "tip", callback?: Callback&lt;Tip&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p435610551774"><a name="p435610551774"></a><a name="p435610551774"></a>Unsubscribes from the events of the specified type.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section13636175015153"></a>

Before starting the development, make the following preparations:

1.  Add the  **ohos.permission.ACCESS\_BIOMETRIC**  permission declaration to the application permission file.
2.  Add  **import userIAM\_userAuth from '@ohos.userIAM.userAuth'**  to the code file that provides biometric recognition.

The development procedure is as follows:

1.  Obtain an  **Authenticator**  singleton object. The sample code is as follows:

    ```
    let auth = userIAM_userAuth.getAuthenticator();
    ```

2.  Check whether the device provides the authentication capability of the specified level.

    2D facial recognition supports authentication lower than S2, and 3D facial recognition supports authentication lower than S3. The sample code is as follows:

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let checkCode = authenticator.checkAvailability("FACE_ONLY", "S2");
    if (checkCode == userIAM_userAuth.CheckAvailabilityResult.SUPPORTED) {
        console.info("check auth support success");
    } else {
        console.error("check auth support fail, code = " + checkCode);
    }
    ```

3.  <a name="li109311114115111"></a>\(Optional\) Subscribe to tip information. The sample code is as follows:

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let tipCallback = (tip)=>{
        console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode +") event(" +
            tip.tipEvent + ") info(" + tip.tipInfo + ")");
    };
    authenticator.on("tip", tipCallback);
    ```

4.  Perform the authentication. The sample code is as follows:

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    authenticator.execute("FACE_ONLY", "S2").then((code)=>{
        authenticator.off("tip", tipCallback);
        console.info("auth success");
    }).catch((code)=>{
        authenticator.off("tip", tipCallback);
        console.error("auth fail, code = " + code);
    });
    ```

5.  \(Optional\) Unsubscribe from tip information if  [you have subscribed to tip information](#li109311114115111)you have subscribed to tip information.

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let tipCallback = (tip)=>{
        console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode + ") event(" +
            tip.tipEvent + ") info(" + tip.tipInfo + ")");
    };
    // Unsubscribe from a specified callback.
    authenticator.off("tip", tipCallback);
    // Unsubscribe from all callbacks.
    authenticator.off("tip");
    ```

6.  Cancel authentication. The sample code is as follows:

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let cancelCode = authenticator.cancel();
    if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
        console.info("cancel auth success");
    } else {
        console.error("cancel auth fail");
    }
    ```


