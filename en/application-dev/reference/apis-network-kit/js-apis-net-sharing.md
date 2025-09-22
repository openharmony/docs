# @ohos.net.sharing (Network Sharing)

This module allows you to share your device's network connectivity with other connected devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import { sharing } from '@kit.NetworkKit';
```

## NetHandle

type NetHandle = connection.NetHandle

Defines the handle of the data network. Before calling the **NetHandle** function, call the **getNetHandle** function to obtain a **NetHandle** object.

**System capability**: SystemCapability.Communication.NetManager.Core

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| [connection.NetHandle](./js-apis-net-connection.md#nethandle) | Network connection information.|
