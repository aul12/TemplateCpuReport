template<typename list, std::size_t index>
struct GetType {
    static_assert(index < Size<list>::val, "GetType out of bounds");
    using type = typename GetType<typename list::next, index - 1>::type;
};

template<typename list>
struct GetType<list, 0> {
    using type = typename list::elem;
};
