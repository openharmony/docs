# Performing Asset Operations in Specified User Space (for System Applications Only)

For a singleton application that provides system-wide management functionalities, all users share an instance, which isolates data of different users. You need to specify the user space to which the operated asset belongs when:

1. When multiple users are active at the same time, the singleton application must notify the user space to which the asset to be operated belongs so that the asset can be stored, accessed, and destroyed in the user space.
2. When storing assets accessible after the device is first unlocked or accessible when the device is unlocked, the singleton application must specify the user space to which the assets belong.

To implement isolation and access control of the assets for singleton applications, ASSET provides a set of APIs for asset operations with the user space specified. These APIs are available only for system applications.

## Constraints

The caller must have the ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS permission.

For details about how to request the permission, see [Requesting Permissions for system_basic Applications](../AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

## Available APIs

The following table describes the APIs.

| API| Description| API with User Space Not Specified<br> |
| -------- | -------- | ----------|
| [addAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetaddasuser)              |   Adds an asset to the specified user space. This API uses a promise to return the result.          |  [add](asset-js-add.md)             |
| [removeAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetremoveasuser)              |   Removes one or more assets from the specified user space. This API uses a promise to return the result.          |  [remove](asset-js-remove.md)             |
| [updateAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetupdateasuser)              |   Updates an asset in the specified user space. This API uses a promise to return the result.          |  [update](asset-js-update.md)             |
| [preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)              |   Performs preprocessing for the asset query in the specified user space. This API is used when user authentication is required for the access to the asset. This API must be used with [queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser) and [postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser) together. This API uses a promise to return the result.          |  [preQuery](asset-js-query-auth.md)             |
| [queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)              |   Queries one or more assets in the specified user space. If user authentication is required before accessing the asset, call [preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser) before this API and call [postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser) after this API. This API uses a promise to return the result.          |  [query](asset-js-query-auth.md) if user authentication is required before the asset is accessed.<br>[query](asset-js-query.md) if the asset can be accessed without user authentication.           |
| [postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)              |   Performs postprocessing for the asset query in the specified user space. This API is used when user authentication is required for the access to the asset. This API must be used with [preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser) together. This API uses a promise to return the result.          |  [postQuery](asset-js-query-auth.md)            |
