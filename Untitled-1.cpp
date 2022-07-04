#include<bits/stdc++.h>
using namespace std;
template <typename _Tp>
iterator_trait<>
struct _List_iterator 
{
    typedef _List_iterator<_Tp>                _Self;
    typedef _List_node<_Tp>                    _Node;

    typedef ptrdiff_t                          difference_type;
    typedef std::bidirectional_iterator_tag    iterator_category;
    typedef _Tp                                value_type;
    typedef _Tp*                               pointer;
    typedef _Tp&                               reference;
};
template <typename I>
algorithm(I first,I last) {
    I::iterator_category
}