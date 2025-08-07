# 使用TaskPool执行多个耗时任务
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

多个任务同时执行时，由于任务复杂度不同，执行时间和返回数据的时间也会不同。如果宿主线程需要所有任务执行完毕的数据，可以通过[TaskGroup](../reference/apis-arkts/js-apis-taskpool.md#taskgroup10)的方式实现。

除了以上情况，如果需要处理的数据量较大，例如一个列表中有10000条数据，将这些数据放在一个Task中处理会非常耗时。那么就可以将原始数据拆分成多个子列表，为每个子列表分配一个独立的Task执行，等待全部Task执行完成后合并结果形成完整的数据，这样可以节省处理时间，提升用户体验。

下面以多个任务进行图片加载为例进行说明。

1. 实现子线程中需要执行的任务。

   ```ts
   // IconItemSource.ets
   export class IconItemSource {
     image: string | Resource = '';
     text: string | Resource = '';
   
     constructor(image: string | Resource = '', text: string | Resource = '') {
       this.image = image;
       this.text = text;
     }
   }
   ```
   <!-- @[implement_child_thread_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/IconItemSource.ets) -->

   ```ts
   // IndependentTask.ets
   import { IconItemSource } from './IconItemSource';
    
   // 在TaskPool线程中执行的方法，需要添加@Concurrent注解，否则无法正常调用
   @Concurrent
   export function loadPicture(count: number): IconItemSource[] {
     let iconItemSourceList: IconItemSource[] = [];
     // 遍历添加6*count个IconItem的数据
     for (let index = 0; index < count; index++) {
       const numStart: number = index * 6;
       // 此处循环使用6张预定义的图片资源（例如：startIcon、background、foreground等）
       iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 1}`));
       iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 2}`));
       iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 3}`));
       iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 4}`));
       iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 5}`));
       iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 6}`));
   
     }
     return iconItemSourceList;
   }
   ```
   <!-- @[implement_child_thread_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/IndependentTask.ets) -->

2. 将需要执行的Task放到一个TaskGroup里面，当TaskGroup中的所有Task执行完毕后，会将所有Task的结果都放在一个数组中并返回给宿主线程，而不是每执行完一个Task就返回一次，这样宿主线程就可以在返回的数据里拿到所有Task的执行结果，便于后续使用。

   ```ts
   // MultiTask.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   import { loadPicture } from './IndependentTask';
    
   let iconItemSourceList: IconItemSource[][] = [];
    
   let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
   taskGroup.addTask(new taskpool.Task(loadPicture, 30));
   taskGroup.addTask(new taskpool.Task(loadPicture, 20));
   taskGroup.addTask(new taskpool.Task(loadPicture, 10));
   taskpool.execute(taskGroup).then((ret: object) => {
     let tmpLength = (ret as IconItemSource[][]).length
     for (let i = 0; i < tmpLength; i++) {
       for (let j = 0; j < ret[i].length; j++) {
         iconItemSourceList.push(ret[i][j]);
       }
     }
   })
   ```
   <!-- @[execute_task_group](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/MultiTask.ets) -->
