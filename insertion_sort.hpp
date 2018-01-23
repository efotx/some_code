template <typename T>
T* find_insertion_ptr(T* start, T* sorted, T value)
{
    for (T* runner = start; runner != sorted; ++runner)
    {
        if (value < *runner)
        {
            return runner;
        }
    }
    return nullptr;
}

template <typename T>
void insert(T* start, T* to, T* from)
{
    T temp = *from;
    for (T* runner = from; runner != to; --runner)
    {
        *runner = *(runner - 1);
    }
    *to = temp;
}

template <typename T>
void insertion_sort(T* start, T* last)
{
    T* runner = start + 1;
    while (runner != last)
    {
        if (*runner < *(runner - 1))
        {
            insert(start, find_insertion_ptr(start, runner, *runner), runner);
        }
        ++runner;
    }
}