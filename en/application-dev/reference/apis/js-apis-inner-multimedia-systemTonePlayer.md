# systemTonePlayer (System Alert Tone Player)

The systemTonePlayer module provides APIs for playing and configuring SMS alert tones and notification alert tones and obtaining related information.

This module must work with [@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager.md) to manage system alert tones.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import systemSoundManager from '@ohos.multimedia.systemSoundManager';
```

## SystemToneOptions

Describes the options of system alert tones.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name     | Type           | Mandatory| Description                       |
| --------- | -------------- |---|---------------------------|
| muteAudio | boolean | No| Whether the sound is muted. The value **true** means that the sound is muted, and **false** means the opposite.|
| muteHaptics | boolean | No| Whether haptics feedback is turned off. The value **true** means that haptics feedback is turned off, and **false** means the opposite.|

## SystemTonePlayer

Implements APIs for playing and configuring SMS alert tones and notification alert tones and obtaining related information. Before calling any API in **SystemTonePlayer**, you must use [getSystemTonePlayer](js-apis-systemSoundManager.md#getsystemtoneplayer11) to create a **SystemTonePlayer** instance.

### getTitle

getTitle(): Promise&lt;string&gt;

Obtains the title of a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type                 | Description                             |
| --------------------- | -------------------------------- |
| Promise&lt;string&gt; | Promise used to return the title obtained.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400103 | I/O error. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

systemTonePlayer.getTitle().then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system tone player title is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone player title ${err}`);
});
```

### prepare

prepare(): Promise&lt;void&gt;

Prepares to play a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400102 | Operation not allowed. |
| 5400103 | I/O error. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

systemTonePlayer.prepare().then(() => {
  console.info(`Promise returned to indicate a successful prepareing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to prepareing system tone player. ${err}`);
});
```

### start

start(toneOptions?: SystemToneOptions): Promise&lt;number&gt;

Starts playing a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- |-----------------------------------------|--| ------------------------- |
| toneOptions  | [SystemToneOptions](#systemtoneoptions) | No| Options of the system alert tone.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the stream ID.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400102 | Operation not allowed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

class SystemToneOptions {
  muteAudio: boolean = false;
  muteHaptics: boolean = false;
}
let systemToneOptions: SystemToneOptions = {muteAudio: true, muteHaptics: false};

systemTonePlayer.start(systemToneOptions).then((value: number) => {
  console.info(`Promise returned to indicate that the value of the system tone player streamID is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start system tone player. ${err}`);
});
```

### stop

stop(id: number): Promise&lt;void&gt;

Stops playing a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- |-----------------------------------------|--| ------------------------- |
| id  | number | Yes| Stream ID returned by **start()**.|

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message             |
| ------- | --------------------- |
| 5400102 | Operation not allowed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let streamID: number = 0; // streamID is the stream ID returned by start(). Only initialization is performed here.
systemTonePlayer.stop(streamID).then(() => {
  console.info(`Promise returned to indicate a successful stopping of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop system tone player. ${err}`);
});
```

### release

release(): Promise&lt;void&gt;

Releases the system alert tone player. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

systemTonePlayer.release().then(() => {
  console.info(`Promise returned to indicate a successful releasing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release system tone player. ${err}`);
});
```
