> ⚠️ This file is currently under development. It does not represents the final standards for contributing.
> Please follow instructions provided.

## 🔴 This project uses a Commit Message Standard (CMS) defined by ACoffeeBreak.

Your commit message should follow this structure:
(Add headers to the message.)

```
# Summary of Changes
"..."

# Reason for Changes
"..." (Answers these questions:
- Why was this change made?
- Does it fix a bug, improve performance, or add a new feature?
)

# Details
"..." (Refers to these topics:
- Describe the changes in more depth.
- Mention any architecture or file structure modifications if applicable.
)

# Security & Testing
"..." (Answers these questions:
- Was this tested on a separate branch?
- Were tests run or added?
)

# References (Optional)
"..." (Includes:
- Link to related issues, documentation, or external resources.
)
```

## ✅ Example of a well-written commit message:

### Summary of Changes
Some header files were removed from .c file and moved to a new .h file.

### Reason for Changes
For a better readability and responsive development.
Now include folder contains a new "example.h" file.

### Details
In the "example.c" file, these lines were copied, removed and moved to a new "example.h" file:
``` C
enum Example {
Error_1,
Error_2,
Error_3
} ListOfErrors;
```
> The "example.c" file was reduced to 466 KB from 467 KB.
> Created "example.h" file (1 KB size) in the 'include' folder,

### Security & Testing
Changes have not been tested. No testing needed in particular this change.

### References
No references.
