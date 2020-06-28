template<type_list List>
struct Size {
    static constexpr std::size_t val = Size<typename List::next>::val + 1;
};

template<>
struct Size<ListEnd> {
    static constexpr std::size_t val = 0;
};
