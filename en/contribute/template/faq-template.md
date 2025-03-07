# FAQ Writing Template

FAQs are designed to offer concise responses to frequently asked questions, covering a range of topics from fundamental product or service concepts to feature explanations and common usage inquiries.

These FAQs are compiled based on the most common questions posed by users and are incorporated into the developer's documentation. By addressing individual user concerns and identifying the underlying issues, they cater to real-world usage scenarios, thereby assisting a broader user base.

## Criteria for Effective FAQs

* FAQs serve as reference materials for users when they are unable to resolve issues on their own. 
* The effectiveness of an FAQ is judged based on two main criteria:
  - First, whether users can quickly locate the relevant FAQ.     → **Titles and symptoms**: acting as guides or maps, which are essential for pinpointing the issue.
  - Second, whether the FAQ can guide users to solve problems effectively.  → **Possible causes and solutions**:

A typical FAQ consists of the following three parts:

FAQ = Symptoms + Possible Causes + Solutions

Problems can be complex or simple. For some straightforward issues, if the title already covers the "symptoms" and "possible causes," it is acceptable to omit redundant information.

| Scenario                                                               | Purpose of Writing              | Corresponding Document Module| Writing Requirement|
| ----------------------------------------------------------------------- | ---------------------------- | -------------- | ---------- |
| 1. Locating: Users look up specific FAQs by identifying problem symptoms, akin to following a map.               | The documentation should be easily navigable and allow for quick matching with user issues.              | Symptom      | The descriptions should be detailed and precise.    |
| 2. Analyzing: This step is optional. Users can compare their situation with the listed possible causes to analyze if they face a similar problem and to gain insights into how to address it.| The documentation should clearly explain the causes to prepare users for problem-solving.| Possible Causes      | The explanations should be logical and coherent.    |
| 3. Resolving: Users follow the provided solutions to resolve issues independently, without needing external help.            | The documentation should guide users through the process of self-help problem resolution.        | Solution      | The instructions should be actionable and practical.    |

FAQs generally fall into two main types:

* [Troubleshooting](#troubleshooting)
* [Consulting (including feature principles, specifications, concepts, and usage)](#consulting)


## Troubleshooting

**Title: A concise, one-sentence summary of the issue's outcome.**

**Symptom**

Describe the errors from the user's perspective that they can observe. This includes the context, manifestations, and conditions under which the problem occurs.

(For complex issues, optional) If there's a full procedure for reproducing the issue, it should be detailed here as well.

**Possible Causes (optional)**

Clearly state the root cause of the issue. If various causes require different solutions, they should be distinctly itemized.

**Solution**

- Compose in a step-by-step format to ensure the steps are actionable.
- Focus on "action-object" phrases for the steps, sometimes including the "purpose of the action" and the "outcomes of the current step".
- Organize the logical flow (appropriate layering), use bullet points for parallel relationships, and numbered lists for sequential dependencies.

**Code Examples**

Showcase the essential code and offer runnable code snippets.
If it is procedural code, it can be integrated with the solution steps.

**Reference**

Include links to guides, API references, and samples to facilitate further reading for developers.

## Consulting

**Title: Begin with the user's query, including specific feature keywords.**

No need for separate subheadings, provide direct answers with implementation plans and relevant specification constraints. If code examples are used to clarify, simple snippets can be given right after the solution.

**Reference**

Include links to guides, API references, and samples to facilitate further reading for developers.
