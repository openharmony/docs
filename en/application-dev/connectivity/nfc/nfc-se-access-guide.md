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
| createService(): Promise\<SEService>                    | Creates an **SEService** instance for connecting to all available SEs in the system.                                                               |
| getReaders(): Reader[]                      | Obtains available SE readers, which include all the SEs on the device.                                                               |
| openSession(): Session                 | Opens a session to connect to an SE in this reader. This API returns a session instance.                                                               |
| openLogicalChannel(aid: number[]): Promise\<Channel>                  | Opens a logical channel. This API returns a logical channel instance.                                                               |
| transmit(command: number[]): Promise\<number[]> | Transmits APDU data to this SE.                                                               |
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
    hilog.info(0x0000, 'testTag', 'secure element available.');
    this.omaTest();
  }

  private async omaTest () {
    // Obtain the service.
    await omapi.createService().then((data) => {
      if (data == undefined || !data.isConnected()) {
        hilog.error(0x0000, 'testTag', 'secure element service disconnected.');
        return;
      }
      seService = data;
      hilog.info(0x0000, 'testTag', 'secure element service connected.');
    }).catch((error: BusinessError) => {
      hilog.error(0x0000, 'testTag', 'createService error %{public}s', JSON.stringify(error));
      return;
    });

    // Obtain readers.
    try {
      seReaders = seService.getReaders();
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getReaders error %{public}s', JSON.stringify(error));
    }
    if (seReaders == undefined || seReaders.length == 0) {
      hilog.error(0x0000, 'testTag', 'no valid reader found.');
      seService.shutdown();
      return;
    }
    let reader: (omapi.Reader | undefined);
    for (let i = 0; i < seReaders.length; ++i) {
      let r = seReaders[i];
      if (r.getName().includes("SIM")) {
        reader = r;
        break;
      }
    }
    if (reader == undefined) {
      hilog.error(0x0000, 'testTag', 'no valid sim reader.');
      return;
    }
    hilog.info(0x0000, 'testTag', 'reader is %{public}s', reader?.getName());

    // Obtain the session.
    try {
      seSession = reader?.openSession() as omapi.Session;
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'openSession error %{public}s', JSON.stringify(error));
    }
    if (seSession == undefined) {
      hilog.error(0x0000, 'testTag', 'seSession invalid.');
      seService.shutdown();
      return;
    }

    // Obtain the channel.
    try {
      // change the aid value for open logical channel
      // Change the value to the AID of the application for which the logical channel is opened.
      seChannel = await seSession.openLogicalChannel(aidArray, p2);
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }

    if (seChannel == undefined) {
      hilog.error(0x0000, 'testTag', 'seChannel invalid.');
      return;
    }

    // Send data.
    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Set command data correctly.
    try {
      let response: number[] = await seChannel.transmit(cmdData)
      hilog.info(0x0000, 'testTag', 'seChannel.transmit() response = %{public}s.', JSON.stringify(response));
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'seChannel.transmit() exception = %{public}s.', JSON.stringify(exception));
    }

    // Close the channel. After performing the operation, make sure that the channel is truly closed.
    try {
      seChannel.close();
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'seChannel.close() exception = %{public}s.', JSON.stringify(exception));
    }

  }
}

```
