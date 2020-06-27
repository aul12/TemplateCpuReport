template<typename T, T val_>
struct ValueContainer {
    using type = T;
    static constexpr auto val = val_;
};
