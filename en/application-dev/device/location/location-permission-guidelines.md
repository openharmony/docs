# Applying for Location Permissions

## Scenario

Before using the capabilities provided by [Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md), check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user.

The system provides the following location permission:

- **ohos.permission.LOCATION**: used to obtain location accurate to meters.

- **ohos.permission.APPROXIMATELY\_LOCATION**: used to obtain location accurate to 5 kilometers.

- **ohos.permission.LOCATION_IN_BACKGROUND**: used to obtain location while the application is running at the background.

For details about the permissions required for each API of Location Kit, see [Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md).

## How to Develop

1. Declare the required permission in your application's configuration file. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

2. If your application needs to access the device location when running in the foreground, declare the location permission as described in the following table.

**Table 1** Description of location permissions

| Permission| Declarable or Not| Location Accuracy|
| -------- | -------- | -------- |
| ohos.permission.APPROXIMATELY_LOCATION| Yes| Location accurate to 5 kilometers.|
| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Yes| Location accurate to meters.|

3. If your application needs to access the device location when running in the background, declare the location permission as follows:

If your application needs to access the device location when running in the background, also request for the **ohos.permission.LOCATION_IN_BACKGROUND** permission or a continuous task of the LOCATION type in addition to the permission declared in step 2.

- A user can grant the **ohos.permission.LOCATION_IN_BACKGROUND** permission for an application on the **Settings** page. For details, see [ohos.permission.LOCATION_IN_BACKGROUND](../../security/AccessToken/permissions-for-all.md#ohospermissionlocation_in_background).

- For details about how to request for a continuous task, see [Continuous Task](../../task-management/continuous-task.md)<!--Del--> and [Continuous Task Development Example](../../performance/reasonable-running-backgroundTask.md#continuous-task)<!--DelEnd-->.
