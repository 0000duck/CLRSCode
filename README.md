For Chinese, please check my Blog: 
http://blog.csdn.net/zhumeng1989/article/category/1232333

1. ��Ŀ�еĺ���ʵ�ֶ�������ͬԭ��һ�£�������ա��������ִ�д��㡣������ԭ
������������1��ʼ�����ע������
2. ���� Programming Pearls ������� �������ݡ�
3. ���� Modern C++ Design C++�����˼ά ��������, ����loki-0.1.7 http://sourceforge.net/projects/loki-lib/ ���޸�include·��������boost_1_51_0 http://www.boost.org/��Note: With new C++11, The template Typelist could be implemented with 'variadic template'[http://stackoverflow.com/questions/9463659/wrap-lokitypelist-with-c11-variadic-template] AND Type traits have been added in C++11.
4. Added Parallel Forall Part, which is come from Nvidia Developer Blog, https://developer.nvidia.com/blog. This part is aimed to follow their "Programming CUDA with C and C++" series, using CUDA 5. And, due to the power of GPU parallel programming, I plain adding  some comparations to basic Algorithm, such as Sort, Sum and so on.
5. Added Thrust CUDA library.
6. Added BSGP, about BSGP http://www.houqiming.net/

TODO: It will be better if separate template declaration and implement, even C++ DO NOT support only template declaration in header file, while we should use .inl file adding to the tail of .h for more clear hierarchy.

NOTE: I think the hierarchy of the code is bull shit, after I read something about the Design Patterns. Now, I'm still learning some basic knowledge. If time is ready, I will refactor these code.