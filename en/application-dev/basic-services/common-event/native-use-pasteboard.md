# Using the Pasteboard to Copy and Paste (C/C++)

## When to Use

The pasteboard allows you to copy and paste data of the plain text, hypertext, and URI.

## Basic Concepts

- **OH_PasteboardObserver**: pasteboard observer object, which is used to listen for data changes on the pasteboard.
- **OH_Pasteboard**: pasteboard object, which is used to query and write.
- **OH_UdmfData**: unified data object.

## Constraints

- The pasteboard content, including system service metadata and application settings, has a maximum size of 128 MB by default. For PCs/2-in-1 devices, the maximum size can be changed through system settings, with a valid range from 128 MB to 2 GB.
- To ensure the accuracy of the pasteboard data, only one copy can be performed at a time.
- Currently, supported data types include **OH_UdsPlainText** (plain text), **OH_UdsHtml** (hypertext markup language), **OH_UdsFileUri** (file URI). **OH_UdsPixelMap** (pixel map), **OH_UdsHyperlink** (hyperlink), **OH_UdsAppItem** (application icon), and custom type. The data types supported by JS APIs are different from those supported by NDK APIs. You need to match the data types with the corresponding APIs during usage. For details, see [Using the Pasteboard to Copy and Paste](../pasteboard/use_pasteboard_to_copy_and_paste.md).
- When you copy and paste data of a custom type, the specified type name cannot be the same as an existing one.
- Since API version 12, [permission control](get-pastedata-permission-guidelines.md) is added to the pasteboard reading API to enhance user privacy protection.
- The copy and paste APIs, [setUnifiedData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#setunifieddata12) and [getUnifiedData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12), added in API version 12 are independent of the **OH_Pasteboard_SetData** and **OH_Pasteboard_GetData** APIs mentioned in this topic. Use the corresponding APIs when writing and reading data.

## Available APIs

For details about more APIs and their usage, see [Pasteboard](../../reference/apis-basic-services-kit/capi-pasteboard.md).

| API                                                    | Description                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| OH_PasteboardObserver* OH_PasteboardObserver_Create()        | Creates a pasteboard observer object.                     |
| OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer) | Destroys the pasteboard observer object.                         |
| int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context, const Pasteboard_Notify callback, const Pasteboard_Finalize finalize) | Sets the callback used to return data changes to the pasteboard observer object. |
| OH_Pasteboard* OH_Pasteboard_Create()                        | Creates a pasteboard instance.                                   |
| void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard)        | Destroys the pasteboard instance.                                       |
| int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer) | Subscribes to the pasteboard observer.                                 |
| int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer) | Unsubscribes from the pasteboard observer.                           |
| bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard)   | Checks whether the pasteboard data comes from remote devices.                   |
| int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len) | Obtains the pasteboard data source.                             |
| bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type) | Checks whether the pasteboard contains data of the specified type.                     |
| bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard)        | Checks whether the pasteboard contains data.                               |
| OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status) | Obtains data from the pasteboard.                                   |
| int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data) | Writes data to the pasteboard.                                   |
| int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard)       | Clears data from the pasteboard.                                   |
| void (\*Pasteboard_Notify)(void\* context, Pasteboard_NotifyType type) | Notifies data changes in the pasteboard.                             |
| void (\*Pasteboard_Finalize)(void\* context)                 | Releases context resources when the pasteboard observer object is destroyed.|

## How to Develop

1. Add dynamic link libraries.

   ```CMake
   # Add the following libraries to **CMakeLists.txt**.
   libudmf.so
   libpasteboard.so
   ```

2. Include header files.

   ```c
   #include <cstdio>
   #include <database/pasteboard/oh_pasteboard.h>
   #include <database/udmf/udmf.h>
   #include <database/udmf/uds.h>
   ```

3. Define the callback for listening for pasteboard data changes.

   ```c
   // Define the callback for notifying data changes in the pasteboard.
   static void Pasteboard_Notify_impl2(void* context, Pasteboard_NotifyType type)
   {
     printf("Pasteboard_NotifyType, type: %d", type);
   }
   // Define the callback for notifying when the pasteboard observer object is destroyed.
   static void Pasteboard_Finalize_impl2(void* context)
   {
     printf("callback: Pasteboard_Finalize");
   }
   ```

4. Subscribe to the pasteboard observer.

   ```c
   // 1. Create a pasteboard instance.
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   // 2. Create a pasteboard observer instance.
   OH_PasteboardObserver* observer = OH_PasteboardObserver_Create();
   // 3. Set two callbacks to the pasteboard observer instance.
   OH_PasteboardObserver_SetData(observer, (void* )pasteboard, Pasteboard_Notify_impl2, Pasteboard_Finalize_impl2);
   // 4. Subscribe to local data changes on the pasteboard.
   OH_Pasteboard_Subscribe(pasteboard, NOTIFY_LOCAL_DATA_CHANGE, observer);
   ```

5. Write data to the pasteboard.

   ```c
   // 1. Create a pasteboard instance.
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   
   // 2. Create an OH_UdmfRecord object and add text data to it.
   OH_UdsPlainText* plainText = OH_UdsPlainText_Create();
   OH_UdsPlainText_SetContent(plainText, "Hello world!");
   OH_UdmfRecord* record = OH_UdmfRecord_Create();
   OH_UdmfRecord_AddPlainText(record, plainText);
   
   // 3. Create an OH_UdmfData object and add OH_UdmfRecord to it.
   OH_UdmfData* data = OH_UdmfData_Create();
   OH_UdmfData_AddRecord(data, record);
   
   // 4. Write data to the pasteboard.
   OH_Pasteboard_SetData(pasteboard, data);
   
   // 5. Destroy the pointer when the object is no longer required.
   OH_UdsPlainText_Destroy(plainText);
   OH_UdmfRecord_Destroy(record);
   OH_UdmfData_Destroy(data);
   OH_Pasteboard_Destroy(pasteboard);
   ```

6. Read data from the pasteboard.

   ```c
   // 1. Create a pasteboard instance.
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   // 2. Check whether the pasteboard contains text data.
   bool hasPlainTextData = OH_Pasteboard_HasType(pasteboard, "text/plain");
   if (hasPlainTextData) {
     // 3. Obtain the unified data OH_UdmfData from the pasteboard.
     int ret = 0;
     OH_UdmfData* udmfData = OH_Pasteboard_GetData(pasteboard, &ret);
     // 4. Obtain the first data record from OH_UdmfData.
     OH_UdmfRecord* record = OH_UdmfData_GetRecord(udmfData, 0);
     // 5. Obtain the text data from the data record.
     OH_UdsPlainText* plainText = OH_UdsPlainText_Create();
     OH_UdmfRecord_GetPlainText(record, plainText);
     const char* content = OH_UdsPlainText_GetContent(plainText);
     printf("Get plain text success. content: %s", content);
     // 5. Destroy the pointer when the object is no longer required.
     OH_UdsPlainText_Destroy(plainText);
     OH_UdmfData_Destroy(udmfData);
   }
   OH_Pasteboard_Destroy(pasteboard);
   ```

 <!--no_check--> 