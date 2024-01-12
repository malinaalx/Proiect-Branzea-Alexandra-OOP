#pragma once
#include<iostream>

template <typename T>
class Factory {
public:
    template <typename... Args>
    static T create(Args&&... args) {
        return T(std::forward<Args>(args)...);
    }
};
