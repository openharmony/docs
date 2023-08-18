# Overview of ArkTS Common Library


The ArkTS common library provides common basic capabilities, as illustrated in the figure below.


**Figure 1** Capabilities of the ArkTS common library

![arkts-commonlibrary](figures/arkts-commonlibrary.png)


- Supporting [asynchronous concurrency and multithread concurrency](concurrency-overview.md)
  - Supports standard JavaScript asynchronous concurrency capabilities such as Promise and async/await.
  - Uses **TaskPool** to provide a multithread running environment for applications. The use of **TaskPool** helps reduce resource consumption and improve system performance. It also frees you from caring about the lifecycle of thread instances.
  - Uses **Worker** to support multithread concurrency. The worker thread can communicate with the host thread. You need to proactively create and close a worker thread.

- Providing common capabilities of [adding, deleting, modifying, and querying elements in containers](container-overview.md)

- Constructing and parsing XML files, URLs, and URIs
  - Extensible Markup Language (XML) is designed for data transmission and storage. The common library provides APIs for [XML generation, parsing, and conversion](xml-overview.md).
  - [URI](../reference/apis/js-apis-uri.md) is a uniform resource identifier that uniquely identifies a resource. [URL](../reference/apis/js-apis-url.md) is a uniform resource locator that provides a path for locating a resource.

- Supporting common [string and binary data processing](../reference/apis/js-apis-util.md) and [logging](../reference/apis/js-apis-logs.md)
  - Provides APIs to encode and decode strings.
  - Provides APIs to encode and decode Base64-encoded bytes.
  - Supports common rational number operations, including comparing rational numbers and obtaining numerators and denominators.
  - Provides **Scope** APIs to define the valid range of a field.
  - Provides APIs to process binary data in scenarios such as TCP flows or file system operations.
  - Supports logging using the console.

- Providing the capability of [obtaining process information and operating processes](../reference/apis/js-apis-process.md)