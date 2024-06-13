Smart pointers in C++ are special types of pointers, which manage dynamic memory automatically, what prevents memory leaks and errors related with incorrect memory management.

Two most popular smart pointers are:

1. `unique_ptr`:

_Ownership_: A `std::uniqure_ptr`has exclusive ownership of the object it points to. This means that there can be only one std::unique_ptr owning a particular object at any time.

_Copy Semantics_: std::unique_ptr cannot be copied, only moved. This is enforced by the compiler, preventing accidental copying of ownership. When a std::unique_ptr is moved, the ownership of the managed object is transferred to the new owner, and the original std::unique_ptr is set to nullptr.

2. `shared_ptr`:

_Ownership_: A std::shared_ptr expresses shared ownership of the object it points to. Multiple std::shared_ptr objects can own the same object. The object is deleted when the last std::shared_ptr owning it is destroyed or reset.

_Copy Semantics_: std::shared_ptr can be copied. When a std::shared_ptr is copied, the reference count of the managed object is incremented, and the new std::shared_ptr shares ownership with the original. When the last std::shared_ptr owning the object is destroyed or reset, the object is deleted.
