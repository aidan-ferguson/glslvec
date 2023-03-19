#ifndef GLSLVEC_VEC1_SWIZZLE_H
#define GLSLVEC_VEC1_SWIZZLE_H

#include "vectorcommon.hpp"

namespace glslvec {

template<typename vec_type, typename T1, int x1, long byte_offset>
class vec1swizzle {
public:
    operator T1() const{
		return ((T1*)this)[x1];
	}
};

} // GLSLVEC

#endif // GLSLVEC_VEC1_SWIZZLE_H