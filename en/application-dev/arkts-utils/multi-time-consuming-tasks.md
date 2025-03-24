# Using TaskPool for Multiple Time-Consuming Tasks

When multiple tasks are executed concurrently, their execution times can vary due to differences in complexity, and the timing of their completion is unpredictable. If the host thread requires the results of all tasks after they are completed, you can use the approach described in this topic.

Additionally, if the volume of data to be processed is large (for example, a list with 10,000 items), processing all the data in a single task can be time-consuming. Instead, you can split the original data into multiple sublists and assign each sublist to an independent task. After all tasks are completed, you can combine the results into a complete dataset. This approach can reduce processing time and enhance user experience.

This example uses image loading of multiple tasks to illustrate the process.

1. Implement the task to be executed in a child thread.

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

   ```ts
   // IndependentTask.ets
   import { IconItemSource } from './IconItemSource';
    
   // Methods executed in the task must be decorated by @Concurrent. Otherwise, they cannot be called.
   @Concurrent
   export function loadPicture(count: number): IconItemSource[] {
     let iconItemSourceList: IconItemSource[] = [];
     // Add six IconItem data records.
     for (let index = 0; index < count; index++) {
       const numStart: number = index * 6;
       // Use six images in the loop.
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

2. Add the tasks to a task group and execute them collectively. When all the tasks in the task group finish executing, their results are placed in an array and sent back to the host thread. In this way, the host thread can access the combined results of all tasks at once, rather than receiving results individually as each task completes.

   ```ts
   // MultiTask.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   import { loadPicture } from './IndependentTask';
    
   let iconItemSourceList: IconItemSource[][];
    
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
