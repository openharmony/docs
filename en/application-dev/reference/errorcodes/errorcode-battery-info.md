# Battery Info Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 4600101 Service Connection Failure

**Error Message**

Operation failed. Cannot connect to service.

**Description**

This error code is reported if a service connection failure occurs.

**Possible Causes**

1. The system service stops running.

2. The internal communication of system services is abnormal.

**Procedure**

Check whether the system services are running properly.

1. Run the following command on the console to view the current system service list:

    ```bash
    > hdc shell hidumper -ls
    ```

2. Check whether **Battery-info** is included in the system service list.
