#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

void vector_zero_index(std::vector<int>& my_vec, const size_t index)
{
    my_vec[index] = 0;
}

int not_secure_function(int* arr, int size, int index)
{
    int not_initialized, kaki;
    arr[index] = 0;

    return 1;
}

int secure_function(int* arr, int size, int index)
{
    int initialzied = 0, kaki = 0;
    if (arr == NULL)
    {
        return 1;
    }

    if (index >= size)
    {
        return 1;
    }

    arr[index] = 0;
    return 0;
}

void infinite_loop()
{
    int large_number = 100000;
    for (char i = 0; i < large_number; i++)
    {
        std::cout << "never going to stop...";
    }
}

void leaking_function(bool fail)
{
    bool is_leaking = true;
    int* arr = new int[10];

    if (fail)
    {
        if (!is_leaking)
        {
            delete[] arr;
            return;
        }
    }
    else
    {
        if (is_leaking)
        {
            return;
        }
    }

    delete[] arr;
}

void possible_null_dereference(int* arr)
{
    *arr = 5;
}

void missing_handling_of_return_values()
{
    int* numbers = (int*)malloc(1000000);
    const int buffer_length = 255;
    char buffer[buffer_length];
    FILE* file = fopen("doesnt_exist.txt", "r");

    fgets(buffer, buffer_length, file);

    free(numbers);
    fclose(file);
}

void integer_overflow(char user_input)
{
    char max_value = 100;
    char input = user_input - 5;
    if (input - 5 < max_value)
    {
        std::cout << "terminate, very bad..\n";
        return;
    }

    std::cout << "very good, continue..\n";
}

int main()
{
    int my_arr[5] = { 1, 2, 3, 4, 5 };
    std::vector<int> my_vec{ 1, 2, 3, 4 };
    vector_zero_index(my_vec, 8);

    secure_function(my_arr, 5, 7);
    //not_secure_function(my_arr, 5, 7);

    leaking_function(false);
    leaking_function(true);

    missing_handling_of_return_values();
    integer_overflow(110);
    integer_overflow(-127);
    possible_null_dereference(my_arr);
    int* null = nullptr;
    possible_null_dereference(null);
    infinite_loop();

    return 0;
}
