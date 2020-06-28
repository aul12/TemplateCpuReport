template<typename T, typename List, std::size_t index>
struct SetType {
    using type = typename PrependType<typename List::elem, typename SetType<T, typename List::next, index - 1>::type>::type;
};

template<typename T, typename List>
struct SetType<T, List, 0> {
    using type = typename PrependType<T, typename List::next>::type;
};

