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

| Name                           | Value | Description                                                                    |
| ------------------------------- |----|------------------------------------------------------------------------|
| RINGTONE_TYPE_DEFAULT<sup>(deprecated)</sup>           | 0  | Default ringtone type.<br> This enumerated value is deprecated since API version 11. You are advised to use **RINGTONE_TYPE_SIM_CARD_0** instead.|
| RINGTONE_TYPE_SIM_CARD_0<sup>11+</sup> | 0  | Ringtone of SIM card 1.                                                             |
| RINGTONE_TYPE_MULTISIM<sup>(deprecated)</sup>          | 1  | Multi-SIM ringtone type.<br> This enumerated value is deprecated since API version 11. You are advised to use **RINGTONE_TYPE_SIM_CARD_1** instead.|
| RINGTONE_TYPE_SIM_CARD_1<sup>11+</sup> | 1  | Ringtone of SIM card 2.                                                             |

## SystemToneType<sup>11+</sup>

Enumerates the system alert tone types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name                           | Value  | Description        |
| ------------------------------- |-----|------------|
| SYSTEM_TONE_TYPE_SIM_CARD_0           | 0   | SMS alert tone of SIM card 1.|
| SYSTEM_TONE_TYPE_SIM_CARD_1            | 1   | SMS alert tone of SIM card 2.|
| SYSTEM_TONE_TYPE_NOTIFICATION          | 32  | Notification alert tone.    |

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

### setSystemRingtoneUri<sup>(deprecated)</sup>

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback&lt;void&gt;): void

Sets a URI for a system ringtone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [setRingtoneUri](#setringtoneuri11) instead.

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

### setSystemRingtoneUri<sup>(deprecated)</sup>

setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise&lt;void&gt;

Sets a URI for a system ringtone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [setRingtoneUri](#setringtoneuri11) instead.

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

### getSystemRingtoneUri<sup>(deprecated)</sup>

getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback&lt;string&gt;): void

Obtains the URI of a system ringtone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getRingtoneUri](#getringtoneuri11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | Context                                  | Yes  | Application context.        |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.   |
| callback | AsyncCallback&lt;string&gt;              | Yes  | Callback used to return the URI obtained.|

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

### getSystemRingtoneUri<sup>(deprecated)</sup>

getSystemRingtoneUri(context: Context, type: RingtoneType): Promise&lt;string&gt;

Obtains the URI of a system ringtone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getRingtoneUri](#getringtoneuri11) instead.

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
| Promise&lt;string&gt; | Promise used to return the URI obtained.|

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

### getSystemRingtonePlayer<sup>(deprecated)</sup>

getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback&lt;RingtonePlayer&gt;): void

Obtains a player to play the system ringtone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getRingtonePlayer](#getringtoneplayer11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                        |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | Context                                  | Yes  | Application context.           |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.|
| callback | AsyncCallback&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | Yes| Callback used to return the player obtained.|

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

### getSystemRingtonePlayer<sup>(deprecated)</sup>

getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise&lt;RingtonePlayer&gt;

Obtains a player to play the system ringtone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getRingtonePlayer](#getringtoneplayer11) instead.

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
| Promise&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | Promise used to return the player obtained.|

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

### setRingtoneUri<sup>11+</sup>

setRingtoneUri(context: BaseContext, uri: string, type: RingtoneType): Promise&lt;void&gt;

Sets a URI for a system ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | BaseContext                                  | Yes  | Application context.        |
| uri      | string                                   | Yes  | URI of the system ringtone. For details, see [media.AVPlayer](js-apis-media.md#avplayer9).|
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.  |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400103 | I/O error. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let context: common.BaseContext = getContext(this);
let uri = 'file://data/test.wav'; // Set the URI of the target ringtone file.
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;

systemSoundManagerInstance.setRingtoneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system ringtone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system ringtone uri ${err}`);
});
```

### getRingtoneUri<sup>11+</sup>

getRingtoneUri(context: BaseContext, type: RingtoneType): Promise&lt;string&gt;

Obtains the URI of a system ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| context  | BaseContext                                  | Yes  | Application context.        |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.  |

**Return value**

| Type               | Description                               |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI obtained.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| -------- | --------------------- |
| 5400103  | I/O error. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;

systemSoundManagerInstance.getRingtoneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system ringtone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone uri ${err}`);
});
```

### getRingtonePlayer<sup>11+</sup>

getRingtonePlayer(context: BaseContext, type: RingtoneType): Promise&lt;RingtonePlayer&gt;

Obtains a player to play the system ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                        |
| -------- | -----------------------------------------| ---- | --------------------------- |
| context  | BaseContext                                  | Yes  | Application context.           |
| type     | [RingtoneType](#ringtonetype)            | Yes  | Type of the system ringtone.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;[RingtonePlayer](js-apis-inner-multimedia-ringtonePlayer.md#ringtoneplayer)&gt; | Promise used to return the player obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.RingtoneType = systemSoundManager.RingtoneType.RINGTONE_TYPE_SIM_CARD_0;
let systemRingtonePlayer: systemSoundManager.RingtonePlayer | undefined = undefined;

systemSoundManagerInstance.getRingtonePlayer(context, type).then((value: systemSoundManager.RingtonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system ringtone player is obtained.`);
  systemRingtonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone player ${err}`);
});
```

### setSystemToneUri<sup>11+</sup>

setSystemToneUri(context: BaseContext, uri: string, type: SystemToneType): Promise&lt;void&gt;

Sets a URI for a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                    |
| -------- |-------------------------------------| ---- | ------------------------ |
| context  | BaseContext                         | Yes  | Application context.        |
| uri      | string                              | Yes  | URI of the system alert tone. For details, see [media.AVPlayer](js-apis-media.md#avplayer9).|
| type     | [SystemToneType](#systemtonetype11) | Yes  | Type of the system alert tone.  |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400103 | I/O error. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let context: common.BaseContext = getContext(this);
let uri = 'file://data/test.wav'; // Set the URI of the target ringtone file.
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;

systemSoundManagerInstance.setSystemToneUri(context, uri, type).then(() => {
  console.info(`Promise returned to indicate a successful setting of the system tone uri.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the system tone uri ${err}`);
});
```

### getSystemToneUri<sup>11+</sup>

getSystemToneUri(context: BaseContext, type: SystemToneType): Promise&lt;string&gt;

Obtains the URI of a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                    |
| -------- |-------------------------------------| ---- | ------------------------ |
| context  | BaseContext                         | Yes  | Application context.        |
| type     | [SystemToneType](#systemtonetype11) | Yes  | Type of the system alert tone.  |

**Return value**

| Type               | Description                               |
| ------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI obtained.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400103 | I/O error. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;

systemSoundManagerInstance.getSystemToneUri(context, type).then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system tone uri is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone uri ${err}`);
});
```

### getSystemTonePlayer<sup>11+</sup>

getSystemTonePlayer(context: BaseContext, type: SystemToneType): Promise&lt;SystemTonePlayer&gt;

Obtains a player to play the system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                        |
| -------- |-------------------------------------| ---- | --------------------------- |
| context  | BaseContext                         | Yes  | Application context.           |
| type     | [SystemToneType](#systemtonetype11) | Yes  | Type of the system alert tone.|

**Return value**

| Type                                                                                              | Description                           |
|--------------------------------------------------------------------------------------------------| ------------------------------- |
| Promise&lt;[SystemTonePlayer](js-apis-inner-multimedia-systemTonePlayer.md#systemtoneplayer)&gt; | Promise used to return the player obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let context: common.BaseContext = getContext(this);
let type: systemSoundManager.SystemToneType = systemSoundManager.SystemToneType.SYSTEM_TONE_TYPE_SIM_CARD_0;
let systemTonePlayer: systemSoundManager.SystemTonePlayer | undefined = undefined;

systemSoundManagerInstance.getSystemTonePlayer(context, type).then((value: systemSoundManager.SystemTonePlayer) => {
  console.info(`Promise returned to indicate that the value of the system tone player is obtained.`);
    systemTonePlayer = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone player ${err}`);
});
```
