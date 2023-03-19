# glslvec - a C++ vector library
`glslvec` is a C++ vector library I wrote becuase I liked the way vectors work in GLSL. So far it supports swizzling, basic arithmetic operations on vectors, some vector functions such as `dot` and `normalised`, in the future I want to add SIMD support too.

### Swizzling
You can access the individual components of the vectors by using swizzling:
```c++
// Swizzling
glslvec::vec4 v1 = glslvec::vec4(1, 2, 3, 4);
glslvec::vec2 v2 = v1.xy;  // v2 now holds [1, 2]
v2 = v1.xw;                // v2 now holds [1, 4]

// Construction
glslvec::vec4 v3 = glslvec::vec4(1, v1, 3);  // v3 now holds [1, 1, 4, 3]
```

### Arithmetic
As mentioned above, most of the relavent operators have been overloaded
```c++
// Continuing from example above
glslvec::vec3 v4 = v1 + v3  // v4 now holds [2, 3, 7, 7]
v4 -= 2  // v4 now holds [0, 1, 5, 5]
bool a = (v4 == v1)  // a is false
```

### Limitations
Due to the amount of templating magic going compile times can be impacted quite heavily but runtime shouldn't be much worse (untested). Each vector should not use up any additional memory that just storing the numbers. Currently I am using some weird union/class inheritance stuff so it could just break.