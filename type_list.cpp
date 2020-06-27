template<typename T, typename next_>
struct Type {
    using elem = T;
    using next = next_;
};

struct ListEnd {};
