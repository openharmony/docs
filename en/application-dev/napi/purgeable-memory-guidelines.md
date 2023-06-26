# Purgeable Memory Development

## When to Use

You can use the native purgeable memory APIs to apply for and release purgeable memory.


The following scenarios are common for native purgeable memory development:

* Apply for a **PurgeableMemory** object and write data to the object.
* Release the **PurgeableMemory** object when it is no longer required.

## Available APIs

| API| Description| 
| -------- | -------- |
| OH_PurgeableMemory \*OH_PurgeableMemory_Create(size_t size, OH_PurgeableMemory_ModifyFunc func, void \*funcPara) | Creates a **PurgeableMemory** object. A new **PurgeableMemory** object is generated each time this API is called.| 
| bool OH_PurgeableMemory_Destroy(OH_PurgeableMemory \*purgObj) | Destroys a **PurgeableMemory** object.| 
| bool OH_PurgeableMemory_BeginRead(OH_PurgeableMemory \*purgObj) | Begins a read operation on a **PurgeableMemory** object.| 
| void OH_PurgeableMemory_EndRead(OH_PurgeableMemory \*purgObj) | Ends a read operation on a **PurgeableMemory** object and decreases the reference count of the object by 1. When the reference count reaches 0, the object can be reclaimed by the system.| 
|bool OH_PurgeableMemory_BeginWrite(OH_PurgeableMemory \*purgObj) | Begins a write operation on a **PurgeableMemory** object.|
|void OH_PurgeableMemory_EndWrite(OH_PurgeableMemory \*purgObj)|Ends a write operation on a **PurgeableMemory** object and decreases the reference count of the object by 1. When the reference count reaches 0, the object can be reclaimed by the system.|
|void \*OH_PurgeableMemory_GetContent(OH_PurgeableMemory \*purgObj)|Obtains the memory data of a **PurgeableMemory** object.|
|size_t OH_PurgeableMemory_ContentSize(OH_PurgeableMemory \*purgObj)|Obtains the memory data size of a **PurgeableMemory** object.|
|bool OH_PurgeableMemory_AppendModify(OH_PurgeableMemory \*purgObj, OH_PurgeableMemory_ModifyFunc func, void \*funcPara)|Adds a function for modifying a **PurgeableMemory** object.|


## How to Develop

The following steps describe how to use the native purgeable memory APIs to apply for a **PurgeableMemory** object, write data to the object, and read data from the object.

1. Declare the rules for creating a **PurgeableMemory** object.
    ```c++
    // Declare the parameters of the constructor.
    struct ParaData{
        int start;
        int end;
    }

    // Declare a function for modifying the object.
    bool FactorialFunc(void* data, size_t size, void* param){
         bool ret = true;
         int oriData = *(int*)(data);
         int i = param->start;
         while(i<param->end){
            oriData *= i;
         }
         *data = oriData;
         if(oriData < 0)
            ret = false;
         return ret;
    }

    // Declare the parameters of the extended function for modifying the object.
    struct AppendParaData{
        int newPara;
    }

    // Declare the extended function for modifying the object.
    bool AddFunc(void* data, size_t size, void* param){
         bool ret = true;
         int oriData = *(int*)(data);
         oriData += param->newPara;
         *data = oriData;
         return ret;
    }
    ```
2. Create a **PurgeableMemory** object.
    ```c++
    // Define the memory data size to 4 MB.
    #define DATASIZE (4 * 1024 * 1024)

    // Declare the parameters of the constructor.
    struct ParaData pdata = {1,2};

    // Create a PurgeableMemory object.
    OH_PurgableMmory* pPurgmem = OH_PurgableMmory_Create(DATASIZE, FactorialFunc, &pdata);
    ```

3. Perfrom a read operation on the **PurgeableMemory** object.
    ```c++
    // Begin a read operation on the object.
    OH_PurgeableMemory_BeginRead(pPurgmem);

    // Obtain the object size.
    size_t size = OH_PurgeableMemory_ContentSize(pPurgmem);

    // Obtain the object content.
    ReqObj* pReqObj = (ReqObj*) OH_PurgeableMemory_GetContent(pPurgmem);

    // End a read operation on the object.
    OH_PurgeableMemory_EndRead(pPurgmem);
    ```

4. Perform a write operation on the **PurgeableMemory** object.
    ```c++
    // Begin a write operation on the object.
    OH_PurgeableMemory_BeginWrite(pPurgmem)

    // Obtain the object data.
    ReqObj* pReqObj = (ReqObj*) OH_PurgeableMemory_GetContent(pPurgmem);

    // Declare the parameters of the extended constructor.
    struct AppendParaData apdata = {1};

    // Update the rules for recreating the object.
    OH_PurgeableMemory_AppendModify(pPurgmem, AddFunc, &apdata);

    // Stop writing data to the object.
    OH_PurgeableMemory_EndWrite(pPurgmem);
    ```

5. Destroy the **PurgeableMemory** object.
    ```c++
    // Destroy the object.
    OH_PurgeableMemory_Destroy(pPurgmem);
    ```
