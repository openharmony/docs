# 普通对象

普通对象跨线程时通过拷贝形式传递，两个线程的对象内容一致，但是指向各自线程的隔离内存区间。例如Ecmascript262规范定义的Object、Array、Map等对象是通过这种方式实现跨并发实例通信的。通信过程如下图所示：

![deep_copy](figures/deep_copy.png)
