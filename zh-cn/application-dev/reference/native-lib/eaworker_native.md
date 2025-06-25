# EAWorker（独占线程任务执行器）(C/C++)
开发者可以通过[AttachCurrentThread](#attachcurrentthread)接口将当前线程提供给ArkTS1.2虚拟机，并获取静态虚拟机的env。开发者可以使用该env在当前执行特定重载/长时任务，避免对于ArkTS1.2虚拟机系统调用造成影响。任务完成后，开发者需要手动调用[DetachCurrentThread](#detachcurrentthread)释放对应的系统资源。

文档中涉及到概念以及解释：
- 互操作（interop）：ArkTS1.2和ArkTS1.1代码相互操作。由于ArkTS1.1运行时为单线程实例，因此支持互操作的EAWorker会持有不同的ArkTS1.1运行时实例用于执行ArkTS1.1字节码，对应的ArkTS1.1中全局变量在不同的线程中对应不同的实例。
- ANI：ArkTS1.2 Native Interface，ArkTS1.2的原生操作接口。

## AttachCurrentThread
ani_status AttachCurrentThread(ani_vm *vm, const ani_options *options, uint32_t version, ani_env **result)

将当前Native线程附加到ArkTS1.2虚拟机，并获取对应的ani_env指针，以便在该线程中执行特定任务。此操作允许Native线程使用虚拟机提供的功能调用ArkTS1.2函数。

**ArkTS版本：** 该接口仅适用于ArkTS1.2。

**参数：**
| 参数名         | 类型             | 必填         | 说明                                                                 |
|---------------|------------------|------------|----------------------------------------------------------------------|
| vm            | ani_vm*          | 是           | ArkTS1.2虚拟机实例句柄。                            |
| options     | ani_options*   | 是           | 用于控制创建的EAWorker是否支持interop。使用方式见示例。|
| version     | uint32_t       | 是           | ANI接口版本标识。                      |
| result      | ani_env**      | 是           | 输出参数，返回绑定成功的线程执行环境指针。   |


**返回值：**
| 类型         | 说明                         |
| ---------- | -------------------------- |
| ani_status | AttachCurrentThread接口调用的结果。<br>- ANI_OK表示接口调用成功。<br>- ANI_ERROR表示接口调用失败。<br>- ANI_INVALID_ARGS表示参数校验失败。<br>- ANI_INVALID_VERSION表示ANI版本校验失败。<br>- ANI_ALREADY_ATTACHED表示当前线程已经attach，开发者尝试重复attach同一个线程。 |

**示例：**

在Native侧将当前线程提供给虚拟机创建不支持interop的EAWorker。
```cpp
std::thread worker((){
	ani_env *workerEnv = nullptr;
	ani_options aniArgs {0, nullptr};
	
	auto status = vm_->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &workerEnv);
})
```

在Native侧将当前线程提供给虚拟机创建支持interop的EAWorker。
```cpp
std::thread worker((){
	ani_env *workerEnv = nullptr;
	ani_option interopEnabled {"--interop=enable", nullptr};
	ani_options aniArgs {1, &interopEnabled};
	
	auto status = vm_->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &workerEnv);
})
```

## DetachCurrentThread
ani_status DetachCurrentThread(ani_vm *vm)

解除当前Native线程与ArkTS1.2虚拟机的绑定关系，释放线程关联的虚拟机资源。必须与[AttachCurrentThread](#attachcurrentthread)严格配对使用。

> **说明：**
> 
> DetachCurrentThread会销毁虚拟机侧对应的资源，Detach之后开发者不应该在当前线程继续调用ArkTS1.2函数。

**ArkTS版本：** 该接口仅适用于ArkTS1.2。

**参数：**
| 参数名    | 类型         | 必填  | 说明                                                                 |
|-----------|--------------|-------|----------------------------------------------------------------------|
| vm      | ani_vm*    | 是    | 有效的ArkTS1.2虚拟机实例句柄。                        |

**返回值：**
| 类型         | 说明                         |
| ---------- | -------------------------- |
| ani_status | DetachCurrentThread接口调用的结果。<br>- ANI_OK表示接口调用成功。<br>- ANI_ERROR表示接口调用失败。<br>- ANI_INVALID_ARGS表示用户传入参数校验失败。<br>- ANI_ALREADY_DETACHED表示当前线程已经detach，开发者尝试重复detach同一个线程。 |

**示例：**

在Native侧销毁不支持interop的EAWorker。
```cpp
std::thread worker((){
	ani_env *workerEnv = nullptr;
	ani_options aniArgs {0, nullptr};
	
	auto status = vm_->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &workerEnv);
	
    status = vm_->DetachCurrentThread();
})
```

在Native侧销毁支持interop的EAWorker。
```cpp
std::thread worker((){
	ani_env *workerEnv = nullptr;
	ani_option interopEnabled {"--interop=enable", nullptr};
	ani_options aniArgs {1, &interopEnabled};
	
	auto status = vm_->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &workerEnv);
	
    status = vm_->DetachCurrentThread();
})
```