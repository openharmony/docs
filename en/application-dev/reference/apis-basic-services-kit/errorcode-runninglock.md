# Running Lock Error Codes

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 4900101 Service Connection Failure

**Error Message**

Failed to connect to the service.

**Description**

This error code is reported if a service connection failure occurs.

**Possible causes**

1. The system service stops running.

2. The internal communication of system services is abnormal.

**Solution**

Check whether the system services are running properly.

1. Run the following command on the console to view the current system service list:

    ```bash
    > hdc shell hidumper -ls
    ```

2. Check whether **PowerManagerService** is included in the system service list.
