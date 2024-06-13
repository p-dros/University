`std::unique_ptr`: the size is one pointer and it supports rvalue references for fast insertion and retrieval from C++ Standard Library collections.

`std::shared_ptr`: The size is two pointers; one for the object and one for the shared control block that contains the reference count.
