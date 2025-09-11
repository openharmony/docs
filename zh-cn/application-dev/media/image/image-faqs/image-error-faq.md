# Image Kit异常处理
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Image Kit提供ArkTS接口和C/C++接口。在遇到特殊情况时（例如输入参数无效、内存不足或函数无法处理请求），系统会通过异常（ArkTS）或错误码（C/C++）反馈错误。开发者需要在应用层合理捕获和处理这些错误，以避免应用崩溃或出现未定义行为。

## ArkTS异常处理

ArkTS接口调用时，如果传入的参数不符合要求，或者底层执行过程中出现不可恢复的错误，系统会抛出BusinessError异常，或者在异步场景中返回一个拒绝的Promise。开发者需要在可能发生异常的位置使用try/catch/finally块来捕获并处理这些异常，或者使用后Ability Kit提供的[错误管理](../../../reference/apis-ability-kit/js-apis-app-ability-errorManager.md)模块来捕获和处理这些异常。



## C/C++异常处理