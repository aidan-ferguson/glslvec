#ifndef GLSLVEC_VEC3_SWIZZLE_H
#define GLSLVEC_VEC3_SWIZZLE_H

#include "vectorcommon.hpp"

namespace glslvec {

template<typename vec_type, typename T1, int x1, int y1, int z1, long byte_offset>
class vec3swizzle {
public:
    // All vector math functions go here
    template<class vec3_type, typename T2, int x2, int y2, int z2, long byte_offset2>
    T1 dot(const vec3swizzle<vec3_type, T2, x2, y2, z2, byte_offset2>& v2) const {
        return (((T1*)this)[x1] * ((const T2*)&v2)[x2] +
        ((T1*)this)[y1] * ((const T2*)&v2)[y2] +
        ((T1*)this)[z1] * ((const T2*)&v2)[z2]);
    }

    void normalise() {
        double l = length();
        ((T1*)this)[x1] /= l;
        ((T1*)this)[y1] /= l;
        ((T1*)this)[z1] /= l;
    }

    double length() const {
        return std::sqrt(this->dot(*this));
    }

    // Subscript operator (indexing the data array)
    T1& operator[](int i) const {
        assert((i < 3) && (i >= 0) || !fprintf(stderr, "index %d is invalid for array of length 2\n", i));
        return ((T1*)this)[i];
    }

    // All overloads go below here
    // Assignment operators
    #define VEC3_ASSIGNMENT_OPERATOR(OP) \
    template<class vec3_type, typename T2, int x2, int y2, int z2, long byte_offset2> \
    vec3swizzle& operator OP(const vec3swizzle<vec3_type, T2, x2, y2, z2, byte_offset2>& rhs) { \
        ((T1*)this)[x1] OP ((const T2*)&rhs)[x2]; \
        ((T1*)this)[y1] OP ((const T2*)&rhs)[y2]; \
        ((T1*)this)[z1] OP ((const T2*)&rhs)[z2]; \
        return *this; \
    } \
    vec3swizzle& operator OP(const T1 rhs){\
        ((T1*)this)[x1] OP rhs; \
        ((T1*)this)[y1] OP rhs; \
        ((T1*)this)[z1] OP rhs; \
        return *this; \
    }

    VEC3_ASSIGNMENT_OPERATOR(=)
    VEC3_ASSIGNMENT_OPERATOR(+=)
    VEC3_ASSIGNMENT_OPERATOR(-=)
    VEC3_ASSIGNMENT_OPERATOR(*=)
    VEC3_ASSIGNMENT_OPERATOR(/=)
    #undef VEC3_ASSIGNMENT_OPERATOR

    // Arithmetic operators
    // + and - require some extra overrides
    #define VEC3_UNARY_ARITHMETIC_OPERATOR(OP)\
    vec_type operator OP() const {              \
        vec_type result;                        \
        result[0] = OP((const T1*)this)[x1];    \
        result[1] = OP((const T1*)this)[y1];    \
        result[2] = OP((const T1*)this)[z1];    \
        return result;                          \
    }
    VEC3_UNARY_ARITHMETIC_OPERATOR(+)
    VEC3_UNARY_ARITHMETIC_OPERATOR(-)
    #undef VEC3_UNARY_ARITHMETIC_OPERATOR

    #define VEC3_ARITHMETIC_OPERATOR(OP)                                                  \
    template<class vec_type2, typename T2, int x2, int y2, int z2, long byte_offset2>                   \
    vec_type operator OP(const vec3swizzle<vec_type2, T2, x2, y2, z2, byte_offset2>& rhs) const {    \
        vec_type result;                                                                       \
        result[0] = ((const T1*)this)[x1] OP ((const T2*)&rhs)[x2];                              \
        result[1] = ((const T1*)this)[y1] OP ((const T2*)&rhs)[y2];                              \
        result[2] = ((const T1*)this)[z1] OP ((const T2*)&rhs)[z2];                              \
        return result;                                                                          \
    }                                                                                           \
    vec_type operator OP(const T1 rhs) const {                                                   \
        vec_type result;                                                                        \
        result[0] = ((const T1*)this)[x1] OP rhs;                                                \
        result[1] = ((const T1*)this)[y1] OP rhs;                                                \
        result[2] = ((const T1*)this)[z1] OP rhs;                                                \
        return result;                                                                          \
    }                                                                                           \
    friend vec_type operator OP(const T1 lhs, const vec3swizzle& rhs) {                          \
        vec_type result;                                                                        \
        result[0] = lhs OP ((const T1*)&rhs)[x1];                                                \
        result[1] = lhs OP ((const T1*)&rhs)[y1];                                                \
        result[2] = lhs OP ((const T1*)&rhs)[z1];                                                \
        return result;                                                                          \
    }

    VEC3_ARITHMETIC_OPERATOR(+)
    VEC3_ARITHMETIC_OPERATOR(-)
    VEC3_ARITHMETIC_OPERATOR(*)
    VEC3_ARITHMETIC_OPERATOR(/)
    VEC3_ARITHMETIC_OPERATOR(%)
    VEC3_ARITHMETIC_OPERATOR(&)
    VEC3_ARITHMETIC_OPERATOR(|)
    VEC3_ARITHMETIC_OPERATOR(^)
    VEC3_ARITHMETIC_OPERATOR(<<)
    VEC3_ARITHMETIC_OPERATOR(>>)
    #undef VEC3_ARITHMETIC_OPERATOR
    
};

template<class vec_type, typename T, int x, int y, int z, long byte_offset>
std::ostream& operator<<(std::ostream& os, const vec3swizzle<vec_type, T, x, y, z, byte_offset>& rhs) {
    os << std::setprecision(VECTOR_PRINT_PRECISION) << "[" << ((vec_type*)(&rhs))->data[x] << "," << ((vec_type*)(&rhs))->data[y] << "," << ((vec_type*)(&rhs))->data[z] << "]";
    return os;
}

} // GLSLVEC


#endif // GLSLVEC_VEC3_SWIZZLE_H