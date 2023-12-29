# 多线程安全注意事项

多线程安全是指多个线程同时访问或修改共享资源时，能够保证程序的正确性和可靠性。

开发者选择TaskPool或Worker进行多线程开发时，在TaskPool和Worker的工作线程中导入的API和模块需要支持多线程安全，否则可能会导致多线程数据竞争问题，造成应用程序异常或崩溃。

在TaskPool或Worker的工作线程中支持使用以下模块，其他模块在使用时需要验证是否满足线程安全。

 - console
 - setInterval
 - setTimeout
 - clearInterval
 - clearTimeout
 - @ohos.buffer
 - @ohos.convertxml
 - @ohos.file
   - @ohos.file.backup
   - @ohos.file.cloudSync
   - @ohos.file.cloudSyncManager
   - @ohos.file.environment
   - @ohos.file.fileAccess
   - @ohos.file.fileExtensionInfo
   - @ohos.file.fileuri
   - @ohos.file.fs
   - @ohos.file.hash
   - @ohos.file.photoAccessHelper
   - @ohos.file.picker
   - @ohos.file.securityLabel
   - @ohos.file.statvfs
   - @ohos.file.storageStatistics
   - @ohos.file.volumeManager
 - @ohos.fileio
 - @ohos.hilog
 - @ohos.multimedia
   - @ohos.multimedia.image
 - @ohos.net
   - @ohos.net.http
 - @ohos.pasteboard
 - @ohos.systemDateTime
 - @ohos.systemTimer
 - @ohos.taskpool
 - @ohos.uri
 - @ohos.url
 - @ohos.util
   - @ohos.util.ArrayList
   - @ohos.util.Deque
   - @ohos.util.HashMap
   - @ohos.util.HashSet
   - @ohos.util.LightWeightMap
   - @ohos.util.LightWeightSet
   - @ohos.util.LinkedList
   - @ohos.util.List
   - @ohos.util.PlainArray
   - @ohos.util.Queue
   - @ohos.util.Stack
   - @ohos.util.TreeMap
   - @ohos.util.TreeSet
   - @ohos.util
 - @ohos.worker
 - @ohos.xml
