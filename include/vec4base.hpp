#ifndef GLSLVEC_VEC4_BASE_H
#define GLSLVEC_VEC4_BASE_H

#include "vectorcommon.hpp"
#include "vec1swizzle.hpp"
#include "vec2swizzle.hpp"
#include "vec3swizzle.hpp"
#include "vec4swizzle.hpp"

namespace glslvec {

template<typename T>
struct vec4base : public vec4swizzle<vec4base<T>, T, 0, 1, 2, 3, 0> {
    union {
        // This holds all the data for our vector
        T data[4];

        // Swizzle attributes
        vec1swizzle<vec1base<T>, T, 0, 8>  x, r;
        vec1swizzle<vec1base<T>, T, 1, 8>  y, g;
        vec1swizzle<vec1base<T>, T, 2, 8>  z, b;
        vec1swizzle<vec1base<T>, T, 3, 8>  w, a;
        vec2swizzle<vec2base<T>, T, 0, 0, 8>  xx, rr;
        vec2swizzle<vec2base<T>, T, 0, 1, 8>  xy, rg;
        vec2swizzle<vec2base<T>, T, 0, 2, 8>  xz, rb;
        vec2swizzle<vec2base<T>, T, 0, 3, 8>  xw, ra;
        vec2swizzle<vec2base<T>, T, 1, 0, 8>  yx, gr;
        vec2swizzle<vec2base<T>, T, 1, 1, 8>  yy, gg;
        vec2swizzle<vec2base<T>, T, 1, 2, 8>  yz, gb;
        vec2swizzle<vec2base<T>, T, 1, 3, 8>  yw, ga;
        vec2swizzle<vec2base<T>, T, 2, 0, 8>  zx, br;
        vec2swizzle<vec2base<T>, T, 2, 1, 8>  zy, bg;
        vec2swizzle<vec2base<T>, T, 2, 2, 8>  zz, bb;
        vec2swizzle<vec2base<T>, T, 2, 3, 8>  zw, ba;
        vec2swizzle<vec2base<T>, T, 3, 0, 8>  wx, ar;
        vec2swizzle<vec2base<T>, T, 3, 1, 8>  wy, ag;
        vec2swizzle<vec2base<T>, T, 3, 2, 8>  wz, ab;
        vec2swizzle<vec2base<T>, T, 3, 3, 8>  ww, aa;
        vec3swizzle<vec3base<T>, T, 0, 0, 0, 8>  xxx, rrr;
        vec3swizzle<vec3base<T>, T, 0, 0, 1, 8>  xxy, rrg;
        vec3swizzle<vec3base<T>, T, 0, 0, 2, 8>  xxz, rrb;
        vec3swizzle<vec3base<T>, T, 0, 0, 3, 8>  xxw, rra;
        vec3swizzle<vec3base<T>, T, 0, 1, 0, 8>  xyx, rgr;
        vec3swizzle<vec3base<T>, T, 0, 1, 1, 8>  xyy, rgg;
        vec3swizzle<vec3base<T>, T, 0, 1, 2, 8>  xyz, rgb;
        vec3swizzle<vec3base<T>, T, 0, 1, 3, 8>  xyw, rga;
        vec3swizzle<vec3base<T>, T, 0, 2, 0, 8>  xzx, rbr;
        vec3swizzle<vec3base<T>, T, 0, 2, 1, 8>  xzy, rbg;
        vec3swizzle<vec3base<T>, T, 0, 2, 2, 8>  xzz, rbb;
        vec3swizzle<vec3base<T>, T, 0, 2, 3, 8>  xzw, rba;
        vec3swizzle<vec3base<T>, T, 0, 3, 0, 8>  xwx, rar;
        vec3swizzle<vec3base<T>, T, 0, 3, 1, 8>  xwy, rag;
        vec3swizzle<vec3base<T>, T, 0, 3, 2, 8>  xwz, rab;
        vec3swizzle<vec3base<T>, T, 0, 3, 3, 8>  xww, raa;
        vec3swizzle<vec3base<T>, T, 1, 0, 0, 8>  yxx, grr;
        vec3swizzle<vec3base<T>, T, 1, 0, 1, 8>  yxy, grg;
        vec3swizzle<vec3base<T>, T, 1, 0, 2, 8>  yxz, grb;
        vec3swizzle<vec3base<T>, T, 1, 0, 3, 8>  yxw, gra;
        vec3swizzle<vec3base<T>, T, 1, 1, 0, 8>  yyx, ggr;
        vec3swizzle<vec3base<T>, T, 1, 1, 1, 8>  yyy, ggg;
        vec3swizzle<vec3base<T>, T, 1, 1, 2, 8>  yyz, ggb;
        vec3swizzle<vec3base<T>, T, 1, 1, 3, 8>  yyw, gga;
        vec3swizzle<vec3base<T>, T, 1, 2, 0, 8>  yzx, gbr;
        vec3swizzle<vec3base<T>, T, 1, 2, 1, 8>  yzy, gbg;
        vec3swizzle<vec3base<T>, T, 1, 2, 2, 8>  yzz, gbb;
        vec3swizzle<vec3base<T>, T, 1, 2, 3, 8>  yzw, gba;
        vec3swizzle<vec3base<T>, T, 1, 3, 0, 8>  ywx, gar;
        vec3swizzle<vec3base<T>, T, 1, 3, 1, 8>  ywy, gag;
        vec3swizzle<vec3base<T>, T, 1, 3, 2, 8>  ywz, gab;
        vec3swizzle<vec3base<T>, T, 1, 3, 3, 8>  yww, gaa;
        vec3swizzle<vec3base<T>, T, 2, 0, 0, 8>  zxx, brr;
        vec3swizzle<vec3base<T>, T, 2, 0, 1, 8>  zxy, brg;
        vec3swizzle<vec3base<T>, T, 2, 0, 2, 8>  zxz, brb;
        vec3swizzle<vec3base<T>, T, 2, 0, 3, 8>  zxw, bra;
        vec3swizzle<vec3base<T>, T, 2, 1, 0, 8>  zyx, bgr;
        vec3swizzle<vec3base<T>, T, 2, 1, 1, 8>  zyy, bgg;
        vec3swizzle<vec3base<T>, T, 2, 1, 2, 8>  zyz, bgb;
        vec3swizzle<vec3base<T>, T, 2, 1, 3, 8>  zyw, bga;
        vec3swizzle<vec3base<T>, T, 2, 2, 0, 8>  zzx, bbr;
        vec3swizzle<vec3base<T>, T, 2, 2, 1, 8>  zzy, bbg;
        vec3swizzle<vec3base<T>, T, 2, 2, 2, 8>  zzz, bbb;
        vec3swizzle<vec3base<T>, T, 2, 2, 3, 8>  zzw, bba;
        vec3swizzle<vec3base<T>, T, 2, 3, 0, 8>  zwx, bar;
        vec3swizzle<vec3base<T>, T, 2, 3, 1, 8>  zwy, bag;
        vec3swizzle<vec3base<T>, T, 2, 3, 2, 8>  zwz, bab;
        vec3swizzle<vec3base<T>, T, 2, 3, 3, 8>  zww, baa;
        vec3swizzle<vec3base<T>, T, 3, 0, 0, 8>  wxx, arr;
        vec3swizzle<vec3base<T>, T, 3, 0, 1, 8>  wxy, arg;
        vec3swizzle<vec3base<T>, T, 3, 0, 2, 8>  wxz, arb;
        vec3swizzle<vec3base<T>, T, 3, 0, 3, 8>  wxw, ara;
        vec3swizzle<vec3base<T>, T, 3, 1, 0, 8>  wyx, agr;
        vec3swizzle<vec3base<T>, T, 3, 1, 1, 8>  wyy, agg;
        vec3swizzle<vec3base<T>, T, 3, 1, 2, 8>  wyz, agb;
        vec3swizzle<vec3base<T>, T, 3, 1, 3, 8>  wyw, aga;
        vec3swizzle<vec3base<T>, T, 3, 2, 0, 8>  wzx, abr;
        vec3swizzle<vec3base<T>, T, 3, 2, 1, 8>  wzy, abg;
        vec3swizzle<vec3base<T>, T, 3, 2, 2, 8>  wzz, abb;
        vec3swizzle<vec3base<T>, T, 3, 2, 3, 8>  wzw, aba;
        vec3swizzle<vec3base<T>, T, 3, 3, 0, 8>  wwx, aar;
        vec3swizzle<vec3base<T>, T, 3, 3, 1, 8>  wwy, aag;
        vec3swizzle<vec3base<T>, T, 3, 3, 2, 8>  wwz, aab;
        vec3swizzle<vec3base<T>, T, 3, 3, 3, 8>  www, aaa;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 0, 8>  xxxx, rrrr;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 1, 8>  xxxy, rrrg;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 2, 8>  xxxz, rrrb;
        vec4swizzle<vec4base<T>, T, 0, 0, 0, 3, 8>  xxxw, rrra;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 0, 8>  xxyx, rrgr;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 1, 8>  xxyy, rrgg;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 2, 8>  xxyz, rrgb;
        vec4swizzle<vec4base<T>, T, 0, 0, 1, 3, 8>  xxyw, rrga;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 0, 8>  xxzx, rrbr;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 1, 8>  xxzy, rrbg;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 2, 8>  xxzz, rrbb;
        vec4swizzle<vec4base<T>, T, 0, 0, 2, 3, 8>  xxzw, rrba;
        vec4swizzle<vec4base<T>, T, 0, 0, 3, 0, 8>  xxwx, rrar;
        vec4swizzle<vec4base<T>, T, 0, 0, 3, 1, 8>  xxwy, rrag;
        vec4swizzle<vec4base<T>, T, 0, 0, 3, 2, 8>  xxwz, rrab;
        vec4swizzle<vec4base<T>, T, 0, 0, 3, 3, 8>  xxww, rraa;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 0, 8>  xyxx, rgrr;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 1, 8>  xyxy, rgrg;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 2, 8>  xyxz, rgrb;
        vec4swizzle<vec4base<T>, T, 0, 1, 0, 3, 8>  xyxw, rgra;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 0, 8>  xyyx, rggr;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 1, 8>  xyyy, rggg;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 2, 8>  xyyz, rggb;
        vec4swizzle<vec4base<T>, T, 0, 1, 1, 3, 8>  xyyw, rgga;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 0, 8>  xyzx, rgbr;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 1, 8>  xyzy, rgbg;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 2, 8>  xyzz, rgbb;
        vec4swizzle<vec4base<T>, T, 0, 1, 2, 3, 8>  xyzw, rgba;
        vec4swizzle<vec4base<T>, T, 0, 1, 3, 0, 8>  xywx, rgar;
        vec4swizzle<vec4base<T>, T, 0, 1, 3, 1, 8>  xywy, rgag;
        vec4swizzle<vec4base<T>, T, 0, 1, 3, 2, 8>  xywz, rgab;
        vec4swizzle<vec4base<T>, T, 0, 1, 3, 3, 8>  xyww, rgaa;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 0, 8>  xzxx, rbrr;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 1, 8>  xzxy, rbrg;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 2, 8>  xzxz, rbrb;
        vec4swizzle<vec4base<T>, T, 0, 2, 0, 3, 8>  xzxw, rbra;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 0, 8>  xzyx, rbgr;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 1, 8>  xzyy, rbgg;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 2, 8>  xzyz, rbgb;
        vec4swizzle<vec4base<T>, T, 0, 2, 1, 3, 8>  xzyw, rbga;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 0, 8>  xzzx, rbbr;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 1, 8>  xzzy, rbbg;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 2, 8>  xzzz, rbbb;
        vec4swizzle<vec4base<T>, T, 0, 2, 2, 3, 8>  xzzw, rbba;
        vec4swizzle<vec4base<T>, T, 0, 2, 3, 0, 8>  xzwx, rbar;
        vec4swizzle<vec4base<T>, T, 0, 2, 3, 1, 8>  xzwy, rbag;
        vec4swizzle<vec4base<T>, T, 0, 2, 3, 2, 8>  xzwz, rbab;
        vec4swizzle<vec4base<T>, T, 0, 2, 3, 3, 8>  xzww, rbaa;
        vec4swizzle<vec4base<T>, T, 0, 3, 0, 0, 8>  xwxx, rarr;
        vec4swizzle<vec4base<T>, T, 0, 3, 0, 1, 8>  xwxy, rarg;
        vec4swizzle<vec4base<T>, T, 0, 3, 0, 2, 8>  xwxz, rarb;
        vec4swizzle<vec4base<T>, T, 0, 3, 0, 3, 8>  xwxw, rara;
        vec4swizzle<vec4base<T>, T, 0, 3, 1, 0, 8>  xwyx, ragr;
        vec4swizzle<vec4base<T>, T, 0, 3, 1, 1, 8>  xwyy, ragg;
        vec4swizzle<vec4base<T>, T, 0, 3, 1, 2, 8>  xwyz, ragb;
        vec4swizzle<vec4base<T>, T, 0, 3, 1, 3, 8>  xwyw, raga;
        vec4swizzle<vec4base<T>, T, 0, 3, 2, 0, 8>  xwzx, rabr;
        vec4swizzle<vec4base<T>, T, 0, 3, 2, 1, 8>  xwzy, rabg;
        vec4swizzle<vec4base<T>, T, 0, 3, 2, 2, 8>  xwzz, rabb;
        vec4swizzle<vec4base<T>, T, 0, 3, 2, 3, 8>  xwzw, raba;
        vec4swizzle<vec4base<T>, T, 0, 3, 3, 0, 8>  xwwx, raar;
        vec4swizzle<vec4base<T>, T, 0, 3, 3, 1, 8>  xwwy, raag;
        vec4swizzle<vec4base<T>, T, 0, 3, 3, 2, 8>  xwwz, raab;
        vec4swizzle<vec4base<T>, T, 0, 3, 3, 3, 8>  xwww, raaa;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 0, 8>  yxxx, grrr;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 1, 8>  yxxy, grrg;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 2, 8>  yxxz, grrb;
        vec4swizzle<vec4base<T>, T, 1, 0, 0, 3, 8>  yxxw, grra;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 0, 8>  yxyx, grgr;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 1, 8>  yxyy, grgg;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 2, 8>  yxyz, grgb;
        vec4swizzle<vec4base<T>, T, 1, 0, 1, 3, 8>  yxyw, grga;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 0, 8>  yxzx, grbr;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 1, 8>  yxzy, grbg;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 2, 8>  yxzz, grbb;
        vec4swizzle<vec4base<T>, T, 1, 0, 2, 3, 8>  yxzw, grba;
        vec4swizzle<vec4base<T>, T, 1, 0, 3, 0, 8>  yxwx, grar;
        vec4swizzle<vec4base<T>, T, 1, 0, 3, 1, 8>  yxwy, grag;
        vec4swizzle<vec4base<T>, T, 1, 0, 3, 2, 8>  yxwz, grab;
        vec4swizzle<vec4base<T>, T, 1, 0, 3, 3, 8>  yxww, graa;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 0, 8>  yyxx, ggrr;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 1, 8>  yyxy, ggrg;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 2, 8>  yyxz, ggrb;
        vec4swizzle<vec4base<T>, T, 1, 1, 0, 3, 8>  yyxw, ggra;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 0, 8>  yyyx, gggr;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 1, 8>  yyyy, gggg;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 2, 8>  yyyz, gggb;
        vec4swizzle<vec4base<T>, T, 1, 1, 1, 3, 8>  yyyw, ggga;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 0, 8>  yyzx, ggbr;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 1, 8>  yyzy, ggbg;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 2, 8>  yyzz, ggbb;
        vec4swizzle<vec4base<T>, T, 1, 1, 2, 3, 8>  yyzw, ggba;
        vec4swizzle<vec4base<T>, T, 1, 1, 3, 0, 8>  yywx, ggar;
        vec4swizzle<vec4base<T>, T, 1, 1, 3, 1, 8>  yywy, ggag;
        vec4swizzle<vec4base<T>, T, 1, 1, 3, 2, 8>  yywz, ggab;
        vec4swizzle<vec4base<T>, T, 1, 1, 3, 3, 8>  yyww, ggaa;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 0, 8>  yzxx, gbrr;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 1, 8>  yzxy, gbrg;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 2, 8>  yzxz, gbrb;
        vec4swizzle<vec4base<T>, T, 1, 2, 0, 3, 8>  yzxw, gbra;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 0, 8>  yzyx, gbgr;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 1, 8>  yzyy, gbgg;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 2, 8>  yzyz, gbgb;
        vec4swizzle<vec4base<T>, T, 1, 2, 1, 3, 8>  yzyw, gbga;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 0, 8>  yzzx, gbbr;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 1, 8>  yzzy, gbbg;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 2, 8>  yzzz, gbbb;
        vec4swizzle<vec4base<T>, T, 1, 2, 2, 3, 8>  yzzw, gbba;
        vec4swizzle<vec4base<T>, T, 1, 2, 3, 0, 8>  yzwx, gbar;
        vec4swizzle<vec4base<T>, T, 1, 2, 3, 1, 8>  yzwy, gbag;
        vec4swizzle<vec4base<T>, T, 1, 2, 3, 2, 8>  yzwz, gbab;
        vec4swizzle<vec4base<T>, T, 1, 2, 3, 3, 8>  yzww, gbaa;
        vec4swizzle<vec4base<T>, T, 1, 3, 0, 0, 8>  ywxx, garr;
        vec4swizzle<vec4base<T>, T, 1, 3, 0, 1, 8>  ywxy, garg;
        vec4swizzle<vec4base<T>, T, 1, 3, 0, 2, 8>  ywxz, garb;
        vec4swizzle<vec4base<T>, T, 1, 3, 0, 3, 8>  ywxw, gara;
        vec4swizzle<vec4base<T>, T, 1, 3, 1, 0, 8>  ywyx, gagr;
        vec4swizzle<vec4base<T>, T, 1, 3, 1, 1, 8>  ywyy, gagg;
        vec4swizzle<vec4base<T>, T, 1, 3, 1, 2, 8>  ywyz, gagb;
        vec4swizzle<vec4base<T>, T, 1, 3, 1, 3, 8>  ywyw, gaga;
        vec4swizzle<vec4base<T>, T, 1, 3, 2, 0, 8>  ywzx, gabr;
        vec4swizzle<vec4base<T>, T, 1, 3, 2, 1, 8>  ywzy, gabg;
        vec4swizzle<vec4base<T>, T, 1, 3, 2, 2, 8>  ywzz, gabb;
        vec4swizzle<vec4base<T>, T, 1, 3, 2, 3, 8>  ywzw, gaba;
        vec4swizzle<vec4base<T>, T, 1, 3, 3, 0, 8>  ywwx, gaar;
        vec4swizzle<vec4base<T>, T, 1, 3, 3, 1, 8>  ywwy, gaag;
        vec4swizzle<vec4base<T>, T, 1, 3, 3, 2, 8>  ywwz, gaab;
        vec4swizzle<vec4base<T>, T, 1, 3, 3, 3, 8>  ywww, gaaa;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 0, 8>  zxxx, brrr;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 1, 8>  zxxy, brrg;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 2, 8>  zxxz, brrb;
        vec4swizzle<vec4base<T>, T, 2, 0, 0, 3, 8>  zxxw, brra;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 0, 8>  zxyx, brgr;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 1, 8>  zxyy, brgg;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 2, 8>  zxyz, brgb;
        vec4swizzle<vec4base<T>, T, 2, 0, 1, 3, 8>  zxyw, brga;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 0, 8>  zxzx, brbr;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 1, 8>  zxzy, brbg;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 2, 8>  zxzz, brbb;
        vec4swizzle<vec4base<T>, T, 2, 0, 2, 3, 8>  zxzw, brba;
        vec4swizzle<vec4base<T>, T, 2, 0, 3, 0, 8>  zxwx, brar;
        vec4swizzle<vec4base<T>, T, 2, 0, 3, 1, 8>  zxwy, brag;
        vec4swizzle<vec4base<T>, T, 2, 0, 3, 2, 8>  zxwz, brab;
        vec4swizzle<vec4base<T>, T, 2, 0, 3, 3, 8>  zxww, braa;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 0, 8>  zyxx, bgrr;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 1, 8>  zyxy, bgrg;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 2, 8>  zyxz, bgrb;
        vec4swizzle<vec4base<T>, T, 2, 1, 0, 3, 8>  zyxw, bgra;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 0, 8>  zyyx, bggr;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 1, 8>  zyyy, bggg;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 2, 8>  zyyz, bggb;
        vec4swizzle<vec4base<T>, T, 2, 1, 1, 3, 8>  zyyw, bgga;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 0, 8>  zyzx, bgbr;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 1, 8>  zyzy, bgbg;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 2, 8>  zyzz, bgbb;
        vec4swizzle<vec4base<T>, T, 2, 1, 2, 3, 8>  zyzw, bgba;
        vec4swizzle<vec4base<T>, T, 2, 1, 3, 0, 8>  zywx, bgar;
        vec4swizzle<vec4base<T>, T, 2, 1, 3, 1, 8>  zywy, bgag;
        vec4swizzle<vec4base<T>, T, 2, 1, 3, 2, 8>  zywz, bgab;
        vec4swizzle<vec4base<T>, T, 2, 1, 3, 3, 8>  zyww, bgaa;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 0, 8>  zzxx, bbrr;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 1, 8>  zzxy, bbrg;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 2, 8>  zzxz, bbrb;
        vec4swizzle<vec4base<T>, T, 2, 2, 0, 3, 8>  zzxw, bbra;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 0, 8>  zzyx, bbgr;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 1, 8>  zzyy, bbgg;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 2, 8>  zzyz, bbgb;
        vec4swizzle<vec4base<T>, T, 2, 2, 1, 3, 8>  zzyw, bbga;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 0, 8>  zzzx, bbbr;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 1, 8>  zzzy, bbbg;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 2, 8>  zzzz, bbbb;
        vec4swizzle<vec4base<T>, T, 2, 2, 2, 3, 8>  zzzw, bbba;
        vec4swizzle<vec4base<T>, T, 2, 2, 3, 0, 8>  zzwx, bbar;
        vec4swizzle<vec4base<T>, T, 2, 2, 3, 1, 8>  zzwy, bbag;
        vec4swizzle<vec4base<T>, T, 2, 2, 3, 2, 8>  zzwz, bbab;
        vec4swizzle<vec4base<T>, T, 2, 2, 3, 3, 8>  zzww, bbaa;
        vec4swizzle<vec4base<T>, T, 2, 3, 0, 0, 8>  zwxx, barr;
        vec4swizzle<vec4base<T>, T, 2, 3, 0, 1, 8>  zwxy, barg;
        vec4swizzle<vec4base<T>, T, 2, 3, 0, 2, 8>  zwxz, barb;
        vec4swizzle<vec4base<T>, T, 2, 3, 0, 3, 8>  zwxw, bara;
        vec4swizzle<vec4base<T>, T, 2, 3, 1, 0, 8>  zwyx, bagr;
        vec4swizzle<vec4base<T>, T, 2, 3, 1, 1, 8>  zwyy, bagg;
        vec4swizzle<vec4base<T>, T, 2, 3, 1, 2, 8>  zwyz, bagb;
        vec4swizzle<vec4base<T>, T, 2, 3, 1, 3, 8>  zwyw, baga;
        vec4swizzle<vec4base<T>, T, 2, 3, 2, 0, 8>  zwzx, babr;
        vec4swizzle<vec4base<T>, T, 2, 3, 2, 1, 8>  zwzy, babg;
        vec4swizzle<vec4base<T>, T, 2, 3, 2, 2, 8>  zwzz, babb;
        vec4swizzle<vec4base<T>, T, 2, 3, 2, 3, 8>  zwzw, baba;
        vec4swizzle<vec4base<T>, T, 2, 3, 3, 0, 8>  zwwx, baar;
        vec4swizzle<vec4base<T>, T, 2, 3, 3, 1, 8>  zwwy, baag;
        vec4swizzle<vec4base<T>, T, 2, 3, 3, 2, 8>  zwwz, baab;
        vec4swizzle<vec4base<T>, T, 2, 3, 3, 3, 8>  zwww, baaa;
        vec4swizzle<vec4base<T>, T, 3, 0, 0, 0, 8>  wxxx, arrr;
        vec4swizzle<vec4base<T>, T, 3, 0, 0, 1, 8>  wxxy, arrg;
        vec4swizzle<vec4base<T>, T, 3, 0, 0, 2, 8>  wxxz, arrb;
        vec4swizzle<vec4base<T>, T, 3, 0, 0, 3, 8>  wxxw, arra;
        vec4swizzle<vec4base<T>, T, 3, 0, 1, 0, 8>  wxyx, argr;
        vec4swizzle<vec4base<T>, T, 3, 0, 1, 1, 8>  wxyy, argg;
        vec4swizzle<vec4base<T>, T, 3, 0, 1, 2, 8>  wxyz, argb;
        vec4swizzle<vec4base<T>, T, 3, 0, 1, 3, 8>  wxyw, arga;
        vec4swizzle<vec4base<T>, T, 3, 0, 2, 0, 8>  wxzx, arbr;
        vec4swizzle<vec4base<T>, T, 3, 0, 2, 1, 8>  wxzy, arbg;
        vec4swizzle<vec4base<T>, T, 3, 0, 2, 2, 8>  wxzz, arbb;
        vec4swizzle<vec4base<T>, T, 3, 0, 2, 3, 8>  wxzw, arba;
        vec4swizzle<vec4base<T>, T, 3, 0, 3, 0, 8>  wxwx, arar;
        vec4swizzle<vec4base<T>, T, 3, 0, 3, 1, 8>  wxwy, arag;
        vec4swizzle<vec4base<T>, T, 3, 0, 3, 2, 8>  wxwz, arab;
        vec4swizzle<vec4base<T>, T, 3, 0, 3, 3, 8>  wxww, araa;
        vec4swizzle<vec4base<T>, T, 3, 1, 0, 0, 8>  wyxx, agrr;
        vec4swizzle<vec4base<T>, T, 3, 1, 0, 1, 8>  wyxy, agrg;
        vec4swizzle<vec4base<T>, T, 3, 1, 0, 2, 8>  wyxz, agrb;
        vec4swizzle<vec4base<T>, T, 3, 1, 0, 3, 8>  wyxw, agra;
        vec4swizzle<vec4base<T>, T, 3, 1, 1, 0, 8>  wyyx, aggr;
        vec4swizzle<vec4base<T>, T, 3, 1, 1, 1, 8>  wyyy, aggg;
        vec4swizzle<vec4base<T>, T, 3, 1, 1, 2, 8>  wyyz, aggb;
        vec4swizzle<vec4base<T>, T, 3, 1, 1, 3, 8>  wyyw, agga;
        vec4swizzle<vec4base<T>, T, 3, 1, 2, 0, 8>  wyzx, agbr;
        vec4swizzle<vec4base<T>, T, 3, 1, 2, 1, 8>  wyzy, agbg;
        vec4swizzle<vec4base<T>, T, 3, 1, 2, 2, 8>  wyzz, agbb;
        vec4swizzle<vec4base<T>, T, 3, 1, 2, 3, 8>  wyzw, agba;
        vec4swizzle<vec4base<T>, T, 3, 1, 3, 0, 8>  wywx, agar;
        vec4swizzle<vec4base<T>, T, 3, 1, 3, 1, 8>  wywy, agag;
        vec4swizzle<vec4base<T>, T, 3, 1, 3, 2, 8>  wywz, agab;
        vec4swizzle<vec4base<T>, T, 3, 1, 3, 3, 8>  wyww, agaa;
        vec4swizzle<vec4base<T>, T, 3, 2, 0, 0, 8>  wzxx, abrr;
        vec4swizzle<vec4base<T>, T, 3, 2, 0, 1, 8>  wzxy, abrg;
        vec4swizzle<vec4base<T>, T, 3, 2, 0, 2, 8>  wzxz, abrb;
        vec4swizzle<vec4base<T>, T, 3, 2, 0, 3, 8>  wzxw, abra;
        vec4swizzle<vec4base<T>, T, 3, 2, 1, 0, 8>  wzyx, abgr;
        vec4swizzle<vec4base<T>, T, 3, 2, 1, 1, 8>  wzyy, abgg;
        vec4swizzle<vec4base<T>, T, 3, 2, 1, 2, 8>  wzyz, abgb;
        vec4swizzle<vec4base<T>, T, 3, 2, 1, 3, 8>  wzyw, abga;
        vec4swizzle<vec4base<T>, T, 3, 2, 2, 0, 8>  wzzx, abbr;
        vec4swizzle<vec4base<T>, T, 3, 2, 2, 1, 8>  wzzy, abbg;
        vec4swizzle<vec4base<T>, T, 3, 2, 2, 2, 8>  wzzz, abbb;
        vec4swizzle<vec4base<T>, T, 3, 2, 2, 3, 8>  wzzw, abba;
        vec4swizzle<vec4base<T>, T, 3, 2, 3, 0, 8>  wzwx, abar;
        vec4swizzle<vec4base<T>, T, 3, 2, 3, 1, 8>  wzwy, abag;
        vec4swizzle<vec4base<T>, T, 3, 2, 3, 2, 8>  wzwz, abab;
        vec4swizzle<vec4base<T>, T, 3, 2, 3, 3, 8>  wzww, abaa;
        vec4swizzle<vec4base<T>, T, 3, 3, 0, 0, 8>  wwxx, aarr;
        vec4swizzle<vec4base<T>, T, 3, 3, 0, 1, 8>  wwxy, aarg;
        vec4swizzle<vec4base<T>, T, 3, 3, 0, 2, 8>  wwxz, aarb;
        vec4swizzle<vec4base<T>, T, 3, 3, 0, 3, 8>  wwxw, aara;
        vec4swizzle<vec4base<T>, T, 3, 3, 1, 0, 8>  wwyx, aagr;
        vec4swizzle<vec4base<T>, T, 3, 3, 1, 1, 8>  wwyy, aagg;
        vec4swizzle<vec4base<T>, T, 3, 3, 1, 2, 8>  wwyz, aagb;
        vec4swizzle<vec4base<T>, T, 3, 3, 1, 3, 8>  wwyw, aaga;
        vec4swizzle<vec4base<T>, T, 3, 3, 2, 0, 8>  wwzx, aabr;
        vec4swizzle<vec4base<T>, T, 3, 3, 2, 1, 8>  wwzy, aabg;
        vec4swizzle<vec4base<T>, T, 3, 3, 2, 2, 8>  wwzz, aabb;
        vec4swizzle<vec4base<T>, T, 3, 3, 2, 3, 8>  wwzw, aaba;
        vec4swizzle<vec4base<T>, T, 3, 3, 3, 0, 8>  wwwx, aaar;
        vec4swizzle<vec4base<T>, T, 3, 3, 3, 1, 8>  wwwy, aaag;
        vec4swizzle<vec4base<T>, T, 3, 3, 3, 2, 8>  wwwz, aaab;
        vec4swizzle<vec4base<T>, T, 3, 3, 3, 3, 8>  wwww, aaaa;
    };

    // Basic constructors
    vec4base() = default;
    vec4base(T a) {data[0] = a; data[1] = a; data[2] = a; data[3] = a;}
    vec4base(T x, T y, T z, T w) {data[0] = x; data[1] = y; data[2] = z; data[3] = w;}

    // Copy constructor from a vec3swizzle
    template<typename vec_type2, typename T2, int x2, int y2, int z2, int w2, long byte_offset>
	vec4base(const vec4swizzle<vec_type2, T2, x2, y2, z2, w2, byte_offset>& v ) {data[0] = v[x2]; data[1] = v[y2]; data[2] = v[z2]; data[3] = v[w2];}

    // Constructors from vec2
    template<typename vec_type2, typename T2, int x2, int y2, long byte_offset>
	vec4base(const vec2swizzle<vec_type2, T2, x2, y2, byte_offset>& v, T z, T w) {data[0] = v[x2]; data[1] = v[y2]; data[2] = z; data[3] = w;}

    template<typename vec_type2, typename T2, int x2, int y2, long byte_offset>
	vec4base(T x, const vec2swizzle<vec_type2, T2, x2, y2, byte_offset>& v, T w) {data[0] = x; data[1] = v[x2]; data[2] = v[y2]; data[3] = w;}
    
    template<typename vec_type2, typename T2, int x2, int y2, long byte_offset>
    vec4base(T x, T y, const vec2swizzle<vec_type2, T2, x2, y2, byte_offset>& v) {data[0] = x; data[1] = y; data[2] = v[x2]; data[3] = v[y2];}

    // Constructors for vec3
    template<typename vec_type2, typename T2, int x2, int y2, int z2, long byte_offset>
    vec4base(const vec3swizzle<vec_type2, T2, x2, y2, z2, byte_offset>& v, T w) {data[0] = v[x2]; data[1] = v[y2]; data[2] = v[z2]; data[3] = w;}

    template<typename vec_type2, typename T2, int x2, int y2, int z2, long byte_offset>
    vec4base(T x, const vec3swizzle<vec_type2, T2, x2, y2, z2, byte_offset>& v) {data[0] = x; data[1] = v[x2]; data[2] = v[y2]; data[3] = v[z2];}
};

typedef vec4base<float> vec4f;
typedef vec4base<double> vec4d;
typedef vec4f vec4;
static_assert(sizeof(vec4) == sizeof(float[4]), "Size of vec4 incorrect");
static_assert(sizeof(vec4d) == sizeof(double[4]), "Size of vec4d incorrect");

} // GLSLVEC

#endif // GLSLVEC_VEC4_BASE_H