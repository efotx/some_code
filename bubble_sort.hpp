template <typename T>
void bubble_sort(T* first, T* last)
{
    bool flag = true;
    do 
    {
        T* runner = first;
        T* forwardRunner = first + 1;
        flag = false;
        for ( ; forwardRunner != last; ++runner, ++forwardRunner)
        {
            if (*forwardRunner < *runner)
            {
                std::swap(*runner, *forwardRunner);
                flag = true;
            }
        }
    }
    while (flag == true);
}