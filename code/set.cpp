template<typename T, typename list, std::size_t index>
struct SetType {
    static_assert(index < Size<list>::val, "SetType out of bounds");
    using type = TypeListElem<typename list::elem, typename SetType<T, typename list::next, index - 1>::type>;
};

template<typename T, typename list>
struct SetType<T, list, 0> {
    using type = TypeListElem<T, typename l::next>;
};
