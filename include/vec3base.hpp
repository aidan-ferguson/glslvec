#ifndef GLSLVEC_VEC3_BASE_H
#define GLSLVEC_VEC3_BASE_H

#include "vectorcommon.hpp"
#include "vec1swizzle.hpp"
#include "vec3swizzle.hpp"
#include "vec2swizzle.hpp"
#include "vec4swizzle.hpp"

namespace glslvec {

template<typename T>
struct vec3base : public vec3swizzle<vec3base<T>, T, 0, 1, 2, 0> {
    union {
        // This holds all the data for our vector
        T data[3];

        // Swizzle attributes
        vec1swizzle<vec1base<T>, T, 0, 8>  x, r;
        vec1swizzle<vec1base<T>, T, 1, 8>  y, g;
        vec1swizzle<vec1base<T>, T, 2, 8>  z, b;
        vec2swizzle<vec2base<T>, T, 0, 0, 8>  xx, rr;
        vec2swizzle<vec2base<T>, T, 0, 1, 8>  xy, rg;
        vec2swizzle<vec2base<T>, T, 0, 2, 8>  xz, rb;
        vec2swizzle<vec2base<T>, T, 1, 0, 8>  yx, gr;
        vec2swizzle<vec2base<T>, T, 1, 1, 8>  yy, gg;
        vec2swizzle<vec2base<T>, T, 1, 2, 8>  yz, gb;
        vec2swizzle<vec2base<T>, T, 2, 0, 8>  zx, br;
        vec2swizzle<vec2base<T>, T, 2, 1, 8>  zy, bg;
        vec2swizzle<vec2base<T>, T, 2, 2, 8>  zz, bb;
        vec3swizzle<vec3base<T>, T, 0, 0, 0, 8>  xxx, rrr;
        vec3swizzle<vec3base<T>, T, 0, 0, 1, 8>  xxy, rrg;
        vec3swizzle<vec3base<T>, T, 0, 0, 2, 8>  xxz, rrb;
        vec3swizzle<vec3base<T>, T, 0, 1, 0, 8>  xyx, rgr;
        vec3swizzle<vec3base<T>, T, 0, 1, 1, 8>  xyy, rgg;
        vec3swizzle<vec3base<T>, T, 0, 1, 2, 8>  xyz, rgb;
        vec3swizzle<vec3base<T>, T, 0, 2, 0, 8>  xzx, rbr;
        vec3swizzle<vec3base<T>, T, 0, 2, 1, 8>  xzy, rbg;
        vec3swizzle<vec3base<T>, T, 0, 2, 2, 8>  xzz, rbb;
        vec3swizzle<vec3base<T>, T, 1, 0, 0, 8>  yxx, grr;
        vec3swizzle<vec3base<T>, T, 1, 0, 1, 8>  yxy, grg;
        vec3swizzle<vec3base<T>, T, 1, 0, 2, 8>  yxz, grb;
        vec3swizzle<vec3base<T>, T, 1, 1, 0, 8>  yyx, ggr;
        vec3swizzle<vec3base<T>, T, 1, 1, 1, 8>  yyy, ggg;
        vec3swizzle<vec3base<T>, T, 1, 1, 2, 8>  yyz, ggb;
        vec3swizzle<vec3base<T>, T, 1, 2, 0, 8>  yzx, gbr;
        vec3swizzle<vec3base<T>, T, 1, 2, 1, 8>  yzy, gbg;
        vec3swizzle<vec3base<T>, T, 1, 2, 2, 8>  yzz, gbb;
        vec3swizzle<vec3base<T>, T, 2, 0, 0, 8>  zxx, brr;
        vec3swizzle<vec3base<T>, T, 2, 0, 1, 8>  zxy, brg;
        vec3swizzle<vec3base<T>, T, 2, 0, 2, 8>  zxz, brb;
        vec3swizzle<vec3base<T>, T, 2, 1, 0, 8>  zyx, bgr;
        vec3swizzle<vec3base<T>, T, 2, 1, 1, 8>  zyy, bgg;
        vec3swizzle<vec3base<T>, T, 2, 1, 2, 8>  zyz, bgb;
        vec3swizzle<vec3base<T>, T, 2, 2, 0, 8>  zzx, bbr;
        vec3swizzle<vec3base<T>, T, 2, 2, 1, 8>  zzy, bbg;
        vec3swizzle<vec3base<T>, T, 2, 2, 2, 8>  zzz, bbb;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 0, 8>  xxxx, rrrr;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 1, 8>  xxxy, rrrg;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 2, 8>  xxxz, rrrb;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 0, 8>  xxyx, rrgr;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 1, 8>  xxyy, rrgg;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 2, 8>  xxyz, rrgb;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 0, 8>  xxzx, rrbr;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 1, 8>  xxzy, rrbg;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 2, 8>  xxzz, rrbb;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 0, 8>  xyxx, rgrr;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 1, 8>  xyxy, rgrg;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 2, 8>  xyxz, rgrb;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 0, 8>  xyyx, rggr;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 1, 8>  xyyy, rggg;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 2, 8>  xyyz, rggb;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 0, 8>  xyzx, rgbr;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 1, 8>  xyzy, rgbg;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 2, 8>  xyzz, rgbb;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 0, 8>  xzxx, rbrr;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 1, 8>  xzxy, rbrg;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 2, 8>  xzxz, rbrb;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 0, 8>  xzyx, rbgr;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 1, 8>  xzyy, rbgg;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 2, 8>  xzyz, rbgb;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 0, 8>  xzzx, rbbr;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 1, 8>  xzzy, rbbg;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 2, 8>  xzzz, rbbb;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 0, 8>  yxxx, grrr;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 1, 8>  yxxy, grrg;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 2, 8>  yxxz, grrb;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 0, 8>  yxyx, grgr;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 1, 8>  yxyy, grgg;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 2, 8>  yxyz, grgb;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 0, 8>  yxzx, grbr;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 1, 8>  yxzy, grbg;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 2, 8>  yxzz, grbb;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 0, 8>  yyxx, ggrr;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 1, 8>  yyxy, ggrg;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 2, 8>  yyxz, ggrb;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 0, 8>  yyyx, gggr;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 1, 8>  yyyy, gggg;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 2, 8>  yyyz, gggb;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 0, 8>  yyzx, ggbr;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 1, 8>  yyzy, ggbg;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 2, 8>  yyzz, ggbb;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 0, 8>  yzxx, gbrr;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 1, 8>  yzxy, gbrg;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 2, 8>  yzxz, gbrb;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 0, 8>  yzyx, gbgr;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 1, 8>  yzyy, gbgg;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 2, 8>  yzyz, gbgb;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 0, 8>  yzzx, gbbr;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 1, 8>  yzzy, gbbg;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 2, 8>  yzzz, gbbb;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 0, 8>  zxxx, brrr;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 1, 8>  zxxy, brrg;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 2, 8>  zxxz, brrb;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 0, 8>  zxyx, brgr;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 1, 8>  zxyy, brgg;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 2, 8>  zxyz, brgb;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 0, 8>  zxzx, brbr;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 1, 8>  zxzy, brbg;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 2, 8>  zxzz, brbb;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 0, 8>  zyxx, bgrr;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 1, 8>  zyxy, bgrg;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 2, 8>  zyxz, bgrb;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 0, 8>  zyyx, bggr;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 1, 8>  zyyy, bggg;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 2, 8>  zyyz, bggb;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 0, 8>  zyzx, bgbr;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 1, 8>  zyzy, bgbg;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 2, 8>  zyzz, bgbb;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 0, 8>  zzxx, bbrr;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 1, 8>  zzxy, bbrg;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 2, 8>  zzxz, bbrb;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 0, 8>  zzyx, bbgr;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 1, 8>  zzyy, bbgg;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 2, 8>  zzyz, bbgb;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 0, 8>  zzzx, bbbr;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 1, 8>  zzzy, bbbg;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 2, 8>  zzzz, bbbb;

    };

    // Basic constructors
    vec3base() = default;
    vec3base(T a) {data[0] = a; data[1] = a; data[2] = a;}
    vec3base(T x, T y, T z) {data[0] = x; data[1] = y; data[2] = z;}

    // Copy constructor from a vec3swizzle
    template<typename vec_type2, typename T2, int x2, int y2, int z2, long byte_offset>
	vec3base(const vec3swizzle<vec_type2, T2, x2, y2, z2, byte_offset>& v ) {data[0] = v[x2]; data[1] = v[y2]; data[2] = v[z2];}

    // Constructors from vec2
    template<typename vec_type2, typename T2, int x2, int y2, long byte_offset>
	vec3base(const vec2swizzle<vec_type2, T2, x2, y2, byte_offset>& v, T z) {data[0] = v[x2]; data[1] = v[y2]; data[2] = z;}
    
    template<typename vec_type2, typename T2, int x2, int y2, long byte_offset>
    vec3base(T x, const vec2swizzle<vec_type2, T2, x2, y2, byte_offset>& v) {data[0] = x; data[1] = v[x2]; data[2] = v[y2];}
};

typedef vec3base<float> vec3f;
typedef vec3base<double> vec3d;
typedef vec3f vec3;
static_assert(sizeof(vec3) == sizeof(float[3]), "Size of vec3 incorrect");
static_assert(sizeof(vec3d) == sizeof(double[3]), "Size of vec3d incorrect");

} // GLSLVEC

#endif // GLSLVEC_VEC3_BASE_H