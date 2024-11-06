# SE Access Development

## Introduction
An electronic device may have one or more secure elements (SEs), such as the embedded SE (eSE) and SIM card. A SIM card that functions as an SE must have the NFC feature.

## When to Use
An application may need to write data to an SE to emulate an NFC card on the device. The NFC card data may be stored on an eSE or a SIM card. Generally, SEs are preset with rules for access control. An application must have related permissions and can access an SE only after a successful permission verification.

## Available APIs
For details about the JS APIs and sample code, see [SE Management](../../reference/apis-connectivity-kit/js-apis-secureElement.md).
The following table describes the APIs for accessing SEs.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| newSEService(type: 'serviceState', callback: Callback\<ServiceState>): SEService                    | Creates an **SEService** instance for connecting to all available SEs in the system.                                                               |
| getReaders(): Reader[]                      | Obtains available SE readers, which include all the SEs on the device.                                                               |
| openSession(): Session                 | Opens a session to connect to an SE in this reader. This API returns a session instance.                                                               |
| openLogicalChannel(aid: number[]): Promise\<Channel>                  | Opens a logical channel. This API returns a logical channel instance.                                                               |
| transmit(command: number[]): Promise\<number[]> | Transmits APDU data to this SE.    |
| close(): void | Closes this channel.                                                           |


## How to Develop

### Accessing an SE
1. Import modules.
2. Check whether the device supports SEs.
3. Access an SE and read or write data.
   
```ts
import { omapi } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';


let seService : omapi.SEService;
let seReaders : omapi.Reader[];
let seSession : omapi.Session;
let seChannel : omapi.Channel;
let aidArray : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];
let p2 : number = 0x00;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // Check whether the device supports SEs.
    if (!canIUse("SystemCapability.Communication.SecureElement")) {
      hilog.error(0x0000, 'testTag', 'secure element unavailable.');
      return;
    }

    // Obtain the service.
    try {
      seService = omapi.newSEService("serviceState", (state) => {
        hilog.info(0x0000, 'testTag', 'se service state = %{public}s', JSON.stringify(state));
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'newSEService error %{public}s', JSON.stringify(error));
    }
    if (seService == undefined || !seService.isConnected()) {
      hilog.error(0x0000, 'testTag', 'secure element service disconnected.');
      return;
    }

    // get readers
    try {
      seReaders = seService.getReaders();
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getReaders error %{public}s', JSON.stringify(error));
    }
    if (seReaders == undefined || seReaders.length == 0) {
      hilog.error(0x0000, 'testTag', 'no valid reader found.');
      return;
    }

    // get session
    try {
      let reader = seReaders[0]; // change it to the selected reader, ese or sim.
      seSession = reader.openSession();
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'openSession error %{public}s', JSON.stringify(error));
    }
    if (seSession == undefined) {
      hilog.error(0x0000, 'testTag', 'seSession invalid.');
      return;
    }

    // get channel
    try {
      // change the aid value for open logical channel.
      seSession.openLogicalChannel(aidArray, p2, (error, data) => {
        if (error) {
          hilog.error(0x0000, 'testTag', 'openLogicalChannel error %{public}s', JSON.stringify(error));
        } else {
          seChannel = data;
        }
      });
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }
    if (seChannel == undefined) {
      hilog.error(0x0000, 'testTag', 'seChannel invalid.');
      return;
    }

    // transmit data
    let cmdData = [0x01, 0x02, 0x03, 0x04]; // please change the raw data to be correct.
    try {
      seChannel.transmit(cmdData).then((response) => {
        hilog.info(0x0000, 'testTag', 'seChannel.transmit() response = %{public}s.', JSON.stringify(response));
      }).catch((error : BusinessError) => {
        hilog.error(0x0000, 'testTag', 'seChannel.transmit() error = %{public}s.', JSON.stringify(error));
      });
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'seChannel.transmit() exception = %{public}s.', JSON.stringify(exception));
    }

    // close channel. must make sure the channel is closed at last.
    try {
      seChannel.close();
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'seChannel.close() exception = %{public}s.', JSON.stringify(exception));
    }
  }
}
```
