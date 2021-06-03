# Telephony <a name="EN-US_TOPIC_0000001162422291"></a>

-   [Introduction](#section104mcpsimp)
-   [Directory Structure](#section119mcpsimp)
-   [Constraints](#section123mcpsimp)
-   [Usage Guidelines](#section128mcpsimp)
    -   [Obtaining Current Cellular Network Signal Information](#section1458213210369)
    -   [Observing Cellular Network Status Changes](#section750135512369)

-   [Repositories Involved](#section152mcpsimp)

## Introduction<a name="section104mcpsimp"></a>

The Telephony subsystem provides APIs for obtaining information about the wireless cellular network and SIM card. Applications can call these APIs to obtain information such as the name of the currently registered network, network service status, signal strength, and SIM card information.

The Telephony subsystem consists of the following modules:

-   Telephony core service: initializes the RIL Manager, SIM card module, and network search module.
-   Call Manager module: manages three types of calls – circuit switched \(CS\), IP multimedia subsystem \(IMS\), and over the top \(OTT\) calls. It is responsible for applying for the audio and video resources required for a call and resolving conflicts in a multi-channel call.
-   Cellular call module: implements basic calls over carrier networks.
-   SMS & MMS module: provides the capabilities of sending and receiving short message service \(SMS\) messages and encoding and decoding multimedia messaging service \(MMS\) messages.
-   State registry module: provides APIs to register and deregister an observer that listens for various callback events of the telephony subsystem. 

**Figure 1**  Telephony subsystem architecture

![](figures/en-us_architecture-of-telephony-subsystem.png)

## Directory Structure<a name="section119mcpsimp"></a>

```
base/telephony/
├── core_service            # Core service
├── call_manager            # Call Manager module
├── cellular_call           # Cellular call module
├── sms_mms                 # SMS & MMS module
└── state_registry          # State registry module
```

## Constraints<a name="section123mcpsimp"></a>

1.  The open-source version currently supports only the CS call and SMS services. Cellular data and dual-SIM card are not supported.

## Usage Guidelines<a name="section128mcpsimp"></a>

### Obtaining Current Cellular Network Signal Information<a name="section1458213210369"></a>

1.  Import the  **radio**  namespace from  **@ohos.telephony.radio.d.ts**.
2.  Call the  **getSignalInformation\(slotId: number\)**  method in callback or Promise mode. This method works in asynchronous mode. 
3.  Obtain the result from the  **SignalInformation**  array in the callback.
4.  Traverse the  **SignalInformation**  array to obtain the  **signalLevel**  \(signal strength\) for each  **signalType**  \(radio access technology\).

    ```
    // Import the radio package.
    import radio from "@ohos.telephony.radio";
    
    // Set the value of slotId.
    let slotId = 1;
    
    // Call the API in callback mode.
    radio.getSignalInformation(slotId, (err, value) => {
      if (err) {
        // If the API call failed, err is not empty.
        console.error(`failed to getSignalInformation because ${err.message}`);
        return;
      }
      // If the API call succeeded, err is empty.
      for (let i = 0; i < value.length; i++) {
        console.log(`success to getSignalInformation: type is ${value[i].signalType}, level is ${value[i].signalLevel}`);
      }
    });
    
    // Call the API in Promise mode.
    let promise = radio.getSignalInformation(slotId);
    promise.then((value) => {
      // The API call succeeded.
      for (let i = 0; i < value.length; i++) {
        console.log(`success to getSignalInformation: type is ${value[i].signalType}, level is ${value[i].signalLevel}`);
      }
    }).catch((err) => {
      // The API call failed.
      console.error(`failed to getSignalInformation because ${err.message}`);
    });
    ```


### Observing Cellular Network Status Changes<a name="section750135512369"></a>

**Adding an Observer**

1.  Import the  **observer**  namespace from  **@ohos.telephony.observer.d.ts**.
2.  Call the  **on\(type: 'networkStateChange'\)**  method with  **slotId**  \(slot ID, optional\) and  **callback**  \(callback processing function\) passed in.
3.  Register an  **observer**  instance for callback events of network status changes.

    ```
    // Import the observer package.
    import observer from '@ohos.telephony.observer';
    
    // Registers an observer.
    observer.on('networkStateChange', {slotId: 1}, (err, value) => {
      if (err) {
        // If the API call failed, err is not empty.
        console.error(`failed, because ${err.message}`);
        return;
      }
      // If the API call succeeded, err is empty.
      console.log(`success on. network state is ` + value);
    });
    ```


**Removing the Observer**

1.  Import the  **observer**  namespace from  **@ohos.telephony.observer.d.ts**.
2.  Call the  **off\(type: 'networkStateChange'\)**  method with the  **callback**  object passed to the  **observer**.

    ```
    // Import the observer package.
    import observer from '@ohos.telephony.observer';
    
    // Deregister the observer.
    observer.off('networkStateChange', (err, value) => {
      if (err) {
        // If the API call failed, err is not empty.
        console.error(`failed, because ${err.message}`);
        return;
      }
      // If the API call succeeded, err is empty.
      console.log(`success off`);
    });
    ```


## Repositories Involved<a name="section152mcpsimp"></a>

**Telephony subsystem**

[telephony_core_service](https://gitee.com/openharmony/telephony_core_service/blob/master/README.md)

[telephony_call_manager](https://gitee.com/openharmony/telephony_call_manager/blob/master/README.md)

[telephony_cellular_call](https://gitee.com/openharmony/telephony_cellular_call/blob/master/README.md)

[telephony_sms_mms](https://gitee.com/openharmony/telephony_sms_mms/blob/master/README.md)

[telephony_state_registry](https://gitee.com/openharmony/telephony_state_registry/blob/master/README.md)

