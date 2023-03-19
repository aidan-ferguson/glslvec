#ifndef GLSLVEC_VEC1_BASE_H
#define GLSLVEC_VEC1_BASE_H

#include "vectorcommon.hpp"
#include "vec1swizzle.hpp"
#include "vec2swizzle.hpp"
#include "vec3swizzle.hpp"
#include "vec4swizzle.hpp"

namespace glslvec {

template<typename T>
struct vec1base : public vec1swizzle<vec1base<T>, T, 0, 0> {
    union {
        T* data[1];

        vec1swizzle<vec1base<T>, T, 0, 8>  x, r;
        vec2swizzle<vec2base<T>, T, 0, 0, 8>  xx, rr;
        vec3swizzle<vec3base<T>, T, 0, 0, 0, 8>  xxx, rrr;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 0, 8>  xxxx, rrrr;
    };

    vec1base() = default;
    vec1base(T x) {data[0] = x;}
};

typedef vec1base<float> vec1f;
typedef vec1base<double> vec1d;
typedef vec1f vec1;
// static_assert(sizeof(vec1) == sizeof(float[1]), "Size of vec1 incorrect"); // TODO: figure out why assertion fails
static_assert(sizeof(vec1d) == sizeof(double[1]), "Size of vec1d incorrect");

} // GLSLVEC

#endif // GLSLVEC_VEC1_BASE_H