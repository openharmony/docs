# 常见问题


## UAF(Use after free)

- 申请小块内存（不大于0x1c000字节）
  free之后：

  读操作：读取free之后的内存大概率是魔术数字(0xFEFEFEFE)

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > free之后的堆内存不会立即释放进堆内存池，会先放至固定长度的队列中，并置魔术数字0xFE，队列满后会将先放至队列中的内存块释放进堆内存池

  写操作：无法校验。


- 申请大块内存（大于0x1c000）
  堆内存由malloc通过调用mmap接口申请，free之后若仍访问该内存，则用户程序异常（该内存区间已被unmap）。


## Double free

Double free时，用户程序将会异常退出。


## 堆内存节点被踩

- 申请小块内存（不大于0x1c000）
  堆内存节点被踩时，用户程序将会异常退出，并输出破坏被踩节点的可能的堆内存申请调用栈，对于野指针踩内存情况无法校验出来。例如用户程序mem_check中存在堆内存越界踩的情况，利用命令行方式可以获得踩内存的可能的具体位置。

    
  ```
  OHOS # ./mem_check --mwatch  
  OHOS # 
  ==PID:6== Memory integrity information:
      [TID:28 allocated addr: 0x272e1ea0, size: 0x120] The possible attacker was allocated from:
          #00: <malloc+0x808>[0x640e8] -> /lib/libc.so
          #01: <threadFunc1+0x7c>[0x21d0] -> mem_check 
  ```

  可以通过调用栈解析脚本对调用栈信息进行解析。

- 申请大块内存（大于0x1c000）

  堆内存由malloc通过mmap接口申请，申请得到的堆内存块前后各置一个size为PAGE_SIZE大小的区间，设置无读写权限，读写操作会触发用户程序异常。
