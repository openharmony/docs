# Obtaining Current Cellular Network Signal Information


## Use Cases

Applications always need to obtain signal information of the registered cellular network to obtain the network quality. You can use this service to obtain the network signal information for the specified SIM card.


## Available APIs

The radio module provides you with APIs to obtain network signal information. The observer module provides APIs to register or unregister the observer for cellular network status changes. The following table describes the related APIs.

| Category| API| Description| Required Permission|
| -------- | -------- | -------- | -------- |
| Obtaining a **SignalInformation** object| radio.getSignalInformation​​() | Obtains the signal strength of the currently registered cellular network.| N/A|
| Registering the observer for signal information changes| observer.on('signalInfoChange') | Registers the observer for signal information changes.| N/A|
| Unregistering the observer for signal information changes| observer.off('signalInfoChange') | Unregisters the observer for signal information changes.| N/A|


## How to Develop

1. Import required modules.

2. Call the **getSignalInformation()** API to obtain the **SignalInformation** list.

3. Traverse the **SignalInformation** list to obtain the signal strength for each radio access technology (RAT) indicated by **signalType**.

4. (Optional) Register the observer for signal information changes.
   
   ```js
   import radio from '@ohos.telephony.radio'
   import observer from '@ohos.telephony.observer';
   
   // Obtain the signal strength of the specified SIM card, for example, card 1.
   let slotId = 0;
   radio.getSignalInformation(slotId, (err, data) => {
       if (!err) {
           console.log("get signal information success.");
           // Traverse the signal information list to obtain the signal strength for each RAT.
           for (let j = 0; j < data.length; j++) {
               console.log("type:" + data[j].signalType + ", level:" + data[j].signalLevel);
           }
       } else {
           console.log("get signal information fail, err is:" + JSON.stringify(err));
       }
   });
   // (Optional) Register the observer for signal information changes.
   observer.on("signalInfoChange", (data) => {
       console.log("signal info change, data is:" + JSON.stringify(data));
   });
   ```
