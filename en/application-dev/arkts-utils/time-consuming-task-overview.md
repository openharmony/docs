# Concurrent Time-Consuming Task Scenarios


Time-consuming tasks refer to tasks that need to be executed for a long time. If a time-consuming task is executed in the main thread of the UI, problems such as frame freezing, frame loss, and slow response may occur. Typical time-consuming tasks include CPU-intensive tasks, I/O-intensive tasks, and synchronization tasks.


Common service scenarios of time-consuming tasks are as follows:


| Common Service Scenario| Description| CPU-Intensive Task| I/O-Intensive Task| Synchronize Task|
| -------- | -------- | -------- | -------- | -------- |
| Image/Video encoding and decoding| Encodes and decodes images or videos before displaying them.| √ | √ | × |
| Compression and decompression| Decompresses a local package or compresses a local file.| √ | √ | × |
| JSON parsing| Serializes and deserializes JSON strings.| √ | × | × |
| Model computation| Performs model operations and analysis on data.| √ | × | × |
| Network download| Downloads resources, images, and files on an intensive network.| × | √ | × |
| Database operation| Saves chat records, page layout, and music list information to the database, or reads the database to display related information when the application is started for the second time.| × | √ | × |
