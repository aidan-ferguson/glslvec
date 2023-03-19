#ifndef GLSLVEC_VEC2_BASE_H
#define GLSLVEC_VEC2_BASE_H

#include "vectorcommon.hpp"
#include "vec1swizzle.hpp"
#include "vec2swizzle.hpp"
#include "vec3swizzle.hpp"
#include "vec4swizzle.hpp"

namespace glslvec {

template<typename T>
struct vec2base : public vec2swizzle<vec2base<T>, T, 0, 1, 0> {
    union {
        // This holds all the data for our vector
        T data[2];

        // Define different swizzler templates as different letter combinations
        //   when one of these is invoked a vec2swizzler type is returned and it can be used
        //   in maths operations as defined in swizzler.h
        vec1swizzle<vec1base<T>, T, 0, 8>  x, r;
        vec1swizzle<vec1base<T>, T, 1, 8>  y, g;
        vec2swizzle<vec2base<T>, T, 0, 0, 8>  xx, rr;
        vec2swizzle<vec2base<T>, T, 0, 1, 8>  xy, rg;
        vec2swizzle<vec2base<T>, T, 1, 0, 8>  yx, gr;
        vec2swizzle<vec2base<T>, T, 1, 1, 8>  yy, gg;
        vec3swizzle<vec3base<T>, T, 0, 0, 0, 8>  xxx, rrr;
        vec3swizzle<vec3base<T>, T, 0, 0, 1, 8>  xxy, rrg;
        vec3swizzle<vec3base<T>, T, 0, 1, 0, 8>  xyx, rgr;
        vec3swizzle<vec3base<T>, T, 0, 1, 1, 8>  xyy, rgg;
        vec3swizzle<vec3base<T>, T, 1, 0, 0, 8>  yxx, grr;
        vec3swizzle<vec3base<T>, T, 1, 0, 1, 8>  yxy, grg;
        vec3swizzle<vec3base<T>, T, 1, 1, 0, 8>  yyx, ggr;
        vec3swizzle<vec3base<T>, T, 1, 1, 1, 8>  yyy, ggg;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 0, 8>  xxxx, rrrr;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 1, 8>  xxxy, rrrg;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 0, 8>  xxyx, rrgr;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 1, 8>  xxyy, rrgg;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 0, 8>  xyxx, rgrr;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 1, 8>  xyxy, rgrg;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 0, 8>  xyyx, rggr;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 1, 8>  xyyy, rggg;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 0, 8>  yxxx, grrr;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 1, 8>  yxxy, grrg;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 0, 8>  yxyx, grgr;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 1, 8>  yxyy, grgg;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 0, 8>  yyxx, ggrr;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 1, 8>  yyxy, ggrg;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 0, 8>  yyyx, gggr;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 1, 8>  yyyy, gggg;

    };

    // Basic constructors
    vec2base() = default;
    vec2base(T a) {data[0] = a; data[1] = a;}
    vec2base(T x, T y) {data[0] = x; data[1] = y;}

    // Copy constructor from a vec2swizzle
    template<typename vec_type2, typename T2, int x2, int y2, long byte_offset>
	vec2base(const vec2swizzle<vec_type2, T2, x2, y2, byte_offset>& rhs ) {data[0] = rhs[x2]; data[1] = rhs[y2]; }

};

// Define type aliases and validate size (when the size is not correct strange stuff happens)
typedef vec2base<float> vec2f;
typedef vec2base<double> vec2d;
typedef vec2f vec2;
static_assert(sizeof(vec2) == sizeof(float[2]), "Size of vec2 incorrect");
static_assert(sizeof(vec2d) == sizeof(double[2]), "Size of vec2d incorrect");

// Vector operations (dot, normalise, etc...) here
template<typename vec_type, typename T1, int x1, int y1, long byte_offset, typename vec_type2, typename T2, int x2, int y2, long byte_offset2>
T1 dot(const vec2swizzle<vec_type, T1, x1, y1, byte_offset>& v1, const vec2swizzle<vec_type2, T2, x2, y2, byte_offset2>& v2) {
    return v1.dot(v2);
}

template<typename vec_type, typename T1, int x1, int y1, long byte_offset>
vec_type normalised(const vec2swizzle<vec_type, T1, x1, y1, byte_offset>& v) {
    vec_type new_v = v;
    new_v.normalise();
    return new_v;
}

template<typename vec_type, typename T1, int x1, int y1, long byte_offset>
double length(const vec2swizzle<vec_type, T1, x1, y1, byte_offset>& v) {
    return v.length();
}

} // GLSLVEC


#endif // GLSLVEC_VEC2_BASE_H