#include <cassert>
#include "set.hpp"

void test_set_getSize() {
    Set<int> set1;

    assert(set1.size() == 0);

    set1.insert(0);
    set1.insert(1);
    set1.insert(100);
    assert(set1.size() == 3);

    set1.remove(1);
    assert(set1.size() == 2);

    std::cout << "test_getSize() passed" << std::endl;
}

void test_constructor() {
    Set<int> set;

    assert(set.size() == 0);
        std::cout << "test_constructor() passed" << std::endl;

}

void test_insert_isMember() {
    Set<int> set;

    set.insert(2);
    set.insert(4);
    
    assert(set.isMember(2) == true);
    assert(set.isMember(4) == true);
    assert(set.isMember(8) == false);

    std::cout << "test_insert_isMember() passed" << std::endl;
}

void test_remove() {
    Set<double> set;
    
    set.insert(2.2);
    set.insert(4.3);
    assert(set.isMember(2.2) == true);
    set.remove(2.2);
    assert(set.isMember(2.2) == false);

    std::cout << "test_remove() passed" << std::endl;
}

void test_pop() {
    Set<float> set;

    set.insert(1.3);
    set.insert(3.75);
    set.insert(10.12);

    float popped = set.pop();

    assert(set.isMember(popped) == false);
    std::cout << "test_pop() passed" << std::endl;
}

void test_intersection() {
    Set<int> set1;
    Set<int> set2;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    set2.insert(2);
    set2.insert(3);
    set2.insert(4);

    Set<int> set3 = set1.intersection(set2);

    assert(set3.isMember(2) == true);
    assert(set3.isMember(3) == true);

    std::cout << "test_intersection() passed" << std::endl;
}

void test_difference() {
    Set<int> set1;
    Set<int> set2;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    set2.insert(2);
    set2.insert(3);
    set2.insert(4);

    Set<int> set3 = set1.difference(set2);

    assert(set3.isMember(1) == true);
    
    std::cout << "test_difference() passed" << std::endl;
}

void test_Union() {
    Set<int> set1;
    Set<int> set2;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    set2.insert(2);
    set2.insert(3);
    set2.insert(4);

    Set<int> set3 = set1.Union(set2);

    assert(set3.isMember(1) == true);
    assert(set3.isMember(2) == true);
    assert(set3.isMember(3) == true);
    assert(set3.isMember(4) == true);
    
    std::cout << "test_union() passed" << std::endl;
}

void run_all_tests() {
    test_set_getSize();
    test_constructor();
    test_insert_isMember();
    test_remove();
    test_pop();
    test_intersection();
    test_difference();
    test_Union();
}


