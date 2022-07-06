# 板级驱动适配


板级驱动适配的主要步骤如下：


1. SDK基于OpenHarmony提供的CMSIS/POSIX适配依赖OS的接口。
   板级SDK适配OS接口存在两种选择：CMSIS、POSIX，当前liteos_m已经适配CMSIS大部分接口（覆盖：基础内核管理、线程管理、定时器、事件、互斥锁、信号量、队列等），基本可以满足直接移植，POSIX接口当前具备初步的移植能力，接口正在补全中；如果SDK原本基于CMSIS或者POSIX接口实现，理论上可以直接适配到liteos_m中；

   如果SDK原本基于freeRTOS等其他嵌入式OS或者本身有一层OS interface的抽象层，建议将依赖OS接口直接适配到CMSIS接口；

   例如，某产品定义的OS interface接口，创建queue的接口原型：

     
   ```
   bool osif_msg_queue_create(void **pp_handle, uint32_t msg_num, uint32_t msg_size)
   ```

   而CMSIS提供的接口原型如下：

     
   ```
   osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t *attr);
   ```

   对应的OS interface接口的原型可以按照如下适配：

     
   ```
   #include "CMSIS_os2.h"
   osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t *attr);
   bool osif_msg_queue_create(void **pp_handle, uint32_t msg_num, uint32_t msg_size)
   {
   	(*pp_handle) = osMessageQueueNew (msg_num, msg_size, NULL);
   	if((*pp_handle) == NULL){
   		return FALSE;
   	}
   	return TRUE;
   }
   ```

2. 接口SDK编译问题或者基于OpenHarmony编译框架改造SDK，将SDK按照目录结构要求合入OpenHarmony的device目录中。
   OS接口适配后，板级驱动集成到OpenHarmony也存在2种选择：

   - SDK独立编译，通过二进制形式直接链入OpenHarmony；
   - SDK基于OpenHarmony改造编译框架，从长期演进及后期联调便利性角度考虑，建议基于GN编译框架直接改造SDK编译框架，通过源码形式链入OpenHarmony工程。

3. 验证SDK基本功能。
