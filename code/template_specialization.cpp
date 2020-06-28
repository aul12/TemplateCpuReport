// Struct-Template with a single template argument
template<bool enable>
struct Not {
    static constexpr auto value = false;
};

// Specialization if the argument is false
template<>
struct Not<false> {
    static constexpr auto value = true;
};
