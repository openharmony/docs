# Overview of the ArkTS Container Library

The ArkTS container library provides a set of methods to process elements of various data types stored in containers. It can yield certain benefits when being used as pure data structure containers.

Container classes are implemented similarly to static languages, with constraints on storage locations and properties. This approach allows each data type to fulfill its purpose without unnecessary logic, ensuring efficient data access and boosting application performance.

At present, two categories of containers are available: [linear containers](linear-container.md) and [nonlinear containers](nonlinear-container.md). Linear containers are backed by arrays, whereas non-linear containers rely on hash tables or red-black trees. Neither type of container is designed to be thread-safe.
