template<TypeList list>
struct Size {
    static constexpr std::size_t val = Size<typename list::next>::val + 1;
};

template<>
struct Size<ListEnd> {
    static constexpr std::size_t val = 0;
};
