# Redirecting to the Dial Screen

You can use this service for your application to redirect users to the dial screen and display the dialed number. When the **makeCall** API is called, the device will automatically display the dial screen. On this screen, the user can choose to make an audio or video call and specify the SIM card.


## Available APIs

The call module provides APIs for call management. The observer module provides APIs to register or unregister an observer for call service status changes. The following table describes the related APIs.

| Category| API| Description| Required Permission|
| -------- | -------- | -------- | -------- |
| Checking call capabilities| call.hasVoiceCapability() | Checks whether the voice call function is supported.| N/A|
| Redirecting to the dial screen| call.makeCall() | Enables redirection to the dial screen and display of the dialed number.| N/A|
| Registering the observer for call service status changes| observer.on('callStateChange') | Registers the observer for call service status changes.| ohos.permission.READ_CALL_LOG (required for obtaining phone numbers)|
| Unregistering the observer for call service status changes| observer.off('callStateChange') | Unregisters the observer for call service status changes.| N/A|


## How to Develop

1. Import required modules.

2. Invoke the **hasVoiceCapability()** API to check whether the call function is supported. If supported, go to step 3; otherwise, calls will be rejected.

3. Enable redirection to the dial screen and display of the dialed number.

4. (Optional) Register the observer for call service status changes.
   
   ```js
   // Import the required modules.
   import call from '@ohos.telephony.call';
   import observer from '@ohos.telephony.observer';
   
   // Check whether the voice call function is supported.
   let isSupport = call.hasVoiceCapability();
   if (!isSupport) {
       console.log("not support voice capability, return.");
       return;
   }
   // If the voice call function is supported, the user will be redirected to the dial screen and the dialed number is displayed.
   call.makeCall("13xxxx", (err)=> {
       if (!err) {
           console.log("make call success.");
       } else {
           console.log("make call fail, err is:" + JSON.stringify(err));
       }
   });
   // (Optional) Register the observer for call service status changes.
   observer.on("callStateChange", (data) => {
       console.log("call state change, data is:" + JSON.stringify(data));
   });
   ```
