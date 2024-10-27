

// #include "PmergeMe.hpp"


// template <class T>
// void merge(T right_stack, T left_stack, T *stack)
// {
//   int l = 0;
//   int r = 0;
//   int i = 0;
//   while (l < left_stack.size() && r < right_stack.size())
//   {
//     if (left_stack[l] < right_stack[r])
//     {
//       stack->at(i) = (left_stack[l]);
//       l++;
//     }
//     else
//     {
//       stack->at(i) = (right_stack[r]);
//       r++;
//     }
//     i++;
//   }
//   while (r < right_stack.size())
//   {
//     stack->at(i) = (right_stack[r]);
//     i++;
//     r++;
//   }
//   while (l < left_stack.size())
//   {
//     stack->at(i) = (left_stack[l]);
//     l++;
//     i++;
//   }
// }
// template <class T>
// void merge_sort(T *stack)
// {
//   if (stack->size() <= 1)
//     return;
//   T right_stack;
//   T left_stack;
//   int j = 0;
//   int k = 0;
//   size_t i = 0;
//   for (; i < stack->size(); i++)
//   {
//     if (i < stack->size() / 2)
//       right_stack.push_back(stack->at(i));
//     else
//       left_stack.push_back(stack->at(i));
//   }
//   merge_sort(&right_stack);
//   merge_sort(&left_stack);

//   merge(right_stack, left_stack, stack);
// }