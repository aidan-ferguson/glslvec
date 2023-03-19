#ifndef GLSLVEC_VEC2_SWIZZLE_H
#define GLSLVEC_VEC2_SWIZZLE_H
//TODO: change header when namespace decided

#include "vectorcommon.hpp"

namespace glslvec {

// Swizzle class which contains definitions for overriding operators
// No data is stored in this class, see subscript operator override for how data is accessed
// The byte offset indicates how much the member is offset in bytes from the start of the struct, very hacky
template<typename vec_type, typename T1, int x1, int y1, long byte_offset>
class vec2swizzle {
public:
    // All vector math functions go here
    template<class vec2_type, typename T2, int x2, int y2, long byte_offset2>
    T1 dot(const vec2swizzle<vec2_type, T2, x2, y2, byte_offset2>& v2) const {
        return (((T1*)this)[x1] * ((const T2*)&v2)[x2] +
        ((T1*)this)[y1] * ((const T2*)&v2)[y2]);
    }

    void normalise() {
        double l = length();
        ((T1*)this)[x1] /= l;
        ((T1*)this)[y1] /= l;
    }

    double length() const {
        return std::sqrt(this->dot(*this));
    }

    // Subscript operator (indexing the data array)
    T1& operator[](int i) const {
        assert((i < 2) && (i >= 0) || !fprintf(stderr, "index %d is invalid for array of length 2\n", i));
        // This feels really weird but given vec2swizzle is only implemented by vec2, which in turn only has the union in memory,
        //   which only contains an array of type T1 then 'this' will point to the start of the array.
        return ((T1*)this)[i];
    }

    // All overloads go below here
    // Comparison operators
    #define VEC2_COMPARISON_OPERATOR(OP) \
    template<class vec2_type, typename T2, int x2, int y2, long byte_offset2> \
    bool operator OP(const vec2swizzle<vec2_type, T2, x2, y2, byte_offset2>& rhs) { \
        return (                                                                    \
            ((T1*)this)[x1] OP ((const T2*)&rhs)[x2] && \
            ((T1*)this)[y1] OP ((const T2*)&rhs)[y2]    \
        );                                               \
    }

    VEC2_COMPARISON_OPERATOR(==)
    VEC2_COMPARISON_OPERATOR(!=)
    VEC2_COMPARISON_OPERATOR(<)
    VEC2_COMPARISON_OPERATOR(>)
    VEC2_COMPARISON_OPERATOR(<=)
    VEC2_COMPARISON_OPERATOR(>=)
    #undef VEC2_COMPARISON_OPERATOR


    // Assignment operators
    #define VEC2_ASSIGNMENT_OPERATOR(OP) \
    template<class vec2_type, typename T2, int x2, int y2, long byte_offset2> \
    vec2swizzle& operator OP(const vec2swizzle<vec2_type, T2, x2, y2, byte_offset2>& rhs) { \
        ((T1*)this)[x1] OP ((const T2*)&rhs)[x2]; \
        ((T1*)this)[y1] OP ((const T2*)&rhs)[y2]; \
        return *this; \
    } \
    vec2swizzle& operator OP(const T1 rhs){\
        ((T1*)this)[x1] OP rhs; \
        ((T1*)this)[y1] OP rhs; \
        return *this; \
    }

    VEC2_ASSIGNMENT_OPERATOR(=)
    VEC2_ASSIGNMENT_OPERATOR(+=)
    VEC2_ASSIGNMENT_OPERATOR(-=)
    VEC2_ASSIGNMENT_OPERATOR(*=)
    VEC2_ASSIGNMENT_OPERATOR(/=)
    #undef VEC2_ASSIGNMENT_OPERATOR

    // Arithmetic operators
    // + and - require some extra overrides
    #define VEC2_UNARY_ARITHMETIC_OPERATOR(OP)\
    vec_type operator OP() const {              \
        vec_type result;                        \
        result[0] = OP((const T1*)this)[x1];    \
        result[1] = OP((const T1*)this)[y1];    \
        return result;                          \
    }
    VEC2_UNARY_ARITHMETIC_OPERATOR(+)
    VEC2_UNARY_ARITHMETIC_OPERATOR(-)
    #undef VEC2_UNARY_ARITHMETIC_OPERATOR

    #define VEC2_ARITHMETIC_OPERATOR(OP)                                                  \
    template<class vec_type2, typename T2, int x2, int y2, long byte_offset2>                   \
    vec_type operator OP(const vec2swizzle<vec_type2, T2, x2, y2, byte_offset2>& rhs) const {    \
        vec_type result;                                                                       \
        result[0] = ((const T1*)this)[x1] OP ((const T2*)&rhs)[x2];                              \
        result[1] = ((const T1*)this)[y1] OP ((const T2*)&rhs)[y2];                              \
        return result;                                                                          \
    }                                                                                           \
    vec_type operator OP(const T1 rhs) const {                                                   \
        vec_type result;                                                                        \
        result[0] = ((const T1*)this)[x1] OP rhs;                                                \
        result[1] = ((const T1*)this)[y1] OP rhs;                                                \
        return result;                                                                          \
    }                                                                                           \
    friend vec_type operator OP(const T1 lhs, const vec2swizzle& rhs) {                          \
        vec_type result;                                                                        \
        result[0] = lhs OP ((const T1*)&rhs)[x1];                                                \
        result[1] = lhs OP ((const T1*)&rhs)[y1];                                                \
        return result;                                                                          \
    }

    VEC2_ARITHMETIC_OPERATOR(+)
    VEC2_ARITHMETIC_OPERATOR(-)
    VEC2_ARITHMETIC_OPERATOR(*)
    VEC2_ARITHMETIC_OPERATOR(/)
    VEC2_ARITHMETIC_OPERATOR(%)
    VEC2_ARITHMETIC_OPERATOR(&)
    VEC2_ARITHMETIC_OPERATOR(|)
    VEC2_ARITHMETIC_OPERATOR(^)
    VEC2_ARITHMETIC_OPERATOR(<<)
    VEC2_ARITHMETIC_OPERATOR(>>)
    #undef VEC2_ARITHMETIC_OPERATOR
    
};

// vec2 to stream overload
template<class vec_type, typename T, int x, int y, long byte_offset>
std::ostream& operator<<(std::ostream& os, const vec2swizzle<vec_type, T, x, y, byte_offset>& rhs) {
    // The reason I can case to vec_type here is because I have the context of the overall class
    //   also compiler alignment stuff means I can't access the pointer as if it was an array of Ts
    os << std::setprecision(VECTOR_PRINT_PRECISION) << "[" << ((vec_type*)(&rhs))->data[x] << "," << ((vec_type*)(&rhs))->data[y] << "]";
    return os;
}

} // GLSLVEC


#endif // GLSLVEC_VEC2_SWIZZLE_H