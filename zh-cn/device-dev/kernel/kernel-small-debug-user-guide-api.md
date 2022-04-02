# 接口说明


  **表1** 内存调测功能

| 接口名 | 描述 | 
| -------- | -------- |
| mem_check_init | 初始化内存检测模块。 | 
| watch_mem | 获取线程级堆内存使用信息。 | 
| check_leak | 检查是否有堆内存泄漏。 | 
| check_heap_integrity | 检查堆内存的完整性。 | 
| backtrace | 获取调用栈地址信息。 | 
| backtrace_symbols | 根据地址信息获取符号信息。 | 
| print_trace | 输出函数调用栈信息。 | 


  **表2** 调用栈回溯功能

| 接口名 | 描述 | 
| -------- | -------- |
| backtrace | 获取调用栈地址信息。 | 
| backtrace_symbols | 根据地址信息获取符号信息。 | 
| print_trace | 输出函数调用栈信息。 | 
