template<typename T, typename next_>
struct TypeListElem {
    using elem = T;
    using next = next_;
};

struct ListEnd {};
