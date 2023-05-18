# FAQ<a name="ZH-CN_TOPIC_0000001053622377"></a>


## 多个代码仓存在编译依赖时如何同时发起构建<a name="section169732563435"></a>

OS\(操作系统\)开发时，经常会遇到多个代码仓的修改具有编译依赖关系，需要同时构建、同时合入。为此码云平台将Issue作为具有编译依赖的多个代码仓提交PR的关联标识。具体操作如下：

1. 在此次提交的任意一个代码仓上创建Issue。

2. 将多个需要同时构建、同时合入的PR关联上述Issue，具体操作请参考码云帮助中心：[https://gitee.com/help/articles/4142](https://gitee.com/help/articles/4142)。

3. 触发构建\(详见触发构建的操作帮助\)后，构建中心会识别关联了同一Issue的PR，同时下载构建，并在代码审核通过后，同时进行合并入代码库。

## `Signed-off-by`相关操作<a name="section-signed-off"></a>

### 如何在Commit中添加signoff记录

使用`git commit -s` 或 `git commit –signoff` 命令提交。

### 如何追加signoff到上一次commit?

执行`git commit --amend --signoff`命令 。

关于commit更多选项，请参考：[https://](https://git-scm.com/docs/git-commit)[git-scm.com/docs/git-commit](https://git-scm.com/docs/git-commit)

## DCO校验异常处理<a name="section-dco"></a>

开发者提交Pull Request后，评论`start build`会触发门禁校验：

1. 该PR提交是否签署Developer Certificate of Origin（DCO) “开发者原创声明”。
2. 该PR提交是否包含 Signed-off-by信息。

校验失败可能的原因有：

1. 未签署“DCO协议”，例如提示：

   ```
   当前检测到如下commit的用户未签署DCO协议：
   
   •345612
   
   •213123
   ```

   **解决办法**：

   点击[这里](https://dco.openharmony.cn/sign)签署、查看签署状态。

   在PR的评论框输入`check dco`后，单击”评论”，系统将再次进行DCO校验。

2. Commits 中未包含 Signed-off-by信息，例如提示：

   ```
   当前检测到如下commit未包含Signed-off-by信息：
   
   •123123
   
   •345612
   ```

   **解决办法**：

   参考`Signed-off-by`相关操作，添加Signed-off-by信息。格式为：Signed-off-by: user.name <user.email>。

   在PR的评论框输入`check dco`后，单击”评论”，系统将再次进行DCO校验。

## 回退提交<a name="section479422315253"></a>

请参考码云帮助中心：[https://gitee.com/help/articles/4195](https://gitee.com/help/articles/4195)

## 处理冲突<a name="section94417232274"></a>

请参考码云帮助中心：[https://gitee.com/help/articles/4194](https://gitee.com/help/articles/4194)

