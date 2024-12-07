# GC

Garbage Collection (GC) is the process of finding garbage in memory and releasing and reclaiming memory space. Two GC algorithms are mainly used: reference counting and tracing GC. Based on the generational model (young generation and old generation), ArkTS uses both the reference counting and object tracking algorithms to concurrently execute GC tasks, achieving high-performance memory reclamation in different scenarios.

In ArkTS, data types are classified into simple type and reference type. Data of the simple type is stored in stacks, and its space is automatically allocated and reclaimed by the operating system. Data of the reference type is stored in heaps, and its space must be manually reclaimed by the engine. GC is a management mechanism for automatically reclaiming heap space.

## Heap Space Structure and Parameters

### Heap Space Structure

![image](./figures/gc-heap-space.png)

- Semi Space: stores young generation, that is, newly created objects, which may be short-lived. The copying algorithm is used to reclaim memory.
- Old Space: stores old generation, that is, long-surviving objects. Multiple algorithms are used to reclaim memory based on scenarios.
- Huge Object Space: stores huge objects. A separate region is used to store a huge object.
- Read Only Space: stores read-only data at runtime.
- Non-Movable Space: stores unmovable objects.
- Snapshot Space: stores heap snapshots.
- Machine Code Space: stores machine codes.

Each space is divided into one or more regions for refined management. A region is the unit applied for from the memory allocator.

### Parameters

> **NOTE**
> 
> Among all the parameters described in this section, if no description is provided for how to configure a parameter, then the parameter is automatically set by the system.

For some of the parameters, three values or value ranges are provided, corresponding to the three value ranges of the total heap size: 64–128 MB/128–256 MB/ > 256 MB. If the remaining memory space is sufficient, the third value range (> 256 MB) is used by default.

#### Parameters of Semi Space

Two Semi Spaces are generated in the heap for the copying algorithm to use.

| Parameter| Value or Value Range| Description|
| --- | --- | :--- |
| semiSpaceSize | 2–4 MB/2–8 MB/2–16 MB| Size of Semi Space. The value varies according to the total heap size.|
| semiSpaceTriggerConcurrentMark | 1 M/1.5 M/1.5 M| Threshold for independently triggering the concurrent marking phase of Semi Space for the first time.|
| semiSpaceStepOvershootSize| 2 MB | Maximum overshoot size of Semi Space.|

#### Parameters of Other Spaces

| Parameter| Value or Value Range| Description|
| --- | --- | :--- |
| defaultReadOnlySpaceSize | 256 KB | Default size of Read Only Space.|
| defaultNonMovableSpaceSize | 2 MB/6 MB/64 MB | Default size of Non-Movable Space.|
| defaultSnapshotSpaceSize | 512 KB/512 KB/ 4 MB | Default size of Snapshot Space.|
| defaultMachineCodeSpaceSize | 2 MB/2 MB/8 MB | Default size of Machine Code Space.|

#### Parameters of Old Space and Huge Object Space

During initialization, the parameter is set to the size of the unallocated heap space left.

| Parameter| Value or Value Range| Description|
| --- | --- | :--- |
| oldSpaceOvershootSize | 4 MB/8 MB/8 MB | Maximum overshoot size of Old Space.|

#### Heap Size Parameters

| Parameter| Value or Value Range| Description|
| --- | --- | :--- |
| HeapSize | 448–1024 MB | Total heap size. The actual size allocated varies according to the heap type. The lower limit is reduced in the case of an insufficient memory pool.|
| SemispaceSize | 2–4 MB/2–8 MB/2–16 MB| Size of Semi Space.|
| NonmovableSpaceSize | 2 MB/6 MB/64 MB | Size of Non-Movable Space.|
| SnapshotSpaceSize | 512 KB| Size of Snapshot Space.|
| MachineCodeSpaceSize | 2 MB| Size of Machine Code Space.|

#### Maximum Number of Worker Thread Heaps

| Parameter| Value or Value Range| Description|
| --- | --- | --- |
| heapSize  | 768 MB | Size of the heap space of the work type.|

#### Size of the Interpreter Stack

| Parameter| Value or Value Range| Description|
| --- | --- | --- |
| maxStackSize | 128 KB| Maximum frame size of the interpreter stack.|

#### Concurrency Parameters

| Parameter| Value| Description|
| --- | ---: | --- |
| gcThreadNum | 7 | Number of GC threads. The default value is 7. You can set this parameter using **gc-thread-num**.|
| MIN_TASKPOOL_THREAD_NUM | 3 | Minimum number of threads in the thread pool.|
| MAX_TASKPOOL_THREAD_NUM | 7 | Maximum number of threads in the thread pool.|

Note: The thread pool is used to execute concurrent tasks in the GC process. During thread pool initialization, all the three parameters need to be considered. If **gcThreadNum** is a negative value, the number of threads in the initialized thread pool is the number of CPU cores divided by 2.

#### Other Parameters

| Parameter| Value| Description|
| --- | --- | --- |
| minAllocLimitGrowingStep | 2 M/4 M/8 M| Minimum increase step of **oldSpace**, **heapObject**, and **globalNative** when the heap space size is recalculated.|
| minGrowingStep | 4 M/8 M/16 M | Minimum increase step of **oldSpace**.|
| longPauseTime | 40 ms| Threshold for checking for a long GC pause. In the case of long GC pauses, complete GC log is printed, facilitating fault locating and analysis. You can set this parameter using **gc-long-paused-time**.|

### Other: The maximum native memory of the ArrayBuffer in a single VM is 4 GB.

## GC Process


![image](./figures/gc-process.png)

### HPP GC

High Performance Partial Garbage Collection (HPP GC) achieves efficient garbage collection by employing generational models, hybrid algorithms, and GC process optimization.

#### Young GC

- **When to trigger**: The young GC trigger threshold ranges from 2 MB to 16 MB, depending on the allocation speed and survival rate.
- **Description**: Reclaims the young-generation objects newly allocated to Semi Space.
- **Scenario**: Foreground
- **Log keywords**: [ HPP YoungGC ]

#### Old GC

- **When to trigger**: The old GC trigger threshold ranges from 20 MB to 300 MB. In most cases, the threshold of the first old GC is about 20 MB, and the threshold for subsequent old GC operations is adjusted based on the survival rate and memory usage.
- **Description**: Sorts and compresses the space of the young generation and some space of the old generation, and sweeps other spaces. The trigger frequency is much lower than that of the young GC. Due to full marking, a single old GC operation takes about 5 ms to 10 ms, longer than that of the young GC.
- **Scenario**: Foreground
- **Log keywords**: [ HPP OldGC ]

#### Full GC

- **When to trigger**: Full GC is not triggered based on the memory threshold. After the application is switched to the background, full GC is triggered if the size of the object that can be reclaimed is expected to be greater than 2 MB. You can also trigger full GC using the DumpHeapSnapshot and AllocationTracker tools or calling native interfaces and JS/TS interfaces.
- **Description**: Performs full compression on the young generation and old generation. Full GC is mainly used in performance-insensitive scenarios to reclaim memory space to the maximum extent.
- **Scenario**: Background
- **Log keywords**: [CompressGC]

Smart GC or idle GC is based on these three GC modes.

### Trigger Policy

#### GC Triggered by Space Thread

- Functions: **AllocateYoungOrHugeObject**, **AllocateHugeObject**, and other allocation-related functions
- Restriction parameters: corresponding space thresholds
- Description: GC is triggered when the space applied for by an object reaches the corresponding threshold.
- Log keywords: **GCReason::ALLOCATION_LIMIT**

#### GC Triggered by Native Binding Size

- Functions: **GlobalNativeSizeLargerThanLimit**
- Restriction parameters: **globalSpaceNativeLimit**
- Description: It affects the decision for performing full marking and concurrent marking.

#### GC Triggered Upon Switching to Background

- Functions: **ChangeGCParams**
- Description: Full GC is triggered when the application switches to the background.
- Log keywords: **app is inBackground**, **app is not inBackground**, and
  **GCReason::SWITCH_BACKGROUND**

### Execution Policy

#### Concurrent Marking

- Function: **TryTriggerConcurrentMarking**
- Description: Attempts to trigger concurrent marking and hand over the object traversal task to the thread pool to reduce the time that the main thread is being suspended.
- Log keywords: **fullMarkRequested, trigger full mark**, **Trigger the first full mark**, **Trigger full mark**, **Trigger the first semi mark**, and **Trigger semi mark**

#### Threshold Adjustment Before and After GC of Semi Space

- Function: **AdjustCapacity**
- Description: Adjusts the GC trigger threshold of Semi Space after GC to optimize the space structure.
- Log keywords: There is no direct log. The GC statistics logs show that the young space threshold before GC is dynamically adjusted.

#### Threshold Adjustment After the First Old GC

- Function: **AdjustOldSpaceLimit**
- Description: Adjusts the old space threshold based on the minimum increase step and average survival rate.
- Log keywords: **"AdjustOldSpaceLimit oldSpaceAllocLimit_: "<< oldSpaceAllocLimit <<" globalSpaceAllocLimit_: " << globalSpaceAllocLimit_;**

#### Old Space/Global Space Threshold and Increase Factor for the Second and Later Old GC Operations

- Function: **RecomputeLimits**
- Description: Recalculates and adjusts **newOldSpaceLimit**, **newGlobalSpaceLimit**, **globalSpaceNativeLimit**, and the increase factor based on the current GC statistics.
- Log keywords: **"RecomputeLimits oldSpaceAllocLimit_: "<< newOldSpaceLimit_ <<" globalSpaceAllocLimit_: "<< globalSpaceAllocLimit_ <<" globalSpaceNativeLimit_: "<< globalSpaceNativeLimit_;**

#### CSet for Partial GC

- Function: **OldSpace::SelectCSet ()**
- Description: Selects a region with a small number of living objects and a low reclamation cost for partial GC.
- Log keywords: **Select CSet failure: number is too few**,
  **"Max evacuation size is 6_MB. The CSet region number: " << selectedRegionNumber;**,
  and **"Select CSet success: number is " << collectRegionSet_.size();**

## SharedHeap

### Shared Heap Structure

![image](./figures/gc-shared-heap.png)

- Shared Old Space: stores common shared objects. The young generation and old generation are not distinguished in the shared heap.
- Shared Huge Object Space: stores huge shared objects. A separate region is used to store a huge object.
- Shared Read Only Space: stores read-only shared data at runtime.
- Shared Non-Movable Space: stores unmovable shared objects.

Note: The shared heap is mainly used to share objects between threads. It improves efficiency and reduces memory usage. The shared heap does not belong to a specific thread. It stores objects with shared value and has a higher survival rate. It does not evolve Semi Space.

## Technical Features

### Smart GC

#### Description

In performance-sensitive scenarios, the GC trigger threshold of the JS thread is temporarily adjusted to the maximum JS heap size (448 MB by default) to prevent frame loss caused by the GC trigger. (Smart GC does not take effect for the Worker thread and TaskPool thread.) However, if the performance-sensitive scenario lasts for a long period of time and the allocated objects reach the maximum heap size, GC is triggered. This GC takes a long time because too many objects are accumulated.

#### Performance-Sensitive Scenarios

- Application cold start
- Application sliding
- Page redirection upon click
- Jumbo frame

Currently, this feature is controlled by the system. Third-party apps do not have APIs to directly call this feature.

Log keyword: **SmartGC**

#### Interaction Process

![image](./figures/gc-smart-feature.png)

Mark performance-sensitive scenarios. When entering or exiting a performance-sensitive scenario, mark the scenario on the heap to avoid unnecessary GC and maintain high performance.

## Log Description

### Typical Logs

```
// Actual size occupied by the object before GC (actual size occupied by the region) - > Actual size occupied by the object after GC (actual size occupied by the region), total duration (+concurrentMark duration), and GC triggering cause
C03F00/ArkCompiler: [gc]  [ CompressGC ] 26.1164 (35) -> 7.10049 (10.5) MB, 160.626(+0)ms, Switch to background
// GC statuses and application name
C03F00/ArkCompiler: [gc] IsInBackground: 1; SensitiveStatus: 0; OnStartupEvent: 0; BundleName: com.huawei.hmos.filemanager;
// Time consumption statistics of each GC phase
C03F00/ArkCompiler: [gc] /***************** GC Duration statistic: ****************/
C03F00/ArkCompiler: [gc] TotalGC:                 160.626 ms
C03F00/ArkCompiler: Initialize:              0.179   ms
C03F00/ArkCompiler: Mark:                    159.204 ms
C03F00/ArkCompiler: MarkRoots:               6.925   ms
C03F00/ArkCompiler: ProcessMarkStack:        158.99  ms
C03F00/ArkCompiler: Sweep:                   0.957   ms
C03F00/ArkCompiler: Finish:                  0.277   ms
// Memory size occupied by each part after GC
C03F00/ArkCompiler: [gc] /****************** GC Memory statistic: *****************/
C03F00/ArkCompiler: [gc] AllSpaces        used:  7270.9KB     committed:   10752KB
C03F00/ArkCompiler: ActiveSemiSpace  used:       0KB     committed:     256KB
C03F00/ArkCompiler: OldSpace         used:  4966.9KB     committed:    5888KB
C03F00/ArkCompiler: HugeObjectSpace  used:    2304KB     committed:    2304KB
C03F00/ArkCompiler: NonMovableSpace  used:       0KB     committed:    2304KB
C03F00/ArkCompiler: MachineCodeSpace used:       0KB     committed:       0KB
C03F00/ArkCompiler: HugeMachineCodeSpace used:       0KB     committed:       0KB
C03F00/ArkCompiler: SnapshotSpace    used:       0KB     committed:       0KB
C03F00/ArkCompiler: AppSpawnSpace    used: 4736.34KB     committed:    4864KB
C03F00/ArkCompiler: [gc] Anno memory usage size:  45      MB
C03F00/ArkCompiler: Native memory usage size:2.99652 MB
C03F00/ArkCompiler: NativeBindingSize:       0.577148KB
C03F00/ArkCompiler: ArrayBufferNativeSize:   0.0117188KB
C03F00/ArkCompiler: RegExpByteCodeNativeSize:0.280273KB
C03F00/ArkCompiler: ChunkNativeSize:         19096   KB
C03F00/ArkCompiler: [gc] Heap alive rate:         0.202871
// Overall statistics of this type of GC on the VM
C03F00/ArkCompiler: [gc] /***************** GC summary statistic: *****************/
C03F00/ArkCompiler: [gc] CompressGC occurs count  6
C03F00/ArkCompiler: CompressGC max pause:    2672.33 ms
C03F00/ArkCompiler: CompressGC min pause:    160.626 ms
C03F00/ArkCompiler: CompressGC average pause:1076.06 ms
C03F00/ArkCompiler: Heap average alive rate: 0.635325
```

- GC type, which can be [HPP YoungGC], [HPP OldGC], [CompressGC] and [SharedGC].
- **TotalGC**: total duration. The following lists the time required for each phase, including Initialize, Mark, MarkRoots, ProcessMarkStack, Sweep, and Finish. The actual phase varies according to the GC process.
- **IsInBackground**: specifies whether it is a background scenario. The options are **1** (background scenario) and **0** (non-background scenario).
- **SensitiveStatus**: specifies whether it is a sensitive scenario. The options are **1** (sensitive scenario) and **0** (non-sensitive scenario).
- **OnStartupEvent**: specifies whether it is a cold start scenario. The options are **1** (cold start scenario) and **0** (non-cold start scenario).
- **used**: actual memory space occupied by the allocated object.
- **committed**: size of the memory allocated to the heap. Memory space is allocated by region, and a region is not fully occupied by objects. Therefore, if **committed** is greater than or equal to **used**, the values of **HugeObjectSpace** is the same under **used** and **committed** because one object occupies the region.
- **Anno memory usage size**: memory size applied by all heaps of the current process, including the heap and shared heap.
- **Native memory usage size**: native memory size requested by the current process.
- **NativeBindingSize**: size of the native memory bound to the objects in the heap of the current process.
- **ArrayBufferNativeSize**: native memory size of the array cache requested by the current process.
- **RegExpByteCodeNativeSize**: native memory size of the regular expression bytecode requested by the current process.
- **ChunkNativeSize**: chunk native memory size requested by the current process.
- **Heap alive rate**: survival rate of objects in the heap.

## GC Developer Debugging Interfaces

> **NOTE**
> The following interfaces are used only for debugging. They are informal external SDK interfaces and should not be used in official application versions.

### ArkTools.hintGC()

- Call method: **ArkTools.hintGC()**
- Type: JS interface
- Description: Determines whether full GC is required. In the background scenario or if the expected survival rate is lower than the preset value, full GC is triggered. In performance-sensitive scenarios, full GC is not triggered.
- Use scenario: The developer asks the system to perform GC.
- Log keywords: There is no direct log. Only external trigger (**GCReason::TRIGGER_BY_JS**) can be found.


Example:

```
// Declare the interface first.
declare class ArkTools {
     static hintGC(): void;
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  build() {
  Row() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Button("Trigger Hint GC").onClick((event: ClickEvent) => {
          ArkTools.hintGC(); // Directly called in a method.
      })
    }
    .width('100%')
  }
  .height('100%')
}
}
```
