# @ohos.multimedia.systemSoundManager (System Sound Management)

The **systemSoundManager** module provides basic capabilities for managing system sounds, including setting and obtaining system ringtones and obtaining a player to play the system ringtone.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import systemSoundManager from '@ohos.multimedia.systemSoundManager';
```

## RingtoneType

Enumerates the ringtone types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name                           |  Value    | Description                                        |
| ------------------------------- | ------ | -------------------------------------------- |
| RINGTONE_TYPE_DEFAULT           | 0      | Default ringtone type.                                |
| RINGTONE_TYPE_MULTISIM          | 1      | Multi-SIM ringtone type.                             |

## systemSoundManager.getSystemSoundManager

getSystemSoundManager(): SystemSoundManager

Obtains a system sound manager.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type                         | Description        |
| ----------------------------- | ------------ |
| [SystemSoundManager](#systemsoundmanager) | System sound manager obtained.|

**Example**
```ts
let systemSoundManagerInstance: systemSoundManager.SystemSoundManager = systemSoundManager.getSystemSoundManager();
```

## SystemSoundManager

Provides APIs to manage system sounds. Before calling any API in **SystemSoundManager**, you must use [getSystemSoundManager](#systemsoundmanagergetsystemsoundmanager) to create a **SystemSoundManager** instance.

### setSystemRingtoneUri

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback&lt;void&gt;): void

Sets a URI for the system ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | Yes  | Application context.          |
| uri      | string                                   | Yes  | URI of the system ringtone. For details, see [media.AVPlayer](js-apis-media.md#avplayer9).|
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.    |
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result.    |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // Set the URI of the target ringtone file.
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.setSystemRingtoneUri(context, uri, type, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set system ringtone uri. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful setting of the system ringtone uri.`);
});
```

### setSystemRingtoneUri

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise&lt;void&gt;

Sets a URI for the system ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | Yes  | Application context.        |
| uri      | string                                   | Yes  | URI of the system ringtone. For details, see [media.AVPlayer](js-apis-media.md#avplayer9).|
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.  |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let uri = 'file://data/test.wav'; // Set the URI of the target ringtone file.
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.setSystemRingtoneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system ringtone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system ringtone uri ${err}`);
});
```

### getSystemRingtoneUri

getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback&lt;string&gt;): void

Obtains the URI of a system ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | Yes  | Application context.        |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.   |
| callback | AsyncCallback&lt;string&gt;              | Yes  | Callback used to return the ringtone URI obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.getSystemRingtoneUri(context, type, (err: BusinessError, value: string) => {
  if (err) {
    console.error(`Failed to get system ringtone uri. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone uri is obtained ${value}.`);
});
```

### getSystemRingtoneUri

getSystemRingtoneUri(context: Context, type: RingtoneType): Promise&lt;string&gt;

Obtains the URI of a system ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | Yes  | Application context.        |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.  |

**Return value**

| Type               | Description                               |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the ringtone URI obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;

systemSoundManagerInstance.getSystemRingtoneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system ringtone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone uri ${err}`);
});
```

### getSystemRingtonePlayer

getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback&lt;RingtonePlayer&gt;): void

Obtains a player to play the system ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                        |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | Context                                  | Yes  | Application context.           |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.|
| callback | AsyncCallback&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | Yes| Callback used to return the ringtone player obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

systemSoundManagerInstance.getSystemRingtonePlayer(context, type, (err: BusinessError, value: systemSoundManager.RingtonePlayer) => {
  if (err) {
    console.error(`Failed to get system ringtone player. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
});
```

### getSystemRingtonePlayer

getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise&lt;RingtonePlayer&gt;

Obtains a player to play the system ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                        |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | Context                                  | Yes  | Application context.           |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | Promise used to return the ringtone player obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let context: Context = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_DEFAULT;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

systemSoundManagerInstance.getSystemRingtonePlayer(context, type).then((value: systemSoundManager.RingtonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone player ${err}`);
});
```
