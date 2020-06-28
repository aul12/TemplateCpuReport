template<typename List, std::size_t index>
struct GetType {
    using type = typename GetType<typename List::next, index - 1>::type;
};

template<typename List>
struct GetType<List, 0> {
    using type = typename List::elem;
};
