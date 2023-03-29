# workScheduler Error Codes

## 9700001 Memory Operation Failure

**Error Message**

Memory operation failed.

**Possible Causes**

1. A memory leak occurs.
2. The system memory is insufficient.

**Solution**

1. Release the memory.
2. Check whether memory leak occurs.

## 9700002 Parcel Operation Failure

**Error Message**

Parcel operation failed.

**Possible Causes**

An exception occurs when invoking the **MessageParcel** object to read or write an object.

**Solution**

Try again later or restart the device.

## 9700003 System Service Failure

**Error Message**

System service operation failed.

**Possible Causes**

1. The system service is not started.
2. The system service is abnormal.

**Solution**

Try again later or restart the device.

## 9700004 workInfo Verification Failure

**Error Message**

Checking workInfo failed.

**Possible Causes**

1. The value of **bundleName** in **workInfo** does not match the UID of the application.
2. The Work Scheduler task to cancel or query does not exist.

**Solution**

Check the **workInfo** parameters.

## 9700005 startWork Failure

**Error Message**

StartWork failed.

**Possible Causes**

1. The Work Scheduler task already exists.
2. The application has already requested 10 Work Scheduler tasks.
3. The repeat interval of a Work Scheduler task must be at least 20 minutes.

**Solution**

Check the input parameters and application code.
