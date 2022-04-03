#include "unity/unity.h"
#include "header.h"
#include "func_decl.h"

void setUp() {}
void tearDown() {}

void test_logincredential(void){
        TEST_ASSERT_EQUAL_INT(0,login("user\n","pass\n"));
        TEST_ASSERT_EQUAL_INT(0,login("user","1234"));
        TEST_ASSERT_EQUAL_INT(0,login("stepin","password"));
}

void test_validvehicletype(void) {
    TEST_ASSERT_EQUAL_INT(1, valid_vehicle_type(TWO_WHEELER));
    TEST_ASSERT_EQUAL_INT(1, valid_vehicle_type(FOUR_WHEELER));
    TEST_ASSERT_EQUAL_INT(0, valid_vehicle_type(3));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_logincredential);
    RUN_TEST(test_validvehicletype);
    return UNITY_END();
}

