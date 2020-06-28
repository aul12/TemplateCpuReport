template<typename toAdd, typename List>
struct PrependType {
    using type = Type<toAdd, List>;
};
