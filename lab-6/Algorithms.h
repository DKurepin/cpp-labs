#ifndef ALGORITHMS_H
#define ALGORITHMS_H

template<class iterator, class predicate>
bool All_of(iterator first, iterator last, predicate pred)
{
    while (first != last)
    {
        if (!pred(*first))
            return false;
        ++first;
    }
    return true;
}

template<class iterator, class sort_cmp>
bool is_Sorted(iterator first, iterator last, sort_cmp cmp)
{
    if (first == last)
        return true;
    iterator next = first;
    while (++next != last)
    {
        if (!cmp(*first, *next))
        {
            return false;
        }
        ++first;
    }
    return true;
}

template<class iterator, class predicate>
bool is_Palindrome(iterator first, iterator last, predicate pred)
{
    iterator next = last;
    --next;
    while (next != first && next > first)
    {
        if (!pred(*first, *next))
            return false;
        ++first;
        --next;
    }
    return true;
}
#endif