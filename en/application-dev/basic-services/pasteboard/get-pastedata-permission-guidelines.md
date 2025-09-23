# Requesting Permissions to Access the Pasteboard
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong-->
<!--Adviser: @HelloCrease-->

## Overview

In API version 12 and later, permission control is added to the pasteboard reading API to enhance user privacy protection.

Related APIs:

| Name| Description                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| getData(callback: AsyncCallback&lt;PasteData&gt;): void | Reads a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.|
| getData(): Promise&lt;PasteData&gt; | Reads a **PasteData** object from the pasteboard. This API uses a promise to return the result.|
| getDataSync(): PasteData | Reads data from the system pasteboard. This API returns the result synchronously.|
| getUnifiedData(): Promise\<unifiedDataChannel.UnifiedData\> | Reads the data of a unified data object from the system pasteboard.|
| getUnifiedDataSync(): unifiedDataChannel.UnifiedData | Reads the data of a unified data object from the system pasteboard. This API returns the result synchronously.|
| OH_UdmfData* OH_Pasteboard_GetData (OH_Pasteboard *pasteboard, int *status) | Obtains data from the pasteboard.|
| getDataWithProgress(params: GetDataParams): Promise\<PasteData\> | Obtains the pasteboard data and paste progress. This API uses a promise to return the result. Folders cannot be copied.|
| OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params, int* status) | Obtains the pasteboard data and paste progress. Folders cannot be copied.|

## Accessing Pasteboard Content

Applications can access the pasteboard content in either of the following ways:

- Using security components

    Applications that use [security components](../../security/AccessToken/pastebutton.md) to access the pasteboard content do not need to request the permission.

    Applications that use the security components can access the pasteboard content without any adaptation.

- Requesting the ohos.permission.READ_PASTEBOARD permission

    ohos.permission.READ_PASTEBOARD is a restricted user_grant permission. Applications that use custom components can request this permission to access the pasteboard content with user authorization.

    How to request permissions:
    <!--RP1-->
    1. Request high-level permissions through [ACL](../../security/AccessToken/declare-permissions-in-acl.md).
    
    2. [Declare permissions](../../security/AccessToken/declare-permissions.md) in the **module.json5** configuration file.
    
    3. [Request user authorization](../../security/AccessToken/request-user-authorization.md) via a dialog box.
    <!--RP1End-->
