# AIP Overview

## When to Use

In the pivotal shift from digital transformation to AI advancement, creating intelligent services is essential for boosting product competitiveness.

The system provides the ArkData Intelligence Platform (AIP) to offer on-device intelligent data solution with four fundamental features: semantic data processing, structured data storage, knowledge generation, and integrated knowledge retrieval — implementing AI-powered data processing on devices.

In personal office scenarios, you can vectorize the semantics of user documents, save them in a vector store (database), and uncover similar documents to generate personalized knowledge, which supports intelligent retrieval, recommendation, content generation, and Q&A.

## Basic Concepts

To get started, it is helpful to understand the following concepts:

### Vectorization
The process of vectorization uses embedding models to convert high-dimensional unstructured data (such as text and images) into low-dimensional continuous vector representations. This approach captures the semantic relationships with the data, translating abstract information into a format that can be analyzed and processed by computers. Embedding technology is widely used in fields such as natural language processing (semantic search), image recognition (feature extraction), and recommendation systems (user/item representation).

## Implementation Mechanism

By leveraging the AIP, you can implement intelligent data construction and retrieval. All these capabilities operate within the application processes, ensuring that data always remains in the application environment. This ensures data security and safeguards user privacy.

Intelligent data construction is a process that converts application data into computable vectors for intelligent data storage and retrieval. For details about the development guide, see application data vectorization.

Intelligent data retrieval involves integrated queries across various data types, such as images and text, or multiple databases. It supports condition filtering and relationship inference. Currently, the intelligent data retrieval capability is not supported.

## Restrictions

- Considering the significant computing workload and resources of data vectorization processing, the APIs are only available to 2-in-1 device applications.
- You can use NPUs to accelerate the inference process of embedding models. NPUs are recommended because pure CPU computation falls far behind in latency and energy efficiency.
