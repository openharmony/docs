# Comparison Between the Actor and Memory Sharing Models

In the memory sharing model, multiple threads execute complex tasks simultaneously. These threads depend on the same memory and have the permission to access the memory. Before accessing the memory, a thread must preempt and lock the memory. In this case, other threads have to wait for the thread to release the memory.

In the actor model, each thread is an independent actor, which has its own memory. Actors trigger the behavior of each other through message transfer. They cannot directly access the memory space of each other.

Different from the memory sharing model, the actor model provides independent memory space for each thread. As such, it avoids memory preemption and resulting function and performance problems.

In the actor model, concurrent tasks and task results are transmitted through the inter-thread communication.

This topic describes the differences between the two models when solving the producer-consumer problem.

## Memory Sharing Model
The following figure shows how the producer-consumer problem is resolved in the memory sharing model.

![Interaction between the producer, consumer, and shared memory container](figures/memory-shared-model-sample.PNG)

To prevent dirty reads and writes caused by simultaneous access, only one producer or consumer can access a shared memory container at a time. This means that producers and consumers need to compete for the lock of the container. After a role obtains the lock, other roles have to wait.

```
// Below is pseudocode and is provided to help you better understand the differences between the memory sharing model and the actor model.
BufferQueue {
    Queue queue
    Mutex mutex
    add(value) {
        // Attempt to acquire the lock.
        if (mutex.lock()) {
            queue.push(value)
            mutex.unlock()
        }
    }

    take() {
        // Attempt to acquire the lock.
        if (mutex.lock()) {
            if (queue.empty()) {
                return null
            }
            let res = queue.pop(value)
            mutex.unlock()
            return res
        }
    }
}

// Construct a globally shared memory segment.
let g_bufferQueue = new BufferQueue()

Producer {
    run() {
        let value = random()
        // Initiate cross-thread access to the bufferQueue object.
        g_bufferQueue.add(value)
    }
}

Consumer {
    run() {
        // Initiate cross-thread access to the bufferQueue object.
        let res = g_bufferQueue.take()
        if (res != null) {
            // Add consumption logic.
        }
    }
}

Main() {
    let consumer = new Consumer()
    let producer = new Producer()
    // Execute the production task in multiple threads.
    for 0 in 10 :
        let thread = new Thread()
        thread.run(producer.run())
        consumer.run()
}
```

## Actor Model
The following figure shows how the producer-consumer problem is resolved by using **TaskPool** in the actor model.

![Inter-thread communication of the actor model](figures/actor-model-sample.PNG)

In the actor model, different roles do not share memory. Both the producer thread and UI thread have their own exclusive memory. After producing the result, the producer sends the result to the UI thread through serialization. After consuming the result, the UI thread sends a new production task to the producer thread.

```ts
import { taskpool } from '@kit.ArkTS';
// Cross-thread concurrent tasks
@Concurrent
async function produce(): Promise<number>{
  // Add production logic.
  console.log("producing...");
  return Math.random();
}

class Consumer {
  public consume(value : Object) {
    // Add consumption logic.
    console.log("consuming value: " + value);
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button() {
          Text("start")
        }.onClick(() => {
          let produceTask: taskpool.Task = new taskpool.Task(produce);
          let consumer: Consumer = new Consumer();
          for (let index: number = 0; index < 10; index++) {
            // Execute the asynchronous concurrent production task.
            taskpool.execute(produceTask).then((res : Object) => {
              consumer.consume(res);
            }).catch((e : Error) => {
              console.error(e.message);
            })
          }
        })
        .width('20%')
        .height('20%')
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
