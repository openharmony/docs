# 使用TaskPool执行独立的耗时任务

对于独立运行的耗时任务，任务执行完毕后将结果返回给宿主线程，没有上下文依赖，可采用以下方式实现。

下面通过图片加载来说明。

1. 实现子线程需要执行的任务。

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
    
   // 在TaskPool线程中执行的方法，需要添加@Concurrent注解，否则无法正常调用。
   @Concurrent
   export function loadPicture(count: number): IconItemSource[] {
     let iconItemSourceList: IconItemSource[] = [];
     // 遍历添加6*count个IconItem的数据
     for (let index = 0; index < count; index++) {
       const numStart: number = index * 6;
       // 此处循环使用6张图片资源
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

2. 使用TaskPool中的execute方法执行上述任务，加载图片。

   ```ts
   // Index.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   import { loadPicture } from './IndependentTask';
   
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
             .onClick(() => {
               let iconItemSourceList: IconItemSource[] = [];
               // 创建Task
               let loadPictureTask: taskpool.Task = new taskpool.Task(loadPicture, 30);
               // 执行Task，并返回结果
               taskpool.execute(loadPictureTask).then((res: object) => {
                 // loadPicture方法的执行结果
                 iconItemSourceList = res as IconItemSource[];
               })
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
