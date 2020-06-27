// Struct Template with two template arguments
template<bool enable, typename T>
struct naive_enable_if {
    using type = typename T;
};

// Template specialization that is used if the first argument is false
template<typename T>
struct naive_enable_if<false, T> {}; // Different implementation: type is not defined
