# Purgeable Memory Development

<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @fang-jinxu-->
<!--Designer: @lingminghw-->
<!--Tester: @RayShih-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=84e5c687623c619df721fa927b62d6782396d98d translatedAt=2026-08-04T13:30:03.048Z pushedAt=2026-08-05T08:18:40.201Z -->

Purgeable Memory refers to memory that can be discarded at any time. This memory area is used to store data that can be easily reconstructed through recalculation. The data can be directly released when the system is low on memory and reconstructed when the user accesses it again. Purgeable Memory is suitable for storing large blocks (at least 4 KB) of data with low recovery cost. It is reclaimed with priority when the system is under high memory pressure (here, it refers to dropping anonymous pages in a manner similar to file pages, rather than compressing them). When used again, the user needs to restore the data themselves before use.

## When to Use

OpenHarmony provides a Purgeable Memory management mechanism. You can use related APIs to create PurgeableMemory objects to manage Purgeable Memory.

This guide describes how to use related Native APIs to operate Purgeable Memory in OpenHarmony applications. The supported operations include requesting and releasing Purgeable Memory.

Common development scenarios for the Purgeable Memory management mechanism are as follows:

1. Use related Native APIs provided by this mechanism to request and manage a **PurgeableMemory** object, and write data content to the object.

2. Release the **PurgeableMemory** object after it is no longer used.

## Available APIs

| Name | Description |
| -------- | -------- |
| OH_PurgeableMemory *OH_PurgeableMemory_Create(size_t size, OH_PurgeableMemory_ModifyFunc func, void *funcPara) | Creates a PurgeableMemory object. Each call produces a new PurgeableMemory object. |
| bool OH_PurgeableMemory_Destroy(OH_PurgeableMemory *purgObj) | Destroys a PurgeableMemory object. |
| bool OH_PurgeableMemory_BeginRead(OH_PurgeableMemory *purgObj) | Begins read access to a PurgeableMemory object and increments the read reference count by 1. |
| void OH_PurgeableMemory_EndRead(OH_PurgeableMemory *purgObj) | Ends the read operation and decrements the read reference count of the PurgeableMemory object by 1. |
| bool OH_PurgeableMemory_BeginWrite(OH_PurgeableMemory *purgObj) | Begins write access to a PurgeableMemory object and increments the write reference count by 1. |
| void OH_PurgeableMemory_EndWrite(OH_PurgeableMemory *purgObj) | Ends the write operation and decrements the write reference count of the PurgeableMemory object by 1. |
| void *OH_PurgeableMemory_GetContent(OH_PurgeableMemory *purgObj) | Obtains the memory data pointer of a PurgeableMemory object. Returns a `void*` type, which must be cast to the actual data type when used. |
| size_t OH_PurgeableMemory_ContentSize(OH_PurgeableMemory *purgObj) | Obtains the memory data size of a PurgeableMemory object. |
| bool OH_PurgeableMemory_AppendModify(OH_PurgeableMemory *purgObj, OH_PurgeableMemory_ModifyFunc func, void *funcPara) | Adds a modify method for the PurgeableMemory object. |

## How to Develop

The following steps describe how to use the Native APIs provided by `Purgeable Memory` in **OpenHarmony** to request a PurgeableMemory object, write content to the object, and then perform read and write access on the object.

1. Declare the creation rules for the **PurgeableMemory** object.

    ```c++
    // Declare parameters for the constructor function.
    struct ParaData{
        int start;
        int end;
    };

    // Declare a function that uses ModifyFunc (example: factorial function).
    bool FactorialFunc(void* data, size_t size, void* param){
        bool ret = true;
        ParaData *pdata = (ParaData*) param;
        int* oriData = (int*)data;
        // Initialize to 1 for factorial calculation.
        *oriData = 1;
        int i = pdata->start;
        while (i <= pdata->end) {
            *oriData *= i;
            i++;
        }
        return ret;
    }

    // Declare parameters for the PurgeableMemory object append-modify function.
    struct AppendParaData{
        int newPara;
    };

    // Declare the extension function for modifying the PurgeableMemory object.
    bool AddFunc(void* data, size_t size, void* param){
        bool ret = true;
        int *oriDatap = (int*) data;
        AppendParaData* apData = (AppendParaData*)param;
        *oriDatap += apData->newPara;
        return ret;
    }
    ```

2. Create a **PurgeableMemory** object.

    ```c++
    // Define a 4 MB PurgeableMemory object size.
    #define DATASIZE (4 * 1024 * 1024)

    // Declare the parameters for the create function.
    struct ParaData pdata = {1,2};

    // Create a PurgeableMemory object.
    OH_PurgeableMemory* pPurgmem = OH_PurgeableMemory_Create(DATASIZE, FactorialFunc, &pdata);
    ```

3. Perform read access on the **PurgeableMemory** object.

    ```c++
    // Business-defined object type. Add member variables and methods in the business code.
    class ReqObj {
    };

    // Read the object.
    if(OH_PurgeableMemory_BeginRead(pPurgmem)) {
        // Obtain the size of the PurgeableMemory object.
        size_t size = OH_PurgeableMemory_ContentSize(pPurgmem);

        // Obtain the content of the PurgeableMemory object. Ensure that the object content is initialized before use.
        ReqObj* pReqObj = reinterpret_cast<ReqObj*>(OH_PurgeableMemory_GetContent(pPurgmem));

        // End reading the PurgeableMemory object.
        OH_PurgeableMemory_EndRead(pPurgmem);
    }
    ```

4. Perform write access on the **PurgeableMemory** object.

    ```c++
    // Business-defined object type. Add member variables and methods in the business code.
    class ReqObj {
    };

    // Modify the PurgeableMemory object.
    if(OH_PurgeableMemory_BeginWrite(pPurgmem)) {
        // Obtain the data of the PurgeableMemory object.
        ReqObj* pReqObj = reinterpret_cast<ReqObj*>(OH_PurgeableMemory_GetContent(pPurgmem));

        // Define and initialize the parameters of the extended modification function.
        struct AppendParaData apdata = {1};

        // Update the rebuild rules of the PurgeableMemory object.
        OH_PurgeableMemory_AppendModify(pPurgmem, AddFunc, &apdata);

        // End the modification of the PurgeableMemory object.
        OH_PurgeableMemory_EndWrite(pPurgmem);
    }
    ```

5. Destroy the **PurgeableMemory** object.

    ```c++
    // Destroy the object.
    OH_PurgeableMemory_Destroy(pPurgmem);
    // Set the pointer to null to prevent dangling pointer access.
    pPurgmem = nullptr;
    ```