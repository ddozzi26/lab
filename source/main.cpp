#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_SWIZZLE

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

int main() {
    using glm::vec3;
    using glm::vec4;

    // 1. Point p(1,4,-5)�� vector v(5,1,4) ��ŭ �̵��϶�
    vec3 p(1, 4, -5);
    vec3 v(5, 1, 4);
    vec3 p_moved = p + v;
    std::cout << "1) " << glm::to_string(p_moved) << "\n";

    // 2. vector v1(1,0,0) �� vector v2(0,1,0)�� ���϶�
    vec3 v1(1, 0, 0), v2(0, 1, 0);
    vec3 v_sum = v1 + v2;
    std::cout << "2) " << glm::to_string(v_sum) << "\n";

    // 3. Vector v1(0,1,0) �� ���̸� �� �� ��ŭ Ű��ÿ�.
    vec3 v3(0, 1, 0);
    vec3 v3_twice = v3 * 2.0f;                              
    std::cout << "3) " << glm::to_string(v3_twice) << "\n";

    // 4. ������ (8,2,5) �� ���� (1,-1,4)�� �մ� ���͸� ���Ͻÿ�
    vec3 s(8, 2, 5), e(1, -1, 4);
    vec3 se = e - s;
    std::cout << "4) " << glm::to_string(se) << "\n";       

    // 5. vector v(1,3,4)�� ����ȭ(normalize)�Ͻÿ�
    vec3 v5(1, 3, 4);
    vec3 v5_norm = glm::normalize(v5);                      
    std::cout << "5) " << glm::to_string(v5_norm) << "\n";  

    // 6. 3���� vector v(1,-1,4)�� 4�������ͷ� ��ȯ�ϰ� w���� 0���� �����Ͻÿ�
    vec3 v6(1, -1, 4);
    vec4 v6_h(v6, 0.0f);                                    
    std::cout << "6) " << glm::to_string(v6_h) << "\n";    

    return 0;
}
