# Pan-Sensor Development

## Are the APIs used for obtaining PPG and ECG sensor data open to individual developers?

Applicable to: OpenHarmony 3.1 Beta5 (API version 9)

Data collected by the PPG and ECG sensors of wearable devices is personal privacy data. Therefore, relative APIs are not open to individual developers.

## What should I do when error code 201 is reported during the calling of a vibrator API?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

**Symptom**

The following error message (error code 201) is reported when an API of the vibrator module is called:

vibrate fail, error.code: 201error.message: NaN

**Solution**

Permission verification failed. You must apply for the **ohos.permission.VIBRATE** permission.

**Reference**

[Applying for Permissions](../security/accesstoken-guidelines.md)