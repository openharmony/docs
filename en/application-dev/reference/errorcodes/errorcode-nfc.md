# NFC Error Codes

## 3100101

**Error Message**

NFC opening or closing state is abnormal in service.

**Description**

The NFC service fails to enable or disable NFC.

**Possible Causes**

Communication with the NFC service failed.

**Solution**

Enable or disable NFC again.

## 3100201

**Error Message**

Tag running state is abnormal in service.

**Description**

An error occurs when the NFC service executes the tag service logic.

**Possible Causes**
1. The tag parameters do not match the API to invoke.
2. The NFC is disabled.
3. The tag is disconnected before the tag operation.
4. The tag chip returns an error status or response timeout.
5. Binding with the NFC service has not been established.

**Solution**
1. Check whether the NFC parameters match the API to invoke.
2. Enable NFC for the device.
3. Connect to the tag and then perform the read and write operations.
4. Touch and read the card again.
5. Exit the app and read the card again.
