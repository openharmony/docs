# C/C++内存错误检测


为追求C/C++的更优性能，编译器和OS(Windows/Linux/Mac)运行框架不会对内存操作进行安全检测。针对该场景，DevEco Studio集成ASan（Address-Sanitizer）为开发者提供面向C/C++的地址越界检测能力，并通过FaultLog展示错误的堆栈详情及导致错误的代码行。


关于ASan的使用说明请参见<!--RP1-->[C/C++内存错误检测](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V4/asan-0000001545528013-V4?catalogVersion=V4)<!--RP1End-->。
