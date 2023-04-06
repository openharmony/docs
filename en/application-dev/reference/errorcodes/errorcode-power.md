# Power Manager Error Codes

## 4900101 Service Connection Failure

**Error Message**

Operation failed. Cannot connect to service.

**Description**

This error code is reported for a service connection failure.

**Possible Causes**

1. The system service stops running.

2. The internal communication of system services is abnormal.

**Solution**

Check whether the system services are running properly.

1. Run the following command on the console to view the current system service list:

    ```bash
    > hdc shell hidumper -ls
    ```

2. Check whether **PowerManagerService** is included in the system service list.

## 4900102 System Shuting Down

**Error Message**

Operation failed. System is shutting down.

**Description**

This error code is reported when an operation failed during system shutting down.

**Possible Causes**

The system is shutting down.

**Solution**

Make sure that the operation is performed when the system is running properly.
