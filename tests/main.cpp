// Simple assertion testing

#include <glslvec.hpp>
#include <iostream>

int main() {
    glslvec::vec2 v1 = glslvec::vec2(0);
    assert((v1[0] == 0 && v1[1] == 0));
    glslvec::vec2 v2 = glslvec::vec2(0, 0);
    assert(v1 == v2);
    v1 = glslvec::vec2(1,2);
    v2 = glslvec::vec2(2,3);
    assert(v1.yy == v2.xx);
}