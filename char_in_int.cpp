#include <iostream>
#include "char_in_int.h"

void one_bits_counter(long input)
{
    unsigned char *ch_ptr = reinterpret_cast<unsigned char *>(&input);
    int counter = 0;

    for (unsigned char *fin = ch_ptr + sizeof(input); ch_ptr != fin; ++ch_ptr)
    {
        for (; *ch_ptr; *ch_ptr >>= 1)
        {
            counter += ((*ch_ptr & 1) == 1);
        }
    }

    std::cout << "the number of one bits: " << counter << std::endl;
}