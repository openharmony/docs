# SE Access Development

## Introduction
An electronic device may have one or more secure elements (SEs), such as the embedded SE (eSE) and SIM card. Access control for SEs is implemented in accordance with the Global Platform Access Control (GPAC) specification.

## When to Use
An application may need to write data to an SE to emulate an NFC card on the device. The NFC card data may be stored on an eSE or a SIM card. Generally, SEs are preset with rules for access control. An application must have related permissions and can access an SE only after a successful permission verification.

## Available APIs
For details about the APIs and sample code, see [SE Management](../../reference/apis-connectivity-kit/js-apis-secureElement.md).

The following table describes the APIs for SE access.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| createService(): Promise\<SEService>                    | Creates an **SEService** instance for connecting to all available SEs in the system.                                                               |
| getReaders(): Reader[]                      | Obtains available SE readers, which include all the SEs on the device.                                                               |
| openSession(): Session                 | Opens a session to connect to an SE in this reader. This API returns a session instance.                                                               |
| openLogicalChannel(aid: number[]): Promise\<Channel>                  | Opens a logical channel. This API returns a logical channel instance.                                                               |
| transmit(command: number[]): Promise\<number[]> | Transmits application protocol data units (APDUs) to this SE.                                                               |
| close(): void | Closes this channel.                                                           |


## How to Develop

### Accessing an SE
1. Import related modules.
2. Check whether the device supports SEs.
3. Access an SE and read or write data.
4. Release channel resources.
   
```ts
import { omapi } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

let seService : omapi.SEService;
let seReaders : omapi.Reader[];
let seSession : omapi.Session;
let seChannel : omapi.Channel;
let testSelectedAid : number[] = [0xA0, 0x00, 0x00, 0x00, 0x03, 0x10, 0x10];
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
    // Create an SEService instance for SE access.
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

    // Obtain all supported readers on the device, that is, the list of all SEs.
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

    // Select an SE (eSE or SIM card) for access based on the service requirements.
    let reader: (omapi.Reader | undefined);
    for (let i = 0; i < seReaders.length; ++i) {
      let r = seReaders[i];
      // Distinguish the SE by name, for example, eSE or SIM.
      if (r.getName().includes("SIM")) {
        reader = r;
        break;
      }
    }
    if (reader == undefined) {
      hilog.error(0x0000, 'testTag', 'no valid sim reader.');
      seService.shutdown();
      return;
    }
    hilog.info(0x0000, 'testTag', 'reader is %{public}s', reader?.getName());

    // Open a session on a specified SE instance.
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

    // Create a logical channel or basic channel via the session instance. Generally, the logical channel is used for access, as the basic channel may be restricted.
    try {
      // Change the value of testSelectedAid to the AID of the application that opens the logical channel.
      seChannel = await seSession.openLogicalChannel(testSelectedAid, p2);
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'openLogicalChannel exception %{public}s', JSON.stringify(exception));
    }

    if (seChannel == undefined) {
      hilog.error(0x0000, 'testTag', 'seChannel invalid.');
      seService.shutdown();
      return;
    }

    // Send APDUs to the SE over the logical channel. Set testApduData correctly based on actual service requirements, and ensue that the APDU format complies with the APDU specification.
    let testApduData = [0x01, 0x02, 0x03, 0x04];
    try {
      let response: number[] = await seChannel.transmit(testApduData);
      hilog.info(0x0000, 'testTag', 'seChannel.transmit() response = %{public}s.', JSON.stringify(response));
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'seChannel.transmit() exception = %{public}s.', JSON.stringify(exception));
    }

    // Close the channel to release resources when the SE access is complete.
    try {
      seChannel.close();
    } catch (exception) {
      hilog.error(0x0000, 'testTag', 'seChannel.close() exception = %{public}s.', JSON.stringify(exception));
    }

    // Close the service, and disable the binding relationship between the application and the SE service.
    seService.shutdown();
  }
}

```
