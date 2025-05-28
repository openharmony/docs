# 并发常见问题

## Taskpool任务不执行快速定位指导

开发者发现Taskpool任务不执行时，可按照以下步骤快速定位。

1. **taskpool.execute接口是否调用**。

   taskpool.execute被调用时，Hilog会打印taskpool维测日志（Task Allocation: taskId:）。
   如果发现没有该维测日志表明taskpool.execute实际未调用，应用需排查taskpool.execute之前的其他业务逻辑是否执行完成。

   ```ts
   console.log("test start");
   ... // 其他业务逻辑
   taskpool.execute(xxx);
   
   // 如果test start在控制台打印，但是并未出现Task Allocation: taskId:的日志，则taskpool.execute没有执行，应用需要排查其他业务逻辑。
   ```

2. **taskpool任务是否被执行**。

   调用taskpool.execute接口会打印taskpool**调用态维测日志**Task Allocation: taskId:。 
   定位到目标任务对应的Task Allocation: taskId:日志后，在日志中搜索taskId后跟随的Id号，正常情况会打印**执行态日志**（Task Perform: name:）和**结束态日志**（Task PerformTask End: taskId:）。

   1.  如果只有调用态日志，没有执行态日志。可能是由于先执行的taskpool任务阻塞了taskpool工作线程，导致taskpool工作线程不可用，后执行的taskpool任务无法执行。应用可以排查自身业务逻辑，或者通过trace进一步定位。

   2. 如果只有调用态日志和执行态日志，没有结束态日志。应用优先分析自定义的taskpool任务内的业务逻辑是否存在阻塞操作。

   3. 如果调用态日志和执行态日志时间间隔较久，且应用关注任务的执行时机，可以按照以下步骤继续分析。

      1. 查看是否发生大量taskpool任务堆积未执行的情况。如果在较短时间内执行大量任务（出现大量调用态日志），后执行的任务需要等待前置任务执行完。此时可以检查taskpool的扩容情况，如果在调用态日志打印之前，taskpool工作线程数量已扩容到接近上限（上限数量为日志片段log2中的maxThreads字段），则可能是短时间内任务数量太多导致，应用可以通过合理设置优先级将重要任务和有时效要求的任务优先执行。

      2. 查看前置执行的taskpool任务是否本身耗时较长或者发生阻塞。如果前置任务本身耗时较长，应用可以通过合理设置优先级解决。如果前置任务发生了意料之外的阻塞（一段时间后阻塞解除），应用需要排查自身业务逻辑。

   ```ts
   // hilog 日志片段（模拟）
   // log1： 大量任务提交
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   ...
   // log2: 扩容日志
   taskpool:: maxThreads: , create num: , total num:
   // log3: 执行态日志
   taskpool:: Task Perform: name: , taskId: , priority:
   ```

3. **taskpool任务执行时是否发生异常**。

   1. 如果在执行taskpool任务过程中发生JS异常，taskpool会捕获该JS异常并通过taskpool.execute().catch((e:Error)=>{})将异常信息返回，应用需要查看异常信息并修复。

      ```ts
      taskpool.execute().then((res: object)=>{
        // 任务执行完处理结果
        ...
      }).catch((e: Error)=>{
        // 任务发生异常后处理异常
        ...
      })
      ```

   2. 如果.catch分支无异常信息返回，但是应用通过taskpool任务实现的功能发生问题，应用需要查看taskpool任务逻辑是否发生阻塞，导致功能异常。

## Taskpool任务执行慢排查思路

开发者发现taskpool任务的调用态日志（如taskpool::add taskId:或者taskpool::Task Allocation: taskId:）与执行态日志（taskpool::Task Perform: name:）间隔时间较长时，可参考该排查指导进行问题定位。

### 排查方向：出问题的taskpool任务优先级较低，应用后续新增较多优先级更高的taskpool任务，导致原有低优先级的taskpool任务执行延后

**场景示例一**

某应用创建了低优先级的taskpool任务，且其他业务场景依赖这个任务执行。后续，应用又创建了很多中优先级任务，导致原有的低优先级任务执行时机延后，其他业务场景未按计划时间点完成任务。

**解决方案**

对完成执行时间点有要求的任务以低优先级执行不是好的选择，应用需要根据业务场景设置合理的任务优先级，且合理搭配任务优先级。

**场景示例二**

应用对某个taskpool任务（简称taskA）执行时间有要求，执行超过5s时有检测机制。应用将taskA设置为MEDIUM优先级，在taskA前以MEDIUM优先级执行了较多其他任务，且这些任务耗时3s/5s不等，将已有线程和新扩容的线程均占满，导致taskA从taskpool.execute到执行结束超过5s。

**解决方案**

1.分析其他任务执行耗时3s/5s是否合理；2.调整taskA优先级。

### 排查方向：晚执行的taskpool任务是串行任务或者依赖其他任务

**场景示例**

如果问题场景对应的taskpool任务是串行队列任务，查看该串行队列内前面任务的执行情况。如日志片段1所示该串行队列有四个任务，问题场景对应的是第四个任务，查看日志片段2发现第二个任务执行了2s，对于应用业务逻辑是不正常的。
```ts
// hilog 日志片段1（模拟）
// seqRunner共有四个任务
taskpool:: taskId 389508780288 in seqRunnner 393913878464 immediately.
taskpool:: add taskId: 394062838784 to seqRunnner 393913878464
taskpool:: add taskId: 393918679936 to seqRunnner 393913878464
taskpool:: add taskId: 393918673408 to seqRunnner 393913878464

// hilog 日志片段2（模拟）
// 查看第二个任务, 发现任务执行到执行结束间隔2s
18:28:28.223 taskpool:: taskId 394062838784 in seqRunner 393913878464 immediately.
18:28:28.224 taskpool:: Task Perform: name : , taskId : 394062838784, priority : 0
18:28:30.243 taskpool:: Task Perform End: taskId : 394062838784, performResult : Successful
```

**解决方案**

应用继续分析第二个任务中的业务逻辑是否存在耗时操作。

### 排查方向：@Concurrent标记的方法所在的ets文件里import过多模块

**场景示例**

taskpool第一次执行任务慢，间隔几百毫秒，原因是子线程反序列化之前，会将@Concurrent标记的方法所在的ets文件import的所有模块都初始化，导致出现任务调度慢的情况。应用可通过trace进一步定位，如果反序列化成功前有许多init module的trace，应用自行排查ets文件是否import过多模块。

**解决方案**

1.可拆分@Concurrent方法到单独的ets文件，减少模块初始化时间；2.使用延迟加载（lazy import）。