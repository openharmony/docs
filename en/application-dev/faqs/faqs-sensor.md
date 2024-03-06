# Pan-Sensor Development


## Are the APIs used for obtaining PPG and ECG sensor data open to individual developers? (API version 9)

Data collected by the PPG and ECG sensors of wearable devices is personal privacy data. Therefore, relative APIs are not open to individual developers.


## What should I do when error code 201 is reported during the calling of a vibrator API? (API version 9)

**Symptom**

The following error message (error code 201) is reported when an API of the vibrator module is called:

vibrate fail, error.code: 201error.message: NaN

**Solution**

Permission verification failed. You must apply for the **ohos.permission.VIBRATE** permission.

**References**

[Declaring Permissions](../security/AccessToken/declare-permissions.md)
