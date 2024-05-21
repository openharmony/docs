# Precautions for Multithread Safe

Multithread safe ensures the correctness and reliability of programs when multiple threads access or modify shared resources at the same time.

When you use TaskPool or Worker for multithreading development, ensure that the APIs and modules imported to the worker thread of TaskPool and Worker support multithread safe. Otherwise, multithread data competition may occur, causing application exceptions or breakdown.

The following modules can be used in the worker thread of TaskPool and Worker. If other modules are used, you must check whether the thread security requirements are met.

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
