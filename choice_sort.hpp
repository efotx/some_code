template <typename T>
void choice_sort(T* start, T* last)
{
    T* sorted = start;
    while (sorted != last)
    {
        T* runner = sorted;
        T* min = sorted;
        for ( ; runner != last; ++runner)
        {
            if (*runner < *min)
            {
                min = runner;
            }
        }
        std::swap(*sorted++, *min);
    }
}