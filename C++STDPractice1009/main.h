#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>

template <typename T, typename U>
class CRect {
public:
    CRect(T height, U width) : height_(height), width_(width) {}
  
    const void Show() { std::cout << Area() << std::endl; }

private:
    const T height_;
    const U width_;

    /// <summary>
    /// �߂�l�̌^���_�֐�
    /// </summary>
    /// <returns>�ʐ�</returns>
    auto Area() const -> decltype(std::declval<T>()* std::declval<U>())
    {
        return height_ * width_;
    }

};