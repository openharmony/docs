# User Authentication Development

## When to Use

OpenHarmony supports 2D and 3D facial recognition that can be used for identity authentication during device unlocking, application login, and payment.

## Available APIs

The  **userIAM\_userAuth**  module provides methods for checking the support for biometric authentication, and performing and canceling authentication. You can perform authentication based on biometric features such as facial characteristics. Before performing biometric authentication, check whether your device supports this capability, including the authentication type, security level, and whether local authentication is used. If biometric authentication is not supported, consider using another authentication type. The following table lists methods in the APIs available for biometric authentication.

**Table  1**  Methods available for biometric authentication

| Method                                                       | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getAuthenticator(): Authenticator                            | Obtains an **Authenticator** object for user authentication. <sup>6+</sup><br>Obtains an **Authenticator** object to check the device's capability of user authentication, perform or cancel user authentication, and obtain the tips generated in the authentication process. <sup>7+</sup> |
| checkAvailability(type: AuthType, level: SecureLevel): number | Checks whether the device supports the specified authentication type and security level. |
| execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void | Performs user authentication and returns the authentication result using an asynchronous callback. |
| execute(type: AuthType, level: SecureLevel): Promise\<number> | Performs user authentication and returns the authentication result using a promise. |
| cancel(): void                                               | Cancels the current authentication.                          |
| on(type: "tip", callback: Callback\<Tip>): void              | Subscribes to the events of the specified type.              |
| off(type: "tip", callback?: Callback\<Tip>): void            | Unsubscribes from the events of the specified type.          |


## How to Develop

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

3.  \(Optional\) Subscribe to tip information. The sample code is as follows:

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

5.  \(Optional\) Unsubscribe from tip information if  you have subscribed to tip information you have subscribed to tip information.

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

