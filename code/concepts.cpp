template<typename T>
struct IsTypeList {
    static constexpr bool val = false;
};

template<typename T, typename next>
struct IsTypeList<TypeListElem<T, next>> {
    static constexpr bool val = true;
};

template<>
struct IsTypeList<ListEnd> {
    static constexpr bool val = true;
};

template<typename T>
concept TypeList = IsTypeList<T>::val;

