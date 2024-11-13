# 内存管理purgeable内存开发指导

## 场景介绍

OpenHarmony提供Purgeable Memory内存管理机制，开发者可以使用相关接口创建PurgeableMemory对象，从而管理purgeable内存。


开发者可以通过本指导了解在OpenHarmony应用中，如何使用Native层相关接口操作purgeable内存。功能包括purgeable内存的申请、释放等。


针对Purgeable Memory内存管理机制，常见的开发场景如下：

* 通过该机制提供的`NAPI`接口申请管理PurgeableMemory对象，并将数据内容写入该对象。
* 使用完毕后释放。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_PurgeableMemory \*OH_PurgeableMemory_Create(size_t size, OH_PurgeableMemory_ModifyFunc func, void \*funcPara) | 创建PurgeableMemory对象，每次调用都会产生一个新的PurgeableMemory对象。 | 
| bool OH_PurgeableMemory_Destroy(OH_PurgeableMemory \*purgObj) | 对PurgeableMemory对象进行析构操作。 | 
| bool OH_PurgeableMemory_BeginRead(OH_PurgeableMemory \*purgObj) | 对PurgeableMemory对象进行读访问。 | 
| void OH_PurgeableMemory_EndRead(OH_PurgeableMemory \*purgObj) | 读操作结束，将PurgeableMemory对象的引用计数减1，当引用计数为0的时候， 该PurgeableMemory对象可以被系统回收。 | 
|bool OH_PurgeableMemory_BeginWrite(OH_PurgeableMemory \*purgObj) | 对PurgeableMemory对象进行写访问。|
|void OH_PurgeableMemory_EndWrite(OH_PurgeableMemory \*purgObj)|写操作结束，将PurgeableMemory对象的引用计数减1，当引用计数为0的时候，该PurgeableMemory对象可以被系统回收。|
|void \*OH_PurgeableMemory_GetContent(OH_PurgeableMemory \*purgObj)|获取PurgeableMemory对象内存数据。|
|size_t OH_PurgeableMemory_ContentSize(OH_PurgeableMemory \*purgObj)|获取PurgeableMemory对象内存数据大小。|
|bool OH_PurgeableMemory_AppendModify(OH_PurgeableMemory \*purgObj, OH_PurgeableMemory_ModifyFunc func, void \*funcPara)|添加PurgeableMemory对象的修改方法。|


## Purgeable Memory应用开发步骤

以下步骤描述了在**OpenHarmony**中如何使用`Purgeable Memory`提供的`NAPI`接口，申请PurgeableMemory对象，并将内容写入PurgeableMemory对象后，对相应对象进行读写访问。

1. 声明PurgeableMemory对象创建规则。
    ```c++
    // 声明构建函数的参数
    struct ParaData{
        int start;
        int end;
    };

    // 声明一个使用ModifyFunc
    bool FactorialFunc(void* data, size_t size, void* param){
        bool ret = true;
        ParaData *pdata = (ParaData*) param;
        int* oriData = (int*)data;
        int i = pdata->start;
        while(i<pdata->end){
            *oriData *= i;
            i++;
        }
        return ret;
    }

    // 声明修改PurgeableMemory对象扩展函数的参数
    struct AppendParaData{
        int newPara;
    };

    // 声明修改PurgeableMemory对象的扩展函数
    bool AddFunc(void* data, size_t size, void* param){
        bool ret = true;
        int *oriDatap = (int*) data;
        AppendParaData* apData = (AppendParaData*)param;
        *oriDatap += apData->newPara;
        return ret;
    }
    ```
2. 创建PurgeableMemory对象。
    ```c++
    // 声明一个4MB的PurgeableMemory对象大小
    #define DATASIZE (4 * 1024 * 1024)

    // 声明创建函数的参数
    struct ParaData pdata = {1,2};

    // 创建一个PurgeableMemory对象
    OH_PurgeableMemory* pPurgmem = OH_PurgeableMemory_Create(DATASIZE, FactorialFunc, &pdata);
    ```

3. 读访问PurgeableMemory对象。
    ```c++
    //业务定义对象类型
    class ReqObj;

    // 读取对象
    if(OH_PurgeableMemory_BeginRead(pPurgmem)) {
        // 获取PurgeableMemory对象大小
        size_t size = OH_PurgeableMemory_ContentSize(pPurgmem);

        // 获取PurgeableMemory对象内容
        ReqObj* pReqObj = (ReqObj*) OH_PurgeableMemory_GetContent(pPurgmem);

        // 读取PurgeableMemory对象结束
        OH_PurgeableMemory_EndRead(pPurgmem);
    }
    ```

4. 写访问PurgeableMemory对象。
    ```c++
     //业务定义对象类型
    class ReqObj;

    // 修改PurgeableMemory对象
    if(OH_PurgeableMemory_BeginWrite(pPurgmem)) {
        // 获取PurgeableMemory对象数据
        ReqObj* pReqObj = (ReqObj*) OH_PurgeableMemory_GetContent(pPurgmem);

        // 声明扩展创建函数的参数
        struct AppendParaData apdata = {1};

        // 更新PurgeableMemory对象重建规则
        OH_PurgeableMemory_AppendModify(pPurgmem, AddFunc, &apdata);

        // 修改PurgeableMemory对象结束
        OH_PurgeableMemory_EndWrite(pPurgmem);
    }
    ```

5. 销毁PurgeableMemory对象。
    ```c++
    // 销毁对象
    OH_PurgeableMemory_Destroy(pPurgmem);
    // 置空指针防止UAF
    pPurgmem = nullptr;
    ```