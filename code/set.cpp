template<typename T, typename List, std::size_t index>
struct SetType {
    static_assert(index < Size<List>::val, "SetType out of bounds");
    using type = Type<typename List::elem, typename SetType<T, typename List::next, index - 1>::type>;
};

template<typename T, typename List>
struct SetType<T, List, 0> {
    using type = Type<T, typename List::next>;
};

