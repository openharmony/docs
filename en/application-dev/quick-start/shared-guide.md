# Shared Package Overview

The system provides two types of shared packages: [Harmony Archive (HAR)](har-package.md) and [Harmony Shared Package (HSP)](in-app-hsp.md).

Both the HAR and HSP are used to share code and resources and can contain code, C++ libraries, resources, and configuration files. The biggest differences between them are as follows: The code and resources in the HAR are compiled with the invoking module, and if there are multiple invoking modules, the build product contains multiple copies of the same code and resources; the code and resources in the HSP are compiled independently, and the build product contains only one copy of the code and resources.

**Figure 1** HAR and HSP in the App Pack
![in-app-hsp-har](figures/in-app-hsp-har.png)

The HSP aims to resolve the App Pack bloat resulting from multiple HAP files referencing the same HAR.

**Restrictions on using the HSP:**
- The HSP and its invoking modules must be in the stage model.
- The HSP and its invoking modules must use the **esmodule** compilation mode.
- The HSP does not support the declaration of **abilities** or **extensionAbilities** in its configuration file.
