# Applying Custom Authentication

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--SE: @lichangting518-->
<!--TSE: @jane_lz-->

If the biometric authentication fails and the user taps the navigation button for a custom authentication, the unified identity authentication framework will terminate the system authentication process and instruct the caller to launch the custom authentication page.

For example, if the facial or fingerprint authentication provided by the system fails in a payment process, the user can switch to the password authentication defined by the device vendor.

Since payment password authentication is not a system authentication capability, the application must provide explicit navigation button information, for example, **Use Payment Password**, when initiating authentication. This ensures that a **Use Payment Password** button is displayed on the authentication page.

When the user taps this button, the application that initiates the custom authentication request will receive a special authentication result returned by the user authentication framework, indicating that the system authentication process is ended and prompting the application to launch its custom authentication page. As a result, the payment password authentication page customized by the service is displayed.

<!--RP1-->
![](figures/authentication-widget.png)
<!--RP1End-->

As shown in the following figure, the selected area is the **WidgetParam.navigationButtonText** field. You can configure this field to guide users to switch from biometric authentication to the service password authentication customized by the application.

> **NOTE**
> The lock screen password authentication and custom authentication are mutually exclusive.

| Authentication Type| Switch to Custom Authentication<br>(√ indicates supported, x indicates not supported)| 
| -------- | -------- |
| Lock screen password authentication| × | 
| Facial authentication| √ | 
| Fingerprint authentication| √ | 
| Facial + fingerprint authentication<sup>18+</sup>| √ | 
| Facial + lock screen password authentication| × | 
| Fingerprint + lock screen password authentication| × | 
| Facial + fingerprint + lock screen password authentication| × | 

## Development Example

For details about how to initiate the authentication request in the transition from a system-supported authentication to a custom authentication, see [initiating authentication](start-authentication.md). Ensure that the **widgetParam** parameter passed in must contain **navigationButtonText**.

This example only shows how to configure the UI and select the custom authentication UI. You need to add the code for launching the custom authentication page at the commented line in the example.

```ts
import { BusinessError } from  '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.FACE],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  // Set navigationButtonText for the authentication page.
  const widgetParam: userAuth.WidgetParam = {
    title: 'Verify identity',
    navigationButtonText: 'Use password',
  };
  // Obtain an authentication object.
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // Subscribe to the authentication result.
  userAuthInstance.on('result', {
    onResult(result) {
      // If the ResultCode 12500000 is returned, the operation is successful.
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
      // If the ResultCode 12500011 is returned, the user taps the navigation button to switch to the custom authentication page.
      if (result.result == 12500011) {
        // You need to implement the process of launching the custom authentication page.
      }
    }
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```
