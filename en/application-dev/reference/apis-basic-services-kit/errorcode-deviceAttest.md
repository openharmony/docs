# Device Attestation Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 20000001 System Service Abnormal

**Error Information**

System service exception, please try again or reboot your device.

**Description**

System service error. Try again or restart the device.

**Possible Causes**

1. The system service stops running.

2. The internal communication of system services is abnormal.

**Solution**

Check whether the system services are running properly.

1. Run the following command on the console to view the current system service list:

    ```bash
    > hdc shell hidumper -ls
    ```

2. Check whether **devattest_service** is present on the system service list.
